#pragma once
#include "../../../runtime.h"
#include "Comparator.h"

extern void sysinitclass_ju_Comparator();
extern int32_t supertypeof_ju_Comparator(TeaVM_Class*, TeaVM_Class*);
typedef struct ju_Comparator_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} ju_Comparator_VT;
extern TeaVM_Class ju_Comparator_Cls;
