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

// WindowsApplicationModelUserDataAccountsSystemAccess.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.UserDataAccounts.SystemAccess.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelUserDataAccountsSystemAccess.h"
#include "WindowsApplicationModelUserDataAccountsSystemAccess_priv.h"

@implementation WAUSDeviceAccountConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.UserDataAccounts.SystemAccess.DeviceAccountConfiguration").Get(), &out));
    return [_createRtProxy<WAUSDeviceAccountConfiguration>(out.Get()) retain];
}

- (NSString*)accountName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccountName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAccountName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_AccountName(nsStrToHstr(value).Get()));
}

- (NSString*)deviceAccountTypeId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceAccountTypeId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDeviceAccountTypeId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_DeviceAccountTypeId(nsStrToHstr(value).Get()));
}

- (WAUSDeviceAccountServerType)serverType {
    ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountServerType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerType(&unmarshalledReturn));
    return (WAUSDeviceAccountServerType)unmarshalledReturn;
}

- (void)setServerType:(WAUSDeviceAccountServerType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ServerType((ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountServerType)value));
}

- (NSString*)emailAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setEmailAddress:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_EmailAddress(nsStrToHstr(value).Get()));
}

- (NSString*)domain {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Domain(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDomain:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_Domain(nsStrToHstr(value).Get()));
}

- (BOOL)emailSyncEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailSyncEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEmailSyncEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_EmailSyncEnabled((boolean)value));
}

- (BOOL)contactsSyncEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContactsSyncEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setContactsSyncEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContactsSyncEnabled((boolean)value));
}

- (BOOL)calendarSyncEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_CalendarSyncEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCalendarSyncEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_CalendarSyncEnabled((boolean)value));
}

- (NSString*)incomingServerAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncomingServerAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setIncomingServerAddress:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_IncomingServerAddress(nsStrToHstr(value).Get()));
}

- (int)incomingServerPort {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncomingServerPort(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIncomingServerPort:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_IncomingServerPort(value));
}

- (BOOL)incomingServerRequiresSsl {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncomingServerRequiresSsl(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIncomingServerRequiresSsl:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_IncomingServerRequiresSsl((boolean)value));
}

- (NSString*)incomingServerUsername {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncomingServerUsername(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setIncomingServerUsername:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_IncomingServerUsername(nsStrToHstr(value).Get()));
}

- (NSString*)outgoingServerAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingServerAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setOutgoingServerAddress:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutgoingServerAddress(nsStrToHstr(value).Get()));
}

- (int)outgoingServerPort {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingServerPort(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOutgoingServerPort:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutgoingServerPort(value));
}

- (BOOL)outgoingServerRequiresSsl {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingServerRequiresSsl(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setOutgoingServerRequiresSsl:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutgoingServerRequiresSsl((boolean)value));
}

- (NSString*)outgoingServerUsername {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingServerUsername(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setOutgoingServerUsername:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutgoingServerUsername(nsStrToHstr(value).Get()));
}

- (WSCPasswordCredential*)incomingServerCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncomingServerCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setIncomingServerCredential:(WSCPasswordCredential*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_IncomingServerCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(value).Get()));
}

- (WSCPasswordCredential*)outgoingServerCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingServerCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setOutgoingServerCredential:(WSCPasswordCredential*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_OutgoingServerCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(value).Get()));
}

- (NSString*)oAuthRefreshToken {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_OAuthRefreshToken(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setOAuthRefreshToken:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_OAuthRefreshToken(nsStrToHstr(value).Get()));
}

- (BOOL)isExternallyManaged {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsExternallyManaged(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsExternallyManaged:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsExternallyManaged((boolean)value));
}

- (WAUSDeviceAccountIconId)accountIconId {
    ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountIconId unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccountIconId(&unmarshalledReturn));
    return (WAUSDeviceAccountIconId)unmarshalledReturn;
}

- (void)setAccountIconId:(WAUSDeviceAccountIconId)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_AccountIconId((ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountIconId)value));
}

