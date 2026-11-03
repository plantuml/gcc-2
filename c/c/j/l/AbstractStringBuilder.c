#include "AbstractStringBuilder.h"
#include "Object.h"
#include "../../../strings.h"
#include "String.h"
#include "StringIndexOutOfBoundsException.h"
#include "../../o/t/r/Allocator.h"
#include "../../../arrayclass.h"
#include "Throwable.h"
#include "../../o/t/r/ExceptionHandling.h"
#include "Character.h"
#include "../../../a/p/char.h"
#include "IndexOutOfBoundsException.h"

void* meth_jl_AbstractStringBuilder_insert(void* teavm_this_, int32_t teavm_local_1, void* teavm_local_2) {
    int32_t teavm_local_3;
    TeaVM_Array* teavm_local_4;
    void* teavm_local_5;
    int32_t teavm_local_6;
    TeaVM_Array* teavm_local_7;
    int32_t teavm_local_8;
    int32_t teavm_local_9;
    TEAVM_ALLOC_STACK(INT32_C(3));
    if ((teavm_local_1 >= INT32_C(0))) {
        teavm_local_3 = TEAVM_FIELD(teavm_this_, cls_jl_AbstractStringBuilder, fld_length);
        if ((teavm_local_1 <= teavm_local_3)) {
            if ((teavm_local_2 == NULL)) {
                teavm_local_2 = TEAVM_GET_STRING(4);
            } else {
                teavm_local_4 = TEAVM_FIELD(teavm_local_2, TeaVM_String, characters);
                TEAVM_GC_ROOT(INT32_C(0), teavm_local_4);
                TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                if ((TEAVM_ARRAY_LENGTH(TEAVM_WITH_CALL_SITE_ID(392, teavm_nullCheck(teavm_local_4))) ? INT32_C(0) : INT32_C(1))) {
                    goto teavm_label_2;
                }
            }
            teavm_local_4 = TEAVM_FIELD(teavm_local_2, TeaVM_String, characters);
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_4);
            TEAVM_GC_ROOT(INT32_C(1), teavm_local_2);
            TEAVM_GC_ROOT_RELEASE(INT32_C(2));
            teavm_local_3 = (teavm_local_3 + TEAVM_ARRAY_LENGTH(TEAVM_WITH_CALL_SITE_ID(393, teavm_nullCheck(teavm_local_4))));
            teavm_local_5 = teavm_this_;
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_5);
            TEAVM_WITH_CALL_SITE_ID(394, meth_jl_AbstractStringBuilder_ensureCapacity(TEAVM_WITH_CALL_SITE_ID(395, teavm_nullCheck(teavm_local_5)), teavm_local_3));
            teavm_local_3 = TEAVM_FIELD(teavm_this_, cls_jl_AbstractStringBuilder, fld_length);
            teavm_local_6 = (teavm_local_3 - INT32_C(1));
            while (1) {
                if (!(teavm_local_6 >= teavm_local_1)) break;
                teavm_local_4 = TEAVM_FIELD(teavm_this_, cls_jl_AbstractStringBuilder, fld_buffer);
                teavm_local_7 = TEAVM_FIELD(teavm_local_2, TeaVM_String, characters);
                TEAVM_GC_ROOT(INT32_C(0), teavm_local_4);
                TEAVM_GC_ROOT(INT32_C(2), teavm_local_7);
                teavm_local_8 = (teavm_local_6 + TEAVM_ARRAY_LENGTH(TEAVM_WITH_CALL_SITE_ID(396, teavm_nullCheck(teavm_local_7))));
                TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(397, teavm_nullCheck(teavm_local_4));
                teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(398, teavm_checkBounds(teavm_local_6, teavm_local_4));
                TEAVM_ARRAY_AT(teavm_local_4, char16_t, TEAVM_WITH_CALL_SITE_ID(399, teavm_checkBounds(teavm_local_8, teavm_local_4))) = TEAVM_ARRAY_AT(teavm_local_4, char16_t, teavm_local_9);
                teavm_local_6 = (teavm_local_9 + -INT32_C(1));
            }
            teavm_local_4 = TEAVM_FIELD(teavm_local_2, TeaVM_String, characters);
            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
            TEAVM_GC_ROOT(INT32_C(1), teavm_local_4);
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(400, teavm_nullCheck(teavm_local_4));
            teavm_local_6 = TEAVM_ARRAY_LENGTH(teavm_local_4);
            TEAVM_FIELD(teavm_this_, cls_jl_AbstractStringBuilder, fld_length) = (teavm_local_3 + teavm_local_6);
            teavm_local_3 = INT32_C(0);
            while (1) {
                teavm_local_8 = teavm_compare_i32(teavm_local_3, teavm_local_6);
                if ((teavm_local_8 >= INT32_C(0))) {
                    goto teavm_label_4;
                }
                teavm_local_7 = TEAVM_FIELD(teavm_this_, cls_jl_AbstractStringBuilder, fld_buffer);
                teavm_local_9 = (teavm_local_1 + INT32_C(1));
                if ((teavm_local_3 < INT32_C(0))) {
                    goto teavm_label_1;
                }
                if ((teavm_local_8 >= INT32_C(0))) {
                    goto teavm_label_1;
                }
                TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
                teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(401, teavm_checkBounds(teavm_local_3, teavm_local_4));
                teavm_local_3 = TEAVM_ARRAY_AT(teavm_local_4, char16_t, teavm_local_8);
                teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(402, teavm_nullCheck(teavm_local_7));
                TEAVM_ARRAY_AT(teavm_local_7, char16_t, TEAVM_WITH_CALL_SITE_ID(403, teavm_checkBounds(teavm_local_1, teavm_local_7))) = teavm_local_3;
                teavm_local_3 = (teavm_local_8 + INT32_C(1));
                teavm_local_1 = teavm_local_9;
            }
        teavm_label_4:;
        teavm_label_2:;
            TEAVM_RELEASE_STACK;
            return teavm_this_;
        teavm_label_1:;
            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
            teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(404, meth_otr_Allocator_allocate(&jl_StringIndexOutOfBoundsException_Cls));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(405, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
            teavm_gc_writeBarrier(teavm_local_2);
            TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressed) = teavm_local_4;
            TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
            TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(406, meth_otr_ExceptionHandling_fillStackTrace());
            teavm_gc_writeBarrier(teavm_local_2);
            TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_stackTrace) = teavm_local_4;
            TEAVM_WITH_CALL_SITE_ID(407, meth_otr_ExceptionHandling_throwException(teavm_local_2));
            TEAVM_UNREACHABLE
        }
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(408, meth_otr_Allocator_allocate(&jl_StringIndexOutOfBoundsException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(409, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_2);
    TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressed) = teavm_local_4;
    TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(410, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_local_2);
    TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_stackTrace) = teavm_local_4;
    TEAVM_WITH_CALL_SITE_ID(411, meth_otr_ExceptionHandling_throwException(teavm_local_2));
    TEAVM_UNREACHABLE
}
void* meth_jl_AbstractStringBuilder_insert_0(void* teavm_this_, int32_t teavm_local_1, int32_t teavm_local_2, int32_t teavm_local_3) {
    int32_t teavm_local_4;
    TeaVM_Array* teavm_local_5;
    int32_t teavm_local_6;
    int32_t teavm_local_7;
    int32_t teavm_local_8;
    int32_t teavm_local_9;
    TEAVM_ALLOC_STACK(INT32_C(1));
    teavm_local_4 = INT32_C(1);
    if ((teavm_local_2 < INT32_C(0))) {
        teavm_local_4 = INT32_C(0);
        teavm_local_2 = (-teavm_local_2);
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    if ((TEAVM_WITH_CALL_SITE_ID(412, teavm_compare_u32(teavm_local_2, teavm_local_3)) < INT32_C(0))) {
        if (teavm_local_4) {
            TEAVM_WITH_CALL_SITE_ID(413, meth_jl_AbstractStringBuilder_insertSpace(teavm_this_, teavm_local_1, (teavm_local_1 + INT32_C(1))));
        } else {
            TEAVM_WITH_CALL_SITE_ID(414, meth_jl_AbstractStringBuilder_insertSpace(teavm_this_, teavm_local_1, (teavm_local_1 + INT32_C(2))));
            teavm_local_5 = TEAVM_FIELD(teavm_this_, cls_jl_AbstractStringBuilder, fld_buffer);
            teavm_local_6 = (teavm_local_1 + INT32_C(1));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_5);
            teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(415, teavm_nullCheck(teavm_local_5));
            TEAVM_ARRAY_AT(teavm_local_5, char16_t, TEAVM_WITH_CALL_SITE_ID(416, teavm_checkBounds(teavm_local_1, teavm_local_5))) = INT32_C(45);
            teavm_local_1 = teavm_local_6;
        }
        teavm_local_5 = TEAVM_FIELD(teavm_this_, cls_jl_AbstractStringBuilder, fld_buffer);
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_5);
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(417, meth_jl_Character_forDigit(teavm_local_2, teavm_local_3));
        teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(418, teavm_nullCheck(teavm_local_5));
        TEAVM_ARRAY_AT(teavm_local_5, char16_t, TEAVM_WITH_CALL_SITE_ID(419, teavm_checkBounds(teavm_local_1, teavm_local_5))) = teavm_local_2;
    } else {
        teavm_local_6 = INT32_C(1);
        teavm_local_7 = INT32_C(1);
        teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(420, ((int32_t) ((uint32_t) -INT32_C(1) / (uint32_t) teavm_local_3)));
        while (1) {
            teavm_local_9 = (teavm_local_6 * teavm_local_3);
            if ((TEAVM_WITH_CALL_SITE_ID(421, teavm_compare_u32(teavm_local_9, teavm_local_2)) > INT32_C(0))) {
                goto teavm_label_3;
            }
            teavm_local_7 = (teavm_local_7 + INT32_C(1));
            if ((TEAVM_WITH_CALL_SITE_ID(422, teavm_compare_u32(teavm_local_9, teavm_local_8)) > INT32_C(0))) {
                goto teavm_label_4;
            }
            teavm_local_6 = teavm_local_9;
        }
    teavm_label_4:;
        goto teavm_label_2;
    teavm_label_3:;
        teavm_local_9 = teavm_local_6;
    teavm_label_2:;
        if ((!teavm_local_4)) {
            teavm_local_7 = (teavm_local_7 + INT32_C(1));
        }
        TEAVM_WITH_CALL_SITE_ID(423, meth_jl_AbstractStringBuilder_insertSpace(teavm_this_, teavm_local_1, (teavm_local_1 + teavm_local_7)));
        if (teavm_local_4) {
            teavm_local_7 = teavm_local_1;
        } else {
            teavm_local_5 = TEAVM_FIELD(teavm_this_, cls_jl_AbstractStringBuilder, fld_buffer);
            teavm_local_7 = (teavm_local_1 + INT32_C(1));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_5);
            teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(424, teavm_nullCheck(teavm_local_5));
            TEAVM_ARRAY_AT(teavm_local_5, char16_t, TEAVM_WITH_CALL_SITE_ID(425, teavm_checkBounds(teavm_local_1, teavm_local_5))) = INT32_C(45);
        }
        while (1) {
            if ((!teavm_local_9)) {
                goto teavm_label_1;
            }
            teavm_local_5 = TEAVM_FIELD(teavm_this_, cls_jl_AbstractStringBuilder, fld_buffer);
            teavm_local_6 = (teavm_local_7 + INT32_C(1));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_5);
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(426, meth_jl_Character_forDigit(TEAVM_WITH_CALL_SITE_ID(427, ((int32_t) ((uint32_t) teavm_local_2 / (uint32_t) teavm_local_9))), teavm_local_3));
            teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(428, teavm_nullCheck(teavm_local_5));
            TEAVM_ARRAY_AT(teavm_local_5, char16_t, TEAVM_WITH_CALL_SITE_ID(429, teavm_checkBounds(teavm_local_7, teavm_local_5))) = teavm_local_4;
            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
            teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(430, ((int32_t) ((uint32_t) teavm_local_2 % (uint32_t) teavm_local_9)));
            teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(431, ((int32_t) ((uint32_t) teavm_local_9 / (uint32_t) teavm_local_3)));
            teavm_local_7 = teavm_local_6;
        }
    }
