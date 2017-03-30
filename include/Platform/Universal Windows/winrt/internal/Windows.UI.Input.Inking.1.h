// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Input.Inking.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.UI.0.h"
#include "Windows.UI.Core.0.h"
#include "Windows.UI.Input.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.UI.Core.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Input::Inking {

struct __declspec(uuid("97a2176c-6774-48ad-84f0-48f5a9be74f9")) __declspec(novtable) IInkDrawingAttributes : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Color(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_Color(Windows::UI::Color value) = 0;
    virtual HRESULT __stdcall get_PenTip(winrt::Windows::UI::Input::Inking::PenTipShape * value) = 0;
    virtual HRESULT __stdcall put_PenTip(winrt::Windows::UI::Input::Inking::PenTipShape value) = 0;
    virtual HRESULT __stdcall get_Size(Windows::Foundation::Size * value) = 0;
    virtual HRESULT __stdcall put_Size(Windows::Foundation::Size value) = 0;
    virtual HRESULT __stdcall get_IgnorePressure(bool * value) = 0;
    virtual HRESULT __stdcall put_IgnorePressure(bool value) = 0;
    virtual HRESULT __stdcall get_FitToCurve(bool * value) = 0;
    virtual HRESULT __stdcall put_FitToCurve(bool value) = 0;
};

struct __declspec(uuid("7cab6508-8ec4-42fd-a5a5-e4b7d1d5316d")) __declspec(novtable) IInkDrawingAttributes2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PenTipTransform(Windows::Foundation::Numerics::float3x2 * value) = 0;
    virtual HRESULT __stdcall put_PenTipTransform(Windows::Foundation::Numerics::float3x2 value) = 0;
    virtual HRESULT __stdcall get_DrawAsHighlighter(bool * value) = 0;
    virtual HRESULT __stdcall put_DrawAsHighlighter(bool value) = 0;
};

struct __declspec(uuid("72020002-7d5b-4690-8af4-e664cbe2b74f")) __declspec(novtable) IInkDrawingAttributes3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Kind(winrt::Windows::UI::Input::Inking::InkDrawingAttributesKind * value) = 0;
    virtual HRESULT __stdcall get_PencilProperties(Windows::UI::Input::Inking::IInkDrawingAttributesPencilProperties ** value) = 0;
};

struct __declspec(uuid("4f2534cb-2d86-41bb-b0e8-e4c2a0253c52")) __declspec(novtable) IInkDrawingAttributesPencilProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Opacity(double * value) = 0;
    virtual HRESULT __stdcall put_Opacity(double value) = 0;
};

struct __declspec(uuid("f731e03f-1a65-4862-96cb-6e1665e17f6d")) __declspec(novtable) IInkDrawingAttributesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateForPencil(Windows::UI::Input::Inking::IInkDrawingAttributes ** result) = 0;
};

struct __declspec(uuid("2778d85e-33ca-4b06-a6d3-ac3945116d37")) __declspec(novtable) IInkInputProcessingConfiguration : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Mode(winrt::Windows::UI::Input::Inking::InkInputProcessingMode * value) = 0;
    virtual HRESULT __stdcall put_Mode(winrt::Windows::UI::Input::Inking::InkInputProcessingMode value) = 0;
    virtual HRESULT __stdcall get_RightDragAction(winrt::Windows::UI::Input::Inking::InkInputRightDragAction * value) = 0;
    virtual HRESULT __stdcall put_RightDragAction(winrt::Windows::UI::Input::Inking::InkInputRightDragAction value) = 0;
};

struct __declspec(uuid("4744737d-671b-4163-9c95-4e8d7a035fe1")) __declspec(novtable) IInkManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Mode(winrt::Windows::UI::Input::Inking::InkManipulationMode * value) = 0;
    virtual HRESULT __stdcall put_Mode(winrt::Windows::UI::Input::Inking::InkManipulationMode value) = 0;
    virtual HRESULT __stdcall abi_ProcessPointerDown(Windows::UI::Input::IPointerPoint * pointerPoint) = 0;
    virtual HRESULT __stdcall abi_ProcessPointerUpdate(Windows::UI::Input::IPointerPoint * pointerPoint, Windows::Foundation::IInspectable ** updateInformation) = 0;
    virtual HRESULT __stdcall abi_ProcessPointerUp(Windows::UI::Input::IPointerPoint * pointerPoint, Windows::Foundation::Rect * updateRectangle) = 0;
    virtual HRESULT __stdcall abi_SetDefaultDrawingAttributes(Windows::UI::Input::Inking::IInkDrawingAttributes * drawingAttributes) = 0;
    virtual HRESULT __stdcall abi_RecognizeAsync2(winrt::Windows::UI::Input::Inking::InkRecognitionTarget recognitionTarget, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult>> ** recognitionResults) = 0;
};

struct __declspec(uuid("9f87272b-858c-46a5-9b41-d195970459fd")) __declspec(novtable) IInkPoint : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_Pressure(float * value) = 0;
};

