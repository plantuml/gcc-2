#pragma once
#include "../../../runtime.h"
#include "../l/Object.h"
#include "Objects.h"

extern void sysinitclass_ju_Objects();
typedef struct cls_ju_Objects {
    struct TeaVM_Object parent;
} cls_ju_Objects;
extern int32_t supertypeof_ju_Objects(TeaVM_Class*, TeaVM_Class*);
typedef struct ju_Objects_VT {
    jl_Object_VT parent;
} ju_Objects_VT;
extern ju_Objects_VT ju_Objects_Cls;
