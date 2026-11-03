#pragma once
#include "../../../runtime.h"
#include "RuntimeException.h"
#include "ArrayStoreException.h"

extern void sysinitclass_jl_ArrayStoreException();
typedef struct cls_jl_ArrayStoreException {
    struct cls_jl_RuntimeException parent;
} cls_jl_ArrayStoreException;
extern int32_t supertypeof_jl_ArrayStoreException(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_ArrayStoreException_VT {
    jl_RuntimeException_VT parent;
} jl_ArrayStoreException_VT;
extern jl_ArrayStoreException_VT jl_ArrayStoreException_Cls;
