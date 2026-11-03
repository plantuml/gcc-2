#pragma once
#include "../../../runtime.h"
#include "../l/Exception.h"
#include "IOException.h"

extern void sysinitclass_ji_IOException();
typedef struct cls_ji_IOException {
    struct cls_jl_Exception parent;
} cls_ji_IOException;
extern int32_t supertypeof_ji_IOException(TeaVM_Class*, TeaVM_Class*);
typedef struct ji_IOException_VT {
    jl_Exception_VT parent;
} ji_IOException_VT;
extern ji_IOException_VT ji_IOException_Cls;
