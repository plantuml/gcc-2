#include "AssertionError.h"
#include "Error.h"
#include "../../../strings.h"
#include "Object.h"

int32_t supertypeof_jl_AssertionError(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 95 || tag >= 97) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_AssertionError_VT jl_AssertionError_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_AssertionError), sizeof(void*)),
                    .flags = 0,
                    .tag = 95,
                    .modifiers = 1,
                    .name = NULL,
                    .arrayType = NULL,
                    .itemType = NULL,
                    .isSupertypeOf = &supertypeof_jl_AssertionError,
                    .superclass = (TeaVM_Class*) &jl_Error_Cls,
                    .layout = NULL,
                    .enumValues = NULL
                },
                .virt_clone = &meth_jl_Object_clone
            }
        }
    }
};
void sysinitclass_jl_AssertionError() {
}
