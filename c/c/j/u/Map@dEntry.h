#pragma once
#include "../../../runtime.h"
#include "Map@dEntry.h"

extern void sysinitclass_ju_Map_Entry();
extern int32_t supertypeof_ju_Map_Entry(TeaVM_Class*, TeaVM_Class*);
typedef struct ju_Map_Entry_VT {
    TeaVM_Class parent;
} ju_Map_Entry_VT;
extern TeaVM_Class ju_Map_Entry_Cls;
