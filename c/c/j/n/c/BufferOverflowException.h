#pragma once
#include "../../../../runtime.h"
#include "../../l/RuntimeException.h"
#include "BufferOverflowException.h"

extern void sysinitclass_jnc_BufferOverflowException();
typedef struct cls_jnc_BufferOverflowException {
    struct cls_jl_RuntimeException parent;
} cls_jnc_BufferOverflowException;
extern int32_t supertypeof_jnc_BufferOverflowException(TeaVM_Class*, TeaVM_Class*);
typedef struct jnc_BufferOverflowException_VT {
    jl_RuntimeException_VT parent;
} jnc_BufferOverflowException_VT;
extern jnc_BufferOverflowException_VT jnc_BufferOverflowException_Cls;
