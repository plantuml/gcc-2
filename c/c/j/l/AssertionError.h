#pragma once
#include "../../../runtime.h"
#include "Error.h"
#include "AssertionError.h"

extern void sysinitclass_jl_AssertionError();
typedef struct cls_jl_AssertionError {
    struct cls_jl_Error parent;
} cls_jl_AssertionError;
extern int32_t supertypeof_jl_AssertionError(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_AssertionError_VT {
    jl_Error_VT parent;
} jl_AssertionError_VT;
extern jl_AssertionError_VT jl_AssertionError_Cls;
