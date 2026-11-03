#include "PrintStream.h"
#include "FilterOutputStream.h"
#include "../../../a/p/byte.h"
#include "../../o/t/r/Allocator.h"
#include "../n/ByteBufferNative.h"
#include "../n/Buffer.h"
#include "../n/ByteOrder.h"
#include "../n/ByteBuffer.h"
#include "../n/c/i/UTF8Encoder.h"
#include "../n/c/CodingErrorAction.h"
#include "../n/c/CharsetEncoder.h"
#include "../l/Object.h"
#include "../../../a/p/char.h"
#include "../n/c/i/BufferedEncoder.h"
#include "../n/c/CoderResult.h"
#include "../../o/t/c/i/c/StdoutOutputStream.h"
#include "../l/IllegalStateException.h"
#include "../../../arrayclass.h"
#include "../l/Throwable.h"
#include "../../o/t/r/ExceptionHandling.h"
#include "../l/IllegalArgumentException.h"
#include "../../../strings.h"
#include "../l/Exception.h"
#include "../l/IndexOutOfBoundsException.h"
#include "../l/AbstractStringBuilder.h"
#include "../n/CharBuffer.h"

void meth_ji_PrintStream_printCharBuffer(void* teavm_this_, void* teavm_local_1, int32_t teavm_local_2, int32_t teavm_local_3) {
    TeaVM_Array* teavm_local_4;
    void* teavm_local_5;
    void* teavm_local_6;
    void* teavm_local_7;
    TeaVM_Array* teavm_local_8;
    TeaVM_Array* teavm_local_9;
    void* teavm_local_10;
    int32_t teavm_local_11;
    int32_t teavm_local_12;
    TEAVM_ALLOC_STACK(INT32_C(5));
    teavm_local_2 = (teavm_local_3 - teavm_local_2);
    teavm_local_3 = INT32_C(1024);
    if ((teavm_local_2 < teavm_local_3)) {
        teavm_local_3 = teavm_local_2;
    }
    if ((INT32_C(16) > teavm_local_3)) {
        teavm_local_3 = INT32_C(16);
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(3));
    TEAVM_GC_ROOT_RELEASE(INT32_C(4));
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(600, meth_otr_Allocator_allocateArray(&Arr_B_Cls, teavm_local_3));
    teavm_local_3 = TEAVM_ARRAY_LENGTH(teavm_local_4);
    if (((teavm_local_3 >= INT32_C(0)) && (teavm_local_3 <= (teavm_local_3 - INT32_C(0))))) {
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_4);
        teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(601, meth_otr_Allocator_allocate(&jn_ByteBufferNative_Cls));
        teavm_local_6 = TEAVM_ARRAY_DATA(teavm_local_4, int32_t);
        TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_mark) = -INT32_C(1);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_5);
        TEAVM_WITH_CALL_SITE_ID(602, teavm_initializeClass((TeaVM_Class*) &jn_ByteOrder_Cls, &initclass_jn_ByteOrder));
        teavm_local_7 = sfld_jn_ByteOrder_BIG_ENDIAN;
        teavm_gc_writeBarrier(teavm_local_5);
        TEAVM_FIELD(teavm_local_5, cls_jn_ByteBuffer, fld_order) = teavm_local_7;
        TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_gcRef) = teavm_local_5;
        TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_array) = teavm_local_4;
        TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_arrayOffset) = INT32_C(0);
        TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_base) = teavm_local_4;
        TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_address) = teavm_local_6;
        TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_capacity) = teavm_local_3;
        TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_readOnly) = INT32_C(0);
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_7);
        TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_swap) = ((teavm_local_7 == TEAVM_WITH_CALL_SITE_ID(603, meth_jn_ByteOrder_nativeOrder())) ? INT32_C(0) : INT32_C(1));
        TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_position) = INT32_C(0);
        TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_limit) = (INT32_C(0) + teavm_local_3);
        teavm_local_6 = TEAVM_FIELD(teavm_this_, cls_ji_PrintStream, fld_charset);
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(604, teavm_nullCheck(teavm_local_6));
        teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(605, meth_otr_Allocator_allocate(&jnci_UTF8Encoder_Cls));
        TEAVM_GC_ROOT(INT32_C(3), teavm_local_7);
        teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(606, meth_otr_Allocator_allocateArray(&Arr_B_Cls, INT32_C(1)));
        teavm_local_9 = teavm_local_8;
        TEAVM_ARRAY_AT(teavm_local_9, int8_t, INT32_C(0)) = INT32_C(63);
        TEAVM_GC_ROOT(INT32_C(4), teavm_local_9);
        TEAVM_WITH_CALL_SITE_ID(607, teavm_initializeClass((TeaVM_Class*) &jnc_CodingErrorAction_Cls, &initclass_jnc_CodingErrorAction));
        teavm_local_10 = sfld_jnc_CodingErrorAction_REPORT;
        teavm_gc_writeBarrier(teavm_local_7);
        TEAVM_FIELD(teavm_local_7, cls_jnc_CharsetEncoder, fld_malformedAction) = teavm_local_10;
        TEAVM_FIELD(teavm_local_7, cls_jnc_CharsetEncoder, fld_unmappableAction) = teavm_local_10;
        teavm_local_2 = TEAVM_ARRAY_LENGTH(teavm_local_9);
        if ((teavm_local_2 && (!(((float) teavm_local_2) < TEAVM_FIELD(teavm_local_7, cls_jnc_CharsetEncoder, fld_maxBytesPerChar))))) {
            teavm_gc_writeBarrier(teavm_local_7);
            TEAVM_FIELD(teavm_local_7, cls_jnc_CharsetEncoder, fld_charset) = teavm_local_6;
            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
            teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(608, TEAVM_METHOD(teavm_local_8, jl_Object_VT, virt_clone)(teavm_local_8));
            teavm_gc_writeBarrier(teavm_local_7);
            TEAVM_FIELD(teavm_local_7, cls_jnc_CharsetEncoder, fld_replacement) = teavm_local_8;
            TEAVM_FIELD(teavm_local_7, cls_jnc_CharsetEncoder, fld_averageBytesPerChar) = 2.0f;
            TEAVM_FIELD(teavm_local_7, cls_jnc_CharsetEncoder, fld_maxBytesPerChar) = 4.0f;
            TEAVM_GC_ROOT_RELEASE(INT32_C(4));
            teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(609, meth_otr_Allocator_allocateArray(&Arr_C_Cls, INT32_C(512)));
            teavm_gc_writeBarrier(teavm_local_7);
            TEAVM_FIELD(teavm_local_7, cls_jnci_BufferedEncoder, fld_inArray) = teavm_local_8;
            teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(610, meth_otr_Allocator_allocateArray(&Arr_B_Cls, INT32_C(512)));
            teavm_gc_writeBarrier(teavm_local_7);
            TEAVM_FIELD(teavm_local_7, cls_jnci_BufferedEncoder, fld_outArray) = teavm_local_8;
            teavm_local_6 = sfld_jnc_CodingErrorAction_REPLACE;
            if ((teavm_local_6 != NULL)) {
                teavm_gc_writeBarrier(teavm_local_7);
                TEAVM_FIELD(teavm_local_7, cls_jnc_CharsetEncoder, fld_malformedAction) = teavm_local_6;
                TEAVM_FIELD(teavm_local_7, cls_jnc_CharsetEncoder, fld_unmappableAction) = teavm_local_6;
                while (1) {
                    teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(611, meth_jnc_CharsetEncoder_encode_0(teavm_local_7, teavm_local_1, teavm_local_5, INT32_C(1)));
                    TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
                    teavm_local_11 = ((TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(612, teavm_nullCheck(teavm_local_6)), cls_jnc_CoderResult, fld_kind) != INT32_C(1)) ? INT32_C(0) : INT32_C(1));
                    teavm_local_12 = TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_position);
                    teavm_local_6 = TEAVM_FIELD(teavm_this_, cls_ji_FilterOutputStream, fld_out);
                    if ((teavm_local_6 == NULL)) {
                        TEAVM_FIELD(teavm_this_, cls_ji_PrintStream, fld_errorState) = INT32_C(1);
                    }
                    if ((TEAVM_FIELD(teavm_this_, cls_ji_PrintStream, fld_errorState) ? INT32_C(0) : INT32_C(1))) {
                        TEAVM_TRY
                            teavm_local_6 = teavm_local_6;
                            TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
                            TEAVM_WITH_CALL_SITE_ID(613, meth_otcic_StdoutOutputStream_write(TEAVM_WITH_CALL_SITE_ID(614, teavm_nullCheck(teavm_local_6)), teavm_local_4, INT32_C(0), teavm_local_12));
                            TEAVM_RESTORE_JUMP_BUFFER;
                            goto teavm_label_2;
                        TEAVM_CATCH
                            // CATCH java.io.IOException
                            case 1: {
                                goto teavm_label_3;
                                break;
                            }
                        TEAVM_END_TRY
                    teavm_label_3:;
                        TEAVM_FIELD(teavm_this_, cls_ji_PrintStream, fld_errorState) = INT32_C(1);
                    teavm_label_2:;
                    }
                    TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_position) = INT32_C(0);
                    teavm_local_6 = teavm_local_5;
                    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                    teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(615, teavm_nullCheck(teavm_local_6));
                    TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_limit) = TEAVM_FIELD(teavm_local_6, cls_jn_ByteBufferNative, fld_capacity);
                    TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_mark) = -INT32_C(1);
                    if ((!teavm_local_11)) {
                        goto teavm_label_1;
                    }
                }
            teavm_label_1:;
                while (1) {
                    teavm_local_3 = TEAVM_FIELD(teavm_local_7, cls_jnc_CharsetEncoder, fld_status);
                    if (((teavm_local_3 != INT32_C(2)) && (teavm_local_3 != INT32_C(4)))) {
                        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                        TEAVM_GC_ROOT_RELEASE(INT32_C(3));
                        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(616, meth_otr_Allocator_allocate(&jl_IllegalStateException_Cls));
                        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
                        teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(617, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                        teavm_gc_writeBarrier(teavm_local_1);
                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_4;
                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                        teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(618, meth_otr_ExceptionHandling_fillStackTrace());
                        teavm_gc_writeBarrier(teavm_local_1);
                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_4;
                        TEAVM_WITH_CALL_SITE_ID(619, meth_otr_ExceptionHandling_throwException(teavm_local_1));
                        TEAVM_UNREACHABLE
                    }
                    TEAVM_WITH_CALL_SITE_ID(620, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
                    teavm_local_1 = sfld_jnc_CoderResult_UNDERFLOW;
                    if ((teavm_local_1 == teavm_local_1)) {
                        TEAVM_FIELD(teavm_local_7, cls_jnc_CharsetEncoder, fld_status) = INT32_C(3);
                    }
                    TEAVM_GC_ROOT(INT32_C(1), teavm_local_1);
                    teavm_local_11 = ((TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(621, teavm_nullCheck(teavm_local_1)), cls_jnc_CoderResult, fld_kind) != INT32_C(1)) ? INT32_C(0) : INT32_C(1));
                    teavm_local_12 = TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_position);
                    teavm_local_1 = TEAVM_FIELD(teavm_this_, cls_ji_FilterOutputStream, fld_out);
                    if ((teavm_local_1 == NULL)) {
                        TEAVM_FIELD(teavm_this_, cls_ji_PrintStream, fld_errorState) = INT32_C(1);
                    }
                    if ((TEAVM_FIELD(teavm_this_, cls_ji_PrintStream, fld_errorState) ? INT32_C(0) : INT32_C(1))) {
                        TEAVM_TRY
                            teavm_local_1 = teavm_local_1;
                            TEAVM_GC_ROOT(INT32_C(1), teavm_local_1);
                            TEAVM_WITH_CALL_SITE_ID(622, meth_otcic_StdoutOutputStream_write(TEAVM_WITH_CALL_SITE_ID(623, teavm_nullCheck(teavm_local_1)), teavm_local_4, INT32_C(0), teavm_local_12));
                            TEAVM_RESTORE_JUMP_BUFFER;
                            goto teavm_label_5;
                        TEAVM_CATCH
                            // CATCH java.io.IOException
                            case 1: {
                                goto teavm_label_6;
                                break;
                            }
                        TEAVM_END_TRY
                    teavm_label_6:;
                        TEAVM_FIELD(teavm_this_, cls_ji_PrintStream, fld_errorState) = INT32_C(1);
                    teavm_label_5:;
                    }
                    TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_position) = INT32_C(0);
                    TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_limit) = TEAVM_FIELD(teavm_local_6, cls_jn_ByteBufferNative, fld_capacity);
                    TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_mark) = -INT32_C(1);
                    if ((!teavm_local_11)) {
                        goto teavm_label_4;
                    }
                }
            teavm_label_4:;
                TEAVM_RELEASE_STACK;
                return;
            }
            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
            TEAVM_GC_ROOT_RELEASE(INT32_C(2));
            TEAVM_GC_ROOT_RELEASE(INT32_C(3));
            teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(624, meth_otr_Allocator_allocate(&jl_IllegalArgumentException_Cls));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_6);
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(625, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
            teavm_gc_writeBarrier(teavm_local_6);
            TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_suppressed) = teavm_local_4;
            TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
            TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(626, meth_otr_ExceptionHandling_fillStackTrace());
            teavm_gc_writeBarrier(teavm_local_6);
            TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_stackTrace) = teavm_local_4;
            TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_message) = TEAVM_GET_STRING(25);
            TEAVM_WITH_CALL_SITE_ID(627, meth_otr_ExceptionHandling_throwException(teavm_local_6));
            TEAVM_UNREACHABLE
        }
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
        TEAVM_GC_ROOT_RELEASE(INT32_C(3));
        TEAVM_GC_ROOT_RELEASE(INT32_C(4));
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(628, meth_otr_Allocator_allocate(&jl_IllegalArgumentException_Cls));
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_6);
        TEAVM_WITH_CALL_SITE_ID(629, meth_jl_Exception__init_(teavm_local_6, TEAVM_GET_STRING(26)));
        TEAVM_WITH_CALL_SITE_ID(630, meth_otr_ExceptionHandling_throwException(teavm_local_6));
        TEAVM_UNREACHABLE
    }
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(631, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(632, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_4;
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(633, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_4;
    TEAVM_WITH_CALL_SITE_ID(634, meth_otr_ExceptionHandling_throwException(teavm_local_1));
    TEAVM_UNREACHABLE
}
void meth_ji_PrintStream_printSB(void* teavm_this_) {
    void* teavm_local_1;
    int32_t teavm_local_2;
    TeaVM_Array* teavm_local_3;
    int32_t teavm_local_4;
    TEAVM_ALLOC_STACK(INT32_C(2));
    teavm_local_1 = TEAVM_FIELD(teavm_this_, cls_ji_PrintStream, fld_sb);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(635, teavm_nullCheck(teavm_local_1));
    teavm_local_2 = TEAVM_FIELD(teavm_local_1, cls_jl_AbstractStringBuilder, fld_length);
    teavm_local_3 = TEAVM_FIELD(teavm_this_, cls_ji_PrintStream, fld_buffer);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    if ((teavm_local_2 > TEAVM_ARRAY_LENGTH(TEAVM_WITH_CALL_SITE_ID(636, teavm_nullCheck(teavm_local_3))))) {
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(637, meth_otr_Allocator_allocateArray(&Arr_C_Cls, teavm_local_2));
    }
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    TEAVM_WITH_CALL_SITE_ID(638, meth_jl_AbstractStringBuilder_getChars(teavm_local_1, INT32_C(0), teavm_local_2, teavm_local_3, INT32_C(0)));
    teavm_local_1 = TEAVM_FIELD(teavm_this_, cls_ji_PrintStream, fld_sb);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_2 = TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(639, teavm_nullCheck(teavm_local_1)), cls_jl_AbstractStringBuilder, fld_length);
    teavm_local_4 = (teavm_local_2 - INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(640, meth_jn_CharBuffer_wrap(teavm_local_3, INT32_C(0), teavm_local_4));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_WITH_CALL_SITE_ID(641, meth_ji_PrintStream_printCharBuffer(teavm_this_, teavm_local_1, INT32_C(0), teavm_local_2));
    teavm_local_1 = TEAVM_FIELD(teavm_this_, cls_ji_PrintStream, fld_sb);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(642, teavm_nullCheck(teavm_local_1)), cls_jl_AbstractStringBuilder, fld_length) = INT32_C(0);
    TEAVM_RELEASE_STACK;
}
int32_t supertypeof_ji_PrintStream(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 191 || tag >= 193) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_ji_PrintStream_Cls[4];
alignas(8) ji_PrintStream_VT ji_PrintStream_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_ji_PrintStream), sizeof(void*)),
                    .flags = 0,
                    .tag = 191,
                    .modifiers = 1,
                    .name = NULL,
                    .arrayType = NULL,
                    .itemType = NULL,
                    .isSupertypeOf = &supertypeof_ji_PrintStream,
                    .superclass = (TeaVM_Class*) &ji_FilterOutputStream_Cls,
                    .layout = teavm_classLayouts_ji_PrintStream_Cls,
                    .enumValues = NULL
                },
                .virt_clone = &meth_jl_Object_clone
            }
        }
    }
};
static int16_t teavm_classLayouts_ji_PrintStream_Cls[4] = {
INT16_C(3), (int16_t) offsetof(cls_ji_PrintStream, fld_sb), (int16_t) offsetof(cls_ji_PrintStream, fld_buffer), (int16_t) offsetof(cls_ji_PrintStream, fld_charset)
};
void sysinitclass_ji_PrintStream() {
}
