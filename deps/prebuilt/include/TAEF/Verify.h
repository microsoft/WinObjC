//---------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>File used for test verification purposes.</summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//---------------------------------------------------------------------------------------------------------------------
#pragma once
#include <limits.h>
#include <winerror.h>

#if (_MSC_VER < 1700)
# error Unsupported version of Visual Studio. Please use VS 2012 or later.
#endif

// Without deprecation support StrSafe.h will define 'malicious' macros in an attempt to prevent older API usage.
// These errors are confusing - deprecation is a lot clearer.
#if !defined(MIDL_PASS) && !defined(DEPRECATE_SUPPORTED)
# define DEPRECATE_SUPPORTED
#endif

#if defined(_CPPUNWIND) && (defined(_STL100_) || defined(_STL110_) || defined (_STL120_) || defined(_STL140_))
#define TAEF_STL_SUPPORT
#endif

#include "Log.h"
#include "StrSafe.h"
#include "PreserveLastError.h"
#include "WexAssert.h"
#include "WexDebug.h"
#include "WexString.h"
#include "WexTypes.h"

#pragma push_macro("_Post_equal_to_")
#if !defined(_Post_equal_to_)
#define _Post_equal_to_(x)
#endif

#pragma push_macro("_Out_opt_")
#if !defined(_Out_opt_)
#define _Out_opt_
#endif

#pragma push_macro("Verify")
#undef Verify

#pragma push_macro("SEALED")
#undef SEALED

#if _MSC_VER >= 1800
# define SEALED final
#elif _MSC_VER >= 1400
# define SEALED sealed
#elif defined(_MSC_VER)
# define SEALED
#else
# define SEALED final
#endif

// Disable verify exception usage if exceptions are disabled for this project
#ifndef _CPPUNWIND
    #ifndef NO_VERIFY_EXCEPTIONS
        #define NO_VERIFY_EXCEPTIONS
    #endif
#endif

#ifdef _CPPUNWIND
    #include "WexException.h"
    #if defined(TAEF_STL_SUPPORT)
        #pragma push_macro("HUGE")
        #undef HUGE
        #include <string>
        #pragma pop_macro("HUGE")
    #endif // #if defined(TAEF_STL_SUPPORT)

    #include <exception>
#endif //_CPPUNWIND is defined

/// <summary>
/// \def VERIFY_ARE_EQUAL(__expected, __actual, ...)
/// Verifies that two specified objects are equal.
/// </summary>
# define VERIFY_ARE_EQUAL(__expected, __actual, ...) (bool)WEX::TestExecution::Private::MacroVerify::AreEqual((__expected), (__actual), (L#__expected), (L#__actual), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that two specified objects are not equal.
# define VERIFY_ARE_NOT_EQUAL(__expected, __actual, ...) (bool)WEX::TestExecution::Private::MacroVerify::AreNotEqual((__expected), (__actual), (L#__expected) , (L#__actual), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the first parameter is greater than the second parameter.
# define VERIFY_IS_GREATER_THAN(__expectedGreater, __expectedLess, ...) (bool)WEX::TestExecution::Private::MacroVerify::IsGreaterThan((__expectedGreater), (__expectedLess), (L#__expectedGreater) , (L#__expectedLess), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the first parameter is greater than or equal to the second parameter.
# define VERIFY_IS_GREATER_THAN_OR_EQUAL(__expectedGreater, __expectedLess, ...) (bool)WEX::TestExecution::Private::MacroVerify::IsGreaterThanOrEqual((__expectedGreater), (__expectedLess), (L#__expectedGreater) , (L#__expectedLess), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the first parameter is less than the second parameter.
# define VERIFY_IS_LESS_THAN(__expectedLess, __expectedGreater, ...) (bool)WEX::TestExecution::Private::MacroVerify::IsLessThan((__expectedLess), (__expectedGreater), (L#__expectedLess) , (L#__expectedGreater), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the first parameter is less than or equal to the second parameter.
# define VERIFY_IS_LESS_THAN_OR_EQUAL(__expectedLess, __expectedGreater, ...) (bool)WEX::TestExecution::Private::MacroVerify::IsLessThanOrEqual((__expectedLess), (__expectedGreater), (L#__expectedLess) , (L#__expectedGreater), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the two parameters specified refer to the same object.
# define VERIFY_ARE_SAME(__expected, __actual, ...) (bool)WEX::TestExecution::Private::MacroVerify::AreSame((__expected), (__actual), (L#__expected), (L#__actual), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the two parameters specified do not refer to the same object.
# define VERIFY_ARE_NOT_SAME(__expected, __actual, ...) (bool)WEX::TestExecution::Private::MacroVerify::AreNotSame((__expected), (__actual), (L#__expected), (L#__actual), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Fails without checking any conditions.
# define VERIFY_FAIL(...) (bool)WEX::TestExecution::Private::MacroVerify::Fail(PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the specified condition is true.
# define VERIFY_IS_TRUE(__condition, ...) (bool)WEX::TestExecution::Private::MacroVerify::IsTrue((__condition), (L#__condition), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the specified condition is false.
# define VERIFY_IS_FALSE(__condition, ...) (bool)WEX::TestExecution::Private::MacroVerify::IsFalse((__condition), (L#__condition), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the specified parameter is null.
# define VERIFY_IS_NULL(__object, ...) (bool)WEX::TestExecution::Private::MacroVerify::IsNull((__object), (L#__object), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the specified parameter is not null.
# define VERIFY_IS_NOT_NULL(__object, ...) (bool)WEX::TestExecution::Private::MacroVerify::IsNotNull((__object), (L#__object), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the specified HRESULT is successful.
# define VERIFY_SUCCEEDED(__hresult, ...) (bool)WEX::TestExecution::Private::MacroVerify::Succeeded((__hresult), (L#__hresult), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the specified HRESULT is successful, and returns the HRESULT that was passed in.
# define VERIFY_SUCCEEDED_RETURN(__hresult, ...) (HRESULT)WEX::TestExecution::Private::MacroVerify::SucceededReturn((__hresult), (L#__hresult), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the specified HRESULT is not successful.
# define VERIFY_FAILED(__hresult, ...) (bool)WEX::TestExecution::Private::MacroVerify::Failed((__hresult), (L#__hresult), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the specified HRESULT is not successful, and returns the HRESULT that was passed in.
# define VERIFY_FAILED_RETURN(__hresult, ...) (HRESULT)WEX::TestExecution::Private::MacroVerify::FailedReturn((__hresult), (L#__hresult), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the specified Win32 result succeeded.
# define VERIFY_WIN32_SUCCEEDED(__win32Result, ...) (bool)WEX::TestExecution::Private::MacroVerify::Win32Succeeded((__win32Result), (L#__win32Result), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the specified Win32 result succeeded, and returns the Win32 value that was passed in.
# define VERIFY_WIN32_SUCCEEDED_RETURN(__win32Result, ...) (::LONG)WEX::TestExecution::Private::MacroVerify::Win32SucceededReturn((__win32Result), (L#__win32Result), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the specified Win32 result failed.
# define VERIFY_WIN32_FAILED(__win32Result, ...) (bool)WEX::TestExecution::Private::MacroVerify::Win32Failed((__win32Result), (L#__win32Result), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the specified Win32 result failed, and returns the Win32 value that was passed in.
# define VERIFY_WIN32_FAILED_RETURN(__win32Result, ...) (::LONG)WEX::TestExecution::Private::MacroVerify::Win32FailedReturn((__win32Result), (L#__win32Result), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the specified Win32 BOOL succeeded and logs the error code returned from GetLastError if not.
# define VERIFY_WIN32_BOOL_SUCCEEDED(__win32Bool, ...) (bool)WEX::TestExecution::Private::MacroVerify::Win32BoolSucceeded((__win32Bool), (L#__win32Bool), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the specified Win32 BOOL succeeded and logs the error code returned from GetLastError if not; returns the Win32 BOOL that was passed in.
# define VERIFY_WIN32_BOOL_SUCCEEDED_RETURN(__win32Bool, ...) (::BOOL)WEX::TestExecution::Private::MacroVerify::Win32BoolSucceededReturn((__win32Bool), (L#__win32Bool), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the specified Win32 BOOL failed.
# define VERIFY_WIN32_BOOL_FAILED(__win32Bool, ...) (bool)WEX::TestExecution::Private::MacroVerify::Win32BoolFailed((__win32Bool), (L#__win32Bool), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

// Verifies that the specified Win32 BOOL failed and returns the Win32 BOOL that was passed in.
# define VERIFY_WIN32_BOOL_FAILED_RETURN(__win32Bool, ...) (::BOOL)WEX::TestExecution::Private::MacroVerify::Win32BoolFailedReturn((__win32Bool), (L#__win32Bool), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)

#ifdef NT_SUCCESS
    #define VERIFY_NT_SUCCESS(__ntStatus, ...) (bool)WEX::TestExecution::Private::MacroVerify::NtSuccess((__ntStatus), (L#__ntStatus), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)
    #define VERIFY_NOT_NT_SUCCESS(__ntStatus, ...) (bool)WEX::TestExecution::Private::MacroVerify::NotNtSuccess((__ntStatus), (L#__ntStatus), PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__)
