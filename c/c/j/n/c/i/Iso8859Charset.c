#include "Iso8859Charset.h"
#include "../Charset.h"
#include "Iso8859Encoder.h"
#include "../../../../o/t/r/Allocator.h"
#include "../../../../../a/p/byte.h"
#include "../CodingErrorAction.h"
#include "../CharsetEncoder.h"
#include "../../../l/Object.h"
#include "../../../../../a/p/char.h"
#include "BufferedEncoder.h"
#include "../../../l/IllegalArgumentException.h"
#include "../../../l/Throwable.h"
#include "../../../../../strings.h"
#include "../../../../o/t/r/ExceptionHandling.h"

void* meth_jnci_Iso8859Charset_newEncoder(void* teavm_this_) {
    void* teavm_local_1;
    TeaVM_Array* teavm_local_2;
    TeaVM_Array* teavm_local_3;
    void* teavm_local_4;
    int32_t teavm_local_5;
    TEAVM_ALLOC_STACK(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(663, meth_otr_Allocator_allocate(&jnci_Iso8859Encoder_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(664, meth_otr_Allocator_allocateArray(&Arr_B_Cls, INT32_C(1)));
    teavm_local_3 = teavm_local_2;
    TEAVM_ARRAY_AT(teavm_local_3, int8_t, INT32_C(0)) = INT32_C(63);
    TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
    TEAVM_WITH_CALL_SITE_ID(665, teavm_initializeClass((TeaVM_Class*) &jnc_CodingErrorAction_Cls, &initclass_jnc_CodingErrorAction));
    teavm_local_4 = sfld_jnc_CodingErrorAction_REPORT;
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jnc_CharsetEncoder, fld_malformedAction) = teavm_local_4;
    TEAVM_FIELD(teavm_local_1, cls_jnc_CharsetEncoder, fld_unmappableAction) = teavm_local_4;
    teavm_local_5 = TEAVM_ARRAY_LENGTH(teavm_local_3);
    if ((teavm_local_5 && (!(((float) teavm_local_5) < TEAVM_FIELD(teavm_local_1, cls_jnc_CharsetEncoder, fld_maxBytesPerChar))))) {
        teavm_gc_writeBarrier(teavm_local_1);
        TEAVM_FIELD(teavm_local_1, cls_jnc_CharsetEncoder, fld_charset) = teavm_this_;
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(666, TEAVM_METHOD(teavm_local_2, jl_Object_VT, virt_clone)(teavm_local_2));
        teavm_gc_writeBarrier(teavm_local_1);
        TEAVM_FIELD(teavm_local_1, cls_jnc_CharsetEncoder, fld_replacement) = teavm_local_2;
        TEAVM_FIELD(teavm_local_1, cls_jnc_CharsetEncoder, fld_averageBytesPerChar) = 1.0f;
        TEAVM_FIELD(teavm_local_1, cls_jnc_CharsetEncoder, fld_maxBytesPerChar) = 1.0f;
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(667, meth_otr_Allocator_allocateArray(&Arr_C_Cls, INT32_C(512)));
        teavm_gc_writeBarrier(teavm_local_1);
        TEAVM_FIELD(teavm_local_1, cls_jnci_BufferedEncoder, fld_inArray) = teavm_local_2;
        teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(668, meth_otr_Allocator_allocateArray(&Arr_B_Cls, INT32_C(512)));
        teavm_gc_writeBarrier(teavm_local_1);
        TEAVM_FIELD(teavm_local_1, cls_jnci_BufferedEncoder, fld_outArray) = teavm_local_2;
        TEAVM_RELEASE_STACK;
        return teavm_local_1;
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(669, meth_otr_Allocator_allocate(&jl_IllegalArgumentException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_4);
    TEAVM_WITH_CALL_SITE_ID(670, meth_jl_Throwable__init_(teavm_local_4, TEAVM_GET_STRING(26)));
    TEAVM_WITH_CALL_SITE_ID(671, meth_otr_ExceptionHandling_throwException(teavm_local_4));
    TEAVM_UNREACHABLE
}
int32_t supertypeof_jnci_Iso8859Charset(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 184 || tag >= 186) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jnci_Iso8859Charset_VT jnci_Iso8859Charset_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jnci_Iso8859Charset), sizeof(void*)),
                .flags = 0,
                .tag = 184,
                .modifiers = 1,
                .name = NULL,
                .arrayType = NULL,
                .itemType = NULL,
                .isSupertypeOf = &supertypeof_jnci_Iso8859Charset,
                .superclass = (TeaVM_Class*) &jnc_Charset_Cls,
                .layout = NULL,
                .enumValues = NULL
            },
            .virt_clone = &meth_jl_Object_clone
        }
    }
};
void sysinitclass_jnci_Iso8859Charset() {
}
