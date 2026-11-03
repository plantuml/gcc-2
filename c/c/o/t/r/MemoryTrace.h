#pragma once
#include "../../../../runtime.h"
#include "../../../j/l/Object.h"
#include "MemoryTrace.h"

extern void sysinitclass_otr_MemoryTrace();
typedef struct cls_otr_MemoryTrace {
    struct TeaVM_Object parent;
} cls_otr_MemoryTrace;
extern int32_t supertypeof_otr_MemoryTrace(TeaVM_Class*, TeaVM_Class*);
typedef struct otr_MemoryTrace_VT {
    jl_Object_VT parent;
} otr_MemoryTrace_VT;
extern otr_MemoryTrace_VT otr_MemoryTrace_Cls;
