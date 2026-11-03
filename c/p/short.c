#include "short.h"
#include "../a/p/short.h"
#include "../strings.h"

int32_t supertypeof_S(TeaVM_Class* supercls, TeaVM_Class* cls) {
    return INT32_C(0);
}
alignas(8) TeaVM_Class S_Cls = {
    .size = sizeof(int16_t),
    .flags = 48,
    .tag = 2147483647,
    .modifiers = 0,
    .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(52),
    .arrayType = (TeaVM_Class*) &Arr_S_Cls,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_S,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
}
;
void sysinitclass_S() {
}
