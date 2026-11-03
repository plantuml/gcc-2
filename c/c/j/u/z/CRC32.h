#pragma once
#include "../../../../runtime.h"
#include "../../l/Object.h"
#include "CRC32.h"

extern void sysinitclass_juz_CRC32();
typedef struct cls_juz_CRC32 {
    struct TeaVM_Object parent;
    void* fld_impl;
    int64_t fld_tbytes;
} cls_juz_CRC32;
extern void meth_juz_CRC32_update(void*, TeaVM_Array*, int32_t, int32_t);
extern int32_t supertypeof_juz_CRC32(TeaVM_Class*, TeaVM_Class*);
typedef struct juz_CRC32_VT {
    jl_Object_VT parent;
    int64_t (*virt_getValue)(void*); // 4
    void (*virt_update)(void*, TeaVM_Array*); // 5
    void (*virt_update_0)(void*, TeaVM_Array*, int32_t, int32_t); // 6
} juz_CRC32_VT;
extern juz_CRC32_VT juz_CRC32_Cls;