struct __declspec(uuid("29e5d51c-c98f-405d-9f3b-e53e31068d4d")) __declspec(novtable) IInkPointFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInkPoint(Windows::Foundation::Point position, float pressure, Windows::UI::Input::Inking::IInkPoint ** result) = 0;
};

struct __declspec(uuid("a69b70e2-887b-458f-b173-4fe4438930a3")) __declspec(novtable) IInkPresenter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsInputEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsInputEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_InputDeviceTypes(winrt::Windows::UI::Core::CoreInputDeviceTypes * value) = 0;
    virtual HRESULT __stdcall put_InputDeviceTypes(winrt::Windows::UI::Core::CoreInputDeviceTypes value) = 0;
    virtual HRESULT __stdcall get_UnprocessedInput(Windows::UI::Input::Inking::IInkUnprocessedInput ** value) = 0;
    virtual HRESULT __stdcall get_StrokeInput(Windows::UI::Input::Inking::IInkStrokeInput ** value) = 0;
    virtual HRESULT __stdcall get_InputProcessingConfiguration(Windows::UI::Input::Inking::IInkInputProcessingConfiguration ** value) = 0;
    virtual HRESULT __stdcall get_StrokeContainer(Windows::UI::Input::Inking::IInkStrokeContainer ** value) = 0;
    virtual HRESULT __stdcall put_StrokeContainer(Windows::UI::Input::Inking::IInkStrokeContainer * value) = 0;
    virtual HRESULT __stdcall abi_CopyDefaultDrawingAttributes(Windows::UI::Input::Inking::IInkDrawingAttributes ** value) = 0;
    virtual HRESULT __stdcall abi_UpdateDefaultDrawingAttributes(Windows::UI::Input::Inking::IInkDrawingAttributes * value) = 0;
    virtual HRESULT __stdcall abi_ActivateCustomDrying(Windows::UI::Input::Inking::IInkSynchronizer ** inkSynchronizer) = 0;
    virtual HRESULT __stdcall abi_SetPredefinedConfiguration(winrt::Windows::UI::Input::Inking::InkPresenterPredefinedConfiguration value) = 0;
    virtual HRESULT __stdcall add_StrokesCollected(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkPresenter, Windows::UI::Input::Inking::InkStrokesCollectedEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_StrokesCollected(event_token cookie) = 0;
    virtual HRESULT __stdcall add_StrokesErased(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkPresenter, Windows::UI::Input::Inking::InkStrokesErasedEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_StrokesErased(event_token cookie) = 0;
};

struct __declspec(uuid("6cda7d5a-dec7-4dd7-877a-2133f183d48a")) __declspec(novtable) IInkPresenterRuler : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Length(double * value) = 0;
    virtual HRESULT __stdcall put_Length(double value) = 0;
    virtual HRESULT __stdcall get_Width(double * value) = 0;
    virtual HRESULT __stdcall put_Width(double value) = 0;
};

struct __declspec(uuid("34361beb-9001-4a4b-a690-69dbaf63e501")) __declspec(novtable) IInkPresenterRulerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::UI::Input::Inking::IInkPresenter * inkPresenter, Windows::UI::Input::Inking::IInkPresenterRuler ** inkPresenterRuler) = 0;
};

struct __declspec(uuid("30d12d6d-3e06-4d02-b116-277fb5d8addc")) __declspec(novtable) IInkPresenterStencil : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Kind(winrt::Windows::UI::Input::Inking::InkPresenterStencilKind * value) = 0;
    virtual HRESULT __stdcall get_IsVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsVisible(bool value) = 0;
    virtual HRESULT __stdcall get_BackgroundColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_BackgroundColor(Windows::UI::Color value) = 0;
    virtual HRESULT __stdcall get_ForegroundColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_ForegroundColor(Windows::UI::Color value) = 0;
    virtual HRESULT __stdcall get_Transform(Windows::Foundation::Numerics::float3x2 * value) = 0;
    virtual HRESULT __stdcall put_Transform(Windows::Foundation::Numerics::float3x2 value) = 0;
};

struct __declspec(uuid("36461a94-5068-40ef-8a05-2c2fb60908a2")) __declspec(novtable) IInkRecognitionResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BoundingRect(Windows::Foundation::Rect * boundingRect) = 0;
    virtual HRESULT __stdcall abi_GetTextCandidates(Windows::Foundation::Collections::IVectorView<hstring> ** textCandidates) = 0;
    virtual HRESULT __stdcall abi_GetStrokes(Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> ** strokes) = 0;
};

struct __declspec(uuid("077ccea3-904d-442a-b151-aaca3631c43b")) __declspec(novtable) IInkRecognizer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
};

struct __declspec(uuid("a74d9a31-8047-4698-a912-f82a5085012f")) __declspec(novtable) IInkRecognizerContainer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetDefaultRecognizer(Windows::UI::Input::Inking::IInkRecognizer * recognizer) = 0;
    virtual HRESULT __stdcall abi_RecognizeAsync(Windows::UI::Input::Inking::IInkStrokeContainer * strokeCollection, winrt::Windows::UI::Input::Inking::InkRecognitionTarget recognitionTarget, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult>> ** recognitionResults) = 0;
    virtual HRESULT __stdcall abi_GetRecognizers(Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognizer> ** recognizerView) = 0;
};

