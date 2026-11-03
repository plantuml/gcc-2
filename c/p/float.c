#include "float.h"
#include "../a/p/float.h"
#include "../strings.h"

int32_t supertypeof_F(TeaVM_Class* supercls, TeaVM_Class* cls) {
    return INT32_C(0);
}
alignas(8) TeaVM_Class F_Cls = {
    .size = sizeof(float),
    .flags = 112,
    .tag = 2147483647,
    .modifiers = 0,
    .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(45),
    .arrayType = (TeaVM_Class*) &Arr_F_Cls,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_F,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
}
;
void sysinitclass_F() {
}
