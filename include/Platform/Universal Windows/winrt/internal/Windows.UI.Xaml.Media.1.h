// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.Media.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Media.Playback.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.UI.0.h"
#include "Windows.UI.Xaml.0.h"
#include "Windows.UI.Xaml.Media.Media3D.0.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.UI.Xaml.Controls.Primitives.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Media {

struct Matrix
{
    double M11;
    double M12;
    double M21;
    double M22;
    double OffsetX;
    double OffsetY;
};

}

namespace Windows::UI::Xaml::Media {

using Matrix = ABI::Windows::UI::Xaml::Media::Matrix;

}

namespace ABI::Windows::UI::Xaml::Media {

struct __declspec(uuid("07940c5f-63fb-4469-91be-f1097c168052")) __declspec(novtable) IArcSegment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Point(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_Point(Windows::Foundation::Point value) = 0;
    virtual HRESULT __stdcall get_Size(Windows::Foundation::Size * value) = 0;
    virtual HRESULT __stdcall put_Size(Windows::Foundation::Size value) = 0;
    virtual HRESULT __stdcall get_RotationAngle(double * value) = 0;
    virtual HRESULT __stdcall put_RotationAngle(double value) = 0;
    virtual HRESULT __stdcall get_IsLargeArc(bool * value) = 0;
    virtual HRESULT __stdcall put_IsLargeArc(bool value) = 0;
    virtual HRESULT __stdcall get_SweepDirection(winrt::Windows::UI::Xaml::Media::SweepDirection * value) = 0;
    virtual HRESULT __stdcall put_SweepDirection(winrt::Windows::UI::Xaml::Media::SweepDirection value) = 0;
};

struct __declspec(uuid("82348f6e-8a69-4204-9c12-7207df317643")) __declspec(novtable) IArcSegmentStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PointProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SizeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RotationAngleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsLargeArcProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SweepDirectionProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("af4bb9ee-8984-49b7-81df-3f35994b95eb")) __declspec(novtable) IBezierSegment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Point1(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_Point1(Windows::Foundation::Point value) = 0;
    virtual HRESULT __stdcall get_Point2(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_Point2(Windows::Foundation::Point value) = 0;
    virtual HRESULT __stdcall get_Point3(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_Point3(Windows::Foundation::Point value) = 0;
};

struct __declspec(uuid("c0287bac-1410-4530-8452-1c9d0ad1f341")) __declspec(novtable) IBezierSegmentStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Point1Property(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_Point2Property(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_Point3Property(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("79c2219e-44d2-4610-9735-9bec83809ecf")) __declspec(novtable) IBitmapCache : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("8806a321-1e06-422c-a1cc-01696559e021")) __declspec(novtable) IBrush : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Opacity(double * value) = 0;
    virtual HRESULT __stdcall put_Opacity(double value) = 0;
    virtual HRESULT __stdcall get_Transform(Windows::UI::Xaml::Media::ITransform ** value) = 0;
    virtual HRESULT __stdcall put_Transform(Windows::UI::Xaml::Media::ITransform * value) = 0;
    virtual HRESULT __stdcall get_RelativeTransform(Windows::UI::Xaml::Media::ITransform ** value) = 0;
    virtual HRESULT __stdcall put_RelativeTransform(Windows::UI::Xaml::Media::ITransform * value) = 0;
};

struct __declspec(uuid("399658a2-14fb-4b8f-83e6-6e3dab12069b")) __declspec(novtable) IBrushFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Media::IBrush ** instance) = 0;
};

struct __declspec(uuid("e70c3102-0225-47f5-b22e-0467619f6a22")) __declspec(novtable) IBrushStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OpacityProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TransformProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RelativeTransformProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("98dc8b11-c6f9-4dab-b838-5fd5ec8c7350")) __declspec(novtable) ICacheMode : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("eb1f8c5b-0abb-4e70-b8a8-620d0d953ab2")) __declspec(novtable) ICacheModeFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Media::ICacheMode ** instance) = 0;
};

struct __declspec(uuid("c8a4385b-f24a-4701-a265-a78846f142b9")) __declspec(novtable) ICompositeTransform : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CenterX(double * value) = 0;
    virtual HRESULT __stdcall put_CenterX(double value) = 0;
    virtual HRESULT __stdcall get_CenterY(double * value) = 0;
    virtual HRESULT __stdcall put_CenterY(double value) = 0;
    virtual HRESULT __stdcall get_ScaleX(double * value) = 0;
    virtual HRESULT __stdcall put_ScaleX(double value) = 0;
    virtual HRESULT __stdcall get_ScaleY(double * value) = 0;
    virtual HRESULT __stdcall put_ScaleY(double value) = 0;
    virtual HRESULT __stdcall get_SkewX(double * value) = 0;
    virtual HRESULT __stdcall put_SkewX(double value) = 0;
    virtual HRESULT __stdcall get_SkewY(double * value) = 0;
    virtual HRESULT __stdcall put_SkewY(double value) = 0;
    virtual HRESULT __stdcall get_Rotation(double * value) = 0;
    virtual HRESULT __stdcall put_Rotation(double value) = 0;
    virtual HRESULT __stdcall get_TranslateX(double * value) = 0;
    virtual HRESULT __stdcall put_TranslateX(double value) = 0;
    virtual HRESULT __stdcall get_TranslateY(double * value) = 0;
    virtual HRESULT __stdcall put_TranslateY(double value) = 0;
};

struct __declspec(uuid("2f190c08-8266-496f-9653-a18bd4f836aa")) __declspec(novtable) ICompositeTransformStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CenterXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CenterYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ScaleXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ScaleYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SkewXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SkewYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RotationProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TranslateXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TranslateYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("26cfbff0-713c-4bec-8803-e101f7b14ed3")) __declspec(novtable) ICompositionTarget : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("2b1af03d-1ed2-4b59-bd00-7594ee92832b")) __declspec(novtable) ICompositionTargetStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_Rendering(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Rendering(event_token token) = 0;
    virtual HRESULT __stdcall add_SurfaceContentsLost(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SurfaceContentsLost(event_token token) = 0;
};

struct __declspec(uuid("d4f61bba-4ea2-40d6-aa6c-8d38aa87651f")) __declspec(novtable) IEllipseGeometry : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Center(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_Center(Windows::Foundation::Point value) = 0;
    virtual HRESULT __stdcall get_RadiusX(double * value) = 0;
    virtual HRESULT __stdcall put_RadiusX(double value) = 0;
    virtual HRESULT __stdcall get_RadiusY(double * value) = 0;
    virtual HRESULT __stdcall put_RadiusY(double value) = 0;
};

struct __declspec(uuid("1744db47-f635-4b16-aee6-e052a65defb2")) __declspec(novtable) IEllipseGeometryStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CenterProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RadiusXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RadiusYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("92467e64-d66a-4cf4-9322-3d23b3c0c361")) __declspec(novtable) IFontFamily : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Source(hstring * value) = 0;
};

struct __declspec(uuid("d5603377-3dae-4dcd-af09-f9498e9ec659")) __declspec(novtable) IFontFamilyFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithName(hstring familyName, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Media::IFontFamily ** instance) = 0;
};

struct __declspec(uuid("52ad7af9-37e6-4297-a238-97fb6a408d9e")) __declspec(novtable) IFontFamilyStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_XamlAutoFontFamily(Windows::UI::Xaml::Media::IFontFamily ** value) = 0;
};

struct __declspec(uuid("a06798b7-a2ec-415f-ade2-eade9333f2c7")) __declspec(novtable) IGeneralTransform : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Inverse(Windows::UI::Xaml::Media::IGeneralTransform ** value) = 0;
    virtual HRESULT __stdcall abi_TransformPoint(Windows::Foundation::Point point, Windows::Foundation::Point * returnValue) = 0;
    virtual HRESULT __stdcall abi_TryTransform(Windows::Foundation::Point inPoint, Windows::Foundation::Point * outPoint, bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_TransformBounds(Windows::Foundation::Rect rect, Windows::Foundation::Rect * returnValue) = 0;
};

struct __declspec(uuid("7a25c930-29c4-4e31-b6f9-dedd52e4df1b")) __declspec(novtable) IGeneralTransformFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Media::IGeneralTransform ** instance) = 0;
};

struct __declspec(uuid("4f121083-24cf-4524-90ad-8a42b1c12783")) __declspec(novtable) IGeneralTransformOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InverseCore(Windows::UI::Xaml::Media::IGeneralTransform ** value) = 0;
    virtual HRESULT __stdcall abi_TryTransformCore(Windows::Foundation::Point inPoint, Windows::Foundation::Point * outPoint, bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_TransformBoundsCore(Windows::Foundation::Rect rect, Windows::Foundation::Rect * returnValue) = 0;
};

struct __declspec(uuid("fa123889-0acd-417b-b62d-5ca1bf4dfc0e")) __declspec(novtable) IGeometry : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Transform(Windows::UI::Xaml::Media::ITransform ** value) = 0;
    virtual HRESULT __stdcall put_Transform(Windows::UI::Xaml::Media::ITransform * value) = 0;
    virtual HRESULT __stdcall get_Bounds(Windows::Foundation::Rect * value) = 0;
};

struct __declspec(uuid("f65daf23-d5fd-42f9-b32a-929c5a4b54e1")) __declspec(novtable) IGeometryFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("55225a61-8677-4c8c-8e46-ee3dc355114b")) __declspec(novtable) IGeometryGroup : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FillRule(winrt::Windows::UI::Xaml::Media::FillRule * value) = 0;
    virtual HRESULT __stdcall put_FillRule(winrt::Windows::UI::Xaml::Media::FillRule value) = 0;
    virtual HRESULT __stdcall get_Children(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Geometry> ** value) = 0;
    virtual HRESULT __stdcall put_Children(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Geometry> * value) = 0;
};

struct __declspec(uuid("56c955f4-8496-4bb6-abf0-617b1fe78b45")) __declspec(novtable) IGeometryGroupStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FillRuleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ChildrenProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("7a70aa8c-0b06-465f-b637-9a47e5a70111")) __declspec(novtable) IGeometryStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Empty(Windows::UI::Xaml::Media::IGeometry ** value) = 0;
    virtual HRESULT __stdcall get_StandardFlatteningTolerance(double * value) = 0;
    virtual HRESULT __stdcall get_TransformProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("2166e69f-935a-4191-8e3c-1c8dfdfcdc78")) __declspec(novtable) IGradientBrush : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SpreadMethod(winrt::Windows::UI::Xaml::Media::GradientSpreadMethod * value) = 0;
    virtual HRESULT __stdcall put_SpreadMethod(winrt::Windows::UI::Xaml::Media::GradientSpreadMethod value) = 0;
    virtual HRESULT __stdcall get_MappingMode(winrt::Windows::UI::Xaml::Media::BrushMappingMode * value) = 0;
    virtual HRESULT __stdcall put_MappingMode(winrt::Windows::UI::Xaml::Media::BrushMappingMode value) = 0;
    virtual HRESULT __stdcall get_ColorInterpolationMode(winrt::Windows::UI::Xaml::Media::ColorInterpolationMode * value) = 0;
    virtual HRESULT __stdcall put_ColorInterpolationMode(winrt::Windows::UI::Xaml::Media::ColorInterpolationMode value) = 0;
    virtual HRESULT __stdcall get_GradientStops(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::GradientStop> ** value) = 0;
    virtual HRESULT __stdcall put_GradientStops(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::GradientStop> * value) = 0;
};

