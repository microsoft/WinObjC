// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Input.Spatial.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Input::Spatial {

struct WINRT_EBO SpatialGestureRecognizer :
    Windows::UI::Input::Spatial::ISpatialGestureRecognizer
{
    SpatialGestureRecognizer(std::nullptr_t) noexcept {}
    SpatialGestureRecognizer(Windows::UI::Input::Spatial::SpatialGestureSettings settings);
};

struct WINRT_EBO SpatialHoldCanceledEventArgs :
    Windows::UI::Input::Spatial::ISpatialHoldCanceledEventArgs
{
    SpatialHoldCanceledEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialHoldCompletedEventArgs :
    Windows::UI::Input::Spatial::ISpatialHoldCompletedEventArgs
{
    SpatialHoldCompletedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialHoldStartedEventArgs :
    Windows::UI::Input::Spatial::ISpatialHoldStartedEventArgs
{
    SpatialHoldStartedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialInteraction :
    Windows::UI::Input::Spatial::ISpatialInteraction
{
    SpatialInteraction(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialInteractionDetectedEventArgs :
    Windows::UI::Input::Spatial::ISpatialInteractionDetectedEventArgs
{
    SpatialInteractionDetectedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialInteractionManager :
    Windows::UI::Input::Spatial::ISpatialInteractionManager
{
    SpatialInteractionManager(std::nullptr_t) noexcept {}
    static Windows::UI::Input::Spatial::SpatialInteractionManager GetForCurrentView();
};

struct WINRT_EBO SpatialInteractionSource :
    Windows::UI::Input::Spatial::ISpatialInteractionSource
{
    SpatialInteractionSource(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialInteractionSourceEventArgs :
    Windows::UI::Input::Spatial::ISpatialInteractionSourceEventArgs
{
    SpatialInteractionSourceEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialInteractionSourceLocation :
    Windows::UI::Input::Spatial::ISpatialInteractionSourceLocation,
    impl::require<SpatialInteractionSourceLocation, Windows::UI::Input::Spatial::ISpatialInteractionSourceLocation2>
{
    SpatialInteractionSourceLocation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialInteractionSourceProperties :
    Windows::UI::Input::Spatial::ISpatialInteractionSourceProperties
{
    SpatialInteractionSourceProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialInteractionSourceState :
    Windows::UI::Input::Spatial::ISpatialInteractionSourceState
{
    SpatialInteractionSourceState(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialManipulationCanceledEventArgs :
    Windows::UI::Input::Spatial::ISpatialManipulationCanceledEventArgs
{
    SpatialManipulationCanceledEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialManipulationCompletedEventArgs :
    Windows::UI::Input::Spatial::ISpatialManipulationCompletedEventArgs
{
    SpatialManipulationCompletedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialManipulationDelta :
    Windows::UI::Input::Spatial::ISpatialManipulationDelta
{
    SpatialManipulationDelta(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialManipulationStartedEventArgs :
    Windows::UI::Input::Spatial::ISpatialManipulationStartedEventArgs
{
    SpatialManipulationStartedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialManipulationUpdatedEventArgs :
    Windows::UI::Input::Spatial::ISpatialManipulationUpdatedEventArgs
{
    SpatialManipulationUpdatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialNavigationCanceledEventArgs :
    Windows::UI::Input::Spatial::ISpatialNavigationCanceledEventArgs
{
    SpatialNavigationCanceledEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialNavigationCompletedEventArgs :
    Windows::UI::Input::Spatial::ISpatialNavigationCompletedEventArgs
{
    SpatialNavigationCompletedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialNavigationStartedEventArgs :
    Windows::UI::Input::Spatial::ISpatialNavigationStartedEventArgs
{
    SpatialNavigationStartedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialNavigationUpdatedEventArgs :
    Windows::UI::Input::Spatial::ISpatialNavigationUpdatedEventArgs
{
    SpatialNavigationUpdatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialPointerPose :
    Windows::UI::Input::Spatial::ISpatialPointerPose
{
    SpatialPointerPose(std::nullptr_t) noexcept {}
    static Windows::UI::Input::Spatial::SpatialPointerPose TryGetAtTimestamp(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Perception::PerceptionTimestamp & timestamp);
};

struct WINRT_EBO SpatialRecognitionEndedEventArgs :
    Windows::UI::Input::Spatial::ISpatialRecognitionEndedEventArgs
{
    SpatialRecognitionEndedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialRecognitionStartedEventArgs :
    Windows::UI::Input::Spatial::ISpatialRecognitionStartedEventArgs
{
    SpatialRecognitionStartedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialTappedEventArgs :
    Windows::UI::Input::Spatial::ISpatialTappedEventArgs
{
    SpatialTappedEventArgs(std::nullptr_t) noexcept {}
};

}

}
