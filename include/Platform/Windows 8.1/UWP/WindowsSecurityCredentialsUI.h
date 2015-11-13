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

// WindowsSecurityCredentialsUI.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSCUUserConsentVerifier, WSCUCredentialPickerOptions, WSCUCredentialPickerResults, WSCUCredentialPicker;
@protocol WSCUIUserConsentVerifierStatics
, WSCUICredentialPickerOptions, WSCUICredentialPickerStatics, WSCUICredentialPickerResults;

// Windows.Security.Credentials.UI.UserConsentVerifierAvailability
enum _WSCUUserConsentVerifierAvailability {
    WSCUUserConsentVerifierAvailabilityAvailable = 0,
    WSCUUserConsentVerifierAvailabilityDeviceNotPresent = 1,
    WSCUUserConsentVerifierAvailabilityNotConfiguredForUser = 2,
    WSCUUserConsentVerifierAvailabilityDisabledByPolicy = 3,
    WSCUUserConsentVerifierAvailabilityDeviceBusy = 4,
};
typedef unsigned WSCUUserConsentVerifierAvailability;

// Windows.Security.Credentials.UI.UserConsentVerificationResult
enum _WSCUUserConsentVerificationResult {
    WSCUUserConsentVerificationResultVerified = 0,
    WSCUUserConsentVerificationResultDeviceNotPresent = 1,
    WSCUUserConsentVerificationResultNotConfiguredForUser = 2,
    WSCUUserConsentVerificationResultDisabledByPolicy = 3,
    WSCUUserConsentVerificationResultDeviceBusy = 4,
    WSCUUserConsentVerificationResultRetriesExhausted = 5,
    WSCUUserConsentVerificationResultCanceled = 6,
};
typedef unsigned WSCUUserConsentVerificationResult;

// Windows.Security.Credentials.UI.AuthenticationProtocol
enum _WSCUAuthenticationProtocol {
    WSCUAuthenticationProtocolBasic = 0,
    WSCUAuthenticationProtocolDigest = 1,
    WSCUAuthenticationProtocolNtlm = 2,
    WSCUAuthenticationProtocolKerberos = 3,
    WSCUAuthenticationProtocolNegotiate = 4,
    WSCUAuthenticationProtocolCredSsp = 5,
    WSCUAuthenticationProtocolCustom = 6,
};
typedef unsigned WSCUAuthenticationProtocol;

// Windows.Security.Credentials.UI.CredentialSaveOption
enum _WSCUCredentialSaveOption {
    WSCUCredentialSaveOptionUnselected = 0,
    WSCUCredentialSaveOptionSelected = 1,
    WSCUCredentialSaveOptionHidden = 2,
};
typedef unsigned WSCUCredentialSaveOption;

#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"

// Windows.Security.Credentials.UI.UserConsentVerifier
#ifndef __WSCUUserConsentVerifier_DEFINED__
#define __WSCUUserConsentVerifier_DEFINED__

WINRT_EXPORT
@interface WSCUUserConsentVerifier : RTObject
+ (void)checkAvailabilityAsyncWithSuccess:(void (^)(WSCUUserConsentVerifierAvailability))success failure:(void (^)(NSError*))failure;
+ (void)requestVerificationAsync:(NSString*)message
                         success:(void (^)(WSCUUserConsentVerificationResult))success
                         failure:(void (^)(NSError*))failure;
@end

#endif // __WSCUUserConsentVerifier_DEFINED__

// Windows.Security.Credentials.UI.CredentialPickerOptions
#ifndef __WSCUCredentialPickerOptions_DEFINED__
#define __WSCUCredentialPickerOptions_DEFINED__

WINRT_EXPORT
@interface WSCUCredentialPickerOptions : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* targetName;
@property (copy) RTObject<WSSIBuffer>* previousCredential;
@property (copy) NSString* message;
@property unsigned errorCode;
@property (copy) NSString* customAuthenticationProtocol;
@property WSCUCredentialSaveOption credentialSaveOption;
@property (copy) NSString* caption;
@property BOOL callerSavesCredential;
@property WSCUAuthenticationProtocol authenticationProtocol;
@property BOOL alwaysDisplayDialog;
@end

#endif // __WSCUCredentialPickerOptions_DEFINED__

// Windows.Security.Credentials.UI.CredentialPickerResults
#ifndef __WSCUCredentialPickerResults_DEFINED__
#define __WSCUCredentialPickerResults_DEFINED__

WINRT_EXPORT
@interface WSCUCredentialPickerResults : RTObject
@property (readonly) RTObject<WSSIBuffer>* credential;
@property (readonly) NSString* credentialDomainName;
@property (readonly) NSString* credentialPassword;
@property (readonly) WSCUCredentialSaveOption credentialSaveOption;
@property (readonly) BOOL credentialSaved;
@property (readonly) NSString* credentialUserName;
@property (readonly) unsigned errorCode;
@end

#endif // __WSCUCredentialPickerResults_DEFINED__

// Windows.Security.Credentials.UI.CredentialPicker
#ifndef __WSCUCredentialPicker_DEFINED__
#define __WSCUCredentialPicker_DEFINED__

WINRT_EXPORT
@interface WSCUCredentialPicker : RTObject
+ (void)pickWithOptionsAsync:(WSCUCredentialPickerOptions*)options
                     success:(void (^)(WSCUCredentialPickerResults*))success
                     failure:(void (^)(NSError*))failure;
+ (void)pickWithMessageAsync:(NSString*)targetName
                     message:(NSString*)message
                     success:(void (^)(WSCUCredentialPickerResults*))success
                     failure:(void (^)(NSError*))failure;
+ (void)pickWithCaptionAsync:(NSString*)targetName
                     message:(NSString*)message
                     caption:(NSString*)caption
                     success:(void (^)(WSCUCredentialPickerResults*))success
                     failure:(void (^)(NSError*))failure;
@end

#endif // __WSCUCredentialPicker_DEFINED__
