#pragma once
#include "../../../../runtime.h"
#include "../../../j/l/Object.h"
#include "Fiber@dPlatformObjectWrapper.h"

extern void sysinitclass_otr_Fiber_PlatformObjectWrapper();
typedef struct cls_otr_Fiber_PlatformObjectWrapper {
    struct TeaVM_Object parent;
    void* fld_object;
} cls_otr_Fiber_PlatformObjectWrapper;
extern int32_t supertypeof_otr_Fiber_PlatformObjectWrapper(TeaVM_Class*, TeaVM_Class*);
typedef struct otr_Fiber_PlatformObjectWrapper_VT {
    jl_Object_VT parent;
} otr_Fiber_PlatformObjectWrapper_VT;
extern otr_Fiber_PlatformObjectWrapper_VT otr_Fiber_PlatformObjectWrapper_Cls;
