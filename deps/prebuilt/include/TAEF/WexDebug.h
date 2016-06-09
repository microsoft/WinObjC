//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>Common classes and macros for debugging.</summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Wex.Common.h"
#include "WexTypes.h"

#pragma warning(push)
#pragma warning(disable:4481)

#pragma push_macro("Assert")
#undef Assert

#pragma push_macro("Debug")
#undef Debug

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

/// \internal
/// <summary>
/// Define __WFILE__ and __WFUNCTION__ macros; do not use __FILEW__ and __FUNCTIONW__ names since STL 
/// uses macros with the same names, but does not check if they exist before defining them
/// </summary>
#ifndef WIDEN2
#define WIDEN2(x) L ## x
#endif

#ifndef WIDEN
#define WIDEN(x) WIDEN2(x)
#endif

#ifndef __WFILE__
#define __WFILE__ WIDEN(__FILE__)
#endif

#ifndef __WFUNCTION__
#define __WFUNCTION__ WIDEN(__FUNCTION__)
#endif

#ifndef UNREFERENCED_PARAMETER
#define UNREFERENCED_PARAMETER(P)          (P)
#endif

/// <summary>
/// Provides 'compile time assert' functionality.
/// </summary>
/// <remarks>
/// Use the COMPILE_TIME_CHECK macro with an compile-time-constant 'expr', and the build will break if the expression evaluates to false.
/// </remarks>
/// <param name="expr">The compile-time-constant expression to check.</param>
/// <param name="msg">A message to output in the build error. Note; this must not contain spaces.</param>
#define COMPILE_TIME_CHECK(expr, msg)                           \
{                                                               \
    __if_exists(WEX::Common::Private::CompileTimeCheck<(expr)>) \
    {                                                           \
        class Error : public ERROR_##msg {};                    \
    }                                                           \
}

#if _MSC_VER >= 1600
#define COMPILE_TIME_CHECK_V2(expr, msg, symbol) static_assert(expr, msg)
#else
#define COMPILE_TIME_CHECK_V2(expr, msg, symbol) COMPILE_TIME_CHECK(expr, symbol)
#endif

namespace WEX { namespace Common
{
    /// \internal
    /// <summary>
    /// The WEX::Common::Private namespace contains internal implementation details.
    /// </summary>
    namespace Private
    {
        /// \internal
        /// <summary>
        /// A template class necessary for the COMPILE_TIME_CHECK macro.
        /// Only the 'CompileTimeCheck&lt;false&gt;' specialization is provided; testing for the existance of a specialization
        /// is then a mechanism for testing an expression at compile time.
        ///
        /// This class should not be used directly - use the COMPILE_TIME_CHECK macro instead.
        /// </summary>
        template<bool>
        class CompileTimeCheck
        {
        };

        /// \internal
        /// <summary>
        /// The specialization of CompileTimeCheck&lt;false&gt;.
        ///
        /// This class should not be used directly - use the COMPILE_TIME_CHECK macro instead.
        /// </summary>
        template<>
        class CompileTimeCheck<false> 
        {
        };
    }

    /// <summary>
    /// Flags for GetStack stackFormats parameter
    /// </summary>
    /// <remarks>
    /// The flags are combinable with the | operator
    /// </remarks>
    namespace CallStackFormat
    {
        /// <summary>Displays only functionModule!functionName for each frame.</summary>
        const extern WEXCOMMON_API DWORD Default;

        /// <summary>Show return, previous frame and other relevant address values for each frame.</summary>
        const extern WEXCOMMON_API DWORD FrameAddress;

        /// <summary>This option is currently ignored.</summary>
        const extern WEXCOMMON_API DWORD FunctionInfo;

        /// <summary>Displays source line information for each frame of the stack trace.</summary>
        const extern WEXCOMMON_API DWORD SourceLine;

        /// <summary>Shows frame numbers.</summary>
        const extern WEXCOMMON_API DWORD FrameNumbers;

        /// <summary>This option is currently ignored.</summary>
        const extern WEXCOMMON_API DWORD Parameters;

        /// <summary>Shows column names.</summary>
        const extern WEXCOMMON_API DWORD ColumnNames;

        /// <summary>Shows frame-to-frame memory usage.</summary>
        const extern WEXCOMMON_API DWORD FrameMemoryUsage;

