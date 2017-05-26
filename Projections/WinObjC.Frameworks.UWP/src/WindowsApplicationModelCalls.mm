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

// WindowsApplicationModelCalls.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Calls.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelCalls.h"
#include "WindowsApplicationModelCalls_priv.h"

@implementation WACPhoneLine

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneLine> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneLineStatics> WACIPhoneLineStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneLineStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Calls.PhoneLine").Get(), &inst));
    return inst;
}

+ (void)fromIdAsync:(WFGUID*)lineId success:(void (^)(WACPhoneLine*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Calls::PhoneLine*>> unmarshalledReturn;
    auto _comInst = WACIPhoneLineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(lineId.guidValue, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Calls::PhoneLine*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Calls::PhoneLine*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneLine> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WACPhoneLine>(result.Get()));
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

- (EventRegistrationToken)addLineChangedEvent:(void (^)(WACPhoneLine*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_LineChanged(Make<ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLine_System_Object>(handler).Get(),
                                  &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLineChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LineChanged(token));
}

- (WFGUID*)id {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WUColor*)displayColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (WACPhoneNetworkState)networkState {
    ABI::Windows::ApplicationModel::Calls::PhoneNetworkState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkState(&unmarshalledReturn));
    return (WACPhoneNetworkState)unmarshalledReturn;
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WACPhoneVoicemail*)voicemail {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneVoicemail> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(_comInst->get_Voicemail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACPhoneVoicemail>(unmarshalledReturn.Get());
}

- (NSString*)networkName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WACPhoneLineCellularDetails*)cellularDetails {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneLineCellularDetails> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(_comInst->get_CellularDetails(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACPhoneLineCellularDetails>(unmarshalledReturn.Get());
}

- (WACPhoneLineTransport)transport {
    ABI::Windows::ApplicationModel::Calls::PhoneLineTransport unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(_comInst->get_Transport(&unmarshalledReturn));
    return (WACPhoneLineTransport)unmarshalledReturn;
}

- (BOOL)canDial {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanDial(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)supportsTile {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportsTile(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WACPhoneCallVideoCapabilities*)videoCallingCapabilities {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilities> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoCallingCapabilities(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACPhoneCallVideoCapabilities>(unmarshalledReturn.Get());
}

- (WACPhoneLineConfiguration*)lineConfiguration {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneLineConfiguration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineConfiguration(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACPhoneLineConfiguration>(unmarshalledReturn.Get());
}

- (void)isImmediateDialNumberAsync:(NSString*)number success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(_comInst->IsImmediateDialNumberAsync(nsStrToHstr(number).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

- (void)dial:(NSString*)number displayName:(NSString*)displayName {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(_comInst->Dial(nsStrToHstr(number).Get(), nsStrToHstr(displayName).Get()));
}

- (void)dialWithOptions:(WACPhoneDialOptions*)options {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLine>(self);
    THROW_NS_IF_FAILED(_comInst->DialWithOptions(_getRtInterface<ABI::Windows::ApplicationModel::Calls::IPhoneDialOptions>(options).Get()));
}

@end

@implementation WACPhoneVoicemail

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneVoicemail> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)number {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneVoicemail>(self);
    THROW_NS_IF_FAILED(_comInst->get_Number(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)messageCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneVoicemail>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WACPhoneVoicemailType)type {
    ABI::Windows::ApplicationModel::Calls::PhoneVoicemailType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneVoicemail>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WACPhoneVoicemailType)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)dialVoicemailAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneVoicemail>(self);
    THROW_NS_IF_FAILED(_comInst->DialVoicemailAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WACPhoneLineCellularDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneLineCellularDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACPhoneSimState)simState {
    ABI::Windows::ApplicationModel::Calls::PhoneSimState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineCellularDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_SimState(&unmarshalledReturn));
    return (WACPhoneSimState)unmarshalledReturn;
}

- (int)simSlotIndex {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineCellularDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_SimSlotIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isModemOn {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineCellularDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsModemOn(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)registrationRejectCode {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineCellularDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_RegistrationRejectCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)getNetworkOperatorDisplayText:(WACPhoneLineNetworkOperatorDisplayTextLocation)location {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineCellularDetails>(self);
    THROW_NS_IF_FAILED(_comInst->GetNetworkOperatorDisplayText(
        (ABI::Windows::ApplicationModel::Calls::PhoneLineNetworkOperatorDisplayTextLocation)location, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WACPhoneCallVideoCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isVideoCallingCapable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsVideoCallingCapable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WACPhoneLineConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneLineConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isVideoCallingEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsVideoCallingEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSDictionary* /* NSString *, RTObject* */)extendedProperties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WACPhoneDialOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneDialOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Calls.PhoneDialOptions").Get(), &out));
    return [_createRtProxy<WACPhoneDialOptions>(out.Get()) retain];
}

- (NSString*)number {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneDialOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Number(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNumber:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneDialOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_Number(nsStrToHstr(value).Get()));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneDialOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneDialOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (WACContact*)contact {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneDialOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contact(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContact>(unmarshalledReturn.Get());
}

- (void)setContact:(WACContact*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneDialOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_Contact(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(value).Get()));
}

- (WACContactPhone*)contactPhone {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactPhone> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneDialOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContactPhone(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactPhone>(unmarshalledReturn.Get());
}

- (void)setContactPhone:(WACContactPhone*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneDialOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContactPhone(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContactPhone>(value).Get()));
}

- (WACPhoneCallMedia)media {
    ABI::Windows::ApplicationModel::Calls::PhoneCallMedia unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneDialOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Media(&unmarshalledReturn));
    return (WACPhoneCallMedia)unmarshalledReturn;
}

- (void)setMedia:(WACPhoneCallMedia)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneDialOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_Media((ABI::Windows::ApplicationModel::Calls::PhoneCallMedia)value));
}

- (WACPhoneAudioRoutingEndpoint)audioEndpoint {
    ABI::Windows::ApplicationModel::Calls::PhoneAudioRoutingEndpoint unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneDialOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioEndpoint(&unmarshalledReturn));
    return (WACPhoneAudioRoutingEndpoint)unmarshalledReturn;
}

- (void)setAudioEndpoint:(WACPhoneAudioRoutingEndpoint)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneDialOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_AudioEndpoint((ABI::Windows::ApplicationModel::Calls::PhoneAudioRoutingEndpoint)value));
}

@end

@implementation WACPhoneLineWatcher

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (EventRegistrationToken)addLineAddedEvent:(void (^)(WACPhoneLineWatcher*, WACPhoneLineWatcherEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_LineAdded(
        Make<ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLineWatcher_Windows_ApplicationModel_Calls_PhoneLineWatcherEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLineAddedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LineAdded(token));
}

- (EventRegistrationToken)addLineRemovedEvent:(void (^)(WACPhoneLineWatcher*, WACPhoneLineWatcherEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_LineRemoved(
        Make<ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLineWatcher_Windows_ApplicationModel_Calls_PhoneLineWatcherEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLineRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LineRemoved(token));
}

- (EventRegistrationToken)addLineUpdatedEvent:(void (^)(WACPhoneLineWatcher*, WACPhoneLineWatcherEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_LineUpdated(
        Make<ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLineWatcher_Windows_ApplicationModel_Calls_PhoneLineWatcherEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLineUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LineUpdated(token));
}

- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WACPhoneLineWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_EnumerationCompleted(
        Make<ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLineWatcher_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_EnumerationCompleted(token));
}

- (EventRegistrationToken)addStoppedEvent:(void (^)(WACPhoneLineWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Stopped(Make<ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLineWatcher_System_Object>(handler).Get(),
                              &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStoppedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Stopped(token));
}

- (WACPhoneLineWatcherStatus)status {
    ABI::Windows::ApplicationModel::Calls::PhoneLineWatcherStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WACPhoneLineWatcherStatus)unmarshalledReturn;
}

@end

@implementation WACPhoneLineWatcherEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcherEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)lineId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcherEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WACPhoneCallStore

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallStore> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)isEmergencyPhoneNumberAsync:(NSString*)number success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallStore>(self);
    THROW_NS_IF_FAILED(_comInst->IsEmergencyPhoneNumberAsync(nsStrToHstr(number).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

- (void)getDefaultLineAsyncWithSuccess:(void (^)(WFGUID*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<GUID>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetDefaultLineAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<GUID>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<GUID>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        GUID result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(_makeObjcFrom<GUID>(result));
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

- (WACPhoneLineWatcher*)requestLineWatcher {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallStore>(self);
    THROW_NS_IF_FAILED(_comInst->RequestLineWatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACPhoneLineWatcher>(unmarshalledReturn.Get());
}

@end

@implementation WACPhoneCallManager

ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallManagerStatics2> WACIPhoneCallManagerStatics2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallManagerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Calls.PhoneCallManager").Get(),
                                                       &inst));
    return inst;
}

+ (EventRegistrationToken)addCallStateChangedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WACIPhoneCallManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->add_CallStateChanged(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeCallStateChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WACIPhoneCallManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->remove_CallStateChanged(token));
}

+ (BOOL)isCallActive {
    boolean unmarshalledReturn;
    auto _comInst = WACIPhoneCallManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsCallActive(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isCallIncoming {
    boolean unmarshalledReturn;
    auto _comInst = WACIPhoneCallManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsCallIncoming(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)showPhoneCallSettingsUI {
    auto _comInst = WACIPhoneCallManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->ShowPhoneCallSettingsUI());
}

+ (void)requestStoreAsyncWithSuccess:(void (^)(WACPhoneCallStore*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Calls::PhoneCallStore*>> unmarshalledReturn;
    auto _comInst = WACIPhoneCallManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->RequestStoreAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Calls::PhoneCallStore*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Calls::PhoneCallStore*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallStore> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACPhoneCallStore>(result.Get()));
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

ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallManagerStatics> WACIPhoneCallManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Calls.PhoneCallManager").Get(),
                                                       &inst));
    return inst;
}

+ (void)showPhoneCallUI:(NSString*)phoneNumber displayName:(NSString*)displayName {
    auto _comInst = WACIPhoneCallManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowPhoneCallUI(nsStrToHstr(phoneNumber).Get(), nsStrToHstr(displayName).Get()));
}

@end

@implementation WACPhoneCallVideoCapabilitiesManager

ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilitiesManagerStatics>
WACIPhoneCallVideoCapabilitiesManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilitiesManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Calls.PhoneCallVideoCapabilitiesManager").Get(), &inst));
    return inst;
}

+ (void)getCapabilitiesAsync:(NSString*)phoneNumber
                     success:(void (^)(WACPhoneCallVideoCapabilities*))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Calls::PhoneCallVideoCapabilities*>>
        unmarshalledReturn;
    auto _comInst = WACIPhoneCallVideoCapabilitiesManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetCapabilitiesAsync(nsStrToHstr(phoneNumber).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Calls::PhoneCallVideoCapabilities*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Calls::PhoneCallVideoCapabilities*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilities> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACPhoneCallVideoCapabilities>(result.Get()));
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

@implementation WACPhoneCallBlocking

ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallBlockingStatics> WACIPhoneCallBlockingStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallBlockingStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Calls.PhoneCallBlocking").Get(),
                                                       &inst));
    return inst;
}

+ (BOOL)blockUnknownNumbers {
    boolean unmarshalledReturn;
    auto _comInst = WACIPhoneCallBlockingStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BlockUnknownNumbers(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setBlockUnknownNumbers:(BOOL)value {
    auto _comInst = WACIPhoneCallBlockingStatics_inst();
    THROW_NS_IF_FAILED(_comInst->put_BlockUnknownNumbers((boolean)value));
}

+ (BOOL)blockPrivateNumbers {
    boolean unmarshalledReturn;
    auto _comInst = WACIPhoneCallBlockingStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BlockPrivateNumbers(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setBlockPrivateNumbers:(BOOL)value {
    auto _comInst = WACIPhoneCallBlockingStatics_inst();
    THROW_NS_IF_FAILED(_comInst->put_BlockPrivateNumbers((boolean)value));
}

+ (void)setCallBlockingListAsync:(id<NSFastEnumeration> /* NSString * */)phoneNumberList
                         success:(void (^)(BOOL))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WACIPhoneCallBlockingStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetCallBlockingListAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(phoneNumberList).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

@implementation WACCallStateChangeEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::ICallStateChangeEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACVoipPhoneCallState)state {
    ABI::Windows::ApplicationModel::Calls::VoipPhoneCallState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::ICallStateChangeEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WACVoipPhoneCallState)unmarshalledReturn;
}

@end

@implementation WACCallAnswerEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::ICallAnswerEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACVoipPhoneCallMedia)acceptedMedia {
    ABI::Windows::ApplicationModel::Calls::VoipPhoneCallMedia unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::ICallAnswerEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AcceptedMedia(&unmarshalledReturn));
    return (WACVoipPhoneCallMedia)unmarshalledReturn;
}

@end

@implementation WACCallRejectEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::ICallRejectEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACVoipPhoneCallRejectReason)rejectReason {
    ABI::Windows::ApplicationModel::Calls::VoipPhoneCallRejectReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::ICallRejectEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RejectReason(&unmarshalledReturn));
    return (WACVoipPhoneCallRejectReason)unmarshalledReturn;
}

