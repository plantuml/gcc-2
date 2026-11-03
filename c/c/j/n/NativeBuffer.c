#include "NativeBuffer.h"
#include "../../../strings.h"

int32_t supertypeof_jn_NativeBuffer(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 175 || tag >= 177) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class jn_NativeBuffer_Cls = {
    .size = 0,
    .flags = 0,
    .tag = 175,
    .modifiers = 1537,
    .name = NULL,
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_jn_NativeBuffer,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
};
void sysinitclass_jn_NativeBuffer() {
}
