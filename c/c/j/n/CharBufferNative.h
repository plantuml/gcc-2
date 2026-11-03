#pragma once
#include "../../../runtime.h"
#include "CharBufferImpl.h"
#include "CharBufferNative.h"

extern void sysinitclass_jn_CharBufferNative();
typedef struct cls_jn_CharBufferNative {
    struct cls_jn_CharBufferImpl parent;
    TeaVM_Array* fld_array;
    int8_t fld_readOnly;
    void* fld_base;
    void* fld_address;
    int32_t fld_capacity;
    int8_t fld_swap;
} cls_jn_CharBufferNative;
extern void meth_jn_CharBufferNative_getImpl(void*, int32_t, TeaVM_Array*, int32_t, int32_t);
extern int32_t supertypeof_jn_CharBufferNative(TeaVM_Class*, TeaVM_Class*);
typedef struct jn_CharBufferNative_VT {
    jn_CharBufferImpl_VT parent;
    void (*virt_getImpl)(void*, int32_t, TeaVM_Array*, int32_t, int32_t); // 14
    void (*virt_copy)(void*, void*, TeaVM_Array*, int32_t, int32_t); // 15
} jn_CharBufferNative_VT;
extern jn_CharBufferNative_VT jn_CharBufferNative_Cls;
