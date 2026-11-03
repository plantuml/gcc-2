#include "ReadOnlyBufferException.h"
#include "../l/UnsupportedOperationException.h"
#include "../../../strings.h"
#include "../l/Object.h"

int32_t supertypeof_jn_ReadOnlyBufferException(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 73 || tag >= 75) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jn_ReadOnlyBufferException_VT jn_ReadOnlyBufferException_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .parent = {
                        .parent = {
                            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jn_ReadOnlyBufferException), sizeof(void*)),
                            .flags = 0,
                            .tag = 73,
                            .modifiers = 1,
                            .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(36),
                            .arrayType = NULL,
                            .itemType = NULL,
                            .isSupertypeOf = &supertypeof_jn_ReadOnlyBufferException,
                            .superclass = (TeaVM_Class*) &jl_UnsupportedOperationException_Cls,
                            .layout = NULL,
                            .enumValues = NULL
                        },
                        .virt_clone = &meth_jl_Object_clone
                    }
                }
            }
        }
    }
};
void sysinitclass_jn_ReadOnlyBufferException() {
}
