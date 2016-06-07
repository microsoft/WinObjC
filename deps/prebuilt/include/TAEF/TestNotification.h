//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary> API and data types for recieving notifications </summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include "TE.Common.h"
#include "WexTypes.h"

namespace WEX { namespace TestExecution
{
    /// <summary>
    ///  Notification registration class
    /// </summary>
    class TECOMMON_API TestNotification
    {
        public:
            /// <summary>
            ///  Register a call back function of LPHANDLER_FUNCTION_EX type to receive notifications from TAEF
            /// </summary>
            static HRESULT __stdcall RegisterHandler(LPHANDLER_FUNCTION_EX pfnHandler);

            /// <summary>
            ///  Unregister the registered call back function
            /// </summary>
            static void __stdcall UnregisterHandler();
    };
} /* TestExecution */ } /* namespace WEX */