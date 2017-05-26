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

// WindowsNetworkingVpn.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Networking.Vpn.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsNetworkingVpn.h"
#include "WindowsNetworkingVpn_priv.h"

@implementation WNVIVpnPlugIn

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnPlugIn> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)connect:(WNVVpnChannel*)channel {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPlugIn>(self);
    THROW_NS_IF_FAILED(_comInst->Connect(_getRtInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(channel).Get()));
}

- (void)disconnect:(WNVVpnChannel*)channel {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPlugIn>(self);
    THROW_NS_IF_FAILED(_comInst->Disconnect(_getRtInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(channel).Get()));
}

- (void)getKeepAlivePayload:(WNVVpnChannel*)channel keepAlivePacket:(WNVVpnPacketBuffer**)keepAlivePacket {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnPacketBuffer> keepAlivePacketOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPlugIn>(self);
    THROW_NS_IF_FAILED(_comInst->GetKeepAlivePayload(_getRtInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(channel).Get(),
                                                     keepAlivePacketOutUnmarshaled.GetAddressOf()));
    *keepAlivePacket = _createRtProxy<WNVVpnPacketBuffer>(keepAlivePacketOutUnmarshaled.Get());
}

- (void)encapsulate:(WNVVpnChannel*)channel
               packets:(WNVVpnPacketBufferList*)packets
    encapulatedPackets:(WNVVpnPacketBufferList*)encapulatedPackets {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPlugIn>(self);
    THROW_NS_IF_FAILED(
        _comInst->Encapsulate(_getRtInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(channel).Get(),
                              _getRtInterface<ABI::Windows::Networking::Vpn::IVpnPacketBufferList>(packets).Get(),
                              _getRtInterface<ABI::Windows::Networking::Vpn::IVpnPacketBufferList>(encapulatedPackets).Get()));
}

- (void)decapsulate:(WNVVpnChannel*)channel
             encapBuffer:(WNVVpnPacketBuffer*)encapBuffer
     decapsulatedPackets:(WNVVpnPacketBufferList*)decapsulatedPackets
    controlPacketsToSend:(WNVVpnPacketBufferList*)controlPacketsToSend {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPlugIn>(self);
    THROW_NS_IF_FAILED(
        _comInst->Decapsulate(_getRtInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(channel).Get(),
                              _getRtInterface<ABI::Windows::Networking::Vpn::IVpnPacketBuffer>(encapBuffer).Get(),
                              _getRtInterface<ABI::Windows::Networking::Vpn::IVpnPacketBufferList>(decapsulatedPackets).Get(),
                              _getRtInterface<ABI::Windows::Networking::Vpn::IVpnPacketBufferList>(controlPacketsToSend).Get()));
}

@end

@implementation WNVIVpnCustomPrompt

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnCustomPrompt> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setLabel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Label(nsStrToHstr(value).Get()));
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCompulsory:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Compulsory((boolean)value));
}

- (BOOL)compulsory {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Compulsory(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setBordered:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Bordered((boolean)value));
}

