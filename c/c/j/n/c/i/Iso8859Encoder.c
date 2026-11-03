#include "Iso8859Encoder.h"
#include "BufferedEncoder.h"
#include "../../../l/Character.h"
#include "../CoderResult.h"
#include "../../../../o/t/r/Allocator.h"
#include "BufferedEncoder@dController.h"
#include "../../Buffer.h"
#include "../../../../../strings.h"
#include "../../../l/Object.h"

void* meth_jnci_Iso8859Encoder_arrayEncode(void* teavm_this_, TeaVM_Array* teavm_local_1, int32_t teavm_local_2, int32_t teavm_local_3, TeaVM_Array* teavm_local_4, int32_t teavm_local_5, int32_t teavm_local_6, void* teavm_local_7) {
    void* teavm_local_8;
    int32_t teavm_local_9;
    TeaVM_Array* teavm_local_10;
    int32_t teavm_local_11;
    int32_t teavm_local_12;
    void* teavm_local_13;
    TEAVM_ALLOC_STACK(INT32_C(3));
    teavm_local_8 = NULL;
    while (1) {
        if (!(teavm_local_2 < teavm_local_3)) break;
        if ((teavm_local_5 >= teavm_local_6)) {
            goto teavm_label_4;
        }
        teavm_local_9 = (teavm_local_2 + INT32_C(1));
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_8);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_4);
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(810, teavm_nullCheck(teavm_local_1));
        teavm_local_10 = teavm_local_1;
        teavm_local_11 = TEAVM_ARRAY_AT(teavm_local_10, char16_t, TEAVM_WITH_CALL_SITE_ID(811, teavm_checkBounds(teavm_local_2, teavm_local_10)));
        TEAVM_WITH_CALL_SITE_ID(812, teavm_initializeClass((TeaVM_Class*) &jl_Character_Cls, &initclass_jl_Character));
        teavm_local_12 = (teavm_local_11 & INT32_C(64512));
        if (((teavm_local_12 != INT32_C(55296)) ? INT32_C(0) : INT32_C(1))) {
            goto teavm_label_2;
        }
        if (((teavm_local_12 != INT32_C(56320)) ? INT32_C(0) : INT32_C(1))) {
            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
            TEAVM_WITH_CALL_SITE_ID(813, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
            teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(814, meth_otr_Allocator_allocate(&jnc_CoderResult_Cls));
            TEAVM_FIELD(teavm_local_8, cls_jnc_CoderResult, fld_kind) = INT32_C(2);
            TEAVM_FIELD(teavm_local_8, cls_jnc_CoderResult, fld_length) = INT32_C(1);
        }
        if ((teavm_local_11 >= INT32_C(256))) {
            goto teavm_label_3;
        }
        teavm_local_12 = (teavm_local_5 + INT32_C(1));
        teavm_local_11 = TEAVM_TO_BYTE(teavm_local_11);
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_8);
        teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(815, teavm_nullCheck(teavm_local_4));
        teavm_local_10 = teavm_local_4;
        TEAVM_ARRAY_AT(teavm_local_10, int8_t, TEAVM_WITH_CALL_SITE_ID(816, teavm_checkBounds(teavm_local_5, teavm_local_10))) = teavm_local_11;
        teavm_local_2 = teavm_local_9;
        teavm_local_5 = teavm_local_12;
    }
    teavm_local_9 = teavm_local_2;
    goto teavm_label_1;
teavm_label_4:;
    teavm_local_9 = teavm_local_2;
    goto teavm_label_1;
teavm_label_3:;
    teavm_local_9 = (teavm_local_9 + -INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_WITH_CALL_SITE_ID(817, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
    teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(818, meth_otr_Allocator_allocate(&jnc_CoderResult_Cls));
    TEAVM_FIELD(teavm_local_8, cls_jnc_CoderResult, fld_kind) = INT32_C(3);
    TEAVM_FIELD(teavm_local_8, cls_jnc_CoderResult, fld_length) = INT32_C(1);
    goto teavm_label_1;
teavm_label_2:;
    if ((teavm_local_9 == teavm_local_3)) {
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
        teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(819, teavm_nullCheck(teavm_local_7));
        teavm_local_13 = TEAVM_FIELD(teavm_local_7, cls_jnci_BufferedEncoder_Controller, fld_in);
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_13);
        teavm_local_13 = TEAVM_WITH_CALL_SITE_ID(820, teavm_nullCheck(teavm_local_13));
        if ((((TEAVM_FIELD(teavm_local_13, cls_jn_Buffer, fld_limit) - TEAVM_FIELD(teavm_local_13, cls_jn_Buffer, fld_position)) < INT32_C(2)) ? INT32_C(0) : INT32_C(1))) {
            teavm_local_9 = (teavm_local_9 + -INT32_C(1));
        } else {
            TEAVM_GC_ROOT_RELEASE(INT32_C(1));
            TEAVM_GC_ROOT_RELEASE(INT32_C(2));
            TEAVM_WITH_CALL_SITE_ID(821, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
            teavm_local_8 = sfld_jnc_CoderResult_UNDERFLOW;
        }
    } else {
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
        teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(822, teavm_checkBounds(teavm_local_9, teavm_local_10));
        if ((!(((TEAVM_ARRAY_AT(teavm_local_10, char16_t, teavm_local_9) & INT32_C(64512)) != INT32_C(56320)) ? INT32_C(0) : INT32_C(1)))) {
            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
            TEAVM_WITH_CALL_SITE_ID(823, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
            teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(824, meth_otr_Allocator_allocate(&jnc_CoderResult_Cls));
            TEAVM_FIELD(teavm_local_8, cls_jnc_CoderResult, fld_kind) = INT32_C(2);
            TEAVM_FIELD(teavm_local_8, cls_jnc_CoderResult, fld_length) = INT32_C(1);
        } else {
            teavm_local_9 = (teavm_local_9 + -INT32_C(1));
            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
            TEAVM_WITH_CALL_SITE_ID(825, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
            teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(826, meth_otr_Allocator_allocate(&jnc_CoderResult_Cls));
            TEAVM_FIELD(teavm_local_8, cls_jnc_CoderResult, fld_kind) = INT32_C(3);
            TEAVM_FIELD(teavm_local_8, cls_jnc_CoderResult, fld_length) = INT32_C(2);
        }
    }
teavm_label_1:;
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_8);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_7);
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(827, teavm_nullCheck(teavm_local_7));
    TEAVM_FIELD(teavm_local_7, cls_jnci_BufferedEncoder_Controller, fld_inPosition) = teavm_local_9;
    TEAVM_FIELD(teavm_local_7, cls_jnci_BufferedEncoder_Controller, fld_outPosition) = teavm_local_5;
    TEAVM_RELEASE_STACK;
    return teavm_local_8;
}
int32_t supertypeof_jnci_Iso8859Encoder(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 207 || tag >= 209) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jnci_Iso8859Encoder_VT jnci_Iso8859Encoder_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnci_Iso8859Encoder), sizeof(void*)),
                    .flags = 0,
                    .tag = 207,
                    .modifiers = 1,
                    .name = NULL,
                    .arrayType = NULL,
                    .itemType = NULL,
                    .isSupertypeOf = &supertypeof_jnci_Iso8859Encoder,
                    .superclass = (TeaVM_Class*) &jnci_BufferedEncoder_Cls,
                    .layout = NULL,
                    .enumValues = NULL
                },
                .virt_clone = &meth_jl_Object_clone
            }
        },
        .virt_arrayEncode = &meth_jnci_Iso8859Encoder_arrayEncode
    }
};
void sysinitclass_jnci_Iso8859Encoder() {
}
