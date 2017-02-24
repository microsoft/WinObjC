// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.UI.Xaml.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.Xaml.Controls.Primitives.3.h"
#include "internal/Windows.UI.Composition.3.h"
#include "internal/Windows.UI.Xaml.Controls.3.h"
#include "internal/Windows.UI.Xaml.Media.Animation.3.h"
#include "Windows.UI.Xaml.Media.h"
#include "Windows.Foundation.Collections.h"
#include "internal/Windows.UI.Xaml.Media.Animation.4.h"
#include "internal/Windows.UI.Xaml.Media.Animation.5.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IAddDeleteThemeTransition> : produce_base<D, Windows::UI::Xaml::Media::Animation::IAddDeleteThemeTransition>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IBackEase> : produce_base<D, Windows::UI::Xaml::Media::Animation::IBackEase>
{
    HRESULT __stdcall get_Amplitude(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Amplitude());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Amplitude(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Amplitude(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IBackEaseStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IBackEaseStatics>
{
    HRESULT __stdcall get_AmplitudeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AmplitudeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IBeginStoryboard> : produce_base<D, Windows::UI::Xaml::Media::Animation::IBeginStoryboard>
{
    HRESULT __stdcall get_Storyboard(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IStoryboard> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Storyboard());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Storyboard(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::IStoryboard> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Storyboard(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::Storyboard *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IBeginStoryboardStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IBeginStoryboardStatics>
{
    HRESULT __stdcall get_StoryboardProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StoryboardProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IBounceEase> : produce_base<D, Windows::UI::Xaml::Media::Animation::IBounceEase>
{
    HRESULT __stdcall get_Bounces(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bounces());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Bounces(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Bounces(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Bounciness(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bounciness());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Bounciness(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Bounciness(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IBounceEaseStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IBounceEaseStatics>
{
    HRESULT __stdcall get_BouncesProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BouncesProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BouncinessProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BouncinessProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ICircleEase> : produce_base<D, Windows::UI::Xaml::Media::Animation::ICircleEase>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IColorAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::IColorAnimation>
{
    HRESULT __stdcall get_From(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().From());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_From(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().From(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_To(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_To(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().To(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_By(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().By());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_By(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().By(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EasingFunction(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EasingFunction());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EasingFunction(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EasingFunction(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::EasingFunctionBase *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnableDependentAnimation(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnableDependentAnimation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EnableDependentAnimation(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableDependentAnimation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IColorAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IColorAnimationStatics>
{
    HRESULT __stdcall get_FromProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ByProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ByProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EasingFunctionProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EasingFunctionProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnableDependentAnimationProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnableDependentAnimationProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IColorAnimationUsingKeyFrames> : produce_base<D, Windows::UI::Xaml::Media::Animation::IColorAnimationUsingKeyFrames>
{
    HRESULT __stdcall get_KeyFrames(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::ColorKeyFrame>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyFrames());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnableDependentAnimation(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnableDependentAnimation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EnableDependentAnimation(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableDependentAnimation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IColorAnimationUsingKeyFramesStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IColorAnimationUsingKeyFramesStatics>
{
    HRESULT __stdcall get_EnableDependentAnimationProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnableDependentAnimationProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IColorKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::IColorKeyFrame>
{
    HRESULT __stdcall get_Value(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Value(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyTime(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::KeyTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeyTime(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::KeyTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyTime(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::KeyTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IColorKeyFrameFactory> : produce_base<D, Windows::UI::Xaml::Media::Animation::IColorKeyFrameFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IColorKeyFrame> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IColorKeyFrameStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IColorKeyFrameStatics>
{
    HRESULT __stdcall get_ValueProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ValueProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyTimeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyTimeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ICommonNavigationTransitionInfo> : produce_base<D, Windows::UI::Xaml::Media::Animation::ICommonNavigationTransitionInfo>
{
    HRESULT __stdcall get_IsStaggeringEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStaggeringEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsStaggeringEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsStaggeringEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ICommonNavigationTransitionInfoStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::ICommonNavigationTransitionInfoStatics>
{
    HRESULT __stdcall get_IsStaggeringEnabledProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStaggeringEnabledProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStaggerElementProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStaggerElementProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsStaggerElement(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetIsStaggerElement(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetIsStaggerElement(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetIsStaggerElement(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IConnectedAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::IConnectedAnimation>
{
    HRESULT __stdcall add_Completed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Media::Animation::ConnectedAnimation, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Completed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Media::Animation::ConnectedAnimation, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Completed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryStart(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> destination, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TryStart(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&destination)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Cancel() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Cancel();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IConnectedAnimationService> : produce_base<D, Windows::UI::Xaml::Media::Animation::IConnectedAnimationService>
{
    HRESULT __stdcall get_DefaultDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DefaultDuration(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultDuration(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultEasingFunction(impl::abi_arg_out<Windows::UI::Composition::ICompositionEasingFunction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultEasingFunction());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DefaultEasingFunction(impl::abi_arg_in<Windows::UI::Composition::ICompositionEasingFunction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultEasingFunction(*reinterpret_cast<const Windows::UI::Composition::CompositionEasingFunction *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareToAnimate(impl::abi_arg_in<hstring> key, impl::abi_arg_in<Windows::UI::Xaml::IUIElement> source, impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IConnectedAnimation> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().PrepareToAnimate(*reinterpret_cast<const hstring *>(&key), *reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&source)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAnimation(impl::abi_arg_in<hstring> key, impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IConnectedAnimation> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAnimation(*reinterpret_cast<const hstring *>(&key)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IConnectedAnimationServiceStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IConnectedAnimationServiceStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IConnectedAnimationService> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IContentThemeTransition> : produce_base<D, Windows::UI::Xaml::Media::Animation::IContentThemeTransition>
{
    HRESULT __stdcall get_HorizontalOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HorizontalOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HorizontalOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HorizontalOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VerticalOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VerticalOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VerticalOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VerticalOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IContentThemeTransitionStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IContentThemeTransitionStatics>
{
    HRESULT __stdcall get_HorizontalOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HorizontalOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VerticalOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VerticalOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IContinuumNavigationTransitionInfo> : produce_base<D, Windows::UI::Xaml::Media::Animation::IContinuumNavigationTransitionInfo>
{
    HRESULT __stdcall get_ExitElement(impl::abi_arg_out<Windows::UI::Xaml::IUIElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitElement());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExitElement(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExitElement(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IContinuumNavigationTransitionInfoStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IContinuumNavigationTransitionInfoStatics>
{
    HRESULT __stdcall get_ExitElementProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitElementProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsEntranceElementProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEntranceElementProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsEntranceElement(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetIsEntranceElement(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetIsEntranceElement(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetIsEntranceElement(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsExitElementProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsExitElementProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsExitElement(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetIsExitElement(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetIsExitElement(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetIsExitElement(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExitElementContainerProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitElementContainerProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetExitElementContainer(impl::abi_arg_in<Windows::UI::Xaml::Controls::IListViewBase> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetExitElementContainer(*reinterpret_cast<const Windows::UI::Xaml::Controls::ListViewBase *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetExitElementContainer(impl::abi_arg_in<Windows::UI::Xaml::Controls::IListViewBase> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetExitElementContainer(*reinterpret_cast<const Windows::UI::Xaml::Controls::ListViewBase *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ICubicEase> : produce_base<D, Windows::UI::Xaml::Media::Animation::ICubicEase>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDiscreteColorKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDiscreteColorKeyFrame>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDiscreteDoubleKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDiscreteDoubleKeyFrame>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDiscreteObjectKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDiscreteObjectKeyFrame>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDiscretePointKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDiscretePointKeyFrame>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDoubleAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDoubleAnimation>
{
    HRESULT __stdcall get_From(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().From());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_From(impl::abi_arg_in<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().From(*reinterpret_cast<const Windows::Foundation::IReference<double> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_To(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_To(impl::abi_arg_in<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().To(*reinterpret_cast<const Windows::Foundation::IReference<double> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_By(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().By());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_By(impl::abi_arg_in<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().By(*reinterpret_cast<const Windows::Foundation::IReference<double> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EasingFunction(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EasingFunction());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EasingFunction(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EasingFunction(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::EasingFunctionBase *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnableDependentAnimation(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnableDependentAnimation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EnableDependentAnimation(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableDependentAnimation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDoubleAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDoubleAnimationStatics>
{
    HRESULT __stdcall get_FromProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ByProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ByProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EasingFunctionProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EasingFunctionProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnableDependentAnimationProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnableDependentAnimationProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDoubleAnimationUsingKeyFrames> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDoubleAnimationUsingKeyFrames>
{
    HRESULT __stdcall get_KeyFrames(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::DoubleKeyFrame>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyFrames());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnableDependentAnimation(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnableDependentAnimation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EnableDependentAnimation(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableDependentAnimation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDoubleAnimationUsingKeyFramesStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDoubleAnimationUsingKeyFramesStatics>
{
    HRESULT __stdcall get_EnableDependentAnimationProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnableDependentAnimationProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame>
{
    HRESULT __stdcall get_Value(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Value(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyTime(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::KeyTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeyTime(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::KeyTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyTime(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::KeyTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDoubleKeyFrameFactory> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDoubleKeyFrameFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDoubleKeyFrameStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDoubleKeyFrameStatics>
{
    HRESULT __stdcall get_ValueProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ValueProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyTimeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyTimeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDragItemThemeAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDragItemThemeAnimation>
{
    HRESULT __stdcall get_TargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDragItemThemeAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDragItemThemeAnimationStatics>
{
    HRESULT __stdcall get_TargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDragOverThemeAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDragOverThemeAnimation>
{
    HRESULT __stdcall get_TargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ToOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ToOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Direction(Windows::UI::Xaml::Controls::Primitives::AnimationDirection * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Direction());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Direction(Windows::UI::Xaml::Controls::Primitives::AnimationDirection value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Direction(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDragOverThemeAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDragOverThemeAnimationStatics>
{
    HRESULT __stdcall get_TargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DirectionProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DirectionProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDrillInNavigationTransitionInfo> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDrillInNavigationTransitionInfo>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimation>
{
    HRESULT __stdcall get_EntranceTargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EntranceTargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EntranceTargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EntranceTargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EntranceTarget(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EntranceTarget());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EntranceTarget(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EntranceTarget(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExitTargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitTargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExitTargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExitTargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExitTarget(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitTarget());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExitTarget(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExitTarget(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimationStatics>
{
    HRESULT __stdcall get_EntranceTargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EntranceTargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EntranceTargetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EntranceTargetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExitTargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitTargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExitTargetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitTargetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimation>
{
    HRESULT __stdcall get_EntranceTargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EntranceTargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EntranceTargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EntranceTargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EntranceTarget(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EntranceTarget());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EntranceTarget(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EntranceTarget(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExitTargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitTargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExitTargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExitTargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExitTarget(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitTarget());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExitTarget(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExitTarget(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimationStatics>
{
    HRESULT __stdcall get_EntranceTargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EntranceTargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EntranceTargetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EntranceTargetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExitTargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitTargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExitTargetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitTargetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDropTargetItemThemeAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDropTargetItemThemeAnimation>
{
    HRESULT __stdcall get_TargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IDropTargetItemThemeAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IDropTargetItemThemeAnimationStatics>
{
    HRESULT __stdcall get_TargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IEasingColorKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::IEasingColorKeyFrame>
{
    HRESULT __stdcall get_EasingFunction(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EasingFunction());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EasingFunction(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EasingFunction(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::EasingFunctionBase *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IEasingColorKeyFrameStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IEasingColorKeyFrameStatics>
{
    HRESULT __stdcall get_EasingFunctionProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EasingFunctionProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IEasingDoubleKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::IEasingDoubleKeyFrame>
{
    HRESULT __stdcall get_EasingFunction(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EasingFunction());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EasingFunction(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EasingFunction(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::EasingFunctionBase *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IEasingDoubleKeyFrameStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IEasingDoubleKeyFrameStatics>
{
    HRESULT __stdcall get_EasingFunctionProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EasingFunctionProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> : produce_base<D, Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>
{
    HRESULT __stdcall get_EasingMode(Windows::UI::Xaml::Media::Animation::EasingMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EasingMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EasingMode(Windows::UI::Xaml::Media::Animation::EasingMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EasingMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Ease(double normalizedTime, double * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Ease(normalizedTime));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IEasingFunctionBaseFactory> : produce_base<D, Windows::UI::Xaml::Media::Animation::IEasingFunctionBaseFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IEasingFunctionBaseStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IEasingFunctionBaseStatics>
{
    HRESULT __stdcall get_EasingModeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EasingModeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IEasingPointKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::IEasingPointKeyFrame>
{
    HRESULT __stdcall get_EasingFunction(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EasingFunction());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EasingFunction(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EasingFunction(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::EasingFunctionBase *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IEasingPointKeyFrameStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IEasingPointKeyFrameStatics>
{
    HRESULT __stdcall get_EasingFunctionProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EasingFunctionProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IEdgeUIThemeTransition> : produce_base<D, Windows::UI::Xaml::Media::Animation::IEdgeUIThemeTransition>
{
    HRESULT __stdcall get_Edge(Windows::UI::Xaml::Controls::Primitives::EdgeTransitionLocation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Edge());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Edge(Windows::UI::Xaml::Controls::Primitives::EdgeTransitionLocation value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Edge(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IEdgeUIThemeTransitionStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IEdgeUIThemeTransitionStatics>
{
    HRESULT __stdcall get_EdgeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EdgeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IElasticEase> : produce_base<D, Windows::UI::Xaml::Media::Animation::IElasticEase>
{
    HRESULT __stdcall get_Oscillations(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Oscillations());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Oscillations(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Oscillations(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Springiness(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Springiness());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Springiness(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Springiness(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IElasticEaseStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IElasticEaseStatics>
{
    HRESULT __stdcall get_OscillationsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OscillationsProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SpringinessProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpringinessProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IEntranceNavigationTransitionInfo> : produce_base<D, Windows::UI::Xaml::Media::Animation::IEntranceNavigationTransitionInfo>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IEntranceNavigationTransitionInfoStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IEntranceNavigationTransitionInfoStatics>
{
    HRESULT __stdcall get_IsTargetElementProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTargetElementProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsTargetElement(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetIsTargetElement(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetIsTargetElement(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetIsTargetElement(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IEntranceThemeTransition> : produce_base<D, Windows::UI::Xaml::Media::Animation::IEntranceThemeTransition>
{
    HRESULT __stdcall get_FromHorizontalOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromHorizontalOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FromHorizontalOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FromHorizontalOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FromVerticalOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromVerticalOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FromVerticalOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FromVerticalOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStaggeringEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStaggeringEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsStaggeringEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsStaggeringEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IEntranceThemeTransitionStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IEntranceThemeTransitionStatics>
{
    HRESULT __stdcall get_FromHorizontalOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromHorizontalOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FromVerticalOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromVerticalOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStaggeringEnabledProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStaggeringEnabledProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IExponentialEase> : produce_base<D, Windows::UI::Xaml::Media::Animation::IExponentialEase>
{
    HRESULT __stdcall get_Exponent(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Exponent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Exponent(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Exponent(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IExponentialEaseStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IExponentialEaseStatics>
{
    HRESULT __stdcall get_ExponentProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExponentProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IFadeInThemeAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::IFadeInThemeAnimation>
{
    HRESULT __stdcall get_TargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IFadeInThemeAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IFadeInThemeAnimationStatics>
{
    HRESULT __stdcall get_TargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IFadeOutThemeAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::IFadeOutThemeAnimation>
{
    HRESULT __stdcall get_TargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IFadeOutThemeAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IFadeOutThemeAnimationStatics>
{
    HRESULT __stdcall get_TargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IKeySpline> : produce_base<D, Windows::UI::Xaml::Media::Animation::IKeySpline>
{
    HRESULT __stdcall get_ControlPoint1(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ControlPoint1());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ControlPoint1(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ControlPoint1(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ControlPoint2(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ControlPoint2());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ControlPoint2(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ControlPoint2(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IKeyTimeHelper> : produce_base<D, Windows::UI::Xaml::Media::Animation::IKeyTimeHelper>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IKeyTimeHelperStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IKeyTimeHelperStatics>
{
    HRESULT __stdcall abi_FromTimeSpan(impl::abi_arg_in<Windows::Foundation::TimeSpan> timeSpan, impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::KeyTime> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromTimeSpan(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&timeSpan)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ILinearColorKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::ILinearColorKeyFrame>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ILinearDoubleKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::ILinearDoubleKeyFrame>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ILinearPointKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::ILinearPointKeyFrame>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::INavigationThemeTransition> : produce_base<D, Windows::UI::Xaml::Media::Animation::INavigationThemeTransition>
{
    HRESULT __stdcall get_DefaultNavigationTransitionInfo(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultNavigationTransitionInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DefaultNavigationTransitionInfo(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultNavigationTransitionInfo(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::INavigationThemeTransitionStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::INavigationThemeTransitionStatics>
{
    HRESULT __stdcall get_DefaultNavigationTransitionInfoProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultNavigationTransitionInfoProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo> : produce_base<D, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoFactory> : produce_base<D, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides> : produce_base<D, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>
{
    HRESULT __stdcall abi_GetNavigationStateCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNavigationStateCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetNavigationStateCore(impl::abi_arg_in<hstring> navigationState) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetNavigationStateCore(*reinterpret_cast<const hstring *>(&navigationState));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IObjectAnimationUsingKeyFrames> : produce_base<D, Windows::UI::Xaml::Media::Animation::IObjectAnimationUsingKeyFrames>
{
    HRESULT __stdcall get_KeyFrames(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::ObjectKeyFrame>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyFrames());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnableDependentAnimation(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnableDependentAnimation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EnableDependentAnimation(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableDependentAnimation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IObjectAnimationUsingKeyFramesStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IObjectAnimationUsingKeyFramesStatics>
{
    HRESULT __stdcall get_EnableDependentAnimationProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnableDependentAnimationProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IObjectKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::IObjectKeyFrame>
{
    HRESULT __stdcall get_Value(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Value(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyTime(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::KeyTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeyTime(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::KeyTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyTime(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::KeyTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IObjectKeyFrameFactory> : produce_base<D, Windows::UI::Xaml::Media::Animation::IObjectKeyFrameFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IObjectKeyFrame> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IObjectKeyFrameStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IObjectKeyFrameStatics>
{
    HRESULT __stdcall get_ValueProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ValueProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyTimeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyTimeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPaneThemeTransition> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPaneThemeTransition>
{
    HRESULT __stdcall get_Edge(Windows::UI::Xaml::Controls::Primitives::EdgeTransitionLocation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Edge());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Edge(Windows::UI::Xaml::Controls::Primitives::EdgeTransitionLocation value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Edge(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPaneThemeTransitionStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPaneThemeTransitionStatics>
{
    HRESULT __stdcall get_EdgeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EdgeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPointAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPointAnimation>
{
    HRESULT __stdcall get_From(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::Point>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().From());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_From(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::Point>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().From(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::Point> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_To(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::Point>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_To(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::Point>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().To(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::Point> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_By(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::Point>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().By());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_By(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::Point>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().By(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::Point> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EasingFunction(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EasingFunction());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EasingFunction(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EasingFunction(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::EasingFunctionBase *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnableDependentAnimation(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnableDependentAnimation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EnableDependentAnimation(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableDependentAnimation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPointAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPointAnimationStatics>
{
    HRESULT __stdcall get_FromProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ByProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ByProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EasingFunctionProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EasingFunctionProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnableDependentAnimationProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnableDependentAnimationProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPointAnimationUsingKeyFrames> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPointAnimationUsingKeyFrames>
{
    HRESULT __stdcall get_KeyFrames(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::PointKeyFrame>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyFrames());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnableDependentAnimation(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnableDependentAnimation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EnableDependentAnimation(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableDependentAnimation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPointAnimationUsingKeyFramesStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPointAnimationUsingKeyFramesStatics>
{
    HRESULT __stdcall get_EnableDependentAnimationProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnableDependentAnimationProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPointKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPointKeyFrame>
{
    HRESULT __stdcall get_Value(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Value(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyTime(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::KeyTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeyTime(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::KeyTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyTime(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::KeyTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPointKeyFrameFactory> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPointKeyFrameFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IPointKeyFrame> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPointKeyFrameStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPointKeyFrameStatics>
{
    HRESULT __stdcall get_ValueProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ValueProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyTimeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyTimeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPointerDownThemeAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPointerDownThemeAnimation>
{
    HRESULT __stdcall get_TargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPointerDownThemeAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPointerDownThemeAnimationStatics>
{
    HRESULT __stdcall get_TargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPointerUpThemeAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPointerUpThemeAnimation>
{
    HRESULT __stdcall get_TargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPointerUpThemeAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPointerUpThemeAnimationStatics>
{
    HRESULT __stdcall get_TargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPopInThemeAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPopInThemeAnimation>
{
    HRESULT __stdcall get_TargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FromHorizontalOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromHorizontalOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FromHorizontalOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FromHorizontalOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FromVerticalOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromVerticalOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FromVerticalOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FromVerticalOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPopInThemeAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPopInThemeAnimationStatics>
{
    HRESULT __stdcall get_TargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FromHorizontalOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromHorizontalOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FromVerticalOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromVerticalOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPopOutThemeAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPopOutThemeAnimation>
{
    HRESULT __stdcall get_TargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPopOutThemeAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPopOutThemeAnimationStatics>
{
    HRESULT __stdcall get_TargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPopupThemeTransition> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPopupThemeTransition>
{
    HRESULT __stdcall get_FromHorizontalOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromHorizontalOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FromHorizontalOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FromHorizontalOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FromVerticalOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromVerticalOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FromVerticalOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FromVerticalOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPopupThemeTransitionStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPopupThemeTransitionStatics>
{
    HRESULT __stdcall get_FromHorizontalOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromHorizontalOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FromVerticalOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromVerticalOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPowerEase> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPowerEase>
{
    HRESULT __stdcall get_Power(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Power());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Power(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Power(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IPowerEaseStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IPowerEaseStatics>
{
    HRESULT __stdcall get_PowerProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PowerProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IQuadraticEase> : produce_base<D, Windows::UI::Xaml::Media::Animation::IQuadraticEase>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IQuarticEase> : produce_base<D, Windows::UI::Xaml::Media::Animation::IQuarticEase>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IQuinticEase> : produce_base<D, Windows::UI::Xaml::Media::Animation::IQuinticEase>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IReorderThemeTransition> : produce_base<D, Windows::UI::Xaml::Media::Animation::IReorderThemeTransition>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IRepeatBehaviorHelper> : produce_base<D, Windows::UI::Xaml::Media::Animation::IRepeatBehaviorHelper>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IRepeatBehaviorHelperStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IRepeatBehaviorHelperStatics>
{
    HRESULT __stdcall get_Forever(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::RepeatBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Forever());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromCount(double count, impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::RepeatBehavior> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromCount(count));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromDuration(impl::abi_arg_in<Windows::Foundation::TimeSpan> duration, impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::RepeatBehavior> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromDuration(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&duration)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetHasCount(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::RepeatBehavior> target, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetHasCount(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::RepeatBehavior *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetHasDuration(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::RepeatBehavior> target, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetHasDuration(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::RepeatBehavior *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Equals(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::RepeatBehavior> target, impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::RepeatBehavior> value, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Equals(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::RepeatBehavior *>(&target), *reinterpret_cast<const Windows::UI::Xaml::Media::Animation::RepeatBehavior *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IRepositionThemeAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::IRepositionThemeAnimation>
{
    HRESULT __stdcall get_TargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FromHorizontalOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromHorizontalOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FromHorizontalOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FromHorizontalOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FromVerticalOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromVerticalOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FromVerticalOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FromVerticalOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IRepositionThemeAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IRepositionThemeAnimationStatics>
{
    HRESULT __stdcall get_TargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FromHorizontalOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromHorizontalOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FromVerticalOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromVerticalOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IRepositionThemeTransition> : produce_base<D, Windows::UI::Xaml::Media::Animation::IRepositionThemeTransition>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IRepositionThemeTransition2> : produce_base<D, Windows::UI::Xaml::Media::Animation::IRepositionThemeTransition2>
{
    HRESULT __stdcall get_IsStaggeringEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStaggeringEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsStaggeringEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsStaggeringEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IRepositionThemeTransitionStatics2> : produce_base<D, Windows::UI::Xaml::Media::Animation::IRepositionThemeTransitionStatics2>
{
    HRESULT __stdcall get_IsStaggeringEnabledProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStaggeringEnabledProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISineEase> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISineEase>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISlideNavigationTransitionInfo> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISlideNavigationTransitionInfo>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISplineColorKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISplineColorKeyFrame>
{
    HRESULT __stdcall get_KeySpline(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IKeySpline> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeySpline());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeySpline(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::IKeySpline> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeySpline(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::KeySpline *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISplineColorKeyFrameStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISplineColorKeyFrameStatics>
{
    HRESULT __stdcall get_KeySplineProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeySplineProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISplineDoubleKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISplineDoubleKeyFrame>
{
    HRESULT __stdcall get_KeySpline(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IKeySpline> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeySpline());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeySpline(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::IKeySpline> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeySpline(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::KeySpline *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISplineDoubleKeyFrameStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISplineDoubleKeyFrameStatics>
{
    HRESULT __stdcall get_KeySplineProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeySplineProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISplinePointKeyFrame> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISplinePointKeyFrame>
{
    HRESULT __stdcall get_KeySpline(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IKeySpline> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeySpline());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeySpline(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::IKeySpline> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeySpline(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::KeySpline *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISplinePointKeyFrameStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISplinePointKeyFrameStatics>
{
    HRESULT __stdcall get_KeySplineProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeySplineProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>
{
    HRESULT __stdcall get_OpenedTargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpenedTargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OpenedTargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OpenedTargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OpenedTarget(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpenedTarget());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OpenedTarget(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OpenedTarget(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClosedTargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClosedTargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ClosedTargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClosedTargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClosedTarget(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClosedTarget());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ClosedTarget(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClosedTarget(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentTargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentTargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTarget(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTarget());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentTarget(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentTarget(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OpenedLength(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpenedLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OpenedLength(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OpenedLength(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClosedLength(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClosedLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ClosedLength(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClosedLength(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OffsetFromCenter(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OffsetFromCenter());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OffsetFromCenter(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OffsetFromCenter(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTranslationDirection(Windows::UI::Xaml::Controls::Primitives::AnimationDirection * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTranslationDirection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentTranslationDirection(Windows::UI::Xaml::Controls::Primitives::AnimationDirection value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentTranslationDirection(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTranslationOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTranslationOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentTranslationOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentTranslationOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimationStatics>
{
    HRESULT __stdcall get_OpenedTargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpenedTargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OpenedTargetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpenedTargetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClosedTargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClosedTargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClosedTargetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClosedTargetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTargetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTargetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OpenedLengthProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpenedLengthProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClosedLengthProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClosedLengthProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OffsetFromCenterProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OffsetFromCenterProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTranslationDirectionProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTranslationDirectionProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTranslationOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTranslationOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>
{
    HRESULT __stdcall get_OpenedTargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpenedTargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OpenedTargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OpenedTargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OpenedTarget(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpenedTarget());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OpenedTarget(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OpenedTarget(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClosedTargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClosedTargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ClosedTargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClosedTargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClosedTarget(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClosedTarget());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ClosedTarget(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClosedTarget(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentTargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentTargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTarget(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTarget());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentTarget(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentTarget(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OpenedLength(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpenedLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OpenedLength(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OpenedLength(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClosedLength(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClosedLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ClosedLength(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClosedLength(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OffsetFromCenter(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OffsetFromCenter());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OffsetFromCenter(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OffsetFromCenter(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTranslationDirection(Windows::UI::Xaml::Controls::Primitives::AnimationDirection * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTranslationDirection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentTranslationDirection(Windows::UI::Xaml::Controls::Primitives::AnimationDirection value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentTranslationDirection(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTranslationOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTranslationOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentTranslationOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentTranslationOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimationStatics>
{
    HRESULT __stdcall get_OpenedTargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpenedTargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OpenedTargetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpenedTargetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClosedTargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClosedTargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClosedTargetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClosedTargetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTargetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTargetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OpenedLengthProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpenedLengthProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClosedLengthProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClosedLengthProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OffsetFromCenterProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OffsetFromCenterProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTranslationDirectionProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTranslationDirectionProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTranslationOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTranslationOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IStoryboard> : produce_base<D, Windows::UI::Xaml::Media::Animation::IStoryboard>
{
    HRESULT __stdcall get_Children(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Timeline>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Children());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Seek(impl::abi_arg_in<Windows::Foundation::TimeSpan> offset) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Seek(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&offset));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Begin() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Begin();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Pause() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Pause();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Resume() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resume();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentState(Windows::UI::Xaml::Media::Animation::ClockState * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetCurrentState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetCurrentTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SeekAlignedToLastTick(impl::abi_arg_in<Windows::Foundation::TimeSpan> offset) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SeekAlignedToLastTick(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&offset));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SkipToFill() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SkipToFill();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::IStoryboardStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::IStoryboardStatics>
{
    HRESULT __stdcall get_TargetPropertyProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetPropertyProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTargetProperty(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::ITimeline> element, impl::abi_arg_out<hstring> path) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *path = detach_abi(this->shim().GetTargetProperty(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::Timeline *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            *path = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetTargetProperty(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::ITimeline> element, impl::abi_arg_in<hstring> path) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetTargetProperty(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::Timeline *>(&element), *reinterpret_cast<const hstring *>(&path));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTargetName(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::ITimeline> element, impl::abi_arg_out<hstring> name) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *name = detach_abi(this->shim().GetTargetName(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::Timeline *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            *name = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetTargetName(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::ITimeline> element, impl::abi_arg_in<hstring> name) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetTargetName(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::Timeline *>(&element), *reinterpret_cast<const hstring *>(&name));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetTarget(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::ITimeline> timeline, impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> target) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetTarget(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::Timeline *>(&timeline), *reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&target));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISuppressNavigationTransitionInfo> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISuppressNavigationTransitionInfo>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISwipeBackThemeAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISwipeBackThemeAnimation>
{
    HRESULT __stdcall get_TargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FromHorizontalOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromHorizontalOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FromHorizontalOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FromHorizontalOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FromVerticalOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromVerticalOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FromVerticalOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FromVerticalOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISwipeBackThemeAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISwipeBackThemeAnimationStatics>
{
    HRESULT __stdcall get_TargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FromHorizontalOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromHorizontalOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FromVerticalOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromVerticalOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISwipeHintThemeAnimation> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISwipeHintThemeAnimation>
{
    HRESULT __stdcall get_TargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToHorizontalOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToHorizontalOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ToHorizontalOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ToHorizontalOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToVerticalOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToVerticalOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ToVerticalOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ToVerticalOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ISwipeHintThemeAnimationStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::ISwipeHintThemeAnimationStatics>
{
    HRESULT __stdcall get_TargetNameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetNameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToHorizontalOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToHorizontalOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToVerticalOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToVerticalOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ITimeline> : produce_base<D, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    HRESULT __stdcall get_AutoReverse(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoReverse());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutoReverse(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoReverse(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BeginTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BeginTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BeginTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BeginTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duration(impl::abi_arg_out<Windows::UI::Xaml::Duration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Duration(impl::abi_arg_in<Windows::UI::Xaml::Duration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Duration(*reinterpret_cast<const Windows::UI::Xaml::Duration *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SpeedRatio(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpeedRatio());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SpeedRatio(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SpeedRatio(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FillBehavior(Windows::UI::Xaml::Media::Animation::FillBehavior * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FillBehavior());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FillBehavior(Windows::UI::Xaml::Media::Animation::FillBehavior value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FillBehavior(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RepeatBehavior(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::RepeatBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RepeatBehavior());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RepeatBehavior(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::RepeatBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RepeatBehavior(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::RepeatBehavior *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Completed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Completed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Completed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ITimelineFactory> : produce_base<D, Windows::UI::Xaml::Media::Animation::ITimelineFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::ITimeline> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ITimelineStatics> : produce_base<D, Windows::UI::Xaml::Media::Animation::ITimelineStatics>
{
    HRESULT __stdcall get_AllowDependentAnimations(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowDependentAnimations());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowDependentAnimations(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowDependentAnimations(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoReverseProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoReverseProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BeginTimeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BeginTimeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DurationProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DurationProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SpeedRatioProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpeedRatioProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FillBehaviorProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FillBehaviorProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RepeatBehaviorProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RepeatBehaviorProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ITransition> : produce_base<D, Windows::UI::Xaml::Media::Animation::ITransition>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Animation::ITransitionFactory> : produce_base<D, Windows::UI::Xaml::Media::Animation::ITransitionFactory>
{};

}

namespace Windows::UI::Xaml::Media::Animation {

template <typename D> Windows::UI::Xaml::Media::Animation::KeyTime impl_IKeyTimeHelperStatics<D>::FromTimeSpan(const Windows::Foundation::TimeSpan & timeSpan) const
{
    Windows::UI::Xaml::Media::Animation::KeyTime returnValue {};
    check_hresult(WINRT_SHIM(IKeyTimeHelperStatics)->abi_FromTimeSpan(get_abi(timeSpan), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Media::Animation::RepeatBehavior impl_IRepeatBehaviorHelperStatics<D>::Forever() const
{
    Windows::UI::Xaml::Media::Animation::RepeatBehavior value {};
    check_hresult(WINRT_SHIM(IRepeatBehaviorHelperStatics)->get_Forever(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::RepeatBehavior impl_IRepeatBehaviorHelperStatics<D>::FromCount(double count) const
{
    Windows::UI::Xaml::Media::Animation::RepeatBehavior returnValue {};
    check_hresult(WINRT_SHIM(IRepeatBehaviorHelperStatics)->abi_FromCount(count, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Media::Animation::RepeatBehavior impl_IRepeatBehaviorHelperStatics<D>::FromDuration(const Windows::Foundation::TimeSpan & duration) const
{
    Windows::UI::Xaml::Media::Animation::RepeatBehavior returnValue {};
    check_hresult(WINRT_SHIM(IRepeatBehaviorHelperStatics)->abi_FromDuration(get_abi(duration), put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_IRepeatBehaviorHelperStatics<D>::GetHasCount(const Windows::UI::Xaml::Media::Animation::RepeatBehavior & target) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IRepeatBehaviorHelperStatics)->abi_GetHasCount(get_abi(target), &value));
    return value;
}

template <typename D> bool impl_IRepeatBehaviorHelperStatics<D>::GetHasDuration(const Windows::UI::Xaml::Media::Animation::RepeatBehavior & target) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IRepeatBehaviorHelperStatics)->abi_GetHasDuration(get_abi(target), &value));
    return value;
}

template <typename D> bool impl_IRepeatBehaviorHelperStatics<D>::Equals(const Windows::UI::Xaml::Media::Animation::RepeatBehavior & target, const Windows::UI::Xaml::Media::Animation::RepeatBehavior & value) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IRepeatBehaviorHelperStatics)->abi_Equals(get_abi(target), get_abi(value), &returnValue));
    return returnValue;
}

template <typename D> Windows::UI::Color impl_IColorKeyFrame<D>::Value() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IColorKeyFrame)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IColorKeyFrame<D>::Value(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IColorKeyFrame)->put_Value(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Animation::KeyTime impl_IColorKeyFrame<D>::KeyTime() const
{
    Windows::UI::Xaml::Media::Animation::KeyTime value {};
    check_hresult(WINRT_SHIM(IColorKeyFrame)->get_KeyTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IColorKeyFrame<D>::KeyTime(const Windows::UI::Xaml::Media::Animation::KeyTime & value) const
{
    check_hresult(WINRT_SHIM(IColorKeyFrame)->put_KeyTime(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IColorKeyFrameStatics<D>::ValueProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IColorKeyFrameStatics)->get_ValueProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IColorKeyFrameStatics<D>::KeyTimeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IColorKeyFrameStatics)->get_KeyTimeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::ColorKeyFrame impl_IColorKeyFrameFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::Animation::ColorKeyFrame instance { nullptr };
    check_hresult(WINRT_SHIM(IColorKeyFrameFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> double impl_IDoubleKeyFrame<D>::Value() const
{
    double value {};
    check_hresult(WINRT_SHIM(IDoubleKeyFrame)->get_Value(&value));
    return value;
}

template <typename D> void impl_IDoubleKeyFrame<D>::Value(double value) const
{
    check_hresult(WINRT_SHIM(IDoubleKeyFrame)->put_Value(value));
}

template <typename D> Windows::UI::Xaml::Media::Animation::KeyTime impl_IDoubleKeyFrame<D>::KeyTime() const
{
    Windows::UI::Xaml::Media::Animation::KeyTime value {};
    check_hresult(WINRT_SHIM(IDoubleKeyFrame)->get_KeyTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IDoubleKeyFrame<D>::KeyTime(const Windows::UI::Xaml::Media::Animation::KeyTime & value) const
{
    check_hresult(WINRT_SHIM(IDoubleKeyFrame)->put_KeyTime(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDoubleKeyFrameStatics<D>::ValueProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDoubleKeyFrameStatics)->get_ValueProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDoubleKeyFrameStatics<D>::KeyTimeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDoubleKeyFrameStatics)->get_KeyTimeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::DoubleKeyFrame impl_IDoubleKeyFrameFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::Animation::DoubleKeyFrame instance { nullptr };
    check_hresult(WINRT_SHIM(IDoubleKeyFrameFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Media::Animation::EasingMode impl_IEasingFunctionBase<D>::EasingMode() const
{
    Windows::UI::Xaml::Media::Animation::EasingMode value {};
    check_hresult(WINRT_SHIM(IEasingFunctionBase)->get_EasingMode(&value));
    return value;
}

template <typename D> void impl_IEasingFunctionBase<D>::EasingMode(Windows::UI::Xaml::Media::Animation::EasingMode value) const
{
    check_hresult(WINRT_SHIM(IEasingFunctionBase)->put_EasingMode(value));
}

template <typename D> double impl_IEasingFunctionBase<D>::Ease(double normalizedTime) const
{
    double returnValue {};
    check_hresult(WINRT_SHIM(IEasingFunctionBase)->abi_Ease(normalizedTime, &returnValue));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IEasingFunctionBaseStatics<D>::EasingModeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IEasingFunctionBaseStatics)->get_EasingModeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IKeySpline<D>::ControlPoint1() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IKeySpline)->get_ControlPoint1(put_abi(value)));
    return value;
}

template <typename D> void impl_IKeySpline<D>::ControlPoint1(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IKeySpline)->put_ControlPoint1(get_abi(value)));
}

template <typename D> Windows::Foundation::Point impl_IKeySpline<D>::ControlPoint2() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IKeySpline)->get_ControlPoint2(put_abi(value)));
    return value;
}

template <typename D> void impl_IKeySpline<D>::ControlPoint2(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IKeySpline)->put_ControlPoint2(get_abi(value)));
}

template <typename D> hstring impl_INavigationTransitionInfoOverrides<D>::GetNavigationStateCore() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(INavigationTransitionInfoOverrides)->abi_GetNavigationStateCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_INavigationTransitionInfoOverrides<D>::SetNavigationStateCore(hstring_view navigationState) const
{
    check_hresult(WINRT_SHIM(INavigationTransitionInfoOverrides)->abi_SetNavigationStateCore(get_abi(navigationState)));
}

template <typename D> Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo impl_INavigationTransitionInfoFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo instance { nullptr };
    check_hresult(WINRT_SHIM(INavigationTransitionInfoFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::IInspectable impl_IObjectKeyFrame<D>::Value() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IObjectKeyFrame)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IObjectKeyFrame<D>::Value(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IObjectKeyFrame)->put_Value(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Animation::KeyTime impl_IObjectKeyFrame<D>::KeyTime() const
{
    Windows::UI::Xaml::Media::Animation::KeyTime value {};
    check_hresult(WINRT_SHIM(IObjectKeyFrame)->get_KeyTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IObjectKeyFrame<D>::KeyTime(const Windows::UI::Xaml::Media::Animation::KeyTime & value) const
{
    check_hresult(WINRT_SHIM(IObjectKeyFrame)->put_KeyTime(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IObjectKeyFrameStatics<D>::ValueProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IObjectKeyFrameStatics)->get_ValueProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IObjectKeyFrameStatics<D>::KeyTimeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IObjectKeyFrameStatics)->get_KeyTimeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::ObjectKeyFrame impl_IObjectKeyFrameFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::Animation::ObjectKeyFrame instance { nullptr };
    check_hresult(WINRT_SHIM(IObjectKeyFrameFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::Point impl_IPointKeyFrame<D>::Value() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IPointKeyFrame)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IPointKeyFrame<D>::Value(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IPointKeyFrame)->put_Value(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Animation::KeyTime impl_IPointKeyFrame<D>::KeyTime() const
{
    Windows::UI::Xaml::Media::Animation::KeyTime value {};
    check_hresult(WINRT_SHIM(IPointKeyFrame)->get_KeyTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IPointKeyFrame<D>::KeyTime(const Windows::UI::Xaml::Media::Animation::KeyTime & value) const
{
    check_hresult(WINRT_SHIM(IPointKeyFrame)->put_KeyTime(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPointKeyFrameStatics<D>::ValueProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPointKeyFrameStatics)->get_ValueProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPointKeyFrameStatics<D>::KeyTimeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPointKeyFrameStatics)->get_KeyTimeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::PointKeyFrame impl_IPointKeyFrameFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::Animation::PointKeyFrame instance { nullptr };
    check_hresult(WINRT_SHIM(IPointKeyFrameFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> bool impl_ITimeline<D>::AutoReverse() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITimeline)->get_AutoReverse(&value));
    return value;
}

template <typename D> void impl_ITimeline<D>::AutoReverse(bool value) const
{
    check_hresult(WINRT_SHIM(ITimeline)->put_AutoReverse(value));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_ITimeline<D>::BeginTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(ITimeline)->get_BeginTime(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimeline<D>::BeginTime(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(ITimeline)->put_BeginTime(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Duration impl_ITimeline<D>::Duration() const
{
    Windows::UI::Xaml::Duration value {};
    check_hresult(WINRT_SHIM(ITimeline)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimeline<D>::Duration(const Windows::UI::Xaml::Duration & value) const
{
    check_hresult(WINRT_SHIM(ITimeline)->put_Duration(get_abi(value)));
}

template <typename D> double impl_ITimeline<D>::SpeedRatio() const
{
    double value {};
    check_hresult(WINRT_SHIM(ITimeline)->get_SpeedRatio(&value));
    return value;
}

template <typename D> void impl_ITimeline<D>::SpeedRatio(double value) const
{
    check_hresult(WINRT_SHIM(ITimeline)->put_SpeedRatio(value));
}

template <typename D> Windows::UI::Xaml::Media::Animation::FillBehavior impl_ITimeline<D>::FillBehavior() const
{
    Windows::UI::Xaml::Media::Animation::FillBehavior value {};
    check_hresult(WINRT_SHIM(ITimeline)->get_FillBehavior(&value));
    return value;
}

template <typename D> void impl_ITimeline<D>::FillBehavior(Windows::UI::Xaml::Media::Animation::FillBehavior value) const
{
    check_hresult(WINRT_SHIM(ITimeline)->put_FillBehavior(value));
}

template <typename D> Windows::UI::Xaml::Media::Animation::RepeatBehavior impl_ITimeline<D>::RepeatBehavior() const
{
    Windows::UI::Xaml::Media::Animation::RepeatBehavior value {};
    check_hresult(WINRT_SHIM(ITimeline)->get_RepeatBehavior(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimeline<D>::RepeatBehavior(const Windows::UI::Xaml::Media::Animation::RepeatBehavior & value) const
{
    check_hresult(WINRT_SHIM(ITimeline)->put_RepeatBehavior(get_abi(value)));
}

template <typename D> event_token impl_ITimeline<D>::Completed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ITimeline)->add_Completed(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<ITimeline> impl_ITimeline<D>::Completed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, ITimeline>(this, &ABI::Windows::UI::Xaml::Media::Animation::ITimeline::remove_Completed, Completed(value));
}

template <typename D> void impl_ITimeline<D>::Completed(event_token token) const
{
    check_hresult(WINRT_SHIM(ITimeline)->remove_Completed(token));
}

template <typename D> bool impl_ITimelineStatics<D>::AllowDependentAnimations() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITimelineStatics)->get_AllowDependentAnimations(&value));
    return value;
}

template <typename D> void impl_ITimelineStatics<D>::AllowDependentAnimations(bool value) const
{
    check_hresult(WINRT_SHIM(ITimelineStatics)->put_AllowDependentAnimations(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITimelineStatics<D>::AutoReverseProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITimelineStatics)->get_AutoReverseProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITimelineStatics<D>::BeginTimeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITimelineStatics)->get_BeginTimeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITimelineStatics<D>::DurationProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITimelineStatics)->get_DurationProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITimelineStatics<D>::SpeedRatioProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITimelineStatics)->get_SpeedRatioProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITimelineStatics<D>::FillBehaviorProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITimelineStatics)->get_FillBehaviorProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITimelineStatics<D>::RepeatBehaviorProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITimelineStatics)->get_RepeatBehaviorProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::Timeline impl_ITimelineFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::Animation::Timeline instance { nullptr };
    check_hresult(WINRT_SHIM(ITimelineFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> double impl_IBackEase<D>::Amplitude() const
{
    double value {};
    check_hresult(WINRT_SHIM(IBackEase)->get_Amplitude(&value));
    return value;
}

template <typename D> void impl_IBackEase<D>::Amplitude(double value) const
{
    check_hresult(WINRT_SHIM(IBackEase)->put_Amplitude(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBackEaseStatics<D>::AmplitudeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBackEaseStatics)->get_AmplitudeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::Storyboard impl_IBeginStoryboard<D>::Storyboard() const
{
    Windows::UI::Xaml::Media::Animation::Storyboard value { nullptr };
    check_hresult(WINRT_SHIM(IBeginStoryboard)->get_Storyboard(put_abi(value)));
    return value;
}

template <typename D> void impl_IBeginStoryboard<D>::Storyboard(const Windows::UI::Xaml::Media::Animation::Storyboard & value) const
{
    check_hresult(WINRT_SHIM(IBeginStoryboard)->put_Storyboard(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBeginStoryboardStatics<D>::StoryboardProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBeginStoryboardStatics)->get_StoryboardProperty(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IBounceEase<D>::Bounces() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IBounceEase)->get_Bounces(&value));
    return value;
}

template <typename D> void impl_IBounceEase<D>::Bounces(int32_t value) const
{
    check_hresult(WINRT_SHIM(IBounceEase)->put_Bounces(value));
}

template <typename D> double impl_IBounceEase<D>::Bounciness() const
{
    double value {};
    check_hresult(WINRT_SHIM(IBounceEase)->get_Bounciness(&value));
    return value;
}

template <typename D> void impl_IBounceEase<D>::Bounciness(double value) const
{
    check_hresult(WINRT_SHIM(IBounceEase)->put_Bounciness(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBounceEaseStatics<D>::BouncesProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBounceEaseStatics)->get_BouncesProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBounceEaseStatics<D>::BouncinessProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBounceEaseStatics)->get_BouncinessProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IColorAnimation<D>::From() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IColorAnimation)->get_From(put_abi(value)));
    return value;
}

template <typename D> void impl_IColorAnimation<D>::From(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IColorAnimation)->put_From(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IColorAnimation<D>::To() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IColorAnimation)->get_To(put_abi(value)));
    return value;
}

template <typename D> void impl_IColorAnimation<D>::To(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IColorAnimation)->put_To(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IColorAnimation<D>::By() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IColorAnimation)->get_By(put_abi(value)));
    return value;
}

template <typename D> void impl_IColorAnimation<D>::By(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IColorAnimation)->put_By(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Animation::EasingFunctionBase impl_IColorAnimation<D>::EasingFunction() const
{
    Windows::UI::Xaml::Media::Animation::EasingFunctionBase value { nullptr };
    check_hresult(WINRT_SHIM(IColorAnimation)->get_EasingFunction(put_abi(value)));
    return value;
}

template <typename D> void impl_IColorAnimation<D>::EasingFunction(const Windows::UI::Xaml::Media::Animation::EasingFunctionBase & value) const
{
    check_hresult(WINRT_SHIM(IColorAnimation)->put_EasingFunction(get_abi(value)));
}

template <typename D> bool impl_IColorAnimation<D>::EnableDependentAnimation() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IColorAnimation)->get_EnableDependentAnimation(&value));
    return value;
}

template <typename D> void impl_IColorAnimation<D>::EnableDependentAnimation(bool value) const
{
    check_hresult(WINRT_SHIM(IColorAnimation)->put_EnableDependentAnimation(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IColorAnimationStatics<D>::FromProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IColorAnimationStatics)->get_FromProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IColorAnimationStatics<D>::ToProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IColorAnimationStatics)->get_ToProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IColorAnimationStatics<D>::ByProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IColorAnimationStatics)->get_ByProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IColorAnimationStatics<D>::EasingFunctionProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IColorAnimationStatics)->get_EasingFunctionProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IColorAnimationStatics<D>::EnableDependentAnimationProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IColorAnimationStatics)->get_EnableDependentAnimationProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::ColorKeyFrameCollection impl_IColorAnimationUsingKeyFrames<D>::KeyFrames() const
{
    Windows::UI::Xaml::Media::Animation::ColorKeyFrameCollection value { nullptr };
    check_hresult(WINRT_SHIM(IColorAnimationUsingKeyFrames)->get_KeyFrames(put_abi(value)));
    return value;
}

template <typename D> bool impl_IColorAnimationUsingKeyFrames<D>::EnableDependentAnimation() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IColorAnimationUsingKeyFrames)->get_EnableDependentAnimation(&value));
    return value;
}

template <typename D> void impl_IColorAnimationUsingKeyFrames<D>::EnableDependentAnimation(bool value) const
{
    check_hresult(WINRT_SHIM(IColorAnimationUsingKeyFrames)->put_EnableDependentAnimation(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IColorAnimationUsingKeyFramesStatics<D>::EnableDependentAnimationProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IColorAnimationUsingKeyFramesStatics)->get_EnableDependentAnimationProperty(put_abi(value)));
    return value;
}

template <typename D> double impl_IContentThemeTransition<D>::HorizontalOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(IContentThemeTransition)->get_HorizontalOffset(&value));
    return value;
}

template <typename D> void impl_IContentThemeTransition<D>::HorizontalOffset(double value) const
{
    check_hresult(WINRT_SHIM(IContentThemeTransition)->put_HorizontalOffset(value));
}

template <typename D> double impl_IContentThemeTransition<D>::VerticalOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(IContentThemeTransition)->get_VerticalOffset(&value));
    return value;
}

template <typename D> void impl_IContentThemeTransition<D>::VerticalOffset(double value) const
{
    check_hresult(WINRT_SHIM(IContentThemeTransition)->put_VerticalOffset(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IContentThemeTransitionStatics<D>::HorizontalOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IContentThemeTransitionStatics)->get_HorizontalOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IContentThemeTransitionStatics<D>::VerticalOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IContentThemeTransitionStatics)->get_VerticalOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_IDoubleAnimation<D>::From() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IDoubleAnimation)->get_From(put_abi(value)));
    return value;
}

template <typename D> void impl_IDoubleAnimation<D>::From(const optional<double> & value) const
{
    check_hresult(WINRT_SHIM(IDoubleAnimation)->put_From(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<double> impl_IDoubleAnimation<D>::To() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IDoubleAnimation)->get_To(put_abi(value)));
    return value;
}

template <typename D> void impl_IDoubleAnimation<D>::To(const optional<double> & value) const
{
    check_hresult(WINRT_SHIM(IDoubleAnimation)->put_To(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<double> impl_IDoubleAnimation<D>::By() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IDoubleAnimation)->get_By(put_abi(value)));
    return value;
}

template <typename D> void impl_IDoubleAnimation<D>::By(const optional<double> & value) const
{
    check_hresult(WINRT_SHIM(IDoubleAnimation)->put_By(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Animation::EasingFunctionBase impl_IDoubleAnimation<D>::EasingFunction() const
{
    Windows::UI::Xaml::Media::Animation::EasingFunctionBase value { nullptr };
    check_hresult(WINRT_SHIM(IDoubleAnimation)->get_EasingFunction(put_abi(value)));
    return value;
}

template <typename D> void impl_IDoubleAnimation<D>::EasingFunction(const Windows::UI::Xaml::Media::Animation::EasingFunctionBase & value) const
{
    check_hresult(WINRT_SHIM(IDoubleAnimation)->put_EasingFunction(get_abi(value)));
}

template <typename D> bool impl_IDoubleAnimation<D>::EnableDependentAnimation() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDoubleAnimation)->get_EnableDependentAnimation(&value));
    return value;
}

template <typename D> void impl_IDoubleAnimation<D>::EnableDependentAnimation(bool value) const
{
    check_hresult(WINRT_SHIM(IDoubleAnimation)->put_EnableDependentAnimation(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDoubleAnimationStatics<D>::FromProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDoubleAnimationStatics)->get_FromProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDoubleAnimationStatics<D>::ToProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDoubleAnimationStatics)->get_ToProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDoubleAnimationStatics<D>::ByProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDoubleAnimationStatics)->get_ByProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDoubleAnimationStatics<D>::EasingFunctionProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDoubleAnimationStatics)->get_EasingFunctionProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDoubleAnimationStatics<D>::EnableDependentAnimationProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDoubleAnimationStatics)->get_EnableDependentAnimationProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::DoubleKeyFrameCollection impl_IDoubleAnimationUsingKeyFrames<D>::KeyFrames() const
{
    Windows::UI::Xaml::Media::Animation::DoubleKeyFrameCollection value { nullptr };
    check_hresult(WINRT_SHIM(IDoubleAnimationUsingKeyFrames)->get_KeyFrames(put_abi(value)));
    return value;
}

template <typename D> bool impl_IDoubleAnimationUsingKeyFrames<D>::EnableDependentAnimation() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDoubleAnimationUsingKeyFrames)->get_EnableDependentAnimation(&value));
    return value;
}

template <typename D> void impl_IDoubleAnimationUsingKeyFrames<D>::EnableDependentAnimation(bool value) const
{
    check_hresult(WINRT_SHIM(IDoubleAnimationUsingKeyFrames)->put_EnableDependentAnimation(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDoubleAnimationUsingKeyFramesStatics<D>::EnableDependentAnimationProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDoubleAnimationUsingKeyFramesStatics)->get_EnableDependentAnimationProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDragItemThemeAnimation<D>::TargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDragItemThemeAnimation)->get_TargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_IDragItemThemeAnimation<D>::TargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDragItemThemeAnimation)->put_TargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDragItemThemeAnimationStatics<D>::TargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDragItemThemeAnimationStatics)->get_TargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDragOverThemeAnimation<D>::TargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDragOverThemeAnimation)->get_TargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_IDragOverThemeAnimation<D>::TargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDragOverThemeAnimation)->put_TargetName(get_abi(value)));
}

template <typename D> double impl_IDragOverThemeAnimation<D>::ToOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(IDragOverThemeAnimation)->get_ToOffset(&value));
    return value;
}

template <typename D> void impl_IDragOverThemeAnimation<D>::ToOffset(double value) const
{
    check_hresult(WINRT_SHIM(IDragOverThemeAnimation)->put_ToOffset(value));
}

template <typename D> Windows::UI::Xaml::Controls::Primitives::AnimationDirection impl_IDragOverThemeAnimation<D>::Direction() const
{
    Windows::UI::Xaml::Controls::Primitives::AnimationDirection value {};
    check_hresult(WINRT_SHIM(IDragOverThemeAnimation)->get_Direction(&value));
    return value;
}

template <typename D> void impl_IDragOverThemeAnimation<D>::Direction(Windows::UI::Xaml::Controls::Primitives::AnimationDirection value) const
{
    check_hresult(WINRT_SHIM(IDragOverThemeAnimation)->put_Direction(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDragOverThemeAnimationStatics<D>::TargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDragOverThemeAnimationStatics)->get_TargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDragOverThemeAnimationStatics<D>::ToOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDragOverThemeAnimationStatics)->get_ToOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDragOverThemeAnimationStatics<D>::DirectionProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDragOverThemeAnimationStatics)->get_DirectionProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDrillInThemeAnimation<D>::EntranceTargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDrillInThemeAnimation)->get_EntranceTargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_IDrillInThemeAnimation<D>::EntranceTargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDrillInThemeAnimation)->put_EntranceTargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_IDrillInThemeAnimation<D>::EntranceTarget() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(IDrillInThemeAnimation)->get_EntranceTarget(put_abi(value)));
    return value;
}

template <typename D> void impl_IDrillInThemeAnimation<D>::EntranceTarget(const Windows::UI::Xaml::DependencyObject & value) const
{
    check_hresult(WINRT_SHIM(IDrillInThemeAnimation)->put_EntranceTarget(get_abi(value)));
}

template <typename D> hstring impl_IDrillInThemeAnimation<D>::ExitTargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDrillInThemeAnimation)->get_ExitTargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_IDrillInThemeAnimation<D>::ExitTargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDrillInThemeAnimation)->put_ExitTargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_IDrillInThemeAnimation<D>::ExitTarget() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(IDrillInThemeAnimation)->get_ExitTarget(put_abi(value)));
    return value;
}

template <typename D> void impl_IDrillInThemeAnimation<D>::ExitTarget(const Windows::UI::Xaml::DependencyObject & value) const
{
    check_hresult(WINRT_SHIM(IDrillInThemeAnimation)->put_ExitTarget(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDrillInThemeAnimationStatics<D>::EntranceTargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDrillInThemeAnimationStatics)->get_EntranceTargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDrillInThemeAnimationStatics<D>::EntranceTargetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDrillInThemeAnimationStatics)->get_EntranceTargetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDrillInThemeAnimationStatics<D>::ExitTargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDrillInThemeAnimationStatics)->get_ExitTargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDrillInThemeAnimationStatics<D>::ExitTargetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDrillInThemeAnimationStatics)->get_ExitTargetProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDrillOutThemeAnimation<D>::EntranceTargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDrillOutThemeAnimation)->get_EntranceTargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_IDrillOutThemeAnimation<D>::EntranceTargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDrillOutThemeAnimation)->put_EntranceTargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_IDrillOutThemeAnimation<D>::EntranceTarget() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(IDrillOutThemeAnimation)->get_EntranceTarget(put_abi(value)));
    return value;
}

template <typename D> void impl_IDrillOutThemeAnimation<D>::EntranceTarget(const Windows::UI::Xaml::DependencyObject & value) const
{
    check_hresult(WINRT_SHIM(IDrillOutThemeAnimation)->put_EntranceTarget(get_abi(value)));
}

template <typename D> hstring impl_IDrillOutThemeAnimation<D>::ExitTargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDrillOutThemeAnimation)->get_ExitTargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_IDrillOutThemeAnimation<D>::ExitTargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDrillOutThemeAnimation)->put_ExitTargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_IDrillOutThemeAnimation<D>::ExitTarget() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(IDrillOutThemeAnimation)->get_ExitTarget(put_abi(value)));
    return value;
}

template <typename D> void impl_IDrillOutThemeAnimation<D>::ExitTarget(const Windows::UI::Xaml::DependencyObject & value) const
{
    check_hresult(WINRT_SHIM(IDrillOutThemeAnimation)->put_ExitTarget(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDrillOutThemeAnimationStatics<D>::EntranceTargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDrillOutThemeAnimationStatics)->get_EntranceTargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDrillOutThemeAnimationStatics<D>::EntranceTargetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDrillOutThemeAnimationStatics)->get_EntranceTargetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDrillOutThemeAnimationStatics<D>::ExitTargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDrillOutThemeAnimationStatics)->get_ExitTargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDrillOutThemeAnimationStatics<D>::ExitTargetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDrillOutThemeAnimationStatics)->get_ExitTargetProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDropTargetItemThemeAnimation<D>::TargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDropTargetItemThemeAnimation)->get_TargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_IDropTargetItemThemeAnimation<D>::TargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDropTargetItemThemeAnimation)->put_TargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDropTargetItemThemeAnimationStatics<D>::TargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDropTargetItemThemeAnimationStatics)->get_TargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::EasingFunctionBase impl_IEasingColorKeyFrame<D>::EasingFunction() const
{
    Windows::UI::Xaml::Media::Animation::EasingFunctionBase value { nullptr };
    check_hresult(WINRT_SHIM(IEasingColorKeyFrame)->get_EasingFunction(put_abi(value)));
    return value;
}

template <typename D> void impl_IEasingColorKeyFrame<D>::EasingFunction(const Windows::UI::Xaml::Media::Animation::EasingFunctionBase & value) const
{
    check_hresult(WINRT_SHIM(IEasingColorKeyFrame)->put_EasingFunction(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IEasingColorKeyFrameStatics<D>::EasingFunctionProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IEasingColorKeyFrameStatics)->get_EasingFunctionProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::EasingFunctionBase impl_IEasingDoubleKeyFrame<D>::EasingFunction() const
{
    Windows::UI::Xaml::Media::Animation::EasingFunctionBase value { nullptr };
    check_hresult(WINRT_SHIM(IEasingDoubleKeyFrame)->get_EasingFunction(put_abi(value)));
    return value;
}

template <typename D> void impl_IEasingDoubleKeyFrame<D>::EasingFunction(const Windows::UI::Xaml::Media::Animation::EasingFunctionBase & value) const
{
    check_hresult(WINRT_SHIM(IEasingDoubleKeyFrame)->put_EasingFunction(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IEasingDoubleKeyFrameStatics<D>::EasingFunctionProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IEasingDoubleKeyFrameStatics)->get_EasingFunctionProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::EasingFunctionBase impl_IEasingPointKeyFrame<D>::EasingFunction() const
{
    Windows::UI::Xaml::Media::Animation::EasingFunctionBase value { nullptr };
    check_hresult(WINRT_SHIM(IEasingPointKeyFrame)->get_EasingFunction(put_abi(value)));
    return value;
}

template <typename D> void impl_IEasingPointKeyFrame<D>::EasingFunction(const Windows::UI::Xaml::Media::Animation::EasingFunctionBase & value) const
{
    check_hresult(WINRT_SHIM(IEasingPointKeyFrame)->put_EasingFunction(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IEasingPointKeyFrameStatics<D>::EasingFunctionProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IEasingPointKeyFrameStatics)->get_EasingFunctionProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Primitives::EdgeTransitionLocation impl_IEdgeUIThemeTransition<D>::Edge() const
{
    Windows::UI::Xaml::Controls::Primitives::EdgeTransitionLocation value {};
    check_hresult(WINRT_SHIM(IEdgeUIThemeTransition)->get_Edge(&value));
    return value;
}

template <typename D> void impl_IEdgeUIThemeTransition<D>::Edge(Windows::UI::Xaml::Controls::Primitives::EdgeTransitionLocation value) const
{
    check_hresult(WINRT_SHIM(IEdgeUIThemeTransition)->put_Edge(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IEdgeUIThemeTransitionStatics<D>::EdgeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IEdgeUIThemeTransitionStatics)->get_EdgeProperty(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IElasticEase<D>::Oscillations() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IElasticEase)->get_Oscillations(&value));
    return value;
}

template <typename D> void impl_IElasticEase<D>::Oscillations(int32_t value) const
{
    check_hresult(WINRT_SHIM(IElasticEase)->put_Oscillations(value));
}

template <typename D> double impl_IElasticEase<D>::Springiness() const
{
    double value {};
    check_hresult(WINRT_SHIM(IElasticEase)->get_Springiness(&value));
    return value;
}

template <typename D> void impl_IElasticEase<D>::Springiness(double value) const
{
    check_hresult(WINRT_SHIM(IElasticEase)->put_Springiness(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IElasticEaseStatics<D>::OscillationsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IElasticEaseStatics)->get_OscillationsProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IElasticEaseStatics<D>::SpringinessProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IElasticEaseStatics)->get_SpringinessProperty(put_abi(value)));
    return value;
}

template <typename D> double impl_IEntranceThemeTransition<D>::FromHorizontalOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(IEntranceThemeTransition)->get_FromHorizontalOffset(&value));
    return value;
}

template <typename D> void impl_IEntranceThemeTransition<D>::FromHorizontalOffset(double value) const
{
    check_hresult(WINRT_SHIM(IEntranceThemeTransition)->put_FromHorizontalOffset(value));
}

template <typename D> double impl_IEntranceThemeTransition<D>::FromVerticalOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(IEntranceThemeTransition)->get_FromVerticalOffset(&value));
    return value;
}

template <typename D> void impl_IEntranceThemeTransition<D>::FromVerticalOffset(double value) const
{
    check_hresult(WINRT_SHIM(IEntranceThemeTransition)->put_FromVerticalOffset(value));
}

template <typename D> bool impl_IEntranceThemeTransition<D>::IsStaggeringEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEntranceThemeTransition)->get_IsStaggeringEnabled(&value));
    return value;
}

template <typename D> void impl_IEntranceThemeTransition<D>::IsStaggeringEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IEntranceThemeTransition)->put_IsStaggeringEnabled(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IEntranceThemeTransitionStatics<D>::FromHorizontalOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IEntranceThemeTransitionStatics)->get_FromHorizontalOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IEntranceThemeTransitionStatics<D>::FromVerticalOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IEntranceThemeTransitionStatics)->get_FromVerticalOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IEntranceThemeTransitionStatics<D>::IsStaggeringEnabledProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IEntranceThemeTransitionStatics)->get_IsStaggeringEnabledProperty(put_abi(value)));
    return value;
}

template <typename D> double impl_IExponentialEase<D>::Exponent() const
{
    double value {};
    check_hresult(WINRT_SHIM(IExponentialEase)->get_Exponent(&value));
    return value;
}

template <typename D> void impl_IExponentialEase<D>::Exponent(double value) const
{
    check_hresult(WINRT_SHIM(IExponentialEase)->put_Exponent(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IExponentialEaseStatics<D>::ExponentProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IExponentialEaseStatics)->get_ExponentProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IFadeInThemeAnimation<D>::TargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFadeInThemeAnimation)->get_TargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_IFadeInThemeAnimation<D>::TargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IFadeInThemeAnimation)->put_TargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFadeInThemeAnimationStatics<D>::TargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFadeInThemeAnimationStatics)->get_TargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IFadeOutThemeAnimation<D>::TargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFadeOutThemeAnimation)->get_TargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_IFadeOutThemeAnimation<D>::TargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IFadeOutThemeAnimation)->put_TargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFadeOutThemeAnimationStatics<D>::TargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFadeOutThemeAnimationStatics)->get_TargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::ObjectKeyFrameCollection impl_IObjectAnimationUsingKeyFrames<D>::KeyFrames() const
{
    Windows::UI::Xaml::Media::Animation::ObjectKeyFrameCollection value { nullptr };
    check_hresult(WINRT_SHIM(IObjectAnimationUsingKeyFrames)->get_KeyFrames(put_abi(value)));
    return value;
}

template <typename D> bool impl_IObjectAnimationUsingKeyFrames<D>::EnableDependentAnimation() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IObjectAnimationUsingKeyFrames)->get_EnableDependentAnimation(&value));
    return value;
}

template <typename D> void impl_IObjectAnimationUsingKeyFrames<D>::EnableDependentAnimation(bool value) const
{
    check_hresult(WINRT_SHIM(IObjectAnimationUsingKeyFrames)->put_EnableDependentAnimation(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IObjectAnimationUsingKeyFramesStatics<D>::EnableDependentAnimationProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IObjectAnimationUsingKeyFramesStatics)->get_EnableDependentAnimationProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Primitives::EdgeTransitionLocation impl_IPaneThemeTransition<D>::Edge() const
{
    Windows::UI::Xaml::Controls::Primitives::EdgeTransitionLocation value {};
    check_hresult(WINRT_SHIM(IPaneThemeTransition)->get_Edge(&value));
    return value;
}

template <typename D> void impl_IPaneThemeTransition<D>::Edge(Windows::UI::Xaml::Controls::Primitives::EdgeTransitionLocation value) const
{
    check_hresult(WINRT_SHIM(IPaneThemeTransition)->put_Edge(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPaneThemeTransitionStatics<D>::EdgeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPaneThemeTransitionStatics)->get_EdgeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::Point> impl_IPointAnimation<D>::From() const
{
    Windows::Foundation::IReference<Windows::Foundation::Point> value;
    check_hresult(WINRT_SHIM(IPointAnimation)->get_From(put_abi(value)));
    return value;
}

template <typename D> void impl_IPointAnimation<D>::From(const optional<Windows::Foundation::Point> & value) const
{
    check_hresult(WINRT_SHIM(IPointAnimation)->put_From(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::Point> impl_IPointAnimation<D>::To() const
{
    Windows::Foundation::IReference<Windows::Foundation::Point> value;
    check_hresult(WINRT_SHIM(IPointAnimation)->get_To(put_abi(value)));
    return value;
}

template <typename D> void impl_IPointAnimation<D>::To(const optional<Windows::Foundation::Point> & value) const
{
    check_hresult(WINRT_SHIM(IPointAnimation)->put_To(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::Point> impl_IPointAnimation<D>::By() const
{
    Windows::Foundation::IReference<Windows::Foundation::Point> value;
    check_hresult(WINRT_SHIM(IPointAnimation)->get_By(put_abi(value)));
    return value;
}

template <typename D> void impl_IPointAnimation<D>::By(const optional<Windows::Foundation::Point> & value) const
{
    check_hresult(WINRT_SHIM(IPointAnimation)->put_By(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Animation::EasingFunctionBase impl_IPointAnimation<D>::EasingFunction() const
{
    Windows::UI::Xaml::Media::Animation::EasingFunctionBase value { nullptr };
    check_hresult(WINRT_SHIM(IPointAnimation)->get_EasingFunction(put_abi(value)));
    return value;
}

template <typename D> void impl_IPointAnimation<D>::EasingFunction(const Windows::UI::Xaml::Media::Animation::EasingFunctionBase & value) const
{
    check_hresult(WINRT_SHIM(IPointAnimation)->put_EasingFunction(get_abi(value)));
}

template <typename D> bool impl_IPointAnimation<D>::EnableDependentAnimation() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPointAnimation)->get_EnableDependentAnimation(&value));
    return value;
}

template <typename D> void impl_IPointAnimation<D>::EnableDependentAnimation(bool value) const
{
    check_hresult(WINRT_SHIM(IPointAnimation)->put_EnableDependentAnimation(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPointAnimationStatics<D>::FromProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPointAnimationStatics)->get_FromProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPointAnimationStatics<D>::ToProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPointAnimationStatics)->get_ToProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPointAnimationStatics<D>::ByProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPointAnimationStatics)->get_ByProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPointAnimationStatics<D>::EasingFunctionProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPointAnimationStatics)->get_EasingFunctionProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPointAnimationStatics<D>::EnableDependentAnimationProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPointAnimationStatics)->get_EnableDependentAnimationProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::PointKeyFrameCollection impl_IPointAnimationUsingKeyFrames<D>::KeyFrames() const
{
    Windows::UI::Xaml::Media::Animation::PointKeyFrameCollection value { nullptr };
    check_hresult(WINRT_SHIM(IPointAnimationUsingKeyFrames)->get_KeyFrames(put_abi(value)));
    return value;
}

template <typename D> bool impl_IPointAnimationUsingKeyFrames<D>::EnableDependentAnimation() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPointAnimationUsingKeyFrames)->get_EnableDependentAnimation(&value));
    return value;
}

template <typename D> void impl_IPointAnimationUsingKeyFrames<D>::EnableDependentAnimation(bool value) const
{
    check_hresult(WINRT_SHIM(IPointAnimationUsingKeyFrames)->put_EnableDependentAnimation(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPointAnimationUsingKeyFramesStatics<D>::EnableDependentAnimationProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPointAnimationUsingKeyFramesStatics)->get_EnableDependentAnimationProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPointerDownThemeAnimation<D>::TargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPointerDownThemeAnimation)->get_TargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_IPointerDownThemeAnimation<D>::TargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPointerDownThemeAnimation)->put_TargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPointerDownThemeAnimationStatics<D>::TargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPointerDownThemeAnimationStatics)->get_TargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPointerUpThemeAnimation<D>::TargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPointerUpThemeAnimation)->get_TargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_IPointerUpThemeAnimation<D>::TargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPointerUpThemeAnimation)->put_TargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPointerUpThemeAnimationStatics<D>::TargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPointerUpThemeAnimationStatics)->get_TargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPopInThemeAnimation<D>::TargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPopInThemeAnimation)->get_TargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_IPopInThemeAnimation<D>::TargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPopInThemeAnimation)->put_TargetName(get_abi(value)));
}

template <typename D> double impl_IPopInThemeAnimation<D>::FromHorizontalOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPopInThemeAnimation)->get_FromHorizontalOffset(&value));
    return value;
}

template <typename D> void impl_IPopInThemeAnimation<D>::FromHorizontalOffset(double value) const
{
    check_hresult(WINRT_SHIM(IPopInThemeAnimation)->put_FromHorizontalOffset(value));
}

template <typename D> double impl_IPopInThemeAnimation<D>::FromVerticalOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPopInThemeAnimation)->get_FromVerticalOffset(&value));
    return value;
}

template <typename D> void impl_IPopInThemeAnimation<D>::FromVerticalOffset(double value) const
{
    check_hresult(WINRT_SHIM(IPopInThemeAnimation)->put_FromVerticalOffset(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPopInThemeAnimationStatics<D>::TargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPopInThemeAnimationStatics)->get_TargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPopInThemeAnimationStatics<D>::FromHorizontalOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPopInThemeAnimationStatics)->get_FromHorizontalOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPopInThemeAnimationStatics<D>::FromVerticalOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPopInThemeAnimationStatics)->get_FromVerticalOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPopOutThemeAnimation<D>::TargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPopOutThemeAnimation)->get_TargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_IPopOutThemeAnimation<D>::TargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPopOutThemeAnimation)->put_TargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPopOutThemeAnimationStatics<D>::TargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPopOutThemeAnimationStatics)->get_TargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> double impl_IPopupThemeTransition<D>::FromHorizontalOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPopupThemeTransition)->get_FromHorizontalOffset(&value));
    return value;
}

template <typename D> void impl_IPopupThemeTransition<D>::FromHorizontalOffset(double value) const
{
    check_hresult(WINRT_SHIM(IPopupThemeTransition)->put_FromHorizontalOffset(value));
}

template <typename D> double impl_IPopupThemeTransition<D>::FromVerticalOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPopupThemeTransition)->get_FromVerticalOffset(&value));
    return value;
}

template <typename D> void impl_IPopupThemeTransition<D>::FromVerticalOffset(double value) const
{
    check_hresult(WINRT_SHIM(IPopupThemeTransition)->put_FromVerticalOffset(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPopupThemeTransitionStatics<D>::FromHorizontalOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPopupThemeTransitionStatics)->get_FromHorizontalOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPopupThemeTransitionStatics<D>::FromVerticalOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPopupThemeTransitionStatics)->get_FromVerticalOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> double impl_IPowerEase<D>::Power() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPowerEase)->get_Power(&value));
    return value;
}

template <typename D> void impl_IPowerEase<D>::Power(double value) const
{
    check_hresult(WINRT_SHIM(IPowerEase)->put_Power(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPowerEaseStatics<D>::PowerProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPowerEaseStatics)->get_PowerProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRepositionThemeAnimation<D>::TargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRepositionThemeAnimation)->get_TargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_IRepositionThemeAnimation<D>::TargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IRepositionThemeAnimation)->put_TargetName(get_abi(value)));
}

template <typename D> double impl_IRepositionThemeAnimation<D>::FromHorizontalOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(IRepositionThemeAnimation)->get_FromHorizontalOffset(&value));
    return value;
}

template <typename D> void impl_IRepositionThemeAnimation<D>::FromHorizontalOffset(double value) const
{
    check_hresult(WINRT_SHIM(IRepositionThemeAnimation)->put_FromHorizontalOffset(value));
}

template <typename D> double impl_IRepositionThemeAnimation<D>::FromVerticalOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(IRepositionThemeAnimation)->get_FromVerticalOffset(&value));
    return value;
}

template <typename D> void impl_IRepositionThemeAnimation<D>::FromVerticalOffset(double value) const
{
    check_hresult(WINRT_SHIM(IRepositionThemeAnimation)->put_FromVerticalOffset(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IRepositionThemeAnimationStatics<D>::TargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IRepositionThemeAnimationStatics)->get_TargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IRepositionThemeAnimationStatics<D>::FromHorizontalOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IRepositionThemeAnimationStatics)->get_FromHorizontalOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IRepositionThemeAnimationStatics<D>::FromVerticalOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IRepositionThemeAnimationStatics)->get_FromVerticalOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_IRepositionThemeTransition2<D>::IsStaggeringEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IRepositionThemeTransition2)->get_IsStaggeringEnabled(&value));
    return value;
}

template <typename D> void impl_IRepositionThemeTransition2<D>::IsStaggeringEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IRepositionThemeTransition2)->put_IsStaggeringEnabled(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IRepositionThemeTransitionStatics2<D>::IsStaggeringEnabledProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IRepositionThemeTransitionStatics2)->get_IsStaggeringEnabledProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::KeySpline impl_ISplineColorKeyFrame<D>::KeySpline() const
{
    Windows::UI::Xaml::Media::Animation::KeySpline value { nullptr };
    check_hresult(WINRT_SHIM(ISplineColorKeyFrame)->get_KeySpline(put_abi(value)));
    return value;
}

template <typename D> void impl_ISplineColorKeyFrame<D>::KeySpline(const Windows::UI::Xaml::Media::Animation::KeySpline & value) const
{
    check_hresult(WINRT_SHIM(ISplineColorKeyFrame)->put_KeySpline(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplineColorKeyFrameStatics<D>::KeySplineProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplineColorKeyFrameStatics)->get_KeySplineProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::KeySpline impl_ISplineDoubleKeyFrame<D>::KeySpline() const
{
    Windows::UI::Xaml::Media::Animation::KeySpline value { nullptr };
    check_hresult(WINRT_SHIM(ISplineDoubleKeyFrame)->get_KeySpline(put_abi(value)));
    return value;
}

template <typename D> void impl_ISplineDoubleKeyFrame<D>::KeySpline(const Windows::UI::Xaml::Media::Animation::KeySpline & value) const
{
    check_hresult(WINRT_SHIM(ISplineDoubleKeyFrame)->put_KeySpline(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplineDoubleKeyFrameStatics<D>::KeySplineProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplineDoubleKeyFrameStatics)->get_KeySplineProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::KeySpline impl_ISplinePointKeyFrame<D>::KeySpline() const
{
    Windows::UI::Xaml::Media::Animation::KeySpline value { nullptr };
    check_hresult(WINRT_SHIM(ISplinePointKeyFrame)->get_KeySpline(put_abi(value)));
    return value;
}

template <typename D> void impl_ISplinePointKeyFrame<D>::KeySpline(const Windows::UI::Xaml::Media::Animation::KeySpline & value) const
{
    check_hresult(WINRT_SHIM(ISplinePointKeyFrame)->put_KeySpline(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplinePointKeyFrameStatics<D>::KeySplineProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplinePointKeyFrameStatics)->get_KeySplineProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISplitCloseThemeAnimation<D>::OpenedTargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->get_OpenedTargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISplitCloseThemeAnimation<D>::OpenedTargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->put_OpenedTargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_ISplitCloseThemeAnimation<D>::OpenedTarget() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->get_OpenedTarget(put_abi(value)));
    return value;
}

template <typename D> void impl_ISplitCloseThemeAnimation<D>::OpenedTarget(const Windows::UI::Xaml::DependencyObject & value) const
{
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->put_OpenedTarget(get_abi(value)));
}

template <typename D> hstring impl_ISplitCloseThemeAnimation<D>::ClosedTargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->get_ClosedTargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISplitCloseThemeAnimation<D>::ClosedTargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->put_ClosedTargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_ISplitCloseThemeAnimation<D>::ClosedTarget() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->get_ClosedTarget(put_abi(value)));
    return value;
}

template <typename D> void impl_ISplitCloseThemeAnimation<D>::ClosedTarget(const Windows::UI::Xaml::DependencyObject & value) const
{
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->put_ClosedTarget(get_abi(value)));
}

template <typename D> hstring impl_ISplitCloseThemeAnimation<D>::ContentTargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->get_ContentTargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISplitCloseThemeAnimation<D>::ContentTargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->put_ContentTargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_ISplitCloseThemeAnimation<D>::ContentTarget() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->get_ContentTarget(put_abi(value)));
    return value;
}

template <typename D> void impl_ISplitCloseThemeAnimation<D>::ContentTarget(const Windows::UI::Xaml::DependencyObject & value) const
{
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->put_ContentTarget(get_abi(value)));
}

template <typename D> double impl_ISplitCloseThemeAnimation<D>::OpenedLength() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->get_OpenedLength(&value));
    return value;
}

template <typename D> void impl_ISplitCloseThemeAnimation<D>::OpenedLength(double value) const
{
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->put_OpenedLength(value));
}

template <typename D> double impl_ISplitCloseThemeAnimation<D>::ClosedLength() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->get_ClosedLength(&value));
    return value;
}

template <typename D> void impl_ISplitCloseThemeAnimation<D>::ClosedLength(double value) const
{
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->put_ClosedLength(value));
}

template <typename D> double impl_ISplitCloseThemeAnimation<D>::OffsetFromCenter() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->get_OffsetFromCenter(&value));
    return value;
}

template <typename D> void impl_ISplitCloseThemeAnimation<D>::OffsetFromCenter(double value) const
{
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->put_OffsetFromCenter(value));
}

template <typename D> Windows::UI::Xaml::Controls::Primitives::AnimationDirection impl_ISplitCloseThemeAnimation<D>::ContentTranslationDirection() const
{
    Windows::UI::Xaml::Controls::Primitives::AnimationDirection value {};
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->get_ContentTranslationDirection(&value));
    return value;
}

template <typename D> void impl_ISplitCloseThemeAnimation<D>::ContentTranslationDirection(Windows::UI::Xaml::Controls::Primitives::AnimationDirection value) const
{
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->put_ContentTranslationDirection(value));
}

template <typename D> double impl_ISplitCloseThemeAnimation<D>::ContentTranslationOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->get_ContentTranslationOffset(&value));
    return value;
}

template <typename D> void impl_ISplitCloseThemeAnimation<D>::ContentTranslationOffset(double value) const
{
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimation)->put_ContentTranslationOffset(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitCloseThemeAnimationStatics<D>::OpenedTargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimationStatics)->get_OpenedTargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitCloseThemeAnimationStatics<D>::OpenedTargetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimationStatics)->get_OpenedTargetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitCloseThemeAnimationStatics<D>::ClosedTargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimationStatics)->get_ClosedTargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitCloseThemeAnimationStatics<D>::ClosedTargetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimationStatics)->get_ClosedTargetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitCloseThemeAnimationStatics<D>::ContentTargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimationStatics)->get_ContentTargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitCloseThemeAnimationStatics<D>::ContentTargetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimationStatics)->get_ContentTargetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitCloseThemeAnimationStatics<D>::OpenedLengthProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimationStatics)->get_OpenedLengthProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitCloseThemeAnimationStatics<D>::ClosedLengthProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimationStatics)->get_ClosedLengthProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitCloseThemeAnimationStatics<D>::OffsetFromCenterProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimationStatics)->get_OffsetFromCenterProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitCloseThemeAnimationStatics<D>::ContentTranslationDirectionProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimationStatics)->get_ContentTranslationDirectionProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitCloseThemeAnimationStatics<D>::ContentTranslationOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitCloseThemeAnimationStatics)->get_ContentTranslationOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISplitOpenThemeAnimation<D>::OpenedTargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->get_OpenedTargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISplitOpenThemeAnimation<D>::OpenedTargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->put_OpenedTargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_ISplitOpenThemeAnimation<D>::OpenedTarget() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->get_OpenedTarget(put_abi(value)));
    return value;
}

template <typename D> void impl_ISplitOpenThemeAnimation<D>::OpenedTarget(const Windows::UI::Xaml::DependencyObject & value) const
{
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->put_OpenedTarget(get_abi(value)));
}

template <typename D> hstring impl_ISplitOpenThemeAnimation<D>::ClosedTargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->get_ClosedTargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISplitOpenThemeAnimation<D>::ClosedTargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->put_ClosedTargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_ISplitOpenThemeAnimation<D>::ClosedTarget() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->get_ClosedTarget(put_abi(value)));
    return value;
}

template <typename D> void impl_ISplitOpenThemeAnimation<D>::ClosedTarget(const Windows::UI::Xaml::DependencyObject & value) const
{
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->put_ClosedTarget(get_abi(value)));
}

template <typename D> hstring impl_ISplitOpenThemeAnimation<D>::ContentTargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->get_ContentTargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISplitOpenThemeAnimation<D>::ContentTargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->put_ContentTargetName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_ISplitOpenThemeAnimation<D>::ContentTarget() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->get_ContentTarget(put_abi(value)));
    return value;
}

template <typename D> void impl_ISplitOpenThemeAnimation<D>::ContentTarget(const Windows::UI::Xaml::DependencyObject & value) const
{
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->put_ContentTarget(get_abi(value)));
}

template <typename D> double impl_ISplitOpenThemeAnimation<D>::OpenedLength() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->get_OpenedLength(&value));
    return value;
}

template <typename D> void impl_ISplitOpenThemeAnimation<D>::OpenedLength(double value) const
{
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->put_OpenedLength(value));
}

template <typename D> double impl_ISplitOpenThemeAnimation<D>::ClosedLength() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->get_ClosedLength(&value));
    return value;
}

template <typename D> void impl_ISplitOpenThemeAnimation<D>::ClosedLength(double value) const
{
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->put_ClosedLength(value));
}

template <typename D> double impl_ISplitOpenThemeAnimation<D>::OffsetFromCenter() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->get_OffsetFromCenter(&value));
    return value;
}

template <typename D> void impl_ISplitOpenThemeAnimation<D>::OffsetFromCenter(double value) const
{
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->put_OffsetFromCenter(value));
}

template <typename D> Windows::UI::Xaml::Controls::Primitives::AnimationDirection impl_ISplitOpenThemeAnimation<D>::ContentTranslationDirection() const
{
    Windows::UI::Xaml::Controls::Primitives::AnimationDirection value {};
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->get_ContentTranslationDirection(&value));
    return value;
}

template <typename D> void impl_ISplitOpenThemeAnimation<D>::ContentTranslationDirection(Windows::UI::Xaml::Controls::Primitives::AnimationDirection value) const
{
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->put_ContentTranslationDirection(value));
}

template <typename D> double impl_ISplitOpenThemeAnimation<D>::ContentTranslationOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->get_ContentTranslationOffset(&value));
    return value;
}

template <typename D> void impl_ISplitOpenThemeAnimation<D>::ContentTranslationOffset(double value) const
{
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimation)->put_ContentTranslationOffset(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitOpenThemeAnimationStatics<D>::OpenedTargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimationStatics)->get_OpenedTargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitOpenThemeAnimationStatics<D>::OpenedTargetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimationStatics)->get_OpenedTargetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitOpenThemeAnimationStatics<D>::ClosedTargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimationStatics)->get_ClosedTargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitOpenThemeAnimationStatics<D>::ClosedTargetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimationStatics)->get_ClosedTargetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitOpenThemeAnimationStatics<D>::ContentTargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimationStatics)->get_ContentTargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitOpenThemeAnimationStatics<D>::ContentTargetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimationStatics)->get_ContentTargetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitOpenThemeAnimationStatics<D>::OpenedLengthProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimationStatics)->get_OpenedLengthProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitOpenThemeAnimationStatics<D>::ClosedLengthProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimationStatics)->get_ClosedLengthProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitOpenThemeAnimationStatics<D>::OffsetFromCenterProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimationStatics)->get_OffsetFromCenterProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitOpenThemeAnimationStatics<D>::ContentTranslationDirectionProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimationStatics)->get_ContentTranslationDirectionProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISplitOpenThemeAnimationStatics<D>::ContentTranslationOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISplitOpenThemeAnimationStatics)->get_ContentTranslationOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::TimelineCollection impl_IStoryboard<D>::Children() const
{
    Windows::UI::Xaml::Media::Animation::TimelineCollection value { nullptr };
    check_hresult(WINRT_SHIM(IStoryboard)->get_Children(put_abi(value)));
    return value;
}

template <typename D> void impl_IStoryboard<D>::Seek(const Windows::Foundation::TimeSpan & offset) const
{
    check_hresult(WINRT_SHIM(IStoryboard)->abi_Seek(get_abi(offset)));
}

template <typename D> void impl_IStoryboard<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IStoryboard)->abi_Stop());
}

template <typename D> void impl_IStoryboard<D>::Begin() const
{
    check_hresult(WINRT_SHIM(IStoryboard)->abi_Begin());
}

template <typename D> void impl_IStoryboard<D>::Pause() const
{
    check_hresult(WINRT_SHIM(IStoryboard)->abi_Pause());
}

template <typename D> void impl_IStoryboard<D>::Resume() const
{
    check_hresult(WINRT_SHIM(IStoryboard)->abi_Resume());
}

template <typename D> Windows::UI::Xaml::Media::Animation::ClockState impl_IStoryboard<D>::GetCurrentState() const
{
    Windows::UI::Xaml::Media::Animation::ClockState returnValue {};
    check_hresult(WINRT_SHIM(IStoryboard)->abi_GetCurrentState(&returnValue));
    return returnValue;
}

template <typename D> Windows::Foundation::TimeSpan impl_IStoryboard<D>::GetCurrentTime() const
{
    Windows::Foundation::TimeSpan returnValue {};
    check_hresult(WINRT_SHIM(IStoryboard)->abi_GetCurrentTime(put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IStoryboard<D>::SeekAlignedToLastTick(const Windows::Foundation::TimeSpan & offset) const
{
    check_hresult(WINRT_SHIM(IStoryboard)->abi_SeekAlignedToLastTick(get_abi(offset)));
}

template <typename D> void impl_IStoryboard<D>::SkipToFill() const
{
    check_hresult(WINRT_SHIM(IStoryboard)->abi_SkipToFill());
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IStoryboardStatics<D>::TargetPropertyProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IStoryboardStatics)->get_TargetPropertyProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoryboardStatics<D>::GetTargetProperty(const Windows::UI::Xaml::Media::Animation::Timeline & element) const
{
    hstring path;
    check_hresult(WINRT_SHIM(IStoryboardStatics)->abi_GetTargetProperty(get_abi(element), put_abi(path)));
    return path;
}

template <typename D> void impl_IStoryboardStatics<D>::SetTargetProperty(const Windows::UI::Xaml::Media::Animation::Timeline & element, hstring_view path) const
{
    check_hresult(WINRT_SHIM(IStoryboardStatics)->abi_SetTargetProperty(get_abi(element), get_abi(path)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IStoryboardStatics<D>::TargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IStoryboardStatics)->get_TargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoryboardStatics<D>::GetTargetName(const Windows::UI::Xaml::Media::Animation::Timeline & element) const
{
    hstring name;
    check_hresult(WINRT_SHIM(IStoryboardStatics)->abi_GetTargetName(get_abi(element), put_abi(name)));
    return name;
}

template <typename D> void impl_IStoryboardStatics<D>::SetTargetName(const Windows::UI::Xaml::Media::Animation::Timeline & element, hstring_view name) const
{
    check_hresult(WINRT_SHIM(IStoryboardStatics)->abi_SetTargetName(get_abi(element), get_abi(name)));
}

template <typename D> void impl_IStoryboardStatics<D>::SetTarget(const Windows::UI::Xaml::Media::Animation::Timeline & timeline, const Windows::UI::Xaml::DependencyObject & target) const
{
    check_hresult(WINRT_SHIM(IStoryboardStatics)->abi_SetTarget(get_abi(timeline), get_abi(target)));
}

template <typename D> hstring impl_ISwipeBackThemeAnimation<D>::TargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISwipeBackThemeAnimation)->get_TargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISwipeBackThemeAnimation<D>::TargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISwipeBackThemeAnimation)->put_TargetName(get_abi(value)));
}

template <typename D> double impl_ISwipeBackThemeAnimation<D>::FromHorizontalOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISwipeBackThemeAnimation)->get_FromHorizontalOffset(&value));
    return value;
}

template <typename D> void impl_ISwipeBackThemeAnimation<D>::FromHorizontalOffset(double value) const
{
    check_hresult(WINRT_SHIM(ISwipeBackThemeAnimation)->put_FromHorizontalOffset(value));
}

template <typename D> double impl_ISwipeBackThemeAnimation<D>::FromVerticalOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISwipeBackThemeAnimation)->get_FromVerticalOffset(&value));
    return value;
}

template <typename D> void impl_ISwipeBackThemeAnimation<D>::FromVerticalOffset(double value) const
{
    check_hresult(WINRT_SHIM(ISwipeBackThemeAnimation)->put_FromVerticalOffset(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISwipeBackThemeAnimationStatics<D>::TargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISwipeBackThemeAnimationStatics)->get_TargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISwipeBackThemeAnimationStatics<D>::FromHorizontalOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISwipeBackThemeAnimationStatics)->get_FromHorizontalOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISwipeBackThemeAnimationStatics<D>::FromVerticalOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISwipeBackThemeAnimationStatics)->get_FromVerticalOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISwipeHintThemeAnimation<D>::TargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISwipeHintThemeAnimation)->get_TargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISwipeHintThemeAnimation<D>::TargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISwipeHintThemeAnimation)->put_TargetName(get_abi(value)));
}

template <typename D> double impl_ISwipeHintThemeAnimation<D>::ToHorizontalOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISwipeHintThemeAnimation)->get_ToHorizontalOffset(&value));
    return value;
}

template <typename D> void impl_ISwipeHintThemeAnimation<D>::ToHorizontalOffset(double value) const
{
    check_hresult(WINRT_SHIM(ISwipeHintThemeAnimation)->put_ToHorizontalOffset(value));
}

template <typename D> double impl_ISwipeHintThemeAnimation<D>::ToVerticalOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISwipeHintThemeAnimation)->get_ToVerticalOffset(&value));
    return value;
}

template <typename D> void impl_ISwipeHintThemeAnimation<D>::ToVerticalOffset(double value) const
{
    check_hresult(WINRT_SHIM(ISwipeHintThemeAnimation)->put_ToVerticalOffset(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISwipeHintThemeAnimationStatics<D>::TargetNameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISwipeHintThemeAnimationStatics)->get_TargetNameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISwipeHintThemeAnimationStatics<D>::ToHorizontalOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISwipeHintThemeAnimationStatics)->get_ToHorizontalOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISwipeHintThemeAnimationStatics<D>::ToVerticalOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISwipeHintThemeAnimationStatics)->get_ToVerticalOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IConnectedAnimation<D>::Completed(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Media::Animation::ConnectedAnimation, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IConnectedAnimation)->add_Completed(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IConnectedAnimation> impl_IConnectedAnimation<D>::Completed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Media::Animation::ConnectedAnimation, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IConnectedAnimation>(this, &ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimation::remove_Completed, Completed(value));
}

template <typename D> void impl_IConnectedAnimation<D>::Completed(event_token token) const
{
    check_hresult(WINRT_SHIM(IConnectedAnimation)->remove_Completed(token));
}

template <typename D> bool impl_IConnectedAnimation<D>::TryStart(const Windows::UI::Xaml::UIElement & destination) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IConnectedAnimation)->abi_TryStart(get_abi(destination), &returnValue));
    return returnValue;
}

template <typename D> void impl_IConnectedAnimation<D>::Cancel() const
{
    check_hresult(WINRT_SHIM(IConnectedAnimation)->abi_Cancel());
}

template <typename D> Windows::Foundation::TimeSpan impl_IConnectedAnimationService<D>::DefaultDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IConnectedAnimationService)->get_DefaultDuration(put_abi(value)));
    return value;
}

template <typename D> void impl_IConnectedAnimationService<D>::DefaultDuration(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IConnectedAnimationService)->put_DefaultDuration(get_abi(value)));
}

template <typename D> Windows::UI::Composition::CompositionEasingFunction impl_IConnectedAnimationService<D>::DefaultEasingFunction() const
{
    Windows::UI::Composition::CompositionEasingFunction value { nullptr };
    check_hresult(WINRT_SHIM(IConnectedAnimationService)->get_DefaultEasingFunction(put_abi(value)));
    return value;
}

template <typename D> void impl_IConnectedAnimationService<D>::DefaultEasingFunction(const Windows::UI::Composition::CompositionEasingFunction & value) const
{
    check_hresult(WINRT_SHIM(IConnectedAnimationService)->put_DefaultEasingFunction(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Animation::ConnectedAnimation impl_IConnectedAnimationService<D>::PrepareToAnimate(hstring_view key, const Windows::UI::Xaml::UIElement & source) const
{
    Windows::UI::Xaml::Media::Animation::ConnectedAnimation returnValue { nullptr };
    check_hresult(WINRT_SHIM(IConnectedAnimationService)->abi_PrepareToAnimate(get_abi(key), get_abi(source), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Media::Animation::ConnectedAnimation impl_IConnectedAnimationService<D>::GetAnimation(hstring_view key) const
{
    Windows::UI::Xaml::Media::Animation::ConnectedAnimation returnValue { nullptr };
    check_hresult(WINRT_SHIM(IConnectedAnimationService)->abi_GetAnimation(get_abi(key), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Media::Animation::ConnectedAnimationService impl_IConnectedAnimationServiceStatics<D>::GetForCurrentView() const
{
    Windows::UI::Xaml::Media::Animation::ConnectedAnimationService returnValue { nullptr };
    check_hresult(WINRT_SHIM(IConnectedAnimationServiceStatics)->abi_GetForCurrentView(put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_ICommonNavigationTransitionInfo<D>::IsStaggeringEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonNavigationTransitionInfo)->get_IsStaggeringEnabled(&value));
    return value;
}

template <typename D> void impl_ICommonNavigationTransitionInfo<D>::IsStaggeringEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ICommonNavigationTransitionInfo)->put_IsStaggeringEnabled(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ICommonNavigationTransitionInfoStatics<D>::IsStaggeringEnabledProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ICommonNavigationTransitionInfoStatics)->get_IsStaggeringEnabledProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ICommonNavigationTransitionInfoStatics<D>::IsStaggerElementProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ICommonNavigationTransitionInfoStatics)->get_IsStaggerElementProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICommonNavigationTransitionInfoStatics<D>::GetIsStaggerElement(const Windows::UI::Xaml::UIElement & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonNavigationTransitionInfoStatics)->abi_GetIsStaggerElement(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ICommonNavigationTransitionInfoStatics<D>::SetIsStaggerElement(const Windows::UI::Xaml::UIElement & element, bool value) const
{
    check_hresult(WINRT_SHIM(ICommonNavigationTransitionInfoStatics)->abi_SetIsStaggerElement(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::UIElement impl_IContinuumNavigationTransitionInfo<D>::ExitElement() const
{
    Windows::UI::Xaml::UIElement value { nullptr };
    check_hresult(WINRT_SHIM(IContinuumNavigationTransitionInfo)->get_ExitElement(put_abi(value)));
    return value;
}

template <typename D> void impl_IContinuumNavigationTransitionInfo<D>::ExitElement(const Windows::UI::Xaml::UIElement & value) const
{
    check_hresult(WINRT_SHIM(IContinuumNavigationTransitionInfo)->put_ExitElement(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IContinuumNavigationTransitionInfoStatics<D>::ExitElementProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IContinuumNavigationTransitionInfoStatics)->get_ExitElementProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IContinuumNavigationTransitionInfoStatics<D>::IsEntranceElementProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IContinuumNavigationTransitionInfoStatics)->get_IsEntranceElementProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_IContinuumNavigationTransitionInfoStatics<D>::GetIsEntranceElement(const Windows::UI::Xaml::UIElement & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IContinuumNavigationTransitionInfoStatics)->abi_GetIsEntranceElement(get_abi(element), &value));
    return value;
}

template <typename D> void impl_IContinuumNavigationTransitionInfoStatics<D>::SetIsEntranceElement(const Windows::UI::Xaml::UIElement & element, bool value) const
{
    check_hresult(WINRT_SHIM(IContinuumNavigationTransitionInfoStatics)->abi_SetIsEntranceElement(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IContinuumNavigationTransitionInfoStatics<D>::IsExitElementProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IContinuumNavigationTransitionInfoStatics)->get_IsExitElementProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_IContinuumNavigationTransitionInfoStatics<D>::GetIsExitElement(const Windows::UI::Xaml::UIElement & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IContinuumNavigationTransitionInfoStatics)->abi_GetIsExitElement(get_abi(element), &value));
    return value;
}

template <typename D> void impl_IContinuumNavigationTransitionInfoStatics<D>::SetIsExitElement(const Windows::UI::Xaml::UIElement & element, bool value) const
{
    check_hresult(WINRT_SHIM(IContinuumNavigationTransitionInfoStatics)->abi_SetIsExitElement(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IContinuumNavigationTransitionInfoStatics<D>::ExitElementContainerProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IContinuumNavigationTransitionInfoStatics)->get_ExitElementContainerProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_IContinuumNavigationTransitionInfoStatics<D>::GetExitElementContainer(const Windows::UI::Xaml::Controls::ListViewBase & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IContinuumNavigationTransitionInfoStatics)->abi_GetExitElementContainer(get_abi(element), &value));
    return value;
}

template <typename D> void impl_IContinuumNavigationTransitionInfoStatics<D>::SetExitElementContainer(const Windows::UI::Xaml::Controls::ListViewBase & element, bool value) const
{
    check_hresult(WINRT_SHIM(IContinuumNavigationTransitionInfoStatics)->abi_SetExitElementContainer(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IEntranceNavigationTransitionInfoStatics<D>::IsTargetElementProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IEntranceNavigationTransitionInfoStatics)->get_IsTargetElementProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_IEntranceNavigationTransitionInfoStatics<D>::GetIsTargetElement(const Windows::UI::Xaml::UIElement & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEntranceNavigationTransitionInfoStatics)->abi_GetIsTargetElement(get_abi(element), &value));
    return value;
}

template <typename D> void impl_IEntranceNavigationTransitionInfoStatics<D>::SetIsTargetElement(const Windows::UI::Xaml::UIElement & element, bool value) const
{
    check_hresult(WINRT_SHIM(IEntranceNavigationTransitionInfoStatics)->abi_SetIsTargetElement(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo impl_INavigationThemeTransition<D>::DefaultNavigationTransitionInfo() const
{
    Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo value { nullptr };
    check_hresult(WINRT_SHIM(INavigationThemeTransition)->get_DefaultNavigationTransitionInfo(put_abi(value)));
    return value;
}

template <typename D> void impl_INavigationThemeTransition<D>::DefaultNavigationTransitionInfo(const Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo & value) const
{
    check_hresult(WINRT_SHIM(INavigationThemeTransition)->put_DefaultNavigationTransitionInfo(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_INavigationThemeTransitionStatics<D>::DefaultNavigationTransitionInfoProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(INavigationThemeTransitionStatics)->get_DefaultNavigationTransitionInfoProperty(put_abi(value)));
    return value;
}

inline AddDeleteThemeTransition::AddDeleteThemeTransition() :
    AddDeleteThemeTransition(activate_instance<AddDeleteThemeTransition>())
{}

inline BackEase::BackEase() :
    BackEase(activate_instance<BackEase>())
{}

inline Windows::UI::Xaml::DependencyProperty BackEase::AmplitudeProperty()
{
    return get_activation_factory<BackEase, IBackEaseStatics>().AmplitudeProperty();
}

inline BeginStoryboard::BeginStoryboard() :
    BeginStoryboard(activate_instance<BeginStoryboard>())
{}

inline Windows::UI::Xaml::DependencyProperty BeginStoryboard::StoryboardProperty()
{
    return get_activation_factory<BeginStoryboard, IBeginStoryboardStatics>().StoryboardProperty();
}

inline BounceEase::BounceEase() :
    BounceEase(activate_instance<BounceEase>())
{}

inline Windows::UI::Xaml::DependencyProperty BounceEase::BouncesProperty()
{
    return get_activation_factory<BounceEase, IBounceEaseStatics>().BouncesProperty();
}

inline Windows::UI::Xaml::DependencyProperty BounceEase::BouncinessProperty()
{
    return get_activation_factory<BounceEase, IBounceEaseStatics>().BouncinessProperty();
}

inline CircleEase::CircleEase() :
    CircleEase(activate_instance<CircleEase>())
{}

inline ColorAnimation::ColorAnimation() :
    ColorAnimation(activate_instance<ColorAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty ColorAnimation::FromProperty()
{
    return get_activation_factory<ColorAnimation, IColorAnimationStatics>().FromProperty();
}

inline Windows::UI::Xaml::DependencyProperty ColorAnimation::ToProperty()
{
    return get_activation_factory<ColorAnimation, IColorAnimationStatics>().ToProperty();
}

inline Windows::UI::Xaml::DependencyProperty ColorAnimation::ByProperty()
{
    return get_activation_factory<ColorAnimation, IColorAnimationStatics>().ByProperty();
}

inline Windows::UI::Xaml::DependencyProperty ColorAnimation::EasingFunctionProperty()
{
    return get_activation_factory<ColorAnimation, IColorAnimationStatics>().EasingFunctionProperty();
}

inline Windows::UI::Xaml::DependencyProperty ColorAnimation::EnableDependentAnimationProperty()
{
    return get_activation_factory<ColorAnimation, IColorAnimationStatics>().EnableDependentAnimationProperty();
}

inline ColorAnimationUsingKeyFrames::ColorAnimationUsingKeyFrames() :
    ColorAnimationUsingKeyFrames(activate_instance<ColorAnimationUsingKeyFrames>())
{}

inline Windows::UI::Xaml::DependencyProperty ColorAnimationUsingKeyFrames::EnableDependentAnimationProperty()
{
    return get_activation_factory<ColorAnimationUsingKeyFrames, IColorAnimationUsingKeyFramesStatics>().EnableDependentAnimationProperty();
}

inline Windows::UI::Xaml::DependencyProperty ColorKeyFrame::ValueProperty()
{
    return get_activation_factory<ColorKeyFrame, IColorKeyFrameStatics>().ValueProperty();
}

inline Windows::UI::Xaml::DependencyProperty ColorKeyFrame::KeyTimeProperty()
{
    return get_activation_factory<ColorKeyFrame, IColorKeyFrameStatics>().KeyTimeProperty();
}

inline ColorKeyFrameCollection::ColorKeyFrameCollection() :
    ColorKeyFrameCollection(activate_instance<ColorKeyFrameCollection>())
{}

inline CommonNavigationTransitionInfo::CommonNavigationTransitionInfo() :
    CommonNavigationTransitionInfo(activate_instance<CommonNavigationTransitionInfo>())
{}

inline Windows::UI::Xaml::DependencyProperty CommonNavigationTransitionInfo::IsStaggeringEnabledProperty()
{
    return get_activation_factory<CommonNavigationTransitionInfo, ICommonNavigationTransitionInfoStatics>().IsStaggeringEnabledProperty();
}

inline Windows::UI::Xaml::DependencyProperty CommonNavigationTransitionInfo::IsStaggerElementProperty()
{
    return get_activation_factory<CommonNavigationTransitionInfo, ICommonNavigationTransitionInfoStatics>().IsStaggerElementProperty();
}

inline bool CommonNavigationTransitionInfo::GetIsStaggerElement(const Windows::UI::Xaml::UIElement & element)
{
    return get_activation_factory<CommonNavigationTransitionInfo, ICommonNavigationTransitionInfoStatics>().GetIsStaggerElement(element);
}

inline void CommonNavigationTransitionInfo::SetIsStaggerElement(const Windows::UI::Xaml::UIElement & element, bool value)
{
    get_activation_factory<CommonNavigationTransitionInfo, ICommonNavigationTransitionInfoStatics>().SetIsStaggerElement(element, value);
}

inline Windows::UI::Xaml::Media::Animation::ConnectedAnimationService ConnectedAnimationService::GetForCurrentView()
{
    return get_activation_factory<ConnectedAnimationService, IConnectedAnimationServiceStatics>().GetForCurrentView();
}

inline ContentThemeTransition::ContentThemeTransition() :
    ContentThemeTransition(activate_instance<ContentThemeTransition>())
{}

inline Windows::UI::Xaml::DependencyProperty ContentThemeTransition::HorizontalOffsetProperty()
{
    return get_activation_factory<ContentThemeTransition, IContentThemeTransitionStatics>().HorizontalOffsetProperty();
}

inline Windows::UI::Xaml::DependencyProperty ContentThemeTransition::VerticalOffsetProperty()
{
    return get_activation_factory<ContentThemeTransition, IContentThemeTransitionStatics>().VerticalOffsetProperty();
}

inline ContinuumNavigationTransitionInfo::ContinuumNavigationTransitionInfo() :
    ContinuumNavigationTransitionInfo(activate_instance<ContinuumNavigationTransitionInfo>())
{}

inline Windows::UI::Xaml::DependencyProperty ContinuumNavigationTransitionInfo::ExitElementProperty()
{
    return get_activation_factory<ContinuumNavigationTransitionInfo, IContinuumNavigationTransitionInfoStatics>().ExitElementProperty();
}

inline Windows::UI::Xaml::DependencyProperty ContinuumNavigationTransitionInfo::IsEntranceElementProperty()
{
    return get_activation_factory<ContinuumNavigationTransitionInfo, IContinuumNavigationTransitionInfoStatics>().IsEntranceElementProperty();
}

inline bool ContinuumNavigationTransitionInfo::GetIsEntranceElement(const Windows::UI::Xaml::UIElement & element)
{
    return get_activation_factory<ContinuumNavigationTransitionInfo, IContinuumNavigationTransitionInfoStatics>().GetIsEntranceElement(element);
}

inline void ContinuumNavigationTransitionInfo::SetIsEntranceElement(const Windows::UI::Xaml::UIElement & element, bool value)
{
    get_activation_factory<ContinuumNavigationTransitionInfo, IContinuumNavigationTransitionInfoStatics>().SetIsEntranceElement(element, value);
}

inline Windows::UI::Xaml::DependencyProperty ContinuumNavigationTransitionInfo::IsExitElementProperty()
{
    return get_activation_factory<ContinuumNavigationTransitionInfo, IContinuumNavigationTransitionInfoStatics>().IsExitElementProperty();
}

inline bool ContinuumNavigationTransitionInfo::GetIsExitElement(const Windows::UI::Xaml::UIElement & element)
{
    return get_activation_factory<ContinuumNavigationTransitionInfo, IContinuumNavigationTransitionInfoStatics>().GetIsExitElement(element);
}

inline void ContinuumNavigationTransitionInfo::SetIsExitElement(const Windows::UI::Xaml::UIElement & element, bool value)
{
    get_activation_factory<ContinuumNavigationTransitionInfo, IContinuumNavigationTransitionInfoStatics>().SetIsExitElement(element, value);
}

inline Windows::UI::Xaml::DependencyProperty ContinuumNavigationTransitionInfo::ExitElementContainerProperty()
{
    return get_activation_factory<ContinuumNavigationTransitionInfo, IContinuumNavigationTransitionInfoStatics>().ExitElementContainerProperty();
}

inline bool ContinuumNavigationTransitionInfo::GetExitElementContainer(const Windows::UI::Xaml::Controls::ListViewBase & element)
{
    return get_activation_factory<ContinuumNavigationTransitionInfo, IContinuumNavigationTransitionInfoStatics>().GetExitElementContainer(element);
}

inline void ContinuumNavigationTransitionInfo::SetExitElementContainer(const Windows::UI::Xaml::Controls::ListViewBase & element, bool value)
{
    get_activation_factory<ContinuumNavigationTransitionInfo, IContinuumNavigationTransitionInfoStatics>().SetExitElementContainer(element, value);
}

inline CubicEase::CubicEase() :
    CubicEase(activate_instance<CubicEase>())
{}

inline DiscreteColorKeyFrame::DiscreteColorKeyFrame() :
    DiscreteColorKeyFrame(activate_instance<DiscreteColorKeyFrame>())
{}

inline DiscreteDoubleKeyFrame::DiscreteDoubleKeyFrame() :
    DiscreteDoubleKeyFrame(activate_instance<DiscreteDoubleKeyFrame>())
{}

inline DiscreteObjectKeyFrame::DiscreteObjectKeyFrame() :
    DiscreteObjectKeyFrame(activate_instance<DiscreteObjectKeyFrame>())
{}

inline DiscretePointKeyFrame::DiscretePointKeyFrame() :
    DiscretePointKeyFrame(activate_instance<DiscretePointKeyFrame>())
{}

inline DoubleAnimation::DoubleAnimation() :
    DoubleAnimation(activate_instance<DoubleAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty DoubleAnimation::FromProperty()
{
    return get_activation_factory<DoubleAnimation, IDoubleAnimationStatics>().FromProperty();
}

inline Windows::UI::Xaml::DependencyProperty DoubleAnimation::ToProperty()
{
    return get_activation_factory<DoubleAnimation, IDoubleAnimationStatics>().ToProperty();
}

inline Windows::UI::Xaml::DependencyProperty DoubleAnimation::ByProperty()
{
    return get_activation_factory<DoubleAnimation, IDoubleAnimationStatics>().ByProperty();
}

inline Windows::UI::Xaml::DependencyProperty DoubleAnimation::EasingFunctionProperty()
{
    return get_activation_factory<DoubleAnimation, IDoubleAnimationStatics>().EasingFunctionProperty();
}

inline Windows::UI::Xaml::DependencyProperty DoubleAnimation::EnableDependentAnimationProperty()
{
    return get_activation_factory<DoubleAnimation, IDoubleAnimationStatics>().EnableDependentAnimationProperty();
}

inline DoubleAnimationUsingKeyFrames::DoubleAnimationUsingKeyFrames() :
    DoubleAnimationUsingKeyFrames(activate_instance<DoubleAnimationUsingKeyFrames>())
{}

inline Windows::UI::Xaml::DependencyProperty DoubleAnimationUsingKeyFrames::EnableDependentAnimationProperty()
{
    return get_activation_factory<DoubleAnimationUsingKeyFrames, IDoubleAnimationUsingKeyFramesStatics>().EnableDependentAnimationProperty();
}

inline Windows::UI::Xaml::DependencyProperty DoubleKeyFrame::ValueProperty()
{
    return get_activation_factory<DoubleKeyFrame, IDoubleKeyFrameStatics>().ValueProperty();
}

inline Windows::UI::Xaml::DependencyProperty DoubleKeyFrame::KeyTimeProperty()
{
    return get_activation_factory<DoubleKeyFrame, IDoubleKeyFrameStatics>().KeyTimeProperty();
}

inline DoubleKeyFrameCollection::DoubleKeyFrameCollection() :
    DoubleKeyFrameCollection(activate_instance<DoubleKeyFrameCollection>())
{}

inline DragItemThemeAnimation::DragItemThemeAnimation() :
    DragItemThemeAnimation(activate_instance<DragItemThemeAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty DragItemThemeAnimation::TargetNameProperty()
{
    return get_activation_factory<DragItemThemeAnimation, IDragItemThemeAnimationStatics>().TargetNameProperty();
}

inline DragOverThemeAnimation::DragOverThemeAnimation() :
    DragOverThemeAnimation(activate_instance<DragOverThemeAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty DragOverThemeAnimation::TargetNameProperty()
{
    return get_activation_factory<DragOverThemeAnimation, IDragOverThemeAnimationStatics>().TargetNameProperty();
}

inline Windows::UI::Xaml::DependencyProperty DragOverThemeAnimation::ToOffsetProperty()
{
    return get_activation_factory<DragOverThemeAnimation, IDragOverThemeAnimationStatics>().ToOffsetProperty();
}

inline Windows::UI::Xaml::DependencyProperty DragOverThemeAnimation::DirectionProperty()
{
    return get_activation_factory<DragOverThemeAnimation, IDragOverThemeAnimationStatics>().DirectionProperty();
}

inline DrillInNavigationTransitionInfo::DrillInNavigationTransitionInfo() :
    DrillInNavigationTransitionInfo(activate_instance<DrillInNavigationTransitionInfo>())
{}

inline DrillInThemeAnimation::DrillInThemeAnimation() :
    DrillInThemeAnimation(activate_instance<DrillInThemeAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty DrillInThemeAnimation::EntranceTargetNameProperty()
{
    return get_activation_factory<DrillInThemeAnimation, IDrillInThemeAnimationStatics>().EntranceTargetNameProperty();
}

inline Windows::UI::Xaml::DependencyProperty DrillInThemeAnimation::EntranceTargetProperty()
{
    return get_activation_factory<DrillInThemeAnimation, IDrillInThemeAnimationStatics>().EntranceTargetProperty();
}

inline Windows::UI::Xaml::DependencyProperty DrillInThemeAnimation::ExitTargetNameProperty()
{
    return get_activation_factory<DrillInThemeAnimation, IDrillInThemeAnimationStatics>().ExitTargetNameProperty();
}

inline Windows::UI::Xaml::DependencyProperty DrillInThemeAnimation::ExitTargetProperty()
{
    return get_activation_factory<DrillInThemeAnimation, IDrillInThemeAnimationStatics>().ExitTargetProperty();
}

inline DrillOutThemeAnimation::DrillOutThemeAnimation() :
    DrillOutThemeAnimation(activate_instance<DrillOutThemeAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty DrillOutThemeAnimation::EntranceTargetNameProperty()
{
    return get_activation_factory<DrillOutThemeAnimation, IDrillOutThemeAnimationStatics>().EntranceTargetNameProperty();
}

inline Windows::UI::Xaml::DependencyProperty DrillOutThemeAnimation::EntranceTargetProperty()
{
    return get_activation_factory<DrillOutThemeAnimation, IDrillOutThemeAnimationStatics>().EntranceTargetProperty();
}

inline Windows::UI::Xaml::DependencyProperty DrillOutThemeAnimation::ExitTargetNameProperty()
{
    return get_activation_factory<DrillOutThemeAnimation, IDrillOutThemeAnimationStatics>().ExitTargetNameProperty();
}

inline Windows::UI::Xaml::DependencyProperty DrillOutThemeAnimation::ExitTargetProperty()
{
    return get_activation_factory<DrillOutThemeAnimation, IDrillOutThemeAnimationStatics>().ExitTargetProperty();
}

inline DropTargetItemThemeAnimation::DropTargetItemThemeAnimation() :
    DropTargetItemThemeAnimation(activate_instance<DropTargetItemThemeAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty DropTargetItemThemeAnimation::TargetNameProperty()
{
    return get_activation_factory<DropTargetItemThemeAnimation, IDropTargetItemThemeAnimationStatics>().TargetNameProperty();
}

inline EasingColorKeyFrame::EasingColorKeyFrame() :
    EasingColorKeyFrame(activate_instance<EasingColorKeyFrame>())
{}

inline Windows::UI::Xaml::DependencyProperty EasingColorKeyFrame::EasingFunctionProperty()
{
    return get_activation_factory<EasingColorKeyFrame, IEasingColorKeyFrameStatics>().EasingFunctionProperty();
}

inline EasingDoubleKeyFrame::EasingDoubleKeyFrame() :
    EasingDoubleKeyFrame(activate_instance<EasingDoubleKeyFrame>())
{}

inline Windows::UI::Xaml::DependencyProperty EasingDoubleKeyFrame::EasingFunctionProperty()
{
    return get_activation_factory<EasingDoubleKeyFrame, IEasingDoubleKeyFrameStatics>().EasingFunctionProperty();
}

inline Windows::UI::Xaml::DependencyProperty EasingFunctionBase::EasingModeProperty()
{
    return get_activation_factory<EasingFunctionBase, IEasingFunctionBaseStatics>().EasingModeProperty();
}

inline EasingPointKeyFrame::EasingPointKeyFrame() :
    EasingPointKeyFrame(activate_instance<EasingPointKeyFrame>())
{}

inline Windows::UI::Xaml::DependencyProperty EasingPointKeyFrame::EasingFunctionProperty()
{
    return get_activation_factory<EasingPointKeyFrame, IEasingPointKeyFrameStatics>().EasingFunctionProperty();
}

inline EdgeUIThemeTransition::EdgeUIThemeTransition() :
    EdgeUIThemeTransition(activate_instance<EdgeUIThemeTransition>())
{}

inline Windows::UI::Xaml::DependencyProperty EdgeUIThemeTransition::EdgeProperty()
{
    return get_activation_factory<EdgeUIThemeTransition, IEdgeUIThemeTransitionStatics>().EdgeProperty();
}

inline ElasticEase::ElasticEase() :
    ElasticEase(activate_instance<ElasticEase>())
{}

inline Windows::UI::Xaml::DependencyProperty ElasticEase::OscillationsProperty()
{
    return get_activation_factory<ElasticEase, IElasticEaseStatics>().OscillationsProperty();
}

inline Windows::UI::Xaml::DependencyProperty ElasticEase::SpringinessProperty()
{
    return get_activation_factory<ElasticEase, IElasticEaseStatics>().SpringinessProperty();
}

inline EntranceNavigationTransitionInfo::EntranceNavigationTransitionInfo() :
    EntranceNavigationTransitionInfo(activate_instance<EntranceNavigationTransitionInfo>())
{}

inline Windows::UI::Xaml::DependencyProperty EntranceNavigationTransitionInfo::IsTargetElementProperty()
{
    return get_activation_factory<EntranceNavigationTransitionInfo, IEntranceNavigationTransitionInfoStatics>().IsTargetElementProperty();
}

inline bool EntranceNavigationTransitionInfo::GetIsTargetElement(const Windows::UI::Xaml::UIElement & element)
{
    return get_activation_factory<EntranceNavigationTransitionInfo, IEntranceNavigationTransitionInfoStatics>().GetIsTargetElement(element);
}

inline void EntranceNavigationTransitionInfo::SetIsTargetElement(const Windows::UI::Xaml::UIElement & element, bool value)
{
    get_activation_factory<EntranceNavigationTransitionInfo, IEntranceNavigationTransitionInfoStatics>().SetIsTargetElement(element, value);
}

inline EntranceThemeTransition::EntranceThemeTransition() :
    EntranceThemeTransition(activate_instance<EntranceThemeTransition>())
{}

inline Windows::UI::Xaml::DependencyProperty EntranceThemeTransition::FromHorizontalOffsetProperty()
{
    return get_activation_factory<EntranceThemeTransition, IEntranceThemeTransitionStatics>().FromHorizontalOffsetProperty();
}

inline Windows::UI::Xaml::DependencyProperty EntranceThemeTransition::FromVerticalOffsetProperty()
{
    return get_activation_factory<EntranceThemeTransition, IEntranceThemeTransitionStatics>().FromVerticalOffsetProperty();
}

inline Windows::UI::Xaml::DependencyProperty EntranceThemeTransition::IsStaggeringEnabledProperty()
{
    return get_activation_factory<EntranceThemeTransition, IEntranceThemeTransitionStatics>().IsStaggeringEnabledProperty();
}

inline ExponentialEase::ExponentialEase() :
    ExponentialEase(activate_instance<ExponentialEase>())
{}

inline Windows::UI::Xaml::DependencyProperty ExponentialEase::ExponentProperty()
{
    return get_activation_factory<ExponentialEase, IExponentialEaseStatics>().ExponentProperty();
}

inline FadeInThemeAnimation::FadeInThemeAnimation() :
    FadeInThemeAnimation(activate_instance<FadeInThemeAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty FadeInThemeAnimation::TargetNameProperty()
{
    return get_activation_factory<FadeInThemeAnimation, IFadeInThemeAnimationStatics>().TargetNameProperty();
}

inline FadeOutThemeAnimation::FadeOutThemeAnimation() :
    FadeOutThemeAnimation(activate_instance<FadeOutThemeAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty FadeOutThemeAnimation::TargetNameProperty()
{
    return get_activation_factory<FadeOutThemeAnimation, IFadeOutThemeAnimationStatics>().TargetNameProperty();
}

inline KeySpline::KeySpline() :
    KeySpline(activate_instance<KeySpline>())
{}

inline Windows::UI::Xaml::Media::Animation::KeyTime KeyTimeHelper::FromTimeSpan(const Windows::Foundation::TimeSpan & timeSpan)
{
    return get_activation_factory<KeyTimeHelper, IKeyTimeHelperStatics>().FromTimeSpan(timeSpan);
}

inline LinearColorKeyFrame::LinearColorKeyFrame() :
    LinearColorKeyFrame(activate_instance<LinearColorKeyFrame>())
{}

inline LinearDoubleKeyFrame::LinearDoubleKeyFrame() :
    LinearDoubleKeyFrame(activate_instance<LinearDoubleKeyFrame>())
{}

inline LinearPointKeyFrame::LinearPointKeyFrame() :
    LinearPointKeyFrame(activate_instance<LinearPointKeyFrame>())
{}

inline NavigationThemeTransition::NavigationThemeTransition() :
    NavigationThemeTransition(activate_instance<NavigationThemeTransition>())
{}

inline Windows::UI::Xaml::DependencyProperty NavigationThemeTransition::DefaultNavigationTransitionInfoProperty()
{
    return get_activation_factory<NavigationThemeTransition, INavigationThemeTransitionStatics>().DefaultNavigationTransitionInfoProperty();
}

inline ObjectAnimationUsingKeyFrames::ObjectAnimationUsingKeyFrames() :
    ObjectAnimationUsingKeyFrames(activate_instance<ObjectAnimationUsingKeyFrames>())
{}

inline Windows::UI::Xaml::DependencyProperty ObjectAnimationUsingKeyFrames::EnableDependentAnimationProperty()
{
    return get_activation_factory<ObjectAnimationUsingKeyFrames, IObjectAnimationUsingKeyFramesStatics>().EnableDependentAnimationProperty();
}

inline Windows::UI::Xaml::DependencyProperty ObjectKeyFrame::ValueProperty()
{
    return get_activation_factory<ObjectKeyFrame, IObjectKeyFrameStatics>().ValueProperty();
}

inline Windows::UI::Xaml::DependencyProperty ObjectKeyFrame::KeyTimeProperty()
{
    return get_activation_factory<ObjectKeyFrame, IObjectKeyFrameStatics>().KeyTimeProperty();
}

inline ObjectKeyFrameCollection::ObjectKeyFrameCollection() :
    ObjectKeyFrameCollection(activate_instance<ObjectKeyFrameCollection>())
{}

inline PaneThemeTransition::PaneThemeTransition() :
    PaneThemeTransition(activate_instance<PaneThemeTransition>())
{}

inline Windows::UI::Xaml::DependencyProperty PaneThemeTransition::EdgeProperty()
{
    return get_activation_factory<PaneThemeTransition, IPaneThemeTransitionStatics>().EdgeProperty();
}

inline PointAnimation::PointAnimation() :
    PointAnimation(activate_instance<PointAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty PointAnimation::FromProperty()
{
    return get_activation_factory<PointAnimation, IPointAnimationStatics>().FromProperty();
}

inline Windows::UI::Xaml::DependencyProperty PointAnimation::ToProperty()
{
    return get_activation_factory<PointAnimation, IPointAnimationStatics>().ToProperty();
}

inline Windows::UI::Xaml::DependencyProperty PointAnimation::ByProperty()
{
    return get_activation_factory<PointAnimation, IPointAnimationStatics>().ByProperty();
}

inline Windows::UI::Xaml::DependencyProperty PointAnimation::EasingFunctionProperty()
{
    return get_activation_factory<PointAnimation, IPointAnimationStatics>().EasingFunctionProperty();
}

inline Windows::UI::Xaml::DependencyProperty PointAnimation::EnableDependentAnimationProperty()
{
    return get_activation_factory<PointAnimation, IPointAnimationStatics>().EnableDependentAnimationProperty();
}

inline PointAnimationUsingKeyFrames::PointAnimationUsingKeyFrames() :
    PointAnimationUsingKeyFrames(activate_instance<PointAnimationUsingKeyFrames>())
{}

inline Windows::UI::Xaml::DependencyProperty PointAnimationUsingKeyFrames::EnableDependentAnimationProperty()
{
    return get_activation_factory<PointAnimationUsingKeyFrames, IPointAnimationUsingKeyFramesStatics>().EnableDependentAnimationProperty();
}

inline Windows::UI::Xaml::DependencyProperty PointKeyFrame::ValueProperty()
{
    return get_activation_factory<PointKeyFrame, IPointKeyFrameStatics>().ValueProperty();
}

inline Windows::UI::Xaml::DependencyProperty PointKeyFrame::KeyTimeProperty()
{
    return get_activation_factory<PointKeyFrame, IPointKeyFrameStatics>().KeyTimeProperty();
}

inline PointKeyFrameCollection::PointKeyFrameCollection() :
    PointKeyFrameCollection(activate_instance<PointKeyFrameCollection>())
{}

inline PointerDownThemeAnimation::PointerDownThemeAnimation() :
    PointerDownThemeAnimation(activate_instance<PointerDownThemeAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty PointerDownThemeAnimation::TargetNameProperty()
{
    return get_activation_factory<PointerDownThemeAnimation, IPointerDownThemeAnimationStatics>().TargetNameProperty();
}

inline PointerUpThemeAnimation::PointerUpThemeAnimation() :
    PointerUpThemeAnimation(activate_instance<PointerUpThemeAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty PointerUpThemeAnimation::TargetNameProperty()
{
    return get_activation_factory<PointerUpThemeAnimation, IPointerUpThemeAnimationStatics>().TargetNameProperty();
}

inline PopInThemeAnimation::PopInThemeAnimation() :
    PopInThemeAnimation(activate_instance<PopInThemeAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty PopInThemeAnimation::TargetNameProperty()
{
    return get_activation_factory<PopInThemeAnimation, IPopInThemeAnimationStatics>().TargetNameProperty();
}

inline Windows::UI::Xaml::DependencyProperty PopInThemeAnimation::FromHorizontalOffsetProperty()
{
    return get_activation_factory<PopInThemeAnimation, IPopInThemeAnimationStatics>().FromHorizontalOffsetProperty();
}

inline Windows::UI::Xaml::DependencyProperty PopInThemeAnimation::FromVerticalOffsetProperty()
{
    return get_activation_factory<PopInThemeAnimation, IPopInThemeAnimationStatics>().FromVerticalOffsetProperty();
}

inline PopOutThemeAnimation::PopOutThemeAnimation() :
    PopOutThemeAnimation(activate_instance<PopOutThemeAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty PopOutThemeAnimation::TargetNameProperty()
{
    return get_activation_factory<PopOutThemeAnimation, IPopOutThemeAnimationStatics>().TargetNameProperty();
}

inline PopupThemeTransition::PopupThemeTransition() :
    PopupThemeTransition(activate_instance<PopupThemeTransition>())
{}

inline Windows::UI::Xaml::DependencyProperty PopupThemeTransition::FromHorizontalOffsetProperty()
{
    return get_activation_factory<PopupThemeTransition, IPopupThemeTransitionStatics>().FromHorizontalOffsetProperty();
}

inline Windows::UI::Xaml::DependencyProperty PopupThemeTransition::FromVerticalOffsetProperty()
{
    return get_activation_factory<PopupThemeTransition, IPopupThemeTransitionStatics>().FromVerticalOffsetProperty();
}

inline PowerEase::PowerEase() :
    PowerEase(activate_instance<PowerEase>())
{}

inline Windows::UI::Xaml::DependencyProperty PowerEase::PowerProperty()
{
    return get_activation_factory<PowerEase, IPowerEaseStatics>().PowerProperty();
}

inline QuadraticEase::QuadraticEase() :
    QuadraticEase(activate_instance<QuadraticEase>())
{}

inline QuarticEase::QuarticEase() :
    QuarticEase(activate_instance<QuarticEase>())
{}

inline QuinticEase::QuinticEase() :
    QuinticEase(activate_instance<QuinticEase>())
{}

inline ReorderThemeTransition::ReorderThemeTransition() :
    ReorderThemeTransition(activate_instance<ReorderThemeTransition>())
{}

inline Windows::UI::Xaml::Media::Animation::RepeatBehavior RepeatBehaviorHelper::Forever()
{
    return get_activation_factory<RepeatBehaviorHelper, IRepeatBehaviorHelperStatics>().Forever();
}

inline Windows::UI::Xaml::Media::Animation::RepeatBehavior RepeatBehaviorHelper::FromCount(double count)
{
    return get_activation_factory<RepeatBehaviorHelper, IRepeatBehaviorHelperStatics>().FromCount(count);
}

inline Windows::UI::Xaml::Media::Animation::RepeatBehavior RepeatBehaviorHelper::FromDuration(const Windows::Foundation::TimeSpan & duration)
{
    return get_activation_factory<RepeatBehaviorHelper, IRepeatBehaviorHelperStatics>().FromDuration(duration);
}

inline bool RepeatBehaviorHelper::GetHasCount(const Windows::UI::Xaml::Media::Animation::RepeatBehavior & target)
{
    return get_activation_factory<RepeatBehaviorHelper, IRepeatBehaviorHelperStatics>().GetHasCount(target);
}

inline bool RepeatBehaviorHelper::GetHasDuration(const Windows::UI::Xaml::Media::Animation::RepeatBehavior & target)
{
    return get_activation_factory<RepeatBehaviorHelper, IRepeatBehaviorHelperStatics>().GetHasDuration(target);
}

inline bool RepeatBehaviorHelper::Equals(const Windows::UI::Xaml::Media::Animation::RepeatBehavior & target, const Windows::UI::Xaml::Media::Animation::RepeatBehavior & value)
{
    return get_activation_factory<RepeatBehaviorHelper, IRepeatBehaviorHelperStatics>().Equals(target, value);
}

inline RepositionThemeAnimation::RepositionThemeAnimation() :
    RepositionThemeAnimation(activate_instance<RepositionThemeAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty RepositionThemeAnimation::TargetNameProperty()
{
    return get_activation_factory<RepositionThemeAnimation, IRepositionThemeAnimationStatics>().TargetNameProperty();
}

inline Windows::UI::Xaml::DependencyProperty RepositionThemeAnimation::FromHorizontalOffsetProperty()
{
    return get_activation_factory<RepositionThemeAnimation, IRepositionThemeAnimationStatics>().FromHorizontalOffsetProperty();
}

inline Windows::UI::Xaml::DependencyProperty RepositionThemeAnimation::FromVerticalOffsetProperty()
{
    return get_activation_factory<RepositionThemeAnimation, IRepositionThemeAnimationStatics>().FromVerticalOffsetProperty();
}

inline RepositionThemeTransition::RepositionThemeTransition() :
    RepositionThemeTransition(activate_instance<RepositionThemeTransition>())
{}

inline Windows::UI::Xaml::DependencyProperty RepositionThemeTransition::IsStaggeringEnabledProperty()
{
    return get_activation_factory<RepositionThemeTransition, IRepositionThemeTransitionStatics2>().IsStaggeringEnabledProperty();
}

inline SineEase::SineEase() :
    SineEase(activate_instance<SineEase>())
{}

inline SlideNavigationTransitionInfo::SlideNavigationTransitionInfo() :
    SlideNavigationTransitionInfo(activate_instance<SlideNavigationTransitionInfo>())
{}

inline SplineColorKeyFrame::SplineColorKeyFrame() :
    SplineColorKeyFrame(activate_instance<SplineColorKeyFrame>())
{}

inline Windows::UI::Xaml::DependencyProperty SplineColorKeyFrame::KeySplineProperty()
{
    return get_activation_factory<SplineColorKeyFrame, ISplineColorKeyFrameStatics>().KeySplineProperty();
}

inline SplineDoubleKeyFrame::SplineDoubleKeyFrame() :
    SplineDoubleKeyFrame(activate_instance<SplineDoubleKeyFrame>())
{}

inline Windows::UI::Xaml::DependencyProperty SplineDoubleKeyFrame::KeySplineProperty()
{
    return get_activation_factory<SplineDoubleKeyFrame, ISplineDoubleKeyFrameStatics>().KeySplineProperty();
}

inline SplinePointKeyFrame::SplinePointKeyFrame() :
    SplinePointKeyFrame(activate_instance<SplinePointKeyFrame>())
{}

inline Windows::UI::Xaml::DependencyProperty SplinePointKeyFrame::KeySplineProperty()
{
    return get_activation_factory<SplinePointKeyFrame, ISplinePointKeyFrameStatics>().KeySplineProperty();
}

inline SplitCloseThemeAnimation::SplitCloseThemeAnimation() :
    SplitCloseThemeAnimation(activate_instance<SplitCloseThemeAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty SplitCloseThemeAnimation::OpenedTargetNameProperty()
{
    return get_activation_factory<SplitCloseThemeAnimation, ISplitCloseThemeAnimationStatics>().OpenedTargetNameProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitCloseThemeAnimation::OpenedTargetProperty()
{
    return get_activation_factory<SplitCloseThemeAnimation, ISplitCloseThemeAnimationStatics>().OpenedTargetProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitCloseThemeAnimation::ClosedTargetNameProperty()
{
    return get_activation_factory<SplitCloseThemeAnimation, ISplitCloseThemeAnimationStatics>().ClosedTargetNameProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitCloseThemeAnimation::ClosedTargetProperty()
{
    return get_activation_factory<SplitCloseThemeAnimation, ISplitCloseThemeAnimationStatics>().ClosedTargetProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitCloseThemeAnimation::ContentTargetNameProperty()
{
    return get_activation_factory<SplitCloseThemeAnimation, ISplitCloseThemeAnimationStatics>().ContentTargetNameProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitCloseThemeAnimation::ContentTargetProperty()
{
    return get_activation_factory<SplitCloseThemeAnimation, ISplitCloseThemeAnimationStatics>().ContentTargetProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitCloseThemeAnimation::OpenedLengthProperty()
{
    return get_activation_factory<SplitCloseThemeAnimation, ISplitCloseThemeAnimationStatics>().OpenedLengthProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitCloseThemeAnimation::ClosedLengthProperty()
{
    return get_activation_factory<SplitCloseThemeAnimation, ISplitCloseThemeAnimationStatics>().ClosedLengthProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitCloseThemeAnimation::OffsetFromCenterProperty()
{
    return get_activation_factory<SplitCloseThemeAnimation, ISplitCloseThemeAnimationStatics>().OffsetFromCenterProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitCloseThemeAnimation::ContentTranslationDirectionProperty()
{
    return get_activation_factory<SplitCloseThemeAnimation, ISplitCloseThemeAnimationStatics>().ContentTranslationDirectionProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitCloseThemeAnimation::ContentTranslationOffsetProperty()
{
    return get_activation_factory<SplitCloseThemeAnimation, ISplitCloseThemeAnimationStatics>().ContentTranslationOffsetProperty();
}

inline SplitOpenThemeAnimation::SplitOpenThemeAnimation() :
    SplitOpenThemeAnimation(activate_instance<SplitOpenThemeAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty SplitOpenThemeAnimation::OpenedTargetNameProperty()
{
    return get_activation_factory<SplitOpenThemeAnimation, ISplitOpenThemeAnimationStatics>().OpenedTargetNameProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitOpenThemeAnimation::OpenedTargetProperty()
{
    return get_activation_factory<SplitOpenThemeAnimation, ISplitOpenThemeAnimationStatics>().OpenedTargetProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitOpenThemeAnimation::ClosedTargetNameProperty()
{
    return get_activation_factory<SplitOpenThemeAnimation, ISplitOpenThemeAnimationStatics>().ClosedTargetNameProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitOpenThemeAnimation::ClosedTargetProperty()
{
    return get_activation_factory<SplitOpenThemeAnimation, ISplitOpenThemeAnimationStatics>().ClosedTargetProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitOpenThemeAnimation::ContentTargetNameProperty()
{
    return get_activation_factory<SplitOpenThemeAnimation, ISplitOpenThemeAnimationStatics>().ContentTargetNameProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitOpenThemeAnimation::ContentTargetProperty()
{
    return get_activation_factory<SplitOpenThemeAnimation, ISplitOpenThemeAnimationStatics>().ContentTargetProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitOpenThemeAnimation::OpenedLengthProperty()
{
    return get_activation_factory<SplitOpenThemeAnimation, ISplitOpenThemeAnimationStatics>().OpenedLengthProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitOpenThemeAnimation::ClosedLengthProperty()
{
    return get_activation_factory<SplitOpenThemeAnimation, ISplitOpenThemeAnimationStatics>().ClosedLengthProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitOpenThemeAnimation::OffsetFromCenterProperty()
{
    return get_activation_factory<SplitOpenThemeAnimation, ISplitOpenThemeAnimationStatics>().OffsetFromCenterProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitOpenThemeAnimation::ContentTranslationDirectionProperty()
{
    return get_activation_factory<SplitOpenThemeAnimation, ISplitOpenThemeAnimationStatics>().ContentTranslationDirectionProperty();
}

inline Windows::UI::Xaml::DependencyProperty SplitOpenThemeAnimation::ContentTranslationOffsetProperty()
{
    return get_activation_factory<SplitOpenThemeAnimation, ISplitOpenThemeAnimationStatics>().ContentTranslationOffsetProperty();
}

inline Storyboard::Storyboard() :
    Storyboard(activate_instance<Storyboard>())
{}

inline Windows::UI::Xaml::DependencyProperty Storyboard::TargetPropertyProperty()
{
    return get_activation_factory<Storyboard, IStoryboardStatics>().TargetPropertyProperty();
}

inline hstring Storyboard::GetTargetProperty(const Windows::UI::Xaml::Media::Animation::Timeline & element)
{
    return get_activation_factory<Storyboard, IStoryboardStatics>().GetTargetProperty(element);
}

inline void Storyboard::SetTargetProperty(const Windows::UI::Xaml::Media::Animation::Timeline & element, hstring_view path)
{
    get_activation_factory<Storyboard, IStoryboardStatics>().SetTargetProperty(element, path);
}

inline Windows::UI::Xaml::DependencyProperty Storyboard::TargetNameProperty()
{
    return get_activation_factory<Storyboard, IStoryboardStatics>().TargetNameProperty();
}

inline hstring Storyboard::GetTargetName(const Windows::UI::Xaml::Media::Animation::Timeline & element)
{
    return get_activation_factory<Storyboard, IStoryboardStatics>().GetTargetName(element);
}

inline void Storyboard::SetTargetName(const Windows::UI::Xaml::Media::Animation::Timeline & element, hstring_view name)
{
    get_activation_factory<Storyboard, IStoryboardStatics>().SetTargetName(element, name);
}

inline void Storyboard::SetTarget(const Windows::UI::Xaml::Media::Animation::Timeline & timeline, const Windows::UI::Xaml::DependencyObject & target)
{
    get_activation_factory<Storyboard, IStoryboardStatics>().SetTarget(timeline, target);
}

inline SuppressNavigationTransitionInfo::SuppressNavigationTransitionInfo() :
    SuppressNavigationTransitionInfo(activate_instance<SuppressNavigationTransitionInfo>())
{}

inline SwipeBackThemeAnimation::SwipeBackThemeAnimation() :
    SwipeBackThemeAnimation(activate_instance<SwipeBackThemeAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty SwipeBackThemeAnimation::TargetNameProperty()
{
    return get_activation_factory<SwipeBackThemeAnimation, ISwipeBackThemeAnimationStatics>().TargetNameProperty();
}

inline Windows::UI::Xaml::DependencyProperty SwipeBackThemeAnimation::FromHorizontalOffsetProperty()
{
    return get_activation_factory<SwipeBackThemeAnimation, ISwipeBackThemeAnimationStatics>().FromHorizontalOffsetProperty();
}

inline Windows::UI::Xaml::DependencyProperty SwipeBackThemeAnimation::FromVerticalOffsetProperty()
{
    return get_activation_factory<SwipeBackThemeAnimation, ISwipeBackThemeAnimationStatics>().FromVerticalOffsetProperty();
}

inline SwipeHintThemeAnimation::SwipeHintThemeAnimation() :
    SwipeHintThemeAnimation(activate_instance<SwipeHintThemeAnimation>())
{}

inline Windows::UI::Xaml::DependencyProperty SwipeHintThemeAnimation::TargetNameProperty()
{
    return get_activation_factory<SwipeHintThemeAnimation, ISwipeHintThemeAnimationStatics>().TargetNameProperty();
}

inline Windows::UI::Xaml::DependencyProperty SwipeHintThemeAnimation::ToHorizontalOffsetProperty()
{
    return get_activation_factory<SwipeHintThemeAnimation, ISwipeHintThemeAnimationStatics>().ToHorizontalOffsetProperty();
}

inline Windows::UI::Xaml::DependencyProperty SwipeHintThemeAnimation::ToVerticalOffsetProperty()
{
    return get_activation_factory<SwipeHintThemeAnimation, ISwipeHintThemeAnimationStatics>().ToVerticalOffsetProperty();
}

inline bool Timeline::AllowDependentAnimations()
{
    return get_activation_factory<Timeline, ITimelineStatics>().AllowDependentAnimations();
}

inline void Timeline::AllowDependentAnimations(bool value)
{
    get_activation_factory<Timeline, ITimelineStatics>().AllowDependentAnimations(value);
}

inline Windows::UI::Xaml::DependencyProperty Timeline::AutoReverseProperty()
{
    return get_activation_factory<Timeline, ITimelineStatics>().AutoReverseProperty();
}

inline Windows::UI::Xaml::DependencyProperty Timeline::BeginTimeProperty()
{
    return get_activation_factory<Timeline, ITimelineStatics>().BeginTimeProperty();
}

inline Windows::UI::Xaml::DependencyProperty Timeline::DurationProperty()
{
    return get_activation_factory<Timeline, ITimelineStatics>().DurationProperty();
}

inline Windows::UI::Xaml::DependencyProperty Timeline::SpeedRatioProperty()
{
    return get_activation_factory<Timeline, ITimelineStatics>().SpeedRatioProperty();
}

inline Windows::UI::Xaml::DependencyProperty Timeline::FillBehaviorProperty()
{
    return get_activation_factory<Timeline, ITimelineStatics>().FillBehaviorProperty();
}

inline Windows::UI::Xaml::DependencyProperty Timeline::RepeatBehaviorProperty()
{
    return get_activation_factory<Timeline, ITimelineStatics>().RepeatBehaviorProperty();
}

inline TimelineCollection::TimelineCollection() :
    TimelineCollection(activate_instance<TimelineCollection>())
{}

inline TransitionCollection::TransitionCollection() :
    TransitionCollection(activate_instance<TransitionCollection>())
{}

}

}
#pragma warning(pop)
