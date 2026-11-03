#pragma once
#include "../../../../../runtime.h"
#include "../../../../j/l/Object.h"
#include "IntegerUtil.h"

extern void sysinitclass_otci_IntegerUtil();
typedef struct cls_otci_IntegerUtil {
    struct TeaVM_Object parent;
} cls_otci_IntegerUtil;
extern void* meth_otci_IntegerUtil_toUnsignedLogRadixString(int64_t, int32_t);
extern int32_t supertypeof_otci_IntegerUtil(TeaVM_Class*, TeaVM_Class*);
typedef struct otci_IntegerUtil_VT {
    jl_Object_VT parent;
} otci_IntegerUtil_VT;
extern otci_IntegerUtil_VT otci_IntegerUtil_Cls;
