#include "char.h"
#include "../../c/j/l/Object.h"
#include "../../p/char.h"
#include "../../strings.h"

int32_t supertypeof_Arr_C(TeaVM_Class* supercls, TeaVM_Class* cls) {
    TeaVM_Class* itemType = cls->itemType;
    if (itemType == NULL) return INT32_C(0);
    return itemType == &C_Cls;
}
alignas(8) jl_Object_VT Arr_C_Cls = {
    .parent = {
        .size = sizeof(char16_t),
        .flags = 0,
        .tag = 0,
        .modifiers = 0,
        .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(40),
        .arrayType = NULL,
        .itemType = (TeaVM_Class*) &C_Cls,
        .isSupertypeOf = &supertypeof_Arr_C,
        .superclass = (TeaVM_Class*) &jl_Object_Cls,
        .layout = NULL,
        .enumValues = NULL
    },
    .virt_clone = &meth_jl_Object_clone
};
void sysinitclass_Arr_C() {
}
