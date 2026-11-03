#pragma once
#include "../../../../../runtime.h"
#include "../Charset.h"
#include "UTF16Charset.h"

extern void sysinitclass_jnci_UTF16Charset();
typedef struct cls_jnci_UTF16Charset {
    struct cls_jnc_Charset parent;
    int8_t fld_bom;
    int8_t fld_littleEndian;
} cls_jnci_UTF16Charset;
extern int32_t supertypeof_jnci_UTF16Charset(TeaVM_Class*, TeaVM_Class*);
typedef struct jnci_UTF16Charset_VT {
    jnc_Charset_VT parent;
} jnci_UTF16Charset_VT;
extern jnci_UTF16Charset_VT jnci_UTF16Charset_Cls;
