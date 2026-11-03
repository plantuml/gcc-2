#include "RuntimeObject.h"

int32_t sfld_otr_RuntimeObject_GC_MARKED;
int32_t sfld_otr_RuntimeObject_GC_OLD_GENERATION;
int32_t sfld_otr_RuntimeObject_nextId;
void sysinitclass_otr_RuntimeObject() {
    sfld_otr_RuntimeObject_GC_MARKED = (int32_t) INT32_C(0x80000000);
    sfld_otr_RuntimeObject_GC_OLD_GENERATION = INT32_C(1073741824);
    sfld_otr_RuntimeObject_nextId = INT32_C(0);
}
