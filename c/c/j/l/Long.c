#include "Long.h"
#include "Number.h"
#include "../../../p/long.h"
#include "../../../strings.h"
#include "Object.h"

void* sfld_jl_Long_TYPE;
int32_t meth_jl_Long_numberOfLeadingZeros(int64_t teavm_local_1) {
    int32_t teavm_local_2;
    int64_t teavm_local_3;
    TEAVM_ALLOC_STACK(INT32_C(0));
    TEAVM_WITH_CALL_SITE_ID(391, teavm_initializeClass((TeaVM_Class*) &jl_Long_Cls, &initclass_jl_Long));
    if ((teavm_local_1 == INT64_C(0))) {
        teavm_local_2 = INT32_C(64);
    } else {
        teavm_local_2 = INT32_C(0);
        teavm_local_3 = ((int64_t) ((uint64_t) teavm_local_1 >> INT32_C(32)));
        if ((teavm_local_3 != INT64_C(0))) {
            teavm_local_2 = INT32_C(32);
        } else {
            teavm_local_3 = teavm_local_1;
        }
        teavm_local_1 = ((int64_t) ((uint64_t) teavm_local_3 >> INT32_C(16)));
        if ((teavm_local_1 == INT64_C(0))) {
            teavm_local_1 = teavm_local_3;
        } else {
            teavm_local_2 = (teavm_local_2 | INT32_C(16));
        }
        teavm_local_3 = ((int64_t) ((uint64_t) teavm_local_1 >> INT32_C(8)));
        if ((teavm_local_3 == INT64_C(0))) {
            teavm_local_3 = teavm_local_1;
        } else {
            teavm_local_2 = (teavm_local_2 | INT32_C(8));
        }
        teavm_local_1 = ((int64_t) ((uint64_t) teavm_local_3 >> INT32_C(4)));
        if ((teavm_local_1 == INT64_C(0))) {
            teavm_local_1 = teavm_local_3;
        } else {
            teavm_local_2 = (teavm_local_2 | INT32_C(4));
        }
        teavm_local_3 = ((int64_t) ((uint64_t) teavm_local_1 >> INT32_C(2)));
        if ((teavm_local_3 == INT64_C(0))) {
            teavm_local_3 = teavm_local_1;
        } else {
            teavm_local_2 = (teavm_local_2 | INT32_C(2));
        }
        if ((((int64_t) ((uint64_t) teavm_local_3 >> INT32_C(1))) != INT64_C(0))) {
            teavm_local_2 = (teavm_local_2 | INT32_C(1));
        }
        teavm_local_2 = ((INT32_C(64) - teavm_local_2) - INT32_C(1));
    }
    TEAVM_RELEASE_STACK;
    return teavm_local_2;
}
void meth_jl_Long__clinit_() {
    sfld_jl_Long_TYPE = teavm_getClassObject((TeaVM_Class*) &J_Cls);
}
void initclass_jl_Long() {
    TeaVM_Class* cls = (TeaVM_Class*) &jl_Long_Cls;
    if (!(cls->flags & INT32_C(1))) {
        cls->flags |= INT32_C(1);
        meth_jl_Long__clinit_();
    }
}
int32_t supertypeof_jl_Long(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 150 || tag >= 152) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) jl_Long_VT jl_Long_Cls = {
    .parent = {
        .parent = {
            .parent = {
                .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_jl_Long), sizeof(void*)),
                .flags = 0,
                .tag = 150,
                .modifiers = 1,
                .name = NULL,
                .arrayType = NULL,
                .itemType = NULL,
                .isSupertypeOf = &supertypeof_jl_Long,
                .superclass = (TeaVM_Class*) &jl_Number_Cls,
                .layout = NULL,
                .enumValues = NULL
            },
            .virt_clone = &meth_jl_Object_clone
        }
    }
};
static void** teavm_gc_localStaticRoots_jl_Long_Cls[1] = {
(void**) &sfld_jl_Long_TYPE
};
void sysinitclass_jl_Long() {
sfld_jl_Long_TYPE = NULL;
teavm_registerStaticGcRoots(teavm_gc_localStaticRoots_jl_Long_Cls, 1);
}
