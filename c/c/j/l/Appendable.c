#include "Appendable.h"
#include "../../../strings.h"

int32_t supertypeof_jl_Appendable(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 156 || tag >= 193) return INT32_C(0);
    if (tag >= 158 && tag < 168) return INT32_C(0);
    if (tag >= 174 && tag < 191) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class jl_Appendable_Cls = {
    .size = 0,
    .flags = 0,
    .tag = 156,
    .modifiers = 1537,
    .name = NULL,
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_jl_Appendable,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
};
void sysinitclass_jl_Appendable() {
}
