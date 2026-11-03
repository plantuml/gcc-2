#include "int.h"
#include "../a/p/int.h"
#include "../strings.h"

int32_t supertypeof_I(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 152 || tag >= 154) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class I_Cls = {
    .size = sizeof(int32_t),
    .flags = 80,
    .tag = 2147483647,
    .modifiers = 0,
    .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(41),
    .arrayType = (TeaVM_Class*) &Arr_I_Cls,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_I,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
}
;
void sysinitclass_I() {
}
