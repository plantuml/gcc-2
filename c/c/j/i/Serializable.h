#pragma once
#include "../../../runtime.h"
#include "Serializable.h"

extern void sysinitclass_ji_Serializable();
extern int32_t supertypeof_ji_Serializable(TeaVM_Class*, TeaVM_Class*);
typedef struct ji_Serializable_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} ji_Serializable_VT;
extern TeaVM_Class ji_Serializable_Cls;
