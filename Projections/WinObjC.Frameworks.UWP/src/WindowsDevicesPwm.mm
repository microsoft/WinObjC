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

// WindowsDevicesPwm.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Pwm.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesPwm.h"
#include "WindowsDevicesPwm_priv.h"

@implementation WDPPwmPin

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Pwm::IPwmPin> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPPwmController*)controller {
    ComPtr<ABI::Windows::Devices::Pwm::IPwmController> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::IPwmPin>(self);
    THROW_NS_IF_FAILED(_comInst->get_Controller(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPwmController>(unmarshalledReturn.Get());
}

- (double)getActiveDutyCyclePercentage {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::IPwmPin>(self);
    THROW_NS_IF_FAILED(_comInst->GetActiveDutyCyclePercentage(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setActiveDutyCyclePercentage:(double)dutyCyclePercentage {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::IPwmPin>(self);
    THROW_NS_IF_FAILED(_comInst->SetActiveDutyCyclePercentage(dutyCyclePercentage));
}

- (WDPPwmPulsePolarity)polarity {
    ABI::Windows::Devices::Pwm::PwmPulsePolarity unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::IPwmPin>(self);
    THROW_NS_IF_FAILED(_comInst->get_Polarity(&unmarshalledReturn));
    return (WDPPwmPulsePolarity)unmarshalledReturn;
}

- (void)setPolarity:(WDPPwmPulsePolarity)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::IPwmPin>(self);
    THROW_NS_IF_FAILED(_comInst->put_Polarity((ABI::Windows::Devices::Pwm::PwmPulsePolarity)value));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::IPwmPin>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::IPwmPin>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (BOOL)isStarted {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::IPwmPin>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStarted(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDPPwmController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Pwm::IPwmController> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Pwm::IPwmControllerStatics2> WDPIPwmControllerStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Pwm::IPwmControllerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Pwm.PwmController").Get(), &inst));
    return inst;
}

+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPPwmController*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Pwm::PwmController*>> unmarshalledReturn;
    auto _comInst = WDPIPwmControllerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Pwm::PwmController*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Pwm::PwmController*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Pwm::IPwmController> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDPPwmController>(result.Get()));
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

ComPtr<ABI::Windows::Devices::Pwm::IPwmControllerStatics> WDPIPwmControllerStatics_inst() {
    ComPtr<ABI::Windows::Devices::Pwm::IPwmControllerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Pwm.PwmController").Get(), &inst));
    return inst;
}

+ (void)getControllersAsync:(RTObject<WDPPIPwmProvider>*)provider
                    success:(void (^)(NSArray* /* WDPPwmController* */))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Pwm::PwmController*>*>> unmarshalledReturn;
    auto _comInst = WDPIPwmControllerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetControllersAsync(_getRtInterface<ABI::Windows::Devices::Pwm::Provider::IPwmProvider>(provider).Get(),
                                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Devices::Pwm::PwmController*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Pwm::PwmController*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Pwm::PwmController*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WDPPwmController_create(result.Get()));
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
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::IPwmController>(self);
    THROW_NS_IF_FAILED(_comInst->get_PinCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)actualFrequency {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::IPwmController>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActualFrequency(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)setDesiredFrequency:(double)desiredFrequency {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::IPwmController>(self);
    THROW_NS_IF_FAILED(_comInst->SetDesiredFrequency(desiredFrequency, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)minFrequency {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::IPwmController>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinFrequency(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)maxFrequency {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::IPwmController>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxFrequency(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDPPwmPin*)openPin:(int)pinNumber {
    ComPtr<ABI::Windows::Devices::Pwm::IPwmPin> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::IPwmController>(self);
    THROW_NS_IF_FAILED(_comInst->OpenPin(pinNumber, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPwmPin>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_WDPPwmController_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Pwm::PwmController*>,
                                         RTArrayObj<ABI::Windows::Devices::Pwm::IPwmController*,
                                                    IVectorView<ABI::Windows::Devices::Pwm::PwmController*>,
                                                    WDPPwmController,
                                                    ABI::Windows::Devices::Pwm::PwmController*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
