#pragma once
#include "../../../../runtime.h"
#include "../../l/Error.h"
#include "CoderMalfunctionError.h"

extern void sysinitclass_jnc_CoderMalfunctionError();
typedef struct cls_jnc_CoderMalfunctionError {
    struct cls_jl_Error parent;
} cls_jnc_CoderMalfunctionError;
extern int32_t supertypeof_jnc_CoderMalfunctionError(TeaVM_Class*, TeaVM_Class*);
typedef struct jnc_CoderMalfunctionError_VT {
    jl_Error_VT parent;
} jnc_CoderMalfunctionError_VT;
extern jnc_CoderMalfunctionError_VT jnc_CoderMalfunctionError_Cls;
