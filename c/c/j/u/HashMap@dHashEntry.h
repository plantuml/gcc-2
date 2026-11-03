#pragma once
#include "../../../runtime.h"
#include "MapEntry.h"
#include "HashMap@dHashEntry.h"

extern void sysinitclass_ju_HashMap_HashEntry();
typedef struct cls_ju_HashMap_HashEntry {
    struct cls_ju_MapEntry parent;
    int32_t fld_origKeyHash;
    void* fld_next;
} cls_ju_HashMap_HashEntry;
extern int32_t supertypeof_ju_HashMap_HashEntry(TeaVM_Class*, TeaVM_Class*);
typedef struct ju_HashMap_HashEntry_VT {
    ju_MapEntry_VT parent;
} ju_HashMap_HashEntry_VT;
extern ju_HashMap_HashEntry_VT ju_HashMap_HashEntry_Cls;
