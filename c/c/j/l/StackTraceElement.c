#include "StackTraceElement.h"
#include "Object.h"
#include "NullPointerException.h"
#include "../../o/t/r/Allocator.h"
#include "../../../arrayclass.h"
#include "Throwable.h"
#include "../../o/t/r/ExceptionHandling.h"
#include "../../../strings.h"

void meth_jl_StackTraceElement__init_(void* teavm_this_, void* teavm_local_1, void* teavm_local_2, void* teavm_local_3, int32_t teavm_local_4) {
    TeaVM_Array* teavm_local_5;
    TEAVM_ALLOC_STACK(INT32_C(1));
    if (((teavm_local_1 != NULL) && (teavm_local_2 != NULL))) {
        teavm_gc_writeBarrier(teavm_this_);
        TEAVM_FIELD(teavm_this_, cls_jl_StackTraceElement, fld_declaringClass) = teavm_local_1;
        TEAVM_FIELD(teavm_this_, cls_jl_StackTraceElement, fld_methodName) = teavm_local_2;
        TEAVM_FIELD(teavm_this_, cls_jl_StackTraceElement, fld_fileName) = teavm_local_3;
        TEAVM_FIELD(teavm_this_, cls_jl_StackTraceElement, fld_lineNumber) = teavm_local_4;
        TEAVM_RELEASE_STACK;
        return;
    }
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(801, meth_otr_Allocator_allocate(&jl_NullPointerException_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(802, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_Throwable_Cls), INT32_C(0)));
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressed) = teavm_local_5;
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_suppressionEnabled) = INT32_C(1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_writableStackTrace) = INT32_C(1);
    teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(803, meth_otr_ExceptionHandling_fillStackTrace());
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_jl_Throwable, fld_stackTrace) = teavm_local_5;
    TEAVM_WITH_CALL_SITE_ID(804, meth_otr_ExceptionHandling_throwException(teavm_local_1));
    TEAVM_UNREACHABLE
}
int32_t supertypeof_jl_StackTraceElement(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 225 || tag >= 227) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_jl_StackTraceElement_Cls[4];
alignas(8) jl_StackTraceElement_VT jl_StackTraceElement_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_StackTraceElement), sizeof(void*)),
            .flags = 0,
            .tag = 225,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jl_StackTraceElement,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_jl_StackTraceElement_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static int16_t teavm_classLayouts_jl_StackTraceElement_Cls[4] = {
INT16_C(3), (int16_t) offsetof(cls_jl_StackTraceElement, fld_declaringClass), (int16_t) offsetof(cls_jl_StackTraceElement, fld_methodName), (int16_t) offsetof(cls_jl_StackTraceElement, fld_fileName)
};
void sysinitclass_jl_StackTraceElement() {
}
