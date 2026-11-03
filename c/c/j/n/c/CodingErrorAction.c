#include "CodingErrorAction.h"
#include "../../l/Object.h"
#include "../../../o/t/r/Allocator.h"
#include "../../../../strings.h"

void* sfld_jnc_CodingErrorAction_IGNORE;
void* sfld_jnc_CodingErrorAction_REPLACE;
void* sfld_jnc_CodingErrorAction_REPORT;
void meth_jnc_CodingErrorAction__clinit_() {
    void* teavm_local_1;
    TEAVM_ALLOC_STACK(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(672, meth_otr_Allocator_allocate(&jnc_CodingErrorAction_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    TEAVM_WITH_CALL_SITE_ID(673, teavm_initializeClass((TeaVM_Class*) &jnc_CodingErrorAction_Cls, &initclass_jnc_CodingErrorAction));
    TEAVM_FIELD(teavm_local_1, cls_jnc_CodingErrorAction, fld_name) = TEAVM_GET_STRING(30);
    sfld_jnc_CodingErrorAction_IGNORE = teavm_local_1;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(674, meth_otr_Allocator_allocate(&jnc_CodingErrorAction_Cls));
    TEAVM_FIELD(teavm_local_1, cls_jnc_CodingErrorAction, fld_name) = TEAVM_GET_STRING(31);
    sfld_jnc_CodingErrorAction_REPLACE = teavm_local_1;
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(675, meth_otr_Allocator_allocate(&jnc_CodingErrorAction_Cls));
    TEAVM_FIELD(teavm_local_1, cls_jnc_CodingErrorAction, fld_name) = TEAVM_GET_STRING(32);
    sfld_jnc_CodingErrorAction_REPORT = teavm_local_1;
    TEAVM_RELEASE_STACK;
}
void initclass_jnc_CodingErrorAction() {
    TeaVM_Class* cls = (TeaVM_Class*) &jnc_CodingErrorAction_Cls;
    if (!(cls->flags & INT32_C(1))) {
        cls->flags |= INT32_C(1);
        meth_jnc_CodingErrorAction__clinit_();
    }
}
int32_t supertypeof_jnc_CodingErrorAction(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 203 || tag >= 205) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_jnc_CodingErrorAction_Cls[2];
alignas(8) jnc_CodingErrorAction_VT jnc_CodingErrorAction_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnc_CodingErrorAction), sizeof(void*)),
            .flags = 0,
            .tag = 203,
            .modifiers = 1,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jnc_CodingErrorAction,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_jnc_CodingErrorAction_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static void** teavm_gc_localStaticRoots_jnc_CodingErrorAction_Cls[3] = {
(void**) &sfld_jnc_CodingErrorAction_IGNORE, (void**) &sfld_jnc_CodingErrorAction_REPLACE, (void**) &sfld_jnc_CodingErrorAction_REPORT
};
static int16_t teavm_classLayouts_jnc_CodingErrorAction_Cls[2] = {
INT16_C(1), (int16_t) offsetof(cls_jnc_CodingErrorAction, fld_name)
};
void sysinitclass_jnc_CodingErrorAction() {
sfld_jnc_CodingErrorAction_IGNORE = NULL;
sfld_jnc_CodingErrorAction_REPLACE = NULL;
sfld_jnc_CodingErrorAction_REPORT = NULL;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_jnc_CodingErrorAction_Cls, 3);
}
