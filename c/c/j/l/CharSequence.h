#pragma once
#include "../../../runtime.h"
#include "CharSequence.h"

extern void sysinitclass_jl_CharSequence();
extern int32_t supertypeof_jl_CharSequence(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_CharSequence_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} jl_CharSequence_VT;
extern TeaVM_Class jl_CharSequence_Cls;
