// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.Shapes.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.UI.Composition.0.h"
#include "Windows.UI.Xaml.0.h"
#include "Windows.UI.Xaml.Media.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Shapes {

struct __declspec(uuid("70e05ac4-d38d-4bab-831f-4a22ef52ac86")) __declspec(novtable) IEllipse : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("46a5433d-4ffb-48df-8732-4e15c834816b")) __declspec(novtable) ILine : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_X1(double * value) = 0;
    virtual HRESULT __stdcall put_X1(double value) = 0;
    virtual HRESULT __stdcall get_Y1(double * value) = 0;
    virtual HRESULT __stdcall put_Y1(double value) = 0;
    virtual HRESULT __stdcall get_X2(double * value) = 0;
    virtual HRESULT __stdcall put_X2(double value) = 0;
    virtual HRESULT __stdcall get_Y2(double * value) = 0;
    virtual HRESULT __stdcall put_Y2(double value) = 0;
};

struct __declspec(uuid("267c123d-6ea4-4c50-8b1d-50207aff1e8a")) __declspec(novtable) ILineStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_X1Property(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_Y1Property(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_X2Property(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_Y2Property(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("78883609-3d57-4f3c-b8a5-6cabcac9711f")) __declspec(novtable) IPath : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Data(Windows::UI::Xaml::Media::IGeometry ** value) = 0;
    virtual HRESULT __stdcall put_Data(Windows::UI::Xaml::Media::IGeometry * value) = 0;
};

struct __declspec(uuid("2340a4e3-5a86-4fc6-9a50-cbb93b828766")) __declspec(novtable) IPathFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Shapes::IPath ** instance) = 0;
};

struct __declspec(uuid("f627e59d-87dc-4142-81f1-97fc7ff8641c")) __declspec(novtable) IPathStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DataProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("e3755c19-2e4d-4bcc-8d34-86871957fa01")) __declspec(novtable) IPolygon : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FillRule(winrt::Windows::UI::Xaml::Media::FillRule * value) = 0;
    virtual HRESULT __stdcall put_FillRule(winrt::Windows::UI::Xaml::Media::FillRule value) = 0;
    virtual HRESULT __stdcall get_Points(Windows::Foundation::Collections::IVector<Windows::Foundation::Point> ** value) = 0;
    virtual HRESULT __stdcall put_Points(Windows::Foundation::Collections::IVector<Windows::Foundation::Point> * value) = 0;
};

struct __declspec(uuid("362a8aab-d463-4366-9e1a-beba72810fb7")) __declspec(novtable) IPolygonStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FillRuleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PointsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("91dc62f8-42b3-47f3-8476-c55124a7c4c6")) __declspec(novtable) IPolyline : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FillRule(winrt::Windows::UI::Xaml::Media::FillRule * value) = 0;
    virtual HRESULT __stdcall put_FillRule(winrt::Windows::UI::Xaml::Media::FillRule value) = 0;
    virtual HRESULT __stdcall get_Points(Windows::Foundation::Collections::IVector<Windows::Foundation::Point> ** value) = 0;
    virtual HRESULT __stdcall put_Points(Windows::Foundation::Collections::IVector<Windows::Foundation::Point> * value) = 0;
};

struct __declspec(uuid("c7aa2cd1-a26c-43b0-aaa5-822fa64a11b9")) __declspec(novtable) IPolylineStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FillRuleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PointsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("855bc230-8a11-4e18-a136-4bc21c7827b0")) __declspec(novtable) IRectangle : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RadiusX(double * value) = 0;
    virtual HRESULT __stdcall put_RadiusX(double value) = 0;
    virtual HRESULT __stdcall get_RadiusY(double * value) = 0;
    virtual HRESULT __stdcall put_RadiusY(double value) = 0;
};

