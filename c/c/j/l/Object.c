#include "Object.h"
#include "../../o/t/r/RuntimeObject.h"
#include "../../../core.h"
#include "../../o/t/r/RuntimeClass.h"
#include "../../o/t/r/Allocator.h"
#include "../../o/t/r/RuntimeArray.h"
#include <string.h>
#include "../../../strings.h"

void meth_jl_Object__init_(void* teavm_this_) {
    return;
}
void* meth_jl_Object_getClass(void* teavm_this_) {
    void* teavm_local_1;
    TEAVM_ALLOC_STACK(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(8, teavm_getClassObject((TeaVM_Class*) TEAVM_WITH_CALL_SITE_ID(9, TEAVM_CLASS_OF(teavm_this_))));
    TEAVM_RELEASE_STACK;
    return teavm_local_1;
}
void* meth_jl_Object_clone(void* teavm_this_) {
    return meth_jl_Object_cloneLowLevel(teavm_this_);
}
void* meth_jl_Object_cloneLowLevel(void* teavm_local_1) {
    void* teavm_local_2;
    int32_t teavm_local_3;
    void* teavm_local_4;
    int32_t teavm_local_5;
    void* teavm_local_6;
    int32_t teavm_local_7;
    void* teavm_local_8;
    teavm_local_2 = meth_otr_RuntimeClass_getClass(teavm_local_1);
    teavm_local_3 = sizeof(TeaVM_Object);
    if ((TEAVM_FIELD(teavm_local_2, TeaVM_Class, itemType) == NULL)) {
        teavm_local_4 = meth_otr_Allocator_allocate(teavm_local_2);
        teavm_local_5 = TEAVM_FIELD(teavm_local_2, TeaVM_Class, size);
    } else {
        teavm_local_6 = teavm_local_1;
        teavm_local_4 = meth_otr_Allocator_allocateArray(teavm_local_2, TEAVM_FIELD(teavm_local_6, TeaVM_Array, size));
        teavm_local_7 = ((!meth_otr_RuntimeClass_isPrimitive(teavm_local_2)) ? sizeof(void*) : TEAVM_FIELD(TEAVM_FIELD(teavm_local_2, TeaVM_Class, itemType), TeaVM_Class, size));
        teavm_local_8 = TEAVM_ALIGN(((void*) (intptr_t) sizeof(TeaVM_Array)), teavm_local_7);
        teavm_local_5 = ((teavm_local_7 * TEAVM_FIELD(teavm_local_6, TeaVM_Array, size)) + ((int32_t) (intptr_t) teavm_local_8));
    }
    if ((teavm_local_5 > teavm_local_3)) {
        memmove(TEAVM_ADDRESS_ADD(teavm_local_4, teavm_local_3), TEAVM_ADDRESS_ADD(teavm_local_1, teavm_local_3), (teavm_local_5 - teavm_local_3));
    }
    return teavm_local_4;
}
int32_t supertypeof_jl_Object(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 0 || tag >= 238) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_Object_VT jl_Object_Cls = {
    .parent = {
        .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(TeaVM_Object), sizeof(void*)),
        .flags = 0,
        .tag = 8,
        .modifiers = 1,
        .name = NULL,
        .arrayType = NULL,
        .itemType = NULL,
        .isSupertypeOf = &supertypeof_jl_Object,
        .superclass = NULL,
        .layout = NULL,
        .enumValues = NULL
    },
    .virt_clone = &meth_jl_Object_clone
};
void sysinitclass_jl_Object() {
}
