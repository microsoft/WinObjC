//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary> </summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once

#include "WexTypes.h"

#include <basetyps.h>

#if (_MSC_VER < 1700)
# error Unsupported version of Visual Studio. Please use VS 2012 or later.
#endif

#ifdef WEXLOGGER_EXPORTS
# define WEXLOGGER_API __declspec(dllexport)
#else
# ifdef WEXLOGGER_UNIT_TESTING
#  define WEXLOGGER_API
# else
#  define WEXLOGGER_API __declspec(dllimport)
# endif
#endif

#ifdef UNIT_TESTING
# define UNIT_TEST_CLASS(__class) __if_exists(__class) { friend class __class; }
#else
# define UNIT_TEST_CLASS(__class)
#endif
