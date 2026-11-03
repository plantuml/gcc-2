#pragma once
#include "../../../runtime.h"
#include "Number.h"
#include "Integer.h"

extern void sysinitclass_jl_Integer();
typedef struct cls_jl_Integer {
    struct cls_jl_Number parent;
} cls_jl_Integer;
extern void* sfld_jl_Integer_TYPE;
extern void meth_jl_Integer__clinit_();
extern void initclass_jl_Integer();
extern int32_t supertypeof_jl_Integer(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Integer_VT {
    jl_Number_VT parent;
} jl_Integer_VT;
extern jl_Integer_VT jl_Integer_Cls;
