// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::ExtendedExecution::Foreground {

struct IExtendedExecutionForegroundRevokedEventArgs;
struct IExtendedExecutionForegroundSession;
struct ExtendedExecutionForegroundRevokedEventArgs;
struct ExtendedExecutionForegroundSession;

}

namespace Windows::ApplicationModel::ExtendedExecution::Foreground {

struct IExtendedExecutionForegroundRevokedEventArgs;
struct IExtendedExecutionForegroundSession;
struct ExtendedExecutionForegroundRevokedEventArgs;
struct ExtendedExecutionForegroundSession;

}

namespace Windows::ApplicationModel::ExtendedExecution::Foreground {

template <typename T> struct impl_IExtendedExecutionForegroundRevokedEventArgs;
template <typename T> struct impl_IExtendedExecutionForegroundSession;

}

namespace Windows::ApplicationModel::ExtendedExecution::Foreground {

enum class ExtendedExecutionForegroundReason
{
    Unspecified = 0,
    SavingData = 1,
    BackgroundAudio = 2,
    Unconstrained = 3,
};

enum class ExtendedExecutionForegroundResult
{
    Allowed = 0,
    Denied = 1,
};

enum class ExtendedExecutionForegroundRevokedReason
{
    Resumed = 0,
    SystemPolicy = 1,
};

}

}
