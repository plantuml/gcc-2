#pragma once
#include "../../../runtime.h"
#include "OutputStream.h"
#include "FilterOutputStream.h"

extern void sysinitclass_ji_FilterOutputStream();
typedef struct cls_ji_FilterOutputStream {
    struct cls_ji_OutputStream parent;
    void* fld_out;
} cls_ji_FilterOutputStream;
extern int32_t supertypeof_ji_FilterOutputStream(TeaVM_Class*, TeaVM_Class*);
typedef struct ji_FilterOutputStream_VT {
    ji_OutputStream_VT parent;
} ji_FilterOutputStream_VT;
extern ji_FilterOutputStream_VT ji_FilterOutputStream_Cls;
