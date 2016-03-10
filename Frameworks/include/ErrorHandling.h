//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#ifndef __ERRORHANDLING_H
#define __ERRORHANDLING_H

#include <sys/cdefs.h>
#include <winerror.h>
#include <stdarg.h>

namespace wil {
struct FailureInfo;
}

// We need to do a bit of work to be able to pull in the result.h file and all of its error handling helpers

#pragma push_macro("PCWSTR")
#undef PCWSTR
#define PCWSTR const wchar_t *

#pragma push_macro("PWSTR")
#undef PWSTR
#define PWSTR wchar_t *

#pragma push_macro("PCSTR")
#undef PCSTR
#define PCSTR const char *

#pragma push_macro("PSTR")
#undef PSTR
#define PSTR char *

#pragma push_macro("ARRAYSIZE")
#undef ARRAYSIZE
#define ARRAYSIZE(A) (sizeof(A) / sizeof((A)[0]))

#pragma push_macro("FORMAT_MESSAGE_IGNORE_INSERTS")
#undef FORMAT_MESSAGE_IGNORE_INSERTS
#define FORMAT_MESSAGE_IGNORE_INSERTS 0x00000200

#pragma push_macro("FORMAT_MESSAGE_FROM_STRING")
#undef FORMAT_MESSAGE_FROM_STRING
#define FORMAT_MESSAGE_FROM_STRING 0x00000400

#pragma push_macro("FORMAT_MESSAGE_FROM_HMODULE")
#undef FORMAT_MESSAGE_FROM_HMODULE
#define FORMAT_MESSAGE_FROM_HMODULE 0x00000800

#pragma push_macro("FORMAT_MESSAGE_FROM_SYSTEM")
#undef FORMAT_MESSAGE_FROM_SYSTEM
#define FORMAT_MESSAGE_FROM_SYSTEM 0x00001000

#pragma push_macro("FORMAT_MESSAGE_ARGUMENT_ARRAY")
#undef FORMAT_MESSAGE_ARGUMENT_ARRAY
#define FORMAT_MESSAGE_ARGUMENT_ARRAY 0x00002000

#pragma push_macro("FORMAT_MESSAGE_MAX_WIDTH_MASK")
#undef FORMAT_MESSAGE_MAX_WIDTH_MASK
#define FORMAT_MESSAGE_MAX_WIDTH_MASK 0x000000FF

#pragma push_macro("LANG_NEUTRAL")
#undef LANG_NEUTRAL
#define LANG_NEUTRAL 0x00

#pragma push_macro("SUBLANG_DEFAULT")
#undef SUBLANG_DEFAULT
#define SUBLANG_DEFAULT 0x01 // user default

#pragma push_macro("MAKELANGID")
#undef MAKELANGID
#define MAKELANGID(p, s) ((((WORD)(s)) << 10) | (WORD)(p))

#pragma push_macro("INVALID_HANDLE_VALUE")
#undef INVALID_HANDLE_VALUE
#define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1)

#pragma push_macro("FAST_FAIL_FATAL_APP_EXIT")
#undef FAST_FAIL_FATAL_APP_EXIT
#define FAST_FAIL_FATAL_APP_EXIT 7

#pragma push_macro("STATUS_NO_MEMORY")
#undef STATUS_NO_MEMORY
#define STATUS_NO_MEMORY ((unsigned long)0xC0000017L)

typedef int INT_PTR, *PINT_PTR;
typedef unsigned int UINT_PTR, *PUINT_PTR;

typedef long LONG;

typedef long LONG_PTR, *PLONG_PTR;
typedef unsigned long ULONG_PTR, *PULONG_PTR;

typedef ULONG_PTR SIZE_T, *PSIZE_T;
typedef void* HANDLE;

typedef int BOOL;
typedef unsigned short WORD;
typedef void* PVOID;

#ifndef BASETYPES
#define BASETYPES
typedef unsigned long ULONG;
typedef ULONG* PULONG;
typedef unsigned short USHORT;
typedef USHORT* PUSHORT;
typedef unsigned char UCHAR;
typedef UCHAR* PUCHAR;
typedef char* PSZ;
#endif /* !BASETYPES */

