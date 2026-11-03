#include "Closeable.h"
#include "../../../strings.h"

int32_t supertypeof_ji_Closeable(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 189 || tag >= 199) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class ji_Closeable_Cls = {
    .size = 0,
    .flags = 0,
    .tag = 189,
    .modifiers = 1537,
    .name = NULL,
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_ji_Closeable,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
};
void sysinitclass_ji_Closeable() {
}