        /// <summary>Shows all available information. This is equivalent to Default | FrameAddress | FunctionInfo | SourceLine
        /// | FrameNumbers | Parameters | ColumnNames | FrameMemoryUsage.</summary>
        const extern WEXCOMMON_API DWORD FullInfo;
    }

    /// <summary>
    /// Flags for SaveDump miniDumpFormats parameter
    /// </summary>
    /// <remarks>
    /// The flags are combinable with the | operator
    /// </remarks>
    namespace MiniDumpFormat
    {
        /// <summary>Include process memory, stacks, etc - enough for most scenarios</summary>
        const extern WEXCOMMON_API DWORD Default;

        /// <summary>Packages dump into a CAB file</summary>
        const extern WEXCOMMON_API DWORD WriteCab;

        /// <summary>When creating a CAB adds secondary files such as current symbols and mapped images; takes very long time to complete</summary>
        const extern WEXCOMMON_API DWORD WriteCabSecondaryFiles;

        /// <summary>Adds full memory data. All accessible committed pages owned by the target application will be included</summary>
        const extern WEXCOMMON_API DWORD FullMemory;

        /// <summary>Adds data about the handles that are associated with the target application</summary>
        const extern WEXCOMMON_API DWORD HandleData;

        /// <summary>Adds unloaded module information</summary>
        const extern WEXCOMMON_API DWORD UnloadedModules;

        /// <summary>Adds indirect memory, a small region of memory that surrounds any address that is referenced by a pointer on the stack or backing store is included</summary>
        const extern WEXCOMMON_API DWORD IndirectMemory;

        /// <summary>Adds all data segments within the executable images</summary>
        const extern WEXCOMMON_API DWORD DataSegments;

        /// <summary>Adds the process environment block (PEB) and thread environment block (TEB). This flag can be used to provide Windows system information for threads and processes.</summary>
        const extern WEXCOMMON_API DWORD ProcessThreadData;

        /// <summary>Adds all committed private read-write memory pages</summary>
        const extern WEXCOMMON_API DWORD PrivateReadWriteMemory;

        /// <summary>Adds all basic memory information. The information for all memory is included, not just valid memory, which allows the debugger to reconstruct the complete virtual memory layout from the Minidump</summary>
        const extern WEXCOMMON_API DWORD FullMemoryInfo;

        /// <summary>Adds additional thread information, which includes execution time, start time, exit time, start address, and exit status</summary>
        const extern WEXCOMMON_API DWORD ThreadInfo;

        /// <summary>Adds all code segments with the executable images</summary>
        const extern WEXCOMMON_API DWORD CodeSegments;

        /// <summary>Creates a mixed / managed process actionable dump (alias to FullMemory)</summary>
        const extern WEXCOMMON_API DWORD ManagedDump;

        /// <summary>FullMemory | HandleData | FullMemoryInfo | ThreadInfo | UnloadedModules | CodeSegments | IndirectMemory</summary>
        const extern WEXCOMMON_API DWORD FullDump;
    }

    class NoThrowString;

    /// <summary>
    /// Debugger related operations helper class
    /// </summary>
    class WEXCOMMON_API Debug SEALED
    {
    public:
        /// <summary>
        /// Assert when a given condition is false
        /// </summary>
        /// <param name="condition">Assert condition</param>
        /// <param name="pszCondition">Assert condition string</param>
        /// <param name="pszMessage">Assert message</param>
        /// <param name="pszFile">Assert source file name</param>
        /// <param name="pszFunction">Assert source function name</param>
        /// <param name="line">Assert souce line number</param>
        static void __stdcall Assert(bool condition, const wchar_t* pszCondition, const wchar_t* pszMessage, 
            const wchar_t* pszFile, const wchar_t* pszFunction, int line);

        /// <summary>
        /// Causes a breakpoint in the code
        /// </summary>
        static void __stdcall Break();

        /// <summary>
        /// Checks whether a debugger is present on the system
        /// </summary>
        /// <returns>true if a debugger found under AEDebug</returns>
        static bool __stdcall IsDebuggerPresent();

        // SaveDump and GetStack require dbgeng.dll and dbghelp.dll of version 6.x or above 
        // to exist in the LoadLibrary search path
        // If older version found, NTE_BAD_VER error is returned

        /// <summary>
        /// Creates a minidump for the current process and saves it in the process local directory
        /// </summary>
        /// <param name="savedDumpFilePath">The full path to the minidump file (set on success)</param>
        /// <returns>Success of saving a dump</returns>
        static HRESULT __stdcall SaveDump(NoThrowString& savedDumpFilePath);

