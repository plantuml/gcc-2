#include "Character.h"
#include "Object.h"
#include "../../../p/char.h"
#include "../../../arrayclass.h"
#include "../../o/t/r/Allocator.h"
#include "../../../strings.h"

void* sfld_jl_Character_TYPE;
TeaVM_Array* sfld_jl_Character_characterCache;
int32_t meth_jl_Character_forDigit(int32_t teavm_local_1, int32_t teavm_local_2) {
    TEAVM_ALLOC_STACK(INT32_C(0));
    TEAVM_WITH_CALL_SITE_ID(793, teavm_initializeClass((TeaVM_Class*) &jl_Character_Cls, &initclass_jl_Character));
    teavm_local_1 = ((!((teavm_local_2 >= INT32_C(2)) && ((teavm_local_2 <= INT32_C(36)) && ((teavm_local_1 >= INT32_C(0)) && (teavm_local_1 < teavm_local_2))))) ? INT32_C(0) : ((teavm_local_1 < INT32_C(10)) ? TEAVM_TO_CHAR((INT32_C(48) + teavm_local_1)) : TEAVM_TO_CHAR(((INT32_C(97) + teavm_local_1) - INT32_C(10)))));
    TEAVM_RELEASE_STACK;
    return teavm_local_1;
}
void meth_jl_Character__clinit_() {
    TEAVM_ALLOC_STACK(INT32_C(0));
    sfld_jl_Character_TYPE = teavm_getClassObject((TeaVM_Class*) &C_Cls);
    sfld_jl_Character_characterCache = TEAVM_WITH_CALL_SITE_ID(794, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Character_Cls), INT32_C(128)));
    TEAVM_RELEASE_STACK;
}
void initclass_jl_Character() {
    TeaVM_Class* cls = (TeaVM_Class*) &jl_Character_Cls;
    if (!(cls->flags & INT32_C(1))) {
        cls->flags |= INT32_C(1);
        meth_jl_Character__clinit_();
    }
}
int32_t supertypeof_jl_Character(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 215 || tag >= 217) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_Character_VT jl_Character_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_Character), sizeof(void*)),
            .flags = 0,
            .tag = 215,
            .modifiers = 1,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jl_Character,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static void** teavm_gc_localStaticRoots_jl_Character_Cls[2] = {
(void**) &sfld_jl_Character_TYPE, (void**) &sfld_jl_Character_characterCache
};
void sysinitclass_jl_Character() {
sfld_jl_Character_TYPE = NULL;
sfld_jl_Character_characterCache = NULL;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_jl_Character_Cls, 2);
}
