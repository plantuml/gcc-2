#include "Memory.h"
#include "../../../../../j/l/Object.h"
#include "../../../../../../strings.h"

int32_t supertypeof_otbcr_Memory(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 223 || tag >= 225) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) otbcr_Memory_VT otbcr_Memory_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otbcr_Memory), sizeof(void*)),
            .flags = 0,
            .tag = 223,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_otbcr_Memory,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
void sysinitclass_otbcr_Memory() {
}
