// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Composition.Interactions.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.UI.Composition.1.h"
#include "Windows.UI.Composition.2.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_719cc2ba_3e76_5def_9f1a_38d85a145ea8
#define WINRT_GENERIC_719cc2ba_3e76_5def_9f1a_38d85a145ea8
template <> struct __declspec(uuid("719cc2ba-3e76-5def-9f1a-38d85a145ea8")) __declspec(novtable) IReference<float> : impl_IReference<float> {};
#endif

#ifndef WINRT_GENERIC_1ee770ff_c954_59ca_a754_6199a9be282c
#define WINRT_GENERIC_1ee770ff_c954_59ca_a754_6199a9be282c
template <> struct __declspec(uuid("1ee770ff-c954-59ca-a754-6199a9be282c")) __declspec(novtable) IReference<Windows::Foundation::Numerics::float3> : impl_IReference<Windows::Foundation::Numerics::float3> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_17c50e21_cb70_5a2b_b797_a8dc01a99113
#define WINRT_GENERIC_17c50e21_cb70_5a2b_b797_a8dc01a99113
template <> struct __declspec(uuid("17c50e21-cb70-5a2b-b797-a8dc01a99113")) __declspec(novtable) IIterable<Windows::UI::Composition::Interactions::ICompositionInteractionSource> : impl_IIterable<Windows::UI::Composition::Interactions::ICompositionInteractionSource> {};
#endif

#ifndef WINRT_GENERIC_9a245c40_aae6_59fb_87f5_4bb05599f0b1
#define WINRT_GENERIC_9a245c40_aae6_59fb_87f5_4bb05599f0b1
template <> struct __declspec(uuid("9a245c40-aae6-59fb-87f5-4bb05599f0b1")) __declspec(novtable) IIterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> : impl_IIterable<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> {};
#endif

#ifndef WINRT_GENERIC_20259ef3_9f4b_5257_8581_6d3eabbbd690
#define WINRT_GENERIC_20259ef3_9f4b_5257_8581_6d3eabbbd690
template <> struct __declspec(uuid("20259ef3-9f4b-5257-8581-6d3eabbbd690")) __declspec(novtable) IIterator<Windows::UI::Composition::Interactions::ICompositionInteractionSource> : impl_IIterator<Windows::UI::Composition::Interactions::ICompositionInteractionSource> {};
#endif

#ifndef WINRT_GENERIC_46617d87_2cd2_5e31_9a30_ea86f8aa7ca1
#define WINRT_GENERIC_46617d87_2cd2_5e31_9a30_ea86f8aa7ca1
template <> struct __declspec(uuid("46617d87-2cd2-5e31-9a30-ea86f8aa7ca1")) __declspec(novtable) IIterator<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> : impl_IIterator<Windows::UI::Composition::Interactions::InteractionTrackerInertiaModifier> {};
#endif


}

namespace Windows::UI::Composition::Interactions {

struct ICompositionInteractionSource :
    Windows::Foundation::IInspectable,
    impl::consume<ICompositionInteractionSource>
{
    ICompositionInteractionSource(std::nullptr_t = nullptr) noexcept {}
};

struct ICompositionInteractionSourceCollection :
    Windows::Foundation::IInspectable,
    impl::consume<ICompositionInteractionSourceCollection>,
    impl::require<ICompositionInteractionSourceCollection, Windows::Foundation::Collections::IIterable<Windows::UI::Composition::Interactions::ICompositionInteractionSource>>
{
    ICompositionInteractionSourceCollection(std::nullptr_t = nullptr) noexcept {}
};

struct IInteractionTracker :
    Windows::Foundation::IInspectable,
    impl::consume<IInteractionTracker>
{
    IInteractionTracker(std::nullptr_t = nullptr) noexcept {}
};

struct IInteractionTrackerCustomAnimationStateEnteredArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IInteractionTrackerCustomAnimationStateEnteredArgs>
{
    IInteractionTrackerCustomAnimationStateEnteredArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IInteractionTrackerIdleStateEnteredArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IInteractionTrackerIdleStateEnteredArgs>
{
    IInteractionTrackerIdleStateEnteredArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IInteractionTrackerInertiaModifier :
    Windows::Foundation::IInspectable,
    impl::consume<IInteractionTrackerInertiaModifier>
{
    IInteractionTrackerInertiaModifier(std::nullptr_t = nullptr) noexcept {}
};

struct IInteractionTrackerInertiaModifierFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IInteractionTrackerInertiaModifierFactory>
{
    IInteractionTrackerInertiaModifierFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IInteractionTrackerInertiaMotion :
    Windows::Foundation::IInspectable,
    impl::consume<IInteractionTrackerInertiaMotion>
{
    IInteractionTrackerInertiaMotion(std::nullptr_t = nullptr) noexcept {}
};

struct IInteractionTrackerInertiaMotionStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IInteractionTrackerInertiaMotionStatics>
{
    IInteractionTrackerInertiaMotionStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IInteractionTrackerInertiaRestingValue :
    Windows::Foundation::IInspectable,
    impl::consume<IInteractionTrackerInertiaRestingValue>
{
    IInteractionTrackerInertiaRestingValue(std::nullptr_t = nullptr) noexcept {}
};

struct IInteractionTrackerInertiaRestingValueStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IInteractionTrackerInertiaRestingValueStatics>
{
    IInteractionTrackerInertiaRestingValueStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IInteractionTrackerInertiaStateEnteredArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IInteractionTrackerInertiaStateEnteredArgs>
{
    IInteractionTrackerInertiaStateEnteredArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IInteractionTrackerInteractingStateEnteredArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IInteractionTrackerInteractingStateEnteredArgs>
{
    IInteractionTrackerInteractingStateEnteredArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IInteractionTrackerOwner :
    Windows::Foundation::IInspectable,
    impl::consume<IInteractionTrackerOwner>
{
    IInteractionTrackerOwner(std::nullptr_t = nullptr) noexcept {}
};

struct IInteractionTrackerRequestIgnoredArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IInteractionTrackerRequestIgnoredArgs>
{
    IInteractionTrackerRequestIgnoredArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IInteractionTrackerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IInteractionTrackerStatics>
{
    IInteractionTrackerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IInteractionTrackerValuesChangedArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IInteractionTrackerValuesChangedArgs>
{
    IInteractionTrackerValuesChangedArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IVisualInteractionSource :
    Windows::Foundation::IInspectable,
    impl::consume<IVisualInteractionSource>
{
    IVisualInteractionSource(std::nullptr_t = nullptr) noexcept {}
};

struct IVisualInteractionSourceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IVisualInteractionSourceStatics>
{
    IVisualInteractionSourceStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
