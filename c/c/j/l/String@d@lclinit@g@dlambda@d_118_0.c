#include "String@d@lclinit@g@dlambda@d_118_0.h"
#include "Object.h"
#include "../../../strings.h"

int32_t supertypeof_jl_String__clinit__lambda__118_0(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 213 || tag >= 215) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_String__clinit__lambda__118_0_VT jl_String__clinit__lambda__118_0_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_String__clinit__lambda__118_0), sizeof(void*)),
            .flags = 0,
            .tag = 213,
            .modifiers = 1,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jl_String__clinit__lambda__118_0,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
void sysinitclass_jl_String__clinit__lambda__118_0() {
}
