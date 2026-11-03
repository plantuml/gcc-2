#pragma once
#include "../../../../../runtime.h"
#include "../Charset.h"
#include "UTF8Charset.h"

extern void sysinitclass_jnci_UTF8Charset();
typedef struct cls_jnci_UTF8Charset {
    struct cls_jnc_Charset parent;
} cls_jnci_UTF8Charset;
extern void* sfld_jnci_UTF8Charset_INSTANCE;
extern void meth_jnci_UTF8Charset__clinit_();
extern void initclass_jnci_UTF8Charset();
extern int32_t supertypeof_jnci_UTF8Charset(TeaVM_Class*, TeaVM_Class*);
typedef struct jnci_UTF8Charset_VT {
    jnc_Charset_VT parent;
    void* (*virt_newEncoder)(void*); // 5
} jnci_UTF8Charset_VT;
extern jnci_UTF8Charset_VT jnci_UTF8Charset_Cls;
