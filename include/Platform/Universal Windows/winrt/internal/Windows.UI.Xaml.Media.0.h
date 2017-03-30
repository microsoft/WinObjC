// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Media {

struct Matrix;

}

namespace Windows::UI::Xaml::Media {

using Matrix = ABI::Windows::UI::Xaml::Media::Matrix;

}

namespace ABI::Windows::UI::Xaml::Media {

struct IArcSegment;
struct IArcSegmentStatics;
struct IBezierSegment;
struct IBezierSegmentStatics;
struct IBitmapCache;
struct IBrush;
struct IBrushFactory;
struct IBrushStatics;
struct ICacheMode;
struct ICacheModeFactory;
struct ICompositeTransform;
struct ICompositeTransformStatics;
struct ICompositionTarget;
struct ICompositionTargetStatics;
struct IEllipseGeometry;
struct IEllipseGeometryStatics;
struct IFontFamily;
struct IFontFamilyFactory;
struct IFontFamilyStatics2;
struct IGeneralTransform;
struct IGeneralTransformFactory;
struct IGeneralTransformOverrides;
struct IGeometry;
struct IGeometryFactory;
struct IGeometryGroup;
struct IGeometryGroupStatics;
struct IGeometryStatics;
struct IGradientBrush;
struct IGradientBrushFactory;
struct IGradientBrushStatics;
struct IGradientStop;
struct IGradientStopStatics;
struct IImageBrush;
struct IImageBrushStatics;
struct IImageSource;
struct IImageSourceFactory;
struct ILineGeometry;
struct ILineGeometryStatics;
struct ILineSegment;
struct ILineSegmentStatics;
struct ILinearGradientBrush;
struct ILinearGradientBrushFactory;
struct ILinearGradientBrushStatics;
struct IMatrix3DProjection;
struct IMatrix3DProjectionStatics;
struct IMatrixHelper;
struct IMatrixHelperStatics;
struct IMatrixTransform;
struct IMatrixTransformStatics;
struct IMediaTransportControlsThumbnailRequestedEventArgs;
struct IPartialMediaFailureDetectedEventArgs;
struct IPartialMediaFailureDetectedEventArgs2;
struct IPathFigure;
struct IPathFigureStatics;
struct IPathGeometry;
struct IPathGeometryStatics;
struct IPathSegment;
struct IPathSegmentFactory;
struct IPlaneProjection;
struct IPlaneProjectionStatics;
struct IPolyBezierSegment;
struct IPolyBezierSegmentStatics;
struct IPolyLineSegment;
struct IPolyLineSegmentStatics;
struct IPolyQuadraticBezierSegment;
struct IPolyQuadraticBezierSegmentStatics;
struct IProjection;
struct IProjectionFactory;
struct IQuadraticBezierSegment;
struct IQuadraticBezierSegmentStatics;
struct IRateChangedRoutedEventArgs;
struct IRectangleGeometry;
struct IRectangleGeometryStatics;
struct IRenderingEventArgs;
struct IRotateTransform;
struct IRotateTransformStatics;
struct IScaleTransform;
struct IScaleTransformStatics;
struct ISkewTransform;
struct ISkewTransformStatics;
struct ISolidColorBrush;
struct ISolidColorBrushFactory;
struct ISolidColorBrushStatics;
struct ITileBrush;
struct ITileBrushFactory;
struct ITileBrushStatics;
struct ITimelineMarker;
struct ITimelineMarkerRoutedEventArgs;
struct ITimelineMarkerStatics;
struct ITransform;
struct ITransformFactory;
struct ITransformGroup;
struct ITransformGroupStatics;
struct ITranslateTransform;
struct ITranslateTransformStatics;
struct IVisualTreeHelper;
struct IVisualTreeHelperStatics;
struct IVisualTreeHelperStatics2;
struct RateChangedRoutedEventHandler;
struct TimelineMarkerRoutedEventHandler;
struct ArcSegment;
struct BezierSegment;
struct BitmapCache;
struct Brush;
struct BrushCollection;
struct CacheMode;
struct CompositeTransform;
struct CompositionTarget;
struct DoubleCollection;
struct EllipseGeometry;
struct FontFamily;
struct GeneralTransform;
struct Geometry;
struct GeometryCollection;
struct GeometryGroup;
struct GradientBrush;
struct GradientStop;
struct GradientStopCollection;
struct ImageBrush;
struct ImageSource;
struct LineGeometry;
struct LineSegment;
struct LinearGradientBrush;
struct Matrix3DProjection;
struct MatrixHelper;
struct MatrixTransform;
struct MediaTransportControlsThumbnailRequestedEventArgs;
struct PartialMediaFailureDetectedEventArgs;
struct PathFigure;
struct PathFigureCollection;
struct PathGeometry;
struct PathSegment;
struct PathSegmentCollection;
struct PlaneProjection;
struct PointCollection;
struct PolyBezierSegment;
struct PolyLineSegment;
struct PolyQuadraticBezierSegment;
struct Projection;
struct QuadraticBezierSegment;
struct RateChangedRoutedEventArgs;
struct RectangleGeometry;
struct RenderingEventArgs;
struct RotateTransform;
struct ScaleTransform;
struct SkewTransform;
struct SolidColorBrush;
struct TileBrush;
struct TimelineMarker;
struct TimelineMarkerCollection;
struct TimelineMarkerRoutedEventArgs;
struct Transform;
struct TransformCollection;
struct TransformGroup;
struct TranslateTransform;
struct VisualTreeHelper;

}

