#include "StringIndexOutOfBoundsException.h"
#include "IndexOutOfBoundsException.h"
#include "../../../strings.h"
#include "Object.h"

int32_t supertypeof_jl_StringIndexOutOfBoundsException(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 59 || tag >= 61) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_StringIndexOutOfBoundsException_VT jl_StringIndexOutOfBoundsException_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .parent = {
                        .parent = {
                            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_StringIndexOutOfBoundsException), sizeof(void*)),
                            .flags = 0,
                            .tag = 59,
                            .modifiers = 1,
                            .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(33),
                            .arrayType = NULL,
                            .itemType = NULL,
                            .isSupertypeOf = &supertypeof_jl_StringIndexOutOfBoundsException,
                            .superclass = (TeaVM_Class*) &jl_IndexOutOfBoundsException_Cls,
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
void sysinitclass_jl_StringIndexOutOfBoundsException() {
}
