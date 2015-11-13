//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsSecurityExchangeActiveSyncProvisioning.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSEEasComplianceResults, WSEEasClientSecurityPolicy, WSEEasClientDeviceInformation;
@protocol WSEIEasClientDeviceInformation
, WSEIEasClientSecurityPolicy, WSEIEasComplianceResults, WSEIEasComplianceResults2;

// Windows.Security.ExchangeActiveSyncProvisioning.EasRequireEncryptionResult
enum _WSEEasRequireEncryptionResult {
    WSEEasRequireEncryptionResultNotEvaluated = 0,
    WSEEasRequireEncryptionResultCompliant = 1,
    WSEEasRequireEncryptionResultCanBeCompliant = 2,
    WSEEasRequireEncryptionResultNotProvisionedOnAllVolumes = 3,
    WSEEasRequireEncryptionResultDeFixedDataNotSupported = 4,
    WSEEasRequireEncryptionResultFixedDataNotSupported = 4,
    WSEEasRequireEncryptionResultDeHardwareNotCompliant = 5,
    WSEEasRequireEncryptionResultHardwareNotCompliant = 5,
    WSEEasRequireEncryptionResultDeWinReNotConfigured = 6,
    WSEEasRequireEncryptionResultLockNotConfigured = 6,
    WSEEasRequireEncryptionResultDeProtectionSuspended = 7,
    WSEEasRequireEncryptionResultProtectionSuspended = 7,
    WSEEasRequireEncryptionResultDeOsVolumeNotProtected = 8,
    WSEEasRequireEncryptionResultOsVolumeNotProtected = 8,
    WSEEasRequireEncryptionResultDeProtectionNotYetEnabled = 9,
    WSEEasRequireEncryptionResultProtectionNotYetEnabled = 9,
    WSEEasRequireEncryptionResultNoFeatureLicense = 10,
    WSEEasRequireEncryptionResultOsNotProtected = 11,
    WSEEasRequireEncryptionResultUnexpectedFailure = 12,
};
typedef unsigned WSEEasRequireEncryptionResult;

// Windows.Security.ExchangeActiveSyncProvisioning.EasEncryptionProviderType
enum _WSEEasEncryptionProviderType {
    WSEEasEncryptionProviderTypeNotEvaluated = 0,
    WSEEasEncryptionProviderTypeWindowsEncryption = 1,
    WSEEasEncryptionProviderTypeOtherEncryption = 2,
};
typedef unsigned WSEEasEncryptionProviderType;

// Windows.Security.ExchangeActiveSyncProvisioning.EasMinPasswordLengthResult
enum _WSEEasMinPasswordLengthResult {
    WSEEasMinPasswordLengthResultNotEvaluated = 0,
    WSEEasMinPasswordLengthResultCompliant = 1,
    WSEEasMinPasswordLengthResultCanBeCompliant = 2,
    WSEEasMinPasswordLengthResultRequestedPolicyIsStricter = 3,
    WSEEasMinPasswordLengthResultRequestedPolicyNotEnforceable = 4,
    WSEEasMinPasswordLengthResultInvalidParameter = 5,
    WSEEasMinPasswordLengthResultCurrentUserHasBlankPassword = 6,
    WSEEasMinPasswordLengthResultAdminsHaveBlankPassword = 7,
    WSEEasMinPasswordLengthResultUserCannotChangePassword = 8,
    WSEEasMinPasswordLengthResultAdminsCannotChangePassword = 9,
    WSEEasMinPasswordLengthResultLocalControlledUsersCannotChangePassword = 10,
    WSEEasMinPasswordLengthResultConnectedAdminsProviderPolicyIsWeak = 11,
    WSEEasMinPasswordLengthResultConnectedUserProviderPolicyIsWeak = 12,
    WSEEasMinPasswordLengthResultChangeConnectedAdminsPassword = 13,
    WSEEasMinPasswordLengthResultChangeConnectedUserPassword = 14,
};
typedef unsigned WSEEasMinPasswordLengthResult;