@end

@implementation WACVoipPhoneCall

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addEndRequestedEvent:(void (^)(WACVoipPhoneCall*, WACCallStateChangeEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->add_EndRequested(
        Make<ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallStateChangeEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeEndRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->remove_EndRequested(token));
}

- (EventRegistrationToken)addHoldRequestedEvent:(void (^)(WACVoipPhoneCall*, WACCallStateChangeEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->add_HoldRequested(
        Make<ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallStateChangeEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHoldRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HoldRequested(token));
}

- (EventRegistrationToken)addResumeRequestedEvent:(void (^)(WACVoipPhoneCall*, WACCallStateChangeEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->add_ResumeRequested(
        Make<ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallStateChangeEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeResumeRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ResumeRequested(token));
}

- (EventRegistrationToken)addAnswerRequestedEvent:(void (^)(WACVoipPhoneCall*, WACCallAnswerEventArgs*))acceptHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->add_AnswerRequested(
        Make<ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallAnswerEventArgs>(
            acceptHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAnswerRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AnswerRequested(token));
}

- (EventRegistrationToken)addRejectRequestedEvent:(void (^)(WACVoipPhoneCall*, WACCallRejectEventArgs*))rejectHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->add_RejectRequested(
        Make<ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallRejectEventArgs>(
            rejectHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRejectRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RejectRequested(token));
}

- (void)notifyCallHeld {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyCallHeld());
}

- (void)notifyCallActive {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyCallActive());
}

- (void)notifyCallEnded {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyCallEnded());
}

