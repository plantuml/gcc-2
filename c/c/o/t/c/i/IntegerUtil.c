#include "IntegerUtil.h"
#include "../../../../j/l/Object.h"
#include "../../../../../strings.h"
#include "../../../../j/l/Long.h"
#include "../../../../../a/p/char.h"
#include "../../r/Allocator.h"
#include "../../../../j/l/Character.h"
#include "../../../../j/l/String.h"
#include "../../../../j/l/System.h"

void* meth_otci_IntegerUtil_toUnsignedLogRadixString(int64_t teavm_local_1, int32_t teavm_local_2) {
    void* teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    int32_t teavm_local_6;
    TeaVM_Array* teavm_local_7;
    TeaVM_Array* teavm_local_8;
    int32_t teavm_local_9;
    int32_t teavm_local_10;
    int32_t teavm_local_11;
    TEAVM_ALLOC_STACK(INT32_C(3));
    if ((teavm_local_1 == INT64_C(0))) {
        teavm_local_3 = TEAVM_GET_STRING(27);
    } else {
        teavm_local_4 = (INT32_C(1) << teavm_local_2);
        teavm_local_5 = (teavm_local_4 - INT32_C(1));
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
        teavm_local_6 = ((((INT32_C(64) - TEAVM_WITH_CALL_SITE_ID(648, meth_jl_Long_numberOfLeadingZeros(teavm_local_1))) + teavm_local_2) - INT32_C(1)) / teavm_local_2);
        teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(649, meth_otr_Allocator_allocateArray(&Arr_C_Cls, teavm_local_6));
        teavm_local_8 = teavm_local_7;
        teavm_local_9 = ((teavm_local_6 - INT32_C(1)) * teavm_local_2);
        teavm_local_10 = INT32_C(0);
        while (1) {
            if (!(teavm_local_9 >= INT32_C(0))) break;
            teavm_local_11 = (teavm_local_10 + INT32_C(1));
            teavm_local_6 = (((int32_t) ((int64_t) ((uint64_t) teavm_local_1 >> teavm_local_9))) & teavm_local_5);
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_8);
            TEAVM_ARRAY_AT(teavm_local_8, char16_t, TEAVM_WITH_CALL_SITE_ID(650, teavm_checkBounds(teavm_local_10, teavm_local_8))) = TEAVM_WITH_CALL_SITE_ID(651, meth_jl_Character_forDigit(teavm_local_6, teavm_local_4));
            teavm_local_9 = (teavm_local_9 - teavm_local_2);
            teavm_local_10 = teavm_local_11;
        }
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_8);
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(652, meth_otr_Allocator_allocate(&jl_String_Cls));
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
        TEAVM_WITH_CALL_SITE_ID(653, teavm_initializeClass((TeaVM_Class*) &jl_String_Cls, &initclass_jl_String));
        teavm_local_4 = TEAVM_ARRAY_LENGTH(teavm_local_8);
        teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(654, meth_otr_Allocator_allocateArray(&Arr_C_Cls, teavm_local_4));
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_8);
        TEAVM_WITH_CALL_SITE_ID(655, meth_jl_System_fastArraycopy(teavm_local_7, INT32_C(0), teavm_local_8, INT32_C(0), teavm_local_4));
        teavm_gc_writeBarrier(teavm_local_3);
        TEAVM_FIELD(teavm_local_3, TeaVM_String, characters) = teavm_local_8;
    }
    TEAVM_RELEASE_STACK;
    return teavm_local_3;
}
int32_t supertypeof_otci_IntegerUtil(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 199 || tag >= 201) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) otci_IntegerUtil_VT otci_IntegerUtil_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otci_IntegerUtil), sizeof(void*)),
            .flags = 0,
            .tag = 199,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_otci_IntegerUtil,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
void sysinitclass_otci_IntegerUtil() {
}
