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

// WindowsNetworkingSockets.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Networking.Sockets.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsNetworkingSockets.h"
#include "WindowsNetworkingSockets_priv.h"

@implementation WNSIWebSocketControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IWebSocketControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)outboundBufferSizeInBytes {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutboundBufferSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOutboundBufferSizeInBytes:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutboundBufferSizeInBytes(value));
}

- (WSCPasswordCredential*)serverCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setServerCredential:(WSCPasswordCredential*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ServerCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(value).Get()));
}

- (WSCPasswordCredential*)proxyCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProxyCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setProxyCredential:(WSCPasswordCredential*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ProxyCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(value).Get()));
}

- (NSMutableArray* /* NSString * */)supportedProtocols {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedProtocols(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WNSIWebSocketControl2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IWebSocketControl2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSMutableArray* /* WSCCChainValidationResult */)ignorableServerCertificateErrors {
    ComPtr<IVector<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IgnorableServerCertificateErrors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WSCCChainValidationResult_create(unmarshalledReturn.Get());
}

- (unsigned int)outboundBufferSizeInBytes {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutboundBufferSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOutboundBufferSizeInBytes:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutboundBufferSizeInBytes(value));
}

- (WSCPasswordCredential*)serverCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setServerCredential:(WSCPasswordCredential*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ServerCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(value).Get()));
}

- (WSCPasswordCredential*)proxyCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProxyCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setProxyCredential:(WSCPasswordCredential*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ProxyCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(value).Get()));
}