#endif

// Only enable these two if exceptions are enabled for the project
# ifdef _CPPUNWIND

// Verifies that the specified operation throws an exception of the specified type that meets the functor criteria
// The temporary __cond variable is necessary to workaround a bug in nested lambdas used in conditionals
#   define VERIFY_THROWS_SPECIFIC(__operation, __exception, __func, ...)                                                                             \
{                                                                                                                                                    \
    bool __exceptionHit = false;                                                                                                                     \
    try                                                                                                                                              \
    {                                                                                                                                                \
        __operation;                                                                                                                                 \
    }                                                                                                                                                \
    catch(__exception& __e)                                                                                                                          \
    {                                                                                                                                                \
        bool __cond = __func(__e);                                                                                                                   \
        if (__cond)                                                                                                                                  \
        {                                                                                                                                            \
            WEX::TestExecution::Private::MacroVerify::ExpectedExceptionThrown(__e, L#__exception, L#__operation, __VA_ARGS__);                       \
            __exceptionHit = true;                                                                                                                   \
        }                                                                                                                                            \
        else                                                                                                                                         \
        {                                                                                                                                            \
            throw;                                                                                                                                   \
        }                                                                                                                                            \
    }                                                                                                                                                \
                                                                                                                                                     \
    if (!__exceptionHit)                                                                                                                             \
    {                                                                                                                                                \
        WEX::TestExecution::Private::MacroVerify::ExpectedExceptionNotThrown(L#__exception, L#__operation, PRIVATE_VERIFY_ERROR_INFO, __VA_ARGS__);  \
    }                                                                                                                                                \
}

// Verifies that the specified operation throws the specified exception.
#  define VERIFY_THROWS(__operation, __exception, ...)                                                                                               \
    VERIFY_THROWS_SPECIFIC(__operation, __exception, WEX::TestExecution::Private::TrueUnaryFunctor<__exception&>(), __VA_ARGS__)

// Verifies that the specified operation does not throw an exception.
#  define VERIFY_NO_THROW(__operation, ...)                                                                                          \
{                                                                                                                                    \
    bool __exceptionHit = false;                                                                                                     \
    try                                                                                                                              \
    {                                                                                                                                \
        __operation;                                                                                                                 \
    }                                                                                                                                \
    catch(...)                                                                                                                       \
    {                                                                                                                                \
        WEX::Common::NoThrowString __messageBuffer;                                                                                  \
        const wchar_t* __pszMessage = WEX::TestExecution::Private::GetExceptionInfo(__messageBuffer);                                \
        WEX::TestExecution::Private::MacroVerify::UnexpectedExceptionThrownWithSpecifics(L#__operation, PRIVATE_VERIFY_ERROR_INFO, __pszMessage, __VA_ARGS__);  \
        __exceptionHit = true;                                                                                                       \
    }                                                                                                                                \
                                                                                                                                     \
    if (!__exceptionHit)                                                                                                             \
    {                                                                                                                                \
        WEX::TestExecution::Private::MacroVerify::UnexpectedExceptionNotThrown(L#__operation, __VA_ARGS__);                          \
    }                                                                                                                                \
}

# endif //_CPPUNWIND is defined

// Macro for creating an ErrorInfo object with file, function and line information
#define PRIVATE_VERIFY_ERROR_INFO WEX::TestExecution::ErrorInfo(__WFILE__, __WFUNCTION__, __LINE__)

// These definitions allow you to customize formatting for common types
#ifndef LONG_VERIFY_FORMATTING
    #define LONG_VERIFY_FORMATTING L"0x%x"  // Default to formatting for HRESULTS
#endif

#ifndef INT_VERIFY_FORMATTING
    #define INT_VERIFY_FORMATTING L"%d"
#endif

#ifndef CHAR_VERIFY_FORMATTING
    #define CHAR_VERIFY_FORMATTING L"%c"
#endif

#ifndef SHORT_VERIFY_FORMATTING
    #define SHORT_VERIFY_FORMATTING INT_VERIFY_FORMATTING
#endif

#ifndef FLOAT_VERIFY_FORMATTING
    #define FLOAT_VERIFY_FORMATTING L"%fl"
#endif

#ifndef SIZE_T_VERIFY_FORMATTING
    #define SIZE_T_VERIFY_FORMATTING L"%d"
#endif

#ifndef DOUBLE_VERIFY_FORMATTING
    #define DOUBLE_VERIFY_FORMATTING FLOAT_VERIFY_FORMATTING
#endif

#ifndef UNSIGNED_LONG_VERIFY_FORMATTING
    #define UNSIGNED_LONG_VERIFY_FORMATTING L"%u"
#endif

#ifndef UNSIGNED_INT_VERIFY_FORMATTING
    #define UNSIGNED_INT_VERIFY_FORMATTING L"%u"
#endif

#ifndef UNSIGNED_CHAR_VERIFY_FORMATTING
    #define UNSIGNED_CHAR_VERIFY_FORMATTING UNSIGNED_INT_VERIFY_FORMATTING
#endif

#ifndef UNSIGNED_SHORT_VERIFY_FORMATTING
    #define UNSIGNED_SHORT_VERIFY_FORMATTING UNSIGNED_INT_VERIFY_FORMATTING
#endif

#ifndef INT_64_VERIFY_FORMATTING
    #define INT_64_VERIFY_FORMATTING L"%I64d"
#endif

#ifndef UNSIGNED_INT_64_VERIFY_FORMATTING
    #define UNSIGNED_INT_64_VERIFY_FORMATTING L"%I64u"
#endif

#ifndef POINTER_VERIFY_FORMATTING
    #define POINTER_VERIFY_FORMATTING L"0x%p"
#endif

namespace WEX { namespace TestExecution
{
    template <typename T, bool IsEnum>
    class DefaultOutputTraits;

    template <typename T>
    class DefaultOutputTraits<T, true>
    {
    public:
        static WEX::Common::NoThrowString ToString(const T& t)
        {
            // Return value as an unsigned long for enums
            return VerifyOutputTraits<unsigned long>::ToString(static_cast<unsigned long>(t));
        }
    };

    template <typename T>
    class DefaultOutputTraits<T, false>
    {
    public:
        static WEX::Common::NoThrowString ToString(const T&)
        {
            // Just return an empty string by default
            return WEX::Common::NoThrowString();
        }
    };

    // Users can implement custom VerifyOutputTraits for their classes to provide log output
    template <typename T>
    class VerifyOutputTraits
    {
    public:
        // Default implementation
        static WEX::Common::NoThrowString ToString(const T& t)
        {
            return DefaultOutputTraits<T, __is_enum(T)>::ToString(t);
        }
    };

    template <typename T>
    class VerifyOutputTraits<T&>
    {
    public:
        static WEX::Common::NoThrowString ToString(const T& ref)
        {
            // Default implementation call through to non reference type
            return VerifyOutputTraits<T>::ToString(ref);
        }
    };

    template <typename T>
    class VerifyOutputTraits<T*>
    {
    public:
        static WEX::Common::NoThrowString ToString(T* const& p)
        {
            return WEX::Common::NoThrowString().Format(POINTER_VERIFY_FORMATTING, p);
        }
    };

#define BUILD_OUTPUT_TRAIT(Type, FormatString) \
    template<> \
    class VerifyOutputTraits<Type> \
    { \
    public: \
        static WEX::Common::NoThrowString ToString(Type const& val) \
        { \
            return WEX::Common::NoThrowString().Format(FormatString, val); \
        } \
    };

    BUILD_OUTPUT_TRAIT(long, LONG_VERIFY_FORMATTING);
    BUILD_OUTPUT_TRAIT(int, INT_VERIFY_FORMATTING);
    BUILD_OUTPUT_TRAIT(char, CHAR_VERIFY_FORMATTING);
    BUILD_OUTPUT_TRAIT(short, SHORT_VERIFY_FORMATTING);
    BUILD_OUTPUT_TRAIT(float, FLOAT_VERIFY_FORMATTING);
    BUILD_OUTPUT_TRAIT(double, DOUBLE_VERIFY_FORMATTING);
    BUILD_OUTPUT_TRAIT(unsigned long, UNSIGNED_LONG_VERIFY_FORMATTING);
    BUILD_OUTPUT_TRAIT(unsigned int, UNSIGNED_INT_VERIFY_FORMATTING);
    BUILD_OUTPUT_TRAIT(unsigned char, UNSIGNED_CHAR_VERIFY_FORMATTING);
    BUILD_OUTPUT_TRAIT(unsigned short, UNSIGNED_SHORT_VERIFY_FORMATTING);
    BUILD_OUTPUT_TRAIT(__int64, INT_64_VERIFY_FORMATTING);
    BUILD_OUTPUT_TRAIT(unsigned __int64, UNSIGNED_INT_64_VERIFY_FORMATTING);
    BUILD_OUTPUT_TRAIT(bool, UNSIGNED_CHAR_VERIFY_FORMATTING);

    #undef BUILD_OUTPUT_TRAIT

#if defined(TAEF_STL_SUPPORT)
    // Custom class to output the value of std::wstring
    template<>
    class VerifyOutputTraits<std::wstring>
    {
    public:
        static WEX::Common::NoThrowString ToString(std::wstring const& string)
        {
            return WEX::Common::NoThrowString(string.c_str());
        }
    };

    // Custom class to output the value of std::string
    template<>
    class VerifyOutputTraits<std::string>
    {
    public:
        static WEX::Common::NoThrowString ToString(std::string const& string)
        {
            return WEX::Common::NoThrowString(string.c_str());
        }
    };
#endif // #if defined(TAEF_STL_SUPPORT)

    // Custom class to output the value of WEX::Common::String
    template<>
    class VerifyOutputTraits<WEX::Common::String>
    {
    public:
        static WEX::Common::NoThrowString ToString(WEX::Common::String const& string)
        {
            return WEX::Common::NoThrowString(string);
        }
    };

    // Custom class to output the value of WEX::Common::NoThrowString
    template<>
    class VerifyOutputTraits<WEX::Common::NoThrowString>
    {
    public:
        static WEX::Common::NoThrowString ToString(WEX::Common::NoThrowString const& string)
        {
            return string;
        }
    };

    struct ErrorInfo
    {
        ErrorInfo(const wchar_t* pszFileName, const wchar_t* pszFunctionName, int lineNumber)
        : pszFile(pszFileName)
        , pszFunction(pszFunctionName)
        , line(lineNumber)
        {
        }

        ErrorInfo::ErrorInfo(const ErrorInfo& other)
        : pszFile(other.pszFile)
        , pszFunction(other.pszFunction)
        , line(other.line)
        {
        }

        const wchar_t* pszFile;
        const wchar_t* pszFunction;
        int line;
    };

    // Users can implement custom VerifyCompareTraits for their classes to perform more detailed comparisons
    template <typename T1, typename T2 = T1>
    class VerifyCompareTraits
    {
    public:
        static bool AreEqual(const T1& expected, const T2& actual)
        {
            return ((expected == actual) != 0);  // != 0 to handle overloads of operator== that return BOOL instead of bool
        }

        static bool AreSame(const T1& expected, const T2& actual)
        {
            return reinterpret_cast<const void*>(&expected) == reinterpret_cast<const void*>(&actual);
        }

        static bool IsLessThan(const T1& expectedLess, const T2& expectedGreater)
        {
            return (expectedLess < expectedGreater);
        }

        static bool IsGreaterThan(const T1& expectedGreater, const T2& expectedLess)
        {
            return (expectedGreater > expectedLess);
        }

        static bool IsNull(const T1& object)
        {
            // works with various kinds of bool checkable types (smart pointers, etc)
            return object ? false : true;
        }
    };

    template <typename T1, typename T2>
    class VerifyCompareTraits<T1*, T2*>
    {
    public:
        static bool AreEqual(T1* const& expected, T2* const& actual)
        {
            return (reinterpret_cast<const void*>(expected) == reinterpret_cast<const void*>(actual));
        }

        static bool AreSame(T1* const& expected, T2* const& actual)
        {
            return (&reinterpret_cast<const void* const&>(expected) == &reinterpret_cast<const void* const&>(actual));
        }

        static bool IsLessThan(T1* const& expectedLess, T2* const& expectedGreater)
        {
            return (reinterpret_cast<const void*>(expectedLess) < reinterpret_cast<const void*>(expectedGreater));
        }

        static bool IsGreaterThan(T1* const& expectedGreater, T2* const& expectedLess)
        {
            return (reinterpret_cast<const void*>(expectedGreater) > reinterpret_cast<const void*>(expectedLess));
        }

        static bool IsNull(T1* const& object)
        {
            return object == nullptr;
        }
    };

    class ComVerify;
    class Verify;
    namespace Private { class MacroVerify; }

    #ifdef _CPPUNWIND
    #ifndef NO_VERIFY_EXCEPTIONS

    // Thrown when a Verify method fails
    class VerifyFailureException : public WEX::Common::Exception
    {
    friend class Verify; // Only allow Verify to construct these

    private:
        VerifyFailureException(HRESULT errorCode, const wchar_t* pszMessage)
        : WEX::Common::Exception(errorCode, pszMessage)
        {}

        ~VerifyFailureException(){}

        // Making 'operator new' private prevents heap allocation of Exception, and forces Exception instances
        // to be thrown by value.
        static void* operator new(size_t);

        // Making 'operator delete' private for consistency with 'operator new'.
        static void operator delete(void*){};
    };

    namespace Private
    {
        extern "C"
        {
            // One counter per thread across all modules.
            WEXLOGGER_API int __stdcall GetDisabledVerifyThrowCount();
            WEXLOGGER_API void __stdcall IncrementDisabledVerifyThrowCount();
            WEXLOGGER_API void __stdcall DecrementDisabledVerifyThrowCount();
        }
    }

    // Class used to disable VerifyFailureException throwing for its lifetime (on a per-thread basis)
    class DisableVerifyExceptions SEALED
    {
    public:
        DisableVerifyExceptions()
        {
            Private::IncrementDisabledVerifyThrowCount();
        }

        ~DisableVerifyExceptions()
        {
            Private::DecrementDisabledVerifyThrowCount();
        }

        int GetDisabledVerifyThrowCount()
        {
            return Private::GetDisabledVerifyThrowCount();
        }

    private:
        // Making 'operator new' private prevents heap allocation
        static void* operator new(size_t);

        // Making 'operator delete' private for consistency with 'operator new'.
        static void operator delete(void*){};

        DisableVerifyExceptions(const DisableVerifyExceptions&); // non-implemented
        DisableVerifyExceptions& operator=(const DisableVerifyExceptions&); // non-implemented
    };

    #endif // NO_VERIFY_EXCEPTIONS is not defined
    #endif //_CPPUNWIND is defined

    namespace VerifyOutputSettings
    {
        enum Setting
        {
            None = 0,
            LogOnlyFailures = 0x01,
            LogFailuresAsBlocked = 0x02,
            LogFailuresAsWarnings = 0x04,
            LogValuesOnSuccess = 0x08
        };
    }

    inline VerifyOutputSettings::Setting& operator|=(VerifyOutputSettings::Setting& lhs, const VerifyOutputSettings::Setting& rhs)
    {
        lhs = static_cast<VerifyOutputSettings::Setting>((static_cast<int>(lhs) | static_cast<int>(rhs)));
        return lhs;
    }

    inline VerifyOutputSettings::Setting operator|(VerifyOutputSettings::Setting lhs, const VerifyOutputSettings::Setting& rhs)
    {
        return lhs |= rhs;
    }

    inline int operator&(VerifyOutputSettings::Setting lhs, const VerifyOutputSettings::Setting& rhs)
    {
        return (static_cast<int>(lhs) & static_cast<int>(rhs));
    }

    namespace Private
    {
        extern "C"
        {
            // One setting per thread across all modules.
            WEXLOGGER_API VerifyOutputSettings::Setting __stdcall GetVerifyOutputSettings();
            WEXLOGGER_API void __stdcall SetVerifyOutputSettings(VerifyOutputSettings::Setting settings);
        }
    }

    // Class used to toggle verify logging settings (on a per-thread basis)
    class SetVerifyOutput SEALED
    {
    public:
        SetVerifyOutput(VerifyOutputSettings::Setting outputSettings)
            : m_previousSetting(Private::GetVerifyOutputSettings())
        {
            Private::SetVerifyOutputSettings(outputSettings);
        }

        ~SetVerifyOutput()
        {
            Private::SetVerifyOutputSettings(m_previousSetting);
        }

    private:
        VerifyOutputSettings::Setting m_previousSetting;

        // Making 'operator new' private prevents heap allocation , and forces instances
        // to be thrown by value.
        static void* operator new(size_t);

        // Making 'operator delete' private for consistency with 'operator new'.
        static void operator delete(void*){};

        SetVerifyOutput(const SetVerifyOutput&); // non-implemented
        SetVerifyOutput& operator=(const SetVerifyOutput&); // non-implemented
    };

    const wchar_t c_szVerifyContext[] = L"Verify";
    const wchar_t c_szErrorGeneratingPassMessage[] = L"Error generating pass message; possibly out of memory.";
    const wchar_t c_szErrorGeneratingFailureMessage[] = L"Error generating failure message; possibly out of memory.";

    // Class used for test verification purposes
    class Verify SEALED
    {
    friend class WEX::TestExecution::ComVerify;
    friend class WEX::TestExecution::Private::MacroVerify;

    public:

        // Verifies that two specified objects are equal.
        template <typename T1, typename T2>
        static bool AreEqual(const T1& expected, const T2& actual, const ErrorInfo& errorInfo)
        {
            return AreEqual<T1, T2>(expected, actual, nullptr, errorInfo);
        }

        // Verifies that two specified objects are equal.
        template <typename T1, typename T2>
        static bool AreEqual(const T1& expected, const T2& actual, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"AreEqual", pszMessage);
            return AreEqualImpl<T1, T2>(expected, actual, errorInfo, buildMessage);
        }

        // Verifies that two specified objects are not equal.
        template <typename T1, typename T2>
        static bool AreNotEqual(const T1& expected, const T2& actual, const ErrorInfo& errorInfo)
        {
            return AreNotEqual<T1, T2>(expected, actual, nullptr, errorInfo);
        }

        // Verifies that two specified objects are not equal.
        template <typename T1, typename T2>
        static bool AreNotEqual(const T1& expected, const T2& actual, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"AreNotEqual", pszMessage);
            return AreNotEqualImpl<T1, T2>(expected, actual, errorInfo, buildMessage);
        }

        // Verifies that the first parameter is less than the second parameter.
        template <typename T1, typename T2>
        static bool IsLessThan(const T1& expectedLess, const T2& expectedGreater, const ErrorInfo& errorInfo)
        {
            return IsLessThan<T1, T2>(expectedLess, expectedGreater, nullptr, errorInfo);
        }

        // Verifies that the first parameter is less than the second parameter.
        template <typename T1, typename T2>
        static bool IsLessThan(const T1& expectedLess, const T2& expectedGreater, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"IsLessThan", pszMessage);
            return IsLessThanImpl<T1, T2>(expectedLess, expectedGreater, errorInfo, buildMessage);
        }

        // Verifies that the first parameter is less than or equal to the second parameter.
        template <typename T1, typename T2>
        static bool IsLessThanOrEqual(const T1& expectedLess, const T2& expectedGreater, const ErrorInfo& errorInfo)
        {
            return IsLessThanOrEqual<T1, T2>(expectedLess, expectedGreater, nullptr, errorInfo);
        }

        // Verifies that the first parameter is less than or equal to the second parameter.
        template <typename T1, typename T2>
        static bool IsLessThanOrEqual(const T1& expectedLess, const T2& expectedGreater, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"IsLessThanOrEqual", pszMessage);
            return IsLessThanOrEqualImpl<T1, T2>(expectedLess, expectedGreater, errorInfo, buildMessage);
        }

        // Verifies that the first parameter is greater than the second parameter.
        template <typename T1, typename T2>
        static bool IsGreaterThan(const T1& expectedGreater, const T2& expectedLess, const ErrorInfo& errorInfo)
        {
            return IsGreaterThan<T1, T2>(expectedGreater, expectedLess, nullptr, errorInfo);
        }

        // Verifies that the first parameter is greater than the second parameter.
        template <typename T1, typename T2>
        static bool IsGreaterThan(const T1& expectedGreater, const T2& expectedLess, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"IsGreaterThan", pszMessage);
            return IsGreaterThanImpl<T1, T2>(expectedGreater, expectedLess, errorInfo, buildMessage);
        }

        // Verifies that the first parameter is greater than or equal to the second parameter.
        template <typename T1, typename T2>
        static bool IsGreaterThanOrEqual(const T1& expectedGreater, const T2& expectedLess, const ErrorInfo& errorInfo)
        {
            return IsGreaterThanOrEqual<T1, T2>(expectedGreater, expectedLess, nullptr, errorInfo);
        }

        // Verifies that the first parameter is greater than or equal to the second parameter.
        template <typename T1, typename T2>
        static bool IsGreaterThanOrEqual(const T1& expectedGreater, const T2& expectedLess, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"IsGreaterThanOrEqual", pszMessage);
            return IsGreaterThanOrEqualImpl<T1, T2>(expectedGreater, expectedLess, errorInfo, buildMessage);
        }

    private:
        // Returns the address of T
        template <typename T>
        class GetAddressOf
        {
        public:
            static const T* Value(const T& ref)
            {
                return &ref;
            }
            typedef const T* Type;
        };

        // Returns the address of T
        template <typename T>
        class GetAddressOf<T&>
        {
        public:
            static const T* Value(const T& ref)
            {
                return &ref;
            }
            typedef const T* Type;
        };

        // Returns the address T* (a pointer-to-pointer) as void*
        template <typename T>
        class GetAddressOf<T*>
        {
        public:
            static const void* Value(T* const& p)
            {
                return &p;
            }
            typedef const void* Type;
        };

    public:
        // Verifies that the two parameters specified refer to the same object.
        template <typename T1, typename T2>
        static bool AreSame(const T1& expected, const T2& actual, const ErrorInfo& errorInfo)
        {
            return AreSame<T1, T2>(expected, actual, nullptr, errorInfo);
        }

        // Verifies that the two parameters specified refer to the same object.
        template <typename T1, typename T2>
        static bool AreSame(const T1& expected, const T2& actual, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"AreSame", pszMessage);
            return AreSameImpl<T1, T2>(expected, actual, errorInfo, buildMessage);
        }

        // Verifies that the two parameters specified do not refer to the same object.
        template <typename T1, typename T2>
        static bool AreNotSame(const T1& expected, const T2& actual, const ErrorInfo& errorInfo)
        {
            return AreNotSame<T1, T2>(expected, actual, nullptr, errorInfo);
        }

        // Verifies that the two parameters specified do not refer to the same object.
        template <typename T1, typename T2>
        static bool AreNotSame(const T1& expected, const T2& actual, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"AreNotSame", pszMessage);
            return AreNotSameImpl<T1, T2>(expected, actual, errorInfo, buildMessage);
        }

        // Fails without checking any conditions.
        _Post_equal_to_(false)
        static bool Fail(const ErrorInfo& errorInfo)
        {
            return Fail(nullptr, errorInfo);
        }

        // Fails without checking any conditions.
        _Post_equal_to_(false)
        static bool Fail(const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            if (WEX::Common::NoThrowString::IsNullOrEmpty(pszMessage))
            {
                return VerificationFailed(L"Fail", errorInfo);
            }

            return VerificationFailed(pszMessage, errorInfo);
        }

        // Verifies that the specified condition is true.
        _Post_equal_to_(condition)
        static bool IsTrue(bool condition, const ErrorInfo& errorInfo)
        {
            return IsTrue(condition, nullptr, errorInfo);
        }

        // Verifies that the specified condition is true.
        _Post_equal_to_(condition)
        static bool IsTrue(bool condition, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"IsTrue", pszMessage);
            return IsTrueImpl(condition, errorInfo, buildMessage);
        }

        // Verifies that the specified condition is false.
        _Post_equal_to_(!condition)
        static bool IsFalse(bool condition, const ErrorInfo& errorInfo)
        {
            return IsFalse(condition, nullptr, errorInfo);
        }

        // Verifies that the specified condition is false.
        _Post_equal_to_(!condition)
        static bool IsFalse(bool condition, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"IsFalse", pszMessage);
            return IsFalseImpl(condition, errorInfo, buildMessage);
        }

        // Verifies that the specified parameter is null.
        template <typename T>
        static bool IsNull(const T& object, const ErrorInfo& errorInfo)
        {
            return IsNull(object, nullptr, errorInfo);
        }

        // Verifies that the specified parameter is null.
        template <typename T>
        static bool IsNull(const T& object, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"IsNull", pszMessage);
            return IsNullImpl(object, errorInfo, buildMessage);
        }

        // Verifies that the specified parameter is not null.
        template <typename T>
        static bool IsNotNull(const T& object, const ErrorInfo& errorInfo)
        {
            return IsNotNull(object, nullptr, errorInfo);
        }

        // Verifies that the specified parameter is not null.
        template <typename T>
        static bool IsNotNull(const T& object, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"IsNotNull", pszMessage);
            return IsNotNullImpl(object, errorInfo, buildMessage);
        }

        // Verifies that the specified HRESULT is successful.
        _Post_equal_to_(SUCCEEDED(hr))
        static bool Succeeded(HRESULT hr, const ErrorInfo& errorInfo)
        {
            return Succeeded(hr, nullptr, errorInfo);
        }

        // Verifies that the specified HRESULT is successful.
        _Post_equal_to_(SUCCEEDED(hr))
        static bool Succeeded(HRESULT hr, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"Succeeded", pszMessage);
            return SucceededImpl(hr, errorInfo, buildMessage);
        }

        // Verifies that the specified HRESULT is not successful.
        _Post_equal_to_(FAILED(hr))
        static bool Failed(HRESULT hr, const ErrorInfo& errorInfo)
        {
            return Failed(hr, nullptr, errorInfo);
        }

        // Verifies that the specified HRESULT is not successful.
        _Post_equal_to_(FAILED(hr))
        static bool Failed(HRESULT hr, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"Failed", pszMessage);
            return FailedImpl(hr, errorInfo, buildMessage);
        }

        // Verifies that the specified Win32 error code is successful.
        _Post_equal_to_(win32ErrorCode == 0)
        static bool Win32Succeeded(::LONG win32ErrorCode, const ErrorInfo& errorInfo)
        {
            return Win32Succeeded(win32ErrorCode, nullptr, errorInfo);
        }

        // Verifies that the specified Win32 error code is successful.
        _Post_equal_to_(win32ErrorCode == 0)
        static bool Win32Succeeded(::LONG win32ErrorCode, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"Win32Succeeded", pszMessage);
            return Win32SucceededImpl(win32ErrorCode, errorInfo, buildMessage);
        }

        // Verifies that the specified Win32 error code is not successful.
        _Post_equal_to_(win32ErrorCode != 0)
        static bool Win32Failed(::LONG win32ErrorCode, const ErrorInfo& errorInfo)
        {
            return Win32Failed(win32ErrorCode, nullptr, errorInfo);
        }

        // Verifies that the specified Win32 error code is not successful.
        _Post_equal_to_(win32ErrorCode != 0)
        static bool Win32Failed(::LONG win32ErrorCode, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"Win32Failed", pszMessage);
            return Win32FailedImpl(win32ErrorCode, errorInfo, buildMessage);
        }

        // Verifies that the specified Win32 BOOL succeeded, and logs the error code returned from GetLastError if not.
        _Post_equal_to_(win32Bool != 0)
        static bool Win32BoolSucceeded(::BOOL win32Bool, const ErrorInfo& errorInfo)
        {
            return Win32BoolSucceeded(win32Bool, nullptr, errorInfo);
        }

        // Verifies that the specified Win32 BOOL succeeded, and logs the error code returned from GetLastError if not.
        _Post_equal_to_(win32Bool != 0)
        static bool Win32BoolSucceeded(::BOOL win32Bool, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"Win32BoolSucceeded", pszMessage);
            return Win32BoolSucceededImpl(win32Bool, errorInfo, buildMessage);
        }

        // Verifies that the specified Win32 error code is not successful.
        _Post_equal_to_(win32Bool == 0)
        static bool Win32BoolFailed(::BOOL win32Bool, const ErrorInfo& errorInfo)
        {
            return Win32BoolFailed(win32Bool, nullptr, errorInfo);
        }

        // Verifies that the specified Win32 error code is not successful.
        _Post_equal_to_(win32Bool == 0)
        static bool Win32BoolFailed(::BOOL win32Bool, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"Win32BoolFailed", pszMessage);
            return Win32BoolFailedImpl(win32Bool, errorInfo, buildMessage);
        }

