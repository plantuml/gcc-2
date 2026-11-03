#include "core.h"
#include "string.h"
#include "c/o/t/r/ExceptionHandling.h"
#include "c/o/t/r/Allocator.h"
#include "arrayclass.h"
#include "c/j/l/String.h"
#include "a/p/char.h"

void* teavm_throwClassCastException() {
    meth_otr_ExceptionHandling_throwClassCastException();
    return NULL;
}
TeaVM_Array* teavm_allocateStringArray(int32_t size) {
    return (TeaVM_Array*) meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &jl_String_Cls), size);
}
TeaVM_Array* teavm_allocateCharArray(int32_t size) {
    return (TeaVM_Array*) meth_otr_Allocator_allocateArray(&Arr_C_Cls, size);
}
TeaVM_String* teavm_createString(TeaVM_Array* array) {
    TeaVM_String* str = (TeaVM_String*) meth_otr_Allocator_allocate(&jl_String_Cls);
    str->characters = array;return str;
}
