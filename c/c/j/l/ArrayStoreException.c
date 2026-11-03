#include "ArrayStoreException.h"
#include "RuntimeException.h"
#include "../../../strings.h"
#include "Object.h"

int32_t supertypeof_jl_ArrayStoreException(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 68 || tag >= 70) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_ArrayStoreException_VT jl_ArrayStoreException_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .parent = {
                        .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_ArrayStoreException), sizeof(void*)),
                        .flags = 0,
                        .tag = 68,
                        .modifiers = 1,
                        .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(28),
                        .arrayType = NULL,
                        .itemType = NULL,
                        .isSupertypeOf = &supertypeof_jl_ArrayStoreException,
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
void sysinitclass_jl_ArrayStoreException() {
}
