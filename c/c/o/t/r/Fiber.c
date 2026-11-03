#include "Fiber.h"
#include "../../../j/l/Object.h"
#include "../../../../a/p/int.h"
#include "Allocator.h"
#include "../../../j/u/Arrays.h"
#include "../../../../a/p/long.h"
#include "../../../../a/p/float.h"
#include "../../../../a/p/double.h"
#include "../../../../arrayclass.h"
#include "Fiber@dPlatformObjectWrapper.h"
#include "Fiber@dPlatformFunctionWrapper.h"
#include "Fiber@dPlatformExceptionWrapper.h"
#include "Fiber@dstartMain@dlambda@d_38_0.h"
#include "EventQueue.h"
#include "../../../Hello.h"
#include "../../../../strings.h"

int32_t sfld_otr_Fiber_userThreadCount;
void* sfld_otr_Fiber_current;
void meth_otr_Fiber_push(void* teavm_this_, int32_t teavm_local_1) {
    TeaVM_Array* teavm_local_2;
    TeaVM_Array* teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    TEAVM_ALLOC_STACK(INT32_C(1));
    teavm_local_2 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_intValues);
    if ((teavm_local_2 == NULL)) {
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(106, meth_otr_Allocator_allocateArray(&Arr_I_Cls, INT32_C(4)));
        teavm_gc_writeBarrier(teavm_this_);
        TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_intValues) = teavm_local_2;
    } else {
        teavm_local_3 = teavm_local_2;
        teavm_local_4 = (TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_intTop) + INT32_C(1));
        teavm_local_5 = TEAVM_ARRAY_LENGTH(teavm_local_3);
        if ((teavm_local_4 == teavm_local_5)) {
            teavm_local_4 = ((teavm_local_5 * INT32_C(3)) / INT32_C(2));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
            teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(107, meth_ju_Arrays_copyOf(teavm_local_2, teavm_local_4));
            teavm_gc_writeBarrier(teavm_this_);
            TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_intValues) = teavm_local_2;
        }
    }
    teavm_local_2 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_intValues);
    teavm_local_5 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_intTop);
    TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_intTop) = (teavm_local_5 + INT32_C(1));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(108, teavm_nullCheck(teavm_local_2));
    TEAVM_ARRAY_AT(teavm_local_2, int32_t, TEAVM_WITH_CALL_SITE_ID(109, teavm_checkBounds(teavm_local_5, teavm_local_2))) = teavm_local_1;
    TEAVM_RELEASE_STACK;
}
void meth_otr_Fiber_push_0(void* teavm_this_, int64_t teavm_local_1) {
    TeaVM_Array* teavm_local_2;
    TeaVM_Array* teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    TEAVM_ALLOC_STACK(INT32_C(1));
    teavm_local_2 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_longValues);
    if ((teavm_local_2 == NULL)) {
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(110, meth_otr_Allocator_allocateArray(&Arr_J_Cls, INT32_C(4)));
        teavm_gc_writeBarrier(teavm_this_);
        TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_longValues) = teavm_local_2;
    } else {
        teavm_local_3 = teavm_local_2;
        teavm_local_4 = (TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_longTop) + INT32_C(1));
        teavm_local_5 = TEAVM_ARRAY_LENGTH(teavm_local_3);
        if ((teavm_local_4 == teavm_local_5)) {
            teavm_local_4 = ((teavm_local_5 * INT32_C(3)) / INT32_C(2));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
            teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(111, meth_ju_Arrays_copyOf_0(teavm_local_2, teavm_local_4));
            teavm_gc_writeBarrier(teavm_this_);
            TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_longValues) = teavm_local_2;
        }
    }
    teavm_local_2 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_longValues);
    teavm_local_5 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_longTop);
    TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_longTop) = (teavm_local_5 + INT32_C(1));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(112, teavm_nullCheck(teavm_local_2));
    TEAVM_ARRAY_AT(teavm_local_2, int64_t, TEAVM_WITH_CALL_SITE_ID(113, teavm_checkBounds(teavm_local_5, teavm_local_2))) = teavm_local_1;
    TEAVM_RELEASE_STACK;
}
void meth_otr_Fiber_push_1(void* teavm_this_, float teavm_local_1) {
    TeaVM_Array* teavm_local_2;
    TeaVM_Array* teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    TEAVM_ALLOC_STACK(INT32_C(1));
    teavm_local_2 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_floatValues);
    if ((teavm_local_2 == NULL)) {
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(114, meth_otr_Allocator_allocateArray(&Arr_F_Cls, INT32_C(4)));
        teavm_gc_writeBarrier(teavm_this_);
        TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_floatValues) = teavm_local_2;
    } else {
        teavm_local_3 = teavm_local_2;
        teavm_local_4 = (TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_floatTop) + INT32_C(1));
        teavm_local_5 = TEAVM_ARRAY_LENGTH(teavm_local_3);
        if ((teavm_local_4 == teavm_local_5)) {
            teavm_local_4 = ((teavm_local_5 * INT32_C(3)) / INT32_C(2));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
            teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(115, meth_ju_Arrays_copyOf_1(teavm_local_2, teavm_local_4));
            teavm_gc_writeBarrier(teavm_this_);
            TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_floatValues) = teavm_local_2;
        }
    }
    teavm_local_2 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_floatValues);
    teavm_local_5 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_floatTop);
    TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_floatTop) = (teavm_local_5 + INT32_C(1));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(116, teavm_nullCheck(teavm_local_2));
    TEAVM_ARRAY_AT(teavm_local_2, float, TEAVM_WITH_CALL_SITE_ID(117, teavm_checkBounds(teavm_local_5, teavm_local_2))) = teavm_local_1;
    TEAVM_RELEASE_STACK;
}
void meth_otr_Fiber_push_2(void* teavm_this_, double teavm_local_1) {
    TeaVM_Array* teavm_local_2;
    TeaVM_Array* teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    TEAVM_ALLOC_STACK(INT32_C(1));
    teavm_local_2 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_doubleValues);
    if ((teavm_local_2 == NULL)) {
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(118, meth_otr_Allocator_allocateArray(&Arr_D_Cls, INT32_C(4)));
        teavm_gc_writeBarrier(teavm_this_);
        TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_doubleValues) = teavm_local_2;
    } else {
        teavm_local_3 = teavm_local_2;
        teavm_local_4 = (TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_doubleTop) + INT32_C(1));
        teavm_local_5 = TEAVM_ARRAY_LENGTH(teavm_local_3);
        if ((teavm_local_4 == teavm_local_5)) {
            teavm_local_4 = ((teavm_local_5 * INT32_C(3)) / INT32_C(2));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
            teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(119, meth_ju_Arrays_copyOf_2(teavm_local_2, teavm_local_4));
            teavm_gc_writeBarrier(teavm_this_);
            TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_doubleValues) = teavm_local_2;
        }
    }
    teavm_local_2 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_doubleValues);
    teavm_local_5 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_doubleTop);
    TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_doubleTop) = (teavm_local_5 + INT32_C(1));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(120, teavm_nullCheck(teavm_local_2));
    TEAVM_ARRAY_AT(teavm_local_2, double, TEAVM_WITH_CALL_SITE_ID(121, teavm_checkBounds(teavm_local_5, teavm_local_2))) = teavm_local_1;
    TEAVM_RELEASE_STACK;
}
void meth_otr_Fiber_push_3(void* teavm_this_, void* teavm_local_1) {
    TeaVM_Array* teavm_local_2;
    TeaVM_Array* teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    TEAVM_ALLOC_STACK(INT32_C(1));
    teavm_local_2 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_objectValues);
    if ((teavm_local_2 == NULL)) {
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(122, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Object_Cls), INT32_C(4)));
        teavm_gc_writeBarrier(teavm_this_);
        TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_objectValues) = teavm_local_2;
    } else {
        teavm_local_3 = teavm_local_2;
        teavm_local_4 = (TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_objectTop) + INT32_C(1));
        teavm_local_5 = TEAVM_ARRAY_LENGTH(teavm_local_3);
        if ((teavm_local_4 == teavm_local_5)) {
            teavm_local_4 = ((teavm_local_5 * INT32_C(3)) / INT32_C(2));
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
            teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(123, meth_ju_Arrays_copyOf_3(teavm_local_2, teavm_local_4));
            teavm_gc_writeBarrier(teavm_this_);
            TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_objectValues) = teavm_local_2;
        }
    }
    teavm_local_2 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_objectValues);
    teavm_local_5 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_objectTop);
    TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_objectTop) = (teavm_local_5 + INT32_C(1));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(124, teavm_nullCheck(teavm_local_2));
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(125, teavm_checkBounds(teavm_local_5, teavm_local_2));
    teavm_gc_writeBarrier(teavm_local_2);
    TEAVM_ARRAY_AT(teavm_local_2, void*, teavm_local_4) = teavm_local_1;
    TEAVM_RELEASE_STACK;
}
int32_t meth_otr_Fiber_popInt(void* teavm_this_) {
    TeaVM_Array* teavm_local_1;
    int32_t teavm_local_2;
    teavm_local_1 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_intValues);
    teavm_local_2 = (TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_intTop) - INT32_C(1));
    TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_intTop) = teavm_local_2;
    return TEAVM_ARRAY_AT(teavm_local_1, int32_t, teavm_checkBounds(teavm_local_2, teavm_local_1));
}
int64_t meth_otr_Fiber_popLong(void* teavm_this_) {
    TeaVM_Array* teavm_local_1;
    int32_t teavm_local_2;
    teavm_local_1 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_longValues);
    teavm_local_2 = (TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_longTop) - INT32_C(1));
    TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_longTop) = teavm_local_2;
    return TEAVM_ARRAY_AT(teavm_local_1, int64_t, teavm_checkBounds(teavm_local_2, teavm_local_1));
}
float meth_otr_Fiber_popFloat(void* teavm_this_) {
    TeaVM_Array* teavm_local_1;
    int32_t teavm_local_2;
    teavm_local_1 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_floatValues);
    teavm_local_2 = (TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_floatTop) - INT32_C(1));
    TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_floatTop) = teavm_local_2;
    return TEAVM_ARRAY_AT(teavm_local_1, float, teavm_checkBounds(teavm_local_2, teavm_local_1));
}
double meth_otr_Fiber_popDouble(void* teavm_this_) {
    TeaVM_Array* teavm_local_1;
    int32_t teavm_local_2;
    teavm_local_1 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_doubleValues);
    teavm_local_2 = (TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_doubleTop) - INT32_C(1));
    TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_doubleTop) = teavm_local_2;
    return TEAVM_ARRAY_AT(teavm_local_1, double, teavm_checkBounds(teavm_local_2, teavm_local_1));
}
void* meth_otr_Fiber_popObject(void* teavm_this_) {
    TeaVM_Array* teavm_local_1;
    int32_t teavm_local_2;
    void* teavm_local_3;
    void* teavm_local_4;
    teavm_local_1 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_objectValues);
    teavm_local_2 = (TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_objectTop) - INT32_C(1));
    TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_objectTop) = teavm_local_2;
    teavm_local_3 = TEAVM_ARRAY_AT(teavm_local_1, void*, teavm_checkBounds(teavm_local_2, teavm_local_1));
    teavm_local_4 = NULL;
    TEAVM_ARRAY_AT(teavm_local_1, void*, teavm_checkBounds(teavm_local_2, teavm_local_1)) = teavm_local_4;
    return teavm_local_3;
}
void* meth_otr_Fiber_popPlatformObject(void* teavm_this_) {
    void* teavm_local_1;
    TEAVM_ALLOC_STACK(INT32_C(1));
    teavm_local_1 = meth_otr_Fiber_popObject(teavm_this_);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_1 = TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(126, teavm_nullCheck(teavm_local_1)), cls_otr_Fiber_PlatformObjectWrapper, fld_object);
    TEAVM_RELEASE_STACK;
    return teavm_local_1;
}
void* meth_otr_Fiber_popPlatformFunction(void* teavm_this_) {
    void* teavm_local_1;
    TEAVM_ALLOC_STACK(INT32_C(1));
    teavm_local_1 = meth_otr_Fiber_popObject(teavm_this_);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_1 = TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(127, teavm_nullCheck(teavm_local_1)), cls_otr_Fiber_PlatformFunctionWrapper, fld_object);
    TEAVM_RELEASE_STACK;
    return teavm_local_1;
}
void* meth_otr_Fiber_popPlatformException(void* teavm_this_) {
    void* teavm_local_1;
    TEAVM_ALLOC_STACK(INT32_C(1));
    teavm_local_1 = meth_otr_Fiber_popObject(teavm_this_);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_1 = TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(128, teavm_nullCheck(teavm_local_1)), cls_otr_Fiber_PlatformExceptionWrapper, fld_object);
    TEAVM_RELEASE_STACK;
    return teavm_local_1;
}
void* meth_otr_Fiber_current() {
    return sfld_otr_Fiber_current;
}
int32_t meth_otr_Fiber_isSuspending(void* teavm_this_) {
    return ((TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_state) != INT32_C(1)) ? INT32_C(0) : INT32_C(1));
}
int32_t meth_otr_Fiber_isResuming(void* teavm_this_) {
    return ((TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_state) != INT32_C(2)) ? INT32_C(0) : INT32_C(1));
}
void meth_otr_Fiber_startMain(TeaVM_Array* teavm_local_1) {
    void* teavm_local_2;
    void* teavm_local_3;
    TEAVM_ALLOC_STACK(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(129, meth_otr_Allocator_allocate(&otr_Fiber_startMain_lambda__38_0_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    TEAVM_WITH_CALL_SITE_ID(130, meth_otr_Fiber_startMain_lambda__38_0__init_(teavm_local_2, teavm_local_1));
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(131, meth_otr_Allocator_allocate(&otr_Fiber_Cls));
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    TEAVM_WITH_CALL_SITE_ID(132, meth_jl_Object__init_(teavm_local_3));
    teavm_gc_writeBarrier(teavm_local_3);
    TEAVM_FIELD(teavm_local_3, cls_otr_Fiber, fld_runner) = teavm_local_2;
    TEAVM_FIELD(teavm_local_3, cls_otr_Fiber, fld_daemon) = INT32_C(0);
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_WITH_CALL_SITE_ID(133, meth_otr_Fiber_start(teavm_local_3));
    TEAVM_RELEASE_STACK;
}
void meth_otr_Fiber_start(void* teavm_this_) {
    void* teavm_local_1;
    void* teavm_local_2;
    int32_t teavm_local_3;
    TEAVM_ALLOC_STACK(INT32_C(2));
    teavm_local_1 = sfld_otr_Fiber_current;
    sfld_otr_Fiber_current = teavm_this_;
    while (1) {
        teavm_local_2 = TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_runner);
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_2);
        TEAVM_WITH_CALL_SITE_ID(134, meth_otr_Fiber_startMain_lambda__38_0_run(TEAVM_WITH_CALL_SITE_ID(135, teavm_nullCheck(teavm_local_2))));
        if ((!TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_isPendingResume))) {
            goto teavm_label_1;
        }
        TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_isPendingResume) = INT32_C(0);
        TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_state) = INT32_C(2);
    }
