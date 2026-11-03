#include "Buffer.h"
#include "../l/Object.h"
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

void* meth_jn_Buffer_position(void* teavm_this_, int32_t teavm_local_1) {
    void* teavm_local_2;
    int32_t teavm_local_3;
    void* teavm_local_4;
    TeaVM_Array* teavm_local_5;
    int32_t teavm_local_6;
    void* teavm_local_7;
    void* teavm_local_8;
    void* teavm_local_9;
    void* teavm_local_10;
    int32_t teavm_local_11;
    TeaVM_Array* teavm_local_12;
    TEAVM_ALLOC_STACK(INT32_C(4));
    if (((teavm_local_1 >= INT32_C(0)) && (teavm_local_1 <= TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_limit)))) {
        TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_position) = teavm_local_1;
        if ((teavm_local_1 < TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_mark))) {
            TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_mark) = INT32_C(0);
        }
        TEAVM_RELEASE_STACK;
        return teavm_this_;
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(3));
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(497, meth_otr_Allocator_allocate(&jl_IllegalArgumentException_Cls));
    teavm_local_3 = TEAVM_FIELD(teavm_this_, cls_jn_Buffer, fld_limit);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(498, meth_otr_Allocator_allocate(&jl_StringBuilder_Cls));
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_4);
    teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(499, meth_otr_Allocator_allocateArray(&Arr_C_Cls, INT32_C(16)));
    teavm_gc_writeBarrier(teavm_local_4);
    TEAVM_FIELD(teavm_local_4, cls_jl_AbstractStringBuilder, fld_buffer) = teavm_local_5;
    teavm_local_6 = TEAVM_FIELD(teavm_local_4, cls_jl_AbstractStringBuilder, fld_length);
    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(500, teavm_nullCheck(teavm_local_4));
    teavm_local_8 = TEAVM_GET_STRING(22);
    TEAVM_GC_ROOT(INT32_C(2), teavm_local_8);
    teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(501, teavm_nullCheck(teavm_local_8));
    teavm_local_10 = TEAVM_WITH_CALL_SITE_ID(502, teavm_nullCheck(teavm_local_7));
    TEAVM_WITH_CALL_SITE_ID(503, meth_jl_AbstractStringBuilder_insert(teavm_local_10, teavm_local_6, teavm_local_9));
    teavm_local_11 = TEAVM_FIELD(teavm_local_4, cls_jl_AbstractStringBuilder, fld_length);
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_WITH_CALL_SITE_ID(504, meth_jl_AbstractStringBuilder_insert_0(teavm_local_4, teavm_local_11, teavm_local_1, INT32_C(10)));
    teavm_local_6 = TEAVM_FIELD(teavm_local_4, cls_jl_AbstractStringBuilder, fld_length);
    teavm_local_8 = TEAVM_GET_STRING(23);
    TEAVM_GC_ROOT(INT32_C(2), teavm_local_8);
    TEAVM_WITH_CALL_SITE_ID(505, meth_jl_AbstractStringBuilder_insert(teavm_local_10, teavm_local_6, TEAVM_WITH_CALL_SITE_ID(506, teavm_nullCheck(teavm_local_8))));
    teavm_local_11 = TEAVM_FIELD(teavm_local_4, cls_jl_AbstractStringBuilder, fld_length);
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_WITH_CALL_SITE_ID(507, meth_jl_AbstractStringBuilder_insert_0(teavm_local_4, teavm_local_11, teavm_local_3, INT32_C(10)));
    teavm_local_3 = TEAVM_FIELD(teavm_local_4, cls_jl_AbstractStringBuilder, fld_length);
    TEAVM_WITH_CALL_SITE_ID(508, meth_jl_AbstractStringBuilder_insertSpace(teavm_local_7, teavm_local_3, (teavm_local_3 + INT32_C(1))));
    teavm_local_5 = TEAVM_FIELD(teavm_local_7, cls_jl_AbstractStringBuilder, fld_buffer);
    TEAVM_GC_ROOT(INT32_C(2), teavm_local_5);
    teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(509, teavm_nullCheck(teavm_local_5));
    TEAVM_ARRAY_AT(teavm_local_5, char16_t, TEAVM_WITH_CALL_SITE_ID(510, teavm_checkBounds(teavm_local_3, teavm_local_5))) = INT32_C(93);
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(511, meth_otr_Allocator_allocate(&jl_String_Cls));
    teavm_local_5 = TEAVM_FIELD(teavm_local_4, cls_jl_AbstractStringBuilder, fld_buffer);
    teavm_local_3 = TEAVM_FIELD(teavm_local_4, cls_jl_AbstractStringBuilder, fld_length);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_8);
    TEAVM_GC_ROOT(INT32_C(2), teavm_local_5);
    TEAVM_WITH_CALL_SITE_ID(512, teavm_initializeClass((TeaVM_Class*) &jl_String_Cls, &initclass_jl_String));
    teavm_local_12 = TEAVM_WITH_CALL_SITE_ID(513, teavm_nullCheck(teavm_local_5));
    teavm_local_6 = TEAVM_ARRAY_LENGTH(teavm_local_12);
    if (((teavm_local_3 >= INT32_C(0)) && (teavm_local_3 <= (teavm_local_6 - INT32_C(0))))) {
        teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(514, meth_otr_Allocator_allocateArray(&Arr_C_Cls, teavm_local_3));
        TEAVM_GC_ROOT(INT32_C(3), teavm_local_5);
        TEAVM_WITH_CALL_SITE_ID(515, meth_jl_System_fastArraycopy(teavm_local_12, INT32_C(0), teavm_local_5, INT32_C(0), teavm_local_3));
        teavm_gc_writeBarrier(teavm_local_8);
        TEAVM_FIELD(teavm_local_8, TeaVM_String, characters) = teavm_local_5;
        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
        TEAVM_GC_ROOT_RELEASE(INT32_C(3));
        teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(516, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
        teavm_gc_writeBarrier(teavm_local_2);
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressed) = teavm_local_5;
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
        teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(517, meth_otr_ExceptionHandling_fillStackTrace());
        teavm_gc_writeBarrier(teavm_local_2);
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_stackTrace) = teavm_local_5;
        TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_message) = teavm_local_8;
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        TEAVM_WITH_CALL_SITE_ID(518, meth_otr_ExceptionHandling_throwException(teavm_local_2));
        TEAVM_UNREACHABLE
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(519, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(520, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_2);
    TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressed) = teavm_local_5;
    TEAVM_WITH_CALL_SITE_ID(521, meth_jl_Throwable_initNativeException(teavm_local_2));
    TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    TEAVM_WITH_CALL_SITE_ID(522, meth_jl_Throwable_fillInStackTrace(teavm_local_2));
    TEAVM_WITH_CALL_SITE_ID(523, meth_otr_ExceptionHandling_throwException(teavm_local_2));
    TEAVM_UNREACHABLE
}
int32_t supertypeof_jn_Buffer(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 167 || tag >= 179) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jn_Buffer_VT jn_Buffer_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jn_Buffer), sizeof(void*)),
            .flags = 0,
            .tag = 167,
            .modifiers = 1025,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jn_Buffer,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
void sysinitclass_jn_Buffer() {
}
