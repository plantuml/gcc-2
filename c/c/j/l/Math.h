#pragma once
#include "../../../runtime.h"
#include "Object.h"
#include "Math.h"

extern void sysinitclass_jl_Math();
typedef struct cls_jl_Math {
    struct TeaVM_Object parent;
} cls_jl_Math;
extern int32_t supertypeof_jl_Math(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Math_VT {
    jl_Object_VT parent;
} jl_Math_VT;
extern jl_Math_VT jl_Math_Cls;
