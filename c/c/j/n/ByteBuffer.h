#pragma once
#include "../../../runtime.h"
#include "Buffer.h"
#include "ByteBuffer.h"

extern void sysinitclass_jn_ByteBuffer();
typedef struct cls_jn_ByteBuffer {
    struct cls_jn_Buffer parent;
    void* fld_order;
} cls_jn_ByteBuffer;
extern void* meth_jn_ByteBuffer_allocate(int32_t);
extern void* meth_jn_ByteBuffer_get(void*, TeaVM_Array*, int32_t, int32_t);
extern void* meth_jn_ByteBuffer_put(void*, TeaVM_Array*, int32_t, int32_t);
extern int32_t supertypeof_jn_ByteBuffer(TeaVM_Class*, TeaVM_Class*);
typedef struct jn_ByteBuffer_VT {
    jn_Buffer_VT parent;
    void* (*virt_get_0)(void*, TeaVM_Array*, int32_t, int32_t); // 12
    void* (*virt_get_1)(void*, TeaVM_Array*); // 13
    void* (*virt_put_0)(void*, TeaVM_Array*, int32_t, int32_t); // 14
    void* (*virt_put_1)(void*, TeaVM_Array*); // 15
    int32_t (*virt_hasArray)(void*); // 16
    TeaVM_Array* (*virt_array)(void*); // 17
    void* (*virt_clear_0)(void*); // 18
    void* (*virt_flip_0)(void*); // 19
    void* (*virt_position_2)(void*, int32_t); // 20
} jn_ByteBuffer_VT;
extern jn_ByteBuffer_VT jn_ByteBuffer_Cls;
