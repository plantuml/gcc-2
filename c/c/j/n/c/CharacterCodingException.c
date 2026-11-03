#include "CharacterCodingException.h"
#include "../../i/IOException.h"
#include "../../../../strings.h"
#include "../../l/Object.h"

int32_t supertypeof_jnc_CharacterCodingException(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 86 || tag >= 92) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jnc_CharacterCodingException_VT jnc_CharacterCodingException_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .parent = {
                        .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnc_CharacterCodingException), sizeof(void*)),
                        .flags = 0,
                        .tag = 86,
                        .modifiers = 1,
                        .name = NULL,
                        .arrayType = NULL,
                        .itemType = NULL,
                        .isSupertypeOf = &supertypeof_jnc_CharacterCodingException,
                        .superclass = (TeaVM_Class*) &ji_IOException_Cls,
                        .layout = NULL,
                        .enumValues = NULL
                    },
                    .virt_clone = &meth_jl_Object_clone
                }
            }
        }
    }
};
void sysinitclass_jnc_CharacterCodingException() {
}
