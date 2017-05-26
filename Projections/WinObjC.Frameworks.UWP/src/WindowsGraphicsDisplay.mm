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

// WindowsGraphicsDisplay.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Graphics.Display.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGraphicsDisplay.h"
#include "WindowsGraphicsDisplay_priv.h"

@implementation WGDDisplayInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Display::IDisplayInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Graphics::Display::IDisplayInformationStatics> WGDIDisplayInformationStatics_inst() {
    ComPtr<ABI::Windows::Graphics::Display::IDisplayInformationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Graphics.Display.DisplayInformation").Get(),
                                                       &inst));
    return inst;
}

+ (WGDDisplayInformation*)getForCurrentView {
    ComPtr<ABI::Windows::Graphics::Display::IDisplayInformation> unmarshalledReturn;
    auto _comInst = WGDIDisplayInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGDDisplayInformation>(unmarshalledReturn.Get());
}

+ (WGDDisplayOrientations)autoRotationPreferences {
    ABI::Windows::Graphics::Display::DisplayOrientations unmarshalledReturn;
    auto _comInst = WGDIDisplayInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AutoRotationPreferences(&unmarshalledReturn));
    return (WGDDisplayOrientations)unmarshalledReturn;
}

+ (void)setAutoRotationPreferences:(WGDDisplayOrientations)value {
    auto _comInst = WGDIDisplayInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->put_AutoRotationPreferences((ABI::Windows::Graphics::Display::DisplayOrientations)value));
}

+ (EventRegistrationToken)addDisplayContentsInvalidatedEvent:(void (^)(WGDDisplayInformation*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGDIDisplayInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_DisplayContentsInvalidated(
        Make<ITypedEventHandler_Windows_Graphics_Display_DisplayInformation_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeDisplayContentsInvalidatedEvent:(EventRegistrationToken)token {
    auto _comInst = WGDIDisplayInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_DisplayContentsInvalidated(token));
}

- (WGDDisplayOrientations)currentOrientation {
    ABI::Windows::Graphics::Display::DisplayOrientations unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentOrientation(&unmarshalledReturn));
    return (WGDDisplayOrientations)unmarshalledReturn;
}

- (WGDDisplayOrientations)nativeOrientation {
    ABI::Windows::Graphics::Display::DisplayOrientations unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_NativeOrientation(&unmarshalledReturn));
    return (WGDDisplayOrientations)unmarshalledReturn;
}

- (EventRegistrationToken)addOrientationChangedEvent:(void (^)(WGDDisplayInformation*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_OrientationChanged(Make<ITypedEventHandler_Windows_Graphics_Display_DisplayInformation_System_Object>(handler).Get(),
                                         &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOrientationChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OrientationChanged(token));
}

- (WGDResolutionScale)resolutionScale {
    ABI::Windows::Graphics::Display::ResolutionScale unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolutionScale(&unmarshalledReturn));
    return (WGDResolutionScale)unmarshalledReturn;
}

