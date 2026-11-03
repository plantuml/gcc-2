#pragma once
#include "../runtime.h"
#include "j/l/Object.h"
#include "Hello.h"

extern void sysinitclass_Hello();
typedef struct cls_Hello {
    struct TeaVM_Object parent;
} cls_Hello;
extern void meth_Hello_main(TeaVM_Array*);
extern void meth_Hello__clinit_();
extern void initclass_Hello();
extern int32_t supertypeof_Hello(TeaVM_Class*, TeaVM_Class*);
typedef struct Hello_VT {
    jl_Object_VT parent;
} Hello_VT;
extern Hello_VT Hello_Cls;
