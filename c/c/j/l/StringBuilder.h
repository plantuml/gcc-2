#pragma once
#include "../../../runtime.h"
#include "AbstractStringBuilder.h"
#include "StringBuilder.h"

extern void sysinitclass_jl_StringBuilder();
typedef struct cls_jl_StringBuilder {
    struct cls_jl_AbstractStringBuilder parent;
} cls_jl_StringBuilder;
extern int32_t supertypeof_jl_StringBuilder(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_StringBuilder_VT {
    jl_AbstractStringBuilder_VT parent;
    void* (*virt_append)(void*, void*); // 18
    void* (*virt_append_0)(void*, void*); // 19
    void* (*virt_append_1)(void*, int32_t); // 20
    void* (*virt_append_2)(void*, int32_t); // 21
    void* (*virt_insert)(void*, int32_t, void*); // 22
    void* (*virt_insert_0)(void*, int32_t, int32_t); // 23
    void* (*virt_insert_1)(void*, int32_t, void*); // 24
} jl_StringBuilder_VT;
extern jl_StringBuilder_VT jl_StringBuilder_Cls;