- (NSString*)contactName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContactName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setContactName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContactName(nsStrToHstr(value).Get()));
}

- (WFDateTime*)startTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setStartTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartTime(*[value internalStruct]));
}

- (WACVoipPhoneCallMedia)callMedia {
    ABI::Windows::ApplicationModel::Calls::VoipPhoneCallMedia unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallMedia(&unmarshalledReturn));
    return (WACVoipPhoneCallMedia)unmarshalledReturn;
}

- (void)setCallMedia:(WACVoipPhoneCallMedia)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->put_CallMedia((ABI::Windows::ApplicationModel::Calls::VoipPhoneCallMedia)value));
}

- (void)notifyCallReady {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyCallReady());
}

@end

@implementation WACMuteChangeEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IMuteChangeEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)muted {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IMuteChangeEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Muted(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WACVoipCallCoordinator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinatorStatics> WACIVoipCallCoordinatorStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinatorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Calls.VoipCallCoordinator").Get(),
                                                       &inst));
    return inst;
}

+ (WACVoipCallCoordinator*)getDefault {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator> unmarshalledReturn;
    auto _comInst = WACIVoipCallCoordinatorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACVoipCallCoordinator>(unmarshalledReturn.Get());
}

- (void)reserveCallResourcesAsync:(NSString*)taskEntryPoint
                          success:(void (^)(WACVoipPhoneCallResourceReservationStatus))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator>(self);
    THROW_NS_IF_FAILED(_comInst->ReserveCallResourcesAsync(nsStrToHstr(taskEntryPoint).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WACVoipPhoneCallResourceReservationStatus)result);
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