- (float)logicalDpi {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LogicalDpi(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)rawDpiX {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawDpiX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)rawDpiY {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawDpiY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addDpiChangedEvent:(void (^)(WGDDisplayInformation*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_DpiChanged(Make<ITypedEventHandler_Windows_Graphics_Display_DisplayInformation_System_Object>(handler).Get(),
                                 &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDpiChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DpiChanged(token));
}

- (BOOL)stereoEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_StereoEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addStereoEnabledChangedEvent:(void (^)(WGDDisplayInformation*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation>(self);
    THROW_NS_IF_FAILED(_comInst->add_StereoEnabledChanged(
        Make<ITypedEventHandler_Windows_Graphics_Display_DisplayInformation_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStereoEnabledChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StereoEnabledChanged(token));
}

- (void)getColorProfileAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation>(self);
    THROW_NS_IF_FAILED(_comInst->GetColorProfileAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStream>(result.Get()));
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

- (EventRegistrationToken)addColorProfileChangedEvent:(void (^)(WGDDisplayInformation*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ColorProfileChanged(Make<ITypedEventHandler_Windows_Graphics_Display_DisplayInformation_System_Object>(handler).Get(),
                                          &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeColorProfileChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ColorProfileChanged(token));
}

- (double)rawPixelsPerViewPixel {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawPixelsPerViewPixel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (id /* double */)diagonalSizeInInches {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation3>(self);
    THROW_NS_IF_FAILED(_comInst->get_DiagonalSizeInInches(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (unsigned int)screenWidthInRawPixels {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation4>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScreenWidthInRawPixels(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)screenHeightInRawPixels {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Display::IDisplayInformation4>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScreenHeightInRawPixels(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WGDDisplayProperties

ComPtr<ABI::Windows::Graphics::Display::IDisplayPropertiesStatics> WGDIDisplayPropertiesStatics_inst() {
    ComPtr<ABI::Windows::Graphics::Display::IDisplayPropertiesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Graphics.Display.DisplayProperties").Get(), &inst));
    return inst;
}

+ (WGDDisplayOrientations)currentOrientation {
    ABI::Windows::Graphics::Display::DisplayOrientations unmarshalledReturn;
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CurrentOrientation(&unmarshalledReturn));
    return (WGDDisplayOrientations)unmarshalledReturn;
}

+ (WGDDisplayOrientations)nativeOrientation {
    ABI::Windows::Graphics::Display::DisplayOrientations unmarshalledReturn;
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NativeOrientation(&unmarshalledReturn));
    return (WGDDisplayOrientations)unmarshalledReturn;
}

+ (WGDDisplayOrientations)autoRotationPreferences {
    ABI::Windows::Graphics::Display::DisplayOrientations unmarshalledReturn;
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AutoRotationPreferences(&unmarshalledReturn));
    return (WGDDisplayOrientations)unmarshalledReturn;
}

+ (void)setAutoRotationPreferences:(WGDDisplayOrientations)value {
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->put_AutoRotationPreferences((ABI::Windows::Graphics::Display::DisplayOrientations)value));
}

+ (EventRegistrationToken)addOrientationChangedEvent:(WGDDisplayPropertiesEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_OrientationChanged(Make<WGDDisplayPropertiesEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeOrientationChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_OrientationChanged(token));
}

+ (WGDResolutionScale)resolutionScale {
    ABI::Windows::Graphics::Display::ResolutionScale unmarshalledReturn;
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ResolutionScale(&unmarshalledReturn));
    return (WGDResolutionScale)unmarshalledReturn;
}

+ (float)logicalDpi {
    float unmarshalledReturn;
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LogicalDpi(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (EventRegistrationToken)addLogicalDpiChangedEvent:(WGDDisplayPropertiesEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_LogicalDpiChanged(Make<WGDDisplayPropertiesEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeLogicalDpiChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_LogicalDpiChanged(token));
}

+ (BOOL)stereoEnabled {
    boolean unmarshalledReturn;
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StereoEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (EventRegistrationToken)addStereoEnabledChangedEvent:(WGDDisplayPropertiesEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_StereoEnabledChanged(Make<WGDDisplayPropertiesEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeStereoEnabledChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_StereoEnabledChanged(token));
}

+ (void)getColorProfileAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>> unmarshalledReturn;
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetColorProfileAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStream>(result.Get()));
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

+ (EventRegistrationToken)addColorProfileChangedEvent:(WGDDisplayPropertiesEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_ColorProfileChanged(Make<WGDDisplayPropertiesEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeColorProfileChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_ColorProfileChanged(token));
}

+ (EventRegistrationToken)addDisplayContentsInvalidatedEvent:(WGDDisplayPropertiesEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_DisplayContentsInvalidated(Make<WGDDisplayPropertiesEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeDisplayContentsInvalidatedEvent:(EventRegistrationToken)token {
    auto _comInst = WGDIDisplayPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_DisplayContentsInvalidated(token));
}

@end
