#pragma once
#include "../../../../runtime.h"
#include "GenericDeclaration.h"

extern void sysinitclass_jlr_GenericDeclaration();
extern int32_t supertypeof_jlr_GenericDeclaration(TeaVM_Class*, TeaVM_Class*);
typedef struct jlr_GenericDeclaration_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} jlr_GenericDeclaration_VT;
extern TeaVM_Class jlr_GenericDeclaration_Cls;
