#include "System.h"
#include "Object.h"
#include "../../../core.h"
#include "Class.h"
#include "../../../arrayclass.h"
#include "ArrayStoreException.h"
#include "../../o/t/r/Allocator.h"
#include "Throwable.h"
#include "../../o/t/r/ExceptionHandling.h"
#include "IllegalArgumentException.h"
#include "IndexOutOfBoundsException.h"
#include "NullPointerException.h"
#include "../../../strings.h"
#include "../../o/t/r/RuntimeArray.h"
#include "../../o/t/r/RuntimeClass.h"
#include <string.h>
#include "../../../time.h"

void* sfld_jl_System_outCache;
void meth_jl_System_arraycopy(void* teavm_local_1, int32_t teavm_local_2, void* teavm_local_3, int32_t teavm_local_4, int32_t teavm_local_5) {
    int32_t teavm_local_6;
    void* teavm_local_7;
    void* teavm_local_8;
    TeaVM_Array* teavm_local_9;
    int32_t teavm_local_10;
    int32_t teavm_local_11;
    TeaVM_Array* teavm_local_12;
    void* teavm_local_13;
    int32_t teavm_local_14;
    TEAVM_ALLOC_STACK(INT32_C(3));
    if (((teavm_local_1 != NULL) && (teavm_local_3 != NULL))) {
        if (((teavm_local_2 >= INT32_C(0)) && ((teavm_local_4 >= INT32_C(0)) && (teavm_local_5 >= INT32_C(0))))) {
            teavm_local_6 = (teavm_local_2 + teavm_local_5);
            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
            TEAVM_GC_ROOT_RELEASE(INT32_C(2));
            teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(178, teavm_getClassObject((TeaVM_Class*) TEAVM_WITH_CALL_SITE_ID(179, TEAVM_CLASS_OF(teavm_local_1))));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
            teavm_local_8 = TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(180, teavm_nullCheck(teavm_local_7)), cls_jl_Class, fld_classInfo);
            if (((((TeaVM_Class*) (teavm_local_8))->itemType) != NULL)) {
                if ((teavm_local_6 > TEAVM_ARRAY_LENGTH(teavm_local_1))) {
                    goto teavm_label_1;
                }
                teavm_local_6 = (teavm_local_4 + teavm_local_5);
                TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(181, teavm_getClassObject((TeaVM_Class*) TEAVM_WITH_CALL_SITE_ID(182, TEAVM_CLASS_OF(teavm_local_3))));
                TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
                teavm_local_8 = TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(183, teavm_nullCheck(teavm_local_7)), cls_jl_Class, fld_classInfo);
                if (((((TeaVM_Class*) (teavm_local_8))->itemType) != NULL)) {
                    if ((teavm_local_6 <= TEAVM_ARRAY_LENGTH(teavm_local_3))) {
                        if ((teavm_local_1 != teavm_local_3)) {
                            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                            teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(184, teavm_getClassObject((TeaVM_Class*) TEAVM_WITH_CALL_SITE_ID(185, TEAVM_CLASS_OF(teavm_local_1))));
                            TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
                            teavm_local_7 = (((TeaVM_Class*) (TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(186, teavm_nullCheck(teavm_local_7)), cls_jl_Class, fld_classInfo)))->itemType);
                            if ((teavm_local_7 == NULL)) {
                                teavm_local_7 = NULL;
                            } else {
                                TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                                teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(187, teavm_getClassObject((TeaVM_Class*) teavm_local_7));
                            }
                            TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
                            teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(188, teavm_getClassObject((TeaVM_Class*) TEAVM_WITH_CALL_SITE_ID(189, TEAVM_CLASS_OF(teavm_local_3))));
                            TEAVM_GC_ROOT(INT32_C(1), teavm_local_8);
                            teavm_local_8 = (((TeaVM_Class*) (TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(190, teavm_nullCheck(teavm_local_8)), cls_jl_Class, fld_classInfo)))->itemType);
                            if ((teavm_local_8 == NULL)) {
                                teavm_local_8 = NULL;
                            } else {
                                TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                                teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(191, teavm_getClassObject((TeaVM_Class*) teavm_local_8));
                            }
                            if (((teavm_local_7 != NULL) && (teavm_local_8 != NULL))) {
                                if ((teavm_local_7 == teavm_local_8)) {
                                    goto teavm_label_4;
                                }
                                TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                                TEAVM_GC_ROOT(INT32_C(2), teavm_local_8);
                                teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(192, teavm_nullCheck(teavm_local_7));
                                if ((!((!teavm_primitiveKind((TeaVM_Class*) TEAVM_FIELD(teavm_local_7, cls_jl_Class, fld_classInfo))) ? INT32_C(0) : INT32_C(1)))) {
                                    teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(193, teavm_nullCheck(teavm_local_8));
                                    if ((!((!teavm_primitiveKind((TeaVM_Class*) TEAVM_FIELD(teavm_local_8, cls_jl_Class, fld_classInfo))) ? INT32_C(0) : INT32_C(1)))) {
                                        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                                        teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(194, teavm_checkcast(teavm_local_1, teavm_getArrayClass((TeaVM_Class*) &jl_Object_Cls), &teavm_isSupertypeOfArray));
                                        teavm_local_6 = INT32_C(0);
                                        teavm_local_10 = teavm_local_2;
                                        while (1) {
                                            if (!(teavm_local_6 < teavm_local_5)) break;
                                            teavm_local_11 = (teavm_local_10 + INT32_C(1));
                                            TEAVM_GC_ROOT(INT32_C(0), teavm_local_9);
                                            teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(195, teavm_nullCheck(teavm_local_9));
                                            teavm_local_12 = teavm_local_9;
                                            teavm_local_13 = TEAVM_ARRAY_AT(teavm_local_12, void*, TEAVM_WITH_CALL_SITE_ID(196, teavm_checkBounds(teavm_local_10, teavm_local_12)));
                                            if ((teavm_local_13 != NULL)) {
                                                TEAVM_GC_ROOT(INT32_C(1), teavm_local_13);
                                                teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(197, TEAVM_CLASS_OF(teavm_local_13));
                                                TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                                                teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(198, teavm_getClassObject((TeaVM_Class*) teavm_local_7));
                                                teavm_local_13 = TEAVM_FIELD(teavm_local_8, cls_jl_Class, fld_classInfo);
                                                TEAVM_GC_ROOT(INT32_C(1), teavm_local_7);
                                                if (teavm_isSupertypeOf((TeaVM_Class*) teavm_local_13, (TeaVM_Class*) TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(199, teavm_nullCheck(teavm_local_7)), cls_jl_Class, fld_classInfo))) {
                                                    goto teavm_label_8;
                                                }
                                            }
                                            teavm_local_14 = INT32_C(0);
                                            goto teavm_label_7;
                                        teavm_label_8:;
                                            teavm_local_14 = INT32_C(1);
                                        teavm_label_7:;
                                            if ((!teavm_local_14)) {
                                                goto teavm_label_5;
                                            }
                                            teavm_local_6 = (teavm_local_6 + INT32_C(1));
                                            teavm_local_10 = teavm_local_11;
                                        }
                                        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                                        TEAVM_WITH_CALL_SITE_ID(200, meth_jl_System_doArrayCopy(teavm_local_1, teavm_local_2, teavm_local_3, teavm_local_4, teavm_local_5));
                                        goto teavm_label_3;
                                    teavm_label_5:;
                                        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                                        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                                        TEAVM_WITH_CALL_SITE_ID(201, meth_jl_System_doArrayCopy(teavm_local_1, teavm_local_2, teavm_local_3, teavm_local_4, teavm_local_6));
                                        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(202, meth_otr_Allocator_allocate(&jl_ArrayStoreException_Cls));
                                        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
                                        teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(203, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                                        teavm_gc_writeBarrier(teavm_local_1);
                                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_9;
                                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                                        teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(204, meth_otr_ExceptionHandling_fillStackTrace());
                                        teavm_gc_writeBarrier(teavm_local_1);
                                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_9;
                                        TEAVM_WITH_CALL_SITE_ID(205, meth_otr_ExceptionHandling_throwException(teavm_local_1));
                                        TEAVM_UNREACHABLE
                                    }
                                }
                                if ((!((!teavm_primitiveKind((TeaVM_Class*) TEAVM_FIELD(teavm_local_7, cls_jl_Class, fld_classInfo))) ? INT32_C(0) : INT32_C(1)))) {
                                    goto teavm_label_2;
                                }
                                TEAVM_GC_ROOT(INT32_C(0), teavm_local_8);
                                TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                                if (((!teavm_primitiveKind((TeaVM_Class*) TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(206, teavm_nullCheck(teavm_local_8)), cls_jl_Class, fld_classInfo))) ? INT32_C(0) : INT32_C(1))) {
                                    goto teavm_label_4;
                                } else {
                                    goto teavm_label_2;
                                }
                            }
                            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                            teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(207, meth_otr_Allocator_allocate(&jl_ArrayStoreException_Cls));
                            TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
                            teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(208, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                            teavm_gc_writeBarrier(teavm_local_1);
                            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_9;
                            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                            teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(209, meth_otr_ExceptionHandling_fillStackTrace());
                            teavm_gc_writeBarrier(teavm_local_1);
                            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_9;
                            TEAVM_WITH_CALL_SITE_ID(210, meth_otr_ExceptionHandling_throwException(teavm_local_1));
                            TEAVM_UNREACHABLE
                        }
                    teavm_label_4:;
                        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                        TEAVM_WITH_CALL_SITE_ID(211, meth_jl_System_doArrayCopy(teavm_local_1, teavm_local_2, teavm_local_3, teavm_local_4, teavm_local_5));
                    teavm_label_3:;
                        TEAVM_RELEASE_STACK;
                        return;
                    teavm_label_2:;
                        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
                        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(212, meth_otr_Allocator_allocate(&jl_ArrayStoreException_Cls));
                        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
                        teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(213, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                        teavm_gc_writeBarrier(teavm_local_1);
                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_9;
                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                        teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(214, meth_otr_ExceptionHandling_fillStackTrace());
                        teavm_gc_writeBarrier(teavm_local_1);
                        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_9;
                        TEAVM_WITH_CALL_SITE_ID(215, meth_otr_ExceptionHandling_throwException(teavm_local_1));
                        TEAVM_UNREACHABLE
                    } else {
                        goto teavm_label_1;
                    }
                }
                TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(216, meth_otr_Allocator_allocate(&jl_IllegalArgumentException_Cls));
                TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
                teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(217, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
                teavm_gc_writeBarrier(teavm_local_1);
                TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_9;
                TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
                TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
                teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(218, meth_otr_ExceptionHandling_fillStackTrace());
                teavm_gc_writeBarrier(teavm_local_1);
                TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_9;
                TEAVM_WITH_CALL_SITE_ID(219, meth_otr_ExceptionHandling_throwException(teavm_local_1));
                TEAVM_UNREACHABLE
            }
            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
            teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(220, meth_otr_Allocator_allocate(&jl_IllegalArgumentException_Cls));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
            teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(221, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
            teavm_gc_writeBarrier(teavm_local_1);
            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_9;
            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
            teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(222, meth_otr_ExceptionHandling_fillStackTrace());
            teavm_gc_writeBarrier(teavm_local_1);
            TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_9;
            TEAVM_WITH_CALL_SITE_ID(223, meth_otr_ExceptionHandling_throwException(teavm_local_1));
            TEAVM_UNREACHABLE
        }
    teavm_label_1:;
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(224, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
        teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(225, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
        teavm_gc_writeBarrier(teavm_local_1);
        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_9;
        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
        teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(226, meth_otr_ExceptionHandling_fillStackTrace());
        teavm_gc_writeBarrier(teavm_local_1);
        TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_9;
        TEAVM_WITH_CALL_SITE_ID(227, meth_otr_ExceptionHandling_throwException(teavm_local_1));
        TEAVM_UNREACHABLE
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(228, meth_otr_Allocator_allocate(&jl_NullPointerException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_3);
    teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(229, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_3);
    TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_suppressed) = teavm_local_9;
    TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(230, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_local_3);
    TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_stackTrace) = teavm_local_9;
    TEAVM_FIELD(teavm_local_3, cls_jl_Throwable, fld_message) = TEAVM_GET_STRING(11);
    TEAVM_WITH_CALL_SITE_ID(231, meth_otr_ExceptionHandling_throwException(teavm_local_3));
    TEAVM_UNREACHABLE
}
void meth_jl_System_fastArraycopy(void* teavm_local_1, int32_t teavm_local_2, void* teavm_local_3, int32_t teavm_local_4, int32_t teavm_local_5) {
    TeaVM_Array* teavm_local_6;
    TEAVM_ALLOC_STACK(INT32_C(1));
    if (((teavm_local_2 >= INT32_C(0)) && ((teavm_local_4 >= INT32_C(0)) && ((teavm_local_5 >= INT32_C(0)) && (((teavm_local_2 + teavm_local_5) <= TEAVM_FIELD(teavm_local_1, TeaVM_Array, size)) && ((teavm_local_4 + teavm_local_5) <= TEAVM_FIELD(teavm_local_3, TeaVM_Array, size))))))) {
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_WITH_CALL_SITE_ID(232, meth_jl_System_doArrayCopy(teavm_local_1, teavm_local_2, teavm_local_3, teavm_local_4, teavm_local_5));
        TEAVM_RELEASE_STACK;
        return;
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(233, meth_otr_Allocator_allocate(&jl_IndexOutOfBoundsException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(234, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_6;
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(235, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_6;
    TEAVM_WITH_CALL_SITE_ID(236, meth_otr_ExceptionHandling_throwException(teavm_local_1));
    TEAVM_UNREACHABLE
}
void meth_jl_System_doArrayCopy(void* teavm_local_1, int32_t teavm_local_2, void* teavm_local_3, int32_t teavm_local_4, int32_t teavm_local_5) {
    meth_jl_System_doArrayCopyLowLevel(teavm_local_1, teavm_local_2, teavm_local_3, teavm_local_4, teavm_local_5);
}
void meth_jl_System_doArrayCopyLowLevel(void* teavm_local_1, int32_t teavm_local_2, void* teavm_local_3, int32_t teavm_local_4, int32_t teavm_local_5) {
    void* teavm_local_6;
    int32_t teavm_local_7;
    int32_t teavm_local_8;
    teavm_local_6 = TEAVM_FIELD(meth_otr_RuntimeClass_getClass(teavm_local_1), TeaVM_Class, itemType);
    teavm_local_7 = TEAVM_FIELD(teavm_local_6, TeaVM_Class, size);
    if ((!meth_otr_RuntimeClass_isPrimitive(teavm_local_6))) {
        teavm_local_7 = sizeof(void*);
        teavm_gc_writeBarrier(teavm_local_3);
    }
    teavm_local_8 = ((int32_t) (intptr_t) TEAVM_ALIGN(TEAVM_ADDRESS_ADD(((void*) (intptr_t) INT32_C(0)), INT32_C(1) * sizeof(TeaVM_Array)), teavm_local_7));
    memmove(TEAVM_ADDRESS_ADD(TEAVM_ADDRESS_ADD(teavm_local_3, teavm_local_8), (teavm_local_7 * teavm_local_4)), TEAVM_ADDRESS_ADD(TEAVM_ADDRESS_ADD(teavm_local_1, teavm_local_8), (teavm_local_7 * teavm_local_2)), (teavm_local_5 * teavm_local_7));
}
int64_t meth_jl_System_currentTimeMillis() {
    return meth_jl_System_currentTimeMillisLowLevel();
}
int64_t meth_jl_System_currentTimeMillisLowLevel() {
    int64_t teavm_local_1;
    TEAVM_ALLOC_STACK(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(237, teavm_currentTimeMillis());
    TEAVM_RELEASE_STACK;
    return teavm_local_1;
}
int32_t supertypeof_jl_System(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 113 || tag >= 115) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_System_VT jl_System_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_System), sizeof(void*)),
            .flags = 0,
            .tag = 113,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jl_System,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static void** teavm_gc_localStaticRoots_jl_System_Cls[1] = {
(void**) &sfld_jl_System_outCache
};
void sysinitclass_jl_System() {
sfld_jl_System_outCache = NULL;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_jl_System_Cls, 1);
}
