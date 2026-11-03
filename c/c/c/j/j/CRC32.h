#pragma once
#include "../../../../runtime.h"
#include "../../../j/l/Object.h"
#include "CRC32.h"

extern void sysinitclass_cjj_CRC32();
typedef struct cls_cjj_CRC32 {
    struct TeaVM_Object parent;
    int32_t fld_v;
} cls_cjj_CRC32;
extern TeaVM_Array* sfld_cjj_CRC32_crc_table;
extern void meth_cjj_CRC32_update(void*, TeaVM_Array*, int32_t, int32_t);
extern void meth_cjj_CRC32__clinit_();
extern void initclass_cjj_CRC32();
extern int32_t supertypeof_cjj_CRC32(TeaVM_Class*, TeaVM_Class*);
typedef struct cjj_CRC32_VT {
    jl_Object_VT parent;
} cjj_CRC32_VT;
extern cjj_CRC32_VT cjj_CRC32_Cls;