struct __declspec(uuid("9f25aa53-bb3a-4c3c-89db-6fbc0d1fa0cc")) __declspec(novtable) IRectangleStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RadiusXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RadiusYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("786f2b75-9aa0-454d-ae06-a2466e37c832")) __declspec(novtable) IShape : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Fill(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_Fill(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_Stroke(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_Stroke(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_StrokeMiterLimit(double * value) = 0;
    virtual HRESULT __stdcall put_StrokeMiterLimit(double value) = 0;
    virtual HRESULT __stdcall get_StrokeThickness(double * value) = 0;
    virtual HRESULT __stdcall put_StrokeThickness(double value) = 0;
    virtual HRESULT __stdcall get_StrokeStartLineCap(winrt::Windows::UI::Xaml::Media::PenLineCap * value) = 0;
    virtual HRESULT __stdcall put_StrokeStartLineCap(winrt::Windows::UI::Xaml::Media::PenLineCap value) = 0;
    virtual HRESULT __stdcall get_StrokeEndLineCap(winrt::Windows::UI::Xaml::Media::PenLineCap * value) = 0;
    virtual HRESULT __stdcall put_StrokeEndLineCap(winrt::Windows::UI::Xaml::Media::PenLineCap value) = 0;
    virtual HRESULT __stdcall get_StrokeLineJoin(winrt::Windows::UI::Xaml::Media::PenLineJoin * value) = 0;
    virtual HRESULT __stdcall put_StrokeLineJoin(winrt::Windows::UI::Xaml::Media::PenLineJoin value) = 0;
    virtual HRESULT __stdcall get_StrokeDashOffset(double * value) = 0;
    virtual HRESULT __stdcall put_StrokeDashOffset(double value) = 0;
    virtual HRESULT __stdcall get_StrokeDashCap(winrt::Windows::UI::Xaml::Media::PenLineCap * value) = 0;
    virtual HRESULT __stdcall put_StrokeDashCap(winrt::Windows::UI::Xaml::Media::PenLineCap value) = 0;
    virtual HRESULT __stdcall get_StrokeDashArray(Windows::Foundation::Collections::IVector<double> ** value) = 0;
    virtual HRESULT __stdcall put_StrokeDashArray(Windows::Foundation::Collections::IVector<double> * value) = 0;
    virtual HRESULT __stdcall get_Stretch(winrt::Windows::UI::Xaml::Media::Stretch * value) = 0;
    virtual HRESULT __stdcall put_Stretch(winrt::Windows::UI::Xaml::Media::Stretch value) = 0;
    virtual HRESULT __stdcall get_GeometryTransform(Windows::UI::Xaml::Media::ITransform ** value) = 0;
};

struct __declspec(uuid("97248dba-49f2-49a4-a5dd-164df824db14")) __declspec(novtable) IShape2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAlphaMask(Windows::UI::Composition::ICompositionBrush ** returnValue) = 0;
};

struct __declspec(uuid("4b717613-f6aa-48d5-9588-e1d188eacbc9")) __declspec(novtable) IShapeFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Shapes::IShape ** instance) = 0;
};

struct __declspec(uuid("1d7b4c55-9df3-48dc-9194-9d306faa6089")) __declspec(novtable) IShapeStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FillProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StrokeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StrokeMiterLimitProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StrokeThicknessProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StrokeStartLineCapProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StrokeEndLineCapProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StrokeLineJoinProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StrokeDashOffsetProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StrokeDashCapProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StrokeDashArrayProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StretchProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::Shapes::Ellipse> { using default_interface = Windows::UI::Xaml::Shapes::IEllipse; };
template <> struct traits<Windows::UI::Xaml::Shapes::Line> { using default_interface = Windows::UI::Xaml::Shapes::ILine; };
template <> struct traits<Windows::UI::Xaml::Shapes::Path> { using default_interface = Windows::UI::Xaml::Shapes::IPath; };
template <> struct traits<Windows::UI::Xaml::Shapes::Polygon> { using default_interface = Windows::UI::Xaml::Shapes::IPolygon; };
template <> struct traits<Windows::UI::Xaml::Shapes::Polyline> { using default_interface = Windows::UI::Xaml::Shapes::IPolyline; };
template <> struct traits<Windows::UI::Xaml::Shapes::Rectangle> { using default_interface = Windows::UI::Xaml::Shapes::IRectangle; };
template <> struct traits<Windows::UI::Xaml::Shapes::Shape> { using default_interface = Windows::UI::Xaml::Shapes::IShape; };

}

