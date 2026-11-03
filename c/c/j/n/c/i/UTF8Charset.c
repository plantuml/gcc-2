#include "UTF8Charset.h"
#include "../Charset.h"
#include "../../../../o/t/r/Allocator.h"
#include "../../../../../arrayclass.h"
#include "../../../l/String.h"
#include "../../../../../strings.h"
#include "../../../l/Object.h"

void* sfld_jnci_UTF8Charset_INSTANCE;
void meth_jnci_UTF8Charset__clinit_() {
    void* teavm_local_1;
    TeaVM_Array* teavm_local_2;
    TeaVM_Array* teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    int32_t teavm_local_6;
    void* teavm_local_7;
    TEAVM_ALLOC_STACK(INT32_C(3));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(656, meth_otr_Allocator_allocate(&jnci_UTF8Charset_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    TEAVM_WITH_CALL_SITE_ID(657, teavm_initializeClass((TeaVM_Class*) &jnci_UTF8Charset_Cls, &initclass_jnci_UTF8Charset));
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(658, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_String_Cls), INT32_C(0)));
    teavm_local_3 = teavm_local_2;
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    TEAVM_WITH_CALL_SITE_ID(659, meth_jnc_Charset_checkCanonicalName(TEAVM_GET_STRING(29)));
    teavm_local_4 = TEAVM_ARRAY_LENGTH(teavm_local_3);
    teavm_local_5 = INT32_C(0);
    while (1) {
        if (!(teavm_local_5 < teavm_local_4)) break;
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(660, teavm_checkLowerBound(teavm_local_5));
        teavm_local_7 = TEAVM_ARRAY_AT(teavm_local_3, void*, teavm_local_6);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_7);
        TEAVM_WITH_CALL_SITE_ID(661, meth_jnc_Charset_checkCanonicalName(teavm_local_7));
        teavm_local_5 = (teavm_local_6 + INT32_C(1));
    }
    TEAVM_FIELD(teavm_local_1, cls_jnc_Charset, fld_canonicalName) = TEAVM_GET_STRING(29);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(662, TEAVM_METHOD(teavm_local_2, jl_Object_VT, virt_clone)(teavm_local_2));
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jnc_Charset, fld_aliases) = teavm_local_2;
    sfld_jnci_UTF8Charset_INSTANCE = teavm_local_1;
    TEAVM_RELEASE_STACK;
}
void initclass_jnci_UTF8Charset() {
    TeaVM_Class* cls = (TeaVM_Class*) &jnci_UTF8Charset_Cls;
    if (!(cls->flags & INT32_C(1))) {
        cls->flags |= INT32_C(1);
        meth_jnci_UTF8Charset__clinit_();
    }
}
int32_t supertypeof_jnci_UTF8Charset(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 180 || tag >= 182) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jnci_UTF8Charset_VT jnci_UTF8Charset_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnci_UTF8Charset), sizeof(void*)),
                .flags = 0,
                .tag = 180,
                .modifiers = 1,
                .name = NULL,
                .arrayType = NULL,
                .itemType = NULL,
                .isSupertypeOf = &supertypeof_jnci_UTF8Charset,
                .superclass = (TeaVM_Class*) &jnc_Charset_Cls,
                .layout = NULL,
                .enumValues = NULL
            },
            .virt_clone = &meth_jl_Object_clone
        }
    }
};
static void** teavm_gc_localStaticRoots_jnci_UTF8Charset_Cls[1] = {
(void**) &sfld_jnci_UTF8Charset_INSTANCE
};
void sysinitclass_jnci_UTF8Charset() {
sfld_jnci_UTF8Charset_INSTANCE = NULL;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_jnci_UTF8Charset_Cls, 1);
}
