//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>Possible WexLogger test results.</summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once

namespace WEX { namespace Logging 
{
    namespace TestResults
    {
        /// <summary>
        /// Possible WexLogger test results.
        /// </summary>
        enum Result
        {
            /// <summary>The test passed.</summary>
            Passed = 0,

            /// <summary>The test was not run.</summary>
            NotRun,

            /// <summary>The test was skipped.</summary>
            Skipped,

            /// <summary>The test was blocked.</summary>
            Blocked,

            /// <summary>The test failed.</summary>
            Failed,

            /// <summary>The test result is unknown.</summary>
            Unknown
        };
    }
} /* namespace Logging */ } /* namespace WEX */
