// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Input::Spatial {

struct ISpatialGestureRecognizer;
struct ISpatialGestureRecognizerFactory;
struct ISpatialHoldCanceledEventArgs;
struct ISpatialHoldCompletedEventArgs;
struct ISpatialHoldStartedEventArgs;
struct ISpatialInteraction;
struct ISpatialInteractionDetectedEventArgs;
struct ISpatialInteractionManager;
struct ISpatialInteractionManagerStatics;
struct ISpatialInteractionSource;
struct ISpatialInteractionSourceEventArgs;
struct ISpatialInteractionSourceLocation;
struct ISpatialInteractionSourceLocation2;
struct ISpatialInteractionSourceProperties;
struct ISpatialInteractionSourceState;
struct ISpatialManipulationCanceledEventArgs;
struct ISpatialManipulationCompletedEventArgs;
struct ISpatialManipulationDelta;
struct ISpatialManipulationStartedEventArgs;
struct ISpatialManipulationUpdatedEventArgs;
struct ISpatialNavigationCanceledEventArgs;
struct ISpatialNavigationCompletedEventArgs;
struct ISpatialNavigationStartedEventArgs;
struct ISpatialNavigationUpdatedEventArgs;
struct ISpatialPointerPose;
struct ISpatialPointerPoseStatics;
struct ISpatialRecognitionEndedEventArgs;
struct ISpatialRecognitionStartedEventArgs;
struct ISpatialTappedEventArgs;
struct SpatialGestureRecognizer;
struct SpatialHoldCanceledEventArgs;
struct SpatialHoldCompletedEventArgs;
struct SpatialHoldStartedEventArgs;
struct SpatialInteraction;
struct SpatialInteractionDetectedEventArgs;
struct SpatialInteractionManager;
struct SpatialInteractionSource;
struct SpatialInteractionSourceEventArgs;
struct SpatialInteractionSourceLocation;
struct SpatialInteractionSourceProperties;
struct SpatialInteractionSourceState;
struct SpatialManipulationCanceledEventArgs;
struct SpatialManipulationCompletedEventArgs;
struct SpatialManipulationDelta;
struct SpatialManipulationStartedEventArgs;
struct SpatialManipulationUpdatedEventArgs;
struct SpatialNavigationCanceledEventArgs;
struct SpatialNavigationCompletedEventArgs;
struct SpatialNavigationStartedEventArgs;
struct SpatialNavigationUpdatedEventArgs;
struct SpatialPointerPose;
struct SpatialRecognitionEndedEventArgs;
struct SpatialRecognitionStartedEventArgs;
struct SpatialTappedEventArgs;

}

namespace Windows::UI::Input::Spatial {

struct ISpatialGestureRecognizer;
struct ISpatialGestureRecognizerFactory;
struct ISpatialHoldCanceledEventArgs;
struct ISpatialHoldCompletedEventArgs;
struct ISpatialHoldStartedEventArgs;
struct ISpatialInteraction;
struct ISpatialInteractionDetectedEventArgs;
struct ISpatialInteractionManager;
struct ISpatialInteractionManagerStatics;
struct ISpatialInteractionSource;
struct ISpatialInteractionSourceEventArgs;
struct ISpatialInteractionSourceLocation;
struct ISpatialInteractionSourceLocation2;
struct ISpatialInteractionSourceProperties;
struct ISpatialInteractionSourceState;
struct ISpatialManipulationCanceledEventArgs;
struct ISpatialManipulationCompletedEventArgs;
struct ISpatialManipulationDelta;
struct ISpatialManipulationStartedEventArgs;
struct ISpatialManipulationUpdatedEventArgs;
struct ISpatialNavigationCanceledEventArgs;
struct ISpatialNavigationCompletedEventArgs;
struct ISpatialNavigationStartedEventArgs;
struct ISpatialNavigationUpdatedEventArgs;
struct ISpatialPointerPose;
struct ISpatialPointerPoseStatics;
struct ISpatialRecognitionEndedEventArgs;
struct ISpatialRecognitionStartedEventArgs;
struct ISpatialTappedEventArgs;
struct SpatialGestureRecognizer;
struct SpatialHoldCanceledEventArgs;
struct SpatialHoldCompletedEventArgs;
struct SpatialHoldStartedEventArgs;
struct SpatialInteraction;
struct SpatialInteractionDetectedEventArgs;
struct SpatialInteractionManager;
struct SpatialInteractionSource;
struct SpatialInteractionSourceEventArgs;
struct SpatialInteractionSourceLocation;
struct SpatialInteractionSourceProperties;
struct SpatialInteractionSourceState;
struct SpatialManipulationCanceledEventArgs;
struct SpatialManipulationCompletedEventArgs;
struct SpatialManipulationDelta;
struct SpatialManipulationStartedEventArgs;
struct SpatialManipulationUpdatedEventArgs;
struct SpatialNavigationCanceledEventArgs;
struct SpatialNavigationCompletedEventArgs;
struct SpatialNavigationStartedEventArgs;
struct SpatialNavigationUpdatedEventArgs;
struct SpatialPointerPose;
struct SpatialRecognitionEndedEventArgs;
struct SpatialRecognitionStartedEventArgs;
struct SpatialTappedEventArgs;

}

