#pragma once
#include "../../../../../runtime.h"
#include "BufferedEncoder.h"
#include "UTF8Encoder.h"

extern void sysinitclass_jnci_UTF8Encoder();
typedef struct cls_jnci_UTF8Encoder {
    struct cls_jnci_BufferedEncoder parent;
} cls_jnci_UTF8Encoder;
extern void* meth_jnci_UTF8Encoder_arrayEncode(void*, TeaVM_Array*, int32_t, int32_t, TeaVM_Array*, int32_t, int32_t, void*);
extern int32_t supertypeof_jnci_UTF8Encoder(TeaVM_Class*, TeaVM_Class*);
typedef struct jnci_UTF8Encoder_VT {
    jnci_BufferedEncoder_VT parent;
} jnci_UTF8Encoder_VT;
extern jnci_UTF8Encoder_VT jnci_UTF8Encoder_Cls;
