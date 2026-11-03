#pragma once
#include "runtime.h"
extern void teavm_initStringPool();
extern TeaVM_String* teavm_stringPool[];
#define TEAVM_GET_STRING(i) teavm_stringPool[i]
#define TEAVM_GET_STRING_ADDRESS(i) (teavm_stringPool + i)
