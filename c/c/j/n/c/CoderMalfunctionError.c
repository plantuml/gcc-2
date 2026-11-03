#include "CoderMalfunctionError.h"
#include "../../l/Error.h"
#include "../../../../strings.h"
#include "../../l/Object.h"

int32_t supertypeof_jnc_CoderMalfunctionError(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 97 || tag >= 99) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jnc_CoderMalfunctionError_VT jnc_CoderMalfunctionError_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnc_CoderMalfunctionError), sizeof(void*)),
                    .flags = 0,
                    .tag = 97,
                    .modifiers = 1,
                    .name = NULL,
                    .arrayType = NULL,
                    .itemType = NULL,
                    .isSupertypeOf = &supertypeof_jnc_CoderMalfunctionError,
                    .superclass = (TeaVM_Class*) &jl_Error_Cls,
                    .layout = NULL,
                    .enumValues = NULL
                },
                .virt_clone = &meth_jl_Object_clone
            }
        }
    }
};
void sysinitclass_jnc_CoderMalfunctionError() {
}