- (WAUSDeviceAccountAuthenticationType)authenticationType {
    ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountAuthenticationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AuthenticationType(&unmarshalledReturn));
    return (WAUSDeviceAccountAuthenticationType)unmarshalledReturn;
}

- (void)setAuthenticationType:(WAUSDeviceAccountAuthenticationType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AuthenticationType(
        (ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountAuthenticationType)value));
}

- (BOOL)isSsoAuthenticationSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSsoAuthenticationSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)ssoAccountId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SsoAccountId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSsoAccountId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_SsoAccountId(nsStrToHstr(value).Get()));
}

- (BOOL)alwaysDownloadFullMessage {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlwaysDownloadFullMessage(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAlwaysDownloadFullMessage:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AlwaysDownloadFullMessage((boolean)value));
}

- (BOOL)doesPolicyAllowMailSync {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DoesPolicyAllowMailSync(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WAUSDeviceAccountSyncScheduleKind)syncScheduleKind {
    ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SyncScheduleKind(&unmarshalledReturn));
    return (WAUSDeviceAccountSyncScheduleKind)unmarshalledReturn;
}

- (void)setSyncScheduleKind:(WAUSDeviceAccountSyncScheduleKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_SyncScheduleKind(
        (ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind)value));
}

- (WAUSDeviceAccountMailAgeFilter)mailAgeFilter {
    ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountMailAgeFilter unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MailAgeFilter(&unmarshalledReturn));
    return (WAUSDeviceAccountMailAgeFilter)unmarshalledReturn;
}

- (void)setMailAgeFilter:(WAUSDeviceAccountMailAgeFilter)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_MailAgeFilter((ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountMailAgeFilter)value));
}

- (BOOL)isClientAuthenticationCertificateRequired {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsClientAuthenticationCertificateRequired(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsClientAuthenticationCertificateRequired:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsClientAuthenticationCertificateRequired((boolean)value));
}

- (BOOL)autoSelectAuthenticationCertificate {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoSelectAuthenticationCertificate(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAutoSelectAuthenticationCertificate:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoSelectAuthenticationCertificate((boolean)value));
}

- (NSString*)authenticationCertificateId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AuthenticationCertificateId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAuthenticationCertificateId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AuthenticationCertificateId(nsStrToHstr(value).Get()));
}

- (WAUSDeviceAccountSyncScheduleKind)cardDavSyncScheduleKind {
    ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CardDavSyncScheduleKind(&unmarshalledReturn));
    return (WAUSDeviceAccountSyncScheduleKind)unmarshalledReturn;
}

- (void)setCardDavSyncScheduleKind:(WAUSDeviceAccountSyncScheduleKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CardDavSyncScheduleKind(
        (ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind)value));
}

- (WAUSDeviceAccountSyncScheduleKind)calDavSyncScheduleKind {
    ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CalDavSyncScheduleKind(&unmarshalledReturn));
    return (WAUSDeviceAccountSyncScheduleKind)unmarshalledReturn;
}

- (void)setCalDavSyncScheduleKind:(WAUSDeviceAccountSyncScheduleKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CalDavSyncScheduleKind(
        (ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind)value));
}

- (WFUri*)cardDavServerUrl {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CardDavServerUrl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setCardDavServerUrl:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CardDavServerUrl(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (BOOL)cardDavRequiresSsl {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CardDavRequiresSsl(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCardDavRequiresSsl:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CardDavRequiresSsl((boolean)value));
}

- (WFUri*)calDavServerUrl {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CalDavServerUrl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setCalDavServerUrl:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CalDavServerUrl(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (BOOL)calDavRequiresSsl {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CalDavRequiresSsl(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCalDavRequiresSsl:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CalDavRequiresSsl((boolean)value));
}

- (BOOL)wasModifiedByUser {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_WasModifiedByUser(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setWasModifiedByUser:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_WasModifiedByUser((boolean)value));
}

- (BOOL)wasIncomingServerCertificateHashConfirmed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_WasIncomingServerCertificateHashConfirmed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setWasIncomingServerCertificateHashConfirmed:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_WasIncomingServerCertificateHashConfirmed((boolean)value));
}

- (NSString*)incomingServerCertificateHash {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncomingServerCertificateHash(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setIncomingServerCertificateHash:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IncomingServerCertificateHash(nsStrToHstr(value).Get()));
}

- (BOOL)isOutgoingServerAuthenticationRequired {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOutgoingServerAuthenticationRequired(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsOutgoingServerAuthenticationRequired:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsOutgoingServerAuthenticationRequired((boolean)value));
}

- (BOOL)isOutgoingServerAuthenticationEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOutgoingServerAuthenticationEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsOutgoingServerAuthenticationEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsOutgoingServerAuthenticationEnabled((boolean)value));
}

