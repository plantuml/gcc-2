#pragma once
#include "../../../runtime.h"
#include "../l/Object.h"
#include "OutputStream.h"

extern void sysinitclass_ji_OutputStream();
typedef struct cls_ji_OutputStream {
    struct TeaVM_Object parent;
} cls_ji_OutputStream;
extern int32_t supertypeof_ji_OutputStream(TeaVM_Class*, TeaVM_Class*);
typedef struct ji_OutputStream_VT {
    jl_Object_VT parent;
} ji_OutputStream_VT;
extern ji_OutputStream_VT ji_OutputStream_Cls;
