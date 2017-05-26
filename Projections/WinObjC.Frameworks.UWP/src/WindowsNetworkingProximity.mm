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

// WindowsNetworkingProximity.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Networking.Proximity.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsNetworkingProximity.h"
#include "WindowsNetworkingProximity_priv.h"

@implementation WNPProximityMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Proximity::IProximityMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)messageType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int64_t)subscriptionId {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_SubscriptionId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (NSString*)dataAsString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataAsString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNPProximityDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Proximity::IProximityDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Networking::Proximity::IProximityDeviceStatics> WNPIProximityDeviceStatics_inst() {
    ComPtr<ABI::Windows::Networking::Proximity::IProximityDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Proximity.ProximityDevice").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WNPIProximityDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (WNPProximityDevice*)getDefault {
    ComPtr<ABI::Windows::Networking::Proximity::IProximityDevice> unmarshalledReturn;
    auto _comInst = WNPIProximityDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNPProximityDevice>(unmarshalledReturn.Get());
}

+ (WNPProximityDevice*)fromId:(NSString*)deviceId {
    ComPtr<ABI::Windows::Networking::Proximity::IProximityDevice> unmarshalledReturn;
    auto _comInst = WNPIProximityDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromId(nsStrToHstr(deviceId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNPProximityDevice>(unmarshalledReturn.Get());
}

- (int64_t)subscribeForMessage:(NSString*)messageType messageReceivedHandler:(WNPMessageReceivedHandler)messageReceivedHandler {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityDevice>(self);
    THROW_NS_IF_FAILED(_comInst->SubscribeForMessage(nsStrToHstr(messageType).Get(),
                                                     Make<WNPMessageReceivedHandler_shim>(messageReceivedHandler).Get(),
                                                     &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)publishMessage:(NSString*)messageType message:(NSString*)message {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityDevice>(self);
    THROW_NS_IF_FAILED(_comInst->PublishMessage(nsStrToHstr(messageType).Get(), nsStrToHstr(message).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)publishMessageWithCallback:(NSString*)messageType
                              message:(NSString*)message
            messageTransmittedHandler:(WNPMessageTransmittedHandler)messageTransmittedHandler {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityDevice>(self);
    THROW_NS_IF_FAILED(_comInst->PublishMessageWithCallback(nsStrToHstr(messageType).Get(),
                                                            nsStrToHstr(message).Get(),
                                                            Make<WNPMessageTransmittedHandler_shim>(messageTransmittedHandler).Get(),
                                                            &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)publishBinaryMessage:(NSString*)messageType message:(RTObject<WSSIBuffer>*)message {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityDevice>(self);
    THROW_NS_IF_FAILED(_comInst->PublishBinaryMessage(nsStrToHstr(messageType).Get(),
                                                      _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(message).Get(),
                                                      &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)publishBinaryMessageWithCallback:(NSString*)messageType
                                    message:(RTObject<WSSIBuffer>*)message
                  messageTransmittedHandler:(WNPMessageTransmittedHandler)messageTransmittedHandler {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityDevice>(self);
    THROW_NS_IF_FAILED(_comInst->PublishBinaryMessageWithCallback(nsStrToHstr(messageType).Get(),
                                                                  _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(message).Get(),
                                                                  Make<WNPMessageTransmittedHandler_shim>(messageTransmittedHandler).Get(),
                                                                  &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)publishUriMessage:(WFUri*)message {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->PublishUriMessage(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(message).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)publishUriMessageWithCallback:(WFUri*)message messageTransmittedHandler:(WNPMessageTransmittedHandler)messageTransmittedHandler {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityDevice>(self);
    THROW_NS_IF_FAILED(_comInst->PublishUriMessageWithCallback(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(message).Get(),
                                                               Make<WNPMessageTransmittedHandler_shim>(messageTransmittedHandler).Get(),
                                                               &unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)stopSubscribingForMessage:(int64_t)subscriptionId {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityDevice>(self);
    THROW_NS_IF_FAILED(_comInst->StopSubscribingForMessage(subscriptionId));
}

- (void)stopPublishingMessage:(int64_t)messageId {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityDevice>(self);
    THROW_NS_IF_FAILED(_comInst->StopPublishingMessage(messageId));
}

- (EventRegistrationToken)addDeviceArrivedEvent:(WNPDeviceArrivedEventHandler)arrivedHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityDevice>(self);
    THROW_NS_IF_FAILED(_comInst->add_DeviceArrived(Make<WNPDeviceArrivedEventHandler_shim>(arrivedHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDeviceArrivedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DeviceArrived(cookie));
}

- (EventRegistrationToken)addDeviceDepartedEvent:(WNPDeviceDepartedEventHandler)departedHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityDevice>(self);
    THROW_NS_IF_FAILED(_comInst->add_DeviceDeparted(Make<WNPDeviceDepartedEventHandler_shim>(departedHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDeviceDepartedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DeviceDeparted(cookie));
}

- (unsigned int)maxMessageBytes {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxMessageBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)bitsPerSecond {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitsPerSecond(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IProximityDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNPTriggeredConnectionStateChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Proximity::ITriggeredConnectionStateChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNPTriggeredConnectState)state {
    ABI::Windows::Networking::Proximity::TriggeredConnectState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::ITriggeredConnectionStateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WNPTriggeredConnectState)unmarshalledReturn;
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::ITriggeredConnectionStateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WNSStreamSocket*)socket {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocket> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::ITriggeredConnectionStateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Socket(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSStreamSocket>(unmarshalledReturn.Get());
}

@end

@implementation WNPPeerInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Proximity::IPeerInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerInformation3>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)discoveryData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerInformation3>(self);
    THROW_NS_IF_FAILED(_comInst->get_DiscoveryData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WNHostName*)hostName {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerInformationWithHostAndService>(self);
    THROW_NS_IF_FAILED(_comInst->get_HostName(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (NSString*)serviceName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerInformationWithHostAndService>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNPConnectionRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Proximity::IConnectionRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNPPeerInformation*)peerInformation {
    ComPtr<ABI::Windows::Networking::Proximity::IPeerInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IConnectionRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PeerInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNPPeerInformation>(unmarshalledReturn.Get());
}

@end

@implementation WNPPeerWatcher

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Proximity::IPeerWatcher> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addAddedEvent:(void (^)(WNPPeerWatcher*, WNPPeerInformation*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Added(
        Make<ITypedEventHandler_Windows_Networking_Proximity_PeerWatcher_Windows_Networking_Proximity_PeerInformation>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAddedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Added(token));
}

- (EventRegistrationToken)addRemovedEvent:(void (^)(WNPPeerWatcher*, WNPPeerInformation*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Removed(
        Make<ITypedEventHandler_Windows_Networking_Proximity_PeerWatcher_Windows_Networking_Proximity_PeerInformation>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Removed(token));
}

- (EventRegistrationToken)addUpdatedEvent:(void (^)(WNPPeerWatcher*, WNPPeerInformation*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Updated(
        Make<ITypedEventHandler_Windows_Networking_Proximity_PeerWatcher_Windows_Networking_Proximity_PeerInformation>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Updated(token));
}

- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WNPPeerWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerWatcher>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_EnumerationCompleted(Make<ITypedEventHandler_Windows_Networking_Proximity_PeerWatcher_System_Object>(handler).Get(),
                                           &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_EnumerationCompleted(token));
}

- (EventRegistrationToken)addStoppedEvent:(void (^)(WNPPeerWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Stopped(Make<ITypedEventHandler_Windows_Networking_Proximity_PeerWatcher_System_Object>(handler).Get(),
                                             &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStoppedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Stopped(token));
}

- (WNPPeerWatcherStatus)status {
    ABI::Windows::Networking::Proximity::PeerWatcherStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WNPPeerWatcherStatus)unmarshalledReturn;
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Proximity::IPeerWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

@end

@implementation WNPPeerFinder

ComPtr<ABI::Windows::Networking::Proximity::IPeerFinderStatics2> WNPIPeerFinderStatics2_inst() {
    ComPtr<ABI::Windows::Networking::Proximity::IPeerFinderStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Proximity.PeerFinder").Get(), &inst));
    return inst;
}

+ (WNPPeerRole)role {
    ABI::Windows::Networking::Proximity::PeerRole unmarshalledReturn;
    auto _comInst = WNPIPeerFinderStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_Role(&unmarshalledReturn));
    return (WNPPeerRole)unmarshalledReturn;
}

+ (void)setRole:(WNPPeerRole)value {
    auto _comInst = WNPIPeerFinderStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->put_Role((ABI::Windows::Networking::Proximity::PeerRole)value));
}

+ (RTObject<WSSIBuffer>*)discoveryData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = WNPIPeerFinderStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_DiscoveryData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

+ (void)setDiscoveryData:(RTObject<WSSIBuffer>*)value {
    auto _comInst = WNPIPeerFinderStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->put_DiscoveryData(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

+ (WNPPeerWatcher*)createWatcher {
    ComPtr<ABI::Windows::Networking::Proximity::IPeerWatcher> unmarshalledReturn;
    auto _comInst = WNPIPeerFinderStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNPPeerWatcher>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Networking::Proximity::IPeerFinderStatics> WNPIPeerFinderStatics_inst() {
    ComPtr<ABI::Windows::Networking::Proximity::IPeerFinderStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Proximity.PeerFinder").Get(), &inst));
    return inst;
}

+ (BOOL)allowBluetooth {
    boolean unmarshalledReturn;
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllowBluetooth(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setAllowBluetooth:(BOOL)value {
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->put_AllowBluetooth((boolean)value));
}

+ (BOOL)allowInfrastructure {
    boolean unmarshalledReturn;
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllowInfrastructure(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setAllowInfrastructure:(BOOL)value {
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->put_AllowInfrastructure((boolean)value));
}

+ (BOOL)allowWiFiDirect {
    boolean unmarshalledReturn;
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllowWiFiDirect(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setAllowWiFiDirect:(BOOL)value {
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->put_AllowWiFiDirect((boolean)value));
}

+ (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setDisplayName:(NSString*)value {
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

+ (WNPPeerDiscoveryTypes)supportedDiscoveryTypes {
    ABI::Windows::Networking::Proximity::PeerDiscoveryTypes unmarshalledReturn;
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SupportedDiscoveryTypes(&unmarshalledReturn));
    return (WNPPeerDiscoveryTypes)unmarshalledReturn;
}

+ (NSMutableDictionary* /* NSString *, NSString * */)alternateIdentities {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AlternateIdentities(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

+ (void)start {
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Start());
}

+ (void)startWithMessage:(NSString*)peerMessage {
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->StartWithMessage(nsStrToHstr(peerMessage).Get()));
}

+ (void)stop {
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Stop());
}

+ (EventRegistrationToken)addTriggeredConnectionStateChangedEvent:(void (^)(RTObject*,
                                                                            WNPTriggeredConnectionStateChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_TriggeredConnectionStateChanged(
        Make<ITypedEventHandler_System_Object_Windows_Networking_Proximity_TriggeredConnectionStateChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeTriggeredConnectionStateChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_TriggeredConnectionStateChanged(cookie));
}

+ (EventRegistrationToken)addConnectionRequestedEvent:(void (^)(RTObject*, WNPConnectionRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_ConnectionRequested(
        Make<ITypedEventHandler_System_Object_Windows_Networking_Proximity_ConnectionRequestedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeConnectionRequestedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_ConnectionRequested(cookie));
}

+ (void)findAllPeersAsyncWithSuccess:(void (^)(NSArray* /* WNPPeerInformation* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::Proximity::PeerInformation*>*>>
        unmarshalledReturn;
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllPeersAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Networking::Proximity::PeerInformation*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::Proximity::PeerInformation*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Networking::Proximity::PeerInformation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WNPPeerInformation_create(result.Get()));
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

+ (void)connectAsync:(WNPPeerInformation*)peerInformation success:(void (^)(WNSStreamSocket*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Sockets::StreamSocket*>> unmarshalledReturn;
    auto _comInst = WNPIPeerFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ConnectAsync(_getRtInterface<ABI::Windows::Networking::Proximity::IPeerInformation>(peerInformation).Get(),
                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::Sockets::StreamSocket*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Sockets::StreamSocket*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::Sockets::IStreamSocket> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNSStreamSocket>(result.Get()));
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

id RTProxiedNSArray_WNPPeerInformation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::Proximity::PeerInformation*>,
                                         RTArrayObj<ABI::Windows::Networking::Proximity::IPeerInformation*,
                                                    IVectorView<ABI::Windows::Networking::Proximity::PeerInformation*>,
                                                    WNPPeerInformation,
                                                    ABI::Windows::Networking::Proximity::PeerInformation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

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
