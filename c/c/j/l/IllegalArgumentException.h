#pragma once
#include "../../../runtime.h"
#include "RuntimeException.h"
#include "IllegalArgumentException.h"

extern void sysinitclass_jl_IllegalArgumentException();
typedef struct cls_jl_IllegalArgumentException {
    struct cls_jl_RuntimeException parent;
} cls_jl_IllegalArgumentException;
extern int32_t supertypeof_jl_IllegalArgumentException(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_IllegalArgumentException_VT {
    jl_RuntimeException_VT parent;
} jl_IllegalArgumentException_VT;
extern jl_IllegalArgumentException_VT jl_IllegalArgumentException_Cls;
