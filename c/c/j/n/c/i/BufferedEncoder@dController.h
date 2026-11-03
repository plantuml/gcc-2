#pragma once
#include "../../../../../runtime.h"
#include "../../../l/Object.h"
#include "BufferedEncoder@dController.h"

extern void sysinitclass_jnci_BufferedEncoder_Controller();
typedef struct cls_jnci_BufferedEncoder_Controller {
    struct TeaVM_Object parent;
    void* fld_in;
    void* fld_out;
    int32_t fld_inPosition;
    int32_t fld_outPosition;
} cls_jnci_BufferedEncoder_Controller;
extern int32_t supertypeof_jnci_BufferedEncoder_Controller(TeaVM_Class*, TeaVM_Class*);
typedef struct jnci_BufferedEncoder_Controller_VT {
    jl_Object_VT parent;
    int32_t (*virt_hasMoreInput)(void*); // 4
    int32_t (*virt_hasMoreInput_0)(void*, int32_t); // 5
    int32_t (*virt_hasMoreOutput)(void*, int32_t); // 6
    void (*virt_setInPosition)(void*, int32_t); // 7
    void (*virt_setOutPosition)(void*, int32_t); // 8
} jnci_BufferedEncoder_Controller_VT;
extern jnci_BufferedEncoder_Controller_VT jnci_BufferedEncoder_Controller_Cls;
