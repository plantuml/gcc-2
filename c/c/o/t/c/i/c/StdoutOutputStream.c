#include "StdoutOutputStream.h"
#include "ConsoleOutputStream.h"
#include "../../../../../../log.h"
#include "../../../r/Allocator.h"
#include "../../../../../../a/p/byte.h"
#include "../../../../../../strings.h"
#include "../../../../../j/l/Object.h"

void* sfld_otcic_StdoutOutputStream_INSTANCE;
void meth_otcic_StdoutOutputStream_write(void* teavm_this_, TeaVM_Array* teavm_local_1, int32_t teavm_local_2, int32_t teavm_local_3) {
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    TeaVM_Array* teavm_local_6;
    TEAVM_ALLOC_STACK(INT32_C(1));
    teavm_local_4 = INT32_C(0);
    while (1) {
        if (!(teavm_local_4 < teavm_local_3)) break;
        teavm_local_5 = (teavm_local_4 + teavm_local_2);
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(643, teavm_nullCheck(teavm_local_1));
        teavm_local_6 = teavm_local_1;
        teavm_logchar((TEAVM_ARRAY_AT(teavm_local_6, int8_t, TEAVM_WITH_CALL_SITE_ID(644, teavm_checkBounds(teavm_local_5, teavm_local_6))) & INT32_C(255)));
        teavm_local_4 = (teavm_local_4 + INT32_C(1));
    }
    TEAVM_RELEASE_STACK;
}
void meth_otcic_StdoutOutputStream__clinit_() {
    void* teavm_local_1;
    TeaVM_Array* teavm_local_2;
    TEAVM_ALLOC_STACK(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(645, meth_otr_Allocator_allocate(&otcic_StdoutOutputStream_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    TEAVM_WITH_CALL_SITE_ID(646, teavm_initializeClass((TeaVM_Class*) &otcic_StdoutOutputStream_Cls, &initclass_otcic_StdoutOutputStream));
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(647, meth_otr_Allocator_allocateArray(&Arr_B_Cls, INT32_C(1)));
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_otcic_ConsoleOutputStream, fld_buffer) = teavm_local_2;
    sfld_otcic_StdoutOutputStream_INSTANCE = teavm_local_1;
    TEAVM_RELEASE_STACK;
}
void initclass_otcic_StdoutOutputStream() {
    TeaVM_Class* cls = (TeaVM_Class*) &otcic_StdoutOutputStream_Cls;
    if (!(cls->flags & INT32_C(1))) {
        cls->flags |= INT32_C(1);
        meth_otcic_StdoutOutputStream__clinit_();
    }
}
int32_t supertypeof_otcic_StdoutOutputStream(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 195 || tag >= 197) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) otcic_StdoutOutputStream_VT otcic_StdoutOutputStream_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otcic_StdoutOutputStream), sizeof(void*)),
                    .flags = 0,
                    .tag = 195,
                    .modifiers = 1,
                    .name = NULL,
                    .arrayType = NULL,
                    .itemType = NULL,
                    .isSupertypeOf = &supertypeof_otcic_StdoutOutputStream,
                    .superclass = (TeaVM_Class*) &otcic_ConsoleOutputStream_Cls,
                    .layout = NULL,
                    .enumValues = NULL
                },
                .virt_clone = &meth_jl_Object_clone
            }
        }
    }
};
static void** teavm_gc_localStaticRoots_otcic_StdoutOutputStream_Cls[1] = {
(void**) &sfld_otcic_StdoutOutputStream_INSTANCE
};
void sysinitclass_otcic_StdoutOutputStream() {
sfld_otcic_StdoutOutputStream_INSTANCE = NULL;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_otcic_StdoutOutputStream_Cls, 1);
}