// Windows.Security.ExchangeActiveSyncProvisioning.EasDisallowConvenienceLogonResult
enum _WSEEasDisallowConvenienceLogonResult {
    WSEEasDisallowConvenienceLogonResultNotEvaluated = 0,
    WSEEasDisallowConvenienceLogonResultCompliant = 1,
    WSEEasDisallowConvenienceLogonResultCanBeCompliant = 2,
    WSEEasDisallowConvenienceLogonResultRequestedPolicyIsStricter = 3,
};
typedef unsigned WSEEasDisallowConvenienceLogonResult;

// Windows.Security.ExchangeActiveSyncProvisioning.EasMinPasswordComplexCharactersResult
enum _WSEEasMinPasswordComplexCharactersResult {
    WSEEasMinPasswordComplexCharactersResultNotEvaluated = 0,
    WSEEasMinPasswordComplexCharactersResultCompliant = 1,
    WSEEasMinPasswordComplexCharactersResultCanBeCompliant = 2,
    WSEEasMinPasswordComplexCharactersResultRequestedPolicyIsStricter = 3,
    WSEEasMinPasswordComplexCharactersResultRequestedPolicyNotEnforceable = 4,
    WSEEasMinPasswordComplexCharactersResultInvalidParameter = 5,
    WSEEasMinPasswordComplexCharactersResultCurrentUserHasBlankPassword = 6,
    WSEEasMinPasswordComplexCharactersResultAdminsHaveBlankPassword = 7,
    WSEEasMinPasswordComplexCharactersResultUserCannotChangePassword = 8,
    WSEEasMinPasswordComplexCharactersResultAdminsCannotChangePassword = 9,
    WSEEasMinPasswordComplexCharactersResultLocalControlledUsersCannotChangePassword = 10,
    WSEEasMinPasswordComplexCharactersResultConnectedAdminsProviderPolicyIsWeak = 11,
    WSEEasMinPasswordComplexCharactersResultConnectedUserProviderPolicyIsWeak = 12,
    WSEEasMinPasswordComplexCharactersResultChangeConnectedAdminsPassword = 13,
    WSEEasMinPasswordComplexCharactersResultChangeConnectedUserPassword = 14,
};
typedef unsigned WSEEasMinPasswordComplexCharactersResult;

// Windows.Security.ExchangeActiveSyncProvisioning.EasPasswordExpirationResult
enum _WSEEasPasswordExpirationResult {
    WSEEasPasswordExpirationResultNotEvaluated = 0,
    WSEEasPasswordExpirationResultCompliant = 1,
    WSEEasPasswordExpirationResultCanBeCompliant = 2,
    WSEEasPasswordExpirationResultRequestedPolicyIsStricter = 3,
    WSEEasPasswordExpirationResultRequestedExpirationIncompatible = 4,
    WSEEasPasswordExpirationResultInvalidParameter = 5,
    WSEEasPasswordExpirationResultUserCannotChangePassword = 6,
    WSEEasPasswordExpirationResultAdminsCannotChangePassword = 7,
    WSEEasPasswordExpirationResultLocalControlledUsersCannotChangePassword = 8,
};
typedef unsigned WSEEasPasswordExpirationResult;

// Windows.Security.ExchangeActiveSyncProvisioning.EasPasswordHistoryResult
enum _WSEEasPasswordHistoryResult {
    WSEEasPasswordHistoryResultNotEvaluated = 0,
    WSEEasPasswordHistoryResultCompliant = 1,
    WSEEasPasswordHistoryResultCanBeCompliant = 2,
    WSEEasPasswordHistoryResultRequestedPolicyIsStricter = 3,
    WSEEasPasswordHistoryResultInvalidParameter = 4,
};
typedef unsigned WSEEasPasswordHistoryResult;

