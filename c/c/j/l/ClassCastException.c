#include "ClassCastException.h"
#include "RuntimeException.h"
#include "../../../arrayclass.h"
#include "Throwable.h"
#include "../../o/t/r/Allocator.h"
#include "../../o/t/r/ExceptionHandling.h"
#include "../../../strings.h"
#include "Object.h"

void meth_jl_ClassCastException__init_(void* teavm_this_) {
    TeaVM_Array* teavm_local_1;
    TEAVM_ALLOC_STACK(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(55, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_this_);
    TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_suppressed) = teavm_local_1;
    TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(56, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_this_);
    TEAVM_FIELD(teavm_this_, cls_jl_Throwable, fld_stackTrace) = teavm_local_1;
    TEAVM_RELEASE_STACK;
}
int32_t supertypeof_jl_ClassCastException(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 52 || tag >= 54) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_ClassCastException_VT jl_ClassCastException_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .parent = {
                        .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_ClassCastException), sizeof(void*)),
                        .flags = 0,
                        .tag = 52,
                        .modifiers = 1,
                        .name = (TeaVM_Object**) TEAVM_GET_STRING_ADDRESS(1),
                        .arrayType = NULL,
                        .itemType = NULL,
                        .isSupertypeOf = &supertypeof_jl_ClassCastException,
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
void sysinitclass_jl_ClassCastException() {
}
