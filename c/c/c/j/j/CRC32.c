#include "CRC32.h"
#include "../../../j/l/Object.h"
#include "../../../../a/p/int.h"
#include "../../../o/t/r/Allocator.h"
#include "../../../../strings.h"

TeaVM_Array* sfld_cjj_CRC32_crc_table;
void meth_cjj_CRC32_update(void* teavm_this_, TeaVM_Array* teavm_local_1, int32_t teavm_local_2, int32_t teavm_local_3) {
    int32_t teavm_local_4;
    TeaVM_Array* teavm_local_5;
    int32_t teavm_local_6;
    TeaVM_Array* teavm_local_7;
    TEAVM_ALLOC_STACK(INT32_C(2));
    teavm_local_4 = (TEAVM_FIELD(teavm_this_, cls_cjj_CRC32, fld_v) ^ -INT32_C(1));
    while (1) {
        teavm_local_3 = (teavm_local_3 + -INT32_C(1));
        if ((teavm_local_3 < INT32_C(0))) {
            goto teavm_label_1;
        }
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_1);
        TEAVM_WITH_CALL_SITE_ID(473, teavm_initializeClass((TeaVM_Class*) &cjj_CRC32_Cls, &initclass_cjj_CRC32));
        teavm_local_5 = sfld_cjj_CRC32_crc_table;
        teavm_local_6 = (teavm_local_2 + INT32_C(1));
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_5);
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(474, teavm_nullCheck(teavm_local_1));
        teavm_local_7 = teavm_local_1;
        teavm_local_2 = ((teavm_local_4 ^ TEAVM_ARRAY_AT(teavm_local_7, int8_t, TEAVM_WITH_CALL_SITE_ID(475, teavm_checkBounds(teavm_local_2, teavm_local_7)))) & INT32_C(255));
        teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(476, teavm_nullCheck(teavm_local_5));
        teavm_local_4 = (TEAVM_ARRAY_AT(teavm_local_5, int32_t, TEAVM_WITH_CALL_SITE_ID(477, teavm_checkBounds(teavm_local_2, teavm_local_5))) ^ ((int32_t) ((uint32_t) teavm_local_4 >> INT32_C(8))));
        teavm_local_2 = teavm_local_6;
    }
teavm_label_1:;
    TEAVM_FIELD(teavm_this_, cls_cjj_CRC32, fld_v) = (teavm_local_4 ^ -INT32_C(1));
    TEAVM_RELEASE_STACK;
}
void meth_cjj_CRC32__clinit_() {
    TeaVM_Array* teavm_local_1;
    TeaVM_Array* teavm_local_2;
    int32_t teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    TEAVM_ALLOC_STACK(INT32_C(1));
    sfld_cjj_CRC32_crc_table = NULL;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(478, meth_otr_Allocator_allocateArray(&Arr_I_Cls, INT32_C(256)));
    teavm_local_2 = teavm_local_1;
    sfld_cjj_CRC32_crc_table = teavm_local_1;
    teavm_local_3 = INT32_C(0);
    while (1) {
        if (!(teavm_local_3 < INT32_C(256))) break;
        teavm_local_4 = INT32_C(8);
        teavm_local_5 = teavm_local_3;
        while (1) {
            teavm_local_4 = (teavm_local_4 + -INT32_C(1));
            if ((teavm_local_4 < INT32_C(0))) {
                goto teavm_label_2;
            }
            if ((!(teavm_local_5 & INT32_C(1)))) {
                teavm_local_5 = ((int32_t) ((uint32_t) teavm_local_5 >> INT32_C(1)));
                goto teavm_cnt_2;
            }
            teavm_local_5 = (-INT32_C(306674912) ^ ((int32_t) ((uint32_t) teavm_local_5 >> INT32_C(1))));
        teavm_cnt_2:;
        }
    teavm_label_2:;
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(479, teavm_checkBounds(teavm_local_3, teavm_local_2));
        TEAVM_ARRAY_AT(teavm_local_2, int32_t, teavm_local_3) = teavm_local_5;
        teavm_local_3 = (teavm_local_3 + INT32_C(1));
    }
    TEAVM_RELEASE_STACK;
}
void initclass_cjj_CRC32() {
    TeaVM_Class* cls = (TeaVM_Class*) &cjj_CRC32_Cls;
    if (!(cls->flags & INT32_C(1))) {
        cls->flags |= INT32_C(1);
        meth_cjj_CRC32__clinit_();
    }
}
int32_t supertypeof_cjj_CRC32(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 165 || tag >= 167) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) cjj_CRC32_VT cjj_CRC32_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_cjj_CRC32), sizeof(void*)),
            .flags = 0,
            .tag = 165,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_cjj_CRC32,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static void** teavm_gc_localStaticRoots_cjj_CRC32_Cls[1] = {
(void**) &sfld_cjj_CRC32_crc_table
};
void sysinitclass_cjj_CRC32() {
sfld_cjj_CRC32_crc_table = NULL;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_cjj_CRC32_Cls, 1);
}
