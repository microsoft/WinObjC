//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// WindowsUIInputInking.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Input.Inking.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIInputInking.h"
#include "WindowsUIInputInking_priv.h"

@implementation WUIIIInkPresenterStencil

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkPresenterStencil> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUIIInkPresenterStencilKind)kind {
    ABI::Windows::UI::Input::Inking::InkPresenterStencilKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WUIIInkPresenterStencilKind)unmarshalledReturn;
}

- (BOOL)isVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsVisible((boolean)value));
}

- (WUColor*)backgroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackgroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setBackgroundColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->put_BackgroundColor(*[value internalStruct]));
}

- (WUColor*)foregroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->get_ForegroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setForegroundColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->put_ForegroundColor(*[value internalStruct]));
}

- (WFNMatrix3x2*)transform {
    ABI::Windows::Foundation::Numerics::Matrix3x2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->get_Transform(&unmarshalledReturn));
    return WFNMatrix3x2_create(unmarshalledReturn);
}

- (void)setTransform:(WFNMatrix3x2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->put_Transform(*[value internalStruct]));
}

@end

@implementation WUIIIInkPresenterRulerFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkPresenterRulerFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUIIInkPresenterRuler*)create:(WUIIInkPresenter*)inkPresenter {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkPresenterRuler> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterRulerFactory>(self);
    THROW_NS_IF_FAILED(_comInst->Create(_getRtInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(inkPresenter).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkPresenterRuler>(unmarshalledReturn.Get());
}

@end

@implementation WUIIIInkPointFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkPointFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUIIInkPoint*)createInkPoint:(WFPoint*)position pressure:(float)pressure {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkPoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPointFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateInkPoint(*[position internalStruct], pressure, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkPoint>(unmarshalledReturn.Get());
}

@end

@implementation WUIIIInkStrokeContainer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkStrokeContainer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFRect*)boundingRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->get_BoundingRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)addStroke:(WUIIInkStroke*)stroke {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->AddStroke(_getRtInterface<ABI::Windows::UI::Input::Inking::IInkStroke>(stroke).Get()));
}

