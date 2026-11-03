#pragma once
#include "../../../../runtime.h"
#include "Checksum.h"

extern void sysinitclass_cjj_Checksum();
extern int32_t supertypeof_cjj_Checksum(TeaVM_Class*, TeaVM_Class*);
typedef struct cjj_Checksum_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} cjj_Checksum_VT;
extern TeaVM_Class cjj_Checksum_Cls;
