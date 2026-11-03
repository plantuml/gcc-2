#include "HashMap.h"
#include "AbstractMap.h"
#include "MapEntry.h"
#include "HashMap@dHashEntry.h"
#include "../../o/t/r/Allocator.h"
#include "../l/Object.h"
#include "../../../arrayclass.h"
#include "../../../strings.h"

int32_t meth_ju_HashMap_calculateCapacity(int32_t teavm_local_1) {
    int32_t teavm_local_2;
    if ((teavm_local_1 < INT32_C(1073741824))) {
        if (teavm_local_1) {
            teavm_local_2 = (teavm_local_1 - INT32_C(1));
            teavm_local_1 = (teavm_local_2 | (teavm_local_2 >> INT32_C(1)));
            teavm_local_1 = (teavm_local_1 | (teavm_local_1 >> INT32_C(2)));
            teavm_local_1 = (teavm_local_1 | (teavm_local_1 >> INT32_C(4)));
            teavm_local_1 = (teavm_local_1 | (teavm_local_1 >> INT32_C(8)));
            return ((teavm_local_1 | (teavm_local_1 >> INT32_C(16))) + INT32_C(1));
        }
        return INT32_C(16);
    }
    return INT32_C(1073741824);
}
void* meth_ju_HashMap_putImpl(void* teavm_this_, void* teavm_local_1, void* teavm_local_2) {
    TeaVM_Array* teavm_local_3;
    void* teavm_local_4;
    void* teavm_local_5;
    int32_t teavm_local_6;
    int32_t teavm_local_7;
    int32_t teavm_local_8;
    void* teavm_local_9;
    TEAVM_ALLOC_STACK(INT32_C(3));
    if ((teavm_local_1 == NULL)) {
        teavm_local_3 = TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_elementData);
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(449, teavm_nullCheck(teavm_local_3));
        teavm_local_4 = TEAVM_ARRAY_AT(teavm_local_3, void*, TEAVM_WITH_CALL_SITE_ID(450, teavm_checkUpperBound(INT32_C(0), teavm_local_3)));
        while (1) {
            if (!((teavm_local_4 != NULL) && (TEAVM_FIELD(teavm_local_4, cls_ju_MapEntry, fld_key) != NULL))) break;
            teavm_local_4 = TEAVM_FIELD(teavm_local_4, cls_ju_HashMap_HashEntry, fld_next);
        }
        if ((teavm_local_4 == NULL)) {
            TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_modCount) = (TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_modCount) + INT32_C(1));
            teavm_local_1 = NULL;
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(451, meth_otr_Allocator_allocate(&ju_HashMap_HashEntry_Cls));
            teavm_local_5 = NULL;
            TEAVM_FIELD(teavm_local_4, cls_ju_MapEntry, fld_key) = teavm_local_1;
            TEAVM_FIELD(teavm_local_4, cls_ju_MapEntry, fld_value) = teavm_local_5;
            TEAVM_FIELD(teavm_local_4, cls_ju_HashMap_HashEntry, fld_origKeyHash) = INT32_C(0);
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_4);
            teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(452, teavm_checkUpperBound(INT32_C(0), teavm_local_3));
            teavm_local_1 = TEAVM_ARRAY_AT(teavm_local_3, void*, teavm_local_6);
            teavm_gc_writeBarrier(teavm_local_4);
            TEAVM_FIELD(teavm_local_4, cls_ju_HashMap_HashEntry, fld_next) = teavm_local_1;
            teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(453, teavm_checkUpperBound(teavm_local_6, teavm_local_3));
            teavm_gc_writeBarrier(teavm_local_3);
            TEAVM_ARRAY_AT(teavm_local_3, void*, teavm_local_6) = teavm_local_4;
            teavm_local_6 = (TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_elementCount) + INT32_C(1));
            TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_elementCount) = teavm_local_6;
            if ((teavm_local_6 > TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_threshold))) {
                teavm_local_7 = TEAVM_ARRAY_LENGTH(teavm_local_3);
                TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                TEAVM_WITH_CALL_SITE_ID(454, meth_ju_HashMap_rehash(teavm_this_, teavm_local_7));
            }
        }
    } else {
        TEAVM_GC_ROOT_RELEASE(INT32_C(0));
        TEAVM_GC_ROOT_RELEASE(INT32_C(1));
        TEAVM_GC_ROOT_RELEASE(INT32_C(2));
        teavm_local_7 = TEAVM_WITH_CALL_SITE_ID(455, TEAVM_METHOD(teavm_local_1, jl_Object_VT, virt_hashCode)(teavm_local_1));
        teavm_local_3 = TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_elementData);
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_3);
        teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(456, teavm_nullCheck(teavm_local_3));
        teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(457, teavm_checkBounds((teavm_local_7 & (TEAVM_ARRAY_LENGTH(teavm_local_3) - INT32_C(1))), teavm_local_3));
        teavm_local_4 = TEAVM_ARRAY_AT(teavm_local_3, void*, teavm_local_8);
        while (1) {
            if (!(teavm_local_4 != NULL)) break;
            if ((TEAVM_FIELD(teavm_local_4, cls_ju_HashMap_HashEntry, fld_origKeyHash) == teavm_local_7)) {
                teavm_local_5 = TEAVM_FIELD(teavm_local_4, cls_ju_MapEntry, fld_key);
                if ((teavm_local_1 != teavm_local_5)) {
                    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
                    TEAVM_GC_ROOT(INT32_C(1), teavm_local_4);
                    TEAVM_GC_ROOT(INT32_C(2), teavm_local_5);
                    teavm_local_9 = TEAVM_WITH_CALL_SITE_ID(458, teavm_nullCheck(teavm_local_1));
                    TEAVM_GC_ROOT(INT32_C(0), teavm_local_9);
                    if ((!TEAVM_WITH_CALL_SITE_ID(459, TEAVM_METHOD(teavm_local_9, jl_Object_VT, virt_equals)(teavm_local_9, teavm_local_5)))) {
                        goto teavm_label_4;
                    }
                }
                teavm_local_6 = INT32_C(1);
                goto teavm_label_3;
            teavm_label_4:;
                teavm_local_6 = INT32_C(0);
            teavm_label_3:;
                if (teavm_local_6) {
                    goto teavm_label_2;
                }
            }
            teavm_local_4 = TEAVM_FIELD(teavm_local_4, cls_ju_HashMap_HashEntry, fld_next);
        }
    teavm_label_2:;
        if ((teavm_local_4 == NULL)) {
            TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_modCount) = (TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_modCount) + INT32_C(1));
            TEAVM_GC_ROOT_RELEASE(INT32_C(0));
            teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(460, meth_otr_Allocator_allocate(&ju_HashMap_HashEntry_Cls));
            teavm_local_5 = NULL;
            TEAVM_FIELD(teavm_local_4, cls_ju_MapEntry, fld_key) = teavm_local_1;
            TEAVM_FIELD(teavm_local_4, cls_ju_MapEntry, fld_value) = teavm_local_5;
            TEAVM_FIELD(teavm_local_4, cls_ju_HashMap_HashEntry, fld_origKeyHash) = teavm_local_7;
            teavm_local_3 = TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_elementData);
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_4);
            TEAVM_GC_ROOT(INT32_C(1), teavm_local_3);
            teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(461, teavm_nullCheck(teavm_local_3));
            teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(462, teavm_checkUpperBound(teavm_local_8, teavm_local_3));
            teavm_local_1 = TEAVM_ARRAY_AT(teavm_local_3, void*, teavm_local_6);
            teavm_gc_writeBarrier(teavm_local_4);
            TEAVM_FIELD(teavm_local_4, cls_ju_HashMap_HashEntry, fld_next) = teavm_local_1;
            teavm_local_6 = TEAVM_WITH_CALL_SITE_ID(463, teavm_checkUpperBound(teavm_local_6, teavm_local_3));
            teavm_gc_writeBarrier(teavm_local_3);
            TEAVM_ARRAY_AT(teavm_local_3, void*, teavm_local_6) = teavm_local_4;
            teavm_local_6 = (TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_elementCount) + INT32_C(1));
            TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_elementCount) = teavm_local_6;
            if ((teavm_local_6 > TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_threshold))) {
                teavm_local_7 = TEAVM_ARRAY_LENGTH(teavm_local_3);
                TEAVM_GC_ROOT_RELEASE(INT32_C(1));
                TEAVM_WITH_CALL_SITE_ID(464, meth_ju_HashMap_rehash(teavm_this_, teavm_local_7));
            }
        }
    }
    teavm_local_5 = TEAVM_FIELD(teavm_local_4, cls_ju_MapEntry, fld_value);
    teavm_gc_writeBarrier(teavm_local_4);
    TEAVM_FIELD(teavm_local_4, cls_ju_MapEntry, fld_value) = teavm_local_2;
    TEAVM_RELEASE_STACK;
    return teavm_local_5;
}
void meth_ju_HashMap_rehash(void* teavm_this_, int32_t teavm_local_1) {
    int32_t teavm_local_2;
    TeaVM_Array* teavm_local_3;
    int32_t teavm_local_4;
    TeaVM_Array* teavm_local_5;
    void* teavm_local_6;
    void* teavm_local_7;
    int32_t teavm_local_8;
    void* teavm_local_9;
    TEAVM_ALLOC_STACK(INT32_C(3));
    teavm_local_1 = ((!teavm_local_1) ? INT32_C(1) : (teavm_local_1 << INT32_C(1)));
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_GC_ROOT_RELEASE(INT32_C(1));
    TEAVM_GC_ROOT_RELEASE(INT32_C(2));
    teavm_local_2 = TEAVM_WITH_CALL_SITE_ID(465, meth_ju_HashMap_calculateCapacity(teavm_local_1));
    teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(466, meth_otr_Allocator_allocateArray(teavm_getArrayClass((TeaVM_Class*) &ju_HashMap_HashEntry_Cls), teavm_local_2));
    teavm_local_4 = INT32_C(0);
    teavm_local_2 = (teavm_local_2 - INT32_C(1));
    while (1) {
        teavm_local_5 = TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_elementData);
        TEAVM_GC_ROOT(INT32_C(0), teavm_local_5);
        TEAVM_GC_ROOT(INT32_C(2), teavm_local_3);
        teavm_local_5 = TEAVM_WITH_CALL_SITE_ID(467, teavm_nullCheck(teavm_local_5));
        if ((teavm_local_4 >= TEAVM_ARRAY_LENGTH(teavm_local_5))) {
            goto teavm_label_1;
        }
        teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(468, teavm_checkBounds(teavm_local_4, teavm_local_5));
        teavm_local_6 = TEAVM_ARRAY_AT(teavm_local_5, void*, teavm_local_4);
        teavm_local_7 = NULL;
        TEAVM_GC_ROOT(INT32_C(1), teavm_local_6);
        teavm_local_4 = TEAVM_WITH_CALL_SITE_ID(469, teavm_checkUpperBound(teavm_local_4, teavm_local_5));
        TEAVM_ARRAY_AT(teavm_local_5, void*, teavm_local_4) = teavm_local_7;
        while (1) {
            if (!(teavm_local_6 != NULL)) break;
            teavm_local_8 = (TEAVM_FIELD(teavm_local_6, cls_ju_HashMap_HashEntry, fld_origKeyHash) & teavm_local_2);
            teavm_local_7 = TEAVM_FIELD(teavm_local_6, cls_ju_HashMap_HashEntry, fld_next);
            TEAVM_GC_ROOT(INT32_C(0), teavm_local_6);
            TEAVM_GC_ROOT(INT32_C(1), teavm_local_7);
            TEAVM_GC_ROOT(INT32_C(2), teavm_local_3);
            teavm_local_3 = TEAVM_WITH_CALL_SITE_ID(470, teavm_nullCheck(teavm_local_3));
            teavm_local_5 = teavm_local_3;
            teavm_local_8 = TEAVM_WITH_CALL_SITE_ID(471, teavm_checkBounds(teavm_local_8, teavm_local_5));
            teavm_local_9 = TEAVM_ARRAY_AT(teavm_local_5, void*, teavm_local_8);
            teavm_gc_writeBarrier(teavm_local_6);
            TEAVM_FIELD(teavm_local_6, cls_ju_HashMap_HashEntry, fld_next) = teavm_local_9;
            teavm_gc_writeBarrier(teavm_local_5);
            TEAVM_ARRAY_AT(teavm_local_5, void*, teavm_local_8) = teavm_local_6;
            teavm_local_6 = teavm_local_7;
        }
        teavm_local_4 = (teavm_local_4 + INT32_C(1));
    }