namespace Windows::UI::Xaml::Media {

struct RateChangedRoutedEventHandler;
struct TimelineMarkerRoutedEventHandler;
struct IArcSegment;
struct IArcSegmentStatics;
struct IBezierSegment;
struct IBezierSegmentStatics;
struct IBitmapCache;
struct IBrush;
struct IBrushFactory;
struct IBrushStatics;
struct ICacheMode;
struct ICacheModeFactory;
struct ICompositeTransform;
struct ICompositeTransformStatics;
struct ICompositionTarget;
struct ICompositionTargetStatics;
struct IEllipseGeometry;
struct IEllipseGeometryStatics;
struct IFontFamily;
struct IFontFamilyFactory;
struct IFontFamilyStatics2;
struct IGeneralTransform;
struct IGeneralTransformFactory;
struct IGeneralTransformOverrides;
struct IGeometry;
struct IGeometryFactory;
struct IGeometryGroup;
struct IGeometryGroupStatics;
struct IGeometryStatics;
struct IGradientBrush;
struct IGradientBrushFactory;
struct IGradientBrushStatics;
struct IGradientStop;
struct IGradientStopStatics;
struct IImageBrush;
struct IImageBrushStatics;
struct IImageSource;
struct IImageSourceFactory;
struct ILineGeometry;
struct ILineGeometryStatics;
struct ILineSegment;
struct ILineSegmentStatics;
struct ILinearGradientBrush;
struct ILinearGradientBrushFactory;
struct ILinearGradientBrushStatics;
struct IMatrix3DProjection;
struct IMatrix3DProjectionStatics;
struct IMatrixHelper;
struct IMatrixHelperStatics;
struct IMatrixTransform;
struct IMatrixTransformStatics;
struct IMediaTransportControlsThumbnailRequestedEventArgs;
struct IPartialMediaFailureDetectedEventArgs;
struct IPartialMediaFailureDetectedEventArgs2;
struct IPathFigure;
struct IPathFigureStatics;
struct IPathGeometry;
struct IPathGeometryStatics;
struct IPathSegment;
struct IPathSegmentFactory;
struct IPlaneProjection;
struct IPlaneProjectionStatics;
struct IPolyBezierSegment;
struct IPolyBezierSegmentStatics;
struct IPolyLineSegment;
struct IPolyLineSegmentStatics;
struct IPolyQuadraticBezierSegment;
struct IPolyQuadraticBezierSegmentStatics;
struct IProjection;
struct IProjectionFactory;
struct IQuadraticBezierSegment;
struct IQuadraticBezierSegmentStatics;
struct IRateChangedRoutedEventArgs;
struct IRectangleGeometry;
struct IRectangleGeometryStatics;
struct IRenderingEventArgs;
struct IRotateTransform;
struct IRotateTransformStatics;
struct IScaleTransform;
struct IScaleTransformStatics;
struct ISkewTransform;
struct ISkewTransformStatics;
struct ISolidColorBrush;
struct ISolidColorBrushFactory;
struct ISolidColorBrushStatics;
struct ITileBrush;
struct ITileBrushFactory;
struct ITileBrushStatics;
struct ITimelineMarker;
struct ITimelineMarkerRoutedEventArgs;
struct ITimelineMarkerStatics;
struct ITransform;
struct ITransformFactory;
struct ITransformGroup;
struct ITransformGroupStatics;
struct ITranslateTransform;
struct ITranslateTransformStatics;
struct IVisualTreeHelper;
struct IVisualTreeHelperStatics;
struct IVisualTreeHelperStatics2;
struct ArcSegment;
struct BezierSegment;
struct BitmapCache;
struct Brush;
struct BrushCollection;
struct CacheMode;
struct CompositeTransform;
struct CompositionTarget;
struct DoubleCollection;
struct EllipseGeometry;
struct FontFamily;
struct GeneralTransform;
struct Geometry;
struct GeometryCollection;
struct GeometryGroup;
struct GradientBrush;
struct GradientStop;
struct GradientStopCollection;
struct ImageBrush;
struct ImageSource;
struct LineGeometry;
struct LineSegment;
struct LinearGradientBrush;
struct Matrix3DProjection;
struct MatrixHelper;
struct MatrixTransform;
struct MediaTransportControlsThumbnailRequestedEventArgs;
struct PartialMediaFailureDetectedEventArgs;
struct PathFigure;
struct PathFigureCollection;
struct PathGeometry;
struct PathSegment;
struct PathSegmentCollection;
struct PlaneProjection;
struct PointCollection;
struct PolyBezierSegment;
struct PolyLineSegment;
struct PolyQuadraticBezierSegment;
struct Projection;
struct QuadraticBezierSegment;
struct RateChangedRoutedEventArgs;
struct RectangleGeometry;
struct RenderingEventArgs;
struct RotateTransform;
struct ScaleTransform;
struct SkewTransform;
struct SolidColorBrush;
struct TileBrush;
struct TimelineMarker;
struct TimelineMarkerCollection;
struct TimelineMarkerRoutedEventArgs;
struct Transform;
struct TransformCollection;
struct TransformGroup;
struct TranslateTransform;
struct VisualTreeHelper;

}

