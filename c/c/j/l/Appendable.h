#pragma once
#include "../../../runtime.h"
#include "Appendable.h"

extern void sysinitclass_jl_Appendable();
extern int32_t supertypeof_jl_Appendable(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Appendable_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} jl_Appendable_VT;
extern TeaVM_Class jl_Appendable_Cls;