#ifdef NT_SUCCESS
        // Verifies that the specified NTSTATUS error code is successful.
        _Post_equal_to_(NT_SUCCESS(ntStatus))
        static bool NtSuccess(NTSTATUS ntStatus, const ErrorInfo& errorInfo)
        {
            return NtSuccess(ntStatus, nullptr, errorInfo);
        }

        // Verifies that the specified NTSTATUS error code is successful.
        _Post_equal_to_(NT_SUCCESS(ntStatus))
        static bool NtSuccess(NTSTATUS ntStatus, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"NtSuccess", pszMessage);
            return NtSuccessImpl(ntStatus, errorInfo, buildMessage);
        }

        // Verifies that the specified NTSTATUS error code is not successful.
        _Post_equal_to_(!NT_SUCCESS(ntStatus))
        static bool NotNtSuccess(NTSTATUS ntStatus, const ErrorInfo& errorInfo)
        {
            return NotNtSuccess(ntStatus, nullptr, errorInfo);
        }

        // Verifies that the specified NTSTATUS error code is not successful.
        _Post_equal_to_(!NT_SUCCESS(ntStatus))
        static bool NotNtSuccess(NTSTATUS ntStatus, const wchar_t* pszMessage, const ErrorInfo& errorInfo)
        {
            VerifyMessageFunctor buildMessage(L"NotNtSuccess", pszMessage);
            return NotNtSuccessImpl(ntStatus, errorInfo, buildMessage);
        }
