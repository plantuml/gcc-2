#pragma once
#include "../../../runtime.h"
#include "Flushable.h"

extern void sysinitclass_ji_Flushable();
extern int32_t supertypeof_ji_Flushable(TeaVM_Class*, TeaVM_Class*);
typedef struct ji_Flushable_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} ji_Flushable_VT;
extern TeaVM_Class ji_Flushable_Cls;
