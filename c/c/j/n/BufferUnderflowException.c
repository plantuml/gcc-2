#include "BufferUnderflowException.h"
#include "../l/RuntimeException.h"
#include "../../../strings.h"
#include "../l/Object.h"

int32_t supertypeof_jn_BufferUnderflowException(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 82 || tag >= 84) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jn_BufferUnderflowException_VT jn_BufferUnderflowException_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .parent = {
                        .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jn_BufferUnderflowException), sizeof(void*)),
                        .flags = 0,
                        .tag = 82,
                        .modifiers = 1,
                        .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(38),
                        .arrayType = NULL,
                        .itemType = NULL,
                        .isSupertypeOf = &supertypeof_jn_BufferUnderflowException,
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
void sysinitclass_jn_BufferUnderflowException() {
}
