#pragma once
#include "../../../../runtime.h"
#include "../../../j/l/Object.h"
#include "EventQueue.h"

extern void sysinitclass_otr_EventQueue();
typedef struct cls_otr_EventQueue {
    struct TeaVM_Object parent;
} cls_otr_EventQueue;
extern TeaVM_Array* sfld_otr_EventQueue_data;
extern int32_t sfld_otr_EventQueue_size;
extern int8_t sfld_otr_EventQueue_finished;
extern void meth_otr_EventQueue_process();
extern void meth_otr_EventQueue_stop();
extern void meth_otr_EventQueue_next();
extern void meth_otr_EventQueue_remove(int32_t);
extern void meth_otr_EventQueue_update(int32_t);
extern void meth_otr_EventQueue__clinit_();
extern int32_t supertypeof_otr_EventQueue(TeaVM_Class*, TeaVM_Class*);
typedef struct otr_EventQueue_VT {
    jl_Object_VT parent;
} otr_EventQueue_VT;
extern otr_EventQueue_VT otr_EventQueue_Cls;
