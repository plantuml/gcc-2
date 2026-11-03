#include "ShadowStack.h"
#include "../../../j/l/Object.h"
#include "../../../../strings.h"

int32_t supertypeof_otr_ShadowStack(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 103 || tag >= 105) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) otr_ShadowStack_VT otr_ShadowStack_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otr_ShadowStack), sizeof(void*)),
            .flags = 0,
            .tag = 103,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_otr_ShadowStack,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
void sysinitclass_otr_ShadowStack() {
}
