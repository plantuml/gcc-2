#pragma once
#include "../../../runtime.h"
#include "IndexOutOfBoundsException.h"
#include "StringIndexOutOfBoundsException.h"

extern void sysinitclass_jl_StringIndexOutOfBoundsException();
typedef struct cls_jl_StringIndexOutOfBoundsException {
    struct cls_jl_IndexOutOfBoundsException parent;
} cls_jl_StringIndexOutOfBoundsException;
extern int32_t supertypeof_jl_StringIndexOutOfBoundsException(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_StringIndexOutOfBoundsException_VT {
    jl_IndexOutOfBoundsException_VT parent;
} jl_StringIndexOutOfBoundsException_VT;
extern jl_StringIndexOutOfBoundsException_VT jl_StringIndexOutOfBoundsException_Cls;
