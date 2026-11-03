#pragma once
#include "../../../runtime.h"
#include "ArrayBufferViewProvider.h"

extern void sysinitclass_jn_ArrayBufferViewProvider();
extern int32_t supertypeof_jn_ArrayBufferViewProvider(TeaVM_Class*, TeaVM_Class*);
typedef struct jn_ArrayBufferViewProvider_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} jn_ArrayBufferViewProvider_VT;
extern TeaVM_Class jn_ArrayBufferViewProvider_Cls;
