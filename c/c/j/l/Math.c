#include "Math.h"
#include "Object.h"
#include "../../../strings.h"

int32_t supertypeof_jl_Math(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 141 || tag >= 143) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_Math_VT jl_Math_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_Math), sizeof(void*)),
            .flags = 0,
            .tag = 141,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jl_Math,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
void sysinitclass_jl_Math() {
}
