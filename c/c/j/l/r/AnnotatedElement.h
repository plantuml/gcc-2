#pragma once
#include "../../../../runtime.h"
#include "AnnotatedElement.h"

extern void sysinitclass_jlr_AnnotatedElement();
extern int32_t supertypeof_jlr_AnnotatedElement(TeaVM_Class*, TeaVM_Class*);
typedef struct jlr_AnnotatedElement_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} jlr_AnnotatedElement_VT;
extern TeaVM_Class jlr_AnnotatedElement_Cls;
