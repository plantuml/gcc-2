#!/usr/bin/env python3
"""Which optimization of -O2 breaks the program?

Only the file given (by default the one found by bisect.py, jzlib's CRC32.c) is built with -O2; the
others use -O0. For each option that -O2 turns on and -O1 does not, the file is built with -O2 and
that option turned off (-fno-...): the options for which the program then works are the culprits.

Usage: tools/scan_flags.py [--cc gcc] [--file c/c/j/j/CRC32.c]
"""
import argparse
import importlib.util
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
spec = importlib.util.spec_from_file_location('bisect_tool', os.path.join(HERE, 'bisect.py'))
bisect_tool = importlib.util.module_from_spec(spec)
spec.loader.exec_module(bisect_tool)


def enabled(cc, level):
    """The set of boolean options (-fxxx) enabled at this level of optimization."""
    out = subprocess.run([cc, level, '-Q', '--help=optimizers'], capture_output=True, text=True).stdout
    return {m.group(1) for m in re.finditer(r'^\s+(-f[a-z0-9-]+)\s+\[enabled\]', out, re.M)}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--cc', default='gcc')
    ap.add_argument('--file', default='c/c/j/j/CRC32.c')
    ap.add_argument('--work', default=os.path.join(bisect_tool.ROOT, 'build-scan'))
    args = ap.parse_args()
    os.makedirs(args.work, exist_ok=True)
    bisect_tool.log(subprocess.run([args.cc, '--version'], capture_output=True, text=True).stdout.split('\n')[0])
    b = bisect_tool.Build(args.cc, '-O0', '-O2', args.work)
    b.prepare()
    only = {args.file}
    if not b.fails(only):
        bisect_tool.log('The program works with %s alone at -O2: nothing to scan.' % args.file)
        return 0
    flags = sorted(enabled(args.cc, '-O2') - enabled(args.cc, '-O1'))
    bisect_tool.log('%d options are on at -O2 and off at -O1' % len(flags))
    culprits = []
    for flag in flags:
        no = '-fno-' + flag[2:]
        obj = b.compile(args.file, '-O2 ' + no, tag=no)
        if b.fails(only, {args.file: obj}):
            bisect_tool.log('  %-45s still fails' % no)
        else:
            bisect_tool.log('  %-45s WORKS: this option is a culprit' % no)
            culprits.append(no)
    # -O1 plus each option, in the other direction
    bisect_tool.log('culprits (turning them off repairs the program): %s' % (', '.join(culprits) or 'none'))
    for flag in flags:
        obj = b.compile(args.file, '-O1 ' + flag, tag='O1' + flag)
        if b.fails(only, {args.file: obj}):
            bisect_tool.log('  -O1 %-41s FAILS: this option is enough to break it' % flag)
    return 0


if __name__ == '__main__':
    sys.exit(main())
