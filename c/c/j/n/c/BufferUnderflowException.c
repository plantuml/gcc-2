#include "BufferUnderflowException.h"
#include "../../l/RuntimeException.h"
#include "../../../../strings.h"
#include "../../l/Object.h"

int32_t supertypeof_jnc_BufferUnderflowException(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 78 || tag >= 80) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jnc_BufferUnderflowException_VT jnc_BufferUnderflowException_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .parent = {
                        .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnc_BufferUnderflowException), sizeof(void*)),
                        .flags = 0,
                        .tag = 78,
                        .modifiers = 1,
                        .name = NULL,
                        .arrayType = NULL,
                        .itemType = NULL,
                        .isSupertypeOf = &supertypeof_jnc_BufferUnderflowException,
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
void sysinitclass_jnc_BufferUnderflowException() {
}
