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

// WindowsDevicesWiFiDirectServices.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.WiFiDirect.Services.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesWiFiDirectServices.h"
#include "WindowsDevicesWiFiDirectServices_priv.h"

@implementation WDWSWiFiDirectServiceProvisioningInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDWSWiFiDirectServiceConfigurationMethod)selectedConfigurationMethod {
    ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedConfigurationMethod(&unmarshalledReturn));
    return (WDWSWiFiDirectServiceConfigurationMethod)unmarshalledReturn;
}

- (BOOL)isGroupFormationNeeded {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsGroupFormationNeeded(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDWSWiFiDirectServiceSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)serviceName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDWSWiFiDirectServiceSessionStatus)status {
    ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDWSWiFiDirectServiceSessionStatus)unmarshalledReturn;
}

- (WDWSWiFiDirectServiceSessionErrorStatus)errorStatus {
    ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionErrorStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorStatus(&unmarshalledReturn));
    return (WDWSWiFiDirectServiceSessionErrorStatus)unmarshalledReturn;
}

- (unsigned int)sessionId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_SessionId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)advertisementId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdvertisementId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)serviceAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)sessionAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_SessionAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* WNEndpointPair* */)getConnectionEndpointPairs {
    ComPtr<IVectorView<ABI::Windows::Networking::EndpointPair*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession>(self);
    THROW_NS_IF_FAILED(_comInst->GetConnectionEndpointPairs(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNEndpointPair_create(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addSessionStatusChangedEvent:(void (^)(WDWSWiFiDirectServiceSession*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession>(self);
    THROW_NS_IF_FAILED(_comInst->add_SessionStatusChanged(
        Make<ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSession_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSessionStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SessionStatusChanged(token));
}

- (RTObject<WFIAsyncAction>*)addStreamSocketListenerAsync:(WNSStreamSocketListener*)value {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddStreamSocketListenerAsync(_getRtInterface<ABI::Windows::Networking::Sockets::IStreamSocketListener>(value).Get(),
                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)addDatagramSocketAsync:(WNSDatagramSocket*)value {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession>(self);
    THROW_NS_IF_FAILED(_comInst->AddDatagramSocketAsync(_getRtInterface<ABI::Windows::Networking::Sockets::IDatagramSocket>(value).Get(),
                                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addRemotePortAddedEvent:(void (^)(WDWSWiFiDirectServiceSession*,
                                                            WDWSWiFiDirectServiceRemotePortAddedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession>(self);
    THROW_NS_IF_FAILED(_comInst->add_RemotePortAdded(
        Make<
            ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSession_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceRemotePortAddedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRemotePortAddedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RemotePortAdded(token));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDWSWiFiDirectServiceAutoAcceptSessionConnectedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDWSWiFiDirectServiceSession*)session {
    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Session(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDWSWiFiDirectServiceSession>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)sessionInfo {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SessionInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WDWSWiFiDirectServiceRemotePortAddedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceRemotePortAddedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WNEndpointPair* */)endpointPairs {
    ComPtr<IVectorView<ABI::Windows::Networking::EndpointPair*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceRemotePortAddedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndpointPairs(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNEndpointPair_create(unmarshalledReturn.Get());
}

- (WDWSWiFiDirectServiceIPProtocol)protocol {
    ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceIPProtocol unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceRemotePortAddedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Protocol(&unmarshalledReturn));
    return (WDWSWiFiDirectServiceIPProtocol)unmarshalledReturn;
}

@end

@implementation WDWSWiFiDirectServiceSessionDeferredEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionDeferredEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIBuffer>*)deferredSessionInfo {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionDeferredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeferredSessionInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WDWSWiFiDirectServiceSessionRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDEDeviceInformation*)deviceInformation {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformation>(unmarshalledReturn.Get());
}

- (WDWSWiFiDirectServiceProvisioningInfo*)provisioningInfo {
    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProvisioningInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDWSWiFiDirectServiceProvisioningInfo>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)sessionInfo {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_SessionInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDWSWiFiDirectServiceSessionRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDWSWiFiDirectServiceSessionRequest*)getSessionRequest {
    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetSessionRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDWSWiFiDirectServiceSessionRequest>(unmarshalledReturn.Get());
}

@end

@implementation WDWSWiFiDirectServiceAdvertiser

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiserFactory>
WDWSIWiFiDirectServiceAdvertiserFactory_inst() {
    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiserFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.WiFiDirect.Services.WiFiDirectServiceAdvertiser").Get(), &inst));
    return inst;
}

+ (WDWSWiFiDirectServiceAdvertiser*)makeWiFiDirectServiceAdvertiser:(NSString*)serviceName {
    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser> unmarshalledReturn;
    auto _comInst = WDWSIWiFiDirectServiceAdvertiserFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWiFiDirectServiceAdvertiser(nsStrToHstr(serviceName).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDWSWiFiDirectServiceAdvertiser>(unmarshalledReturn.Get()) retain];
}

- (NSString*)serviceName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSMutableArray* /* NSString * */)serviceNamePrefixes {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceNamePrefixes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)serviceInfo {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setServiceInfo:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->put_ServiceInfo(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (BOOL)autoAcceptSession {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoAcceptSession(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAutoAcceptSession:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoAcceptSession((boolean)value));
}

- (BOOL)preferGroupOwnerMode {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreferGroupOwnerMode(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setPreferGroupOwnerMode:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->put_PreferGroupOwnerMode((boolean)value));
}

- (NSMutableArray* /* WDWSWiFiDirectServiceConfigurationMethod */)preferredConfigurationMethods {
    ComPtr<IVector<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreferredConfigurationMethods(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDWSWiFiDirectServiceConfigurationMethod_create(unmarshalledReturn.Get());
}

- (WDWSWiFiDirectServiceStatus)serviceStatus {
    ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceStatus(&unmarshalledReturn));
    return (WDWSWiFiDirectServiceStatus)unmarshalledReturn;
}

- (void)setServiceStatus:(WDWSWiFiDirectServiceStatus)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->put_ServiceStatus((ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceStatus)value));
}

- (unsigned int)customServiceStatusCode {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomServiceStatusCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCustomServiceStatusCode:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->put_CustomServiceStatusCode(value));
}

- (RTObject<WSSIBuffer>*)deferredSessionInfo {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeferredSessionInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setDeferredSessionInfo:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->put_DeferredSessionInfo(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (WDWSWiFiDirectServiceAdvertisementStatus)advertisementStatus {
    ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertisementStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdvertisementStatus(&unmarshalledReturn));
    return (WDWSWiFiDirectServiceAdvertisementStatus)unmarshalledReturn;
}

- (WDWSWiFiDirectServiceError)serviceError {
    ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceError unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceError(&unmarshalledReturn));
    return (WDWSWiFiDirectServiceError)unmarshalledReturn;
}

- (EventRegistrationToken)addSessionRequestedEvent:(void (^)(WDWSWiFiDirectServiceAdvertiser*,
                                                             WDWSWiFiDirectServiceSessionRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->add_SessionRequested(
        Make<
            ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSessionRequestedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSessionRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SessionRequested(token));
}

- (EventRegistrationToken)addAutoAcceptSessionConnectedEvent:(void (^)(WDWSWiFiDirectServiceAdvertiser*,
                                                                       WDWSWiFiDirectServiceAutoAcceptSessionConnectedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->add_AutoAcceptSessionConnected(
        Make<
            ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAutoAcceptSessionConnectedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAutoAcceptSessionConnectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AutoAcceptSessionConnected(token));
}

- (EventRegistrationToken)addAdvertisementStatusChangedEvent:(void (^)(WDWSWiFiDirectServiceAdvertiser*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->add_AdvertisementStatusChanged(
        Make<ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAdvertisementStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AdvertisementStatusChanged(token));
}

- (void)connectAsync:(WDEDeviceInformation*)deviceInfo
             success:(void (^)(WDWSWiFiDirectServiceSession*))success
             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->ConnectAsync(_getRtInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(deviceInfo).Get(),
                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDWSWiFiDirectServiceSession>(result.Get()));
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

- (void)connectAsyncWithPin:(WDEDeviceInformation*)deviceInfo
                        pin:(NSString*)pin
                    success:(void (^)(WDWSWiFiDirectServiceSession*))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(
        _comInst->ConnectAsyncWithPin(_getRtInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(deviceInfo).Get(),
                                      nsStrToHstr(pin).Get(),
                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDWSWiFiDirectServiceSession>(result.Get()));
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

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

@end

@implementation WDWSWiFiDirectService

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceStatics> WDWSIWiFiDirectServiceStatics_inst() {
    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.WiFiDirect.Services.WiFiDirectService").Get(), &inst));
    return inst;
}

+ (NSString*)getSelector:(NSString*)serviceName {
    HSTRING unmarshalledReturn;
    auto _comInst = WDWSIWiFiDirectServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetSelector(nsStrToHstr(serviceName).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getSelectorWithFilter:(NSString*)serviceName serviceInfoFilter:(RTObject<WSSIBuffer>*)serviceInfoFilter {
    HSTRING unmarshalledReturn;
    auto _comInst = WDWSIWiFiDirectServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetSelectorWithFilter(nsStrToHstr(serviceName).Get(),
                                                       _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(serviceInfoFilter).Get(),
                                                       &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDWSWiFiDirectService*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectService*>> unmarshalledReturn;
    auto _comInst = WDWSIWiFiDirectServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectService*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectService*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDWSWiFiDirectService>(result.Get()));
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

- (RTObject<WSSIBuffer>*)remoteServiceInfo {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteServiceInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (NSArray* /* WDWSWiFiDirectServiceConfigurationMethod */)supportedConfigurationMethods {
    ComPtr<IVectorView<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedConfigurationMethods(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDWSWiFiDirectServiceConfigurationMethod_create(unmarshalledReturn.Get());
}

- (BOOL)preferGroupOwnerMode {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreferGroupOwnerMode(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setPreferGroupOwnerMode:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService>(self);
    THROW_NS_IF_FAILED(_comInst->put_PreferGroupOwnerMode((boolean)value));
}

- (RTObject<WSSIBuffer>*)sessionInfo {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService>(self);
    THROW_NS_IF_FAILED(_comInst->get_SessionInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setSessionInfo:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService>(self);
    THROW_NS_IF_FAILED(_comInst->put_SessionInfo(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (WDWSWiFiDirectServiceError)serviceError {
    ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceError unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceError(&unmarshalledReturn));
    return (WDWSWiFiDirectServiceError)unmarshalledReturn;
}

- (EventRegistrationToken)addSessionDeferredEvent:(void (^)(WDWSWiFiDirectService*,
                                                            WDWSWiFiDirectServiceSessionDeferredEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService>(self);
    THROW_NS_IF_FAILED(_comInst->add_SessionDeferred(
        Make<
            ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectService_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSessionDeferredEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSessionDeferredEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SessionDeferred(token));
}

- (void)getProvisioningInfoAsync:(WDWSWiFiDirectServiceConfigurationMethod)selectedConfigurationMethod
                         success:(void (^)(WDWSWiFiDirectServiceProvisioningInfo*))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceProvisioningInfo*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetProvisioningInfoAsync((ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod)
                                               selectedConfigurationMethod,
                                           &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceProvisioningInfo*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceProvisioningInfo*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDWSWiFiDirectServiceProvisioningInfo>(result.Get()));
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

- (void)connectAsyncWithSuccess:(void (^)(WDWSWiFiDirectServiceSession*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService>(self);
    THROW_NS_IF_FAILED(_comInst->ConnectAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDWSWiFiDirectServiceSession>(result.Get()));
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

- (void)connectAsyncWithPin:(NSString*)pin success:(void (^)(WDWSWiFiDirectServiceSession*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService>(self);
    THROW_NS_IF_FAILED(_comInst->ConnectAsyncWithPin(nsStrToHstr(pin).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDWSWiFiDirectServiceSession>(result.Get()));
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

@end

id RTProxiedNSArray_WDWSWiFiDirectServiceConfigurationMethod_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod>,
                        RTArrayObj<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod,
                                   IVectorView<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod>,
                                   WDWSWiFiDirectServiceConfigurationMethod,
                                   ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

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

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WDWSWiFiDirectServiceConfigurationMethod_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod>,
                               RTMutableArrayObj<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod,
                                                 IVector<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod>,
                                                 WDWSWiFiDirectServiceConfigurationMethod,
                                                 ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
