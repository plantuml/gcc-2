#pragma once
#include "../../../../../runtime.h"
#include "../Charset.h"
#include "AsciiCharset.h"

extern void sysinitclass_jnci_AsciiCharset();
typedef struct cls_jnci_AsciiCharset {
    struct cls_jnc_Charset parent;
} cls_jnci_AsciiCharset;
extern int32_t supertypeof_jnci_AsciiCharset(TeaVM_Class*, TeaVM_Class*);
typedef struct jnci_AsciiCharset_VT {
    jnc_Charset_VT parent;
} jnci_AsciiCharset_VT;
extern jnci_AsciiCharset_VT jnci_AsciiCharset_Cls;
