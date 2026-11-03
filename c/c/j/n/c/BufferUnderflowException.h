#pragma once
#include "../../../../runtime.h"
#include "../../l/RuntimeException.h"
#include "BufferUnderflowException.h"

extern void sysinitclass_jnc_BufferUnderflowException();
typedef struct cls_jnc_BufferUnderflowException {
    struct cls_jl_RuntimeException parent;
} cls_jnc_BufferUnderflowException;
extern int32_t supertypeof_jnc_BufferUnderflowException(TeaVM_Class*, TeaVM_Class*);
typedef struct jnc_BufferUnderflowException_VT {
    jl_RuntimeException_VT parent;
} jnc_BufferUnderflowException_VT;
extern jnc_BufferUnderflowException_VT jnc_BufferUnderflowException_Cls;
