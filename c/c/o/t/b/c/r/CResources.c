#include "CResources.h"
#include "../../../../../j/l/Object.h"
#include "../../../r/Allocator.h"
#include "../../../../../../strings.h"
#include "../../../../../../arrayclass.h"
#include "CResources@dResource.h"
#include "../../../../../../resources_gen.h"
#include "../../../../../j/u/HashMap.h"
#include "../../../../../j/u/HashMap@dHashEntry.h"

void* sfld_otbcr_CResources_resources;
const char teavm_resourceData[] = "";
TeaVM_Array* meth_otbcr_CResources_acquireResources() {
    TeaVM_Array* result = (TeaVM_Array*) meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &otbcr_CResources_Resource_Cls), 0);
    void** arrayData = TEAVM_ARRAY_DATA(result, void*);
    return result;
}
void* meth_otbcr_CResources_create(void* teavm_local_1, int32_t teavm_local_2, int32_t teavm_local_3) {
    void* teavm_local_4;
    void* teavm_local_5;
    TEAVM_ALLOC_STACK(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_WITH_CALL_SITE_ID(276, teavm_initializeClass((TeaVM_Class*) &otbcr_CResources_Cls, &initclass_otbcr_CResources));
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(277, meth_otr_Allocator_allocate(&otbcr_CResources_Resource_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_4);
    teavm_local_5 = TEAVM_ADDRESS_ADD(TEAVM_WITH_CALL_SITE_ID(278, ((void*) teavm_resourceData)), teavm_local_2);
    teavm_gc_writeBarrier(teavm_local_4);
    TEAVM_FIELD(teavm_local_4, cls_otbcr_CResources_Resource, fld_name) = teavm_local_1;
    TEAVM_FIELD(teavm_local_4, cls_otbcr_CResources_Resource, fld_start) = teavm_local_5;
    TEAVM_FIELD(teavm_local_4, cls_otbcr_CResources_Resource, fld_length) = teavm_local_3;
    TEAVM_RELEASE_STACK;
    return teavm_local_4;
}
void meth_otbcr_CResources__clinit_() {
    void* teavm_local_1;
    int32_t teavm_local_2;
    TeaVM_Array* teavm_local_3;
    TeaVM_Array* teavm_local_4;
    int32_t teavm_local_5;
    int32_t teavm_local_6;
    void* teavm_local_7;
    void* teavm_local_8;
    TEAVM_ALLOC_STACK(INT32_C(4));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    TEAVM_GC_ROOT_RELEASE(INT32_C(3));
    teavm_local_1 = TEAVM_WITH_CALL_SITE_ID(279, meth_otr_Allocator_allocate(&ju_HashMap_Cls));
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_1);
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(280, meth_ju_HashMap_calculateCapacity(INT32_C(16)));
    TEAVM_FIELD(teavm_local_1, cls_ju_HashMap, fld_elementCount) = INT32_C(0);
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(281, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &ju_HashMap_HashEntry_Cls), teavm_local_2));
    teavm_local_4 = teavm_local_3;
    teavm_gc_writeBarrier(teavm_local_1);
    TEAVM_FIELD(teavm_local_1, cls_ju_HashMap, fld_elementData) = teavm_local_3;
    TEAVM_FIELD(teavm_local_1, cls_ju_HashMap, fld_loadFactor) = 0x1.8p-1f;
    TEAVM_FIELD(teavm_local_1, cls_ju_HashMap, fld_threshold) = ((int32_t) (((float) TEAVM_ARRAY_LENGTH(teavm_local_4)) * 0x1.8p-1f));
    sfld_otbcr_CResources_resources = teavm_local_1;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(282, meth_otbcr_CResources_acquireResources());
    TEAVM_GC_ROOT(INT32_C(0), teavm_local_4);
    teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(283, teavm_nullCheck(teavm_local_4));
    teavm_local_2 = TEAVM_ARRAY_LENGTH(teavm_local_4);
    teavm_local_5 = INT32_C(0);
    while (1) {
        if (!(teavm_local_5 < teavm_local_2)) break;
        teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(284, teavm_checkLowerBound(teavm_local_5));
        teavm_local_1 = TEAVM_ARRAY_AT(teavm_local_4, void*, teavm_local_6);
        teavm_local_7 = sfld_otbcr_CResources_resources;
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_1);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_7);
        teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(285, teavm_nullCheck(teavm_local_1));
        teavm_local_1 = TEAVM_FIELD(teavm_local_8, cls_otbcr_CResources_Resource, fld_name);
        teavm_local_7 = teavm_local_7;
        TEAVM_GC_ROOT(INT32_C(3), teavm_local_1);
        TEAVM_WITH_CALL_SITE_ID(286, meth_ju_HashMap_putImpl(TEAVM_WITH_CALL_SITE_ID(287, teavm_nullCheck(teavm_local_7)), teavm_local_1, teavm_local_8));
        teavm_local_5 = (teavm_local_6 + INT32_C(1));
    }
    TEAVM_RELEASE_STACK;
}
void initclass_otbcr_CResources() {
    TeaVM_Class* cls = (TeaVM_Class*) &otbcr_CResources_Cls;
    if (!(cls->flags & INT32_C(1))) {
        cls->flags |= INT32_C(1);
        meth_otbcr_CResources__clinit_();
    }
}
int32_t supertypeof_otbcr_CResources(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 123 || tag >= 125) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) otbcr_CResources_VT otbcr_CResources_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otbcr_CResources), sizeof(void*)),
            .flags = 0,
            .tag = 123,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_otbcr_CResources,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
static void** teavm_gc_localStaticRoots_otbcr_CResources_Cls[1] = {
(void**) &sfld_otbcr_CResources_resources
};
void sysinitclass_otbcr_CResources() {
sfld_otbcr_CResources_resources = NULL;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_otbcr_CResources_Cls, 1);
}
