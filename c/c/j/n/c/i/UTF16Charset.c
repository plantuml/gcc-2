#include "UTF16Charset.h"
#include "../Charset.h"
#include "../../../../../strings.h"
#include "../../../l/Object.h"

int32_t supertypeof_jnci_UTF16Charset(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 186 || tag >= 188) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jnci_UTF16Charset_VT jnci_UTF16Charset_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnci_UTF16Charset), sizeof(void*)),
                .flags = 0,
                .tag = 186,
                .modifiers = 1,
                .name = NULL,
                .arrayType = NULL,
                .itemType = NULL,
                .isSupertypeOf = &supertypeof_jnci_UTF16Charset,
                .superclass = (TeaVM_Class*) &jnc_Charset_Cls,
                .layout = NULL,
                .enumValues = NULL
            },
            .virt_clone = &meth_jl_Object_clone
        }
    }
};
void sysinitclass_jnci_UTF16Charset() {
}
