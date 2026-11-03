#pragma once
#include "../../../runtime.h"
#include "Object.h"
#include "StackTraceElement.h"

extern void sysinitclass_jl_StackTraceElement();
typedef struct cls_jl_StackTraceElement {
    struct TeaVM_Object parent;
    void* fld_declaringClass;
    void* fld_methodName;
    void* fld_fileName;
    int32_t fld_lineNumber;
} cls_jl_StackTraceElement;
extern void meth_jl_StackTraceElement__init_(void*, void*, void*, void*, int32_t);
extern int32_t supertypeof_jl_StackTraceElement(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_StackTraceElement_VT {
    jl_Object_VT parent;
} jl_StackTraceElement_VT;
extern jl_StackTraceElement_VT jl_StackTraceElement_Cls;