struct __declspec(uuid("ed4779ca-45bd-4131-b625-be86e07c6112")) __declspec(novtable) IGradientBrushFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Media::IGradientBrush ** instance) = 0;
};

struct __declspec(uuid("961661f9-8bb4-4e6c-b923-b5d787e0f1a9")) __declspec(novtable) IGradientBrushStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SpreadMethodProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MappingModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ColorInterpolationModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_GradientStopsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("665f44fe-2e59-4c4a-ab53-076a100ccd81")) __declspec(novtable) IGradientStop : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Color(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_Color(Windows::UI::Color value) = 0;
    virtual HRESULT __stdcall get_Offset(double * value) = 0;
    virtual HRESULT __stdcall put_Offset(double value) = 0;
};

struct __declspec(uuid("602a6d75-6193-4fe5-8e82-c7c6f6febafd")) __declspec(novtable) IGradientStopStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ColorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OffsetProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("9fd11377-c12a-4493-bf7d-f3a8ad74b554")) __declspec(novtable) IImageBrush : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ImageSource(Windows::UI::Xaml::Media::IImageSource ** value) = 0;
    virtual HRESULT __stdcall put_ImageSource(Windows::UI::Xaml::Media::IImageSource * value) = 0;
    virtual HRESULT __stdcall add_ImageFailed(Windows::UI::Xaml::ExceptionRoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ImageFailed(event_token token) = 0;
    virtual HRESULT __stdcall add_ImageOpened(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ImageOpened(event_token token) = 0;
};

struct __declspec(uuid("1255b1b2-dd18-42e5-892c-eae30c305b8c")) __declspec(novtable) IImageBrushStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ImageSourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("737ef309-ea41-4d96-a71c-98e98efcab07")) __declspec(novtable) IImageSource : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("297ec001-2540-4e5a-ab66-88035dd3ddb5")) __declspec(novtable) IImageSourceFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("30edd4a2-8fc5-40af-a7a2-c27fe7aa1363")) __declspec(novtable) ILineGeometry : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_StartPoint(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_StartPoint(Windows::Foundation::Point value) = 0;
    virtual HRESULT __stdcall get_EndPoint(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_EndPoint(Windows::Foundation::Point value) = 0;
};

struct __declspec(uuid("578ae763-5562-4ee4-8703-ea4036d891e3")) __declspec(novtable) ILineGeometryStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_StartPointProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_EndPointProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("ef6a2e25-3ff0-4420-a411-7182a4cecb15")) __declspec(novtable) ILineSegment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Point(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_Point(Windows::Foundation::Point value) = 0;
};

struct __declspec(uuid("9fcab141-04c0-4afb-87b3-e800b969b894")) __declspec(novtable) ILineSegmentStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PointProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("8e96d16b-bb84-4c6f-9dbf-9d6c5c6d9c39")) __declspec(novtable) ILinearGradientBrush : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_StartPoint(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_StartPoint(Windows::Foundation::Point value) = 0;
    virtual HRESULT __stdcall get_EndPoint(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_EndPoint(Windows::Foundation::Point value) = 0;
};

struct __declspec(uuid("0ae0861c-1e7a-4fed-9857-ea8caa798490")) __declspec(novtable) ILinearGradientBrushFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithGradientStopCollectionAndAngle(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::GradientStop> * gradientStopCollection, double angle, Windows::UI::Xaml::Media::ILinearGradientBrush ** instance) = 0;
};

struct __declspec(uuid("7af6e504-2dc3-40e3-be0b-b314c13cb991")) __declspec(novtable) ILinearGradientBrushStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_StartPointProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_EndPointProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("6f03e149-bfc9-4c01-b578-50338cec97fc")) __declspec(novtable) IMatrix3DProjection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ProjectionMatrix(Windows::UI::Xaml::Media::Media3D::Matrix3D * value) = 0;
    virtual HRESULT __stdcall put_ProjectionMatrix(Windows::UI::Xaml::Media::Media3D::Matrix3D value) = 0;
};

struct __declspec(uuid("ae9d5895-41ec-4e37-abaa-69f41d2f876b")) __declspec(novtable) IMatrix3DProjectionStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ProjectionMatrixProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("f3cf4882-06b5-48c8-9eb2-1763e9364038")) __declspec(novtable) IMatrixHelper : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("c18606a6-39f4-4b8a-8403-28e5e5f033b4")) __declspec(novtable) IMatrixHelperStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Identity(Windows::UI::Xaml::Media::Matrix * value) = 0;
    virtual HRESULT __stdcall abi_FromElements(double m11, double m12, double m21, double m22, double offsetX, double offsetY, Windows::UI::Xaml::Media::Matrix * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetIsIdentity(Windows::UI::Xaml::Media::Matrix target, bool * value) = 0;
    virtual HRESULT __stdcall abi_Transform(Windows::UI::Xaml::Media::Matrix target, Windows::Foundation::Point point, Windows::Foundation::Point * returnValue) = 0;
};

struct __declspec(uuid("edfdd551-5fed-45fc-ae62-92a4b6cf9707")) __declspec(novtable) IMatrixTransform : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Matrix(Windows::UI::Xaml::Media::Matrix * value) = 0;
    virtual HRESULT __stdcall put_Matrix(Windows::UI::Xaml::Media::Matrix value) = 0;
};

struct __declspec(uuid("43e02e47-15b8-4758-bb97-7d52420acc5b")) __declspec(novtable) IMatrixTransformStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MatrixProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("e4a8b21c-e3c2-485c-ae69-f1537b76755a")) __declspec(novtable) IMediaTransportControlsThumbnailRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetThumbnailImage(Windows::Storage::Streams::IInputStream * source) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** returnValue) = 0;
};

struct __declspec(uuid("02b65a91-e5a1-442b-88d3-2dc127bfc59b")) __declspec(novtable) IPartialMediaFailureDetectedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_StreamKind(winrt::Windows::Media::Playback::FailedMediaStreamKind * value) = 0;
};

struct __declspec(uuid("73074875-890d-416b-b9ae-e84dfd9c4b1b")) __declspec(novtable) IPartialMediaFailureDetectedEventArgs2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ExtendedError(HRESULT * value) = 0;
};

struct __declspec(uuid("5d955c8c-5fa9-4dda-a3cc-10fcdcaa20d7")) __declspec(novtable) IPathFigure : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Segments(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::PathSegment> ** value) = 0;
    virtual HRESULT __stdcall put_Segments(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::PathSegment> * value) = 0;
    virtual HRESULT __stdcall get_StartPoint(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_StartPoint(Windows::Foundation::Point value) = 0;
    virtual HRESULT __stdcall get_IsClosed(bool * value) = 0;
    virtual HRESULT __stdcall put_IsClosed(bool value) = 0;
    virtual HRESULT __stdcall get_IsFilled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsFilled(bool value) = 0;
};

struct __declspec(uuid("b60591d9-2395-4317-9552-3a58526f8c7b")) __declspec(novtable) IPathFigureStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SegmentsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StartPointProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsClosedProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsFilledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("081b9df8-bae6-4bcb-813c-bde0e46dc8b7")) __declspec(novtable) IPathGeometry : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FillRule(winrt::Windows::UI::Xaml::Media::FillRule * value) = 0;
    virtual HRESULT __stdcall put_FillRule(winrt::Windows::UI::Xaml::Media::FillRule value) = 0;
    virtual HRESULT __stdcall get_Figures(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::PathFigure> ** value) = 0;
    virtual HRESULT __stdcall put_Figures(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::PathFigure> * value) = 0;
};

struct __declspec(uuid("d9e58bba-2cba-4741-8f8d-3198cf5186b9")) __declspec(novtable) IPathGeometryStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FillRuleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FiguresProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("fcfa71cf-9ce3-474f-8157-10b6435a616b")) __declspec(novtable) IPathSegment : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("2a1c0aae-eccd-4464-a148-6ffdb3aa281f")) __declspec(novtable) IPathSegmentFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("e6f82bfa-6726-469a-b259-a5188347ca8f")) __declspec(novtable) IPlaneProjection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LocalOffsetX(double * value) = 0;
    virtual HRESULT __stdcall put_LocalOffsetX(double value) = 0;
    virtual HRESULT __stdcall get_LocalOffsetY(double * value) = 0;
    virtual HRESULT __stdcall put_LocalOffsetY(double value) = 0;
    virtual HRESULT __stdcall get_LocalOffsetZ(double * value) = 0;
    virtual HRESULT __stdcall put_LocalOffsetZ(double value) = 0;
    virtual HRESULT __stdcall get_RotationX(double * value) = 0;
    virtual HRESULT __stdcall put_RotationX(double value) = 0;
    virtual HRESULT __stdcall get_RotationY(double * value) = 0;
    virtual HRESULT __stdcall put_RotationY(double value) = 0;
    virtual HRESULT __stdcall get_RotationZ(double * value) = 0;
    virtual HRESULT __stdcall put_RotationZ(double value) = 0;
    virtual HRESULT __stdcall get_CenterOfRotationX(double * value) = 0;
    virtual HRESULT __stdcall put_CenterOfRotationX(double value) = 0;
    virtual HRESULT __stdcall get_CenterOfRotationY(double * value) = 0;
    virtual HRESULT __stdcall put_CenterOfRotationY(double value) = 0;
    virtual HRESULT __stdcall get_CenterOfRotationZ(double * value) = 0;
    virtual HRESULT __stdcall put_CenterOfRotationZ(double value) = 0;
    virtual HRESULT __stdcall get_GlobalOffsetX(double * value) = 0;
    virtual HRESULT __stdcall put_GlobalOffsetX(double value) = 0;
    virtual HRESULT __stdcall get_GlobalOffsetY(double * value) = 0;
    virtual HRESULT __stdcall put_GlobalOffsetY(double value) = 0;
    virtual HRESULT __stdcall get_GlobalOffsetZ(double * value) = 0;
    virtual HRESULT __stdcall put_GlobalOffsetZ(double value) = 0;
    virtual HRESULT __stdcall get_ProjectionMatrix(Windows::UI::Xaml::Media::Media3D::Matrix3D * value) = 0;
};

struct __declspec(uuid("ad919c67-3bdc-4855-8969-d1f9a3adc27d")) __declspec(novtable) IPlaneProjectionStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LocalOffsetXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_LocalOffsetYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_LocalOffsetZProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RotationXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RotationYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RotationZProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CenterOfRotationXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CenterOfRotationYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CenterOfRotationZProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_GlobalOffsetXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_GlobalOffsetYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_GlobalOffsetZProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ProjectionMatrixProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("36805271-38c4-4bcf-96cd-028a6d38af25")) __declspec(novtable) IPolyBezierSegment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Points(Windows::Foundation::Collections::IVector<Windows::Foundation::Point> ** value) = 0;
    virtual HRESULT __stdcall put_Points(Windows::Foundation::Collections::IVector<Windows::Foundation::Point> * value) = 0;
};

