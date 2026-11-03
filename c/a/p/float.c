#include "float.h"
#include "../../c/j/l/Object.h"
#include "../../p/float.h"
#include "../../strings.h"

int32_t supertypeof_Arr_F(TeaVM_Class* supercls, TeaVM_Class* cls) {
    TeaVM_Class* itemType = cls->itemType;
    if (itemType == NULL) return INT32_C(0);
    return itemType == &F_Cls;
}
alignas(8) jl_Object_VT Arr_F_Cls = {
    .parent = {
        .size = sizeof(float),
        .flags = 0,
        .tag = 0,
        .modifiers = 0,
        .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(46),
        .arrayType = NULL,
        .itemType = (TeaVM_Class*) &F_Cls,
        .isSupertypeOf = &supertypeof_Arr_F,
        .superclass = (TeaVM_Class*) &jl_Object_Cls,
        .layout = NULL,
        .enumValues = NULL
    },
    .virt_clone = &meth_jl_Object_clone
};
void sysinitclass_Arr_F() {
}