- (EventRegistrationToken)addMuteStateChangedEvent:(void (^)(WACVoipCallCoordinator*, WACMuteChangeEventArgs*))muteChangeHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator>(self);
    THROW_NS_IF_FAILED(_comInst->add_MuteStateChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_Calls_VoipCallCoordinator_Windows_ApplicationModel_Calls_MuteChangeEventArgs>(
            muteChangeHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMuteStateChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MuteStateChanged(token));
}

- (WACVoipPhoneCall*)requestNewIncomingCall:(NSString*)context
                                contactName:(NSString*)contactName
                              contactNumber:(NSString*)contactNumber
                               contactImage:(WFUri*)contactImage
                                serviceName:(NSString*)serviceName
                              brandingImage:(WFUri*)brandingImage
                                callDetails:(NSString*)callDetails
                                   ringtone:(WFUri*)ringtone
                                      media:(WACVoipPhoneCallMedia)media
                                ringTimeout:(WFTimeSpan*)ringTimeout {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator>(self);
    THROW_NS_IF_FAILED(_comInst->RequestNewIncomingCall(nsStrToHstr(context).Get(),
                                                        nsStrToHstr(contactName).Get(),
                                                        nsStrToHstr(contactNumber).Get(),
                                                        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(contactImage).Get(),
                                                        nsStrToHstr(serviceName).Get(),
                                                        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(brandingImage).Get(),
                                                        nsStrToHstr(callDetails).Get(),
                                                        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(ringtone).Get(),
                                                        (ABI::Windows::ApplicationModel::Calls::VoipPhoneCallMedia)media,
                                                        *[ringTimeout internalStruct],
                                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACVoipPhoneCall>(unmarshalledReturn.Get());
}

- (WACVoipPhoneCall*)requestNewOutgoingCall:(NSString*)context
                                contactName:(NSString*)contactName
                                serviceName:(NSString*)serviceName
                                      media:(WACVoipPhoneCallMedia)media {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator>(self);
    THROW_NS_IF_FAILED(_comInst->RequestNewOutgoingCall(nsStrToHstr(context).Get(),
                                                        nsStrToHstr(contactName).Get(),
                                                        nsStrToHstr(serviceName).Get(),
                                                        (ABI::Windows::ApplicationModel::Calls::VoipPhoneCallMedia)media,
                                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACVoipPhoneCall>(unmarshalledReturn.Get());
}

- (void)notifyMuted {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyMuted());
}

- (void)notifyUnmuted {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyUnmuted());
}

- (WACVoipPhoneCall*)requestOutgoingUpgradeToVideoCall:(WFGUID*)callUpgradeGuid
                                               context:(NSString*)context
                                           contactName:(NSString*)contactName
                                           serviceName:(NSString*)serviceName {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator>(self);
    THROW_NS_IF_FAILED(_comInst->RequestOutgoingUpgradeToVideoCall(callUpgradeGuid.guidValue,
                                                                   nsStrToHstr(context).Get(),
                                                                   nsStrToHstr(contactName).Get(),
                                                                   nsStrToHstr(serviceName).Get(),
                                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACVoipPhoneCall>(unmarshalledReturn.Get());
}

- (WACVoipPhoneCall*)requestIncomingUpgradeToVideoCall:(NSString*)context
                                           contactName:(NSString*)contactName
                                         contactNumber:(NSString*)contactNumber
                                          contactImage:(WFUri*)contactImage
                                           serviceName:(NSString*)serviceName
                                         brandingImage:(WFUri*)brandingImage
                                           callDetails:(NSString*)callDetails
                                              ringtone:(WFUri*)ringtone
                                           ringTimeout:(WFTimeSpan*)ringTimeout {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator>(self);
    THROW_NS_IF_FAILED(
        _comInst->RequestIncomingUpgradeToVideoCall(nsStrToHstr(context).Get(),
                                                    nsStrToHstr(contactName).Get(),
                                                    nsStrToHstr(contactNumber).Get(),
                                                    _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(contactImage).Get(),
                                                    nsStrToHstr(serviceName).Get(),
                                                    _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(brandingImage).Get(),
                                                    nsStrToHstr(callDetails).Get(),
                                                    _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(ringtone).Get(),
                                                    *[ringTimeout internalStruct],
                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACVoipPhoneCall>(unmarshalledReturn.Get());
}

- (void)terminateCellularCall:(WFGUID*)callUpgradeGuid {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator>(self);
    THROW_NS_IF_FAILED(_comInst->TerminateCellularCall(callUpgradeGuid.guidValue));
}

- (void)cancelUpgrade:(WFGUID*)callUpgradeGuid {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator>(self);
    THROW_NS_IF_FAILED(_comInst->CancelUpgrade(callUpgradeGuid.guidValue));
}

@end

@implementation WACLockScreenCallEndCallDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::ILockScreenCallEndCallDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::ILockScreenCallEndCallDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WACLockScreenCallUI

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::ILockScreenCallUI> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)dismiss {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::ILockScreenCallUI>(self);
    THROW_NS_IF_FAILED(_comInst->Dismiss());
}

- (EventRegistrationToken)addEndRequestedEvent:(void (^)(WACLockScreenCallUI*, WACLockScreenCallEndRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::ILockScreenCallUI>(self);
    THROW_NS_IF_FAILED(_comInst->add_EndRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Calls_LockScreenCallUI_Windows_ApplicationModel_Calls_LockScreenCallEndRequestedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeEndRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::ILockScreenCallUI>(self);
    THROW_NS_IF_FAILED(_comInst->remove_EndRequested(token));
}

- (EventRegistrationToken)addClosedEvent:(void (^)(WACLockScreenCallUI*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::ILockScreenCallUI>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Closed(Make<ITypedEventHandler_Windows_ApplicationModel_Calls_LockScreenCallUI_System_Object>(handler).Get(),
                             &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::ILockScreenCallUI>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Closed(token));
}

- (NSString*)callTitle {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::ILockScreenCallUI>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallTitle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCallTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::ILockScreenCallUI>(self);
    THROW_NS_IF_FAILED(_comInst->put_CallTitle(nsStrToHstr(value).Get()));
}

@end

@implementation WACLockScreenCallEndRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACLockScreenCallEndCallDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::Calls::ILockScreenCallEndCallDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACLockScreenCallEndCallDeferral>(unmarshalledReturn.Get());
}

- (WFDateTime*)deadline {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Deadline(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

@end

@implementation WACPhoneCallHistoryEntryAddress

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory> WACIPhoneCallHistoryEntryAddressFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntryAddress").Get(), &inst));
    return inst;
}

+ (WACPhoneCallHistoryEntryAddress*)make:(NSString*)rawAddress rawAddressKind:(WACPhoneCallHistoryEntryRawAddressKind)rawAddressKind {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> unmarshalledReturn;
    auto _comInst = WACIPhoneCallHistoryEntryAddressFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(rawAddress).Get(),
                                        (ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind)rawAddressKind,
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WACPhoneCallHistoryEntryAddress>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntryAddress").Get(),
                                              &out));
    return [_createRtProxy<WACPhoneCallHistoryEntryAddress>(out.Get()) retain];
}

- (NSString*)contactId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContactId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setContactId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContactId(nsStrToHstr(value).Get()));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)rawAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRawAddress:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>(self);
    THROW_NS_IF_FAILED(_comInst->put_RawAddress(nsStrToHstr(value).Get()));
}

- (WACPhoneCallHistoryEntryRawAddressKind)rawAddressKind {
    ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawAddressKind(&unmarshalledReturn));
    return (WACPhoneCallHistoryEntryRawAddressKind)unmarshalledReturn;
}

- (void)setRawAddressKind:(WACPhoneCallHistoryEntryRawAddressKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>(self);
    THROW_NS_IF_FAILED(_comInst->put_RawAddressKind((ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind)value));
}

@end

@implementation WACPhoneCallHistoryEntry

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntry").Get(), &out));
    return [_createRtProxy<WACPhoneCallHistoryEntry>(out.Get()) retain];
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WACPhoneCallHistoryEntryAddress*)address {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Address(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACPhoneCallHistoryEntryAddress>(unmarshalledReturn.Get());
}

- (void)setAddress:(WACPhoneCallHistoryEntryAddress*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Address(_getRtInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>(value).Get()));
}

- (id /* WFTimeSpan* */)duration {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setDuration:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->put_Duration(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (BOOL)isCallerIdBlocked {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCallerIdBlocked(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsCallerIdBlocked:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsCallerIdBlocked((boolean)value));
}

- (BOOL)isEmergency {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEmergency(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsEmergency:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsEmergency((boolean)value));
}

- (BOOL)isIncoming {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsIncoming(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsIncoming:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsIncoming((boolean)value));
}

- (BOOL)isMissed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsMissed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsMissed:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsMissed((boolean)value));
}

- (BOOL)isRinging {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsRinging(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsRinging:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsRinging((boolean)value));
}

- (BOOL)isSeen {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSeen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsSeen:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsSeen((boolean)value));
}

