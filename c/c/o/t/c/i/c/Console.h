#pragma once
#include "../../../../../../runtime.h"
#include "../../../../../j/l/Object.h"
#include "Console.h"

extern void sysinitclass_otcic_Console();
typedef struct cls_otcic_Console {
    struct TeaVM_Object parent;
} cls_otcic_Console;
extern int32_t supertypeof_otcic_Console(TeaVM_Class*, TeaVM_Class*);
typedef struct otcic_Console_VT {
    jl_Object_VT parent;
} otcic_Console_VT;
extern otcic_Console_VT otcic_Console_Cls;
