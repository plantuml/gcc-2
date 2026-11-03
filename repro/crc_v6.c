/* Step 6: no call at all: the table is given. */
#include <stdint.h>

void init(int32_t *t) {
	for (int32_t i = 0; i < 256; i++) {
		int32_t c = i;
		int32_t k = 8;
		while (--k >= 0) {
			if (c & 1)
				c = -306674912 ^ (int32_t) ((uint32_t) c >> 1);
			else
				c = (int32_t) ((uint32_t) c >> 1);
		}
		t[i] = c;
	}
}
