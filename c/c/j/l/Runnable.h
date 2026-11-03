#pragma once
#include "../../../runtime.h"
#include "Runnable.h"

extern void sysinitclass_jl_Runnable();
extern int32_t supertypeof_jl_Runnable(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Runnable_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} jl_Runnable_VT;
extern TeaVM_Class jl_Runnable_Cls;
