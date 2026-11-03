#pragma once
#include "../../../../runtime.h"
#include "AddressBasedBuffer.h"

extern void sysinitclass_jnf_AddressBasedBuffer();
extern int32_t supertypeof_jnf_AddressBasedBuffer(TeaVM_Class*, TeaVM_Class*);
typedef struct jnf_AddressBasedBuffer_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} jnf_AddressBasedBuffer_VT;
extern TeaVM_Class jnf_AddressBasedBuffer_Cls;