- (WFRect*)deleteSelected {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteSelected(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFRect*)moveSelected:(WFPoint*)translation {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->MoveSelected(*[translation internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFRect*)selectWithPolyLine:(id<NSFastEnumeration> /* WFPoint* */)polyline {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->SelectWithPolyLine(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Point>::type>*>(
            ConvertToIterable<WFPoint, ABI::Windows::Foundation::Point>(polyline).Get()),
        &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFRect*)selectWithLine:(WFPoint*)from to:(WFPoint*)to {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->SelectWithLine(*[from internalStruct], *[to internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)copySelectedToClipboard {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->CopySelectedToClipboard());
}

- (WFRect*)pasteFromClipboard:(WFPoint*)position {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->PasteFromClipboard(*[position internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (BOOL)canPasteFromClipboard {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->CanPasteFromClipboard(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

// Failed to generate member LoadAsync (Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<UInt64>)
- (void)saveAsync:(RTObject<WSSIOutputStream>*)outputStream
          success:(void (^)(unsigned int))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(
        _comInst->SaveAsync(_getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(outputStream).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<unsigned int, unsigned int>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>* op, unsigned int status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<unsigned int, unsigned int>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    unsigned int result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });
    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)updateRecognitionResults:(NSArray* /* WUIIInkRecognitionResult* */)recognitionResults {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateRecognitionResults(
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Input::Inking::InkRecognitionResult*,
                                                              ABI::Windows::UI::Input::Inking::IInkRecognitionResult*>>::type>*>(
            ConvertToVectorView<WUIIInkRecognitionResult,
                                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Input::Inking::InkRecognitionResult*,
                                                                                  ABI::Windows::UI::Input::Inking::IInkRecognitionResult*>>(
                recognitionResults)
                .Get())));
}

- (NSArray* /* WUIIInkStroke* */)getStrokes {
    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkStroke*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->GetStrokes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUIIInkStroke_create(unmarshalledReturn.Get());
}

- (NSArray* /* WUIIInkRecognitionResult* */)getRecognitionResults {
    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->GetRecognitionResults(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUIIInkRecognitionResult_create(unmarshalledReturn.Get());
}

@end

@implementation WUIIIInkRecognizerContainer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkRecognizerContainer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setDefaultRecognizer:(WUIIInkRecognizer*)recognizer {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkRecognizerContainer>(self);
    THROW_NS_IF_FAILED(_comInst->SetDefaultRecognizer(_getRtInterface<ABI::Windows::UI::Input::Inking::IInkRecognizer>(recognizer).Get()));
}

- (void)recognizeAsync:(WUIIInkStrokeContainer*)strokeCollection
     recognitionTarget:(WUIIInkRecognitionTarget)recognitionTarget
               success:(void (^)(NSArray* /* WUIIInkRecognitionResult* */))success
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkRecognizerContainer>(self);
    THROW_NS_IF_FAILED(
        _comInst->RecognizeAsync(_getRtInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(strokeCollection).Get(),
                                 (ABI::Windows::UI::Input::Inking::InkRecognitionTarget)recognitionTarget,
                                 &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WUIIInkRecognitionResult_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (NSArray* /* WUIIInkRecognizer* */)getRecognizers {
    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognizer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkRecognizerContainer>(self);
    THROW_NS_IF_FAILED(_comInst->GetRecognizers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUIIInkRecognizer_create(unmarshalledReturn.Get());
}

@end

@implementation WUIIInkUnprocessedInput

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addPointerEnteredEvent:(void (^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerEntered(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_InkUnprocessedInput_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerEnteredEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerEntered(cookie));
}

- (EventRegistrationToken)addPointerHoveredEvent:(void (^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerHovered(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_InkUnprocessedInput_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerHoveredEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerHovered(cookie));
}

- (EventRegistrationToken)addPointerExitedEvent:(void (^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerExited(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_InkUnprocessedInput_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerExitedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerExited(cookie));
}

- (EventRegistrationToken)addPointerPressedEvent:(void (^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerPressed(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_InkUnprocessedInput_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerPressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerPressed(cookie));
}

- (EventRegistrationToken)addPointerMovedEvent:(void (^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerMoved(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_InkUnprocessedInput_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerMovedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerMoved(cookie));
}

- (EventRegistrationToken)addPointerReleasedEvent:(void (^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerReleased(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_InkUnprocessedInput_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerReleasedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerReleased(cookie));
}

- (EventRegistrationToken)addPointerLostEvent:(void (^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerLost(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_InkUnprocessedInput_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerLostEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerLost(cookie));
}

- (WUIIInkPresenter*)inkPresenter {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkPresenter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput>(self);
    THROW_NS_IF_FAILED(_comInst->get_InkPresenter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkPresenter>(unmarshalledReturn.Get());
}

@end

@implementation WUIIInkStrokeInput

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkStrokeInput> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addStrokeStartedEvent:(void (^)(WUIIInkStrokeInput*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeInput>(self);
    THROW_NS_IF_FAILED(_comInst->add_StrokeStarted(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_InkStrokeInput_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStrokeStartedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeInput>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StrokeStarted(cookie));
}

- (EventRegistrationToken)addStrokeContinuedEvent:(void (^)(WUIIInkStrokeInput*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeInput>(self);
    THROW_NS_IF_FAILED(_comInst->add_StrokeContinued(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_InkStrokeInput_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStrokeContinuedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeInput>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StrokeContinued(cookie));
}

- (EventRegistrationToken)addStrokeEndedEvent:(void (^)(WUIIInkStrokeInput*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeInput>(self);
    THROW_NS_IF_FAILED(_comInst->add_StrokeEnded(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_InkStrokeInput_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStrokeEndedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeInput>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StrokeEnded(cookie));
}

- (EventRegistrationToken)addStrokeCanceledEvent:(void (^)(WUIIInkStrokeInput*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeInput>(self);
    THROW_NS_IF_FAILED(_comInst->add_StrokeCanceled(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_InkStrokeInput_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStrokeCanceledEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeInput>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StrokeCanceled(cookie));
}

- (WUIIInkPresenter*)inkPresenter {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkPresenter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeInput>(self);
    THROW_NS_IF_FAILED(_comInst->get_InkPresenter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkPresenter>(unmarshalledReturn.Get());
}

@end

@implementation WUIIInkInputProcessingConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkInputProcessingConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUIIInkInputProcessingMode)mode {
    ABI::Windows::UI::Input::Inking::InkInputProcessingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkInputProcessingConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WUIIInkInputProcessingMode)unmarshalledReturn;
}

- (void)setMode:(WUIIInkInputProcessingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkInputProcessingConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mode((ABI::Windows::UI::Input::Inking::InkInputProcessingMode)value));
}

- (WUIIInkInputRightDragAction)rightDragAction {
    ABI::Windows::UI::Input::Inking::InkInputRightDragAction unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkInputProcessingConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_RightDragAction(&unmarshalledReturn));
    return (WUIIInkInputRightDragAction)unmarshalledReturn;
}

- (void)setRightDragAction:(WUIIInkInputRightDragAction)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkInputProcessingConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_RightDragAction((ABI::Windows::UI::Input::Inking::InkInputRightDragAction)value));
}

@end

@implementation WUIIInkSynchronizer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkSynchronizer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WUIIInkStroke* */)beginDry {
    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkStroke*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkSynchronizer>(self);
    THROW_NS_IF_FAILED(_comInst->BeginDry(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUIIInkStroke_create(unmarshalledReturn.Get());
}

- (void)endDry {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkSynchronizer>(self);
    THROW_NS_IF_FAILED(_comInst->EndDry());
}

@end

@implementation WUIIInkPresenter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkPresenter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isInputEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInputEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsInputEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsInputEnabled((boolean)value));
}

- (WUCCoreInputDeviceTypes)inputDeviceTypes {
    ABI::Windows::UI::Core::CoreInputDeviceTypes unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputDeviceTypes(&unmarshalledReturn));
    return (WUCCoreInputDeviceTypes)unmarshalledReturn;
}

- (void)setInputDeviceTypes:(WUCCoreInputDeviceTypes)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_InputDeviceTypes((ABI::Windows::UI::Core::CoreInputDeviceTypes)value));
}

- (WUIIInkUnprocessedInput*)unprocessedInput {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkUnprocessedInput> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnprocessedInput(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkUnprocessedInput>(unmarshalledReturn.Get());
}

- (WUIIInkStrokeInput*)strokeInput {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkStrokeInput> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_StrokeInput(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkStrokeInput>(unmarshalledReturn.Get());
}

- (WUIIInkInputProcessingConfiguration*)inputProcessingConfiguration {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkInputProcessingConfiguration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputProcessingConfiguration(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkInputProcessingConfiguration>(unmarshalledReturn.Get());
}

- (WUIIInkStrokeContainer*)strokeContainer {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkStrokeContainer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_StrokeContainer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkStrokeContainer>(unmarshalledReturn.Get());
}

- (void)setStrokeContainer:(WUIIInkStrokeContainer*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_StrokeContainer(_getRtInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(value).Get()));
}

- (WUIIInkDrawingAttributes*)copyDefaultDrawingAttributes __attribute__((ns_returns_not_retained)) {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->CopyDefaultDrawingAttributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkDrawingAttributes>(unmarshalledReturn.Get());
}

- (void)updateDefaultDrawingAttributes:(WUIIInkDrawingAttributes*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(
        _comInst->UpdateDefaultDrawingAttributes(_getRtInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes>(value).Get()));
}

- (WUIIInkSynchronizer*)activateCustomDrying {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkSynchronizer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->ActivateCustomDrying(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkSynchronizer>(unmarshalledReturn.Get());
}

- (void)setPredefinedConfiguration:(WUIIInkPresenterPredefinedConfiguration)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->SetPredefinedConfiguration((ABI::Windows::UI::Input::Inking::InkPresenterPredefinedConfiguration)value));
}

- (EventRegistrationToken)addStrokesCollectedEvent:(void (^)(WUIIInkPresenter*, WUIIInkStrokesCollectedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->add_StrokesCollected(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_InkPresenter_Windows_UI_Input_Inking_InkStrokesCollectedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStrokesCollectedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StrokesCollected(cookie));
}

- (EventRegistrationToken)addStrokesErasedEvent:(void (^)(WUIIInkPresenter*, WUIIInkStrokesErasedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->add_StrokesErased(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_InkPresenter_Windows_UI_Input_Inking_InkStrokesErasedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStrokesErasedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StrokesErased(cookie));
}

@end

@implementation WUIIInkStrokesCollectedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkStrokesCollectedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WUIIInkStroke* */)strokes {
    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkStroke*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokesCollectedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Strokes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUIIInkStroke_create(unmarshalledReturn.Get());
}

@end

@implementation WUIIInkStrokesErasedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkStrokesErasedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WUIIInkStroke* */)strokes {
    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkStroke*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokesErasedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Strokes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUIIInkStroke_create(unmarshalledReturn.Get());
}

@end

@implementation WUIIInkPresenterRuler

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkPresenterRuler> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Input::Inking::IInkPresenterRulerFactory> WUIIIInkPresenterRulerFactory_inst() {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkPresenterRulerFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Input.Inking.InkPresenterRuler").Get(), &inst));
    return inst;
}

+ (WUIIInkPresenterRuler*)make:(WUIIInkPresenter*)inkPresenter {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkPresenterRuler> unmarshalledReturn;
    auto _comInst = WUIIIInkPresenterRulerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(_getRtInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(inkPresenter).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUIIInkPresenterRuler>(unmarshalledReturn.Get()) retain];
}

- (double)length {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterRuler>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLength:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterRuler>(self);
    THROW_NS_IF_FAILED(_comInst->put_Length(value));
}

- (double)width {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterRuler>(self);
    THROW_NS_IF_FAILED(_comInst->get_Width(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setWidth:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterRuler>(self);
    THROW_NS_IF_FAILED(_comInst->put_Width(value));
}

- (WUIIInkPresenterStencilKind)kind {
    ABI::Windows::UI::Input::Inking::InkPresenterStencilKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WUIIInkPresenterStencilKind)unmarshalledReturn;
}

- (BOOL)isVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsVisible((boolean)value));
}

- (WUColor*)backgroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackgroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setBackgroundColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->put_BackgroundColor(*[value internalStruct]));
}

- (WUColor*)foregroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->get_ForegroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setForegroundColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->put_ForegroundColor(*[value internalStruct]));
}

- (WFNMatrix3x2*)transform {
    ABI::Windows::Foundation::Numerics::Matrix3x2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->get_Transform(&unmarshalledReturn));
    return WFNMatrix3x2_create(unmarshalledReturn);
}

- (void)setTransform:(WFNMatrix3x2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPresenterStencil>(self);
    THROW_NS_IF_FAILED(_comInst->put_Transform(*[value internalStruct]));
}

@end

@implementation WUIIInkPoint

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkPoint> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Input::Inking::IInkPointFactory> WUIIIInkPointFactory_inst() {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkPointFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Input.Inking.InkPoint").Get(), &inst));
    return inst;
}

+ (WUIIInkPoint*)makeInkPoint:(WFPoint*)position pressure:(float)pressure {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkPoint> unmarshalledReturn;
    auto _comInst = WUIIIInkPointFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInkPoint(*[position internalStruct], pressure, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUIIInkPoint>(unmarshalledReturn.Get()) retain];
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPoint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (float)pressure {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkPoint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pressure(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUIIInkDrawingAttributesPencilProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkDrawingAttributesPencilProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)opacity {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributesPencilProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Opacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOpacity:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributesPencilProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Opacity(value));
}

@end

@implementation WUIIInkDrawingAttributes

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Input.Inking.InkDrawingAttributes").Get(), &out));
    return [_createRtProxy<WUIIInkDrawingAttributes>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Input::Inking::IInkDrawingAttributesStatics> WUIIIInkDrawingAttributesStatics_inst() {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkDrawingAttributesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Input.Inking.InkDrawingAttributes").Get(),
                                                       &inst));
    return inst;
}

+ (WUIIInkDrawingAttributes*)createForPencil {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes> unmarshalledReturn;
    auto _comInst = WUIIIInkDrawingAttributesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateForPencil(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkDrawingAttributes>(unmarshalledReturn.Get());
}

- (WUColor*)color {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes>(self);
    THROW_NS_IF_FAILED(_comInst->get_Color(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes>(self);
    THROW_NS_IF_FAILED(_comInst->put_Color(*[value internalStruct]));
}

- (WUIIPenTipShape)penTip {
    ABI::Windows::UI::Input::Inking::PenTipShape unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes>(self);
    THROW_NS_IF_FAILED(_comInst->get_PenTip(&unmarshalledReturn));
    return (WUIIPenTipShape)unmarshalledReturn;
}

- (void)setPenTip:(WUIIPenTipShape)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes>(self);
    THROW_NS_IF_FAILED(_comInst->put_PenTip((ABI::Windows::UI::Input::Inking::PenTipShape)value));
}

- (WFSize*)size {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (void)setSize:(WFSize*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes>(self);
    THROW_NS_IF_FAILED(_comInst->put_Size(*[value internalStruct]));
}

- (BOOL)ignorePressure {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes>(self);
    THROW_NS_IF_FAILED(_comInst->get_IgnorePressure(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIgnorePressure:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes>(self);
    THROW_NS_IF_FAILED(_comInst->put_IgnorePressure((boolean)value));
}

- (BOOL)fitToCurve {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes>(self);
    THROW_NS_IF_FAILED(_comInst->get_FitToCurve(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setFitToCurve:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes>(self);
    THROW_NS_IF_FAILED(_comInst->put_FitToCurve((boolean)value));
}

- (WFNMatrix3x2*)penTipTransform {
    ABI::Windows::Foundation::Numerics::Matrix3x2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PenTipTransform(&unmarshalledReturn));
    return WFNMatrix3x2_create(unmarshalledReturn);
}

- (void)setPenTipTransform:(WFNMatrix3x2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes2>(self);
    THROW_NS_IF_FAILED(_comInst->put_PenTipTransform(*[value internalStruct]));
}

- (BOOL)drawAsHighlighter {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DrawAsHighlighter(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setDrawAsHighlighter:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes2>(self);
    THROW_NS_IF_FAILED(_comInst->put_DrawAsHighlighter((boolean)value));
}

- (WUIIInkDrawingAttributesKind)kind {
    ABI::Windows::UI::Input::Inking::InkDrawingAttributesKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes3>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WUIIInkDrawingAttributesKind)unmarshalledReturn;
}

- (WUIIInkDrawingAttributesPencilProperties*)pencilProperties {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkDrawingAttributesPencilProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes3>(self);
    THROW_NS_IF_FAILED(_comInst->get_PencilProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkDrawingAttributesPencilProperties>(unmarshalledReturn.Get());
}

@end

@implementation WUIIInkStrokeRenderingSegment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkStrokeRenderingSegment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeRenderingSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WFPoint*)bezierControlPoint1 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeRenderingSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_BezierControlPoint1(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WFPoint*)bezierControlPoint2 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeRenderingSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_BezierControlPoint2(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (float)pressure {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeRenderingSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pressure(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)tiltX {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeRenderingSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_TiltX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)tiltY {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeRenderingSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_TiltY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)twist {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeRenderingSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Twist(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUIIInkStroke

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkStroke> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUIIInkDrawingAttributes*)drawingAttributes {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStroke>(self);
    THROW_NS_IF_FAILED(_comInst->get_DrawingAttributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkDrawingAttributes>(unmarshalledReturn.Get());
}

- (void)setDrawingAttributes:(WUIIInkDrawingAttributes*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStroke>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_DrawingAttributes(_getRtInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes>(value).Get()));
}

- (WFRect*)boundingRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStroke>(self);
    THROW_NS_IF_FAILED(_comInst->get_BoundingRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (BOOL)selected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStroke>(self);
    THROW_NS_IF_FAILED(_comInst->get_Selected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSelected:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStroke>(self);
    THROW_NS_IF_FAILED(_comInst->put_Selected((boolean)value));
}

- (BOOL)recognized {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStroke>(self);
    THROW_NS_IF_FAILED(_comInst->get_Recognized(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WUIIInkStrokeRenderingSegment* */)getRenderingSegments {
    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkStrokeRenderingSegment*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStroke>(self);
    THROW_NS_IF_FAILED(_comInst->GetRenderingSegments(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUIIInkStrokeRenderingSegment_create(unmarshalledReturn.Get());
}

- (WUIIInkStroke*)clone {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkStroke> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStroke>(self);
    THROW_NS_IF_FAILED(_comInst->Clone(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkStroke>(unmarshalledReturn.Get());
}

- (WFNMatrix3x2*)pointTransform {
    ABI::Windows::Foundation::Numerics::Matrix3x2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStroke2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointTransform(&unmarshalledReturn));
    return WFNMatrix3x2_create(unmarshalledReturn);
}

- (void)setPointTransform:(WFNMatrix3x2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStroke2>(self);
    THROW_NS_IF_FAILED(_comInst->put_PointTransform(*[value internalStruct]));
}

- (NSArray* /* WUIIInkPoint* */)getInkPoints {
    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkPoint*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStroke2>(self);
    THROW_NS_IF_FAILED(_comInst->GetInkPoints(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUIIInkPoint_create(unmarshalledReturn.Get());
}

@end

@implementation WUIIInkStrokeBuilder

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkStrokeBuilder> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Input.Inking.InkStrokeBuilder").Get(), &out));
    return [_createRtProxy<WUIIInkStrokeBuilder>(out.Get()) retain];
}

- (void)beginStroke:(WUIPointerPoint*)pointerPoint {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeBuilder>(self);
    THROW_NS_IF_FAILED(_comInst->BeginStroke(_getRtInterface<ABI::Windows::UI::Input::IPointerPoint>(pointerPoint).Get()));
}

- (WUIPointerPoint*)appendToStroke:(WUIPointerPoint*)pointerPoint {
    ComPtr<ABI::Windows::UI::Input::IPointerPoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeBuilder>(self);
    THROW_NS_IF_FAILED(_comInst->AppendToStroke(_getRtInterface<ABI::Windows::UI::Input::IPointerPoint>(pointerPoint).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIPointerPoint>(unmarshalledReturn.Get());
}

- (WUIIInkStroke*)endStroke:(WUIPointerPoint*)pointerPoint {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkStroke> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeBuilder>(self);
    THROW_NS_IF_FAILED(_comInst->EndStroke(_getRtInterface<ABI::Windows::UI::Input::IPointerPoint>(pointerPoint).Get(),
                                           unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkStroke>(unmarshalledReturn.Get());
}

- (WUIIInkStroke*)createStroke:(id<NSFastEnumeration> /* WFPoint* */)points {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkStroke> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeBuilder>(self);
    THROW_NS_IF_FAILED(_comInst->CreateStroke(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Point>::type>*>(
            ConvertToIterable<WFPoint, ABI::Windows::Foundation::Point>(points).Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkStroke>(unmarshalledReturn.Get());
}

- (void)setDefaultDrawingAttributes:(WUIIInkDrawingAttributes*)drawingAttributes {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeBuilder>(self);
    THROW_NS_IF_FAILED(_comInst->SetDefaultDrawingAttributes(
        _getRtInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes>(drawingAttributes).Get()));
}

- (WUIIInkStroke*)createStrokeFromInkPoints:(id<NSFastEnumeration> /* WUIIInkPoint* */)inkPoints transform:(WFNMatrix3x2*)transform {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkStroke> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeBuilder2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateStrokeFromInkPoints(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Input::Inking::InkPoint*,
                                                              ABI::Windows::UI::Input::Inking::IInkPoint*>>::type>*>(
            ConvertToIterable<WUIIInkPoint,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Input::Inking::InkPoint*,
                                                                                ABI::Windows::UI::Input::Inking::IInkPoint*>>(inkPoints)
                .Get()),
        *[transform internalStruct],
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkStroke>(unmarshalledReturn.Get());
}

@end

@implementation WUIIInkRecognitionResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkRecognitionResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFRect*)boundingRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkRecognitionResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_BoundingRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (NSArray* /* NSString * */)getTextCandidates {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkRecognitionResult>(self);
    THROW_NS_IF_FAILED(_comInst->GetTextCandidates(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSArray* /* WUIIInkStroke* */)getStrokes {
    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkStroke*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkRecognitionResult>(self);
    THROW_NS_IF_FAILED(_comInst->GetStrokes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUIIInkStroke_create(unmarshalledReturn.Get());
}

@end

@implementation WUIIInkStrokeContainer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkStrokeContainer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Input.Inking.InkStrokeContainer").Get(), &out));
    return [_createRtProxy<WUIIInkStrokeContainer>(out.Get()) retain];
}

- (WFRect*)boundingRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->get_BoundingRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)addStroke:(WUIIInkStroke*)stroke {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->AddStroke(_getRtInterface<ABI::Windows::UI::Input::Inking::IInkStroke>(stroke).Get()));
}

- (WFRect*)deleteSelected {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteSelected(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFRect*)moveSelected:(WFPoint*)translation {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->MoveSelected(*[translation internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFRect*)selectWithPolyLine:(id<NSFastEnumeration> /* WFPoint* */)polyline {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->SelectWithPolyLine(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Point>::type>*>(
            ConvertToIterable<WFPoint, ABI::Windows::Foundation::Point>(polyline).Get()),
        &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFRect*)selectWithLine:(WFPoint*)from to:(WFPoint*)to {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->SelectWithLine(*[from internalStruct], *[to internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)copySelectedToClipboard {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->CopySelectedToClipboard());
}

- (WFRect*)pasteFromClipboard:(WFPoint*)position {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->PasteFromClipboard(*[position internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (BOOL)canPasteFromClipboard {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->CanPasteFromClipboard(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

// Failed to generate member LoadAsync (Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<UInt64>)
- (void)saveAsync:(RTObject<WSSIOutputStream>*)outputStream
          success:(void (^)(unsigned int))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(
        _comInst->SaveAsync(_getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(outputStream).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<unsigned int, unsigned int>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>* op, unsigned int status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<unsigned int, unsigned int>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    unsigned int result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });
    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)updateRecognitionResults:(NSArray* /* WUIIInkRecognitionResult* */)recognitionResults {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateRecognitionResults(
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Input::Inking::InkRecognitionResult*,
                                                              ABI::Windows::UI::Input::Inking::IInkRecognitionResult*>>::type>*>(
            ConvertToVectorView<WUIIInkRecognitionResult,
                                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Input::Inking::InkRecognitionResult*,
                                                                                  ABI::Windows::UI::Input::Inking::IInkRecognitionResult*>>(
                recognitionResults)
                .Get())));
}

- (NSArray* /* WUIIInkStroke* */)getStrokes {
    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkStroke*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->GetStrokes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUIIInkStroke_create(unmarshalledReturn.Get());
}

- (NSArray* /* WUIIInkRecognitionResult* */)getRecognitionResults {
    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->GetRecognitionResults(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUIIInkRecognitionResult_create(unmarshalledReturn.Get());
}

- (void)addStrokes:(id<NSFastEnumeration> /* WUIIInkStroke* */)strokes {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer2>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddStrokes(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
                                 ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Input::Inking::InkStroke*,
                                                                                   ABI::Windows::UI::Input::Inking::IInkStroke*>>::type>*>(
            ConvertToIterable<WUIIInkStroke,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Input::Inking::InkStroke*,
                                                                                ABI::Windows::UI::Input::Inking::IInkStroke*>>(strokes)
                .Get())));
}

- (void)clear {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer2>(self);
    THROW_NS_IF_FAILED(_comInst->Clear());
}

@end

@implementation WUIIInkRecognizer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkRecognizer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUIIInkRecognizerContainer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkRecognizerContainer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Input.Inking.InkRecognizerContainer").Get(), &out));
    return [_createRtProxy<WUIIInkRecognizerContainer>(out.Get()) retain];
}

- (void)setDefaultRecognizer:(WUIIInkRecognizer*)recognizer {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkRecognizerContainer>(self);
    THROW_NS_IF_FAILED(_comInst->SetDefaultRecognizer(_getRtInterface<ABI::Windows::UI::Input::Inking::IInkRecognizer>(recognizer).Get()));
}

- (void)recognizeAsync:(WUIIInkStrokeContainer*)strokeCollection
     recognitionTarget:(WUIIInkRecognitionTarget)recognitionTarget
               success:(void (^)(NSArray* /* WUIIInkRecognitionResult* */))success
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkRecognizerContainer>(self);
    THROW_NS_IF_FAILED(
        _comInst->RecognizeAsync(_getRtInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(strokeCollection).Get(),
                                 (ABI::Windows::UI::Input::Inking::InkRecognitionTarget)recognitionTarget,
                                 &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WUIIInkRecognitionResult_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (NSArray* /* WUIIInkRecognizer* */)getRecognizers {
    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognizer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkRecognizerContainer>(self);
    THROW_NS_IF_FAILED(_comInst->GetRecognizers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUIIInkRecognizer_create(unmarshalledReturn.Get());
}

@end

@implementation WUIIInkManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Input.Inking.InkManager").Get(), &out));
    return [_createRtProxy<WUIIInkManager>(out.Get()) retain];
}

- (WUIIInkManipulationMode)mode {
    ABI::Windows::UI::Input::Inking::InkManipulationMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WUIIInkManipulationMode)unmarshalledReturn;
}

- (void)setMode:(WUIIInkManipulationMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkManager>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mode((ABI::Windows::UI::Input::Inking::InkManipulationMode)value));
}

- (void)processPointerDown:(WUIPointerPoint*)pointerPoint {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkManager>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessPointerDown(_getRtInterface<ABI::Windows::UI::Input::IPointerPoint>(pointerPoint).Get()));
}

- (RTObject*)processPointerUpdate:(WUIPointerPoint*)pointerPoint {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkManager>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessPointerUpdate(_getRtInterface<ABI::Windows::UI::Input::IPointerPoint>(pointerPoint).Get(),
                                                      unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WFRect*)processPointerUp:(WUIPointerPoint*)pointerPoint {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->ProcessPointerUp(_getRtInterface<ABI::Windows::UI::Input::IPointerPoint>(pointerPoint).Get(), &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)setDefaultDrawingAttributes:(WUIIInkDrawingAttributes*)drawingAttributes {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkManager>(self);
    THROW_NS_IF_FAILED(_comInst->SetDefaultDrawingAttributes(
        _getRtInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes>(drawingAttributes).Get()));
}

- (void)recognizeAsync2:(WUIIInkRecognitionTarget)recognitionTarget
                success:(void (^)(NSArray* /* WUIIInkRecognitionResult* */))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->RecognizeAsync2((ABI::Windows::UI::Input::Inking::InkRecognitionTarget)recognitionTarget, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WUIIInkRecognitionResult_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (WFRect*)boundingRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->get_BoundingRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)addStroke:(WUIIInkStroke*)stroke {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->AddStroke(_getRtInterface<ABI::Windows::UI::Input::Inking::IInkStroke>(stroke).Get()));
}

- (WFRect*)deleteSelected {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteSelected(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFRect*)moveSelected:(WFPoint*)translation {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->MoveSelected(*[translation internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFRect*)selectWithPolyLine:(id<NSFastEnumeration> /* WFPoint* */)polyline {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->SelectWithPolyLine(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Point>::type>*>(
            ConvertToIterable<WFPoint, ABI::Windows::Foundation::Point>(polyline).Get()),
        &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFRect*)selectWithLine:(WFPoint*)from to:(WFPoint*)to {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->SelectWithLine(*[from internalStruct], *[to internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)copySelectedToClipboard {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->CopySelectedToClipboard());
}

- (WFRect*)pasteFromClipboard:(WFPoint*)position {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->PasteFromClipboard(*[position internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (BOOL)canPasteFromClipboard {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->CanPasteFromClipboard(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

// Failed to generate member LoadAsync (Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<UInt64>)
- (void)saveAsync:(RTObject<WSSIOutputStream>*)outputStream
          success:(void (^)(unsigned int))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(
        _comInst->SaveAsync(_getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(outputStream).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<unsigned int, unsigned int>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>* op, unsigned int status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<unsigned int, unsigned int>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    unsigned int result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });
    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)updateRecognitionResults:(NSArray* /* WUIIInkRecognitionResult* */)recognitionResults {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateRecognitionResults(
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Input::Inking::InkRecognitionResult*,
                                                              ABI::Windows::UI::Input::Inking::IInkRecognitionResult*>>::type>*>(
            ConvertToVectorView<WUIIInkRecognitionResult,
                                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Input::Inking::InkRecognitionResult*,
                                                                                  ABI::Windows::UI::Input::Inking::IInkRecognitionResult*>>(
                recognitionResults)
                .Get())));
}

- (NSArray* /* WUIIInkStroke* */)getStrokes {
    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkStroke*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->GetStrokes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUIIInkStroke_create(unmarshalledReturn.Get());
}

- (NSArray* /* WUIIInkRecognitionResult* */)getRecognitionResults {
    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(self);
    THROW_NS_IF_FAILED(_comInst->GetRecognitionResults(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUIIInkRecognitionResult_create(unmarshalledReturn.Get());
}

- (void)setDefaultRecognizer:(WUIIInkRecognizer*)recognizer {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkRecognizerContainer>(self);
    THROW_NS_IF_FAILED(_comInst->SetDefaultRecognizer(_getRtInterface<ABI::Windows::UI::Input::Inking::IInkRecognizer>(recognizer).Get()));
}

- (void)recognizeAsync:(WUIIInkStrokeContainer*)strokeCollection
     recognitionTarget:(WUIIInkRecognitionTarget)recognitionTarget
               success:(void (^)(NSArray* /* WUIIInkRecognitionResult* */))success
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkRecognizerContainer>(self);
    THROW_NS_IF_FAILED(
        _comInst->RecognizeAsync(_getRtInterface<ABI::Windows::UI::Input::Inking::IInkStrokeContainer>(strokeCollection).Get(),
                                 (ABI::Windows::UI::Input::Inking::InkRecognitionTarget)recognitionTarget,
                                 &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WUIIInkRecognitionResult_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (NSArray* /* WUIIInkRecognizer* */)getRecognizers {
    ComPtr<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognizer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::IInkRecognizerContainer>(self);
    THROW_NS_IF_FAILED(_comInst->GetRecognizers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUIIInkRecognizer_create(unmarshalledReturn.Get());
}

// Failed to generate member LoadAsync (Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<UInt64>)
@end

id RTProxiedIterableNSArray_WFPoint_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Foundation::Point>,
                                                 RTIterableObj<ABI::Windows::Foundation::Point,
                                                               IIterable<ABI::Windows::Foundation::Point>,
                                                               WFPoint,
                                                               ABI::Windows::Foundation::Point,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WUIIInkPoint_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::UI::Input::Inking::InkPoint*>,
                                                 RTIterableObj<ABI::Windows::UI::Input::Inking::IInkPoint*,
                                                               IIterable<ABI::Windows::UI::Input::Inking::InkPoint*>,
                                                               WUIIInkPoint,
                                                               ABI::Windows::UI::Input::Inking::InkPoint*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WUIIInkStroke_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::UI::Input::Inking::InkStroke*>,
                                                 RTIterableObj<ABI::Windows::UI::Input::Inking::IInkStroke*,
                                                               IIterable<ABI::Windows::UI::Input::Inking::InkStroke*>,
                                                               WUIIInkStroke,
                                                               ABI::Windows::UI::Input::Inking::InkStroke*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WUIIInkPoint_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Input::Inking::InkPoint*>,
                                         RTArrayObj<ABI::Windows::UI::Input::Inking::IInkPoint*,
                                                    IVectorView<ABI::Windows::UI::Input::Inking::InkPoint*>,
                                                    WUIIInkPoint,
                                                    ABI::Windows::UI::Input::Inking::InkPoint*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WUIIInkRecognitionResult_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>,
                                         RTArrayObj<ABI::Windows::UI::Input::Inking::IInkRecognitionResult*,
                                                    IVectorView<ABI::Windows::UI::Input::Inking::InkRecognitionResult*>,
                                                    WUIIInkRecognitionResult,
                                                    ABI::Windows::UI::Input::Inking::InkRecognitionResult*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WUIIInkRecognizer_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Input::Inking::InkRecognizer*>,
                                         RTArrayObj<ABI::Windows::UI::Input::Inking::IInkRecognizer*,
                                                    IVectorView<ABI::Windows::UI::Input::Inking::InkRecognizer*>,
                                                    WUIIInkRecognizer,
                                                    ABI::Windows::UI::Input::Inking::InkRecognizer*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WUIIInkStroke_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Input::Inking::InkStroke*>,
                                         RTArrayObj<ABI::Windows::UI::Input::Inking::IInkStroke*,
                                                    IVectorView<ABI::Windows::UI::Input::Inking::InkStroke*>,
                                                    WUIIInkStroke,
                                                    ABI::Windows::UI::Input::Inking::InkStroke*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WUIIInkStrokeRenderingSegment_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Input::Inking::InkStrokeRenderingSegment*>,
                                         RTArrayObj<ABI::Windows::UI::Input::Inking::IInkStrokeRenderingSegment*,
                                                    IVectorView<ABI::Windows::UI::Input::Inking::InkStrokeRenderingSegment*>,
                                                    WUIIInkStrokeRenderingSegment,
                                                    ABI::Windows::UI::Input::Inking::InkStrokeRenderingSegment*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
