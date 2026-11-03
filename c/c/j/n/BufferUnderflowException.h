#pragma once
#include "../../../runtime.h"
#include "../l/RuntimeException.h"
#include "BufferUnderflowException.h"

extern void sysinitclass_jn_BufferUnderflowException();
typedef struct cls_jn_BufferUnderflowException {
    struct cls_jl_RuntimeException parent;
} cls_jn_BufferUnderflowException;
extern int32_t supertypeof_jn_BufferUnderflowException(TeaVM_Class*, TeaVM_Class*);
typedef struct jn_BufferUnderflowException_VT {
    jl_RuntimeException_VT parent;
} jn_BufferUnderflowException_VT;
extern jn_BufferUnderflowException_VT jn_BufferUnderflowException_Cls;
