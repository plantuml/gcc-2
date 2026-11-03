#pragma once
#include "../../../../runtime.h"

extern void sysinitclass_otr_Relocation();
typedef struct cls_otr_Relocation {
    int32_t fld_classBackup;
    int32_t fld_sizeBackup;
    void* fld_newAddress;
} cls_otr_Relocation;
