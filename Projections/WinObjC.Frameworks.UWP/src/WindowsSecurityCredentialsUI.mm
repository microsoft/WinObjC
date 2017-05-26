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

// WindowsSecurityCredentialsUI.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Security.Credentials.UI.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSecurityCredentialsUI.h"
#include "WindowsSecurityCredentialsUI_priv.h"

@implementation WSCUCredentialPickerOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Security.Credentials.UI.CredentialPickerOptions").Get(),
                                              &out));
    return [_createRtProxy<WSCUCredentialPickerOptions>(out.Get()) retain];
}

- (void)setCaption:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_Caption(nsStrToHstr(value).Get()));
}

- (NSString*)caption {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Caption(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setMessage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_Message(nsStrToHstr(value).Get()));
}

- (NSString*)message {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setErrorCode:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorCode(value));
}

- (unsigned int)errorCode {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetName(nsStrToHstr(value).Get()));
}

- (NSString*)targetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAuthenticationProtocol:(WSCUAuthenticationProtocol)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_AuthenticationProtocol((ABI::Windows::Security::Credentials::UI::AuthenticationProtocol)value));
}

- (WSCUAuthenticationProtocol)authenticationProtocol {
    ABI::Windows::Security::Credentials::UI::AuthenticationProtocol unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_AuthenticationProtocol(&unmarshalledReturn));
    return (WSCUAuthenticationProtocol)unmarshalledReturn;
}

- (void)setCustomAuthenticationProtocol:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_CustomAuthenticationProtocol(nsStrToHstr(value).Get()));
}

- (NSString*)customAuthenticationProtocol {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomAuthenticationProtocol(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPreviousCredential:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_PreviousCredential(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (RTObject<WSSIBuffer>*)previousCredential {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setAlwaysDisplayDialog:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_AlwaysDisplayDialog((boolean)value));
}

- (BOOL)alwaysDisplayDialog {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlwaysDisplayDialog(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCallerSavesCredential:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_CallerSavesCredential((boolean)value));
}

- (BOOL)callerSavesCredential {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallerSavesCredential(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCredentialSaveOption:(WSCUCredentialSaveOption)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_CredentialSaveOption((ABI::Windows::Security::Credentials::UI::CredentialSaveOption)value));
}

- (WSCUCredentialSaveOption)credentialSaveOption {
    ABI::Windows::Security::Credentials::UI::CredentialSaveOption unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_CredentialSaveOption(&unmarshalledReturn));
    return (WSCUCredentialSaveOption)unmarshalledReturn;
}

@end

@implementation WSCUCredentialPickerResults

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Credentials::UI::ICredentialPickerResults> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)errorCode {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WSCUCredentialSaveOption)credentialSaveOption {
    ABI::Windows::Security::Credentials::UI::CredentialSaveOption unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_CredentialSaveOption(&unmarshalledReturn));
    return (WSCUCredentialSaveOption)unmarshalledReturn;
}

- (BOOL)credentialSaved {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_CredentialSaved(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)credential {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_Credential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (NSString*)credentialDomainName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_CredentialDomainName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)credentialUserName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_CredentialUserName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)credentialPassword {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_CredentialPassword(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSCUCredentialPicker

ComPtr<ABI::Windows::Security::Credentials::UI::ICredentialPickerStatics> WSCUICredentialPickerStatics_inst() {
    ComPtr<ABI::Windows::Security::Credentials::UI::ICredentialPickerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Security.Credentials.UI.CredentialPicker").Get(),
                                                       &inst));
    return inst;
}

+ (void)pickWithOptionsAsync:(WSCUCredentialPickerOptions*)options
                     success:(void (^)(WSCUCredentialPickerResults*))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::UI::CredentialPickerResults*>> unmarshalledReturn;
    auto _comInst = WSCUICredentialPickerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->PickWithOptionsAsync(_getRtInterface<ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions>(options).Get(),
                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::UI::CredentialPickerResults*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::UI::CredentialPickerResults*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Credentials::UI::ICredentialPickerResults> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSCUCredentialPickerResults>(result.Get()));
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

+ (void)pickWithMessageAsync:(NSString*)targetName
                     message:(NSString*)message
                     success:(void (^)(WSCUCredentialPickerResults*))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::UI::CredentialPickerResults*>> unmarshalledReturn;
    auto _comInst = WSCUICredentialPickerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->PickWithMessageAsync(nsStrToHstr(targetName).Get(), nsStrToHstr(message).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::UI::CredentialPickerResults*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::UI::CredentialPickerResults*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Credentials::UI::ICredentialPickerResults> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSCUCredentialPickerResults>(result.Get()));
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

+ (void)pickWithCaptionAsync:(NSString*)targetName
                     message:(NSString*)message
                     caption:(NSString*)caption
                     success:(void (^)(WSCUCredentialPickerResults*))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::UI::CredentialPickerResults*>> unmarshalledReturn;
    auto _comInst = WSCUICredentialPickerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->PickWithCaptionAsync(nsStrToHstr(targetName).Get(),
                                                      nsStrToHstr(message).Get(),
                                                      nsStrToHstr(caption).Get(),
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::UI::CredentialPickerResults*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::UI::CredentialPickerResults*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Credentials::UI::ICredentialPickerResults> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSCUCredentialPickerResults>(result.Get()));
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

@implementation WSCUUserConsentVerifier

ComPtr<ABI::Windows::Security::Credentials::UI::IUserConsentVerifierStatics> WSCUIUserConsentVerifierStatics_inst() {
    ComPtr<ABI::Windows::Security::Credentials::UI::IUserConsentVerifierStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Security.Credentials.UI.UserConsentVerifier").Get(),
                                                       &inst));
    return inst;
}

+ (void)checkAvailabilityAsyncWithSuccess:(void (^)(WSCUUserConsentVerifierAvailability))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::UI::UserConsentVerifierAvailability>>
        unmarshalledReturn;
    auto _comInst = WSCUIUserConsentVerifierStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CheckAvailabilityAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::UI::UserConsentVerifierAvailability>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::UI::UserConsentVerifierAvailability>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::Credentials::UI::UserConsentVerifierAvailability result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSCUUserConsentVerifierAvailability)result);
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

+ (void)requestVerificationAsync:(NSString*)message
                         success:(void (^)(WSCUUserConsentVerificationResult))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::UI::UserConsentVerificationResult>>
        unmarshalledReturn;
    auto _comInst = WSCUIUserConsentVerifierStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestVerificationAsync(nsStrToHstr(message).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::UI::UserConsentVerificationResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::UI::UserConsentVerificationResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::Credentials::UI::UserConsentVerificationResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSCUUserConsentVerificationResult)result);
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
