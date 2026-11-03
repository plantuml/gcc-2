#pragma once
#include "../../../../runtime.h"

extern void sysinitclass_otr_RelocationBlock();
typedef struct cls_otr_RelocationBlock {
    int32_t fld_count;
    void* fld_start;
    void* fld_end;
} cls_otr_RelocationBlock;
