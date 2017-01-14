//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>Common definitions for the Te.Common.dll.</summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once

#ifdef TECOMMON_EXPORTS
# ifndef TECOMMON_API
#  define TECOMMON_API __declspec(dllexport)
# endif
# ifndef TECOMMON_EXPORT_TEMPLATE
#  define TECOMMON_EXPORT_TEMPLATE
# endif
#else
# ifdef TECOMMON_UNIT_TESTING
#  ifndef TECOMMON_API
#   define TECOMMON_API
#  endif
#  ifndef TECOMMON_EXPORT_TEMPLATE
#   define TECOMMON_EXPORT_TEMPLATE
#  endif
# else
#  ifndef TECOMMON_API
#   define TECOMMON_API __declspec(dllimport)
#  endif
#  ifndef TECOMMON_EXPORT_TEMPLATE
#   define TECOMMON_EXPORT_TEMPLATE extern
#  endif
# endif
#endif

#ifdef UNIT_TESTING
# define UNIT_TEST_CLASS(__class) __if_exists(__class) { friend class __class; }
#else
# define UNIT_TEST_CLASS(__class)
#endif