#include "CResources@dResource.h"
#include "../../../../../j/l/Object.h"
#include "../../../../../../strings.h"

int32_t supertypeof_otbcr_CResources_Resource(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 125 || tag >= 127) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_otbcr_CResources_Resource_Cls[2];
alignas(8) otbcr_CResources_Resource_VT otbcr_CResources_Resource_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otbcr_CResources_Resource), sizeof(void*)),
            .flags = 0,
            .tag = 125,
            .modifiers = 1,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_otbcr_CResources_Resource,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_otbcr_CResources_Resource_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static int16_t teavm_classLayouts_otbcr_CResources_Resource_Cls[2] = {
INT16_C(1), (int16_t) offsetof(cls_otbcr_CResources_Resource, fld_name)
};
void sysinitclass_otbcr_CResources_Resource() {
}
