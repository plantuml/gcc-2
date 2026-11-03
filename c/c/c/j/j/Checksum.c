#include "Checksum.h"
#include "../../../../strings.h"

int32_t supertypeof_cjj_Checksum(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 165 || tag >= 167) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class cjj_Checksum_Cls = {
    .size = 0,
    .flags = 0,
    .tag = 165,
    .modifiers = 1536,
    .name = NULL,
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_cjj_Checksum,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
};
void sysinitclass_cjj_Checksum() {
}
