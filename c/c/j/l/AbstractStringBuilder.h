#pragma once
#include "../../../runtime.h"
#include "Object.h"
#include "AbstractStringBuilder.h"

extern void sysinitclass_jl_AbstractStringBuilder();
typedef struct cls_jl_AbstractStringBuilder {
    struct TeaVM_Object parent;
    TeaVM_Array* fld_buffer;
    int32_t fld_length;
} cls_jl_AbstractStringBuilder;
extern void* meth_jl_AbstractStringBuilder_insert(void*, int32_t, void*);
extern void* meth_jl_AbstractStringBuilder_insert_0(void*, int32_t, int32_t, int32_t);
extern void meth_jl_AbstractStringBuilder_ensureCapacity(void*, int32_t);
extern void meth_jl_AbstractStringBuilder_getChars(void*, int32_t, int32_t, TeaVM_Array*, int32_t);
extern void meth_jl_AbstractStringBuilder_insertSpace(void*, int32_t, int32_t);
extern int32_t supertypeof_jl_AbstractStringBuilder(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_AbstractStringBuilder_VT {
    jl_Object_VT parent;
    void* (*virt_append_3)(void*, void*); // 4
    void* (*virt_append_4)(void*, void*); // 5
    void* (*virt_insert_2)(void*, int32_t, void*); // 6
    void* (*virt_append_5)(void*, int32_t); // 7
    void* (*virt_append_6)(void*, int32_t, int32_t); // 8
    void* (*virt_insert_3)(void*, int32_t, int32_t, int32_t); // 9
    void* (*virt_append_7)(void*, int32_t); // 10
    void* (*virt_insert_4)(void*, int32_t, int32_t); // 11
    void* (*virt_insert_5)(void*, int32_t, void*); // 12
    void (*virt_ensureCapacity)(void*, int32_t); // 13
    void* (*virt_toString)(void*); // 14
    int32_t (*virt_length)(void*); // 15
    void (*virt_getChars)(void*, int32_t, int32_t, TeaVM_Array*, int32_t); // 16
    void (*virt_setLength)(void*, int32_t); // 17
} jl_AbstractStringBuilder_VT;
extern jl_AbstractStringBuilder_VT jl_AbstractStringBuilder_Cls;
