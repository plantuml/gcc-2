#pragma once
#include "../../../runtime.h"
#include "CharBuffer.h"
#include "CharBufferImpl.h"

extern void sysinitclass_jn_CharBufferImpl();
typedef struct cls_jn_CharBufferImpl {
    struct cls_jn_CharBuffer parent;
} cls_jn_CharBufferImpl;
extern int32_t supertypeof_jn_CharBufferImpl(TeaVM_Class*, TeaVM_Class*);
typedef struct jn_CharBufferImpl_VT {
    jn_CharBuffer_VT parent;
} jn_CharBufferImpl_VT;
extern jn_CharBufferImpl_VT jn_CharBufferImpl_Cls;
