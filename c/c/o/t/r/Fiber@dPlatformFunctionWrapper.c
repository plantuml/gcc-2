#include "Fiber@dPlatformFunctionWrapper.h"
#include "../../../j/l/Object.h"
#include "../../../../strings.h"

int32_t supertypeof_otr_Fiber_PlatformFunctionWrapper(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 119 || tag >= 121) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_otr_Fiber_PlatformFunctionWrapper_Cls[2];
alignas(8) otr_Fiber_PlatformFunctionWrapper_VT otr_Fiber_PlatformFunctionWrapper_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otr_Fiber_PlatformFunctionWrapper), sizeof(void*)),
            .flags = 0,
            .tag = 119,
            .modifiers = 1,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_otr_Fiber_PlatformFunctionWrapper,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_otr_Fiber_PlatformFunctionWrapper_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static int16_t teavm_classLayouts_otr_Fiber_PlatformFunctionWrapper_Cls[2] = {
INT16_C(1), (int16_t) offsetof(cls_otr_Fiber_PlatformFunctionWrapper, fld_object)
};
void sysinitclass_otr_Fiber_PlatformFunctionWrapper() {
}
