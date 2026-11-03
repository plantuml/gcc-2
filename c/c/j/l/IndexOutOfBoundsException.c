#include "IndexOutOfBoundsException.h"
#include "RuntimeException.h"
#include "../../../strings.h"
#include "Object.h"

int32_t supertypeof_jl_IndexOutOfBoundsException(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 56 || tag >= 62) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_IndexOutOfBoundsException_VT jl_IndexOutOfBoundsException_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .parent = {
                        .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_IndexOutOfBoundsException), sizeof(void*)),
                        .flags = 0,
                        .tag = 56,
                        .modifiers = 1,
                        .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(9),
                        .arrayType = NULL,
                        .itemType = NULL,
                        .isSupertypeOf = &supertypeof_jl_IndexOutOfBoundsException,
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
void sysinitclass_jl_IndexOutOfBoundsException() {
}
