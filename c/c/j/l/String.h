#pragma once
#include "../../../runtime.h"
#include "Object.h"
#include "String.h"

extern void sysinitclass_jl_String();
extern TeaVM_Array* sfld_jl_String_EMPTY_CHARS;
extern void* sfld_jl_String_EMPTY;
extern void* sfld_jl_String_CASE_INSENSITIVE_ORDER;
extern void meth_jl_String__init_(void*, TeaVM_Array*);
extern void meth_jl_String__clinit_();
extern void initclass_jl_String();
extern int32_t supertypeof_jl_String(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_String_VT {
    jl_Object_VT parent;
} jl_String_VT;
extern jl_String_VT jl_String_Cls;
