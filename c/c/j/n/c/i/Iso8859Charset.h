#pragma once
#include "../../../../../runtime.h"
#include "../Charset.h"
#include "Iso8859Charset.h"

extern void sysinitclass_jnci_Iso8859Charset();
typedef struct cls_jnci_Iso8859Charset {
    struct cls_jnc_Charset parent;
} cls_jnci_Iso8859Charset;
extern void* meth_jnci_Iso8859Charset_newEncoder(void*);
extern int32_t supertypeof_jnci_Iso8859Charset(TeaVM_Class*, TeaVM_Class*);
typedef struct jnci_Iso8859Charset_VT {
    jnc_Charset_VT parent;
    void* (*virt_newEncoder)(void*); // 5
} jnci_Iso8859Charset_VT;
extern jnci_Iso8859Charset_VT jnci_Iso8859Charset_Cls;
