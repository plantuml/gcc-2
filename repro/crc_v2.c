/* Step 2: as TeaVM generates it: with a "shadow stack" whose address is in a global, and a
   bounds check that calls a function that does not return (but is not declared noreturn). */
typedef struct Frame { struct Frame *next; int size; int callSiteId; } Frame;
extern Frame *stackTop;
extern int *allocate(int n);
extern void throwOutOfBounds(void);
int *table;

static inline int checkBounds(int index, int *array) {
	if (index < 0 || index >= array[-1]) {
		throwOutOfBounds();
		__builtin_unreachable();
	}
	return index;
}

void init(void) {
	struct { Frame header; void *data[1]; } shadow;
	shadow.header.next = stackTop;
	shadow.header.size = 1;
	stackTop = &shadow.header;
	table = 0;
	shadow.data[0] = 0;
	shadow.header.callSiteId = 478;
	int *t = allocate(256);
	table = t;
	for (int i = 0; i < 256; i++) {
		int c = i;
		for (int k = 0; k < 8; k++)
			c = (c & 1) ? (-306674912 ^ (int) ((unsigned) c >> 1)) : (int) ((unsigned) c >> 1);
		shadow.data[0] = t;
		shadow.header.callSiteId = 479;
		t[checkBounds(i, t)] = c;
	}
	stackTop = shadow.header.next;
}
