#include "char.h"
#include "../a/p/char.h"
#include "../strings.h"

int32_t supertypeof_C(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 215 || tag >= 217) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class C_Cls = {
    .size = sizeof(char16_t),
    .flags = 64,
    .tag = 2147483647,
    .modifiers = 0,
    .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(39),
    .arrayType = (TeaVM_Class*) &Arr_C_Cls,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_C,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
}
;
void sysinitclass_C() {
}
