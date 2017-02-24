// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.UI.Xaml.Media.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.Xaml.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Composition.3.h"
#include "internal/Windows.UI.Xaml.Shapes.3.h"
#include "Windows.UI.Xaml.h"
#include "internal/Windows.UI.Xaml.Shapes.5.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Shapes::IEllipse> : produce_base<D, Windows::UI::Xaml::Shapes::IEllipse>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Shapes::ILine> : produce_base<D, Windows::UI::Xaml::Shapes::ILine>
{
    HRESULT __stdcall get_X1(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().X1());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_X1(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().X1(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Y1(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Y1());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Y1(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Y1(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_X2(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().X2());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_X2(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().X2(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Y2(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Y2());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Y2(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Y2(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Shapes::ILineStatics> : produce_base<D, Windows::UI::Xaml::Shapes::ILineStatics>
{
    HRESULT __stdcall get_X1Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().X1Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Y1Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Y1Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_X2Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().X2Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Y2Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Y2Property());
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
struct produce<D, Windows::UI::Xaml::Shapes::IPath> : produce_base<D, Windows::UI::Xaml::Shapes::IPath>
{
    HRESULT __stdcall get_Data(impl::abi_arg_out<Windows::UI::Xaml::Media::IGeometry> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Data());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Data(impl::abi_arg_in<Windows::UI::Xaml::Media::IGeometry> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Data(*reinterpret_cast<const Windows::UI::Xaml::Media::Geometry *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Shapes::IPathFactory> : produce_base<D, Windows::UI::Xaml::Shapes::IPathFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Shapes::IPath> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::Shapes::IPathStatics> : produce_base<D, Windows::UI::Xaml::Shapes::IPathStatics>
{
    HRESULT __stdcall get_DataProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataProperty());
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
struct produce<D, Windows::UI::Xaml::Shapes::IPolygon> : produce_base<D, Windows::UI::Xaml::Shapes::IPolygon>
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
struct produce<D, Windows::UI::Xaml::Shapes::IPolygonStatics> : produce_base<D, Windows::UI::Xaml::Shapes::IPolygonStatics>
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
struct produce<D, Windows::UI::Xaml::Shapes::IPolyline> : produce_base<D, Windows::UI::Xaml::Shapes::IPolyline>
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
struct produce<D, Windows::UI::Xaml::Shapes::IPolylineStatics> : produce_base<D, Windows::UI::Xaml::Shapes::IPolylineStatics>
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
struct produce<D, Windows::UI::Xaml::Shapes::IRectangle> : produce_base<D, Windows::UI::Xaml::Shapes::IRectangle>
{
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
struct produce<D, Windows::UI::Xaml::Shapes::IRectangleStatics> : produce_base<D, Windows::UI::Xaml::Shapes::IRectangleStatics>
{
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
struct produce<D, Windows::UI::Xaml::Shapes::IShape> : produce_base<D, Windows::UI::Xaml::Shapes::IShape>
{
    HRESULT __stdcall get_Fill(impl::abi_arg_out<Windows::UI::Xaml::Media::IBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Fill());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Fill(impl::abi_arg_in<Windows::UI::Xaml::Media::IBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Fill(*reinterpret_cast<const Windows::UI::Xaml::Media::Brush *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Stroke(impl::abi_arg_out<Windows::UI::Xaml::Media::IBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Stroke());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Stroke(impl::abi_arg_in<Windows::UI::Xaml::Media::IBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stroke(*reinterpret_cast<const Windows::UI::Xaml::Media::Brush *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeMiterLimit(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeMiterLimit());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StrokeMiterLimit(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeMiterLimit(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeThickness(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeThickness());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StrokeThickness(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeThickness(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeStartLineCap(Windows::UI::Xaml::Media::PenLineCap * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeStartLineCap());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StrokeStartLineCap(Windows::UI::Xaml::Media::PenLineCap value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeStartLineCap(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeEndLineCap(Windows::UI::Xaml::Media::PenLineCap * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeEndLineCap());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StrokeEndLineCap(Windows::UI::Xaml::Media::PenLineCap value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeEndLineCap(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeLineJoin(Windows::UI::Xaml::Media::PenLineJoin * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeLineJoin());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StrokeLineJoin(Windows::UI::Xaml::Media::PenLineJoin value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeLineJoin(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeDashOffset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeDashOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StrokeDashOffset(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeDashOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeDashCap(Windows::UI::Xaml::Media::PenLineCap * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeDashCap());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StrokeDashCap(Windows::UI::Xaml::Media::PenLineCap value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeDashCap(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeDashArray(impl::abi_arg_out<Windows::Foundation::Collections::IVector<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeDashArray());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StrokeDashArray(impl::abi_arg_in<Windows::Foundation::Collections::IVector<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeDashArray(*reinterpret_cast<const Windows::UI::Xaml::Media::DoubleCollection *>(&value));
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

    HRESULT __stdcall get_GeometryTransform(impl::abi_arg_out<Windows::UI::Xaml::Media::ITransform> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GeometryTransform());
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
struct produce<D, Windows::UI::Xaml::Shapes::IShape2> : produce_base<D, Windows::UI::Xaml::Shapes::IShape2>
{
    HRESULT __stdcall abi_GetAlphaMask(impl::abi_arg_out<Windows::UI::Composition::ICompositionBrush> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAlphaMask());
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
struct produce<D, Windows::UI::Xaml::Shapes::IShapeFactory> : produce_base<D, Windows::UI::Xaml::Shapes::IShapeFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Shapes::IShape> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::Shapes::IShapeStatics> : produce_base<D, Windows::UI::Xaml::Shapes::IShapeStatics>
{
    HRESULT __stdcall get_FillProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FillProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeMiterLimitProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeMiterLimitProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeThicknessProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeThicknessProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeStartLineCapProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeStartLineCapProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeEndLineCapProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeEndLineCapProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeLineJoinProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeLineJoinProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeDashOffsetProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeDashOffsetProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeDashCapProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeDashCapProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeDashArrayProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeDashArrayProperty());
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

}

namespace Windows::UI::Xaml::Shapes {

template <typename D> Windows::UI::Xaml::Media::Brush impl_IShape<D>::Fill() const
{
    Windows::UI::Xaml::Media::Brush value { nullptr };
    check_hresult(WINRT_SHIM(IShape)->get_Fill(put_abi(value)));
    return value;
}

template <typename D> void impl_IShape<D>::Fill(const Windows::UI::Xaml::Media::Brush & value) const
{
    check_hresult(WINRT_SHIM(IShape)->put_Fill(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Brush impl_IShape<D>::Stroke() const
{
    Windows::UI::Xaml::Media::Brush value { nullptr };
    check_hresult(WINRT_SHIM(IShape)->get_Stroke(put_abi(value)));
    return value;
}

template <typename D> void impl_IShape<D>::Stroke(const Windows::UI::Xaml::Media::Brush & value) const
{
    check_hresult(WINRT_SHIM(IShape)->put_Stroke(get_abi(value)));
}

template <typename D> double impl_IShape<D>::StrokeMiterLimit() const
{
    double value {};
    check_hresult(WINRT_SHIM(IShape)->get_StrokeMiterLimit(&value));
    return value;
}

template <typename D> void impl_IShape<D>::StrokeMiterLimit(double value) const
{
    check_hresult(WINRT_SHIM(IShape)->put_StrokeMiterLimit(value));
}

template <typename D> double impl_IShape<D>::StrokeThickness() const
{
    double value {};
    check_hresult(WINRT_SHIM(IShape)->get_StrokeThickness(&value));
    return value;
}

template <typename D> void impl_IShape<D>::StrokeThickness(double value) const
{
    check_hresult(WINRT_SHIM(IShape)->put_StrokeThickness(value));
}

template <typename D> Windows::UI::Xaml::Media::PenLineCap impl_IShape<D>::StrokeStartLineCap() const
{
    Windows::UI::Xaml::Media::PenLineCap value {};
    check_hresult(WINRT_SHIM(IShape)->get_StrokeStartLineCap(&value));
    return value;
}

template <typename D> void impl_IShape<D>::StrokeStartLineCap(Windows::UI::Xaml::Media::PenLineCap value) const
{
    check_hresult(WINRT_SHIM(IShape)->put_StrokeStartLineCap(value));
}

template <typename D> Windows::UI::Xaml::Media::PenLineCap impl_IShape<D>::StrokeEndLineCap() const
{
    Windows::UI::Xaml::Media::PenLineCap value {};
    check_hresult(WINRT_SHIM(IShape)->get_StrokeEndLineCap(&value));
    return value;
}

template <typename D> void impl_IShape<D>::StrokeEndLineCap(Windows::UI::Xaml::Media::PenLineCap value) const
{
    check_hresult(WINRT_SHIM(IShape)->put_StrokeEndLineCap(value));
}

template <typename D> Windows::UI::Xaml::Media::PenLineJoin impl_IShape<D>::StrokeLineJoin() const
{
    Windows::UI::Xaml::Media::PenLineJoin value {};
    check_hresult(WINRT_SHIM(IShape)->get_StrokeLineJoin(&value));
    return value;
}

template <typename D> void impl_IShape<D>::StrokeLineJoin(Windows::UI::Xaml::Media::PenLineJoin value) const
{
    check_hresult(WINRT_SHIM(IShape)->put_StrokeLineJoin(value));
}

template <typename D> double impl_IShape<D>::StrokeDashOffset() const
{
    double value {};
    check_hresult(WINRT_SHIM(IShape)->get_StrokeDashOffset(&value));
    return value;
}

template <typename D> void impl_IShape<D>::StrokeDashOffset(double value) const
{
    check_hresult(WINRT_SHIM(IShape)->put_StrokeDashOffset(value));
}

template <typename D> Windows::UI::Xaml::Media::PenLineCap impl_IShape<D>::StrokeDashCap() const
{
    Windows::UI::Xaml::Media::PenLineCap value {};
    check_hresult(WINRT_SHIM(IShape)->get_StrokeDashCap(&value));
    return value;
}

template <typename D> void impl_IShape<D>::StrokeDashCap(Windows::UI::Xaml::Media::PenLineCap value) const
{
    check_hresult(WINRT_SHIM(IShape)->put_StrokeDashCap(value));
}

template <typename D> Windows::UI::Xaml::Media::DoubleCollection impl_IShape<D>::StrokeDashArray() const
{
    Windows::UI::Xaml::Media::DoubleCollection value { nullptr };
    check_hresult(WINRT_SHIM(IShape)->get_StrokeDashArray(put_abi(value)));
    return value;
}

template <typename D> void impl_IShape<D>::StrokeDashArray(const Windows::UI::Xaml::Media::DoubleCollection & value) const
{
    check_hresult(WINRT_SHIM(IShape)->put_StrokeDashArray(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Stretch impl_IShape<D>::Stretch() const
{
    Windows::UI::Xaml::Media::Stretch value {};
    check_hresult(WINRT_SHIM(IShape)->get_Stretch(&value));
    return value;
}

template <typename D> void impl_IShape<D>::Stretch(Windows::UI::Xaml::Media::Stretch value) const
{
    check_hresult(WINRT_SHIM(IShape)->put_Stretch(value));
}

template <typename D> Windows::UI::Xaml::Media::Transform impl_IShape<D>::GeometryTransform() const
{
    Windows::UI::Xaml::Media::Transform value { nullptr };
    check_hresult(WINRT_SHIM(IShape)->get_GeometryTransform(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IShapeStatics<D>::FillProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IShapeStatics)->get_FillProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IShapeStatics<D>::StrokeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IShapeStatics)->get_StrokeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IShapeStatics<D>::StrokeMiterLimitProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IShapeStatics)->get_StrokeMiterLimitProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IShapeStatics<D>::StrokeThicknessProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IShapeStatics)->get_StrokeThicknessProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IShapeStatics<D>::StrokeStartLineCapProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IShapeStatics)->get_StrokeStartLineCapProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IShapeStatics<D>::StrokeEndLineCapProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IShapeStatics)->get_StrokeEndLineCapProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IShapeStatics<D>::StrokeLineJoinProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IShapeStatics)->get_StrokeLineJoinProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IShapeStatics<D>::StrokeDashOffsetProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IShapeStatics)->get_StrokeDashOffsetProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IShapeStatics<D>::StrokeDashCapProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IShapeStatics)->get_StrokeDashCapProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IShapeStatics<D>::StrokeDashArrayProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IShapeStatics)->get_StrokeDashArrayProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IShapeStatics<D>::StretchProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IShapeStatics)->get_StretchProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Shapes::Shape impl_IShapeFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Shapes::Shape instance { nullptr };
    check_hresult(WINRT_SHIM(IShapeFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Composition::CompositionBrush impl_IShape2<D>::GetAlphaMask() const
{
    Windows::UI::Composition::CompositionBrush returnValue { nullptr };
    check_hresult(WINRT_SHIM(IShape2)->abi_GetAlphaMask(put_abi(returnValue)));
    return returnValue;
}

template <typename D> double impl_ILine<D>::X1() const
{
    double value {};
    check_hresult(WINRT_SHIM(ILine)->get_X1(&value));
    return value;
}

template <typename D> void impl_ILine<D>::X1(double value) const
{
    check_hresult(WINRT_SHIM(ILine)->put_X1(value));
}

template <typename D> double impl_ILine<D>::Y1() const
{
    double value {};
    check_hresult(WINRT_SHIM(ILine)->get_Y1(&value));
    return value;
}

template <typename D> void impl_ILine<D>::Y1(double value) const
{
    check_hresult(WINRT_SHIM(ILine)->put_Y1(value));
}

template <typename D> double impl_ILine<D>::X2() const
{
    double value {};
    check_hresult(WINRT_SHIM(ILine)->get_X2(&value));
    return value;
}

template <typename D> void impl_ILine<D>::X2(double value) const
{
    check_hresult(WINRT_SHIM(ILine)->put_X2(value));
}

template <typename D> double impl_ILine<D>::Y2() const
{
    double value {};
    check_hresult(WINRT_SHIM(ILine)->get_Y2(&value));
    return value;
}

template <typename D> void impl_ILine<D>::Y2(double value) const
{
    check_hresult(WINRT_SHIM(ILine)->put_Y2(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ILineStatics<D>::X1Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ILineStatics)->get_X1Property(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ILineStatics<D>::Y1Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ILineStatics)->get_Y1Property(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ILineStatics<D>::X2Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ILineStatics)->get_X2Property(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ILineStatics<D>::Y2Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ILineStatics)->get_Y2Property(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Geometry impl_IPath<D>::Data() const
{
    Windows::UI::Xaml::Media::Geometry value { nullptr };
    check_hresult(WINRT_SHIM(IPath)->get_Data(put_abi(value)));
    return value;
}

template <typename D> void impl_IPath<D>::Data(const Windows::UI::Xaml::Media::Geometry & value) const
{
    check_hresult(WINRT_SHIM(IPath)->put_Data(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPathStatics<D>::DataProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPathStatics)->get_DataProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Shapes::Path impl_IPathFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Shapes::Path instance { nullptr };
    check_hresult(WINRT_SHIM(IPathFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Media::FillRule impl_IPolygon<D>::FillRule() const
{
    Windows::UI::Xaml::Media::FillRule value {};
    check_hresult(WINRT_SHIM(IPolygon)->get_FillRule(&value));
    return value;
}

template <typename D> void impl_IPolygon<D>::FillRule(Windows::UI::Xaml::Media::FillRule value) const
{
    check_hresult(WINRT_SHIM(IPolygon)->put_FillRule(value));
}

template <typename D> Windows::UI::Xaml::Media::PointCollection impl_IPolygon<D>::Points() const
{
    Windows::UI::Xaml::Media::PointCollection value { nullptr };
    check_hresult(WINRT_SHIM(IPolygon)->get_Points(put_abi(value)));
    return value;
}

template <typename D> void impl_IPolygon<D>::Points(const Windows::UI::Xaml::Media::PointCollection & value) const
{
    check_hresult(WINRT_SHIM(IPolygon)->put_Points(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPolygonStatics<D>::FillRuleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPolygonStatics)->get_FillRuleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPolygonStatics<D>::PointsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPolygonStatics)->get_PointsProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::FillRule impl_IPolyline<D>::FillRule() const
{
    Windows::UI::Xaml::Media::FillRule value {};
    check_hresult(WINRT_SHIM(IPolyline)->get_FillRule(&value));
    return value;
}

template <typename D> void impl_IPolyline<D>::FillRule(Windows::UI::Xaml::Media::FillRule value) const
{
    check_hresult(WINRT_SHIM(IPolyline)->put_FillRule(value));
}

template <typename D> Windows::UI::Xaml::Media::PointCollection impl_IPolyline<D>::Points() const
{
    Windows::UI::Xaml::Media::PointCollection value { nullptr };
    check_hresult(WINRT_SHIM(IPolyline)->get_Points(put_abi(value)));
    return value;
}

template <typename D> void impl_IPolyline<D>::Points(const Windows::UI::Xaml::Media::PointCollection & value) const
{
    check_hresult(WINRT_SHIM(IPolyline)->put_Points(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPolylineStatics<D>::FillRuleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPolylineStatics)->get_FillRuleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPolylineStatics<D>::PointsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPolylineStatics)->get_PointsProperty(put_abi(value)));
    return value;
}

template <typename D> double impl_IRectangle<D>::RadiusX() const
{
    double value {};
    check_hresult(WINRT_SHIM(IRectangle)->get_RadiusX(&value));
    return value;
}

template <typename D> void impl_IRectangle<D>::RadiusX(double value) const
{
    check_hresult(WINRT_SHIM(IRectangle)->put_RadiusX(value));
}

template <typename D> double impl_IRectangle<D>::RadiusY() const
{
    double value {};
    check_hresult(WINRT_SHIM(IRectangle)->get_RadiusY(&value));
    return value;
}

template <typename D> void impl_IRectangle<D>::RadiusY(double value) const
{
    check_hresult(WINRT_SHIM(IRectangle)->put_RadiusY(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IRectangleStatics<D>::RadiusXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IRectangleStatics)->get_RadiusXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IRectangleStatics<D>::RadiusYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IRectangleStatics)->get_RadiusYProperty(put_abi(value)));
    return value;
}

inline Ellipse::Ellipse() :
    Ellipse(activate_instance<Ellipse>())
{}

inline Line::Line() :
    Line(activate_instance<Line>())
{}

inline Windows::UI::Xaml::DependencyProperty Line::X1Property()
{
    return get_activation_factory<Line, ILineStatics>().X1Property();
}

inline Windows::UI::Xaml::DependencyProperty Line::Y1Property()
{
    return get_activation_factory<Line, ILineStatics>().Y1Property();
}

inline Windows::UI::Xaml::DependencyProperty Line::X2Property()
{
    return get_activation_factory<Line, ILineStatics>().X2Property();
}

inline Windows::UI::Xaml::DependencyProperty Line::Y2Property()
{
    return get_activation_factory<Line, ILineStatics>().Y2Property();
}

inline Path::Path()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<Path, IPathFactory>().CreateInstance(outer, inner));
}

inline Windows::UI::Xaml::DependencyProperty Path::DataProperty()
{
    return get_activation_factory<Path, IPathStatics>().DataProperty();
}

inline Polygon::Polygon() :
    Polygon(activate_instance<Polygon>())
{}

inline Windows::UI::Xaml::DependencyProperty Polygon::FillRuleProperty()
{
    return get_activation_factory<Polygon, IPolygonStatics>().FillRuleProperty();
}

inline Windows::UI::Xaml::DependencyProperty Polygon::PointsProperty()
{
    return get_activation_factory<Polygon, IPolygonStatics>().PointsProperty();
}

inline Polyline::Polyline() :
    Polyline(activate_instance<Polyline>())
{}

inline Windows::UI::Xaml::DependencyProperty Polyline::FillRuleProperty()
{
    return get_activation_factory<Polyline, IPolylineStatics>().FillRuleProperty();
}

inline Windows::UI::Xaml::DependencyProperty Polyline::PointsProperty()
{
    return get_activation_factory<Polyline, IPolylineStatics>().PointsProperty();
}

inline Rectangle::Rectangle() :
    Rectangle(activate_instance<Rectangle>())
{}

inline Windows::UI::Xaml::DependencyProperty Rectangle::RadiusXProperty()
{
    return get_activation_factory<Rectangle, IRectangleStatics>().RadiusXProperty();
}

inline Windows::UI::Xaml::DependencyProperty Rectangle::RadiusYProperty()
{
    return get_activation_factory<Rectangle, IRectangleStatics>().RadiusYProperty();
}

inline Windows::UI::Xaml::DependencyProperty Shape::FillProperty()
{
    return get_activation_factory<Shape, IShapeStatics>().FillProperty();
}

inline Windows::UI::Xaml::DependencyProperty Shape::StrokeProperty()
{
    return get_activation_factory<Shape, IShapeStatics>().StrokeProperty();
}

inline Windows::UI::Xaml::DependencyProperty Shape::StrokeMiterLimitProperty()
{
    return get_activation_factory<Shape, IShapeStatics>().StrokeMiterLimitProperty();
}

inline Windows::UI::Xaml::DependencyProperty Shape::StrokeThicknessProperty()
{
    return get_activation_factory<Shape, IShapeStatics>().StrokeThicknessProperty();
}

inline Windows::UI::Xaml::DependencyProperty Shape::StrokeStartLineCapProperty()
{
    return get_activation_factory<Shape, IShapeStatics>().StrokeStartLineCapProperty();
}

inline Windows::UI::Xaml::DependencyProperty Shape::StrokeEndLineCapProperty()
{
    return get_activation_factory<Shape, IShapeStatics>().StrokeEndLineCapProperty();
}

inline Windows::UI::Xaml::DependencyProperty Shape::StrokeLineJoinProperty()
{
    return get_activation_factory<Shape, IShapeStatics>().StrokeLineJoinProperty();
}

inline Windows::UI::Xaml::DependencyProperty Shape::StrokeDashOffsetProperty()
{
    return get_activation_factory<Shape, IShapeStatics>().StrokeDashOffsetProperty();
}

inline Windows::UI::Xaml::DependencyProperty Shape::StrokeDashCapProperty()
{
    return get_activation_factory<Shape, IShapeStatics>().StrokeDashCapProperty();
}

inline Windows::UI::Xaml::DependencyProperty Shape::StrokeDashArrayProperty()
{
    return get_activation_factory<Shape, IShapeStatics>().StrokeDashArrayProperty();
}

inline Windows::UI::Xaml::DependencyProperty Shape::StretchProperty()
{
    return get_activation_factory<Shape, IShapeStatics>().StretchProperty();
}

}

}
#pragma warning(pop)
