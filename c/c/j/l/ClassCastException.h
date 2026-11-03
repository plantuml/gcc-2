#pragma once
#include "../../../runtime.h"
#include "RuntimeException.h"
#include "ClassCastException.h"

extern void sysinitclass_jl_ClassCastException();
typedef struct cls_jl_ClassCastException {
    struct cls_jl_RuntimeException parent;
} cls_jl_ClassCastException;
extern void meth_jl_ClassCastException__init_(void*);
extern int32_t supertypeof_jl_ClassCastException(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_ClassCastException_VT {
    jl_RuntimeException_VT parent;
} jl_ClassCastException_VT;
extern jl_ClassCastException_VT jl_ClassCastException_Cls;
