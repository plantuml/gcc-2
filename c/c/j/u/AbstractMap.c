#include "AbstractMap.h"
#include "../l/Object.h"
#include "../../../strings.h"

int32_t supertypeof_ju_AbstractMap(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 161 || tag >= 165) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) ju_AbstractMap_VT ju_AbstractMap_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_ju_AbstractMap), sizeof(void*)),
            .flags = 0,
            .tag = 161,
            .modifiers = 1025,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_ju_AbstractMap,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        }
    }
};
void sysinitclass_ju_AbstractMap() {
}
