#pragma once
#include "../../../runtime.h"
#include "Object.h"
#include "Thread.h"

extern void sysinitclass_jl_Thread();
typedef struct cls_jl_Thread {
    struct TeaVM_Object parent;
    int64_t fld_id;
    int64_t fld_timeSliceStart;
    void* fld_finishedLock;
    void* fld_name;
    int8_t fld_alive;
    void* fld_target;
} cls_jl_Thread;
extern void* sfld_jl_Thread_mainThread;
extern void* sfld_jl_Thread_currentThread;
extern int32_t sfld_jl_Thread_nextId;
extern int32_t sfld_jl_Thread_activeCount;
extern void* sfld_jl_Thread_defaultUncaughtExceptionHandler;
extern void meth_jl_Thread_setCurrentThread(void*);
extern void meth_jl_Thread__clinit_();
extern void initclass_jl_Thread();
extern int32_t supertypeof_jl_Thread(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Thread_VT {
    jl_Object_VT parent;
} jl_Thread_VT;
extern jl_Thread_VT jl_Thread_Cls;
