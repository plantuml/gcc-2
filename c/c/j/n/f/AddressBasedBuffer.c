#include "AddressBasedBuffer.h"
#include "../../../../strings.h"

int32_t supertypeof_jnf_AddressBasedBuffer(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 170 || tag >= 177) return INT32_C(0);
    if (tag >= 172 && tag < 175) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class jnf_AddressBasedBuffer_Cls = {
    .size = 0,
    .flags = 0,
    .tag = 170,
    .modifiers = 1537,
    .name = NULL,
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_jnf_AddressBasedBuffer,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
};
void sysinitclass_jnf_AddressBasedBuffer() {
}
