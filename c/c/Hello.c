#include "Hello.h"
#include "j/l/Object.h"
#include "j/u/z/CRC32.h"
#include "o/t/r/Allocator.h"
#include "c/j/j/CRC32.h"
#include "j/n/c/StandardCharsets.h"
#include "../strings.h"
#include "j/l/String.h"
#include "j/n/CharBuffer.h"
#include "j/n/c/i/Iso8859Charset.h"
#include "j/n/c/CodingErrorAction.h"
#include "j/n/c/CharsetEncoder.h"
#include "j/l/AssertionError.h"
#include "../arrayclass.h"
#include "j/l/Throwable.h"
#include "o/t/r/ExceptionHandling.h"
#include "j/n/ByteBufferNative.h"
#include "j/n/Buffer.h"
#include "../a/p/byte.h"
#include "j/n/ByteBuffer.h"
#include "j/l/UnsupportedOperationException.h"
#include "j/l/System.h"
#include "j/i/PrintStream.h"
#include "o/t/c/i/c/StdoutOutputStream.h"
#include "j/i/FilterOutputStream.h"
#include "j/l/StringBuilder.h"
#include "../a/p/char.h"
#include "j/l/AbstractStringBuilder.h"
#include "j/n/c/i/UTF8Charset.h"
#include "j/l/Long.h"
#include "o/t/c/i/IntegerUtil.h"
#include "j/l/IndexOutOfBoundsException.h"

void meth_Hello_main(TeaVM_Array* teavm_local_1) {
    void* teavm_local_2;
    void* teavm_local_3;
    TeaVM_Array* teavm_local_4;
    void* teavm_local_5;
    void* teavm_local_6;
    int32_t teavm_local_7;
    int32_t teavm_local_8;
    int64_t teavm_local_9;
    void* teavm_local_10;
    void* teavm_local_11;
    int32_t teavm_local_12;
    TEAVM_ALLOC_STACK(INT32_C(4));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(3));
    TEAVM_WITH_CALL_SITE_ID(288, teavm_initializeClass((TeaVM_Class*) &Hello_Cls, &initclass_Hello));
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(289, meth_otr_Allocator_allocate(&juz_CRC32_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(290, meth_otr_Allocator_allocate(&cjj_CRC32_Cls));
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    TEAVM_WITH_CALL_SITE_ID(291, teavm_initializeClass((TeaVM_Class*) &cjj_CRC32_Cls, &initclass_cjj_CRC32));
    TEAVM_FIELD(teavm_local_3, cls_cjj_CRC32, fld_v) = INT32_C(0);
    teavm_gc_writeBarrier(teavm_local_2);
    TEAVM_FIELD(teavm_local_2, cls_juz_CRC32, fld_impl) = teavm_local_3;
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_WITH_CALL_SITE_ID(292, teavm_initializeClass((TeaVM_Class*) &jnc_StandardCharsets_Cls, &initclass_jnc_StandardCharsets));
    teavm_local_3 = sfld_jnc_StandardCharsets_ISO_8859_1;
    teavm_local_1 = TEAVM_FIELD(TEAVM_GET_STRING(12), TeaVM_String, characters);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    TEAVM_GC_ROOT(INT32_C(2), teavm_local_1);
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(293, teavm_nullCheck(teavm_local_1));
    teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(294, meth_jn_CharBuffer_wrap(teavm_local_4, INT32_C(0), TEAVM_ARRAY_LENGTH(teavm_local_4)));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_GC_ROOT(INT32_C(3), teavm_local_5);
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(295, teavm_nullCheck(teavm_local_3));
    TEAVM_TRY
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(296, meth_jnci_Iso8859Charset_newEncoder(TEAVM_WITH_CALL_SITE_ID(297, teavm_nullCheck(teavm_local_3))));
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_6);
        TEAVM_WITH_CALL_SITE_ID(298, teavm_initializeClass((TeaVM_Class*) &jnc_CodingErrorAction_Cls, &initclass_jnc_CodingErrorAction));
        teavm_local_3 = sfld_jnc_CodingErrorAction_REPLACE;
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(299, meth_jnc_CharsetEncoder_onMalformedInput(TEAVM_WITH_CALL_SITE_ID(300, teavm_nullCheck(teavm_local_6)), teavm_local_3));
        teavm_local_6 = sfld_jnc_CodingErrorAction_REPLACE;
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_6);
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(301, meth_jnc_CharsetEncoder_onUnmappableCharacter(TEAVM_WITH_CALL_SITE_ID(302, teavm_nullCheck(teavm_local_3)), teavm_local_6));
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(303, meth_jnc_CharsetEncoder_encode(TEAVM_WITH_CALL_SITE_ID(304, teavm_nullCheck(teavm_local_3)), teavm_local_5));
        TEAVM_RESTORE_JUMP_BUFFER;
        goto teavm_label_1;
    TEAVM_CATCH
        // CATCH java.nio.charset.CharacterCodingException
        case 1: {
            teavm_local_3 = teavm_catchException();
            break;
        }
    TEAVM_END_TRY
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_3);
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(3));
    teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(305, meth_otr_Allocator_allocate(&jl_AssertionError_Cls));
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(306, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_6);
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(307, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_local_6);
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_message) = TEAVM_GET_STRING(13);
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_cause) = teavm_local_3;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_WITH_CALL_SITE_ID(308, meth_otr_ExceptionHandling_throwException(teavm_local_6));
    TEAVM_UNREACHABLE
