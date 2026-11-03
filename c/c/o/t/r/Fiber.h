#pragma once
#include "../../../../runtime.h"
#include "../../../j/l/Object.h"
#include "Fiber.h"

extern void sysinitclass_otr_Fiber();
typedef struct cls_otr_Fiber {
    struct TeaVM_Object parent;
    TeaVM_Array* fld_intValues;
    int32_t fld_intTop;
    TeaVM_Array* fld_longValues;
    int32_t fld_longTop;
    TeaVM_Array* fld_floatValues;
    int32_t fld_floatTop;
    TeaVM_Array* fld_doubleValues;
    int32_t fld_doubleTop;
    TeaVM_Array* fld_objectValues;
    int32_t fld_objectTop;
    int32_t fld_state;
    void* fld_runner;
    int8_t fld_isPendingResume;
    int8_t fld_daemon;
} cls_otr_Fiber;
extern int32_t sfld_otr_Fiber_userThreadCount;
extern void* sfld_otr_Fiber_current;
extern void meth_otr_Fiber_push(void*, int32_t);
extern void meth_otr_Fiber_push_0(void*, int64_t);
extern void meth_otr_Fiber_push_1(void*, float);
extern void meth_otr_Fiber_push_2(void*, double);
extern void meth_otr_Fiber_push_3(void*, void*);
extern int32_t meth_otr_Fiber_popInt(void*);
extern int64_t meth_otr_Fiber_popLong(void*);
extern float meth_otr_Fiber_popFloat(void*);
extern double meth_otr_Fiber_popDouble(void*);
extern void* meth_otr_Fiber_popObject(void*);
extern void* meth_otr_Fiber_popPlatformObject(void*);
extern void* meth_otr_Fiber_popPlatformFunction(void*);
extern void* meth_otr_Fiber_popPlatformException(void*);
extern void* meth_otr_Fiber_current();
extern int32_t meth_otr_Fiber_isSuspending(void*);
extern int32_t meth_otr_Fiber_isResuming(void*);
extern void meth_otr_Fiber_startMain(TeaVM_Array*);
extern void meth_otr_Fiber_start(void*);
extern void meth_otr_Fiber_lambda_startMain_0(TeaVM_Array*);
extern void meth_otr_Fiber__clinit_();
extern int32_t supertypeof_otr_Fiber(TeaVM_Class*, TeaVM_Class*);
typedef struct otr_Fiber_VT {
    jl_Object_VT parent;
} otr_Fiber_VT;
extern otr_Fiber_VT otr_Fiber_Cls;
