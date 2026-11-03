#include "CoderResult.h"
#include "../../l/Object.h"
#include "../../../o/t/r/Allocator.h"
#include "../../../../strings.h"

void* sfld_jnc_CoderResult_UNDERFLOW;
void* sfld_jnc_CoderResult_OVERFLOW;
void meth_jnc_CoderResult__clinit_() {
    void* teavm_local_1;
    TEAVM_ALLOC_STACK(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(798, meth_otr_Allocator_allocate(&jnc_CoderResult_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    TEAVM_WITH_CALL_SITE_ID(799, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
    TEAVM_FIELD(teavm_local_1, cls_jnc_CoderResult, fld_kind) = INT32_C(0);
    TEAVM_FIELD(teavm_local_1, cls_jnc_CoderResult, fld_length) = INT32_C(0);
    sfld_jnc_CoderResult_UNDERFLOW = teavm_local_1;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(800, meth_otr_Allocator_allocate(&jnc_CoderResult_Cls));
    TEAVM_FIELD(teavm_local_1, cls_jnc_CoderResult, fld_kind) = INT32_C(1);
    TEAVM_FIELD(teavm_local_1, cls_jnc_CoderResult, fld_length) = INT32_C(0);
    sfld_jnc_CoderResult_OVERFLOW = teavm_local_1;
    TEAVM_RELEASE_STACK;
}
void initclass_jnc_CoderResult() {
    TeaVM_Class* cls = (TeaVM_Class*) &jnc_CoderResult_Cls;
    if (!(cls->flags & INT32_C(1))) {
        cls->flags |= INT32_C(1);
        meth_jnc_CoderResult__clinit_();
    }
}
int32_t supertypeof_jnc_CoderResult(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 217 || tag >= 219) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jnc_CoderResult_VT jnc_CoderResult_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnc_CoderResult), sizeof(void*)),
            .flags = 0,
            .tag = 217,
            .modifiers = 1,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jnc_CoderResult,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static void** teavm_gc_localStaticRoots_jnc_CoderResult_Cls[2] = {
(void**) &sfld_jnc_CoderResult_UNDERFLOW, (void**) &sfld_jnc_CoderResult_OVERFLOW
};
void sysinitclass_jnc_CoderResult() {
sfld_jnc_CoderResult_UNDERFLOW = NULL;
sfld_jnc_CoderResult_OVERFLOW = NULL;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_jnc_CoderResult_Cls, 2);
}
