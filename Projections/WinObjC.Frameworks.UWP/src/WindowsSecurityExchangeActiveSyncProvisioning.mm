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

// WindowsSecurityExchangeActiveSyncProvisioning.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Security.ExchangeActiveSyncProvisioning.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSecurityExchangeActiveSyncProvisioning.h"
#include "WindowsSecurityExchangeActiveSyncProvisioning_priv.h"

@implementation WSEEasClientDeviceInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Security.ExchangeActiveSyncProvisioning.EasClientDeviceInformation").Get(), &out));
    return [_createRtProxy<WSEEasClientDeviceInformation>(out.Get()) retain];
}

- (WFGUID*)id {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (NSString*)operatingSystem {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_OperatingSystem(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)friendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)systemManufacturer {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemManufacturer(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)systemProductName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemProductName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)systemSku {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemSku(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)systemHardwareVersion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemHardwareVersion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)systemFirmwareVersion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemFirmwareVersion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSEEasComplianceResults

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)compliant {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_Compliant(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WSEEasRequireEncryptionResult)requireEncryptionResult {
    ABI::Windows::Security::ExchangeActiveSyncProvisioning::EasRequireEncryptionResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequireEncryptionResult(&unmarshalledReturn));
    return (WSEEasRequireEncryptionResult)unmarshalledReturn;
}

- (WSEEasMinPasswordLengthResult)minPasswordLengthResult {
    ABI::Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordLengthResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinPasswordLengthResult(&unmarshalledReturn));
    return (WSEEasMinPasswordLengthResult)unmarshalledReturn;
}

- (WSEEasDisallowConvenienceLogonResult)disallowConvenienceLogonResult {
    ABI::Windows::Security::ExchangeActiveSyncProvisioning::EasDisallowConvenienceLogonResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisallowConvenienceLogonResult(&unmarshalledReturn));
    return (WSEEasDisallowConvenienceLogonResult)unmarshalledReturn;
}

- (WSEEasMinPasswordComplexCharactersResult)minPasswordComplexCharactersResult {
    ABI::Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordComplexCharactersResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinPasswordComplexCharactersResult(&unmarshalledReturn));
    return (WSEEasMinPasswordComplexCharactersResult)unmarshalledReturn;
}

- (WSEEasPasswordExpirationResult)passwordExpirationResult {
    ABI::Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordExpirationResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_PasswordExpirationResult(&unmarshalledReturn));
    return (WSEEasPasswordExpirationResult)unmarshalledReturn;
}

- (WSEEasPasswordHistoryResult)passwordHistoryResult {
    ABI::Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordHistoryResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_PasswordHistoryResult(&unmarshalledReturn));
    return (WSEEasPasswordHistoryResult)unmarshalledReturn;
}

- (WSEEasMaxPasswordFailedAttemptsResult)maxPasswordFailedAttemptsResult {
    ABI::Windows::Security::ExchangeActiveSyncProvisioning::EasMaxPasswordFailedAttemptsResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPasswordFailedAttemptsResult(&unmarshalledReturn));
    return (WSEEasMaxPasswordFailedAttemptsResult)unmarshalledReturn;
}

- (WSEEasMaxInactivityTimeLockResult)maxInactivityTimeLockResult {
    ABI::Windows::Security::ExchangeActiveSyncProvisioning::EasMaxInactivityTimeLockResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxInactivityTimeLockResult(&unmarshalledReturn));
    return (WSEEasMaxInactivityTimeLockResult)unmarshalledReturn;
}

- (WSEEasEncryptionProviderType)encryptionProviderType {
    ABI::Windows::Security::ExchangeActiveSyncProvisioning::EasEncryptionProviderType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncryptionProviderType(&unmarshalledReturn));
    return (WSEEasEncryptionProviderType)unmarshalledReturn;
}

@end

@implementation WSEEasClientSecurityPolicy

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Security.ExchangeActiveSyncProvisioning.EasClientSecurityPolicy").Get(), &out));
    return [_createRtProxy<WSEEasClientSecurityPolicy>(out.Get()) retain];
}

- (BOOL)requireEncryption {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequireEncryption(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setRequireEncryption:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->put_RequireEncryption((boolean)value));
}

- (uint8_t)minPasswordLength {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinPasswordLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMinPasswordLength:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->put_MinPasswordLength(value));
}

- (BOOL)disallowConvenienceLogon {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisallowConvenienceLogon(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setDisallowConvenienceLogon:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisallowConvenienceLogon((boolean)value));
}

- (uint8_t)minPasswordComplexCharacters {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinPasswordComplexCharacters(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMinPasswordComplexCharacters:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->put_MinPasswordComplexCharacters(value));
}

- (WFTimeSpan*)passwordExpiration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_PasswordExpiration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setPasswordExpiration:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->put_PasswordExpiration(*[value internalStruct]));
}

- (unsigned int)passwordHistory {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_PasswordHistory(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPasswordHistory:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->put_PasswordHistory(value));
}

- (uint8_t)maxPasswordFailedAttempts {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPasswordFailedAttempts(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMaxPasswordFailedAttempts:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxPasswordFailedAttempts(value));
}

- (WFTimeSpan*)maxInactivityTimeLock {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxInactivityTimeLock(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setMaxInactivityTimeLock:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxInactivityTimeLock(*[value internalStruct]));
}

- (WSEEasComplianceResults*)checkCompliance {
    ComPtr<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->CheckCompliance(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSEEasComplianceResults>(unmarshalledReturn.Get());
}

- (void)applyAsyncWithSuccess:(void (^)(WSEEasComplianceResults*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->ApplyAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSEEasComplianceResults>(result.Get()));
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
