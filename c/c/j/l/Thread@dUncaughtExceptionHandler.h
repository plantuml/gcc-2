#pragma once
#include "../../../runtime.h"
#include "Thread@dUncaughtExceptionHandler.h"

extern void sysinitclass_jl_Thread_UncaughtExceptionHandler();
extern int32_t supertypeof_jl_Thread_UncaughtExceptionHandler(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Thread_UncaughtExceptionHandler_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} jl_Thread_UncaughtExceptionHandler_VT;
extern TeaVM_Class jl_Thread_UncaughtExceptionHandler_Cls;