- (BOOL)bordered {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bordered(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNVIVpnRouteFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnRouteFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNVVpnRoute*)createVpnRoute:(WNHostName*)address prefixSize:(uint8_t)prefixSize {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnRoute> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnRouteFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateVpnRoute(_getRtInterface<ABI::Windows::Networking::IHostName>(address).Get(),
                                                prefixSize,
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNVVpnRoute>(unmarshalledReturn.Get());
}

@end

@implementation WNVIVpnNamespaceInfoFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnNamespaceInfoFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNVVpnNamespaceInfo*)createVpnNamespaceInfo:(NSString*)name
                                 dnsServerList:(NSMutableArray* /* WNHostName* */)dnsServerList
                               proxyServerList:(NSMutableArray* /* WNHostName* */)proxyServerList {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnNamespaceInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNamespaceInfoFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateVpnNamespaceInfo(
        nsStrToHstr(name).Get(),
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                              ABI::Windows::Networking::IHostName*>>::type>*>(
            ConvertToVector<WNHostName,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                              ABI::Windows::Networking::IHostName*>>(dnsServerList)
                .Get()),
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                              ABI::Windows::Networking::IHostName*>>::type>*>(
            ConvertToVector<WNHostName,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                              ABI::Windows::Networking::IHostName*>>(proxyServerList)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNVVpnNamespaceInfo>(unmarshalledReturn.Get());
}

@end

@implementation WNVIVpnInterfaceIdFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnInterfaceIdFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNVVpnInterfaceId*)createVpnInterfaceId:(NSArray* /* uint8_t */)address {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnInterfaceId> unmarshalledReturn;
    UINT32 __address_ArrayLen = 0;
    bool __address_IsTemp = false;
    uint8_t* __address_Array = NULL;
    if (!ConvertToCArray<uint8_t>(address, &__address_ArrayLen, &__address_Array, &__address_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnInterfaceIdFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateVpnInterfaceId(__address_ArrayLen, __address_Array, unmarshalledReturn.GetAddressOf()));
    if (__address_IsTemp)
        CoTaskMemFree(__address_Array);
    return _createRtProxy<WNVVpnInterfaceId>(unmarshalledReturn.Get());
}

@end

@implementation WNVIVpnCredential

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnCredential> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSCPasswordCredential*)passkeyCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCredential>(self);
    THROW_NS_IF_FAILED(_comInst->get_PasskeyCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (WSCCCertificate*)certificateCredential {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCredential>(self);
    THROW_NS_IF_FAILED(_comInst->get_CertificateCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (NSString*)additionalPin {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCredential>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdditionalPin(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSCPasswordCredential*)oldPasswordCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCredential>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldPasswordCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

@end

@implementation WNVIVpnCustomPromptElement

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCompulsory:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Compulsory((boolean)value));
}

- (BOOL)compulsory {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Compulsory(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEmphasized:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Emphasized((boolean)value));
}

- (BOOL)emphasized {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Emphasized(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNVIVpnChannelStatics

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnChannelStatics> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)processEventAsync:(RTObject*)thirdPartyPlugIn event:(RTObject*)event {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannelStatics>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessEventAsync([thirdPartyPlugIn comObj].Get(), [event comObj].Get()));
}

@end

@implementation WNVIVpnPacketBufferFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnPacketBufferFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNVVpnPacketBuffer*)createVpnPacketBuffer:(WNVVpnPacketBuffer*)parentBuffer offset:(unsigned int)offset length:(unsigned int)length {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnPacketBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPacketBufferFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateVpnPacketBuffer(_getRtInterface<ABI::Windows::Networking::Vpn::IVpnPacketBuffer>(parentBuffer).Get(),
                                                       offset,
                                                       length,
                                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNVVpnPacketBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WNVIVpnDomainNameInfoFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnDomainNameInfoFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNVVpnDomainNameInfo*)createVpnDomainNameInfo:(NSString*)name
                                        nameType:(WNVVpnDomainNameType)nameType
                                   dnsServerList:(id<NSFastEnumeration> /* WNHostName* */)dnsServerList
                                 proxyServerList:(id<NSFastEnumeration> /* WNHostName* */)proxyServerList {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnDomainNameInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnDomainNameInfoFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateVpnDomainNameInfo(
        nsStrToHstr(name).Get(),
        (ABI::Windows::Networking::Vpn::VpnDomainNameType)nameType,
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                              ABI::Windows::Networking::IHostName*>>::type>*>(
            ConvertToIterable<WNHostName,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                                ABI::Windows::Networking::IHostName*>>(dnsServerList)
                .Get()),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                              ABI::Windows::Networking::IHostName*>>::type>*>(
            ConvertToIterable<WNHostName,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                                ABI::Windows::Networking::IHostName*>>(proxyServerList)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNVVpnDomainNameInfo>(unmarshalledReturn.Get());
}

@end

@implementation WNVIVpnProfile

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnProfile> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)profileName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProfileName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setProfileName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProfileName(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* WNVVpnAppId* */)appTriggers {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnAppId*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppTriggers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnAppId_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WNVVpnRoute* */)routes {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnRoute*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_Routes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnRoute_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WNVVpnDomainNameInfo* */)domainNameInfoList {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnDomainNameInfo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainNameInfoList(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnDomainNameInfo_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WNVVpnTrafficFilter* */)trafficFilters {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnTrafficFilter*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrafficFilters(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnTrafficFilter_create(unmarshalledReturn.Get());
}

- (BOOL)rememberCredentials {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_RememberCredentials(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setRememberCredentials:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_RememberCredentials((boolean)value));
}

- (BOOL)alwaysOn {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlwaysOn(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAlwaysOn:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_AlwaysOn((boolean)value));
}

@end

@implementation WNVVpnRoute

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnRoute> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Networking::Vpn::IVpnRouteFactory> WNVIVpnRouteFactory_inst() {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnRouteFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Vpn.VpnRoute").Get(), &inst));
    return inst;
}

+ (WNVVpnRoute*)makeVpnRoute:(WNHostName*)address prefixSize:(uint8_t)prefixSize {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnRoute> unmarshalledReturn;
    auto _comInst = WNVIVpnRouteFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateVpnRoute(_getRtInterface<ABI::Windows::Networking::IHostName>(address).Get(),
                                                prefixSize,
                                                unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNVVpnRoute>(unmarshalledReturn.Get()) retain];
}

- (void)setAddress:(WNHostName*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnRoute>(self);
    THROW_NS_IF_FAILED(_comInst->put_Address(_getRtInterface<ABI::Windows::Networking::IHostName>(value).Get()));
}

- (WNHostName*)address {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnRoute>(self);
    THROW_NS_IF_FAILED(_comInst->get_Address(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (void)setPrefixSize:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnRoute>(self);
    THROW_NS_IF_FAILED(_comInst->put_PrefixSize(value));
}

- (uint8_t)prefixSize {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnRoute>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrefixSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WNVVpnNamespaceInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnNamespaceInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Networking::Vpn::IVpnNamespaceInfoFactory> WNVIVpnNamespaceInfoFactory_inst() {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnNamespaceInfoFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Vpn.VpnNamespaceInfo").Get(), &inst));
    return inst;
}

+ (WNVVpnNamespaceInfo*)makeVpnNamespaceInfo:(NSString*)name
                               dnsServerList:(NSMutableArray* /* WNHostName* */)dnsServerList
                             proxyServerList:(NSMutableArray* /* WNHostName* */)proxyServerList {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnNamespaceInfo> unmarshalledReturn;
    auto _comInst = WNVIVpnNamespaceInfoFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateVpnNamespaceInfo(
        nsStrToHstr(name).Get(),
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                              ABI::Windows::Networking::IHostName*>>::type>*>(
            ConvertToVector<WNHostName,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                              ABI::Windows::Networking::IHostName*>>(dnsServerList)
                .Get()),
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                              ABI::Windows::Networking::IHostName*>>::type>*>(
            ConvertToVector<WNHostName,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                              ABI::Windows::Networking::IHostName*>>(proxyServerList)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNVVpnNamespaceInfo>(unmarshalledReturn.Get()) retain];
}

- (void)setNamespace:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNamespaceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Namespace(nsStrToHstr(value).Get()));
}

- (NSString*)Namespace {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNamespaceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Namespace(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDnsServers:(NSMutableArray* /* WNHostName* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNamespaceInfo>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_DnsServers(static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
                                     ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                                       ABI::Windows::Networking::IHostName*>>::type>*>(
            ConvertToVector<WNHostName,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                              ABI::Windows::Networking::IHostName*>>(value)
                .Get())));
}

- (NSMutableArray* /* WNHostName* */)dnsServers {
    ComPtr<IVector<ABI::Windows::Networking::HostName*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNamespaceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DnsServers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNHostName_create(unmarshalledReturn.Get());
}

- (void)setWebProxyServers:(NSMutableArray* /* WNHostName* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNamespaceInfo>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_WebProxyServers(static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
                                          ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                                            ABI::Windows::Networking::IHostName*>>::type>*>(
            ConvertToVector<WNHostName,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                              ABI::Windows::Networking::IHostName*>>(value)
                .Get())));
}

- (NSMutableArray* /* WNHostName* */)webProxyServers {
    ComPtr<IVector<ABI::Windows::Networking::HostName*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNamespaceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebProxyServers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNHostName_create(unmarshalledReturn.Get());
}

@end

@implementation WNVVpnInterfaceId

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnInterfaceId> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Networking::Vpn::IVpnInterfaceIdFactory> WNVIVpnInterfaceIdFactory_inst() {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnInterfaceIdFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Vpn.VpnInterfaceId").Get(), &inst));
    return inst;
}

+ (WNVVpnInterfaceId*)makeVpnInterfaceId:(NSArray* /* uint8_t */)address {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnInterfaceId> unmarshalledReturn;
    UINT32 __address_ArrayLen = 0;
    bool __address_IsTemp = false;
    uint8_t* __address_Array = NULL;
    if (!ConvertToCArray<uint8_t>(address, &__address_ArrayLen, &__address_Array, &__address_IsTemp))
        assert(0);

    auto _comInst = WNVIVpnInterfaceIdFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateVpnInterfaceId(__address_ArrayLen, __address_Array, unmarshalledReturn.GetAddressOf()));
    if (__address_IsTemp)
        CoTaskMemFree(__address_Array);
    return [_createRtProxy<WNVVpnInterfaceId>(unmarshalledReturn.Get()) retain];
}

- (void)getAddressInfo:(NSArray* /* uint8_t */*)id {
    UINT32 __id_ArrayLen = 0;
    uint8_t* __id_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnInterfaceId>(self);
    THROW_NS_IF_FAILED(_comInst->GetAddressInfo(&__id_ArrayLen, &__id_Array));
    *id = RTProxiedNSArray_C_UInt8_create(__id_ArrayLen, __id_Array);
}

@end

@implementation WNVVpnRouteAssignment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnRouteAssignment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Vpn.VpnRouteAssignment").Get(), &out));
    return [_createRtProxy<WNVVpnRouteAssignment>(out.Get()) retain];
}

- (void)setIpv4InclusionRoutes:(NSMutableArray* /* WNVVpnRoute* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnRouteAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Ipv4InclusionRoutes(
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::Vpn::VpnRoute*,
                                                              ABI::Windows::Networking::Vpn::IVpnRoute*>>::type>*>(
            ConvertToVector<WNVVpnRoute,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::Vpn::VpnRoute*,
                                                                              ABI::Windows::Networking::Vpn::IVpnRoute*>>(value)
                .Get())));
}

- (void)setIpv6InclusionRoutes:(NSMutableArray* /* WNVVpnRoute* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnRouteAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Ipv6InclusionRoutes(
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::Vpn::VpnRoute*,
                                                              ABI::Windows::Networking::Vpn::IVpnRoute*>>::type>*>(
            ConvertToVector<WNVVpnRoute,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::Vpn::VpnRoute*,
                                                                              ABI::Windows::Networking::Vpn::IVpnRoute*>>(value)
                .Get())));
}

- (NSMutableArray* /* WNVVpnRoute* */)ipv4InclusionRoutes {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnRoute*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnRouteAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Ipv4InclusionRoutes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnRoute_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WNVVpnRoute* */)ipv6InclusionRoutes {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnRoute*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnRouteAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Ipv6InclusionRoutes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnRoute_create(unmarshalledReturn.Get());
}

- (void)setIpv4ExclusionRoutes:(NSMutableArray* /* WNVVpnRoute* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnRouteAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Ipv4ExclusionRoutes(
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::Vpn::VpnRoute*,
                                                              ABI::Windows::Networking::Vpn::IVpnRoute*>>::type>*>(
            ConvertToVector<WNVVpnRoute,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::Vpn::VpnRoute*,
                                                                              ABI::Windows::Networking::Vpn::IVpnRoute*>>(value)
                .Get())));
}

- (void)setIpv6ExclusionRoutes:(NSMutableArray* /* WNVVpnRoute* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnRouteAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Ipv6ExclusionRoutes(
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::Vpn::VpnRoute*,
                                                              ABI::Windows::Networking::Vpn::IVpnRoute*>>::type>*>(
            ConvertToVector<WNVVpnRoute,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::Vpn::VpnRoute*,
                                                                              ABI::Windows::Networking::Vpn::IVpnRoute*>>(value)
                .Get())));
}

- (NSMutableArray* /* WNVVpnRoute* */)ipv4ExclusionRoutes {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnRoute*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnRouteAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Ipv4ExclusionRoutes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnRoute_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WNVVpnRoute* */)ipv6ExclusionRoutes {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnRoute*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnRouteAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Ipv6ExclusionRoutes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnRoute_create(unmarshalledReturn.Get());
}

- (void)setExcludeLocalSubnets:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnRouteAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExcludeLocalSubnets((boolean)value));
}

- (BOOL)excludeLocalSubnets {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnRouteAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExcludeLocalSubnets(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNVVpnNamespaceAssignment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnNamespaceAssignment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Vpn.VpnNamespaceAssignment").Get(), &out));
    return [_createRtProxy<WNVVpnNamespaceAssignment>(out.Get()) retain];
}

- (void)setNamespaceList:(NSMutableArray* /* WNVVpnNamespaceInfo* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNamespaceAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->put_NamespaceList(
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::Vpn::VpnNamespaceInfo*,
                                                              ABI::Windows::Networking::Vpn::IVpnNamespaceInfo*>>::type>*>(
            ConvertToVector<WNVVpnNamespaceInfo,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::Vpn::VpnNamespaceInfo*,
                                                                              ABI::Windows::Networking::Vpn::IVpnNamespaceInfo*>>(value)
                .Get())));
}

- (NSMutableArray* /* WNVVpnNamespaceInfo* */)namespaceList {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnNamespaceInfo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNamespaceAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->get_NamespaceList(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnNamespaceInfo_create(unmarshalledReturn.Get());
}

- (void)setProxyAutoConfigUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNamespaceAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProxyAutoConfigUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)proxyAutoConfigUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNamespaceAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProxyAutoConfigUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

@end

@implementation WNVVpnPickedCredential

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnPickedCredential> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSCPasswordCredential*)passkeyCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPickedCredential>(self);
    THROW_NS_IF_FAILED(_comInst->get_PasskeyCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (NSString*)additionalPin {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPickedCredential>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdditionalPin(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSCPasswordCredential*)oldPasswordCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPickedCredential>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldPasswordCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

@end

@implementation WNVVpnPacketBuffer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnPacketBuffer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Networking::Vpn::IVpnPacketBufferFactory> WNVIVpnPacketBufferFactory_inst() {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnPacketBufferFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Vpn.VpnPacketBuffer").Get(), &inst));
    return inst;
}

+ (WNVVpnPacketBuffer*)makeVpnPacketBuffer:(WNVVpnPacketBuffer*)parentBuffer offset:(unsigned int)offset length:(unsigned int)length {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnPacketBuffer> unmarshalledReturn;
    auto _comInst = WNVIVpnPacketBufferFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateVpnPacketBuffer(_getRtInterface<ABI::Windows::Networking::Vpn::IVpnPacketBuffer>(parentBuffer).Get(),
                                                       offset,
                                                       length,
                                                       unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNVVpnPacketBuffer>(unmarshalledReturn.Get()) retain];
}

- (WSSBuffer*)buffer {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPacketBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Buffer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSBuffer>(unmarshalledReturn.Get());
}

- (void)setStatus:(WNVVpnPacketBufferStatus)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPacketBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->put_Status((ABI::Windows::Networking::Vpn::VpnPacketBufferStatus)value));
}

- (WNVVpnPacketBufferStatus)status {
    ABI::Windows::Networking::Vpn::VpnPacketBufferStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPacketBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WNVVpnPacketBufferStatus)unmarshalledReturn;
}

- (void)setTransportAffinity:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPacketBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->put_TransportAffinity(value));
}

- (unsigned int)transportAffinity {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPacketBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportAffinity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WNVVpnAppId*)appId {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnAppId> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPacketBuffer2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppId(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNVVpnAppId>(unmarshalledReturn.Get());
}

@end

@implementation WNVVpnChannelConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnChannelConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)serverServiceName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannelConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerServiceName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* WNHostName* */)serverHostNameList {
    ComPtr<IVectorView<ABI::Windows::Networking::HostName*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannelConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerHostNameList(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNHostName_create(unmarshalledReturn.Get());
}

- (NSString*)customField {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannelConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomField(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* WFUri* */)serverUris {
    ComPtr<IVectorView<ABI::Windows::Foundation::Uri*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannelConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerUris(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WFUri_create(unmarshalledReturn.Get());
}

@end

@implementation WNVVpnChannel

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnChannel> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Networking::Vpn::IVpnChannelStatics> WNVIVpnChannelStatics_inst() {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnChannelStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Vpn.VpnChannel").Get(), &inst));
    return inst;
}

+ (void)processEventAsync:(RTObject*)thirdPartyPlugIn event:(RTObject*)event {
    auto _comInst = WNVIVpnChannelStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ProcessEventAsync([thirdPartyPlugIn comObj].Get(), [event comObj].Get()));
}

- (void)associateTransport:(RTObject*)mainOuterTunnelTransport optionalOuterTunnelTransport:(RTObject*)optionalOuterTunnelTransport {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(self);
    THROW_NS_IF_FAILED(_comInst->AssociateTransport([mainOuterTunnelTransport comObj].Get(), [optionalOuterTunnelTransport comObj].Get()));
}

- (void)start:(NSArray* /* WNHostName* */)assignedClientIPv4list
          assignedClientIPv6list:(NSArray* /* WNHostName* */)assignedClientIPv6list
                  vpnInterfaceId:(WNVVpnInterfaceId*)vpnInterfaceId
                      routeScope:(WNVVpnRouteAssignment*)routeScope
                  namespaceScope:(WNVVpnNamespaceAssignment*)namespaceScope
                         mtuSize:(unsigned int)mtuSize
                    maxFrameSize:(unsigned int)maxFrameSize
       optimizeForLowCostNetwork:(BOOL)optimizeForLowCostNetwork
        mainOuterTunnelTransport:(RTObject*)mainOuterTunnelTransport
    optionalOuterTunnelTransport:(RTObject*)optionalOuterTunnelTransport {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(self);
    THROW_NS_IF_FAILED(
        _comInst->Start(static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                              ABI::Windows::Networking::IHostName*>>::type>*>(
                            ConvertToVectorView<WNHostName,
                                                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                                                  ABI::Windows::Networking::IHostName*>>(
                                assignedClientIPv4list)
                                .Get()),
                        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                              ABI::Windows::Networking::IHostName*>>::type>*>(
                            ConvertToVectorView<WNHostName,
                                                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                                                  ABI::Windows::Networking::IHostName*>>(
                                assignedClientIPv6list)
                                .Get()),
                        _getRtInterface<ABI::Windows::Networking::Vpn::IVpnInterfaceId>(vpnInterfaceId).Get(),
                        _getRtInterface<ABI::Windows::Networking::Vpn::IVpnRouteAssignment>(routeScope).Get(),
                        _getRtInterface<ABI::Windows::Networking::Vpn::IVpnNamespaceAssignment>(namespaceScope).Get(),
                        mtuSize,
                        maxFrameSize,
                        (boolean)optimizeForLowCostNetwork,
                        [mainOuterTunnelTransport comObj].Get(),
                        [optionalOuterTunnelTransport comObj].Get()));
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (WNVVpnPickedCredential*)requestCredentials:(WNVVpnCredentialType)credType
                                      isRetry:(BOOL)isRetry
                     isSingleSignOnCredential:(BOOL)isSingleSignOnCredential
                                  certificate:(WSCCCertificate*)certificate {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnPickedCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(self);
    THROW_NS_IF_FAILED(
        _comInst->RequestCredentials((ABI::Windows::Networking::Vpn::VpnCredentialType)credType,
                                     (boolean)isRetry,
                                     (boolean)isSingleSignOnCredential,
                                     _getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(certificate).Get(),
                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNVVpnPickedCredential>(unmarshalledReturn.Get());
}

- (void)requestVpnPacketBuffer:(WNVVpnDataPathType)type vpnPacketBuffer:(WNVVpnPacketBuffer**)vpnPacketBuffer {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnPacketBuffer> vpnPacketBufferOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(self);
    THROW_NS_IF_FAILED(_comInst->RequestVpnPacketBuffer((ABI::Windows::Networking::Vpn::VpnDataPathType)type,
                                                        vpnPacketBufferOutUnmarshaled.GetAddressOf()));
    *vpnPacketBuffer = _createRtProxy<WNVVpnPacketBuffer>(vpnPacketBufferOutUnmarshaled.Get());
}

- (void)logDiagnosticMessage:(NSString*)message {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(self);
    THROW_NS_IF_FAILED(_comInst->LogDiagnosticMessage(nsStrToHstr(message).Get()));
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WNVVpnChannelConfiguration*)configuration {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnChannelConfiguration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Configuration(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNVVpnChannelConfiguration>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addActivityChangeEvent:(void (^)(WNVVpnChannel*, WNVVpnChannelActivityEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(self);
    THROW_NS_IF_FAILED(_comInst->add_ActivityChange(
        Make<ITypedEventHandler_Windows_Networking_Vpn_VpnChannel_Windows_Networking_Vpn_VpnChannelActivityEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeActivityChangeEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ActivityChange(token));
}

- (void)setPlugInContext:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(self);
    THROW_NS_IF_FAILED(_comInst->put_PlugInContext([value comObj].Get()));
}

- (RTObject*)plugInContext {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlugInContext(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WNVVpnSystemHealth*)systemHealth {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnSystemHealth> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemHealth(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNVVpnSystemHealth>(unmarshalledReturn.Get());
}

- (void)requestCustomPrompt:(NSArray* /* RTObject<WNVIVpnCustomPrompt>* */)customPrompt {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(self);
    THROW_NS_IF_FAILED(_comInst->RequestCustomPrompt(
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::Vpn::IVpnCustomPrompt*,
                                                              ABI::Windows::Networking::Vpn::IVpnCustomPrompt*>>::type>*>(
            ConvertToVectorView<RTObject<WNVIVpnCustomPrompt>,
                                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::Vpn::IVpnCustomPrompt*,
                                                                                  ABI::Windows::Networking::Vpn::IVpnCustomPrompt*>>(
                customPrompt)
                .Get())));
}

- (void)setErrorMessage:(NSString*)message {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(self);
    THROW_NS_IF_FAILED(_comInst->SetErrorMessage(nsStrToHstr(message).Get()));
}

- (void)setAllowedSslTlsVersions:(RTObject*)tunnelTransport useTls12:(BOOL)useTls12 {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel>(self);
    THROW_NS_IF_FAILED(_comInst->SetAllowedSslTlsVersions([tunnelTransport comObj].Get(), (boolean)useTls12));
}

- (void)startWithMainTransport:(NSArray* /* WNHostName* */)assignedClientIPv4list
        assignedClientIPv6list:(NSArray* /* WNHostName* */)assignedClientIPv6list
                vpnInterfaceId:(WNVVpnInterfaceId*)vpnInterfaceId
                assignedRoutes:(WNVVpnRouteAssignment*)assignedRoutes
            assignedDomainName:(WNVVpnDomainNameAssignment*)assignedDomainName
                       mtuSize:(unsigned int)mtuSize
                  maxFrameSize:(unsigned int)maxFrameSize
                      Reserved:(BOOL)Reserved
      mainOuterTunnelTransport:(RTObject*)mainOuterTunnelTransport {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel2>(self);
    THROW_NS_IF_FAILED(_comInst->StartWithMainTransport(
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                              ABI::Windows::Networking::IHostName*>>::type>*>(
            ConvertToVectorView<WNHostName,
                                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                                  ABI::Windows::Networking::IHostName*>>(
                assignedClientIPv4list)
                .Get()),
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                              ABI::Windows::Networking::IHostName*>>::type>*>(
            ConvertToVectorView<WNHostName,
                                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                                  ABI::Windows::Networking::IHostName*>>(
                assignedClientIPv6list)
                .Get()),
        _getRtInterface<ABI::Windows::Networking::Vpn::IVpnInterfaceId>(vpnInterfaceId).Get(),
        _getRtInterface<ABI::Windows::Networking::Vpn::IVpnRouteAssignment>(assignedRoutes).Get(),
        _getRtInterface<ABI::Windows::Networking::Vpn::IVpnDomainNameAssignment>(assignedDomainName).Get(),
        mtuSize,
        maxFrameSize,
        (boolean)Reserved,
        [mainOuterTunnelTransport comObj].Get()));
}

- (void)startExistingTransports:(NSArray* /* WNHostName* */)assignedClientIPv4list
         assignedClientIPv6list:(NSArray* /* WNHostName* */)assignedClientIPv6list
                 vpnInterfaceId:(WNVVpnInterfaceId*)vpnInterfaceId
                 assignedRoutes:(WNVVpnRouteAssignment*)assignedRoutes
             assignedDomainName:(WNVVpnDomainNameAssignment*)assignedDomainName
                        mtuSize:(unsigned int)mtuSize
                   maxFrameSize:(unsigned int)maxFrameSize
                       Reserved:(BOOL)Reserved {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel2>(self);
    THROW_NS_IF_FAILED(_comInst->StartExistingTransports(
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                              ABI::Windows::Networking::IHostName*>>::type>*>(
            ConvertToVectorView<WNHostName,
                                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                                  ABI::Windows::Networking::IHostName*>>(
                assignedClientIPv4list)
                .Get()),
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                              ABI::Windows::Networking::IHostName*>>::type>*>(
            ConvertToVectorView<WNHostName,
                                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                                  ABI::Windows::Networking::IHostName*>>(
                assignedClientIPv6list)
                .Get()),
        _getRtInterface<ABI::Windows::Networking::Vpn::IVpnInterfaceId>(vpnInterfaceId).Get(),
        _getRtInterface<ABI::Windows::Networking::Vpn::IVpnRouteAssignment>(assignedRoutes).Get(),
        _getRtInterface<ABI::Windows::Networking::Vpn::IVpnDomainNameAssignment>(assignedDomainName).Get(),
        mtuSize,
        maxFrameSize,
        (boolean)Reserved));
}

- (EventRegistrationToken)addActivityStateChangeEvent:(void (^)(WNVVpnChannel*, WNVVpnChannelActivityStateChangedArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel2>(self);
    THROW_NS_IF_FAILED(_comInst->add_ActivityStateChange(
        Make<ITypedEventHandler_Windows_Networking_Vpn_VpnChannel_Windows_Networking_Vpn_VpnChannelActivityStateChangedArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeActivityStateChangeEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ActivityStateChange(token));
}

- (WNVVpnPacketBuffer*)getVpnSendPacketBuffer {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnPacketBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel2>(self);
    THROW_NS_IF_FAILED(_comInst->GetVpnSendPacketBuffer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNVVpnPacketBuffer>(unmarshalledReturn.Get());
}

- (WNVVpnPacketBuffer*)getVpnReceivePacketBuffer {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnPacketBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel2>(self);
    THROW_NS_IF_FAILED(_comInst->GetVpnReceivePacketBuffer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNVVpnPacketBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)requestCustomPromptAsync:(NSArray* /* RTObject<WNVIVpnCustomPromptElement>* */)customPromptElement {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel2>(self);
    THROW_NS_IF_FAILED(_comInst->RequestCustomPromptAsync(
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement*,
                                                              ABI::Windows::Networking::Vpn::IVpnCustomPromptElement*>>::type>*>(
            ConvertToVectorView<RTObject<WNVIVpnCustomPromptElement>,
                                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement*,
                                                                                  ABI::Windows::Networking::Vpn::IVpnCustomPromptElement*>>(
                customPromptElement)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)requestCredentialsWithCertificateAsync:(WNVVpnCredentialType)credType
                                   credOptions:(unsigned int)credOptions
                                   certificate:(WSCCCertificate*)certificate
                                       success:(void (^)(WNVVpnCredential*))success
                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnCredential*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel2>(self);
    THROW_NS_IF_FAILED(_comInst->RequestCredentialsWithCertificateAsync(
        (ABI::Windows::Networking::Vpn::VpnCredentialType)credType,
        credOptions,
        _getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(certificate).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::Vpn::VpnCredential*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnCredential*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::Vpn::IVpnCredential> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNVVpnCredential>(result.Get()));
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

- (void)requestCredentialsWithOptionsAsync:(WNVVpnCredentialType)credType
                               credOptions:(unsigned int)credOptions
                                   success:(void (^)(WNVVpnCredential*))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnCredential*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel2>(self);
    THROW_NS_IF_FAILED(_comInst->RequestCredentialsWithOptionsAsync((ABI::Windows::Networking::Vpn::VpnCredentialType)credType,
                                                                    credOptions,
                                                                    &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::Vpn::VpnCredential*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnCredential*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::Vpn::IVpnCredential> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNVVpnCredential>(result.Get()));
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

- (void)requestCredentialsSimpleAsync:(WNVVpnCredentialType)credType
                              success:(void (^)(WNVVpnCredential*))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnCredential*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel2>(self);
    THROW_NS_IF_FAILED(
        _comInst->RequestCredentialsSimpleAsync((ABI::Windows::Networking::Vpn::VpnCredentialType)credType, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::Vpn::VpnCredential*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnCredential*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::Vpn::IVpnCredential> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNVVpnCredential>(result.Get()));
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

- (void)terminateConnection:(NSString*)message {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel2>(self);
    THROW_NS_IF_FAILED(_comInst->TerminateConnection(nsStrToHstr(message).Get()));
}

- (void)startWithTrafficFilter:(NSArray* /* WNHostName* */)assignedClientIpv4List
          assignedClientIpv6List:(NSArray* /* WNHostName* */)assignedClientIpv6List
                  vpnInterfaceId:(WNVVpnInterfaceId*)vpnInterfaceId
                  assignedRoutes:(WNVVpnRouteAssignment*)assignedRoutes
               assignedNamespace:(WNVVpnDomainNameAssignment*)assignedNamespace
                         mtuSize:(unsigned int)mtuSize
                    maxFrameSize:(unsigned int)maxFrameSize
                        reserved:(BOOL)reserved
        mainOuterTunnelTransport:(RTObject*)mainOuterTunnelTransport
    optionalOuterTunnelTransport:(RTObject*)optionalOuterTunnelTransport
          assignedTrafficFilters:(WNVVpnTrafficFilterAssignment*)assignedTrafficFilters {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannel2>(self);
    THROW_NS_IF_FAILED(_comInst->StartWithTrafficFilter(
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                              ABI::Windows::Networking::IHostName*>>::type>*>(
            ConvertToVectorView<WNHostName,
                                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                                  ABI::Windows::Networking::IHostName*>>(
                assignedClientIpv4List)
                .Get()),
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                              ABI::Windows::Networking::IHostName*>>::type>*>(
            ConvertToVectorView<WNHostName,
                                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                                  ABI::Windows::Networking::IHostName*>>(
                assignedClientIpv6List)
                .Get()),
        _getRtInterface<ABI::Windows::Networking::Vpn::IVpnInterfaceId>(vpnInterfaceId).Get(),
        _getRtInterface<ABI::Windows::Networking::Vpn::IVpnRouteAssignment>(assignedRoutes).Get(),
        _getRtInterface<ABI::Windows::Networking::Vpn::IVpnDomainNameAssignment>(assignedNamespace).Get(),
        mtuSize,
        maxFrameSize,
        (boolean)reserved,
        [mainOuterTunnelTransport comObj].Get(),
        [optionalOuterTunnelTransport comObj].Get(),
        _getRtInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilterAssignment>(assignedTrafficFilters).Get()));
}

@end

@implementation WNVVpnChannelActivityEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnChannelActivityEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNVVpnChannelActivityEventType)type {
    ABI::Windows::Networking::Vpn::VpnChannelActivityEventType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannelActivityEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WNVVpnChannelActivityEventType)unmarshalledReturn;
}

@end

@implementation WNVVpnSystemHealth

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnSystemHealth> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSSBuffer*)statementOfHealth {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnSystemHealth>(self);
    THROW_NS_IF_FAILED(_comInst->get_StatementOfHealth(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WNVVpnDomainNameAssignment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnDomainNameAssignment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Vpn.VpnDomainNameAssignment").Get(), &out));
    return [_createRtProxy<WNVVpnDomainNameAssignment>(out.Get()) retain];
}

- (NSMutableArray* /* WNVVpnDomainNameInfo* */)domainNameList {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnDomainNameInfo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnDomainNameAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainNameList(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnDomainNameInfo_create(unmarshalledReturn.Get());
}

- (void)setProxyAutoConfigurationUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnDomainNameAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProxyAutoConfigurationUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)proxyAutoConfigurationUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnDomainNameAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProxyAutoConfigurationUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

@end

@implementation WNVVpnChannelActivityStateChangedArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnChannelActivityStateChangedArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNVVpnChannelActivityEventType)activityState {
    ABI::Windows::Networking::Vpn::VpnChannelActivityEventType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnChannelActivityStateChangedArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivityState(&unmarshalledReturn));
    return (WNVVpnChannelActivityEventType)unmarshalledReturn;
}

@end

@implementation WNVVpnCredential

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnCredential> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSCPasswordCredential*)passkeyCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCredential>(self);
    THROW_NS_IF_FAILED(_comInst->get_PasskeyCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (WSCCCertificate*)certificateCredential {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCredential>(self);
    THROW_NS_IF_FAILED(_comInst->get_CertificateCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (NSString*)additionalPin {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCredential>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdditionalPin(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSCPasswordCredential*)oldPasswordCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCredential>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldPasswordCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

@end

@implementation WNVVpnTrafficFilterAssignment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnTrafficFilterAssignment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Vpn.VpnTrafficFilterAssignment").Get(), &out));
    return [_createRtProxy<WNVVpnTrafficFilterAssignment>(out.Get()) retain];
}

- (NSMutableArray* /* WNVVpnTrafficFilter* */)trafficFilterList {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnTrafficFilter*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilterAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrafficFilterList(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnTrafficFilter_create(unmarshalledReturn.Get());
}

- (BOOL)allowOutbound {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilterAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowOutbound(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowOutbound:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilterAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowOutbound((boolean)value));
}

- (BOOL)allowInbound {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilterAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowInbound(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowInbound:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilterAssignment>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowInbound((boolean)value));
}

@end

@implementation WNVVpnAppId

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnAppId> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Networking::Vpn::IVpnAppIdFactory> WNVIVpnAppIdFactory_inst() {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnAppIdFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Vpn.VpnAppId").Get(), &inst));
    return inst;
}

+ (WNVVpnAppId*)make:(WNVVpnAppIdType)type value:(NSString*)value {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnAppId> unmarshalledReturn;
    auto _comInst = WNVIVpnAppIdFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create((ABI::Windows::Networking::Vpn::VpnAppIdType)type, nsStrToHstr(value).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNVVpnAppId>(unmarshalledReturn.Get()) retain];
}

- (WNVVpnAppIdType)type {
    ABI::Windows::Networking::Vpn::VpnAppIdType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnAppId>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WNVVpnAppIdType)unmarshalledReturn;
}

- (void)setType:(WNVVpnAppIdType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnAppId>(self);
    THROW_NS_IF_FAILED(_comInst->put_Type((ABI::Windows::Networking::Vpn::VpnAppIdType)value));
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnAppId>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setValue:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnAppId>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(nsStrToHstr(value).Get()));
}

@end

@implementation WNVVpnDomainNameInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnDomainNameInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Networking::Vpn::IVpnDomainNameInfoFactory> WNVIVpnDomainNameInfoFactory_inst() {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnDomainNameInfoFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Vpn.VpnDomainNameInfo").Get(), &inst));
    return inst;
}

+ (WNVVpnDomainNameInfo*)makeVpnDomainNameInfo:(NSString*)name
                                      nameType:(WNVVpnDomainNameType)nameType
                                 dnsServerList:(id<NSFastEnumeration> /* WNHostName* */)dnsServerList
                               proxyServerList:(id<NSFastEnumeration> /* WNHostName* */)proxyServerList {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnDomainNameInfo> unmarshalledReturn;
    auto _comInst = WNVIVpnDomainNameInfoFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateVpnDomainNameInfo(
        nsStrToHstr(name).Get(),
        (ABI::Windows::Networking::Vpn::VpnDomainNameType)nameType,
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                              ABI::Windows::Networking::IHostName*>>::type>*>(
            ConvertToIterable<WNHostName,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                                ABI::Windows::Networking::IHostName*>>(dnsServerList)
                .Get()),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                              ABI::Windows::Networking::IHostName*>>::type>*>(
            ConvertToIterable<WNHostName,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::HostName*,
                                                                                ABI::Windows::Networking::IHostName*>>(proxyServerList)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNVVpnDomainNameInfo>(unmarshalledReturn.Get()) retain];
}

- (void)setDomainName:(WNHostName*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnDomainNameInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_DomainName(_getRtInterface<ABI::Windows::Networking::IHostName>(value).Get()));
}

- (WNHostName*)domainName {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnDomainNameInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainName(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (void)setDomainNameType:(WNVVpnDomainNameType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnDomainNameInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_DomainNameType((ABI::Windows::Networking::Vpn::VpnDomainNameType)value));
}

- (WNVVpnDomainNameType)domainNameType {
    ABI::Windows::Networking::Vpn::VpnDomainNameType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnDomainNameInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainNameType(&unmarshalledReturn));
    return (WNVVpnDomainNameType)unmarshalledReturn;
}

- (NSMutableArray* /* WNHostName* */)dnsServers {
    ComPtr<IVector<ABI::Windows::Networking::HostName*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnDomainNameInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DnsServers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNHostName_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WNHostName* */)webProxyServers {
    ComPtr<IVector<ABI::Windows::Networking::HostName*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnDomainNameInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebProxyServers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNHostName_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WFUri* */)webProxyUris {
    ComPtr<IVector<ABI::Windows::Foundation::Uri*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnDomainNameInfo2>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebProxyUris(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WFUri_create(unmarshalledReturn.Get());
}

@end

@implementation WNVVpnTrafficFilter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnTrafficFilter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Networking::Vpn::IVpnTrafficFilterFactory> WNVIVpnTrafficFilterFactory_inst() {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnTrafficFilterFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Vpn.VpnTrafficFilter").Get(), &inst));
    return inst;
}

+ (WNVVpnTrafficFilter*)make:(WNVVpnAppId*)appId {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnTrafficFilter> unmarshalledReturn;
    auto _comInst = WNVIVpnTrafficFilterFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Networking::Vpn::IVpnAppId>(appId).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNVVpnTrafficFilter>(unmarshalledReturn.Get()) retain];
}

- (WNVVpnAppId*)appId {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnAppId> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppId(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNVVpnAppId>(unmarshalledReturn.Get());
}

- (void)setAppId:(WNVVpnAppId*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_AppId(_getRtInterface<ABI::Windows::Networking::Vpn::IVpnAppId>(value).Get()));
}

- (NSMutableArray* /* NSString * */)appClaims {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppClaims(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (WNVVpnIPProtocol)protocol {
    ABI::Windows::Networking::Vpn::VpnIPProtocol unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Protocol(&unmarshalledReturn));
    return (WNVVpnIPProtocol)unmarshalledReturn;
}

- (void)setProtocol:(WNVVpnIPProtocol)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_Protocol((ABI::Windows::Networking::Vpn::VpnIPProtocol)value));
}

- (NSMutableArray* /* NSString * */)localPortRanges {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalPortRanges(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* NSString * */)remotePortRanges {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemotePortRanges(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* NSString * */)localAddressRanges {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalAddressRanges(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* NSString * */)remoteAddressRanges {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteAddressRanges(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (WNVVpnRoutingPolicyType)routingPolicyType {
    ABI::Windows::Networking::Vpn::VpnRoutingPolicyType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoutingPolicyType(&unmarshalledReturn));
    return (WNVVpnRoutingPolicyType)unmarshalledReturn;
}

- (void)setRoutingPolicyType:(WNVVpnRoutingPolicyType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnTrafficFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_RoutingPolicyType((ABI::Windows::Networking::Vpn::VpnRoutingPolicyType)value));
}

@end

@implementation WNVVpnPacketBufferList

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnPacketBufferList> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)append:(WNVVpnPacketBuffer*)nextVpnPacketBuffer {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPacketBufferList>(self);
    THROW_NS_IF_FAILED(_comInst->Append(_getRtInterface<ABI::Windows::Networking::Vpn::IVpnPacketBuffer>(nextVpnPacketBuffer).Get()));
}

- (void)addAtBegin:(WNVVpnPacketBuffer*)nextVpnPacketBuffer {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPacketBufferList>(self);
    THROW_NS_IF_FAILED(_comInst->AddAtBegin(_getRtInterface<ABI::Windows::Networking::Vpn::IVpnPacketBuffer>(nextVpnPacketBuffer).Get()));
}

- (WNVVpnPacketBuffer*)removeAtEnd {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnPacketBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPacketBufferList>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAtEnd(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNVVpnPacketBuffer>(unmarshalledReturn.Get());
}

- (WNVVpnPacketBuffer*)removeAtBegin {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnPacketBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPacketBufferList>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAtBegin(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNVVpnPacketBuffer>(unmarshalledReturn.Get());
}

- (void)clear {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPacketBufferList>(self);
    THROW_NS_IF_FAILED(_comInst->Clear());
}

- (void)setStatus:(WNVVpnPacketBufferStatus)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPacketBufferList>(self);
    THROW_NS_IF_FAILED(_comInst->put_Status((ABI::Windows::Networking::Vpn::VpnPacketBufferStatus)value));
}

- (WNVVpnPacketBufferStatus)status {
    ABI::Windows::Networking::Vpn::VpnPacketBufferStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPacketBufferList>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WNVVpnPacketBufferStatus)unmarshalledReturn;
}

- (unsigned int)size {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPacketBufferList>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WNVVpnCustomEditBox

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnCustomEditBox> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Vpn.VpnCustomEditBox").Get(), &out));
    return [_createRtProxy<WNVVpnCustomEditBox>(out.Get()) retain];
}

- (void)setDefaultText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomEditBox>(self);
    THROW_NS_IF_FAILED(_comInst->put_DefaultText(nsStrToHstr(value).Get()));
}

- (NSString*)defaultText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomEditBox>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNoEcho:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomEditBox>(self);
    THROW_NS_IF_FAILED(_comInst->put_NoEcho((boolean)value));
}

- (BOOL)noEcho {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomEditBox>(self);
    THROW_NS_IF_FAILED(_comInst->get_NoEcho(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomEditBox>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLabel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Label(nsStrToHstr(value).Get()));
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCompulsory:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Compulsory((boolean)value));
}

- (BOOL)compulsory {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Compulsory(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setBordered:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Bordered((boolean)value));
}

- (BOOL)bordered {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bordered(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNVVpnCustomPromptTextInput

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnCustomPromptTextInput> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Vpn.VpnCustomPromptTextInput").Get(), &out));
    return [_createRtProxy<WNVVpnCustomPromptTextInput>(out.Get()) retain];
}

- (void)setPlaceholderText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptTextInput>(self);
    THROW_NS_IF_FAILED(_comInst->put_PlaceholderText(nsStrToHstr(value).Get()));
}

- (NSString*)placeholderText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptTextInput>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaceholderText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setIsTextHidden:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptTextInput>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsTextHidden((boolean)value));
}

- (BOOL)isTextHidden {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptTextInput>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTextHidden(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptTextInput>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCompulsory:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Compulsory((boolean)value));
}

- (BOOL)compulsory {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Compulsory(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEmphasized:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Emphasized((boolean)value));
}

- (BOOL)emphasized {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Emphasized(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNVVpnCustomComboBox

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnCustomComboBox> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Vpn.VpnCustomComboBox").Get(), &out));
    return [_createRtProxy<WNVVpnCustomComboBox>(out.Get()) retain];
}

- (void)setOptionsText:(NSArray* /* NSString * */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomComboBox>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_OptionsText(static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToVectorView<NSString, HSTRING>(value).Get())));
}

- (NSArray* /* NSString * */)optionsText {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomComboBox>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionsText(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (unsigned int)selected {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomComboBox>(self);
    THROW_NS_IF_FAILED(_comInst->get_Selected(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLabel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Label(nsStrToHstr(value).Get()));
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCompulsory:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Compulsory((boolean)value));
}

- (BOOL)compulsory {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Compulsory(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setBordered:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Bordered((boolean)value));
}

- (BOOL)bordered {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bordered(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNVVpnCustomPromptOptionSelector

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnCustomPromptOptionSelector> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Vpn.VpnCustomPromptOptionSelector").Get(), &out));
    return [_createRtProxy<WNVVpnCustomPromptOptionSelector>(out.Get()) retain];
}

- (NSMutableArray* /* NSString * */)options {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptOptionSelector>(self);
    THROW_NS_IF_FAILED(_comInst->get_Options(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (unsigned int)selectedIndex {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptOptionSelector>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCompulsory:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Compulsory((boolean)value));
}

- (BOOL)compulsory {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Compulsory(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEmphasized:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Emphasized((boolean)value));
}

- (BOOL)emphasized {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Emphasized(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNVVpnCustomTextBox

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnCustomTextBox> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Vpn.VpnCustomTextBox").Get(), &out));
    return [_createRtProxy<WNVVpnCustomTextBox>(out.Get()) retain];
}

- (void)setDisplayText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomTextBox>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayText(nsStrToHstr(value).Get()));
}

- (NSString*)displayText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomTextBox>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLabel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Label(nsStrToHstr(value).Get()));
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCompulsory:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Compulsory((boolean)value));
}

- (BOOL)compulsory {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Compulsory(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setBordered:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Bordered((boolean)value));
}

- (BOOL)bordered {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bordered(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNVVpnCustomPromptText

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnCustomPromptText> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Vpn.VpnCustomPromptText").Get(), &out));
    return [_createRtProxy<WNVVpnCustomPromptText>(out.Get()) retain];
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptText>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptText>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCompulsory:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Compulsory((boolean)value));
}

- (BOOL)compulsory {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Compulsory(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEmphasized:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Emphasized((boolean)value));
}

- (BOOL)emphasized {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Emphasized(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNVVpnCustomCheckBox

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnCustomCheckBox> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Vpn.VpnCustomCheckBox").Get(), &out));
    return [_createRtProxy<WNVVpnCustomCheckBox>(out.Get()) retain];
}

- (void)setInitialCheckState:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomCheckBox>(self);
    THROW_NS_IF_FAILED(_comInst->put_InitialCheckState((boolean)value));
}

- (BOOL)initialCheckState {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomCheckBox>(self);
    THROW_NS_IF_FAILED(_comInst->get_InitialCheckState(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)checked {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomCheckBox>(self);
    THROW_NS_IF_FAILED(_comInst->get_Checked(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setLabel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Label(nsStrToHstr(value).Get()));
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCompulsory:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Compulsory((boolean)value));
}

- (BOOL)compulsory {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Compulsory(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setBordered:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Bordered((boolean)value));
}

- (BOOL)bordered {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bordered(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNVVpnCustomPromptBooleanInput

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnCustomPromptBooleanInput> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Vpn.VpnCustomPromptBooleanInput").Get(), &out));
    return [_createRtProxy<WNVVpnCustomPromptBooleanInput>(out.Get()) retain];
}

- (void)setInitialValue:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptBooleanInput>(self);
    THROW_NS_IF_FAILED(_comInst->put_InitialValue((boolean)value));
}

- (BOOL)initialValue {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptBooleanInput>(self);
    THROW_NS_IF_FAILED(_comInst->get_InitialValue(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptBooleanInput>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCompulsory:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Compulsory((boolean)value));
}

- (BOOL)compulsory {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Compulsory(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEmphasized:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Emphasized((boolean)value));
}

- (BOOL)emphasized {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Emphasized(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNVVpnCustomErrorBox

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnCustomErrorBox> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Vpn.VpnCustomErrorBox").Get(), &out));
    return [_createRtProxy<WNVVpnCustomErrorBox>(out.Get()) retain];
}

- (void)setLabel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Label(nsStrToHstr(value).Get()));
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCompulsory:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Compulsory((boolean)value));
}

- (BOOL)compulsory {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Compulsory(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setBordered:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->put_Bordered((boolean)value));
}

- (BOOL)bordered {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnCustomPrompt>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bordered(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNVVpnPlugInProfile

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnPlugInProfile> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Vpn.VpnPlugInProfile").Get(), &out));
    return [_createRtProxy<WNVVpnPlugInProfile>(out.Get()) retain];
}

- (NSMutableArray* /* WFUri* */)serverUris {
    ComPtr<IVector<ABI::Windows::Foundation::Uri*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPlugInProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerUris(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WFUri_create(unmarshalledReturn.Get());
}

- (NSString*)customConfiguration {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPlugInProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomConfiguration(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCustomConfiguration:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPlugInProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_CustomConfiguration(nsStrToHstr(value).Get()));
}

- (NSString*)vpnPluginPackageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPlugInProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_VpnPluginPackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setVpnPluginPackageFamilyName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPlugInProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_VpnPluginPackageFamilyName(nsStrToHstr(value).Get()));
}

- (NSString*)profileName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProfileName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setProfileName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProfileName(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* WNVVpnAppId* */)appTriggers {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnAppId*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppTriggers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnAppId_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WNVVpnRoute* */)routes {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnRoute*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_Routes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnRoute_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WNVVpnDomainNameInfo* */)domainNameInfoList {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnDomainNameInfo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainNameInfoList(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnDomainNameInfo_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WNVVpnTrafficFilter* */)trafficFilters {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnTrafficFilter*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrafficFilters(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnTrafficFilter_create(unmarshalledReturn.Get());
}

- (BOOL)rememberCredentials {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_RememberCredentials(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setRememberCredentials:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_RememberCredentials((boolean)value));
}

- (BOOL)alwaysOn {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlwaysOn(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAlwaysOn:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_AlwaysOn((boolean)value));
}

- (BOOL)requireVpnClientAppUI {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPlugInProfile2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequireVpnClientAppUI(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setRequireVpnClientAppUI:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPlugInProfile2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RequireVpnClientAppUI((boolean)value));
}

- (WNVVpnManagementConnectionStatus)connectionStatus {
    ABI::Windows::Networking::Vpn::VpnManagementConnectionStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnPlugInProfile2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionStatus(&unmarshalledReturn));
    return (WNVVpnManagementConnectionStatus)unmarshalledReturn;
}

@end

@implementation WNVVpnNativeProfile

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnNativeProfile> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Vpn.VpnNativeProfile").Get(), &out));
    return [_createRtProxy<WNVVpnNativeProfile>(out.Get()) retain];
}

- (NSMutableArray* /* NSString * */)servers {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNativeProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_Servers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (WNVVpnRoutingPolicyType)routingPolicyType {
    ABI::Windows::Networking::Vpn::VpnRoutingPolicyType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNativeProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoutingPolicyType(&unmarshalledReturn));
    return (WNVVpnRoutingPolicyType)unmarshalledReturn;
}

- (void)setRoutingPolicyType:(WNVVpnRoutingPolicyType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNativeProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_RoutingPolicyType((ABI::Windows::Networking::Vpn::VpnRoutingPolicyType)value));
}

- (WNVVpnNativeProtocolType)nativeProtocolType {
    ABI::Windows::Networking::Vpn::VpnNativeProtocolType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNativeProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_NativeProtocolType(&unmarshalledReturn));
    return (WNVVpnNativeProtocolType)unmarshalledReturn;
}

- (void)setNativeProtocolType:(WNVVpnNativeProtocolType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNativeProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_NativeProtocolType((ABI::Windows::Networking::Vpn::VpnNativeProtocolType)value));
}

- (WNVVpnAuthenticationMethod)userAuthenticationMethod {
    ABI::Windows::Networking::Vpn::VpnAuthenticationMethod unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNativeProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserAuthenticationMethod(&unmarshalledReturn));
    return (WNVVpnAuthenticationMethod)unmarshalledReturn;
}

- (void)setUserAuthenticationMethod:(WNVVpnAuthenticationMethod)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNativeProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_UserAuthenticationMethod((ABI::Windows::Networking::Vpn::VpnAuthenticationMethod)value));
}

- (WNVVpnAuthenticationMethod)tunnelAuthenticationMethod {
    ABI::Windows::Networking::Vpn::VpnAuthenticationMethod unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNativeProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_TunnelAuthenticationMethod(&unmarshalledReturn));
    return (WNVVpnAuthenticationMethod)unmarshalledReturn;
}

- (void)setTunnelAuthenticationMethod:(WNVVpnAuthenticationMethod)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNativeProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_TunnelAuthenticationMethod((ABI::Windows::Networking::Vpn::VpnAuthenticationMethod)value));
}

- (NSString*)eapConfiguration {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNativeProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_EapConfiguration(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setEapConfiguration:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNativeProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_EapConfiguration(nsStrToHstr(value).Get()));
}

- (NSString*)profileName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProfileName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setProfileName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProfileName(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* WNVVpnAppId* */)appTriggers {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnAppId*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppTriggers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnAppId_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WNVVpnRoute* */)routes {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnRoute*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_Routes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnRoute_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WNVVpnDomainNameInfo* */)domainNameInfoList {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnDomainNameInfo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_DomainNameInfoList(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnDomainNameInfo_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WNVVpnTrafficFilter* */)trafficFilters {
    ComPtr<IVector<ABI::Windows::Networking::Vpn::VpnTrafficFilter*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrafficFilters(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WNVVpnTrafficFilter_create(unmarshalledReturn.Get());
}

- (BOOL)rememberCredentials {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_RememberCredentials(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setRememberCredentials:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_RememberCredentials((boolean)value));
}

- (BOOL)alwaysOn {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlwaysOn(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAlwaysOn:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_AlwaysOn((boolean)value));
}

- (BOOL)requireVpnClientAppUI {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNativeProfile2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequireVpnClientAppUI(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setRequireVpnClientAppUI:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNativeProfile2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RequireVpnClientAppUI((boolean)value));
}

- (WNVVpnManagementConnectionStatus)connectionStatus {
    ABI::Windows::Networking::Vpn::VpnManagementConnectionStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnNativeProfile2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionStatus(&unmarshalledReturn));
    return (WNVVpnManagementConnectionStatus)unmarshalledReturn;
}

@end

@implementation WNVVpnManagementAgent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Vpn::IVpnManagementAgent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Vpn.VpnManagementAgent").Get(), &out));
    return [_createRtProxy<WNVVpnManagementAgent>(out.Get()) retain];
}

- (void)addProfileFromXmlAsync:(NSString*)xml success:(void (^)(WNVVpnManagementErrorStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnManagementAgent>(self);
    THROW_NS_IF_FAILED(_comInst->AddProfileFromXmlAsync(nsStrToHstr(xml).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Networking::Vpn::VpnManagementErrorStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WNVVpnManagementErrorStatus)result);
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

- (void)addProfileFromObjectAsync:(RTObject<WNVIVpnProfile>*)profile
                          success:(void (^)(WNVVpnManagementErrorStatus))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnManagementAgent>(self);
    THROW_NS_IF_FAILED(_comInst->AddProfileFromObjectAsync(_getRtInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(profile).Get(),
                                                           &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Networking::Vpn::VpnManagementErrorStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WNVVpnManagementErrorStatus)result);
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

- (void)updateProfileFromXmlAsync:(NSString*)xml
                          success:(void (^)(WNVVpnManagementErrorStatus))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnManagementAgent>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateProfileFromXmlAsync(nsStrToHstr(xml).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Networking::Vpn::VpnManagementErrorStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WNVVpnManagementErrorStatus)result);
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

- (void)updateProfileFromObjectAsync:(RTObject<WNVIVpnProfile>*)profile
                             success:(void (^)(WNVVpnManagementErrorStatus))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnManagementAgent>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateProfileFromObjectAsync(_getRtInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(profile).Get(),
                                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Networking::Vpn::VpnManagementErrorStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WNVVpnManagementErrorStatus)result);
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

- (void)getProfilesAsyncWithSuccess:(void (^)(NSArray* /* RTObject<WNVIVpnProfile>* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::Vpn::IVpnProfile*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnManagementAgent>(self);
    THROW_NS_IF_FAILED(_comInst->GetProfilesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Networking::Vpn::IVpnProfile*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::Vpn::IVpnProfile*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Networking::Vpn::IVpnProfile*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_RTObject_WNVIVpnProfile_create(result.Get()));
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

- (void)deleteProfileAsync:(RTObject<WNVIVpnProfile>*)profile
                   success:(void (^)(WNVVpnManagementErrorStatus))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnManagementAgent>(self);
    THROW_NS_IF_FAILED(
        _comInst->DeleteProfileAsync(_getRtInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(profile).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Networking::Vpn::VpnManagementErrorStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WNVVpnManagementErrorStatus)result);
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

- (void)connectProfileAsync:(RTObject<WNVIVpnProfile>*)profile
                    success:(void (^)(WNVVpnManagementErrorStatus))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnManagementAgent>(self);
    THROW_NS_IF_FAILED(
        _comInst->ConnectProfileAsync(_getRtInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(profile).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Networking::Vpn::VpnManagementErrorStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WNVVpnManagementErrorStatus)result);
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

- (void)connectProfileWithPasswordCredentialAsync:(RTObject<WNVIVpnProfile>*)profile
                               passwordCredential:(WSCPasswordCredential*)passwordCredential
                                          success:(void (^)(WNVVpnManagementErrorStatus))success
                                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnManagementAgent>(self);
    THROW_NS_IF_FAILED(_comInst->ConnectProfileWithPasswordCredentialAsync(
        _getRtInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(profile).Get(),
        _getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(passwordCredential).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Networking::Vpn::VpnManagementErrorStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WNVVpnManagementErrorStatus)result);
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

- (void)disconnectProfileAsync:(RTObject<WNVIVpnProfile>*)profile
                       success:(void (^)(WNVVpnManagementErrorStatus))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Vpn::IVpnManagementAgent>(self);
    THROW_NS_IF_FAILED(
        _comInst->DisconnectProfileAsync(_getRtInterface<ABI::Windows::Networking::Vpn::IVpnProfile>(profile).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Vpn::VpnManagementErrorStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Networking::Vpn::VpnManagementErrorStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WNVVpnManagementErrorStatus)result);
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

id RTProxiedIterableNSArray_WNHostName_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Networking::HostName*>,
                                                 RTIterableObj<ABI::Windows::Networking::IHostName*,
                                                               IIterable<ABI::Windows::Networking::HostName*>,
                                                               WNHostName,
                                                               ABI::Windows::Networking::HostName*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_RTObject_WNVIVpnCustomPrompt_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::Vpn::IVpnCustomPrompt*>,
                                         RTArrayObj<ABI::Windows::Networking::Vpn::IVpnCustomPrompt*,
                                                    IVectorView<ABI::Windows::Networking::Vpn::IVpnCustomPrompt*>,
                                                    RTObject<WNVIVpnCustomPrompt>,
                                                    ABI::Windows::Networking::Vpn::IVpnCustomPrompt*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_RTObject_WNVIVpnCustomPromptElement_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement*>,
                                         RTArrayObj<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement*,
                                                    IVectorView<ABI::Windows::Networking::Vpn::IVpnCustomPromptElement*>,
                                                    RTObject<WNVIVpnCustomPromptElement>,
                                                    ABI::Windows::Networking::Vpn::IVpnCustomPromptElement*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_RTObject_WNVIVpnProfile_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::Vpn::IVpnProfile*>,
                                         RTArrayObj<ABI::Windows::Networking::Vpn::IVpnProfile*,
                                                    IVectorView<ABI::Windows::Networking::Vpn::IVpnProfile*>,
                                                    RTObject<WNVIVpnProfile>,
                                                    ABI::Windows::Networking::Vpn::IVpnProfile*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WFUri_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Foundation::Uri*>,
                                                                             RTArrayObj<ABI::Windows::Foundation::IUriRuntimeClass*,
                                                                                        IVectorView<ABI::Windows::Foundation::Uri*>,
                                                                                        WFUri,
                                                                                        ABI::Windows::Foundation::Uri*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WNHostName_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::HostName*>,
                                                                             RTArrayObj<ABI::Windows::Networking::IHostName*,
                                                                                        IVectorView<ABI::Windows::Networking::HostName*>,
                                                                                        WNHostName,
                                                                                        ABI::Windows::Networking::HostName*,
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

id RTProxiedNSMutableArray_WFUri_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Foundation::Uri*>,
                                                RTMutableArrayObj<ABI::Windows::Foundation::IUriRuntimeClass*,
                                                                  IVector<ABI::Windows::Foundation::Uri*>,
                                                                  WFUri,
                                                                  ABI::Windows::Foundation::Uri*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WNHostName_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Networking::HostName*>,
                                                RTMutableArrayObj<ABI::Windows::Networking::IHostName*,
                                                                  IVector<ABI::Windows::Networking::HostName*>,
                                                                  WNHostName,
                                                                  ABI::Windows::Networking::HostName*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WNVVpnAppId_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Networking::Vpn::VpnAppId*>,
                                                RTMutableArrayObj<ABI::Windows::Networking::Vpn::IVpnAppId*,
                                                                  IVector<ABI::Windows::Networking::Vpn::VpnAppId*>,
                                                                  WNVVpnAppId,
                                                                  ABI::Windows::Networking::Vpn::VpnAppId*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WNVVpnDomainNameInfo_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Networking::Vpn::VpnDomainNameInfo*>,
                                                RTMutableArrayObj<ABI::Windows::Networking::Vpn::IVpnDomainNameInfo*,
                                                                  IVector<ABI::Windows::Networking::Vpn::VpnDomainNameInfo*>,
                                                                  WNVVpnDomainNameInfo,
                                                                  ABI::Windows::Networking::Vpn::VpnDomainNameInfo*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WNVVpnNamespaceInfo_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Networking::Vpn::VpnNamespaceInfo*>,
                                                RTMutableArrayObj<ABI::Windows::Networking::Vpn::IVpnNamespaceInfo*,
                                                                  IVector<ABI::Windows::Networking::Vpn::VpnNamespaceInfo*>,
                                                                  WNVVpnNamespaceInfo,
                                                                  ABI::Windows::Networking::Vpn::VpnNamespaceInfo*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WNVVpnRoute_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Networking::Vpn::VpnRoute*>,
                                                RTMutableArrayObj<ABI::Windows::Networking::Vpn::IVpnRoute*,
                                                                  IVector<ABI::Windows::Networking::Vpn::VpnRoute*>,
                                                                  WNVVpnRoute,
                                                                  ABI::Windows::Networking::Vpn::VpnRoute*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WNVVpnTrafficFilter_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Networking::Vpn::VpnTrafficFilter*>,
                                                RTMutableArrayObj<ABI::Windows::Networking::Vpn::IVpnTrafficFilter*,
                                                                  IVector<ABI::Windows::Networking::Vpn::VpnTrafficFilter*>,
                                                                  WNVVpnTrafficFilter,
                                                                  ABI::Windows::Networking::Vpn::VpnTrafficFilter*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
