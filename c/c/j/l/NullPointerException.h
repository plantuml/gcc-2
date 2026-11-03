#pragma once
#include "../../../runtime.h"
#include "RuntimeException.h"
#include "NullPointerException.h"

extern void sysinitclass_jl_NullPointerException();
typedef struct cls_jl_NullPointerException {
    struct cls_jl_RuntimeException parent;
} cls_jl_NullPointerException;
extern void meth_jl_NullPointerException__init_(void*);
extern int32_t supertypeof_jl_NullPointerException(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_NullPointerException_VT {
    jl_RuntimeException_VT parent;
} jl_NullPointerException_VT;
extern jl_NullPointerException_VT jl_NullPointerException_Cls;
