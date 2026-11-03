#include "BufferedEncoder.h"
#include "../CharsetEncoder.h"
#include "../../Buffer.h"
#include "../../CharBuffer.h"
#include "BufferedEncoder@dController.h"
#include "../../../../o/t/r/Allocator.h"
#include "../CoderResult.h"
#include "../../ByteBuffer.h"
#include "../../../../../strings.h"
#include "../../../l/Object.h"

void* meth_jnci_BufferedEncoder_encodeLoop(void* teavm_this_, void* teavm_local_1, void* teavm_local_2) {
    TeaVM_Array* teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    TeaVM_Array* teavm_local_6;
    int32_t teavm_local_7;
    int32_t teavm_local_8;
    int32_t teavm_local_9;
    int32_t teavm_local_10;
    TeaVM_Array* teavm_local_11;
    int32_t teavm_local_12;
    void* teavm_local_13;
    void* teavm_local_14;
    TEAVM_ALLOC_STACK(INT32_C(5));
    teavm_local_3 = TEAVM_FIELD(teavm_this_, cls_jnci_BufferedEncoder, fld_inArray);
    teavm_local_4 = INT32_C(0);
    teavm_local_5 = INT32_C(0);
    teavm_local_6 = TEAVM_FIELD(teavm_this_, cls_jnci_BufferedEncoder, fld_outArray);
    while (1) {
        if (((teavm_local_4 + INT32_C(32)) > teavm_local_5)) {
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_6);
            TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
            TEAVM_GC_ROOT(INT32_C(2), teavm_local_1);
            TEAVM_GC_ROOT(INT32_C(3), teavm_local_2);
            TEAVM_GC_ROOT_RELEASE(INT32_C(4));
            teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(828, teavm_nullCheck(teavm_local_1));
            teavm_local_7 = TEAVM_FIELD(teavm_local_1, cls_jn_Buffer, fld_position);
            teavm_local_8 = TEAVM_FIELD(teavm_local_1, cls_jn_Buffer, fld_limit);
            if (((teavm_local_7 >= teavm_local_8) ? INT32_C(0) : INT32_C(1))) {
                teavm_local_9 = teavm_local_4;
                while (1) {
                    if (!(teavm_local_9 < teavm_local_5)) break;
                    teavm_local_10 = (teavm_local_9 - teavm_local_4);
                    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
                    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(829, teavm_nullCheck(teavm_local_3));
                    teavm_local_11 = teavm_local_3;
                    teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(830, teavm_checkBounds(teavm_local_9, teavm_local_11));
                    TEAVM_ARRAY_AT(teavm_local_11, char16_t, TEAVM_WITH_CALL_SITE_ID(831, teavm_checkBounds(teavm_local_10, teavm_local_11))) = TEAVM_ARRAY_AT(teavm_local_11, char16_t, teavm_local_9);
                    teavm_local_9 = (teavm_local_9 + INT32_C(1));
                }
                teavm_local_9 = (teavm_local_5 - teavm_local_4);
                teavm_local_8 = ((teavm_local_8 - teavm_local_7) + teavm_local_9);
                TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
                teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(832, teavm_nullCheck(teavm_local_3));
                teavm_local_5 = TEAVM_ARRAY_LENGTH(teavm_local_3);
                if ((teavm_local_8 < teavm_local_5)) {
                    teavm_local_5 = teavm_local_8;
                }
                TEAVM_WITH_CALL_SITE_ID(833, meth_jn_CharBuffer_get(teavm_local_1, teavm_local_3, teavm_local_9, (teavm_local_5 - teavm_local_9)));
                teavm_local_4 = INT32_C(0);
            }
        }
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_6);
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_1);
        TEAVM_GC_ROOT(INT32_C(3), teavm_local_2);
        TEAVM_GC_ROOT(INT32_C(4), teavm_local_3);
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(834, teavm_nullCheck(teavm_local_2));
        teavm_local_7 = TEAVM_FIELD(teavm_local_2, cls_jn_Buffer, fld_position);
        teavm_local_8 = TEAVM_FIELD(teavm_local_2, cls_jn_Buffer, fld_limit);
        if ((!((teavm_local_7 >= teavm_local_8) ? INT32_C(0) : INT32_C(1)))) {
            goto teavm_label_2;
        }
        teavm_local_8 = (teavm_local_8 - teavm_local_7);
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(835, teavm_nullCheck(teavm_local_6));
        teavm_local_12 = TEAVM_ARRAY_LENGTH(teavm_local_6);
        if ((teavm_local_8 < teavm_local_12)) {
            teavm_local_12 = teavm_local_8;
        }
        teavm_local_13 = TEAVM_WITH_CALL_SITE_ID(836, meth_otr_Allocator_allocate(&jnci_BufferedEncoder_Controller_Cls));
        TEAVM_FIELD(teavm_local_13, cls_jnci_BufferedEncoder_Controller, fld_in) = teavm_local_1;
        TEAVM_FIELD(teavm_local_13, cls_jnci_BufferedEncoder_Controller, fld_out) = teavm_local_2;
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_13);
        teavm_local_14 = TEAVM_WITH_CALL_SITE_ID(837, TEAVM_METHOD(teavm_this_, jnci_BufferedEncoder_VT, virt_arrayEncode)(teavm_this_, teavm_local_3, teavm_local_4, teavm_local_5, teavm_local_6, INT32_C(0), teavm_local_12, teavm_local_13));
        teavm_local_4 = TEAVM_FIELD(teavm_local_13, cls_jnci_BufferedEncoder_Controller, fld_inPosition);
        teavm_local_9 = TEAVM_FIELD(teavm_local_13, cls_jnci_BufferedEncoder_Controller, fld_outPosition);
        if ((teavm_local_14 == NULL)) {
            TEAVM_GC_ROOT(INT32_C(1), teavm_local_14);
            teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(838, teavm_nullCheck(teavm_local_1));
            teavm_local_7 = ((TEAVM_FIELD(teavm_local_1, cls_jn_Buffer, fld_position) >= TEAVM_FIELD(teavm_local_1, cls_jn_Buffer, fld_limit)) ? INT32_C(0) : INT32_C(1));
            if (((!teavm_local_7) && (teavm_local_4 >= teavm_local_5))) {
                TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                TEAVM_WITH_CALL_SITE_ID(839, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
                teavm_local_14 = sfld_jnc_CoderResult_UNDERFLOW;
            } else if (((!((TEAVM_FIELD(teavm_local_2, cls_jn_Buffer, fld_position) >= TEAVM_FIELD(teavm_local_2, cls_jn_Buffer, fld_limit)) ? INT32_C(0) : INT32_C(1))) && (teavm_local_4 >= teavm_local_5))) {
                TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                TEAVM_WITH_CALL_SITE_ID(840, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
                teavm_local_14 = sfld_jnc_CoderResult_OVERFLOW;
            }
        }
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_14);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_1);
        TEAVM_WITH_CALL_SITE_ID(841, meth_jn_ByteBuffer_put(teavm_local_2, teavm_local_6, INT32_C(0), teavm_local_9));
        if ((teavm_local_14 != NULL)) {
            goto teavm_label_3;
        }
    }
