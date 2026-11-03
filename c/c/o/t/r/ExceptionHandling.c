#include "ExceptionHandling.h"
#include "../../../j/l/Object.h"
#include "../../../../log.h"
#include "../../../../string.h"
#include "RuntimeClass.h"
#include <stdlib.h>
#include "../../../j/l/ClassCastException.h"
#include "Allocator.h"
#include "../../../j/l/NullPointerException.h"
#include "../../../j/l/ArrayIndexOutOfBoundsException.h"
#include "../../../../arrayclass.h"
#include "../../../j/l/StackTraceElement.h"
#include "../../../../strings.h"

void* sfld_otr_ExceptionHandling_thrownException;
void meth_otr_ExceptionHandling_printStack() {
    void* teavm_local_1;
    int32_t teavm_local_2;
    void* teavm_local_3;
    void* teavm_local_4;
    void* teavm_local_5;
    teavm_local_1 = teavm_stackTop;
    while (1) {
        if (!(teavm_local_1 != NULL)) break;
        teavm_local_2 = TEAVM_GET_CALL_SITE_ID(teavm_local_1);
        if (TEAVM_OBFUSCATED) {
            teavm_printString(u"\tat Obfuscated.obfuscated(Obfuscated.java:");
            teavm_printInt(teavm_local_2);
            teavm_printString(u")\n");
        } else {
            teavm_local_3 = TEAVM_FIELD(TEAVM_FIND_CALLSITE(teavm_local_2, teavm_local_1), TeaVM_CallSite, location);
            while (1) {
                if ((teavm_local_3 == NULL)) {
                    goto teavm_label_2;
                }
                teavm_local_4 = TEAVM_FIELD(teavm_local_3, TeaVM_CallSiteLocation, method);
                if ((teavm_local_4 != NULL)) {
                    teavm_printString(u"\tat ");
                    teavm_local_5 = TEAVM_FIELD(teavm_local_4, TeaVM_MethodLocation, className);
                    if ((!((teavm_local_5 != NULL) && (TEAVM_FIELD(teavm_local_4, TeaVM_MethodLocation, methodName) != NULL)))) {
                        teavm_printString(u"(Unknown method)");
                    } else {
                        teavm_printString(teavm_stringToC16(TEAVM_FIELD(teavm_local_5, TeaVM_StringPtr, value)));
                        teavm_printString(u".");
                        teavm_printString(teavm_stringToC16(TEAVM_FIELD(TEAVM_FIELD(teavm_local_4, TeaVM_MethodLocation, methodName), TeaVM_StringPtr, value)));
                    }
                    teavm_printString(u"(");
                    teavm_local_5 = TEAVM_FIELD(teavm_local_4, TeaVM_MethodLocation, fileName);
                    if (((teavm_local_5 != NULL) && (TEAVM_FIELD(teavm_local_3, TeaVM_CallSiteLocation, lineNumber) >= INT32_C(0)))) {
                        teavm_printString(teavm_stringToC16(TEAVM_FIELD(teavm_local_5, TeaVM_StringPtr, value)));
                        teavm_printString(u":");
                        teavm_printInt(TEAVM_FIELD(teavm_local_3, TeaVM_CallSiteLocation, lineNumber));
                    }
                    teavm_printString(u")\n");
                }
                teavm_local_3 = TEAVM_FIELD(teavm_local_3, TeaVM_CallSiteLocation, next);
            }
        }
    teavm_label_2:;
        teavm_local_1 = TEAVM_GET_NEXT_FRAME(teavm_local_1);
    }
}
void* teavm_catchException() {
    void* teavm_local_1;
    teavm_local_1 = sfld_otr_ExceptionHandling_thrownException;
    sfld_otr_ExceptionHandling_thrownException = NULL;
    return teavm_local_1;
}
void meth_otr_ExceptionHandling_throwException(void* teavm_local_1) {
    void* teavm_local_2;
    void* teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    void* teavm_local_6;
    sfld_otr_ExceptionHandling_thrownException = teavm_local_1;
    teavm_local_2 = meth_otr_RuntimeClass_getClass(teavm_local_1);
    teavm_local_3 = teavm_stackTop;
    teavm_local_4 = INT32_C(0);
    while (1) {
        if (!(teavm_local_3 != NULL)) break;
        teavm_local_5 = TEAVM_GET_CALL_SITE_ID(teavm_local_3);
        if ((teavm_local_5 >= INT32_C(0))) {
            teavm_local_6 = TEAVM_FIELD(TEAVM_FIND_CALLSITE(teavm_local_5, teavm_local_3), TeaVM_CallSite, firstHandler);
            while (1) {
                if (!(teavm_local_6 != NULL)) break;
                teavm_local_1 = TEAVM_FIELD(teavm_local_6, TeaVM_ExceptionHandler, exceptionClass);
                if ((teavm_local_1 == NULL)) {
                    goto teavm_label_2;
                }
                if ((((int32_t (*)(void*, void*)) TEAVM_FIELD(teavm_local_1, TeaVM_Class, isSupertypeOf))(teavm_local_1, teavm_local_2))) {
                    goto teavm_label_2;
                }
                teavm_local_6 = TEAVM_FIELD(teavm_local_6, TeaVM_ExceptionHandler, next);
            }
            if ((!TEAVM_JUMP_SUPPORTED)) {
                TEAVM_SET_EXCEPTION_HANDLER_SKIP(teavm_local_3);
            }
        }
        teavm_local_3 = TEAVM_GET_NEXT_FRAME(teavm_local_3);
    }
    goto teavm_label_1;
teavm_label_2:;
    teavm_local_4 = TEAVM_FIELD(teavm_local_6, TeaVM_ExceptionHandler, id);
    if ((!TEAVM_JUMP_SUPPORTED)) {
        TEAVM_SET_EXCEPTION_HANDLER(teavm_local_3, teavm_local_4);
    }
teavm_label_1:;
    if ((teavm_local_3 != NULL)) {
        TEAVM_JUMP_TO_FRAME(teavm_local_3, teavm_local_4);
    } else {
        if ((!TEAVM_JUMP_SUPPORTED)) {
            teavm_local_1 = teavm_stackTop;
            while (1) {
                if ((teavm_local_1 == NULL)) {
                    goto teavm_label_5;
                }
                if ((TEAVM_GET_CALL_SITE_ID(teavm_local_1) >= INT32_C(0))) {
                    TEAVM_SET_EXCEPTION_HANDLER_RESTORE(teavm_local_1);
                }
                teavm_local_1 = TEAVM_GET_NEXT_FRAME(teavm_local_1);
            }
        }
    teavm_label_5:;
        meth_otr_ExceptionHandling_printStack();
        abort();;
    }
}
void meth_otr_ExceptionHandling_throwClassCastException() {
    void* teavm_tmp_ptr_0;
    meth_otr_ExceptionHandling_throwException((teavm_tmp_ptr_0 = meth_otr_Allocator_allocate(&jl_ClassCastException_Cls), meth_jl_ClassCastException__init_(teavm_tmp_ptr_0), teavm_tmp_ptr_0));
}
void teavm_throwNullPointerException() {
    void* teavm_tmp_ptr_0;
    meth_otr_ExceptionHandling_throwException((teavm_tmp_ptr_0 = meth_otr_Allocator_allocate(&jl_NullPointerException_Cls), meth_jl_NullPointerException__init_(teavm_tmp_ptr_0), teavm_tmp_ptr_0));
}
void teavm_throwArrayIndexOutOfBoundsException() {
    void* teavm_tmp_ptr_0;
    meth_otr_ExceptionHandling_throwException((teavm_tmp_ptr_0 = meth_otr_Allocator_allocate(&jl_ArrayIndexOutOfBoundsException_Cls), meth_jl_ArrayIndexOutOfBoundsException__init_(teavm_tmp_ptr_0), teavm_tmp_ptr_0));
}
int32_t meth_otr_ExceptionHandling_callStackSize() {
    void* teavm_local_1;
    int32_t teavm_local_2;
    int32_t teavm_local_3;
    void* teavm_local_4;
    teavm_local_1 = teavm_stackTop;
    teavm_local_2 = INT32_C(0);
    while (1) {
        if (!(teavm_local_1 != NULL)) break;
        teavm_local_3 = TEAVM_GET_CALL_SITE_ID(teavm_local_1);
        if ((teavm_local_3 >= INT32_C(0))) {
            teavm_local_4 = TEAVM_FIELD(TEAVM_FIND_CALLSITE(teavm_local_3, teavm_local_1), TeaVM_CallSite, location);
            if ((!((!TEAVM_OBFUSCATED) && (teavm_local_4 != NULL)))) {
                teavm_local_2 = (teavm_local_2 + INT32_C(1));
            } else {
                while (1) {
                    if (!(teavm_local_4 != NULL)) break;
                    teavm_local_2 = (teavm_local_2 + INT32_C(1));
                    teavm_local_4 = TEAVM_FIELD(teavm_local_4, TeaVM_CallSiteLocation, next);
                }
            }
        }
        teavm_local_1 = TEAVM_GET_NEXT_FRAME(teavm_local_1);
    }
    return teavm_local_2;
}
TeaVM_Array* meth_otr_ExceptionHandling_fillStackTrace() {
    void* teavm_local_1;
    int32_t teavm_local_2;
    TeaVM_Array* teavm_local_3;
    TeaVM_Array* teavm_local_4;
    int32_t teavm_local_5;
    int32_t teavm_local_6;
    void* teavm_local_7;
    void* teavm_local_8;
    int32_t teavm_local_9;
    void* teavm_local_10;
    void* teavm_local_11;
    void* teavm_local_12;
    void* teavm_tmp_ptr_0;
    teavm_local_1 = teavm_stackTop;
    teavm_local_2 = meth_otr_ExceptionHandling_callStackSize();
    TEAVM_ALLOC_STACK(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    teavm_local_3 = meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_StackTraceElement_Cls), teavm_local_2);
    teavm_local_4 = teavm_local_3;
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_3);
    teavm_local_5 = INT32_C(0);
    while (1) {
        if (!(teavm_local_1 != NULL)) break;
        teavm_local_6 = TEAVM_GET_CALL_SITE_ID(teavm_local_1);
        if ((teavm_local_6 >= INT32_C(0))) {
            teavm_local_7 = TEAVM_FIELD(TEAVM_FIND_CALLSITE(teavm_local_6, teavm_local_1), TeaVM_CallSite, location);
            if (TEAVM_OBFUSCATED) {
                teavm_local_2 = (teavm_local_5 + INT32_C(1));
                teavm_local_8 = (teavm_tmp_ptr_0 = meth_otr_Allocator_allocate(&jl_StackTraceElement_Cls), meth_jl_StackTraceElement__init_(teavm_tmp_ptr_0, TEAVM_GET_STRING(5), TEAVM_GET_STRING(6), TEAVM_GET_STRING(7), teavm_local_6), teavm_tmp_ptr_0);
                teavm_local_9 = teavm_checkBounds(teavm_local_5, teavm_local_4);
                teavm_gc_writeBarrier(teavm_local_4);
                TEAVM_ARRAY_AT(teavm_local_4, void*, teavm_local_9) = teavm_local_8;
                teavm_local_5 = teavm_local_2;
            } else if ((teavm_local_7 == NULL)) {
                teavm_local_9 = (teavm_local_5 + INT32_C(1));
                teavm_local_10 = (teavm_tmp_ptr_0 = meth_otr_Allocator_allocate(&jl_StackTraceElement_Cls), meth_jl_StackTraceElement__init_(teavm_tmp_ptr_0, TEAVM_GET_STRING(2), TEAVM_GET_STRING(2), NULL, -INT32_C(1)), teavm_tmp_ptr_0);
                teavm_local_5 = teavm_checkBounds(teavm_local_5, teavm_local_4);
                teavm_gc_writeBarrier(teavm_local_4);
                TEAVM_ARRAY_AT(teavm_local_4, void*, teavm_local_5) = teavm_local_10;
                teavm_local_5 = teavm_local_9;
            } else {
                while (1) {
                    if (!(teavm_local_7 != NULL)) break;
                    teavm_local_10 = TEAVM_FIELD(teavm_local_7, TeaVM_CallSiteLocation, method);
                    if ((teavm_local_10 == NULL)) {
                        teavm_local_11 = (teavm_tmp_ptr_0 = meth_otr_Allocator_allocate(&jl_StackTraceElement_Cls), meth_jl_StackTraceElement__init_(teavm_tmp_ptr_0, TEAVM_GET_STRING(2), TEAVM_GET_STRING(2), NULL, TEAVM_FIELD(teavm_local_7, TeaVM_CallSiteLocation, lineNumber)), teavm_tmp_ptr_0);
                    } else {
                        teavm_local_11 = meth_otr_Allocator_allocate(&jl_StackTraceElement_Cls);
                        teavm_local_8 = TEAVM_FIELD(teavm_local_10, TeaVM_MethodLocation, className);
                        teavm_local_8 = ((teavm_local_8 == NULL) ? TEAVM_GET_STRING(2) : TEAVM_FIELD(teavm_local_8, TeaVM_StringPtr, value));
                        teavm_local_12 = TEAVM_FIELD(teavm_local_10, TeaVM_MethodLocation, methodName);
                        teavm_local_12 = ((teavm_local_12 == NULL) ? TEAVM_GET_STRING(2) : TEAVM_FIELD(teavm_local_12, TeaVM_StringPtr, value));
                        teavm_local_10 = TEAVM_FIELD(teavm_local_10, TeaVM_MethodLocation, fileName);
                        meth_jl_StackTraceElement__init_(teavm_local_11, teavm_local_8, teavm_local_12, ((teavm_local_10 == NULL) ? NULL : TEAVM_FIELD(teavm_local_10, TeaVM_StringPtr, value)), TEAVM_FIELD(teavm_local_7, TeaVM_CallSiteLocation, lineNumber));
                    }
                    teavm_local_9 = (teavm_local_5 + INT32_C(1));
                    teavm_local_2 = teavm_checkBounds(teavm_local_5, teavm_local_4);
                    teavm_gc_writeBarrier(teavm_local_4);
                    TEAVM_ARRAY_AT(teavm_local_4, void*, teavm_local_2) = teavm_local_11;
                    teavm_local_7 = TEAVM_FIELD(teavm_local_7, TeaVM_CallSiteLocation, next);
                    teavm_local_5 = teavm_local_9;
                }
            }
        }
        teavm_local_1 = TEAVM_GET_NEXT_FRAME(teavm_local_1);
    }
    TEAVM_RELEASE_STACK;
    return teavm_local_3;
}
int32_t supertypeof_otr_ExceptionHandling(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 101 || tag >= 103) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) otr_ExceptionHandling_VT otr_ExceptionHandling_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otr_ExceptionHandling), sizeof(void*)),
            .flags = 0,
            .tag = 101,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_otr_ExceptionHandling,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static void** teavm_gc_localStaticRoots_otr_ExceptionHandling_Cls[1] = {
(void**) &sfld_otr_ExceptionHandling_thrownException
};
void sysinitclass_otr_ExceptionHandling() {
sfld_otr_ExceptionHandling_thrownException = NULL;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_otr_ExceptionHandling_Cls, 1);
}
