#include "NullPointerException.h"
#include "RuntimeException.h"
#include "../../../arrayclass.h"
#include "Throwable.h"
#include "../../o/t/r/Allocator.h"
#include "../../o/t/r/ExceptionHandling.h"
#include "../../../strings.h"
#include "Object.h"

void meth_jl_NullPointerException__init_(void* teavm_this_) {
    TeaVM_Array* teavm_local_1;
    TEAVM_ALLOC_STACK(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(102, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_this_);
    TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
    TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(103, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_this_);
    TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
    TEAVM_RELEASE_STACK;
}
int32_t supertypeof_jl_NullPointerException(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 54 || tag >= 56) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_NullPointerException_VT jl_NullPointerException_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .parent = {
                        .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_NullPointerException), sizeof(void*)),
                        .flags = 0,
                        .tag = 54,
                        .modifiers = 1,
                        .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(8),
                        .arrayType = NULL,
                        .itemType = NULL,
                        .isSupertypeOf = &supertypeof_jl_NullPointerException,
                        .superclass = (TeaVM_Class*) &jl_RuntimeException_Cls,
                        .layout = NULL,
                        .enumValues = NULL
                    },
                    .virt_clone = &meth_jl_Object_clone
                }
            }
        }
    }
};
void sysinitclass_jl_NullPointerException() {
}
