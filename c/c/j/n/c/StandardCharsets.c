#include "StandardCharsets.h"
#include "../../l/Object.h"
#include "i/UTF8Charset.h"
#include "i/AsciiCharset.h"
#include "../../../o/t/r/Allocator.h"
#include "../../../../arrayclass.h"
#include "../../l/String.h"
#include "Charset.h"
#include "../../../../strings.h"
#include "i/Iso8859Charset.h"
#include "i/UTF16Charset.h"

void* sfld_jnc_StandardCharsets_UTF_8;
void* sfld_jnc_StandardCharsets_US_ASCII;
void* sfld_jnc_StandardCharsets_ISO_8859_1;
void* sfld_jnc_StandardCharsets_UTF_16;
void* sfld_jnc_StandardCharsets_UTF_16BE;
void* sfld_jnc_StandardCharsets_UTF_16LE;
void meth_jnc_StandardCharsets__clinit_() {
    void* teavm_local_1;
    TeaVM_Array* teavm_local_2;
    TeaVM_Array* teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    int32_t teavm_local_6;
    void* teavm_local_7;
    void* teavm_local_8;
    int32_t teavm_local_9;
    int32_t teavm_local_10;
    TEAVM_ALLOC_STACK(INT32_C(3));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_WITH_CALL_SITE_ID(360, teavm_initializeClass((TeaVM_Class*) &jnci_UTF8Charset_Cls, &initclass_jnci_UTF8Charset));
    sfld_jnc_StandardCharsets_UTF_8 = sfld_jnci_UTF8Charset_INSTANCE;
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(361, meth_otr_Allocator_allocate(&jnci_AsciiCharset_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(362, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_String_Cls), INT32_C(0)));
    teavm_local_3 = teavm_local_2;
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    TEAVM_WITH_CALL_SITE_ID(363, meth_jnc_Charset_checkCanonicalName(TEAVM_GET_STRING(15)));
    teavm_local_4 = TEAVM_ARRAY_LENGTH(teavm_local_3);
    teavm_local_5 = INT32_C(0);
    while (1) {
        if (!(teavm_local_5 < teavm_local_4)) break;
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(364, teavm_checkLowerBound(teavm_local_5));
        teavm_local_7 = TEAVM_ARRAY_AT(teavm_local_3, void*, teavm_local_6);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_7);
        TEAVM_WITH_CALL_SITE_ID(365, meth_jnc_Charset_checkCanonicalName(teavm_local_7));
        teavm_local_5 = (teavm_local_6 + INT32_C(1));
    }
    TEAVM_FIELD(teavm_local_1, cls_jnc_Charset, fld_canonicalName) = TEAVM_GET_STRING(15);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(366, TEAVM_METHOD(teavm_local_2, jl_Object_VT, virt_clone)(teavm_local_2));
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jnc_Charset, fld_aliases) = teavm_local_2;
    sfld_jnc_StandardCharsets_US_ASCII = teavm_local_1;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(367, meth_otr_Allocator_allocate(&jnci_Iso8859Charset_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(368, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_String_Cls), INT32_C(0)));
    teavm_local_3 = teavm_local_2;
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    TEAVM_WITH_CALL_SITE_ID(369, meth_jnc_Charset_checkCanonicalName(TEAVM_GET_STRING(16)));
    teavm_local_4 = TEAVM_ARRAY_LENGTH(teavm_local_3);
    teavm_local_5 = INT32_C(0);
    while (1) {
        if (!(teavm_local_5 < teavm_local_4)) break;
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(370, teavm_checkLowerBound(teavm_local_5));
        teavm_local_7 = TEAVM_ARRAY_AT(teavm_local_3, void*, teavm_local_6);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_7);
        TEAVM_WITH_CALL_SITE_ID(371, meth_jnc_Charset_checkCanonicalName(teavm_local_7));
        teavm_local_5 = (teavm_local_6 + INT32_C(1));
    }
    TEAVM_FIELD(teavm_local_1, cls_jnc_Charset, fld_canonicalName) = TEAVM_GET_STRING(16);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(372, TEAVM_METHOD(teavm_local_2, jl_Object_VT, virt_clone)(teavm_local_2));
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jnc_Charset, fld_aliases) = teavm_local_2;
    sfld_jnc_StandardCharsets_ISO_8859_1 = teavm_local_1;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(373, meth_otr_Allocator_allocate(&jnci_UTF16Charset_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_8);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(374, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_String_Cls), INT32_C(0)));
    teavm_local_3 = teavm_local_2;
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    TEAVM_WITH_CALL_SITE_ID(375, meth_jnc_Charset_checkCanonicalName(TEAVM_GET_STRING(17)));
    teavm_local_6 = TEAVM_ARRAY_LENGTH(teavm_local_3);
    teavm_local_9 = INT32_C(0);
    while (1) {
        if (!(teavm_local_9 < teavm_local_6)) break;
        teavm_local_10 = TEAVM_WITH_CALL_SITE_ID(376, teavm_checkLowerBound(teavm_local_9));
        teavm_local_7 = TEAVM_ARRAY_AT(teavm_local_3, void*, teavm_local_10);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_7);
        TEAVM_WITH_CALL_SITE_ID(377, meth_jnc_Charset_checkCanonicalName(teavm_local_7));
        teavm_local_9 = (teavm_local_10 + INT32_C(1));
    }
    TEAVM_FIELD(teavm_local_8, cls_jnc_Charset, fld_canonicalName) = TEAVM_GET_STRING(17);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(378, TEAVM_METHOD(teavm_local_2, jl_Object_VT, virt_clone)(teavm_local_2));
    teavm_gc_writeBarrier(teavm_local_8);
    TEAVM_FIELD(teavm_local_8, cls_jnc_Charset, fld_aliases) = teavm_local_2;
    TEAVM_FIELD(teavm_local_8, cls_jnci_UTF16Charset, fld_bom) = INT32_C(1);
    TEAVM_FIELD(teavm_local_8, cls_jnci_UTF16Charset, fld_littleEndian) = INT32_C(0);
    sfld_jnc_StandardCharsets_UTF_16 = teavm_local_8;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(379, meth_otr_Allocator_allocate(&jnci_UTF16Charset_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(380, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_String_Cls), INT32_C(0)));
    teavm_local_3 = teavm_local_2;
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    TEAVM_WITH_CALL_SITE_ID(381, meth_jnc_Charset_checkCanonicalName(TEAVM_GET_STRING(18)));
    teavm_local_6 = TEAVM_ARRAY_LENGTH(teavm_local_3);
    teavm_local_9 = INT32_C(0);
    while (1) {
        if (!(teavm_local_9 < teavm_local_6)) break;
        teavm_local_10 = TEAVM_WITH_CALL_SITE_ID(382, teavm_checkLowerBound(teavm_local_9));
        teavm_local_7 = TEAVM_ARRAY_AT(teavm_local_3, void*, teavm_local_10);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_7);
        TEAVM_WITH_CALL_SITE_ID(383, meth_jnc_Charset_checkCanonicalName(teavm_local_7));
        teavm_local_9 = (teavm_local_10 + INT32_C(1));
    }
    TEAVM_FIELD(teavm_local_1, cls_jnc_Charset, fld_canonicalName) = TEAVM_GET_STRING(18);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(384, TEAVM_METHOD(teavm_local_2, jl_Object_VT, virt_clone)(teavm_local_2));
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jnc_Charset, fld_aliases) = teavm_local_2;
    TEAVM_FIELD(teavm_local_1, cls_jnci_UTF16Charset, fld_bom) = INT32_C(0);
    TEAVM_FIELD(teavm_local_1, cls_jnci_UTF16Charset, fld_littleEndian) = INT32_C(0);
    sfld_jnc_StandardCharsets_UTF_16BE = teavm_local_1;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(385, meth_otr_Allocator_allocate(&jnci_UTF16Charset_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(386, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_String_Cls), INT32_C(0)));
    teavm_local_3 = teavm_local_2;
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    TEAVM_WITH_CALL_SITE_ID(387, meth_jnc_Charset_checkCanonicalName(TEAVM_GET_STRING(19)));
    teavm_local_6 = TEAVM_ARRAY_LENGTH(teavm_local_3);
    teavm_local_9 = INT32_C(0);
    while (1) {
        if (!(teavm_local_9 < teavm_local_6)) break;
        teavm_local_10 = TEAVM_WITH_CALL_SITE_ID(388, teavm_checkLowerBound(teavm_local_9));
        teavm_local_7 = TEAVM_ARRAY_AT(teavm_local_3, void*, teavm_local_10);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_7);
        TEAVM_WITH_CALL_SITE_ID(389, meth_jnc_Charset_checkCanonicalName(teavm_local_7));
        teavm_local_9 = (teavm_local_10 + INT32_C(1));
    }
    TEAVM_FIELD(teavm_local_1, cls_jnc_Charset, fld_canonicalName) = TEAVM_GET_STRING(19);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(390, TEAVM_METHOD(teavm_local_2, jl_Object_VT, virt_clone)(teavm_local_2));
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jnc_Charset, fld_aliases) = teavm_local_2;
    TEAVM_FIELD(teavm_local_1, cls_jnci_UTF16Charset, fld_bom) = INT32_C(0);
    TEAVM_FIELD(teavm_local_1, cls_jnci_UTF16Charset, fld_littleEndian) = INT32_C(1);
    sfld_jnc_StandardCharsets_UTF_16LE = teavm_local_1;
    TEAVM_RELEASE_STACK;
}
void initclass_jnc_StandardCharsets() {
    TeaVM_Class* cls = (TeaVM_Class*) &jnc_StandardCharsets_Cls;
    if (!(cls->flags & INT32_C(1))) {
        cls->flags |= INT32_C(1);
        meth_jnc_StandardCharsets__clinit_();
    }
}
int32_t supertypeof_jnc_StandardCharsets(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 147 || tag >= 149) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jnc_StandardCharsets_VT jnc_StandardCharsets_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnc_StandardCharsets), sizeof(void*)),
            .flags = 0,
            .tag = 147,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jnc_StandardCharsets,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static void** teavm_gc_localStaticRoots_jnc_StandardCharsets_Cls[6] = {
(void**) &sfld_jnc_StandardCharsets_UTF_8, (void**) &sfld_jnc_StandardCharsets_US_ASCII, (void**) &sfld_jnc_StandardCharsets_ISO_8859_1, (void**) &sfld_jnc_StandardCharsets_UTF_16, (void**) &sfld_jnc_StandardCharsets_UTF_16BE, (void**) &sfld_jnc_StandardCharsets_UTF_16LE
};
void sysinitclass_jnc_StandardCharsets() {
sfld_jnc_StandardCharsets_UTF_8 = NULL;
sfld_jnc_StandardCharsets_US_ASCII = NULL;
sfld_jnc_StandardCharsets_ISO_8859_1 = NULL;
sfld_jnc_StandardCharsets_UTF_16 = NULL;
sfld_jnc_StandardCharsets_UTF_16BE = NULL;
sfld_jnc_StandardCharsets_UTF_16LE = NULL;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_jnc_StandardCharsets_Cls, 6);
}