#endif

    private:
        template<typename T>
        static bool AppendValueToMessage(WEX::Common::NoThrowString& message, const T& value)
        {
            WEX::Common::NoThrowString valueString(VerifyOutputTraits<T>::ToString(value));
            if (!valueString.IsEmpty())
            {
                message.Append(valueString);
                return true;
            }
            return false;
        }

        static bool AppendValueToMessage(WEX::Common::NoThrowString& message, const wchar_t* pszValue)
        {
            message.Append(pszValue);
            return true;
        }

        static bool AppendValueToMessage(WEX::Common::NoThrowString& message, const char* paszValue)
        {
            message.Append(WEX::Common::NoThrowString(paszValue));
            return true;
        }

        static bool AppendValueToMessage(WEX::Common::NoThrowString& message, const WEX::Common::String& value)
        {
            message.Append(static_cast<const wchar_t*>(value));
            return true;
        }

        static bool AppendValueToMessage(WEX::Common::NoThrowString& message, const WEX::Common::NoThrowString& value)
        {
            message.Append(value);
            return true;
        }

#if defined(TAEF_STL_SUPPORT)
        static bool AppendValueToMessage(WEX::Common::NoThrowString& message, const std::wstring& value)
        {
            message.Append(value.c_str());
            return true;
        }

        static bool AppendValueToMessage(WEX::Common::NoThrowString& message, const std::string& value)
        {
            message.Append(WEX::Common::NoThrowString(value.c_str()));
            return true;
        }
