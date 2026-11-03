#pragma once
#include "../../../../runtime.h"
#include "../../../j/l/Object.h"
#include "MarkQueue.h"

extern void sysinitclass_otr_MarkQueue();
typedef struct cls_otr_MarkQueue {
    struct TeaVM_Object parent;
} cls_otr_MarkQueue;
extern int32_t sfld_otr_MarkQueue_head;
extern int32_t sfld_otr_MarkQueue_tail;
extern int32_t sfld_otr_MarkQueue_limit;
extern void meth_otr_MarkQueue_init();
extern void meth_otr_MarkQueue_enqueue(void*);
extern void* meth_otr_MarkQueue_dequeue();
extern int32_t meth_otr_MarkQueue_pack(void*);
extern void* meth_otr_MarkQueue_unpack(int32_t);
extern int32_t meth_otr_MarkQueue_isEmpty();
extern int32_t supertypeof_otr_MarkQueue(TeaVM_Class*, TeaVM_Class*);
typedef struct otr_MarkQueue_VT {
    jl_Object_VT parent;
} otr_MarkQueue_VT;
extern otr_MarkQueue_VT otr_MarkQueue_Cls;
