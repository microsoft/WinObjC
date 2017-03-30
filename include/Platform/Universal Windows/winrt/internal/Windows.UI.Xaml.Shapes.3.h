// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Shapes.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Shapes {

struct WINRT_EBO Ellipse :
    Windows::UI::Xaml::Shapes::IEllipse,
    impl::bases<Ellipse, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Shapes::Shape>,
    impl::require<Ellipse, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Shapes::IShape, Windows::UI::Xaml::Shapes::IShape2>
{
    Ellipse(std::nullptr_t) noexcept {}
    Ellipse();
};

struct WINRT_EBO Line :
    Windows::UI::Xaml::Shapes::ILine,
    impl::bases<Line, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Shapes::Shape>,
    impl::require<Line, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Shapes::IShape, Windows::UI::Xaml::Shapes::IShape2>
{
    Line(std::nullptr_t) noexcept {}
    Line();
    static Windows::UI::Xaml::DependencyProperty X1Property();
    static Windows::UI::Xaml::DependencyProperty Y1Property();
    static Windows::UI::Xaml::DependencyProperty X2Property();
    static Windows::UI::Xaml::DependencyProperty Y2Property();
};

struct WINRT_EBO Path :
    Windows::UI::Xaml::Shapes::IPath,
    impl::bases<Path, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Shapes::Shape>,
    impl::require<Path, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Shapes::IShape, Windows::UI::Xaml::Shapes::IShape2>
{
    Path(std::nullptr_t) noexcept {}
    Path();
    static Windows::UI::Xaml::DependencyProperty DataProperty();
};

struct WINRT_EBO Polygon :
    Windows::UI::Xaml::Shapes::IPolygon,
    impl::bases<Polygon, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Shapes::Shape>,
    impl::require<Polygon, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Shapes::IShape, Windows::UI::Xaml::Shapes::IShape2>
{
    Polygon(std::nullptr_t) noexcept {}
    Polygon();
    static Windows::UI::Xaml::DependencyProperty FillRuleProperty();
    static Windows::UI::Xaml::DependencyProperty PointsProperty();
};

struct WINRT_EBO Polyline :
    Windows::UI::Xaml::Shapes::IPolyline,
    impl::bases<Polyline, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Shapes::Shape>,
    impl::require<Polyline, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Shapes::IShape, Windows::UI::Xaml::Shapes::IShape2>
{
    Polyline(std::nullptr_t) noexcept {}
    Polyline();
    static Windows::UI::Xaml::DependencyProperty FillRuleProperty();
    static Windows::UI::Xaml::DependencyProperty PointsProperty();
};

struct WINRT_EBO Rectangle :
    Windows::UI::Xaml::Shapes::IRectangle,
    impl::bases<Rectangle, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Shapes::Shape>,
    impl::require<Rectangle, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Shapes::IShape, Windows::UI::Xaml::Shapes::IShape2>
{
    Rectangle(std::nullptr_t) noexcept {}
    Rectangle();
    static Windows::UI::Xaml::DependencyProperty RadiusXProperty();
    static Windows::UI::Xaml::DependencyProperty RadiusYProperty();
};

struct WINRT_EBO Shape :
    Windows::UI::Xaml::Shapes::IShape,
    impl::bases<Shape, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<Shape, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Shapes::IShape2>
{
    Shape(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty FillProperty();
    static Windows::UI::Xaml::DependencyProperty StrokeProperty();
    static Windows::UI::Xaml::DependencyProperty StrokeMiterLimitProperty();
    static Windows::UI::Xaml::DependencyProperty StrokeThicknessProperty();
    static Windows::UI::Xaml::DependencyProperty StrokeStartLineCapProperty();
    static Windows::UI::Xaml::DependencyProperty StrokeEndLineCapProperty();
    static Windows::UI::Xaml::DependencyProperty StrokeLineJoinProperty();
    static Windows::UI::Xaml::DependencyProperty StrokeDashOffsetProperty();
    static Windows::UI::Xaml::DependencyProperty StrokeDashCapProperty();
    static Windows::UI::Xaml::DependencyProperty StrokeDashArrayProperty();
    static Windows::UI::Xaml::DependencyProperty StretchProperty();
};

}

}
