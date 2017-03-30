// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::ExtendedExecution {

struct IExtendedExecutionRevokedEventArgs;
struct IExtendedExecutionSession;
struct ExtendedExecutionRevokedEventArgs;
struct ExtendedExecutionSession;

}

namespace Windows::ApplicationModel::ExtendedExecution {

struct IExtendedExecutionRevokedEventArgs;
struct IExtendedExecutionSession;
struct ExtendedExecutionRevokedEventArgs;
struct ExtendedExecutionSession;

}

namespace Windows::ApplicationModel::ExtendedExecution {

template <typename T> struct impl_IExtendedExecutionRevokedEventArgs;
template <typename T> struct impl_IExtendedExecutionSession;

}

namespace Windows::ApplicationModel::ExtendedExecution {

enum class ExtendedExecutionReason
{
    Unspecified = 0,
    LocationTracking = 1,
    SavingData = 2,
};

enum class ExtendedExecutionResult
{
    Allowed = 0,
    Denied = 1,
};

enum class ExtendedExecutionRevokedReason
{
    Resumed = 0,
    SystemPolicy = 1,
};

}

}
