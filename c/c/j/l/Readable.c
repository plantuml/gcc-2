#include "Readable.h"
#include "../../../strings.h"

int32_t supertypeof_jl_Readable(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 168 || tag >= 174) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class jl_Readable_Cls = {
    .size = 0,
    .flags = 0,
    .tag = 168,
    .modifiers = 1537,
    .name = NULL,
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_jl_Readable,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
};
void sysinitclass_jl_Readable() {
}