struct __declspec(uuid("15144d60-cce3-4fcf-9d52-11518ab6afd4")) __declspec(novtable) IInkStroke : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DrawingAttributes(Windows::UI::Input::Inking::IInkDrawingAttributes ** value) = 0;
    virtual HRESULT __stdcall put_DrawingAttributes(Windows::UI::Input::Inking::IInkDrawingAttributes * value) = 0;
    virtual HRESULT __stdcall get_BoundingRect(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall get_Selected(bool * value) = 0;
    virtual HRESULT __stdcall put_Selected(bool value) = 0;
    virtual HRESULT __stdcall get_Recognized(bool * value) = 0;
    virtual HRESULT __stdcall abi_GetRenderingSegments(Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStrokeRenderingSegment> ** renderingSegments) = 0;
    virtual HRESULT __stdcall abi_Clone(Windows::UI::Input::Inking::IInkStroke ** clonedStroke) = 0;
};

struct __declspec(uuid("5db9e4f4-bafa-4de1-89d3-201b1ed7d89b")) __declspec(novtable) IInkStroke2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PointTransform(Windows::Foundation::Numerics::float3x2 * value) = 0;
    virtual HRESULT __stdcall put_PointTransform(Windows::Foundation::Numerics::float3x2 value) = 0;
    virtual HRESULT __stdcall abi_GetInkPoints(Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkPoint> ** inkPoints) = 0;
};

struct __declspec(uuid("82bbd1dc-1c63-41dc-9e07-4b4a70ced801")) __declspec(novtable) IInkStrokeBuilder : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_BeginStroke(Windows::UI::Input::IPointerPoint * pointerPoint) = 0;
    virtual HRESULT __stdcall abi_AppendToStroke(Windows::UI::Input::IPointerPoint * pointerPoint, Windows::UI::Input::IPointerPoint ** previousPointerPoint) = 0;
    virtual HRESULT __stdcall abi_EndStroke(Windows::UI::Input::IPointerPoint * pointerPoint, Windows::UI::Input::Inking::IInkStroke ** stroke) = 0;
    virtual HRESULT __stdcall abi_CreateStroke(Windows::Foundation::Collections::IIterable<Windows::Foundation::Point> * points, Windows::UI::Input::Inking::IInkStroke ** stroke) = 0;
    virtual HRESULT __stdcall abi_SetDefaultDrawingAttributes(Windows::UI::Input::Inking::IInkDrawingAttributes * drawingAttributes) = 0;
};

struct __declspec(uuid("bd82bc27-731f-4cbc-bbbf-6d468044f1e5")) __declspec(novtable) IInkStrokeBuilder2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateStrokeFromInkPoints(Windows::Foundation::Collections::IIterable<Windows::UI::Input::Inking::InkPoint> * inkPoints, Windows::Foundation::Numerics::float3x2 transform, Windows::UI::Input::Inking::IInkStroke ** result) = 0;
};

struct __declspec(uuid("22accbc6-faa9-4f14-b68c-f6cee670ae16")) __declspec(novtable) IInkStrokeContainer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BoundingRect(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall abi_AddStroke(Windows::UI::Input::Inking::IInkStroke * stroke) = 0;
    virtual HRESULT __stdcall abi_DeleteSelected(Windows::Foundation::Rect * invalidatedRect) = 0;
    virtual HRESULT __stdcall abi_MoveSelected(Windows::Foundation::Point translation, Windows::Foundation::Rect * invalidatedRectangle) = 0;
    virtual HRESULT __stdcall abi_SelectWithPolyLine(Windows::Foundation::Collections::IIterable<Windows::Foundation::Point> * polyline, Windows::Foundation::Rect * invalidatedRectangle) = 0;
    virtual HRESULT __stdcall abi_SelectWithLine(Windows::Foundation::Point from, Windows::Foundation::Point to, Windows::Foundation::Rect * invalidatedRectangle) = 0;
    virtual HRESULT __stdcall abi_CopySelectedToClipboard() = 0;
    virtual HRESULT __stdcall abi_PasteFromClipboard(Windows::Foundation::Point position, Windows::Foundation::Rect * invalidatedRectangle) = 0;
    virtual HRESULT __stdcall abi_CanPasteFromClipboard(bool * canPaste) = 0;
    virtual HRESULT __stdcall abi_LoadAsync(Windows::Storage::Streams::IInputStream * inputStream, Windows::Foundation::IAsyncActionWithProgress<uint64_t> ** loadAction) = 0;
    virtual HRESULT __stdcall abi_SaveAsync(Windows::Storage::Streams::IOutputStream * outputStream, Windows::Foundation::IAsyncOperationWithProgress<uint32_t, uint32_t> ** outputStreamOperation) = 0;
    virtual HRESULT __stdcall abi_UpdateRecognitionResults(Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult> * recognitionResults) = 0;
    virtual HRESULT __stdcall abi_GetStrokes(Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> ** strokeView) = 0;
    virtual HRESULT __stdcall abi_GetRecognitionResults(Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult> ** recognitionResults) = 0;
};