struct __declspec(uuid("1d91a6da-1492-4acc-bd66-a496f3d829d6")) __declspec(novtable) IPolyBezierSegmentStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PointsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("4b397f87-a2e6-479d-bdc8-6f4464646887")) __declspec(novtable) IPolyLineSegment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Points(Windows::Foundation::Collections::IVector<Windows::Foundation::Point> ** value) = 0;
    virtual HRESULT __stdcall put_Points(Windows::Foundation::Collections::IVector<Windows::Foundation::Point> * value) = 0;
};

struct __declspec(uuid("d64a2c87-33f1-4e70-a47f-b4981ef648a2")) __declspec(novtable) IPolyLineSegmentStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PointsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("dd5ced7d-e6db-4c96-b6a1-3fce96e987a6")) __declspec(novtable) IPolyQuadraticBezierSegment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Points(Windows::Foundation::Collections::IVector<Windows::Foundation::Point> ** value) = 0;
    virtual HRESULT __stdcall put_Points(Windows::Foundation::Collections::IVector<Windows::Foundation::Point> * value) = 0;
};

struct __declspec(uuid("fdf5eb75-7ad5-4c89-8169-8c9786abd9eb")) __declspec(novtable) IPolyQuadraticBezierSegmentStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PointsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("b3443557-7f39-4d04-a89c-844338cac897")) __declspec(novtable) IProjection : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("c4f29cab-60ad-4f24-bd27-9d69c3127c9a")) __declspec(novtable) IProjectionFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Media::IProjection ** instance) = 0;
};

struct __declspec(uuid("2c509a5b-bf18-455a-a078-914b5232d8af")) __declspec(novtable) IQuadraticBezierSegment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Point1(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_Point1(Windows::Foundation::Point value) = 0;
    virtual HRESULT __stdcall get_Point2(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_Point2(Windows::Foundation::Point value) = 0;
};

struct __declspec(uuid("69c78278-3c0b-4b4f-b7a2-f003ded41bb0")) __declspec(novtable) IQuadraticBezierSegmentStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Point1Property(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_Point2Property(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("9016aa6f-3ca8-4c80-8e2f-8851a68f131f")) __declspec(novtable) IRateChangedRoutedEventArgs : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("a25a1f58-c575-4196-91cf-9fdfb10445c3")) __declspec(novtable) IRectangleGeometry : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Rect(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall put_Rect(Windows::Foundation::Rect value) = 0;
};

struct __declspec(uuid("377f8dba-7902-48e3-83be-7c8002a6653c")) __declspec(novtable) IRectangleGeometryStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RectProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("5bf7d30d-9748-4aed-8380-d7890eb776a0")) __declspec(novtable) IRenderingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RenderingTime(Windows::Foundation::TimeSpan * value) = 0;
};

struct __declspec(uuid("688ea9b9-1e4e-4596-86e3-428b27334faf")) __declspec(novtable) IRotateTransform : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CenterX(double * value) = 0;
    virtual HRESULT __stdcall put_CenterX(double value) = 0;
    virtual HRESULT __stdcall get_CenterY(double * value) = 0;
    virtual HRESULT __stdcall put_CenterY(double value) = 0;
    virtual HRESULT __stdcall get_Angle(double * value) = 0;
    virtual HRESULT __stdcall put_Angle(double value) = 0;
};

struct __declspec(uuid("a131eb8a-51a3-41b6-b9d3-a10e429054ab")) __declspec(novtable) IRotateTransformStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CenterXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CenterYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AngleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("ed67f18d-936e-43ab-929a-e9cd0a511e52")) __declspec(novtable) IScaleTransform : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CenterX(double * value) = 0;
    virtual HRESULT __stdcall put_CenterX(double value) = 0;
    virtual HRESULT __stdcall get_CenterY(double * value) = 0;
    virtual HRESULT __stdcall put_CenterY(double value) = 0;
    virtual HRESULT __stdcall get_ScaleX(double * value) = 0;
    virtual HRESULT __stdcall put_ScaleX(double value) = 0;
    virtual HRESULT __stdcall get_ScaleY(double * value) = 0;
    virtual HRESULT __stdcall put_ScaleY(double value) = 0;
};

struct __declspec(uuid("9d9436f4-40a7-46dd-975a-07d337cd852e")) __declspec(novtable) IScaleTransformStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CenterXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CenterYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ScaleXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ScaleYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("4e8a3b15-7a0f-4617-9e98-1e65bdc92115")) __declspec(novtable) ISkewTransform : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CenterX(double * value) = 0;
    virtual HRESULT __stdcall put_CenterX(double value) = 0;
    virtual HRESULT __stdcall get_CenterY(double * value) = 0;
    virtual HRESULT __stdcall put_CenterY(double value) = 0;
    virtual HRESULT __stdcall get_AngleX(double * value) = 0;
    virtual HRESULT __stdcall put_AngleX(double value) = 0;
    virtual HRESULT __stdcall get_AngleY(double * value) = 0;
    virtual HRESULT __stdcall put_AngleY(double value) = 0;
};

struct __declspec(uuid("ecd11d73-5614-4b31-b6af-beae10105624")) __declspec(novtable) ISkewTransformStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CenterXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CenterYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AngleXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AngleYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("9d850850-66f3-48df-9a8f-824bd5e070af")) __declspec(novtable) ISolidColorBrush : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Color(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_Color(Windows::UI::Color value) = 0;
};

struct __declspec(uuid("d935ce0c-86f5-4da6-8a27-b1619ef7f92b")) __declspec(novtable) ISolidColorBrushFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithColor(Windows::UI::Color color, Windows::UI::Xaml::Media::ISolidColorBrush ** instance) = 0;
};

struct __declspec(uuid("e1a65efa-2b23-41ba-b9ba-7094ec8e4e9f")) __declspec(novtable) ISolidColorBrushStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ColorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("c201cf06-cd84-48a5-9607-664d7361cd61")) __declspec(novtable) ITileBrush : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AlignmentX(winrt::Windows::UI::Xaml::Media::AlignmentX * value) = 0;
    virtual HRESULT __stdcall put_AlignmentX(winrt::Windows::UI::Xaml::Media::AlignmentX value) = 0;
    virtual HRESULT __stdcall get_AlignmentY(winrt::Windows::UI::Xaml::Media::AlignmentY * value) = 0;
    virtual HRESULT __stdcall put_AlignmentY(winrt::Windows::UI::Xaml::Media::AlignmentY value) = 0;
    virtual HRESULT __stdcall get_Stretch(winrt::Windows::UI::Xaml::Media::Stretch * value) = 0;
    virtual HRESULT __stdcall put_Stretch(winrt::Windows::UI::Xaml::Media::Stretch value) = 0;
};

struct __declspec(uuid("aa159f7c-ed6a-4fb3-b014-b5c7e379a4de")) __declspec(novtable) ITileBrushFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Media::ITileBrush ** instance) = 0;
};

struct __declspec(uuid("3497c25b-b562-4e68-8435-2399f6eb94d5")) __declspec(novtable) ITileBrushStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AlignmentXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AlignmentYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StretchProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("a68ef02d-45ba-4e50-8cad-aaea3a227af5")) __declspec(novtable) ITimelineMarker : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Time(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_Time(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_Type(hstring * value) = 0;
    virtual HRESULT __stdcall put_Type(hstring value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall put_Text(hstring value) = 0;
};

struct __declspec(uuid("7c3b3ef3-2c88-4d9c-99b6-46cdbd48d4c1")) __declspec(novtable) ITimelineMarkerRoutedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Marker(Windows::UI::Xaml::Media::ITimelineMarker ** value) = 0;
    virtual HRESULT __stdcall put_Marker(Windows::UI::Xaml::Media::ITimelineMarker * value) = 0;
};

struct __declspec(uuid("c4aef0c6-16a3-484b-87f5-6528b8f04a47")) __declspec(novtable) ITimelineMarkerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TimeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TypeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("4df74078-bfd6-4ed1-9682-d2fd8bf2fe6f")) __declspec(novtable) ITransform : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("1a955a66-7cf4-4320-b416-6181192fcc6d")) __declspec(novtable) ITransformFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("63418ccc-8d2d-4737-b951-2afce1ddc4c4")) __declspec(novtable) ITransformGroup : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Children(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Transform> ** value) = 0;
    virtual HRESULT __stdcall put_Children(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Transform> * value) = 0;
    virtual HRESULT __stdcall get_Value(Windows::UI::Xaml::Media::Matrix * value) = 0;
};

struct __declspec(uuid("25312f2a-cfab-4b24-9713-5bdead1929c0")) __declspec(novtable) ITransformGroupStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ChildrenProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("c975905c-3c36-4229-817b-178f64c0e113")) __declspec(novtable) ITranslateTransform : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_X(double * value) = 0;
    virtual HRESULT __stdcall put_X(double value) = 0;
    virtual HRESULT __stdcall get_Y(double * value) = 0;
    virtual HRESULT __stdcall put_Y(double value) = 0;
};

struct __declspec(uuid("f419aa91-e042-4111-9c2f-d201304123dd")) __declspec(novtable) ITranslateTransformStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_XProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_YProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("24b935e3-52c7-4141-8bac-a73d06130569")) __declspec(novtable) IVisualTreeHelper : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("e75758c4-d25d-4b1d-971f-596f17f12baa")) __declspec(novtable) IVisualTreeHelperStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindElementsInHostCoordinatesPoint(Windows::Foundation::Point intersectingPoint, Windows::UI::Xaml::IUIElement * subtree, Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> ** elements) = 0;
    virtual HRESULT __stdcall abi_FindElementsInHostCoordinatesRect(Windows::Foundation::Rect intersectingRect, Windows::UI::Xaml::IUIElement * subtree, Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> ** elements) = 0;
    virtual HRESULT __stdcall abi_FindAllElementsInHostCoordinatesPoint(Windows::Foundation::Point intersectingPoint, Windows::UI::Xaml::IUIElement * subtree, bool includeAllElements, Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> ** elements) = 0;
    virtual HRESULT __stdcall abi_FindAllElementsInHostCoordinatesRect(Windows::Foundation::Rect intersectingRect, Windows::UI::Xaml::IUIElement * subtree, bool includeAllElements, Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> ** elements) = 0;
    virtual HRESULT __stdcall abi_GetChild(Windows::UI::Xaml::IDependencyObject * reference, int32_t childIndex, Windows::UI::Xaml::IDependencyObject ** child) = 0;
    virtual HRESULT __stdcall abi_GetChildrenCount(Windows::UI::Xaml::IDependencyObject * reference, int32_t * count) = 0;
    virtual HRESULT __stdcall abi_GetParent(Windows::UI::Xaml::IDependencyObject * reference, Windows::UI::Xaml::IDependencyObject ** parent) = 0;
    virtual HRESULT __stdcall abi_DisconnectChildrenRecursive(Windows::UI::Xaml::IUIElement * element) = 0;
};

