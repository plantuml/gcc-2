#include "UnsupportedOperationException.h"
#include "RuntimeException.h"
#include "../../../strings.h"
#include "Object.h"

int32_t supertypeof_jl_UnsupportedOperationException(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 72 || tag >= 76) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_UnsupportedOperationException_VT jl_UnsupportedOperationException_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .parent = {
                        .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_UnsupportedOperationException), sizeof(void*)),
                        .flags = 0,
                        .tag = 72,
                        .modifiers = 1,
                        .name = NULL,
                        .arrayType = NULL,
                        .itemType = NULL,
                        .isSupertypeOf = &supertypeof_jl_UnsupportedOperationException,
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
void sysinitclass_jl_UnsupportedOperationException() {
}
