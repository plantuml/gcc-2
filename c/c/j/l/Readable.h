#pragma once
#include "../../../runtime.h"
#include "Readable.h"

extern void sysinitclass_jl_Readable();
extern int32_t supertypeof_jl_Readable(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Readable_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} jl_Readable_VT;
extern TeaVM_Class jl_Readable_Cls;
