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

// WindowsDevicesAdc.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Adc.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesAdc.h"
#include "WindowsDevicesAdc_priv.h"

@implementation WDAAdcChannel

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Adc::IAdcChannel> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDAAdcController*)controller {
    ComPtr<ABI::Windows::Devices::Adc::IAdcController> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::IAdcChannel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Controller(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDAAdcController>(unmarshalledReturn.Get());
}

- (int)readValue {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::IAdcChannel>(self);
    THROW_NS_IF_FAILED(_comInst->ReadValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)readRatio {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::IAdcChannel>(self);
    THROW_NS_IF_FAILED(_comInst->ReadRatio(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDAAdcController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Adc::IAdcController> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Adc::IAdcControllerStatics> WDAIAdcControllerStatics_inst() {
    ComPtr<ABI::Windows::Devices::Adc::IAdcControllerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Adc.AdcController").Get(), &inst));
    return inst;
}

+ (void)getControllersAsync:(RTObject<WDAPIAdcProvider>*)provider
                    success:(void (^)(NSArray* /* WDAAdcController* */))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Adc::AdcController*>*>> unmarshalledReturn;
    auto _comInst = WDAIAdcControllerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetControllersAsync(_getRtInterface<ABI::Windows::Devices::Adc::Provider::IAdcProvider>(provider).Get(),
                                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Devices::Adc::AdcController*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Adc::AdcController*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Adc::AdcController*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WDAAdcController_create(result.Get()));
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

ComPtr<ABI::Windows::Devices::Adc::IAdcControllerStatics2> WDAIAdcControllerStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Adc::IAdcControllerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Adc.AdcController").Get(), &inst));
    return inst;
}

+ (void)getDefaultAsyncWithSuccess:(void (^)(WDAAdcController*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Adc::AdcController*>> unmarshalledReturn;
    auto _comInst = WDAIAdcControllerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Adc::AdcController*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Adc::AdcController*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Adc::IAdcController> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDAAdcController>(result.Get()));
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

- (int)channelCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::IAdcController>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChannelCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)resolutionInBits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::IAdcController>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolutionInBits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)minValue {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::IAdcController>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)maxValue {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::IAdcController>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDAAdcChannelMode)channelMode {
    ABI::Windows::Devices::Adc::AdcChannelMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::IAdcController>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChannelMode(&unmarshalledReturn));
    return (WDAAdcChannelMode)unmarshalledReturn;
}

- (void)setChannelMode:(WDAAdcChannelMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::IAdcController>(self);
    THROW_NS_IF_FAILED(_comInst->put_ChannelMode((ABI::Windows::Devices::Adc::AdcChannelMode)value));
}

- (BOOL)isChannelModeSupported:(WDAAdcChannelMode)channelMode {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::IAdcController>(self);
    THROW_NS_IF_FAILED(_comInst->IsChannelModeSupported((ABI::Windows::Devices::Adc::AdcChannelMode)channelMode, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDAAdcChannel*)openChannel:(int)channelNumber {
    ComPtr<ABI::Windows::Devices::Adc::IAdcChannel> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::IAdcController>(self);
    THROW_NS_IF_FAILED(_comInst->OpenChannel(channelNumber, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDAAdcChannel>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_WDAAdcController_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Adc::AdcController*>,
                                         RTArrayObj<ABI::Windows::Devices::Adc::IAdcController*,
                                                    IVectorView<ABI::Windows::Devices::Adc::AdcController*>,
                                                    WDAAdcController,
                                                    ABI::Windows::Devices::Adc::AdcController*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