// Windows.Security.ExchangeActiveSyncProvisioning.EasMaxPasswordFailedAttemptsResult
enum _WSEEasMaxPasswordFailedAttemptsResult {
    WSEEasMaxPasswordFailedAttemptsResultNotEvaluated = 0,
    WSEEasMaxPasswordFailedAttemptsResultCompliant = 1,
    WSEEasMaxPasswordFailedAttemptsResultCanBeCompliant = 2,
    WSEEasMaxPasswordFailedAttemptsResultRequestedPolicyIsStricter = 3,
    WSEEasMaxPasswordFailedAttemptsResultInvalidParameter = 4,
};
typedef unsigned WSEEasMaxPasswordFailedAttemptsResult;

// Windows.Security.ExchangeActiveSyncProvisioning.EasMaxInactivityTimeLockResult
enum _WSEEasMaxInactivityTimeLockResult {
    WSEEasMaxInactivityTimeLockResultNotEvaluated = 0,
    WSEEasMaxInactivityTimeLockResultCompliant = 1,
    WSEEasMaxInactivityTimeLockResultCanBeCompliant = 2,
    WSEEasMaxInactivityTimeLockResultRequestedPolicyIsStricter = 3,
    WSEEasMaxInactivityTimeLockResultInvalidParameter = 4,
};
typedef unsigned WSEEasMaxInactivityTimeLockResult;

#include "WindowsFoundation.h"

// Windows.Security.ExchangeActiveSyncProvisioning.EasComplianceResults
#ifndef __WSEEasComplianceResults_DEFINED__
#define __WSEEasComplianceResults_DEFINED__

WINRT_EXPORT
@interface WSEEasComplianceResults : RTObject
@property (readonly) BOOL compliant;
@property (readonly) WSEEasDisallowConvenienceLogonResult disallowConvenienceLogonResult;
@property (readonly) WSEEasMaxInactivityTimeLockResult maxInactivityTimeLockResult;
@property (readonly) WSEEasMaxPasswordFailedAttemptsResult maxPasswordFailedAttemptsResult;
@property (readonly) WSEEasMinPasswordComplexCharactersResult minPasswordComplexCharactersResult;
@property (readonly) WSEEasMinPasswordLengthResult minPasswordLengthResult;
@property (readonly) WSEEasPasswordExpirationResult passwordExpirationResult;
@property (readonly) WSEEasPasswordHistoryResult passwordHistoryResult;
@property (readonly) WSEEasRequireEncryptionResult requireEncryptionResult;
@property (readonly) WSEEasEncryptionProviderType encryptionProviderType;
@end

#endif // __WSEEasComplianceResults_DEFINED__

// Windows.Security.ExchangeActiveSyncProvisioning.EasClientSecurityPolicy
#ifndef __WSEEasClientSecurityPolicy_DEFINED__
#define __WSEEasClientSecurityPolicy_DEFINED__

WINRT_EXPORT
@interface WSEEasClientSecurityPolicy : RTObject
+ (instancetype)create ACTIVATOR;
@property BOOL requireEncryption;
@property unsigned passwordHistory;
@property (copy) WFTimeSpan* passwordExpiration;
@property uint8_t minPasswordLength;
@property uint8_t minPasswordComplexCharacters;
@property uint8_t maxPasswordFailedAttempts;
@property (copy) WFTimeSpan* maxInactivityTimeLock;
@property BOOL disallowConvenienceLogon;
- (WSEEasComplianceResults*)checkCompliance;
- (void)applyAsyncWithSuccess:(void (^)(WSEEasComplianceResults*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSEEasClientSecurityPolicy_DEFINED__

// Windows.Security.ExchangeActiveSyncProvisioning.EasClientDeviceInformation
#ifndef __WSEEasClientDeviceInformation_DEFINED__
#define __WSEEasClientDeviceInformation_DEFINED__

WINRT_EXPORT
@interface WSEEasClientDeviceInformation : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) NSString* friendlyName;
@property (readonly) WFGUID* id;
@property (readonly) NSString* operatingSystem;
@property (readonly) NSString* systemManufacturer;
@property (readonly) NSString* systemProductName;
@property (readonly) NSString* systemSku;
@end

#endif // __WSEEasClientDeviceInformation_DEFINED__
