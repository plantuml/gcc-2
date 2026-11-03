#pragma once
#include "../../../../runtime.h"
#include "../../l/Object.h"
#include "StandardCharsets.h"

extern void sysinitclass_jnc_StandardCharsets();
typedef struct cls_jnc_StandardCharsets {
    struct TeaVM_Object parent;
} cls_jnc_StandardCharsets;
extern void* sfld_jnc_StandardCharsets_UTF_8;
extern void* sfld_jnc_StandardCharsets_US_ASCII;
extern void* sfld_jnc_StandardCharsets_ISO_8859_1;
extern void* sfld_jnc_StandardCharsets_UTF_16;
extern void* sfld_jnc_StandardCharsets_UTF_16BE;
extern void* sfld_jnc_StandardCharsets_UTF_16LE;
extern void meth_jnc_StandardCharsets__clinit_();
extern void initclass_jnc_StandardCharsets();
extern int32_t supertypeof_jnc_StandardCharsets(TeaVM_Class*, TeaVM_Class*);
typedef struct jnc_StandardCharsets_VT {
    jl_Object_VT parent;
} jnc_StandardCharsets_VT;
extern jnc_StandardCharsets_VT jnc_StandardCharsets_Cls;
