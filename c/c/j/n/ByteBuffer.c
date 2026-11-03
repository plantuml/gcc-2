#include "ByteBuffer.h"
#include "Buffer.h"
#include "../l/IllegalArgumentException.h"
#include "../../o/t/r/Allocator.h"
#include "../l/StringBuilder.h"
#include "../../../a/p/char.h"
#include "../l/AbstractStringBuilder.h"
#include "../../../strings.h"
#include "../l/String.h"
#include "../l/System.h"
#include "../../../arrayclass.h"
#include "../l/Throwable.h"
#include "../../o/t/r/ExceptionHandling.h"
#include "../l/IndexOutOfBoundsException.h"
#include "../../../a/p/byte.h"
#include "ByteBufferNative.h"
#include "ByteOrder.h"
#include "BufferUnderflowException.h"
#include <string.h>
#include "BufferOverflowException.h"
#include "ReadOnlyBufferException.h"
#include "../l/Object.h"

void* meth_jn_ByteBuffer_allocate(int32_t teavm_local_1) {
    void* teavm_local_2;
    void* teavm_local_3;
    TeaVM_Array* teavm_local_4;
    int32_t teavm_local_5;
    void* teavm_local_6;
    void* teavm_local_7;
    void* teavm_local_8;
    int32_t teavm_local_9;
    TeaVM_Array* teavm_local_10;
    int32_t teavm_local_11;
    TEAVM_ALLOC_STACK(INT32_C(4));
    if ((teavm_local_1 < INT32_C(0))) {
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
        TEAVM_GC_ROOT_RELEASE(INT32_C(3));
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(551, meth_otr_Allocator_allocate(&jl_IllegalArgumentException_Cls));
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(552, meth_otr_Allocator_allocate(&jl_StringBuilder_Cls));
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
        teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(553, meth_otr_Allocator_allocateArray(&Arr_C_Cls, INT32_C(16)));
        teavm_gc_writeBarrier(teavm_local_3);
        TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_buffer) = teavm_local_4;
        teavm_local_5 = TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_length);
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(554, teavm_nullCheck(teavm_local_3));
        teavm_local_7 = TEAVM_GET_STRING(24);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_7);
        teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(555, teavm_nullCheck(teavm_local_7));
        TEAVM_WITH_CALL_SITE_ID(556, meth_jl_AbstractStringBuilder_insert(TEAVM_WITH_CALL_SITE_ID(557, teavm_nullCheck(teavm_local_6)), teavm_local_5, teavm_local_8));
        teavm_local_9 = TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_length);
        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
        TEAVM_WITH_CALL_SITE_ID(558, meth_jl_AbstractStringBuilder_insert_0(teavm_local_3, teavm_local_9, teavm_local_1, INT32_C(10)));
        teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(559, meth_otr_Allocator_allocate(&jl_String_Cls));
        teavm_local_4 = TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_buffer);
        teavm_local_5 = TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_length);
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_7);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_4);
        TEAVM_WITH_CALL_SITE_ID(560, teavm_initializeClass((TeaVM_Class*) &jl_String_Cls, &initclass_jl_String));
        teavm_local_10 = TEAVM_WITH_CALL_SITE_ID(561, teavm_nullCheck(teavm_local_4));
        teavm_local_9 = TEAVM_ARRAY_LENGTH(teavm_local_10);
        if (((teavm_local_5 >= INT32_C(0)) && (teavm_local_5 <= (teavm_local_9 - INT32_C(0))))) {
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(562, meth_otr_Allocator_allocateArray(&Arr_C_Cls, teavm_local_5));
            TEAVM_GC_ROOT(INT32_C(3), teavm_local_4);
            TEAVM_WITH_CALL_SITE_ID(563, meth_jl_System_fastArraycopy(teavm_local_10, INT32_C(0), teavm_local_4, INT32_C(0), teavm_local_5));
            teavm_gc_writeBarrier(teavm_local_7);
            TEAVM_FIELD(teavm_local_7, TeaVM_String, characters) = teavm_local_4;
            TEAVM_GC_ROOT_RELEASE(INT32_C(2));
            TEAVM_GC_ROOT_RELEASE(INT32_C(3));
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(564, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
            teavm_gc_writeBarrier(teavm_local_2);
            TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressed) = teavm_local_4;
            TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
            TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(565, meth_otr_ExceptionHandling_fillStackTrace());
            teavm_gc_writeBarrier(teavm_local_2);
            TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_stackTrace) = teavm_local_4;
            TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_message) = teavm_local_7;
            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
            TEAVM_WITH_CALL_SITE_ID(566, meth_otr_ExceptionHandling_throwException(teavm_local_2));
            TEAVM_UNREACHABLE
        }
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(567, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
        teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(568, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
        teavm_gc_writeBarrier(teavm_local_2);
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressed) = teavm_local_4;
        TEAVM_WITH_CALL_SITE_ID(569, meth_jl_Throwable_initNativeException(teavm_local_2));
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
        TEAVM_WITH_CALL_SITE_ID(570, meth_jl_Throwable_fillInStackTrace(teavm_local_2));
        TEAVM_WITH_CALL_SITE_ID(571, meth_otr_ExceptionHandling_throwException(teavm_local_2));
        TEAVM_UNREACHABLE
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(3));
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(572, meth_otr_Allocator_allocateArray(&Arr_B_Cls, teavm_local_1));
    teavm_local_10 = teavm_local_4;
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_10);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(573, meth_otr_Allocator_allocate(&jn_ByteBufferNative_Cls));
    teavm_local_3 = TEAVM_ARRAY_DATA(teavm_local_4, int32_t);
    teavm_local_11 = TEAVM_ARRAY_LENGTH(teavm_local_10);
    TEAVM_FIELD(teavm_local_2, cls_jn_Buffer, fld_mark) = -INT32_C(1);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_2);
    TEAVM_WITH_CALL_SITE_ID(574, teavm_initializeClass((TeaVM_Class*) &jn_ByteOrder_Cls, &initclass_jn_ByteOrder));
    teavm_local_7 = sfld_jn_ByteOrder_BIG_ENDIAN;
    teavm_gc_writeBarrier(teavm_local_2);
    TEAVM_FIELD(teavm_local_2, cls_jn_ByteBuffer, fld_order) = teavm_local_7;
    TEAVM_FIELD(teavm_local_2, cls_jn_ByteBufferNative, fld_gcRef) = teavm_local_2;
    TEAVM_FIELD(teavm_local_2, cls_jn_ByteBufferNative, fld_array) = teavm_local_4;
    TEAVM_FIELD(teavm_local_2, cls_jn_ByteBufferNative, fld_arrayOffset) = INT32_C(0);
    TEAVM_FIELD(teavm_local_2, cls_jn_ByteBufferNative, fld_base) = teavm_local_4;
    TEAVM_FIELD(teavm_local_2, cls_jn_ByteBufferNative, fld_address) = teavm_local_3;
    TEAVM_FIELD(teavm_local_2, cls_jn_ByteBufferNative, fld_capacity) = teavm_local_11;
    TEAVM_FIELD(teavm_local_2, cls_jn_ByteBufferNative, fld_readOnly) = INT32_C(0);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
    TEAVM_FIELD(teavm_local_2, cls_jn_ByteBufferNative, fld_swap) = ((teavm_local_7 == TEAVM_WITH_CALL_SITE_ID(575, meth_jn_ByteOrder_nativeOrder())) ? INT32_C(0) : INT32_C(1));
    TEAVM_FIELD(teavm_local_2, cls_jn_Buffer, fld_limit) = teavm_local_1;
    TEAVM_RELEASE_STACK;
    return teavm_local_2;
}
void* meth_jn_ByteBuffer_get(void* teavm_this_, TeaVM_Array* teavm_local_1, int32_t teavm_local_2, int32_t teavm_local_3) {
    int32_t teavm_local_4;
    TeaVM_Array* teavm_local_5;
    int32_t teavm_local_6;
    void* teavm_local_7;
    TEAVM_ALLOC_STACK(INT32_C(2));
    if (((teavm_local_3 >= INT32_C(0)) && (teavm_local_2 >= INT32_C(0)))) {
        teavm_local_4 = (teavm_local_2 + teavm_local_3);
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(576, teavm_nullCheck(teavm_local_1));
        if ((teavm_local_4 <= TEAVM_ARRAY_LENGTH(teavm_local_5))) {
            teavm_local_4 = TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_limit);
            teavm_local_6 = TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_position);
            if ((teavm_local_3 > (teavm_local_4 - teavm_local_6))) {
                teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(577, meth_otr_Allocator_allocate(&jn_BufferUnderflowException_Cls));
                TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
                teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(578, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                teavm_gc_writeBarrier(teavm_local_7);
                TEAVM_FIELD(teavm_local_7, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
                TEAVM_FIELD(teavm_local_7, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                TEAVM_FIELD(teavm_local_7, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(579, meth_otr_ExceptionHandling_fillStackTrace());
                teavm_gc_writeBarrier(teavm_local_7);
                TEAVM_FIELD(teavm_local_7, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
                TEAVM_WITH_CALL_SITE_ID(580, meth_otr_ExceptionHandling_throwException(teavm_local_7));
                TEAVM_UNREACHABLE
            }
            teavm_local_7 = teavm_this_;
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
            TEAVM_GC_ROOT(INT32_C(1), teavm_local_5);
            memmove(TEAVM_ADDRESS_ADD(TEAVM_ARRAY_DATA(teavm_local_5, int32_t), teavm_local_2), TEAVM_ADDRESS_ADD(TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(581, teavm_nullCheck(teavm_local_7)), cls_jn_ByteBufferNative, fld_address), teavm_local_6), teavm_local_3);
            TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_position) = (TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_position) + teavm_local_3);
            TEAVM_RELEASE_STACK;
            return teavm_this_;
        }
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(582, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(583, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_7);
    TEAVM_FIELD(teavm_local_7, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
    TEAVM_FIELD(teavm_local_7, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_7, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(584, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_local_7);
    TEAVM_FIELD(teavm_local_7, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
    TEAVM_WITH_CALL_SITE_ID(585, meth_otr_ExceptionHandling_throwException(teavm_local_7));
    TEAVM_UNREACHABLE
}
void* meth_jn_ByteBuffer_put(void* teavm_this_, TeaVM_Array* teavm_local_1, int32_t teavm_local_2, int32_t teavm_local_3) {
    void* teavm_local_4;
    int32_t teavm_local_5;
    TeaVM_Array* teavm_local_6;
    int32_t teavm_local_7;
    TEAVM_ALLOC_STACK(INT32_C(1));
    if (teavm_local_3) {
        teavm_local_4 = teavm_this_;
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_4);
        teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(586, teavm_nullCheck(teavm_local_4));
        if ((!TEAVM_FIELD(teavm_local_4, cls_jn_ByteBufferNative, fld_readOnly))) {
            if (((teavm_local_3 >= INT32_C(0)) && (teavm_local_2 >= INT32_C(0)))) {
                teavm_local_5 = (teavm_local_2 + teavm_local_3);
                teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(587, teavm_nullCheck(teavm_local_1));
                if ((teavm_local_5 <= TEAVM_ARRAY_LENGTH(teavm_local_6))) {
                    teavm_local_5 = TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_limit);
                    teavm_local_7 = TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_position);
                    if ((teavm_local_3 > (teavm_local_5 - teavm_local_7))) {
                        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                        teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(588, meth_otr_Allocator_allocate(&jn_BufferOverflowException_Cls));
                        TEAVM_GC_ROOT(INT32_C(0), teavm_local_4);
                        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(589, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                        teavm_gc_writeBarrier(teavm_local_4);
                        TEAVM_FIELD(teavm_local_4, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
                        TEAVM_FIELD(teavm_local_4, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                        TEAVM_FIELD(teavm_local_4, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(590, meth_otr_ExceptionHandling_fillStackTrace());
                        teavm_gc_writeBarrier(teavm_local_4);
                        TEAVM_FIELD(teavm_local_4, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
                        TEAVM_WITH_CALL_SITE_ID(591, meth_otr_ExceptionHandling_throwException(teavm_local_4));
                        TEAVM_UNREACHABLE
                    }
                    teavm_local_4 = TEAVM_ADDRESS_ADD(TEAVM_FIELD(teavm_local_4, cls_jn_ByteBufferNative, fld_address), teavm_local_7);
                    memmove(teavm_local_4, TEAVM_ADDRESS_ADD(TEAVM_ARRAY_DATA(teavm_local_6, int32_t), teavm_local_2), teavm_local_3);
                    TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_position) = (TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_position) + teavm_local_3);
                    goto teavm_label_1;
                }
            }
            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(592, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_4);
            teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(593, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
            teavm_gc_writeBarrier(teavm_local_4);
            TEAVM_FIELD(teavm_local_4, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
            TEAVM_FIELD(teavm_local_4, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
            TEAVM_FIELD(teavm_local_4, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
            teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(594, meth_otr_ExceptionHandling_fillStackTrace());
            teavm_gc_writeBarrier(teavm_local_4);
            TEAVM_FIELD(teavm_local_4, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
            TEAVM_WITH_CALL_SITE_ID(595, meth_otr_ExceptionHandling_throwException(teavm_local_4));
            TEAVM_UNREACHABLE
        }
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(596, meth_otr_Allocator_allocate(&jn_ReadOnlyBufferException_Cls));
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_4);
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(597, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
        teavm_gc_writeBarrier(teavm_local_4);
        TEAVM_FIELD(teavm_local_4, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
        TEAVM_FIELD(teavm_local_4, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
        TEAVM_FIELD(teavm_local_4, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(598, meth_otr_ExceptionHandling_fillStackTrace());
        teavm_gc_writeBarrier(teavm_local_4);
        TEAVM_FIELD(teavm_local_4, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
        TEAVM_WITH_CALL_SITE_ID(599, meth_otr_ExceptionHandling_throwException(teavm_local_4));
        TEAVM_UNREACHABLE
    }
teavm_label_1:;
    TEAVM_RELEASE_STACK;
    return teavm_this_;
}
int32_t supertypeof_jn_ByteBuffer(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 174 || tag >= 178) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_jn_ByteBuffer_Cls[2];
alignas(8) jn_ByteBuffer_VT jn_ByteBuffer_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jn_ByteBuffer), sizeof(void*)),
                .flags = 0,
                .tag = 174,
                .modifiers = 1025,
                .name = NULL,
                .arrayType = NULL,
                .itemType = NULL,
                .isSupertypeOf = &supertypeof_jn_ByteBuffer,
                .superclass = (TeaVM_Class*) &jn_Buffer_Cls,
                .layout = teavm_classLayouts_jn_ByteBuffer_Cls,
                .enumValues = NULL
            },
            .virt_clone = &meth_jl_Object_clone
        }
    }
};
static int16_t teavm_classLayouts_jn_ByteBuffer_Cls[2] = {
INT16_C(1), (int16_t) offsetof(cls_jn_ByteBuffer, fld_order)
};
void sysinitclass_jn_ByteBuffer() {
}
