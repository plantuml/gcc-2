#include "EventQueue.h"
#include "../../../j/l/Object.h"
#include "../../../j/l/System.h"
#include "../../../../fiber.h"
#include "EventQueue@dNode.h"
#include "../../../../arrayclass.h"
#include "Allocator.h"
#include "../../../../strings.h"

TeaVM_Array* sfld_otr_EventQueue_data;
int32_t sfld_otr_EventQueue_size;
int8_t sfld_otr_EventQueue_finished;
void meth_otr_EventQueue_process() {
    TEAVM_ALLOC_STACK(INT32_C(0));
    while (1) {
        if (!((sfld_otr_EventQueue_size > INT32_C(0)) && (!sfld_otr_EventQueue_finished))) break;
        TEAVM_WITH_CALL_SITE_ID(139, meth_otr_EventQueue_next());
    }
    TEAVM_RELEASE_STACK;
}
void meth_otr_EventQueue_stop() {
    sfld_otr_EventQueue_finished = INT32_C(1);
}
void meth_otr_EventQueue_next() {
    TeaVM_Array* teavm_local_1;
    int64_t teavm_local_2;
    void* teavm_local_3;
    TEAVM_ALLOC_STACK(INT32_C(1));
    while (1) {
        teavm_local_1 = sfld_otr_EventQueue_data;
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(140, teavm_nullCheck(teavm_local_1));
        if (TEAVM_ARRAY_LENGTH(teavm_local_1)) {
            goto teavm_label_1;
        }
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        teavm_local_2 = ((TEAVM_WITH_CALL_SITE_ID(141, meth_jl_System_currentTimeMillis()) + INT64_C(1000)) - TEAVM_WITH_CALL_SITE_ID(142, meth_jl_System_currentTimeMillis()));
        if ((teavm_local_2 > INT64_C(0))) {
            TEAVM_WITH_CALL_SITE_ID(143, teavm_waitFor(teavm_local_2));
        }
    }
teavm_label_1:;
    teavm_local_3 = TEAVM_ARRAY_AT(teavm_local_1, void*, TEAVM_WITH_CALL_SITE_ID(144, teavm_checkUpperBound(INT32_C(0), teavm_local_1)));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_3);
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(145, teavm_nullCheck(teavm_local_3));
    teavm_local_2 = (TEAVM_FIELD(teavm_local_3, cls_otr_EventQueue_Node, fld_time) - TEAVM_WITH_CALL_SITE_ID(146, meth_jl_System_currentTimeMillis()));
    if ((teavm_local_2 > INT64_C(0))) {
        TEAVM_WITH_CALL_SITE_ID(147, teavm_waitFor(teavm_local_2));
    }
    if ((TEAVM_FIELD(teavm_local_3, cls_otr_EventQueue_Node, fld_time) <= TEAVM_WITH_CALL_SITE_ID(148, meth_jl_System_currentTimeMillis()))) {
        TEAVM_WITH_CALL_SITE_ID(149, meth_otr_EventQueue_remove(INT32_C(0)));
        teavm_local_3 = TEAVM_FIELD(teavm_local_3, cls_otr_EventQueue_Node, fld_event);
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_3);
        TEAVM_WITH_CALL_SITE_ID(150, (TEAVM_WITH_CALL_SITE_ID(151, teavm_nullCheck(teavm_local_3)), NULL));
    }
    TEAVM_RELEASE_STACK;
}
void meth_otr_EventQueue_remove(int32_t teavm_local_1) {
    int32_t teavm_local_2;
    TeaVM_Array* teavm_local_3;
    void* teavm_local_4;
    TEAVM_ALLOC_STACK(INT32_C(2));
    teavm_local_2 = (sfld_otr_EventQueue_size - INT32_C(1));
    sfld_otr_EventQueue_size = teavm_local_2;
    if ((teavm_local_1 < teavm_local_2)) {
        teavm_local_3 = sfld_otr_EventQueue_data;
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_3);
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(152, teavm_nullCheck(teavm_local_3));
        teavm_local_4 = TEAVM_ARRAY_AT(teavm_local_3, void*, TEAVM_WITH_CALL_SITE_ID(153, teavm_checkBounds(teavm_local_2, teavm_local_3)));
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_4);
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(154, teavm_checkBounds(teavm_local_1, teavm_local_3));
        teavm_gc_writeBarrier(teavm_local_3);
        TEAVM_ARRAY_AT(teavm_local_3, void*, teavm_local_1) = teavm_local_4;
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        TEAVM_WITH_CALL_SITE_ID(155, meth_otr_EventQueue_update(teavm_local_1));
    }
    teavm_local_3 = sfld_otr_EventQueue_data;
    teavm_local_1 = sfld_otr_EventQueue_size;
    teavm_local_4 = NULL;
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_3);
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(156, teavm_nullCheck(teavm_local_3));
    TEAVM_ARRAY_AT(teavm_local_3, void*, TEAVM_WITH_CALL_SITE_ID(157, teavm_checkBounds(teavm_local_1, teavm_local_3))) = teavm_local_4;
    TEAVM_RELEASE_STACK;
}
void meth_otr_EventQueue_update(int32_t teavm_local_1) {
    TeaVM_Array* teavm_local_2;
    void* teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    int32_t teavm_local_6;
    int32_t teavm_local_7;
    void* teavm_local_8;
    int64_t teavm_local_9;
    TEAVM_ALLOC_STACK(INT32_C(3));
    teavm_local_2 = sfld_otr_EventQueue_data;
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(158, teavm_nullCheck(teavm_local_2));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(159, teavm_checkBounds(teavm_local_1, teavm_local_2));
    teavm_local_3 = TEAVM_ARRAY_AT(teavm_local_2, void*, teavm_local_1);
    while (1) {
        teavm_local_4 = ((teavm_local_1 * INT32_C(2)) + INT32_C(1));
        teavm_local_5 = (teavm_local_4 + INT32_C(1));
        teavm_local_6 = sfld_otr_EventQueue_size;
        if ((teavm_local_4 >= teavm_local_6)) {
            goto teavm_label_3;
        }
        if ((teavm_local_5 < teavm_local_6)) {
            TEAVM_GC_ROOT(INT32_C(2), teavm_local_3);
            teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(160, teavm_checkBounds(teavm_local_4, teavm_local_2));
            teavm_local_8 = TEAVM_ARRAY_AT(teavm_local_2, void*, teavm_local_7);
            TEAVM_GC_ROOT(INT32_C(1), teavm_local_8);
            teavm_local_9 = TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(161, teavm_nullCheck(teavm_local_8)), cls_otr_EventQueue_Node, fld_time);
            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(162, teavm_checkBounds(teavm_local_5, teavm_local_2));
            teavm_local_8 = TEAVM_ARRAY_AT(teavm_local_2, void*, teavm_local_4);
            TEAVM_GC_ROOT(INT32_C(1), teavm_local_8);
            if ((teavm_local_9 < TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(163, teavm_nullCheck(teavm_local_8)), cls_otr_EventQueue_Node, fld_time))) {
                teavm_local_4 = teavm_local_7;
            }
        }
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_3);
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(164, teavm_nullCheck(teavm_local_3));
        teavm_local_9 = TEAVM_FIELD(teavm_local_3, cls_otr_EventQueue_Node, fld_time);
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(165, teavm_checkBounds(teavm_local_4, teavm_local_2));
        teavm_local_8 = TEAVM_ARRAY_AT(teavm_local_2, void*, teavm_local_6);
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_8);
        if ((teavm_local_9 <= TEAVM_FIELD(TEAVM_WITH_CALL_SITE_ID(166, teavm_nullCheck(teavm_local_8)), cls_otr_EventQueue_Node, fld_time))) {
            goto teavm_label_2;
        }
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(167, teavm_checkUpperBound(teavm_local_6, teavm_local_2));
        teavm_local_8 = TEAVM_ARRAY_AT(teavm_local_2, void*, teavm_local_6);
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_8);
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(168, teavm_checkBounds(teavm_local_1, teavm_local_2));
        teavm_gc_writeBarrier(teavm_local_2);
        TEAVM_ARRAY_AT(teavm_local_2, void*, teavm_local_1) = teavm_local_8;
        teavm_local_1 = teavm_local_6;
    }
