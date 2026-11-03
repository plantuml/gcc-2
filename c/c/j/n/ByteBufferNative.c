#include "ByteBufferNative.h"
#include "ByteBuffer.h"
#include "../../../strings.h"
#include "../l/Object.h"

int32_t supertypeof_jn_ByteBufferNative(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 175 || tag >= 177) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_jn_ByteBufferNative_Cls[4];
alignas(8) jn_ByteBufferNative_VT jn_ByteBufferNative_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .parent = {
                    .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jn_ByteBufferNative), sizeof(void*)),
                    .flags = 0,
                    .tag = 175,
                    .modifiers = 0,
                    .name = NULL,
                    .arrayType = NULL,
                    .itemType = NULL,
                    .isSupertypeOf = &supertypeof_jn_ByteBufferNative,
                    .superclass = (TeaVM_Class*) &jn_ByteBuffer_Cls,
                    .layout = teavm_classLayouts_jn_ByteBufferNative_Cls,
                    .enumValues = (void*) offsetof(cls_jn_ByteBufferNative, fld_base)
                },
                .virt_clone = &meth_jl_Object_clone
            }
        }
    }
};
static int16_t teavm_classLayouts_jn_ByteBufferNative_Cls[4] = {
INT16_C(3), (int16_t) offsetof(cls_jn_ByteBufferNative, fld_gcRef), (int16_t) offsetof(cls_jn_ByteBufferNative, fld_array), (int16_t) offsetof(cls_jn_ByteBufferNative, fld_base)
};
void sysinitclass_jn_ByteBufferNative() {
}
