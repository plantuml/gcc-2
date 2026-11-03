#pragma once
#include "../../../runtime.h"
#include "Throwable.h"
#include "Exception.h"

extern void sysinitclass_jl_Exception();
typedef struct cls_jl_Exception {
    struct cls_jl_Throwable parent;
} cls_jl_Exception;
extern void meth_jl_Exception__init_(void*, void*);
extern int32_t supertypeof_jl_Exception(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Exception_VT {
    jl_Throwable_VT parent;
} jl_Exception_VT;
extern jl_Exception_VT jl_Exception_Cls;
