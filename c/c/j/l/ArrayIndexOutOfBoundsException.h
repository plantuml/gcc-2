#pragma once
#include "../../../runtime.h"
#include "IndexOutOfBoundsException.h"
#include "ArrayIndexOutOfBoundsException.h"

extern void sysinitclass_jl_ArrayIndexOutOfBoundsException();
typedef struct cls_jl_ArrayIndexOutOfBoundsException {
    struct cls_jl_IndexOutOfBoundsException parent;
} cls_jl_ArrayIndexOutOfBoundsException;
extern void meth_jl_ArrayIndexOutOfBoundsException__init_(void*);
extern int32_t supertypeof_jl_ArrayIndexOutOfBoundsException(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_ArrayIndexOutOfBoundsException_VT {
    jl_IndexOutOfBoundsException_VT parent;
} jl_ArrayIndexOutOfBoundsException_VT;
extern jl_ArrayIndexOutOfBoundsException_VT jl_ArrayIndexOutOfBoundsException_Cls;
