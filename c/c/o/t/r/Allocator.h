#pragma once
#include "../../../../runtime.h"
#include "../../../j/l/Object.h"
#include "Allocator.h"

extern void sysinitclass_otr_Allocator();
typedef struct cls_otr_Allocator {
    struct TeaVM_Object parent;
} cls_otr_Allocator;
extern void* meth_otr_Allocator_allocate(void*);
extern void* meth_otr_Allocator_allocateArray(void*, int32_t);
extern void* meth_otr_Allocator_allocateMultiArray(void*, void*, int32_t);
extern int32_t supertypeof_otr_Allocator(TeaVM_Class*, TeaVM_Class*);
typedef struct otr_Allocator_VT {
    jl_Object_VT parent;
} otr_Allocator_VT;
extern otr_Allocator_VT otr_Allocator_Cls;
