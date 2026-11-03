#pragma once
#include "../../../runtime.h"
#include "../l/Object.h"
#include "AbstractMap.h"

extern void sysinitclass_ju_AbstractMap();
typedef struct cls_ju_AbstractMap {
    struct TeaVM_Object parent;
} cls_ju_AbstractMap;
extern int32_t supertypeof_ju_AbstractMap(TeaVM_Class*, TeaVM_Class*);
typedef struct ju_AbstractMap_VT {
    jl_Object_VT parent;
} ju_AbstractMap_VT;
extern ju_AbstractMap_VT ju_AbstractMap_Cls;
