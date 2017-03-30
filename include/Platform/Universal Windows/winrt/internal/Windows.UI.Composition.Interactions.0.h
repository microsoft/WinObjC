// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Composition::Interactions {

struct ICompositionInteractionSource;
struct ICompositionInteractionSourceCollection;
struct IInteractionTracker;
struct IInteractionTrackerCustomAnimationStateEnteredArgs;
struct IInteractionTrackerIdleStateEnteredArgs;
struct IInteractionTrackerInertiaModifier;
struct IInteractionTrackerInertiaModifierFactory;
struct IInteractionTrackerInertiaMotion;
struct IInteractionTrackerInertiaMotionStatics;
struct IInteractionTrackerInertiaRestingValue;
struct IInteractionTrackerInertiaRestingValueStatics;
struct IInteractionTrackerInertiaStateEnteredArgs;
struct IInteractionTrackerInteractingStateEnteredArgs;
struct IInteractionTrackerOwner;
struct IInteractionTrackerRequestIgnoredArgs;
struct IInteractionTrackerStatics;
struct IInteractionTrackerValuesChangedArgs;
struct IVisualInteractionSource;
struct IVisualInteractionSourceStatics;
struct CompositionInteractionSourceCollection;
struct InteractionTracker;
struct InteractionTrackerCustomAnimationStateEnteredArgs;
struct InteractionTrackerIdleStateEnteredArgs;
struct InteractionTrackerInertiaModifier;
struct InteractionTrackerInertiaMotion;
struct InteractionTrackerInertiaRestingValue;
struct InteractionTrackerInertiaStateEnteredArgs;
struct InteractionTrackerInteractingStateEnteredArgs;
struct InteractionTrackerRequestIgnoredArgs;
struct InteractionTrackerValuesChangedArgs;
struct VisualInteractionSource;

}

namespace Windows::UI::Composition::Interactions {

struct ICompositionInteractionSource;
struct ICompositionInteractionSourceCollection;
struct IInteractionTracker;
struct IInteractionTrackerCustomAnimationStateEnteredArgs;
struct IInteractionTrackerIdleStateEnteredArgs;
struct IInteractionTrackerInertiaModifier;
struct IInteractionTrackerInertiaModifierFactory;
struct IInteractionTrackerInertiaMotion;
struct IInteractionTrackerInertiaMotionStatics;
struct IInteractionTrackerInertiaRestingValue;
struct IInteractionTrackerInertiaRestingValueStatics;
struct IInteractionTrackerInertiaStateEnteredArgs;
struct IInteractionTrackerInteractingStateEnteredArgs;
struct IInteractionTrackerOwner;
struct IInteractionTrackerRequestIgnoredArgs;
struct IInteractionTrackerStatics;
struct IInteractionTrackerValuesChangedArgs;
struct IVisualInteractionSource;
struct IVisualInteractionSourceStatics;
struct CompositionInteractionSourceCollection;
struct InteractionTracker;
struct InteractionTrackerCustomAnimationStateEnteredArgs;
struct InteractionTrackerIdleStateEnteredArgs;
struct InteractionTrackerInertiaModifier;
struct InteractionTrackerInertiaMotion;
struct InteractionTrackerInertiaRestingValue;
struct InteractionTrackerInertiaStateEnteredArgs;
struct InteractionTrackerInteractingStateEnteredArgs;
struct InteractionTrackerRequestIgnoredArgs;
struct InteractionTrackerValuesChangedArgs;
struct VisualInteractionSource;

}

namespace Windows::UI::Composition::Interactions {

template <typename T> struct impl_ICompositionInteractionSource;
template <typename T> struct impl_ICompositionInteractionSourceCollection;
template <typename T> struct impl_IInteractionTracker;
template <typename T> struct impl_IInteractionTrackerCustomAnimationStateEnteredArgs;
template <typename T> struct impl_IInteractionTrackerIdleStateEnteredArgs;
template <typename T> struct impl_IInteractionTrackerInertiaModifier;
template <typename T> struct impl_IInteractionTrackerInertiaModifierFactory;
template <typename T> struct impl_IInteractionTrackerInertiaMotion;
template <typename T> struct impl_IInteractionTrackerInertiaMotionStatics;
template <typename T> struct impl_IInteractionTrackerInertiaRestingValue;
template <typename T> struct impl_IInteractionTrackerInertiaRestingValueStatics;
template <typename T> struct impl_IInteractionTrackerInertiaStateEnteredArgs;
template <typename T> struct impl_IInteractionTrackerInteractingStateEnteredArgs;
template <typename T> struct impl_IInteractionTrackerOwner;
template <typename T> struct impl_IInteractionTrackerRequestIgnoredArgs;
template <typename T> struct impl_IInteractionTrackerStatics;
template <typename T> struct impl_IInteractionTrackerValuesChangedArgs;
template <typename T> struct impl_IVisualInteractionSource;
template <typename T> struct impl_IVisualInteractionSourceStatics;

}

namespace Windows::UI::Composition::Interactions {

enum class InteractionChainingMode
{
    Auto = 0,
    Always = 1,
    Never = 2,
};

enum class InteractionSourceMode
{
    Disabled = 0,
    EnabledWithInertia = 1,
    EnabledWithoutInertia = 2,
};

enum class VisualInteractionSourceRedirectionMode
{
    Off = 0,
    CapableTouchpadOnly = 1,
};

}

}
