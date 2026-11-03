#include "Array.h"
#include "../Object.h"
#include "../../../../strings.h"

int32_t supertypeof_jlr_Array(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 143 || tag >= 145) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jlr_Array_VT jlr_Array_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jlr_Array), sizeof(void*)),
            .flags = 0,
            .tag = 143,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jlr_Array,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
void sysinitclass_jlr_Array() {
}
