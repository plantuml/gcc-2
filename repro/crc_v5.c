/* Step 5: the same loops as plain C (no goto, no label), still a call before the loop. */
#include <stdint.h>
extern int32_t *allocate(int32_t n);
int32_t *table;

void init(void) {
	int32_t *t = allocate(256);
	table = t;
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
