#include <windows.h>
#include <type_traits>
#include "NSExceptionInternal.h"

// From ucrt's throw.cpp.
#define EH_EXCEPTION_NUMBER ('msc' | 0xE0000000)
#define EH_MAGIC_NUMBER1 0x19930520

template <typename T, typename U>
static std::add_const_t<std::decay_t<T>> rebase_and_cast(uintptr_t base, U value) {
    return reinterpret_cast<std::add_const_t<std::decay_t<T>>>(base + (uintptr_t)(value));
}

// _ThrowInfo, _CatchableTypeArray, _CatchableType and _TypeDescriptor (nee std::type_info) are defined by CL at compile time.
extern "C" LONG WINAPI _NSWindowsUnhandledExceptionFilter(struct _EXCEPTION_POINTERS* ExceptionInfo) {
    const EXCEPTION_RECORD* ex = ExceptionInfo->ExceptionRecord;

    // An exception thrown by libobjc2 goes through _CxxThrowException, which populates the EXCEPTION_RECORD with the magic C++
    // exception number (0xE0000000 ORed with the bytes 'msc' (in platform endianness)) and the exception parameters with
    // a _ThrowInfo*, another magic number, and the object being thrown.
    if (ex->ExceptionCode == EH_EXCEPTION_NUMBER && ex->ExceptionInformation[0] == EH_MAGIC_NUMBER1 && ex->NumberParameters >= 3) {
        // On some platforms, thrown exception catch data are relative virtual addresses off the module base.
        uintptr_t moduleBase = ex->NumberParameters >= 4 ? ex->ExceptionInformation[3] : 0;

        auto throwInfo = reinterpret_cast<_ThrowInfo*>(ex->ExceptionInformation[2]);
        if (throwInfo && throwInfo->pCatchableTypeArray) {
            auto catchableTypes = rebase_and_cast<_CatchableTypeArray*>(moduleBase, throwInfo->pCatchableTypeArray);
            // _ThrowInfo contains a handful of useful things that we completely ignore as we bumble towards the catchable type array.
            // libobjc2 populates the catchable type array with a list of mangled Objective-C class names that aid the exception catcher
            // in determining which exception type was thrown. Here we walk that list of types to find one containing NSException.
            //
            // This _will_ cause an issue if a clever developer C++-throws a value of a type with NSException in its name that derives from
            // a type with objc_object in its name.

            bool foundNSException = false;
            bool foundobjc_object = false;
            for (int i = 0; i < catchableTypes->nCatchableTypes; ++i) {
                const _CatchableType* catchableType =
                    rebase_and_cast<_CatchableType*>(moduleBase, catchableTypes->arrayOfCatchableTypes[i]);
                const _TypeDescriptor* typeDescriptor = rebase_and_cast<_TypeDescriptor*>(moduleBase, catchableType->pType);
                if (strstr(typeDescriptor->name, "NSException") != nullptr) {
                    // We're using strstr because:
                    // 1. Our exception classes are not mangled properly, but we do not want this code to break when they are.
                    // 2. The buffer is guaranteed to be null-terminated.
                    foundNSException = true;
                    continue;
                } else if (strstr(typeDescriptor->name, "objc_object") != nullptr) {
                    foundobjc_object = true;
                    // objc_object should always be after NSException*.
                    break;
                }
            }

            if (foundNSException && foundobjc_object) {
                _NSExceptionCallUnhandledExceptionHandler(*reinterpret_cast<void**>(ex->ExceptionInformation[1]));
                // EXCEPTION_EXECUTE_HANDLER instructs the exception handler to continue (and abort the app.)
                return EXCEPTION_EXECUTE_HANDLER;
            }
        }
    }

    // EXCEPTION_CONTINUE_SEARCH instructs the exception handler to continue searching for appropriate exception handlers.
    // Since this is the last one, it is not likely to find any more.
    return EXCEPTION_CONTINUE_SEARCH;
}
