#include "HashMap@dHashEntry.h"
#include "MapEntry.h"
#include "../../../strings.h"

int32_t supertypeof_ju_HashMap_HashEntry(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 230 || tag >= 232) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_ju_HashMap_HashEntry_Cls[2];
alignas(8) ju_HashMap_HashEntry_VT ju_HashMap_HashEntry_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_ju_HashMap_HashEntry), sizeof(void*)),
                .flags = 0,
                .tag = 230,
                .modifiers = 0,
                .name = NULL,
                .arrayType = NULL,
                .itemType = NULL,
                .isSupertypeOf = &supertypeof_ju_HashMap_HashEntry,
                .superclass = (TeaVM_Class*) &ju_MapEntry_Cls,
                .layout = teavm_classLayouts_ju_HashMap_HashEntry_Cls,
                .enumValues = NULL
            }
        }
    }
};
static int16_t teavm_classLayouts_ju_HashMap_HashEntry_Cls[2] = {
INT16_C(1), (int16_t) offsetof(cls_ju_HashMap_HashEntry, fld_next)
};
void sysinitclass_ju_HashMap_HashEntry() {
}
