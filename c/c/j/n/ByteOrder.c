#include "ByteOrder.h"
#include "../l/Object.h"
#include "../../../a/p/short.h"
#include "../../o/t/r/Allocator.h"
#include "../../../strings.h"

void* sfld_jn_ByteOrder_BIG_ENDIAN;
void* sfld_jn_ByteOrder_LITTLE_ENDIAN;
void* sfld_jn_ByteOrder_nativeOrder;
void* meth_jn_ByteOrder_nativeOrder() {
    TeaVM_Array* teavm_local_1;
    void* teavm_local_2;
    TEAVM_ALLOC_STACK(INT32_C(0));
    TEAVM_WITH_CALL_SITE_ID(805, teavm_initializeClass((TeaVM_Class*) &jn_ByteOrder_Cls, &initclass_jn_ByteOrder));
    if ((sfld_jn_ByteOrder_nativeOrder == NULL)) {
        teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(806, meth_otr_Allocator_allocateArray(&Arr_S_Cls, INT32_C(1)));
        TEAVM_ARRAY_AT(teavm_local_1, int16_t, INT32_C(0)) = INT32_C(1);
        sfld_jn_ByteOrder_nativeOrder = (((int32_t) *(int8_t*) TEAVM_ARRAY_DATA(teavm_local_1, int32_t)) ? sfld_jn_ByteOrder_LITTLE_ENDIAN : sfld_jn_ByteOrder_BIG_ENDIAN);
    }
    teavm_local_2 = sfld_jn_ByteOrder_nativeOrder;
    TEAVM_RELEASE_STACK;
    return teavm_local_2;
}
void meth_jn_ByteOrder__clinit_() {
    void* teavm_local_1;
    TEAVM_ALLOC_STACK(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(807, meth_otr_Allocator_allocate(&jn_ByteOrder_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    TEAVM_WITH_CALL_SITE_ID(808, teavm_initializeClass((TeaVM_Class*) &jn_ByteOrder_Cls, &initclass_jn_ByteOrder));
    TEAVM_FIELD(teavm_local_1, cls_jn_ByteOrder, fld_name) = TEAVM_GET_STRING(34);
    sfld_jn_ByteOrder_BIG_ENDIAN = teavm_local_1;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(809, meth_otr_Allocator_allocate(&jn_ByteOrder_Cls));
    TEAVM_FIELD(teavm_local_1, cls_jn_ByteOrder, fld_name) = TEAVM_GET_STRING(35);
    sfld_jn_ByteOrder_LITTLE_ENDIAN = teavm_local_1;
    TEAVM_RELEASE_STACK;
}
void initclass_jn_ByteOrder() {
    TeaVM_Class* cls = (TeaVM_Class*) &jn_ByteOrder_Cls;
    if (!(cls->flags & INT32_C(1))) {
        cls->flags |= INT32_C(1);
        meth_jn_ByteOrder__clinit_();
    }
}
int32_t supertypeof_jn_ByteOrder(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 227 || tag >= 229) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_jn_ByteOrder_Cls[2];
alignas(8) jn_ByteOrder_VT jn_ByteOrder_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jn_ByteOrder), sizeof(void*)),
            .flags = 0,
            .tag = 227,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_jn_ByteOrder,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = teavm_classLayouts_jn_ByteOrder_Cls,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static void** teavm_gc_localStaticRoots_jn_ByteOrder_Cls[3] = {
(void**) &sfld_jn_ByteOrder_BIG_ENDIAN, (void**) &sfld_jn_ByteOrder_LITTLE_ENDIAN, (void**) &sfld_jn_ByteOrder_nativeOrder
};
static int16_t teavm_classLayouts_jn_ByteOrder_Cls[2] = {
INT16_C(1), (int16_t) offsetof(cls_jn_ByteOrder, fld_name)
};
void sysinitclass_jn_ByteOrder() {
sfld_jn_ByteOrder_BIG_ENDIAN = NULL;
sfld_jn_ByteOrder_LITTLE_ENDIAN = NULL;
sfld_jn_ByteOrder_nativeOrder = NULL;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_jn_ByteOrder_Cls, 3);
}
