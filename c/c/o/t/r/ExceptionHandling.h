#pragma once
#include "../../../../runtime.h"
#include "../../../j/l/Object.h"
#include "ExceptionHandling.h"

extern void sysinitclass_otr_ExceptionHandling();
typedef struct cls_otr_ExceptionHandling {
    struct TeaVM_Object parent;
} cls_otr_ExceptionHandling;
extern void* sfld_otr_ExceptionHandling_thrownException;
extern void meth_otr_ExceptionHandling_printStack();
extern void* teavm_catchException();
extern void meth_otr_ExceptionHandling_throwException(void*);
extern void meth_otr_ExceptionHandling_throwClassCastException();
extern void teavm_throwNullPointerException();
extern void teavm_throwArrayIndexOutOfBoundsException();
extern int32_t meth_otr_ExceptionHandling_callStackSize();
extern TeaVM_Array* meth_otr_ExceptionHandling_fillStackTrace();
extern int32_t supertypeof_otr_ExceptionHandling(TeaVM_Class*, TeaVM_Class*);
typedef struct otr_ExceptionHandling_VT {
    jl_Object_VT parent;
} otr_ExceptionHandling_VT;
extern otr_ExceptionHandling_VT otr_ExceptionHandling_Cls;
