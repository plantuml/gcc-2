#pragma once
#include "../../../../runtime.h"
#include "../../../j/l/Object.h"
#include "Fiber@dstartMain@dlambda@d_38_0.h"

extern void sysinitclass_otr_Fiber_startMain_lambda__38_0();
typedef struct cls_otr_Fiber_startMain_lambda__38_0 {
    struct TeaVM_Object parent;
    TeaVM_Array* fld__0;
} cls_otr_Fiber_startMain_lambda__38_0;
extern void meth_otr_Fiber_startMain_lambda__38_0__init_(void*, TeaVM_Array*);
extern void meth_otr_Fiber_startMain_lambda__38_0_run(void*);
extern int32_t supertypeof_otr_Fiber_startMain_lambda__38_0(TeaVM_Class*, TeaVM_Class*);
typedef struct otr_Fiber_startMain_lambda__38_0_VT {
    jl_Object_VT parent;
    void (*virt_run)(void*); // 4
} otr_Fiber_startMain_lambda__38_0_VT;
extern otr_Fiber_startMain_lambda__38_0_VT otr_Fiber_startMain_lambda__38_0_Cls;
