#include "UTF8Encoder.h"
#include "BufferedEncoder.h"
#include "../../../l/Character.h"
#include "../CoderResult.h"
#include "../../../../o/t/r/Allocator.h"
#include "BufferedEncoder@dController.h"
#include "../../Buffer.h"
#include "../../../../../strings.h"
#include "../../../l/Object.h"

void* meth_jnci_UTF8Encoder_arrayEncode(void* teavm_this_, TeaVM_Array* teavm_local_1, int32_t teavm_local_2, int32_t teavm_local_3, TeaVM_Array* teavm_local_4, int32_t teavm_local_5, int32_t teavm_local_6, void* teavm_local_7) {
    void* teavm_local_8;
    int32_t teavm_local_9;
    TeaVM_Array* teavm_local_10;
    int32_t teavm_local_11;
    int32_t teavm_local_12;
    int32_t teavm_local_13;
    int32_t teavm_local_14;
    int32_t teavm_local_15;
    void* teavm_local_16;
    TEAVM_ALLOC_STACK(INT32_C(2));
    teavm_local_8 = NULL;
    while (1) {
        if (!(teavm_local_2 < teavm_local_3)) break;
        if ((teavm_local_5 >= teavm_local_6)) {
            goto teavm_label_8;
        }
        teavm_local_9 = (teavm_local_2 + INT32_C(1));
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_4);
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(847, teavm_nullCheck(teavm_local_1));
        teavm_local_10 = teavm_local_1;
        teavm_local_11 = TEAVM_ARRAY_AT(teavm_local_10, char16_t, TEAVM_WITH_CALL_SITE_ID(848, teavm_checkBounds(teavm_local_2, teavm_local_10)));
        if ((teavm_local_11 < INT32_C(128))) {
            teavm_local_12 = (teavm_local_5 + INT32_C(1));
            teavm_local_13 = TEAVM_TO_BYTE(teavm_local_11);
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(849, teavm_nullCheck(teavm_local_4));
            teavm_local_10 = teavm_local_4;
            TEAVM_ARRAY_AT(teavm_local_10, int8_t, TEAVM_WITH_CALL_SITE_ID(850, teavm_checkBounds(teavm_local_5, teavm_local_10))) = teavm_local_13;
        } else if ((teavm_local_11 < INT32_C(2048))) {
            if (((teavm_local_5 + INT32_C(2)) > teavm_local_6)) {
                goto teavm_label_2;
            }
            teavm_local_13 = (teavm_local_5 + INT32_C(1));
            teavm_local_12 = TEAVM_TO_BYTE((INT32_C(192) | (teavm_local_11 >> INT32_C(6))));
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(851, teavm_nullCheck(teavm_local_4));
            teavm_local_10 = teavm_local_4;
            TEAVM_ARRAY_AT(teavm_local_10, int8_t, TEAVM_WITH_CALL_SITE_ID(852, teavm_checkBounds(teavm_local_5, teavm_local_10))) = teavm_local_12;
            teavm_local_12 = (teavm_local_13 + INT32_C(1));
            TEAVM_ARRAY_AT(teavm_local_10, int8_t, TEAVM_WITH_CALL_SITE_ID(853, teavm_checkBounds(teavm_local_13, teavm_local_10))) = TEAVM_TO_BYTE((INT32_C(128) | (teavm_local_11 & INT32_C(63))));
        } else {
            TEAVM_WITH_CALL_SITE_ID(854, teavm_initializeClass((TeaVM_Class*) &jl_Character_Cls, &initclass_jl_Character));
            teavm_local_2 = (teavm_local_11 & INT32_C(64512));
            teavm_local_13 = teavm_compare_i32(teavm_local_2, INT32_C(55296));
            teavm_local_12 = (teavm_local_13 ? INT32_C(0) : INT32_C(1));
            if ((!((!((!teavm_local_12) && (!((teavm_local_2 != INT32_C(56320)) ? INT32_C(0) : INT32_C(1))))) ? INT32_C(1) : INT32_C(0)))) {
                if (((teavm_local_5 + INT32_C(3)) > teavm_local_6)) {
                    goto teavm_label_3;
                }
                teavm_local_13 = (teavm_local_5 + INT32_C(1));
                teavm_local_12 = TEAVM_TO_BYTE((INT32_C(224) | (teavm_local_11 >> INT32_C(12))));
                teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(855, teavm_nullCheck(teavm_local_4));
                teavm_local_10 = teavm_local_4;
                TEAVM_ARRAY_AT(teavm_local_10, int8_t, TEAVM_WITH_CALL_SITE_ID(856, teavm_checkBounds(teavm_local_5, teavm_local_10))) = teavm_local_12;
                teavm_local_14 = (teavm_local_13 + INT32_C(1));
                TEAVM_ARRAY_AT(teavm_local_10, int8_t, TEAVM_WITH_CALL_SITE_ID(857, teavm_checkBounds(teavm_local_13, teavm_local_10))) = TEAVM_TO_BYTE((INT32_C(128) | ((teavm_local_11 >> INT32_C(6)) & INT32_C(63))));
                teavm_local_12 = (teavm_local_14 + INT32_C(1));
                TEAVM_ARRAY_AT(teavm_local_10, int8_t, TEAVM_WITH_CALL_SITE_ID(858, teavm_checkBounds(teavm_local_14, teavm_local_10))) = TEAVM_TO_BYTE((INT32_C(128) | (teavm_local_11 & INT32_C(63))));
            } else {
                if ((!(teavm_local_13 ? INT32_C(0) : INT32_C(1)))) {
                    goto teavm_label_7;
                }
                if ((teavm_local_9 >= teavm_local_3)) {
                    goto teavm_label_5;
                }
                teavm_local_14 = (teavm_local_9 + INT32_C(1));
                teavm_local_13 = TEAVM_ARRAY_AT(teavm_local_10, char16_t, TEAVM_WITH_CALL_SITE_ID(859, teavm_checkBounds(teavm_local_9, teavm_local_10)));
                if ((!(((teavm_local_13 & INT32_C(64512)) != INT32_C(56320)) ? INT32_C(0) : INT32_C(1)))) {
                    goto teavm_label_6;
                }
                if (((teavm_local_5 + INT32_C(4)) > teavm_local_6)) {
                    goto teavm_label_4;
                }
                teavm_local_15 = ((((teavm_local_11 & INT32_C(1023)) << INT32_C(10)) | (teavm_local_13 & INT32_C(1023))) + INT32_C(65536));
                teavm_local_13 = (teavm_local_5 + INT32_C(1));
                teavm_local_12 = TEAVM_TO_BYTE((INT32_C(240) | (teavm_local_15 >> INT32_C(18))));
                teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(860, teavm_nullCheck(teavm_local_4));
                teavm_local_10 = teavm_local_4;
                TEAVM_ARRAY_AT(teavm_local_10, int8_t, TEAVM_WITH_CALL_SITE_ID(861, teavm_checkBounds(teavm_local_5, teavm_local_10))) = teavm_local_12;
                teavm_local_5 = (teavm_local_13 + INT32_C(1));
                TEAVM_ARRAY_AT(teavm_local_10, int8_t, TEAVM_WITH_CALL_SITE_ID(862, teavm_checkBounds(teavm_local_13, teavm_local_10))) = TEAVM_TO_BYTE((INT32_C(128) | ((teavm_local_15 >> INT32_C(12)) & INT32_C(63))));
                teavm_local_13 = (teavm_local_5 + INT32_C(1));
                TEAVM_ARRAY_AT(teavm_local_10, int8_t, TEAVM_WITH_CALL_SITE_ID(863, teavm_checkBounds(teavm_local_5, teavm_local_10))) = TEAVM_TO_BYTE((INT32_C(128) | ((teavm_local_15 >> INT32_C(6)) & INT32_C(63))));
                teavm_local_12 = (teavm_local_13 + INT32_C(1));
                TEAVM_ARRAY_AT(teavm_local_10, int8_t, TEAVM_WITH_CALL_SITE_ID(864, teavm_checkBounds(teavm_local_13, teavm_local_10))) = TEAVM_TO_BYTE((INT32_C(128) | (teavm_local_15 & INT32_C(63))));
                teavm_local_9 = teavm_local_14;
            }
        }
        teavm_local_2 = teavm_local_9;
        teavm_local_5 = teavm_local_12;
    }
    teavm_local_9 = teavm_local_2;
    goto teavm_label_1;
