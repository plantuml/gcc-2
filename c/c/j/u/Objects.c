#include "Objects.h"
#include "../l/Object.h"
#include "../../../strings.h"

int32_t supertypeof_ju_Objects(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 219 || tag >= 221) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) ju_Objects_VT ju_Objects_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_ju_Objects), sizeof(void*)),
            .flags = 0,
            .tag = 219,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_ju_Objects,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
void sysinitclass_ju_Objects() {
}
