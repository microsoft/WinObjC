// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::System::Threading {

struct IThreadPoolStatics;
struct IThreadPoolTimer;
struct IThreadPoolTimerStatics;
struct TimerDestroyedHandler;
struct TimerElapsedHandler;
struct WorkItemHandler;
struct ThreadPoolTimer;

}

namespace Windows::System::Threading {

struct TimerDestroyedHandler;
struct TimerElapsedHandler;
struct WorkItemHandler;
struct IThreadPoolStatics;
struct IThreadPoolTimer;
struct IThreadPoolTimerStatics;
struct ThreadPool;
struct ThreadPoolTimer;

}

namespace Windows::System::Threading {

template <typename T> struct impl_IThreadPoolStatics;
template <typename T> struct impl_IThreadPoolTimer;
template <typename T> struct impl_IThreadPoolTimerStatics;
template <typename T> struct impl_TimerDestroyedHandler;
template <typename T> struct impl_TimerElapsedHandler;
template <typename T> struct impl_WorkItemHandler;

}

namespace Windows::System::Threading {

enum class WorkItemOptions : unsigned
{
    None = 0x0,
    TimeSliced = 0x1,
};

DEFINE_ENUM_FLAG_OPERATORS(WorkItemOptions)

enum class WorkItemPriority
{
    Low = -1,
    Normal = 0,
    High = 1,
};

}

}
