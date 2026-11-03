#include "proxy.h"
#include "core.h"
#include "reflection.h"
#include "strings.h"

static void* teavm_proxyMethods[1];

void* teavm_getProxyMethod(int32_t index) {
    return teavm_proxyMethods[index];
}

void teavm_proxy_registerClasses(void) {
}