namespace Windows::UI::Input::Spatial {

template <typename T> struct impl_ISpatialGestureRecognizer;
template <typename T> struct impl_ISpatialGestureRecognizerFactory;
template <typename T> struct impl_ISpatialHoldCanceledEventArgs;
template <typename T> struct impl_ISpatialHoldCompletedEventArgs;
template <typename T> struct impl_ISpatialHoldStartedEventArgs;
template <typename T> struct impl_ISpatialInteraction;
template <typename T> struct impl_ISpatialInteractionDetectedEventArgs;
template <typename T> struct impl_ISpatialInteractionManager;
template <typename T> struct impl_ISpatialInteractionManagerStatics;
template <typename T> struct impl_ISpatialInteractionSource;
template <typename T> struct impl_ISpatialInteractionSourceEventArgs;
template <typename T> struct impl_ISpatialInteractionSourceLocation;
template <typename T> struct impl_ISpatialInteractionSourceLocation2;
template <typename T> struct impl_ISpatialInteractionSourceProperties;
template <typename T> struct impl_ISpatialInteractionSourceState;
template <typename T> struct impl_ISpatialManipulationCanceledEventArgs;
template <typename T> struct impl_ISpatialManipulationCompletedEventArgs;
template <typename T> struct impl_ISpatialManipulationDelta;
template <typename T> struct impl_ISpatialManipulationStartedEventArgs;
template <typename T> struct impl_ISpatialManipulationUpdatedEventArgs;
template <typename T> struct impl_ISpatialNavigationCanceledEventArgs;
template <typename T> struct impl_ISpatialNavigationCompletedEventArgs;
template <typename T> struct impl_ISpatialNavigationStartedEventArgs;
template <typename T> struct impl_ISpatialNavigationUpdatedEventArgs;
template <typename T> struct impl_ISpatialPointerPose;
template <typename T> struct impl_ISpatialPointerPoseStatics;
template <typename T> struct impl_ISpatialRecognitionEndedEventArgs;
template <typename T> struct impl_ISpatialRecognitionStartedEventArgs;
template <typename T> struct impl_ISpatialTappedEventArgs;

}

namespace Windows::UI::Input::Spatial {

enum class SpatialGestureSettings : unsigned
{
    None = 0x0,
    Tap = 0x1,
    DoubleTap = 0x2,
    Hold = 0x4,
    ManipulationTranslate = 0x8,
    NavigationX = 0x10,
    NavigationY = 0x20,
    NavigationZ = 0x40,
    NavigationRailsX = 0x80,
    NavigationRailsY = 0x100,
    NavigationRailsZ = 0x200,
};

DEFINE_ENUM_FLAG_OPERATORS(SpatialGestureSettings)

enum class SpatialInteractionSourceKind
{
    Other = 0,
    Hand = 1,
    Voice = 2,
    Controller = 3,
};

}

}
