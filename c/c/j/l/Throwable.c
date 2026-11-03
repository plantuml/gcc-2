#include "Throwable.h"
#include "Object.h"
#include "../../../arrayclass.h"
#include "../../o/t/r/Allocator.h"
#include "../../o/t/r/ExceptionHandling.h"
#include "../../../core.h"
#include "Class.h"
#include "../../../strings.h"
#include "StringBuilder.h"
#include "../../../a/p/char.h"
#include "AbstractStringBuilder.h"
#include "String.h"
#include "System.h"
#include "IndexOutOfBoundsException.h"

void meth_jl_Throwable__init_(void* teavm_this_, void* teavm_local_1) {
    TeaVM_Array* teavm_local_2;
    TEAVM_ALLOC_STACK(INT32_C(0));
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(59, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_this_);
    TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_suppressed) = teavm_local_2;
    TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(60, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_this_);
    TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_stackTrace) = teavm_local_2;
    TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_message) = teavm_local_1;
    TEAVM_RELEASE_STACK;
}
void* meth_jl_Throwable_fillInStackTrace(void* teavm_this_) {
    TeaVM_Array* teavm_local_1;
    TEAVM_ALLOC_STACK(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(61, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_this_);
    TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
    TEAVM_RELEASE_STACK;
    return teavm_this_;
}
void meth_jl_Throwable_initNativeException(void* teavm_this_) {
    return;
}
void* meth_jl_Throwable_getMessage(void* teavm_this_) {
    return TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_message);
}
void* meth_jl_Throwable_getLocalizedMessage(void* teavm_this_) {
    return TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_message);
}
void* meth_jl_Throwable_toString(void* teavm_this_) {
    void* teavm_local_1;
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
    teavm_local_1 = TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_message);
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_GC_ROOT(INT32_C(3), teavm_local_1);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(62, teavm_getClassObject((TeaVM_Class*) TEAVM_WITH_CALL_SITE_ID(63, TEAVM_CLASS_OF(teavm_this_))));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(64, meth_jl_Class_getName(TEAVM_WITH_CALL_SITE_ID(65, teavm_nullCheck(teavm_local_2))));
    if ((teavm_local_1 == NULL)) {
        teavm_local_1 = TEAVM_GET_STRING(2);
    } else {
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(66, meth_otr_Allocator_allocate(&jl_StringBuilder_Cls));
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
        teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(67, meth_otr_Allocator_allocateArray(&Arr_C_Cls, INT32_C(16)));
        teavm_gc_writeBarrier(teavm_local_3);
        TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_buffer) = teavm_local_4;
        teavm_local_5 = TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_length);
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(68, teavm_nullCheck(teavm_local_3));
        teavm_local_7 = TEAVM_GET_STRING(3);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_7);
        teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(69, teavm_nullCheck(teavm_local_7));
        teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(70, teavm_nullCheck(teavm_local_6));
        TEAVM_WITH_CALL_SITE_ID(71, meth_jl_AbstractStringBuilder_insert(teavm_local_7, teavm_local_5, teavm_local_8));
        teavm_local_5 = TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_length);
        teavm_local_1 = teavm_local_1;
        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
        TEAVM_WITH_CALL_SITE_ID(72, meth_jl_AbstractStringBuilder_insert(teavm_local_7, teavm_local_5, TEAVM_WITH_CALL_SITE_ID(73, teavm_nullCheck(teavm_local_1))));
        TEAVM_GC_ROOT_RELEASE(INT32_C(3));
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(74, meth_otr_Allocator_allocate(&jl_String_Cls));
        teavm_local_4 = TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_buffer);
        teavm_local_9 = TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_length);
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_1);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_4);
        TEAVM_WITH_CALL_SITE_ID(75, teavm_initializeClass((TeaVM_Class*) &jl_String_Cls, &initclass_jl_String));
        teavm_local_10 = TEAVM_WITH_CALL_SITE_ID(76, teavm_nullCheck(teavm_local_4));
        teavm_local_11 = TEAVM_ARRAY_LENGTH(teavm_local_10);
        if (((teavm_local_9 >= INT32_C(0)) && (teavm_local_9 <= (teavm_local_11 - INT32_C(0))))) {
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(77, meth_otr_Allocator_allocateArray(&Arr_C_Cls, teavm_local_9));
            TEAVM_GC_ROOT(INT32_C(3), teavm_local_4);
            TEAVM_WITH_CALL_SITE_ID(78, meth_jl_System_fastArraycopy(teavm_local_10, INT32_C(0), teavm_local_4, INT32_C(0), teavm_local_9));
            teavm_gc_writeBarrier(teavm_local_1);
            TEAVM_FIELD(teavm_local_1, TeaVM_String, characters) = teavm_local_4;
        } else {
            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
            TEAVM_GC_ROOT_RELEASE(INT32_C(2));
            teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(79, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(80, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
            teavm_gc_writeBarrier(teavm_local_1);
            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_4;
            TEAVM_WITH_CALL_SITE_ID(81, meth_jl_Throwable_initNativeException(teavm_local_1));
            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
            TEAVM_WITH_CALL_SITE_ID(82, meth_jl_Throwable_fillInStackTrace(teavm_local_1));
            TEAVM_WITH_CALL_SITE_ID(83, meth_otr_ExceptionHandling_throwException(teavm_local_1));
            TEAVM_UNREACHABLE
        }
    }
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_1);
    TEAVM_GC_ROOT_RELEASE(INT32_C(3));
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(84, meth_otr_Allocator_allocate(&jl_StringBuilder_Cls));
    TEAVM_GC_ROOT(INT32_C(2), teavm_local_3);
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(85, meth_otr_Allocator_allocateArray(&Arr_C_Cls, INT32_C(16)));
    teavm_gc_writeBarrier(teavm_local_3);
    TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_buffer) = teavm_local_4;
    teavm_local_5 = TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_length);
    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(86, teavm_nullCheck(teavm_local_3));
    teavm_local_2 = ((teavm_local_2 == NULL) ? TEAVM_GET_STRING(4) : TEAVM_WITH_CALL_SITE_ID(87, teavm_nullCheck(teavm_local_2)));
    teavm_local_7 = teavm_local_7;
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(88, teavm_nullCheck(teavm_local_7));
    TEAVM_WITH_CALL_SITE_ID(89, meth_jl_AbstractStringBuilder_insert(teavm_local_7, teavm_local_5, teavm_local_2));
    teavm_local_5 = TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_length);
    teavm_local_1 = teavm_local_1;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_WITH_CALL_SITE_ID(90, meth_jl_AbstractStringBuilder_insert(teavm_local_7, teavm_local_5, TEAVM_WITH_CALL_SITE_ID(91, teavm_nullCheck(teavm_local_1))));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(92, meth_otr_Allocator_allocate(&jl_String_Cls));
    teavm_local_4 = TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_buffer);
    teavm_local_9 = TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_length);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_4);
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_WITH_CALL_SITE_ID(93, teavm_initializeClass((TeaVM_Class*) &jl_String_Cls, &initclass_jl_String));
    teavm_local_10 = TEAVM_WITH_CALL_SITE_ID(94, teavm_nullCheck(teavm_local_4));
    teavm_local_11 = TEAVM_ARRAY_LENGTH(teavm_local_10);
    if (((teavm_local_9 >= INT32_C(0)) && (teavm_local_9 <= (teavm_local_11 - INT32_C(0))))) {
        teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(95, meth_otr_Allocator_allocateArray(&Arr_C_Cls, teavm_local_9));
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_4);
        TEAVM_WITH_CALL_SITE_ID(96, meth_jl_System_fastArraycopy(teavm_local_10, INT32_C(0), teavm_local_4, INT32_C(0), teavm_local_9));
        teavm_gc_writeBarrier(teavm_local_1);
        TEAVM_FIELD(teavm_local_1, TeaVM_String, characters) = teavm_local_4;
        TEAVM_RELEASE_STACK;
        return teavm_local_1;
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(97, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(98, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_4;
    TEAVM_WITH_CALL_SITE_ID(99, meth_jl_Throwable_initNativeException(teavm_local_1));
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    TEAVM_WITH_CALL_SITE_ID(100, meth_jl_Throwable_fillInStackTrace(teavm_local_1));
    TEAVM_WITH_CALL_SITE_ID(101, meth_otr_ExceptionHandling_throwException(teavm_local_1));
    TEAVM_UNREACHABLE
}
int32_t supertypeof_jl_Throwable(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 49 || tag >= 101) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_jl_Throwable_Cls[5];
alignas(8) jl_Throwable_VT jl_Throwable_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_Throwable), sizeof(void*)),
            .flags = 0,
            .tag = 49,
            .modifiers = 1,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jl_Throwable,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_jl_Throwable_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static int16_t teavm_classLayouts_jl_Throwable_Cls[5] = {
INT16_C(4), (int16_t) offsetof(cls_jl_Throwable, fld_message), (int16_t) offsetof(cls_jl_Throwable, fld_cause), (int16_t) offsetof(cls_jl_Throwable, fld_suppressed), (int16_t) offsetof(cls_jl_Throwable, fld_stackTrace)
};
void sysinitclass_jl_Throwable() {
}
