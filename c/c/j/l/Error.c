#include "Error.h"
#include "Throwable.h"
#include "../../../strings.h"
#include "Object.h"

int32_t supertypeof_jl_Error(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 94 || tag >= 100) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_Error_VT jl_Error_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_Error), sizeof(void*)),
                .flags = 0,
                .tag = 94,
                .modifiers = 1,
                .name = NULL,
                .arrayType = NULL,
                .itemType = NULL,
                .isSupertypeOf = &supertypeof_jl_Error,
                .superclass = (TeaVM_Class*) &jl_Throwable_Cls,
                .layout = NULL,
                .enumValues = NULL
            },
            .virt_clone = &meth_jl_Object_clone
        }
    }
};
void sysinitclass_jl_Error() {
}
