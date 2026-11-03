#include "Integer.h"
#include "Number.h"
#include "../../../p/int.h"
#include "../../../strings.h"
#include "Object.h"

void* sfld_jl_Integer_TYPE;
void meth_jl_Integer__clinit_() {
    sfld_jl_Integer_TYPE = teavm_getClassObject((TeaVM_Class*) &I_Cls);
}
void initclass_jl_Integer() {
    TeaVM_Class* cls = (TeaVM_Class*) &jl_Integer_Cls;
    if (!(cls->flags & INT32_C(1))) {
        cls->flags |= INT32_C(1);
        meth_jl_Integer__clinit_();
    }
}
int32_t supertypeof_jl_Integer(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 152 || tag >= 154) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_Integer_VT jl_Integer_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_Integer), sizeof(void*)),
                .flags = 0,
                .tag = 152,
                .modifiers = 1,
                .name = NULL,
                .arrayType = NULL,
                .itemType = NULL,
                .isSupertypeOf = &supertypeof_jl_Integer,
                .superclass = (TeaVM_Class*) &jl_Number_Cls,
                .layout = NULL,
                .enumValues = NULL
            },
            .virt_clone = &meth_jl_Object_clone
        }
    }
};
static void** teavm_gc_localStaticRoots_jl_Integer_Cls[1] = {
(void**) &sfld_jl_Integer_TYPE
};
void sysinitclass_jl_Integer() {
sfld_jl_Integer_TYPE = NULL;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_jl_Integer_Cls, 1);
}
