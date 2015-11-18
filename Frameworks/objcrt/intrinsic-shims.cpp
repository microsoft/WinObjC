#include "error-handling.h"
#include <Windows.h>

// This is temporary, since it's supposed to be an intrinsic. When our compiler supports them correct they will be removed:

OBJCRT_EXPORT extern "C" void* _ReturnAddress() {
    return nullptr;
}

OBJCRT_EXPORT extern "C" void __fastfail(unsigned) {
    RaiseFailFastException(nullptr, nullptr, 0);
}
