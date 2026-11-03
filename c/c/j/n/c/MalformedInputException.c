#include "MalformedInputException.h"
#include "CharacterCodingException.h"
#include "../../../../strings.h"
#include "../../l/Object.h"

int32_t supertypeof_jnc_MalformedInputException(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 87 || tag >= 89) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jnc_MalformedInputException_VT jnc_MalformedInputException_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .parent = {
                        .parent = {
                            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnc_MalformedInputException), sizeof(void*)),
                            .flags = 0,
                            .tag = 87,
                            .modifiers = 1,
                            .name = NULL,
                            .arrayType = NULL,
                            .itemType = NULL,
                            .isSupertypeOf = &supertypeof_jnc_MalformedInputException,
                            .superclass = (TeaVM_Class*) &jnc_CharacterCodingException_Cls,
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
void sysinitclass_jnc_MalformedInputException() {
}
