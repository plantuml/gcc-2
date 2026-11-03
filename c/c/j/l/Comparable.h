#pragma once
#include "../../../runtime.h"
#include "Comparable.h"

extern void sysinitclass_jl_Comparable();
extern int32_t supertypeof_jl_Comparable(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Comparable_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} jl_Comparable_VT;
extern TeaVM_Class jl_Comparable_Cls;
