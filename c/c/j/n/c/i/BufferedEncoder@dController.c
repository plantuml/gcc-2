#include "BufferedEncoder@dController.h"
#include "../../../l/Object.h"
#include "../../../../../strings.h"

int32_t supertypeof_jnci_BufferedEncoder_Controller(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 233 || tag >= 235) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_jnci_BufferedEncoder_Controller_Cls[3];
alignas(8) jnci_BufferedEncoder_Controller_VT jnci_BufferedEncoder_Controller_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnci_BufferedEncoder_Controller), sizeof(void*)),
            .flags = 0,
            .tag = 233,
            .modifiers = 1,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jnci_BufferedEncoder_Controller,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_jnci_BufferedEncoder_Controller_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static int16_t teavm_classLayouts_jnci_BufferedEncoder_Controller_Cls[3] = {
INT16_C(2), (int16_t) offsetof(cls_jnci_BufferedEncoder_Controller, fld_in), (int16_t) offsetof(cls_jnci_BufferedEncoder_Controller, fld_out)
};
void sysinitclass_jnci_BufferedEncoder_Controller() {
}
