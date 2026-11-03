#include "CharBuffer.h"
#include "Buffer.h"
#include "CharBufferNative.h"
#include "../../o/t/r/Allocator.h"
#include "../l/IndexOutOfBoundsException.h"
#include "../../../arrayclass.h"
#include "../l/Throwable.h"
#include "../../o/t/r/ExceptionHandling.h"
#include "BufferUnderflowException.h"
#include "../../../strings.h"
#include "../l/Object.h"

void* meth_jn_CharBuffer_wrap(TeaVM_Array* teavm_local_1, int32_t teavm_local_2, int32_t teavm_local_3) {
    TeaVM_Array* teavm_local_4;
    int32_t teavm_local_5;
    void* teavm_local_6;
    void* teavm_local_7;
    TEAVM_ALLOC_STACK(INT32_C(1));
    if (((teavm_local_3 >= INT32_C(0)) && (teavm_local_2 >= INT32_C(0)))) {
        teavm_local_3 = (teavm_local_3 + teavm_local_2);
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(480, teavm_nullCheck(teavm_local_1));
        teavm_local_5 = TEAVM_ARRAY_LENGTH(teavm_local_4);
        if ((teavm_local_3 <= teavm_local_5)) {
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_4);
            teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(481, meth_otr_Allocator_allocate(&jn_CharBufferNative_Cls));
            teavm_local_7 = TEAVM_ARRAY_DATA(teavm_local_4, int32_t);
            TEAVM_FIELD(teavm_local_6, cls_jn_Buffer, fld_mark) = -INT32_C(1);
            TEAVM_FIELD(teavm_local_6, cls_jn_Buffer, fld_position) = INT32_C(0);
            TEAVM_FIELD(teavm_local_6, cls_jn_Buffer, fld_limit) = teavm_local_5;
            teavm_gc_writeBarrier(teavm_local_6);
            TEAVM_FIELD(teavm_local_6, cls_jn_CharBufferNative, fld_array) = teavm_local_4;
            TEAVM_FIELD(teavm_local_6, cls_jn_CharBufferNative, fld_readOnly) = INT32_C(0);
            TEAVM_FIELD(teavm_local_6, cls_jn_CharBufferNative, fld_base) = teavm_local_4;
            TEAVM_FIELD(teavm_local_6, cls_jn_CharBufferNative, fld_address) = teavm_local_7;
            TEAVM_FIELD(teavm_local_6, cls_jn_CharBufferNative, fld_capacity) = teavm_local_5;
            TEAVM_FIELD(teavm_local_6, cls_jn_CharBufferNative, fld_swap) = INT32_C(0);
            TEAVM_FIELD(teavm_local_6, cls_jn_Buffer, fld_position) = teavm_local_2;
            TEAVM_FIELD(teavm_local_6, cls_jn_Buffer, fld_limit) = teavm_local_3;
            TEAVM_RELEASE_STACK;
            return teavm_local_6;
        }
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(482, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_6);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(483, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_6);
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(484, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_local_6);
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
    TEAVM_WITH_CALL_SITE_ID(485, meth_otr_ExceptionHandling_throwException(teavm_local_6));
    TEAVM_UNREACHABLE
}
void* meth_jn_CharBuffer_get(void* teavm_this_, TeaVM_Array* teavm_local_1, int32_t teavm_local_2, int32_t teavm_local_3) {
    int32_t teavm_local_4;
    TeaVM_Array* teavm_local_5;
    int32_t teavm_local_6;
    void* teavm_local_7;
    TEAVM_ALLOC_STACK(INT32_C(2));
    if (((teavm_local_3 >= INT32_C(0)) && (teavm_local_2 >= INT32_C(0)))) {
        teavm_local_4 = (teavm_local_2 + teavm_local_3);
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(486, teavm_nullCheck(teavm_local_1));
        if ((teavm_local_4 <= TEAVM_ARRAY_LENGTH(teavm_local_5))) {
            teavm_local_4 = TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_limit);
            teavm_local_6 = TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_position);
            if ((teavm_local_3 > (teavm_local_4 - teavm_local_6))) {
                teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(487, meth_otr_Allocator_allocate(&jn_BufferUnderflowException_Cls));
                TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
                teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(488, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                teavm_gc_writeBarrier(teavm_local_7);
                TEAVM_FIELD(teavm_local_7, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
                TEAVM_FIELD(teavm_local_7, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                TEAVM_FIELD(teavm_local_7, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(489, meth_otr_ExceptionHandling_fillStackTrace());
                teavm_gc_writeBarrier(teavm_local_7);
                TEAVM_FIELD(teavm_local_7, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
                TEAVM_WITH_CALL_SITE_ID(490, meth_otr_ExceptionHandling_throwException(teavm_local_7));
                TEAVM_UNREACHABLE
            }
            teavm_local_7 = teavm_this_;
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
            TEAVM_GC_ROOT(INT32_C(1), teavm_local_5);
            TEAVM_WITH_CALL_SITE_ID(491, meth_jn_CharBufferNative_getImpl(TEAVM_WITH_CALL_SITE_ID(492, teavm_nullCheck(teavm_local_7)), teavm_local_6, teavm_local_5, teavm_local_2, teavm_local_3));
            TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_position) = (TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_position) + teavm_local_3);
            TEAVM_RELEASE_STACK;
            return teavm_this_;
        }
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(493, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(494, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_7);
    TEAVM_FIELD(teavm_local_7, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
    TEAVM_FIELD(teavm_local_7, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_7, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(495, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_local_7);
    TEAVM_FIELD(teavm_local_7, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
    TEAVM_WITH_CALL_SITE_ID(496, meth_otr_ExceptionHandling_throwException(teavm_local_7));
    TEAVM_UNREACHABLE
}
int32_t supertypeof_jn_CharBuffer(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 168 || tag >= 174) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jn_CharBuffer_VT jn_CharBuffer_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jn_CharBuffer), sizeof(void*)),
                .flags = 0,
                .tag = 168,
                .modifiers = 1025,
                .name = NULL,
                .arrayType = NULL,
                .itemType = NULL,
                .isSupertypeOf = &supertypeof_jn_CharBuffer,
                .superclass = (TeaVM_Class*) &jn_Buffer_Cls,
                .layout = NULL,
                .enumValues = NULL
            },
            .virt_clone = &meth_jl_Object_clone
        }
    }
};
void sysinitclass_jn_CharBuffer() {
}