struct __declspec(uuid("07bcd176-869f-44a7-8797-2103a4c3e47a")) __declspec(novtable) IVisualTreeHelperStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetOpenPopups(Windows::UI::Xaml::IWindow * window, Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Controls::Primitives::Popup> ** popups) = 0;
};

struct __declspec(uuid("08e9a257-ae05-489b-8839-28c6225d2349")) __declspec(novtable) RateChangedRoutedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Media::IRateChangedRoutedEventArgs * e) = 0;
};

struct __declspec(uuid("72e2fa9c-6dea-4cbe-a159-06ce95fbeced")) __declspec(novtable) TimelineMarkerRoutedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Media::ITimelineMarkerRoutedEventArgs * e) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::Media::ArcSegment> { using default_interface = Windows::UI::Xaml::Media::IArcSegment; };
template <> struct traits<Windows::UI::Xaml::Media::BezierSegment> { using default_interface = Windows::UI::Xaml::Media::IBezierSegment; };
template <> struct traits<Windows::UI::Xaml::Media::BitmapCache> { using default_interface = Windows::UI::Xaml::Media::IBitmapCache; };
template <> struct traits<Windows::UI::Xaml::Media::Brush> { using default_interface = Windows::UI::Xaml::Media::IBrush; };
template <> struct traits<Windows::UI::Xaml::Media::BrushCollection> { using default_interface = Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Brush>; };
template <> struct traits<Windows::UI::Xaml::Media::CacheMode> { using default_interface = Windows::UI::Xaml::Media::ICacheMode; };
template <> struct traits<Windows::UI::Xaml::Media::CompositeTransform> { using default_interface = Windows::UI::Xaml::Media::ICompositeTransform; };
template <> struct traits<Windows::UI::Xaml::Media::CompositionTarget> { using default_interface = Windows::UI::Xaml::Media::ICompositionTarget; };
template <> struct traits<Windows::UI::Xaml::Media::DoubleCollection> { using default_interface = Windows::Foundation::Collections::IVector<double>; };
template <> struct traits<Windows::UI::Xaml::Media::EllipseGeometry> { using default_interface = Windows::UI::Xaml::Media::IEllipseGeometry; };
template <> struct traits<Windows::UI::Xaml::Media::FontFamily> { using default_interface = Windows::UI::Xaml::Media::IFontFamily; };
template <> struct traits<Windows::UI::Xaml::Media::GeneralTransform> { using default_interface = Windows::UI::Xaml::Media::IGeneralTransform; };
template <> struct traits<Windows::UI::Xaml::Media::Geometry> { using default_interface = Windows::UI::Xaml::Media::IGeometry; };
template <> struct traits<Windows::UI::Xaml::Media::GeometryCollection> { using default_interface = Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Geometry>; };
template <> struct traits<Windows::UI::Xaml::Media::GeometryGroup> { using default_interface = Windows::UI::Xaml::Media::IGeometryGroup; };
template <> struct traits<Windows::UI::Xaml::Media::GradientBrush> { using default_interface = Windows::UI::Xaml::Media::IGradientBrush; };
template <> struct traits<Windows::UI::Xaml::Media::GradientStop> { using default_interface = Windows::UI::Xaml::Media::IGradientStop; };
template <> struct traits<Windows::UI::Xaml::Media::GradientStopCollection> { using default_interface = Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::GradientStop>; };
template <> struct traits<Windows::UI::Xaml::Media::ImageBrush> { using default_interface = Windows::UI::Xaml::Media::IImageBrush; };
template <> struct traits<Windows::UI::Xaml::Media::ImageSource> { using default_interface = Windows::UI::Xaml::Media::IImageSource; };
template <> struct traits<Windows::UI::Xaml::Media::LineGeometry> { using default_interface = Windows::UI::Xaml::Media::ILineGeometry; };
template <> struct traits<Windows::UI::Xaml::Media::LineSegment> { using default_interface = Windows::UI::Xaml::Media::ILineSegment; };
template <> struct traits<Windows::UI::Xaml::Media::LinearGradientBrush> { using default_interface = Windows::UI::Xaml::Media::ILinearGradientBrush; };
template <> struct traits<Windows::UI::Xaml::Media::Matrix3DProjection> { using default_interface = Windows::UI::Xaml::Media::IMatrix3DProjection; };
template <> struct traits<Windows::UI::Xaml::Media::MatrixHelper> { using default_interface = Windows::UI::Xaml::Media::IMatrixHelper; };
template <> struct traits<Windows::UI::Xaml::Media::MatrixTransform> { using default_interface = Windows::UI::Xaml::Media::IMatrixTransform; };
template <> struct traits<Windows::UI::Xaml::Media::MediaTransportControlsThumbnailRequestedEventArgs> { using default_interface = Windows::UI::Xaml::Media::IMediaTransportControlsThumbnailRequestedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Media::PartialMediaFailureDetectedEventArgs> { using default_interface = Windows::UI::Xaml::Media::IPartialMediaFailureDetectedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Media::PathFigure> { using default_interface = Windows::UI::Xaml::Media::IPathFigure; };
template <> struct traits<Windows::UI::Xaml::Media::PathFigureCollection> { using default_interface = Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::PathFigure>; };
template <> struct traits<Windows::UI::Xaml::Media::PathGeometry> { using default_interface = Windows::UI::Xaml::Media::IPathGeometry; };
template <> struct traits<Windows::UI::Xaml::Media::PathSegment> { using default_interface = Windows::UI::Xaml::Media::IPathSegment; };
template <> struct traits<Windows::UI::Xaml::Media::PathSegmentCollection> { using default_interface = Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::PathSegment>; };
template <> struct traits<Windows::UI::Xaml::Media::PlaneProjection> { using default_interface = Windows::UI::Xaml::Media::IPlaneProjection; };
template <> struct traits<Windows::UI::Xaml::Media::PointCollection> { using default_interface = Windows::Foundation::Collections::IVector<Windows::Foundation::Point>; };
template <> struct traits<Windows::UI::Xaml::Media::PolyBezierSegment> { using default_interface = Windows::UI::Xaml::Media::IPolyBezierSegment; };
template <> struct traits<Windows::UI::Xaml::Media::PolyLineSegment> { using default_interface = Windows::UI::Xaml::Media::IPolyLineSegment; };
template <> struct traits<Windows::UI::Xaml::Media::PolyQuadraticBezierSegment> { using default_interface = Windows::UI::Xaml::Media::IPolyQuadraticBezierSegment; };
template <> struct traits<Windows::UI::Xaml::Media::Projection> { using default_interface = Windows::UI::Xaml::Media::IProjection; };
template <> struct traits<Windows::UI::Xaml::Media::QuadraticBezierSegment> { using default_interface = Windows::UI::Xaml::Media::IQuadraticBezierSegment; };
template <> struct traits<Windows::UI::Xaml::Media::RateChangedRoutedEventArgs> { using default_interface = Windows::UI::Xaml::Media::IRateChangedRoutedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Media::RectangleGeometry> { using default_interface = Windows::UI::Xaml::Media::IRectangleGeometry; };
template <> struct traits<Windows::UI::Xaml::Media::RenderingEventArgs> { using default_interface = Windows::UI::Xaml::Media::IRenderingEventArgs; };
template <> struct traits<Windows::UI::Xaml::Media::RotateTransform> { using default_interface = Windows::UI::Xaml::Media::IRotateTransform; };
template <> struct traits<Windows::UI::Xaml::Media::ScaleTransform> { using default_interface = Windows::UI::Xaml::Media::IScaleTransform; };
template <> struct traits<Windows::UI::Xaml::Media::SkewTransform> { using default_interface = Windows::UI::Xaml::Media::ISkewTransform; };
template <> struct traits<Windows::UI::Xaml::Media::SolidColorBrush> { using default_interface = Windows::UI::Xaml::Media::ISolidColorBrush; };
template <> struct traits<Windows::UI::Xaml::Media::TileBrush> { using default_interface = Windows::UI::Xaml::Media::ITileBrush; };
template <> struct traits<Windows::UI::Xaml::Media::TimelineMarker> { using default_interface = Windows::UI::Xaml::Media::ITimelineMarker; };
template <> struct traits<Windows::UI::Xaml::Media::TimelineMarkerCollection> { using default_interface = Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::TimelineMarker>; };
template <> struct traits<Windows::UI::Xaml::Media::TimelineMarkerRoutedEventArgs> { using default_interface = Windows::UI::Xaml::Media::ITimelineMarkerRoutedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Media::Transform> { using default_interface = Windows::UI::Xaml::Media::ITransform; };
template <> struct traits<Windows::UI::Xaml::Media::TransformCollection> { using default_interface = Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Transform>; };
template <> struct traits<Windows::UI::Xaml::Media::TransformGroup> { using default_interface = Windows::UI::Xaml::Media::ITransformGroup; };
template <> struct traits<Windows::UI::Xaml::Media::TranslateTransform> { using default_interface = Windows::UI::Xaml::Media::ITranslateTransform; };
template <> struct traits<Windows::UI::Xaml::Media::VisualTreeHelper> { using default_interface = Windows::UI::Xaml::Media::IVisualTreeHelper; };

}

namespace Windows::UI::Xaml::Media {

template <typename D>
struct WINRT_EBO impl_IArcSegment
{
    Windows::Foundation::Point Point() const;
    void Point(const Windows::Foundation::Point & value) const;
    Windows::Foundation::Size Size() const;
    void Size(const Windows::Foundation::Size & value) const;
    double RotationAngle() const;
    void RotationAngle(double value) const;
    bool IsLargeArc() const;
    void IsLargeArc(bool value) const;
    Windows::UI::Xaml::Media::SweepDirection SweepDirection() const;
    void SweepDirection(Windows::UI::Xaml::Media::SweepDirection value) const;
};

template <typename D>
struct WINRT_EBO impl_IArcSegmentStatics
{
    Windows::UI::Xaml::DependencyProperty PointProperty() const;
    Windows::UI::Xaml::DependencyProperty SizeProperty() const;
    Windows::UI::Xaml::DependencyProperty RotationAngleProperty() const;
    Windows::UI::Xaml::DependencyProperty IsLargeArcProperty() const;
    Windows::UI::Xaml::DependencyProperty SweepDirectionProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IBezierSegment
{
    Windows::Foundation::Point Point1() const;
    void Point1(const Windows::Foundation::Point & value) const;
    Windows::Foundation::Point Point2() const;
    void Point2(const Windows::Foundation::Point & value) const;
    Windows::Foundation::Point Point3() const;
    void Point3(const Windows::Foundation::Point & value) const;
};

template <typename D>
struct WINRT_EBO impl_IBezierSegmentStatics
{
    Windows::UI::Xaml::DependencyProperty Point1Property() const;
    Windows::UI::Xaml::DependencyProperty Point2Property() const;
    Windows::UI::Xaml::DependencyProperty Point3Property() const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapCache
{
};

template <typename D>
struct WINRT_EBO impl_IBrush
{
    double Opacity() const;
    void Opacity(double value) const;
    Windows::UI::Xaml::Media::Transform Transform() const;
    void Transform(const Windows::UI::Xaml::Media::Transform & value) const;
    Windows::UI::Xaml::Media::Transform RelativeTransform() const;
    void RelativeTransform(const Windows::UI::Xaml::Media::Transform & value) const;
};

template <typename D>
struct WINRT_EBO impl_IBrushFactory
{
    Windows::UI::Xaml::Media::Brush CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IBrushStatics
{
    Windows::UI::Xaml::DependencyProperty OpacityProperty() const;
    Windows::UI::Xaml::DependencyProperty TransformProperty() const;
    Windows::UI::Xaml::DependencyProperty RelativeTransformProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ICacheMode
{
};

template <typename D>
struct WINRT_EBO impl_ICacheModeFactory
{
    Windows::UI::Xaml::Media::CacheMode CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ICompositeTransform
{
    double CenterX() const;
    void CenterX(double value) const;
    double CenterY() const;
    void CenterY(double value) const;
    double ScaleX() const;
    void ScaleX(double value) const;
    double ScaleY() const;
    void ScaleY(double value) const;
    double SkewX() const;
    void SkewX(double value) const;
    double SkewY() const;
    void SkewY(double value) const;
    double Rotation() const;
    void Rotation(double value) const;
    double TranslateX() const;
    void TranslateX(double value) const;
    double TranslateY() const;
    void TranslateY(double value) const;
};

template <typename D>
struct WINRT_EBO impl_ICompositeTransformStatics
{
    Windows::UI::Xaml::DependencyProperty CenterXProperty() const;
    Windows::UI::Xaml::DependencyProperty CenterYProperty() const;
    Windows::UI::Xaml::DependencyProperty ScaleXProperty() const;
    Windows::UI::Xaml::DependencyProperty ScaleYProperty() const;
    Windows::UI::Xaml::DependencyProperty SkewXProperty() const;
    Windows::UI::Xaml::DependencyProperty SkewYProperty() const;
    Windows::UI::Xaml::DependencyProperty RotationProperty() const;
    Windows::UI::Xaml::DependencyProperty TranslateXProperty() const;
    Windows::UI::Xaml::DependencyProperty TranslateYProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ICompositionTarget
{
};

template <typename D>
struct WINRT_EBO impl_ICompositionTargetStatics
{
    event_token Rendering(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using Rendering_revoker = event_revoker<ICompositionTargetStatics>;
    Rendering_revoker Rendering(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void Rendering(event_token token) const;
    event_token SurfaceContentsLost(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using SurfaceContentsLost_revoker = event_revoker<ICompositionTargetStatics>;
    SurfaceContentsLost_revoker SurfaceContentsLost(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void SurfaceContentsLost(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IEllipseGeometry
{
    Windows::Foundation::Point Center() const;
    void Center(const Windows::Foundation::Point & value) const;
    double RadiusX() const;
    void RadiusX(double value) const;
    double RadiusY() const;
    void RadiusY(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IEllipseGeometryStatics
{
    Windows::UI::Xaml::DependencyProperty CenterProperty() const;
    Windows::UI::Xaml::DependencyProperty RadiusXProperty() const;
    Windows::UI::Xaml::DependencyProperty RadiusYProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IFontFamily
{
    hstring Source() const;
};

template <typename D>
struct WINRT_EBO impl_IFontFamilyFactory
{
    Windows::UI::Xaml::Media::FontFamily CreateInstanceWithName(hstring_view familyName, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IFontFamilyStatics2
{
    Windows::UI::Xaml::Media::FontFamily XamlAutoFontFamily() const;
};

template <typename D>
struct WINRT_EBO impl_IGeneralTransform
{
    Windows::UI::Xaml::Media::GeneralTransform Inverse() const;
    Windows::Foundation::Point TransformPoint(const Windows::Foundation::Point & point) const;
    bool TryTransform(const Windows::Foundation::Point & inPoint, Windows::Foundation::Point & outPoint) const;
    Windows::Foundation::Rect TransformBounds(const Windows::Foundation::Rect & rect) const;
};

template <typename D>
struct WINRT_EBO impl_IGeneralTransformFactory
{
    Windows::UI::Xaml::Media::GeneralTransform CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IGeneralTransformOverrides
{
    Windows::UI::Xaml::Media::GeneralTransform InverseCore() const;
    bool TryTransformCore(const Windows::Foundation::Point & inPoint, Windows::Foundation::Point & outPoint) const;
    Windows::Foundation::Rect TransformBoundsCore(const Windows::Foundation::Rect & rect) const;
};

template <typename D>
struct WINRT_EBO impl_IGeometry
{
    Windows::UI::Xaml::Media::Transform Transform() const;
    void Transform(const Windows::UI::Xaml::Media::Transform & value) const;
    Windows::Foundation::Rect Bounds() const;
};

template <typename D>
struct WINRT_EBO impl_IGeometryFactory
{
};

template <typename D>
struct WINRT_EBO impl_IGeometryGroup
{
    Windows::UI::Xaml::Media::FillRule FillRule() const;
    void FillRule(Windows::UI::Xaml::Media::FillRule value) const;
    Windows::UI::Xaml::Media::GeometryCollection Children() const;
    void Children(const Windows::UI::Xaml::Media::GeometryCollection & value) const;
};

template <typename D>
struct WINRT_EBO impl_IGeometryGroupStatics
{
    Windows::UI::Xaml::DependencyProperty FillRuleProperty() const;
    Windows::UI::Xaml::DependencyProperty ChildrenProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IGeometryStatics
{
    Windows::UI::Xaml::Media::Geometry Empty() const;
    double StandardFlatteningTolerance() const;
    Windows::UI::Xaml::DependencyProperty TransformProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IGradientBrush
{
    Windows::UI::Xaml::Media::GradientSpreadMethod SpreadMethod() const;
    void SpreadMethod(Windows::UI::Xaml::Media::GradientSpreadMethod value) const;
    Windows::UI::Xaml::Media::BrushMappingMode MappingMode() const;
    void MappingMode(Windows::UI::Xaml::Media::BrushMappingMode value) const;
    Windows::UI::Xaml::Media::ColorInterpolationMode ColorInterpolationMode() const;
    void ColorInterpolationMode(Windows::UI::Xaml::Media::ColorInterpolationMode value) const;
    Windows::UI::Xaml::Media::GradientStopCollection GradientStops() const;
    void GradientStops(const Windows::UI::Xaml::Media::GradientStopCollection & value) const;
};

template <typename D>
struct WINRT_EBO impl_IGradientBrushFactory
{
    Windows::UI::Xaml::Media::GradientBrush CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IGradientBrushStatics
{
    Windows::UI::Xaml::DependencyProperty SpreadMethodProperty() const;
    Windows::UI::Xaml::DependencyProperty MappingModeProperty() const;
    Windows::UI::Xaml::DependencyProperty ColorInterpolationModeProperty() const;
    Windows::UI::Xaml::DependencyProperty GradientStopsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IGradientStop
{
    Windows::UI::Color Color() const;
    void Color(const Windows::UI::Color & value) const;
    double Offset() const;
    void Offset(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IGradientStopStatics
{
    Windows::UI::Xaml::DependencyProperty ColorProperty() const;
    Windows::UI::Xaml::DependencyProperty OffsetProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IImageBrush
{
    Windows::UI::Xaml::Media::ImageSource ImageSource() const;
    void ImageSource(const Windows::UI::Xaml::Media::ImageSource & value) const;
    event_token ImageFailed(const Windows::UI::Xaml::ExceptionRoutedEventHandler & value) const;
    using ImageFailed_revoker = event_revoker<IImageBrush>;
    ImageFailed_revoker ImageFailed(auto_revoke_t, const Windows::UI::Xaml::ExceptionRoutedEventHandler & value) const;
    void ImageFailed(event_token token) const;
    event_token ImageOpened(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using ImageOpened_revoker = event_revoker<IImageBrush>;
    ImageOpened_revoker ImageOpened(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void ImageOpened(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IImageBrushStatics
{
    Windows::UI::Xaml::DependencyProperty ImageSourceProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IImageSource
{
};

template <typename D>
struct WINRT_EBO impl_IImageSourceFactory
{
};

template <typename D>
struct WINRT_EBO impl_ILineGeometry
{
    Windows::Foundation::Point StartPoint() const;
    void StartPoint(const Windows::Foundation::Point & value) const;
    Windows::Foundation::Point EndPoint() const;
    void EndPoint(const Windows::Foundation::Point & value) const;
};

template <typename D>
struct WINRT_EBO impl_ILineGeometryStatics
{
    Windows::UI::Xaml::DependencyProperty StartPointProperty() const;
    Windows::UI::Xaml::DependencyProperty EndPointProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ILineSegment
{
    Windows::Foundation::Point Point() const;
    void Point(const Windows::Foundation::Point & value) const;
};

template <typename D>
struct WINRT_EBO impl_ILineSegmentStatics
{
    Windows::UI::Xaml::DependencyProperty PointProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ILinearGradientBrush
{
    Windows::Foundation::Point StartPoint() const;
    void StartPoint(const Windows::Foundation::Point & value) const;
    Windows::Foundation::Point EndPoint() const;
    void EndPoint(const Windows::Foundation::Point & value) const;
};

template <typename D>
struct WINRT_EBO impl_ILinearGradientBrushFactory
{
    Windows::UI::Xaml::Media::LinearGradientBrush CreateInstanceWithGradientStopCollectionAndAngle(const Windows::UI::Xaml::Media::GradientStopCollection & gradientStopCollection, double angle) const;
};

template <typename D>
struct WINRT_EBO impl_ILinearGradientBrushStatics
{
    Windows::UI::Xaml::DependencyProperty StartPointProperty() const;
    Windows::UI::Xaml::DependencyProperty EndPointProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMatrix3DProjection
{
    Windows::UI::Xaml::Media::Media3D::Matrix3D ProjectionMatrix() const;
    void ProjectionMatrix(const Windows::UI::Xaml::Media::Media3D::Matrix3D & value) const;
};

template <typename D>
struct WINRT_EBO impl_IMatrix3DProjectionStatics
{
    Windows::UI::Xaml::DependencyProperty ProjectionMatrixProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMatrixHelper
{
};

template <typename D>
struct WINRT_EBO impl_IMatrixHelperStatics
{
    Windows::UI::Xaml::Media::Matrix Identity() const;
    Windows::UI::Xaml::Media::Matrix FromElements(double m11, double m12, double m21, double m22, double offsetX, double offsetY) const;
    bool GetIsIdentity(const Windows::UI::Xaml::Media::Matrix & target) const;
    Windows::Foundation::Point Transform(const Windows::UI::Xaml::Media::Matrix & target, const Windows::Foundation::Point & point) const;
};

template <typename D>
struct WINRT_EBO impl_IMatrixTransform
{
    Windows::UI::Xaml::Media::Matrix Matrix() const;
    void Matrix(const Windows::UI::Xaml::Media::Matrix & value) const;
};

template <typename D>
struct WINRT_EBO impl_IMatrixTransformStatics
{
    Windows::UI::Xaml::DependencyProperty MatrixProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaTransportControlsThumbnailRequestedEventArgs
{
    void SetThumbnailImage(const Windows::Storage::Streams::IInputStream & source) const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IPartialMediaFailureDetectedEventArgs
{
    Windows::Media::Playback::FailedMediaStreamKind StreamKind() const;
};

template <typename D>
struct WINRT_EBO impl_IPartialMediaFailureDetectedEventArgs2
{
    HRESULT ExtendedError() const;
};

template <typename D>
struct WINRT_EBO impl_IPathFigure
{
    Windows::UI::Xaml::Media::PathSegmentCollection Segments() const;
    void Segments(const Windows::UI::Xaml::Media::PathSegmentCollection & value) const;
    Windows::Foundation::Point StartPoint() const;
    void StartPoint(const Windows::Foundation::Point & value) const;
    bool IsClosed() const;
    void IsClosed(bool value) const;
    bool IsFilled() const;
    void IsFilled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IPathFigureStatics
{
    Windows::UI::Xaml::DependencyProperty SegmentsProperty() const;
    Windows::UI::Xaml::DependencyProperty StartPointProperty() const;
    Windows::UI::Xaml::DependencyProperty IsClosedProperty() const;
    Windows::UI::Xaml::DependencyProperty IsFilledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IPathGeometry
{
    Windows::UI::Xaml::Media::FillRule FillRule() const;
    void FillRule(Windows::UI::Xaml::Media::FillRule value) const;
    Windows::UI::Xaml::Media::PathFigureCollection Figures() const;
    void Figures(const Windows::UI::Xaml::Media::PathFigureCollection & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPathGeometryStatics
{
    Windows::UI::Xaml::DependencyProperty FillRuleProperty() const;
    Windows::UI::Xaml::DependencyProperty FiguresProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IPathSegment
{
};

template <typename D>
struct WINRT_EBO impl_IPathSegmentFactory
{
};

template <typename D>
struct WINRT_EBO impl_IPlaneProjection
{
    double LocalOffsetX() const;
    void LocalOffsetX(double value) const;
    double LocalOffsetY() const;
    void LocalOffsetY(double value) const;
    double LocalOffsetZ() const;
    void LocalOffsetZ(double value) const;
    double RotationX() const;
    void RotationX(double value) const;
    double RotationY() const;
    void RotationY(double value) const;
    double RotationZ() const;
    void RotationZ(double value) const;
    double CenterOfRotationX() const;
    void CenterOfRotationX(double value) const;
    double CenterOfRotationY() const;
    void CenterOfRotationY(double value) const;
    double CenterOfRotationZ() const;
    void CenterOfRotationZ(double value) const;
    double GlobalOffsetX() const;
    void GlobalOffsetX(double value) const;
    double GlobalOffsetY() const;
    void GlobalOffsetY(double value) const;
    double GlobalOffsetZ() const;
    void GlobalOffsetZ(double value) const;
    Windows::UI::Xaml::Media::Media3D::Matrix3D ProjectionMatrix() const;
};

template <typename D>
struct WINRT_EBO impl_IPlaneProjectionStatics
{
    Windows::UI::Xaml::DependencyProperty LocalOffsetXProperty() const;
    Windows::UI::Xaml::DependencyProperty LocalOffsetYProperty() const;
    Windows::UI::Xaml::DependencyProperty LocalOffsetZProperty() const;
    Windows::UI::Xaml::DependencyProperty RotationXProperty() const;
    Windows::UI::Xaml::DependencyProperty RotationYProperty() const;
    Windows::UI::Xaml::DependencyProperty RotationZProperty() const;
    Windows::UI::Xaml::DependencyProperty CenterOfRotationXProperty() const;
    Windows::UI::Xaml::DependencyProperty CenterOfRotationYProperty() const;
    Windows::UI::Xaml::DependencyProperty CenterOfRotationZProperty() const;
    Windows::UI::Xaml::DependencyProperty GlobalOffsetXProperty() const;
    Windows::UI::Xaml::DependencyProperty GlobalOffsetYProperty() const;
    Windows::UI::Xaml::DependencyProperty GlobalOffsetZProperty() const;
    Windows::UI::Xaml::DependencyProperty ProjectionMatrixProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IPolyBezierSegment
{
    Windows::UI::Xaml::Media::PointCollection Points() const;
    void Points(const Windows::UI::Xaml::Media::PointCollection & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPolyBezierSegmentStatics
{
    Windows::UI::Xaml::DependencyProperty PointsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IPolyLineSegment
{
    Windows::UI::Xaml::Media::PointCollection Points() const;
    void Points(const Windows::UI::Xaml::Media::PointCollection & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPolyLineSegmentStatics
{
    Windows::UI::Xaml::DependencyProperty PointsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IPolyQuadraticBezierSegment
{
    Windows::UI::Xaml::Media::PointCollection Points() const;
    void Points(const Windows::UI::Xaml::Media::PointCollection & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPolyQuadraticBezierSegmentStatics
{
    Windows::UI::Xaml::DependencyProperty PointsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IProjection
{
};

template <typename D>
struct WINRT_EBO impl_IProjectionFactory
{
    Windows::UI::Xaml::Media::Projection CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IQuadraticBezierSegment
{
    Windows::Foundation::Point Point1() const;
    void Point1(const Windows::Foundation::Point & value) const;
    Windows::Foundation::Point Point2() const;
    void Point2(const Windows::Foundation::Point & value) const;
};

template <typename D>
struct WINRT_EBO impl_IQuadraticBezierSegmentStatics
{
    Windows::UI::Xaml::DependencyProperty Point1Property() const;
    Windows::UI::Xaml::DependencyProperty Point2Property() const;
};

template <typename D>
struct WINRT_EBO impl_IRateChangedRoutedEventArgs
{
};

template <typename D>
struct WINRT_EBO impl_IRectangleGeometry
{
    Windows::Foundation::Rect Rect() const;
    void Rect(const Windows::Foundation::Rect & value) const;
};

template <typename D>
struct WINRT_EBO impl_IRectangleGeometryStatics
{
    Windows::UI::Xaml::DependencyProperty RectProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IRenderingEventArgs
{
    Windows::Foundation::TimeSpan RenderingTime() const;
};

template <typename D>
struct WINRT_EBO impl_IRotateTransform
{
    double CenterX() const;
    void CenterX(double value) const;
    double CenterY() const;
    void CenterY(double value) const;
    double Angle() const;
    void Angle(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IRotateTransformStatics
{
    Windows::UI::Xaml::DependencyProperty CenterXProperty() const;
    Windows::UI::Xaml::DependencyProperty CenterYProperty() const;
    Windows::UI::Xaml::DependencyProperty AngleProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IScaleTransform
{
    double CenterX() const;
    void CenterX(double value) const;
    double CenterY() const;
    void CenterY(double value) const;
    double ScaleX() const;
    void ScaleX(double value) const;
    double ScaleY() const;
    void ScaleY(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IScaleTransformStatics
{
    Windows::UI::Xaml::DependencyProperty CenterXProperty() const;
    Windows::UI::Xaml::DependencyProperty CenterYProperty() const;
    Windows::UI::Xaml::DependencyProperty ScaleXProperty() const;
    Windows::UI::Xaml::DependencyProperty ScaleYProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ISkewTransform
{
    double CenterX() const;
    void CenterX(double value) const;
    double CenterY() const;
    void CenterY(double value) const;
    double AngleX() const;
    void AngleX(double value) const;
    double AngleY() const;
    void AngleY(double value) const;
};

template <typename D>
struct WINRT_EBO impl_ISkewTransformStatics
{
    Windows::UI::Xaml::DependencyProperty CenterXProperty() const;
    Windows::UI::Xaml::DependencyProperty CenterYProperty() const;
    Windows::UI::Xaml::DependencyProperty AngleXProperty() const;
    Windows::UI::Xaml::DependencyProperty AngleYProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ISolidColorBrush
{
    Windows::UI::Color Color() const;
    void Color(const Windows::UI::Color & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISolidColorBrushFactory
{
    Windows::UI::Xaml::Media::SolidColorBrush CreateInstanceWithColor(const Windows::UI::Color & color) const;
};

template <typename D>
struct WINRT_EBO impl_ISolidColorBrushStatics
{
    Windows::UI::Xaml::DependencyProperty ColorProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITileBrush
{
    Windows::UI::Xaml::Media::AlignmentX AlignmentX() const;
    void AlignmentX(Windows::UI::Xaml::Media::AlignmentX value) const;
    Windows::UI::Xaml::Media::AlignmentY AlignmentY() const;
    void AlignmentY(Windows::UI::Xaml::Media::AlignmentY value) const;
    Windows::UI::Xaml::Media::Stretch Stretch() const;
    void Stretch(Windows::UI::Xaml::Media::Stretch value) const;
};

template <typename D>
struct WINRT_EBO impl_ITileBrushFactory
{
    Windows::UI::Xaml::Media::TileBrush CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ITileBrushStatics
{
    Windows::UI::Xaml::DependencyProperty AlignmentXProperty() const;
    Windows::UI::Xaml::DependencyProperty AlignmentYProperty() const;
    Windows::UI::Xaml::DependencyProperty StretchProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITimelineMarker
{
    Windows::Foundation::TimeSpan Time() const;
    void Time(const Windows::Foundation::TimeSpan & value) const;
    hstring Type() const;
    void Type(hstring_view value) const;
    hstring Text() const;
    void Text(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_ITimelineMarkerRoutedEventArgs
{
    Windows::UI::Xaml::Media::TimelineMarker Marker() const;
    void Marker(const Windows::UI::Xaml::Media::TimelineMarker & value) const;
};

template <typename D>
struct WINRT_EBO impl_ITimelineMarkerStatics
{
    Windows::UI::Xaml::DependencyProperty TimeProperty() const;
    Windows::UI::Xaml::DependencyProperty TypeProperty() const;
    Windows::UI::Xaml::DependencyProperty TextProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITransform
{
};

template <typename D>
struct WINRT_EBO impl_ITransformFactory
{
};

template <typename D>
struct WINRT_EBO impl_ITransformGroup
{
    Windows::UI::Xaml::Media::TransformCollection Children() const;
    void Children(const Windows::UI::Xaml::Media::TransformCollection & value) const;
    Windows::UI::Xaml::Media::Matrix Value() const;
};

template <typename D>
struct WINRT_EBO impl_ITransformGroupStatics
{
    Windows::UI::Xaml::DependencyProperty ChildrenProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITranslateTransform
{
    double X() const;
    void X(double value) const;
    double Y() const;
    void Y(double value) const;
};

template <typename D>
struct WINRT_EBO impl_ITranslateTransformStatics
{
    Windows::UI::Xaml::DependencyProperty XProperty() const;
    Windows::UI::Xaml::DependencyProperty YProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IVisualTreeHelper
{
};

template <typename D>
struct WINRT_EBO impl_IVisualTreeHelperStatics
{
    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> FindElementsInHostCoordinates(const Windows::Foundation::Point & intersectingPoint, const Windows::UI::Xaml::UIElement & subtree) const;
    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> FindElementsInHostCoordinates(const Windows::Foundation::Rect & intersectingRect, const Windows::UI::Xaml::UIElement & subtree) const;
    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> FindElementsInHostCoordinates(const Windows::Foundation::Point & intersectingPoint, const Windows::UI::Xaml::UIElement & subtree, bool includeAllElements) const;
    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::UIElement> FindElementsInHostCoordinates(const Windows::Foundation::Rect & intersectingRect, const Windows::UI::Xaml::UIElement & subtree, bool includeAllElements) const;
    Windows::UI::Xaml::DependencyObject GetChild(const Windows::UI::Xaml::DependencyObject & reference, int32_t childIndex) const;
    int32_t GetChildrenCount(const Windows::UI::Xaml::DependencyObject & reference) const;
    Windows::UI::Xaml::DependencyObject GetParent(const Windows::UI::Xaml::DependencyObject & reference) const;
    void DisconnectChildrenRecursive(const Windows::UI::Xaml::UIElement & element) const;
};

template <typename D>
struct WINRT_EBO impl_IVisualTreeHelperStatics2
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Controls::Primitives::Popup> GetOpenPopups(const Windows::UI::Xaml::Window & window) const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Media::IArcSegment>
{
    using abi = ABI::Windows::UI::Xaml::Media::IArcSegment;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IArcSegment<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IArcSegmentStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IArcSegmentStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IArcSegmentStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IBezierSegment>
{
    using abi = ABI::Windows::UI::Xaml::Media::IBezierSegment;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IBezierSegment<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IBezierSegmentStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IBezierSegmentStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IBezierSegmentStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IBitmapCache>
{
    using abi = ABI::Windows::UI::Xaml::Media::IBitmapCache;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IBitmapCache<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IBrush>
{
    using abi = ABI::Windows::UI::Xaml::Media::IBrush;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IBrush<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IBrushFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::IBrushFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IBrushFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IBrushStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IBrushStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IBrushStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ICacheMode>
{
    using abi = ABI::Windows::UI::Xaml::Media::ICacheMode;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ICacheMode<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ICacheModeFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::ICacheModeFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ICacheModeFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ICompositeTransform>
{
    using abi = ABI::Windows::UI::Xaml::Media::ICompositeTransform;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ICompositeTransform<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ICompositeTransformStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::ICompositeTransformStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ICompositeTransformStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ICompositionTarget>
{
    using abi = ABI::Windows::UI::Xaml::Media::ICompositionTarget;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ICompositionTarget<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ICompositionTargetStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::ICompositionTargetStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ICompositionTargetStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IEllipseGeometry>
{
    using abi = ABI::Windows::UI::Xaml::Media::IEllipseGeometry;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IEllipseGeometry<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IEllipseGeometryStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IEllipseGeometryStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IEllipseGeometryStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IFontFamily>
{
    using abi = ABI::Windows::UI::Xaml::Media::IFontFamily;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IFontFamily<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IFontFamilyFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::IFontFamilyFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IFontFamilyFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IFontFamilyStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Media::IFontFamilyStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IFontFamilyStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IGeneralTransform>
{
    using abi = ABI::Windows::UI::Xaml::Media::IGeneralTransform;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IGeneralTransform<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IGeneralTransformFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::IGeneralTransformFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IGeneralTransformFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IGeneralTransformOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Media::IGeneralTransformOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IGeneralTransformOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IGeometry>
{
    using abi = ABI::Windows::UI::Xaml::Media::IGeometry;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IGeometry<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IGeometryFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::IGeometryFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IGeometryFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IGeometryGroup>
{
    using abi = ABI::Windows::UI::Xaml::Media::IGeometryGroup;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IGeometryGroup<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IGeometryGroupStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IGeometryGroupStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IGeometryGroupStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IGeometryStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IGeometryStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IGeometryStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IGradientBrush>
{
    using abi = ABI::Windows::UI::Xaml::Media::IGradientBrush;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IGradientBrush<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IGradientBrushFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::IGradientBrushFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IGradientBrushFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IGradientBrushStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IGradientBrushStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IGradientBrushStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IGradientStop>
{
    using abi = ABI::Windows::UI::Xaml::Media::IGradientStop;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IGradientStop<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IGradientStopStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IGradientStopStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IGradientStopStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IImageBrush>
{
    using abi = ABI::Windows::UI::Xaml::Media::IImageBrush;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IImageBrush<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IImageBrushStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IImageBrushStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IImageBrushStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IImageSource>
{
    using abi = ABI::Windows::UI::Xaml::Media::IImageSource;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IImageSource<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IImageSourceFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::IImageSourceFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IImageSourceFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ILineGeometry>
{
    using abi = ABI::Windows::UI::Xaml::Media::ILineGeometry;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ILineGeometry<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ILineGeometryStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::ILineGeometryStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ILineGeometryStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ILineSegment>
{
    using abi = ABI::Windows::UI::Xaml::Media::ILineSegment;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ILineSegment<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ILineSegmentStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::ILineSegmentStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ILineSegmentStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ILinearGradientBrush>
{
    using abi = ABI::Windows::UI::Xaml::Media::ILinearGradientBrush;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ILinearGradientBrush<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ILinearGradientBrushFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::ILinearGradientBrushFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ILinearGradientBrushFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ILinearGradientBrushStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::ILinearGradientBrushStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ILinearGradientBrushStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IMatrix3DProjection>
{
    using abi = ABI::Windows::UI::Xaml::Media::IMatrix3DProjection;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IMatrix3DProjection<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IMatrix3DProjectionStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IMatrix3DProjectionStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IMatrix3DProjectionStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IMatrixHelper>
{
    using abi = ABI::Windows::UI::Xaml::Media::IMatrixHelper;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IMatrixHelper<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IMatrixHelperStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IMatrixHelperStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IMatrixHelperStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IMatrixTransform>
{
    using abi = ABI::Windows::UI::Xaml::Media::IMatrixTransform;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IMatrixTransform<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IMatrixTransformStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IMatrixTransformStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IMatrixTransformStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IMediaTransportControlsThumbnailRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Media::IMediaTransportControlsThumbnailRequestedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IMediaTransportControlsThumbnailRequestedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IPartialMediaFailureDetectedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Media::IPartialMediaFailureDetectedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IPartialMediaFailureDetectedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IPartialMediaFailureDetectedEventArgs2>
{
    using abi = ABI::Windows::UI::Xaml::Media::IPartialMediaFailureDetectedEventArgs2;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IPartialMediaFailureDetectedEventArgs2<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IPathFigure>
{
    using abi = ABI::Windows::UI::Xaml::Media::IPathFigure;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IPathFigure<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IPathFigureStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IPathFigureStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IPathFigureStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IPathGeometry>
{
    using abi = ABI::Windows::UI::Xaml::Media::IPathGeometry;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IPathGeometry<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IPathGeometryStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IPathGeometryStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IPathGeometryStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IPathSegment>
{
    using abi = ABI::Windows::UI::Xaml::Media::IPathSegment;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IPathSegment<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IPathSegmentFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::IPathSegmentFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IPathSegmentFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IPlaneProjection>
{
    using abi = ABI::Windows::UI::Xaml::Media::IPlaneProjection;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IPlaneProjection<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IPlaneProjectionStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IPlaneProjectionStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IPlaneProjectionStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IPolyBezierSegment>
{
    using abi = ABI::Windows::UI::Xaml::Media::IPolyBezierSegment;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IPolyBezierSegment<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IPolyBezierSegmentStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IPolyBezierSegmentStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IPolyBezierSegmentStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IPolyLineSegment>
{
    using abi = ABI::Windows::UI::Xaml::Media::IPolyLineSegment;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IPolyLineSegment<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IPolyLineSegmentStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IPolyLineSegmentStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IPolyLineSegmentStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IPolyQuadraticBezierSegment>
{
    using abi = ABI::Windows::UI::Xaml::Media::IPolyQuadraticBezierSegment;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IPolyQuadraticBezierSegment<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IPolyQuadraticBezierSegmentStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IPolyQuadraticBezierSegmentStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IPolyQuadraticBezierSegmentStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IProjection>
{
    using abi = ABI::Windows::UI::Xaml::Media::IProjection;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IProjection<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IProjectionFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::IProjectionFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IProjectionFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IQuadraticBezierSegment>
{
    using abi = ABI::Windows::UI::Xaml::Media::IQuadraticBezierSegment;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IQuadraticBezierSegment<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IQuadraticBezierSegmentStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IQuadraticBezierSegmentStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IQuadraticBezierSegmentStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IRateChangedRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Media::IRateChangedRoutedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IRateChangedRoutedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IRectangleGeometry>
{
    using abi = ABI::Windows::UI::Xaml::Media::IRectangleGeometry;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IRectangleGeometry<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IRectangleGeometryStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IRectangleGeometryStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IRectangleGeometryStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IRenderingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Media::IRenderingEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IRenderingEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IRotateTransform>
{
    using abi = ABI::Windows::UI::Xaml::Media::IRotateTransform;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IRotateTransform<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IRotateTransformStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IRotateTransformStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IRotateTransformStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IScaleTransform>
{
    using abi = ABI::Windows::UI::Xaml::Media::IScaleTransform;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IScaleTransform<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IScaleTransformStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IScaleTransformStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IScaleTransformStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ISkewTransform>
{
    using abi = ABI::Windows::UI::Xaml::Media::ISkewTransform;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ISkewTransform<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ISkewTransformStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::ISkewTransformStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ISkewTransformStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ISolidColorBrush>
{
    using abi = ABI::Windows::UI::Xaml::Media::ISolidColorBrush;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ISolidColorBrush<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ISolidColorBrushFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::ISolidColorBrushFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ISolidColorBrushFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ISolidColorBrushStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::ISolidColorBrushStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ISolidColorBrushStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ITileBrush>
{
    using abi = ABI::Windows::UI::Xaml::Media::ITileBrush;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ITileBrush<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ITileBrushFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::ITileBrushFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ITileBrushFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ITileBrushStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::ITileBrushStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ITileBrushStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ITimelineMarker>
{
    using abi = ABI::Windows::UI::Xaml::Media::ITimelineMarker;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ITimelineMarker<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ITimelineMarkerRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Media::ITimelineMarkerRoutedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ITimelineMarkerRoutedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ITimelineMarkerStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::ITimelineMarkerStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ITimelineMarkerStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ITransform>
{
    using abi = ABI::Windows::UI::Xaml::Media::ITransform;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ITransform<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ITransformFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::ITransformFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ITransformFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ITransformGroup>
{
    using abi = ABI::Windows::UI::Xaml::Media::ITransformGroup;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ITransformGroup<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ITransformGroupStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::ITransformGroupStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ITransformGroupStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ITranslateTransform>
{
    using abi = ABI::Windows::UI::Xaml::Media::ITranslateTransform;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ITranslateTransform<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::ITranslateTransformStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::ITranslateTransformStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_ITranslateTransformStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IVisualTreeHelper>
{
    using abi = ABI::Windows::UI::Xaml::Media::IVisualTreeHelper;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IVisualTreeHelper<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IVisualTreeHelperStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::IVisualTreeHelperStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IVisualTreeHelperStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::IVisualTreeHelperStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Media::IVisualTreeHelperStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Media::impl_IVisualTreeHelperStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::RateChangedRoutedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Media::RateChangedRoutedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Media::TimelineMarkerRoutedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Media::TimelineMarkerRoutedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Media::ArcSegment>
{
    using abi = ABI::Windows::UI::Xaml::Media::ArcSegment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.ArcSegment"; }
};

template <> struct traits<Windows::UI::Xaml::Media::BezierSegment>
{
    using abi = ABI::Windows::UI::Xaml::Media::BezierSegment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.BezierSegment"; }
};

template <> struct traits<Windows::UI::Xaml::Media::BitmapCache>
{
    using abi = ABI::Windows::UI::Xaml::Media::BitmapCache;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.BitmapCache"; }
};

template <> struct traits<Windows::UI::Xaml::Media::Brush>
{
    using abi = ABI::Windows::UI::Xaml::Media::Brush;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.Brush"; }
};

template <> struct traits<Windows::UI::Xaml::Media::BrushCollection>
{
    using abi = ABI::Windows::UI::Xaml::Media::BrushCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.BrushCollection"; }
};

template <> struct traits<Windows::UI::Xaml::Media::CacheMode>
{
    using abi = ABI::Windows::UI::Xaml::Media::CacheMode;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.CacheMode"; }
};

template <> struct traits<Windows::UI::Xaml::Media::CompositeTransform>
{
    using abi = ABI::Windows::UI::Xaml::Media::CompositeTransform;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.CompositeTransform"; }
};

template <> struct traits<Windows::UI::Xaml::Media::CompositionTarget>
{
    using abi = ABI::Windows::UI::Xaml::Media::CompositionTarget;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.CompositionTarget"; }
};

template <> struct traits<Windows::UI::Xaml::Media::DoubleCollection>
{
    using abi = ABI::Windows::UI::Xaml::Media::DoubleCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.DoubleCollection"; }
};

template <> struct traits<Windows::UI::Xaml::Media::EllipseGeometry>
{
    using abi = ABI::Windows::UI::Xaml::Media::EllipseGeometry;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.EllipseGeometry"; }
};

template <> struct traits<Windows::UI::Xaml::Media::FontFamily>
{
    using abi = ABI::Windows::UI::Xaml::Media::FontFamily;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.FontFamily"; }
};

template <> struct traits<Windows::UI::Xaml::Media::GeneralTransform>
{
    using abi = ABI::Windows::UI::Xaml::Media::GeneralTransform;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.GeneralTransform"; }
};

template <> struct traits<Windows::UI::Xaml::Media::Geometry>
{
    using abi = ABI::Windows::UI::Xaml::Media::Geometry;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.Geometry"; }
};

template <> struct traits<Windows::UI::Xaml::Media::GeometryCollection>
{
    using abi = ABI::Windows::UI::Xaml::Media::GeometryCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.GeometryCollection"; }
};

template <> struct traits<Windows::UI::Xaml::Media::GeometryGroup>
{
    using abi = ABI::Windows::UI::Xaml::Media::GeometryGroup;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.GeometryGroup"; }
};

template <> struct traits<Windows::UI::Xaml::Media::GradientBrush>
{
    using abi = ABI::Windows::UI::Xaml::Media::GradientBrush;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.GradientBrush"; }
};

template <> struct traits<Windows::UI::Xaml::Media::GradientStop>
{
    using abi = ABI::Windows::UI::Xaml::Media::GradientStop;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.GradientStop"; }
};

template <> struct traits<Windows::UI::Xaml::Media::GradientStopCollection>
{
    using abi = ABI::Windows::UI::Xaml::Media::GradientStopCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.GradientStopCollection"; }
};

template <> struct traits<Windows::UI::Xaml::Media::ImageBrush>
{
    using abi = ABI::Windows::UI::Xaml::Media::ImageBrush;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.ImageBrush"; }
};

template <> struct traits<Windows::UI::Xaml::Media::ImageSource>
{
    using abi = ABI::Windows::UI::Xaml::Media::ImageSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.ImageSource"; }
};

template <> struct traits<Windows::UI::Xaml::Media::LineGeometry>
{
    using abi = ABI::Windows::UI::Xaml::Media::LineGeometry;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.LineGeometry"; }
};

template <> struct traits<Windows::UI::Xaml::Media::LineSegment>
{
    using abi = ABI::Windows::UI::Xaml::Media::LineSegment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.LineSegment"; }
};

template <> struct traits<Windows::UI::Xaml::Media::LinearGradientBrush>
{
    using abi = ABI::Windows::UI::Xaml::Media::LinearGradientBrush;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.LinearGradientBrush"; }
};

template <> struct traits<Windows::UI::Xaml::Media::Matrix3DProjection>
{
    using abi = ABI::Windows::UI::Xaml::Media::Matrix3DProjection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.Matrix3DProjection"; }
};

template <> struct traits<Windows::UI::Xaml::Media::MatrixHelper>
{
    using abi = ABI::Windows::UI::Xaml::Media::MatrixHelper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.MatrixHelper"; }
};

template <> struct traits<Windows::UI::Xaml::Media::MatrixTransform>
{
    using abi = ABI::Windows::UI::Xaml::Media::MatrixTransform;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.MatrixTransform"; }
};

template <> struct traits<Windows::UI::Xaml::Media::MediaTransportControlsThumbnailRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Media::MediaTransportControlsThumbnailRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.MediaTransportControlsThumbnailRequestedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Media::PartialMediaFailureDetectedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Media::PartialMediaFailureDetectedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.PartialMediaFailureDetectedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Media::PathFigure>
{
    using abi = ABI::Windows::UI::Xaml::Media::PathFigure;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.PathFigure"; }
};

template <> struct traits<Windows::UI::Xaml::Media::PathFigureCollection>
{
    using abi = ABI::Windows::UI::Xaml::Media::PathFigureCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.PathFigureCollection"; }
};

template <> struct traits<Windows::UI::Xaml::Media::PathGeometry>
{
    using abi = ABI::Windows::UI::Xaml::Media::PathGeometry;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.PathGeometry"; }
};

template <> struct traits<Windows::UI::Xaml::Media::PathSegment>
{
    using abi = ABI::Windows::UI::Xaml::Media::PathSegment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.PathSegment"; }
};

template <> struct traits<Windows::UI::Xaml::Media::PathSegmentCollection>
{
    using abi = ABI::Windows::UI::Xaml::Media::PathSegmentCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.PathSegmentCollection"; }
};

template <> struct traits<Windows::UI::Xaml::Media::PlaneProjection>
{
    using abi = ABI::Windows::UI::Xaml::Media::PlaneProjection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.PlaneProjection"; }
};

template <> struct traits<Windows::UI::Xaml::Media::PointCollection>
{
    using abi = ABI::Windows::UI::Xaml::Media::PointCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.PointCollection"; }
};

template <> struct traits<Windows::UI::Xaml::Media::PolyBezierSegment>
{
    using abi = ABI::Windows::UI::Xaml::Media::PolyBezierSegment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.PolyBezierSegment"; }
};

template <> struct traits<Windows::UI::Xaml::Media::PolyLineSegment>
{
    using abi = ABI::Windows::UI::Xaml::Media::PolyLineSegment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.PolyLineSegment"; }
};

template <> struct traits<Windows::UI::Xaml::Media::PolyQuadraticBezierSegment>
{
    using abi = ABI::Windows::UI::Xaml::Media::PolyQuadraticBezierSegment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.PolyQuadraticBezierSegment"; }
};

template <> struct traits<Windows::UI::Xaml::Media::Projection>
{
    using abi = ABI::Windows::UI::Xaml::Media::Projection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.Projection"; }
};

template <> struct traits<Windows::UI::Xaml::Media::QuadraticBezierSegment>
{
    using abi = ABI::Windows::UI::Xaml::Media::QuadraticBezierSegment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.QuadraticBezierSegment"; }
};

template <> struct traits<Windows::UI::Xaml::Media::RateChangedRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Media::RateChangedRoutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.RateChangedRoutedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Media::RectangleGeometry>
{
    using abi = ABI::Windows::UI::Xaml::Media::RectangleGeometry;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.RectangleGeometry"; }
};

template <> struct traits<Windows::UI::Xaml::Media::RenderingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Media::RenderingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.RenderingEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Media::RotateTransform>
{
    using abi = ABI::Windows::UI::Xaml::Media::RotateTransform;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.RotateTransform"; }
};

template <> struct traits<Windows::UI::Xaml::Media::ScaleTransform>
{
    using abi = ABI::Windows::UI::Xaml::Media::ScaleTransform;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.ScaleTransform"; }
};

template <> struct traits<Windows::UI::Xaml::Media::SkewTransform>
{
    using abi = ABI::Windows::UI::Xaml::Media::SkewTransform;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.SkewTransform"; }
};

template <> struct traits<Windows::UI::Xaml::Media::SolidColorBrush>
{
    using abi = ABI::Windows::UI::Xaml::Media::SolidColorBrush;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.SolidColorBrush"; }
};

template <> struct traits<Windows::UI::Xaml::Media::TileBrush>
{
    using abi = ABI::Windows::UI::Xaml::Media::TileBrush;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.TileBrush"; }
};

template <> struct traits<Windows::UI::Xaml::Media::TimelineMarker>
{
    using abi = ABI::Windows::UI::Xaml::Media::TimelineMarker;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.TimelineMarker"; }
};

template <> struct traits<Windows::UI::Xaml::Media::TimelineMarkerCollection>
{
    using abi = ABI::Windows::UI::Xaml::Media::TimelineMarkerCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.TimelineMarkerCollection"; }
};

template <> struct traits<Windows::UI::Xaml::Media::TimelineMarkerRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Media::TimelineMarkerRoutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.TimelineMarkerRoutedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Media::Transform>
{
    using abi = ABI::Windows::UI::Xaml::Media::Transform;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.Transform"; }
};

template <> struct traits<Windows::UI::Xaml::Media::TransformCollection>
{
    using abi = ABI::Windows::UI::Xaml::Media::TransformCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.TransformCollection"; }
};

template <> struct traits<Windows::UI::Xaml::Media::TransformGroup>
{
    using abi = ABI::Windows::UI::Xaml::Media::TransformGroup;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.TransformGroup"; }
};

template <> struct traits<Windows::UI::Xaml::Media::TranslateTransform>
{
    using abi = ABI::Windows::UI::Xaml::Media::TranslateTransform;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.TranslateTransform"; }
};

template <> struct traits<Windows::UI::Xaml::Media::VisualTreeHelper>
{
    using abi = ABI::Windows::UI::Xaml::Media::VisualTreeHelper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.VisualTreeHelper"; }
};

}

}
