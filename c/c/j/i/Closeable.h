#pragma once
#include "../../../runtime.h"
#include "Closeable.h"

extern void sysinitclass_ji_Closeable();
extern int32_t supertypeof_ji_Closeable(TeaVM_Class*, TeaVM_Class*);
typedef struct ji_Closeable_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} ji_Closeable_VT;
extern TeaVM_Class ji_Closeable_Cls;