- (BOOL)isSuppressed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSuppressed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsSuppressed:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsSuppressed((boolean)value));
}

- (BOOL)isVoicemail {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsVoicemail(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsVoicemail:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsVoicemail((boolean)value));
}

- (WACPhoneCallHistoryEntryMedia)media {
    ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Media(&unmarshalledReturn));
    return (WACPhoneCallHistoryEntryMedia)unmarshalledReturn;
}

- (void)setMedia:(WACPhoneCallHistoryEntryMedia)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->put_Media((ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryMedia)value));
}

- (WACPhoneCallHistoryEntryOtherAppReadAccess)otherAppReadAccess {
    ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_OtherAppReadAccess(&unmarshalledReturn));
    return (WACPhoneCallHistoryEntryOtherAppReadAccess)unmarshalledReturn;
}

- (void)setOtherAppReadAccess:(WACPhoneCallHistoryEntryOtherAppReadAccess)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_OtherAppReadAccess((ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess)value));
}

- (NSString*)remoteId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRemoteId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteId(nsStrToHstr(value).Get()));
}

- (NSString*)sourceDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)sourceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSourceId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->put_SourceId(nsStrToHstr(value).Get()));
}

- (WACPhoneCallHistorySourceIdKind)sourceIdKind {
    ABI::Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceIdKind(&unmarshalledReturn));
    return (WACPhoneCallHistorySourceIdKind)unmarshalledReturn;
}