teavm_label_1:;
    TEAVM_RELEASE_STACK;
    return teavm_this_;
}
void meth_jl_AbstractStringBuilder_ensureCapacity(void* teavm_this_, int32_t teavm_local_1) {
    TeaVM_Array* teavm_local_2;
    int32_t teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    TeaVM_Array* teavm_local_6;
    TeaVM_Array* teavm_local_7;
    TEAVM_ALLOC_STACK(INT32_C(2));
    teavm_local_2 = TEAVM_FIELD(teavm_this_, cls_jl_AbstractStringBuilder, fld_buffer);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(432, teavm_nullCheck(teavm_local_2));
    teavm_local_3 = TEAVM_ARRAY_LENGTH(teavm_local_2);
    if ((teavm_local_3 < teavm_local_1)) {
        if ((teavm_local_3 >= INT32_C(1073741823))) {
            teavm_local_4 = INT32_C(2147483647);
        } else {
            teavm_local_5 = (teavm_local_3 * INT32_C(2));
            teavm_local_4 = INT32_C(5);
            if ((teavm_local_5 > teavm_local_4)) {
                teavm_local_4 = teavm_local_5;
            }
            if ((teavm_local_1 > teavm_local_4)) {
                teavm_local_4 = teavm_local_1;
            }
        }
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(433, meth_otr_Allocator_allocateArray(&Arr_C_Cls, teavm_local_4));
        if ((teavm_local_4 < teavm_local_3)) {
            teavm_local_3 = teavm_local_4;
        }
        teavm_local_7 = teavm_local_6;
        teavm_local_4 = INT32_C(0);
        while (1) {
            if (!(teavm_local_4 < teavm_local_3)) break;
            TEAVM_GC_ROOT(INT32_C(1), teavm_local_7);
            teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(434, teavm_checkBounds(teavm_local_4, teavm_local_2));
            teavm_local_4 = TEAVM_ARRAY_AT(teavm_local_2, char16_t, teavm_local_1);
            teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(435, teavm_checkUpperBound(teavm_local_1, teavm_local_7));
            TEAVM_ARRAY_AT(teavm_local_7, char16_t, teavm_local_1) = teavm_local_4;
            teavm_local_4 = (teavm_local_1 + INT32_C(1));
        }
        teavm_gc_writeBarrier(teavm_this_);
        TEAVM_FIELD(teavm_this_, cls_jl_AbstractStringBuilder, fld_buffer) = teavm_local_6;
    }
    TEAVM_RELEASE_STACK;
}
void meth_jl_AbstractStringBuilder_getChars(void* teavm_this_, int32_t teavm_local_1, int32_t teavm_local_2, TeaVM_Array* teavm_local_3, int32_t teavm_local_4) {
    int32_t teavm_local_5;
    TeaVM_Array* teavm_local_6;
    int32_t teavm_local_7;
    int32_t teavm_local_8;
    void* teavm_local_9;
    TEAVM_ALLOC_STACK(INT32_C(2));
    if ((teavm_local_1 <= teavm_local_2)) {
        while (1) {
            if (!(teavm_local_1 < teavm_local_2)) break;
            teavm_local_5 = (teavm_local_4 + INT32_C(1));
            teavm_local_6 = TEAVM_FIELD(teavm_this_, cls_jl_AbstractStringBuilder, fld_buffer);
            teavm_local_7 = (teavm_local_1 + INT32_C(1));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_6);
            TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
            teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(436, teavm_nullCheck(teavm_local_6));
            teavm_local_8 = TEAVM_ARRAY_AT(teavm_local_6, char16_t, TEAVM_WITH_CALL_SITE_ID(437, teavm_checkBounds(teavm_local_1, teavm_local_6)));
            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
            teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(438, teavm_nullCheck(teavm_local_3));
            teavm_local_6 = teavm_local_3;
            TEAVM_ARRAY_AT(teavm_local_6, char16_t, TEAVM_WITH_CALL_SITE_ID(439, teavm_checkBounds(teavm_local_4, teavm_local_6))) = teavm_local_8;
            teavm_local_4 = teavm_local_5;
            teavm_local_1 = teavm_local_7;
        }
        TEAVM_RELEASE_STACK;
        return;
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(440, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_9);
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(441, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_9);
    TEAVM_FIELD(teavm_local_9, cls_jl_Throwable, fld_suppressed) = teavm_local_3;
    TEAVM_FIELD(teavm_local_9, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_9, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(442, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_local_9);
    TEAVM_FIELD(teavm_local_9, cls_jl_Throwable, fld_stackTrace) = teavm_local_3;
    TEAVM_FIELD(teavm_local_9, cls_jl_Throwable, fld_message) = TEAVM_GET_STRING(20);
    TEAVM_WITH_CALL_SITE_ID(443, meth_otr_ExceptionHandling_throwException(teavm_local_9));
    TEAVM_UNREACHABLE
}
void meth_jl_AbstractStringBuilder_insertSpace(void* teavm_this_, int32_t teavm_local_1, int32_t teavm_local_2) {
    int32_t teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    void* teavm_local_6;
    TeaVM_Array* teavm_local_7;
    int32_t teavm_local_8;
    TEAVM_ALLOC_STACK(INT32_C(1));
    teavm_local_3 = TEAVM_FIELD(teavm_this_, cls_jl_AbstractStringBuilder, fld_length);
    teavm_local_4 = (teavm_local_3 - teavm_local_1);
    teavm_local_5 = ((teavm_local_3 + teavm_local_2) - teavm_local_1);
    teavm_local_6 = teavm_this_;
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_6);
    TEAVM_WITH_CALL_SITE_ID(444, meth_jl_AbstractStringBuilder_ensureCapacity(TEAVM_WITH_CALL_SITE_ID(445, teavm_nullCheck(teavm_local_6)), teavm_local_5));
    teavm_local_5 = (teavm_local_4 - INT32_C(1));
    while (1) {
        if (!(teavm_local_5 >= INT32_C(0))) break;
        teavm_local_7 = TEAVM_FIELD(teavm_this_, cls_jl_AbstractStringBuilder, fld_buffer);
        teavm_local_8 = (teavm_local_2 + teavm_local_5);
        teavm_local_3 = (teavm_local_1 + teavm_local_5);
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
        teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(446, teavm_nullCheck(teavm_local_7));
        teavm_local_3 = TEAVM_ARRAY_AT(teavm_local_7, char16_t, TEAVM_WITH_CALL_SITE_ID(447, teavm_checkBounds(teavm_local_3, teavm_local_7)));
        TEAVM_ARRAY_AT(teavm_local_7, char16_t, TEAVM_WITH_CALL_SITE_ID(448, teavm_checkBounds(teavm_local_8, teavm_local_7))) = teavm_local_3;
        teavm_local_5 = (teavm_local_5 + -INT32_C(1));
    }
    TEAVM_FIELD(teavm_this_, cls_jl_AbstractStringBuilder, fld_length) = (TEAVM_FIELD(teavm_this_, cls_jl_AbstractStringBuilder, fld_length) + (teavm_local_2 - teavm_local_1));
    TEAVM_RELEASE_STACK;
}
int32_t supertypeof_jl_AbstractStringBuilder(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 155 || tag >= 159) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_jl_AbstractStringBuilder_Cls[2];
alignas(8) jl_AbstractStringBuilder_VT jl_AbstractStringBuilder_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_AbstractStringBuilder), sizeof(void*)),
            .flags = 0,
            .tag = 155,
            .modifiers = 0,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jl_AbstractStringBuilder,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_jl_AbstractStringBuilder_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static int16_t teavm_classLayouts_jl_AbstractStringBuilder_Cls[2] = {
INT16_C(1), (int16_t) offsetof(cls_jl_AbstractStringBuilder, fld_buffer)
};
void sysinitclass_jl_AbstractStringBuilder() {
}
