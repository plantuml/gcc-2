#include "Charset.h"
#include "../../l/Object.h"
#include "../../l/String.h"
#include "IllegalCharsetNameException.h"
#include "../../../o/t/r/Allocator.h"
#include "../../../../arrayclass.h"
#include "../../l/Throwable.h"
#include "../../../o/t/r/ExceptionHandling.h"
#include "../../l/StringIndexOutOfBoundsException.h"
#include "../../../../strings.h"

void meth_jnc_Charset_checkCanonicalName(void* teavm_local_1) {
    TeaVM_Array* teavm_local_2;
    int32_t teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    void* teavm_local_6;
    TEAVM_ALLOC_STACK(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(524, teavm_nullCheck(teavm_local_1));
    teavm_local_2 = TEAVM_FIELD(teavm_local_1, TeaVM_String, characters);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_2);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(525, teavm_nullCheck(teavm_local_2));
    teavm_local_3 = TEAVM_ARRAY_LENGTH(teavm_local_2);
    if ((!(teavm_local_3 ? INT32_C(0) : INT32_C(1)))) {
        if ((INT32_C(0) < teavm_local_3)) {
            teavm_local_4 = TEAVM_ARRAY_AT(teavm_local_2, char16_t, TEAVM_WITH_CALL_SITE_ID(526, teavm_checkUpperBound(INT32_C(0), teavm_local_2)));
            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
            if (TEAVM_WITH_CALL_SITE_ID(527, meth_jnc_Charset_isValidCharsetStart(teavm_local_4))) {
                teavm_local_4 = INT32_C(1);
                while (1) {
                    teavm_local_2 = TEAVM_FIELD(teavm_local_1, TeaVM_String, characters);
                    TEAVM_GC_ROOT(INT32_C(1), teavm_local_2);
                    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(528, teavm_nullCheck(teavm_local_2));
                    teavm_local_3 = teavm_compare_i32(teavm_local_4, TEAVM_ARRAY_LENGTH(teavm_local_2));
                    if ((teavm_local_3 >= INT32_C(0))) {
                        goto teavm_label_2;
                    }
                    if ((teavm_local_4 < INT32_C(0))) {
                        goto teavm_label_1;
                    }
                    if ((teavm_local_3 >= INT32_C(0))) {
                        goto teavm_label_1;
                    }
                    teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(529, teavm_checkBounds(teavm_local_4, teavm_local_2));
                    teavm_local_3 = TEAVM_ARRAY_AT(teavm_local_2, char16_t, teavm_local_5);
                    switch (teavm_local_3) {
                        case 43:
                        case 45:
                        case 46:
                        case 58:
                        case 95:
                            goto teavm_label_5;
                        default:
                            goto teavm_label_4;
                    }
                teavm_label_5:;
                    goto teavm_label_3;
                teavm_label_4:;
                    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                    if ((!TEAVM_WITH_CALL_SITE_ID(530, meth_jnc_Charset_isValidCharsetStart(teavm_local_3)))) {
                        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(531, meth_otr_Allocator_allocate(&jnc_IllegalCharsetNameException_Cls));
                        TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
                        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(532, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                        teavm_gc_writeBarrier(teavm_local_6);
                        TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_suppressed) = teavm_local_2;
                        TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                        TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(533, meth_otr_ExceptionHandling_fillStackTrace());
                        teavm_gc_writeBarrier(teavm_local_6);
                        TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_stackTrace) = teavm_local_2;
                        TEAVM_FIELD(teavm_local_6, cls_jnc_IllegalCharsetNameException, fld_charsetName) = teavm_local_1;
                        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                        TEAVM_WITH_CALL_SITE_ID(534, meth_otr_ExceptionHandling_throwException(teavm_local_6));
                        TEAVM_UNREACHABLE
                    }
                teavm_label_3:;
                    teavm_local_4 = (teavm_local_5 + INT32_C(1));
                }
            teavm_label_2:;
                TEAVM_RELEASE_STACK;
                return;
            teavm_label_1:;
                TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(535, meth_otr_Allocator_allocate(&jl_StringIndexOutOfBoundsException_Cls));
                TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
                teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(536, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                teavm_gc_writeBarrier(teavm_local_1);
                TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_2;
                TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(537, meth_otr_ExceptionHandling_fillStackTrace());
                teavm_gc_writeBarrier(teavm_local_1);
                TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_2;
                TEAVM_WITH_CALL_SITE_ID(538, meth_otr_ExceptionHandling_throwException(teavm_local_1));
                TEAVM_UNREACHABLE
            }
            teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(539, meth_otr_Allocator_allocate(&jnc_IllegalCharsetNameException_Cls));
            TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
            teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(540, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
            teavm_gc_writeBarrier(teavm_local_6);
            TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_suppressed) = teavm_local_2;
            TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
            TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
            teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(541, meth_otr_ExceptionHandling_fillStackTrace());
            teavm_gc_writeBarrier(teavm_local_6);
            TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_stackTrace) = teavm_local_2;
            TEAVM_FIELD(teavm_local_6, cls_jnc_IllegalCharsetNameException, fld_charsetName) = teavm_local_1;
            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
            TEAVM_WITH_CALL_SITE_ID(542, meth_otr_ExceptionHandling_throwException(teavm_local_6));
            TEAVM_UNREACHABLE
        }
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(543, meth_otr_Allocator_allocate(&jl_StringIndexOutOfBoundsException_Cls));
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(544, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
        teavm_gc_writeBarrier(teavm_local_1);
        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_2;
        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(545, meth_otr_ExceptionHandling_fillStackTrace());
        teavm_gc_writeBarrier(teavm_local_1);
        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_2;
        TEAVM_WITH_CALL_SITE_ID(546, meth_otr_ExceptionHandling_throwException(teavm_local_1));
        TEAVM_UNREACHABLE
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(547, meth_otr_Allocator_allocate(&jnc_IllegalCharsetNameException_Cls));
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(548, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_6);
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_suppressed) = teavm_local_2;
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(549, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_local_6);
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_stackTrace) = teavm_local_2;
    TEAVM_FIELD(teavm_local_6, cls_jnc_IllegalCharsetNameException, fld_charsetName) = teavm_local_1;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_WITH_CALL_SITE_ID(550, meth_otr_ExceptionHandling_throwException(teavm_local_6));
    TEAVM_UNREACHABLE
}
int32_t meth_jnc_Charset_isValidCharsetStart(int32_t teavm_local_1) {
    if (((!((teavm_local_1 >= INT32_C(48)) && (teavm_local_1 <= INT32_C(57)))) && (!((teavm_local_1 >= INT32_C(97)) && (teavm_local_1 <= INT32_C(122)))))) {
        if ((teavm_local_1 < INT32_C(65))) {
            goto teavm_label_2;
        }
        if ((teavm_local_1 > INT32_C(90))) {
            goto teavm_label_2;
        }
    }
    teavm_local_1 = INT32_C(1);
    goto teavm_label_1;
teavm_label_2:;
    teavm_local_1 = INT32_C(0);
teavm_label_1:;
    return teavm_local_1;
}
int32_t supertypeof_jnc_Charset(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 179 || tag >= 189) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_jnc_Charset_Cls[3];
alignas(8) jnc_Charset_VT jnc_Charset_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnc_Charset), sizeof(void*)),
            .flags = 0,
            .tag = 179,
            .modifiers = 1025,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jnc_Charset,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_jnc_Charset_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static int16_t teavm_classLayouts_jnc_Charset_Cls[3] = {
INT16_C(2), (int16_t) offsetof(cls_jnc_Charset, fld_canonicalName), (int16_t) offsetof(cls_jnc_Charset, fld_aliases)
};
void sysinitclass_jnc_Charset() {
}