teavm_label_3:;
    goto teavm_label_1;
teavm_label_2:;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(3));
    TEAVM_GC_ROOT_RELEASE(INT32_C(4));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(842, teavm_nullCheck(teavm_local_1));
    teavm_local_7 = ((TEAVM_FIELD(teavm_local_1, cls_jn_Buffer, fld_position) >= TEAVM_FIELD(teavm_local_1, cls_jn_Buffer, fld_limit)) ? INT32_C(0) : INT32_C(1));
    if ((!((!teavm_local_7) && (teavm_local_4 >= teavm_local_5)))) {
        TEAVM_WITH_CALL_SITE_ID(843, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
        teavm_local_14 = sfld_jnc_CoderResult_OVERFLOW;
    } else {
        TEAVM_WITH_CALL_SITE_ID(844, teavm_initializeClass((TeaVM_Class*) &jnc_CoderResult_Cls, &initclass_jnc_CoderResult));
        teavm_local_14 = sfld_jnc_CoderResult_UNDERFLOW;
    }
teavm_label_1:;
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_14);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_1);
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(3));
    TEAVM_GC_ROOT_RELEASE(INT32_C(4));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(845, teavm_nullCheck(teavm_local_1));
    TEAVM_WITH_CALL_SITE_ID(846, meth_jn_Buffer_position(teavm_local_1, (TEAVM_FIELD(teavm_local_1, cls_jn_Buffer, fld_position) - (teavm_local_5 - teavm_local_4))));
    TEAVM_RELEASE_STACK;
    return teavm_local_14;
}
int32_t supertypeof_jnci_BufferedEncoder(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 206 || tag >= 212) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_jnci_BufferedEncoder_Cls[3];
alignas(8) jnci_BufferedEncoder_VT jnci_BufferedEncoder_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnci_BufferedEncoder), sizeof(void*)),
                .flags = 0,
                .tag = 206,
                .modifiers = 1025,
                .name = NULL,
                .arrayType = NULL,
                .itemType = NULL,
                .isSupertypeOf = &supertypeof_jnci_BufferedEncoder,
                .superclass = (TeaVM_Class*) &jnc_CharsetEncoder_Cls,
                .layout = teavm_classLayouts_jnci_BufferedEncoder_Cls,
                .enumValues = NULL
            },
            .virt_clone = &meth_jl_Object_clone
        }
    }
};
static int16_t teavm_classLayouts_jnci_BufferedEncoder_Cls[3] = {
INT16_C(2), (int16_t) offsetof(cls_jnci_BufferedEncoder, fld_inArray), (int16_t) offsetof(cls_jnci_BufferedEncoder, fld_outArray)
};
void sysinitclass_jnci_BufferedEncoder() {
}
