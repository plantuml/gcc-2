#pragma once
#include "../../../../../../runtime.h"
#include "../../../../../j/l/Object.h"
#include "Memory.h"

extern void sysinitclass_otbcr_Memory();
typedef struct cls_otbcr_Memory {
    struct TeaVM_Object parent;
} cls_otbcr_Memory;
extern int32_t supertypeof_otbcr_Memory(TeaVM_Class*, TeaVM_Class*);
typedef struct otbcr_Memory_VT {
    jl_Object_VT parent;
} otbcr_Memory_VT;
extern otbcr_Memory_VT otbcr_Memory_Cls;
