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

// WindowsDevicesWiFi.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.WiFi.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesWiFi.h"
#include "WindowsDevicesWiFi_priv.h"

@implementation WDWWiFiAdapter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFi::IWiFiAdapter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::WiFi::IWiFiAdapterStatics> WDWIWiFiAdapterStatics_inst() {
    ComPtr<ABI::Windows::Devices::WiFi::IWiFiAdapterStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.WiFi.WiFiAdapter").Get(), &inst));
    return inst;
}

+ (void)findAllAdaptersAsyncWithSuccess:(void (^)(NSArray* /* WDWWiFiAdapter* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::WiFi::WiFiAdapter*>*>> unmarshalledReturn;
    auto _comInst = WDWIWiFiAdapterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllAdaptersAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Devices::WiFi::WiFiAdapter*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::WiFi::WiFiAdapter*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::WiFi::WiFiAdapter*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WDWWiFiAdapter_create(result.Get()));
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

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDWIWiFiAdapterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDWWiFiAdapter*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFi::WiFiAdapter*>> unmarshalledReturn;
    auto _comInst = WDWIWiFiAdapterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::WiFi::WiFiAdapter*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFi::WiFiAdapter*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::WiFi::IWiFiAdapter> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDWWiFiAdapter>(result.Get()));
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

+ (void)requestAccessAsyncWithSuccess:(void (^)(WDWWiFiAccessStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFi::WiFiAccessStatus>> unmarshalledReturn;
    auto _comInst = WDWIWiFiAdapterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAccessAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::WiFi::WiFiAccessStatus>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFi::WiFiAccessStatus>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Devices::WiFi::WiFiAccessStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WDWWiFiAccessStatus)result);
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

- (WNCNetworkAdapter*)networkAdapter {
    ComPtr<ABI::Windows::Networking::Connectivity::INetworkAdapter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAdapter>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkAdapter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCNetworkAdapter>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)scanAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAdapter>(self);
    THROW_NS_IF_FAILED(_comInst->ScanAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (WDWWiFiNetworkReport*)networkReport {
    ComPtr<ABI::Windows::Devices::WiFi::IWiFiNetworkReport> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAdapter>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkReport(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDWWiFiNetworkReport>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addAvailableNetworksChangedEvent:(void (^)(WDWWiFiAdapter*, RTObject*))args {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAdapter>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_AvailableNetworksChanged(Make<ITypedEventHandler_Windows_Devices_WiFi_WiFiAdapter_System_Object>(args).Get(),
                                               &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAvailableNetworksChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAdapter>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AvailableNetworksChanged(eventCookie));
}

- (void)connectAsync:(WDWWiFiAvailableNetwork*)availableNetwork
    reconnectionKind:(WDWWiFiReconnectionKind)reconnectionKind
             success:(void (^)(WDWWiFiConnectionResult*))success
             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFi::WiFiConnectionResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAdapter>(self);
    THROW_NS_IF_FAILED(_comInst->ConnectAsync(_getRtInterface<ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork>(availableNetwork).Get(),
                                              (ABI::Windows::Devices::WiFi::WiFiReconnectionKind)reconnectionKind,
                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::WiFi::WiFiConnectionResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFi::WiFiConnectionResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::WiFi::IWiFiConnectionResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDWWiFiConnectionResult>(result.Get()));
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

- (void)connectWithPasswordCredentialAsync:(WDWWiFiAvailableNetwork*)availableNetwork
                          reconnectionKind:(WDWWiFiReconnectionKind)reconnectionKind
                        passwordCredential:(WSCPasswordCredential*)passwordCredential
                                   success:(void (^)(WDWWiFiConnectionResult*))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFi::WiFiConnectionResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAdapter>(self);
    THROW_NS_IF_FAILED(_comInst->ConnectWithPasswordCredentialAsync(
        _getRtInterface<ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork>(availableNetwork).Get(),
        (ABI::Windows::Devices::WiFi::WiFiReconnectionKind)reconnectionKind,
        _getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(passwordCredential).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::WiFi::WiFiConnectionResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFi::WiFiConnectionResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::WiFi::IWiFiConnectionResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDWWiFiConnectionResult>(result.Get()));
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

- (void)connectWithPasswordCredentialAndSsidAsync:(WDWWiFiAvailableNetwork*)availableNetwork
                                 reconnectionKind:(WDWWiFiReconnectionKind)reconnectionKind
                               passwordCredential:(WSCPasswordCredential*)passwordCredential
                                             ssid:(NSString*)ssid
                                          success:(void (^)(WDWWiFiConnectionResult*))success
                                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFi::WiFiConnectionResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAdapter>(self);
    THROW_NS_IF_FAILED(_comInst->ConnectWithPasswordCredentialAndSsidAsync(
        _getRtInterface<ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork>(availableNetwork).Get(),
        (ABI::Windows::Devices::WiFi::WiFiReconnectionKind)reconnectionKind,
        _getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(passwordCredential).Get(),
        nsStrToHstr(ssid).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::WiFi::WiFiConnectionResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFi::WiFiConnectionResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::WiFi::IWiFiConnectionResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDWWiFiConnectionResult>(result.Get()));
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

- (void)disconnect {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAdapter>(self);
    THROW_NS_IF_FAILED(_comInst->Disconnect());
}

@end

@implementation WDWWiFiNetworkReport

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFi::IWiFiNetworkReport> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiNetworkReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSArray* /* WDWWiFiAvailableNetwork* */)availableNetworks {
    ComPtr<IVectorView<ABI::Windows::Devices::WiFi::WiFiAvailableNetwork*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiNetworkReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_AvailableNetworks(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDWWiFiAvailableNetwork_create(unmarshalledReturn.Get());
}

@end

@implementation WDWWiFiAvailableNetwork

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFTimeSpan*)uptime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uptime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (NSString*)ssid {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_Ssid(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)bssid {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bssid(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)channelCenterFrequencyInKilohertz {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChannelCenterFrequencyInKilohertz(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)networkRssiInDecibelMilliwatts {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkRssiInDecibelMilliwatts(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)signalBars {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_SignalBars(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDWWiFiNetworkKind)networkKind {
    ABI::Windows::Devices::WiFi::WiFiNetworkKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkKind(&unmarshalledReturn));
    return (WDWWiFiNetworkKind)unmarshalledReturn;
}

- (WDWWiFiPhyKind)phyKind {
    ABI::Windows::Devices::WiFi::WiFiPhyKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhyKind(&unmarshalledReturn));
    return (WDWWiFiPhyKind)unmarshalledReturn;
}

- (WNCNetworkSecuritySettings*)securitySettings {
    ComPtr<ABI::Windows::Networking::Connectivity::INetworkSecuritySettings> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_SecuritySettings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCNetworkSecuritySettings>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)beaconInterval {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_BeaconInterval(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (BOOL)isWiFiDirect {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsWiFiDirect(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDWWiFiConnectionResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFi::IWiFiConnectionResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDWWiFiConnectionStatus)connectionStatus {
    ABI::Windows::Devices::WiFi::WiFiConnectionStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFi::IWiFiConnectionResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionStatus(&unmarshalledReturn));
    return (WDWWiFiConnectionStatus)unmarshalledReturn;
}

@end

id RTProxiedNSArray_WDWWiFiAdapter_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::WiFi::WiFiAdapter*>,
                                         RTArrayObj<ABI::Windows::Devices::WiFi::IWiFiAdapter*,
                                                    IVectorView<ABI::Windows::Devices::WiFi::WiFiAdapter*>,
                                                    WDWWiFiAdapter,
                                                    ABI::Windows::Devices::WiFi::WiFiAdapter*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDWWiFiAvailableNetwork_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::WiFi::WiFiAvailableNetwork*>,
                                         RTArrayObj<ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork*,
                                                    IVectorView<ABI::Windows::Devices::WiFi::WiFiAvailableNetwork*>,
                                                    WDWWiFiAvailableNetwork,
                                                    ABI::Windows::Devices::WiFi::WiFiAvailableNetwork*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
