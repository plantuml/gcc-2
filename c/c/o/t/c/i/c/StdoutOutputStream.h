#pragma once
#include "../../../../../../runtime.h"
#include "ConsoleOutputStream.h"
#include "StdoutOutputStream.h"

extern void sysinitclass_otcic_StdoutOutputStream();
typedef struct cls_otcic_StdoutOutputStream {
    struct cls_otcic_ConsoleOutputStream parent;
} cls_otcic_StdoutOutputStream;
extern void* sfld_otcic_StdoutOutputStream_INSTANCE;
extern void meth_otcic_StdoutOutputStream_write(void*, TeaVM_Array*, int32_t, int32_t);
extern void meth_otcic_StdoutOutputStream__clinit_();
extern void initclass_otcic_StdoutOutputStream();
extern int32_t supertypeof_otcic_StdoutOutputStream(TeaVM_Class*, TeaVM_Class*);
typedef struct otcic_StdoutOutputStream_VT {
    otcic_ConsoleOutputStream_VT parent;
    void (*virt_write)(void*, TeaVM_Array*, int32_t, int32_t); // 4
} otcic_StdoutOutputStream_VT;
extern otcic_StdoutOutputStream_VT otcic_StdoutOutputStream_Cls;
