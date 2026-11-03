#include "CharSequence.h"
#include "../../../strings.h"

int32_t supertypeof_jl_CharSequence(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 1 || tag >= 174) return INT32_C(0);
    if (tag >= 3 && tag < 155) return INT32_C(0);
    if (tag >= 159 && tag < 168) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class jl_CharSequence_Cls = {
    .size = 0,
    .flags = 0,
    .tag = 1,
    .modifiers = 1537,
    .name = NULL,
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_jl_CharSequence,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
};
void sysinitclass_jl_CharSequence() {
}
