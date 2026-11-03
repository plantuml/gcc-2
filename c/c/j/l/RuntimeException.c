#include "RuntimeException.h"
#include "Exception.h"
#include "../../../strings.h"
#include "Object.h"

int32_t supertypeof_jl_RuntimeException(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 51 || tag >= 85) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_RuntimeException_VT jl_RuntimeException_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_RuntimeException), sizeof(void*)),
                    .flags = 0,
                    .tag = 51,
                    .modifiers = 1,
                    .name = NULL,
                    .arrayType = NULL,
                    .itemType = NULL,
                    .isSupertypeOf = &supertypeof_jl_RuntimeException,
                    .superclass = (TeaVM_Class*) &jl_Exception_Cls,
                    .layout = NULL,
                    .enumValues = NULL
                },
                .virt_clone = &meth_jl_Object_clone
            }
        }
    }
};
void sysinitclass_jl_RuntimeException() {
}
