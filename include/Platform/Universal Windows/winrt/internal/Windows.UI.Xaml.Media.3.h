// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Media.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Media {

template <typename H> struct impl_RateChangedRoutedEventHandler : implements<impl_RateChangedRoutedEventHandler<H>, abi<RateChangedRoutedEventHandler>>, H
{
    impl_RateChangedRoutedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Media::IRateChangedRoutedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Media::RateChangedRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_TimelineMarkerRoutedEventHandler : implements<impl_TimelineMarkerRoutedEventHandler<H>, abi<TimelineMarkerRoutedEventHandler>>, H
{
    impl_TimelineMarkerRoutedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Media::ITimelineMarkerRoutedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Media::TimelineMarkerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Media {

struct WINRT_EBO ArcSegment :
    Windows::UI::Xaml::Media::IArcSegment,
    impl::bases<ArcSegment, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::PathSegment>,
    impl::require<ArcSegment, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IPathSegment>
{
    ArcSegment(std::nullptr_t) noexcept {}
    ArcSegment();
    static Windows::UI::Xaml::DependencyProperty PointProperty();
    static Windows::UI::Xaml::DependencyProperty SizeProperty();
    static Windows::UI::Xaml::DependencyProperty RotationAngleProperty();
    static Windows::UI::Xaml::DependencyProperty IsLargeArcProperty();
    static Windows::UI::Xaml::DependencyProperty SweepDirectionProperty();
};

struct WINRT_EBO BezierSegment :
    Windows::UI::Xaml::Media::IBezierSegment,
    impl::bases<BezierSegment, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::PathSegment>,
    impl::require<BezierSegment, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IPathSegment>
{
    BezierSegment(std::nullptr_t) noexcept {}
    BezierSegment();
    static Windows::UI::Xaml::DependencyProperty Point1Property();
    static Windows::UI::Xaml::DependencyProperty Point2Property();
    static Windows::UI::Xaml::DependencyProperty Point3Property();
};

struct WINRT_EBO BitmapCache :
    Windows::UI::Xaml::Media::IBitmapCache,
    impl::bases<BitmapCache, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::CacheMode>,
    impl::require<BitmapCache, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::ICacheMode>
{
    BitmapCache(std::nullptr_t) noexcept {}
    BitmapCache();
};

struct WINRT_EBO Brush :
    Windows::UI::Xaml::Media::IBrush,
    impl::bases<Brush, Windows::UI::Xaml::DependencyObject>,
    impl::require<Brush, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    Brush(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty OpacityProperty();
    static Windows::UI::Xaml::DependencyProperty TransformProperty();
    static Windows::UI::Xaml::DependencyProperty RelativeTransformProperty();
};

struct WINRT_EBO BrushCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Brush>
{
    BrushCollection(std::nullptr_t) noexcept {}
    BrushCollection();
};

struct WINRT_EBO CacheMode :
    Windows::UI::Xaml::Media::ICacheMode,
    impl::bases<CacheMode, Windows::UI::Xaml::DependencyObject>,
    impl::require<CacheMode, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    CacheMode(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositeTransform :
    Windows::UI::Xaml::Media::ICompositeTransform,
    impl::bases<CompositeTransform, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::GeneralTransform, Windows::UI::Xaml::Media::Transform>,
    impl::require<CompositeTransform, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeneralTransform, Windows::UI::Xaml::Media::IGeneralTransformOverrides, Windows::UI::Xaml::Media::ITransform>
{
    CompositeTransform(std::nullptr_t) noexcept {}
    CompositeTransform();
    static Windows::UI::Xaml::DependencyProperty CenterXProperty();
    static Windows::UI::Xaml::DependencyProperty CenterYProperty();
    static Windows::UI::Xaml::DependencyProperty ScaleXProperty();
    static Windows::UI::Xaml::DependencyProperty ScaleYProperty();
    static Windows::UI::Xaml::DependencyProperty SkewXProperty();
    static Windows::UI::Xaml::DependencyProperty SkewYProperty();
    static Windows::UI::Xaml::DependencyProperty RotationProperty();
    static Windows::UI::Xaml::DependencyProperty TranslateXProperty();
    static Windows::UI::Xaml::DependencyProperty TranslateYProperty();
};

struct WINRT_EBO CompositionTarget :
    Windows::UI::Xaml::Media::ICompositionTarget
{
    CompositionTarget(std::nullptr_t) noexcept {}
    static event_token Rendering(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value);
    using Rendering_revoker = factory_event_revoker<ICompositionTargetStatics>;
    static Rendering_revoker Rendering(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value);
    static void Rendering(event_token token);
    static event_token SurfaceContentsLost(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value);
    using SurfaceContentsLost_revoker = factory_event_revoker<ICompositionTargetStatics>;
    static SurfaceContentsLost_revoker SurfaceContentsLost(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value);
    static void SurfaceContentsLost(event_token token);
};

struct WINRT_EBO DoubleCollection :
    Windows::Foundation::Collections::IVector<double>
{
    DoubleCollection(std::nullptr_t) noexcept {}
    DoubleCollection();
};

struct WINRT_EBO EllipseGeometry :
    Windows::UI::Xaml::Media::IEllipseGeometry,
    impl::bases<EllipseGeometry, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Geometry>,
    impl::require<EllipseGeometry, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeometry>
{
    EllipseGeometry(std::nullptr_t) noexcept {}
    EllipseGeometry();
    static Windows::UI::Xaml::DependencyProperty CenterProperty();
    static Windows::UI::Xaml::DependencyProperty RadiusXProperty();
    static Windows::UI::Xaml::DependencyProperty RadiusYProperty();
};

struct WINRT_EBO FontFamily :
    Windows::UI::Xaml::Media::IFontFamily
{
    FontFamily(std::nullptr_t) noexcept {}
    FontFamily(hstring_view familyName);
    static Windows::UI::Xaml::Media::FontFamily XamlAutoFontFamily();
};

struct WINRT_EBO GeneralTransform :
    Windows::UI::Xaml::Media::IGeneralTransform,
    impl::bases<GeneralTransform, Windows::UI::Xaml::DependencyObject>,
    impl::require<GeneralTransform, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeneralTransformOverrides>
{
    GeneralTransform(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Geometry :
    Windows::UI::Xaml::Media::IGeometry,
    impl::bases<Geometry, Windows::UI::Xaml::DependencyObject>,
    impl::require<Geometry, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    Geometry(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Media::Geometry Empty();
    static double StandardFlatteningTolerance();
    static Windows::UI::Xaml::DependencyProperty TransformProperty();
};

struct WINRT_EBO GeometryCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Geometry>
{
    GeometryCollection(std::nullptr_t) noexcept {}
    GeometryCollection();
};

struct WINRT_EBO GeometryGroup :
    Windows::UI::Xaml::Media::IGeometryGroup,
    impl::bases<GeometryGroup, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Geometry>,
    impl::require<GeometryGroup, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeometry>
{
    GeometryGroup(std::nullptr_t) noexcept {}
    GeometryGroup();
    static Windows::UI::Xaml::DependencyProperty FillRuleProperty();
    static Windows::UI::Xaml::DependencyProperty ChildrenProperty();
};

struct WINRT_EBO GradientBrush :
    Windows::UI::Xaml::Media::IGradientBrush,
    impl::bases<GradientBrush, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Brush>,
    impl::require<GradientBrush, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IBrush>
{
    GradientBrush(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty SpreadMethodProperty();
    static Windows::UI::Xaml::DependencyProperty MappingModeProperty();
    static Windows::UI::Xaml::DependencyProperty ColorInterpolationModeProperty();
    static Windows::UI::Xaml::DependencyProperty GradientStopsProperty();
};

struct WINRT_EBO GradientStop :
    Windows::UI::Xaml::Media::IGradientStop,
    impl::bases<GradientStop, Windows::UI::Xaml::DependencyObject>,
    impl::require<GradientStop, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    GradientStop(std::nullptr_t) noexcept {}
    GradientStop();
    static Windows::UI::Xaml::DependencyProperty ColorProperty();
    static Windows::UI::Xaml::DependencyProperty OffsetProperty();
};

struct WINRT_EBO GradientStopCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::GradientStop>
{
    GradientStopCollection(std::nullptr_t) noexcept {}
    GradientStopCollection();
};

struct WINRT_EBO ImageBrush :
    Windows::UI::Xaml::Media::IImageBrush,
    impl::bases<ImageBrush, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Brush, Windows::UI::Xaml::Media::TileBrush>,
    impl::require<ImageBrush, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IBrush, Windows::UI::Xaml::Media::ITileBrush>
{
    ImageBrush(std::nullptr_t) noexcept {}
    ImageBrush();
    static Windows::UI::Xaml::DependencyProperty ImageSourceProperty();
};

struct WINRT_EBO ImageSource :
    Windows::UI::Xaml::Media::IImageSource,
    impl::bases<ImageSource, Windows::UI::Xaml::DependencyObject>,
    impl::require<ImageSource, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    ImageSource(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LineGeometry :
    Windows::UI::Xaml::Media::ILineGeometry,
    impl::bases<LineGeometry, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Geometry>,
    impl::require<LineGeometry, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeometry>
{
    LineGeometry(std::nullptr_t) noexcept {}
    LineGeometry();
    static Windows::UI::Xaml::DependencyProperty StartPointProperty();
    static Windows::UI::Xaml::DependencyProperty EndPointProperty();
};

struct WINRT_EBO LineSegment :
    Windows::UI::Xaml::Media::ILineSegment,
    impl::bases<LineSegment, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::PathSegment>,
    impl::require<LineSegment, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IPathSegment>
{
    LineSegment(std::nullptr_t) noexcept {}
    LineSegment();
    static Windows::UI::Xaml::DependencyProperty PointProperty();
};

struct WINRT_EBO LinearGradientBrush :
    Windows::UI::Xaml::Media::ILinearGradientBrush,
    impl::bases<LinearGradientBrush, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Brush, Windows::UI::Xaml::Media::GradientBrush>,
    impl::require<LinearGradientBrush, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IBrush, Windows::UI::Xaml::Media::IGradientBrush>
{
    LinearGradientBrush(std::nullptr_t) noexcept {}
    LinearGradientBrush();
    LinearGradientBrush(const Windows::UI::Xaml::Media::GradientStopCollection & gradientStopCollection, double angle);
    static Windows::UI::Xaml::DependencyProperty StartPointProperty();
    static Windows::UI::Xaml::DependencyProperty EndPointProperty();
};

struct WINRT_EBO Matrix3DProjection :
    Windows::UI::Xaml::Media::IMatrix3DProjection,
    impl::bases<Matrix3DProjection, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Projection>,
    impl::require<Matrix3DProjection, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IProjection>
{
    Matrix3DProjection(std::nullptr_t) noexcept {}
    Matrix3DProjection();
    static Windows::UI::Xaml::DependencyProperty ProjectionMatrixProperty();
};

struct WINRT_EBO MatrixHelper :
    Windows::UI::Xaml::Media::IMatrixHelper
{
    MatrixHelper(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Media::Matrix Identity();
    static Windows::UI::Xaml::Media::Matrix FromElements(double m11, double m12, double m21, double m22, double offsetX, double offsetY);
    static bool GetIsIdentity(const Windows::UI::Xaml::Media::Matrix & target);
    static Windows::Foundation::Point Transform(const Windows::UI::Xaml::Media::Matrix & target, const Windows::Foundation::Point & point);
};

struct WINRT_EBO MatrixTransform :
    Windows::UI::Xaml::Media::IMatrixTransform,
    impl::bases<MatrixTransform, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::GeneralTransform, Windows::UI::Xaml::Media::Transform>,
    impl::require<MatrixTransform, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeneralTransform, Windows::UI::Xaml::Media::IGeneralTransformOverrides, Windows::UI::Xaml::Media::ITransform>
{
    MatrixTransform(std::nullptr_t) noexcept {}
    MatrixTransform();
    static Windows::UI::Xaml::DependencyProperty MatrixProperty();
};

struct WINRT_EBO MediaTransportControlsThumbnailRequestedEventArgs :
    Windows::UI::Xaml::Media::IMediaTransportControlsThumbnailRequestedEventArgs
{
    MediaTransportControlsThumbnailRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PartialMediaFailureDetectedEventArgs :
    Windows::UI::Xaml::Media::IPartialMediaFailureDetectedEventArgs,
    impl::require<PartialMediaFailureDetectedEventArgs, Windows::UI::Xaml::Media::IPartialMediaFailureDetectedEventArgs2>
{
    PartialMediaFailureDetectedEventArgs(std::nullptr_t) noexcept {}
    PartialMediaFailureDetectedEventArgs();
};

struct WINRT_EBO PathFigure :
    Windows::UI::Xaml::Media::IPathFigure,
    impl::bases<PathFigure, Windows::UI::Xaml::DependencyObject>,
    impl::require<PathFigure, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    PathFigure(std::nullptr_t) noexcept {}
    PathFigure();
    static Windows::UI::Xaml::DependencyProperty SegmentsProperty();
    static Windows::UI::Xaml::DependencyProperty StartPointProperty();
    static Windows::UI::Xaml::DependencyProperty IsClosedProperty();
    static Windows::UI::Xaml::DependencyProperty IsFilledProperty();
};

struct WINRT_EBO PathFigureCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::PathFigure>
{
    PathFigureCollection(std::nullptr_t) noexcept {}
    PathFigureCollection();
};

struct WINRT_EBO PathGeometry :
    Windows::UI::Xaml::Media::IPathGeometry,
    impl::bases<PathGeometry, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Geometry>,
    impl::require<PathGeometry, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeometry>
{
    PathGeometry(std::nullptr_t) noexcept {}
    PathGeometry();
    static Windows::UI::Xaml::DependencyProperty FillRuleProperty();
    static Windows::UI::Xaml::DependencyProperty FiguresProperty();
};

struct WINRT_EBO PathSegment :
    Windows::UI::Xaml::Media::IPathSegment,
    impl::bases<PathSegment, Windows::UI::Xaml::DependencyObject>,
    impl::require<PathSegment, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    PathSegment(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PathSegmentCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::PathSegment>
{
    PathSegmentCollection(std::nullptr_t) noexcept {}
    PathSegmentCollection();
};

struct WINRT_EBO PlaneProjection :
    Windows::UI::Xaml::Media::IPlaneProjection,
    impl::bases<PlaneProjection, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Projection>,
    impl::require<PlaneProjection, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IProjection>
{
    PlaneProjection(std::nullptr_t) noexcept {}
    PlaneProjection();
    static Windows::UI::Xaml::DependencyProperty LocalOffsetXProperty();
    static Windows::UI::Xaml::DependencyProperty LocalOffsetYProperty();
    static Windows::UI::Xaml::DependencyProperty LocalOffsetZProperty();
    static Windows::UI::Xaml::DependencyProperty RotationXProperty();
    static Windows::UI::Xaml::DependencyProperty RotationYProperty();
    static Windows::UI::Xaml::DependencyProperty RotationZProperty();
    static Windows::UI::Xaml::DependencyProperty CenterOfRotationXProperty();
    static Windows::UI::Xaml::DependencyProperty CenterOfRotationYProperty();
    static Windows::UI::Xaml::DependencyProperty CenterOfRotationZProperty();
    static Windows::UI::Xaml::DependencyProperty GlobalOffsetXProperty();
    static Windows::UI::Xaml::DependencyProperty GlobalOffsetYProperty();
    static Windows::UI::Xaml::DependencyProperty GlobalOffsetZProperty();
    static Windows::UI::Xaml::DependencyProperty ProjectionMatrixProperty();
};

struct WINRT_EBO PointCollection :
    Windows::Foundation::Collections::IVector<Windows::Foundation::Point>
{
    PointCollection(std::nullptr_t) noexcept {}
    PointCollection();
};

struct WINRT_EBO PolyBezierSegment :
    Windows::UI::Xaml::Media::IPolyBezierSegment,
    impl::bases<PolyBezierSegment, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::PathSegment>,
    impl::require<PolyBezierSegment, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IPathSegment>
{
    PolyBezierSegment(std::nullptr_t) noexcept {}
    PolyBezierSegment();
    static Windows::UI::Xaml::DependencyProperty PointsProperty();
};

struct WINRT_EBO PolyLineSegment :
    Windows::UI::Xaml::Media::IPolyLineSegment,
    impl::bases<PolyLineSegment, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::PathSegment>,
    impl::require<PolyLineSegment, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IPathSegment>
{
    PolyLineSegment(std::nullptr_t) noexcept {}
    PolyLineSegment();
    static Windows::UI::Xaml::DependencyProperty PointsProperty();
};

struct WINRT_EBO PolyQuadraticBezierSegment :
    Windows::UI::Xaml::Media::IPolyQuadraticBezierSegment,
    impl::bases<PolyQuadraticBezierSegment, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::PathSegment>,
    impl::require<PolyQuadraticBezierSegment, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IPathSegment>
{
    PolyQuadraticBezierSegment(std::nullptr_t) noexcept {}
    PolyQuadraticBezierSegment();
    static Windows::UI::Xaml::DependencyProperty PointsProperty();
};

struct WINRT_EBO Projection :
    Windows::UI::Xaml::Media::IProjection,
    impl::bases<Projection, Windows::UI::Xaml::DependencyObject>,
    impl::require<Projection, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    Projection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO QuadraticBezierSegment :
    Windows::UI::Xaml::Media::IQuadraticBezierSegment,
    impl::bases<QuadraticBezierSegment, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::PathSegment>,
    impl::require<QuadraticBezierSegment, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IPathSegment>
{
    QuadraticBezierSegment(std::nullptr_t) noexcept {}
    QuadraticBezierSegment();
    static Windows::UI::Xaml::DependencyProperty Point1Property();
    static Windows::UI::Xaml::DependencyProperty Point2Property();
};

struct WINRT_EBO RateChangedRoutedEventArgs :
    Windows::UI::Xaml::Media::IRateChangedRoutedEventArgs,
    impl::bases<RateChangedRoutedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<RateChangedRoutedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    RateChangedRoutedEventArgs(std::nullptr_t) noexcept {}
    RateChangedRoutedEventArgs();
};

struct WINRT_EBO RectangleGeometry :
    Windows::UI::Xaml::Media::IRectangleGeometry,
    impl::bases<RectangleGeometry, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Geometry>,
    impl::require<RectangleGeometry, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeometry>
{
    RectangleGeometry(std::nullptr_t) noexcept {}
    RectangleGeometry();
    static Windows::UI::Xaml::DependencyProperty RectProperty();
};

struct WINRT_EBO RenderingEventArgs :
    Windows::UI::Xaml::Media::IRenderingEventArgs
{
    RenderingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RotateTransform :
    Windows::UI::Xaml::Media::IRotateTransform,
    impl::bases<RotateTransform, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::GeneralTransform, Windows::UI::Xaml::Media::Transform>,
    impl::require<RotateTransform, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeneralTransform, Windows::UI::Xaml::Media::IGeneralTransformOverrides, Windows::UI::Xaml::Media::ITransform>
{
    RotateTransform(std::nullptr_t) noexcept {}
    RotateTransform();
    static Windows::UI::Xaml::DependencyProperty CenterXProperty();
    static Windows::UI::Xaml::DependencyProperty CenterYProperty();
    static Windows::UI::Xaml::DependencyProperty AngleProperty();
};

struct WINRT_EBO ScaleTransform :
    Windows::UI::Xaml::Media::IScaleTransform,
    impl::bases<ScaleTransform, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::GeneralTransform, Windows::UI::Xaml::Media::Transform>,
    impl::require<ScaleTransform, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeneralTransform, Windows::UI::Xaml::Media::IGeneralTransformOverrides, Windows::UI::Xaml::Media::ITransform>
{
    ScaleTransform(std::nullptr_t) noexcept {}
    ScaleTransform();
    static Windows::UI::Xaml::DependencyProperty CenterXProperty();
    static Windows::UI::Xaml::DependencyProperty CenterYProperty();
    static Windows::UI::Xaml::DependencyProperty ScaleXProperty();
    static Windows::UI::Xaml::DependencyProperty ScaleYProperty();
};

struct WINRT_EBO SkewTransform :
    Windows::UI::Xaml::Media::ISkewTransform,
    impl::bases<SkewTransform, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::GeneralTransform, Windows::UI::Xaml::Media::Transform>,
    impl::require<SkewTransform, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeneralTransform, Windows::UI::Xaml::Media::IGeneralTransformOverrides, Windows::UI::Xaml::Media::ITransform>
{
    SkewTransform(std::nullptr_t) noexcept {}
    SkewTransform();
    static Windows::UI::Xaml::DependencyProperty CenterXProperty();
    static Windows::UI::Xaml::DependencyProperty CenterYProperty();
    static Windows::UI::Xaml::DependencyProperty AngleXProperty();
    static Windows::UI::Xaml::DependencyProperty AngleYProperty();
};

struct WINRT_EBO SolidColorBrush :
    Windows::UI::Xaml::Media::ISolidColorBrush,
    impl::bases<SolidColorBrush, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Brush>,
    impl::require<SolidColorBrush, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IBrush>
{
    SolidColorBrush(std::nullptr_t) noexcept {}
    SolidColorBrush();
    SolidColorBrush(const Windows::UI::Color & color);
    static Windows::UI::Xaml::DependencyProperty ColorProperty();
};

struct WINRT_EBO TileBrush :
    Windows::UI::Xaml::Media::ITileBrush,
    impl::bases<TileBrush, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Brush>,
    impl::require<TileBrush, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IBrush>
{
    TileBrush(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty AlignmentXProperty();
    static Windows::UI::Xaml::DependencyProperty AlignmentYProperty();
    static Windows::UI::Xaml::DependencyProperty StretchProperty();
};

struct WINRT_EBO TimelineMarker :
    Windows::UI::Xaml::Media::ITimelineMarker,
    impl::bases<TimelineMarker, Windows::UI::Xaml::DependencyObject>,
    impl::require<TimelineMarker, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    TimelineMarker(std::nullptr_t) noexcept {}
    TimelineMarker();
    static Windows::UI::Xaml::DependencyProperty TimeProperty();
    static Windows::UI::Xaml::DependencyProperty TypeProperty();
    static Windows::UI::Xaml::DependencyProperty TextProperty();
};

struct WINRT_EBO TimelineMarkerCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::TimelineMarker>
{
    TimelineMarkerCollection(std::nullptr_t) noexcept {}
    TimelineMarkerCollection();
};

struct WINRT_EBO TimelineMarkerRoutedEventArgs :
    Windows::UI::Xaml::Media::ITimelineMarkerRoutedEventArgs,
    impl::bases<TimelineMarkerRoutedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<TimelineMarkerRoutedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    TimelineMarkerRoutedEventArgs(std::nullptr_t) noexcept {}
    TimelineMarkerRoutedEventArgs();
};

struct WINRT_EBO Transform :
    Windows::UI::Xaml::Media::ITransform,
    impl::bases<Transform, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::GeneralTransform>,
    impl::require<Transform, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeneralTransform, Windows::UI::Xaml::Media::IGeneralTransformOverrides>
{
    Transform(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TransformCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Transform>
{
    TransformCollection(std::nullptr_t) noexcept {}
    TransformCollection();
};

struct WINRT_EBO TransformGroup :
    Windows::UI::Xaml::Media::ITransformGroup,
    impl::bases<TransformGroup, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::GeneralTransform, Windows::UI::Xaml::Media::Transform>,
    impl::require<TransformGroup, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeneralTransform, Windows::UI::Xaml::Media::IGeneralTransformOverrides, Windows::UI::Xaml::Media::ITransform>
{
    TransformGroup(std::nullptr_t) noexcept {}
    TransformGroup();
    static Windows::UI::Xaml::DependencyProperty ChildrenProperty();
};

struct WINRT_EBO TranslateTransform :
    Windows::UI::Xaml::Media::ITranslateTransform,
    impl::bases<TranslateTransform, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::GeneralTransform, Windows::UI::Xaml::Media::Transform>,
    impl::require<TranslateTransform, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IGeneralTransform, Windows::UI::Xaml::Media::IGeneralTransformOverrides, Windows::UI::Xaml::Media::ITransform>
{
    TranslateTransform(std::nullptr_t) noexcept {}
    TranslateTransform();
    static Windows::UI::Xaml::DependencyProperty XProperty();
    static Windows::UI::Xaml::DependencyProperty YProperty();
};

struct WINRT_EBO VisualTreeHelper :
    Windows::UI::Xaml::Media::IVisualTreeHelper
{
    VisualTreeHelper(std::nullptr_t) noexcept {}
    static Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> FindElementsInHostCoordinates(const Windows::Foundation::Point & intersectingPoint, const Windows::UI::Xaml::UIElement & subtree);
    static Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> FindElementsInHostCoordinates(const Windows::Foundation::Rect & intersectingRect, const Windows::UI::Xaml::UIElement & subtree);
    static Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> FindElementsInHostCoordinates(const Windows::Foundation::Point & intersectingPoint, const Windows::UI::Xaml::UIElement & subtree, bool includeAllElements);
    static Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> FindElementsInHostCoordinates(const Windows::Foundation::Rect & intersectingRect, const Windows::UI::Xaml::UIElement & subtree, bool includeAllElements);
    static Windows::UI::Xaml::DependencyObject GetChild(const Windows::UI::Xaml::DependencyObject & reference, int32_t childIndex);
    static int32_t GetChildrenCount(const Windows::UI::Xaml::DependencyObject & reference);
    static Windows::UI::Xaml::DependencyObject GetParent(const Windows::UI::Xaml::DependencyObject & reference);
    static void DisconnectChildrenRecursive(const Windows::UI::Xaml::UIElement & element);
    static Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Controls::Primitives::Popup> GetOpenPopups(const Windows::UI::Xaml::Window & window);
};

}

}
