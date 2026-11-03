#include "ArrayBufferViewProvider.h"
#include "../../../strings.h"

int32_t supertypeof_jn_ArrayBufferViewProvider(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 170 || tag >= 177) return INT32_C(0);
    if (tag >= 172 && tag < 175) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class jn_ArrayBufferViewProvider_Cls = {
    .size = 0,
    .flags = 0,
    .tag = 170,
    .modifiers = 1537,
    .name = NULL,
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_jn_ArrayBufferViewProvider,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
};
void sysinitclass_jn_ArrayBufferViewProvider() {
}
