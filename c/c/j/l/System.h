#pragma once
#include "../../../runtime.h"
#include "Object.h"
#include "System.h"

extern void sysinitclass_jl_System();
typedef struct cls_jl_System {
    struct TeaVM_Object parent;
} cls_jl_System;
extern void* sfld_jl_System_outCache;
extern void meth_jl_System_arraycopy(void*, int32_t, void*, int32_t, int32_t);
extern void meth_jl_System_fastArraycopy(void*, int32_t, void*, int32_t, int32_t);
extern void meth_jl_System_doArrayCopy(void*, int32_t, void*, int32_t, int32_t);
extern void meth_jl_System_doArrayCopyLowLevel(void*, int32_t, void*, int32_t, int32_t);
extern int64_t meth_jl_System_currentTimeMillis();
extern int64_t meth_jl_System_currentTimeMillisLowLevel();
extern int32_t supertypeof_jl_System(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_System_VT {
    jl_Object_VT parent;
} jl_System_VT;
extern jl_System_VT jl_System_Cls;
