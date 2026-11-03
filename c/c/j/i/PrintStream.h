#pragma once
#include "../../../runtime.h"
#include "FilterOutputStream.h"
#include "PrintStream.h"

extern void sysinitclass_ji_PrintStream();
typedef struct cls_ji_PrintStream {
    struct cls_ji_FilterOutputStream parent;
    int8_t fld_autoFlush;
    int8_t fld_errorState;
    void* fld_sb;
    TeaVM_Array* fld_buffer;
    void* fld_charset;
} cls_ji_PrintStream;
extern void meth_ji_PrintStream_printCharBuffer(void*, void*, int32_t, int32_t);
extern void meth_ji_PrintStream_printSB(void*);
extern int32_t supertypeof_ji_PrintStream(TeaVM_Class*, TeaVM_Class*);
typedef struct ji_PrintStream_VT {
    ji_FilterOutputStream_VT parent;
    void (*virt_write)(void*, TeaVM_Array*, int32_t, int32_t); // 4
    void (*virt_print)(void*, TeaVM_Array*, int32_t, int32_t); // 5
    void (*virt_println)(void*, void*); // 6
} ji_PrintStream_VT;
extern ji_PrintStream_VT ji_PrintStream_Cls;
