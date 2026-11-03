#pragma once
#include "../../../../runtime.h"
#include "Fiber@dFiberRunner.h"

extern void sysinitclass_otr_Fiber_FiberRunner();
extern int32_t supertypeof_otr_Fiber_FiberRunner(TeaVM_Class*, TeaVM_Class*);
typedef struct otr_Fiber_FiberRunner_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} otr_Fiber_FiberRunner_VT;
extern TeaVM_Class otr_Fiber_FiberRunner_Cls;
