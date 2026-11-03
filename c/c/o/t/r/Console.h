#pragma once
#include "../../../../runtime.h"
#include "../../../j/l/Object.h"
#include "Console.h"

extern void sysinitclass_otr_Console();
typedef struct cls_otr_Console {
    struct TeaVM_Object parent;
} cls_otr_Console;
extern int32_t supertypeof_otr_Console(TeaVM_Class*, TeaVM_Class*);
typedef struct otr_Console_VT {
    jl_Object_VT parent;
} otr_Console_VT;
extern otr_Console_VT otr_Console_Cls;
