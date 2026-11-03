#pragma once
#include "../../../runtime.h"
#include "AutoCloseable.h"

extern void sysinitclass_jl_AutoCloseable();
extern int32_t supertypeof_jl_AutoCloseable(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_AutoCloseable_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} jl_AutoCloseable_VT;
extern TeaVM_Class jl_AutoCloseable_Cls;
