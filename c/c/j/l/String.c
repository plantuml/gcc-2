#include "String.h"
#include "Object.h"
#include "../../../a/p/char.h"
#include "../../o/t/r/Allocator.h"
#include "System.h"
#include "String@d@lclinit@g@dlambda@d_118_0.h"
#include "../../../strings.h"

TeaVM_Array* sfld_jl_String_EMPTY_CHARS;
void* sfld_jl_String_EMPTY;
void* sfld_jl_String_CASE_INSENSITIVE_ORDER;
void meth_jl_String__init_(void* teavm_this_, TeaVM_Array* teavm_local_1) {
    TeaVM_Array* teavm_local_2;
    int32_t teavm_local_3;
    TEAVM_ALLOC_STACK(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_WITH_CALL_SITE_ID(0, teavm_initializeClass((TeaVM_Class*) &jl_String_Cls, &initclass_jl_String));
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(1, teavm_nullCheck(teavm_local_1));
    teavm_local_3 = TEAVM_ARRAY_LENGTH(teavm_local_2);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(2, meth_otr_Allocator_allocateArray(&Arr_C_Cls, teavm_local_3));
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_1);
    TEAVM_WITH_CALL_SITE_ID(3, meth_jl_System_fastArraycopy(teavm_local_2, INT32_C(0), teavm_local_1, INT32_C(0), teavm_local_3));
    teavm_gc_writeBarrier(teavm_this_);
    TEAVM_FIELD(teavm_this_, TeaVM_String, characters) = teavm_local_1;
    TEAVM_RELEASE_STACK;
}
void meth_jl_String__clinit_() {
    TeaVM_Array* teavm_local_1;
    void* teavm_local_2;
    TEAVM_ALLOC_STACK(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(4, meth_otr_Allocator_allocateArray(&Arr_C_Cls, INT32_C(0)));
    sfld_jl_String_EMPTY_CHARS = teavm_local_1;
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(5, meth_otr_Allocator_allocate(&jl_String_Cls));
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_2);
    TEAVM_WITH_CALL_SITE_ID(6, teavm_initializeClass((TeaVM_Class*) &jl_String_Cls, &initclass_jl_String));
    teavm_gc_writeBarrier(teavm_local_2);
    TEAVM_FIELD(teavm_local_2, TeaVM_String, characters) = teavm_local_1;
    sfld_jl_String_EMPTY = teavm_local_2;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    sfld_jl_String_CASE_INSENSITIVE_ORDER = TEAVM_WITH_CALL_SITE_ID(7, meth_otr_Allocator_allocate(&jl_String__clinit__lambda__118_0_Cls));
    TEAVM_RELEASE_STACK;
}
void initclass_jl_String() {
    TeaVM_Class* cls = (TeaVM_Class*) &jl_String_Cls;
    if (!(cls->flags & INT32_C(1))) {
        cls->flags |= INT32_C(1);
        meth_jl_String__clinit_();
    }
}
int32_t supertypeof_jl_String(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 1 || tag >= 3) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_jl_String_Cls[2];
alignas(8) jl_String_VT jl_String_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(TeaVM_String), sizeof(void*)),
            .flags = 0,
            .tag = 1,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jl_String,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_jl_String_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static void** teavm_gc_localStaticRoots_jl_String_Cls[3] = {
(void**) &sfld_jl_String_EMPTY_CHARS, (void**) &sfld_jl_String_EMPTY, (void**) &sfld_jl_String_CASE_INSENSITIVE_ORDER
};
static int16_t teavm_classLayouts_jl_String_Cls[2] = {
INT16_C(1), (int16_t) offsetof(TeaVM_String, characters)
};
void sysinitclass_jl_String() {
sfld_jl_String_EMPTY_CHARS = NULL;
sfld_jl_String_EMPTY = NULL;
sfld_jl_String_CASE_INSENSITIVE_ORDER = NULL;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_jl_String_Cls, 3);
}
