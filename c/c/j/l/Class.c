#include "Class.h"
#include "Object.h"
#include "../../o/t/r/Allocator.h"
#include "../../../core.h"
#include "StringBuilder.h"
#include "../../../a/p/char.h"
#include "AbstractStringBuilder.h"
#include "../../../strings.h"
#include "String.h"
#include "System.h"
#include "IndexOutOfBoundsException.h"
#include "../../../arrayclass.h"
#include "Throwable.h"
#include "../../o/t/r/ExceptionHandling.h"

void* meth_jl_Class_createClass(void* teavm_local_1) {
    void* teavm_local_2;
    TEAVM_ALLOC_STACK(INT32_C(0));
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(10, meth_otr_Allocator_allocate(&jl_Class_Cls));
    TEAVM_FIELD(teavm_local_2, cls_jl_Class, fld_classInfo) = teavm_local_1;
    TEAVM_RELEASE_STACK;
    return teavm_local_2;
}
void* meth_jl_Class_getName(void* teavm_this_) {
    int32_t teavm_local_1;
    void* teavm_local_2;
    void* teavm_local_3;
    void* teavm_local_4;
    void* teavm_local_5;
    TeaVM_Array* teavm_local_6;
    int32_t teavm_local_7;
    void* teavm_local_8;
    void* teavm_local_9;
    int32_t teavm_local_10;
    TeaVM_Array* teavm_local_11;
    TEAVM_ALLOC_STACK(INT32_C(3));
    teavm_local_1 = TEAVM_FIELD(teavm_this_, cls_jl_Class, fld_flags);
    if ((!(teavm_local_1 & INT32_C(1)))) {
        TEAVM_FIELD(teavm_this_, cls_jl_Class, fld_flags) = (teavm_local_1 | INT32_C(1));
        teavm_local_2 = (((TeaVM_Class*) (TEAVM_FIELD(teavm_this_, cls_jl_Class, fld_classInfo)))->name);
        teavm_local_3 = ((teavm_local_2 == NULL) ? NULL : *((TeaVM_String**) teavm_local_2));
        if ((teavm_local_3 == NULL)) {
            teavm_local_4 = (((TeaVM_Class*) (TEAVM_FIELD(teavm_this_, cls_jl_Class, fld_classInfo)))->itemType);
            if ((teavm_local_4 != NULL)) {
                TEAVM_GC_ROOT(INT32_C(0), teavm_local_3);
                TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(11, teavm_getClassObject((TeaVM_Class*) teavm_local_4));
                TEAVM_GC_ROOT(INT32_C(1), teavm_local_2);
                teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(12, meth_jl_Class_getName(TEAVM_WITH_CALL_SITE_ID(13, teavm_nullCheck(teavm_local_2))));
                if ((teavm_local_5 != NULL)) {
                    if (((((TeaVM_Class*) (teavm_local_4))->itemType) == NULL)) {
                        TEAVM_GC_ROOT(INT32_C(0), teavm_local_5);
                        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(14, meth_otr_Allocator_allocate(&jl_StringBuilder_Cls));
                        TEAVM_GC_ROOT(INT32_C(1), teavm_local_2);
                        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(15, meth_otr_Allocator_allocateArray(&Arr_C_Cls, INT32_C(16)));
                        teavm_gc_writeBarrier(teavm_local_2);
                        TEAVM_FIELD(teavm_local_2, cls_jl_AbstractStringBuilder, fld_buffer) = teavm_local_6;
                        teavm_local_7 = TEAVM_FIELD(teavm_local_2, cls_jl_AbstractStringBuilder, fld_length);
                        teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(16, teavm_nullCheck(teavm_local_2));
                        teavm_local_3 = TEAVM_GET_STRING(0);
                        TEAVM_GC_ROOT(INT32_C(2), teavm_local_3);
                        teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(17, teavm_nullCheck(teavm_local_3));
                        teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(18, teavm_nullCheck(teavm_local_4));
                        TEAVM_WITH_CALL_SITE_ID(19, meth_jl_AbstractStringBuilder_insert(teavm_local_9, teavm_local_7, teavm_local_8));
                        teavm_local_7 = TEAVM_FIELD(teavm_local_2, cls_jl_AbstractStringBuilder, fld_length);
                        teavm_local_3 = teavm_local_5;
                        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                        TEAVM_WITH_CALL_SITE_ID(20, meth_jl_AbstractStringBuilder_insert(teavm_local_9, teavm_local_7, TEAVM_WITH_CALL_SITE_ID(21, teavm_nullCheck(teavm_local_3))));
                        teavm_local_1 = TEAVM_FIELD(teavm_local_2, cls_jl_AbstractStringBuilder, fld_length);
                        teavm_local_10 = (teavm_local_1 + INT32_C(1));
                        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                        TEAVM_WITH_CALL_SITE_ID(22, meth_jl_AbstractStringBuilder_insertSpace(teavm_local_4, teavm_local_1, teavm_local_10));
                        teavm_local_6 = TEAVM_FIELD(teavm_local_4, cls_jl_AbstractStringBuilder, fld_buffer);
                        TEAVM_GC_ROOT(INT32_C(0), teavm_local_6);
                        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(23, teavm_nullCheck(teavm_local_6));
                        TEAVM_ARRAY_AT(teavm_local_6, char16_t, TEAVM_WITH_CALL_SITE_ID(24, teavm_checkBounds(teavm_local_1, teavm_local_6))) = INT32_C(59);
                        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(25, meth_otr_Allocator_allocate(&jl_String_Cls));
                        teavm_local_6 = TEAVM_FIELD(teavm_local_2, cls_jl_AbstractStringBuilder, fld_buffer);
                        teavm_local_1 = TEAVM_FIELD(teavm_local_2, cls_jl_AbstractStringBuilder, fld_length);
                        TEAVM_GC_ROOT(INT32_C(0), teavm_local_3);
                        TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
                        TEAVM_WITH_CALL_SITE_ID(26, teavm_initializeClass((TeaVM_Class*) &jl_String_Cls, &initclass_jl_String));
                        teavm_local_11 = TEAVM_WITH_CALL_SITE_ID(27, teavm_nullCheck(teavm_local_6));
                        teavm_local_10 = TEAVM_ARRAY_LENGTH(teavm_local_11);
                        if ((teavm_local_1 < INT32_C(0))) {
                            goto teavm_label_1;
                        }
                        if ((teavm_local_1 > (teavm_local_10 - INT32_C(0)))) {
                            goto teavm_label_1;
                        }
                        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(28, meth_otr_Allocator_allocateArray(&Arr_C_Cls, teavm_local_1));
                        TEAVM_GC_ROOT(INT32_C(2), teavm_local_6);
                        TEAVM_WITH_CALL_SITE_ID(29, meth_jl_System_fastArraycopy(teavm_local_11, INT32_C(0), teavm_local_6, INT32_C(0), teavm_local_1));
                        teavm_gc_writeBarrier(teavm_local_3);
                        TEAVM_FIELD(teavm_local_3, TeaVM_String, characters) = teavm_local_6;
                    } else {
                        TEAVM_GC_ROOT(INT32_C(0), teavm_local_5);
                        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(30, meth_otr_Allocator_allocate(&jl_StringBuilder_Cls));
                        TEAVM_GC_ROOT(INT32_C(1), teavm_local_2);
                        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(31, meth_otr_Allocator_allocateArray(&Arr_C_Cls, INT32_C(16)));
                        teavm_gc_writeBarrier(teavm_local_2);
                        TEAVM_FIELD(teavm_local_2, cls_jl_AbstractStringBuilder, fld_buffer) = teavm_local_6;
                        teavm_local_10 = TEAVM_FIELD(teavm_local_2, cls_jl_AbstractStringBuilder, fld_length);
                        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(32, teavm_nullCheck(teavm_local_2));
                        TEAVM_WITH_CALL_SITE_ID(33, meth_jl_AbstractStringBuilder_insertSpace(teavm_local_3, teavm_local_10, (teavm_local_10 + INT32_C(1))));
                        teavm_local_6 = TEAVM_FIELD(teavm_local_3, cls_jl_AbstractStringBuilder, fld_buffer);
                        TEAVM_GC_ROOT(INT32_C(2), teavm_local_6);
                        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(34, teavm_nullCheck(teavm_local_6));
                        TEAVM_ARRAY_AT(teavm_local_6, char16_t, TEAVM_WITH_CALL_SITE_ID(35, teavm_checkBounds(teavm_local_10, teavm_local_6))) = INT32_C(91);
                        teavm_local_7 = TEAVM_FIELD(teavm_local_2, cls_jl_AbstractStringBuilder, fld_length);
                        teavm_local_4 = teavm_local_5;
                        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                        teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(36, teavm_nullCheck(teavm_local_4));
                        TEAVM_WITH_CALL_SITE_ID(37, meth_jl_AbstractStringBuilder_insert(TEAVM_WITH_CALL_SITE_ID(38, teavm_nullCheck(teavm_local_3)), teavm_local_7, teavm_local_4));
                        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(39, meth_otr_Allocator_allocate(&jl_String_Cls));
                        teavm_local_6 = TEAVM_FIELD(teavm_local_2, cls_jl_AbstractStringBuilder, fld_buffer);
                        teavm_local_1 = TEAVM_FIELD(teavm_local_2, cls_jl_AbstractStringBuilder, fld_length);
                        TEAVM_GC_ROOT(INT32_C(0), teavm_local_3);
                        TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
                        TEAVM_WITH_CALL_SITE_ID(40, teavm_initializeClass((TeaVM_Class*) &jl_String_Cls, &initclass_jl_String));
                        teavm_local_11 = TEAVM_WITH_CALL_SITE_ID(41, teavm_nullCheck(teavm_local_6));
                        teavm_local_10 = TEAVM_ARRAY_LENGTH(teavm_local_11);
                        if (((teavm_local_1 >= INT32_C(0)) && (teavm_local_1 <= (teavm_local_10 - INT32_C(0))))) {
                            teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(42, meth_otr_Allocator_allocateArray(&Arr_C_Cls, teavm_local_1));
                            TEAVM_GC_ROOT(INT32_C(2), teavm_local_6);
                            TEAVM_WITH_CALL_SITE_ID(43, meth_jl_System_fastArraycopy(teavm_local_11, INT32_C(0), teavm_local_6, INT32_C(0), teavm_local_1));
                            teavm_gc_writeBarrier(teavm_local_3);
                            TEAVM_FIELD(teavm_local_3, TeaVM_String, characters) = teavm_local_6;
                        } else {
                            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                            teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(44, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
                            TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
                            teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(45, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                            teavm_gc_writeBarrier(teavm_local_2);
                            TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressed) = teavm_local_6;
                            TEAVM_WITH_CALL_SITE_ID(46, meth_jl_Throwable_initNativeException(teavm_local_2));
                            TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                            TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                            TEAVM_WITH_CALL_SITE_ID(47, meth_jl_Throwable_fillInStackTrace(teavm_local_2));
                            TEAVM_WITH_CALL_SITE_ID(48, meth_otr_ExceptionHandling_throwException(teavm_local_2));
                            TEAVM_UNREACHABLE
                        }
                    }
                }
            }
        }
        teavm_gc_writeBarrier(teavm_this_);
        TEAVM_FIELD(teavm_this_, cls_jl_Class, fld_name) = teavm_local_3;
    }
    teavm_local_2 = TEAVM_FIELD(teavm_this_, cls_jl_Class, fld_name);
    TEAVM_RELEASE_STACK;
    return teavm_local_2;
teavm_label_1:;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(49, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(50, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_2);
    TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressed) = teavm_local_6;
    TEAVM_WITH_CALL_SITE_ID(51, meth_jl_Throwable_initNativeException(teavm_local_2));
    TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_2, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    TEAVM_WITH_CALL_SITE_ID(52, meth_jl_Throwable_fillInStackTrace(teavm_local_2));
    TEAVM_WITH_CALL_SITE_ID(53, meth_otr_ExceptionHandling_throwException(teavm_local_2));
    TEAVM_UNREACHABLE
}
void* meth_jl_Class_getComponentType(void* teavm_this_) {
    void* teavm_local_1;
    TEAVM_ALLOC_STACK(INT32_C(0));
    teavm_local_1 = (((TeaVM_Class*) (TEAVM_FIELD(teavm_this_, cls_jl_Class, fld_classInfo)))->itemType);
    teavm_local_1 = ((teavm_local_1 == NULL) ? NULL : TEAVM_WITH_CALL_SITE_ID(54, teavm_getClassObject((TeaVM_Class*) teavm_local_1)));
    TEAVM_RELEASE_STACK;
    return teavm_local_1;
}
int32_t supertypeof_jl_Class(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 3 || tag >= 5) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_jl_Class_Cls[2];
alignas(8) jl_Class_VT jl_Class_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_Class), sizeof(void*)),
            .flags = 0,
            .tag = 3,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jl_Class,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_jl_Class_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static int16_t teavm_classLayouts_jl_Class_Cls[2] = {
INT16_C(1), (int16_t) offsetof(cls_jl_Class, fld_name)
};
void sysinitclass_jl_Class() {
}