- (BOOL)wasOutgoingServerCertificateHashConfirmed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_WasOutgoingServerCertificateHashConfirmed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setWasOutgoingServerCertificateHashConfirmed:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_WasOutgoingServerCertificateHashConfirmed((boolean)value));
}

- (NSString*)outgoingServerCertificateHash {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingServerCertificateHash(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setOutgoingServerCertificateHash:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutgoingServerCertificateHash(nsStrToHstr(value).Get()));
}

- (BOOL)isSyncScheduleManagedBySystem {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSyncScheduleManagedBySystem(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsSyncScheduleManagedBySystem:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsSyncScheduleManagedBySystem((boolean)value));
}

@end

@implementation WAUSUserDataAccountSystemAccessManager

ComPtr<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics2>
WAUSIUserDataAccountSystemAccessManagerStatics2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.UserDataAccounts.SystemAccess.UserDataAccountSystemAccessManager").Get(), &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)suppressLocalAccountWithAccountAsync:(NSString*)userDataAccountId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WAUSIUserDataAccountSystemAccessManagerStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->SuppressLocalAccountWithAccountAsync(nsStrToHstr(userDataAccountId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)createDeviceAccountAsync:(WAUSDeviceAccountConfiguration*)account
                         success:(void (^)(NSString*))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WAUSIUserDataAccountSystemAccessManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->CreateDeviceAccountAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>(account).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

+ (RTObject<WFIAsyncAction>*)deleteDeviceAccountAsync:(NSString*)accountId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WAUSIUserDataAccountSystemAccessManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->DeleteDeviceAccountAsync(nsStrToHstr(accountId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)getDeviceAccountConfigurationAsync:(NSString*)accountId
                                   success:(void (^)(WAUSDeviceAccountConfiguration*))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration*>>
        unmarshalledReturn;
    auto _comInst = WAUSIUserDataAccountSystemAccessManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceAccountConfigurationAsync(nsStrToHstr(accountId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAUSDeviceAccountConfiguration>(result.Get()));
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

ComPtr<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics>
WAUSIUserDataAccountSystemAccessManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.UserDataAccounts.SystemAccess.UserDataAccountSystemAccessManager").Get(), &inst));
    return inst;
}

+ (void)addAndShowDeviceAccountsAsync:(id<NSFastEnumeration> /* WAUSDeviceAccountConfiguration* */)accounts
                              success:(void (^)(NSArray* /* NSString * */))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<HSTRING>*>> unmarshalledReturn;
    auto _comInst = WAUSIUserDataAccountSystemAccessManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AddAndShowDeviceAccountsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration*,
            ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration*>>::type>*>(
            ConvertToIterable<WAUSDeviceAccountConfiguration,
                              ABI::Windows::Foundation::Internal::AggregateType<
                                  ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration*,
                                  ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration*>>(accounts)
                .Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<HSTRING>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<HSTRING>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<HSTRING>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_NSString_create(result.Get()));
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

id RTProxiedIterableNSArray_WAUSDeviceAccountConfiguration_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<IterableArrayAdapterObj<
        IIterable<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration*>,
        RTIterableObj<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration*,
                      IIterable<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration*>,
                      WAUSDeviceAccountConfiguration,
                      ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration*,
                      dummyObjCCreator,
                      dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
