#pragma once
#include "../../../runtime.h"
#include "Map.h"

extern void sysinitclass_ju_Map();
extern int32_t supertypeof_ju_Map(TeaVM_Class*, TeaVM_Class*);
typedef struct ju_Map_VT {
    TeaVM_Class parent;
} ju_Map_VT;
extern TeaVM_Class ju_Map_Cls;
