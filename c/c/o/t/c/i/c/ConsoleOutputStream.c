#include "ConsoleOutputStream.h"
#include "../../../../../j/i/OutputStream.h"
#include "../../../../../../strings.h"
#include "../../../../../j/l/Object.h"

int32_t supertypeof_otcic_ConsoleOutputStream(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 194 || tag >= 198) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_otcic_ConsoleOutputStream_Cls[2];
alignas(8) otcic_ConsoleOutputStream_VT otcic_ConsoleOutputStream_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otcic_ConsoleOutputStream), sizeof(void*)),
                .flags = 0,
                .tag = 194,
                .modifiers = 1025,
                .name = NULL,
                .arrayType = NULL,
                .itemType = NULL,
                .isSupertypeOf = &supertypeof_otcic_ConsoleOutputStream,
                .superclass = (TeaVM_Class*) &ji_OutputStream_Cls,
                .layout = teavm_classLayouts_otcic_ConsoleOutputStream_Cls,
                .enumValues = NULL
            },
            .virt_clone = &meth_jl_Object_clone
        }
    }
};
static int16_t teavm_classLayouts_otcic_ConsoleOutputStream_Cls[2] = {
INT16_C(1), (int16_t) offsetof(cls_otcic_ConsoleOutputStream, fld_buffer)
};
void sysinitclass_otcic_ConsoleOutputStream() {
}
