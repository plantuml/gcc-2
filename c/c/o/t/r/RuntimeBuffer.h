#pragma once
#include "../../../../runtime.h"
#include "RuntimeObject.h"

extern void sysinitclass_otr_RuntimeBuffer();
typedef struct cls_otr_RuntimeBuffer {
    struct TeaVM_Object parent;
    void* fld_nextRef;
} cls_otr_RuntimeBuffer;