        /// <summary>
        /// Creates a minidump for the current process and saves it in the process local directory
        /// </summary>
        /// <param name="miniDumpFormat">See the values in namespace MiniDumpFormat above for miniDumpFormat parameter</param>
        /// <param name="savedDumpFilePath">The full path to the minidump file (set on success)</param>
        /// <returns>Success of saving a dump</returns>
        static HRESULT __stdcall SaveDump(DWORD miniDumpFormat, NoThrowString& savedDumpFilePath);

        /// <summary>
        /// Obtains the call stack for the context in capturedStack
        /// </summary>
        /// <param name="capturedStack">The captured stack value</param>
        /// <returns>Success of capturing stack</returns>
        static HRESULT __stdcall GetStack(NoThrowString& capturedStack);

        /// <summary>
        /// Obtains the call stack for the context in capturedStack
        /// </summary>
        /// <param name="stackFormat"> See the values in namespace CallStackFormat above for stackFormat parameter</param>
        /// <param name="capturedStack">The captured stack value</param>
        /// <returns>Success of capturing stack</returns>
        static HRESULT __stdcall GetStack(DWORD stackFormat, NoThrowString& capturedStack);

        /// <summary>
        /// Returns the last 'Win32' error - acting as a compiler firewall so that the Verify classes don't have to depend on Windows.h
        /// </summary>
        /// <returns>The calling thread's last error code.</returns>
        static DWORD __stdcall GetLastError();

        /// <summary>
        /// Sets the last 'Win32' error - acting as a compiler firewall so that the Verify classes don't have to depend on Windows.h
        /// </summary>
        /// <param name="lastError">The error code to set for the calling thread.</returns>
        static void __stdcall SetLastError(unsigned long lastError);

        /// <summary>
        /// Sends text to debug output.
        /// </summary>
        /// <remarks>
        /// The text will only be written on a 'debug' build.
        /// </remarks>
        /// <param name="pszString">The message to be sent</param>
        static void __stdcall Write(const wchar_t* pszString)
        {
#ifndef NDEBUG
            Debug::WriteImpl(pszString);
#else
            UNREFERENCED_PARAMETER(pszString);
#endif
        }

        /// <summary>
        /// Sends text to debug output. Each text message ends with a new line
        /// </summary>
        /// <remarks>
        /// The text will only be written on a 'debug' build.
        /// </remarks>
        /// <param name="pszString">The message to be sent</param>
        static void __stdcall WriteLine(const wchar_t* pszString)
        {
#ifndef NDEBUG
            Debug::WriteLineImpl(pszString);
#else
            UNREFERENCED_PARAMETER(pszString);
#endif
        }

        // wchar_t native type exports
#ifdef WEXCOMMON_FULL_BUILD
        static void __stdcall Assert(bool condition, const __wchar_t* pszCondition, const __wchar_t* pszMessage, 
            const __wchar_t* pszFile, const __wchar_t* pszFunction, int line);

        static void __stdcall Write(const __wchar_t* pszString)
        {
#ifndef NDEBUG
            Debug::WriteImpl(reinterpret_cast<const wchar_t*>(pszString));
#else
            UNREFERENCED_PARAMETER(pszString);
#endif
        }

        static void __stdcall WriteLine(const __wchar_t* pszString)
        {
#ifndef NDEBUG
            Debug::WriteLineImpl(reinterpret_cast<const wchar_t*>(pszString));
#else
            UNREFERENCED_PARAMETER(pszString);
#endif
        }
#endif

    private:
        Debug();
        Debug(const Debug&);
        Debug& operator=(const Debug&);

        static void __stdcall WriteImpl(const wchar_t* pszString);
        static void __stdcall WriteLineImpl(const wchar_t* pszString);

        // wchar_t native type exports
#ifdef WEXCOMMON_FULL_BUILD
        static void __stdcall WriteImpl(const __wchar_t* pszString);
        static void __stdcall WriteLineImpl(const __wchar_t* pszString);
#endif

        static const bool c_fullDebug;
    };
} /* namespace Common */ } /* namespace WEX */

#pragma pop_macro("SEALED")
#pragma pop_macro("Debug")
#pragma pop_macro("Assert")
#pragma warning(pop)