#endif // #if defined(TAEF_STL_SUPPORT)

        template<typename T1, typename T2>
        static void AddValuesListToMessage(WEX::Common::NoThrowString& message, const T1& expected, const T2& actual)
        {
            const int lengthWithoutValues = message.GetLength();

            message.Append(L" - Values (");
            if (!AppendValueToMessage(message, expected))
            {
                // Roll back the append of " - Values (".
                message.GetBufferSetLength(lengthWithoutValues);
                message.ReleaseBuffer(lengthWithoutValues);
                return;
            }
            message.Append(L", ");
            AppendValueToMessage(message, actual);
            message.Append(L")");
        }

        template<typename T>
        static void AddValuesListToMessage(WEX::Common::NoThrowString& message, const T& expected)
        {
            const int lengthWithoutValue = message.GetLength();

            message.Append(L" - Value (");
            if (!AppendValueToMessage(message, expected))
            {
                // Roll back the append of " - Value (".
                message.GetBufferSetLength(lengthWithoutValue);
                message.ReleaseBuffer(lengthWithoutValue);
                return;
            }
            message.Append(L")");
        }

        template <typename T1, typename T2>
        static bool VerificationFailed(const T1& expected, const T2& actual, WEX::Common::NoThrowString&& message, const ErrorInfo& errorInfo)
        {
            WEX::Common::PreserveLastError preserveLastError;
            AddValuesListToMessage(message, expected, actual);
            return FailImpl(message, errorInfo, E_FAIL /*Work around the compiler issue on the woa build*/);
        }

        template <typename T>
        static bool VerificationFailed(const T& expected, WEX::Common::NoThrowString&& message, const ErrorInfo& errorInfo)
        {
            WEX::Common::PreserveLastError preserveLastError;
            AddValuesListToMessage(message, expected);
            return FailImpl(message, errorInfo, E_FAIL /*Work around the compiler issue on the woa build*/);
        }

        _Post_equal_to_(false)
        static bool VerificationFailed(WEX::Common::NoThrowString&& message, const ErrorInfo& errorInfo)
        {
            WEX::Common::PreserveLastError preserveLastError;
            return FailImpl(message, errorInfo);
        }

        _Post_equal_to_(false)
        static bool FailImpl(const WEX::Common::NoThrowString& message, const ErrorInfo& errorInfo, HRESULT hrToThrow = E_FAIL)
        {
            if (!message.IsEmpty())
            {
                VerifyOutputSettings::Setting outputSetting = Private::GetVerifyOutputSettings();

                if (outputSetting & VerifyOutputSettings::LogFailuresAsBlocked)
                {
                    WEX::Logging::Log::Result(WEX::Logging::TestResults::Blocked, message.ToCStrWithFallbackTo(c_szErrorGeneratingFailureMessage), c_szVerifyContext);
                }
                else if (outputSetting & VerifyOutputSettings::LogFailuresAsWarnings)
                {
                    WEX::Logging::Log::Warning(message.ToCStrWithFallbackTo(c_szErrorGeneratingFailureMessage), c_szVerifyContext, errorInfo.pszFile, errorInfo.pszFunction, errorInfo.line);
                }
                else
                {
                    WEX::Logging::Log::Error(message.ToCStrWithFallbackTo(c_szErrorGeneratingFailureMessage), c_szVerifyContext, errorInfo.pszFile, errorInfo.pszFunction, errorInfo.line);
                }
            }

            UNREFERENCED_PARAMETER(hrToThrow); // Unreferenced if exceptions are disabled

            #ifdef _CPPUNWIND
            #ifndef NO_VERIFY_EXCEPTIONS

            if (Private::GetDisabledVerifyThrowCount() == 0)
            {
                throw VerifyFailureException(hrToThrow, message);
            }

            #endif // NO_VERIFY_EXCEPTIONS is not defined
            #endif //_CPPUNWIND is defined

            return false;
        }

        static bool LogValuesOnSuccess()
        {
            #ifdef LOG_VALUES_ON_SUCCESS
                return true;
            #else
                // If LOG_VALUES_ON_SUCCESS wasn't globally defined, look at the current VerifyOutputSettings
                return ((Private::GetVerifyOutputSettings() & VerifyOutputSettings::LogValuesOnSuccess) != 0);
            #endif
        }

        static bool LogOnlyFailures()
        {
            #ifdef LOG_ONLY_FAILURES
                return true;
            #else
                // If LOG_ONLY_FAILURES wasn't globally defined, look at the current VerifyOutputSettings
                return ((Private::GetVerifyOutputSettings() & VerifyOutputSettings::LogOnlyFailures) != 0);
            #endif
        }

        template <typename T1, typename T2>
        _Post_equal_to_(true)
        static bool VerificationPassed(const T1& expected, const T2& actual, WEX::Common::NoThrowString&& message)
        {
            if (LogOnlyFailures())
            {
                return true;
            }

            WEX::Common::PreserveLastError preserveLastError;
            if (LogValuesOnSuccess())
            {
                AddValuesListToMessage(message, expected, actual);
            }

            return PassImpl(message);
        }

        template <typename T>
        _Post_equal_to_(true)
        static bool VerificationPassed(const T& expected, WEX::Common::NoThrowString&& message)
        {
            if (LogOnlyFailures())
            {
                return true;
            }

            WEX::Common::PreserveLastError preserveLastError;
            if (LogValuesOnSuccess())
            {
                AddValuesListToMessage(message, expected);
            }

            return PassImpl(message);
        }

        _Post_equal_to_(true)
        static bool VerificationPassed(WEX::Common::NoThrowString&& message)
        {
            if (LogOnlyFailures())
            {
                return true;
            }

            WEX::Common::PreserveLastError preserveLastError;
            return PassImpl(message);
        }

        _Post_equal_to_(true)
        static bool PassImpl(const WEX::Common::NoThrowString& message)
        {
            if (!message.IsEmpty())
            {
                WEX::Logging::Log::Comment(message.ToCStrWithFallbackTo(c_szErrorGeneratingPassMessage), c_szVerifyContext);
            }

            return true;
        }

        class VerifyMessageFunctor
        {
        public:
            VerifyMessageFunctor(const wchar_t* pszDefaultMessage, const wchar_t* pszMessage)
            : m_pszDefaultMessage(pszDefaultMessage)
            , m_pszMessage(pszMessage)
            {
            }

            WEX::Common::NoThrowString operator()() const
            {
                if (WEX::Common::NoThrowString::IsNullOrEmpty(m_pszMessage))
                {
                    return WEX::Common::NoThrowString(m_pszDefaultMessage);
                }

                return WEX::Common::NoThrowString().Format(L"%s: %s", m_pszDefaultMessage, m_pszMessage);
            }

        private:
            const wchar_t* m_pszDefaultMessage;
            const wchar_t* m_pszMessage;
        };

        template <typename T1, typename T2, typename TBuildMessage>
        static bool AreEqualImpl(const T1& expected, const T2& actual, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (!VerifyCompareTraits<T1, T2>::AreEqual(expected, actual))
            {
                return VerificationFailed(expected, actual, buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed(expected, actual, buildMessage());
            }

            return true;
        }

        template <typename T1, typename T2, typename TBuildMessage>
        static bool AreNotEqualImpl(const T1& expected, const T2& actual, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (VerifyCompareTraits<T1, T2>::AreEqual(expected, actual))
            {
                return VerificationFailed(expected, actual, buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed(expected, actual, buildMessage());
            }

            return true;
        }

        template <typename T1, typename T2, typename TBuildMessage>
        static bool IsLessThanImpl(const T1& expectedLess, const T2& expectedGreater, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (!VerifyCompareTraits<T1, T2>::IsLessThan(expectedLess, expectedGreater))
            {
                return VerificationFailed(expectedLess, expectedGreater, buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed(expectedLess, expectedGreater, buildMessage());
            }

            return true;
        }

        template <typename T1, typename T2, typename TBuildMessage>
        static bool IsLessThanOrEqualImpl(const T1& expectedLess, const T2& expectedGreater, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (!VerifyCompareTraits<T1, T2>::IsLessThan(expectedLess, expectedGreater) &&
                !VerifyCompareTraits<T1, T2>::AreEqual(expectedLess, expectedGreater))
            {
                return VerificationFailed(expectedLess, expectedGreater, buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed(expectedLess, expectedGreater, buildMessage());
            }

            return true;
        }

        template <typename T1, typename T2, typename TBuildMessage>
        static bool IsGreaterThanImpl(const T1& expectedGreater, const T2& expectedLess, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (!VerifyCompareTraits<T1, T2>::IsGreaterThan(expectedGreater, expectedLess))
            {
                return VerificationFailed(expectedGreater, expectedLess, buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed(expectedGreater, expectedLess, buildMessage());
            }

            return true;
        }


        template <typename T1, typename T2, typename TBuildMessage>
        static bool IsGreaterThanOrEqualImpl(const T1& expectedGreater, const T2& expectedLess, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (!VerifyCompareTraits<T1, T2>::IsGreaterThan(expectedGreater, expectedLess) &&
                !VerifyCompareTraits<T1, T2>::AreEqual(expectedGreater, expectedLess))
            {
                return VerificationFailed(expectedGreater, expectedLess, buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed(expectedGreater, expectedLess, buildMessage());
            }

            return true;
        }

        template <typename T1, typename T2, typename TBuildMessage>
        static bool AreSameImpl(const T1& expected, const T2& actual, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (!VerifyCompareTraits<T1, T2>::AreSame(expected, actual))
            {
                return VerificationFailed<GetAddressOf<T1>::Type, GetAddressOf<T2>::Type>(GetAddressOf<T1>::Value(expected), GetAddressOf<T2>::Value(actual), buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed<GetAddressOf<T1>::Type, GetAddressOf<T2>::Type>(GetAddressOf<T1>::Value(expected), GetAddressOf<T2>::Value(actual), buildMessage());
            }

            return true;
        }

        template <typename T1, typename T2, typename TBuildMessage>
        static bool AreNotSameImpl(const T1& expected, const T2& actual, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (VerifyCompareTraits<T1, T2>::AreSame(expected, actual))
            {
                return VerificationFailed<GetAddressOf<T1>::Type, GetAddressOf<T2>::Type>(GetAddressOf<T1>::Value(expected), GetAddressOf<T2>::Value(actual), buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed<GetAddressOf<T1>::Type, GetAddressOf<T2>::Type>(GetAddressOf<T1>::Value(expected), GetAddressOf<T2>::Value(actual), buildMessage());
            }

            return true;
        }

        template <typename TBuildMessage>
        static bool IsTrueImpl(bool condition, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (!condition)
            {
                return VerificationFailed(buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed(buildMessage());
            }

            return true;
        }

        template <typename TBuildMessage>
        static bool IsFalseImpl(bool condition, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (condition)
            {
                return VerificationFailed(buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed(buildMessage());
            }

            return true;
        }

        template <typename T, typename TBuildMessage>
        static bool IsNullImpl(const T& object, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (VerifyCompareTraits<T, T>::IsNull(object))
            {
                if (!LogOnlyFailures())
                {
                    return VerificationPassed(object, buildMessage());
                }

                return true;
            }

            return VerificationFailed(object, buildMessage(), errorInfo);
        }

        // Verifies that the specified parameter is not null.
        template <typename T, typename TBuildMessage>
        static bool IsNotNullImpl(const T& object, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (!VerifyCompareTraits<T, T>::IsNull(object))
            {
                if (!LogOnlyFailures())
                {
                    return VerificationPassed(object, buildMessage());
                }

                return true;
            }

            return VerificationFailed(object, buildMessage(), errorInfo);
        }

        template <typename TBuildMessage>
        _Post_equal_to_(SUCCEEDED(hr))
        static bool SucceededImpl(HRESULT hr, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (FAILED(hr))
            {
                return VerificationFailed<HRESULT>(hr, buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed<HRESULT>(hr, buildMessage());
            }

            return true;
        }

        template <typename TBuildMessage>
        _Post_equal_to_(FAILED(hr))
        static bool FailedImpl(HRESULT hr, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (!FAILED(hr))
            {
                return VerificationFailed<HRESULT>(hr, buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed<HRESULT>(hr, buildMessage());
            }

            return true;
        }

        template <typename TBuildMessage>
        _Post_equal_to_(win32ErrorCode == 0)
        static bool Win32SucceededImpl(::LONG win32ErrorCode, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (win32ErrorCode != ERROR_SUCCESS)
            {
                return VerificationFailed< ::LONG>(win32ErrorCode, buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed< ::LONG>(win32ErrorCode, buildMessage());
            }

            return true;
        }

        template <typename TBuildMessage>
        _Post_equal_to_(win32ErrorCode != 0)
        static bool Win32FailedImpl(::LONG win32ErrorCode, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (win32ErrorCode == ERROR_SUCCESS)
            {
                return VerificationFailed< ::LONG>(win32ErrorCode, buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed< ::LONG>(win32ErrorCode, buildMessage());
            }

            return true;
        }

        template <typename TBuildMessage>
        _Post_equal_to_(win32Bool != 0)
        static bool Win32BoolSucceededImpl(::BOOL win32Bool, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (0 == win32Bool)
            {
                // Log the value returned from Debug::GetLastError()
                return VerificationFailed< ::DWORD>(WEX::Common::Debug::GetLastError(), buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed< ::BOOL>(win32Bool, buildMessage());
            }

            return true;
        }

        template <typename TBuildMessage>
        _Post_equal_to_(win32Bool == 0)
        static bool Win32BoolFailedImpl(::BOOL win32Bool, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (0 != win32Bool)
            {
                return VerificationFailed< ::BOOL>(win32Bool, buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed< ::BOOL>(win32Bool, buildMessage());
            }

            return true;
        }

#ifdef NT_SUCCESS
        template <typename TBuildMessage>
        _Post_equal_to_(NT_SUCCESS(ntStatus))
        static bool NtSuccessImpl(NTSTATUS ntStatus, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (!NT_SUCCESS(ntStatus))
            {
                return VerificationFailed<NTSTATUS>(ntStatus, buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed<NTSTATUS>(ntStatus, buildMessage());
            }

            return true;
        }

        template <typename TBuildMessage>
        _Post_equal_to_(!NT_SUCCESS(ntStatus))
        static bool NotNtSuccessImpl(NTSTATUS ntStatus, const ErrorInfo& errorInfo, const TBuildMessage& buildMessage)
        {
            if (NT_SUCCESS(ntStatus))
            {
                return VerificationFailed<NTSTATUS>(ntStatus, buildMessage(), errorInfo);
            }

            if (!LogOnlyFailures())
            {
                return VerificationPassed<NTSTATUS>(ntStatus, buildMessage());
            }

            return true;
        }
#endif

        Verify(){}; // Disallow construction of static class
        ~Verify(){}; // Disallow construction of static class
        Verify(const Verify&); // non-implemented
        Verify& operator=(const Verify&); // non-implemented
    };

    namespace Private
    {
        class MacroVerify SEALED
        {
        public:

            template <typename T1, typename T2>
            static bool AreEqual(const T1& expected, const T2& actual, const wchar_t* pszExpected, const wchar_t* pszActual, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"AreEqual(%s, %s)", pszExpected, pszActual, pszMessage);
                return WEX::TestExecution::Verify::AreEqualImpl<T1, T2>(expected, actual, errorInfo, buildMessage);
            }

            template <typename T1, typename T2>
            static bool AreNotEqual(const T1& expected, const T2& actual, const wchar_t* pszExpected, const wchar_t* pszActual, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"AreNotEqual(%s, %s)", pszExpected, pszActual, pszMessage);
                return WEX::TestExecution::Verify::AreNotEqualImpl(expected, actual, errorInfo, buildMessage);
            }

            template <typename T1, typename T2>
            static bool IsLessThan(const T1& expected, const T2& actual, const wchar_t* pszExpected, const wchar_t* pszActual, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"IsLessThan(%s, %s)", pszExpected, pszActual, pszMessage);
                return WEX::TestExecution::Verify::IsLessThanImpl(expected, actual, errorInfo, buildMessage);
            }

            template <typename T1, typename T2>
            static bool IsLessThanOrEqual(const T1& expected, const T2& actual, const wchar_t* pszExpected, const wchar_t* pszActual, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"IsLessThanOrEqual(%s, %s)", pszExpected, pszActual, pszMessage);
                return WEX::TestExecution::Verify::IsLessThanOrEqualImpl(expected, actual, errorInfo, buildMessage);
            }

            template <typename T1, typename T2>
            static bool IsGreaterThan(const T1& expected, const T2& actual, const wchar_t* pszExpected, const wchar_t* pszActual, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"IsGreaterThan(%s, %s)", pszExpected, pszActual, pszMessage);
                return WEX::TestExecution::Verify::IsGreaterThanImpl(expected, actual, errorInfo, buildMessage);
            }

            template <typename T1, typename T2>
            static bool IsGreaterThanOrEqual(const T1& expected, const T2& actual, const wchar_t* pszExpected, const wchar_t* pszActual, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"IsGreaterThanOrEqual(%s, %s)", pszExpected, pszActual, pszMessage);
                return WEX::TestExecution::Verify::IsGreaterThanOrEqualImpl(expected, actual, errorInfo, buildMessage);
            }

            template <typename T1, typename T2>
            static bool AreSame(const T1& expected, const T2& actual, const wchar_t* pszExpected, const wchar_t* pszActual, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"AreSame(%s, %s)", pszExpected, pszActual, pszMessage);
                return WEX::TestExecution::Verify::AreSameImpl(expected, actual, errorInfo, buildMessage);
            }

            template <typename T1, typename T2>
            static bool AreNotSame(const T1& expected, const T2& actual, const wchar_t* pszExpected, const wchar_t* pszActual, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"AreNotSame(%s, %s)", pszExpected, pszActual, pszMessage);
                return WEX::TestExecution::Verify::AreNotSameImpl(expected, actual, errorInfo, buildMessage);
            }

            _Post_equal_to_(false)
            static bool Fail(const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                return WEX::TestExecution::Verify::Fail(pszMessage, errorInfo);
            }

            _Post_equal_to_(condition)
            static bool IsTrue(bool condition, const wchar_t* pszCondition, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"IsTrue(%s)", pszCondition, pszMessage);
                return WEX::TestExecution::Verify::IsTrueImpl(condition, errorInfo, buildMessage);
            }

            _Post_equal_to_(!condition)
            static bool IsFalse(bool condition, const wchar_t* pszCondition, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"IsFalse(%s)", pszCondition, pszMessage);
                return WEX::TestExecution::Verify::IsFalseImpl(condition, errorInfo, buildMessage);
            }

            template <typename T>
            static bool IsNull(const T& object, const wchar_t* pszObject, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"IsNull(%s)", pszObject, pszMessage);
                return WEX::TestExecution::Verify::IsNullImpl(object, errorInfo, buildMessage);
            }

            template <typename T>
            static bool IsNotNull(const T& object, const wchar_t* pszObject, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"IsNotNull(%s)", pszObject, pszMessage);
                return WEX::TestExecution::Verify::IsNotNullImpl(object, errorInfo, buildMessage);
            }

            _Post_equal_to_(SUCCEEDED(hr))
            static bool Succeeded(HRESULT hr, const wchar_t* pszHresult, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"SUCCEEDED(%s)", pszHresult, pszMessage);
                return WEX::TestExecution::Verify::SucceededImpl(hr, errorInfo, buildMessage);
            }

            _Post_equal_to_(hr)
            static HRESULT SucceededReturn(HRESULT hr, const wchar_t* pszHresult, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                Succeeded(hr, pszHresult, errorInfo, pszMessage);
                return hr;
            }

            _Post_equal_to_(FAILED(hr))
            static bool Failed(HRESULT hr, const wchar_t* pszHresult, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"FAILED(%s)", pszHresult, pszMessage);
                return WEX::TestExecution::Verify::FailedImpl(hr, errorInfo, buildMessage);
            }

            _Post_equal_to_(hr)
            static HRESULT FailedReturn(HRESULT hr, const wchar_t* pszHresult, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                Failed(hr, pszHresult, errorInfo, pszMessage);
                return hr;
            }

            _Post_equal_to_(win32ErrorCode == 0)
            static bool Win32Succeeded(::LONG win32ErrorCode, const wchar_t* pszWin32ErrorCode, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"Win32Succeeded(%s)", pszWin32ErrorCode, pszMessage);
                return WEX::TestExecution::Verify::Win32SucceededImpl(win32ErrorCode, errorInfo, buildMessage);
            }

            _Post_equal_to_(win32ErrorCode)
            static ::LONG Win32SucceededReturn(::LONG win32ErrorCode, const wchar_t* pszWin32ErrorCode, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                Win32Succeeded(win32ErrorCode, pszWin32ErrorCode, errorInfo, pszMessage);
                return win32ErrorCode;
            }

            _Post_equal_to_(win32ErrorCode != 0)
            static bool Win32Failed(::LONG win32ErrorCode, const wchar_t* pszWin32ErrorCode, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"Win32Failed(%s)", pszWin32ErrorCode, pszMessage);
                return WEX::TestExecution::Verify::Win32FailedImpl(win32ErrorCode, errorInfo, buildMessage);
            }

            _Post_equal_to_(win32ErrorCode)
            static ::LONG Win32FailedReturn(::LONG win32ErrorCode, const wchar_t* pszWin32ErrorCode, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                Win32Failed(win32ErrorCode, pszWin32ErrorCode, errorInfo, pszMessage);
                return win32ErrorCode;
            }

            _Post_equal_to_(win32Bool != 0)
            static bool Win32BoolSucceeded(::BOOL win32Bool, const wchar_t* pszWin32Bool, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"Win32BoolSucceeded(%s)", pszWin32Bool, pszMessage);
                return WEX::TestExecution::Verify::Win32BoolSucceededImpl(win32Bool, errorInfo, buildMessage);
            }

            _Post_equal_to_(win32Bool)
            static ::BOOL Win32BoolSucceededReturn(::BOOL win32Bool, const wchar_t* pszWin32Bool, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                Win32BoolSucceeded(win32Bool, pszWin32Bool, errorInfo, pszMessage);
                return win32Bool;
            }

            _Post_equal_to_(win32Bool == 0)
            static bool Win32BoolFailed(::BOOL win32Bool, const wchar_t* pszWin32Bool, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"Win32BoolFailed(%s)", pszWin32Bool, pszMessage);
                return WEX::TestExecution::Verify::Win32BoolFailedImpl(win32Bool, errorInfo, buildMessage);
            }

            _Post_equal_to_(win32Bool)
            static ::BOOL Win32BoolFailedReturn(::BOOL win32Bool, const wchar_t* pszWin32Bool, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                Win32BoolFailed(win32Bool, pszWin32Bool, errorInfo, pszMessage);
                return win32Bool;
            }

