#include "NegativeArraySizeException.h"
#include "RuntimeException.h"
#include "../../../strings.h"
#include "Object.h"

int32_t supertypeof_jl_NegativeArraySizeException(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 66 || tag >= 68) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_NegativeArraySizeException_VT jl_NegativeArraySizeException_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .parent = {
                        .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_NegativeArraySizeException), sizeof(void*)),
                        .flags = 0,
                        .tag = 66,
                        .modifiers = 1,
                        .name = NULL,
                        .arrayType = NULL,
                        .itemType = NULL,
                        .isSupertypeOf = &supertypeof_jl_NegativeArraySizeException,
                        .superclass = (TeaVM_Class*) &jl_RuntimeException_Cls,
                        .layout = NULL,
                        .enumValues = NULL
                    },
                    .virt_clone = &meth_jl_Object_clone
                }
            }
        }
    }
};
void sysinitclass_jl_NegativeArraySizeException() {
}