struct __declspec(uuid("8901d364-da36-4bcf-9e5c-d195825995b4")) __declspec(novtable) IInkStrokeContainer2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AddStrokes(Windows::Foundation::Collections::IIterable<Windows::UI::Input::Inking::InkStroke> * strokes) = 0;
    virtual HRESULT __stdcall abi_Clear() = 0;
};

struct __declspec(uuid("cf2ffe7b-5e10-43c6-a080-88f26e1dc67d")) __declspec(novtable) IInkStrokeInput : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_StrokeStarted(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_StrokeStarted(event_token cookie) = 0;
    virtual HRESULT __stdcall add_StrokeContinued(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_StrokeContinued(event_token cookie) = 0;
    virtual HRESULT __stdcall add_StrokeEnded(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_StrokeEnded(event_token cookie) = 0;
    virtual HRESULT __stdcall add_StrokeCanceled(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_StrokeCanceled(event_token cookie) = 0;
    virtual HRESULT __stdcall get_InkPresenter(Windows::UI::Input::Inking::IInkPresenter ** value) = 0;
};

struct __declspec(uuid("68510f1f-88e3-477a-a2fa-569f5f1f9bd5")) __declspec(novtable) IInkStrokeRenderingSegment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_BezierControlPoint1(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_BezierControlPoint2(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_Pressure(float * value) = 0;
    virtual HRESULT __stdcall get_TiltX(float * value) = 0;
    virtual HRESULT __stdcall get_TiltY(float * value) = 0;
    virtual HRESULT __stdcall get_Twist(float * value) = 0;
};

struct __declspec(uuid("c4f3f229-1938-495c-b4d9-6de4b08d4811")) __declspec(novtable) IInkStrokesCollectedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Strokes(Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> ** value) = 0;
};

struct __declspec(uuid("a4216a22-1503-4ebf-8ff5-2de84584a8aa")) __declspec(novtable) IInkStrokesErasedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Strokes(Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> ** value) = 0;
};

struct __declspec(uuid("9b9ea160-ae9b-45f9-8407-4b493b163661")) __declspec(novtable) IInkSynchronizer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_BeginDry(Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> ** inkStrokes) = 0;
    virtual HRESULT __stdcall abi_EndDry() = 0;
};

struct __declspec(uuid("db4445e0-8398-4921-ac3b-ab978c5ba256")) __declspec(novtable) IInkUnprocessedInput : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_PointerEntered(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerEntered(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerHovered(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerHovered(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerExited(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerExited(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerPressed(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerPressed(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerMoved(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerMoved(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerReleased(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerReleased(event_token cookie) = 0;
    virtual HRESULT __stdcall add_PointerLost(Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_PointerLost(event_token cookie) = 0;
    virtual HRESULT __stdcall get_InkPresenter(Windows::UI::Input::Inking::IInkPresenter ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Input::Inking::InkDrawingAttributes> { using default_interface = Windows::UI::Input::Inking::IInkDrawingAttributes; };
template <> struct traits<Windows::UI::Input::Inking::InkDrawingAttributesPencilProperties> { using default_interface = Windows::UI::Input::Inking::IInkDrawingAttributesPencilProperties; };
template <> struct traits<Windows::UI::Input::Inking::InkInputProcessingConfiguration> { using default_interface = Windows::UI::Input::Inking::IInkInputProcessingConfiguration; };
template <> struct traits<Windows::UI::Input::Inking::InkManager> { using default_interface = Windows::UI::Input::Inking::IInkManager; };
template <> struct traits<Windows::UI::Input::Inking::InkPoint> { using default_interface = Windows::UI::Input::Inking::IInkPoint; };
template <> struct traits<Windows::UI::Input::Inking::InkPresenter> { using default_interface = Windows::UI::Input::Inking::IInkPresenter; };
template <> struct traits<Windows::UI::Input::Inking::InkPresenterRuler> { using default_interface = Windows::UI::Input::Inking::IInkPresenterRuler; };
template <> struct traits<Windows::UI::Input::Inking::InkRecognitionResult> { using default_interface = Windows::UI::Input::Inking::IInkRecognitionResult; };
template <> struct traits<Windows::UI::Input::Inking::InkRecognizer> { using default_interface = Windows::UI::Input::Inking::IInkRecognizer; };
template <> struct traits<Windows::UI::Input::Inking::InkRecognizerContainer> { using default_interface = Windows::UI::Input::Inking::IInkRecognizerContainer; };
template <> struct traits<Windows::UI::Input::Inking::InkStroke> { using default_interface = Windows::UI::Input::Inking::IInkStroke; };
template <> struct traits<Windows::UI::Input::Inking::InkStrokeBuilder> { using default_interface = Windows::UI::Input::Inking::IInkStrokeBuilder; };
template <> struct traits<Windows::UI::Input::Inking::InkStrokeContainer> { using default_interface = Windows::UI::Input::Inking::IInkStrokeContainer; };
template <> struct traits<Windows::UI::Input::Inking::InkStrokeInput> { using default_interface = Windows::UI::Input::Inking::IInkStrokeInput; };
template <> struct traits<Windows::UI::Input::Inking::InkStrokeRenderingSegment> { using default_interface = Windows::UI::Input::Inking::IInkStrokeRenderingSegment; };
template <> struct traits<Windows::UI::Input::Inking::InkStrokesCollectedEventArgs> { using default_interface = Windows::UI::Input::Inking::IInkStrokesCollectedEventArgs; };
template <> struct traits<Windows::UI::Input::Inking::InkStrokesErasedEventArgs> { using default_interface = Windows::UI::Input::Inking::IInkStrokesErasedEventArgs; };
template <> struct traits<Windows::UI::Input::Inking::InkSynchronizer> { using default_interface = Windows::UI::Input::Inking::IInkSynchronizer; };
template <> struct traits<Windows::UI::Input::Inking::InkUnprocessedInput> { using default_interface = Windows::UI::Input::Inking::IInkUnprocessedInput; };

}

namespace Windows::UI::Input::Inking {

template <typename D>
struct WINRT_EBO impl_IInkDrawingAttributes
{
    Windows::UI::Color Color() const;
    void Color(const Windows::UI::Color & value) const;
    Windows::UI::Input::Inking::PenTipShape PenTip() const;
    void PenTip(Windows::UI::Input::Inking::PenTipShape value) const;
    Windows::Foundation::Size Size() const;
    void Size(const Windows::Foundation::Size & value) const;
    bool IgnorePressure() const;
    void IgnorePressure(bool value) const;
    bool FitToCurve() const;
    void FitToCurve(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IInkDrawingAttributes2
{
    Windows::Foundation::Numerics::float3x2 PenTipTransform() const;
    void PenTipTransform(const Windows::Foundation::Numerics::float3x2 & value) const;
    bool DrawAsHighlighter() const;
    void DrawAsHighlighter(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IInkDrawingAttributes3
{
    Windows::UI::Input::Inking::InkDrawingAttributesKind Kind() const;
    Windows::UI::Input::Inking::InkDrawingAttributesPencilProperties PencilProperties() const;
};

template <typename D>
struct WINRT_EBO impl_IInkDrawingAttributesPencilProperties
{
    double Opacity() const;
    void Opacity(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IInkDrawingAttributesStatics
{
    Windows::UI::Input::Inking::InkDrawingAttributes CreateForPencil() const;
};

template <typename D>
struct WINRT_EBO impl_IInkInputProcessingConfiguration
{
    Windows::UI::Input::Inking::InkInputProcessingMode Mode() const;
    void Mode(Windows::UI::Input::Inking::InkInputProcessingMode value) const;
    Windows::UI::Input::Inking::InkInputRightDragAction RightDragAction() const;
    void RightDragAction(Windows::UI::Input::Inking::InkInputRightDragAction value) const;
};

template <typename D>
struct WINRT_EBO impl_IInkManager
{
    Windows::UI::Input::Inking::InkManipulationMode Mode() const;
    void Mode(Windows::UI::Input::Inking::InkManipulationMode value) const;
    void ProcessPointerDown(const Windows::UI::Input::PointerPoint & pointerPoint) const;
    Windows::Foundation::IInspectable ProcessPointerUpdate(const Windows::UI::Input::PointerPoint & pointerPoint) const;
    Windows::Foundation::Rect ProcessPointerUp(const Windows::UI::Input::PointerPoint & pointerPoint) const;
    void SetDefaultDrawingAttributes(const Windows::UI::Input::Inking::InkDrawingAttributes & drawingAttributes) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult>> RecognizeAsync(Windows::UI::Input::Inking::InkRecognitionTarget recognitionTarget) const;
};

template <typename D>
struct WINRT_EBO impl_IInkPoint
{
    Windows::Foundation::Point Position() const;
    float Pressure() const;
};

template <typename D>
struct WINRT_EBO impl_IInkPointFactory
{
    Windows::UI::Input::Inking::InkPoint CreateInkPoint(const Windows::Foundation::Point & position, float pressure) const;
};

template <typename D>
struct WINRT_EBO impl_IInkPresenter
{
    bool IsInputEnabled() const;
    void IsInputEnabled(bool value) const;
    Windows::UI::Core::CoreInputDeviceTypes InputDeviceTypes() const;
    void InputDeviceTypes(Windows::UI::Core::CoreInputDeviceTypes value) const;
    Windows::UI::Input::Inking::InkUnprocessedInput UnprocessedInput() const;
    Windows::UI::Input::Inking::InkStrokeInput StrokeInput() const;
    Windows::UI::Input::Inking::InkInputProcessingConfiguration InputProcessingConfiguration() const;
    Windows::UI::Input::Inking::InkStrokeContainer StrokeContainer() const;
    void StrokeContainer(const Windows::UI::Input::Inking::InkStrokeContainer & value) const;
    Windows::UI::Input::Inking::InkDrawingAttributes CopyDefaultDrawingAttributes() const;
    void UpdateDefaultDrawingAttributes(const Windows::UI::Input::Inking::InkDrawingAttributes & value) const;
    Windows::UI::Input::Inking::InkSynchronizer ActivateCustomDrying() const;
    void SetPredefinedConfiguration(Windows::UI::Input::Inking::InkPresenterPredefinedConfiguration value) const;
    event_token StrokesCollected(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkPresenter, Windows::UI::Input::Inking::InkStrokesCollectedEventArgs> & handler) const;
    using StrokesCollected_revoker = event_revoker<IInkPresenter>;
    StrokesCollected_revoker StrokesCollected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkPresenter, Windows::UI::Input::Inking::InkStrokesCollectedEventArgs> & handler) const;
    void StrokesCollected(event_token cookie) const;
    event_token StrokesErased(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkPresenter, Windows::UI::Input::Inking::InkStrokesErasedEventArgs> & handler) const;
    using StrokesErased_revoker = event_revoker<IInkPresenter>;
    StrokesErased_revoker StrokesErased(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkPresenter, Windows::UI::Input::Inking::InkStrokesErasedEventArgs> & handler) const;
    void StrokesErased(event_token cookie) const;
};

template <typename D>
struct WINRT_EBO impl_IInkPresenterRuler
{
    double Length() const;
    void Length(double value) const;
    double Width() const;
    void Width(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IInkPresenterRulerFactory
{
    Windows::UI::Input::Inking::InkPresenterRuler Create(const Windows::UI::Input::Inking::InkPresenter & inkPresenter) const;
};

template <typename D>
struct WINRT_EBO impl_IInkPresenterStencil
{
    Windows::UI::Input::Inking::InkPresenterStencilKind Kind() const;
    bool IsVisible() const;
    void IsVisible(bool value) const;
    Windows::UI::Color BackgroundColor() const;
    void BackgroundColor(const Windows::UI::Color & value) const;
    Windows::UI::Color ForegroundColor() const;
    void ForegroundColor(const Windows::UI::Color & value) const;
    Windows::Foundation::Numerics::float3x2 Transform() const;
    void Transform(const Windows::Foundation::Numerics::float3x2 & value) const;
};

template <typename D>
struct WINRT_EBO impl_IInkRecognitionResult
{
    Windows::Foundation::Rect BoundingRect() const;
    Windows::Foundation::Collections::IVectorView<hstring> GetTextCandidates() const;
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> GetStrokes() const;
};

template <typename D>
struct WINRT_EBO impl_IInkRecognizer
{
    hstring Name() const;
};

template <typename D>
struct WINRT_EBO impl_IInkRecognizerContainer
{
    void SetDefaultRecognizer(const Windows::UI::Input::Inking::InkRecognizer & recognizer) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult>> RecognizeAsync(const Windows::UI::Input::Inking::InkStrokeContainer & strokeCollection, Windows::UI::Input::Inking::InkRecognitionTarget recognitionTarget) const;
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognizer> GetRecognizers() const;
};

template <typename D>
struct WINRT_EBO impl_IInkStroke
{
    Windows::UI::Input::Inking::InkDrawingAttributes DrawingAttributes() const;
    void DrawingAttributes(const Windows::UI::Input::Inking::InkDrawingAttributes & value) const;
    Windows::Foundation::Rect BoundingRect() const;
    bool Selected() const;
    void Selected(bool value) const;
    bool Recognized() const;
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStrokeRenderingSegment> GetRenderingSegments() const;
    Windows::UI::Input::Inking::InkStroke Clone() const;
};

template <typename D>
struct WINRT_EBO impl_IInkStroke2
{
    Windows::Foundation::Numerics::float3x2 PointTransform() const;
    void PointTransform(const Windows::Foundation::Numerics::float3x2 & value) const;
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkPoint> GetInkPoints() const;
};

template <typename D>
struct WINRT_EBO impl_IInkStrokeBuilder
{
    void BeginStroke(const Windows::UI::Input::PointerPoint & pointerPoint) const;
    Windows::UI::Input::PointerPoint AppendToStroke(const Windows::UI::Input::PointerPoint & pointerPoint) const;
    Windows::UI::Input::Inking::InkStroke EndStroke(const Windows::UI::Input::PointerPoint & pointerPoint) const;
    Windows::UI::Input::Inking::InkStroke CreateStroke(iterable<Windows::Foundation::Point> points) const;
    void SetDefaultDrawingAttributes(const Windows::UI::Input::Inking::InkDrawingAttributes & drawingAttributes) const;
};

template <typename D>
struct WINRT_EBO impl_IInkStrokeBuilder2
{
    Windows::UI::Input::Inking::InkStroke CreateStrokeFromInkPoints(iterable<Windows::UI::Input::Inking::InkPoint> inkPoints, const Windows::Foundation::Numerics::float3x2 & transform) const;
};

template <typename D>
struct WINRT_EBO impl_IInkStrokeContainer
{
    Windows::Foundation::Rect BoundingRect() const;
    void AddStroke(const Windows::UI::Input::Inking::InkStroke & stroke) const;
    Windows::Foundation::Rect DeleteSelected() const;
    Windows::Foundation::Rect MoveSelected(const Windows::Foundation::Point & translation) const;
    Windows::Foundation::Rect SelectWithPolyLine(iterable<Windows::Foundation::Point> polyline) const;
    Windows::Foundation::Rect SelectWithLine(const Windows::Foundation::Point & from, const Windows::Foundation::Point & to) const;
    void CopySelectedToClipboard() const;
    Windows::Foundation::Rect PasteFromClipboard(const Windows::Foundation::Point & position) const;
    bool CanPasteFromClipboard() const;
    Windows::Foundation::IAsyncActionWithProgress<uint64_t> LoadAsync(const Windows::Storage::Streams::IInputStream & inputStream) const;
    Windows::Foundation::IAsyncOperationWithProgress<uint32_t, uint32_t> SaveAsync(const Windows::Storage::Streams::IOutputStream & outputStream) const;
    void UpdateRecognitionResults(vector_view<Windows::UI::Input::Inking::InkRecognitionResult> recognitionResults) const;
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> GetStrokes() const;
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult> GetRecognitionResults() const;
};

template <typename D>
struct WINRT_EBO impl_IInkStrokeContainer2
{
    void AddStrokes(iterable<Windows::UI::Input::Inking::InkStroke> strokes) const;
    void Clear() const;
};

template <typename D>
struct WINRT_EBO impl_IInkStrokeInput
{
    event_token StrokeStarted(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    using StrokeStarted_revoker = event_revoker<IInkStrokeInput>;
    StrokeStarted_revoker StrokeStarted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    void StrokeStarted(event_token cookie) const;
    event_token StrokeContinued(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    using StrokeContinued_revoker = event_revoker<IInkStrokeInput>;
    StrokeContinued_revoker StrokeContinued(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    void StrokeContinued(event_token cookie) const;
    event_token StrokeEnded(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    using StrokeEnded_revoker = event_revoker<IInkStrokeInput>;
    StrokeEnded_revoker StrokeEnded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    void StrokeEnded(event_token cookie) const;
    event_token StrokeCanceled(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    using StrokeCanceled_revoker = event_revoker<IInkStrokeInput>;
    StrokeCanceled_revoker StrokeCanceled(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    void StrokeCanceled(event_token cookie) const;
    Windows::UI::Input::Inking::InkPresenter InkPresenter() const;
};

template <typename D>
struct WINRT_EBO impl_IInkStrokeRenderingSegment
{
    Windows::Foundation::Point Position() const;
    Windows::Foundation::Point BezierControlPoint1() const;
    Windows::Foundation::Point BezierControlPoint2() const;
    float Pressure() const;
    float TiltX() const;
    float TiltY() const;
    float Twist() const;
};

template <typename D>
struct WINRT_EBO impl_IInkStrokesCollectedEventArgs
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> Strokes() const;
};

template <typename D>
struct WINRT_EBO impl_IInkStrokesErasedEventArgs
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> Strokes() const;
};

template <typename D>
struct WINRT_EBO impl_IInkSynchronizer
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> BeginDry() const;
    void EndDry() const;
};

template <typename D>
struct WINRT_EBO impl_IInkUnprocessedInput
{
    event_token PointerEntered(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    using PointerEntered_revoker = event_revoker<IInkUnprocessedInput>;
    PointerEntered_revoker PointerEntered(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    void PointerEntered(event_token cookie) const;
    event_token PointerHovered(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    using PointerHovered_revoker = event_revoker<IInkUnprocessedInput>;
    PointerHovered_revoker PointerHovered(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    void PointerHovered(event_token cookie) const;
    event_token PointerExited(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    using PointerExited_revoker = event_revoker<IInkUnprocessedInput>;
    PointerExited_revoker PointerExited(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    void PointerExited(event_token cookie) const;
    event_token PointerPressed(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    using PointerPressed_revoker = event_revoker<IInkUnprocessedInput>;
    PointerPressed_revoker PointerPressed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    void PointerPressed(event_token cookie) const;
    event_token PointerMoved(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    using PointerMoved_revoker = event_revoker<IInkUnprocessedInput>;
    PointerMoved_revoker PointerMoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    void PointerMoved(event_token cookie) const;
    event_token PointerReleased(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    using PointerReleased_revoker = event_revoker<IInkUnprocessedInput>;
    PointerReleased_revoker PointerReleased(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    void PointerReleased(event_token cookie) const;
    event_token PointerLost(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    using PointerLost_revoker = event_revoker<IInkUnprocessedInput>;
    PointerLost_revoker PointerLost(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const;
    void PointerLost(event_token cookie) const;
    Windows::UI::Input::Inking::InkPresenter InkPresenter() const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Input::Inking::IInkDrawingAttributes>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkDrawingAttributes;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkDrawingAttributes<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkDrawingAttributes2>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkDrawingAttributes2;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkDrawingAttributes2<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkDrawingAttributes3>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkDrawingAttributes3;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkDrawingAttributes3<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkDrawingAttributesPencilProperties>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkDrawingAttributesPencilProperties;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkDrawingAttributesPencilProperties<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkDrawingAttributesStatics>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkDrawingAttributesStatics;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkDrawingAttributesStatics<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkInputProcessingConfiguration>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkInputProcessingConfiguration;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkInputProcessingConfiguration<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkManager>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkManager;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkManager<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkPoint>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkPoint;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkPoint<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkPointFactory>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkPointFactory;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkPointFactory<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkPresenter>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkPresenter;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkPresenter<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkPresenterRuler>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkPresenterRuler;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkPresenterRuler<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkPresenterRulerFactory>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkPresenterRulerFactory;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkPresenterRulerFactory<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkPresenterStencil>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkPresenterStencil;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkPresenterStencil<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkRecognitionResult>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkRecognitionResult;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkRecognitionResult<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkRecognizer>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkRecognizer;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkRecognizer<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkRecognizerContainer>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkRecognizerContainer;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkRecognizerContainer<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkStroke>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkStroke;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkStroke<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkStroke2>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkStroke2;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkStroke2<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkStrokeBuilder>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkStrokeBuilder;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkStrokeBuilder<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkStrokeBuilder2>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkStrokeBuilder2;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkStrokeBuilder2<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkStrokeContainer>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkStrokeContainer;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkStrokeContainer<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkStrokeContainer2>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkStrokeContainer2;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkStrokeContainer2<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkStrokeInput>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkStrokeInput;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkStrokeInput<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkStrokeRenderingSegment>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkStrokeRenderingSegment;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkStrokeRenderingSegment<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkStrokesCollectedEventArgs>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkStrokesCollectedEventArgs;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkStrokesCollectedEventArgs<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkStrokesErasedEventArgs>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkStrokesErasedEventArgs;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkStrokesErasedEventArgs<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkSynchronizer>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkSynchronizer;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkSynchronizer<D>;
};

template <> struct traits<Windows::UI::Input::Inking::IInkUnprocessedInput>
{
    using abi = ABI::Windows::UI::Input::Inking::IInkUnprocessedInput;
    template <typename D> using consume = Windows::UI::Input::Inking::impl_IInkUnprocessedInput<D>;
};

template <> struct traits<Windows::UI::Input::Inking::InkDrawingAttributes>
{
    using abi = ABI::Windows::UI::Input::Inking::InkDrawingAttributes;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkDrawingAttributes"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkDrawingAttributesPencilProperties>
{
    using abi = ABI::Windows::UI::Input::Inking::InkDrawingAttributesPencilProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkDrawingAttributesPencilProperties"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkInputProcessingConfiguration>
{
    using abi = ABI::Windows::UI::Input::Inking::InkInputProcessingConfiguration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkInputProcessingConfiguration"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkManager>
{
    using abi = ABI::Windows::UI::Input::Inking::InkManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkManager"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkPoint>
{
    using abi = ABI::Windows::UI::Input::Inking::InkPoint;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkPoint"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkPresenter>
{
    using abi = ABI::Windows::UI::Input::Inking::InkPresenter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkPresenter"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkPresenterRuler>
{
    using abi = ABI::Windows::UI::Input::Inking::InkPresenterRuler;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkPresenterRuler"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkRecognitionResult>
{
    using abi = ABI::Windows::UI::Input::Inking::InkRecognitionResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkRecognitionResult"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkRecognizer>
{
    using abi = ABI::Windows::UI::Input::Inking::InkRecognizer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkRecognizer"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkRecognizerContainer>
{
    using abi = ABI::Windows::UI::Input::Inking::InkRecognizerContainer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkRecognizerContainer"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkStroke>
{
    using abi = ABI::Windows::UI::Input::Inking::InkStroke;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkStroke"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkStrokeBuilder>
{
    using abi = ABI::Windows::UI::Input::Inking::InkStrokeBuilder;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkStrokeBuilder"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkStrokeContainer>
{
    using abi = ABI::Windows::UI::Input::Inking::InkStrokeContainer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkStrokeContainer"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkStrokeInput>
{
    using abi = ABI::Windows::UI::Input::Inking::InkStrokeInput;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkStrokeInput"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkStrokeRenderingSegment>
{
    using abi = ABI::Windows::UI::Input::Inking::InkStrokeRenderingSegment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkStrokeRenderingSegment"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkStrokesCollectedEventArgs>
{
    using abi = ABI::Windows::UI::Input::Inking::InkStrokesCollectedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkStrokesCollectedEventArgs"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkStrokesErasedEventArgs>
{
    using abi = ABI::Windows::UI::Input::Inking::InkStrokesErasedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkStrokesErasedEventArgs"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkSynchronizer>
{
    using abi = ABI::Windows::UI::Input::Inking::InkSynchronizer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkSynchronizer"; }
};

template <> struct traits<Windows::UI::Input::Inking::InkUnprocessedInput>
{
    using abi = ABI::Windows::UI::Input::Inking::InkUnprocessedInput;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Inking.InkUnprocessedInput"; }
};

}

}
