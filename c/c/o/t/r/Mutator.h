#pragma once
#include "../../../../runtime.h"
#include "../../../j/l/Object.h"
#include "Mutator.h"

extern void sysinitclass_otr_Mutator();
typedef struct cls_otr_Mutator {
    struct TeaVM_Object parent;
} cls_otr_Mutator;
extern int32_t supertypeof_otr_Mutator(TeaVM_Class*, TeaVM_Class*);
typedef struct otr_Mutator_VT {
    jl_Object_VT parent;
} otr_Mutator_VT;
extern otr_Mutator_VT otr_Mutator_Cls;
