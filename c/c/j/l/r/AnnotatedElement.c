#include "AnnotatedElement.h"
#include "../../../../strings.h"

int32_t supertypeof_jlr_AnnotatedElement(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 3 || tag >= 5) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class jlr_AnnotatedElement_Cls = {
    .size = 0,
    .flags = 0,
    .tag = 3,
    .modifiers = 1537,
    .name = NULL,
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_jlr_AnnotatedElement,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
};
void sysinitclass_jlr_AnnotatedElement() {
}
