#pragma once
#include "../../../runtime.h"
#include "../l/Object.h"
#include "MapEntry.h"

extern void sysinitclass_ju_MapEntry();
typedef struct cls_ju_MapEntry {
    struct TeaVM_Object parent;
    void* fld_key;
    void* fld_value;
} cls_ju_MapEntry;
extern int32_t supertypeof_ju_MapEntry(TeaVM_Class*, TeaVM_Class*);
typedef struct ju_MapEntry_VT {
    jl_Object_VT parent;
} ju_MapEntry_VT;
extern ju_MapEntry_VT ju_MapEntry_Cls;
