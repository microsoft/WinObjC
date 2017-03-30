// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Core.AnimationMetrics.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_719cc2ba_3e76_5def_9f1a_38d85a145ea8
#define WINRT_GENERIC_719cc2ba_3e76_5def_9f1a_38d85a145ea8
template <> struct __declspec(uuid("719cc2ba-3e76-5def-9f1a-38d85a145ea8")) __declspec(novtable) IReference<float> : impl_IReference<float> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_3a6ed95d_6a50_5ead_a4c6_09f8babc632c
#define WINRT_GENERIC_3a6ed95d_6a50_5ead_a4c6_09f8babc632c
template <> struct __declspec(uuid("3a6ed95d-6a50-5ead-a4c6-09f8babc632c")) __declspec(novtable) IVectorView<Windows::UI::Core::AnimationMetrics::IPropertyAnimation> : impl_IVectorView<Windows::UI::Core::AnimationMetrics::IPropertyAnimation> {};
#endif

#ifndef WINRT_GENERIC_bb6799d3_9f1a_5a4e_a940_945f1ab8c4fe
#define WINRT_GENERIC_bb6799d3_9f1a_5a4e_a940_945f1ab8c4fe
template <> struct __declspec(uuid("bb6799d3-9f1a-5a4e-a940-945f1ab8c4fe")) __declspec(novtable) IIterator<Windows::UI::Core::AnimationMetrics::IPropertyAnimation> : impl_IIterator<Windows::UI::Core::AnimationMetrics::IPropertyAnimation> {};
#endif

#ifndef WINRT_GENERIC_c75f1bd1_a3c1_5881_9da0_1ecdb8e51bc3
#define WINRT_GENERIC_c75f1bd1_a3c1_5881_9da0_1ecdb8e51bc3
template <> struct __declspec(uuid("c75f1bd1-a3c1-5881-9da0-1ecdb8e51bc3")) __declspec(novtable) IIterable<Windows::UI::Core::AnimationMetrics::IPropertyAnimation> : impl_IIterable<Windows::UI::Core::AnimationMetrics::IPropertyAnimation> {};
#endif


}

namespace Windows::UI::Core::AnimationMetrics {

struct IAnimationDescription :
    Windows::Foundation::IInspectable,
    impl::consume<IAnimationDescription>
{
    IAnimationDescription(std::nullptr_t = nullptr) noexcept {}
};

struct IAnimationDescriptionFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IAnimationDescriptionFactory>
{
    IAnimationDescriptionFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IOpacityAnimation :
    Windows::Foundation::IInspectable,
    impl::consume<IOpacityAnimation>,
    impl::require<IOpacityAnimation, Windows::UI::Core::AnimationMetrics::IPropertyAnimation>
{
    IOpacityAnimation(std::nullptr_t = nullptr) noexcept {}
};

struct IPropertyAnimation :
    Windows::Foundation::IInspectable,
    impl::consume<IPropertyAnimation>
{
    IPropertyAnimation(std::nullptr_t = nullptr) noexcept {}
};

struct IScaleAnimation :
    Windows::Foundation::IInspectable,
    impl::consume<IScaleAnimation>,
    impl::require<IScaleAnimation, Windows::UI::Core::AnimationMetrics::IPropertyAnimation>
{
    IScaleAnimation(std::nullptr_t = nullptr) noexcept {}
};

}

}
