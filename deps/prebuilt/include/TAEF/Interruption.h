//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>API and data types for interacting with TAEF during Reboot scenarios.</summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include "TE.Common.h"

namespace WEX { namespace TestExecution
{
    namespace RebootOption
    {
        enum Option
        {
            Rerun,
            Continue
        };
    }

    namespace Interruption
    {
        TECOMMON_API void __stdcall Reboot(RebootOption::Option option);
        TECOMMON_API void __stdcall RebootCustom(RebootOption::Option option);
    }
} /* TestExecution */ } /* namespace WEX */
