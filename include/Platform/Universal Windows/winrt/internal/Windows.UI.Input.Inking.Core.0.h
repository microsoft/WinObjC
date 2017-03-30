// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Input::Inking::Core {

struct ICoreInkIndependentInputSource;
struct ICoreInkIndependentInputSourceStatics;
struct ICoreWetStrokeUpdateEventArgs;
struct ICoreWetStrokeUpdateSource;
struct ICoreWetStrokeUpdateSourceStatics;
struct CoreInkIndependentInputSource;
struct CoreWetStrokeUpdateEventArgs;
struct CoreWetStrokeUpdateSource;

}

namespace Windows::UI::Input::Inking::Core {

struct ICoreInkIndependentInputSource;
struct ICoreInkIndependentInputSourceStatics;
struct ICoreWetStrokeUpdateEventArgs;
struct ICoreWetStrokeUpdateSource;
struct ICoreWetStrokeUpdateSourceStatics;
struct CoreInkIndependentInputSource;
struct CoreWetStrokeUpdateEventArgs;
struct CoreWetStrokeUpdateSource;

}

namespace Windows::UI::Input::Inking::Core {

template <typename T> struct impl_ICoreInkIndependentInputSource;
template <typename T> struct impl_ICoreInkIndependentInputSourceStatics;
template <typename T> struct impl_ICoreWetStrokeUpdateEventArgs;
template <typename T> struct impl_ICoreWetStrokeUpdateSource;
template <typename T> struct impl_ICoreWetStrokeUpdateSourceStatics;

}

namespace Windows::UI::Input::Inking::Core {

enum class CoreWetStrokeDisposition
{
    Inking = 0,
    Completed = 1,
    Canceled = 2,
};

}

}
