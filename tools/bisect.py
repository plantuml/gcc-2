#!/usr/bin/env python3
"""Which part of the C needs the optimization for the program to crash?

The C of c/ is built with gcc -O0 (it works) and -O2 (it crashes with gcc 15). This script finds
the smallest set of files, then the smallest set of functions of these files, that must be compiled
with -O2 (the rest being -O0) for the failure to show up: the "delta debugging" of the units of
compilation, then of the functions. The failure depends on the layout of the memory, so a run
counts as failed if one of the sizes of the heap (as in README.md) fails.

Usage: tools/bisect.py [--cc gcc] [--bad -O2] [--good -O0]
"""
import argparse
import concurrent.futures as cf
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
C = os.path.join(ROOT, 'c')
EXPECTED = 'Hello, world! CRC32 = ebe6c6e6'
HEAPS = [None, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 24, 32, 48, 64]
FUNCTION = re.compile(r'^(?P<head>[A-Za-z_][^;{}()#/]*?\b(?P<name>[A-Za-z_]\w*)\((?:[^;{}]*)\)\s*)\{\s*$')


def log(message):
    print(message, flush=True)


def ddmin(items, still_fails):
    """The smallest subset of items (1-minimal) for which still_fails is true."""
    n = 2
    while len(items) >= 2:
        size = max(1, len(items) // n)
        reduced = False
        for i in range(0, len(items), size):
            complement = items[:i] + items[i + size:]
            if still_fails(complement):
                items = complement
                n = max(n - 1, 2)
                reduced = True
                break
        if not reduced:
            if n >= len(items):
                break
            n = min(len(items), n * 2)
    return items


class Build:
    def __init__(self, cc, good, bad, work):
        self.cc, self.good, self.bad, self.work = cc, good, bad, work
        self.files = [l.strip() for l in open(os.path.join(C, 'all.txt')) if l.strip()]
        self.cache = {}

    def source(self, rel, heap):
        """The path of the source: c/rel, or a copy of main.c with another heap."""
        if rel != 'main.c' or heap is None:
            return os.path.join(C, rel)
        path = os.path.join(self.work, 'main-%d.c' % heap)
        if not os.path.exists(path):
            text = open(os.path.join(C, 'main.c')).read()
            text = re.sub(r'teavm_initHeap\(\d+, \d+\)',
                          'teavm_initHeap(%d, %d)' % (heap << 20, heap << 20), text)
            # the copy is not next to the headers: full path (no -I, TeaVM has a string.h)
            text = re.sub(r'#include "([^"]+)"', lambda m: '#include "%s/%s"' % (C, m.group(1)), text)
            open(path, 'w').write(text)
        return path

    def compile(self, rel, opt, heap=None, source=None, tag=''):
        key = (rel, opt, heap, tag)
        if key in self.cache:
            return self.cache[key]
        obj = os.path.join(self.work, 'o', '%s%s%s%s.o' % (rel.replace('/', '_'), opt, heap or '', tag))
        os.makedirs(os.path.dirname(obj), exist_ok=True)
        src = source or self.source(rel, heap)
        r = subprocess.run([self.cc, '-std=gnu11', '-w', opt, '-c', src, '-o', obj], capture_output=True, text=True)
        if r.returncode != 0:
            raise RuntimeError('compile %s: %s' % (rel, r.stderr[-500:]))
        self.cache[key] = obj
        return obj

    def prepare(self):
        with cf.ThreadPoolExecutor(os.cpu_count() or 2) as pool:
            jobs = [pool.submit(self.compile, f, o) for f in self.files if f != 'main.c' for o in (self.good, self.bad)]
            jobs += [pool.submit(self.compile, 'main.c', o, h) for h in HEAPS for o in (self.good, self.bad)]
            for j in jobs:
                j.result()

    def run(self, objs, heap_label):
        exe = os.path.join(self.work, 'hello-test')
        r = subprocess.run([self.cc, '-o', exe] + objs + ['-lm', '-lrt'], capture_output=True, text=True)
        if r.returncode != 0:
            raise RuntimeError('link: ' + r.stderr[-500:])
        try:
            p = subprocess.run([exe], capture_output=True, text=True, timeout=20)
            return p.returncode == 0 and p.stdout.strip() == EXPECTED
        except subprocess.TimeoutExpired:
            return False

    def fails(self, bad_files, replaced=None):
        """True if the program fails for one size of the heap when the files of bad_files use
        the option 'bad', the others 'good'. replaced: {file: object} to use instead."""
        replaced = replaced or {}
        bad_files = set(bad_files)
        for heap in HEAPS:
            objs = []
            for f in self.files:
                opt = self.bad if f in bad_files else self.good
                if f in replaced:
                    objs.append(replaced[f])
                elif f == 'main.c':
                    objs.append(self.compile(f, opt, heap))
                else:
                    objs.append(self.compile(f, opt))
            if not self.run(objs, heap):
                return True
        return False

    def sweep(self, bad_files, label):
        results = []
        for heap in HEAPS:
            objs = [self.compile(f, self.bad if f in bad_files else self.good, heap if f == 'main.c' else None)
                    for f in self.files]
            results.append('%s: %s' % (heap or 'default', 'ok' if self.run(objs, heap) else 'FAILED'))
        log('%s: %s' % (label, ', '.join(results)))


def functions(path):
    """(line index, name) of the definitions of functions of a generated file."""
    lines = open(path).read().split('\n')
    found = []
    for i, line in enumerate(lines):
        m = FUNCTION.match(line)
        if m and not line.startswith(('if', 'while', 'for', 'switch', 'else', 'typedef', 'struct')):
            found.append((i, m.group('name')))
    return lines, found


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--cc', default='gcc')
    ap.add_argument('--good', default='-O0')
    ap.add_argument('--bad', default='-O2')
    ap.add_argument('--work', default=os.path.join(ROOT, 'build-bisect'))
    args = ap.parse_args()
    os.makedirs(args.work, exist_ok=True)
    log(subprocess.run([args.cc, '--version'], capture_output=True, text=True).stdout.split('\n')[0])
    b = Build(args.cc, args.good, args.bad, args.work)
    log('compiling %d files with %s and %s...' % (len(b.files), args.good, args.bad))
    b.prepare()
    b.sweep(set(), 'all %s' % args.good)
    b.sweep(set(b.files), 'all %s' % args.bad)
    if b.fails([]):
        log('The program fails even with %s everywhere: it is not an optimization issue.' % args.good)
        return 0
    if not b.fails(b.files):
        log('The program works with %s everywhere: nothing to look for.' % args.bad)
        return 0

    log('--- files that must use %s (the others use %s)' % (args.bad, args.good))
    minimal = ddmin(list(b.files), b.fails)
    for f in minimal:
        log('  ' + f)

    for f in minimal:
        log('--- functions of %s that must use %s (the others use %s)' % (f, args.bad, args.good))
        path = os.path.join(C, f)
        lines, funcs = functions(path)
        names = [n for _, n in funcs]
        log('  %d functions' % len(names))
        counter = [0]

        def variant(keep):
            """An object of f where the functions of keep are -O2 and the others are -O0."""
            keep = set(keep)
            out = list(lines)
            for i, name in funcs:
                if name not in keep:
                    out[i] = '__attribute__((optimize("O0"))) ' + out[i]
            counter[0] += 1
            src = os.path.join(args.work, 'variant-%d.c' % counter[0])
            # the copy is not next to the headers: full path
            text = '\n'.join(out)
            text = re.sub(r'#include "([^"]+)"', lambda m: '#include "%s"' % os.path.normpath(
                os.path.join(os.path.dirname(path), m.group(1))), text)
            open(src, 'w').write(text)
            return b.compile(f, args.bad, source=src, tag='-v%d' % counter[0])

        def fails_with(keep):
            return b.fails(minimal, {f: variant(keep)})

        if not fails_with(names):
            log('  the failure needs the optimization of the whole file, not of some functions only')
            continue
        small = ddmin(names, fails_with)
        for name in small:
            log('  ' + name)
        for name in small:
            i = next(i for i, n in funcs if n == name)
            log('::group::source of %s' % name)
            end = i
            while end < len(lines) and lines[end] != '}':
                end += 1
            log('\n'.join(lines[i:end + 1]))
            log('::endgroup::')
    return 0


if __name__ == '__main__':
    sys.exit(main())
