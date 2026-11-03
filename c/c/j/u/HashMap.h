#pragma once
#include "../../../runtime.h"
#include "AbstractMap.h"
#include "HashMap.h"

extern void sysinitclass_ju_HashMap();
typedef struct cls_ju_HashMap {
    struct cls_ju_AbstractMap parent;
    int32_t fld_elementCount;
    TeaVM_Array* fld_elementData;
    int32_t fld_modCount;
    float fld_loadFactor;
    int32_t fld_threshold;
} cls_ju_HashMap;
extern int32_t meth_ju_HashMap_calculateCapacity(int32_t);
extern void* meth_ju_HashMap_putImpl(void*, void*, void*);
extern void meth_ju_HashMap_rehash(void*, int32_t);
extern int32_t supertypeof_ju_HashMap(TeaVM_Class*, TeaVM_Class*);
typedef struct ju_HashMap_VT {
    ju_AbstractMap_VT parent;
    TeaVM_Array* (*virt_newElementArray)(void*, int32_t); // 4
    void* (*virt_findNonNullKeyEntry)(void*, void*, int32_t, int32_t); // 5
    void* (*virt_findNullKeyEntry)(void*); // 6
    void* (*virt_put)(void*, void*, void*); // 7
    void (*virt_rehash)(void*, int32_t); // 8
    void (*virt_rehash_0)(void*); // 9
} ju_HashMap_VT;
extern ju_HashMap_VT ju_HashMap_Cls;
