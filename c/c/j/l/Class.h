#pragma once
#include "../../../runtime.h"
#include "Object.h"
#include "Class.h"

extern void sysinitclass_jl_Class();
typedef struct cls_jl_Class {
    struct TeaVM_Object parent;
    int32_t fld_flags;
    void* fld_classInfo;
    void* fld_name;
} cls_jl_Class;
extern void* meth_jl_Class_createClass(void*);
extern void* meth_jl_Class_getName(void*);
extern void* meth_jl_Class_getComponentType(void*);
extern int32_t supertypeof_jl_Class(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Class_VT {
    jl_Object_VT parent;
} jl_Class_VT;
extern jl_Class_VT jl_Class_Cls;
