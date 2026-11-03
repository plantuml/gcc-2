#include "Serializable.h"
#include "../../../strings.h"

int32_t supertypeof_ji_Serializable(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 1 || tag >= 227) return INT32_C(0);
    if (tag >= 3 && tag < 149) return INT32_C(0);
    if (tag >= 155 && tag < 155) return INT32_C(0);
    if (tag >= 159 && tag < 162) return INT32_C(0);
    if (tag >= 164 && tag < 225) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class ji_Serializable_Cls = {
    .size = 0,
    .flags = 0,
    .tag = 1,
    .modifiers = 1537,
    .name = NULL,
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_ji_Serializable,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
};
void sysinitclass_ji_Serializable() {
}
