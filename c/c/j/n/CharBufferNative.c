#include "CharBufferNative.h"
#include "CharBufferImpl.h"
#include <string.h>
#include "../l/Character.h"
#include "../../../strings.h"
#include "../l/Object.h"

void meth_jn_CharBufferNative_getImpl(void* teavm_this_, int32_t teavm_local_1, TeaVM_Array* teavm_local_2, int32_t teavm_local_3, int32_t teavm_local_4) {
    void* teavm_local_5;
    int32_t teavm_local_6;
    TeaVM_Array* teavm_local_7;
    TEAVM_ALLOC_STACK(INT32_C(1));
    teavm_local_5 = TEAVM_ADDRESS_ADD(TEAVM_FIELD(teavm_this_, cls_jn_CharBufferNative, fld_address), (teavm_local_1 * INT32_C(2)));
    if ((!TEAVM_FIELD(teavm_this_, cls_jn_CharBufferNative, fld_swap))) {
        memmove(TEAVM_ADDRESS_ADD(TEAVM_ARRAY_DATA(teavm_local_2, int32_t), (teavm_local_3 * INT32_C(2))), teavm_local_5, (teavm_local_4 * INT32_C(2)));
    } else {
        while (1) {
            teavm_local_1 = (teavm_local_4 + -INT32_C(1));
            if ((teavm_local_4 <= INT32_C(0))) {
                goto teavm_label_1;
            }
            teavm_local_6 = (teavm_local_3 + INT32_C(1));
            teavm_local_4 = ((int32_t) *(char16_t*) teavm_local_5);
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_2);
            TEAVM_WITH_CALL_SITE_ID(795, teavm_initializeClass((TeaVM_Class*) &jl_Character_Cls, &initclass_jl_Character));
            teavm_local_4 = TEAVM_TO_CHAR((((teavm_local_4 & INT32_C(65280)) >> INT32_C(8)) | (teavm_local_4 << INT32_C(8))));
            teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(796, teavm_nullCheck(teavm_local_2));
            teavm_local_7 = teavm_local_2;
            TEAVM_ARRAY_AT(teavm_local_7, char16_t, TEAVM_WITH_CALL_SITE_ID(797, teavm_checkBounds(teavm_local_3, teavm_local_7))) = teavm_local_4;
            teavm_local_5 = TEAVM_ADDRESS_ADD(teavm_local_5, INT32_C(2));
            teavm_local_4 = teavm_local_1;
            teavm_local_3 = teavm_local_6;
        }
    }
teavm_label_1:;
    TEAVM_RELEASE_STACK;
}
int32_t supertypeof_jn_CharBufferNative(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 170 || tag >= 172) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_jn_CharBufferNative_Cls[3];
alignas(8) jn_CharBufferNative_VT jn_CharBufferNative_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .parent = {
                        .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jn_CharBufferNative), sizeof(void*)),
                        .flags = 0,
                        .tag = 170,
                        .modifiers = 0,
                        .name = NULL,
                        .arrayType = NULL,
                        .itemType = NULL,
                        .isSupertypeOf = &supertypeof_jn_CharBufferNative,
                        .superclass = (TeaVM_Class*) &jn_CharBufferImpl_Cls,
                        .layout = teavm_classLayouts_jn_CharBufferNative_Cls,
                        .enumValues = (void*) offsetof(cls_jn_CharBufferNative, fld_base)
                    },
                    .virt_clone = &meth_jl_Object_clone
                }
            }
        }
    }
};
static int16_t teavm_classLayouts_jn_CharBufferNative_Cls[3] = {
INT16_C(2), (int16_t) offsetof(cls_jn_CharBufferNative, fld_array), (int16_t) offsetof(cls_jn_CharBufferNative, fld_base)
};
void sysinitclass_jn_CharBufferNative() {
}
