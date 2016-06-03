//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary> API for accessing runtime parameters from native tests </summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include "TE.Common.h"
#include "WexTypes.h"

#include <BaseTyps.h>

#pragma push_macro("_In_z_")

#if !defined(_In_z_)
#define _In_z_
#endif

namespace WEX { namespace TestExecution
{
    namespace Private
    {
        /// \internal
        /// WEX::TestExecution::Private::RuntimeParameters must be a templatized *class* so that we can dll export explicit 
        /// instantiations.
        template <typename T>
        class TECOMMON_API RuntimeParameters
        {
        public:
            // Tries to get the requested value in the requested format
            static HRESULT __stdcall TryGetValue(_In_z_ const wchar_t* pszString, T& result);

            #ifdef TECOMMON_EXPORTS
            static HRESULT __stdcall TryGetValue(_In_z_ const __wchar_t* pszString, T& result);
            #endif

        private:
            RuntimeParameters(const RuntimeParameters&);
            RuntimeParameters& operator=(const RuntimeParameters&);
        };
    }

    namespace RuntimeParameterConstants
    {
        const wchar_t c_szTestDeploymentDir[] = L"TestDeploymentDir"; // Constant used to query RunTimeParameters for the directory that the test binary is loaded from
        const wchar_t c_szTestName[] = L"TestName"; // Constant used to query RunTimeParameters for the name of the test that is currently running
        const wchar_t c_szFullTestName[] = L"FullTestName"; // Constant used to query RunTimeParameters for the name of the test variation that is currently running
        const wchar_t c_szTestResult[] = L"TestResult"; // Constant used to query RuntimeParameters for the result of the test(s) run within the scope fo this cleanup function
    };

    /// <summary>
    ///  Runtime parameters retrival class
    /// </summary>
    /// \internal
    /// WEX::TestExecution::RuntimeParameters provides 'templatized' *methods* to allow compiler type inference, and simply routes 
    /// the call to the matching WEX::TestExecution::Private::TestData<T> instantiation.
    class RuntimeParameters
    {
    public:
        /// <summary>
        ///  API for runtime parameters retrival
        /// </summary>
        /// \code
        /// Example:
        ///    String value;
        ///    RuntimeParameters::TryGetValue(L"ParameterName3", value);
        /// \endcode
        template <typename T>
        static HRESULT __stdcall TryGetValue(_In_z_ const wchar_t* pszString, T& result)
        {
            return Private::RuntimeParameters<T>::TryGetValue(pszString, result);
        }

    private:
        RuntimeParameters(const RuntimeParameters&);
        RuntimeParameters& operator=(const RuntimeParameters&);
    };

} /* TestExecution */ } /* namespace WEX */

#pragma pop_macro("_In_z_")
