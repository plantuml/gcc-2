#pragma once
#include "../../../../runtime.h"
#include "../../../j/l/Object.h"
#include "Fiber@dPlatformExceptionWrapper.h"

extern void sysinitclass_otr_Fiber_PlatformExceptionWrapper();
typedef struct cls_otr_Fiber_PlatformExceptionWrapper {
    struct TeaVM_Object parent;
    void* fld_object;
} cls_otr_Fiber_PlatformExceptionWrapper;
extern int32_t supertypeof_otr_Fiber_PlatformExceptionWrapper(TeaVM_Class*, TeaVM_Class*);
typedef struct otr_Fiber_PlatformExceptionWrapper_VT {
    jl_Object_VT parent;
} otr_Fiber_PlatformExceptionWrapper_VT;
extern otr_Fiber_PlatformExceptionWrapper_VT otr_Fiber_PlatformExceptionWrapper_Cls;
