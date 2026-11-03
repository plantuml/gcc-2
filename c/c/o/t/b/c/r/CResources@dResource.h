#pragma once
#include "../../../../../../runtime.h"
#include "../../../../../j/l/Object.h"
#include "CResources@dResource.h"

extern void sysinitclass_otbcr_CResources_Resource();
typedef struct cls_otbcr_CResources_Resource {
    struct TeaVM_Object parent;
    void* fld_name;
    void* fld_start;
    int32_t fld_length;
} cls_otbcr_CResources_Resource;
extern int32_t supertypeof_otbcr_CResources_Resource(TeaVM_Class*, TeaVM_Class*);
typedef struct otbcr_CResources_Resource_VT {
    jl_Object_VT parent;
} otbcr_CResources_Resource_VT;
extern otbcr_CResources_Resource_VT otbcr_CResources_Resource_Cls;
