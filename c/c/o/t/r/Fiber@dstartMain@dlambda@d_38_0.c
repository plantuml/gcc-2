#include "Fiber@dstartMain@dlambda@d_38_0.h"
#include "../../../j/l/Object.h"
#include "Fiber.h"
#include "../../../../strings.h"

void meth_otr_Fiber_startMain_lambda__38_0__init_(void* teavm_this_, TeaVM_Array* teavm_local_1) {
    teavm_gc_writeBarrier(teavm_this_);
    TEAVM_FIELD(teavm_this_, cls_otr_Fiber_startMain_lambda__38_0, fld__0) = teavm_local_1;
}
void meth_otr_Fiber_startMain_lambda__38_0_run(void* teavm_this_) {
    TeaVM_Array* teavm_local_1;
    TEAVM_ALLOC_STACK(INT32_C(1));
    teavm_local_1 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber_startMain_lambda__38_0, fld__0);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    TEAVM_WITH_CALL_SITE_ID(138, meth_otr_Fiber_lambda_startMain_0(teavm_local_1));
    TEAVM_RELEASE_STACK;
}
int32_t supertypeof_otr_Fiber_startMain_lambda__38_0(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 107 || tag >= 109) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_otr_Fiber_startMain_lambda__38_0_Cls[2];
alignas(8) otr_Fiber_startMain_lambda__38_0_VT otr_Fiber_startMain_lambda__38_0_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otr_Fiber_startMain_lambda__38_0), sizeof(void*)),
            .flags = 0,
            .tag = 107,
            .modifiers = 1,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_otr_Fiber_startMain_lambda__38_0,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_otr_Fiber_startMain_lambda__38_0_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static int16_t teavm_classLayouts_otr_Fiber_startMain_lambda__38_0_Cls[2] = {
INT16_C(1), (int16_t) offsetof(cls_otr_Fiber_startMain_lambda__38_0, fld__0)
};
void sysinitclass_otr_Fiber_startMain_lambda__38_0() {
}
