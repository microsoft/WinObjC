//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>Public logging interface for C++ tests.</summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Wex.Logger.h"

#include "LogTestResults.h"

// Allow anyone who has defined an Assert macro to compile with this header file included
#pragma push_macro("Assert")
#undef Assert

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
    class WEXLOGGER_API Log SEALED
    {
    public:
        /// <summary>
        /// Log a test assert
        /// </summary>
        /// <param name="pszAssert"> </param>
        static void __stdcall Assert(const wchar_t* pszAssert);

        /// <summary>
        /// Log a test assert
        /// </summary>
        /// <param name="pszAssert"> </param>
        /// <param name="pszContext"> </param>
        static void __stdcall Assert(const wchar_t* pszAssert, const wchar_t* pszContext);

        /// <summary>
        /// Log a test assert
        /// </summary>
        /// <param name="pszAssert"> </param>
        /// <param name="pszFile"> </param>
        /// <param name="pszFunction"> </param>
        /// <param name="line"> </param>
        static void __stdcall Assert(const wchar_t* pszAssert, const wchar_t* pszFile, const wchar_t* pszFunction, int line);

        /// <summary>
        /// Log a test assert
        /// </summary>
        /// <param name="pszAssert"> </param>
        /// <param name="pszContext"> </param>
        /// <param name="pszFile"> </param>
        /// <param name="pszFunction"> </param>
        /// <param name="line"> </param>
        static void __stdcall Assert(const wchar_t* pszAssert, const wchar_t* pszContext, const wchar_t* pszFile, const wchar_t* pszFunction, int line);

        /// <summary>
        /// Log a known bug number
        /// </summary>
        /// <param name="pszBugDatabase"> </param>
        /// <param name="bugId"> </param>
        static void __stdcall Bug(const wchar_t* pszBugDatabase, int bugId);

        /// <summary>
        /// Log a known bug number
        /// </summary>
        /// <param name="pszBugDatabase"> </param>
        /// <param name="bugId"> </param>
        /// <param name="pszContext"> </param>
        static void __stdcall Bug(const wchar_t* pszBugDatabase, int bugId, const wchar_t* pszContext);

        /// <summary>
        /// Log a test comment
        /// </summary>
        /// <param name="pszComment"> </param>
        static void __stdcall Comment(const wchar_t* pszComment);

        /// <summary>
        /// Log a test comment
        /// </summary>
        /// <param name="pszComment"> </param>
        /// <param name="pszContext"> </param>
        static void __stdcall Comment(const wchar_t* pszComment, const wchar_t* pszContext);

        /// <summary>
        /// Log the end of a group of tests, or of a specific test
        /// </summary>
        /// <param name="pszGroupName"> </param>
        static void __stdcall EndGroup(const wchar_t* pszGroupName);

        /// <summary>
        /// Log the end of a group of tests, or of a specific test
        /// </summary>
        /// <param name="pszGroupName"> </param>
        /// <param name="pszContext"> </param>
        static void __stdcall EndGroup(const wchar_t* pszGroupName, const wchar_t* pszContext);

        /// <summary>
        /// Log a test error
        /// </summary>
        /// <param name="pszError"> </param>
        static void __stdcall Error(const wchar_t* pszError);

        /// <summary>
        /// Log a test error
        /// </summary>
        /// <param name="pszError"> </param>
        /// <param name="pszContext"> </param>
        static void __stdcall Error(const wchar_t* pszError, const wchar_t* pszContext);

        /// <summary>
        /// Log a test error
        /// </summary>
        /// <param name="pszError"> </param>
        /// <param name="pszFile"> </param>
        /// <param name="pszFunction"> </param>
        /// <param name="line"> </param>
        static void __stdcall Error(const wchar_t* pszError, const wchar_t* pszFile, const wchar_t* pszFunction, int line);

        /// <summary>
        /// Log a test error
        /// </summary>
        /// <param name="pszError"> </param>
        /// <param name="pszContext"> </param>
        /// <param name="pszFile"> </param>
        /// <param name="pszFunction"> </param>
        /// <param name="line"> </param>
        static void __stdcall Error(const wchar_t* pszError, const wchar_t* pszContext, const wchar_t* pszFile, const wchar_t* pszFunction, int line);

        /// <summary>
        /// Log a test file to be saved to disk
        /// </summary>
        /// <param name="pszFilePath"> </param>
        static void __stdcall File(const wchar_t* pszFilePath);

        /// <summary>
        /// Log a test file to be saved to disk
        /// </summary>
        /// <param name="pszFilePath"> </param>
        /// <param name="pszContext"> </param>
        static void __stdcall File(const wchar_t* pszFilePath, const wchar_t* pszContext);

        /// <summary>
        /// Log a test file (in byte array form) to be saved to disk
        /// </summary>
        /// <param name="pszFileName"> </param>
        /// <param name="pFileBuffer"> </param>
        /// <param name="bufferSize"> </param>
        static void __stdcall File(const wchar_t* pszFileName, const unsigned char* pFileBuffer, size_t bufferSize);

        /// <summary>
        /// Log a test file (in byte array form) to be saved
        /// </summary>
        /// <param name="pszFileName"> </param>
        /// <param name="pszContext"> </param>
        /// <param name="pFileBuffer"> </param>
        /// <param name="bufferSize"> </param>
        static void __stdcall File(const wchar_t* pszFileName, const wchar_t* pszContext, const unsigned char* pFileBuffer, size_t bufferSize);

        /// <summary>
        /// Log a name/value property pair; the value can be in xml format
        /// </summary>
        /// <param name="pszName"> </param>
        /// <param name="pszValue"> </param>
        static void __stdcall Property(const wchar_t* pszName, const wchar_t* pszValue);

        /// <summary>
        /// Log a name/value property pair; the value can be in xml format
        /// </summary>
        /// <param name="pszName"> </param>
        /// <param name="pszValue"> </param>
        /// <param name="pszContext"> </param>
        static void __stdcall Property(const wchar_t* pszName, const wchar_t* pszValue, const wchar_t* pszContext);

        /// <summary>
        /// Log a test result
        /// </summary>
        /// <param name="testResult"> </param>
        static void __stdcall Result(TestResults::Result testResult);

        /// <summary>
        /// Log a test result
        /// </summary>
        /// <param name="testResult"> </param>
        /// <param name="pszComment"> </param>
        static void __stdcall Result(TestResults::Result testResult, const wchar_t* pszComment);

        /// <summary>
        /// Log a test result
        /// </summary>
        /// <param name="testResult"> </param>
        /// <param name="pszComment"> </param>
        /// <param name="pszContext"> </param>
        static void __stdcall Result(TestResults::Result testResult, const wchar_t* pszComment, const wchar_t* pszContext);

        /// <summary>
        /// Log the start of a group of tests, or of a specific test
        /// </summary>
        /// <param name="pszGroupName"> </param>
        static void __stdcall StartGroup(const wchar_t* pszGroupName);

        /// <summary>
        /// Log the start of a group of tests, or of a specific test; also sets the default test result
        /// </summary>
        /// <param name="pszGroupName"> </param>
        /// <param name="defaultTestResult"> </param>
        static void __stdcall StartGroup(const wchar_t* pszGroupName, TestResults::Result defaultTestResult);

        /// <summary>
        /// Log the start of a group of tests, or of a specific test
        /// </summary>
        /// <param name="pszGroupName"> </param>
        /// <param name="pszContext"> </param>
        static void __stdcall StartGroup(const wchar_t* pszGroupName, const wchar_t* pszContext);

        /// <summary>
        /// Log the start of a group of tests, or of a specific test; also sets the default test result
        /// </summary>
        /// <param name="pszGroupName"> </param>
        /// <param name="pszContext"> </param>
        /// <param name="defaultTestResult"> </param>
        static void __stdcall StartGroup(const wchar_t* pszGroupName, const wchar_t* pszContext, TestResults::Result defaultTestResult);

        /// <summary>
        /// Log a test warning
        /// </summary>
        /// <param name="pszWarning"> </param>
        static void __stdcall Warning(const wchar_t* pszWarning);

        /// <summary>
        /// Log a test warning
        /// </summary>
        /// <param name="pszWarning"> </param>
        /// <param name="pszContext"> </param>
        static void __stdcall Warning(const wchar_t* pszWarning, const wchar_t* pszContext);

        /// <summary>
        /// Log a test warning
        /// </summary>
        /// <param name="pszWarning"> </param>
        /// <param name="pszFile"> </param>
        /// <param name="pszFunction"> </param>
        /// <param name="line"> </param>
        static void __stdcall Warning(const wchar_t* pszWarning, const wchar_t* pszFile, const wchar_t* pszFunction, int line);

        /// <summary>
        /// Log a test warning
        /// </summary>
        /// <param name="pszWarning"> </param>
        /// <param name="pszContext"> </param>
        /// <param name="pszFile"> </param>
        /// <param name="pszFunction"> </param>
        /// <param name="line"> </param>
        static void __stdcall Warning(const wchar_t* pszWarning, const wchar_t* pszContext, const wchar_t* pszFile, const wchar_t* pszFunction, int line);

        /// <summary>
        /// Log xml data; no check is made to verify that it is well-formed
        /// </summary>
        /// <param name="pszXml"> </param>
        static void __stdcall Xml(const wchar_t* pszXml);

        /// <summary>
        /// Log xml data; no check is made to verify that it is well-formed
        /// </summary>
        /// <param name="pszXml"> </param>
        /// <param name="pszContext"> </param>
        static void __stdcall Xml(const wchar_t* pszXml, const wchar_t* pszContext);

        /// <summary>
        /// Log the current process mini dump
        /// </summary>
        static void __stdcall MiniDump();

        // wchar_t native type exports
        #ifdef WEXLOGGER_EXPORTS
        static void __stdcall Assert(const __wchar_t* pszAssert); 
        static void __stdcall Assert(const __wchar_t* pszAssert, const __wchar_t* pszContext); 
        static void __stdcall Assert(const __wchar_t* pszAssert, const __wchar_t* pszFile, const __wchar_t* pszFunction, int line); 
        static void __stdcall Assert(const __wchar_t* pszAssert, const __wchar_t* pszContext, const __wchar_t* pszFile, const __wchar_t* pszFunction, int line); 

        static void __stdcall Bug(const __wchar_t* pszBugDatabase, int bugId); 
        static void __stdcall Bug(const __wchar_t* pszBugDatabase, int bugId, const __wchar_t* pszContext); 

        static void __stdcall Comment(const __wchar_t* pszComment);
        static void __stdcall Comment(const __wchar_t* pszComment, const __wchar_t* pszContext);

        static void __stdcall EndGroup(const __wchar_t* pszGroupName);
        static void __stdcall EndGroup(const __wchar_t* pszGroupName, const __wchar_t* pszContext);

        static void __stdcall Error(const __wchar_t* pszError);
        static void __stdcall Error(const __wchar_t* pszError, const __wchar_t* pszContext);
        static void __stdcall Error(const __wchar_t* pszError, const __wchar_t* pszFile, const __wchar_t* pszFunction, int line);
        static void __stdcall Error(const __wchar_t* pszError, const __wchar_t* pszContext, const __wchar_t* pszFile, const __wchar_t* pszFunction, int line);

        static void __stdcall File(const __wchar_t* pszFilePath);
        static void __stdcall File(const __wchar_t* pszFilePath, const __wchar_t* pszContext);
        static void __stdcall File(const __wchar_t* pszFileName, const unsigned char* pFileBuffer, size_t bufferSize);
        static void __stdcall File(const __wchar_t* pszFileName, const __wchar_t* pszContext, const unsigned char* pFileBuffer, size_t bufferSize);

        static void __stdcall Property(const __wchar_t* pszName, const __wchar_t* pszValue);
        static void __stdcall Property(const __wchar_t* pszName, const __wchar_t* pszValue, const __wchar_t* pszContext);

        static void __stdcall Result(TestResults::Result testResult, const __wchar_t* pszComment);
        static void __stdcall Result(TestResults::Result testResult, const __wchar_t* pszComment, const __wchar_t* pszContext);

        static void __stdcall StartGroup(const __wchar_t* pszGroupName);
        static void __stdcall StartGroup(const __wchar_t* pszGroupName, TestResults::Result defaultTestResult);
        static void __stdcall StartGroup(const __wchar_t* pszGroupName, const __wchar_t* pszContext);
        static void __stdcall StartGroup(const __wchar_t* pszGroupName, const __wchar_t* pszContext, TestResults::Result defaultTestResult);

        static void __stdcall Warning(const __wchar_t* pszWarning);
        static void __stdcall Warning(const __wchar_t* pszWarning, const __wchar_t* pszContext);
        static void __stdcall Warning(const __wchar_t* pszWarning, const __wchar_t* pszFile, const __wchar_t* pszFunction, int line);
        static void __stdcall Warning(const __wchar_t* pszWarning, const __wchar_t* pszContext, const __wchar_t* pszFile, const __wchar_t* pszFunction, int line);

        static void __stdcall Xml(const __wchar_t* pszXml);
        static void __stdcall Xml(const __wchar_t* pszXml, const __wchar_t* pszContext);
        #endif
    private:
        Log(); // Disallow construction of static class
        ~Log(); // Disallow destruction of static class
        Log(const Log&); // non-implemented
        Log& operator=(const Log&); // non-implemented
    };
} /* namespace Logging */ } /* namespace WEX */

#pragma pop_macro("SEALED")
#pragma pop_macro("Assert")
