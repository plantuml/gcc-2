#include "OutputStream.h"
#include "../l/Object.h"
#include "../../../strings.h"

int32_t supertypeof_ji_OutputStream(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 189 || tag >= 199) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) ji_OutputStream_VT ji_OutputStream_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_ji_OutputStream), sizeof(void*)),
            .flags = 0,
            .tag = 189,
            .modifiers = 1025,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_ji_OutputStream,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
void sysinitclass_ji_OutputStream() {
}