namespace Windows::UI::Xaml::Shapes {

template <typename D>
struct WINRT_EBO impl_IEllipse
{
};

template <typename D>
struct WINRT_EBO impl_ILine
{
    double X1() const;
    void X1(double value) const;
    double Y1() const;
    void Y1(double value) const;
    double X2() const;
    void X2(double value) const;
    double Y2() const;
    void Y2(double value) const;
};

template <typename D>
struct WINRT_EBO impl_ILineStatics
{
    Windows::UI::Xaml::DependencyProperty X1Property() const;
    Windows::UI::Xaml::DependencyProperty Y1Property() const;
    Windows::UI::Xaml::DependencyProperty X2Property() const;
    Windows::UI::Xaml::DependencyProperty Y2Property() const;
};

template <typename D>
struct WINRT_EBO impl_IPath
{
    Windows::UI::Xaml::Media::Geometry Data() const;
    void Data(const Windows::UI::Xaml::Media::Geometry & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPathFactory
{
    Windows::UI::Xaml::Shapes::Path CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IPathStatics
{
    Windows::UI::Xaml::DependencyProperty DataProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IPolygon
{
    Windows::UI::Xaml::Media::FillRule FillRule() const;
    void FillRule(Windows::UI::Xaml::Media::FillRule value) const;
    Windows::UI::Xaml::Media::PointCollection Points() const;
    void Points(const Windows::UI::Xaml::Media::PointCollection & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPolygonStatics
{
    Windows::UI::Xaml::DependencyProperty FillRuleProperty() const;
    Windows::UI::Xaml::DependencyProperty PointsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IPolyline
{
    Windows::UI::Xaml::Media::FillRule FillRule() const;
    void FillRule(Windows::UI::Xaml::Media::FillRule value) const;
    Windows::UI::Xaml::Media::PointCollection Points() const;
    void Points(const Windows::UI::Xaml::Media::PointCollection & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPolylineStatics
{
    Windows::UI::Xaml::DependencyProperty FillRuleProperty() const;
    Windows::UI::Xaml::DependencyProperty PointsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IRectangle
{
    double RadiusX() const;
    void RadiusX(double value) const;
    double RadiusY() const;
    void RadiusY(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IRectangleStatics
{
    Windows::UI::Xaml::DependencyProperty RadiusXProperty() const;
    Windows::UI::Xaml::DependencyProperty RadiusYProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IShape
{
    Windows::UI::Xaml::Media::Brush Fill() const;
    void Fill(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush Stroke() const;
    void Stroke(const Windows::UI::Xaml::Media::Brush & value) const;
    double StrokeMiterLimit() const;
    void StrokeMiterLimit(double value) const;
    double StrokeThickness() const;
    void StrokeThickness(double value) const;
    Windows::UI::Xaml::Media::PenLineCap StrokeStartLineCap() const;
    void StrokeStartLineCap(Windows::UI::Xaml::Media::PenLineCap value) const;
    Windows::UI::Xaml::Media::PenLineCap StrokeEndLineCap() const;
    void StrokeEndLineCap(Windows::UI::Xaml::Media::PenLineCap value) const;
    Windows::UI::Xaml::Media::PenLineJoin StrokeLineJoin() const;
    void StrokeLineJoin(Windows::UI::Xaml::Media::PenLineJoin value) const;
    double StrokeDashOffset() const;
    void StrokeDashOffset(double value) const;
    Windows::UI::Xaml::Media::PenLineCap StrokeDashCap() const;
    void StrokeDashCap(Windows::UI::Xaml::Media::PenLineCap value) const;
    Windows::UI::Xaml::Media::DoubleCollection StrokeDashArray() const;
    void StrokeDashArray(const Windows::UI::Xaml::Media::DoubleCollection & value) const;
    Windows::UI::Xaml::Media::Stretch Stretch() const;
    void Stretch(Windows::UI::Xaml::Media::Stretch value) const;
    Windows::UI::Xaml::Media::Transform GeometryTransform() const;
};

template <typename D>
struct WINRT_EBO impl_IShape2
{
    Windows::UI::Composition::CompositionBrush GetAlphaMask() const;
};

template <typename D>
struct WINRT_EBO impl_IShapeFactory
{
    Windows::UI::Xaml::Shapes::Shape CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IShapeStatics
{
    Windows::UI::Xaml::DependencyProperty FillProperty() const;
    Windows::UI::Xaml::DependencyProperty StrokeProperty() const;
    Windows::UI::Xaml::DependencyProperty StrokeMiterLimitProperty() const;
    Windows::UI::Xaml::DependencyProperty StrokeThicknessProperty() const;
    Windows::UI::Xaml::DependencyProperty StrokeStartLineCapProperty() const;
    Windows::UI::Xaml::DependencyProperty StrokeEndLineCapProperty() const;
    Windows::UI::Xaml::DependencyProperty StrokeLineJoinProperty() const;
    Windows::UI::Xaml::DependencyProperty StrokeDashOffsetProperty() const;
    Windows::UI::Xaml::DependencyProperty StrokeDashCapProperty() const;
    Windows::UI::Xaml::DependencyProperty StrokeDashArrayProperty() const;
    Windows::UI::Xaml::DependencyProperty StretchProperty() const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Shapes::IEllipse>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::IEllipse;
    template <typename D> using consume = Windows::UI::Xaml::Shapes::impl_IEllipse<D>;
};

template <> struct traits<Windows::UI::Xaml::Shapes::ILine>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::ILine;
    template <typename D> using consume = Windows::UI::Xaml::Shapes::impl_ILine<D>;
};

template <> struct traits<Windows::UI::Xaml::Shapes::ILineStatics>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::ILineStatics;
    template <typename D> using consume = Windows::UI::Xaml::Shapes::impl_ILineStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Shapes::IPath>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::IPath;
    template <typename D> using consume = Windows::UI::Xaml::Shapes::impl_IPath<D>;
};

template <> struct traits<Windows::UI::Xaml::Shapes::IPathFactory>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::IPathFactory;
    template <typename D> using consume = Windows::UI::Xaml::Shapes::impl_IPathFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Shapes::IPathStatics>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::IPathStatics;
    template <typename D> using consume = Windows::UI::Xaml::Shapes::impl_IPathStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Shapes::IPolygon>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::IPolygon;
    template <typename D> using consume = Windows::UI::Xaml::Shapes::impl_IPolygon<D>;
};

template <> struct traits<Windows::UI::Xaml::Shapes::IPolygonStatics>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::IPolygonStatics;
    template <typename D> using consume = Windows::UI::Xaml::Shapes::impl_IPolygonStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Shapes::IPolyline>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::IPolyline;
    template <typename D> using consume = Windows::UI::Xaml::Shapes::impl_IPolyline<D>;
};

template <> struct traits<Windows::UI::Xaml::Shapes::IPolylineStatics>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::IPolylineStatics;
    template <typename D> using consume = Windows::UI::Xaml::Shapes::impl_IPolylineStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Shapes::IRectangle>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::IRectangle;
    template <typename D> using consume = Windows::UI::Xaml::Shapes::impl_IRectangle<D>;
};

template <> struct traits<Windows::UI::Xaml::Shapes::IRectangleStatics>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::IRectangleStatics;
    template <typename D> using consume = Windows::UI::Xaml::Shapes::impl_IRectangleStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Shapes::IShape>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::IShape;
    template <typename D> using consume = Windows::UI::Xaml::Shapes::impl_IShape<D>;
};

template <> struct traits<Windows::UI::Xaml::Shapes::IShape2>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::IShape2;
    template <typename D> using consume = Windows::UI::Xaml::Shapes::impl_IShape2<D>;
};

template <> struct traits<Windows::UI::Xaml::Shapes::IShapeFactory>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::IShapeFactory;
    template <typename D> using consume = Windows::UI::Xaml::Shapes::impl_IShapeFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Shapes::IShapeStatics>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::IShapeStatics;
    template <typename D> using consume = Windows::UI::Xaml::Shapes::impl_IShapeStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Shapes::Ellipse>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::Ellipse;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Shapes.Ellipse"; }
};

template <> struct traits<Windows::UI::Xaml::Shapes::Line>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::Line;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Shapes.Line"; }
};

template <> struct traits<Windows::UI::Xaml::Shapes::Path>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::Path;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Shapes.Path"; }
};

template <> struct traits<Windows::UI::Xaml::Shapes::Polygon>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::Polygon;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Shapes.Polygon"; }
};

template <> struct traits<Windows::UI::Xaml::Shapes::Polyline>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::Polyline;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Shapes.Polyline"; }
};

template <> struct traits<Windows::UI::Xaml::Shapes::Rectangle>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::Rectangle;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Shapes.Rectangle"; }
};

template <> struct traits<Windows::UI::Xaml::Shapes::Shape>
{
    using abi = ABI::Windows::UI::Xaml::Shapes::Shape;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Shapes.Shape"; }
};

}

}
