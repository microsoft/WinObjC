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

// WindowsDevicesWiFiDirect.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.WiFiDirect.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesWiFiDirect.h"
#include "WindowsDevicesWiFiDirect_priv.h"

@implementation WDWWiFiDirectDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectDeviceStatics2> WDWIWiFiDirectDeviceStatics2_inst() {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectDeviceStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.WiFiDirect.WiFiDirectDevice").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)getDeviceSelector:(WDWWiFiDirectDeviceSelectorType)type {
    HSTRING unmarshalledReturn;
    auto _comInst = WDWIWiFiDirectDeviceStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetDeviceSelector((ABI::Windows::Devices::WiFiDirect::WiFiDirectDeviceSelectorType)type, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)fromIdAsync:(NSString*)deviceId
    connectionParameters:(WDWWiFiDirectConnectionParameters*)connectionParameters
                 success:(void (^)(WDWWiFiDirectDevice*))success
                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFiDirect::WiFiDirectDevice*>> unmarshalledReturn;
    auto _comInst = WDWIWiFiDirectDeviceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(
        nsStrToHstr(deviceId).Get(),
        _getRtInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionParameters>(connectionParameters).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::WiFiDirect::WiFiDirectDevice*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFiDirect::WiFiDirectDevice*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectDevice> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDWWiFiDirectDevice>(result.Get()));
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

ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectDeviceStatics> WDWIWiFiDirectDeviceStatics_inst() {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.WiFiDirect.WiFiDirectDevice").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDWIWiFiDirectDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDWWiFiDirectDevice*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFiDirect::WiFiDirectDevice*>> unmarshalledReturn;
    auto _comInst = WDWIWiFiDirectDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::WiFiDirect::WiFiDirectDevice*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::WiFiDirect::WiFiDirectDevice*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectDevice> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDWWiFiDirectDevice>(result.Get()));
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

- (WDWWiFiDirectConnectionStatus)connectionStatus {
    ABI::Windows::Devices::WiFiDirect::WiFiDirectConnectionStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionStatus(&unmarshalledReturn));
    return (WDWWiFiDirectConnectionStatus)unmarshalledReturn;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (EventRegistrationToken)addConnectionStatusChangedEvent:(void (^)(WDWWiFiDirectDevice*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectDevice>(self);
    THROW_NS_IF_FAILED(_comInst->add_ConnectionStatusChanged(
        Make<ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectDevice_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeConnectionStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ConnectionStatusChanged(token));
}

- (NSArray* /* WNEndpointPair* */)getConnectionEndpointPairs {
    ComPtr<IVectorView<ABI::Windows::Networking::EndpointPair*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectDevice>(self);
    THROW_NS_IF_FAILED(_comInst->GetConnectionEndpointPairs(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNEndpointPair_create(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDWWiFiDirectConnectionParameters

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionParameters> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.WiFiDirect.WiFiDirectConnectionParameters").Get(),
                                              &out));
    return [_createRtProxy<WDWWiFiDirectConnectionParameters>(out.Get()) retain];
}

ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionParametersStatics> WDWIWiFiDirectConnectionParametersStatics_inst() {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionParametersStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.WiFiDirect.WiFiDirectConnectionParameters").Get(), &inst));
    return inst;
}

+ (WDEDevicePairingKinds)getDevicePairingKinds:(WDWWiFiDirectConfigurationMethod)configurationMethod {
    ABI::Windows::Devices::Enumeration::DevicePairingKinds unmarshalledReturn;
    auto _comInst = WDWIWiFiDirectConnectionParametersStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetDevicePairingKinds((ABI::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod)configurationMethod,
                                        &unmarshalledReturn));
    return (WDEDevicePairingKinds)unmarshalledReturn;
}

- (int16_t)groupOwnerIntent {
    int16_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_GroupOwnerIntent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setGroupOwnerIntent:(int16_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_GroupOwnerIntent(value));
}

- (NSMutableArray* /* WDWWiFiDirectConfigurationMethod */)preferenceOrderedConfigurationMethods {
    ComPtr<IVector<ABI::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionParameters2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreferenceOrderedConfigurationMethods(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDWWiFiDirectConfigurationMethod_create(unmarshalledReturn.Get());
}

- (WDWWiFiDirectPairingProcedure)preferredPairingProcedure {
    ABI::Windows::Devices::WiFiDirect::WiFiDirectPairingProcedure unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionParameters2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreferredPairingProcedure(&unmarshalledReturn));
    return (WDWWiFiDirectPairingProcedure)unmarshalledReturn;
}

- (void)setPreferredPairingProcedure:(WDWWiFiDirectPairingProcedure)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionParameters2>(self);
    THROW_NS_IF_FAILED(_comInst->put_PreferredPairingProcedure((ABI::Windows::Devices::WiFiDirect::WiFiDirectPairingProcedure)value));
}

@end

@implementation WDWWiFiDirectInformationElement

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectInformationElement> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.WiFiDirect.WiFiDirectInformationElement").Get(),
                                              &out));
    return [_createRtProxy<WDWWiFiDirectInformationElement>(out.Get()) retain];
}

ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectInformationElementStatics> WDWIWiFiDirectInformationElementStatics_inst() {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectInformationElementStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.WiFiDirect.WiFiDirectInformationElement").Get(), &inst));
    return inst;
}

