// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Composition.Interactions.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Composition::Interactions {

struct WINRT_EBO CompositionInteractionSourceCollection :
    Windows::UI::Composition::Interactions::ICompositionInteractionSourceCollection,
    impl::bases<CompositionInteractionSourceCollection, Windows::UI::Composition::CompositionObject>,
    impl::require<CompositionInteractionSourceCollection, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionInteractionSourceCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InteractionTracker :
    Windows::UI::Composition::Interactions::IInteractionTracker,
    impl::bases<InteractionTracker, Windows::UI::Composition::CompositionObject>,
    impl::require<InteractionTracker, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    InteractionTracker(std::nullptr_t) noexcept {}
    static Windows::UI::Composition::Interactions::InteractionTracker Create(const Windows::UI::Composition::Compositor & compositor);
    static Windows::UI::Composition::Interactions::InteractionTracker CreateWithOwner(const Windows::UI::Composition::Compositor & compositor, const Windows::UI::Composition::Interactions::IInteractionTrackerOwner & owner);
};

struct WINRT_EBO InteractionTrackerCustomAnimationStateEnteredArgs :
    Windows::UI::Composition::Interactions::IInteractionTrackerCustomAnimationStateEnteredArgs
{
    InteractionTrackerCustomAnimationStateEnteredArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InteractionTrackerIdleStateEnteredArgs :
    Windows::UI::Composition::Interactions::IInteractionTrackerIdleStateEnteredArgs
{
    InteractionTrackerIdleStateEnteredArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InteractionTrackerInertiaModifier :
    Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifier,
    impl::bases<InteractionTrackerInertiaModifier, Windows::UI::Composition::CompositionObject>,
    impl::require<InteractionTrackerInertiaModifier, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    InteractionTrackerInertiaModifier(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InteractionTrackerInertiaMotion :
    Windows::UI::Composition::Interactions::IInteractionTrackerInertiaMotion,
    impl::bases<InteractionTrackerInertiaMotion, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier>,
    impl::require<InteractionTrackerInertiaMotion, Windows::Foundation::IClosable, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifier, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    InteractionTrackerInertiaMotion(std::nullptr_t) noexcept {}
    static Windows::UI::Composition::Interactions::InteractionTrackerInertiaMotion Create(const Windows::UI::Composition::Compositor & compositor);
};

struct WINRT_EBO InteractionTrackerInertiaRestingValue :
    Windows::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValue,
    impl::bases<InteractionTrackerInertiaRestingValue, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier>,
    impl::require<InteractionTrackerInertiaRestingValue, Windows::Foundation::IClosable, Windows::UI::Composition::Interactions::IInteractionTrackerInertiaModifier, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    InteractionTrackerInertiaRestingValue(std::nullptr_t) noexcept {}
    static Windows::UI::Composition::Interactions::InteractionTrackerInertiaRestingValue Create(const Windows::UI::Composition::Compositor & compositor);
};

struct WINRT_EBO InteractionTrackerInertiaStateEnteredArgs :
    Windows::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs
{
    InteractionTrackerInertiaStateEnteredArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InteractionTrackerInteractingStateEnteredArgs :
    Windows::UI::Composition::Interactions::IInteractionTrackerInteractingStateEnteredArgs
{
    InteractionTrackerInteractingStateEnteredArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InteractionTrackerRequestIgnoredArgs :
    Windows::UI::Composition::Interactions::IInteractionTrackerRequestIgnoredArgs
{
    InteractionTrackerRequestIgnoredArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InteractionTrackerValuesChangedArgs :
    Windows::UI::Composition::Interactions::IInteractionTrackerValuesChangedArgs
{
    InteractionTrackerValuesChangedArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VisualInteractionSource :
    Windows::UI::Composition::Interactions::IVisualInteractionSource,
    impl::bases<VisualInteractionSource, Windows::UI::Composition::CompositionObject>,
    impl::require<VisualInteractionSource, Windows::Foundation::IClosable, Windows::UI::Composition::Interactions::ICompositionInteractionSource, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    VisualInteractionSource(std::nullptr_t) noexcept {}
    static Windows::UI::Composition::Interactions::VisualInteractionSource Create(const Windows::UI::Composition::Visual & source);
};

}

}
