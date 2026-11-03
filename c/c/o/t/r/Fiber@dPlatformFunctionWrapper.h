#pragma once
#include "../../../../runtime.h"
#include "../../../j/l/Object.h"
#include "Fiber@dPlatformFunctionWrapper.h"

extern void sysinitclass_otr_Fiber_PlatformFunctionWrapper();
typedef struct cls_otr_Fiber_PlatformFunctionWrapper {
    struct TeaVM_Object parent;
    void* fld_object;
} cls_otr_Fiber_PlatformFunctionWrapper;
extern int32_t supertypeof_otr_Fiber_PlatformFunctionWrapper(TeaVM_Class*, TeaVM_Class*);
typedef struct otr_Fiber_PlatformFunctionWrapper_VT {
    jl_Object_VT parent;
} otr_Fiber_PlatformFunctionWrapper_VT;
extern otr_Fiber_PlatformFunctionWrapper_VT otr_Fiber_PlatformFunctionWrapper_Cls;
