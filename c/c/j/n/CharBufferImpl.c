#include "CharBufferImpl.h"
#include "CharBuffer.h"
#include "../../../strings.h"
#include "../l/Object.h"

int32_t supertypeof_jn_CharBufferImpl(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 169 || tag >= 173) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jn_CharBufferImpl_VT jn_CharBufferImpl_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jn_CharBufferImpl), sizeof(void*)),
                    .flags = 0,
                    .tag = 169,
                    .modifiers = 1024,
                    .name = NULL,
                    .arrayType = NULL,
                    .itemType = NULL,
                    .isSupertypeOf = &supertypeof_jn_CharBufferImpl,
                    .superclass = (TeaVM_Class*) &jn_CharBuffer_Cls,
                    .layout = NULL,
                    .enumValues = NULL
                },
                .virt_clone = &meth_jl_Object_clone
            }
        }
    }
};
void sysinitclass_jn_CharBufferImpl() {
}
