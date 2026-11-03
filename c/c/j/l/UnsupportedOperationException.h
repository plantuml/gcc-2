#pragma once
#include "../../../runtime.h"
#include "RuntimeException.h"
#include "UnsupportedOperationException.h"

extern void sysinitclass_jl_UnsupportedOperationException();
typedef struct cls_jl_UnsupportedOperationException {
    struct cls_jl_RuntimeException parent;
} cls_jl_UnsupportedOperationException;
extern int32_t supertypeof_jl_UnsupportedOperationException(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_UnsupportedOperationException_VT {
    jl_RuntimeException_VT parent;
} jl_UnsupportedOperationException_VT;
extern jl_UnsupportedOperationException_VT jl_UnsupportedOperationException_Cls;
