#pragma once
#include "../../../runtime.h"
#include "Object.h"
#include "Throwable.h"

extern void sysinitclass_jl_Throwable();
typedef struct cls_jl_Throwable {
    struct TeaVM_Object parent;
    void* fld_message;
    void* fld_cause;
    int8_t fld_suppressionEnabled;
    int8_t fld_writableStackTrace;
    TeaVM_Array* fld_suppressed;
    TeaVM_Array* fld_stackTrace;
} cls_jl_Throwable;
extern void meth_jl_Throwable__init_(void*, void*);
extern void* meth_jl_Throwable_fillInStackTrace(void*);
extern void meth_jl_Throwable_initNativeException(void*);
extern void* meth_jl_Throwable_getMessage(void*);
extern void* meth_jl_Throwable_getLocalizedMessage(void*);
extern void* meth_jl_Throwable_toString(void*);
extern int32_t supertypeof_jl_Throwable(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Throwable_VT {
    jl_Object_VT parent;
    void* (*virt_fillInStackTrace)(void*); // 4
    void* (*virt_getMessage)(void*); // 5
    void* (*virt_getLocalizedMessage)(void*); // 6
    void* (*virt_toString)(void*); // 7
} jl_Throwable_VT;
extern jl_Throwable_VT jl_Throwable_Cls;
