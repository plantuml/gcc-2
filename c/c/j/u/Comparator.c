#include "Comparator.h"
#include "../../../strings.h"

int32_t supertypeof_ju_Comparator(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 213 || tag >= 215) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class ju_Comparator_Cls = {
    .size = 0,
    .flags = 0,
    .tag = 213,
    .modifiers = 1537,
    .name = NULL,
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_ju_Comparator,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
};
void sysinitclass_ju_Comparator() {
}
