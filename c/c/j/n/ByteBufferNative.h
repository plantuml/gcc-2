#pragma once
#include "../../../runtime.h"
#include "ByteBuffer.h"
#include "ByteBufferNative.h"

extern void sysinitclass_jn_ByteBufferNative();
typedef struct cls_jn_ByteBufferNative {
    struct cls_jn_ByteBuffer parent;
    void* fld_gcRef;
    TeaVM_Array* fld_array;
    int32_t fld_arrayOffset;
    void* fld_base;
    void* fld_address;
    int32_t fld_capacity;
    int8_t fld_readOnly;
    int8_t fld_swap;
} cls_jn_ByteBufferNative;
extern int32_t supertypeof_jn_ByteBufferNative(TeaVM_Class*, TeaVM_Class*);
typedef struct jn_ByteBufferNative_VT {
    jn_ByteBuffer_VT parent;
    TeaVM_Array* (*virt_arrayImpl)(void*); // 21
    int32_t (*virt_hasArrayImpl)(void*); // 22
    int32_t (*virt_capacityImpl)(void*); // 23
    void (*virt_getImpl_0)(void*, int32_t, TeaVM_Array*, int32_t, int32_t); // 24
    void (*virt_putImpl)(void*, TeaVM_Array*, int32_t, int32_t, int32_t); // 25
    int32_t (*virt_isReadOnly)(void*); // 26
    void (*virt_copy_0)(void*, TeaVM_Array*, int32_t, void*, int32_t); // 27
    void (*virt_copy_1)(void*, void*, TeaVM_Array*, int32_t, int32_t); // 28
} jn_ByteBufferNative_VT;
extern jn_ByteBufferNative_VT jn_ByteBufferNative_Cls;
