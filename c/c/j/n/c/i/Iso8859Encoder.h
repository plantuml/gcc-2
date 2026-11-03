#pragma once
#include "../../../../../runtime.h"
#include "BufferedEncoder.h"
#include "Iso8859Encoder.h"

extern void sysinitclass_jnci_Iso8859Encoder();
typedef struct cls_jnci_Iso8859Encoder {
    struct cls_jnci_BufferedEncoder parent;
} cls_jnci_Iso8859Encoder;
extern void* meth_jnci_Iso8859Encoder_arrayEncode(void*, TeaVM_Array*, int32_t, int32_t, TeaVM_Array*, int32_t, int32_t, void*);
extern int32_t supertypeof_jnci_Iso8859Encoder(TeaVM_Class*, TeaVM_Class*);
typedef struct jnci_Iso8859Encoder_VT {
    jnci_BufferedEncoder_VT parent;
} jnci_Iso8859Encoder_VT;
extern jnci_Iso8859Encoder_VT jnci_Iso8859Encoder_Cls;
