#include "Number.h"
#include "Object.h"
#include "../../../strings.h"

int32_t supertypeof_jl_Number(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 149 || tag >= 155) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_Number_VT jl_Number_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_Number), sizeof(void*)),
            .flags = 0,
            .tag = 149,
            .modifiers = 1025,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jl_Number,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
void sysinitclass_jl_Number() {
}
