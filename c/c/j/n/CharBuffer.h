#pragma once
#include "../../../runtime.h"
#include "Buffer.h"
#include "CharBuffer.h"

extern void sysinitclass_jn_CharBuffer();
typedef struct cls_jn_CharBuffer {
    struct cls_jn_Buffer parent;
} cls_jn_CharBuffer;
extern void* meth_jn_CharBuffer_wrap(TeaVM_Array*, int32_t, int32_t);
extern void* meth_jn_CharBuffer_get(void*, TeaVM_Array*, int32_t, int32_t);
extern int32_t supertypeof_jn_CharBuffer(TeaVM_Class*, TeaVM_Class*);
typedef struct jn_CharBuffer_VT {
    jn_Buffer_VT parent;
    void* (*virt_get)(void*, TeaVM_Array*, int32_t, int32_t); // 12
    void* (*virt_position)(void*, int32_t); // 13
} jn_CharBuffer_VT;
extern jn_CharBuffer_VT jn_CharBuffer_Cls;
