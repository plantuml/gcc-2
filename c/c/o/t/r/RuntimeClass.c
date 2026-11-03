#include "RuntimeClass.h"
#include "RuntimeObject.h"

int32_t sfld_otr_RuntimeClass_INITIALIZED;
int32_t sfld_otr_RuntimeClass_VM_TYPE_SHIFT;
int32_t sfld_otr_RuntimeClass_VM_TYPE_MASK;
int32_t sfld_otr_RuntimeClass_PRIMITIVE_TYPE_SHIFT;
int32_t sfld_otr_RuntimeClass_PRIMITIVE_TYPE_MASK;
int32_t sfld_otr_RuntimeClass_VM_TYPE_REGULAR;
int32_t sfld_otr_RuntimeClass_VM_TYPE_WEAKREFERENCE;
int32_t sfld_otr_RuntimeClass_VM_TYPE_REFERENCEQUEUE;
int32_t sfld_otr_RuntimeClass_VM_TYPE_BUFFER;
void* meth_otr_RuntimeClass_getClass(void* teavm_local_1) {
    return TEAVM_UNPACK_CLASS(TEAVM_FIELD(teavm_local_1, TeaVM_Object, header));
}
int32_t meth_otr_RuntimeClass_isPrimitive(void* teavm_local_1) {
    return ((!((TEAVM_FIELD(teavm_local_1, TeaVM_Class, flags) >> INT32_C(4)) & INT32_C(15))) ? INT32_C(0) : INT32_C(1));
}
void sysinitclass_otr_RuntimeClass() {
    sfld_otr_RuntimeClass_INITIALIZED = INT32_C(1);
    sfld_otr_RuntimeClass_VM_TYPE_SHIFT = INT32_C(1);
    sfld_otr_RuntimeClass_VM_TYPE_MASK = INT32_C(7);
    sfld_otr_RuntimeClass_PRIMITIVE_TYPE_SHIFT = INT32_C(4);
    sfld_otr_RuntimeClass_PRIMITIVE_TYPE_MASK = INT32_C(15);
    sfld_otr_RuntimeClass_VM_TYPE_REGULAR = INT32_C(0);
    sfld_otr_RuntimeClass_VM_TYPE_WEAKREFERENCE = INT32_C(1);
    sfld_otr_RuntimeClass_VM_TYPE_REFERENCEQUEUE = INT32_C(2);
    sfld_otr_RuntimeClass_VM_TYPE_BUFFER = INT32_C(3);
}
