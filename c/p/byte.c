#include "byte.h"
#include "../a/p/byte.h"
#include "../strings.h"

int32_t supertypeof_B(TeaVM_Class* supercls, TeaVM_Class* cls) {
    return INT32_C(0);
}
alignas(8) TeaVM_Class B_Cls = {
    .size = sizeof(int8_t),
    .flags = 32,
    .tag = 2147483647,
    .modifiers = 0,
    .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(50),
    .arrayType = (TeaVM_Class*) &Arr_B_Cls,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_B,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
}
;
void sysinitclass_B() {
}
