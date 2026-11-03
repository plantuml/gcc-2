#pragma once
#include "../../../../../runtime.h"
#include "../CharsetEncoder.h"
#include "BufferedEncoder.h"

extern void sysinitclass_jnci_BufferedEncoder();
typedef struct cls_jnci_BufferedEncoder {
    struct cls_jnc_CharsetEncoder parent;
    TeaVM_Array* fld_inArray;
    TeaVM_Array* fld_outArray;
} cls_jnci_BufferedEncoder;
extern void* meth_jnci_BufferedEncoder_encodeLoop(void*, void*, void*);
extern int32_t supertypeof_jnci_BufferedEncoder(TeaVM_Class*, TeaVM_Class*);
typedef struct jnci_BufferedEncoder_VT {
    jnc_CharsetEncoder_VT parent;
    void* (*virt_arrayEncode)(void*, TeaVM_Array*, int32_t, int32_t, TeaVM_Array*, int32_t, int32_t, void*); // 14
    void* (*virt_encodeLoop)(void*, void*, void*); // 15
} jnci_BufferedEncoder_VT;
extern jnci_BufferedEncoder_VT jnci_BufferedEncoder_Cls;
