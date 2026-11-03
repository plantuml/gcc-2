#pragma once
#include "../../../../runtime.h"
#include "../../l/Object.h"
#include "CoderResult.h"

extern void sysinitclass_jnc_CoderResult();
typedef struct cls_jnc_CoderResult {
    struct TeaVM_Object parent;
    int8_t fld_kind;
    int32_t fld_length;
} cls_jnc_CoderResult;
extern void* sfld_jnc_CoderResult_UNDERFLOW;
extern void* sfld_jnc_CoderResult_OVERFLOW;
extern void meth_jnc_CoderResult__clinit_();
extern void initclass_jnc_CoderResult();
extern int32_t supertypeof_jnc_CoderResult(TeaVM_Class*, TeaVM_Class*);
typedef struct jnc_CoderResult_VT {
    jl_Object_VT parent;
    int32_t (*virt_isUnderflow)(void*); // 4
    int32_t (*virt_isOverflow)(void*); // 5
    int32_t (*virt_isError)(void*); // 6
    int32_t (*virt_isMalformed)(void*); // 7
    int32_t (*virt_isUnmappable)(void*); // 8
    int32_t (*virt_length)(void*); // 9
    void (*virt_throwException)(void*); // 10
} jnc_CoderResult_VT;
extern jnc_CoderResult_VT jnc_CoderResult_Cls;
