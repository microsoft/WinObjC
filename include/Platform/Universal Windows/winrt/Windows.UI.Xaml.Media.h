// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Xaml.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Media.Playback.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.UI.Xaml.Media.Media3D.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.UI.Xaml.Media.3.h"
#include "Windows.UI.Xaml.h"
#include "Windows.Foundation.Collections.h"
#include "internal/Windows.UI.Xaml.Media.4.h"
#include "internal/Windows.UI.Xaml.Media.5.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Media {

template <typename L> RateChangedRoutedEventHandler::RateChangedRoutedEventHandler(L lambda) :
    RateChangedRoutedEventHandler(impl::make_delegate<impl_RateChangedRoutedEventHandler<L>, RateChangedRoutedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> RateChangedRoutedEventHandler::RateChangedRoutedEventHandler(F * function) :
    RateChangedRoutedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> RateChangedRoutedEventHandler::RateChangedRoutedEventHandler(O * object, M method) :
    RateChangedRoutedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void RateChangedRoutedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Media::RateChangedRoutedEventArgs & e) const
{
    check_hresult((*(abi<RateChangedRoutedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> TimelineMarkerRoutedEventHandler::TimelineMarkerRoutedEventHandler(L lambda) :
    TimelineMarkerRoutedEventHandler(impl::make_delegate<impl_TimelineMarkerRoutedEventHandler<L>, TimelineMarkerRoutedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> TimelineMarkerRoutedEventHandler::TimelineMarkerRoutedEventHandler(F * function) :
    TimelineMarkerRoutedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> TimelineMarkerRoutedEventHandler::TimelineMarkerRoutedEventHandler(O * object, M method) :
    TimelineMarkerRoutedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void TimelineMarkerRoutedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Media::TimelineMarkerRoutedEventArgs & e) const
{
    check_hresult((*(abi<TimelineMarkerRoutedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IArcSegment> : produce_base<D, Windows::UI::Xaml::Media::IArcSegment>
{
    HRESULT __stdcall get_Point(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Point());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Point(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Point(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Size(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Size());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Size(impl::abi_arg_in<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Size(*reinterpret_cast<const Windows::Foundation::Size *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationAngle(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationAngle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RotationAngle(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngle(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsLargeArc(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsLargeArc());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsLargeArc(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsLargeArc(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SweepDirection(Windows::UI::Xaml::Media::SweepDirection * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SweepDirection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SweepDirection(Windows::UI::Xaml::Media::SweepDirection value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SweepDirection(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IArcSegmentStatics> : produce_base<D, Windows::UI::Xaml::Media::IArcSegmentStatics>
{
    HRESULT __stdcall get_PointProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SizeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SizeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationAngleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationAngleProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsLargeArcProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsLargeArcProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SweepDirectionProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SweepDirectionProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IBezierSegment> : produce_base<D, Windows::UI::Xaml::Media::IBezierSegment>
{
    HRESULT __stdcall get_Point1(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Point1());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Point1(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Point1(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Point2(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Point2());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Point2(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Point2(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Point3(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Point3());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Point3(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Point3(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IBezierSegmentStatics> : produce_base<D, Windows::UI::Xaml::Media::IBezierSegmentStatics>
{
    HRESULT __stdcall get_Point1Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Point1Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Point2Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Point2Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Point3Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Point3Property());
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
struct produce<D, Windows::UI::Xaml::Media::IBitmapCache> : produce_base<D, Windows::UI::Xaml::Media::IBitmapCache>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IBrush> : produce_base<D, Windows::UI::Xaml::Media::IBrush>
{
    HRESULT __stdcall get_Opacity(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Opacity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Opacity(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Opacity(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Transform(impl::abi_arg_out<Windows::UI::Xaml::Media::ITransform> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Transform());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Transform(impl::abi_arg_in<Windows::UI::Xaml::Media::ITransform> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Transform(*reinterpret_cast<const Windows::UI::Xaml::Media::Transform *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RelativeTransform(impl::abi_arg_out<Windows::UI::Xaml::Media::ITransform> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RelativeTransform());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RelativeTransform(impl::abi_arg_in<Windows::UI::Xaml::Media::ITransform> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RelativeTransform(*reinterpret_cast<const Windows::UI::Xaml::Media::Transform *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IBrushFactory> : produce_base<D, Windows::UI::Xaml::Media::IBrushFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::IBrush> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::Media::IBrushStatics> : produce_base<D, Windows::UI::Xaml::Media::IBrushStatics>
{
    HRESULT __stdcall get_OpacityProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpacityProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransformProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransformProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RelativeTransformProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RelativeTransformProperty());
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
struct produce<D, Windows::UI::Xaml::Media::ICacheMode> : produce_base<D, Windows::UI::Xaml::Media::ICacheMode>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ICacheModeFactory> : produce_base<D, Windows::UI::Xaml::Media::ICacheModeFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::ICacheMode> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::Media::ICompositeTransform> : produce_base<D, Windows::UI::Xaml::Media::ICompositeTransform>
{
    HRESULT __stdcall get_CenterX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CenterX(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CenterY(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScaleX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScaleX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ScaleX(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScaleX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScaleY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScaleY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ScaleY(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScaleY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SkewX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SkewX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SkewX(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SkewX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SkewY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SkewY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SkewY(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SkewY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Rotation(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Rotation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Rotation(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rotation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TranslateX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TranslateX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TranslateX(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TranslateX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TranslateY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TranslateY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TranslateY(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TranslateY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ICompositeTransformStatics> : produce_base<D, Windows::UI::Xaml::Media::ICompositeTransformStatics>
{
    HRESULT __stdcall get_CenterXProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterXProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterYProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterYProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScaleXProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScaleXProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScaleYProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScaleYProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SkewXProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SkewXProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SkewYProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SkewYProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TranslateXProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TranslateXProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TranslateYProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TranslateYProperty());
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
struct produce<D, Windows::UI::Xaml::Media::ICompositionTarget> : produce_base<D, Windows::UI::Xaml::Media::ICompositionTarget>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ICompositionTargetStatics> : produce_base<D, Windows::UI::Xaml::Media::ICompositionTargetStatics>
{
    HRESULT __stdcall add_Rendering(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Rendering(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Rendering(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rendering(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SurfaceContentsLost(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SurfaceContentsLost(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SurfaceContentsLost(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SurfaceContentsLost(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IEllipseGeometry> : produce_base<D, Windows::UI::Xaml::Media::IEllipseGeometry>
{
    HRESULT __stdcall get_Center(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Center());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Center(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Center(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RadiusX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RadiusX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RadiusX(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RadiusX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RadiusY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RadiusY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RadiusY(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RadiusY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IEllipseGeometryStatics> : produce_base<D, Windows::UI::Xaml::Media::IEllipseGeometryStatics>
{
    HRESULT __stdcall get_CenterProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RadiusXProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RadiusXProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RadiusYProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RadiusYProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IFontFamily> : produce_base<D, Windows::UI::Xaml::Media::IFontFamily>
{
    HRESULT __stdcall get_Source(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
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
struct produce<D, Windows::UI::Xaml::Media::IFontFamilyFactory> : produce_base<D, Windows::UI::Xaml::Media::IFontFamilyFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithName(impl::abi_arg_in<hstring> familyName, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::IFontFamily> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithName(*reinterpret_cast<const hstring *>(&familyName), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Media::IFontFamilyStatics2> : produce_base<D, Windows::UI::Xaml::Media::IFontFamilyStatics2>
{
    HRESULT __stdcall get_XamlAutoFontFamily(impl::abi_arg_out<Windows::UI::Xaml::Media::IFontFamily> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().XamlAutoFontFamily());
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
struct produce<D, Windows::UI::Xaml::Media::IGeneralTransform> : produce_base<D, Windows::UI::Xaml::Media::IGeneralTransform>
{
    HRESULT __stdcall get_Inverse(impl::abi_arg_out<Windows::UI::Xaml::Media::IGeneralTransform> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Inverse());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TransformPoint(impl::abi_arg_in<Windows::Foundation::Point> point, impl::abi_arg_out<Windows::Foundation::Point> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TransformPoint(*reinterpret_cast<const Windows::Foundation::Point *>(&point)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryTransform(impl::abi_arg_in<Windows::Foundation::Point> inPoint, impl::abi_arg_out<Windows::Foundation::Point> outPoint, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TryTransform(*reinterpret_cast<const Windows::Foundation::Point *>(&inPoint), *outPoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TransformBounds(impl::abi_arg_in<Windows::Foundation::Rect> rect, impl::abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TransformBounds(*reinterpret_cast<const Windows::Foundation::Rect *>(&rect)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IGeneralTransformFactory> : produce_base<D, Windows::UI::Xaml::Media::IGeneralTransformFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::IGeneralTransform> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::Media::IGeneralTransformOverrides> : produce_base<D, Windows::UI::Xaml::Media::IGeneralTransformOverrides>
{
    HRESULT __stdcall get_InverseCore(impl::abi_arg_out<Windows::UI::Xaml::Media::IGeneralTransform> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InverseCore());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryTransformCore(impl::abi_arg_in<Windows::Foundation::Point> inPoint, impl::abi_arg_out<Windows::Foundation::Point> outPoint, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TryTransformCore(*reinterpret_cast<const Windows::Foundation::Point *>(&inPoint), *outPoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TransformBoundsCore(impl::abi_arg_in<Windows::Foundation::Rect> rect, impl::abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TransformBoundsCore(*reinterpret_cast<const Windows::Foundation::Rect *>(&rect)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IGeometry> : produce_base<D, Windows::UI::Xaml::Media::IGeometry>
{
    HRESULT __stdcall get_Transform(impl::abi_arg_out<Windows::UI::Xaml::Media::ITransform> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Transform());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Transform(impl::abi_arg_in<Windows::UI::Xaml::Media::ITransform> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Transform(*reinterpret_cast<const Windows::UI::Xaml::Media::Transform *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Bounds(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bounds());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IGeometryFactory> : produce_base<D, Windows::UI::Xaml::Media::IGeometryFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IGeometryGroup> : produce_base<D, Windows::UI::Xaml::Media::IGeometryGroup>
{
    HRESULT __stdcall get_FillRule(Windows::UI::Xaml::Media::FillRule * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FillRule());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FillRule(Windows::UI::Xaml::Media::FillRule value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FillRule(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Children(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Geometry>> value) noexcept override
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

    HRESULT __stdcall put_Children(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Geometry>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Children(*reinterpret_cast<const Windows::UI::Xaml::Media::GeometryCollection *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IGeometryGroupStatics> : produce_base<D, Windows::UI::Xaml::Media::IGeometryGroupStatics>
{
    HRESULT __stdcall get_FillRuleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FillRuleProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ChildrenProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChildrenProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IGeometryStatics> : produce_base<D, Windows::UI::Xaml::Media::IGeometryStatics>
{
    HRESULT __stdcall get_Empty(impl::abi_arg_out<Windows::UI::Xaml::Media::IGeometry> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Empty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StandardFlatteningTolerance(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StandardFlatteningTolerance());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransformProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransformProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IGradientBrush> : produce_base<D, Windows::UI::Xaml::Media::IGradientBrush>
{
    HRESULT __stdcall get_SpreadMethod(Windows::UI::Xaml::Media::GradientSpreadMethod * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpreadMethod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SpreadMethod(Windows::UI::Xaml::Media::GradientSpreadMethod value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SpreadMethod(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MappingMode(Windows::UI::Xaml::Media::BrushMappingMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MappingMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MappingMode(Windows::UI::Xaml::Media::BrushMappingMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MappingMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ColorInterpolationMode(Windows::UI::Xaml::Media::ColorInterpolationMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ColorInterpolationMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ColorInterpolationMode(Windows::UI::Xaml::Media::ColorInterpolationMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ColorInterpolationMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GradientStops(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::GradientStop>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GradientStops());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_GradientStops(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::GradientStop>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GradientStops(*reinterpret_cast<const Windows::UI::Xaml::Media::GradientStopCollection *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IGradientBrushFactory> : produce_base<D, Windows::UI::Xaml::Media::IGradientBrushFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::IGradientBrush> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::Media::IGradientBrushStatics> : produce_base<D, Windows::UI::Xaml::Media::IGradientBrushStatics>
{
    HRESULT __stdcall get_SpreadMethodProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpreadMethodProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MappingModeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MappingModeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ColorInterpolationModeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ColorInterpolationModeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GradientStopsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GradientStopsProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IGradientStop> : produce_base<D, Windows::UI::Xaml::Media::IGradientStop>
{
    HRESULT __stdcall get_Color(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Color());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Color(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Offset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Offset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Offset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IGradientStopStatics> : produce_base<D, Windows::UI::Xaml::Media::IGradientStopStatics>
{
    HRESULT __stdcall get_ColorProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ColorProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OffsetProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IImageBrush> : produce_base<D, Windows::UI::Xaml::Media::IImageBrush>
{
    HRESULT __stdcall get_ImageSource(impl::abi_arg_out<Windows::UI::Xaml::Media::IImageSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImageSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ImageSource(impl::abi_arg_in<Windows::UI::Xaml::Media::IImageSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ImageSource(*reinterpret_cast<const Windows::UI::Xaml::Media::ImageSource *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ImageFailed(impl::abi_arg_in<Windows::UI::Xaml::ExceptionRoutedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ImageFailed(*reinterpret_cast<const Windows::UI::Xaml::ExceptionRoutedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ImageFailed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ImageFailed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ImageOpened(impl::abi_arg_in<Windows::UI::Xaml::RoutedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ImageOpened(*reinterpret_cast<const Windows::UI::Xaml::RoutedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ImageOpened(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ImageOpened(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IImageBrushStatics> : produce_base<D, Windows::UI::Xaml::Media::IImageBrushStatics>
{
    HRESULT __stdcall get_ImageSourceProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImageSourceProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IImageSource> : produce_base<D, Windows::UI::Xaml::Media::IImageSource>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IImageSourceFactory> : produce_base<D, Windows::UI::Xaml::Media::IImageSourceFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ILineGeometry> : produce_base<D, Windows::UI::Xaml::Media::ILineGeometry>
{
    HRESULT __stdcall get_StartPoint(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartPoint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StartPoint(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartPoint(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndPoint(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndPoint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EndPoint(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EndPoint(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ILineGeometryStatics> : produce_base<D, Windows::UI::Xaml::Media::ILineGeometryStatics>
{
    HRESULT __stdcall get_StartPointProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartPointProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndPointProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndPointProperty());
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
struct produce<D, Windows::UI::Xaml::Media::ILineSegment> : produce_base<D, Windows::UI::Xaml::Media::ILineSegment>
{
    HRESULT __stdcall get_Point(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Point());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Point(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Point(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ILineSegmentStatics> : produce_base<D, Windows::UI::Xaml::Media::ILineSegmentStatics>
{
    HRESULT __stdcall get_PointProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointProperty());
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
struct produce<D, Windows::UI::Xaml::Media::ILinearGradientBrush> : produce_base<D, Windows::UI::Xaml::Media::ILinearGradientBrush>
{
    HRESULT __stdcall get_StartPoint(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartPoint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StartPoint(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartPoint(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndPoint(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndPoint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EndPoint(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EndPoint(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ILinearGradientBrushFactory> : produce_base<D, Windows::UI::Xaml::Media::ILinearGradientBrushFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithGradientStopCollectionAndAngle(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::GradientStop>> gradientStopCollection, double angle, impl::abi_arg_out<Windows::UI::Xaml::Media::ILinearGradientBrush> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithGradientStopCollectionAndAngle(*reinterpret_cast<const Windows::UI::Xaml::Media::GradientStopCollection *>(&gradientStopCollection), angle));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ILinearGradientBrushStatics> : produce_base<D, Windows::UI::Xaml::Media::ILinearGradientBrushStatics>
{
    HRESULT __stdcall get_StartPointProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartPointProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndPointProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndPointProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IMatrix3DProjection> : produce_base<D, Windows::UI::Xaml::Media::IMatrix3DProjection>
{
    HRESULT __stdcall get_ProjectionMatrix(impl::abi_arg_out<Windows::UI::Xaml::Media::Media3D::Matrix3D> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProjectionMatrix());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProjectionMatrix(impl::abi_arg_in<Windows::UI::Xaml::Media::Media3D::Matrix3D> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProjectionMatrix(*reinterpret_cast<const Windows::UI::Xaml::Media::Media3D::Matrix3D *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IMatrix3DProjectionStatics> : produce_base<D, Windows::UI::Xaml::Media::IMatrix3DProjectionStatics>
{
    HRESULT __stdcall get_ProjectionMatrixProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProjectionMatrixProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IMatrixHelper> : produce_base<D, Windows::UI::Xaml::Media::IMatrixHelper>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IMatrixHelperStatics> : produce_base<D, Windows::UI::Xaml::Media::IMatrixHelperStatics>
{
    HRESULT __stdcall get_Identity(impl::abi_arg_out<Windows::UI::Xaml::Media::Matrix> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Identity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromElements(double m11, double m12, double m21, double m22, double offsetX, double offsetY, impl::abi_arg_out<Windows::UI::Xaml::Media::Matrix> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromElements(m11, m12, m21, m22, offsetX, offsetY));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsIdentity(impl::abi_arg_in<Windows::UI::Xaml::Media::Matrix> target, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetIsIdentity(*reinterpret_cast<const Windows::UI::Xaml::Media::Matrix *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Transform(impl::abi_arg_in<Windows::UI::Xaml::Media::Matrix> target, impl::abi_arg_in<Windows::Foundation::Point> point, impl::abi_arg_out<Windows::Foundation::Point> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Transform(*reinterpret_cast<const Windows::UI::Xaml::Media::Matrix *>(&target), *reinterpret_cast<const Windows::Foundation::Point *>(&point)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IMatrixTransform> : produce_base<D, Windows::UI::Xaml::Media::IMatrixTransform>
{
    HRESULT __stdcall get_Matrix(impl::abi_arg_out<Windows::UI::Xaml::Media::Matrix> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Matrix());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Matrix(impl::abi_arg_in<Windows::UI::Xaml::Media::Matrix> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Matrix(*reinterpret_cast<const Windows::UI::Xaml::Media::Matrix *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IMatrixTransformStatics> : produce_base<D, Windows::UI::Xaml::Media::IMatrixTransformStatics>
{
    HRESULT __stdcall get_MatrixProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MatrixProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IMediaTransportControlsThumbnailRequestedEventArgs> : produce_base<D, Windows::UI::Xaml::Media::IMediaTransportControlsThumbnailRequestedEventArgs>
{
    HRESULT __stdcall abi_SetThumbnailImage(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> source) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetThumbnailImage(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&source));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::UI::Xaml::Media::IPartialMediaFailureDetectedEventArgs> : produce_base<D, Windows::UI::Xaml::Media::IPartialMediaFailureDetectedEventArgs>
{
    HRESULT __stdcall get_StreamKind(Windows::Media::Playback::FailedMediaStreamKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StreamKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IPartialMediaFailureDetectedEventArgs2> : produce_base<D, Windows::UI::Xaml::Media::IPartialMediaFailureDetectedEventArgs2>
{
    HRESULT __stdcall get_ExtendedError(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IPathFigure> : produce_base<D, Windows::UI::Xaml::Media::IPathFigure>
{
    HRESULT __stdcall get_Segments(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::PathSegment>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Segments());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Segments(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::PathSegment>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Segments(*reinterpret_cast<const Windows::UI::Xaml::Media::PathSegmentCollection *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StartPoint(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartPoint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StartPoint(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartPoint(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsClosed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsClosed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsClosed(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsClosed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsFilled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsFilled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsFilled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsFilled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IPathFigureStatics> : produce_base<D, Windows::UI::Xaml::Media::IPathFigureStatics>
{
    HRESULT __stdcall get_SegmentsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SegmentsProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StartPointProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartPointProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsClosedProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsClosedProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsFilledProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsFilledProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IPathGeometry> : produce_base<D, Windows::UI::Xaml::Media::IPathGeometry>
{
    HRESULT __stdcall get_FillRule(Windows::UI::Xaml::Media::FillRule * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FillRule());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FillRule(Windows::UI::Xaml::Media::FillRule value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FillRule(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Figures(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::PathFigure>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Figures());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Figures(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::PathFigure>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Figures(*reinterpret_cast<const Windows::UI::Xaml::Media::PathFigureCollection *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IPathGeometryStatics> : produce_base<D, Windows::UI::Xaml::Media::IPathGeometryStatics>
{
    HRESULT __stdcall get_FillRuleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FillRuleProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FiguresProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FiguresProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IPathSegment> : produce_base<D, Windows::UI::Xaml::Media::IPathSegment>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IPathSegmentFactory> : produce_base<D, Windows::UI::Xaml::Media::IPathSegmentFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IPlaneProjection> : produce_base<D, Windows::UI::Xaml::Media::IPlaneProjection>
{
    HRESULT __stdcall get_LocalOffsetX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalOffsetX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LocalOffsetX(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LocalOffsetX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocalOffsetY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalOffsetY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LocalOffsetY(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LocalOffsetY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocalOffsetZ(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalOffsetZ());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LocalOffsetZ(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LocalOffsetZ(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RotationX(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RotationY(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationZ(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationZ());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RotationZ(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationZ(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterOfRotationX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterOfRotationX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CenterOfRotationX(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterOfRotationX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterOfRotationY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterOfRotationY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CenterOfRotationY(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterOfRotationY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterOfRotationZ(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterOfRotationZ());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CenterOfRotationZ(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterOfRotationZ(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GlobalOffsetX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GlobalOffsetX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_GlobalOffsetX(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GlobalOffsetX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GlobalOffsetY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GlobalOffsetY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_GlobalOffsetY(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GlobalOffsetY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GlobalOffsetZ(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GlobalOffsetZ());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_GlobalOffsetZ(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GlobalOffsetZ(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProjectionMatrix(impl::abi_arg_out<Windows::UI::Xaml::Media::Media3D::Matrix3D> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProjectionMatrix());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IPlaneProjectionStatics> : produce_base<D, Windows::UI::Xaml::Media::IPlaneProjectionStatics>
{
    HRESULT __stdcall get_LocalOffsetXProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalOffsetXProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocalOffsetYProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalOffsetYProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocalOffsetZProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalOffsetZProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationXProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationXProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationYProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationYProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationZProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationZProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterOfRotationXProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterOfRotationXProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterOfRotationYProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterOfRotationYProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterOfRotationZProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterOfRotationZProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GlobalOffsetXProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GlobalOffsetXProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GlobalOffsetYProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GlobalOffsetYProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GlobalOffsetZProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GlobalOffsetZProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProjectionMatrixProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProjectionMatrixProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IPolyBezierSegment> : produce_base<D, Windows::UI::Xaml::Media::IPolyBezierSegment>
{
    HRESULT __stdcall get_Points(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Foundation::Point>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Points());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Points(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::Foundation::Point>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Points(*reinterpret_cast<const Windows::UI::Xaml::Media::PointCollection *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IPolyBezierSegmentStatics> : produce_base<D, Windows::UI::Xaml::Media::IPolyBezierSegmentStatics>
{
    HRESULT __stdcall get_PointsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointsProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IPolyLineSegment> : produce_base<D, Windows::UI::Xaml::Media::IPolyLineSegment>
{
    HRESULT __stdcall get_Points(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Foundation::Point>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Points());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Points(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::Foundation::Point>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Points(*reinterpret_cast<const Windows::UI::Xaml::Media::PointCollection *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IPolyLineSegmentStatics> : produce_base<D, Windows::UI::Xaml::Media::IPolyLineSegmentStatics>
{
    HRESULT __stdcall get_PointsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointsProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IPolyQuadraticBezierSegment> : produce_base<D, Windows::UI::Xaml::Media::IPolyQuadraticBezierSegment>
{
    HRESULT __stdcall get_Points(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Foundation::Point>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Points());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Points(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::Foundation::Point>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Points(*reinterpret_cast<const Windows::UI::Xaml::Media::PointCollection *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IPolyQuadraticBezierSegmentStatics> : produce_base<D, Windows::UI::Xaml::Media::IPolyQuadraticBezierSegmentStatics>
{
    HRESULT __stdcall get_PointsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointsProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IProjection> : produce_base<D, Windows::UI::Xaml::Media::IProjection>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IProjectionFactory> : produce_base<D, Windows::UI::Xaml::Media::IProjectionFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::IProjection> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::Media::IQuadraticBezierSegment> : produce_base<D, Windows::UI::Xaml::Media::IQuadraticBezierSegment>
{
    HRESULT __stdcall get_Point1(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Point1());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Point1(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Point1(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Point2(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Point2());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Point2(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Point2(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IQuadraticBezierSegmentStatics> : produce_base<D, Windows::UI::Xaml::Media::IQuadraticBezierSegmentStatics>
{
    HRESULT __stdcall get_Point1Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Point1Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Point2Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Point2Property());
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
struct produce<D, Windows::UI::Xaml::Media::IRateChangedRoutedEventArgs> : produce_base<D, Windows::UI::Xaml::Media::IRateChangedRoutedEventArgs>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IRectangleGeometry> : produce_base<D, Windows::UI::Xaml::Media::IRectangleGeometry>
{
    HRESULT __stdcall get_Rect(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Rect());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Rect(impl::abi_arg_in<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rect(*reinterpret_cast<const Windows::Foundation::Rect *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IRectangleGeometryStatics> : produce_base<D, Windows::UI::Xaml::Media::IRectangleGeometryStatics>
{
    HRESULT __stdcall get_RectProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RectProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IRenderingEventArgs> : produce_base<D, Windows::UI::Xaml::Media::IRenderingEventArgs>
{
    HRESULT __stdcall get_RenderingTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RenderingTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IRotateTransform> : produce_base<D, Windows::UI::Xaml::Media::IRotateTransform>
{
    HRESULT __stdcall get_CenterX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CenterX(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CenterY(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Angle(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Angle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Angle(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Angle(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IRotateTransformStatics> : produce_base<D, Windows::UI::Xaml::Media::IRotateTransformStatics>
{
    HRESULT __stdcall get_CenterXProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterXProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterYProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterYProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AngleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AngleProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IScaleTransform> : produce_base<D, Windows::UI::Xaml::Media::IScaleTransform>
{
    HRESULT __stdcall get_CenterX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CenterX(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CenterY(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScaleX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScaleX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ScaleX(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScaleX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScaleY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScaleY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ScaleY(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScaleY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IScaleTransformStatics> : produce_base<D, Windows::UI::Xaml::Media::IScaleTransformStatics>
{
    HRESULT __stdcall get_CenterXProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterXProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterYProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterYProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScaleXProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScaleXProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScaleYProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScaleYProperty());
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
struct produce<D, Windows::UI::Xaml::Media::ISkewTransform> : produce_base<D, Windows::UI::Xaml::Media::ISkewTransform>
{
    HRESULT __stdcall get_CenterX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CenterX(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CenterY(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AngleX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AngleX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AngleX(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AngleX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AngleY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AngleY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AngleY(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AngleY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ISkewTransformStatics> : produce_base<D, Windows::UI::Xaml::Media::ISkewTransformStatics>
{
    HRESULT __stdcall get_CenterXProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterXProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterYProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterYProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AngleXProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AngleXProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AngleYProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AngleYProperty());
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
struct produce<D, Windows::UI::Xaml::Media::ISolidColorBrush> : produce_base<D, Windows::UI::Xaml::Media::ISolidColorBrush>
{
    HRESULT __stdcall get_Color(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Color());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Color(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ISolidColorBrushFactory> : produce_base<D, Windows::UI::Xaml::Media::ISolidColorBrushFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithColor(impl::abi_arg_in<Windows::UI::Color> color, impl::abi_arg_out<Windows::UI::Xaml::Media::ISolidColorBrush> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithColor(*reinterpret_cast<const Windows::UI::Color *>(&color)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ISolidColorBrushStatics> : produce_base<D, Windows::UI::Xaml::Media::ISolidColorBrushStatics>
{
    HRESULT __stdcall get_ColorProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ColorProperty());
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
struct produce<D, Windows::UI::Xaml::Media::ITileBrush> : produce_base<D, Windows::UI::Xaml::Media::ITileBrush>
{
    HRESULT __stdcall get_AlignmentX(Windows::UI::Xaml::Media::AlignmentX * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlignmentX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AlignmentX(Windows::UI::Xaml::Media::AlignmentX value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlignmentX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlignmentY(Windows::UI::Xaml::Media::AlignmentY * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlignmentY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AlignmentY(Windows::UI::Xaml::Media::AlignmentY value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlignmentY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Stretch(Windows::UI::Xaml::Media::Stretch * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Stretch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Stretch(Windows::UI::Xaml::Media::Stretch value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stretch(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ITileBrushFactory> : produce_base<D, Windows::UI::Xaml::Media::ITileBrushFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::ITileBrush> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::Media::ITileBrushStatics> : produce_base<D, Windows::UI::Xaml::Media::ITileBrushStatics>
{
    HRESULT __stdcall get_AlignmentXProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlignmentXProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlignmentYProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlignmentYProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StretchProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StretchProperty());
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
struct produce<D, Windows::UI::Xaml::Media::ITimelineMarker> : produce_base<D, Windows::UI::Xaml::Media::ITimelineMarker>
{
    HRESULT __stdcall get_Time(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Time());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Time(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Time(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Type(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Type(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Type(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Text(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Text(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ITimelineMarkerRoutedEventArgs> : produce_base<D, Windows::UI::Xaml::Media::ITimelineMarkerRoutedEventArgs>
{
    HRESULT __stdcall get_Marker(impl::abi_arg_out<Windows::UI::Xaml::Media::ITimelineMarker> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Marker());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Marker(impl::abi_arg_in<Windows::UI::Xaml::Media::ITimelineMarker> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Marker(*reinterpret_cast<const Windows::UI::Xaml::Media::TimelineMarker *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ITimelineMarkerStatics> : produce_base<D, Windows::UI::Xaml::Media::ITimelineMarkerStatics>
{
    HRESULT __stdcall get_TimeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TimeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TypeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TypeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextProperty());
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
struct produce<D, Windows::UI::Xaml::Media::ITransform> : produce_base<D, Windows::UI::Xaml::Media::ITransform>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ITransformFactory> : produce_base<D, Windows::UI::Xaml::Media::ITransformFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ITransformGroup> : produce_base<D, Windows::UI::Xaml::Media::ITransformGroup>
{
    HRESULT __stdcall get_Children(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Transform>> value) noexcept override
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

    HRESULT __stdcall put_Children(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Transform>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Children(*reinterpret_cast<const Windows::UI::Xaml::Media::TransformCollection *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(impl::abi_arg_out<Windows::UI::Xaml::Media::Matrix> value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ITransformGroupStatics> : produce_base<D, Windows::UI::Xaml::Media::ITransformGroupStatics>
{
    HRESULT __stdcall get_ChildrenProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChildrenProperty());
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
struct produce<D, Windows::UI::Xaml::Media::ITranslateTransform> : produce_base<D, Windows::UI::Xaml::Media::ITranslateTransform>
{
    HRESULT __stdcall get_X(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().X());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_X(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().X(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Y(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Y());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Y(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Y(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::ITranslateTransformStatics> : produce_base<D, Windows::UI::Xaml::Media::ITranslateTransformStatics>
{
    HRESULT __stdcall get_XProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().XProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_YProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().YProperty());
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
struct produce<D, Windows::UI::Xaml::Media::IVisualTreeHelper> : produce_base<D, Windows::UI::Xaml::Media::IVisualTreeHelper>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IVisualTreeHelperStatics> : produce_base<D, Windows::UI::Xaml::Media::IVisualTreeHelperStatics>
{
    HRESULT __stdcall abi_FindElementsInHostCoordinatesPoint(impl::abi_arg_in<Windows::Foundation::Point> intersectingPoint, impl::abi_arg_in<Windows::UI::Xaml::IUIElement> subtree, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement>> elements) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *elements = detach_abi(this->shim().FindElementsInHostCoordinates(*reinterpret_cast<const Windows::Foundation::Point *>(&intersectingPoint), *reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&subtree)));
            return S_OK;
        }
        catch (...)
        {
            *elements = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindElementsInHostCoordinatesRect(impl::abi_arg_in<Windows::Foundation::Rect> intersectingRect, impl::abi_arg_in<Windows::UI::Xaml::IUIElement> subtree, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement>> elements) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *elements = detach_abi(this->shim().FindElementsInHostCoordinates(*reinterpret_cast<const Windows::Foundation::Rect *>(&intersectingRect), *reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&subtree)));
            return S_OK;
        }
        catch (...)
        {
            *elements = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllElementsInHostCoordinatesPoint(impl::abi_arg_in<Windows::Foundation::Point> intersectingPoint, impl::abi_arg_in<Windows::UI::Xaml::IUIElement> subtree, bool includeAllElements, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement>> elements) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *elements = detach_abi(this->shim().FindElementsInHostCoordinates(*reinterpret_cast<const Windows::Foundation::Point *>(&intersectingPoint), *reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&subtree), includeAllElements));
            return S_OK;
        }
        catch (...)
        {
            *elements = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllElementsInHostCoordinatesRect(impl::abi_arg_in<Windows::Foundation::Rect> intersectingRect, impl::abi_arg_in<Windows::UI::Xaml::IUIElement> subtree, bool includeAllElements, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement>> elements) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *elements = detach_abi(this->shim().FindElementsInHostCoordinates(*reinterpret_cast<const Windows::Foundation::Rect *>(&intersectingRect), *reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&subtree), includeAllElements));
            return S_OK;
        }
        catch (...)
        {
            *elements = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetChild(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> reference, int32_t childIndex, impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> child) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *child = detach_abi(this->shim().GetChild(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&reference), childIndex));
            return S_OK;
        }
        catch (...)
        {
            *child = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetChildrenCount(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> reference, int32_t * count) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *count = detach_abi(this->shim().GetChildrenCount(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&reference)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetParent(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> reference, impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> parent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *parent = detach_abi(this->shim().GetParent(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&reference)));
            return S_OK;
        }
        catch (...)
        {
            *parent = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DisconnectChildrenRecursive(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisconnectChildrenRecursive(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::IVisualTreeHelperStatics2> : produce_base<D, Windows::UI::Xaml::Media::IVisualTreeHelperStatics2>
{
    HRESULT __stdcall abi_GetOpenPopups(impl::abi_arg_in<Windows::UI::Xaml::IWindow> window, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Controls::Primitives::Popup>> popups) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *popups = detach_abi(this->shim().GetOpenPopups(*reinterpret_cast<const Windows::UI::Xaml::Window *>(&window)));
            return S_OK;
        }
        catch (...)
        {
            *popups = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Media {

template <typename D> Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> impl_IVisualTreeHelperStatics<D>::FindElementsInHostCoordinates(const Windows::Foundation::Point & intersectingPoint, const Windows::UI::Xaml::UIElement & subtree) const
{
    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> elements;
    check_hresult(WINRT_SHIM(IVisualTreeHelperStatics)->abi_FindElementsInHostCoordinatesPoint(get_abi(intersectingPoint), get_abi(subtree), put_abi(elements)));
    return elements;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> impl_IVisualTreeHelperStatics<D>::FindElementsInHostCoordinates(const Windows::Foundation::Rect & intersectingRect, const Windows::UI::Xaml::UIElement & subtree) const
{
    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> elements;
    check_hresult(WINRT_SHIM(IVisualTreeHelperStatics)->abi_FindElementsInHostCoordinatesRect(get_abi(intersectingRect), get_abi(subtree), put_abi(elements)));
    return elements;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> impl_IVisualTreeHelperStatics<D>::FindElementsInHostCoordinates(const Windows::Foundation::Point & intersectingPoint, const Windows::UI::Xaml::UIElement & subtree, bool includeAllElements) const
{
    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> elements;
    check_hresult(WINRT_SHIM(IVisualTreeHelperStatics)->abi_FindAllElementsInHostCoordinatesPoint(get_abi(intersectingPoint), get_abi(subtree), includeAllElements, put_abi(elements)));
    return elements;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> impl_IVisualTreeHelperStatics<D>::FindElementsInHostCoordinates(const Windows::Foundation::Rect & intersectingRect, const Windows::UI::Xaml::UIElement & subtree, bool includeAllElements) const
{
    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> elements;
    check_hresult(WINRT_SHIM(IVisualTreeHelperStatics)->abi_FindAllElementsInHostCoordinatesRect(get_abi(intersectingRect), get_abi(subtree), includeAllElements, put_abi(elements)));
    return elements;
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_IVisualTreeHelperStatics<D>::GetChild(const Windows::UI::Xaml::DependencyObject & reference, int32_t childIndex) const
{
    Windows::UI::Xaml::DependencyObject child { nullptr };
    check_hresult(WINRT_SHIM(IVisualTreeHelperStatics)->abi_GetChild(get_abi(reference), childIndex, put_abi(child)));
    return child;
}

template <typename D> int32_t impl_IVisualTreeHelperStatics<D>::GetChildrenCount(const Windows::UI::Xaml::DependencyObject & reference) const
{
    int32_t count {};
    check_hresult(WINRT_SHIM(IVisualTreeHelperStatics)->abi_GetChildrenCount(get_abi(reference), &count));
    return count;
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_IVisualTreeHelperStatics<D>::GetParent(const Windows::UI::Xaml::DependencyObject & reference) const
{
    Windows::UI::Xaml::DependencyObject parent { nullptr };
    check_hresult(WINRT_SHIM(IVisualTreeHelperStatics)->abi_GetParent(get_abi(reference), put_abi(parent)));
    return parent;
}

template <typename D> void impl_IVisualTreeHelperStatics<D>::DisconnectChildrenRecursive(const Windows::UI::Xaml::UIElement & element) const
{
    check_hresult(WINRT_SHIM(IVisualTreeHelperStatics)->abi_DisconnectChildrenRecursive(get_abi(element)));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Controls::Primitives::Popup> impl_IVisualTreeHelperStatics2<D>::GetOpenPopups(const Windows::UI::Xaml::Window & window) const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Controls::Primitives::Popup> popups;
    check_hresult(WINRT_SHIM(IVisualTreeHelperStatics2)->abi_GetOpenPopups(get_abi(window), put_abi(popups)));
    return popups;
}

template <typename D> Windows::Media::Playback::FailedMediaStreamKind impl_IPartialMediaFailureDetectedEventArgs<D>::StreamKind() const
{
    Windows::Media::Playback::FailedMediaStreamKind value {};
    check_hresult(WINRT_SHIM(IPartialMediaFailureDetectedEventArgs)->get_StreamKind(&value));
    return value;
}

template <typename D> HRESULT impl_IPartialMediaFailureDetectedEventArgs2<D>::ExtendedError() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IPartialMediaFailureDetectedEventArgs2)->get_ExtendedError(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Matrix impl_IMatrixHelperStatics<D>::Identity() const
{
    Windows::UI::Xaml::Media::Matrix value {};
    check_hresult(WINRT_SHIM(IMatrixHelperStatics)->get_Identity(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Matrix impl_IMatrixHelperStatics<D>::FromElements(double m11, double m12, double m21, double m22, double offsetX, double offsetY) const
{
    Windows::UI::Xaml::Media::Matrix returnValue {};
    check_hresult(WINRT_SHIM(IMatrixHelperStatics)->abi_FromElements(m11, m12, m21, m22, offsetX, offsetY, put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_IMatrixHelperStatics<D>::GetIsIdentity(const Windows::UI::Xaml::Media::Matrix & target) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMatrixHelperStatics)->abi_GetIsIdentity(get_abi(target), &value));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IMatrixHelperStatics<D>::Transform(const Windows::UI::Xaml::Media::Matrix & target, const Windows::Foundation::Point & point) const
{
    Windows::Foundation::Point returnValue {};
    check_hresult(WINRT_SHIM(IMatrixHelperStatics)->abi_Transform(get_abi(target), get_abi(point), put_abi(returnValue)));
    return returnValue;
}

template <typename D> event_token impl_ICompositionTargetStatics<D>::Rendering(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICompositionTargetStatics)->add_Rendering(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<ICompositionTargetStatics> impl_ICompositionTargetStatics<D>::Rendering(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, ICompositionTargetStatics>(this, &ABI::Windows::UI::Xaml::Media::ICompositionTargetStatics::remove_Rendering, Rendering(value));
}

template <typename D> void impl_ICompositionTargetStatics<D>::Rendering(event_token token) const
{
    check_hresult(WINRT_SHIM(ICompositionTargetStatics)->remove_Rendering(token));
}

template <typename D> event_token impl_ICompositionTargetStatics<D>::SurfaceContentsLost(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICompositionTargetStatics)->add_SurfaceContentsLost(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<ICompositionTargetStatics> impl_ICompositionTargetStatics<D>::SurfaceContentsLost(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, ICompositionTargetStatics>(this, &ABI::Windows::UI::Xaml::Media::ICompositionTargetStatics::remove_SurfaceContentsLost, SurfaceContentsLost(value));
}

template <typename D> void impl_ICompositionTargetStatics<D>::SurfaceContentsLost(event_token token) const
{
    check_hresult(WINRT_SHIM(ICompositionTargetStatics)->remove_SurfaceContentsLost(token));
}

template <typename D> hstring impl_IFontFamily<D>::Source() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFontFamily)->get_Source(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::FontFamily impl_IFontFamilyFactory<D>::CreateInstanceWithName(hstring_view familyName, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::FontFamily instance { nullptr };
    check_hresult(WINRT_SHIM(IFontFamilyFactory)->abi_CreateInstanceWithName(get_abi(familyName), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Media::FontFamily impl_IFontFamilyStatics2<D>::XamlAutoFontFamily() const
{
    Windows::UI::Xaml::Media::FontFamily value { nullptr };
    check_hresult(WINRT_SHIM(IFontFamilyStatics2)->get_XamlAutoFontFamily(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaTransportControlsThumbnailRequestedEventArgs<D>::SetThumbnailImage(const Windows::Storage::Streams::IInputStream & source) const
{
    check_hresult(WINRT_SHIM(IMediaTransportControlsThumbnailRequestedEventArgs)->abi_SetThumbnailImage(get_abi(source)));
}

template <typename D> Windows::Foundation::Deferral impl_IMediaTransportControlsThumbnailRequestedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral returnValue { nullptr };
    check_hresult(WINRT_SHIM(IMediaTransportControlsThumbnailRequestedEventArgs)->abi_GetDeferral(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::TimeSpan impl_IRenderingEventArgs<D>::RenderingTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IRenderingEventArgs)->get_RenderingTime(put_abi(value)));
    return value;
}

template <typename D> double impl_IBrush<D>::Opacity() const
{
    double value {};
    check_hresult(WINRT_SHIM(IBrush)->get_Opacity(&value));
    return value;
}

template <typename D> void impl_IBrush<D>::Opacity(double value) const
{
    check_hresult(WINRT_SHIM(IBrush)->put_Opacity(value));
}

template <typename D> Windows::UI::Xaml::Media::Transform impl_IBrush<D>::Transform() const
{
    Windows::UI::Xaml::Media::Transform value { nullptr };
    check_hresult(WINRT_SHIM(IBrush)->get_Transform(put_abi(value)));
    return value;
}

template <typename D> void impl_IBrush<D>::Transform(const Windows::UI::Xaml::Media::Transform & value) const
{
    check_hresult(WINRT_SHIM(IBrush)->put_Transform(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Transform impl_IBrush<D>::RelativeTransform() const
{
    Windows::UI::Xaml::Media::Transform value { nullptr };
    check_hresult(WINRT_SHIM(IBrush)->get_RelativeTransform(put_abi(value)));
    return value;
}

template <typename D> void impl_IBrush<D>::RelativeTransform(const Windows::UI::Xaml::Media::Transform & value) const
{
    check_hresult(WINRT_SHIM(IBrush)->put_RelativeTransform(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBrushStatics<D>::OpacityProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBrushStatics)->get_OpacityProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBrushStatics<D>::TransformProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBrushStatics)->get_TransformProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBrushStatics<D>::RelativeTransformProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBrushStatics)->get_RelativeTransformProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Brush impl_IBrushFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::Brush instance { nullptr };
    check_hresult(WINRT_SHIM(IBrushFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Media::CacheMode impl_ICacheModeFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::CacheMode instance { nullptr };
    check_hresult(WINRT_SHIM(ICacheModeFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Media::GeneralTransform impl_IGeneralTransform<D>::Inverse() const
{
    Windows::UI::Xaml::Media::GeneralTransform value { nullptr };
    check_hresult(WINRT_SHIM(IGeneralTransform)->get_Inverse(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IGeneralTransform<D>::TransformPoint(const Windows::Foundation::Point & point) const
{
    Windows::Foundation::Point returnValue {};
    check_hresult(WINRT_SHIM(IGeneralTransform)->abi_TransformPoint(get_abi(point), put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_IGeneralTransform<D>::TryTransform(const Windows::Foundation::Point & inPoint, Windows::Foundation::Point & outPoint) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IGeneralTransform)->abi_TryTransform(get_abi(inPoint), put_abi(outPoint), &returnValue));
    return returnValue;
}

template <typename D> Windows::Foundation::Rect impl_IGeneralTransform<D>::TransformBounds(const Windows::Foundation::Rect & rect) const
{
    Windows::Foundation::Rect returnValue {};
    check_hresult(WINRT_SHIM(IGeneralTransform)->abi_TransformBounds(get_abi(rect), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Media::GeneralTransform impl_IGeneralTransformOverrides<D>::InverseCore() const
{
    Windows::UI::Xaml::Media::GeneralTransform value { nullptr };
    check_hresult(WINRT_SHIM(IGeneralTransformOverrides)->get_InverseCore(put_abi(value)));
    return value;
}

template <typename D> bool impl_IGeneralTransformOverrides<D>::TryTransformCore(const Windows::Foundation::Point & inPoint, Windows::Foundation::Point & outPoint) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IGeneralTransformOverrides)->abi_TryTransformCore(get_abi(inPoint), put_abi(outPoint), &returnValue));
    return returnValue;
}

template <typename D> Windows::Foundation::Rect impl_IGeneralTransformOverrides<D>::TransformBoundsCore(const Windows::Foundation::Rect & rect) const
{
    Windows::Foundation::Rect returnValue {};
    check_hresult(WINRT_SHIM(IGeneralTransformOverrides)->abi_TransformBoundsCore(get_abi(rect), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Media::GeneralTransform impl_IGeneralTransformFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::GeneralTransform instance { nullptr };
    check_hresult(WINRT_SHIM(IGeneralTransformFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Media::Transform impl_IGeometry<D>::Transform() const
{
    Windows::UI::Xaml::Media::Transform value { nullptr };
    check_hresult(WINRT_SHIM(IGeometry)->get_Transform(put_abi(value)));
    return value;
}

template <typename D> void impl_IGeometry<D>::Transform(const Windows::UI::Xaml::Media::Transform & value) const
{
    check_hresult(WINRT_SHIM(IGeometry)->put_Transform(get_abi(value)));
}

template <typename D> Windows::Foundation::Rect impl_IGeometry<D>::Bounds() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IGeometry)->get_Bounds(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Geometry impl_IGeometryStatics<D>::Empty() const
{
    Windows::UI::Xaml::Media::Geometry value { nullptr };
    check_hresult(WINRT_SHIM(IGeometryStatics)->get_Empty(put_abi(value)));
    return value;
}

template <typename D> double impl_IGeometryStatics<D>::StandardFlatteningTolerance() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGeometryStatics)->get_StandardFlatteningTolerance(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGeometryStatics<D>::TransformProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGeometryStatics)->get_TransformProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Projection impl_IProjectionFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::Projection instance { nullptr };
    check_hresult(WINRT_SHIM(IProjectionFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::TimeSpan impl_ITimelineMarker<D>::Time() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ITimelineMarker)->get_Time(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimelineMarker<D>::Time(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ITimelineMarker)->put_Time(get_abi(value)));
}

template <typename D> hstring impl_ITimelineMarker<D>::Type() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITimelineMarker)->get_Type(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimelineMarker<D>::Type(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ITimelineMarker)->put_Type(get_abi(value)));
}

template <typename D> hstring impl_ITimelineMarker<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITimelineMarker)->get_Text(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimelineMarker<D>::Text(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ITimelineMarker)->put_Text(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITimelineMarkerStatics<D>::TimeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITimelineMarkerStatics)->get_TimeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITimelineMarkerStatics<D>::TypeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITimelineMarkerStatics)->get_TypeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITimelineMarkerStatics<D>::TextProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITimelineMarkerStatics)->get_TextProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::TimelineMarker impl_ITimelineMarkerRoutedEventArgs<D>::Marker() const
{
    Windows::UI::Xaml::Media::TimelineMarker value { nullptr };
    check_hresult(WINRT_SHIM(ITimelineMarkerRoutedEventArgs)->get_Marker(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimelineMarkerRoutedEventArgs<D>::Marker(const Windows::UI::Xaml::Media::TimelineMarker & value) const
{
    check_hresult(WINRT_SHIM(ITimelineMarkerRoutedEventArgs)->put_Marker(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Media3D::Matrix3D impl_IMatrix3DProjection<D>::ProjectionMatrix() const
{
    Windows::UI::Xaml::Media::Media3D::Matrix3D value {};
    check_hresult(WINRT_SHIM(IMatrix3DProjection)->get_ProjectionMatrix(put_abi(value)));
    return value;
}

template <typename D> void impl_IMatrix3DProjection<D>::ProjectionMatrix(const Windows::UI::Xaml::Media::Media3D::Matrix3D & value) const
{
    check_hresult(WINRT_SHIM(IMatrix3DProjection)->put_ProjectionMatrix(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMatrix3DProjectionStatics<D>::ProjectionMatrixProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMatrix3DProjectionStatics)->get_ProjectionMatrixProperty(put_abi(value)));
    return value;
}

template <typename D> double impl_IPlaneProjection<D>::LocalOffsetX() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPlaneProjection)->get_LocalOffsetX(&value));
    return value;
}

template <typename D> void impl_IPlaneProjection<D>::LocalOffsetX(double value) const
{
    check_hresult(WINRT_SHIM(IPlaneProjection)->put_LocalOffsetX(value));
}

template <typename D> double impl_IPlaneProjection<D>::LocalOffsetY() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPlaneProjection)->get_LocalOffsetY(&value));
    return value;
}

template <typename D> void impl_IPlaneProjection<D>::LocalOffsetY(double value) const
{
    check_hresult(WINRT_SHIM(IPlaneProjection)->put_LocalOffsetY(value));
}

template <typename D> double impl_IPlaneProjection<D>::LocalOffsetZ() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPlaneProjection)->get_LocalOffsetZ(&value));
    return value;
}

template <typename D> void impl_IPlaneProjection<D>::LocalOffsetZ(double value) const
{
    check_hresult(WINRT_SHIM(IPlaneProjection)->put_LocalOffsetZ(value));
}

template <typename D> double impl_IPlaneProjection<D>::RotationX() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPlaneProjection)->get_RotationX(&value));
    return value;
}

template <typename D> void impl_IPlaneProjection<D>::RotationX(double value) const
{
    check_hresult(WINRT_SHIM(IPlaneProjection)->put_RotationX(value));
}

template <typename D> double impl_IPlaneProjection<D>::RotationY() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPlaneProjection)->get_RotationY(&value));
    return value;
}

template <typename D> void impl_IPlaneProjection<D>::RotationY(double value) const
{
    check_hresult(WINRT_SHIM(IPlaneProjection)->put_RotationY(value));
}

template <typename D> double impl_IPlaneProjection<D>::RotationZ() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPlaneProjection)->get_RotationZ(&value));
    return value;
}

template <typename D> void impl_IPlaneProjection<D>::RotationZ(double value) const
{
    check_hresult(WINRT_SHIM(IPlaneProjection)->put_RotationZ(value));
}

template <typename D> double impl_IPlaneProjection<D>::CenterOfRotationX() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPlaneProjection)->get_CenterOfRotationX(&value));
    return value;
}

template <typename D> void impl_IPlaneProjection<D>::CenterOfRotationX(double value) const
{
    check_hresult(WINRT_SHIM(IPlaneProjection)->put_CenterOfRotationX(value));
}

template <typename D> double impl_IPlaneProjection<D>::CenterOfRotationY() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPlaneProjection)->get_CenterOfRotationY(&value));
    return value;
}

template <typename D> void impl_IPlaneProjection<D>::CenterOfRotationY(double value) const
{
    check_hresult(WINRT_SHIM(IPlaneProjection)->put_CenterOfRotationY(value));
}

template <typename D> double impl_IPlaneProjection<D>::CenterOfRotationZ() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPlaneProjection)->get_CenterOfRotationZ(&value));
    return value;
}

template <typename D> void impl_IPlaneProjection<D>::CenterOfRotationZ(double value) const
{
    check_hresult(WINRT_SHIM(IPlaneProjection)->put_CenterOfRotationZ(value));
}

template <typename D> double impl_IPlaneProjection<D>::GlobalOffsetX() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPlaneProjection)->get_GlobalOffsetX(&value));
    return value;
}

template <typename D> void impl_IPlaneProjection<D>::GlobalOffsetX(double value) const
{
    check_hresult(WINRT_SHIM(IPlaneProjection)->put_GlobalOffsetX(value));
}

template <typename D> double impl_IPlaneProjection<D>::GlobalOffsetY() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPlaneProjection)->get_GlobalOffsetY(&value));
    return value;
}

template <typename D> void impl_IPlaneProjection<D>::GlobalOffsetY(double value) const
{
    check_hresult(WINRT_SHIM(IPlaneProjection)->put_GlobalOffsetY(value));
}

template <typename D> double impl_IPlaneProjection<D>::GlobalOffsetZ() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPlaneProjection)->get_GlobalOffsetZ(&value));
    return value;
}

template <typename D> void impl_IPlaneProjection<D>::GlobalOffsetZ(double value) const
{
    check_hresult(WINRT_SHIM(IPlaneProjection)->put_GlobalOffsetZ(value));
}

template <typename D> Windows::UI::Xaml::Media::Media3D::Matrix3D impl_IPlaneProjection<D>::ProjectionMatrix() const
{
    Windows::UI::Xaml::Media::Media3D::Matrix3D value {};
    check_hresult(WINRT_SHIM(IPlaneProjection)->get_ProjectionMatrix(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPlaneProjectionStatics<D>::LocalOffsetXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPlaneProjectionStatics)->get_LocalOffsetXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPlaneProjectionStatics<D>::LocalOffsetYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPlaneProjectionStatics)->get_LocalOffsetYProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPlaneProjectionStatics<D>::LocalOffsetZProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPlaneProjectionStatics)->get_LocalOffsetZProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPlaneProjectionStatics<D>::RotationXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPlaneProjectionStatics)->get_RotationXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPlaneProjectionStatics<D>::RotationYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPlaneProjectionStatics)->get_RotationYProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPlaneProjectionStatics<D>::RotationZProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPlaneProjectionStatics)->get_RotationZProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPlaneProjectionStatics<D>::CenterOfRotationXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPlaneProjectionStatics)->get_CenterOfRotationXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPlaneProjectionStatics<D>::CenterOfRotationYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPlaneProjectionStatics)->get_CenterOfRotationYProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPlaneProjectionStatics<D>::CenterOfRotationZProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPlaneProjectionStatics)->get_CenterOfRotationZProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPlaneProjectionStatics<D>::GlobalOffsetXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPlaneProjectionStatics)->get_GlobalOffsetXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPlaneProjectionStatics<D>::GlobalOffsetYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPlaneProjectionStatics)->get_GlobalOffsetYProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPlaneProjectionStatics<D>::GlobalOffsetZProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPlaneProjectionStatics)->get_GlobalOffsetZProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPlaneProjectionStatics<D>::ProjectionMatrixProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPlaneProjectionStatics)->get_ProjectionMatrixProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IRectangleGeometry<D>::Rect() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IRectangleGeometry)->get_Rect(put_abi(value)));
    return value;
}

template <typename D> void impl_IRectangleGeometry<D>::Rect(const Windows::Foundation::Rect & value) const
{
    check_hresult(WINRT_SHIM(IRectangleGeometry)->put_Rect(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IRectangleGeometryStatics<D>::RectProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IRectangleGeometryStatics)->get_RectProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Color impl_ISolidColorBrush<D>::Color() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(ISolidColorBrush)->get_Color(put_abi(value)));
    return value;
}

template <typename D> void impl_ISolidColorBrush<D>::Color(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(ISolidColorBrush)->put_Color(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISolidColorBrushStatics<D>::ColorProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISolidColorBrushStatics)->get_ColorProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::SolidColorBrush impl_ISolidColorBrushFactory<D>::CreateInstanceWithColor(const Windows::UI::Color & color) const
{
    Windows::UI::Xaml::Media::SolidColorBrush instance { nullptr };
    check_hresult(WINRT_SHIM(ISolidColorBrushFactory)->abi_CreateInstanceWithColor(get_abi(color), put_abi(instance)));
    return instance;
}

template <typename D> double impl_ICompositeTransform<D>::CenterX() const
{
    double value {};
    check_hresult(WINRT_SHIM(ICompositeTransform)->get_CenterX(&value));
    return value;
}

template <typename D> void impl_ICompositeTransform<D>::CenterX(double value) const
{
    check_hresult(WINRT_SHIM(ICompositeTransform)->put_CenterX(value));
}

template <typename D> double impl_ICompositeTransform<D>::CenterY() const
{
    double value {};
    check_hresult(WINRT_SHIM(ICompositeTransform)->get_CenterY(&value));
    return value;
}

template <typename D> void impl_ICompositeTransform<D>::CenterY(double value) const
{
    check_hresult(WINRT_SHIM(ICompositeTransform)->put_CenterY(value));
}

template <typename D> double impl_ICompositeTransform<D>::ScaleX() const
{
    double value {};
    check_hresult(WINRT_SHIM(ICompositeTransform)->get_ScaleX(&value));
    return value;
}

template <typename D> void impl_ICompositeTransform<D>::ScaleX(double value) const
{
    check_hresult(WINRT_SHIM(ICompositeTransform)->put_ScaleX(value));
}

template <typename D> double impl_ICompositeTransform<D>::ScaleY() const
{
    double value {};
    check_hresult(WINRT_SHIM(ICompositeTransform)->get_ScaleY(&value));
    return value;
}

template <typename D> void impl_ICompositeTransform<D>::ScaleY(double value) const
{
    check_hresult(WINRT_SHIM(ICompositeTransform)->put_ScaleY(value));
}

template <typename D> double impl_ICompositeTransform<D>::SkewX() const
{
    double value {};
    check_hresult(WINRT_SHIM(ICompositeTransform)->get_SkewX(&value));
    return value;
}

template <typename D> void impl_ICompositeTransform<D>::SkewX(double value) const
{
    check_hresult(WINRT_SHIM(ICompositeTransform)->put_SkewX(value));
}

template <typename D> double impl_ICompositeTransform<D>::SkewY() const
{
    double value {};
    check_hresult(WINRT_SHIM(ICompositeTransform)->get_SkewY(&value));
    return value;
}

template <typename D> void impl_ICompositeTransform<D>::SkewY(double value) const
{
    check_hresult(WINRT_SHIM(ICompositeTransform)->put_SkewY(value));
}

template <typename D> double impl_ICompositeTransform<D>::Rotation() const
{
    double value {};
    check_hresult(WINRT_SHIM(ICompositeTransform)->get_Rotation(&value));
    return value;
}

template <typename D> void impl_ICompositeTransform<D>::Rotation(double value) const
{
    check_hresult(WINRT_SHIM(ICompositeTransform)->put_Rotation(value));
}

template <typename D> double impl_ICompositeTransform<D>::TranslateX() const
{
    double value {};
    check_hresult(WINRT_SHIM(ICompositeTransform)->get_TranslateX(&value));
    return value;
}

template <typename D> void impl_ICompositeTransform<D>::TranslateX(double value) const
{
    check_hresult(WINRT_SHIM(ICompositeTransform)->put_TranslateX(value));
}

template <typename D> double impl_ICompositeTransform<D>::TranslateY() const
{
    double value {};
    check_hresult(WINRT_SHIM(ICompositeTransform)->get_TranslateY(&value));
    return value;
}

template <typename D> void impl_ICompositeTransform<D>::TranslateY(double value) const
{
    check_hresult(WINRT_SHIM(ICompositeTransform)->put_TranslateY(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ICompositeTransformStatics<D>::CenterXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ICompositeTransformStatics)->get_CenterXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ICompositeTransformStatics<D>::CenterYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ICompositeTransformStatics)->get_CenterYProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ICompositeTransformStatics<D>::ScaleXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ICompositeTransformStatics)->get_ScaleXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ICompositeTransformStatics<D>::ScaleYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ICompositeTransformStatics)->get_ScaleYProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ICompositeTransformStatics<D>::SkewXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ICompositeTransformStatics)->get_SkewXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ICompositeTransformStatics<D>::SkewYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ICompositeTransformStatics)->get_SkewYProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ICompositeTransformStatics<D>::RotationProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ICompositeTransformStatics)->get_RotationProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ICompositeTransformStatics<D>::TranslateXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ICompositeTransformStatics)->get_TranslateXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ICompositeTransformStatics<D>::TranslateYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ICompositeTransformStatics)->get_TranslateYProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Matrix impl_IMatrixTransform<D>::Matrix() const
{
    Windows::UI::Xaml::Media::Matrix value {};
    check_hresult(WINRT_SHIM(IMatrixTransform)->get_Matrix(put_abi(value)));
    return value;
}

template <typename D> void impl_IMatrixTransform<D>::Matrix(const Windows::UI::Xaml::Media::Matrix & value) const
{
    check_hresult(WINRT_SHIM(IMatrixTransform)->put_Matrix(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMatrixTransformStatics<D>::MatrixProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMatrixTransformStatics)->get_MatrixProperty(put_abi(value)));
    return value;
}

template <typename D> double impl_IRotateTransform<D>::CenterX() const
{
    double value {};
    check_hresult(WINRT_SHIM(IRotateTransform)->get_CenterX(&value));
    return value;
}

template <typename D> void impl_IRotateTransform<D>::CenterX(double value) const
{
    check_hresult(WINRT_SHIM(IRotateTransform)->put_CenterX(value));
}

template <typename D> double impl_IRotateTransform<D>::CenterY() const
{
    double value {};
    check_hresult(WINRT_SHIM(IRotateTransform)->get_CenterY(&value));
    return value;
}

template <typename D> void impl_IRotateTransform<D>::CenterY(double value) const
{
    check_hresult(WINRT_SHIM(IRotateTransform)->put_CenterY(value));
}

template <typename D> double impl_IRotateTransform<D>::Angle() const
{
    double value {};
    check_hresult(WINRT_SHIM(IRotateTransform)->get_Angle(&value));
    return value;
}

template <typename D> void impl_IRotateTransform<D>::Angle(double value) const
{
    check_hresult(WINRT_SHIM(IRotateTransform)->put_Angle(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IRotateTransformStatics<D>::CenterXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IRotateTransformStatics)->get_CenterXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IRotateTransformStatics<D>::CenterYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IRotateTransformStatics)->get_CenterYProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IRotateTransformStatics<D>::AngleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IRotateTransformStatics)->get_AngleProperty(put_abi(value)));
    return value;
}

template <typename D> double impl_IScaleTransform<D>::CenterX() const
{
    double value {};
    check_hresult(WINRT_SHIM(IScaleTransform)->get_CenterX(&value));
    return value;
}

template <typename D> void impl_IScaleTransform<D>::CenterX(double value) const
{
    check_hresult(WINRT_SHIM(IScaleTransform)->put_CenterX(value));
}

template <typename D> double impl_IScaleTransform<D>::CenterY() const
{
    double value {};
    check_hresult(WINRT_SHIM(IScaleTransform)->get_CenterY(&value));
    return value;
}

template <typename D> void impl_IScaleTransform<D>::CenterY(double value) const
{
    check_hresult(WINRT_SHIM(IScaleTransform)->put_CenterY(value));
}

template <typename D> double impl_IScaleTransform<D>::ScaleX() const
{
    double value {};
    check_hresult(WINRT_SHIM(IScaleTransform)->get_ScaleX(&value));
    return value;
}

template <typename D> void impl_IScaleTransform<D>::ScaleX(double value) const
{
    check_hresult(WINRT_SHIM(IScaleTransform)->put_ScaleX(value));
}

template <typename D> double impl_IScaleTransform<D>::ScaleY() const
{
    double value {};
    check_hresult(WINRT_SHIM(IScaleTransform)->get_ScaleY(&value));
    return value;
}

template <typename D> void impl_IScaleTransform<D>::ScaleY(double value) const
{
    check_hresult(WINRT_SHIM(IScaleTransform)->put_ScaleY(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IScaleTransformStatics<D>::CenterXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IScaleTransformStatics)->get_CenterXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IScaleTransformStatics<D>::CenterYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IScaleTransformStatics)->get_CenterYProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IScaleTransformStatics<D>::ScaleXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IScaleTransformStatics)->get_ScaleXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IScaleTransformStatics<D>::ScaleYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IScaleTransformStatics)->get_ScaleYProperty(put_abi(value)));
    return value;
}

template <typename D> double impl_ISkewTransform<D>::CenterX() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISkewTransform)->get_CenterX(&value));
    return value;
}

template <typename D> void impl_ISkewTransform<D>::CenterX(double value) const
{
    check_hresult(WINRT_SHIM(ISkewTransform)->put_CenterX(value));
}

template <typename D> double impl_ISkewTransform<D>::CenterY() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISkewTransform)->get_CenterY(&value));
    return value;
}

template <typename D> void impl_ISkewTransform<D>::CenterY(double value) const
{
    check_hresult(WINRT_SHIM(ISkewTransform)->put_CenterY(value));
}

template <typename D> double impl_ISkewTransform<D>::AngleX() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISkewTransform)->get_AngleX(&value));
    return value;
}

template <typename D> void impl_ISkewTransform<D>::AngleX(double value) const
{
    check_hresult(WINRT_SHIM(ISkewTransform)->put_AngleX(value));
}

template <typename D> double impl_ISkewTransform<D>::AngleY() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISkewTransform)->get_AngleY(&value));
    return value;
}

template <typename D> void impl_ISkewTransform<D>::AngleY(double value) const
{
    check_hresult(WINRT_SHIM(ISkewTransform)->put_AngleY(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISkewTransformStatics<D>::CenterXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISkewTransformStatics)->get_CenterXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISkewTransformStatics<D>::CenterYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISkewTransformStatics)->get_CenterYProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISkewTransformStatics<D>::AngleXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISkewTransformStatics)->get_AngleXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISkewTransformStatics<D>::AngleYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISkewTransformStatics)->get_AngleYProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::TransformCollection impl_ITransformGroup<D>::Children() const
{
    Windows::UI::Xaml::Media::TransformCollection value { nullptr };
    check_hresult(WINRT_SHIM(ITransformGroup)->get_Children(put_abi(value)));
    return value;
}

template <typename D> void impl_ITransformGroup<D>::Children(const Windows::UI::Xaml::Media::TransformCollection & value) const
{
    check_hresult(WINRT_SHIM(ITransformGroup)->put_Children(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Matrix impl_ITransformGroup<D>::Value() const
{
    Windows::UI::Xaml::Media::Matrix value {};
    check_hresult(WINRT_SHIM(ITransformGroup)->get_Value(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITransformGroupStatics<D>::ChildrenProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITransformGroupStatics)->get_ChildrenProperty(put_abi(value)));
    return value;
}

template <typename D> double impl_ITranslateTransform<D>::X() const
{
    double value {};
    check_hresult(WINRT_SHIM(ITranslateTransform)->get_X(&value));
    return value;
}

template <typename D> void impl_ITranslateTransform<D>::X(double value) const
{
    check_hresult(WINRT_SHIM(ITranslateTransform)->put_X(value));
}

template <typename D> double impl_ITranslateTransform<D>::Y() const
{
    double value {};
    check_hresult(WINRT_SHIM(ITranslateTransform)->get_Y(&value));
    return value;
}

template <typename D> void impl_ITranslateTransform<D>::Y(double value) const
{
    check_hresult(WINRT_SHIM(ITranslateTransform)->put_Y(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITranslateTransformStatics<D>::XProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITranslateTransformStatics)->get_XProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITranslateTransformStatics<D>::YProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITranslateTransformStatics)->get_YProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Color impl_IGradientStop<D>::Color() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IGradientStop)->get_Color(put_abi(value)));
    return value;
}

template <typename D> void impl_IGradientStop<D>::Color(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IGradientStop)->put_Color(get_abi(value)));
}

template <typename D> double impl_IGradientStop<D>::Offset() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGradientStop)->get_Offset(&value));
    return value;
}

template <typename D> void impl_IGradientStop<D>::Offset(double value) const
{
    check_hresult(WINRT_SHIM(IGradientStop)->put_Offset(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGradientStopStatics<D>::ColorProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGradientStopStatics)->get_ColorProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGradientStopStatics<D>::OffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGradientStopStatics)->get_OffsetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::PathSegmentCollection impl_IPathFigure<D>::Segments() const
{
    Windows::UI::Xaml::Media::PathSegmentCollection value { nullptr };
    check_hresult(WINRT_SHIM(IPathFigure)->get_Segments(put_abi(value)));
    return value;
}

template <typename D> void impl_IPathFigure<D>::Segments(const Windows::UI::Xaml::Media::PathSegmentCollection & value) const
{
    check_hresult(WINRT_SHIM(IPathFigure)->put_Segments(get_abi(value)));
}

template <typename D> Windows::Foundation::Point impl_IPathFigure<D>::StartPoint() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IPathFigure)->get_StartPoint(put_abi(value)));
    return value;
}

template <typename D> void impl_IPathFigure<D>::StartPoint(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IPathFigure)->put_StartPoint(get_abi(value)));
}

template <typename D> bool impl_IPathFigure<D>::IsClosed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPathFigure)->get_IsClosed(&value));
    return value;
}

template <typename D> void impl_IPathFigure<D>::IsClosed(bool value) const
{
    check_hresult(WINRT_SHIM(IPathFigure)->put_IsClosed(value));
}

template <typename D> bool impl_IPathFigure<D>::IsFilled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPathFigure)->get_IsFilled(&value));
    return value;
}

template <typename D> void impl_IPathFigure<D>::IsFilled(bool value) const
{
    check_hresult(WINRT_SHIM(IPathFigure)->put_IsFilled(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPathFigureStatics<D>::SegmentsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPathFigureStatics)->get_SegmentsProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPathFigureStatics<D>::StartPointProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPathFigureStatics)->get_StartPointProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPathFigureStatics<D>::IsClosedProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPathFigureStatics)->get_IsClosedProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPathFigureStatics<D>::IsFilledProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPathFigureStatics)->get_IsFilledProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IArcSegment<D>::Point() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IArcSegment)->get_Point(put_abi(value)));
    return value;
}

template <typename D> void impl_IArcSegment<D>::Point(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IArcSegment)->put_Point(get_abi(value)));
}

template <typename D> Windows::Foundation::Size impl_IArcSegment<D>::Size() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IArcSegment)->get_Size(put_abi(value)));
    return value;
}

template <typename D> void impl_IArcSegment<D>::Size(const Windows::Foundation::Size & value) const
{
    check_hresult(WINRT_SHIM(IArcSegment)->put_Size(get_abi(value)));
}

template <typename D> double impl_IArcSegment<D>::RotationAngle() const
{
    double value {};
    check_hresult(WINRT_SHIM(IArcSegment)->get_RotationAngle(&value));
    return value;
}

template <typename D> void impl_IArcSegment<D>::RotationAngle(double value) const
{
    check_hresult(WINRT_SHIM(IArcSegment)->put_RotationAngle(value));
}

template <typename D> bool impl_IArcSegment<D>::IsLargeArc() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IArcSegment)->get_IsLargeArc(&value));
    return value;
}

template <typename D> void impl_IArcSegment<D>::IsLargeArc(bool value) const
{
    check_hresult(WINRT_SHIM(IArcSegment)->put_IsLargeArc(value));
}

template <typename D> Windows::UI::Xaml::Media::SweepDirection impl_IArcSegment<D>::SweepDirection() const
{
    Windows::UI::Xaml::Media::SweepDirection value {};
    check_hresult(WINRT_SHIM(IArcSegment)->get_SweepDirection(&value));
    return value;
}

template <typename D> void impl_IArcSegment<D>::SweepDirection(Windows::UI::Xaml::Media::SweepDirection value) const
{
    check_hresult(WINRT_SHIM(IArcSegment)->put_SweepDirection(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IArcSegmentStatics<D>::PointProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IArcSegmentStatics)->get_PointProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IArcSegmentStatics<D>::SizeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IArcSegmentStatics)->get_SizeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IArcSegmentStatics<D>::RotationAngleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IArcSegmentStatics)->get_RotationAngleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IArcSegmentStatics<D>::IsLargeArcProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IArcSegmentStatics)->get_IsLargeArcProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IArcSegmentStatics<D>::SweepDirectionProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IArcSegmentStatics)->get_SweepDirectionProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IBezierSegment<D>::Point1() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IBezierSegment)->get_Point1(put_abi(value)));
    return value;
}

template <typename D> void impl_IBezierSegment<D>::Point1(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IBezierSegment)->put_Point1(get_abi(value)));
}

template <typename D> Windows::Foundation::Point impl_IBezierSegment<D>::Point2() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IBezierSegment)->get_Point2(put_abi(value)));
    return value;
}

template <typename D> void impl_IBezierSegment<D>::Point2(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IBezierSegment)->put_Point2(get_abi(value)));
}

template <typename D> Windows::Foundation::Point impl_IBezierSegment<D>::Point3() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IBezierSegment)->get_Point3(put_abi(value)));
    return value;
}

template <typename D> void impl_IBezierSegment<D>::Point3(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IBezierSegment)->put_Point3(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBezierSegmentStatics<D>::Point1Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBezierSegmentStatics)->get_Point1Property(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBezierSegmentStatics<D>::Point2Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBezierSegmentStatics)->get_Point2Property(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBezierSegmentStatics<D>::Point3Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBezierSegmentStatics)->get_Point3Property(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IEllipseGeometry<D>::Center() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IEllipseGeometry)->get_Center(put_abi(value)));
    return value;
}

template <typename D> void impl_IEllipseGeometry<D>::Center(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IEllipseGeometry)->put_Center(get_abi(value)));
}

template <typename D> double impl_IEllipseGeometry<D>::RadiusX() const
{
    double value {};
    check_hresult(WINRT_SHIM(IEllipseGeometry)->get_RadiusX(&value));
    return value;
}

template <typename D> void impl_IEllipseGeometry<D>::RadiusX(double value) const
{
    check_hresult(WINRT_SHIM(IEllipseGeometry)->put_RadiusX(value));
}

template <typename D> double impl_IEllipseGeometry<D>::RadiusY() const
{
    double value {};
    check_hresult(WINRT_SHIM(IEllipseGeometry)->get_RadiusY(&value));
    return value;
}

template <typename D> void impl_IEllipseGeometry<D>::RadiusY(double value) const
{
    check_hresult(WINRT_SHIM(IEllipseGeometry)->put_RadiusY(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IEllipseGeometryStatics<D>::CenterProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IEllipseGeometryStatics)->get_CenterProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IEllipseGeometryStatics<D>::RadiusXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IEllipseGeometryStatics)->get_RadiusXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IEllipseGeometryStatics<D>::RadiusYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IEllipseGeometryStatics)->get_RadiusYProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::FillRule impl_IGeometryGroup<D>::FillRule() const
{
    Windows::UI::Xaml::Media::FillRule value {};
    check_hresult(WINRT_SHIM(IGeometryGroup)->get_FillRule(&value));
    return value;
}

template <typename D> void impl_IGeometryGroup<D>::FillRule(Windows::UI::Xaml::Media::FillRule value) const
{
    check_hresult(WINRT_SHIM(IGeometryGroup)->put_FillRule(value));
}

template <typename D> Windows::UI::Xaml::Media::GeometryCollection impl_IGeometryGroup<D>::Children() const
{
    Windows::UI::Xaml::Media::GeometryCollection value { nullptr };
    check_hresult(WINRT_SHIM(IGeometryGroup)->get_Children(put_abi(value)));
    return value;
}

template <typename D> void impl_IGeometryGroup<D>::Children(const Windows::UI::Xaml::Media::GeometryCollection & value) const
{
    check_hresult(WINRT_SHIM(IGeometryGroup)->put_Children(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGeometryGroupStatics<D>::FillRuleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGeometryGroupStatics)->get_FillRuleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGeometryGroupStatics<D>::ChildrenProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGeometryGroupStatics)->get_ChildrenProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::GradientSpreadMethod impl_IGradientBrush<D>::SpreadMethod() const
{
    Windows::UI::Xaml::Media::GradientSpreadMethod value {};
    check_hresult(WINRT_SHIM(IGradientBrush)->get_SpreadMethod(&value));
    return value;
}

template <typename D> void impl_IGradientBrush<D>::SpreadMethod(Windows::UI::Xaml::Media::GradientSpreadMethod value) const
{
    check_hresult(WINRT_SHIM(IGradientBrush)->put_SpreadMethod(value));
}

template <typename D> Windows::UI::Xaml::Media::BrushMappingMode impl_IGradientBrush<D>::MappingMode() const
{
    Windows::UI::Xaml::Media::BrushMappingMode value {};
    check_hresult(WINRT_SHIM(IGradientBrush)->get_MappingMode(&value));
    return value;
}

template <typename D> void impl_IGradientBrush<D>::MappingMode(Windows::UI::Xaml::Media::BrushMappingMode value) const
{
    check_hresult(WINRT_SHIM(IGradientBrush)->put_MappingMode(value));
}

template <typename D> Windows::UI::Xaml::Media::ColorInterpolationMode impl_IGradientBrush<D>::ColorInterpolationMode() const
{
    Windows::UI::Xaml::Media::ColorInterpolationMode value {};
    check_hresult(WINRT_SHIM(IGradientBrush)->get_ColorInterpolationMode(&value));
    return value;
}

template <typename D> void impl_IGradientBrush<D>::ColorInterpolationMode(Windows::UI::Xaml::Media::ColorInterpolationMode value) const
{
    check_hresult(WINRT_SHIM(IGradientBrush)->put_ColorInterpolationMode(value));
}

template <typename D> Windows::UI::Xaml::Media::GradientStopCollection impl_IGradientBrush<D>::GradientStops() const
{
    Windows::UI::Xaml::Media::GradientStopCollection value { nullptr };
    check_hresult(WINRT_SHIM(IGradientBrush)->get_GradientStops(put_abi(value)));
    return value;
}

template <typename D> void impl_IGradientBrush<D>::GradientStops(const Windows::UI::Xaml::Media::GradientStopCollection & value) const
{
    check_hresult(WINRT_SHIM(IGradientBrush)->put_GradientStops(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGradientBrushStatics<D>::SpreadMethodProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGradientBrushStatics)->get_SpreadMethodProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGradientBrushStatics<D>::MappingModeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGradientBrushStatics)->get_MappingModeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGradientBrushStatics<D>::ColorInterpolationModeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGradientBrushStatics)->get_ColorInterpolationModeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGradientBrushStatics<D>::GradientStopsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGradientBrushStatics)->get_GradientStopsProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::GradientBrush impl_IGradientBrushFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::GradientBrush instance { nullptr };
    check_hresult(WINRT_SHIM(IGradientBrushFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::Point impl_ILineGeometry<D>::StartPoint() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(ILineGeometry)->get_StartPoint(put_abi(value)));
    return value;
}

template <typename D> void impl_ILineGeometry<D>::StartPoint(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(ILineGeometry)->put_StartPoint(get_abi(value)));
}

template <typename D> Windows::Foundation::Point impl_ILineGeometry<D>::EndPoint() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(ILineGeometry)->get_EndPoint(put_abi(value)));
    return value;
}

template <typename D> void impl_ILineGeometry<D>::EndPoint(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(ILineGeometry)->put_EndPoint(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ILineGeometryStatics<D>::StartPointProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ILineGeometryStatics)->get_StartPointProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ILineGeometryStatics<D>::EndPointProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ILineGeometryStatics)->get_EndPointProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_ILineSegment<D>::Point() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(ILineSegment)->get_Point(put_abi(value)));
    return value;
}

template <typename D> void impl_ILineSegment<D>::Point(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(ILineSegment)->put_Point(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ILineSegmentStatics<D>::PointProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ILineSegmentStatics)->get_PointProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::FillRule impl_IPathGeometry<D>::FillRule() const
{
    Windows::UI::Xaml::Media::FillRule value {};
    check_hresult(WINRT_SHIM(IPathGeometry)->get_FillRule(&value));
    return value;
}

template <typename D> void impl_IPathGeometry<D>::FillRule(Windows::UI::Xaml::Media::FillRule value) const
{
    check_hresult(WINRT_SHIM(IPathGeometry)->put_FillRule(value));
}

template <typename D> Windows::UI::Xaml::Media::PathFigureCollection impl_IPathGeometry<D>::Figures() const
{
    Windows::UI::Xaml::Media::PathFigureCollection value { nullptr };
    check_hresult(WINRT_SHIM(IPathGeometry)->get_Figures(put_abi(value)));
    return value;
}

template <typename D> void impl_IPathGeometry<D>::Figures(const Windows::UI::Xaml::Media::PathFigureCollection & value) const
{
    check_hresult(WINRT_SHIM(IPathGeometry)->put_Figures(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPathGeometryStatics<D>::FillRuleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPathGeometryStatics)->get_FillRuleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPathGeometryStatics<D>::FiguresProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPathGeometryStatics)->get_FiguresProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::PointCollection impl_IPolyBezierSegment<D>::Points() const
{
    Windows::UI::Xaml::Media::PointCollection value { nullptr };
    check_hresult(WINRT_SHIM(IPolyBezierSegment)->get_Points(put_abi(value)));
    return value;
}

template <typename D> void impl_IPolyBezierSegment<D>::Points(const Windows::UI::Xaml::Media::PointCollection & value) const
{
    check_hresult(WINRT_SHIM(IPolyBezierSegment)->put_Points(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPolyBezierSegmentStatics<D>::PointsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPolyBezierSegmentStatics)->get_PointsProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::PointCollection impl_IPolyLineSegment<D>::Points() const
{
    Windows::UI::Xaml::Media::PointCollection value { nullptr };
    check_hresult(WINRT_SHIM(IPolyLineSegment)->get_Points(put_abi(value)));
    return value;
}

template <typename D> void impl_IPolyLineSegment<D>::Points(const Windows::UI::Xaml::Media::PointCollection & value) const
{
    check_hresult(WINRT_SHIM(IPolyLineSegment)->put_Points(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPolyLineSegmentStatics<D>::PointsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPolyLineSegmentStatics)->get_PointsProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::PointCollection impl_IPolyQuadraticBezierSegment<D>::Points() const
{
    Windows::UI::Xaml::Media::PointCollection value { nullptr };
    check_hresult(WINRT_SHIM(IPolyQuadraticBezierSegment)->get_Points(put_abi(value)));
    return value;
}

template <typename D> void impl_IPolyQuadraticBezierSegment<D>::Points(const Windows::UI::Xaml::Media::PointCollection & value) const
{
    check_hresult(WINRT_SHIM(IPolyQuadraticBezierSegment)->put_Points(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPolyQuadraticBezierSegmentStatics<D>::PointsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPolyQuadraticBezierSegmentStatics)->get_PointsProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IQuadraticBezierSegment<D>::Point1() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IQuadraticBezierSegment)->get_Point1(put_abi(value)));
    return value;
}

template <typename D> void impl_IQuadraticBezierSegment<D>::Point1(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IQuadraticBezierSegment)->put_Point1(get_abi(value)));
}

template <typename D> Windows::Foundation::Point impl_IQuadraticBezierSegment<D>::Point2() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IQuadraticBezierSegment)->get_Point2(put_abi(value)));
    return value;
}

template <typename D> void impl_IQuadraticBezierSegment<D>::Point2(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IQuadraticBezierSegment)->put_Point2(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IQuadraticBezierSegmentStatics<D>::Point1Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IQuadraticBezierSegmentStatics)->get_Point1Property(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IQuadraticBezierSegmentStatics<D>::Point2Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IQuadraticBezierSegmentStatics)->get_Point2Property(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::AlignmentX impl_ITileBrush<D>::AlignmentX() const
{
    Windows::UI::Xaml::Media::AlignmentX value {};
    check_hresult(WINRT_SHIM(ITileBrush)->get_AlignmentX(&value));
    return value;
}

template <typename D> void impl_ITileBrush<D>::AlignmentX(Windows::UI::Xaml::Media::AlignmentX value) const
{
    check_hresult(WINRT_SHIM(ITileBrush)->put_AlignmentX(value));
}

template <typename D> Windows::UI::Xaml::Media::AlignmentY impl_ITileBrush<D>::AlignmentY() const
{
    Windows::UI::Xaml::Media::AlignmentY value {};
    check_hresult(WINRT_SHIM(ITileBrush)->get_AlignmentY(&value));
    return value;
}

template <typename D> void impl_ITileBrush<D>::AlignmentY(Windows::UI::Xaml::Media::AlignmentY value) const
{
    check_hresult(WINRT_SHIM(ITileBrush)->put_AlignmentY(value));
}

template <typename D> Windows::UI::Xaml::Media::Stretch impl_ITileBrush<D>::Stretch() const
{
    Windows::UI::Xaml::Media::Stretch value {};
    check_hresult(WINRT_SHIM(ITileBrush)->get_Stretch(&value));
    return value;
}

template <typename D> void impl_ITileBrush<D>::Stretch(Windows::UI::Xaml::Media::Stretch value) const
{
    check_hresult(WINRT_SHIM(ITileBrush)->put_Stretch(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITileBrushStatics<D>::AlignmentXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITileBrushStatics)->get_AlignmentXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITileBrushStatics<D>::AlignmentYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITileBrushStatics)->get_AlignmentYProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITileBrushStatics<D>::StretchProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITileBrushStatics)->get_StretchProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::TileBrush impl_ITileBrushFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::TileBrush instance { nullptr };
    check_hresult(WINRT_SHIM(ITileBrushFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Media::ImageSource impl_IImageBrush<D>::ImageSource() const
{
    Windows::UI::Xaml::Media::ImageSource value { nullptr };
    check_hresult(WINRT_SHIM(IImageBrush)->get_ImageSource(put_abi(value)));
    return value;
}

template <typename D> void impl_IImageBrush<D>::ImageSource(const Windows::UI::Xaml::Media::ImageSource & value) const
{
    check_hresult(WINRT_SHIM(IImageBrush)->put_ImageSource(get_abi(value)));
}

template <typename D> event_token impl_IImageBrush<D>::ImageFailed(const Windows::UI::Xaml::ExceptionRoutedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IImageBrush)->add_ImageFailed(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IImageBrush> impl_IImageBrush<D>::ImageFailed(auto_revoke_t, const Windows::UI::Xaml::ExceptionRoutedEventHandler & value) const
{
    return impl::make_event_revoker<D, IImageBrush>(this, &ABI::Windows::UI::Xaml::Media::IImageBrush::remove_ImageFailed, ImageFailed(value));
}

template <typename D> void impl_IImageBrush<D>::ImageFailed(event_token token) const
{
    check_hresult(WINRT_SHIM(IImageBrush)->remove_ImageFailed(token));
}

template <typename D> event_token impl_IImageBrush<D>::ImageOpened(const Windows::UI::Xaml::RoutedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IImageBrush)->add_ImageOpened(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IImageBrush> impl_IImageBrush<D>::ImageOpened(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const
{
    return impl::make_event_revoker<D, IImageBrush>(this, &ABI::Windows::UI::Xaml::Media::IImageBrush::remove_ImageOpened, ImageOpened(value));
}

template <typename D> void impl_IImageBrush<D>::ImageOpened(event_token token) const
{
    check_hresult(WINRT_SHIM(IImageBrush)->remove_ImageOpened(token));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IImageBrushStatics<D>::ImageSourceProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IImageBrushStatics)->get_ImageSourceProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_ILinearGradientBrush<D>::StartPoint() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(ILinearGradientBrush)->get_StartPoint(put_abi(value)));
    return value;
}

template <typename D> void impl_ILinearGradientBrush<D>::StartPoint(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(ILinearGradientBrush)->put_StartPoint(get_abi(value)));
}

template <typename D> Windows::Foundation::Point impl_ILinearGradientBrush<D>::EndPoint() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(ILinearGradientBrush)->get_EndPoint(put_abi(value)));
    return value;
}

template <typename D> void impl_ILinearGradientBrush<D>::EndPoint(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(ILinearGradientBrush)->put_EndPoint(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ILinearGradientBrushStatics<D>::StartPointProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ILinearGradientBrushStatics)->get_StartPointProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ILinearGradientBrushStatics<D>::EndPointProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ILinearGradientBrushStatics)->get_EndPointProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::LinearGradientBrush impl_ILinearGradientBrushFactory<D>::CreateInstanceWithGradientStopCollectionAndAngle(const Windows::UI::Xaml::Media::GradientStopCollection & gradientStopCollection, double angle) const
{
    Windows::UI::Xaml::Media::LinearGradientBrush instance { nullptr };
    check_hresult(WINRT_SHIM(ILinearGradientBrushFactory)->abi_CreateInstanceWithGradientStopCollectionAndAngle(get_abi(gradientStopCollection), angle, put_abi(instance)));
    return instance;
}

inline ArcSegment::ArcSegment() :
    ArcSegment(activate_instance<ArcSegment>())
{}

inline Windows::UI::Xaml::DependencyProperty ArcSegment::PointProperty()
{
    return get_activation_factory<ArcSegment, IArcSegmentStatics>().PointProperty();
}

inline Windows::UI::Xaml::DependencyProperty ArcSegment::SizeProperty()
{
    return get_activation_factory<ArcSegment, IArcSegmentStatics>().SizeProperty();
}

inline Windows::UI::Xaml::DependencyProperty ArcSegment::RotationAngleProperty()
{
    return get_activation_factory<ArcSegment, IArcSegmentStatics>().RotationAngleProperty();
}

inline Windows::UI::Xaml::DependencyProperty ArcSegment::IsLargeArcProperty()
{
    return get_activation_factory<ArcSegment, IArcSegmentStatics>().IsLargeArcProperty();
}

inline Windows::UI::Xaml::DependencyProperty ArcSegment::SweepDirectionProperty()
{
    return get_activation_factory<ArcSegment, IArcSegmentStatics>().SweepDirectionProperty();
}

inline BezierSegment::BezierSegment() :
    BezierSegment(activate_instance<BezierSegment>())
{}

inline Windows::UI::Xaml::DependencyProperty BezierSegment::Point1Property()
{
    return get_activation_factory<BezierSegment, IBezierSegmentStatics>().Point1Property();
}

inline Windows::UI::Xaml::DependencyProperty BezierSegment::Point2Property()
{
    return get_activation_factory<BezierSegment, IBezierSegmentStatics>().Point2Property();
}

inline Windows::UI::Xaml::DependencyProperty BezierSegment::Point3Property()
{
    return get_activation_factory<BezierSegment, IBezierSegmentStatics>().Point3Property();
}

inline BitmapCache::BitmapCache() :
    BitmapCache(activate_instance<BitmapCache>())
{}

inline Windows::UI::Xaml::DependencyProperty Brush::OpacityProperty()
{
    return get_activation_factory<Brush, IBrushStatics>().OpacityProperty();
}

inline Windows::UI::Xaml::DependencyProperty Brush::TransformProperty()
{
    return get_activation_factory<Brush, IBrushStatics>().TransformProperty();
}

inline Windows::UI::Xaml::DependencyProperty Brush::RelativeTransformProperty()
{
    return get_activation_factory<Brush, IBrushStatics>().RelativeTransformProperty();
}

inline BrushCollection::BrushCollection() :
    BrushCollection(activate_instance<BrushCollection>())
{}

inline CompositeTransform::CompositeTransform() :
    CompositeTransform(activate_instance<CompositeTransform>())
{}

inline Windows::UI::Xaml::DependencyProperty CompositeTransform::CenterXProperty()
{
    return get_activation_factory<CompositeTransform, ICompositeTransformStatics>().CenterXProperty();
}

inline Windows::UI::Xaml::DependencyProperty CompositeTransform::CenterYProperty()
{
    return get_activation_factory<CompositeTransform, ICompositeTransformStatics>().CenterYProperty();
}

inline Windows::UI::Xaml::DependencyProperty CompositeTransform::ScaleXProperty()
{
    return get_activation_factory<CompositeTransform, ICompositeTransformStatics>().ScaleXProperty();
}

inline Windows::UI::Xaml::DependencyProperty CompositeTransform::ScaleYProperty()
{
    return get_activation_factory<CompositeTransform, ICompositeTransformStatics>().ScaleYProperty();
}

inline Windows::UI::Xaml::DependencyProperty CompositeTransform::SkewXProperty()
{
    return get_activation_factory<CompositeTransform, ICompositeTransformStatics>().SkewXProperty();
}

inline Windows::UI::Xaml::DependencyProperty CompositeTransform::SkewYProperty()
{
    return get_activation_factory<CompositeTransform, ICompositeTransformStatics>().SkewYProperty();
}

inline Windows::UI::Xaml::DependencyProperty CompositeTransform::RotationProperty()
{
    return get_activation_factory<CompositeTransform, ICompositeTransformStatics>().RotationProperty();
}

inline Windows::UI::Xaml::DependencyProperty CompositeTransform::TranslateXProperty()
{
    return get_activation_factory<CompositeTransform, ICompositeTransformStatics>().TranslateXProperty();
}

inline Windows::UI::Xaml::DependencyProperty CompositeTransform::TranslateYProperty()
{
    return get_activation_factory<CompositeTransform, ICompositeTransformStatics>().TranslateYProperty();
}

inline event_token CompositionTarget::Rendering(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value)
{
    return get_activation_factory<CompositionTarget, ICompositionTargetStatics>().Rendering(value);
}

inline factory_event_revoker<ICompositionTargetStatics> CompositionTarget::Rendering(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value)
{
    auto factory = get_activation_factory<CompositionTarget, ICompositionTargetStatics>();
    return { factory, &ABI::Windows::UI::Xaml::Media::ICompositionTargetStatics::remove_Rendering, factory.Rendering(value) };
}

inline void CompositionTarget::Rendering(event_token token)
{
    get_activation_factory<CompositionTarget, ICompositionTargetStatics>().Rendering(token);
}

inline event_token CompositionTarget::SurfaceContentsLost(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value)
{
    return get_activation_factory<CompositionTarget, ICompositionTargetStatics>().SurfaceContentsLost(value);
}

inline factory_event_revoker<ICompositionTargetStatics> CompositionTarget::SurfaceContentsLost(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value)
{
    auto factory = get_activation_factory<CompositionTarget, ICompositionTargetStatics>();
    return { factory, &ABI::Windows::UI::Xaml::Media::ICompositionTargetStatics::remove_SurfaceContentsLost, factory.SurfaceContentsLost(value) };
}

inline void CompositionTarget::SurfaceContentsLost(event_token token)
{
    get_activation_factory<CompositionTarget, ICompositionTargetStatics>().SurfaceContentsLost(token);
}

inline DoubleCollection::DoubleCollection() :
    DoubleCollection(activate_instance<DoubleCollection>())
{}

inline EllipseGeometry::EllipseGeometry() :
    EllipseGeometry(activate_instance<EllipseGeometry>())
{}

inline Windows::UI::Xaml::DependencyProperty EllipseGeometry::CenterProperty()
{
    return get_activation_factory<EllipseGeometry, IEllipseGeometryStatics>().CenterProperty();
}

inline Windows::UI::Xaml::DependencyProperty EllipseGeometry::RadiusXProperty()
{
    return get_activation_factory<EllipseGeometry, IEllipseGeometryStatics>().RadiusXProperty();
}

inline Windows::UI::Xaml::DependencyProperty EllipseGeometry::RadiusYProperty()
{
    return get_activation_factory<EllipseGeometry, IEllipseGeometryStatics>().RadiusYProperty();
}

inline FontFamily::FontFamily(hstring_view familyName)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<FontFamily, IFontFamilyFactory>().CreateInstanceWithName(familyName, outer, inner));
}

inline Windows::UI::Xaml::Media::FontFamily FontFamily::XamlAutoFontFamily()
{
    return get_activation_factory<FontFamily, IFontFamilyStatics2>().XamlAutoFontFamily();
}

inline Windows::UI::Xaml::Media::Geometry Geometry::Empty()
{
    return get_activation_factory<Geometry, IGeometryStatics>().Empty();
}

inline double Geometry::StandardFlatteningTolerance()
{
    return get_activation_factory<Geometry, IGeometryStatics>().StandardFlatteningTolerance();
}

inline Windows::UI::Xaml::DependencyProperty Geometry::TransformProperty()
{
    return get_activation_factory<Geometry, IGeometryStatics>().TransformProperty();
}

inline GeometryCollection::GeometryCollection() :
    GeometryCollection(activate_instance<GeometryCollection>())
{}

inline GeometryGroup::GeometryGroup() :
    GeometryGroup(activate_instance<GeometryGroup>())
{}

inline Windows::UI::Xaml::DependencyProperty GeometryGroup::FillRuleProperty()
{
    return get_activation_factory<GeometryGroup, IGeometryGroupStatics>().FillRuleProperty();
}

inline Windows::UI::Xaml::DependencyProperty GeometryGroup::ChildrenProperty()
{
    return get_activation_factory<GeometryGroup, IGeometryGroupStatics>().ChildrenProperty();
}

inline Windows::UI::Xaml::DependencyProperty GradientBrush::SpreadMethodProperty()
{
    return get_activation_factory<GradientBrush, IGradientBrushStatics>().SpreadMethodProperty();
}

inline Windows::UI::Xaml::DependencyProperty GradientBrush::MappingModeProperty()
{
    return get_activation_factory<GradientBrush, IGradientBrushStatics>().MappingModeProperty();
}

inline Windows::UI::Xaml::DependencyProperty GradientBrush::ColorInterpolationModeProperty()
{
    return get_activation_factory<GradientBrush, IGradientBrushStatics>().ColorInterpolationModeProperty();
}

inline Windows::UI::Xaml::DependencyProperty GradientBrush::GradientStopsProperty()
{
    return get_activation_factory<GradientBrush, IGradientBrushStatics>().GradientStopsProperty();
}

inline GradientStop::GradientStop() :
    GradientStop(activate_instance<GradientStop>())
{}

inline Windows::UI::Xaml::DependencyProperty GradientStop::ColorProperty()
{
    return get_activation_factory<GradientStop, IGradientStopStatics>().ColorProperty();
}

inline Windows::UI::Xaml::DependencyProperty GradientStop::OffsetProperty()
{
    return get_activation_factory<GradientStop, IGradientStopStatics>().OffsetProperty();
}

inline GradientStopCollection::GradientStopCollection() :
    GradientStopCollection(activate_instance<GradientStopCollection>())
{}

inline ImageBrush::ImageBrush() :
    ImageBrush(activate_instance<ImageBrush>())
{}

inline Windows::UI::Xaml::DependencyProperty ImageBrush::ImageSourceProperty()
{
    return get_activation_factory<ImageBrush, IImageBrushStatics>().ImageSourceProperty();
}

inline LineGeometry::LineGeometry() :
    LineGeometry(activate_instance<LineGeometry>())
{}

inline Windows::UI::Xaml::DependencyProperty LineGeometry::StartPointProperty()
{
    return get_activation_factory<LineGeometry, ILineGeometryStatics>().StartPointProperty();
}

inline Windows::UI::Xaml::DependencyProperty LineGeometry::EndPointProperty()
{
    return get_activation_factory<LineGeometry, ILineGeometryStatics>().EndPointProperty();
}

inline LineSegment::LineSegment() :
    LineSegment(activate_instance<LineSegment>())
{}

inline Windows::UI::Xaml::DependencyProperty LineSegment::PointProperty()
{
    return get_activation_factory<LineSegment, ILineSegmentStatics>().PointProperty();
}

inline LinearGradientBrush::LinearGradientBrush() :
    LinearGradientBrush(activate_instance<LinearGradientBrush>())
{}

inline LinearGradientBrush::LinearGradientBrush(const Windows::UI::Xaml::Media::GradientStopCollection & gradientStopCollection, double angle) :
    LinearGradientBrush(get_activation_factory<LinearGradientBrush, ILinearGradientBrushFactory>().CreateInstanceWithGradientStopCollectionAndAngle(gradientStopCollection, angle))
{}

inline Windows::UI::Xaml::DependencyProperty LinearGradientBrush::StartPointProperty()
{
    return get_activation_factory<LinearGradientBrush, ILinearGradientBrushStatics>().StartPointProperty();
}

inline Windows::UI::Xaml::DependencyProperty LinearGradientBrush::EndPointProperty()
{
    return get_activation_factory<LinearGradientBrush, ILinearGradientBrushStatics>().EndPointProperty();
}

inline Matrix3DProjection::Matrix3DProjection() :
    Matrix3DProjection(activate_instance<Matrix3DProjection>())
{}

inline Windows::UI::Xaml::DependencyProperty Matrix3DProjection::ProjectionMatrixProperty()
{
    return get_activation_factory<Matrix3DProjection, IMatrix3DProjectionStatics>().ProjectionMatrixProperty();
}

inline Windows::UI::Xaml::Media::Matrix MatrixHelper::Identity()
{
    return get_activation_factory<MatrixHelper, IMatrixHelperStatics>().Identity();
}

inline Windows::UI::Xaml::Media::Matrix MatrixHelper::FromElements(double m11, double m12, double m21, double m22, double offsetX, double offsetY)
{
    return get_activation_factory<MatrixHelper, IMatrixHelperStatics>().FromElements(m11, m12, m21, m22, offsetX, offsetY);
}

inline bool MatrixHelper::GetIsIdentity(const Windows::UI::Xaml::Media::Matrix & target)
{
    return get_activation_factory<MatrixHelper, IMatrixHelperStatics>().GetIsIdentity(target);
}

inline Windows::Foundation::Point MatrixHelper::Transform(const Windows::UI::Xaml::Media::Matrix & target, const Windows::Foundation::Point & point)
{
    return get_activation_factory<MatrixHelper, IMatrixHelperStatics>().Transform(target, point);
}

inline MatrixTransform::MatrixTransform() :
    MatrixTransform(activate_instance<MatrixTransform>())
{}

inline Windows::UI::Xaml::DependencyProperty MatrixTransform::MatrixProperty()
{
    return get_activation_factory<MatrixTransform, IMatrixTransformStatics>().MatrixProperty();
}

inline PartialMediaFailureDetectedEventArgs::PartialMediaFailureDetectedEventArgs() :
    PartialMediaFailureDetectedEventArgs(activate_instance<PartialMediaFailureDetectedEventArgs>())
{}

inline PathFigure::PathFigure() :
    PathFigure(activate_instance<PathFigure>())
{}

inline Windows::UI::Xaml::DependencyProperty PathFigure::SegmentsProperty()
{
    return get_activation_factory<PathFigure, IPathFigureStatics>().SegmentsProperty();
}

inline Windows::UI::Xaml::DependencyProperty PathFigure::StartPointProperty()
{
    return get_activation_factory<PathFigure, IPathFigureStatics>().StartPointProperty();
}

inline Windows::UI::Xaml::DependencyProperty PathFigure::IsClosedProperty()
{
    return get_activation_factory<PathFigure, IPathFigureStatics>().IsClosedProperty();
}

inline Windows::UI::Xaml::DependencyProperty PathFigure::IsFilledProperty()
{
    return get_activation_factory<PathFigure, IPathFigureStatics>().IsFilledProperty();
}

inline PathFigureCollection::PathFigureCollection() :
    PathFigureCollection(activate_instance<PathFigureCollection>())
{}

inline PathGeometry::PathGeometry() :
    PathGeometry(activate_instance<PathGeometry>())
{}

inline Windows::UI::Xaml::DependencyProperty PathGeometry::FillRuleProperty()
{
    return get_activation_factory<PathGeometry, IPathGeometryStatics>().FillRuleProperty();
}

inline Windows::UI::Xaml::DependencyProperty PathGeometry::FiguresProperty()
{
    return get_activation_factory<PathGeometry, IPathGeometryStatics>().FiguresProperty();
}

inline PathSegmentCollection::PathSegmentCollection() :
    PathSegmentCollection(activate_instance<PathSegmentCollection>())
{}

inline PlaneProjection::PlaneProjection() :
    PlaneProjection(activate_instance<PlaneProjection>())
{}

inline Windows::UI::Xaml::DependencyProperty PlaneProjection::LocalOffsetXProperty()
{
    return get_activation_factory<PlaneProjection, IPlaneProjectionStatics>().LocalOffsetXProperty();
}

inline Windows::UI::Xaml::DependencyProperty PlaneProjection::LocalOffsetYProperty()
{
    return get_activation_factory<PlaneProjection, IPlaneProjectionStatics>().LocalOffsetYProperty();
}

inline Windows::UI::Xaml::DependencyProperty PlaneProjection::LocalOffsetZProperty()
{
    return get_activation_factory<PlaneProjection, IPlaneProjectionStatics>().LocalOffsetZProperty();
}

inline Windows::UI::Xaml::DependencyProperty PlaneProjection::RotationXProperty()
{
    return get_activation_factory<PlaneProjection, IPlaneProjectionStatics>().RotationXProperty();
}

inline Windows::UI::Xaml::DependencyProperty PlaneProjection::RotationYProperty()
{
    return get_activation_factory<PlaneProjection, IPlaneProjectionStatics>().RotationYProperty();
}

inline Windows::UI::Xaml::DependencyProperty PlaneProjection::RotationZProperty()
{
    return get_activation_factory<PlaneProjection, IPlaneProjectionStatics>().RotationZProperty();
}

inline Windows::UI::Xaml::DependencyProperty PlaneProjection::CenterOfRotationXProperty()
{
    return get_activation_factory<PlaneProjection, IPlaneProjectionStatics>().CenterOfRotationXProperty();
}

inline Windows::UI::Xaml::DependencyProperty PlaneProjection::CenterOfRotationYProperty()
{
    return get_activation_factory<PlaneProjection, IPlaneProjectionStatics>().CenterOfRotationYProperty();
}

inline Windows::UI::Xaml::DependencyProperty PlaneProjection::CenterOfRotationZProperty()
{
    return get_activation_factory<PlaneProjection, IPlaneProjectionStatics>().CenterOfRotationZProperty();
}

inline Windows::UI::Xaml::DependencyProperty PlaneProjection::GlobalOffsetXProperty()
{
    return get_activation_factory<PlaneProjection, IPlaneProjectionStatics>().GlobalOffsetXProperty();
}

inline Windows::UI::Xaml::DependencyProperty PlaneProjection::GlobalOffsetYProperty()
{
    return get_activation_factory<PlaneProjection, IPlaneProjectionStatics>().GlobalOffsetYProperty();
}

inline Windows::UI::Xaml::DependencyProperty PlaneProjection::GlobalOffsetZProperty()
{
    return get_activation_factory<PlaneProjection, IPlaneProjectionStatics>().GlobalOffsetZProperty();
}

inline Windows::UI::Xaml::DependencyProperty PlaneProjection::ProjectionMatrixProperty()
{
    return get_activation_factory<PlaneProjection, IPlaneProjectionStatics>().ProjectionMatrixProperty();
}

inline PointCollection::PointCollection() :
    PointCollection(activate_instance<PointCollection>())
{}

inline PolyBezierSegment::PolyBezierSegment() :
    PolyBezierSegment(activate_instance<PolyBezierSegment>())
{}

inline Windows::UI::Xaml::DependencyProperty PolyBezierSegment::PointsProperty()
{
    return get_activation_factory<PolyBezierSegment, IPolyBezierSegmentStatics>().PointsProperty();
}

inline PolyLineSegment::PolyLineSegment() :
    PolyLineSegment(activate_instance<PolyLineSegment>())
{}

inline Windows::UI::Xaml::DependencyProperty PolyLineSegment::PointsProperty()
{
    return get_activation_factory<PolyLineSegment, IPolyLineSegmentStatics>().PointsProperty();
}

inline PolyQuadraticBezierSegment::PolyQuadraticBezierSegment() :
    PolyQuadraticBezierSegment(activate_instance<PolyQuadraticBezierSegment>())
{}

inline Windows::UI::Xaml::DependencyProperty PolyQuadraticBezierSegment::PointsProperty()
{
    return get_activation_factory<PolyQuadraticBezierSegment, IPolyQuadraticBezierSegmentStatics>().PointsProperty();
}

inline QuadraticBezierSegment::QuadraticBezierSegment() :
    QuadraticBezierSegment(activate_instance<QuadraticBezierSegment>())
{}

inline Windows::UI::Xaml::DependencyProperty QuadraticBezierSegment::Point1Property()
{
    return get_activation_factory<QuadraticBezierSegment, IQuadraticBezierSegmentStatics>().Point1Property();
}

inline Windows::UI::Xaml::DependencyProperty QuadraticBezierSegment::Point2Property()
{
    return get_activation_factory<QuadraticBezierSegment, IQuadraticBezierSegmentStatics>().Point2Property();
}

inline RateChangedRoutedEventArgs::RateChangedRoutedEventArgs() :
    RateChangedRoutedEventArgs(activate_instance<RateChangedRoutedEventArgs>())
{}

inline RectangleGeometry::RectangleGeometry() :
    RectangleGeometry(activate_instance<RectangleGeometry>())
{}

inline Windows::UI::Xaml::DependencyProperty RectangleGeometry::RectProperty()
{
    return get_activation_factory<RectangleGeometry, IRectangleGeometryStatics>().RectProperty();
}

inline RotateTransform::RotateTransform() :
    RotateTransform(activate_instance<RotateTransform>())
{}

inline Windows::UI::Xaml::DependencyProperty RotateTransform::CenterXProperty()
{
    return get_activation_factory<RotateTransform, IRotateTransformStatics>().CenterXProperty();
}

inline Windows::UI::Xaml::DependencyProperty RotateTransform::CenterYProperty()
{
    return get_activation_factory<RotateTransform, IRotateTransformStatics>().CenterYProperty();
}

inline Windows::UI::Xaml::DependencyProperty RotateTransform::AngleProperty()
{
    return get_activation_factory<RotateTransform, IRotateTransformStatics>().AngleProperty();
}

inline ScaleTransform::ScaleTransform() :
    ScaleTransform(activate_instance<ScaleTransform>())
{}

inline Windows::UI::Xaml::DependencyProperty ScaleTransform::CenterXProperty()
{
    return get_activation_factory<ScaleTransform, IScaleTransformStatics>().CenterXProperty();
}

inline Windows::UI::Xaml::DependencyProperty ScaleTransform::CenterYProperty()
{
    return get_activation_factory<ScaleTransform, IScaleTransformStatics>().CenterYProperty();
}

inline Windows::UI::Xaml::DependencyProperty ScaleTransform::ScaleXProperty()
{
    return get_activation_factory<ScaleTransform, IScaleTransformStatics>().ScaleXProperty();
}

inline Windows::UI::Xaml::DependencyProperty ScaleTransform::ScaleYProperty()
{
    return get_activation_factory<ScaleTransform, IScaleTransformStatics>().ScaleYProperty();
}

inline SkewTransform::SkewTransform() :
    SkewTransform(activate_instance<SkewTransform>())
{}

inline Windows::UI::Xaml::DependencyProperty SkewTransform::CenterXProperty()
{
    return get_activation_factory<SkewTransform, ISkewTransformStatics>().CenterXProperty();
}

inline Windows::UI::Xaml::DependencyProperty SkewTransform::CenterYProperty()
{
    return get_activation_factory<SkewTransform, ISkewTransformStatics>().CenterYProperty();
}

inline Windows::UI::Xaml::DependencyProperty SkewTransform::AngleXProperty()
{
    return get_activation_factory<SkewTransform, ISkewTransformStatics>().AngleXProperty();
}

inline Windows::UI::Xaml::DependencyProperty SkewTransform::AngleYProperty()
{
    return get_activation_factory<SkewTransform, ISkewTransformStatics>().AngleYProperty();
}

inline SolidColorBrush::SolidColorBrush() :
    SolidColorBrush(activate_instance<SolidColorBrush>())
{}

inline SolidColorBrush::SolidColorBrush(const Windows::UI::Color & color) :
    SolidColorBrush(get_activation_factory<SolidColorBrush, ISolidColorBrushFactory>().CreateInstanceWithColor(color))
{}

inline Windows::UI::Xaml::DependencyProperty SolidColorBrush::ColorProperty()
{
    return get_activation_factory<SolidColorBrush, ISolidColorBrushStatics>().ColorProperty();
}

inline Windows::UI::Xaml::DependencyProperty TileBrush::AlignmentXProperty()
{
    return get_activation_factory<TileBrush, ITileBrushStatics>().AlignmentXProperty();
}

inline Windows::UI::Xaml::DependencyProperty TileBrush::AlignmentYProperty()
{
    return get_activation_factory<TileBrush, ITileBrushStatics>().AlignmentYProperty();
}

inline Windows::UI::Xaml::DependencyProperty TileBrush::StretchProperty()
{
    return get_activation_factory<TileBrush, ITileBrushStatics>().StretchProperty();
}

inline TimelineMarker::TimelineMarker() :
    TimelineMarker(activate_instance<TimelineMarker>())
{}

inline Windows::UI::Xaml::DependencyProperty TimelineMarker::TimeProperty()
{
    return get_activation_factory<TimelineMarker, ITimelineMarkerStatics>().TimeProperty();
}

inline Windows::UI::Xaml::DependencyProperty TimelineMarker::TypeProperty()
{
    return get_activation_factory<TimelineMarker, ITimelineMarkerStatics>().TypeProperty();
}

inline Windows::UI::Xaml::DependencyProperty TimelineMarker::TextProperty()
{
    return get_activation_factory<TimelineMarker, ITimelineMarkerStatics>().TextProperty();
}

inline TimelineMarkerCollection::TimelineMarkerCollection() :
    TimelineMarkerCollection(activate_instance<TimelineMarkerCollection>())
{}

inline TimelineMarkerRoutedEventArgs::TimelineMarkerRoutedEventArgs() :
    TimelineMarkerRoutedEventArgs(activate_instance<TimelineMarkerRoutedEventArgs>())
{}

inline TransformCollection::TransformCollection() :
    TransformCollection(activate_instance<TransformCollection>())
{}

inline TransformGroup::TransformGroup() :
    TransformGroup(activate_instance<TransformGroup>())
{}

inline Windows::UI::Xaml::DependencyProperty TransformGroup::ChildrenProperty()
{
    return get_activation_factory<TransformGroup, ITransformGroupStatics>().ChildrenProperty();
}

inline TranslateTransform::TranslateTransform() :
    TranslateTransform(activate_instance<TranslateTransform>())
{}

inline Windows::UI::Xaml::DependencyProperty TranslateTransform::XProperty()
{
    return get_activation_factory<TranslateTransform, ITranslateTransformStatics>().XProperty();
}

inline Windows::UI::Xaml::DependencyProperty TranslateTransform::YProperty()
{
    return get_activation_factory<TranslateTransform, ITranslateTransformStatics>().YProperty();
}

inline Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> VisualTreeHelper::FindElementsInHostCoordinates(const Windows::Foundation::Point & intersectingPoint, const Windows::UI::Xaml::UIElement & subtree)
{
    return get_activation_factory<VisualTreeHelper, IVisualTreeHelperStatics>().FindElementsInHostCoordinates(intersectingPoint, subtree);
}

inline Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> VisualTreeHelper::FindElementsInHostCoordinates(const Windows::Foundation::Rect & intersectingRect, const Windows::UI::Xaml::UIElement & subtree)
{
    return get_activation_factory<VisualTreeHelper, IVisualTreeHelperStatics>().FindElementsInHostCoordinates(intersectingRect, subtree);
}

inline Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> VisualTreeHelper::FindElementsInHostCoordinates(const Windows::Foundation::Point & intersectingPoint, const Windows::UI::Xaml::UIElement & subtree, bool includeAllElements)
{
    return get_activation_factory<VisualTreeHelper, IVisualTreeHelperStatics>().FindElementsInHostCoordinates(intersectingPoint, subtree, includeAllElements);
}

inline Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> VisualTreeHelper::FindElementsInHostCoordinates(const Windows::Foundation::Rect & intersectingRect, const Windows::UI::Xaml::UIElement & subtree, bool includeAllElements)
{
    return get_activation_factory<VisualTreeHelper, IVisualTreeHelperStatics>().FindElementsInHostCoordinates(intersectingRect, subtree, includeAllElements);
}

inline Windows::UI::Xaml::DependencyObject VisualTreeHelper::GetChild(const Windows::UI::Xaml::DependencyObject & reference, int32_t childIndex)
{
    return get_activation_factory<VisualTreeHelper, IVisualTreeHelperStatics>().GetChild(reference, childIndex);
}

inline int32_t VisualTreeHelper::GetChildrenCount(const Windows::UI::Xaml::DependencyObject & reference)
{
    return get_activation_factory<VisualTreeHelper, IVisualTreeHelperStatics>().GetChildrenCount(reference);
}

inline Windows::UI::Xaml::DependencyObject VisualTreeHelper::GetParent(const Windows::UI::Xaml::DependencyObject & reference)
{
    return get_activation_factory<VisualTreeHelper, IVisualTreeHelperStatics>().GetParent(reference);
}

inline void VisualTreeHelper::DisconnectChildrenRecursive(const Windows::UI::Xaml::UIElement & element)
{
    get_activation_factory<VisualTreeHelper, IVisualTreeHelperStatics>().DisconnectChildrenRecursive(element);
}

inline Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Controls::Primitives::Popup> VisualTreeHelper::GetOpenPopups(const Windows::UI::Xaml::Window & window)
{
    return get_activation_factory<VisualTreeHelper, IVisualTreeHelperStatics2>().GetOpenPopups(window);
}

}

}
#pragma warning(pop)
