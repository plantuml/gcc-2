#include "MemoryTrace.h"
#include "../../../j/l/Object.h"
#include "../../../../strings.h"

int32_t supertypeof_otr_MemoryTrace(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 135 || tag >= 137) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) otr_MemoryTrace_VT otr_MemoryTrace_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otr_MemoryTrace), sizeof(void*)),
            .flags = 0,
            .tag = 135,
            .modifiers = 1,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_otr_MemoryTrace,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
void sysinitclass_otr_MemoryTrace() {
}
