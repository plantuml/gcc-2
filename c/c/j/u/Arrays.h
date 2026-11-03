#pragma once
#include "../../../runtime.h"
#include "../l/Object.h"
#include "Arrays.h"

extern void sysinitclass_ju_Arrays();
typedef struct cls_ju_Arrays {
    struct TeaVM_Object parent;
} cls_ju_Arrays;
extern TeaVM_Array* meth_ju_Arrays_copyOf(TeaVM_Array*, int32_t);
extern TeaVM_Array* meth_ju_Arrays_copyOf_0(TeaVM_Array*, int32_t);
extern TeaVM_Array* meth_ju_Arrays_copyOf_1(TeaVM_Array*, int32_t);
extern TeaVM_Array* meth_ju_Arrays_copyOf_2(TeaVM_Array*, int32_t);
extern TeaVM_Array* meth_ju_Arrays_copyOf_3(TeaVM_Array*, int32_t);
extern int32_t supertypeof_ju_Arrays(TeaVM_Class*, TeaVM_Class*);
typedef struct ju_Arrays_VT {
    jl_Object_VT parent;
} ju_Arrays_VT;
extern ju_Arrays_VT ju_Arrays_Cls;
