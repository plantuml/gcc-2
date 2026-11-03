#include "Checksum.h"
#include "../../../../strings.h"

int32_t supertypeof_juz_Checksum(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 145 || tag >= 147) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class juz_Checksum_Cls = {
    .size = 0,
    .flags = 0,
    .tag = 145,
    .modifiers = 1537,
    .name = NULL,
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_juz_Checksum,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
};
void sysinitclass_juz_Checksum() {
}
