/* Step 7: as crc_v4.c (goto form) but with no call: the table is given. */
#include <stdint.h>

void init(int32_t *t) {
	int32_t i = 0;
	while (1) {
		if (!(i < 256)) break;
		int32_t k = 8;
		int32_t c = i;
		while (1) {
			k = k - 1;
			if (k < 0) goto done;
			if (!(c & 1)) {
				c = (int32_t) ((uint32_t) c >> 1);
				goto next;
			}
			c = -306674912 ^ (int32_t) ((uint32_t) c >> 1);
		next:;
		}
	done:;
		t[i] = c;
		i = i + 1;
	}
}
