#pragma once
#include "../../../../runtime.h"
#include "../../l/Object.h"
#include "Charset.h"

extern void sysinitclass_jnc_Charset();
typedef struct cls_jnc_Charset {
    struct TeaVM_Object parent;
    void* fld_canonicalName;
    TeaVM_Array* fld_aliases;
} cls_jnc_Charset;
extern void meth_jnc_Charset_checkCanonicalName(void*);
extern int32_t meth_jnc_Charset_isValidCharsetStart(int32_t);
extern int32_t supertypeof_jnc_Charset(TeaVM_Class*, TeaVM_Class*);
typedef struct jnc_Charset_VT {
    jl_Object_VT parent;
    void* (*virt_encode)(void*, void*); // 4
} jnc_Charset_VT;
extern jnc_Charset_VT jnc_Charset_Cls;
