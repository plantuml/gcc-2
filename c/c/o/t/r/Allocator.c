#include "Allocator.h"
#include "../../../j/l/Object.h"
#include "GC.h"
#include <string.h>
#include "RuntimeObject.h"
#include "RuntimeClass.h"
#include "RuntimeArray.h"
#include "../../../../strings.h"

void* meth_otr_Allocator_allocate(void* teavm_local_1) {
    void* teavm_local_2;
    teavm_local_2 = meth_otr_GC_alloc(TEAVM_FIELD(teavm_local_1, TeaVM_Class, size));
    memset(teavm_local_2, 0, TEAVM_FIELD(teavm_local_1, TeaVM_Class, size));
    TEAVM_FIELD(teavm_local_2, TeaVM_Object, header) = TEAVM_PACK_CLASS(teavm_local_1);
    return teavm_local_2;
}
void* meth_otr_Allocator_allocateArray(void* teavm_local_1, int32_t teavm_local_2) {
    int32_t teavm_local_3;
    void* teavm_local_4;
    void* teavm_local_5;
    teavm_local_3 = ((!meth_otr_RuntimeClass_isPrimitive(TEAVM_FIELD(teavm_local_1, TeaVM_Class, itemType))) ? sizeof(void*) : TEAVM_FIELD(TEAVM_FIELD(teavm_local_1, TeaVM_Class, itemType), TeaVM_Class, size));
    teavm_local_3 = ((int32_t) (intptr_t) TEAVM_ALIGN(((void*) (intptr_t) (((int32_t) (intptr_t) TEAVM_ALIGN(((void*) (intptr_t) sizeof(TeaVM_Array)), teavm_local_3)) + (teavm_local_3 * teavm_local_2))), sizeof(void*)));
    teavm_local_4 = meth_otr_GC_alloc(teavm_local_3);
    memset(teavm_local_4, 0, teavm_local_3);
    teavm_local_5 = teavm_local_4;
    TEAVM_FIELD(teavm_local_5, TeaVM_Object, header) = TEAVM_PACK_CLASS(teavm_local_1);
    TEAVM_FIELD(teavm_local_5, TeaVM_Array, size) = teavm_local_2;
    return teavm_local_4;
}
void* meth_otr_Allocator_allocateMultiArray(void* teavm_local_1, void* teavm_local_2, int32_t teavm_local_3) {
    int32_t teavm_local_4;
    void* teavm_local_5;
    void* teavm_local_6;
    int32_t teavm_local_7;
    int32_t teavm_local_8;
    teavm_local_4 = (*(int32_t*) teavm_local_2);
    teavm_local_5 = meth_otr_Allocator_allocateArray(teavm_local_1, (*(int32_t*) teavm_local_2));
    if ((teavm_local_3 > INT32_C(1))) {
        teavm_local_6 = TEAVM_ALIGN(TEAVM_STRUCTURE_ADD(TeaVM_Array, teavm_local_5, INT32_C(1)), sizeof(void*));
        teavm_local_7 = INT32_C(0);
        teavm_local_8 = (teavm_local_3 - INT32_C(1));
        while (1) {
            if ((teavm_local_7 >= teavm_local_4)) {
                goto teavm_label_1;
            }
            (*(void**) teavm_local_6 = meth_otr_Allocator_allocateMultiArray(TEAVM_FIELD(teavm_local_1, TeaVM_Class, itemType), TEAVM_ADDRESS_ADD(teavm_local_2, INT32_C(4)), teavm_local_8));
            teavm_local_6 = TEAVM_ADDRESS_ADD(teavm_local_6, sizeof(void*));
            teavm_local_7 = (teavm_local_7 + INT32_C(1));
        }
    }
teavm_label_1:;
    return teavm_local_5;
}
int32_t supertypeof_otr_Allocator(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 43 || tag >= 45) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) otr_Allocator_VT otr_Allocator_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otr_Allocator), sizeof(void*)),
            .flags = 0,
            .tag = 43,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_otr_Allocator,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
void sysinitclass_otr_Allocator() {
}
