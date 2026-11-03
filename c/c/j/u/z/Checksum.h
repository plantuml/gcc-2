#pragma once
#include "../../../../runtime.h"
#include "Checksum.h"

extern void sysinitclass_juz_Checksum();
extern int32_t supertypeof_juz_Checksum(TeaVM_Class*, TeaVM_Class*);
typedef struct juz_Checksum_VT {
    TeaVM_Class parent;
    void (*pad0)(); // 0
    void* (*virt_clone)(void*); // 1
} juz_Checksum_VT;
extern TeaVM_Class juz_Checksum_Cls;