teavm_label_8:;
    teavm_local_9 = teavm_local_2;
    goto teavm_label_1;
teavm_label_7:;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_WITH_CALL_SITE_ID(865, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
    teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(866, meth_otr_Allocator_allocate(&jnc_CoderResult_Cls));
    TEAVM_FIELD(teavm_local_8, cls_jnc_CoderResult, fld_kind) = INT32_C(2);
    TEAVM_FIELD(teavm_local_8, cls_jnc_CoderResult, fld_length) = INT32_C(1);
    goto teavm_label_1;
teavm_label_6:;
    teavm_local_9 = (teavm_local_14 + -INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_WITH_CALL_SITE_ID(867, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
    teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(868, meth_otr_Allocator_allocate(&jnc_CoderResult_Cls));
    TEAVM_FIELD(teavm_local_8, cls_jnc_CoderResult, fld_kind) = INT32_C(2);
    TEAVM_FIELD(teavm_local_8, cls_jnc_CoderResult, fld_length) = INT32_C(1);
    goto teavm_label_1;
teavm_label_5:;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(869, teavm_nullCheck(teavm_local_7));
    teavm_local_16 = TEAVM_FIELD(teavm_local_7, cls_jnci_BufferedEncoder_Controller, fld_in);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_16);
    teavm_local_16 = TEAVM_WITH_CALL_SITE_ID(870, teavm_nullCheck(teavm_local_16));
    if (((TEAVM_FIELD(teavm_local_16, cls_jn_Buffer, fld_position) >= TEAVM_FIELD(teavm_local_16, cls_jn_Buffer, fld_limit)) ? INT32_C(0) : INT32_C(1))) {
        goto teavm_label_1;
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_WITH_CALL_SITE_ID(871, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
    teavm_local_8 = sfld_jnc_CoderResult_UNDERFLOW;
    goto teavm_label_1;
teavm_label_4:;
    teavm_local_9 = (teavm_local_14 + -INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(872, teavm_nullCheck(teavm_local_7));
    teavm_local_16 = TEAVM_FIELD(teavm_local_7, cls_jnci_BufferedEncoder_Controller, fld_out);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_16);
    teavm_local_16 = TEAVM_WITH_CALL_SITE_ID(873, teavm_nullCheck(teavm_local_16));
    if ((((TEAVM_FIELD(teavm_local_16, cls_jn_Buffer, fld_limit) - TEAVM_FIELD(teavm_local_16, cls_jn_Buffer, fld_position)) < INT32_C(4)) ? INT32_C(0) : INT32_C(1))) {
        goto teavm_label_1;
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_WITH_CALL_SITE_ID(874, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
    teavm_local_8 = sfld_jnc_CoderResult_OVERFLOW;
    goto teavm_label_1;
teavm_label_3:;
    teavm_local_9 = (teavm_local_9 + -INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(875, teavm_nullCheck(teavm_local_7));
    teavm_local_16 = TEAVM_FIELD(teavm_local_7, cls_jnci_BufferedEncoder_Controller, fld_out);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_16);
    teavm_local_16 = TEAVM_WITH_CALL_SITE_ID(876, teavm_nullCheck(teavm_local_16));
    if ((((TEAVM_FIELD(teavm_local_16, cls_jn_Buffer, fld_limit) - TEAVM_FIELD(teavm_local_16, cls_jn_Buffer, fld_position)) < INT32_C(3)) ? INT32_C(0) : INT32_C(1))) {
        goto teavm_label_1;
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_WITH_CALL_SITE_ID(877, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
    teavm_local_8 = sfld_jnc_CoderResult_OVERFLOW;
    goto teavm_label_1;
teavm_label_2:;
    teavm_local_9 = (teavm_local_9 + -INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(878, teavm_nullCheck(teavm_local_7));
    teavm_local_16 = TEAVM_FIELD(teavm_local_7, cls_jnci_BufferedEncoder_Controller, fld_out);
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_7);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_16);
    teavm_local_16 = TEAVM_WITH_CALL_SITE_ID(879, teavm_nullCheck(teavm_local_16));
    if ((!(((TEAVM_FIELD(teavm_local_16, cls_jn_Buffer, fld_limit) - TEAVM_FIELD(teavm_local_16, cls_jn_Buffer, fld_position)) < INT32_C(2)) ? INT32_C(0) : INT32_C(1)))) {
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        TEAVM_WITH_CALL_SITE_ID(880, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
        teavm_local_8 = sfld_jnc_CoderResult_OVERFLOW;
    }
teavm_label_1:;
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_8);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_7);
    teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(881, teavm_nullCheck(teavm_local_7));
    TEAVM_FIELD(teavm_local_7, cls_jnci_BufferedEncoder_Controller, fld_inPosition) = teavm_local_9;
    TEAVM_FIELD(teavm_local_7, cls_jnci_BufferedEncoder_Controller, fld_outPosition) = teavm_local_5;
    TEAVM_RELEASE_STACK;
    return teavm_local_8;
}
int32_t supertypeof_jnci_UTF8Encoder(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 209 || tag >= 211) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jnci_UTF8Encoder_VT jnci_UTF8Encoder_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnci_UTF8Encoder), sizeof(void*)),
                    .flags = 0,
                    .tag = 209,
                    .modifiers = 1,
                    .name = NULL,
                    .arrayType = NULL,
                    .itemType = NULL,
                    .isSupertypeOf = &supertypeof_jnci_UTF8Encoder,
                    .superclass = (TeaVM_Class*) &jnci_BufferedEncoder_Cls,
                    .layout = NULL,
                    .enumValues = NULL
                },
                .virt_clone = &meth_jl_Object_clone
            }
        },
        .virt_arrayEncode = &meth_jnci_UTF8Encoder_arrayEncode
    }
};
void sysinitclass_jnci_UTF8Encoder() {
}
