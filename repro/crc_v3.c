/* Step 3: the clinit of CRC32 as TeaVM generates it (same shape of loops: while (1), goto),
   with the few declarations that it needs. */
#include <stdint.h>
#include <stddef.h>

typedef struct TeaVM_Object { int32_t header; } TeaVM_Object;
typedef struct TeaVM_Array { TeaVM_Object parent; int32_t size; } TeaVM_Array;
typedef struct TeaVM_StackFrame {
	struct TeaVM_StackFrame* next;
	int32_t size;
	int32_t callSiteId;
} TeaVM_StackFrame;

extern TeaVM_StackFrame* teavm_stackTop;
extern void* sfld_crc_table;
extern char Arr_I_Cls;
extern void* allocateArray(void*, int32_t);
extern void teavm_throwArrayIndexOutOfBoundsException();

#define TEAVM_ALIGN(addr, alignment) ((void*) (((uintptr_t) (addr) + ((alignment) - 1)) / (alignment) * (alignment)))
#define TEAVM_ARRAY_DATA(array, type) ((type*) TEAVM_ALIGN((((TeaVM_Array*) (array)) + 1), sizeof(type)))
#define TEAVM_ARRAY_AT(array, type, index) (((type*) TEAVM_ARRAY_DATA(array, type))[index])
#define TEAVM_ALLOC_STACK(sz) \
	struct { TeaVM_StackFrame header; void* data[(sz)]; } teavm_shadowStack; \
	teavm_shadowStack.header.next = teavm_stackTop; \
	teavm_shadowStack.header.size = (sz); \
	teavm_stackTop = &teavm_shadowStack.header
#define TEAVM_RELEASE_STACK (teavm_stackTop = teavm_shadowStack.header.next)
#define TEAVM_GC_ROOT(index, ptr) teavm_shadowStack.data[index] = ptr
#define TEAVM_GC_ROOT_RELEASE(index) teavm_shadowStack.data[index] = NULL
#define TEAVM_WITH_CALL_SITE_ID(id, expr) ((teavm_shadowStack.header.callSiteId = (id)), (expr))

inline static int32_t teavm_checkBounds(int32_t index, void* array) {
	if (index < 0 || index >= ((TeaVM_Array*) (array))->size) {
		teavm_throwArrayIndexOutOfBoundsException();
		__builtin_unreachable();
	}
	return index;
}

void clinit() {
    TeaVM_Array* teavm_local_1;
    TeaVM_Array* teavm_local_2;
    int32_t teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    TEAVM_ALLOC_STACK(INT32_C(1));
    sfld_crc_table = NULL;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(478, allocateArray(&Arr_I_Cls, INT32_C(256)));
    teavm_local_2 = teavm_local_1;
    sfld_crc_table = teavm_local_1;
    teavm_local_3 = INT32_C(0);
    while (1) {
        if (!(teavm_local_3 < INT32_C(256))) break;
        teavm_local_4 = INT32_C(8);
        teavm_local_5 = teavm_local_3;
        while (1) {
            teavm_local_4 = (teavm_local_4 + -INT32_C(1));
            if ((teavm_local_4 < INT32_C(0))) {
                goto teavm_label_2;
            }
            if ((!(teavm_local_5 & INT32_C(1)))) {
                teavm_local_5 = ((int32_t) ((uint32_t) teavm_local_5 >> INT32_C(1)));
                goto teavm_cnt_2;
            }
            teavm_local_5 = (-INT32_C(306674912) ^ ((int32_t) ((uint32_t) teavm_local_5 >> INT32_C(1))));
        teavm_cnt_2:;
        }
    teavm_label_2:;
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(479, teavm_checkBounds(teavm_local_3, teavm_local_2));
        TEAVM_ARRAY_AT(teavm_local_2, int32_t, teavm_local_3) = teavm_local_5;
        teavm_local_3 = (teavm_local_3 + INT32_C(1));
    }
    TEAVM_RELEASE_STACK;
}
