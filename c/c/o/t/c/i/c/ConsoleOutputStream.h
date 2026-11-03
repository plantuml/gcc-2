#pragma once
#include "../../../../../../runtime.h"
#include "../../../../../j/i/OutputStream.h"
#include "ConsoleOutputStream.h"

extern void sysinitclass_otcic_ConsoleOutputStream();
typedef struct cls_otcic_ConsoleOutputStream {
    struct cls_ji_OutputStream parent;
    TeaVM_Array* fld_buffer;
} cls_otcic_ConsoleOutputStream;
extern int32_t supertypeof_otcic_ConsoleOutputStream(TeaVM_Class*, TeaVM_Class*);
typedef struct otcic_ConsoleOutputStream_VT {
    ji_OutputStream_VT parent;
} otcic_ConsoleOutputStream_VT;
extern otcic_ConsoleOutputStream_VT otcic_ConsoleOutputStream_Cls;