- (NSMutableArray* /* NSString * */)supportedProtocols {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedProtocols(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WNSIWebSocketInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IWebSocketInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNHostName*)localAddress {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalAddress(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (WNSBandwidthStatistics*)bandwidthStatistics {
    ABI::Windows::Networking::Sockets::BandwidthStatistics unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_BandwidthStatistics(&unmarshalledReturn));
    return WNSBandwidthStatistics_create(unmarshalledReturn);
}

- (NSString*)protocol {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Protocol(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNSIWebSocketInformation2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IWebSocketInformation2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSCCCertificate*)serverCertificate {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (WNSSocketSslErrorSeverity)serverCertificateErrorSeverity {
    ABI::Windows::Networking::Sockets::SocketSslErrorSeverity unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificateErrorSeverity(&unmarshalledReturn));
    return (WNSSocketSslErrorSeverity)unmarshalledReturn;
}

- (NSArray* /* WSCCChainValidationResult */)serverCertificateErrors {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificateErrors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCChainValidationResult_create(unmarshalledReturn.Get());
}

- (NSArray* /* WSCCCertificate* */)serverIntermediateCertificates {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerIntermediateCertificates(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCCertificate_create(unmarshalledReturn.Get());
}

- (WNHostName*)localAddress {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalAddress(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (WNSBandwidthStatistics*)bandwidthStatistics {
    ABI::Windows::Networking::Sockets::BandwidthStatistics unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_BandwidthStatistics(&unmarshalledReturn));
    return WNSBandwidthStatistics_create(unmarshalledReturn);
}

- (NSString*)protocol {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Protocol(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNSIWebSocket

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IWebSocket> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIOutputStream>*)outputStream {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutputStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIOutputStream>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)connectAsync:(WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(
        _comInst->ConnectAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)setRequestHeader:(NSString*)headerName headerValue:(NSString*)headerValue {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->SetRequestHeader(nsStrToHstr(headerName).Get(), nsStrToHstr(headerValue).Get()));
}

- (EventRegistrationToken)addClosedEvent:(void (^)(RTObject<WNSIWebSocket>*, WNSWebSocketClosedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->add_Closed(
        Make<ITypedEventHandler_Windows_Networking_Sockets_IWebSocket_Windows_Networking_Sockets_WebSocketClosedEventArgs>(eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Closed(eventCookie));
}

- (void)closeWithStatus:(unsigned short)code reason:(NSString*)reason {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->CloseWithStatus(code, nsStrToHstr(reason).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WNSIControlChannelTriggerEventDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IControlChannelTriggerEventDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNSControlChannelTrigger*)controlChannelTrigger {
    ComPtr<ABI::Windows::Networking::Sockets::IControlChannelTrigger> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IControlChannelTriggerEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ControlChannelTrigger(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSControlChannelTrigger>(unmarshalledReturn.Get());
}

@end

@implementation WNSIControlChannelTriggerResetEventDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IControlChannelTriggerResetEventDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNSControlChannelTriggerResetReason)resetReason {
    ABI::Windows::Networking::Sockets::ControlChannelTriggerResetReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IControlChannelTriggerResetEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResetReason(&unmarshalledReturn));
    return (WNSControlChannelTriggerResetReason)unmarshalledReturn;
}

- (BOOL)hardwareSlotReset {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IControlChannelTriggerResetEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_HardwareSlotReset(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)softwareSlotReset {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IControlChannelTriggerResetEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_SoftwareSlotReset(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNSSocketActivityContext

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::ISocketActivityContext> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Networking::Sockets::ISocketActivityContextFactory> WNSISocketActivityContextFactory_inst() {
    ComPtr<ABI::Windows::Networking::Sockets::ISocketActivityContextFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Sockets.SocketActivityContext").Get(),
                                                       &inst));
    return inst;
}

+ (WNSSocketActivityContext*)make:(RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Networking::Sockets::ISocketActivityContext> unmarshalledReturn;
    auto _comInst = WNSISocketActivityContextFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNSSocketActivityContext>(unmarshalledReturn.Get()) retain];
}

- (RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::ISocketActivityContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WNSDatagramSocket

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IDatagramSocket> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Sockets.DatagramSocket").Get(), &out));
    return [_createRtProxy<WNSDatagramSocket>(out.Get()) retain];
}

ComPtr<ABI::Windows::Networking::Sockets::IDatagramSocketStatics> WNSIDatagramSocketStatics_inst() {
    ComPtr<ABI::Windows::Networking::Sockets::IDatagramSocketStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Sockets.DatagramSocket").Get(), &inst));
    return inst;
}

+ (void)getEndpointPairsAsync:(WNHostName*)remoteHostName
            remoteServiceName:(NSString*)remoteServiceName
                      success:(void (^)(NSArray* /* WNEndpointPair* */))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::EndpointPair*>*>> unmarshalledReturn;
    auto _comInst = WNSIDatagramSocketStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetEndpointPairsAsync(_getRtInterface<ABI::Windows::Networking::IHostName>(remoteHostName).Get(),
                                                       nsStrToHstr(remoteServiceName).Get(),
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Networking::EndpointPair*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::EndpointPair*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Networking::EndpointPair*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WNEndpointPair_create(result.Get()));
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

+ (void)getEndpointPairsWithSortOptionsAsync:(WNHostName*)remoteHostName
                           remoteServiceName:(NSString*)remoteServiceName
                                 sortOptions:(WNHostNameSortOptions)sortOptions
                                     success:(void (^)(NSArray* /* WNEndpointPair* */))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::EndpointPair*>*>> unmarshalledReturn;
    auto _comInst = WNSIDatagramSocketStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetEndpointPairsWithSortOptionsAsync(_getRtInterface<ABI::Windows::Networking::IHostName>(remoteHostName).Get(),
                                                       nsStrToHstr(remoteServiceName).Get(),
                                                       (ABI::Windows::Networking::HostNameSortOptions)sortOptions,
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Networking::EndpointPair*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::EndpointPair*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Networking::EndpointPair*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WNEndpointPair_create(result.Get()));
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

- (WNSDatagramSocketControl*)control {
    ComPtr<ABI::Windows::Networking::Sockets::IDatagramSocketControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket>(self);
    THROW_NS_IF_FAILED(_comInst->get_Control(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSDatagramSocketControl>(unmarshalledReturn.Get());
}

- (WNSDatagramSocketInformation*)information {
    ComPtr<ABI::Windows::Networking::Sockets::IDatagramSocketInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket>(self);
    THROW_NS_IF_FAILED(_comInst->get_Information(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSDatagramSocketInformation>(unmarshalledReturn.Get());
}

- (RTObject<WSSIOutputStream>*)outputStream {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutputStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIOutputStream>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)connectAsync:(WNHostName*)remoteHostName remoteServiceName:(NSString*)remoteServiceName {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket>(self);
    THROW_NS_IF_FAILED(_comInst->ConnectAsync(_getRtInterface<ABI::Windows::Networking::IHostName>(remoteHostName).Get(),
                                              nsStrToHstr(remoteServiceName).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)connectWithEndpointPairAsync:(WNEndpointPair*)endpointPair {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket>(self);
    THROW_NS_IF_FAILED(_comInst->ConnectWithEndpointPairAsync(_getRtInterface<ABI::Windows::Networking::IEndpointPair>(endpointPair).Get(),
                                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)bindServiceNameAsync:(NSString*)localServiceName {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket>(self);
    THROW_NS_IF_FAILED(_comInst->BindServiceNameAsync(nsStrToHstr(localServiceName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)bindEndpointAsync:(WNHostName*)localHostName localServiceName:(NSString*)localServiceName {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket>(self);
    THROW_NS_IF_FAILED(_comInst->BindEndpointAsync(_getRtInterface<ABI::Windows::Networking::IHostName>(localHostName).Get(),
                                                   nsStrToHstr(localServiceName).Get(),
                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)joinMulticastGroup:(WNHostName*)host {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket>(self);
    THROW_NS_IF_FAILED(_comInst->JoinMulticastGroup(_getRtInterface<ABI::Windows::Networking::IHostName>(host).Get()));
}

- (void)getOutputStreamAsync:(WNHostName*)remoteHostName
           remoteServiceName:(NSString*)remoteServiceName
                     success:(void (^)(RTObject<WSSIOutputStream>*))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IOutputStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket>(self);
    THROW_NS_IF_FAILED(_comInst->GetOutputStreamAsync(_getRtInterface<ABI::Windows::Networking::IHostName>(remoteHostName).Get(),
                                                      nsStrToHstr(remoteServiceName).Get(),
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IOutputStream*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IOutputStream*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Storage::Streams::IOutputStream> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSSIOutputStream>(result.Get()));
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

- (void)getOutputStreamWithEndpointPairAsync:(WNEndpointPair*)endpointPair
                                     success:(void (^)(RTObject<WSSIOutputStream>*))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IOutputStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetOutputStreamWithEndpointPairAsync(_getRtInterface<ABI::Windows::Networking::IEndpointPair>(endpointPair).Get(),
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IOutputStream*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IOutputStream*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Storage::Streams::IOutputStream> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSSIOutputStream>(result.Get()));
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

- (EventRegistrationToken)addMessageReceivedEvent:(void (^)(WNSDatagramSocket*, WNSDatagramSocketMessageReceivedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket>(self);
    THROW_NS_IF_FAILED(_comInst->add_MessageReceived(
        Make<
            ITypedEventHandler_Windows_Networking_Sockets_DatagramSocket_Windows_Networking_Sockets_DatagramSocketMessageReceivedEventArgs>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMessageReceivedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MessageReceived(eventCookie));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (RTObject<WFIAsyncAction>*)bindServiceNameAndAdapterAsync:(NSString*)localServiceName adapter:(WNCNetworkAdapter*)adapter {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket2>(self);
    THROW_NS_IF_FAILED(
        _comInst->BindServiceNameAndAdapterAsync(nsStrToHstr(localServiceName).Get(),
                                                 _getRtInterface<ABI::Windows::Networking::Connectivity::INetworkAdapter>(adapter).Get(),
                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)cancelIOAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket3>(self);
    THROW_NS_IF_FAILED(_comInst->CancelIOAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)enableTransferOwnership:(WFGUID*)taskId {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket3>(self);
    THROW_NS_IF_FAILED(_comInst->EnableTransferOwnership(taskId.guidValue));
}

- (void)enableTransferOwnershipWithConnectedStandbyAction:(WFGUID*)taskId
                                   connectedStandbyAction:(WNSSocketActivityConnectedStandbyAction)connectedStandbyAction {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket3>(self);
    THROW_NS_IF_FAILED(_comInst->EnableTransferOwnershipWithConnectedStandbyAction(
        taskId.guidValue, (ABI::Windows::Networking::Sockets::SocketActivityConnectedStandbyAction)connectedStandbyAction));
}

- (void)transferOwnership:(NSString*)socketId {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket3>(self);
    THROW_NS_IF_FAILED(_comInst->TransferOwnership(nsStrToHstr(socketId).Get()));
}

- (void)transferOwnershipWithContext:(NSString*)socketId data:(WNSSocketActivityContext*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket3>(self);
    THROW_NS_IF_FAILED(
        _comInst->TransferOwnershipWithContext(nsStrToHstr(socketId).Get(),
                                               _getRtInterface<ABI::Windows::Networking::Sockets::ISocketActivityContext>(data).Get()));
}

- (void)transferOwnershipWithContextAndKeepAliveTime:(NSString*)socketId
                                                data:(WNSSocketActivityContext*)data
                                       keepAliveTime:(WFTimeSpan*)keepAliveTime {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocket3>(self);
    THROW_NS_IF_FAILED(_comInst->TransferOwnershipWithContextAndKeepAliveTime(
        nsStrToHstr(socketId).Get(),
        _getRtInterface<ABI::Windows::Networking::Sockets::ISocketActivityContext>(data).Get(),
        *[keepAliveTime internalStruct]));
}

@end

@implementation WNSStreamSocket

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocket> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Sockets.StreamSocket").Get(), &out));
    return [_createRtProxy<WNSStreamSocket>(out.Get()) retain];
}

ComPtr<ABI::Windows::Networking::Sockets::IStreamSocketStatics> WNSIStreamSocketStatics_inst() {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocketStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Sockets.StreamSocket").Get(), &inst));
    return inst;
}

+ (void)getEndpointPairsAsync:(WNHostName*)remoteHostName
            remoteServiceName:(NSString*)remoteServiceName
                      success:(void (^)(NSArray* /* WNEndpointPair* */))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::EndpointPair*>*>> unmarshalledReturn;
    auto _comInst = WNSIStreamSocketStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetEndpointPairsAsync(_getRtInterface<ABI::Windows::Networking::IHostName>(remoteHostName).Get(),
                                                       nsStrToHstr(remoteServiceName).Get(),
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Networking::EndpointPair*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::EndpointPair*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Networking::EndpointPair*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WNEndpointPair_create(result.Get()));
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

+ (void)getEndpointPairsWithSortOptionsAsync:(WNHostName*)remoteHostName
                           remoteServiceName:(NSString*)remoteServiceName
                                 sortOptions:(WNHostNameSortOptions)sortOptions
                                     success:(void (^)(NSArray* /* WNEndpointPair* */))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::EndpointPair*>*>> unmarshalledReturn;
    auto _comInst = WNSIStreamSocketStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetEndpointPairsWithSortOptionsAsync(_getRtInterface<ABI::Windows::Networking::IHostName>(remoteHostName).Get(),
                                                       nsStrToHstr(remoteServiceName).Get(),
                                                       (ABI::Windows::Networking::HostNameSortOptions)sortOptions,
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Networking::EndpointPair*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::EndpointPair*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Networking::EndpointPair*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WNEndpointPair_create(result.Get()));
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

- (WNSStreamSocketControl*)control {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocketControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocket>(self);
    THROW_NS_IF_FAILED(_comInst->get_Control(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSStreamSocketControl>(unmarshalledReturn.Get());
}

- (WNSStreamSocketInformation*)information {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocketInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocket>(self);
    THROW_NS_IF_FAILED(_comInst->get_Information(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSStreamSocketInformation>(unmarshalledReturn.Get());
}

- (RTObject<WSSIInputStream>*)inputStream {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocket>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

- (RTObject<WSSIOutputStream>*)outputStream {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocket>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutputStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIOutputStream>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)connectWithEndpointPairAsync:(WNEndpointPair*)endpointPair {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocket>(self);
    THROW_NS_IF_FAILED(_comInst->ConnectWithEndpointPairAsync(_getRtInterface<ABI::Windows::Networking::IEndpointPair>(endpointPair).Get(),
                                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)connectAsync:(WNHostName*)remoteHostName remoteServiceName:(NSString*)remoteServiceName {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocket>(self);
    THROW_NS_IF_FAILED(_comInst->ConnectAsync(_getRtInterface<ABI::Windows::Networking::IHostName>(remoteHostName).Get(),
                                              nsStrToHstr(remoteServiceName).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)connectWithEndpointPairAndProtectionLevelAsync:(WNEndpointPair*)endpointPair
                                                            protectionLevel:(WNSSocketProtectionLevel)protectionLevel {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocket>(self);
    THROW_NS_IF_FAILED(_comInst->ConnectWithEndpointPairAndProtectionLevelAsync(
        _getRtInterface<ABI::Windows::Networking::IEndpointPair>(endpointPair).Get(),
        (ABI::Windows::Networking::Sockets::SocketProtectionLevel)protectionLevel,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)connectWithProtectionLevelAsync:(WNHostName*)remoteHostName
                                           remoteServiceName:(NSString*)remoteServiceName
                                             protectionLevel:(WNSSocketProtectionLevel)protectionLevel {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocket>(self);
    THROW_NS_IF_FAILED(_comInst->ConnectWithProtectionLevelAsync(_getRtInterface<ABI::Windows::Networking::IHostName>(remoteHostName).Get(),
                                                                 nsStrToHstr(remoteServiceName).Get(),
                                                                 (ABI::Windows::Networking::Sockets::SocketProtectionLevel)protectionLevel,
                                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)upgradeToSslAsync:(WNSSocketProtectionLevel)protectionLevel
                            validationHostName:(WNHostName*)validationHostName {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocket>(self);
    THROW_NS_IF_FAILED(_comInst->UpgradeToSslAsync((ABI::Windows::Networking::Sockets::SocketProtectionLevel)protectionLevel,
                                                   _getRtInterface<ABI::Windows::Networking::IHostName>(validationHostName).Get(),
                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (RTObject<WFIAsyncAction>*)connectWithProtectionLevelAndAdapterAsync:(WNHostName*)remoteHostName
                                                     remoteServiceName:(NSString*)remoteServiceName
                                                       protectionLevel:(WNSSocketProtectionLevel)protectionLevel
                                                               adapter:(WNCNetworkAdapter*)adapter {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocket2>(self);
    THROW_NS_IF_FAILED(_comInst->ConnectWithProtectionLevelAndAdapterAsync(
        _getRtInterface<ABI::Windows::Networking::IHostName>(remoteHostName).Get(),
        nsStrToHstr(remoteServiceName).Get(),
        (ABI::Windows::Networking::Sockets::SocketProtectionLevel)protectionLevel,
        _getRtInterface<ABI::Windows::Networking::Connectivity::INetworkAdapter>(adapter).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)cancelIOAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocket3>(self);
    THROW_NS_IF_FAILED(_comInst->CancelIOAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)enableTransferOwnership:(WFGUID*)taskId {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocket3>(self);
    THROW_NS_IF_FAILED(_comInst->EnableTransferOwnership(taskId.guidValue));
}

- (void)enableTransferOwnershipWithConnectedStandbyAction:(WFGUID*)taskId
                                   connectedStandbyAction:(WNSSocketActivityConnectedStandbyAction)connectedStandbyAction {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocket3>(self);
    THROW_NS_IF_FAILED(_comInst->EnableTransferOwnershipWithConnectedStandbyAction(
        taskId.guidValue, (ABI::Windows::Networking::Sockets::SocketActivityConnectedStandbyAction)connectedStandbyAction));
}

- (void)transferOwnership:(NSString*)socketId {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocket3>(self);
    THROW_NS_IF_FAILED(_comInst->TransferOwnership(nsStrToHstr(socketId).Get()));
}

- (void)transferOwnershipWithContext:(NSString*)socketId data:(WNSSocketActivityContext*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocket3>(self);
    THROW_NS_IF_FAILED(
        _comInst->TransferOwnershipWithContext(nsStrToHstr(socketId).Get(),
                                               _getRtInterface<ABI::Windows::Networking::Sockets::ISocketActivityContext>(data).Get()));
}

- (void)transferOwnershipWithContextAndKeepAliveTime:(NSString*)socketId
                                                data:(WNSSocketActivityContext*)data
                                       keepAliveTime:(WFTimeSpan*)keepAliveTime {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocket3>(self);
    THROW_NS_IF_FAILED(_comInst->TransferOwnershipWithContextAndKeepAliveTime(
        nsStrToHstr(socketId).Get(),
        _getRtInterface<ABI::Windows::Networking::Sockets::ISocketActivityContext>(data).Get(),
        *[keepAliveTime internalStruct]));
}

@end

@implementation WNSStreamSocketListener

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocketListener> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Sockets.StreamSocketListener").Get(), &out));
    return [_createRtProxy<WNSStreamSocketListener>(out.Get()) retain];
}

- (WNSStreamSocketListenerControl*)control {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocketListenerControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener>(self);
    THROW_NS_IF_FAILED(_comInst->get_Control(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSStreamSocketListenerControl>(unmarshalledReturn.Get());
}

- (WNSStreamSocketListenerInformation*)information {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocketListenerInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener>(self);
    THROW_NS_IF_FAILED(_comInst->get_Information(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSStreamSocketListenerInformation>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)bindServiceNameAsync:(NSString*)localServiceName {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener>(self);
    THROW_NS_IF_FAILED(_comInst->BindServiceNameAsync(nsStrToHstr(localServiceName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)bindEndpointAsync:(WNHostName*)localHostName localServiceName:(NSString*)localServiceName {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener>(self);
    THROW_NS_IF_FAILED(_comInst->BindEndpointAsync(_getRtInterface<ABI::Windows::Networking::IHostName>(localHostName).Get(),
                                                   nsStrToHstr(localServiceName).Get(),
                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addConnectionReceivedEvent:(void (^)(WNSStreamSocketListener*,
                                                               WNSStreamSocketListenerConnectionReceivedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener>(self);
    THROW_NS_IF_FAILED(_comInst->add_ConnectionReceived(
        Make<
            ITypedEventHandler_Windows_Networking_Sockets_StreamSocketListener_Windows_Networking_Sockets_StreamSocketListenerConnectionReceivedEventArgs>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeConnectionReceivedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ConnectionReceived(eventCookie));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (RTObject<WFIAsyncAction>*)bindServiceNameWithProtectionLevelAsync:(NSString*)localServiceName
                                                     protectionLevel:(WNSSocketProtectionLevel)protectionLevel {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener2>(self);
    THROW_NS_IF_FAILED(
        _comInst->BindServiceNameWithProtectionLevelAsync(nsStrToHstr(localServiceName).Get(),
                                                          (ABI::Windows::Networking::Sockets::SocketProtectionLevel)protectionLevel,
                                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)bindServiceNameWithProtectionLevelAndAdapterAsync:(NSString*)localServiceName
                                                               protectionLevel:(WNSSocketProtectionLevel)protectionLevel
                                                                       adapter:(WNCNetworkAdapter*)adapter {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener2>(self);
    THROW_NS_IF_FAILED(_comInst->BindServiceNameWithProtectionLevelAndAdapterAsync(
        nsStrToHstr(localServiceName).Get(),
        (ABI::Windows::Networking::Sockets::SocketProtectionLevel)protectionLevel,
        _getRtInterface<ABI::Windows::Networking::Connectivity::INetworkAdapter>(adapter).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)cancelIOAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener3>(self);
    THROW_NS_IF_FAILED(_comInst->CancelIOAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)enableTransferOwnership:(WFGUID*)taskId {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener3>(self);
    THROW_NS_IF_FAILED(_comInst->EnableTransferOwnership(taskId.guidValue));
}

- (void)enableTransferOwnershipWithConnectedStandbyAction:(WFGUID*)taskId
                                   connectedStandbyAction:(WNSSocketActivityConnectedStandbyAction)connectedStandbyAction {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener3>(self);
    THROW_NS_IF_FAILED(_comInst->EnableTransferOwnershipWithConnectedStandbyAction(
        taskId.guidValue, (ABI::Windows::Networking::Sockets::SocketActivityConnectedStandbyAction)connectedStandbyAction));
}

- (void)transferOwnership:(NSString*)socketId {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener3>(self);
    THROW_NS_IF_FAILED(_comInst->TransferOwnership(nsStrToHstr(socketId).Get()));
}

- (void)transferOwnershipWithContext:(NSString*)socketId data:(WNSSocketActivityContext*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener3>(self);
    THROW_NS_IF_FAILED(
        _comInst->TransferOwnershipWithContext(nsStrToHstr(socketId).Get(),
                                               _getRtInterface<ABI::Windows::Networking::Sockets::ISocketActivityContext>(data).Get()));
}

@end

@implementation WNSSocketActivityInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::ISocketActivityInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Networking::Sockets::ISocketActivityInformationStatics> WNSISocketActivityInformationStatics_inst() {
    ComPtr<ABI::Windows::Networking::Sockets::ISocketActivityInformationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.Sockets.SocketActivityInformation").Get(), &inst));
    return inst;
}

+ (NSDictionary* /* NSString *, WNSSocketActivityInformation* */)allSockets {
    ComPtr<IMapView<HSTRING, ABI::Windows::Networking::Sockets::SocketActivityInformation*>> unmarshalledReturn;
    auto _comInst = WNSISocketActivityInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllSockets(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_WNSSocketActivityInformation_create(unmarshalledReturn.Get());
}

- (WFGUID*)taskId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::ISocketActivityInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_TaskId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::ISocketActivityInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNSSocketActivityKind)socketKind {
    ABI::Windows::Networking::Sockets::SocketActivityKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::ISocketActivityInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_SocketKind(&unmarshalledReturn));
    return (WNSSocketActivityKind)unmarshalledReturn;
}

- (WNSSocketActivityContext*)context {
    ComPtr<ABI::Windows::Networking::Sockets::ISocketActivityContext> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::ISocketActivityInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Context(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSSocketActivityContext>(unmarshalledReturn.Get());
}

- (WNSDatagramSocket*)datagramSocket {
    ComPtr<ABI::Windows::Networking::Sockets::IDatagramSocket> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::ISocketActivityInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DatagramSocket(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSDatagramSocket>(unmarshalledReturn.Get());
}

- (WNSStreamSocket*)streamSocket {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocket> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::ISocketActivityInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_StreamSocket(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSStreamSocket>(unmarshalledReturn.Get());
}

- (WNSStreamSocketListener*)streamSocketListener {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocketListener> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::ISocketActivityInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_StreamSocketListener(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSStreamSocketListener>(unmarshalledReturn.Get());
}

@end

@implementation WNSDatagramSocketControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IDatagramSocketControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNSSocketQualityOfService)qualityOfService {
    ABI::Windows::Networking::Sockets::SocketQualityOfService unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_QualityOfService(&unmarshalledReturn));
    return (WNSSocketQualityOfService)unmarshalledReturn;
}

- (void)setQualityOfService:(WNSSocketQualityOfService)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_QualityOfService((ABI::Windows::Networking::Sockets::SocketQualityOfService)value));
}

- (uint8_t)outboundUnicastHopLimit {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutboundUnicastHopLimit(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOutboundUnicastHopLimit:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutboundUnicastHopLimit(value));
}

- (unsigned int)inboundBufferSizeInBytes {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_InboundBufferSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setInboundBufferSizeInBytes:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketControl2>(self);
    THROW_NS_IF_FAILED(_comInst->put_InboundBufferSizeInBytes(value));
}

- (BOOL)dontFragment {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DontFragment(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setDontFragment:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketControl2>(self);
    THROW_NS_IF_FAILED(_comInst->put_DontFragment((boolean)value));
}

- (BOOL)multicastOnly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketControl3>(self);
    THROW_NS_IF_FAILED(_comInst->get_MulticastOnly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setMulticastOnly:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketControl3>(self);
    THROW_NS_IF_FAILED(_comInst->put_MulticastOnly((boolean)value));
}

@end

@implementation WNSDatagramSocketInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IDatagramSocketInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNHostName*)localAddress {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalAddress(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (NSString*)localPort {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalPort(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNHostName*)remoteAddress {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteAddress(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (NSString*)remotePort {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemotePort(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNSDatagramSocketMessageReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IDatagramSocketMessageReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNHostName*)remoteAddress {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketMessageReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteAddress(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (NSString*)remotePort {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketMessageReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemotePort(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNHostName*)localAddress {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketMessageReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalAddress(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (WSSDataReader*)getDataReader {
    ComPtr<ABI::Windows::Storage::Streams::IDataReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketMessageReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDataReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSDataReader>(unmarshalledReturn.Get());
}

- (RTObject<WSSIInputStream>*)getDataStream {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IDatagramSocketMessageReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDataStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

@end

@implementation WNSStreamSocketControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocketControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)noDelay {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_NoDelay(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setNoDelay:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_NoDelay((boolean)value));
}

- (BOOL)keepAlive {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeepAlive(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setKeepAlive:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeepAlive((boolean)value));
}

- (unsigned int)outboundBufferSizeInBytes {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutboundBufferSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOutboundBufferSizeInBytes:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutboundBufferSizeInBytes(value));
}

- (WNSSocketQualityOfService)qualityOfService {
    ABI::Windows::Networking::Sockets::SocketQualityOfService unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_QualityOfService(&unmarshalledReturn));
    return (WNSSocketQualityOfService)unmarshalledReturn;
}

- (void)setQualityOfService:(WNSSocketQualityOfService)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_QualityOfService((ABI::Windows::Networking::Sockets::SocketQualityOfService)value));
}

- (uint8_t)outboundUnicastHopLimit {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutboundUnicastHopLimit(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOutboundUnicastHopLimit:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutboundUnicastHopLimit(value));
}

- (NSMutableArray* /* WSCCChainValidationResult */)ignorableServerCertificateErrors {
    ComPtr<IVector<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IgnorableServerCertificateErrors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WSCCChainValidationResult_create(unmarshalledReturn.Get());
}

- (BOOL)serializeConnectionAttempts {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketControl3>(self);
    THROW_NS_IF_FAILED(_comInst->get_SerializeConnectionAttempts(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSerializeConnectionAttempts:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketControl3>(self);
    THROW_NS_IF_FAILED(_comInst->put_SerializeConnectionAttempts((boolean)value));
}

- (WSCCCertificate*)clientCertificate {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketControl3>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClientCertificate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (void)setClientCertificate:(WSCCCertificate*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketControl3>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ClientCertificate(_getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(value).Get()));
}

@end

@implementation WNSStreamSocketInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocketInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNHostName*)localAddress {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalAddress(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (NSString*)localPort {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalPort(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNHostName*)remoteHostName {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteHostName(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (WNHostName*)remoteAddress {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteAddress(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (NSString*)remoteServiceName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteServiceName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)remotePort {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemotePort(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNSRoundTripTimeStatistics*)roundTripTimeStatistics {
    ABI::Windows::Networking::Sockets::RoundTripTimeStatistics unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoundTripTimeStatistics(&unmarshalledReturn));
    return WNSRoundTripTimeStatistics_create(unmarshalledReturn);
}

- (WNSBandwidthStatistics*)bandwidthStatistics {
    ABI::Windows::Networking::Sockets::BandwidthStatistics unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_BandwidthStatistics(&unmarshalledReturn));
    return WNSBandwidthStatistics_create(unmarshalledReturn);
}

- (WNSSocketProtectionLevel)protectionLevel {
    ABI::Windows::Networking::Sockets::SocketProtectionLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionLevel(&unmarshalledReturn));
    return (WNSSocketProtectionLevel)unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)sessionKey {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_SessionKey(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WNSSocketSslErrorSeverity)serverCertificateErrorSeverity {
    ABI::Windows::Networking::Sockets::SocketSslErrorSeverity unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificateErrorSeverity(&unmarshalledReturn));
    return (WNSSocketSslErrorSeverity)unmarshalledReturn;
}

- (NSArray* /* WSCCChainValidationResult */)serverCertificateErrors {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificateErrors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCChainValidationResult_create(unmarshalledReturn.Get());
}

- (WSCCCertificate*)serverCertificate {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (NSArray* /* WSCCCertificate* */)serverIntermediateCertificates {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerIntermediateCertificates(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCCertificate_create(unmarshalledReturn.Get());
}

@end

@implementation WNSStreamSocketListenerControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocketListenerControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNSSocketQualityOfService)qualityOfService {
    ABI::Windows::Networking::Sockets::SocketQualityOfService unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListenerControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_QualityOfService(&unmarshalledReturn));
    return (WNSSocketQualityOfService)unmarshalledReturn;
}

- (void)setQualityOfService:(WNSSocketQualityOfService)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListenerControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_QualityOfService((ABI::Windows::Networking::Sockets::SocketQualityOfService)value));
}

- (BOOL)noDelay {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListenerControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_NoDelay(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setNoDelay:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListenerControl2>(self);
    THROW_NS_IF_FAILED(_comInst->put_NoDelay((boolean)value));
}

- (BOOL)keepAlive {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListenerControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeepAlive(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setKeepAlive:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListenerControl2>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeepAlive((boolean)value));
}

- (unsigned int)outboundBufferSizeInBytes {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListenerControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutboundBufferSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOutboundBufferSizeInBytes:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListenerControl2>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutboundBufferSizeInBytes(value));
}

- (uint8_t)outboundUnicastHopLimit {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListenerControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutboundUnicastHopLimit(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOutboundUnicastHopLimit:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListenerControl2>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutboundUnicastHopLimit(value));
}

@end

@implementation WNSStreamSocketListenerInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocketListenerInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)localPort {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListenerInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalPort(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNSStreamSocketListenerConnectionReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocketListenerConnectionReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNSStreamSocket*)socket {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocket> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamSocketListenerConnectionReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Socket(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSStreamSocket>(unmarshalledReturn.Get());
}

@end

@implementation WNSWebSocketClosedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IWebSocketClosedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned short)code {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketClosedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Code(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)reason {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketClosedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reason(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNSMessageWebSocketControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IMessageWebSocketControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)maxMessageSize {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IMessageWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxMessageSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMaxMessageSize:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IMessageWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxMessageSize(value));
}

- (WNSSocketMessageType)messageType {
    ABI::Windows::Networking::Sockets::SocketMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IMessageWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageType(&unmarshalledReturn));
    return (WNSSocketMessageType)unmarshalledReturn;
}

- (void)setMessageType:(WNSSocketMessageType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IMessageWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_MessageType((ABI::Windows::Networking::Sockets::SocketMessageType)value));
}

- (unsigned int)outboundBufferSizeInBytes {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutboundBufferSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOutboundBufferSizeInBytes:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutboundBufferSizeInBytes(value));
}

- (WSCPasswordCredential*)serverCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setServerCredential:(WSCPasswordCredential*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ServerCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(value).Get()));
}

- (WSCPasswordCredential*)proxyCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProxyCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setProxyCredential:(WSCPasswordCredential*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ProxyCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(value).Get()));
}

- (NSMutableArray* /* NSString * */)supportedProtocols {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedProtocols(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WSCCChainValidationResult */)ignorableServerCertificateErrors {
    ComPtr<IVector<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IgnorableServerCertificateErrors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WSCCChainValidationResult_create(unmarshalledReturn.Get());
}

@end

@implementation WNSMessageWebSocketInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IWebSocketInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNHostName*)localAddress {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalAddress(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (WNSBandwidthStatistics*)bandwidthStatistics {
    ABI::Windows::Networking::Sockets::BandwidthStatistics unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_BandwidthStatistics(&unmarshalledReturn));
    return WNSBandwidthStatistics_create(unmarshalledReturn);
}

- (NSString*)protocol {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Protocol(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSCCCertificate*)serverCertificate {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (WNSSocketSslErrorSeverity)serverCertificateErrorSeverity {
    ABI::Windows::Networking::Sockets::SocketSslErrorSeverity unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificateErrorSeverity(&unmarshalledReturn));
    return (WNSSocketSslErrorSeverity)unmarshalledReturn;
}

- (NSArray* /* WSCCChainValidationResult */)serverCertificateErrors {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificateErrors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCChainValidationResult_create(unmarshalledReturn.Get());
}

- (NSArray* /* WSCCCertificate* */)serverIntermediateCertificates {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerIntermediateCertificates(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCCertificate_create(unmarshalledReturn.Get());
}

@end

@implementation WNSMessageWebSocket

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IMessageWebSocket> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Sockets.MessageWebSocket").Get(), &out));
    return [_createRtProxy<WNSMessageWebSocket>(out.Get()) retain];
}

- (WNSMessageWebSocketControl*)control {
    ComPtr<ABI::Windows::Networking::Sockets::IMessageWebSocketControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IMessageWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->get_Control(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSMessageWebSocketControl>(unmarshalledReturn.Get());
}

- (WNSMessageWebSocketInformation*)information {
    ComPtr<ABI::Windows::Networking::Sockets::IWebSocketInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IMessageWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->get_Information(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSMessageWebSocketInformation>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addMessageReceivedEvent:(void (^)(WNSMessageWebSocket*,
                                                            WNSMessageWebSocketMessageReceivedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IMessageWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->add_MessageReceived(
        Make<
            ITypedEventHandler_Windows_Networking_Sockets_MessageWebSocket_Windows_Networking_Sockets_MessageWebSocketMessageReceivedEventArgs>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMessageReceivedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IMessageWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MessageReceived(eventCookie));
}

- (RTObject<WSSIOutputStream>*)outputStream {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutputStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIOutputStream>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)connectAsync:(WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(
        _comInst->ConnectAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)setRequestHeader:(NSString*)headerName headerValue:(NSString*)headerValue {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->SetRequestHeader(nsStrToHstr(headerName).Get(), nsStrToHstr(headerValue).Get()));
}

- (EventRegistrationToken)addClosedEvent:(void (^)(RTObject<WNSIWebSocket>*, WNSWebSocketClosedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->add_Closed(
        Make<ITypedEventHandler_Windows_Networking_Sockets_IWebSocket_Windows_Networking_Sockets_WebSocketClosedEventArgs>(eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Closed(eventCookie));
}

- (void)closeWithStatus:(unsigned short)code reason:(NSString*)reason {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->CloseWithStatus(code, nsStrToHstr(reason).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (EventRegistrationToken)addServerCustomValidationRequestedEvent:
    (void (^)(WNSMessageWebSocket*, WNSWebSocketServerCustomValidationRequestedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IMessageWebSocket2>(self);
    THROW_NS_IF_FAILED(_comInst->add_ServerCustomValidationRequested(
        Make<
            ITypedEventHandler_Windows_Networking_Sockets_MessageWebSocket_Windows_Networking_Sockets_WebSocketServerCustomValidationRequestedEventArgs>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeServerCustomValidationRequestedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IMessageWebSocket2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ServerCustomValidationRequested(eventCookie));
}

@end

@implementation WNSMessageWebSocketMessageReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IMessageWebSocketMessageReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNSSocketMessageType)messageType {
    ABI::Windows::Networking::Sockets::SocketMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IMessageWebSocketMessageReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageType(&unmarshalledReturn));
    return (WNSSocketMessageType)unmarshalledReturn;
}

- (WSSDataReader*)getDataReader {
    ComPtr<ABI::Windows::Storage::Streams::IDataReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IMessageWebSocketMessageReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDataReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSDataReader>(unmarshalledReturn.Get());
}

- (RTObject<WSSIInputStream>*)getDataStream {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IMessageWebSocketMessageReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDataStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

@end

@implementation WNSWebSocketServerCustomValidationRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IWebSocketServerCustomValidationRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSCCCertificate*)serverCertificate {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketServerCustomValidationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (WNSSocketSslErrorSeverity)serverCertificateErrorSeverity {
    ABI::Windows::Networking::Sockets::SocketSslErrorSeverity unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketServerCustomValidationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificateErrorSeverity(&unmarshalledReturn));
    return (WNSSocketSslErrorSeverity)unmarshalledReturn;
}

- (NSArray* /* WSCCChainValidationResult */)serverCertificateErrors {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketServerCustomValidationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificateErrors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCChainValidationResult_create(unmarshalledReturn.Get());
}

- (NSArray* /* WSCCCertificate* */)serverIntermediateCertificates {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketServerCustomValidationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerIntermediateCertificates(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCCertificate_create(unmarshalledReturn.Get());
}

- (void)reject {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketServerCustomValidationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->Reject());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketServerCustomValidationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WNSStreamWebSocketControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamWebSocketControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)noDelay {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_NoDelay(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setNoDelay:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_NoDelay((boolean)value));
}

- (unsigned int)outboundBufferSizeInBytes {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutboundBufferSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOutboundBufferSizeInBytes:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutboundBufferSizeInBytes(value));
}

- (WSCPasswordCredential*)serverCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setServerCredential:(WSCPasswordCredential*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ServerCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(value).Get()));
}

- (WSCPasswordCredential*)proxyCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProxyCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setProxyCredential:(WSCPasswordCredential*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ProxyCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(value).Get()));
}

- (NSMutableArray* /* NSString * */)supportedProtocols {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedProtocols(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WSCCChainValidationResult */)ignorableServerCertificateErrors {
    ComPtr<IVector<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IgnorableServerCertificateErrors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WSCCChainValidationResult_create(unmarshalledReturn.Get());
}

@end

@implementation WNSStreamWebSocketInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IWebSocketInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNHostName*)localAddress {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalAddress(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (WNSBandwidthStatistics*)bandwidthStatistics {
    ABI::Windows::Networking::Sockets::BandwidthStatistics unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_BandwidthStatistics(&unmarshalledReturn));
    return WNSBandwidthStatistics_create(unmarshalledReturn);
}

- (NSString*)protocol {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Protocol(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSCCCertificate*)serverCertificate {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (WNSSocketSslErrorSeverity)serverCertificateErrorSeverity {
    ABI::Windows::Networking::Sockets::SocketSslErrorSeverity unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificateErrorSeverity(&unmarshalledReturn));
    return (WNSSocketSslErrorSeverity)unmarshalledReturn;
}

- (NSArray* /* WSCCChainValidationResult */)serverCertificateErrors {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificateErrors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCChainValidationResult_create(unmarshalledReturn.Get());
}

- (NSArray* /* WSCCCertificate* */)serverIntermediateCertificates {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocketInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerIntermediateCertificates(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCCertificate_create(unmarshalledReturn.Get());
}

@end

@implementation WNSStreamWebSocket

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamWebSocket> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Sockets.StreamWebSocket").Get(), &out));
    return [_createRtProxy<WNSStreamWebSocket>(out.Get()) retain];
}

- (WNSStreamWebSocketControl*)control {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamWebSocketControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->get_Control(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSStreamWebSocketControl>(unmarshalledReturn.Get());
}

- (WNSStreamWebSocketInformation*)information {
    ComPtr<ABI::Windows::Networking::Sockets::IWebSocketInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->get_Information(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSStreamWebSocketInformation>(unmarshalledReturn.Get());
}

- (RTObject<WSSIInputStream>*)inputStream {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

- (RTObject<WSSIOutputStream>*)outputStream {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutputStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIOutputStream>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)connectAsync:(WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(
        _comInst->ConnectAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)setRequestHeader:(NSString*)headerName headerValue:(NSString*)headerValue {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->SetRequestHeader(nsStrToHstr(headerName).Get(), nsStrToHstr(headerValue).Get()));
}

- (EventRegistrationToken)addClosedEvent:(void (^)(RTObject<WNSIWebSocket>*, WNSWebSocketClosedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->add_Closed(
        Make<ITypedEventHandler_Windows_Networking_Sockets_IWebSocket_Windows_Networking_Sockets_WebSocketClosedEventArgs>(eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Closed(eventCookie));
}

- (void)closeWithStatus:(unsigned short)code reason:(NSString*)reason {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IWebSocket>(self);
    THROW_NS_IF_FAILED(_comInst->CloseWithStatus(code, nsStrToHstr(reason).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (EventRegistrationToken)addServerCustomValidationRequestedEvent:
    (void (^)(WNSStreamWebSocket*, WNSWebSocketServerCustomValidationRequestedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamWebSocket2>(self);
    THROW_NS_IF_FAILED(_comInst->add_ServerCustomValidationRequested(
        Make<
            ITypedEventHandler_Windows_Networking_Sockets_StreamWebSocket_Windows_Networking_Sockets_WebSocketServerCustomValidationRequestedEventArgs>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeServerCustomValidationRequestedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IStreamWebSocket2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ServerCustomValidationRequested(eventCookie));
}

@end

@implementation WNSWebSocketKeepAlive

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTask> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Sockets.WebSocketKeepAlive").Get(), &out));
    return [_createRtProxy<WNSWebSocketKeepAlive>(out.Get()) retain];
}

- (void)run:(RTObject<WABIBackgroundTaskInstance>*)taskInstance {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTask>(self);
    THROW_NS_IF_FAILED(
        _comInst->Run(_getRtInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(taskInstance).Get()));
}

@end

@implementation WNSSocketError

ComPtr<ABI::Windows::Networking::Sockets::ISocketErrorStatics> WNSISocketErrorStatics_inst() {
    ComPtr<ABI::Windows::Networking::Sockets::ISocketErrorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Sockets.SocketError").Get(), &inst));
    return inst;
}

+ (WNSSocketErrorStatus)getStatus:(int)hresult {
    ABI::Windows::Networking::Sockets::SocketErrorStatus unmarshalledReturn;
    auto _comInst = WNSISocketErrorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetStatus(hresult, &unmarshalledReturn));
    return (WNSSocketErrorStatus)unmarshalledReturn;
}

@end

@implementation WNSWebSocketError

ComPtr<ABI::Windows::Networking::Sockets::IWebSocketErrorStatics> WNSIWebSocketErrorStatics_inst() {
    ComPtr<ABI::Windows::Networking::Sockets::IWebSocketErrorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Sockets.WebSocketError").Get(), &inst));
    return inst;
}

+ (WWWebErrorStatus)getStatus:(int)hresult {
    ABI::Windows::Web::WebErrorStatus unmarshalledReturn;
    auto _comInst = WNSIWebSocketErrorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetStatus(hresult, &unmarshalledReturn));
    return (WWWebErrorStatus)unmarshalledReturn;
}

@end

@implementation WNSSocketActivityTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::ISocketActivityTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNSSocketActivityTriggerReason)reason {
    ABI::Windows::Networking::Sockets::SocketActivityTriggerReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::ISocketActivityTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reason(&unmarshalledReturn));
    return (WNSSocketActivityTriggerReason)unmarshalledReturn;
}

- (WNSSocketActivityInformation*)socketInformation {
    ComPtr<ABI::Windows::Networking::Sockets::ISocketActivityInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::ISocketActivityTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_SocketInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSSocketActivityInformation>(unmarshalledReturn.Get());
}

@end

@implementation WNSControlChannelTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Sockets::IControlChannelTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Networking::Sockets::IControlChannelTriggerFactory> WNSIControlChannelTriggerFactory_inst() {
    ComPtr<ABI::Windows::Networking::Sockets::IControlChannelTriggerFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Sockets.ControlChannelTrigger").Get(),
                                                       &inst));
    return inst;
}

+ (WNSControlChannelTrigger*)makeControlChannelTrigger:(NSString*)channelId
                      serverKeepAliveIntervalInMinutes:(unsigned int)serverKeepAliveIntervalInMinutes {
    ComPtr<ABI::Windows::Networking::Sockets::IControlChannelTrigger> unmarshalledReturn;
    auto _comInst = WNSIControlChannelTriggerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateControlChannelTrigger(nsStrToHstr(channelId).Get(),
                                                             serverKeepAliveIntervalInMinutes,
                                                             unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNSControlChannelTrigger>(unmarshalledReturn.Get()) retain];
}

+ (WNSControlChannelTrigger*)makeControlChannelTriggerEx:(NSString*)channelId
                        serverKeepAliveIntervalInMinutes:(unsigned int)serverKeepAliveIntervalInMinutes
                                     resourceRequestType:(WNSControlChannelTriggerResourceType)resourceRequestType {
    ComPtr<ABI::Windows::Networking::Sockets::IControlChannelTrigger> unmarshalledReturn;
    auto _comInst = WNSIControlChannelTriggerFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateControlChannelTriggerEx(nsStrToHstr(channelId).Get(),
                                                serverKeepAliveIntervalInMinutes,
                                                (ABI::Windows::Networking::Sockets::ControlChannelTriggerResourceType)resourceRequestType,
                                                unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNSControlChannelTrigger>(unmarshalledReturn.Get()) retain];
}

- (NSString*)controlChannelTriggerId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IControlChannelTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_ControlChannelTriggerId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned int)serverKeepAliveIntervalInMinutes {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IControlChannelTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerKeepAliveIntervalInMinutes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setServerKeepAliveIntervalInMinutes:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IControlChannelTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->put_ServerKeepAliveIntervalInMinutes(value));
}

- (unsigned int)currentKeepAliveIntervalInMinutes {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IControlChannelTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentKeepAliveIntervalInMinutes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject*)transportObject {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IControlChannelTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportObject(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject<WABIBackgroundTrigger>*)keepAliveTrigger {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IControlChannelTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeepAliveTrigger(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABIBackgroundTrigger>(unmarshalledReturn.Get());
}

- (RTObject<WABIBackgroundTrigger>*)pushNotificationTrigger {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IControlChannelTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_PushNotificationTrigger(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABIBackgroundTrigger>(unmarshalledReturn.Get());
}

- (void)usingTransport:(RTObject*)transport {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IControlChannelTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->UsingTransport([transport comObj].Get()));
}

- (WNSControlChannelTriggerStatus)waitForPushEnabled {
    ABI::Windows::Networking::Sockets::ControlChannelTriggerStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IControlChannelTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->WaitForPushEnabled(&unmarshalledReturn));
    return (WNSControlChannelTriggerStatus)unmarshalledReturn;
}

- (void)decreaseNetworkKeepAliveInterval {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IControlChannelTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->DecreaseNetworkKeepAliveInterval());
}

- (void)flushTransport {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IControlChannelTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->FlushTransport());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (BOOL)isWakeFromLowPowerSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Sockets::IControlChannelTrigger2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsWakeFromLowPowerSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNSRoundTripTimeStatistics {
    ABI::Windows::Networking::Sockets::RoundTripTimeStatistics structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Networking::Sockets::RoundTripTimeStatistics)s {
    WNSRoundTripTimeStatistics* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Networking::Sockets::RoundTripTimeStatistics*)internalStruct {
    return &structVal;
}
- (unsigned int)variance {
    return structVal.Variance;
}
- (void)setVariance:(unsigned int)val {
    structVal.Variance = val;
}
- (unsigned int)max {
    return structVal.Max;
}
- (void)setMax:(unsigned int)val {
    structVal.Max = val;
}
- (unsigned int)min {
    return structVal.Min;
}
- (void)setMin:(unsigned int)val {
    structVal.Min = val;
}
- (unsigned int)sum {
    return structVal.Sum;
}
- (void)setSum:(unsigned int)val {
    structVal.Sum = val;
}
@end
@implementation WNSBandwidthStatistics {
    ABI::Windows::Networking::Sockets::BandwidthStatistics structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Networking::Sockets::BandwidthStatistics)s {
    WNSBandwidthStatistics* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Networking::Sockets::BandwidthStatistics*)internalStruct {
    return &structVal;
}
- (uint64_t)outboundBitsPerSecond {
    return structVal.OutboundBitsPerSecond;
}
- (void)setOutboundBitsPerSecond:(uint64_t)val {
    structVal.OutboundBitsPerSecond = val;
}
- (uint64_t)inboundBitsPerSecond {
    return structVal.InboundBitsPerSecond;
}
- (void)setInboundBitsPerSecond:(uint64_t)val {
    structVal.InboundBitsPerSecond = val;
}
- (uint64_t)outboundBitsPerSecondInstability {
    return structVal.OutboundBitsPerSecondInstability;
}
- (void)setOutboundBitsPerSecondInstability:(uint64_t)val {
    structVal.OutboundBitsPerSecondInstability = val;
}
- (uint64_t)inboundBitsPerSecondInstability {
    return structVal.InboundBitsPerSecondInstability;
}
- (void)setInboundBitsPerSecondInstability:(uint64_t)val {
    structVal.InboundBitsPerSecondInstability = val;
}
- (BOOL)outboundBandwidthPeaked {
    return (BOOL)structVal.OutboundBandwidthPeaked;
}
- (void)setOutboundBandwidthPeaked:(BOOL)val {
    structVal.OutboundBandwidthPeaked = (boolean)val;
}
- (BOOL)inboundBandwidthPeaked {
    return (BOOL)structVal.InboundBandwidthPeaked;
}
- (void)setInboundBandwidthPeaked:(BOOL)val {
    structVal.InboundBandwidthPeaked = (boolean)val;
}
@end
id RTProxiedNSArray_WNEndpointPair_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::EndpointPair*>,
                                         RTArrayObj<ABI::Windows::Networking::IEndpointPair*,
                                                    IVectorView<ABI::Windows::Networking::EndpointPair*>,
                                                    WNEndpointPair,
                                                    ABI::Windows::Networking::EndpointPair*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSCCChainValidationResult_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>,
                                         RTArrayObj<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult,
                                                    IVectorView<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>,
                                                    WSCCChainValidationResult,
                                                    ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_WNSSocketActivityInformation_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<DictionaryAdapterObj<
        IMapView<HSTRING, ABI::Windows::Networking::Sockets::SocketActivityInformation*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::Networking::Sockets::SocketActivityInformation*>>,
        RTMapViewObj<HSTRING,
                     HSTRING,
                     ABI::Windows::Networking::Sockets::SocketActivityInformation*,
                     ABI::Windows::Networking::Sockets::ISocketActivityInformation*,
                     NSString,
                     WNSSocketActivityInformation,
                     IMapView<HSTRING, ABI::Windows::Networking::Sockets::SocketActivityInformation*>,
                     dummyObjCCreator,
                     dummyObjCCreator,
                     dummyWRLCreator,
                     dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WSCCChainValidationResult_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>,
                               RTMutableArrayObj<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult,
                                                 IVector<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>,
                                                 WSCCChainValidationResult,
                                                 ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
