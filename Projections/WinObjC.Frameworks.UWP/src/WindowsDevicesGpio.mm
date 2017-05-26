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

// WindowsDevicesGpio.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Gpio.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesGpio.h"
#include "WindowsDevicesGpio_priv.h"

@implementation WDGGpioPinValueChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Gpio::IGpioPinValueChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDGGpioPinEdge)edge {
    ABI::Windows::Devices::Gpio::GpioPinEdge unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::IGpioPinValueChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Edge(&unmarshalledReturn));
    return (WDGGpioPinEdge)unmarshalledReturn;
}

@end

@implementation WDGGpioPin

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Gpio::IGpioPin> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addValueChangedEvent:(void (^)(WDGGpioPin*, WDGGpioPinValueChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::IGpioPin>(self);
    THROW_NS_IF_FAILED(_comInst->add_ValueChanged(
        Make<ITypedEventHandler_Windows_Devices_Gpio_GpioPin_Windows_Devices_Gpio_GpioPinValueChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeValueChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::IGpioPin>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ValueChanged(token));
}

- (WFTimeSpan*)debounceTimeout {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::IGpioPin>(self);
    THROW_NS_IF_FAILED(_comInst->get_DebounceTimeout(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setDebounceTimeout:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::IGpioPin>(self);
    THROW_NS_IF_FAILED(_comInst->put_DebounceTimeout(*[value internalStruct]));
}

- (int)pinNumber {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::IGpioPin>(self);
    THROW_NS_IF_FAILED(_comInst->get_PinNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDGGpioSharingMode)sharingMode {
    ABI::Windows::Devices::Gpio::GpioSharingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::IGpioPin>(self);
    THROW_NS_IF_FAILED(_comInst->get_SharingMode(&unmarshalledReturn));
    return (WDGGpioSharingMode)unmarshalledReturn;
}

- (BOOL)isDriveModeSupported:(WDGGpioPinDriveMode)driveMode {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::IGpioPin>(self);
    THROW_NS_IF_FAILED(_comInst->IsDriveModeSupported((ABI::Windows::Devices::Gpio::GpioPinDriveMode)driveMode, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDGGpioPinDriveMode)getDriveMode {
    ABI::Windows::Devices::Gpio::GpioPinDriveMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::IGpioPin>(self);
    THROW_NS_IF_FAILED(_comInst->GetDriveMode(&unmarshalledReturn));
    return (WDGGpioPinDriveMode)unmarshalledReturn;
}

- (void)setDriveMode:(WDGGpioPinDriveMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::IGpioPin>(self);
    THROW_NS_IF_FAILED(_comInst->SetDriveMode((ABI::Windows::Devices::Gpio::GpioPinDriveMode)value));
}

- (void)write:(WDGGpioPinValue)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::IGpioPin>(self);
    THROW_NS_IF_FAILED(_comInst->Write((ABI::Windows::Devices::Gpio::GpioPinValue)value));
}

- (WDGGpioPinValue)read {
    ABI::Windows::Devices::Gpio::GpioPinValue unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::IGpioPin>(self);
    THROW_NS_IF_FAILED(_comInst->Read(&unmarshalledReturn));
    return (WDGGpioPinValue)unmarshalledReturn;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDGGpioController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Gpio::IGpioController> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Gpio::IGpioControllerStatics> WDGIGpioControllerStatics_inst() {
    ComPtr<ABI::Windows::Devices::Gpio::IGpioControllerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Gpio.GpioController").Get(), &inst));
    return inst;
}

+ (WDGGpioController*)getDefault {
    ComPtr<ABI::Windows::Devices::Gpio::IGpioController> unmarshalledReturn;
    auto _comInst = WDGIGpioControllerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGpioController>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Devices::Gpio::IGpioControllerStatics2> WDGIGpioControllerStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Gpio::IGpioControllerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Gpio.GpioController").Get(), &inst));
    return inst;
}

+ (void)getControllersAsync:(RTObject<WDGPIGpioProvider>*)provider
                    success:(void (^)(NSArray* /* WDGGpioController* */))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Gpio::GpioController*>*>> unmarshalledReturn;
    auto _comInst = WDGIGpioControllerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetControllersAsync(_getRtInterface<ABI::Windows::Devices::Gpio::Provider::IGpioProvider>(provider).Get(),
                                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Devices::Gpio::GpioController*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Gpio::GpioController*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Gpio::GpioController*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WDGGpioController_create(result.Get()));
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

+ (void)getDefaultAsyncWithSuccess:(void (^)(WDGGpioController*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Gpio::GpioController*>> unmarshalledReturn;
    auto _comInst = WDGIGpioControllerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Gpio::GpioController*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Gpio::GpioController*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Gpio::IGpioController> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDGGpioController>(result.Get()));
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

- (int)pinCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::IGpioController>(self);
    THROW_NS_IF_FAILED(_comInst->get_PinCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDGGpioPin*)openPin:(int)pinNumber {
    ComPtr<ABI::Windows::Devices::Gpio::IGpioPin> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::IGpioController>(self);
    THROW_NS_IF_FAILED(_comInst->OpenPin(pinNumber, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGpioPin>(unmarshalledReturn.Get());
}

- (WDGGpioPin*)openPinWithSharingMode:(int)pinNumber sharingMode:(WDGGpioSharingMode)sharingMode {
    ComPtr<ABI::Windows::Devices::Gpio::IGpioPin> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::IGpioController>(self);
    THROW_NS_IF_FAILED(_comInst->OpenPinWithSharingMode(pinNumber,
                                                        (ABI::Windows::Devices::Gpio::GpioSharingMode)sharingMode,
                                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGpioPin>(unmarshalledReturn.Get());
}

- (BOOL)tryOpenPin:(int)pinNumber
       sharingMode:(WDGGpioSharingMode)sharingMode
               pin:(WDGGpioPin**)pin
        openStatus:(WDGGpioOpenStatus*)openStatus {
    ComPtr<ABI::Windows::Devices::Gpio::IGpioPin> pinOutUnmarshaled;
    ABI::Windows::Devices::Gpio::GpioOpenStatus openStatusOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::IGpioController>(self);
    THROW_NS_IF_FAILED(_comInst->TryOpenPin(pinNumber,
                                            (ABI::Windows::Devices::Gpio::GpioSharingMode)sharingMode,
                                            pinOutUnmarshaled.GetAddressOf(),
                                            &openStatusOutUnmarshaled,
                                            &unmarshalledReturn));
    *pin = _createRtProxy<WDGGpioPin>(pinOutUnmarshaled.Get());
    *openStatus = (WDGGpioOpenStatus)openStatusOutUnmarshaled;
    return (BOOL)unmarshalledReturn;
}

@end

id RTProxiedNSArray_WDGGpioController_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Gpio::GpioController*>,
                                         RTArrayObj<ABI::Windows::Devices::Gpio::IGpioController*,
                                                    IVectorView<ABI::Windows::Devices::Gpio::GpioController*>,
                                                    WDGGpioController,
                                                    ABI::Windows::Devices::Gpio::GpioController*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
