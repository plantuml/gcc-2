#include "CRC32.h"
#include "../../l/Object.h"
#include "../../../c/j/j/CRC32.h"
#include "../../l/ArrayIndexOutOfBoundsException.h"
#include "../../../o/t/r/Allocator.h"
#include "../../../../arrayclass.h"
#include "../../l/Throwable.h"
#include "../../../o/t/r/ExceptionHandling.h"
#include "../../../../strings.h"

void meth_juz_CRC32_update(void* teavm_this_, TeaVM_Array* teavm_local_1, int32_t teavm_local_2, int32_t teavm_local_3) {
    TeaVM_Array* teavm_local_4;
    int32_t teavm_local_5;
    void* teavm_local_6;
    TEAVM_ALLOC_STACK(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(353, teavm_nullCheck(teavm_local_1));
    teavm_local_5 = TEAVM_ARRAY_LENGTH(teavm_local_4);
    if (((teavm_local_2 <= teavm_local_5) && ((teavm_local_3 >= INT32_C(0)) && ((teavm_local_2 >= INT32_C(0)) && ((teavm_local_5 - teavm_local_2) >= teavm_local_3))))) {
        teavm_local_6 = TEAVM_FIELD(teavm_this_, cls_juz_CRC32, fld_impl);
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_4);
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
        TEAVM_WITH_CALL_SITE_ID(354, meth_cjj_CRC32_update(TEAVM_WITH_CALL_SITE_ID(355, teavm_nullCheck(teavm_local_6)), teavm_local_4, teavm_local_2, teavm_local_3));
        TEAVM_FIELD(teavm_this_, cls_juz_CRC32, fld_tbytes) = (TEAVM_FIELD(teavm_this_, cls_juz_CRC32, fld_tbytes) + ((int64_t) teavm_local_3));
        TEAVM_RELEASE_STACK;
        return;
    }
    teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(356, meth_otr_Allocator_allocate(&jl_ArrayIndexOutOfBoundsException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_6);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(357, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_6);
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(358, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_local_6);
    TEAVM_FIELD(teavm_local_6, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
    TEAVM_WITH_CALL_SITE_ID(359, meth_otr_ExceptionHandling_throwException(teavm_local_6));
    TEAVM_UNREACHABLE
}
int32_t supertypeof_juz_CRC32(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 145 || tag >= 147) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_juz_CRC32_Cls[2];
alignas(8) juz_CRC32_VT juz_CRC32_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_juz_CRC32), sizeof(void*)),
            .flags = 0,
            .tag = 145,
            .modifiers = 1,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_juz_CRC32,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_juz_CRC32_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static int16_t teavm_classLayouts_juz_CRC32_Cls[2] = {
INT16_C(1), (int16_t) offsetof(cls_juz_CRC32, fld_impl)
};
void sysinitclass_juz_CRC32() {
}
