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

// WindowsNetworkingServiceDiscoveryDnssd.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Networking.ServiceDiscovery.Dnssd.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsNetworkingServiceDiscoveryDnssd.h"
#include "WindowsNetworkingServiceDiscoveryDnssd_priv.h"

@implementation WNSDDnssdServiceWatcher

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addAddedEvent:(void (^)(WNSDDnssdServiceWatcher*, WNSDDnssdServiceInstance*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Added(
        Make<
            ITypedEventHandler_Windows_Networking_ServiceDiscovery_Dnssd_DnssdServiceWatcher_Windows_Networking_ServiceDiscovery_Dnssd_DnssdServiceInstance>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAddedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Added(token));
}

- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WNSDDnssdServiceWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_EnumerationCompleted(
        Make<ITypedEventHandler_Windows_Networking_ServiceDiscovery_Dnssd_DnssdServiceWatcher_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_EnumerationCompleted(token));
}

- (EventRegistrationToken)addStoppedEvent:(void (^)(WNSDDnssdServiceWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Stopped(
        Make<ITypedEventHandler_Windows_Networking_ServiceDiscovery_Dnssd_DnssdServiceWatcher_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStoppedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Stopped(token));
}

- (WNSDDnssdServiceWatcherStatus)status {
    ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcherStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WNSDDnssdServiceWatcherStatus)unmarshalledReturn;
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

@end

@implementation WNSDDnssdServiceInstance

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstanceFactory> WNSDIDnssdServiceInstanceFactory_inst() {
    ComPtr<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstanceFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.ServiceDiscovery.Dnssd.DnssdServiceInstance").Get(), &inst));
    return inst;
}

+ (WNSDDnssdServiceInstance*)make:(NSString*)dnssdServiceInstanceName hostName:(WNHostName*)hostName port:(unsigned short)port {
    ComPtr<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance> unmarshalledReturn;
    auto _comInst = WNSDIDnssdServiceInstanceFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(dnssdServiceInstanceName).Get(),
                                        _getRtInterface<ABI::Windows::Networking::IHostName>(hostName).Get(),
                                        port,
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNSDDnssdServiceInstance>(unmarshalledReturn.Get()) retain];
}

- (NSString*)dnssdServiceInstanceName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_DnssdServiceInstanceName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDnssdServiceInstanceName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>(self);
    THROW_NS_IF_FAILED(_comInst->put_DnssdServiceInstanceName(nsStrToHstr(value).Get()));
}

- (WNHostName*)hostName {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_HostName(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (void)setHostName:(WNHostName*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>(self);
    THROW_NS_IF_FAILED(_comInst->put_HostName(_getRtInterface<ABI::Windows::Networking::IHostName>(value).Get()));
}

- (unsigned short)port {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_Port(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPort:(unsigned short)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>(self);
    THROW_NS_IF_FAILED(_comInst->put_Port(value));
}

- (unsigned short)priority {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_Priority(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPriority:(unsigned short)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>(self);
    THROW_NS_IF_FAILED(_comInst->put_Priority(value));
}

- (unsigned short)weight {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_Weight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setWeight:(unsigned short)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>(self);
    THROW_NS_IF_FAILED(_comInst->put_Weight(value));
}

- (NSMutableDictionary* /* NSString *, NSString * */)textAttributes {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextAttributes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

- (void)registerStreamSocketListenerAsync1:(WNSStreamSocketListener*)socket
                                   success:(void (^)(WNSDDnssdRegistrationResult*))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterStreamSocketListenerAsync1(
        _getRtInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener>(socket).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNSDDnssdRegistrationResult>(result.Get()));
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

- (void)registerStreamSocketListenerAsync2:(WNSStreamSocketListener*)socket
                                   adapter:(WNCNetworkAdapter*)adapter
                                   success:(void (^)(WNSDDnssdRegistrationResult*))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterStreamSocketListenerAsync2(
        _getRtInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener>(socket).Get(),
        _getRtInterface<ABI::Windows::Networking::Connectivity::INetworkAdapter>(adapter).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNSDDnssdRegistrationResult>(result.Get()));
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

- (void)registerDatagramSocketAsync1:(WNSDatagramSocket*)socket
                             success:(void (^)(WNSDDnssdRegistrationResult*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>(self);
    THROW_NS_IF_FAILED(
        _comInst->RegisterDatagramSocketAsync1(_getRtInterface<ABI::Windows::Networking::Sockets::IDatagramSocket>(socket).Get(),
                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNSDDnssdRegistrationResult>(result.Get()));
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

- (void)registerDatagramSocketAsync2:(WNSDatagramSocket*)socket
                             adapter:(WNCNetworkAdapter*)adapter
                             success:(void (^)(WNSDDnssdRegistrationResult*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>(self);
    THROW_NS_IF_FAILED(
        _comInst->RegisterDatagramSocketAsync2(_getRtInterface<ABI::Windows::Networking::Sockets::IDatagramSocket>(socket).Get(),
                                               _getRtInterface<ABI::Windows::Networking::Connectivity::INetworkAdapter>(adapter).Get(),
                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNSDDnssdRegistrationResult>(result.Get()));
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

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNSDDnssdRegistrationResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Networking.ServiceDiscovery.Dnssd.DnssdRegistrationResult").Get(), &out));
    return [_createRtProxy<WNSDDnssdRegistrationResult>(out.Get()) retain];
}

- (WNSDDnssdRegistrationStatus)status {
    ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WNSDDnssdRegistrationStatus)unmarshalledReturn;
}

- (WNHostName*)iPAddress {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_IPAddress(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (BOOL)hasInstanceNameChanged {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasInstanceNameChanged(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNSDDnssdServiceInstanceCollection {
    RTArrayObj<ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance*,
               IVectorView<ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance*>,
               WNSDDnssdServiceInstance,
               ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance*,
               dummyObjCCreator,
               dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTORVIEW_FULL(self.comObj,
                             WNSDDnssdServiceInstance,
                             ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance*,
                             ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVectorView<ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

id RTProxiedNSMutableDictionary_NSString_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<
        MutableDictionaryAdapterObj<IMap<HSTRING, HSTRING>,
                                    DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, HSTRING>>,
                                    RTMapObj<HSTRING,
                                             HSTRING,
                                             HSTRING,
                                             HSTRING,
                                             NSString,
                                             NSString,
                                             IMap<HSTRING, HSTRING>,
                                             dummyObjCCreator,
                                             dummyObjCCreator,
                                             dummyWRLCreator,
                                             dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
