#include "byte.h"
#include "../../c/j/l/Object.h"
#include "../../p/byte.h"
#include "../../strings.h"

int32_t supertypeof_Arr_B(TeaVM_Class* supercls, TeaVM_Class* cls) {
    TeaVM_Class* itemType = cls->itemType;
    if (itemType == NULL) return INT32_C(0);
    return itemType == &B_Cls;
}
alignas(8) jl_Object_VT Arr_B_Cls = {
    .parent = {
        .size = sizeof(int8_t),
        .flags = 0,
        .tag = 0,
        .modifiers = 0,
        .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(51),
        .arrayType = NULL,
        .itemType = (TeaVM_Class*) &B_Cls,
        .isSupertypeOf = &supertypeof_Arr_B,
        .superclass = (TeaVM_Class*) &jl_Object_Cls,
        .layout = NULL,
        .enumValues = NULL
    },
    .virt_clone = &meth_jl_Object_clone
};
void sysinitclass_Arr_B() {
}
