#include "long.h"
#include "../a/p/long.h"
#include "../strings.h"

int32_t supertypeof_J(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 150 || tag >= 152) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class J_Cls = {
    .size = sizeof(int64_t),
    .flags = 96,
    .tag = 2147483647,
    .modifiers = 0,
    .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(43),
    .arrayType = (TeaVM_Class*) &Arr_J_Cls,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_J,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
}
;
void sysinitclass_J() {
}
