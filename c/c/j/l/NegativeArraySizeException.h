#pragma once
#include "../../../runtime.h"
#include "RuntimeException.h"
#include "NegativeArraySizeException.h"

extern void sysinitclass_jl_NegativeArraySizeException();
typedef struct cls_jl_NegativeArraySizeException {
    struct cls_jl_RuntimeException parent;
} cls_jl_NegativeArraySizeException;
extern int32_t supertypeof_jl_NegativeArraySizeException(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_NegativeArraySizeException_VT {
    jl_RuntimeException_VT parent;
} jl_NegativeArraySizeException_VT;
extern jl_NegativeArraySizeException_VT jl_NegativeArraySizeException_Cls;
