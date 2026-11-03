#include "Comparable.h"
#include "../../../strings.h"

int32_t supertypeof_jl_Comparable(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 1 || tag >= 217) return INT32_C(0);
    if (tag >= 3 && tag < 150) return INT32_C(0);
    if (tag >= 152 && tag < 152) return INT32_C(0);
    if (tag >= 154 && tag < 168) return INT32_C(0);
    if (tag >= 174 && tag < 174) return INT32_C(0);
    if (tag >= 178 && tag < 179) return INT32_C(0);
    if (tag >= 189 && tag < 215) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class jl_Comparable_Cls = {
    .size = 0,
    .flags = 0,
    .tag = 1,
    .modifiers = 1537,
    .name = NULL,
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_jl_Comparable,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
};
void sysinitclass_jl_Comparable() {
}
