#include "double.h"
#include "../a/p/double.h"
#include "../strings.h"

int32_t supertypeof_D(TeaVM_Class* supercls, TeaVM_Class* cls) {
    return INT32_C(0);
}
alignas(8) TeaVM_Class D_Cls = {
    .size = sizeof(double),
    .flags = 128,
    .tag = 2147483647,
    .modifiers = 0,
    .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(47),
    .arrayType = (TeaVM_Class*) &Arr_D_Cls,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_D,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
}
;
void sysinitclass_D() {
}
