#pragma once
#include "../../../../runtime.h"
#include "../../../j/l/Object.h"
#include "ShadowStack.h"

extern void sysinitclass_otr_ShadowStack();
typedef struct cls_otr_ShadowStack {
    struct TeaVM_Object parent;
} cls_otr_ShadowStack;
extern int32_t supertypeof_otr_ShadowStack(TeaVM_Class*, TeaVM_Class*);
typedef struct otr_ShadowStack_VT {
    jl_Object_VT parent;
} otr_ShadowStack_VT;
extern otr_ShadowStack_VT otr_ShadowStack_Cls;