teavm_label_1:;
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT(INT32_C(2), teavm_local_3);
    TEAVM_GC_ROOT_RELEASE(INT32_C(3));
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(309, teavm_nullCheck(teavm_local_3));
    teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(310, teavm_nullCheck(teavm_local_3));
    teavm_local_1 = TEAVM_FIELD(teavm_local_6, cls_jn_ByteBufferNative, fld_array);
    teavm_local_7 = ((teavm_local_1 == NULL) ? INT32_C(0) : INT32_C(1));
    if ((!(teavm_local_7 && ((!TEAVM_FIELD(teavm_local_3, cls_jn_Buffer, fld_position)) && (TEAVM_FIELD(teavm_local_3, cls_jn_Buffer, fld_limit) == TEAVM_FIELD(teavm_local_6, cls_jn_ByteBufferNative, fld_capacity)))))) {
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(311, meth_otr_Allocator_allocateArray(&Arr_B_Cls, (TEAVM_FIELD(teavm_local_3, cls_jn_Buffer, fld_limit) - TEAVM_FIELD(teavm_local_3, cls_jn_Buffer, fld_position))));
        teavm_local_8 = TEAVM_ARRAY_LENGTH(teavm_local_1);
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_1);
        TEAVM_WITH_CALL_SITE_ID(312, meth_jn_ByteBuffer_get(teavm_local_3, teavm_local_1, INT32_C(0), teavm_local_8));
    } else if ((teavm_local_1 == NULL)) {
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(313, meth_otr_Allocator_allocate(&jl_UnsupportedOperationException_Cls));
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(314, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
        teavm_gc_writeBarrier(teavm_local_2);
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(315, meth_otr_ExceptionHandling_fillStackTrace());
        teavm_gc_writeBarrier(teavm_local_2);
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
        TEAVM_WITH_CALL_SITE_ID(316, meth_otr_ExceptionHandling_throwException(teavm_local_2));
        TEAVM_UNREACHABLE
    }
    teavm_local_8 = TEAVM_ARRAY_LENGTH(teavm_local_1);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_1);
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_WITH_CALL_SITE_ID(317, meth_juz_CRC32_update(teavm_local_2, teavm_local_1, INT32_C(0), teavm_local_8));
    if ((sfld_jl_System_outCache == NULL)) {
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(318, meth_otr_Allocator_allocate(&ji_PrintStream_Cls));
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
        TEAVM_WITH_CALL_SITE_ID(319, teavm_initializeClass((TeaVM_Class*) &otcic_StdoutOutputStream_Cls, &initclass_otcic_StdoutOutputStream));
        teavm_local_3 = sfld_otcic_StdoutOutputStream_INSTANCE;
        teavm_gc_writeBarrier(teavm_local_6);
        TEAVM_FIELD(teavm_local_6, cls_ji_FilterOutputStream, fld_out) = teavm_local_3;
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(320, meth_otr_Allocator_allocate(&jl_StringBuilder_Cls));
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_3);
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(321, meth_otr_Allocator_allocateArray(&Arr_C_Cls, INT32_C(16)));
        teavm_gc_writeBarrier(teavm_local_3);
        TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_buffer) = teavm_local_1;
        teavm_gc_writeBarrier(teavm_local_6);
        TEAVM_FIELD(teavm_local_6, cls_ji_PrintStream, fld_sb) = teavm_local_3;
        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(322, meth_otr_Allocator_allocateArray(&Arr_C_Cls, INT32_C(32)));
        teavm_gc_writeBarrier(teavm_local_6);
        TEAVM_FIELD(teavm_local_6, cls_ji_PrintStream, fld_buffer) = teavm_local_1;
        TEAVM_FIELD(teavm_local_6, cls_ji_PrintStream, fld_autoFlush) = INT32_C(0);
        TEAVM_WITH_CALL_SITE_ID(323, teavm_initializeClass((TeaVM_Class*) &jnci_UTF8Charset_Cls, &initclass_jnci_UTF8Charset));
        teavm_local_3 = sfld_jnci_UTF8Charset_INSTANCE;
        teavm_gc_writeBarrier(teavm_local_6);
        TEAVM_FIELD(teavm_local_6, cls_ji_PrintStream, fld_charset) = teavm_local_3;
        sfld_jl_System_outCache = teavm_local_6;
    }
    teavm_local_3 = sfld_jl_System_outCache;
    teavm_local_2 = TEAVM_FIELD(teavm_local_2, cls_juz_CRC32, fld_impl);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT(INT32_C(2), teavm_local_3);
    teavm_local_9 = (((int64_t) TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(324, teavm_nullCheck(teavm_local_2)), cls_cjj_CRC32, fld_v)) & INT64_C(4294967295));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_WITH_CALL_SITE_ID(325, teavm_initializeClass((TeaVM_Class*) &jl_Long_Cls, &initclass_jl_Long));
    teavm_local_10 = TEAVM_WITH_CALL_SITE_ID(326, meth_otci_IntegerUtil_toUnsignedLogRadixString(teavm_local_9, INT32_C(4)));
    TEAVM_GC_ROOT(INT32_C(3), teavm_local_10);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(327, meth_otr_Allocator_allocate(&jl_StringBuilder_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(328, meth_otr_Allocator_allocateArray(&Arr_C_Cls, INT32_C(16)));
    teavm_gc_writeBarrier(teavm_local_2);
    TEAVM_FIELD(teavm_local_2, cls_jl_AbstractStringBuilder, fld_buffer) = teavm_local_1;
    teavm_local_7 = TEAVM_FIELD(teavm_local_2, cls_jl_AbstractStringBuilder, fld_length);
    teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(329, teavm_nullCheck(teavm_local_2));
    teavm_local_6 = TEAVM_GET_STRING(14);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
    teavm_local_11 = TEAVM_WITH_CALL_SITE_ID(330, teavm_nullCheck(teavm_local_6));
    teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(331, teavm_nullCheck(teavm_local_5));
    TEAVM_WITH_CALL_SITE_ID(332, meth_jl_AbstractStringBuilder_insert(teavm_local_5, teavm_local_7, teavm_local_11));
    teavm_local_7 = TEAVM_FIELD(teavm_local_2, cls_jl_AbstractStringBuilder, fld_length);
    if ((teavm_local_10 == NULL)) {
        teavm_local_6 = TEAVM_GET_STRING(4);
    } else {
        teavm_local_6 = teavm_local_10;
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(333, teavm_nullCheck(teavm_local_6));
    }
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
    TEAVM_GC_ROOT_RELEASE(INT32_C(3));
    TEAVM_WITH_CALL_SITE_ID(334, meth_jl_AbstractStringBuilder_insert(teavm_local_5, teavm_local_7, teavm_local_6));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(335, meth_otr_Allocator_allocate(&jl_String_Cls));
    teavm_local_1 = TEAVM_FIELD(teavm_local_2, cls_jl_AbstractStringBuilder, fld_buffer);
    teavm_local_8 = TEAVM_FIELD(teavm_local_2, cls_jl_AbstractStringBuilder, fld_length);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
    TEAVM_WITH_CALL_SITE_ID(336, teavm_initializeClass((TeaVM_Class*) &jl_String_Cls, &initclass_jl_String));
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(337, teavm_nullCheck(teavm_local_1));
    teavm_local_12 = TEAVM_ARRAY_LENGTH(teavm_local_4);
    if (((teavm_local_8 >= INT32_C(0)) && (teavm_local_8 <= (teavm_local_12 - INT32_C(0))))) {
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(338, meth_otr_Allocator_allocateArray(&Arr_C_Cls, teavm_local_8));
        TEAVM_GC_ROOT(INT32_C(3), teavm_local_1);
        TEAVM_WITH_CALL_SITE_ID(339, meth_jl_System_fastArraycopy(teavm_local_4, INT32_C(0), teavm_local_1, INT32_C(0), teavm_local_8));
        teavm_gc_writeBarrier(teavm_local_6);
        TEAVM_FIELD(teavm_local_6, TeaVM_String, characters) = teavm_local_1;
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT_RELEASE(INT32_C(3));
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(340, teavm_nullCheck(teavm_local_3));
        teavm_local_3 = TEAVM_FIELD(teavm_local_2, cls_ji_PrintStream, fld_sb);
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_3);
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(341, teavm_nullCheck(teavm_local_3));
        teavm_local_7 = TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_length);
        teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(342, teavm_nullCheck(teavm_local_3));
        TEAVM_WITH_CALL_SITE_ID(343, meth_jl_AbstractStringBuilder_insert(teavm_local_5, teavm_local_7, teavm_local_6));
        teavm_local_8 = TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_length);
        teavm_local_12 = (teavm_local_8 + INT32_C(1));
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        TEAVM_WITH_CALL_SITE_ID(344, meth_jl_AbstractStringBuilder_insertSpace(teavm_local_5, teavm_local_8, teavm_local_12));
        teavm_local_1 = TEAVM_FIELD(teavm_local_5, cls_jl_AbstractStringBuilder, fld_buffer);
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(345, teavm_nullCheck(teavm_local_1));
        TEAVM_ARRAY_AT(teavm_local_1, char16_t, TEAVM_WITH_CALL_SITE_ID(346, teavm_checkBounds(teavm_local_8, teavm_local_1))) = INT32_C(10);
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_WITH_CALL_SITE_ID(347, meth_ji_PrintStream_printSB(teavm_local_2));
        TEAVM_RELEASE_STACK;
        return;
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(348, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(349, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_2);
    TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
    TEAVM_WITH_CALL_SITE_ID(350, meth_jl_Throwable_initNativeException(teavm_local_2));
    TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    TEAVM_WITH_CALL_SITE_ID(351, meth_jl_Throwable_fillInStackTrace(teavm_local_2));
    TEAVM_WITH_CALL_SITE_ID(352, meth_otr_ExceptionHandling_throwException(teavm_local_2));
    TEAVM_UNREACHABLE
}
void meth_Hello__clinit_() {
    return;
}
void initclass_Hello() {
    TeaVM_Class* cls = (TeaVM_Class*) &Hello_Cls;
    if (!(cls->flags & INT32_C(1))) {
        cls->flags |= INT32_C(1);
        meth_Hello__clinit_();
    }
}
int32_t supertypeof_Hello(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 133 || tag >= 135) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) Hello_VT Hello_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_Hello), sizeof(void*)),
            .flags = 0,
            .tag = 133,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_Hello,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
void sysinitclass_Hello() {
}
