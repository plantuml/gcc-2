#pragma once
#include "../../../../../../runtime.h"
#include "../../../../../j/l/Object.h"
#include "CResources.h"

extern void sysinitclass_otbcr_CResources();
typedef struct cls_otbcr_CResources {
    struct TeaVM_Object parent;
} cls_otbcr_CResources;
extern void* sfld_otbcr_CResources_resources;
extern TeaVM_Array* meth_otbcr_CResources_acquireResources();
extern void* meth_otbcr_CResources_create(void*, int32_t, int32_t);
extern void meth_otbcr_CResources__clinit_();
extern void initclass_otbcr_CResources();
extern int32_t supertypeof_otbcr_CResources(TeaVM_Class*, TeaVM_Class*);
typedef struct otbcr_CResources_VT {
    jl_Object_VT parent;
} otbcr_CResources_VT;
extern otbcr_CResources_VT otbcr_CResources_Cls;
