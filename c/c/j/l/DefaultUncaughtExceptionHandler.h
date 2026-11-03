#pragma once
#include "../../../runtime.h"
#include "Object.h"
#include "DefaultUncaughtExceptionHandler.h"

extern void sysinitclass_jl_DefaultUncaughtExceptionHandler();
typedef struct cls_jl_DefaultUncaughtExceptionHandler {
    struct TeaVM_Object parent;
} cls_jl_DefaultUncaughtExceptionHandler;
extern int32_t supertypeof_jl_DefaultUncaughtExceptionHandler(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_DefaultUncaughtExceptionHandler_VT {
    jl_Object_VT parent;
} jl_DefaultUncaughtExceptionHandler_VT;
extern jl_DefaultUncaughtExceptionHandler_VT jl_DefaultUncaughtExceptionHandler_Cls;
