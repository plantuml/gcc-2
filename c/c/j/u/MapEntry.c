#include "MapEntry.h"
#include "../l/Object.h"
#include "../../../strings.h"

int32_t supertypeof_ju_MapEntry(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 229 || tag >= 233) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_ju_MapEntry_Cls[3];
alignas(8) ju_MapEntry_VT ju_MapEntry_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_ju_MapEntry), sizeof(void*)),
            .flags = 0,
            .tag = 229,
            .modifiers = 0,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_ju_MapEntry,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_ju_MapEntry_Cls,
            .enumValues = NULL
        }
    }
};
static int16_t teavm_classLayouts_ju_MapEntry_Cls[3] = {
INT16_C(2), (int16_t) offsetof(cls_ju_MapEntry, fld_key), (int16_t) offsetof(cls_ju_MapEntry, fld_value)
};
void sysinitclass_ju_MapEntry() {
}
