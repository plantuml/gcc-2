#include "IOException.h"
#include "../l/Exception.h"
#include "../../../strings.h"
#include "../l/Object.h"

int32_t supertypeof_ji_IOException(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 85 || tag >= 93) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) ji_IOException_VT ji_IOException_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_ji_IOException), sizeof(void*)),
                    .flags = 0,
                    .tag = 85,
                    .modifiers = 1,
                    .name = NULL,
                    .arrayType = NULL,
                    .itemType = NULL,
                    .isSupertypeOf = &supertypeof_ji_IOException,
                    .superclass = (TeaVM_Class*) &jl_Exception_Cls,
                    .layout = NULL,
                    .enumValues = NULL
                },
                .virt_clone = &meth_jl_Object_clone
            }
        }
    }
};
void sysinitclass_ji_IOException() {
}
