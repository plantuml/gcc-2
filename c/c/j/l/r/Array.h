#pragma once
#include "../../../../runtime.h"
#include "../Object.h"
#include "Array.h"

extern void sysinitclass_jlr_Array();
typedef struct cls_jlr_Array {
    struct TeaVM_Object parent;
} cls_jlr_Array;
extern int32_t supertypeof_jlr_Array(TeaVM_Class*, TeaVM_Class*);
typedef struct jlr_Array_VT {
    jl_Object_VT parent;
} jlr_Array_VT;
extern jlr_Array_VT jlr_Array_Cls;