teavm_label_1:;
    teavm_gc_writeBarrier(teavm_this_);
    TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_elementData) = teavm_local_3;
    TEAVM_GC_ROOT_RELEASE(INT32_C(0));
    TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_threshold) = ((int32_t) (((float) TEAVM_ARRAY_LENGTH(TEAVM_WITH_CALL_SITE_ID(472, teavm_nullCheck(teavm_local_3)))) * TEAVM_FIELD(teavm_this_, cls_ju_HashMap, fld_loadFactor)));
    TEAVM_RELEASE_STACK;
}
int32_t supertypeof_ju_HashMap(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 162 || tag >= 164) return INT32_C(0);
    return INT32_C(1);
}
static int16_t teavm_classLayouts_ju_HashMap_Cls[2];
alignas(8) ju_HashMap_VT ju_HashMap_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_ju_HashMap), sizeof(void*)),
                .flags = 0,
                .tag = 162,
                .modifiers = 1,
                .name = NULL,
                .arrayType = NULL,
                .itemType = NULL,
                .isSupertypeOf = &supertypeof_ju_HashMap,
                .superclass = (TeaVM_Class*) &ju_AbstractMap_Cls,
                .layout = teavm_classLayouts_ju_HashMap_Cls,
                .enumValues = NULL
            }
        }
    }
};
static int16_t teavm_classLayouts_ju_HashMap_Cls[2] = {
INT16_C(1), (int16_t) offsetof(cls_ju_HashMap, fld_elementData)
};
void sysinitclass_ju_HashMap() {
}
