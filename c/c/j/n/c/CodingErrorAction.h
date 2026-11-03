#pragma once
#include "../../../../runtime.h"
#include "../../l/Object.h"
#include "CodingErrorAction.h"

extern void sysinitclass_jnc_CodingErrorAction();
typedef struct cls_jnc_CodingErrorAction {
    struct TeaVM_Object parent;
    void* fld_name;
} cls_jnc_CodingErrorAction;
extern void* sfld_jnc_CodingErrorAction_IGNORE;
extern void* sfld_jnc_CodingErrorAction_REPLACE;
extern void* sfld_jnc_CodingErrorAction_REPORT;
extern void meth_jnc_CodingErrorAction__clinit_();
extern void initclass_jnc_CodingErrorAction();
extern int32_t supertypeof_jnc_CodingErrorAction(TeaVM_Class*, TeaVM_Class*);
typedef struct jnc_CodingErrorAction_VT {
    jl_Object_VT parent;
} jnc_CodingErrorAction_VT;
extern jnc_CodingErrorAction_VT jnc_CodingErrorAction_Cls;
