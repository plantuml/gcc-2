#include "EventQueue@dNode.h"
#include "../../../j/l/Object.h"
#include "../../../../strings.h"

int32_t supertypeof_otr_EventQueue_Node(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 139 || tag >= 141) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_otr_EventQueue_Node_Cls[2];
alignas(8) otr_EventQueue_Node_VT otr_EventQueue_Node_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otr_EventQueue_Node), sizeof(void*)),
            .flags = 0,
            .tag = 139,
            .modifiers = 0,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_otr_EventQueue_Node,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_otr_EventQueue_Node_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static int16_t teavm_classLayouts_otr_EventQueue_Node_Cls[2] = {
INT16_C(1), (int16_t) offsetof(cls_otr_EventQueue_Node, fld_event)
};
void sysinitclass_otr_EventQueue_Node() {
}
