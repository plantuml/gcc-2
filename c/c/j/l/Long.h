#pragma once
#include "../../../runtime.h"
#include "Number.h"
#include "Long.h"

extern void sysinitclass_jl_Long();
typedef struct cls_jl_Long {
    struct cls_jl_Number parent;
} cls_jl_Long;
extern void* sfld_jl_Long_TYPE;
extern int32_t meth_jl_Long_numberOfLeadingZeros(int64_t);
extern void meth_jl_Long__clinit_();
extern void initclass_jl_Long();
extern int32_t supertypeof_jl_Long(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Long_VT {
    jl_Number_VT parent;
} jl_Long_VT;
extern jl_Long_VT jl_Long_Cls;
