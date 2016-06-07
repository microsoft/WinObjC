//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>Base exception class; all exceptions thrown should either be this class or derive from it.</summary>
/// <remarks>You cannot throw this Exception directly - instead, you must use one of the Throw class methods.</remarks>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Wex.Common.h"
#include "WexString.h"
#include "Throw.h"

#pragma push_macro("_In_z_")
#pragma push_macro("_Ret_z_")
#pragma push_macro("_In_range_")
#pragma push_macro("_Field_range_")
#pragma push_macro("_Ret_range_")

#if !defined(_In_z_)
#define _In_z_
#endif

#if !defined(_Ret_z_)
#define _Ret_z_
#endif

#if !defined(_In_range_)
#define _In_range_(a,b)
#endif

#if !defined(_Field_range_)
#define _Field_range_(a,b)
#endif

#if !defined(_Ret_range_)
#define _Ret_range_(a,b)
#endif

namespace WEX { namespace Common
{
    const wchar_t c_szExceptionMessageUnavailable[] = L"Error retrieving exception message; possibly out of memory.";

    class WEXCOMMON_API Exception
    {
    // Only allow Throw to construct Exception objects
    friend void Throw::Private::ThrowImpl(HRESULT, const wchar_t*);

    public:
        Exception(const Exception& other); // Copy constructor
        virtual ~Exception(){}

        _Ret_z_ const unsigned short* Message() const // Returns the message (if any) that was passed into the Exception constructor 
        {
            if (m_message.IsValid())
            {
                return reinterpret_cast<const unsigned short*>(static_cast<const wchar_t*>(m_message));
            }
            else
            {
                return reinterpret_cast<const unsigned short*>(c_szExceptionMessageUnavailable);
            }
        }

        #pragma prefast(suppress:28196, "PreFast is not taking the _Field_range_ annotation under consideration when enforcing _Ret_range_.")
        _Ret_range_(<,0) HRESULT ErrorCode() const // Returns the HRESULT that was passed into the Exception constructor
        {
            return m_hresult;
        }

    protected:
        explicit Exception(_In_range_(<, 0) HRESULT errorCode) // Don't allow "throw Exception()" -- use Throw::<method>() instead
        : m_hresult(errorCode)
        {
        }

        Exception(_In_range_(<, 0) HRESULT errorCode, _In_z_ const wchar_t* pszMessage) // Don't allow "throw Exception()" -- use Throw::<method>() instead
        : m_hresult(errorCode)
        , m_message(pszMessage)
        {
        }

        Exception(_In_range_(<, 0) HRESULT errorCode, const WEX::Common::String& message) // Don't allow "throw Exception()" -- use Throw::<method>() instead
        : m_hresult(errorCode)
        , m_message(message)
        {
        }

        // wchar_t native type export
        #ifdef WEXCOMMON_FULL_BUILD
        Exception(_In_range_(<, 0) HRESULT errorCode, _In_z_ const __wchar_t* pszMessage) // Don't allow "throw Exception()" -- use Throw::<method>() instead
        : m_hresult(errorCode)
        , m_message(reinterpret_cast<const wchar_t*>(pszMessage))
        {
        }
        #endif

    private:
        Exception& operator=(const Exception&); // non-implemented assignment operator

        // Making 'operator new' private prevents heap allocation of Exception, and forces Exception instances
        // to be thrown by value.
        static void* operator new(size_t);

        // Making 'operator delete' private for consistency with 'operator new'.
        // This is implemented to prevent linker errors.
        static void operator delete(void*) {}

        _Field_range_(<,0) const HRESULT m_hresult;
        WEX::Common::NoThrowString m_message;
    };

} /* namespace Common */ } /* namespace WEX */

#pragma pop_macro("_In_z_")
#pragma pop_macro("_Ret_z_")
#pragma pop_macro("_In_range_")
#pragma pop_macro("_Field_range_")
#pragma pop_macro("_Ret_range_")
