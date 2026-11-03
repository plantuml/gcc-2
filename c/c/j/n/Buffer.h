#pragma once
#include "../../../runtime.h"
#include "../l/Object.h"
#include "Buffer.h"

extern void sysinitclass_jn_Buffer();
typedef struct cls_jn_Buffer {
    struct TeaVM_Object parent;
    void* fld_nextRef;
    int32_t fld_position;
    int32_t fld_limit;
    int32_t fld_mark;
} cls_jn_Buffer;
extern void* meth_jn_Buffer_position(void*, int32_t);
extern int32_t supertypeof_jn_Buffer(TeaVM_Class*, TeaVM_Class*);
typedef struct jn_Buffer_VT {
    jl_Object_VT parent;
    int32_t (*virt_capacity)(void*); // 4
    int32_t (*virt_position_0)(void*); // 5
    void* (*virt_position_1)(void*, int32_t); // 6
    int32_t (*virt_limit)(void*); // 7
    void* (*virt_clear)(void*); // 8
    void* (*virt_flip)(void*); // 9
    int32_t (*virt_remaining)(void*); // 10
    int32_t (*virt_hasRemaining)(void*); // 11
} jn_Buffer_VT;
extern jn_Buffer_VT jn_Buffer_Cls;
