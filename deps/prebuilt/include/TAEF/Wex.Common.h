//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>Common definitions for the Wex.Common.dll.</summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once

#include <basetyps.h>

#if defined(WEXCOMMON_EXPORTS)
# define WEXCOMMON_API __declspec(dllexport)
# define EXPIMP_TEMPLATE
#elif defined(WEXCOMMON_UNIT_TESTING)
# define WEXCOMMON_API
# define EXPIMP_TEMPLATE
#elif defined(WEXCOMMON_STATIC)
# define WEXCOMMON_API
# define EXPIMP_TEMPLATE
#else
# define WEXCOMMON_API __declspec(dllimport)
# define EXPIMP_TEMPLATE extern
#endif

#if defined(UNIT_TESTING)
# define UNIT_TEST_CLASS(__class) __if_exists(__class) { friend class __class; }
#else
# define UNIT_TEST_CLASS(__class)
#endif