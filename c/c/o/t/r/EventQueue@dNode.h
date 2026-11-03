#pragma once
#include "../../../../runtime.h"
#include "../../../j/l/Object.h"
#include "EventQueue@dNode.h"

extern void sysinitclass_otr_EventQueue_Node();
typedef struct cls_otr_EventQueue_Node {
    struct TeaVM_Object parent;
    void* fld_event;
    int64_t fld_time;
} cls_otr_EventQueue_Node;
extern int32_t supertypeof_otr_EventQueue_Node(TeaVM_Class*, TeaVM_Class*);
typedef struct otr_EventQueue_Node_VT {
    jl_Object_VT parent;
} otr_EventQueue_Node_VT;
extern otr_EventQueue_Node_VT otr_EventQueue_Node_Cls;
