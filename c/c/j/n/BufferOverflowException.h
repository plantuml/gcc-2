#pragma once
#include "../../../runtime.h"
#include "../l/RuntimeException.h"
#include "BufferOverflowException.h"

extern void sysinitclass_jn_BufferOverflowException();
typedef struct cls_jn_BufferOverflowException {
    struct cls_jl_RuntimeException parent;
} cls_jn_BufferOverflowException;
extern int32_t supertypeof_jn_BufferOverflowException(TeaVM_Class*, TeaVM_Class*);
typedef struct jn_BufferOverflowException_VT {
    jl_RuntimeException_VT parent;
} jn_BufferOverflowException_VT;
extern jn_BufferOverflowException_VT jn_BufferOverflowException_Cls;