teavm_label_1:;
    sfld_otr_Fiber_current = teavm_local_1;
    if (((!meth_otr_Fiber_isSuspending(teavm_this_)) && (!TEAVM_FIELD(teavm_this_, cls_otr_Fiber, fld_daemon)))) {
        teavm_local_3 = (sfld_otr_Fiber_userThreadCount - INT32_C(1));
        sfld_otr_Fiber_userThreadCount = teavm_local_3;
        if ((!teavm_local_3)) {
            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
            TEAVM_WITH_CALL_SITE_ID(136, meth_otr_EventQueue_stop());
        }
    }
    TEAVM_RELEASE_STACK;
}
void meth_otr_Fiber_lambda_startMain_0(TeaVM_Array* teavm_local_1) {
    TEAVM_ALLOC_STACK(INT32_C(0));
    TEAVM_WITH_CALL_SITE_ID(137, meth_Hello_main(teavm_local_1));
    TEAVM_RELEASE_STACK;
}
void meth_otr_Fiber__clinit_() {
    sfld_otr_Fiber_userThreadCount = INT32_C(1);
}
int32_t supertypeof_otr_Fiber(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 105 || tag >= 107) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_otr_Fiber_Cls[7];
alignas(8) otr_Fiber_VT otr_Fiber_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otr_Fiber), sizeof(void*)),
            .flags = 0,
            .tag = 105,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_otr_Fiber,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_otr_Fiber_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static void** teavm_gc_localStaticRoots_otr_Fiber_Cls[1] = {
(void**) &sfld_otr_Fiber_current
};
static int16_t teavm_classLayouts_otr_Fiber_Cls[7] = {
INT16_C(6), (int16_t) offsetof(cls_otr_Fiber, fld_intValues), (int16_t) offsetof(cls_otr_Fiber, fld_longValues), (int16_t) offsetof(cls_otr_Fiber, fld_floatValues), (int16_t) offsetof(cls_otr_Fiber, fld_doubleValues), (int16_t) offsetof(cls_otr_Fiber, fld_objectValues), (int16_t) offsetof(cls_otr_Fiber, fld_runner)
};
void sysinitclass_otr_Fiber() {
sfld_otr_Fiber_userThreadCount = INT32_C(0);
sfld_otr_Fiber_current = NULL;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_otr_Fiber_Cls, 1);
}
