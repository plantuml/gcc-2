#include "AsciiCharset.h"
#include "../Charset.h"
#include "../../../../../strings.h"
#include "../../../l/Object.h"

int32_t supertypeof_jnci_AsciiCharset(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 182 || tag >= 184) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jnci_AsciiCharset_VT jnci_AsciiCharset_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnci_AsciiCharset), sizeof(void*)),
                .flags = 0,
                .tag = 182,
                .modifiers = 1,
                .name = NULL,
                .arrayType = NULL,
                .itemType = NULL,
                .isSupertypeOf = &supertypeof_jnci_AsciiCharset,
                .superclass = (TeaVM_Class*) &jnc_Charset_Cls,
                .layout = NULL,
                .enumValues = NULL
            },
            .virt_clone = &meth_jl_Object_clone
        }
    }
};
void sysinitclass_jnci_AsciiCharset() {
}