// Templates are defined here in order to avoid a dependency on C++ <type_traits> header file,
// or on compiler-specific contructs.
extern "C++" {
template <size_t S>
struct OBJC_ENUM_FLAG_INTEGER_FOR_SIZE;

template <>
struct OBJC_ENUM_FLAG_INTEGER_FOR_SIZE<1> {
    typedef char type;
};

template <>
struct OBJC_ENUM_FLAG_INTEGER_FOR_SIZE<2> {
    typedef short type;
};

template <>
struct OBJC_ENUM_FLAG_INTEGER_FOR_SIZE<4> {
    typedef int type;
};

// used as an approximation of std::underlying_type<T>
template <class T>
struct OBJC_ENUM_FLAG_SIZED_INTEGER {
    typedef typename OBJC_ENUM_FLAG_INTEGER_FOR_SIZE<sizeof(T)>::type type;
};
}

#pragma push_macro("DEFINE_ENUM_FLAG_OPERATORS")
#undef DEFINE_ENUM_FLAG_OPERATORS
#define DEFINE_ENUM_FLAG_OPERATORS(ENUMTYPE)                                                                                         \
    extern "C++" {                                                                                                                   \
    inline ENUMTYPE operator|(ENUMTYPE a, ENUMTYPE b) {                                                                              \
        return ENUMTYPE(((OBJC_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)a) | ((OBJC_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b));      \
    }                                                                                                                                \
    inline ENUMTYPE& operator|=(ENUMTYPE& a, ENUMTYPE b) {                                                                           \
        return (ENUMTYPE&)(((OBJC_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type&)a) |= ((OBJC_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b)); \
    }                                                                                                                                \
    inline ENUMTYPE operator&(ENUMTYPE a, ENUMTYPE b) {                                                                              \
        return ENUMTYPE(((OBJC_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)a) & ((OBJC_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b));      \
    }                                                                                                                                \
    inline ENUMTYPE& operator&=(ENUMTYPE& a, ENUMTYPE b) {                                                                           \
        return (ENUMTYPE&)(((OBJC_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type&)a) &= ((OBJC_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b)); \
    }                                                                                                                                \
    inline ENUMTYPE operator~(ENUMTYPE a) {                                                                                          \
        return ENUMTYPE(~((OBJC_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)a));                                                         \
    }                                                                                                                                \
    inline ENUMTYPE operator^(ENUMTYPE a, ENUMTYPE b) {                                                                              \
        return ENUMTYPE(((OBJC_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)a) ^ ((OBJC_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b));      \
    } inline ENUMTYPE&                                                                                                               \
    operator^=(ENUMTYPE& a, ENUMTYPE b) {                                                                                            \
        return (ENUMTYPE&)(((OBJC_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type&)a) ^= ((OBJC_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b)); \
    }                                                                                                                                \
    }

// Override Win32 function calls
#pragma push_macro("GetCurrentThreadId")
#pragma push_macro("InterlockedIncrementNoFence")
#pragma push_macro("GetLastError")
#pragma push_macro("CopyMemory")
#pragma push_macro("ZeroMemory")
#pragma push_macro("FormatMessageW")
#pragma push_macro("OutputDebugStringW")
#pragma push_macro("InterlockedDecrementRelease")
#pragma push_macro("InterlockedCompareExchangePointer")

__BEGIN_DECLS

#ifndef IWPLATFORM_EXPORT
#define IWPLATFORM_EXPORT
#endif

// Should hitting the UNIMPLEMENTED macro cause a fast fail? If this returns false, we still log unimplemented calls but they are not fatal.
IWPLATFORM_EXPORT bool failFastOnUnimplemented();

// Error-handling exports
IWPLATFORM_EXPORT unsigned long starboardGetCurrentThreadId();
IWPLATFORM_EXPORT long starboardInterlockedIncrementNoFence(long volatile* addend);
IWPLATFORM_EXPORT unsigned long starboardGetLastError();
IWPLATFORM_EXPORT void starboardCopyMemory(void* destination, const void* source, size_t length);
IWPLATFORM_EXPORT void starboardZeroMemory(void* destination, size_t length);
IWPLATFORM_EXPORT unsigned long starboardFormatMessageW(unsigned long flags,
                                                        const void* source,
                                                        unsigned long messageId,
                                                        unsigned long languageId,
                                                        wchar_t* buffer,
                                                        unsigned long size,
                                                        va_list* arguments);
IWPLATFORM_EXPORT void starboardOutputDebugStringW(wchar_t* outputString);
IWPLATFORM_EXPORT long starboardInterlockedDecrementRelease(long volatile* addend);
IWPLATFORM_EXPORT void* starboardInterlockedCompareExchangePointer(void* volatile* destination, void* exchange, void* comparand);

__END_DECLS

#define GetCurrentThreadId starboardGetCurrentThreadId
#define InterlockedIncrementNoFence starboardInterlockedIncrementNoFence
#define GetLastError starboardGetLastError
#define CopyMemory starboardCopyMemory
#define ZeroMemory starboardZeroMemory
#define FormatMessageW starboardFormatMessageW
#define OutputDebugStringW starboardOutputDebugStringW
#define InterlockedDecrementRelease starboardInterlockedDecrementRelease
#define InterlockedCompareExchangePointer starboardInterlockedCompareExchangePointer

// Ignore some warnings in result.h
#if defined __clang__

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-noreturn"
#pragma clang diagnostic ignored "-Wunused-value"

#ifdef _M_ARM
// Disable 'invalid calling convention' warnings for __stdcall usage in ARM builds
#pragma clang diagnostic ignored "-Wignored-attributes"
#endif // _M_ARM

#endif // __clang__

// Always log debug info even on release builds
#define RESULT_DEBUG_INFO
#include "wil/result.h"

#if defined __clang__
#pragma clang diagnostic pop
#endif

// Pop all the temp Win32 function defines
#pragma pop_macro("GetCurrentThreadId")
#pragma pop_macro("InterlockedIncrementNoFence")
#pragma pop_macro("GetLastError")
#pragma pop_macro("CopyMemory")
#pragma pop_macro("ZeroMemory")
#pragma pop_macro("FormatMessageW")
#pragma pop_macro("OutputDebugStringW")
#pragma pop_macro("InterlockedDecrementRelease")
#pragma pop_macro("InterlockedCompareExchangePointer")

// Pop all the temp Win32 defines
#pragma pop_macro("PCWSTR")
#pragma pop_macro("PWSTR")
#pragma pop_macro("PCSTR")
#pragma pop_macro("PSTR")
#pragma pop_macro("ARRAYSIZE")
#pragma pop_macro("FORMAT_MESSAGE_IGNORE_INSERTS")
#pragma pop_macro("FORMAT_MESSAGE_FROM_STRING")
#pragma pop_macro("FORMAT_MESSAGE_FROM_HMODULE")
#pragma pop_macro("FORMAT_MESSAGE_FROM_SYSTEM")
#pragma pop_macro("FORMAT_MESSAGE_ARGUMENT_ARRAY")
#pragma pop_macro("FORMAT_MESSAGE_MAX_WIDTH_MASK")
#pragma pop_macro("LANG_NEUTRAL")
#pragma pop_macro("SUBLANG_DEFAULT")
#pragma pop_macro("MAKELANGID")
#pragma pop_macro("INVALID_HANDLE_VALUE")
#pragma pop_macro("FAST_FAIL_FATAL_APP_EXIT")
#pragma pop_macro("STATUS_NO_MEMORY")
#pragma pop_macro("DEFINE_ENUM_FLAG_OPERATORS")

//*****************************************************************************
// WinObjC Extensions
//*****************************************************************************

// This should be used for functions which have no implementation yet:
#define UNIMPLEMENTED()                                    \
    if (failFastOnUnimplemented()) {                       \
        FAIL_FAST_HR(E_NOTIMPL);                           \
    } else {                                               \
        LOG_HR_MSG(E_NOTIMPL, "Stubbed function called!"); \
    }

// This should be used to convey information along with the fact that something isn't implemented. For example, if we have a
// portion of a function implemented but we've hit something unsupported:
#define UNIMPLEMENTED_WITH_MSG(msg, ...)               \
    if (failFastOnUnimplemented()) {                   \
        FAIL_FAST_HR_MSG(E_NOTIMPL, msg, __VA_ARGS__); \
    } else {                                           \
        LOG_HR_MSG(E_NOTIMPL, msg, __VA_ARGS__);       \
    }

#endif // __ERRORHANDLING_H
