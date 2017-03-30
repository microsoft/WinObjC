// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Core.AnimationMetrics.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Core::AnimationMetrics {

struct __declspec(uuid("7d11a549-be3d-41de-b081-05c149962f9b")) __declspec(novtable) IAnimationDescription : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Animations(Windows::Foundation::Collections::IVectorView<Windows::UI::Core::AnimationMetrics::IPropertyAnimation> ** value) = 0;
    virtual HRESULT __stdcall get_StaggerDelay(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_StaggerDelayFactor(float * value) = 0;
    virtual HRESULT __stdcall get_DelayLimit(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_ZOrder(int32_t * value) = 0;
};

struct __declspec(uuid("c6e27abe-c1fb-48b5-9271-ecc70ac86ef0")) __declspec(novtable) IAnimationDescriptionFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(winrt::Windows::UI::Core::AnimationMetrics::AnimationEffect effect, winrt::Windows::UI::Core::AnimationMetrics::AnimationEffectTarget target, Windows::UI::Core::AnimationMetrics::IAnimationDescription ** animation) = 0;
};

struct __declspec(uuid("803aabe5-ee7e-455f-84e9-2506afb8d2b4")) __declspec(novtable) IOpacityAnimation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InitialOpacity(Windows::Foundation::IReference<float> ** value) = 0;
    virtual HRESULT __stdcall get_FinalOpacity(float * value) = 0;
};