- (void)setSourceIdKind:(WACPhoneCallHistorySourceIdKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->put_SourceIdKind((ABI::Windows::ApplicationModel::Calls::PhoneCallHistorySourceIdKind)value));
}

- (WFDateTime*)startTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setStartTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartTime(*[value internalStruct]));
}

@end

@implementation WACPhoneCallHistoryEntryReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)readBatchAsyncWithSuccess:(void (^)(NSArray* /* WACPhoneCallHistoryEntry* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBatchAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACPhoneCallHistoryEntry_create(result.Get()));
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

@implementation WACPhoneCallHistoryEntryQueryOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntryQueryOptions").Get(), &out));
    return [_createRtProxy<WACPhoneCallHistoryEntryQueryOptions>(out.Get()) retain];
}

- (WACPhoneCallHistoryEntryQueryDesiredMedia)desiredMedia {
    ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredMedia(&unmarshalledReturn));
    return (WACPhoneCallHistoryEntryQueryDesiredMedia)unmarshalledReturn;
}

- (void)setDesiredMedia:(WACPhoneCallHistoryEntryQueryDesiredMedia)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredMedia((ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia)value));
}

- (NSMutableArray* /* NSString * */)sourceIds {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceIds(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WACPhoneCallHistoryStore

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getEntryAsync:(NSString*)callHistoryEntryId
              success:(void (^)(WACPhoneCallHistoryEntry*))success
              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetEntryAsync(nsStrToHstr(callHistoryEntryId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACPhoneCallHistoryEntry>(result.Get()));
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

- (WACPhoneCallHistoryEntryReader*)getEntryReader {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetEntryReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACPhoneCallHistoryEntryReader>(unmarshalledReturn.Get());
}

- (WACPhoneCallHistoryEntryReader*)getEntryReaderWithOptions:(WACPhoneCallHistoryEntryQueryOptions*)queryOptions {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetEntryReaderWithOptions(
        _getRtInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions>(queryOptions).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACPhoneCallHistoryEntryReader>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)saveEntryAsync:(WACPhoneCallHistoryEntry*)callHistoryEntry {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>(self);
    THROW_NS_IF_FAILED(
        _comInst->SaveEntryAsync(_getRtInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(callHistoryEntry).Get(),
                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteEntryAsync:(WACPhoneCallHistoryEntry*)callHistoryEntry {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>(self);
    THROW_NS_IF_FAILED(
        _comInst->DeleteEntryAsync(_getRtInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(callHistoryEntry).Get(),
                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteEntriesAsync:(id<NSFastEnumeration> /* WACPhoneCallHistoryEntry* */)callHistoryEntries {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteEntriesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*,
                                                              ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry*>>::type>*>(
            ConvertToIterable<
                WACPhoneCallHistoryEntry,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*,
                                                                  ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry*>>(
                callHistoryEntries)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)markEntryAsSeenAsync:(WACPhoneCallHistoryEntry*)callHistoryEntry {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>(self);
    THROW_NS_IF_FAILED(_comInst->MarkEntryAsSeenAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry>(callHistoryEntry).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)markEntriesAsSeenAsync:(id<NSFastEnumeration> /* WACPhoneCallHistoryEntry* */)callHistoryEntries {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>(self);
    THROW_NS_IF_FAILED(_comInst->MarkEntriesAsSeenAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*,
                                                              ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry*>>::type>*>(
            ConvertToIterable<
                WACPhoneCallHistoryEntry,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*,
                                                                  ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry*>>(
                callHistoryEntries)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)getUnseenCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetUnseenCountAsync(&unmarshalledReturn));

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

- (RTObject<WFIAsyncAction>*)markAllAsSeenAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>(self);
    THROW_NS_IF_FAILED(_comInst->MarkAllAsSeenAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)getSourcesUnseenCountAsync:(id<NSFastEnumeration> /* NSString * */)sourceIds
                           success:(void (^)(unsigned int))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetSourcesUnseenCountAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(sourceIds).Get()),
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

- (RTObject<WFIAsyncAction>*)markSourcesAsSeenAsync:(id<NSFastEnumeration> /* NSString * */)sourceIds {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore>(self);
    THROW_NS_IF_FAILED(_comInst->MarkSourcesAsSeenAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(sourceIds).Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WACPhoneCallHistoryManagerForUser

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)requestStoreAsync:(WACPhoneCallHistoryStoreAccessType)accessType
                  success:(void (^)(WACPhoneCallHistoryStore*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryStore*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->RequestStoreAsync((ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType)accessType,
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryStore*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryStore*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACPhoneCallHistoryStore>(result.Get()));
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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WACPhoneCallHistoryManager

ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics> WACIPhoneCallHistoryManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Calls.PhoneCallHistoryManager").Get(), &inst));
    return inst;
}

+ (void)requestStoreAsync:(WACPhoneCallHistoryStoreAccessType)accessType
                  success:(void (^)(WACPhoneCallHistoryStore*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryStore*>> unmarshalledReturn;
    auto _comInst = WACIPhoneCallHistoryManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestStoreAsync((ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType)accessType,
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryStore*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryStore*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryStore> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACPhoneCallHistoryStore>(result.Get()));
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

ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2> WACIPhoneCallHistoryManagerStatics2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Calls.PhoneCallHistoryManager").Get(), &inst));
    return inst;
}

+ (WACPhoneCallHistoryManagerForUser*)getForUser:(WSUser*)user {
    ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser> unmarshalledReturn;
    auto _comInst = WACIPhoneCallHistoryManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetForUser(_getRtInterface<ABI::Windows::System::IUser>(user).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACPhoneCallHistoryManagerForUser>(unmarshalledReturn.Get());
}

@end

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WACPhoneCallHistoryEntry_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*>,
                                                 RTIterableObj<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry*,
                                                               IIterable<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*>,
                                                               WACPhoneCallHistoryEntry,
                                                               ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WACPhoneCallHistoryEntry_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntry*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*>,
                                                    WACPhoneCallHistoryEntry,
                                                    ABI::Windows::ApplicationModel::Calls::PhoneCallHistoryEntry*,
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
