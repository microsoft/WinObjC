//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>
/// Entry point for throwing WEX::Exceptions.
/// 
/// Provides helper functions for verifying before throwing, as well as throwing without verification.
/// </summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Wex.Common.h"
#include "WexTypes.h"

#pragma push_macro("_In_opt_z_")
#pragma push_macro("_In_range_")
#pragma push_macro("_Maybenull_")
#pragma push_macro("_When_")

#if !defined(_In_opt_z_)
#define _In_opt_z_
#endif

#if !defined(_In_range_)
#define _In_range_(a,b)
#endif

#if !defined(_Maybenull_)
#define _Maybenull_
#endif

#if !defined(_When_)
#define _When_(a,b)
#endif

/// <summary>
/// </summary>
namespace WEX { namespace Common { namespace Throw
{
    // Verify before throwing

    /// <summary>Throws a Wex::Exception if -condition- failed</summary>
    WEXCOMMON_API void __stdcall IfFailed(HRESULT condition);

    /// <summary>Throws a Wex::Exception if -condition- failed</summary>
    WEXCOMMON_API void __stdcall IfFailed(HRESULT condition, _In_opt_z_ const wchar_t* pszMessage);

    /// <summary>Throws a Wex::Exception if -condition- *false*</summary>
    WEXCOMMON_API void __stdcall IfFalse(bool condition, _When_(!condition, _In_range_(<, 0)) HRESULT errorToThrow);

    /// <summary>Throws a Wex::Exception if -condition- *false*</summary>
    WEXCOMMON_API void __stdcall IfFalse(bool condition, _When_(!condition, _In_range_(<, 0)) HRESULT errorToThrow, _In_opt_z_ const wchar_t* pszMessage);

    /// <summary>Throws a Wex::Exception if -condition- is *true*</summary>
    WEXCOMMON_API void __stdcall If(bool condition, _When_(condition, _In_range_(<, 0)) HRESULT errorToThrow);

    /// <summary>Throws a Wex::Exception if -condition- is *true*</summary>
    WEXCOMMON_API void __stdcall If(bool condition, _When_(condition, _In_range_(<, 0)) HRESULT errorToThrow, _In_opt_z_ const wchar_t* pszMessage);

    /// <summary>Throws a Wex::Exception (E_POINTER) if -p- is null</summary>
    WEXCOMMON_API void __stdcall IfNull(_Maybenull_ const void* p);

    /// <summary>Throws a Wex::Exception (E_POINTER) if -p- is null</summary>
    WEXCOMMON_API void __stdcall IfNull(_Maybenull_ const void* p, _In_opt_z_ const wchar_t* pszMessage);

    /// <summary>Throws a Wex::Exception with GetLastError() information if -condition- is *true*</summary>
    WEXCOMMON_API void __stdcall LastErrorIf(bool condition);

    /// <summary>Throws a Wex::Exception with GetLastError() information if -condition- is *true*</summary>
    WEXCOMMON_API void __stdcall LastErrorIf(bool condition, _In_opt_z_ const wchar_t* pszMessage);

    /// <summary>Throws a Wex::Exception with GetLastError() information if -condition- is *false*</summary>
    WEXCOMMON_API void __stdcall LastErrorIfFalse(bool condition);

    /// <summary>Throws a Wex::Exception with GetLastError() information if -condition- is *false*</summary>
    WEXCOMMON_API void __stdcall LastErrorIfFalse(bool condition, _In_opt_z_ const wchar_t* pszMessage);

    // Throw without verification

    /// <summary>Throws a Wex::Exception with the specified parameters</summary>
    WEXCOMMON_API void __declspec(noreturn) __stdcall Exception(_In_range_(<, 0) HRESULT errorToThrow);

    /// <summary>Throws a Wex::Exception with the specified parameters</summary>
    WEXCOMMON_API void __declspec(noreturn) __stdcall Exception(_In_range_(<, 0) HRESULT errorToThrow, _In_opt_z_ const wchar_t* pszMessage);

    /// <summary>Throws a Wex::Exception with GetLastError() information</summary>
    WEXCOMMON_API __declspec(noreturn) void __stdcall LastError();

    /// <summary>Throws a Wex::Exception with GetLastError() information</summary>
    WEXCOMMON_API __declspec(noreturn) void __stdcall LastError(_In_opt_z_ const wchar_t* pszMessage);

    // wchar_t native type exports
    #ifdef WEXCOMMON_FULL_BUILD
    WEXCOMMON_API void __stdcall IfFailed(HRESULT condition, _In_opt_z_ const __wchar_t* pszMessage); // Throws a Wex::Exception if -condition- failed
    WEXCOMMON_API void __stdcall IfFalse(bool condition, _When_(!condition, _In_range_(<, 0)) HRESULT errorToThrow, _In_opt_z_ const __wchar_t* pszMessage); // Throws a Wex::Exception if -condition- *false*
    WEXCOMMON_API void __stdcall If(bool condition, _When_(condition, _In_range_(<, 0)) HRESULT errorToThrow, _In_opt_z_ const __wchar_t* pszMessage); // Throws a Wex::Exception if -condition- is *true*
    WEXCOMMON_API void __stdcall IfNull(_Maybenull_ const void* p, _In_opt_z_ const __wchar_t* pszMessage); // Throws a Wex::Exception (E_POINTER) if -p- is null
    WEXCOMMON_API void __stdcall LastErrorIf(bool condition, _In_opt_z_ const __wchar_t* pszMessage); // Throws a Wex::Exception with GetLastError() information if -condition- is *true*
    WEXCOMMON_API void __stdcall LastErrorIfFalse(bool condition, _In_opt_z_ const __wchar_t* pszMessage); // Throws a Wex::Exception with GetLastError() information if -condition- is *false*
    WEXCOMMON_API __declspec(noreturn) void __stdcall Exception(_In_range_(<, 0) HRESULT errorToThrow, _In_opt_z_ const __wchar_t* pszMessage); // Throws a Wex::Exception with the specified parameters
    WEXCOMMON_API __declspec(noreturn) void __stdcall LastError(_In_opt_z_ const __wchar_t* pszMessage); // Throws a Wex::Exception with GetLastError() information
    #endif

    namespace Private {
        // not exported, only declared so that WEX::Common::Exception can befriend it
        void ThrowImpl(_In_range_(<, 0) HRESULT errorToThrow, _In_opt_z_ const wchar_t* pszMessage);
    }
} /* namespace Throw */ } /* namespace Common */ } /* namespace WEX */

#pragma pop_macro("_In_opt_z_")
#pragma pop_macro("_In_range_")
#pragma pop_macro("_Maybenull_")
#pragma pop_macro("_When_")
