/* Minimal case, step 1: the table of a CRC32 filled in a loop, in an array that comes from a
   function that the compiler cannot see. GCC 15.2 -O2 (-foptimize-crc) drops the code after the call. */
extern int *allocate(int n);
int *table;

void init(void) {
	int *t = allocate(256);
	table = t;
	for (int i = 0; i < 256; i++) {
		int c = i;
		for (int k = 0; k < 8; k++)
			c = (c & 1) ? (-306674912 ^ (int) ((unsigned) c >> 1)) : (int) ((unsigned) c >> 1);
		t[i] = c;
	}
}
