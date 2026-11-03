#pragma once
#include "../../../runtime.h"
#include "../l/Object.h"
#include "ByteOrder.h"

extern void sysinitclass_jn_ByteOrder();
typedef struct cls_jn_ByteOrder {
    struct TeaVM_Object parent;
    void* fld_name;
} cls_jn_ByteOrder;
extern void* sfld_jn_ByteOrder_BIG_ENDIAN;
extern void* sfld_jn_ByteOrder_LITTLE_ENDIAN;
extern void* sfld_jn_ByteOrder_nativeOrder;
extern void* meth_jn_ByteOrder_nativeOrder();
extern void meth_jn_ByteOrder__clinit_();
extern void initclass_jn_ByteOrder();
extern int32_t supertypeof_jn_ByteOrder(TeaVM_Class*, TeaVM_Class*);
typedef struct jn_ByteOrder_VT {
    jl_Object_VT parent;
} jn_ByteOrder_VT;
extern jn_ByteOrder_VT jn_ByteOrder_Cls;
