#pragma once
#include "../../../../runtime.h"
#include "../../l/Object.h"
#include "CharsetEncoder.h"

extern void sysinitclass_jnc_CharsetEncoder();
typedef struct cls_jnc_CharsetEncoder {
    struct TeaVM_Object parent;
    void* fld_charset;
    TeaVM_Array* fld_replacement;
    float fld_averageBytesPerChar;
    float fld_maxBytesPerChar;
    void* fld_malformedAction;
    void* fld_unmappableAction;
    int32_t fld_status;
} cls_jnc_CharsetEncoder;
extern void* meth_jnc_CharsetEncoder_onMalformedInput(void*, void*);
extern void meth_jnc_CharsetEncoder_implOnMalformedInput(void*, void*);
extern void* meth_jnc_CharsetEncoder_onUnmappableCharacter(void*, void*);
extern void meth_jnc_CharsetEncoder_implOnUnmappableCharacter(void*, void*);
extern void* meth_jnc_CharsetEncoder_encode_0(void*, void*, void*, int32_t);
extern void* meth_jnc_CharsetEncoder_encode(void*, void*);
extern void* meth_jnc_CharsetEncoder_implFlush(void*, void*);
extern void meth_jnc_CharsetEncoder_implReset(void*);
extern int32_t supertypeof_jnc_CharsetEncoder(TeaVM_Class*, TeaVM_Class*);
typedef struct jnc_CharsetEncoder_VT {
    jl_Object_VT parent;
    void* (*virt_onMalformedInput)(void*, void*); // 4
    void (*virt_implOnMalformedInput)(void*, void*); // 5
    void* (*virt_onUnmappableCharacter)(void*, void*); // 6
    void (*virt_implOnUnmappableCharacter)(void*, void*); // 7
    void* (*virt_encode_0)(void*, void*, void*, int32_t); // 8
    void* (*virt_encode)(void*, void*); // 9
    void* (*virt_flush)(void*, void*); // 10
    void* (*virt_implFlush)(void*, void*); // 11
    void* (*virt_reset)(void*); // 12
    void (*virt_implReset)(void*); // 13
} jnc_CharsetEncoder_VT;
extern jnc_CharsetEncoder_VT jnc_CharsetEncoder_Cls;
