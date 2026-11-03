#include "MarkQueue.h"
#include "../../../j/l/Object.h"
#include "../../../../heaptrace.h"
#include "ExceptionHandling.h"
#include "../../../../strings.h"

int32_t sfld_otr_MarkQueue_head;
int32_t sfld_otr_MarkQueue_tail;
int32_t sfld_otr_MarkQueue_limit;
void meth_otr_MarkQueue_init() {
    sfld_otr_MarkQueue_head = INT32_C(0);
    sfld_otr_MarkQueue_tail = INT32_C(0);
    sfld_otr_MarkQueue_limit = (teavm_gc_gcStorageSize / INT32_C(4));
}
void meth_otr_MarkQueue_enqueue(void* teavm_local_1) {
    int32_t teavm_local_2;
    (*(int32_t*) TEAVM_ADDRESS_ADD(teavm_gc_gcStorageAddress, (INT32_C(4) * sfld_otr_MarkQueue_tail)) = meth_otr_MarkQueue_pack(teavm_local_1));
    teavm_local_2 = (sfld_otr_MarkQueue_tail + INT32_C(1));
    sfld_otr_MarkQueue_tail = teavm_local_2;
    if ((teavm_local_2 >= sfld_otr_MarkQueue_limit)) {
        sfld_otr_MarkQueue_tail = INT32_C(0);
    }
    if ((sfld_otr_MarkQueue_tail == sfld_otr_MarkQueue_head)) {
        meth_otr_ExceptionHandling_printStack();
        teavm_outOfMemory();
    }
}
void* meth_otr_MarkQueue_dequeue() {
    void* teavm_local_1;
    int32_t teavm_local_2;
    teavm_local_1 = meth_otr_MarkQueue_unpack((*(int32_t*) TEAVM_ADDRESS_ADD(teavm_gc_gcStorageAddress, (INT32_C(4) * sfld_otr_MarkQueue_head))));
    teavm_local_2 = (sfld_otr_MarkQueue_head + INT32_C(1));
    sfld_otr_MarkQueue_head = teavm_local_2;
    if ((teavm_local_2 >= sfld_otr_MarkQueue_limit)) {
        sfld_otr_MarkQueue_head = INT32_C(0);
    }
    return teavm_local_1;
}
int32_t meth_otr_MarkQueue_pack(void* teavm_local_1) {
    return ((int32_t) ((int64_t) ((uint64_t) (((int64_t) (intptr_t) teavm_local_1) - ((int64_t) (intptr_t) teavm_gc_heapAddress)) >> INT32_C(2))));
}
void* meth_otr_MarkQueue_unpack(int32_t teavm_local_1) {
    return TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, (((int64_t) teavm_local_1) << INT32_C(2)));
}
int32_t meth_otr_MarkQueue_isEmpty() {
    return ((sfld_otr_MarkQueue_head != sfld_otr_MarkQueue_tail) ? INT32_C(0) : INT32_C(1));
}
int32_t supertypeof_otr_MarkQueue(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 221 || tag >= 223) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) otr_MarkQueue_VT otr_MarkQueue_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otr_MarkQueue), sizeof(void*)),
            .flags = 0,
            .tag = 221,
            .modifiers = 16,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_otr_MarkQueue,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
void sysinitclass_otr_MarkQueue() {
    sfld_otr_MarkQueue_head = INT32_C(0);
    sfld_otr_MarkQueue_tail = INT32_C(0);
    sfld_otr_MarkQueue_limit = INT32_C(0);
}
