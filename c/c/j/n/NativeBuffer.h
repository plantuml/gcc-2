#pragma once
#include "../../../runtime.h"
#include "NativeBuffer.h"

extern void sysinitclass_jn_NativeBuffer();
extern int32_t supertypeof_jn_NativeBuffer(TeaVM_Class*, TeaVM_Class*);
typedef struct jn_NativeBuffer_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} jn_NativeBuffer_VT;
extern TeaVM_Class jn_NativeBuffer_Cls;
