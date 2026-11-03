#pragma once
#include "../../../../runtime.h"
#include "../../l/IllegalArgumentException.h"
#include "IllegalCharsetNameException.h"

extern void sysinitclass_jnc_IllegalCharsetNameException();
typedef struct cls_jnc_IllegalCharsetNameException {
    struct cls_jl_IllegalArgumentException parent;
    void* fld_charsetName;
} cls_jnc_IllegalCharsetNameException;
extern int32_t supertypeof_jnc_IllegalCharsetNameException(TeaVM_Class*, TeaVM_Class*);
typedef struct jnc_IllegalCharsetNameException_VT {
    jl_IllegalArgumentException_VT parent;
} jnc_IllegalCharsetNameException_VT;
extern jnc_IllegalCharsetNameException_VT jnc_IllegalCharsetNameException_Cls;
