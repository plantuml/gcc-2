#pragma once
#include "../../../../runtime.h"
#include "Type.h"

extern void sysinitclass_jlr_Type();
extern int32_t supertypeof_jlr_Type(TeaVM_Class*, TeaVM_Class*);
typedef struct jlr_Type_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} jlr_Type_VT;
extern TeaVM_Class jlr_Type_Cls;
