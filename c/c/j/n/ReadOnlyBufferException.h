#pragma once
#include "../../../runtime.h"
#include "../l/UnsupportedOperationException.h"
#include "ReadOnlyBufferException.h"

extern void sysinitclass_jn_ReadOnlyBufferException();
typedef struct cls_jn_ReadOnlyBufferException {
    struct cls_jl_UnsupportedOperationException parent;
} cls_jn_ReadOnlyBufferException;
extern int32_t supertypeof_jn_ReadOnlyBufferException(TeaVM_Class*, TeaVM_Class*);
typedef struct jn_ReadOnlyBufferException_VT {
    jl_UnsupportedOperationException_VT parent;
} jn_ReadOnlyBufferException_VT;
extern jn_ReadOnlyBufferException_VT jn_ReadOnlyBufferException_Cls;