namespace Windows::UI::Xaml::Media {

template <typename T> struct impl_IArcSegment;
template <typename T> struct impl_IArcSegmentStatics;
template <typename T> struct impl_IBezierSegment;
template <typename T> struct impl_IBezierSegmentStatics;
template <typename T> struct impl_IBitmapCache;
template <typename T> struct impl_IBrush;
template <typename T> struct impl_IBrushFactory;
template <typename T> struct impl_IBrushStatics;
template <typename T> struct impl_ICacheMode;
template <typename T> struct impl_ICacheModeFactory;
template <typename T> struct impl_ICompositeTransform;
template <typename T> struct impl_ICompositeTransformStatics;
template <typename T> struct impl_ICompositionTarget;
template <typename T> struct impl_ICompositionTargetStatics;
template <typename T> struct impl_IEllipseGeometry;
template <typename T> struct impl_IEllipseGeometryStatics;
template <typename T> struct impl_IFontFamily;
template <typename T> struct impl_IFontFamilyFactory;
template <typename T> struct impl_IFontFamilyStatics2;
template <typename T> struct impl_IGeneralTransform;
template <typename T> struct impl_IGeneralTransformFactory;
template <typename T> struct impl_IGeneralTransformOverrides;
template <typename T> struct impl_IGeometry;
template <typename T> struct impl_IGeometryFactory;
template <typename T> struct impl_IGeometryGroup;
template <typename T> struct impl_IGeometryGroupStatics;
template <typename T> struct impl_IGeometryStatics;
template <typename T> struct impl_IGradientBrush;
template <typename T> struct impl_IGradientBrushFactory;
template <typename T> struct impl_IGradientBrushStatics;
template <typename T> struct impl_IGradientStop;
template <typename T> struct impl_IGradientStopStatics;
template <typename T> struct impl_IImageBrush;
template <typename T> struct impl_IImageBrushStatics;
template <typename T> struct impl_IImageSource;
template <typename T> struct impl_IImageSourceFactory;
template <typename T> struct impl_ILineGeometry;
template <typename T> struct impl_ILineGeometryStatics;
template <typename T> struct impl_ILineSegment;
template <typename T> struct impl_ILineSegmentStatics;
template <typename T> struct impl_ILinearGradientBrush;
template <typename T> struct impl_ILinearGradientBrushFactory;
template <typename T> struct impl_ILinearGradientBrushStatics;
template <typename T> struct impl_IMatrix3DProjection;
template <typename T> struct impl_IMatrix3DProjectionStatics;
template <typename T> struct impl_IMatrixHelper;
template <typename T> struct impl_IMatrixHelperStatics;
template <typename T> struct impl_IMatrixTransform;
template <typename T> struct impl_IMatrixTransformStatics;
template <typename T> struct impl_IMediaTransportControlsThumbnailRequestedEventArgs;
template <typename T> struct impl_IPartialMediaFailureDetectedEventArgs;
template <typename T> struct impl_IPartialMediaFailureDetectedEventArgs2;
template <typename T> struct impl_IPathFigure;
template <typename T> struct impl_IPathFigureStatics;
template <typename T> struct impl_IPathGeometry;
template <typename T> struct impl_IPathGeometryStatics;
template <typename T> struct impl_IPathSegment;
template <typename T> struct impl_IPathSegmentFactory;
template <typename T> struct impl_IPlaneProjection;
template <typename T> struct impl_IPlaneProjectionStatics;
template <typename T> struct impl_IPolyBezierSegment;
template <typename T> struct impl_IPolyBezierSegmentStatics;
template <typename T> struct impl_IPolyLineSegment;
template <typename T> struct impl_IPolyLineSegmentStatics;
template <typename T> struct impl_IPolyQuadraticBezierSegment;
template <typename T> struct impl_IPolyQuadraticBezierSegmentStatics;
template <typename T> struct impl_IProjection;
template <typename T> struct impl_IProjectionFactory;
template <typename T> struct impl_IQuadraticBezierSegment;
template <typename T> struct impl_IQuadraticBezierSegmentStatics;
template <typename T> struct impl_IRateChangedRoutedEventArgs;
template <typename T> struct impl_IRectangleGeometry;
template <typename T> struct impl_IRectangleGeometryStatics;
template <typename T> struct impl_IRenderingEventArgs;
template <typename T> struct impl_IRotateTransform;
template <typename T> struct impl_IRotateTransformStatics;
template <typename T> struct impl_IScaleTransform;
template <typename T> struct impl_IScaleTransformStatics;
template <typename T> struct impl_ISkewTransform;
template <typename T> struct impl_ISkewTransformStatics;
template <typename T> struct impl_ISolidColorBrush;
template <typename T> struct impl_ISolidColorBrushFactory;
template <typename T> struct impl_ISolidColorBrushStatics;
template <typename T> struct impl_ITileBrush;
template <typename T> struct impl_ITileBrushFactory;
template <typename T> struct impl_ITileBrushStatics;
template <typename T> struct impl_ITimelineMarker;
template <typename T> struct impl_ITimelineMarkerRoutedEventArgs;
template <typename T> struct impl_ITimelineMarkerStatics;
template <typename T> struct impl_ITransform;
template <typename T> struct impl_ITransformFactory;
template <typename T> struct impl_ITransformGroup;
template <typename T> struct impl_ITransformGroupStatics;
template <typename T> struct impl_ITranslateTransform;
template <typename T> struct impl_ITranslateTransformStatics;
template <typename T> struct impl_IVisualTreeHelper;
template <typename T> struct impl_IVisualTreeHelperStatics;
template <typename T> struct impl_IVisualTreeHelperStatics2;
template <typename T> struct impl_RateChangedRoutedEventHandler;
template <typename T> struct impl_TimelineMarkerRoutedEventHandler;

}

