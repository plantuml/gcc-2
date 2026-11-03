/* Run-time check: does the result of a bit-reflected CRC loop stay right at -O2 with GCC 15?
   (GCC PR 127984: a loop of 24 iterations gives the result of 32.) The loops are in functions that
   are called with constants; the reference uses a count that the compiler cannot know. */
#include <stdio.h>

__attribute__((noipa)) unsigned ref(unsigned crc, int n) {
	volatile int count = n;
	for (int i = 0; i < count; i++)
		crc = (crc & 1) ? (crc >> 1) ^ 0xEDB88320u : crc >> 1;
	return crc;
}

#define LOOP(name, n) \
	__attribute__((noipa)) unsigned name(unsigned crc) { \
		for (int i = 0; i < (n); i++) \
			if (crc & 1) crc = (crc >> 1) ^ 0xEDB88320u; else crc >>= 1; \
		return crc; \
	}
LOOP(f8, 8)
LOOP(f16, 16)
LOOP(f24, 24)
LOOP(f32, 32)

/* the table of the TeaVM jzlib: 8 iterations, the way TeaVM writes it */
__attribute__((noipa)) unsigned t8(unsigned crc) {
	int k = 8;
	while (1) {
		k = k - 1;
		if (k < 0) goto done;
		if (!(crc & 1)) { crc = crc >> 1; goto next; }
		crc = 0xEDB88320u ^ (crc >> 1);
	next:;
	}
done:
	return crc;
}

int main(void) {
	int bad = 0;
	for (unsigned v = 0; v < 256; v++) {
		unsigned seeds[2] = { v, v * 0x01010101u };
		for (int s = 0; s < 2; s++) {
			unsigned x = seeds[s];
			if (f8(x) != ref(x, 8)) bad |= 1;
			if (f16(x) != ref(x, 16)) bad |= 2;
			if (f24(x) != ref(x, 24)) bad |= 4;
			if (f32(x) != ref(x, 32)) bad |= 8;
			if (t8(x) != ref(x, 8)) bad |= 16;
		}
	}
	printf("mismatches (bit mask: 1=8 it., 2=16, 4=24, 8=32, 16=TeaVM form): %d\n", bad);
	return bad != 0;
}
