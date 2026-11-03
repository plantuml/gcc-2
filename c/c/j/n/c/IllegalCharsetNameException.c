#include "IllegalCharsetNameException.h"
#include "../../l/IllegalArgumentException.h"
#include "../../../../strings.h"
#include "../../l/Object.h"

int32_t supertypeof_jnc_IllegalCharsetNameException(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 63 || tag >= 65) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_jnc_IllegalCharsetNameException_Cls[2];
alignas(8) jnc_IllegalCharsetNameException_VT jnc_IllegalCharsetNameException_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .parent = {
                        .parent = {
                            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnc_IllegalCharsetNameException), sizeof(void*)),
                            .flags = 0,
                            .tag = 63,
                            .modifiers = 1,
                            .name = NULL,
                            .arrayType = NULL,
                            .itemType = NULL,
                            .isSupertypeOf = &supertypeof_jnc_IllegalCharsetNameException,
                            .superclass = (TeaVM_Class*) &jl_IllegalArgumentException_Cls,
                            .layout = teavm_classLayouts_jnc_IllegalCharsetNameException_Cls,
                            .enumValues = NULL
                        },
                        .virt_clone = &meth_jl_Object_clone
                    }
                }
            }
        }
    }
};
static int16_t teavm_classLayouts_jnc_IllegalCharsetNameException_Cls[2] = {
INT16_C(1), (int16_t) offsetof(cls_jnc_IllegalCharsetNameException, fld_charsetName)
};
void sysinitclass_jnc_IllegalCharsetNameException() {
}
