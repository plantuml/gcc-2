#include "FilterOutputStream.h"
#include "OutputStream.h"
#include "../../../strings.h"
#include "../l/Object.h"

int32_t supertypeof_ji_FilterOutputStream(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 190 || tag >= 194) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_ji_FilterOutputStream_Cls[2];
alignas(8) ji_FilterOutputStream_VT ji_FilterOutputStream_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_ji_FilterOutputStream), sizeof(void*)),
                .flags = 0,
                .tag = 190,
                .modifiers = 1,
                .name = NULL,
                .arrayType = NULL,
                .itemType = NULL,
                .isSupertypeOf = &supertypeof_ji_FilterOutputStream,
                .superclass = (TeaVM_Class*) &ji_OutputStream_Cls,
                .layout = teavm_classLayouts_ji_FilterOutputStream_Cls,
                .enumValues = NULL
            },
            .virt_clone = &meth_jl_Object_clone
        }
    }
};
static int16_t teavm_classLayouts_ji_FilterOutputStream_Cls[2] = {
INT16_C(1), (int16_t) offsetof(cls_ji_FilterOutputStream, fld_out)
};
void sysinitclass_ji_FilterOutputStream() {
}