struct __declspec(uuid("3a01b4da-4d8c-411e-b615-1ade683a9903")) __declspec(novtable) IPropertyAnimation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Type(winrt::Windows::UI::Core::AnimationMetrics::PropertyAnimationType * value) = 0;
    virtual HRESULT __stdcall get_Delay(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Duration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Control1(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_Control2(Windows::Foundation::Point * value) = 0;
};

struct __declspec(uuid("023552c7-71ab-428c-9c9f-d31780964995")) __declspec(novtable) IScaleAnimation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InitialScaleX(Windows::Foundation::IReference<float> ** value) = 0;
    virtual HRESULT __stdcall get_InitialScaleY(Windows::Foundation::IReference<float> ** value) = 0;
    virtual HRESULT __stdcall get_FinalScaleX(float * value) = 0;
    virtual HRESULT __stdcall get_FinalScaleY(float * value) = 0;
    virtual HRESULT __stdcall get_NormalizedOrigin(Windows::Foundation::Point * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Core::AnimationMetrics::AnimationDescription> { using default_interface = Windows::UI::Core::AnimationMetrics::IAnimationDescription; };
template <> struct traits<Windows::UI::Core::AnimationMetrics::OpacityAnimation> { using default_interface = Windows::UI::Core::AnimationMetrics::IOpacityAnimation; };
template <> struct traits<Windows::UI::Core::AnimationMetrics::PropertyAnimation> { using default_interface = Windows::UI::Core::AnimationMetrics::IPropertyAnimation; };
template <> struct traits<Windows::UI::Core::AnimationMetrics::ScaleAnimation> { using default_interface = Windows::UI::Core::AnimationMetrics::IScaleAnimation; };
template <> struct traits<Windows::UI::Core::AnimationMetrics::TranslationAnimation> { using default_interface = Windows::UI::Core::AnimationMetrics::IPropertyAnimation; };

}

namespace Windows::UI::Core::AnimationMetrics {

template <typename D>
struct WINRT_EBO impl_IAnimationDescription
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Core::AnimationMetrics::IPropertyAnimation> Animations() const;
    Windows::Foundation::TimeSpan StaggerDelay() const;
    float StaggerDelayFactor() const;
    Windows::Foundation::TimeSpan DelayLimit() const;
    int32_t ZOrder() const;
};

template <typename D>
struct WINRT_EBO impl_IAnimationDescriptionFactory
{
    Windows::UI::Core::AnimationMetrics::AnimationDescription CreateInstance(Windows::UI::Core::AnimationMetrics::AnimationEffect effect, Windows::UI::Core::AnimationMetrics::AnimationEffectTarget target) const;
};

template <typename D>
struct WINRT_EBO impl_IOpacityAnimation
{
    Windows::Foundation::IReference<float> InitialOpacity() const;
    float FinalOpacity() const;
};

template <typename D>
struct WINRT_EBO impl_IPropertyAnimation
{
    Windows::UI::Core::AnimationMetrics::PropertyAnimationType Type() const;
    Windows::Foundation::TimeSpan Delay() const;
    Windows::Foundation::TimeSpan Duration() const;
    Windows::Foundation::Point Control1() const;
    Windows::Foundation::Point Control2() const;
};

template <typename D>
struct WINRT_EBO impl_IScaleAnimation
{
    Windows::Foundation::IReference<float> InitialScaleX() const;
    Windows::Foundation::IReference<float> InitialScaleY() const;
    float FinalScaleX() const;
    float FinalScaleY() const;
    Windows::Foundation::Point NormalizedOrigin() const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Core::AnimationMetrics::IAnimationDescription>
{
    using abi = ABI::Windows::UI::Core::AnimationMetrics::IAnimationDescription;
    template <typename D> using consume = Windows::UI::Core::AnimationMetrics::impl_IAnimationDescription<D>;
};

template <> struct traits<Windows::UI::Core::AnimationMetrics::IAnimationDescriptionFactory>
{
    using abi = ABI::Windows::UI::Core::AnimationMetrics::IAnimationDescriptionFactory;
    template <typename D> using consume = Windows::UI::Core::AnimationMetrics::impl_IAnimationDescriptionFactory<D>;
};

template <> struct traits<Windows::UI::Core::AnimationMetrics::IOpacityAnimation>
{
    using abi = ABI::Windows::UI::Core::AnimationMetrics::IOpacityAnimation;
    template <typename D> using consume = Windows::UI::Core::AnimationMetrics::impl_IOpacityAnimation<D>;
};

template <> struct traits<Windows::UI::Core::AnimationMetrics::IPropertyAnimation>
{
    using abi = ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation;
    template <typename D> using consume = Windows::UI::Core::AnimationMetrics::impl_IPropertyAnimation<D>;
};

template <> struct traits<Windows::UI::Core::AnimationMetrics::IScaleAnimation>
{
    using abi = ABI::Windows::UI::Core::AnimationMetrics::IScaleAnimation;
    template <typename D> using consume = Windows::UI::Core::AnimationMetrics::impl_IScaleAnimation<D>;
};

template <> struct traits<Windows::UI::Core::AnimationMetrics::AnimationDescription>
{
    using abi = ABI::Windows::UI::Core::AnimationMetrics::AnimationDescription;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.AnimationMetrics.AnimationDescription"; }
};

template <> struct traits<Windows::UI::Core::AnimationMetrics::OpacityAnimation>
{
    using abi = ABI::Windows::UI::Core::AnimationMetrics::OpacityAnimation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.AnimationMetrics.OpacityAnimation"; }
};

template <> struct traits<Windows::UI::Core::AnimationMetrics::PropertyAnimation>
{
    using abi = ABI::Windows::UI::Core::AnimationMetrics::PropertyAnimation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.AnimationMetrics.PropertyAnimation"; }
};

template <> struct traits<Windows::UI::Core::AnimationMetrics::ScaleAnimation>
{
    using abi = ABI::Windows::UI::Core::AnimationMetrics::ScaleAnimation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.AnimationMetrics.ScaleAnimation"; }
};

template <> struct traits<Windows::UI::Core::AnimationMetrics::TranslationAnimation>
{
    using abi = ABI::Windows::UI::Core::AnimationMetrics::TranslationAnimation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Core.AnimationMetrics.TranslationAnimation"; }
};

}

}
