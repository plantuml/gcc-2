#include "void.h"
#include "../strings.h"

int32_t supertypeof_V(TeaVM_Class* supercls, TeaVM_Class* cls) {
    return INT32_C(0);
}
alignas(8) TeaVM_Class V_Cls = {
    .size = 0,
    .flags = 144,
    .tag = 0,
    .modifiers = 0,
    .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(49),
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_V,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
}
;
void sysinitclass_V() {
}
