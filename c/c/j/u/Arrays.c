#include "Arrays.h"
#include "../l/Object.h"
#include "../../../a/p/int.h"
#include "../../o/t/r/Allocator.h"
#include "../../../a/p/long.h"
#include "../../../a/p/float.h"
#include "../../../a/p/double.h"
#include "../../../core.h"
#include "../l/Class.h"
#include "../../../p/void.h"
#include "../../../arrayclass.h"
#include "../l/NegativeArraySizeException.h"
#include "../l/Throwable.h"
#include "../../o/t/r/ExceptionHandling.h"
#include "../l/IllegalArgumentException.h"
#include "../l/NullPointerException.h"
#include "../../../strings.h"

TeaVM_Array* meth_ju_Arrays_copyOf(TeaVM_Array* teavm_local_1, int32_t teavm_local_2) {
    TeaVM_Array* teavm_local_3;
    int32_t teavm_local_4;
    TeaVM_Array* teavm_local_5;
    int32_t teavm_local_6;
    TEAVM_ALLOC_STACK(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(238, meth_otr_Allocator_allocateArray(&Arr_I_Cls, teavm_local_2));
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(239, teavm_nullCheck(teavm_local_1));
    teavm_local_4 = TEAVM_ARRAY_LENGTH(teavm_local_1);
    if ((teavm_local_2 < teavm_local_4)) {
        teavm_local_4 = teavm_local_2;
    }
    teavm_local_5 = teavm_local_3;
    teavm_local_6 = INT32_C(0);
    while (1) {
        if (!(teavm_local_6 < teavm_local_4)) break;
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(240, teavm_checkBounds(teavm_local_6, teavm_local_1));
        teavm_local_2 = TEAVM_ARRAY_AT(teavm_local_1, int32_t, teavm_local_6);
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(241, teavm_checkUpperBound(teavm_local_6, teavm_local_5));
        TEAVM_ARRAY_AT(teavm_local_5, int32_t, teavm_local_6) = teavm_local_2;
        teavm_local_6 = (teavm_local_6 + INT32_C(1));
    }
    TEAVM_RELEASE_STACK;
    return teavm_local_3;
}
TeaVM_Array* meth_ju_Arrays_copyOf_0(TeaVM_Array* teavm_local_1, int32_t teavm_local_2) {
    TeaVM_Array* teavm_local_3;
    int32_t teavm_local_4;
    TeaVM_Array* teavm_local_5;
    int32_t teavm_local_6;
    int64_t teavm_local_7;
    TEAVM_ALLOC_STACK(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(242, meth_otr_Allocator_allocateArray(&Arr_J_Cls, teavm_local_2));
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(243, teavm_nullCheck(teavm_local_1));
    teavm_local_4 = TEAVM_ARRAY_LENGTH(teavm_local_1);
    if ((teavm_local_2 < teavm_local_4)) {
        teavm_local_4 = teavm_local_2;
    }
    teavm_local_5 = teavm_local_3;
    teavm_local_6 = INT32_C(0);
    while (1) {
        if (!(teavm_local_6 < teavm_local_4)) break;
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(244, teavm_checkBounds(teavm_local_6, teavm_local_1));
        teavm_local_7 = TEAVM_ARRAY_AT(teavm_local_1, int64_t, teavm_local_6);
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(245, teavm_checkUpperBound(teavm_local_6, teavm_local_5));
        TEAVM_ARRAY_AT(teavm_local_5, int64_t, teavm_local_6) = teavm_local_7;
        teavm_local_6 = (teavm_local_6 + INT32_C(1));
    }
    TEAVM_RELEASE_STACK;
    return teavm_local_3;
}
TeaVM_Array* meth_ju_Arrays_copyOf_1(TeaVM_Array* teavm_local_1, int32_t teavm_local_2) {
    TeaVM_Array* teavm_local_3;
    int32_t teavm_local_4;
    TeaVM_Array* teavm_local_5;
    int32_t teavm_local_6;
    float teavm_local_7;
    TEAVM_ALLOC_STACK(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(246, meth_otr_Allocator_allocateArray(&Arr_F_Cls, teavm_local_2));
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(247, teavm_nullCheck(teavm_local_1));
    teavm_local_4 = TEAVM_ARRAY_LENGTH(teavm_local_1);
    if ((teavm_local_2 < teavm_local_4)) {
        teavm_local_4 = teavm_local_2;
    }
    teavm_local_5 = teavm_local_3;
    teavm_local_6 = INT32_C(0);
    while (1) {
        if (!(teavm_local_6 < teavm_local_4)) break;
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(248, teavm_checkBounds(teavm_local_6, teavm_local_1));
        teavm_local_7 = TEAVM_ARRAY_AT(teavm_local_1, float, teavm_local_6);
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(249, teavm_checkUpperBound(teavm_local_6, teavm_local_5));
        TEAVM_ARRAY_AT(teavm_local_5, float, teavm_local_6) = teavm_local_7;
        teavm_local_6 = (teavm_local_6 + INT32_C(1));
    }
    TEAVM_RELEASE_STACK;
    return teavm_local_3;
}
TeaVM_Array* meth_ju_Arrays_copyOf_2(TeaVM_Array* teavm_local_1, int32_t teavm_local_2) {
    TeaVM_Array* teavm_local_3;
    int32_t teavm_local_4;
    TeaVM_Array* teavm_local_5;
    int32_t teavm_local_6;
    double teavm_local_7;
    TEAVM_ALLOC_STACK(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(250, meth_otr_Allocator_allocateArray(&Arr_D_Cls, teavm_local_2));
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(251, teavm_nullCheck(teavm_local_1));
    teavm_local_4 = TEAVM_ARRAY_LENGTH(teavm_local_1);
    if ((teavm_local_2 < teavm_local_4)) {
        teavm_local_4 = teavm_local_2;
    }
    teavm_local_5 = teavm_local_3;
    teavm_local_6 = INT32_C(0);
    while (1) {
        if (!(teavm_local_6 < teavm_local_4)) break;
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(252, teavm_checkBounds(teavm_local_6, teavm_local_1));
        teavm_local_7 = TEAVM_ARRAY_AT(teavm_local_1, double, teavm_local_6);
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(253, teavm_checkUpperBound(teavm_local_6, teavm_local_5));
        TEAVM_ARRAY_AT(teavm_local_5, double, teavm_local_6) = teavm_local_7;
        teavm_local_6 = (teavm_local_6 + INT32_C(1));
    }
    TEAVM_RELEASE_STACK;
    return teavm_local_3;
}
TeaVM_Array* meth_ju_Arrays_copyOf_3(TeaVM_Array* teavm_local_1, int32_t teavm_local_2) {
    void* teavm_local_3;
    void* teavm_local_4;
    TeaVM_Array* teavm_local_5;
    int32_t teavm_local_6;
    int32_t teavm_local_7;
    TeaVM_Array* teavm_local_8;
    TEAVM_ALLOC_STACK(INT32_C(3));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(254, teavm_nullCheck(teavm_local_1));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(255, teavm_getClassObject((TeaVM_Class*) TEAVM_WITH_CALL_SITE_ID(256, TEAVM_CLASS_OF(teavm_local_1))));
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    teavm_local_3 = (((TeaVM_Class*) (TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(257, teavm_nullCheck(teavm_local_3)), cls_jl_Class, fld_classInfo)))->itemType);
    if ((teavm_local_3 == NULL)) {
        teavm_local_4 = NULL;
    } else {
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(258, teavm_getClassObject((TeaVM_Class*) teavm_local_3));
    }
    if ((teavm_local_4 != NULL)) {
        if ((teavm_local_4 != teavm_getClassObject((TeaVM_Class*) &V_Cls))) {
            if ((teavm_local_2 >= INT32_C(0))) {
                teavm_local_1 = teavm_local_1;
                teavm_local_3 = teavm_local_4;
                TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
                teavm_local_3 = TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(259, teavm_nullCheck(teavm_local_3)), cls_jl_Class, fld_classInfo);
                TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(260, meth_otr_Allocator_allocateArray(teavm_getArrayClass(teavm_local_3), teavm_local_2));
                teavm_local_6 = TEAVM_ARRAY_LENGTH(teavm_local_1);
                if ((teavm_local_2 < teavm_local_6)) {
                    teavm_local_6 = teavm_local_2;
                }
                teavm_local_7 = INT32_C(0);
                while (1) {
                    if (!(teavm_local_7 < teavm_local_6)) break;
                    TEAVM_GC_ROOT(INT32_C(2), teavm_local_5);
                    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(261, teavm_checkBounds(teavm_local_7, teavm_local_1));
                    teavm_local_3 = TEAVM_ARRAY_AT(teavm_local_1, void*, teavm_local_7);
                    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
                    teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(262, teavm_nullCheck(teavm_local_5));
                    teavm_local_8 = teavm_local_5;
                    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(263, teavm_checkUpperBound(teavm_local_7, teavm_local_8));
                    teavm_gc_writeBarrier(teavm_local_8);
                    TEAVM_ARRAY_AT(teavm_local_8, void*, teavm_local_7) = teavm_local_3;
                    teavm_local_7 = (teavm_local_7 + INT32_C(1));
                }
                TEAVM_RELEASE_STACK;
                return teavm_local_5;
            }
            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
            teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(264, meth_otr_Allocator_allocate(&jl_NegativeArraySizeException_Cls));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_3);
            teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(265, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
            teavm_gc_writeBarrier(teavm_local_3);
            TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
            TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
            TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
            teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(266, meth_otr_ExceptionHandling_fillStackTrace());
            teavm_gc_writeBarrier(teavm_local_3);
            TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
            TEAVM_WITH_CALL_SITE_ID(267, meth_otr_ExceptionHandling_throwException(teavm_local_3));
            TEAVM_UNREACHABLE
        }
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(268, meth_otr_Allocator_allocate(&jl_IllegalArgumentException_Cls));
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_3);
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(269, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
        teavm_gc_writeBarrier(teavm_local_3);
        TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
        TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
        TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(270, meth_otr_ExceptionHandling_fillStackTrace());
        teavm_gc_writeBarrier(teavm_local_3);
        TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
        TEAVM_WITH_CALL_SITE_ID(271, meth_otr_ExceptionHandling_throwException(teavm_local_3));
        TEAVM_UNREACHABLE
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(272, meth_otr_Allocator_allocate(&jl_NullPointerException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_3);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(273, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_3);
    TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
    TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(274, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_local_3);
    TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
    TEAVM_WITH_CALL_SITE_ID(275, meth_otr_ExceptionHandling_throwException(teavm_local_3));
    TEAVM_UNREACHABLE
}
int32_t supertypeof_ju_Arrays(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 115 || tag >= 117) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) ju_Arrays_VT ju_Arrays_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_ju_Arrays), sizeof(void*)),
            .flags = 0,
            .tag = 115,
            .modifiers = 1,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_ju_Arrays,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
void sysinitclass_ju_Arrays() {
}
