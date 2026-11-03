#include "CharsetEncoder.h"
#include "../../l/Object.h"
#include "../../l/IllegalArgumentException.h"
#include "../../../o/t/r/Allocator.h"
#include "../../../../arrayclass.h"
#include "../../l/Throwable.h"
#include "../../../o/t/r/ExceptionHandling.h"
#include "../../../../strings.h"
#include "../../l/IllegalStateException.h"
#include "i/BufferedEncoder.h"
#include "CoderMalfunctionError.h"
#include "CoderResult.h"
#include "../Buffer.h"
#include "CodingErrorAction.h"
#include "../ByteBuffer.h"
#include "../../l/UnsupportedOperationException.h"
#include "BufferOverflowException.h"
#include "MalformedInputException.h"
#include "UnmappableCharacterException.h"
#include "BufferUnderflowException.h"
#include "../ByteBufferNative.h"
#include "../../../../a/p/byte.h"
#include "../ByteOrder.h"
#include "../../l/IndexOutOfBoundsException.h"

void* meth_jnc_CharsetEncoder_onMalformedInput(void* teavm_this_, void* teavm_local_1) {
    void* teavm_local_2;
    TeaVM_Array* teavm_local_3;
    TEAVM_ALLOC_STACK(INT32_C(1));
    if ((teavm_local_1 == NULL)) {
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(676, meth_otr_Allocator_allocate(&jl_IllegalArgumentException_Cls));
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(677, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
        teavm_gc_writeBarrier(teavm_local_2);
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressed) = teavm_local_3;
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(678, meth_otr_ExceptionHandling_fillStackTrace());
        teavm_gc_writeBarrier(teavm_local_2);
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_stackTrace) = teavm_local_3;
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_message) = TEAVM_GET_STRING(25);
        TEAVM_WITH_CALL_SITE_ID(679, meth_otr_ExceptionHandling_throwException(teavm_local_2));
        TEAVM_UNREACHABLE
    }
    teavm_gc_writeBarrier(teavm_this_);
    TEAVM_FIELD(teavm_this_, cls_jnc_CharsetEncoder, fld_malformedAction) = teavm_local_1;
    TEAVM_RELEASE_STACK;
    return teavm_this_;
}
void meth_jnc_CharsetEncoder_implOnMalformedInput(void* teavm_this_, void* teavm_local_1) {
    return;
}
void* meth_jnc_CharsetEncoder_onUnmappableCharacter(void* teavm_this_, void* teavm_local_1) {
    void* teavm_local_2;
    TeaVM_Array* teavm_local_3;
    TEAVM_ALLOC_STACK(INT32_C(1));
    if ((teavm_local_1 == NULL)) {
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(680, meth_otr_Allocator_allocate(&jl_IllegalArgumentException_Cls));
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(681, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
        teavm_gc_writeBarrier(teavm_local_2);
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressed) = teavm_local_3;
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(682, meth_otr_ExceptionHandling_fillStackTrace());
        teavm_gc_writeBarrier(teavm_local_2);
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_stackTrace) = teavm_local_3;
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_message) = TEAVM_GET_STRING(25);
        TEAVM_WITH_CALL_SITE_ID(683, meth_otr_ExceptionHandling_throwException(teavm_local_2));
        TEAVM_UNREACHABLE
    }
    teavm_gc_writeBarrier(teavm_this_);
    TEAVM_FIELD(teavm_this_, cls_jnc_CharsetEncoder, fld_unmappableAction) = teavm_local_1;
    TEAVM_RELEASE_STACK;
    return teavm_this_;
}
void meth_jnc_CharsetEncoder_implOnUnmappableCharacter(void* teavm_this_, void* teavm_local_1) {
    return;
}
void* meth_jnc_CharsetEncoder_encode_0(void* teavm_this_, void* teavm_local_1, void* teavm_local_2, int32_t teavm_local_3) {
    int32_t teavm_local_4;
    TeaVM_Array* teavm_local_5;
    void* teavm_local_6;
    void * volatile teavm_spill_6;
    void* teavm_local_7;
    void* teavm_local_8;
    int32_t teavm_local_9;
    TeaVM_Array* teavm_local_10;
    int32_t teavm_local_11;
    TEAVM_ALLOC_STACK(INT32_C(5));
    teavm_local_4 = TEAVM_FIELD(teavm_this_, cls_jnc_CharsetEncoder, fld_status);
    if ((teavm_local_4 != INT32_C(3))) {
        if (teavm_local_3) {
            goto teavm_label_1;
        }
        if ((teavm_local_4 != INT32_C(2))) {
            goto teavm_label_1;
        }
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(3));
    TEAVM_GC_ROOT_RELEASE(INT32_C(4));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(684, meth_otr_Allocator_allocate(&jl_IllegalStateException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(685, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_5;
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(686, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_5;
    TEAVM_WITH_CALL_SITE_ID(687, meth_otr_ExceptionHandling_throwException(teavm_local_1));
    TEAVM_UNREACHABLE
teavm_label_1:;
    TEAVM_FIELD(teavm_this_, cls_jnc_CharsetEncoder, fld_status) = ((!teavm_local_3) ? INT32_C(1) : INT32_C(2));
    teavm_local_6 = teavm_this_;
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_6);
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(3));
    TEAVM_GC_ROOT_RELEASE(INT32_C(4));
    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(688, teavm_nullCheck(teavm_local_6));
    while (1) {
        TEAVM_TRY
            teavm_spill_6 = teavm_local_6;
            TEAVM_GC_ROOT(INT32_C(2), teavm_local_1);
            TEAVM_GC_ROOT(INT32_C(3), teavm_local_2);
            teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(689, meth_jnci_BufferedEncoder_encodeLoop(teavm_local_7, teavm_local_1, teavm_local_2));
            teavm_spill_6 = teavm_local_6;
        TEAVM_CATCH
            // CATCH java.lang.RuntimeException
            case 1: {
                teavm_local_6 = teavm_spill_6;
                teavm_local_7 = teavm_catchException();
                TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
                TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                TEAVM_GC_ROOT_RELEASE(INT32_C(3));
                teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(690, meth_otr_Allocator_allocate(&jnc_CoderMalfunctionError_Cls));
                TEAVM_GC_ROOT(INT32_C(1), teavm_local_1);
                teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(691, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                teavm_gc_writeBarrier(teavm_local_1);
                TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_5;
                TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(692, meth_otr_ExceptionHandling_fillStackTrace());
                teavm_gc_writeBarrier(teavm_local_1);
                TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_5;
                teavm_local_2 = ((teavm_local_7 == NULL) ? NULL : TEAVM_WITH_CALL_SITE_ID(693, meth_jl_Throwable_toString(teavm_local_7)));
                teavm_gc_writeBarrier(teavm_local_1);
                TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_message) = teavm_local_2;
                TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_cause) = teavm_local_7;
                TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                TEAVM_WITH_CALL_SITE_ID(694, meth_otr_ExceptionHandling_throwException(teavm_local_1));
                TEAVM_UNREACHABLE
                break;
            }
        TEAVM_END_TRY
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(695, teavm_nullCheck(teavm_local_6));
        teavm_local_4 = TEAVM_FIELD(teavm_local_6, cls_jnc_CoderResult, fld_kind);
        if ((teavm_local_4 ? INT32_C(0) : INT32_C(1))) {
            if ((!teavm_local_3)) {
                goto teavm_label_4;
            }
            teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(696, teavm_nullCheck(teavm_local_1));
            teavm_local_4 = (TEAVM_FIELD(teavm_local_1, cls_jn_Buffer, fld_limit) - TEAVM_FIELD(teavm_local_1, cls_jn_Buffer, fld_position));
            if ((teavm_local_4 <= INT32_C(0))) {
                goto teavm_label_5;
            }
            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
            TEAVM_WITH_CALL_SITE_ID(697, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
            teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(698, meth_otr_Allocator_allocate(&jnc_CoderResult_Cls));
            TEAVM_FIELD(teavm_local_6, cls_jnc_CoderResult, fld_kind) = INT32_C(2);
            TEAVM_FIELD(teavm_local_6, cls_jnc_CoderResult, fld_length) = teavm_local_4;
        } else if (((teavm_local_4 != INT32_C(1)) ? INT32_C(0) : INT32_C(1))) {
            goto teavm_label_6;
        }
        teavm_local_8 = ((!((TEAVM_FIELD(teavm_local_6, cls_jnc_CoderResult, fld_kind) != INT32_C(3)) ? INT32_C(0) : INT32_C(1))) ? TEAVM_FIELD(teavm_this_, cls_jnc_CharsetEncoder, fld_malformedAction) : TEAVM_FIELD(teavm_this_, cls_jnc_CharsetEncoder, fld_unmappableAction));
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_8);
        TEAVM_GC_ROOT(INT32_C(4), teavm_local_1);
        TEAVM_WITH_CALL_SITE_ID(699, teavm_initializeClass((TeaVM_Class*) &jnc_CodingErrorAction_Cls, &initclass_jnc_CodingErrorAction));
        if ((teavm_local_8 == sfld_jnc_CodingErrorAction_REPLACE)) {
            TEAVM_GC_ROOT_RELEASE(INT32_C(2));
            teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(700, teavm_nullCheck(teavm_local_2));
            teavm_local_9 = (TEAVM_FIELD(teavm_local_2, cls_jn_Buffer, fld_limit) - TEAVM_FIELD(teavm_local_2, cls_jn_Buffer, fld_position));
            teavm_local_5 = TEAVM_FIELD(teavm_this_, cls_jnc_CharsetEncoder, fld_replacement);
            TEAVM_GC_ROOT(INT32_C(2), teavm_local_5);
            teavm_local_10 = TEAVM_WITH_CALL_SITE_ID(701, teavm_nullCheck(teavm_local_5));
            teavm_local_4 = TEAVM_ARRAY_LENGTH(teavm_local_10);
            if ((teavm_local_9 < teavm_local_4)) {
                goto teavm_label_3;
            }
            TEAVM_WITH_CALL_SITE_ID(702, meth_jn_ByteBuffer_put(teavm_local_2, teavm_local_10, INT32_C(0), teavm_local_4));
        } else if ((teavm_local_8 != sfld_jnc_CodingErrorAction_IGNORE)) {
            goto teavm_label_7;
        }
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_2);
        TEAVM_GC_ROOT_RELEASE(INT32_C(3));
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(703, teavm_nullCheck(teavm_local_1));
        teavm_local_11 = TEAVM_FIELD(teavm_local_1, cls_jn_Buffer, fld_position);
        teavm_local_4 = TEAVM_FIELD(teavm_local_6, cls_jnc_CoderResult, fld_kind);
        teavm_local_9 = ((teavm_local_4 != INT32_C(2)) ? INT32_C(0) : INT32_C(1));
        if ((!((!((!teavm_local_9) && (!((teavm_local_4 != INT32_C(3)) ? INT32_C(0) : INT32_C(1))))) ? INT32_C(1) : INT32_C(0)))) {
            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
            TEAVM_GC_ROOT_RELEASE(INT32_C(2));
            TEAVM_GC_ROOT_RELEASE(INT32_C(4));
            teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(704, meth_otr_Allocator_allocate(&jl_UnsupportedOperationException_Cls));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
            teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(705, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
            teavm_gc_writeBarrier(teavm_local_1);
            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_5;
            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
            teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(706, meth_otr_ExceptionHandling_fillStackTrace());
            teavm_gc_writeBarrier(teavm_local_1);
            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_5;
            TEAVM_WITH_CALL_SITE_ID(707, meth_otr_ExceptionHandling_throwException(teavm_local_1));
            TEAVM_UNREACHABLE
        }
        teavm_local_4 = (teavm_local_11 + TEAVM_FIELD(teavm_local_6, cls_jnc_CoderResult, fld_length));
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        TEAVM_WITH_CALL_SITE_ID(708, meth_jn_Buffer_position(teavm_local_1, teavm_local_4));
    }
teavm_label_7:;
    goto teavm_label_2;
teavm_label_6:;
    goto teavm_label_2;
teavm_label_5:;
    goto teavm_label_2;
teavm_label_4:;
    goto teavm_label_2;
teavm_label_3:;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(3));
    TEAVM_GC_ROOT_RELEASE(INT32_C(4));
    TEAVM_WITH_CALL_SITE_ID(709, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
    teavm_local_6 = sfld_jnc_CoderResult_OVERFLOW;
teavm_label_2:;
    TEAVM_RELEASE_STACK;
    return teavm_local_6;
}
void* meth_jnc_CharsetEncoder_encode(void* teavm_this_, void* teavm_local_1) {
    void* teavm_local_2;
    int32_t teavm_local_3;
    int32_t teavm_local_4;
    void* teavm_local_5;
    void* teavm_local_6;
    TeaVM_Array* teavm_local_7;
    TeaVM_Array* teavm_local_8;
    TeaVM_Array* teavm_local_9;
    int32_t teavm_local_10;
    void* teavm_local_11;
    TEAVM_ALLOC_STACK(INT32_C(4));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(3));
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(710, teavm_nullCheck(teavm_local_1));
    teavm_local_3 = (TEAVM_FIELD(teavm_local_2, cls_jn_Buffer, fld_limit) - TEAVM_FIELD(teavm_local_2, cls_jn_Buffer, fld_position));
    if ((!teavm_local_3)) {
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(711, meth_jn_ByteBuffer_allocate(INT32_C(0)));
    } else {
        TEAVM_FIELD(teavm_this_, cls_jnc_CharsetEncoder, fld_status) = INT32_C(0);
        teavm_local_4 = ((int32_t) (((float) teavm_local_3) * TEAVM_FIELD(teavm_this_, cls_jnc_CharsetEncoder, fld_averageBytesPerChar)));
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
        teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(712, meth_jn_ByteBuffer_allocate(teavm_local_4));
        while (1) {
            TEAVM_GC_ROOT(INT32_C(1), teavm_local_5);
            teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(713, meth_jnc_CharsetEncoder_encode_0(teavm_this_, teavm_local_2, teavm_local_5, INT32_C(0)));
            TEAVM_GC_ROOT(INT32_C(2), teavm_local_6);
            TEAVM_WITH_CALL_SITE_ID(714, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
            if ((teavm_local_6 == sfld_jnc_CoderResult_UNDERFLOW)) {
                TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(715, meth_jnc_CharsetEncoder_encode_0(teavm_this_, teavm_local_2, teavm_local_5, INT32_C(1)));
                TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
                teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(716, teavm_nullCheck(teavm_local_1));
                teavm_local_3 = TEAVM_FIELD(teavm_local_1, cls_jnc_CoderResult, fld_kind);
                teavm_local_4 = ((teavm_local_3 != INT32_C(2)) ? INT32_C(0) : INT32_C(1));
                teavm_local_4 = ((!((!teavm_local_4) && (!((teavm_local_3 != INT32_C(3)) ? INT32_C(0) : INT32_C(1))))) ? INT32_C(1) : INT32_C(0));
                if (teavm_local_4) {
                    switch (teavm_local_3) {
                        case 0:
                            goto teavm_label_5;
                        case 1:
                            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                            teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(717, meth_otr_Allocator_allocate(&jnc_BufferOverflowException_Cls));
                            TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
                            teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(718, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                            teavm_gc_writeBarrier(teavm_local_1);
                            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_7;
                            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                            teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(719, meth_otr_ExceptionHandling_fillStackTrace());
                            teavm_gc_writeBarrier(teavm_local_1);
                            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_7;
                            TEAVM_WITH_CALL_SITE_ID(720, meth_otr_ExceptionHandling_throwException(teavm_local_1));
                            TEAVM_UNREACHABLE
                        case 2:
                            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                            teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(721, meth_otr_Allocator_allocate(&jnc_MalformedInputException_Cls));
                            teavm_local_4 = TEAVM_FIELD(teavm_local_1, cls_jnc_CoderResult, fld_length);
                            TEAVM_GC_ROOT(INT32_C(0), teavm_local_5);
                            teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(722, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                            teavm_gc_writeBarrier(teavm_local_5);
                            TEAVM_FIELD(teavm_local_5, cls_jl_Throwable, fld_suppressed) = teavm_local_7;
                            TEAVM_FIELD(teavm_local_5, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                            TEAVM_FIELD(teavm_local_5, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                            teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(723, meth_otr_ExceptionHandling_fillStackTrace());
                            teavm_gc_writeBarrier(teavm_local_5);
                            TEAVM_FIELD(teavm_local_5, cls_jl_Throwable, fld_stackTrace) = teavm_local_7;
                            TEAVM_FIELD(teavm_local_5, cls_jnc_MalformedInputException, fld_length) = teavm_local_4;
                            TEAVM_WITH_CALL_SITE_ID(724, meth_otr_ExceptionHandling_throwException(teavm_local_5));
                            TEAVM_UNREACHABLE
                        case 3:
                            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                            teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(725, meth_otr_Allocator_allocate(&jnc_UnmappableCharacterException_Cls));
                            teavm_local_4 = TEAVM_FIELD(teavm_local_1, cls_jnc_CoderResult, fld_length);
                            TEAVM_GC_ROOT(INT32_C(0), teavm_local_5);
                            teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(726, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                            teavm_gc_writeBarrier(teavm_local_5);
                            TEAVM_FIELD(teavm_local_5, cls_jl_Throwable, fld_suppressed) = teavm_local_7;
                            TEAVM_FIELD(teavm_local_5, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                            TEAVM_FIELD(teavm_local_5, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                            teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(727, meth_otr_ExceptionHandling_fillStackTrace());
                            teavm_gc_writeBarrier(teavm_local_5);
                            TEAVM_FIELD(teavm_local_5, cls_jl_Throwable, fld_stackTrace) = teavm_local_7;
                            TEAVM_FIELD(teavm_local_5, cls_jnc_UnmappableCharacterException, fld_length) = teavm_local_4;
                            TEAVM_WITH_CALL_SITE_ID(728, meth_otr_ExceptionHandling_throwException(teavm_local_5));
                            TEAVM_UNREACHABLE
                        default:
                            goto teavm_label_4;
                    }
                teavm_label_5:;
                    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(729, meth_otr_Allocator_allocate(&jnc_BufferUnderflowException_Cls));
                    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
                    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(730, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                    teavm_gc_writeBarrier(teavm_local_1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_7;
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(731, meth_otr_ExceptionHandling_fillStackTrace());
                    teavm_gc_writeBarrier(teavm_local_1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_7;
                    TEAVM_WITH_CALL_SITE_ID(732, meth_otr_ExceptionHandling_throwException(teavm_local_1));
                    TEAVM_UNREACHABLE
                }
            teavm_label_4:;
                while (1) {
                    teavm_local_3 = TEAVM_FIELD(teavm_this_, cls_jnc_CharsetEncoder, fld_status);
                    if (((teavm_local_3 != INT32_C(2)) && (teavm_local_3 != INT32_C(4)))) {
                        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(733, meth_otr_Allocator_allocate(&jl_IllegalStateException_Cls));
                        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
                        teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(734, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                        teavm_gc_writeBarrier(teavm_local_1);
                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_7;
                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                        teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(735, meth_otr_ExceptionHandling_fillStackTrace());
                        teavm_gc_writeBarrier(teavm_local_1);
                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_7;
                        TEAVM_WITH_CALL_SITE_ID(736, meth_otr_ExceptionHandling_throwException(teavm_local_1));
                        TEAVM_UNREACHABLE
                    }
                    teavm_local_1 = sfld_jnc_CoderResult_UNDERFLOW;
                    if ((teavm_local_1 == teavm_local_1)) {
                        TEAVM_FIELD(teavm_this_, cls_jnc_CharsetEncoder, fld_status) = INT32_C(3);
                    }
                    TEAVM_GC_ROOT(INT32_C(0), teavm_local_5);
                    TEAVM_GC_ROOT(INT32_C(1), teavm_local_1);
                    teavm_local_3 = TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(737, teavm_nullCheck(teavm_local_1)), cls_jnc_CoderResult, fld_kind);
                    if ((teavm_local_3 ? INT32_C(0) : INT32_C(1))) {
                        goto teavm_label_6;
                    }
                    if ((!((teavm_local_3 != INT32_C(1)) ? INT32_C(0) : INT32_C(1)))) {
                        goto teavm_cnt_6;
                    }
                    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(738, teavm_nullCheck(teavm_local_5));
                    teavm_local_7 = TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(739, teavm_nullCheck(teavm_local_1)), cls_jn_ByteBufferNative, fld_array);
                    if ((teavm_local_7 == NULL)) {
                        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(740, meth_otr_Allocator_allocate(&jl_UnsupportedOperationException_Cls));
                        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
                        teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(741, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                        teavm_gc_writeBarrier(teavm_local_1);
                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_7;
                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                        teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(742, meth_otr_ExceptionHandling_fillStackTrace());
                        teavm_gc_writeBarrier(teavm_local_1);
                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_7;
                        TEAVM_WITH_CALL_SITE_ID(743, meth_otr_ExceptionHandling_throwException(teavm_local_1));
                        TEAVM_UNREACHABLE
                    }
                    teavm_local_7 = teavm_local_7;
                    teavm_local_3 = TEAVM_ARRAY_LENGTH(teavm_local_7);
                    teavm_local_4 = (teavm_local_3 * INT32_C(2));
                    TEAVM_GC_ROOT(INT32_C(1), teavm_local_7);
                    teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(744, meth_otr_Allocator_allocateArray(&Arr_B_Cls, teavm_local_4));
                    if ((teavm_local_4 < teavm_local_3)) {
                        teavm_local_3 = teavm_local_4;
                    }
                    teavm_local_9 = teavm_local_8;
                    teavm_local_4 = INT32_C(0);
                    while (1) {
                        if (!(teavm_local_4 < teavm_local_3)) break;
                        TEAVM_GC_ROOT(INT32_C(2), teavm_local_9);
                        teavm_local_10 = TEAVM_WITH_CALL_SITE_ID(745, teavm_checkBounds(teavm_local_4, teavm_local_7));
                        teavm_local_4 = TEAVM_ARRAY_AT(teavm_local_7, int8_t, teavm_local_10);
                        teavm_local_10 = TEAVM_WITH_CALL_SITE_ID(746, teavm_checkUpperBound(teavm_local_10, teavm_local_9));
                        TEAVM_ARRAY_AT(teavm_local_9, int8_t, teavm_local_10) = teavm_local_4;
                        teavm_local_4 = (teavm_local_10 + INT32_C(1));
                    }
                    teavm_local_3 = TEAVM_ARRAY_LENGTH(teavm_local_9);
                    if ((teavm_local_3 < INT32_C(0))) {
                        goto teavm_label_1;
                    }
                    if ((teavm_local_3 > (teavm_local_3 - INT32_C(0)))) {
                        goto teavm_label_1;
                    }
                    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                    TEAVM_GC_ROOT(INT32_C(2), teavm_local_8);
                    teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(747, meth_otr_Allocator_allocate(&jn_ByteBufferNative_Cls));
                    teavm_local_6 = TEAVM_ARRAY_DATA(teavm_local_8, int32_t);
                    TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_mark) = -INT32_C(1);
                    TEAVM_GC_ROOT(INT32_C(1), teavm_local_5);
                    TEAVM_WITH_CALL_SITE_ID(748, teavm_initializeClass((TeaVM_Class*) &jn_ByteOrder_Cls, &initclass_jn_ByteOrder));
                    teavm_local_2 = sfld_jn_ByteOrder_BIG_ENDIAN;
                    teavm_gc_writeBarrier(teavm_local_5);
                    TEAVM_FIELD(teavm_local_5, cls_jn_ByteBuffer, fld_order) = teavm_local_2;
                    TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_gcRef) = teavm_local_5;
                    TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_array) = teavm_local_8;
                    TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_arrayOffset) = INT32_C(0);
                    TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_base) = teavm_local_8;
                    TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_address) = teavm_local_6;
                    TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_capacity) = teavm_local_3;
                    TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_readOnly) = INT32_C(0);
                    TEAVM_GC_ROOT(INT32_C(2), teavm_local_2);
                    TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_swap) = ((teavm_local_2 == TEAVM_WITH_CALL_SITE_ID(749, meth_jn_ByteOrder_nativeOrder())) ? INT32_C(0) : INT32_C(1));
                    TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_position) = INT32_C(0);
                    TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_limit) = (INT32_C(0) + teavm_local_3);
                    teavm_local_4 = TEAVM_FIELD(teavm_local_1, cls_jn_Buffer, fld_position);
                    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                    TEAVM_WITH_CALL_SITE_ID(750, meth_jn_Buffer_position(teavm_local_5, teavm_local_4));
                teavm_cnt_6:;
                }
            teavm_label_6:;
                TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(751, teavm_nullCheck(teavm_local_5));
                TEAVM_FIELD(teavm_local_1, cls_jn_Buffer, fld_limit) = TEAVM_FIELD(teavm_local_1, cls_jn_Buffer, fld_position);
                TEAVM_FIELD(teavm_local_1, cls_jn_Buffer, fld_position) = INT32_C(0);
                TEAVM_FIELD(teavm_local_1, cls_jn_Buffer, fld_mark) = -INT32_C(1);
                goto teavm_label_2;
            }
            if ((teavm_local_6 == sfld_jnc_CoderResult_OVERFLOW)) {
                TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(752, teavm_nullCheck(teavm_local_5));
                teavm_local_7 = TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(753, teavm_nullCheck(teavm_local_1)), cls_jn_ByteBufferNative, fld_array);
                if ((teavm_local_7 == NULL)) {
                    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(754, meth_otr_Allocator_allocate(&jl_UnsupportedOperationException_Cls));
                    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
                    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(755, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                    teavm_gc_writeBarrier(teavm_local_1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_7;
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(756, meth_otr_ExceptionHandling_fillStackTrace());
                    teavm_gc_writeBarrier(teavm_local_1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_7;
                    TEAVM_WITH_CALL_SITE_ID(757, meth_otr_ExceptionHandling_throwException(teavm_local_1));
                    TEAVM_UNREACHABLE
                }
                teavm_local_7 = teavm_local_7;
                teavm_local_3 = TEAVM_ARRAY_LENGTH(teavm_local_7);
                teavm_local_4 = (teavm_local_3 * INT32_C(2));
                TEAVM_GC_ROOT(INT32_C(2), teavm_local_7);
                teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(758, meth_otr_Allocator_allocateArray(&Arr_B_Cls, teavm_local_4));
                if ((teavm_local_4 < teavm_local_3)) {
                    teavm_local_3 = teavm_local_4;
                }
                teavm_local_9 = teavm_local_8;
                teavm_local_4 = INT32_C(0);
                while (1) {
                    if (!(teavm_local_4 < teavm_local_3)) break;
                    TEAVM_GC_ROOT(INT32_C(3), teavm_local_9);
                    teavm_local_10 = TEAVM_WITH_CALL_SITE_ID(759, teavm_checkBounds(teavm_local_4, teavm_local_7));
                    teavm_local_4 = TEAVM_ARRAY_AT(teavm_local_7, int8_t, teavm_local_10);
                    teavm_local_10 = TEAVM_WITH_CALL_SITE_ID(760, teavm_checkUpperBound(teavm_local_10, teavm_local_9));
                    TEAVM_ARRAY_AT(teavm_local_9, int8_t, teavm_local_10) = teavm_local_4;
                    teavm_local_4 = (teavm_local_10 + INT32_C(1));
                }
                teavm_local_3 = TEAVM_ARRAY_LENGTH(teavm_local_9);
                if ((teavm_local_3 < INT32_C(0))) {
                    goto teavm_label_3;
                }
                if ((teavm_local_3 > (teavm_local_3 - INT32_C(0)))) {
                    goto teavm_label_3;
                }
                TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                TEAVM_GC_ROOT(INT32_C(3), teavm_local_8);
                teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(761, meth_otr_Allocator_allocate(&jn_ByteBufferNative_Cls));
                teavm_local_6 = TEAVM_ARRAY_DATA(teavm_local_8, int32_t);
                TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_mark) = -INT32_C(1);
                TEAVM_GC_ROOT(INT32_C(2), teavm_local_5);
                TEAVM_WITH_CALL_SITE_ID(762, teavm_initializeClass((TeaVM_Class*) &jn_ByteOrder_Cls, &initclass_jn_ByteOrder));
                teavm_local_11 = sfld_jn_ByteOrder_BIG_ENDIAN;
                teavm_gc_writeBarrier(teavm_local_5);
                TEAVM_FIELD(teavm_local_5, cls_jn_ByteBuffer, fld_order) = teavm_local_11;
                TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_gcRef) = teavm_local_5;
                TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_array) = teavm_local_8;
                TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_arrayOffset) = INT32_C(0);
                TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_base) = teavm_local_8;
                TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_address) = teavm_local_6;
                TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_capacity) = teavm_local_3;
                TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_readOnly) = INT32_C(0);
                TEAVM_GC_ROOT(INT32_C(3), teavm_local_11);
                TEAVM_FIELD(teavm_local_5, cls_jn_ByteBufferNative, fld_swap) = ((teavm_local_11 == TEAVM_WITH_CALL_SITE_ID(763, meth_jn_ByteOrder_nativeOrder())) ? INT32_C(0) : INT32_C(1));
                TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_position) = INT32_C(0);
                TEAVM_FIELD(teavm_local_5, cls_jn_Buffer, fld_limit) = (INT32_C(0) + teavm_local_3);
                teavm_local_4 = TEAVM_FIELD(teavm_local_1, cls_jn_Buffer, fld_position);
                TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                TEAVM_GC_ROOT_RELEASE(INT32_C(3));
                TEAVM_WITH_CALL_SITE_ID(764, meth_jn_Buffer_position(teavm_local_5, teavm_local_4));
                goto teavm_cnt_3;
            }
            teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(765, teavm_nullCheck(teavm_local_6));
            teavm_local_3 = TEAVM_FIELD(teavm_local_6, cls_jnc_CoderResult, fld_kind);
            teavm_local_4 = ((teavm_local_3 != INT32_C(2)) ? INT32_C(0) : INT32_C(1));
            if ((!((!((!teavm_local_4) && (!((teavm_local_3 != INT32_C(3)) ? INT32_C(0) : INT32_C(1))))) ? INT32_C(1) : INT32_C(0)))) {
                goto teavm_cnt_3;
            }
            switch (teavm_local_3) {
                case 0:
                    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(766, meth_otr_Allocator_allocate(&jnc_BufferUnderflowException_Cls));
                    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
                    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(767, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                    teavm_gc_writeBarrier(teavm_local_1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_7;
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(768, meth_otr_ExceptionHandling_fillStackTrace());
                    teavm_gc_writeBarrier(teavm_local_1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_7;
                    TEAVM_WITH_CALL_SITE_ID(769, meth_otr_ExceptionHandling_throwException(teavm_local_1));
                    TEAVM_UNREACHABLE
                case 1:
                    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(770, meth_otr_Allocator_allocate(&jnc_BufferOverflowException_Cls));
                    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
                    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(771, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                    teavm_gc_writeBarrier(teavm_local_1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_7;
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(772, meth_otr_ExceptionHandling_fillStackTrace());
                    teavm_gc_writeBarrier(teavm_local_1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_7;
                    TEAVM_WITH_CALL_SITE_ID(773, meth_otr_ExceptionHandling_throwException(teavm_local_1));
                    TEAVM_UNREACHABLE
                case 2:
                    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(774, meth_otr_Allocator_allocate(&jnc_MalformedInputException_Cls));
                    teavm_local_4 = TEAVM_FIELD(teavm_local_6, cls_jnc_CoderResult, fld_length);
                    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
                    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(775, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                    teavm_gc_writeBarrier(teavm_local_1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_7;
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(776, meth_otr_ExceptionHandling_fillStackTrace());
                    teavm_gc_writeBarrier(teavm_local_1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_7;
                    TEAVM_FIELD(teavm_local_1, cls_jnc_MalformedInputException, fld_length) = teavm_local_4;
                    TEAVM_WITH_CALL_SITE_ID(777, meth_otr_ExceptionHandling_throwException(teavm_local_1));
                    TEAVM_UNREACHABLE
                case 3:
                    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(778, meth_otr_Allocator_allocate(&jnc_UnmappableCharacterException_Cls));
                    teavm_local_4 = TEAVM_FIELD(teavm_local_6, cls_jnc_CoderResult, fld_length);
                    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
                    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(779, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                    teavm_gc_writeBarrier(teavm_local_1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_7;
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(780, meth_otr_ExceptionHandling_fillStackTrace());
                    teavm_gc_writeBarrier(teavm_local_1);
                    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_7;
                    TEAVM_FIELD(teavm_local_1, cls_jnc_UnmappableCharacterException, fld_length) = teavm_local_4;
                    TEAVM_WITH_CALL_SITE_ID(781, meth_otr_ExceptionHandling_throwException(teavm_local_1));
                    TEAVM_UNREACHABLE
            }
        teavm_cnt_3:;
        }
    teavm_label_3:;
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(782, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
        teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(783, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
        teavm_gc_writeBarrier(teavm_local_1);
        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_7;
        TEAVM_WITH_CALL_SITE_ID(784, meth_jl_Throwable_initNativeException(teavm_local_1));
        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
        TEAVM_WITH_CALL_SITE_ID(785, meth_jl_Throwable_fillInStackTrace(teavm_local_1));
        TEAVM_WITH_CALL_SITE_ID(786, meth_otr_ExceptionHandling_throwException(teavm_local_1));
        TEAVM_UNREACHABLE
    }
teavm_label_2:;
    TEAVM_RELEASE_STACK;
    return teavm_local_1;
teavm_label_1:;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(787, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(788, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_7;
    TEAVM_WITH_CALL_SITE_ID(789, meth_jl_Throwable_initNativeException(teavm_local_1));
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    TEAVM_WITH_CALL_SITE_ID(790, meth_jl_Throwable_fillInStackTrace(teavm_local_1));
    TEAVM_WITH_CALL_SITE_ID(791, meth_otr_ExceptionHandling_throwException(teavm_local_1));
    TEAVM_UNREACHABLE
}
void* meth_jnc_CharsetEncoder_implFlush(void* teavm_this_, void* teavm_local_1) {
    TEAVM_ALLOC_STACK(INT32_C(0));
    TEAVM_WITH_CALL_SITE_ID(792, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
    teavm_local_1 = sfld_jnc_CoderResult_UNDERFLOW;
    TEAVM_RELEASE_STACK;
    return teavm_local_1;
}
void meth_jnc_CharsetEncoder_implReset(void* teavm_this_) {
    return;
}
int32_t supertypeof_jnc_CharsetEncoder(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 205 || tag >= 213) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_jnc_CharsetEncoder_Cls[5];
alignas(8) jnc_CharsetEncoder_VT jnc_CharsetEncoder_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnc_CharsetEncoder), sizeof(void*)),
            .flags = 0,
            .tag = 205,
            .modifiers = 1025,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jnc_CharsetEncoder,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_jnc_CharsetEncoder_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static int16_t teavm_classLayouts_jnc_CharsetEncoder_Cls[5] = {
INT16_C(4), (int16_t) offsetof(cls_jnc_CharsetEncoder, fld_charset), (int16_t) offsetof(cls_jnc_CharsetEncoder, fld_replacement), (int16_t) offsetof(cls_jnc_CharsetEncoder, fld_malformedAction), (int16_t) offsetof(cls_jnc_CharsetEncoder, fld_unmappableAction)
};
void sysinitclass_jnc_CharsetEncoder() {
}