+ (NSMutableArray* /* WDWWiFiDirectInformationElement* */)createFromBuffer:(RTObject<WSSIBuffer>*)buffer {
    ComPtr<IVector<ABI::Windows::Devices::WiFiDirect::WiFiDirectInformationElement*>> unmarshalledReturn;
    auto _comInst = WDWIWiFiDirectInformationElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDWWiFiDirectInformationElement_create(unmarshalledReturn.Get());
}

+ (NSMutableArray* /* WDWWiFiDirectInformationElement* */)createFromDeviceInformation:(WDEDeviceInformation*)deviceInformation {
    ComPtr<IVector<ABI::Windows::Devices::WiFiDirect::WiFiDirectInformationElement*>> unmarshalledReturn;
    auto _comInst = WDWIWiFiDirectInformationElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromDeviceInformation(
        _getRtInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(deviceInformation).Get(),
        unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDWWiFiDirectInformationElement_create(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)oui {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectInformationElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Oui(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setOui:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectInformationElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Oui(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (uint8_t)ouiType {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectInformationElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_OuiType(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOuiType:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectInformationElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_OuiType(value));
}

- (RTObject<WSSIBuffer>*)value {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectInformationElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setValue:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectInformationElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

@end

@implementation WDWWiFiDirectLegacySettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectLegacySettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectLegacySettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectLegacySettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsEnabled((boolean)value));
}

- (NSString*)ssid {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectLegacySettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_Ssid(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSsid:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectLegacySettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_Ssid(nsStrToHstr(value).Get()));
}

- (WSCPasswordCredential*)passphrase {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectLegacySettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_Passphrase(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setPassphrase:(WSCPasswordCredential*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectLegacySettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_Passphrase(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(value).Get()));
}

@end

@implementation WDWWiFiDirectAdvertisement

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSMutableArray* /* WDWWiFiDirectInformationElement* */)informationElements {
    ComPtr<IVector<ABI::Windows::Devices::WiFiDirect::WiFiDirectInformationElement*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement>(self);
    THROW_NS_IF_FAILED(_comInst->get_InformationElements(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDWWiFiDirectInformationElement_create(unmarshalledReturn.Get());
}

- (void)setInformationElements:(NSMutableArray* /* WDWWiFiDirectInformationElement* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement>(self);
    THROW_NS_IF_FAILED(_comInst->put_InformationElements(
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::WiFiDirect::WiFiDirectInformationElement*,
                                                              ABI::Windows::Devices::WiFiDirect::IWiFiDirectInformationElement*>>::type>*>(
            ConvertToVector<
                WDWWiFiDirectInformationElement,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::WiFiDirect::WiFiDirectInformationElement*,
                                                                  ABI::Windows::Devices::WiFiDirect::IWiFiDirectInformationElement*>>(value)
                .Get())));
}

- (WDWWiFiDirectAdvertisementListenStateDiscoverability)listenStateDiscoverability {
    ABI::Windows::Devices::WiFiDirect::WiFiDirectAdvertisementListenStateDiscoverability unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement>(self);
    THROW_NS_IF_FAILED(_comInst->get_ListenStateDiscoverability(&unmarshalledReturn));
    return (WDWWiFiDirectAdvertisementListenStateDiscoverability)unmarshalledReturn;
}

- (void)setListenStateDiscoverability:(WDWWiFiDirectAdvertisementListenStateDiscoverability)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement>(self);
    THROW_NS_IF_FAILED(_comInst->put_ListenStateDiscoverability(
        (ABI::Windows::Devices::WiFiDirect::WiFiDirectAdvertisementListenStateDiscoverability)value));
}

- (BOOL)isAutonomousGroupOwnerEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAutonomousGroupOwnerEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsAutonomousGroupOwnerEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsAutonomousGroupOwnerEnabled((boolean)value));
}

- (WDWWiFiDirectLegacySettings*)legacySettings {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectLegacySettings> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement>(self);
    THROW_NS_IF_FAILED(_comInst->get_LegacySettings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDWWiFiDirectLegacySettings>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WDWWiFiDirectConfigurationMethod */)supportedConfigurationMethods {
    ComPtr<IVector<ABI::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedConfigurationMethods(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDWWiFiDirectConfigurationMethod_create(unmarshalledReturn.Get());
}

@end

@implementation WDWWiFiDirectAdvertisementPublisherStatusChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisherStatusChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDWWiFiDirectAdvertisementPublisherStatus)status {
    ABI::Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisherStatusChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDWWiFiDirectAdvertisementPublisherStatus)unmarshalledReturn;
}

- (WDWWiFiDirectError)error {
    ABI::Windows::Devices::WiFiDirect::WiFiDirectError unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisherStatusChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Error(&unmarshalledReturn));
    return (WDWWiFiDirectError)unmarshalledReturn;
}

@end

@implementation WDWWiFiDirectAdvertisementPublisher

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.WiFiDirect.WiFiDirectAdvertisementPublisher").Get(),
                                              &out));
    return [_createRtProxy<WDWWiFiDirectAdvertisementPublisher>(out.Get()) retain];
}

- (WDWWiFiDirectAdvertisement*)advertisement {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher>(self);
    THROW_NS_IF_FAILED(_comInst->get_Advertisement(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDWWiFiDirectAdvertisement>(unmarshalledReturn.Get());
}

- (WDWWiFiDirectAdvertisementPublisherStatus)status {
    ABI::Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDWWiFiDirectAdvertisementPublisherStatus)unmarshalledReturn;
}

- (EventRegistrationToken)addStatusChangedEvent:(void (^)(WDWWiFiDirectAdvertisementPublisher*,
                                                          WDWWiFiDirectAdvertisementPublisherStatusChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher>(self);
    THROW_NS_IF_FAILED(_comInst->add_StatusChanged(
        Make<
            ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectAdvertisementPublisher_Windows_Devices_WiFiDirect_WiFiDirectAdvertisementPublisherStatusChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StatusChanged(token));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

@end

@implementation WDWWiFiDirectConnectionRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDEDeviceInformation*)deviceInformation {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformation>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDWWiFiDirectConnectionRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDWWiFiDirectConnectionRequest*)getConnectionRequest {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetConnectionRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDWWiFiDirectConnectionRequest>(unmarshalledReturn.Get());
}

@end

@implementation WDWWiFiDirectConnectionListener

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionListener> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.WiFiDirect.WiFiDirectConnectionListener").Get(),
                                              &out));
    return [_createRtProxy<WDWWiFiDirectConnectionListener>(out.Get()) retain];
}

- (EventRegistrationToken)addConnectionRequestedEvent:(void (^)(WDWWiFiDirectConnectionListener*,
                                                                WDWWiFiDirectConnectionRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionListener>(self);
    THROW_NS_IF_FAILED(_comInst->add_ConnectionRequested(
        Make<
            ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectConnectionListener_Windows_Devices_WiFiDirect_WiFiDirectConnectionRequestedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeConnectionRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionListener>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ConnectionRequested(token));
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

id RTProxiedNSMutableArray_WDWWiFiDirectConfigurationMethod_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod>,
                                                RTMutableArrayObj<ABI::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod,
                                                                  IVector<ABI::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod>,
                                                                  WDWWiFiDirectConfigurationMethod,
                                                                  ABI::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WDWWiFiDirectInformationElement_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Devices::WiFiDirect::WiFiDirectInformationElement*>,
                                                RTMutableArrayObj<ABI::Windows::Devices::WiFiDirect::IWiFiDirectInformationElement*,
                                                                  IVector<ABI::Windows::Devices::WiFiDirect::WiFiDirectInformationElement*>,
                                                                  WDWWiFiDirectInformationElement,
                                                                  ABI::Windows::Devices::WiFiDirect::WiFiDirectInformationElement*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
