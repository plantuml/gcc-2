#pragma once
#include "../../../runtime.h"
#include "RuntimeException.h"
#include "IndexOutOfBoundsException.h"

extern void sysinitclass_jl_IndexOutOfBoundsException();
typedef struct cls_jl_IndexOutOfBoundsException {
    struct cls_jl_RuntimeException parent;
} cls_jl_IndexOutOfBoundsException;
extern int32_t supertypeof_jl_IndexOutOfBoundsException(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_IndexOutOfBoundsException_VT {
    jl_RuntimeException_VT parent;
} jl_IndexOutOfBoundsException_VT;
extern jl_IndexOutOfBoundsException_VT jl_IndexOutOfBoundsException_Cls;
