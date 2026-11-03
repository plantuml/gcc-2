#pragma once
#include "../../../runtime.h"
#include "Throwable.h"
#include "Error.h"

extern void sysinitclass_jl_Error();
typedef struct cls_jl_Error {
    struct cls_jl_Throwable parent;
} cls_jl_Error;
extern int32_t supertypeof_jl_Error(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Error_VT {
    jl_Throwable_VT parent;
} jl_Error_VT;
extern jl_Error_VT jl_Error_Cls;