namespace Windows::UI::Xaml::Media {

enum class AlignmentX
{
    Left = 0,
    Center = 1,
    Right = 2,
};

enum class AlignmentY
{
    Top = 0,
    Center = 1,
    Bottom = 2,
};

enum class AudioCategory
{
    Other = 0,
    ForegroundOnlyMedia [[deprecated("ForegroundOnlyMedia is deprecated and might not work on all platforms. For more info, see MSDN.")]] = 1,
    BackgroundCapableMedia [[deprecated("BackgroundCapableMedia is deprecated and might not work on all platforms. For more info, see MSDN.")]] = 2,
    Communications = 3,
    Alerts = 4,
    SoundEffects = 5,
    GameEffects = 6,
    GameMedia = 7,
    GameChat = 8,
    Speech = 9,
    Movie = 10,
    Media = 11,
};

enum class AudioDeviceType
{
    Console = 0,
    Multimedia = 1,
    Communications = 2,
};

enum class BrushMappingMode
{
    Absolute = 0,
    RelativeToBoundingBox = 1,
};

enum class ColorInterpolationMode
{
    ScRgbLinearInterpolation = 0,
    SRgbLinearInterpolation = 1,
};

enum class ElementCompositeMode
{
    Inherit = 0,
    SourceOver = 1,
    MinBlend = 2,
};

enum class FastPlayFallbackBehaviour
{
    Skip = 0,
    Hide = 1,
    Disable = 2,
};

enum class FillRule
{
    EvenOdd = 0,
    Nonzero = 1,
};

enum class GradientSpreadMethod
{
    Pad = 0,
    Reflect = 1,
    Repeat = 2,
};

enum class MediaCanPlayResponse
{
    NotSupported = 0,
    Maybe = 1,
    Probably = 2,
};

enum class MediaElementState
{
    Closed = 0,
    Opening = 1,
    Buffering = 2,
    Playing = 3,
    Paused = 4,
    Stopped = 5,
};

enum class PenLineCap
{
    Flat = 0,
    Square = 1,
    Round = 2,
    Triangle = 3,
};

enum class PenLineJoin
{
    Miter = 0,
    Bevel = 1,
    Round = 2,
};

enum class Stereo3DVideoPackingMode
{
    None = 0,
    SideBySide = 1,
    TopBottom = 2,
};

enum class Stereo3DVideoRenderMode
{
    Mono = 0,
    Stereo = 1,
};

enum class Stretch
{
    None = 0,
    Fill = 1,
    Uniform = 2,
    UniformToFill = 3,
};

enum class StyleSimulations
{
    None = 0,
    BoldSimulation = 1,
    ItalicSimulation = 2,
    BoldItalicSimulation = 3,
};

enum class SweepDirection
{
    Counterclockwise = 0,
    Clockwise = 1,
};

}

}
