//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>WexCommon assert implementation.</summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Wex.Common.h"
#include "WexDebug.h"

#ifndef WEX_ASSERT
#ifdef NDEBUG

#define WEX_ASSERT(___condition, ___message)

#else

#define WEX_ASSERT(___condition, ___message) WEX::Common::Debug::Assert(!!(___condition), (L#___condition), (___message), __WFILE__, __WFUNCTION__, __LINE__)

#endif /* NDEBUG */
#endif /* WEX_ASSERT */

