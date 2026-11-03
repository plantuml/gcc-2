#pragma once
#include "../../../runtime.h"
#include "Object.h"

extern void sysinitclass_jl_Object();
extern void meth_jl_Object__init_(void*);
extern void* meth_jl_Object_getClass(void*);
extern void* meth_jl_Object_clone(void*);
extern void* meth_jl_Object_cloneLowLevel(void*);
extern int32_t supertypeof_jl_Object(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Object_VT {
    TeaVM_Class parent;
    int32_t (*virt_hashCode)(void*); // 0
    void* (*virt_clone)(void*); // 1
    int32_t (*virt_equals)(void*, void*); // 2
    void* (*virt_getClass)(void*); // 3
} jl_Object_VT;
extern jl_Object_VT jl_Object_Cls;
