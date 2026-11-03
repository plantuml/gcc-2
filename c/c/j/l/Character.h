#pragma once
#include "../../../runtime.h"
#include "Object.h"
#include "Character.h"

extern void sysinitclass_jl_Character();
typedef struct cls_jl_Character {
    struct TeaVM_Object parent;
} cls_jl_Character;
extern void* sfld_jl_Character_TYPE;
extern TeaVM_Array* sfld_jl_Character_characterCache;
extern int32_t meth_jl_Character_forDigit(int32_t, int32_t);
extern void meth_jl_Character__clinit_();
extern void initclass_jl_Character();
extern int32_t supertypeof_jl_Character(TeaVM_Class*, TeaVM_Class*);
typedef struct jl_Character_VT {
    jl_Object_VT parent;
} jl_Character_VT;
extern jl_Character_VT jl_Character_Cls;
