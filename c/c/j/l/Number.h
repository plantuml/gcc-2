#pragma once
#include "../../../runtime.h"
#include "Object.h"
#include "Number.h"

extern void sysinitclass_jl_Number();
typedef struct cls_jl_Number {
    struct TeaVM_Object parent;
} cls_jl_Number;
extern int32_t supertypeof_jl_Number(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Number_VT {
    jl_Object_VT parent;
} jl_Number_VT;
extern jl_Number_VT jl_Number_Cls;
