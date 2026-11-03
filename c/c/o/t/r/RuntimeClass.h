#pragma once
#include "../../../../runtime.h"

extern void sysinitclass_otr_RuntimeClass();
extern int32_t sfld_otr_RuntimeClass_INITIALIZED;
extern int32_t sfld_otr_RuntimeClass_VM_TYPE_SHIFT;
extern int32_t sfld_otr_RuntimeClass_VM_TYPE_MASK;
extern int32_t sfld_otr_RuntimeClass_PRIMITIVE_TYPE_SHIFT;
extern int32_t sfld_otr_RuntimeClass_PRIMITIVE_TYPE_MASK;
extern int32_t sfld_otr_RuntimeClass_VM_TYPE_REGULAR;
extern int32_t sfld_otr_RuntimeClass_VM_TYPE_WEAKREFERENCE;
extern int32_t sfld_otr_RuntimeClass_VM_TYPE_REFERENCEQUEUE;
extern int32_t sfld_otr_RuntimeClass_VM_TYPE_BUFFER;
extern void* meth_otr_RuntimeClass_getClass(void*);
extern int32_t meth_otr_RuntimeClass_isPrimitive(void*);
