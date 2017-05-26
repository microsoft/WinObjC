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

// WindowsDevicesHumanInterfaceDevice.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.HumanInterfaceDevice.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesHumanInterfaceDevice.h"
#include "WindowsDevicesHumanInterfaceDevice_priv.h"

@implementation WDHHidDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidDeviceStatics> WDHIHidDeviceStatics_inst() {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.HumanInterfaceDevice.HidDevice").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)getDeviceSelector:(unsigned short)usagePage usageId:(unsigned short)usageId {
    HSTRING unmarshalledReturn;
    auto _comInst = WDHIHidDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(usagePage, usageId, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorVidPid:(unsigned short)usagePage
                             usageId:(unsigned short)usageId
                            vendorId:(unsigned short)vendorId
                           productId:(unsigned short)productId {
    HSTRING unmarshalledReturn;
    auto _comInst = WDHIHidDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorVidPid(usagePage, usageId, vendorId, productId, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)fromIdAsync:(NSString*)deviceId
         accessMode:(WSFileAccessMode)accessMode
            success:(void (^)(WDHHidDevice*))success
            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::HumanInterfaceDevice::HidDevice*>> unmarshalledReturn;
    auto _comInst = WDHIHidDeviceStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), (ABI::Windows::Storage::FileAccessMode)accessMode, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::HumanInterfaceDevice::HidDevice*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::HumanInterfaceDevice::HidDevice*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDHHidDevice>(result.Get()));
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

- (unsigned short)vendorId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_VendorId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)productId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProductId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)Version {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_Version(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)usagePage {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsagePage(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)usageId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsageId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)getInputReportAsyncWithSuccess:(void (^)(WDHHidInputReport*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::HumanInterfaceDevice::HidInputReport*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->GetInputReportAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::HumanInterfaceDevice::HidInputReport*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::HumanInterfaceDevice::HidInputReport*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReport> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDHHidInputReport>(result.Get()));
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

- (void)getInputReportByIdAsync:(unsigned short)reportId success:(void (^)(WDHHidInputReport*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::HumanInterfaceDevice::HidInputReport*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->GetInputReportByIdAsync(reportId, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::HumanInterfaceDevice::HidInputReport*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::HumanInterfaceDevice::HidInputReport*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReport> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDHHidInputReport>(result.Get()));
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

- (void)getFeatureReportAsyncWithSuccess:(void (^)(WDHHidFeatureReport*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::HumanInterfaceDevice::HidFeatureReport*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->GetFeatureReportAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::HumanInterfaceDevice::HidFeatureReport*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::HumanInterfaceDevice::HidFeatureReport*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidFeatureReport> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDHHidFeatureReport>(result.Get()));
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

- (void)getFeatureReportByIdAsync:(unsigned short)reportId
                          success:(void (^)(WDHHidFeatureReport*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::HumanInterfaceDevice::HidFeatureReport*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->GetFeatureReportByIdAsync(reportId, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::HumanInterfaceDevice::HidFeatureReport*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::HumanInterfaceDevice::HidFeatureReport*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidFeatureReport> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDHHidFeatureReport>(result.Get()));
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

- (WDHHidOutputReport*)createOutputReport {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidOutputReport> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->CreateOutputReport(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidOutputReport>(unmarshalledReturn.Get());
}

- (WDHHidOutputReport*)createOutputReportById:(unsigned short)reportId {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidOutputReport> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->CreateOutputReportById(reportId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidOutputReport>(unmarshalledReturn.Get());
}

- (WDHHidFeatureReport*)createFeatureReport {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidFeatureReport> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFeatureReport(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidFeatureReport>(unmarshalledReturn.Get());
}

- (WDHHidFeatureReport*)createFeatureReportById:(unsigned short)reportId {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidFeatureReport> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFeatureReportById(reportId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidFeatureReport>(unmarshalledReturn.Get());
}

- (void)sendOutputReportAsync:(WDHHidOutputReport*)outputReport
                      success:(void (^)(unsigned int))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->SendOutputReportAsync(_getRtInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidOutputReport>(outputReport).Get(),
                                        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<unsigned int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<unsigned int>* op, AsyncStatus status) {
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

- (void)sendFeatureReportAsync:(WDHHidFeatureReport*)featureReport
                       success:(void (^)(unsigned int))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->SendFeatureReportAsync(
        _getRtInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidFeatureReport>(featureReport).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<unsigned int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<unsigned int>* op, AsyncStatus status) {
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

- (NSArray* /* WDHHidBooleanControlDescription* */)getBooleanControlDescriptions:(WDHHidReportType)reportType
                                                                       usagePage:(unsigned short)usagePage
                                                                         usageId:(unsigned short)usageId {
    ComPtr<IVectorView<ABI::Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->GetBooleanControlDescriptions((ABI::Windows::Devices::HumanInterfaceDevice::HidReportType)reportType,
                                                               usagePage,
                                                               usageId,
                                                               unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDHHidBooleanControlDescription_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDHHidNumericControlDescription* */)getNumericControlDescriptions:(WDHHidReportType)reportType
                                                                       usagePage:(unsigned short)usagePage
                                                                         usageId:(unsigned short)usageId {
    ComPtr<IVectorView<ABI::Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->GetNumericControlDescriptions((ABI::Windows::Devices::HumanInterfaceDevice::HidReportType)reportType,
                                                               usagePage,
                                                               usageId,
                                                               unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDHHidNumericControlDescription_create(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addInputReportReceivedEvent:(void (^)(WDHHidDevice*, WDHHidInputReportReceivedEventArgs*))reportHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->add_InputReportReceived(
        Make<
            ITypedEventHandler_Windows_Devices_HumanInterfaceDevice_HidDevice_Windows_Devices_HumanInterfaceDevice_HidInputReportReceivedEventArgs>(
            reportHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeInputReportReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_InputReportReceived(token));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDHHidInputReport

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReport> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned short)id {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (NSArray* /* WDHHidBooleanControl* */)activatedBooleanControls {
    ComPtr<IVectorView<ABI::Windows::Devices::HumanInterfaceDevice::HidBooleanControl*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedBooleanControls(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDHHidBooleanControl_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDHHidBooleanControl* */)transitionedBooleanControls {
    ComPtr<IVectorView<ABI::Windows::Devices::HumanInterfaceDevice::HidBooleanControl*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransitionedBooleanControls(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDHHidBooleanControl_create(unmarshalledReturn.Get());
}

- (WDHHidBooleanControl*)getBooleanControl:(unsigned short)usagePage usageId:(unsigned short)usageId {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReport>(self);
    THROW_NS_IF_FAILED(_comInst->GetBooleanControl(usagePage, usageId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidBooleanControl>(unmarshalledReturn.Get());
}

- (WDHHidBooleanControl*)getBooleanControlByDescription:(WDHHidBooleanControlDescription*)controlDescription {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReport>(self);
    THROW_NS_IF_FAILED(_comInst->GetBooleanControlByDescription(
        _getRtInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription>(controlDescription).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidBooleanControl>(unmarshalledReturn.Get());
}

- (WDHHidNumericControl*)getNumericControl:(unsigned short)usagePage usageId:(unsigned short)usageId {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReport>(self);
    THROW_NS_IF_FAILED(_comInst->GetNumericControl(usagePage, usageId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidNumericControl>(unmarshalledReturn.Get());
}

- (WDHHidNumericControl*)getNumericControlByDescription:(WDHHidNumericControlDescription*)controlDescription {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReport>(self);
    THROW_NS_IF_FAILED(_comInst->GetNumericControlByDescription(
        _getRtInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(controlDescription).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidNumericControl>(unmarshalledReturn.Get());
}

@end

@implementation WDHHidFeatureReport

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidFeatureReport> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned short)id {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidFeatureReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidFeatureReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setData:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidFeatureReport>(self);
    THROW_NS_IF_FAILED(_comInst->put_Data(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (WDHHidBooleanControl*)getBooleanControl:(unsigned short)usagePage usageId:(unsigned short)usageId {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidFeatureReport>(self);
    THROW_NS_IF_FAILED(_comInst->GetBooleanControl(usagePage, usageId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidBooleanControl>(unmarshalledReturn.Get());
}

- (WDHHidBooleanControl*)getBooleanControlByDescription:(WDHHidBooleanControlDescription*)controlDescription {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidFeatureReport>(self);
    THROW_NS_IF_FAILED(_comInst->GetBooleanControlByDescription(
        _getRtInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription>(controlDescription).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidBooleanControl>(unmarshalledReturn.Get());
}

- (WDHHidNumericControl*)getNumericControl:(unsigned short)usagePage usageId:(unsigned short)usageId {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidFeatureReport>(self);
    THROW_NS_IF_FAILED(_comInst->GetNumericControl(usagePage, usageId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidNumericControl>(unmarshalledReturn.Get());
}

- (WDHHidNumericControl*)getNumericControlByDescription:(WDHHidNumericControlDescription*)controlDescription {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidFeatureReport>(self);
    THROW_NS_IF_FAILED(_comInst->GetNumericControlByDescription(
        _getRtInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(controlDescription).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidNumericControl>(unmarshalledReturn.Get());
}

@end

@implementation WDHHidOutputReport

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidOutputReport> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned short)id {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidOutputReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidOutputReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setData:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidOutputReport>(self);
    THROW_NS_IF_FAILED(_comInst->put_Data(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (WDHHidBooleanControl*)getBooleanControl:(unsigned short)usagePage usageId:(unsigned short)usageId {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidOutputReport>(self);
    THROW_NS_IF_FAILED(_comInst->GetBooleanControl(usagePage, usageId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidBooleanControl>(unmarshalledReturn.Get());
}

- (WDHHidBooleanControl*)getBooleanControlByDescription:(WDHHidBooleanControlDescription*)controlDescription {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidOutputReport>(self);
    THROW_NS_IF_FAILED(_comInst->GetBooleanControlByDescription(
        _getRtInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription>(controlDescription).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidBooleanControl>(unmarshalledReturn.Get());
}

- (WDHHidNumericControl*)getNumericControl:(unsigned short)usagePage usageId:(unsigned short)usageId {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidOutputReport>(self);
    THROW_NS_IF_FAILED(_comInst->GetNumericControl(usagePage, usageId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidNumericControl>(unmarshalledReturn.Get());
}

- (WDHHidNumericControl*)getNumericControlByDescription:(WDHHidNumericControlDescription*)controlDescription {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidOutputReport>(self);
    THROW_NS_IF_FAILED(_comInst->GetNumericControlByDescription(
        _getRtInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(controlDescription).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidNumericControl>(unmarshalledReturn.Get());
}

@end

@implementation WDHHidBooleanControlDescription

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)reportId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDHHidReportType)reportType {
    ABI::Windows::Devices::HumanInterfaceDevice::HidReportType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportType(&unmarshalledReturn));
    return (WDHHidReportType)unmarshalledReturn;
}

- (unsigned short)usagePage {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsagePage(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)usageId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsageId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSArray* /* WDHHidCollection* */)parentCollections {
    ComPtr<IVectorView<ABI::Windows::Devices::HumanInterfaceDevice::HidCollection*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentCollections(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDHHidCollection_create(unmarshalledReturn.Get());
}

- (BOOL)isAbsolute {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAbsolute(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDHHidNumericControlDescription

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)reportId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDHHidReportType)reportType {
    ABI::Windows::Devices::HumanInterfaceDevice::HidReportType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportType(&unmarshalledReturn));
    return (WDHHidReportType)unmarshalledReturn;
}

- (unsigned int)reportSize {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)reportCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)usagePage {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsagePage(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)usageId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsageId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)logicalMinimum {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_LogicalMinimum(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)logicalMaximum {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_LogicalMaximum(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)physicalMinimum {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhysicalMinimum(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)physicalMaximum {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhysicalMaximum(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)unitExponent {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnitExponent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)unit {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_Unit(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isAbsolute {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAbsolute(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)hasNull {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasNull(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WDHHidCollection* */)parentCollections {
    ComPtr<IVectorView<ABI::Windows::Devices::HumanInterfaceDevice::HidCollection*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentCollections(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDHHidCollection_create(unmarshalledReturn.Get());
}

@end

@implementation WDHHidInputReportReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReportReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDHHidInputReport*)report {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReport> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReportReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Report(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidInputReport>(unmarshalledReturn.Get());
}

@end

@implementation WDHHidCollection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDHHidCollectionType)type {
    ABI::Windows::Devices::HumanInterfaceDevice::HidCollectionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDHHidCollectionType)unmarshalledReturn;
}

- (unsigned int)usagePage {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsagePage(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)usageId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsageId(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDHHidBooleanControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)usagePage {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsagePage(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)usageId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsageId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isActive {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsActive(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsActive:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsActive((boolean)value));
}

- (WDHHidBooleanControlDescription*)controlDescription {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ControlDescription(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidBooleanControlDescription>(unmarshalledReturn.Get());
}

@end

@implementation WDHHidNumericControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isGrouped {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsGrouped(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (unsigned short)usagePage {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsagePage(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)usageId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsageId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)value {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setValue:(int64_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(value));
}

- (int64_t)scaledValue {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScaledValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setScaledValue:(int64_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScaledValue(value));
}

- (WDHHidNumericControlDescription*)controlDescription {
    ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ControlDescription(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDHHidNumericControlDescription>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_WDHHidBooleanControl_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::HumanInterfaceDevice::HidBooleanControl*>,
                                         RTArrayObj<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControl*,
                                                    IVectorView<ABI::Windows::Devices::HumanInterfaceDevice::HidBooleanControl*>,
                                                    WDHHidBooleanControl,
                                                    ABI::Windows::Devices::HumanInterfaceDevice::HidBooleanControl*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDHHidBooleanControlDescription_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription*>,
                                         RTArrayObj<ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription*,
                                                    IVectorView<ABI::Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription*>,
                                                    WDHHidBooleanControlDescription,
                                                    ABI::Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDHHidCollection_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::HumanInterfaceDevice::HidCollection*>,
                                         RTArrayObj<ABI::Windows::Devices::HumanInterfaceDevice::IHidCollection*,
                                                    IVectorView<ABI::Windows::Devices::HumanInterfaceDevice::HidCollection*>,
                                                    WDHHidCollection,
                                                    ABI::Windows::Devices::HumanInterfaceDevice::HidCollection*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDHHidNumericControlDescription_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription*>,
                                         RTArrayObj<ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription*,
                                                    IVectorView<ABI::Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription*>,
                                                    WDHHidNumericControlDescription,
                                                    ABI::Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
