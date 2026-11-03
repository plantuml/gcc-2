#include "Cloneable.h"
#include "../../../strings.h"

int32_t supertypeof_jl_Cloneable(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 162 || tag >= 233) return INT32_C(0);
    if (tag >= 164 && tag < 229) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class jl_Cloneable_Cls = {
    .size = 0,
    .flags = 0,
    .tag = 162,
    .modifiers = 1537,
    .name = NULL,
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_jl_Cloneable,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
};
void sysinitclass_jl_Cloneable() {
}
