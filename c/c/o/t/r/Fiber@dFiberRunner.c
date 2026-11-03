#include "Fiber@dFiberRunner.h"
#include "../../../../strings.h"

int32_t supertypeof_otr_Fiber_FiberRunner(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 107 || tag >= 109) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) TeaVM_Class otr_Fiber_FiberRunner_Cls = {
    .size = 0,
    .flags = 0,
    .tag = 107,
    .modifiers = 1537,
    .name = NULL,
    .arrayType = NULL,
    .itemType = NULL,
    .isSupertypeOf = &supertypeof_otr_Fiber_FiberRunner,
    .superclass = NULL,
    .layout = NULL,
    .enumValues = NULL
};
void sysinitclass_otr_Fiber_FiberRunner() {
}
