#include "short.h"
#include "../../c/j/l/Object.h"
#include "../../p/short.h"
#include "../../strings.h"

int32_t supertypeof_Arr_S(TeaVM_Class* supercls, TeaVM_Class* cls) {
    TeaVM_Class* itemType = cls->itemType;
    if (itemType == NULL) return INT32_C(0);
    return itemType == &S_Cls;
}
alignas(8) jl_Object_VT Arr_S_Cls = {
    .parent = {
        .size = sizeof(int16_t),
        .flags = 0,
        .tag = 0,
        .modifiers = 0,
        .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(53),
        .arrayType = NULL,
        .itemType = (TeaVM_Class*) &S_Cls,
        .isSupertypeOf = &supertypeof_Arr_S,
        .superclass = (TeaVM_Class*) &jl_Object_Cls,
        .layout = NULL,
        .enumValues = NULL
    },
    .virt_clone = &meth_jl_Object_clone
};
void sysinitclass_Arr_S() {
}
