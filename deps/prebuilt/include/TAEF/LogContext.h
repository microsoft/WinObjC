//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>Class used for opening/closing log contexts.</summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Wex.Logger.h"
#include "Log.h"

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

namespace WEX { namespace Logging
{
    /// <summary>
    ///
    /// </summary>
    class WEXLOGGER_API LogContext SEALED
    {
    public:
        /// <summary>
        /// Create a new context
        /// </summary>
        /// <param name="pszParentContext"> </param>
        /// <param name="pszChildContext"> </param>
        /// <param name="pszChildData"> </param>
        static void __stdcall CreateContext(const wchar_t* pszParentContext, const wchar_t* pszChildContext, const wchar_t* pszChildData);
        
        /// <summary>
        /// Close the specified context, and assign it the specified test result
        /// </summary>
        /// <param name="pszContext"> </param>
        /// <param name="testResult"> </param>
        static void __stdcall CloseContext(const wchar_t* pszContext, TestResults::Result testResult);

        /// <summary>
        /// Log a comment in plain text for the specified context
        /// </summary>
        /// <param name="pszContext"> </param>
        /// <param name="pszComment"> </param>
        static void __stdcall LogComment(const wchar_t* pszContext, const wchar_t* pszComment);

        /// <summary>
        /// Log a test file to be saved for the specified context
        /// </summary>
        /// <param name="pszContext"> </param>
        /// <param name="pszFileName"> </param>
        static void __stdcall LogFile(const wchar_t* pszContext, const wchar_t* pszFileName);

        /// <summary>
        /// Log xml data for the specified context; no check is made to verify that it is well-formed
        /// </summary>
        /// <param name="pszContext"> </param>
        /// <param name="pszXml"> </param>
        static void __stdcall LogXml(const wchar_t* pszContext, const wchar_t* pszXml);

        // wchar_t native type exports
        #ifdef WEXLOGGER_EXPORTS
        static void __stdcall CreateContext(const __wchar_t* pszParentContext, const __wchar_t* pszChildContext, const __wchar_t* pszChildData);
        static void __stdcall CloseContext(const __wchar_t* pszContext, TestResults::Result testResult);
        static void __stdcall LogComment(const __wchar_t* pszContext, const __wchar_t* pszComment);
        static void __stdcall LogFile(const __wchar_t* pszContext, const __wchar_t* pszFileName);
        static void __stdcall LogXml(const __wchar_t* pszContext, const __wchar_t* pszXml);
        #endif

    private:
        LogContext(); // Disallow construction of static class
        ~LogContext(); // Disallow destruction of static class
        LogContext(const LogContext&); // non-implemented
        LogContext& operator=(const LogContext&); // non-implemented
    };
} /* namespace Logging */ } /* namespace WEX */

#pragma pop_macro("SEALED")
