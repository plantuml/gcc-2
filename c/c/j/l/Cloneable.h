#pragma once
#include "../../../runtime.h"
#include "Cloneable.h"

extern void sysinitclass_jl_Cloneable();
extern int32_t supertypeof_jl_Cloneable(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Cloneable_VT {
    TeaVM_Class parent;
} jl_Cloneable_VT;
extern TeaVM_Class jl_Cloneable_Cls;
