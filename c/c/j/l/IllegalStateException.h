#pragma once
#include "../../../runtime.h"
#include "RuntimeException.h"
#include "IllegalStateException.h"

extern void sysinitclass_jl_IllegalStateException();
typedef struct cls_jl_IllegalStateException {
    struct cls_jl_RuntimeException parent;
} cls_jl_IllegalStateException;
extern int32_t supertypeof_jl_IllegalStateException(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_IllegalStateException_VT {
    jl_RuntimeException_VT parent;
} jl_IllegalStateException_VT;
extern jl_IllegalStateException_VT jl_IllegalStateException_Cls;
