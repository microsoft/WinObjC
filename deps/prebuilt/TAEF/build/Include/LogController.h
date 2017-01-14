//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>Class used for logging initialization and finalization.</summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Wex.Logger.h"
#include "WexString.h"

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

/// \namespace WEX::Logging
/// <summary>
/// The WEX::Logging namespace contains the Native API's for the Wex Logger.
/// </summary>
namespace WEX { namespace Logging 
{
    /// <summary>
    /// 
    /// </summary>
    typedef void (__stdcall *WexLoggerErrorCallback)(const unsigned short* pszMessage, HRESULT hr);

    /// <summary>
    /// 
    /// </summary>
    class WEXLOGGER_API LogController SEALED
    {
    public:
        /// <summary>
        /// Initialize logging functionality
        /// </summary>
        static HRESULT __stdcall InitializeLogging();

        /// <summary>
        /// Initialize logging functionality and provide a callback to be notified of any logging errors
        /// </summary>
        /// <param name="pfnErrorCallback"> </param>
        static HRESULT __stdcall InitializeLogging(WexLoggerErrorCallback pfnErrorCallback);

        /// <summary>
        /// Initialize logging functionality and specify the log name
        /// </summary>
        /// <param name="pszLogName"> </param>
        static HRESULT __stdcall InitializeLogging(_In_z_ const wchar_t* pszLogName);

        /// <summary>
        /// Initialize logging functionality, specify the log name and provide a callback to be notified of any logging errors
        /// </summary>
        /// <param name="pszLogName"> </param>
        /// <param name="pfnErrorCallback"> </param>
        static HRESULT __stdcall InitializeLogging(_In_z_ const wchar_t* pszLogName, WexLoggerErrorCallback pfnErrorCallback);

        /// <summary>
        /// Returns whether or not the LogController has been initialized for this process
        /// </summary>
        static bool __stdcall IsInitialized();

        /// <summary>
        /// Returns the name that was specified for the log in the InitializeLogging call (if any)
        /// </summary>
        static const unsigned short* __stdcall GetLogName();

        /// <summary>
        /// Finalize logging functionality
        /// </summary>
        static HRESULT __stdcall FinalizeLogging();

        // wchar_t native type exports
#ifdef WEXLOGGER_EXPORTS
        static HRESULT __stdcall InitializeLogging(_In_z_ const __wchar_t* pszLogName);
        static HRESULT __stdcall InitializeLogging(_In_z_ const __wchar_t* pszLogName, WexLoggerErrorCallback pfnErrorCallback);
#endif

    private:
        LogController(); // Disallow construction of static class
        ~LogController(); // Disallow destruction of static class
        LogController(const LogController&); // non-implemented
        LogController& operator=(const LogController&); // non-implemented
    };

    const wchar_t c_szWexLoggerRemoteConnectionData[] = L"/wexlogger_connectiondata=";

    /// <summary>
    /// Class used for preparing an incoming remote logging connection
    /// </summary>
    class WEXLOGGER_API RemoteLogController SEALED
    {
    public:
        /// <summary>
        /// Generate the connection data needed for the remote process to connect and log back to this process
        /// </summary>
        /// <param name="connectionData">Reference to a NoThrowString that will be populated with the connection data</param>
        static HRESULT __stdcall GenerateConnectionData(WEX::Common::NoThrowString& connectionData);

        /// <summary>
        /// Generate the connection data needed for the remote process to connect and log back to this process
        /// </summary>
        /// <param name="pszMachineName">The name of the machine on which the process will be created; only use this overload when creating a process on a remote machine.</param>
        /// <param name="connectionData">Reference to a NoThrowString that will be populated with the connection data</param>
        static HRESULT __stdcall GenerateConnectionData(const wchar_t* pszMachineName, WEX::Common::NoThrowString& connectionData);
        
        /// <summary>
        /// Initialize remote logging functionality
        /// </summary>
        /// <param name="pszConnectionData">Connection data used to connect to the remote process for receiving logging messages</param>
        static HRESULT __stdcall InitializeLogging(_In_z_ const wchar_t* pszConnectionData);

        // wchar_t native type exports
#ifdef WEXLOGGER_EXPORTS
        static HRESULT __stdcall GenerateConnectionData(const __wchar_t* pszMachineName, WEX::Common::NoThrowString& connectionData);
        static HRESULT __stdcall InitializeLogging(_In_z_ const __wchar_t* pszConnectionData);
#endif

    private:
        RemoteLogController(); // Disallow construction of static class
        ~RemoteLogController(); // Disallow destruction of static class
        RemoteLogController(const RemoteLogController&); // non-implemented
        RemoteLogController& operator=(const RemoteLogController&); // non-implemented
    };
} /* namespace Logging */ } /* namespace WEX */
#pragma pop_macro("SEALED")
