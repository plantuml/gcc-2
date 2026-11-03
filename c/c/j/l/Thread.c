#include "Thread.h"
#include "Object.h"
#include "System.h"
#include "../../o/t/r/Allocator.h"
#include "../../../strings.h"
#include "DefaultUncaughtExceptionHandler.h"

void* sfld_jl_Thread_mainThread;
void* sfld_jl_Thread_currentThread;
int32_t sfld_jl_Thread_nextId;
int32_t sfld_jl_Thread_activeCount;
void* sfld_jl_Thread_defaultUncaughtExceptionHandler;
void meth_jl_Thread_setCurrentThread(void* teavm_local_1) {
    int64_t teavm_local_2;
    TEAVM_ALLOC_STACK(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_WITH_CALL_SITE_ID(171, teavm_initializeClass((TeaVM_Class*) &jl_Thread_Cls, &initclass_jl_Thread));
    if ((sfld_jl_Thread_currentThread != teavm_local_1)) {
        sfld_jl_Thread_currentThread = teavm_local_1;
    }
    teavm_local_1 = sfld_jl_Thread_currentThread;
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(172, meth_jl_System_currentTimeMillis());
    TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(173, teavm_nullCheck(teavm_local_1)), cls_jl_Thread, fld_timeSliceStart) = teavm_local_2;
    TEAVM_RELEASE_STACK;
}
void meth_jl_Thread__clinit_() {
    void* teavm_local_1;
    void* teavm_local_2;
    void* teavm_local_3;
    int32_t teavm_local_4;
    TEAVM_ALLOC_STACK(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(174, meth_otr_Allocator_allocate(&jl_Thread_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    TEAVM_WITH_CALL_SITE_ID(175, teavm_initializeClass((TeaVM_Class*) &jl_Thread_Cls, &initclass_jl_Thread));
    teavm_local_2 = NULL;
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(176, meth_otr_Allocator_allocate(&jl_Object_Cls));
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Thread, fld_finishedLock) = teavm_local_3;
    TEAVM_FIELD(teavm_local_1, cls_jl_Thread, fld_alive) = INT32_C(1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Thread, fld_name) = TEAVM_GET_STRING(10);
    TEAVM_FIELD(teavm_local_1, cls_jl_Thread, fld_target) = teavm_local_2;
    teavm_local_4 = sfld_jl_Thread_nextId;
    sfld_jl_Thread_nextId = (teavm_local_4 + INT32_C(1));
    TEAVM_FIELD(teavm_local_1, cls_jl_Thread, fld_id) = ((int64_t) teavm_local_4);
    sfld_jl_Thread_mainThread = teavm_local_1;
    sfld_jl_Thread_currentThread = teavm_local_1;
    sfld_jl_Thread_nextId = INT32_C(1);
    sfld_jl_Thread_activeCount = INT32_C(1);
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    sfld_jl_Thread_defaultUncaughtExceptionHandler = TEAVM_WITH_CALL_SITE_ID(177, meth_otr_Allocator_allocate(&jl_DefaultUncaughtExceptionHandler_Cls));
    TEAVM_RELEASE_STACK;
}
void initclass_jl_Thread() {
    TeaVM_Class* cls = (TeaVM_Class*) &jl_Thread_Cls;
    if (!(cls->flags & INT32_C(1))) {
        cls->flags |= INT32_C(1);
        meth_jl_Thread__clinit_();
    }
}
int32_t supertypeof_jl_Thread(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 111 || tag >= 113) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_jl_Thread_Cls[4];
alignas(8) jl_Thread_VT jl_Thread_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_Thread), sizeof(void*)),
            .flags = 0,
            .tag = 111,
            .modifiers = 1,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jl_Thread,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_jl_Thread_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static void** teavm_gc_localStaticRoots_jl_Thread_Cls[3] = {
(void**) &sfld_jl_Thread_mainThread, (void**) &sfld_jl_Thread_currentThread, (void**) &sfld_jl_Thread_defaultUncaughtExceptionHandler
};
static int16_t teavm_classLayouts_jl_Thread_Cls[4] = {
INT16_C(3), (int16_t) offsetof(cls_jl_Thread, fld_finishedLock), (int16_t) offsetof(cls_jl_Thread, fld_name), (int16_t) offsetof(cls_jl_Thread, fld_target)
};
void sysinitclass_jl_Thread() {
sfld_jl_Thread_mainThread = NULL;
sfld_jl_Thread_currentThread = NULL;
sfld_jl_Thread_nextId = INT32_C(0);
sfld_jl_Thread_activeCount = INT32_C(0);
sfld_jl_Thread_defaultUncaughtExceptionHandler = NULL;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_jl_Thread_Cls, 3);
}
