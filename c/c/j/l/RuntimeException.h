#pragma once
#include "../../../runtime.h"
#include "Exception.h"
#include "RuntimeException.h"

extern void sysinitclass_jl_RuntimeException();
typedef struct cls_jl_RuntimeException {
    struct cls_jl_Exception parent;
} cls_jl_RuntimeException;
extern int32_t supertypeof_jl_RuntimeException(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_RuntimeException_VT {
    jl_Exception_VT parent;
} jl_RuntimeException_VT;
extern jl_RuntimeException_VT jl_RuntimeException_Cls;
