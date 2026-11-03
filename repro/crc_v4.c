/* Step 4: without the shadow stack and without the bounds check. */
#include <stdint.h>
extern int32_t *allocate(int32_t n);
int32_t *table;

void init(void) {
	int32_t *t = allocate(256);
	table = t;
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
