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

// WindowsDevicesAllJoyn.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.AllJoyn.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesAllJoyn.h"
#include "WindowsDevicesAllJoyn_priv.h"

@implementation WDAIAllJoynProducer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynProducer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setBusObject:(WDAAllJoynBusObject*)busObject {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynProducer>(self);
    THROW_NS_IF_FAILED(_comInst->SetBusObject(_getRtInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusObject>(busObject).Get()));
}

@end

@implementation WDAIAllJoynAcceptSessionJoiner

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoiner> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)accept {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoiner>(self);
    THROW_NS_IF_FAILED(_comInst->Accept());
}

@end

@implementation WDAAllJoynStatus

ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynStatusStatics> WDAIAllJoynStatusStatics_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynStatusStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynStatus").Get(), &inst));
    return inst;
}

+ (int)ok {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ok(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)fail {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Fail(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)operationTimedOut {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OperationTimedOut(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)otherEndClosed {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OtherEndClosed(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)connectionRefused {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ConnectionRefused(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)authenticationFailed {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AuthenticationFailed(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)authenticationRejectedByUser {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AuthenticationRejectedByUser(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)sslConnectFailed {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SslConnectFailed(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)sslIdentityVerificationFailed {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SslIdentityVerificationFailed(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)insufficientSecurity {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_InsufficientSecurity(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)invalidArgument1 {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_InvalidArgument1(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)invalidArgument2 {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_InvalidArgument2(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)invalidArgument3 {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_InvalidArgument3(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)invalidArgument4 {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_InvalidArgument4(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)invalidArgument5 {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_InvalidArgument5(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)invalidArgument6 {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_InvalidArgument6(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)invalidArgument7 {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_InvalidArgument7(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)invalidArgument8 {
    int unmarshalledReturn;
    auto _comInst = WDAIAllJoynStatusStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_InvalidArgument8(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDAAllJoynAboutData

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsEnabled((boolean)value));
}

- (NSString*)defaultAppName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultAppName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDefaultAppName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->put_DefaultAppName(nsStrToHstr(value).Get()));
}

- (NSMutableDictionary* /* NSString *, NSString * */)appNames {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppNames(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

- (id /* WFDateTime* */)dateOfManufacture {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->get_DateOfManufacture(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setDateOfManufacture:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->put_DateOfManufacture(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (NSString*)defaultDescription {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultDescription(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDefaultDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->put_DefaultDescription(nsStrToHstr(value).Get()));
}

- (NSMutableDictionary* /* NSString *, NSString * */)descriptions {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Descriptions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)defaultManufacturer {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultManufacturer(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDefaultManufacturer:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->put_DefaultManufacturer(nsStrToHstr(value).Get()));
}

- (NSMutableDictionary* /* NSString *, NSString * */)manufacturers {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Manufacturers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)modelNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->get_ModelNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setModelNumber:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->put_ModelNumber(nsStrToHstr(value).Get()));
}

- (NSString*)softwareVersion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->get_SoftwareVersion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSoftwareVersion:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->put_SoftwareVersion(nsStrToHstr(value).Get()));
}

- (WFUri*)supportUrl {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportUrl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setSupportUrl:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->put_SupportUrl(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFGUID*)appId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (void)setAppId:(WFGUID*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData>(self);
    THROW_NS_IF_FAILED(_comInst->put_AppId(value.guidValue));
}

@end

@implementation WDAAllJoynBusAttachment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachmentFactory> WDAIAllJoynBusAttachmentFactory_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachmentFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynBusAttachment").Get(),
                                                       &inst));
    return inst;
}

+ (WDAAllJoynBusAttachment*)make:(NSString*)connectionSpecification {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment> unmarshalledReturn;
    auto _comInst = WDAIAllJoynBusAttachmentFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(connectionSpecification).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDAAllJoynBusAttachment>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynBusAttachment").Get(), &out));
    return [_createRtProxy<WDAAllJoynBusAttachment>(out.Get()) retain];
}

ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachmentStatics> WDAIAllJoynBusAttachmentStatics_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachmentStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynBusAttachment").Get(),
                                                       &inst));
    return inst;
}

+ (WDAAllJoynBusAttachment*)getDefault {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment> unmarshalledReturn;
    auto _comInst = WDAIAllJoynBusAttachmentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDAAllJoynBusAttachment>(unmarshalledReturn.Get());
}

+ (WDEDeviceWatcher*)getWatcher:(id<NSFastEnumeration> /* NSString * */)requiredInterfaces {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceWatcher> unmarshalledReturn;
    auto _comInst = WDAIAllJoynBusAttachmentStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetWatcher(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                 ConvertToIterable<NSString, HSTRING>(requiredInterfaces).Get()),
                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceWatcher>(unmarshalledReturn.Get());
}

- (WDAAllJoynAboutData*)aboutData {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAboutData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->get_AboutData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDAAllJoynAboutData>(unmarshalledReturn.Get());
}

- (NSString*)connectionSpecification {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionSpecification(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDAAllJoynBusAttachmentState)state {
    ABI::Windows::Devices::AllJoyn::AllJoynBusAttachmentState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WDAAllJoynBusAttachmentState)unmarshalledReturn;
}

- (NSString*)uniqueName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->get_UniqueName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)pingAsync:(NSString*)uniqueName success:(void (^)(int))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->PingAsync(nsStrToHstr(uniqueName).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<int>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        int result;
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

- (void)connect {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->Connect());
}

- (void)disconnect {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->Disconnect());
}

- (EventRegistrationToken)addStateChangedEvent:(void (^)(WDAAllJoynBusAttachment*, WDAAllJoynBusAttachmentStateChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->add_StateChanged(
        Make<
            ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynBusAttachmentStateChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStateChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StateChanged(token));
}

- (NSMutableArray* /* WDAAllJoynAuthenticationMechanism */)authenticationMechanisms {
    ComPtr<IVector<ABI::Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->get_AuthenticationMechanisms(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDAAllJoynAuthenticationMechanism_create(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addCredentialsRequestedEvent:(void (^)(WDAAllJoynBusAttachment*,
                                                                 WDAAllJoynCredentialsRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->add_CredentialsRequested(
        Make<ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynCredentialsRequestedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCredentialsRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CredentialsRequested(token));
}

- (EventRegistrationToken)addCredentialsVerificationRequestedEvent:(void (^)(WDAAllJoynBusAttachment*,
                                                                             WDAAllJoynCredentialsVerificationRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->add_CredentialsVerificationRequested(
        Make<
            ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynCredentialsVerificationRequestedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCredentialsVerificationRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CredentialsVerificationRequested(token));
}

- (EventRegistrationToken)addAuthenticationCompleteEvent:(void (^)(WDAAllJoynBusAttachment*,
                                                                   WDAAllJoynAuthenticationCompleteEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->add_AuthenticationComplete(
        Make<
            ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynAuthenticationCompleteEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAuthenticationCompleteEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AuthenticationComplete(token));
}

- (void)getAboutDataAsync:(WDAAllJoynServiceInfo*)serviceInfo
                  success:(void (^)(WDAAllJoynAboutDataView*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::AllJoyn::AllJoynAboutDataView*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->GetAboutDataAsync(_getRtInterface<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfo>(serviceInfo).Get(),
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::AllJoyn::AllJoynAboutDataView*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::AllJoyn::AllJoynAboutDataView*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDAAllJoynAboutDataView>(result.Get()));
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

- (void)getAboutDataWithLanguageAsync:(WDAAllJoynServiceInfo*)serviceInfo
                             language:(WGLanguage*)language
                              success:(void (^)(WDAAllJoynAboutDataView*))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::AllJoyn::AllJoynAboutDataView*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment2>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetAboutDataWithLanguageAsync(_getRtInterface<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfo>(serviceInfo).Get(),
                                                _getRtInterface<ABI::Windows::Globalization::ILanguage>(language).Get(),
                                                &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::AllJoyn::AllJoynAboutDataView*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::AllJoyn::AllJoynAboutDataView*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDAAllJoynAboutDataView>(result.Get()));
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

- (EventRegistrationToken)addAcceptSessionJoinerRequestedEvent:(void (^)(WDAAllJoynBusAttachment*,
                                                                         WDAAllJoynAcceptSessionJoinerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->add_AcceptSessionJoinerRequested(
        Make<ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynAcceptSessionJoinerEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAcceptSessionJoinerRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AcceptSessionJoinerRequested(token));
}

- (EventRegistrationToken)addSessionJoinedEvent:(void (^)(WDAAllJoynBusAttachment*, WDAAllJoynSessionJoinedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->add_SessionJoined(
        Make<ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynSessionJoinedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSessionJoinedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SessionJoined(token));
}

@end

@implementation WDAAllJoynBusAttachmentStateChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachmentStateChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDAAllJoynBusAttachmentState)state {
    ABI::Windows::Devices::AllJoyn::AllJoynBusAttachmentState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachmentStateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WDAAllJoynBusAttachmentState)unmarshalledReturn;
}

- (int)status {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachmentStateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDAAllJoynCredentialsRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned short)attemptCount {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AttemptCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDAAllJoynCredentials*)credentials {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynCredentials> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Credentials(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDAAllJoynCredentials>(unmarshalledReturn.Get());
}

- (NSString*)peerUniqueName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PeerUniqueName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)requestedUserName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestedUserName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WDAAllJoynCredentialsVerificationRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsVerificationRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDAAllJoynAuthenticationMechanism)authenticationMechanism {
    ABI::Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsVerificationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AuthenticationMechanism(&unmarshalledReturn));
    return (WDAAllJoynAuthenticationMechanism)unmarshalledReturn;
}

- (NSString*)peerUniqueName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsVerificationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PeerUniqueName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSCCCertificate*)peerCertificate {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsVerificationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PeerCertificate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (WNSSocketSslErrorSeverity)peerCertificateErrorSeverity {
    ABI::Windows::Networking::Sockets::SocketSslErrorSeverity unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsVerificationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PeerCertificateErrorSeverity(&unmarshalledReturn));
    return (WNSSocketSslErrorSeverity)unmarshalledReturn;
}

- (NSArray* /* WSCCChainValidationResult */)peerCertificateErrors {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsVerificationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PeerCertificateErrors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCChainValidationResult_create(unmarshalledReturn.Get());
}

- (NSArray* /* WSCCCertificate* */)peerIntermediateCertificates {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsVerificationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PeerIntermediateCertificates(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCCertificate_create(unmarshalledReturn.Get());
}

- (void)accept {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsVerificationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->Accept());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsVerificationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WDAAllJoynAuthenticationCompleteEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAuthenticationCompleteEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDAAllJoynAuthenticationMechanism)authenticationMechanism {
    ABI::Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAuthenticationCompleteEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AuthenticationMechanism(&unmarshalledReturn));
    return (WDAAllJoynAuthenticationMechanism)unmarshalledReturn;
}

- (NSString*)peerUniqueName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAuthenticationCompleteEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PeerUniqueName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)succeeded {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAuthenticationCompleteEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Succeeded(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDAAllJoynServiceInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfoFactory> WDAIAllJoynServiceInfoFactory_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfoFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynServiceInfo").Get(), &inst));
    return inst;
}

+ (WDAAllJoynServiceInfo*)make:(NSString*)uniqueName objectPath:(NSString*)objectPath sessionPort:(unsigned short)sessionPort {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfo> unmarshalledReturn;
    auto _comInst = WDAIAllJoynServiceInfoFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(nsStrToHstr(uniqueName).Get(), nsStrToHstr(objectPath).Get(), sessionPort, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDAAllJoynServiceInfo>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfoStatics> WDAIAllJoynServiceInfoStatics_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfoStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynServiceInfo").Get(), &inst));
    return inst;
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDAAllJoynServiceInfo*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::AllJoyn::AllJoynServiceInfo*>> unmarshalledReturn;
    auto _comInst = WDAIAllJoynServiceInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::AllJoyn::AllJoynServiceInfo*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::AllJoyn::AllJoynServiceInfo*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfo> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDAAllJoynServiceInfo>(result.Get()));
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

- (NSString*)uniqueName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_UniqueName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)objectPath {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ObjectPath(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned short)sessionPort {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SessionPort(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDAAllJoynAboutDataView

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataViewStatics> WDAIAllJoynAboutDataViewStatics_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataViewStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynAboutDataView").Get(),
                                                       &inst));
    return inst;
}

+ (void)getDataBySessionPortAsync:(NSString*)uniqueName
                    busAttachment:(WDAAllJoynBusAttachment*)busAttachment
                      sessionPort:(unsigned short)sessionPort
                          success:(void (^)(WDAAllJoynAboutDataView*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::AllJoyn::AllJoynAboutDataView*>> unmarshalledReturn;
    auto _comInst = WDAIAllJoynAboutDataViewStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetDataBySessionPortAsync(nsStrToHstr(uniqueName).Get(),
                                            _getRtInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(busAttachment).Get(),
                                            sessionPort,
                                            &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::AllJoyn::AllJoynAboutDataView*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::AllJoyn::AllJoynAboutDataView*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDAAllJoynAboutDataView>(result.Get()));
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

+ (void)getDataBySessionPortWithLanguageAsync:(NSString*)uniqueName
                                busAttachment:(WDAAllJoynBusAttachment*)busAttachment
                                  sessionPort:(unsigned short)sessionPort
                                     language:(WGLanguage*)language
                                      success:(void (^)(WDAAllJoynAboutDataView*))success
                                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::AllJoyn::AllJoynAboutDataView*>> unmarshalledReturn;
    auto _comInst = WDAIAllJoynAboutDataViewStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDataBySessionPortWithLanguageAsync(
        nsStrToHstr(uniqueName).Get(),
        _getRtInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(busAttachment).Get(),
        sessionPort,
        _getRtInterface<ABI::Windows::Globalization::ILanguage>(language).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::AllJoyn::AllJoynAboutDataView*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::AllJoyn::AllJoynAboutDataView*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDAAllJoynAboutDataView>(result.Get()));
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

- (int)status {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSDictionary* /* NSString *, RTObject* */)properties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

- (NSString*)aJSoftwareVersion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView>(self);
    THROW_NS_IF_FAILED(_comInst->get_AJSoftwareVersion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFGUID*)appId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (id /* WFDateTime* */)dateOfManufacture {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView>(self);
    THROW_NS_IF_FAILED(_comInst->get_DateOfManufacture(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (WGLanguage*)defaultLanguage {
    ComPtr<ABI::Windows::Globalization::ILanguage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultLanguage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGLanguage>(unmarshalledReturn.Get());
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)hardwareVersion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView>(self);
    THROW_NS_IF_FAILED(_comInst->get_HardwareVersion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)modelNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView>(self);
    THROW_NS_IF_FAILED(_comInst->get_ModelNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)softwareVersion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView>(self);
    THROW_NS_IF_FAILED(_comInst->get_SoftwareVersion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* WGLanguage* */)supportedLanguages {
    ComPtr<IVectorView<ABI::Windows::Globalization::Language*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedLanguages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGLanguage_create(unmarshalledReturn.Get());
}

- (WFUri*)supportUrl {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportUrl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (NSString*)appName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)deviceName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)manufacturer {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView>(self);
    THROW_NS_IF_FAILED(_comInst->get_Manufacturer(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDAAllJoynAcceptSessionJoinerEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgsFactory>
WDAIAllJoynAcceptSessionJoinerEventArgsFactory_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgsFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynAcceptSessionJoinerEventArgs").Get(), &inst));
    return inst;
}

+ (WDAAllJoynAcceptSessionJoinerEventArgs*)make:(NSString*)uniqueName
                                    sessionPort:(unsigned short)sessionPort
                                    trafficType:(WDAAllJoynTrafficType)trafficType
                                      proximity:(uint8_t)proximity
                            acceptSessionJoiner:(RTObject<WDAIAllJoynAcceptSessionJoiner>*)acceptSessionJoiner {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgs> unmarshalledReturn;
    auto _comInst = WDAIAllJoynAcceptSessionJoinerEventArgsFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(nsStrToHstr(uniqueName).Get(),
                         sessionPort,
                         (ABI::Windows::Devices::AllJoyn::AllJoynTrafficType)trafficType,
                         proximity,
                         _getRtInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoiner>(acceptSessionJoiner).Get(),
                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDAAllJoynAcceptSessionJoinerEventArgs>(unmarshalledReturn.Get()) retain];
}

- (NSString*)uniqueName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_UniqueName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned short)sessionPort {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SessionPort(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDAAllJoynTrafficType)trafficType {
    ABI::Windows::Devices::AllJoyn::AllJoynTrafficType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrafficType(&unmarshalledReturn));
    return (WDAAllJoynTrafficType)unmarshalledReturn;
}

- (BOOL)samePhysicalNode {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SamePhysicalNode(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)sameNetwork {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SameNetwork(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)accept {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->Accept());
}

@end

@implementation WDAAllJoynSessionJoinedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionJoinedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionJoinedEventArgsFactory> WDAIAllJoynSessionJoinedEventArgsFactory_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionJoinedEventArgsFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynSessionJoinedEventArgs").Get(), &inst));
    return inst;
}

+ (WDAAllJoynSessionJoinedEventArgs*)make:(WDAAllJoynSession*)session {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionJoinedEventArgs> unmarshalledReturn;
    auto _comInst = WDAIAllJoynSessionJoinedEventArgsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(_getRtInterface<ABI::Windows::Devices::AllJoyn::IAllJoynSession>(session).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDAAllJoynSessionJoinedEventArgs>(unmarshalledReturn.Get()) retain];
}

- (WDAAllJoynSession*)session {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSession> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynSessionJoinedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Session(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDAAllJoynSession>(unmarshalledReturn.Get());
}

@end

@implementation WDAAllJoynCredentials

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynCredentials> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDAAllJoynAuthenticationMechanism)authenticationMechanism {
    ABI::Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentials>(self);
    THROW_NS_IF_FAILED(_comInst->get_AuthenticationMechanism(&unmarshalledReturn));
    return (WDAAllJoynAuthenticationMechanism)unmarshalledReturn;
}

- (WSCCCertificate*)certificate {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentials>(self);
    THROW_NS_IF_FAILED(_comInst->get_Certificate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (void)setCertificate:(WSCCCertificate*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentials>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Certificate(_getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(value).Get()));
}

- (WSCPasswordCredential*)passwordCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentials>(self);
    THROW_NS_IF_FAILED(_comInst->get_PasswordCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setPasswordCredential:(WSCPasswordCredential*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentials>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_PasswordCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(value).Get()));
}

- (WFTimeSpan*)timeout {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentials>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timeout(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setTimeout:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynCredentials>(self);
    THROW_NS_IF_FAILED(_comInst->put_Timeout(*[value internalStruct]));
}

@end

@implementation WDAAllJoynSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionStatics> WDAIAllJoynSessionStatics_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynSession").Get(), &inst));
    return inst;
}

+ (void)getFromServiceInfoAsync:(WDAAllJoynServiceInfo*)serviceInfo
                        success:(void (^)(WDAAllJoynSession*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::AllJoyn::AllJoynSession*>> unmarshalledReturn;
    auto _comInst = WDAIAllJoynSessionStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetFromServiceInfoAsync(_getRtInterface<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfo>(serviceInfo).Get(),
                                          &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::AllJoyn::AllJoynSession*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::AllJoyn::AllJoynSession*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSession> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDAAllJoynSession>(result.Get()));
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

+ (void)getFromServiceInfoAndBusAttachmentAsync:(WDAAllJoynServiceInfo*)serviceInfo
                                  busAttachment:(WDAAllJoynBusAttachment*)busAttachment
                                        success:(void (^)(WDAAllJoynSession*))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::AllJoyn::AllJoynSession*>> unmarshalledReturn;
    auto _comInst = WDAIAllJoynSessionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetFromServiceInfoAndBusAttachmentAsync(
        _getRtInterface<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfo>(serviceInfo).Get(),
        _getRtInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(busAttachment).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::AllJoyn::AllJoynSession*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::AllJoyn::AllJoynSession*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSession> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDAAllJoynSession>(result.Get()));
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

- (int)id {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)status {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)removeMemberAsync:(NSString*)uniqueName success:(void (^)(int))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynSession>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveMemberAsync(nsStrToHstr(uniqueName).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<int>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        int result;
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

- (EventRegistrationToken)addMemberAddedEvent:(void (^)(WDAAllJoynSession*, WDAAllJoynSessionMemberAddedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynSession>(self);
    THROW_NS_IF_FAILED(_comInst->add_MemberAdded(
        Make<ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionMemberAddedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMemberAddedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MemberAdded(token));
}

- (EventRegistrationToken)addMemberRemovedEvent:(void (^)(WDAAllJoynSession*, WDAAllJoynSessionMemberRemovedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynSession>(self);
    THROW_NS_IF_FAILED(_comInst->add_MemberRemoved(
        Make<ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionMemberRemovedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMemberRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MemberRemoved(token));
}

- (EventRegistrationToken)addLostEvent:(void (^)(WDAAllJoynSession*, WDAAllJoynSessionLostEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynSession>(self);
    THROW_NS_IF_FAILED(_comInst->add_Lost(
        Make<ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionLostEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLostEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Lost(token));
}

@end

@implementation WDAAllJoynSessionMemberAddedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberAddedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberAddedEventArgsFactory>
WDAIAllJoynSessionMemberAddedEventArgsFactory_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberAddedEventArgsFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynSessionMemberAddedEventArgs").Get(), &inst));
    return inst;
}

+ (WDAAllJoynSessionMemberAddedEventArgs*)make:(NSString*)uniqueName {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberAddedEventArgs> unmarshalledReturn;
    auto _comInst = WDAIAllJoynSessionMemberAddedEventArgsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(uniqueName).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDAAllJoynSessionMemberAddedEventArgs>(unmarshalledReturn.Get()) retain];
}

- (NSString*)uniqueName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberAddedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_UniqueName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDAAllJoynSessionMemberRemovedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberRemovedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberRemovedEventArgsFactory>
WDAIAllJoynSessionMemberRemovedEventArgsFactory_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberRemovedEventArgsFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynSessionMemberRemovedEventArgs").Get(), &inst));
    return inst;
}

+ (WDAAllJoynSessionMemberRemovedEventArgs*)make:(NSString*)uniqueName {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberRemovedEventArgs> unmarshalledReturn;
    auto _comInst = WDAIAllJoynSessionMemberRemovedEventArgsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(uniqueName).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDAAllJoynSessionMemberRemovedEventArgs>(unmarshalledReturn.Get()) retain];
}

- (NSString*)uniqueName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberRemovedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_UniqueName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDAAllJoynSessionLostEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionLostEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionLostEventArgsFactory> WDAIAllJoynSessionLostEventArgsFactory_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionLostEventArgsFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynSessionLostEventArgs").Get(),
                                                       &inst));
    return inst;
}

+ (WDAAllJoynSessionLostEventArgs*)make:(WDAAllJoynSessionLostReason)reason {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionLostEventArgs> unmarshalledReturn;
    auto _comInst = WDAIAllJoynSessionLostEventArgsFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create((ABI::Windows::Devices::AllJoyn::AllJoynSessionLostReason)reason, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDAAllJoynSessionLostEventArgs>(unmarshalledReturn.Get()) retain];
}

- (WDAAllJoynSessionLostReason)reason {
    ABI::Windows::Devices::AllJoyn::AllJoynSessionLostReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynSessionLostEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reason(&unmarshalledReturn));
    return (WDAAllJoynSessionLostReason)unmarshalledReturn;
}

@end

@implementation WDAAllJoynBusObject

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusObject> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusObjectFactory> WDAIAllJoynBusObjectFactory_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusObjectFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynBusObject").Get(), &inst));
    return inst;
}

+ (WDAAllJoynBusObject*)make:(NSString*)objectPath {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusObject> unmarshalledReturn;
    auto _comInst = WDAIAllJoynBusObjectFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(objectPath).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDAAllJoynBusObject>(unmarshalledReturn.Get()) retain];
}

+ (WDAAllJoynBusObject*)makeWithBusAttachment:(NSString*)objectPath busAttachment:(WDAAllJoynBusAttachment*)busAttachment {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusObject> unmarshalledReturn;
    auto _comInst = WDAIAllJoynBusObjectFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithBusAttachment(nsStrToHstr(objectPath).Get(),
                                          _getRtInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment>(busAttachment).Get(),
                                          unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDAAllJoynBusObject>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynBusObject").Get(), &out));
    return [_createRtProxy<WDAAllJoynBusObject>(out.Get()) retain];
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusObject>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusObject>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)addProducer:(RTObject<WDAIAllJoynProducer>*)producer {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusObject>(self);
    THROW_NS_IF_FAILED(_comInst->AddProducer(_getRtInterface<ABI::Windows::Devices::AllJoyn::IAllJoynProducer>(producer).Get()));
}

- (WDAAllJoynBusAttachment*)busAttachment {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusObject>(self);
    THROW_NS_IF_FAILED(_comInst->get_BusAttachment(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDAAllJoynBusAttachment>(unmarshalledReturn.Get());
}

- (WDAAllJoynSession*)session {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSession> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusObject>(self);
    THROW_NS_IF_FAILED(_comInst->get_Session(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDAAllJoynSession>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addStoppedEvent:(void (^)(WDAAllJoynBusObject*, WDAAllJoynBusObjectStoppedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusObject>(self);
    THROW_NS_IF_FAILED(_comInst->add_Stopped(
        Make<ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusObject_Windows_Devices_AllJoyn_AllJoynBusObjectStoppedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStoppedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusObject>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Stopped(token));
}

@end

@implementation WDAAllJoynBusObjectStoppedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusObjectStoppedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusObjectStoppedEventArgsFactory> WDAIAllJoynBusObjectStoppedEventArgsFactory_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusObjectStoppedEventArgsFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynBusObjectStoppedEventArgs").Get(), &inst));
    return inst;
}

+ (WDAAllJoynBusObjectStoppedEventArgs*)make:(int)status {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusObjectStoppedEventArgs> unmarshalledReturn;
    auto _comInst = WDAIAllJoynBusObjectStoppedEventArgsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(status, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDAAllJoynBusObjectStoppedEventArgs>(unmarshalledReturn.Get()) retain];
}

- (int)status {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynBusObjectStoppedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDAAllJoynProducerStoppedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynProducerStoppedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynProducerStoppedEventArgsFactory> WDAIAllJoynProducerStoppedEventArgsFactory_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynProducerStoppedEventArgsFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynProducerStoppedEventArgs").Get(), &inst));
    return inst;
}

+ (WDAAllJoynProducerStoppedEventArgs*)make:(int)status {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynProducerStoppedEventArgs> unmarshalledReturn;
    auto _comInst = WDAIAllJoynProducerStoppedEventArgsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(status, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDAAllJoynProducerStoppedEventArgs>(unmarshalledReturn.Get()) retain];
}

- (int)status {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynProducerStoppedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDAAllJoynWatcherStoppedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynWatcherStoppedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynWatcherStoppedEventArgsFactory> WDAIAllJoynWatcherStoppedEventArgsFactory_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynWatcherStoppedEventArgsFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynWatcherStoppedEventArgs").Get(), &inst));
    return inst;
}

+ (WDAAllJoynWatcherStoppedEventArgs*)make:(int)status {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynWatcherStoppedEventArgs> unmarshalledReturn;
    auto _comInst = WDAIAllJoynWatcherStoppedEventArgsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(status, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDAAllJoynWatcherStoppedEventArgs>(unmarshalledReturn.Get()) retain];
}

- (int)status {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynWatcherStoppedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDAAllJoynServiceInfoRemovedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfoRemovedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfoRemovedEventArgsFactory>
WDAIAllJoynServiceInfoRemovedEventArgsFactory_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfoRemovedEventArgsFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynServiceInfoRemovedEventArgs").Get(), &inst));
    return inst;
}

+ (WDAAllJoynServiceInfoRemovedEventArgs*)make:(NSString*)uniqueName {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfoRemovedEventArgs> unmarshalledReturn;
    auto _comInst = WDAIAllJoynServiceInfoRemovedEventArgsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(uniqueName).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDAAllJoynServiceInfoRemovedEventArgs>(unmarshalledReturn.Get()) retain];
}

- (NSString*)uniqueName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfoRemovedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_UniqueName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDAAllJoynMessageInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynMessageInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynMessageInfoFactory> WDAIAllJoynMessageInfoFactory_inst() {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynMessageInfoFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.AllJoyn.AllJoynMessageInfo").Get(), &inst));
    return inst;
}

+ (WDAAllJoynMessageInfo*)make:(NSString*)senderUniqueName {
    ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynMessageInfo> unmarshalledReturn;
    auto _comInst = WDAIAllJoynMessageInfoFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(senderUniqueName).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDAAllJoynMessageInfo>(unmarshalledReturn.Get()) retain];
}

- (NSString*)senderUniqueName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::AllJoyn::IAllJoynMessageInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SenderUniqueName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WGLanguage_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Globalization::Language*>,
                                                                             RTArrayObj<ABI::Windows::Globalization::ILanguage*,
                                                                                        IVectorView<ABI::Windows::Globalization::Language*>,
                                                                                        WGLanguage,
                                                                                        ABI::Windows::Globalization::Language*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSCCCertificate_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>,
                                         RTArrayObj<ABI::Windows::Security::Cryptography::Certificates::ICertificate*,
                                                    IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>,
                                                    WSCCCertificate,
                                                    ABI::Windows::Security::Cryptography::Certificates::Certificate*,
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

id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<
        DictionaryAdapterObj<IMapView<HSTRING, IInspectable*>,
                             DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, IInspectable*>>,
                             RTMapViewObj<HSTRING,
                                          HSTRING,
                                          IInspectable*,
                                          IInspectable*,
                                          NSString,
                                          RTObject,
                                          IMapView<HSTRING, IInspectable*>,
                                          dummyObjCCreator,
                                          dummyObjCCreator,
                                          dummyWRLCreator,
                                          dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WDAAllJoynAuthenticationMechanism_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism>,
                                                RTMutableArrayObj<ABI::Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism,
                                                                  IVector<ABI::Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism>,
                                                                  WDAAllJoynAuthenticationMechanism,
                                                                  ABI::Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
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