#ifdef NT_SUCCESS
            _Post_equal_to_(NT_SUCCESS(ntStatus))
            static bool NtSuccess(NTSTATUS ntStatus, const wchar_t* pszNtStatus, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"NtSuccess(%s)", pszNtStatus, pszMessage);
                return WEX::TestExecution::Verify::NtSuccessImpl(ntStatus, errorInfo, buildMessage);
            }

            _Post_equal_to_(!NT_SUCCESS(ntStatus))
            static bool NotNtSuccess(NTSTATUS ntStatus, const wchar_t* pszNtStatus, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                MacroVerifyMessageFunctor buildMessage(L"NotNtSuccess(%s)", pszNtStatus, pszMessage);
                return WEX::TestExecution::Verify::NotNtSuccessImpl(ntStatus, errorInfo, buildMessage);
            }
#endif

            template <typename T>
            _Post_equal_to_(true)
            static bool ExpectedExceptionThrown(const T& TException, const wchar_t* pszException, const wchar_t* pszOperation, const wchar_t* pszMessage = nullptr)
            {
                UNREFERENCED_PARAMETER(TException);

                if (WEX::TestExecution::Verify::LogOnlyFailures())
                {
                    return WEX::TestExecution::Verify::VerificationPassed(WEX::Common::NoThrowString());
                }

                static const wchar_t c_szFormat[] = L"Expected exception (%s) caught during (%s)";
                WEX::Common::NoThrowString message(BuildMessage(c_szFormat, pszException, pszOperation, pszMessage));
                return WEX::TestExecution::Verify::VerificationPassed(message.ToCStrWithFallbackTo(c_szFormat));
            }

            _Post_equal_to_(false)
            static bool ExpectedExceptionNotThrown(const wchar_t* pszException, const wchar_t* pszOperation, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                static const wchar_t c_szFormat[] = L"Expected exception (%s) not caught during (%s)";
                WEX::Common::NoThrowString message(BuildMessage(c_szFormat, pszException, pszOperation, pszMessage));
                return WEX::TestExecution::Verify::VerificationFailed(message.ToCStrWithFallbackTo(c_szFormat), errorInfo);
            }

            _Post_equal_to_(false)
            static bool UnexpectedExceptionThrown(const wchar_t* pszOperation, const ErrorInfo& errorInfo, const wchar_t* pszMessage = nullptr)
            {
                static const wchar_t c_szFormat[] = L"Unexpected exception caught during (%s)";
                WEX::Common::NoThrowString message(BuildMessage(c_szFormat, pszOperation, pszMessage));
                return WEX::TestExecution::Verify::VerificationFailed(message.ToCStrWithFallbackTo(c_szFormat), errorInfo);
            }

            _Post_equal_to_(false)
            static bool UnexpectedExceptionThrownWithSpecifics(const wchar_t* pszOperation, const ErrorInfo& errorInfo, const wchar_t* pszSpecificException, const wchar_t* pszMessage = nullptr)
            {
                static const wchar_t c_szFallbackString[] = L"Unexpected exception caught";
                static const wchar_t c_szFormat[] = L"%s during (%s)";
                WEX::Common::NoThrowString message(BuildMessage(c_szFormat, pszSpecificException, pszOperation, pszMessage));
                return WEX::TestExecution::Verify::VerificationFailed(message.ToCStrWithFallbackTo(c_szFallbackString), errorInfo);
            }

            _Post_equal_to_(true)
            static bool UnexpectedExceptionNotThrown(const wchar_t* pszOperation, const wchar_t* pszMessage = nullptr)
            {
                if (WEX::TestExecution::Verify::LogOnlyFailures())
                {
                    return WEX::TestExecution::Verify::VerificationPassed(WEX::Common::NoThrowString());
                }

                static const wchar_t c_szFormat[] = L"Exception not caught during (%s)";
                WEX::Common::NoThrowString message(BuildMessage(c_szFormat, pszOperation, pszMessage));
                return WEX::TestExecution::Verify::VerificationPassed(message.ToCStrWithFallbackTo(c_szFormat));
            }

        private:
            MacroVerify(){}; // Disallow construction of static class
            ~MacroVerify(){}; // Disallow construction of static class
            MacroVerify(const MacroVerify&); // non-implemented
            MacroVerify& operator=(const MacroVerify&); // non-implemented

            class MacroVerifyMessageFunctor
            {
            public:
                MacroVerifyMessageFunctor(const wchar_t* pszFormat, const wchar_t* psz1, const wchar_t* psz2, const wchar_t* pszMessage)
                : m_pszFormat(pszFormat)
                , m_psz1(psz1)
                , m_psz2(psz2)
                , m_pszMessage(pszMessage)
                {
                }

                MacroVerifyMessageFunctor(const wchar_t* pszFormat, const wchar_t* psz1, const wchar_t* pszMessage)
                : m_pszFormat(pszFormat)
                , m_psz1(psz1)
                , m_psz2(nullptr)
                , m_pszMessage(pszMessage)
                {
                }

                WEX::Common::NoThrowString operator()() const
                {
                    if (m_psz2)
                    {
                        return BuildMessage(m_pszFormat, m_psz1, m_psz2, m_pszMessage);
                    }

                    return BuildMessage(m_pszFormat, m_psz1, m_pszMessage);
                }

            private:
                const wchar_t* m_pszFormat;
                const wchar_t* m_psz1;
                const wchar_t* m_psz2;
                const wchar_t* m_pszMessage;
            };

            static WEX::Common::NoThrowString BuildMessage(const wchar_t* pszFormat, const wchar_t* psz1, const wchar_t* psz2, const wchar_t* pszMessage)
            {
                WEX::Common::NoThrowString message;
                message.Format(pszFormat, psz1, psz2);
                if (!WEX::Common::String::IsNullOrEmpty(pszMessage))
                {
                    message.AppendFormat(L": %s", pszMessage);
                }
                return message;
            }

            static WEX::Common::NoThrowString BuildMessage(const wchar_t* pszFormat, const wchar_t* psz1, const wchar_t* pszMessage)
            {
                WEX::Common::NoThrowString message;
                message.Format(pszFormat, psz1);
                if (!WEX::Common::String::IsNullOrEmpty(pszMessage))
                {
                    message.AppendFormat(L": %s", pszMessage);
                }
                return message;
            }
        };

        template<typename Parameter>
        class TrueUnaryFunctor
        {
        public:
            bool operator()(Parameter)
            {
                return true;
            }
        };

