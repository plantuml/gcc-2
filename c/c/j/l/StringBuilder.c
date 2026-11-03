#include "StringBuilder.h"
#include "AbstractStringBuilder.h"
#include "../../../strings.h"
#include "Object.h"

int32_t supertypeof_jl_StringBuilder(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 156 || tag >= 158) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_StringBuilder_VT jl_StringBuilder_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_StringBuilder), sizeof(void*)),
                .flags = 0,
                .tag = 156,
                .modifiers = 1,
                .name = NULL,
                .arrayType = NULL,
                .itemType = NULL,
                .isSupertypeOf = &supertypeof_jl_StringBuilder,
                .superclass = (TeaVM_Class*) &jl_AbstractStringBuilder_Cls,
                .layout = NULL,
                .enumValues = NULL
            },
            .virt_clone = &meth_jl_Object_clone
        }
    }
};
void sysinitclass_jl_StringBuilder() {
}
