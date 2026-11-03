#include "int.h"
#include "../../c/j/l/Object.h"
#include "../../p/int.h"
#include "../../strings.h"

int32_t supertypeof_Arr_I(TeaVM_Class* supercls, TeaVM_Class* cls) {
    TeaVM_Class* itemType = cls->itemType;
    if (itemType == NULL) return INT32_C(0);
    return itemType == &I_Cls;
}
alignas(8) jl_Object_VT Arr_I_Cls = {
    .parent = {
        .size = sizeof(int32_t),
        .flags = 0,
        .tag = 0,
        .modifiers = 0,
        .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(42),
        .arrayType = NULL,
        .itemType = (TeaVM_Class*) &I_Cls,
        .isSupertypeOf = &supertypeof_Arr_I,
        .superclass = (TeaVM_Class*) &jl_Object_Cls,
        .layout = NULL,
        .enumValues = NULL
    },
    .virt_clone = &meth_jl_Object_clone
};
void sysinitclass_Arr_I() {
}