#if defined(_CPPUNWIND)
        inline const wchar_t* GetExceptionInfo(WEX::Common::NoThrowString& message, _Out_opt_ HRESULT * pHResult = nullptr)
        {
            try
            {
                throw;
            }
            catch (const std::exception& e)
            {
                if (pHResult)
                {
                    *pHResult = E_UNEXPECTED;
                }

                static const wchar_t c_szMessage[] = L"Caught std::exception";
                message.Format(L"%s: %S", c_szMessage, e.what());
                return message.ToCStrWithFallbackTo(c_szMessage);
            }
            catch (const WEX::Common::Exception& e)
            {
                if (pHResult)
                {
                    *pHResult = e.ErrorCode();
                }

                static const wchar_t c_szMessage[] = L"Caught WEX::Common::Exception";
                message.Format(L"%s: %s [HRESULT: 0x%x]", c_szMessage, e.Message(), e.ErrorCode());
                return message.ToCStrWithFallbackTo(c_szMessage);
            }
# if defined(__cplusplus_winrt)
            catch (Platform::Exception^ e)
            {
                if (pHResult)
                {
                    *pHResult = e->HResult;
                }

                static const wchar_t c_szMessage[] = L"Caught Platform::Exception^";
                message.Format(L"%s: %s [HRESULT: 0x%x]", c_szMessage, e->Message->Data(), e->HResult);
                return message.ToCStrWithFallbackTo(c_szMessage);
            }
# endif // if defined(__cplusplus_winrt)
            catch (...)
            {
                if (pHResult)
                {
                    *pHResult = E_UNEXPECTED;
                }

                static const wchar_t c_szMessage[] = L"Caught an unidentified C++ exception";
                return c_szMessage;
            }
        }
#endif // if defined(_CPPUNWIND)

    } /* namespace Private */
} /* namespace TestExecution */ } /* namespace WEX */

#pragma pop_macro("SEALED")
#pragma pop_macro("Verify")
#pragma pop_macro("_Post_equal_to_")
#pragma pop_macro("_Out_opt_")