teavm_label_3:;
    goto teavm_label_1;
teavm_label_2:;
teavm_label_1:;
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(169, teavm_checkBounds(teavm_local_1, teavm_local_2));
    teavm_gc_writeBarrier(teavm_local_2);
    TEAVM_ARRAY_AT(teavm_local_2, void*, teavm_local_1) = teavm_local_3;
    TEAVM_RELEASE_STACK;
}
void meth_otr_EventQueue__clinit_() {
    TEAVM_ALLOC_STACK(INT32_C(0));
    sfld_otr_EventQueue_data = TEAVM_WITH_CALL_SITE_ID(170, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &otr_EventQueue_Node_Cls), INT32_C(16)));
    TEAVM_RELEASE_STACK;
}
int32_t supertypeof_otr_EventQueue(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 109 || tag >= 111) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) otr_EventQueue_VT otr_EventQueue_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otr_EventQueue), sizeof(void*)),
            .flags = 0,
            .tag = 109,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_otr_EventQueue,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static void** teavm_gc_localStaticRoots_otr_EventQueue_Cls[1] = {
(void**) &sfld_otr_EventQueue_data
};
void sysinitclass_otr_EventQueue() {
sfld_otr_EventQueue_data = NULL;
sfld_otr_EventQueue_size = INT32_C(0);
sfld_otr_EventQueue_finished = 0;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_otr_EventQueue_Cls, 1);
}
