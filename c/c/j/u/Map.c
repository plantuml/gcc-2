#include "Map.h"
#include "../../../strings.h"

int32_t supertypeof_ju_Map(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 161 || tag >= 165) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class ju_Map_Cls = {
    .size = 0,
    .flags = 0,
    .tag = 161,
    .modifiers = 1537,
    .name = NULL,
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_ju_Map,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
};
void sysinitclass_ju_Map() {
}
