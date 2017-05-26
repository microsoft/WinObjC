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

// WindowsSecurityCredentials.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Security.Credentials.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSecurityCredentials.h"
#include "WindowsSecurityCredentials_priv.h"

@implementation WSCIWebAccount

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccount> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSCWebAccountProvider*)webAccountProvider {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccountProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccount>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebAccountProvider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCWebAccountProvider>(unmarshalledReturn.Get());
}

- (NSString*)userName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccount>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSCWebAccountState)state {
    ABI::Windows::Security::Credentials::WebAccountState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccount>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WSCWebAccountState)unmarshalledReturn;
}

@end

@implementation WSCWebAccountProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccountProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Security::Credentials::IWebAccountProviderFactory> WSCIWebAccountProviderFactory_inst() {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccountProviderFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Security.Credentials.WebAccountProvider").Get(),
                                                       &inst));
    return inst;
}

+ (WSCWebAccountProvider*)makeWebAccountProvider:(NSString*)id displayName:(NSString*)displayName iconUri:(WFUri*)iconUri {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccountProvider> unmarshalledReturn;
    auto _comInst = WSCIWebAccountProviderFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWebAccountProvider(nsStrToHstr(id).Get(),
                                                          nsStrToHstr(displayName).Get(),
                                                          _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(iconUri).Get(),
                                                          unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSCWebAccountProvider>(unmarshalledReturn.Get()) retain];
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccountProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccountProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFUri*)iconUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccountProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IconUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (NSString*)displayPurpose {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccountProvider2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayPurpose(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)authority {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccountProvider2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Authority(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccountProvider3>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WSCWebAccount

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccount> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Security::Credentials::IWebAccountFactory> WSCIWebAccountFactory_inst() {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccountFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Security.Credentials.WebAccount").Get(), &inst));
    return inst;
}

+ (WSCWebAccount*)makeWebAccount:(WSCWebAccountProvider*)webAccountProvider userName:(NSString*)userName state:(WSCWebAccountState)state {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccount> unmarshalledReturn;
    auto _comInst = WSCIWebAccountFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWebAccount(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccountProvider>(webAccountProvider).Get(),
                                   nsStrToHstr(userName).Get(),
                                   (ABI::Windows::Security::Credentials::WebAccountState)state,
                                   unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSCWebAccount>(unmarshalledReturn.Get()) retain];
}

- (WSCWebAccountProvider*)webAccountProvider {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccountProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccount>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebAccountProvider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCWebAccountProvider>(unmarshalledReturn.Get());
}

- (NSString*)userName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccount>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSCWebAccountState)state {
    ABI::Windows::Security::Credentials::WebAccountState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccount>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WSCWebAccountState)unmarshalledReturn;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccount2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSDictionary* /* NSString *, NSString * */)properties {
    ComPtr<IMapView<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccount2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

- (void)getPictureAsync:(WSCWebAccountPictureSize)desizedSize
                success:(void (^)(RTObject<WSSIRandomAccessStream>*))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccount2>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetPictureAsync((ABI::Windows::Security::Credentials::WebAccountPictureSize)desizedSize, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStream>(result.Get()));
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

- (RTObject<WFIAsyncAction>*)signOutAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccount2>(self);
    THROW_NS_IF_FAILED(_comInst->SignOutAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)signOutWithClientIdAsync:(NSString*)clientId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IWebAccount2>(self);
    THROW_NS_IF_FAILED(_comInst->SignOutWithClientIdAsync(nsStrToHstr(clientId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSCKeyCredentialRetrievalResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Credentials::IKeyCredentialRetrievalResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSCKeyCredential*)credential {
    ComPtr<ABI::Windows::Security::Credentials::IKeyCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IKeyCredentialRetrievalResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Credential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCKeyCredential>(unmarshalledReturn.Get());
}

- (WSCKeyCredentialStatus)status {
    ABI::Windows::Security::Credentials::KeyCredentialStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IKeyCredentialRetrievalResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSCKeyCredentialStatus)unmarshalledReturn;
}

@end

@implementation WSCKeyCredentialOperationResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Credentials::IKeyCredentialOperationResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIBuffer>*)result {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IKeyCredentialOperationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Result(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WSCKeyCredentialStatus)status {
    ABI::Windows::Security::Credentials::KeyCredentialStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IKeyCredentialOperationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSCKeyCredentialStatus)unmarshalledReturn;
}

@end

@implementation WSCKeyCredentialAttestationResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Credentials::IKeyCredentialAttestationResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIBuffer>*)certificateChainBuffer {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IKeyCredentialAttestationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_CertificateChainBuffer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)attestationBuffer {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IKeyCredentialAttestationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_AttestationBuffer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WSCKeyCredentialAttestationStatus)status {
    ABI::Windows::Security::Credentials::KeyCredentialAttestationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IKeyCredentialAttestationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSCKeyCredentialAttestationStatus)unmarshalledReturn;
}

@end

@implementation WSCKeyCredential

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Credentials::IKeyCredential> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IKeyCredential>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)retrievePublicKeyWithDefaultBlobType {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IKeyCredential>(self);
    THROW_NS_IF_FAILED(_comInst->RetrievePublicKeyWithDefaultBlobType(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)retrievePublicKeyWithBlobType:(WSCCCryptographicPublicKeyBlobType)blobType {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IKeyCredential>(self);
    THROW_NS_IF_FAILED(
        _comInst->RetrievePublicKeyWithBlobType((ABI::Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType)blobType,
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)requestSignAsync:(RTObject<WSSIBuffer>*)data
                 success:(void (^)(WSCKeyCredentialOperationResult*))success
                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::KeyCredentialOperationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IKeyCredential>(self);
    THROW_NS_IF_FAILED(
        _comInst->RequestSignAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::KeyCredentialOperationResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::KeyCredentialOperationResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Credentials::IKeyCredentialOperationResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSCKeyCredentialOperationResult>(result.Get()));
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

- (void)getAttestationAsyncWithSuccess:(void (^)(WSCKeyCredentialAttestationResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::KeyCredentialAttestationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IKeyCredential>(self);
    THROW_NS_IF_FAILED(_comInst->GetAttestationAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::KeyCredentialAttestationResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::KeyCredentialAttestationResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Credentials::IKeyCredentialAttestationResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSCKeyCredentialAttestationResult>(result.Get()));
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

@implementation WSCKeyCredentialManager

ComPtr<ABI::Windows::Security::Credentials::IKeyCredentialManagerStatics> WSCIKeyCredentialManagerStatics_inst() {
    ComPtr<ABI::Windows::Security::Credentials::IKeyCredentialManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Security.Credentials.KeyCredentialManager").Get(),
                                                       &inst));
    return inst;
}

+ (void)isSupportedAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WSCIKeyCredentialManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsSupportedAsync(&unmarshalledReturn));

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

+ (RTObject<WFIAsyncAction>*)renewAttestationAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSCIKeyCredentialManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RenewAttestationAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)requestCreateAsync:(NSString*)name
                    option:(WSCKeyCredentialCreationOption)option
                   success:(void (^)(WSCKeyCredentialRetrievalResult*))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::KeyCredentialRetrievalResult*>>
        unmarshalledReturn;
    auto _comInst = WSCIKeyCredentialManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestCreateAsync(nsStrToHstr(name).Get(),
                                                    (ABI::Windows::Security::Credentials::KeyCredentialCreationOption)option,
                                                    &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::KeyCredentialRetrievalResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::KeyCredentialRetrievalResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Credentials::IKeyCredentialRetrievalResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSCKeyCredentialRetrievalResult>(result.Get()));
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

+ (void)openAsync:(NSString*)name success:(void (^)(WSCKeyCredentialRetrievalResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::KeyCredentialRetrievalResult*>>
        unmarshalledReturn;
    auto _comInst = WSCIKeyCredentialManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->OpenAsync(nsStrToHstr(name).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::KeyCredentialRetrievalResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::KeyCredentialRetrievalResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Credentials::IKeyCredentialRetrievalResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSCKeyCredentialRetrievalResult>(result.Get()));
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

+ (RTObject<WFIAsyncAction>*)deleteAsync:(NSString*)name {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSCIKeyCredentialManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->DeleteAsync(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSCPasswordCredential

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Security::Credentials::ICredentialFactory> WSCICredentialFactory_inst() {
    ComPtr<ABI::Windows::Security::Credentials::ICredentialFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Security.Credentials.PasswordCredential").Get(),
                                                       &inst));
    return inst;
}

+ (WSCPasswordCredential*)makePasswordCredential:(NSString*)resource userName:(NSString*)userName password:(NSString*)password {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = WSCICredentialFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreatePasswordCredential(nsStrToHstr(resource).Get(),
                                                          nsStrToHstr(userName).Get(),
                                                          nsStrToHstr(password).Get(),
                                                          unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Security.Credentials.PasswordCredential").Get(), &out));
    return [_createRtProxy<WSCPasswordCredential>(out.Get()) retain];
}

- (NSString*)resource {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(self);
    THROW_NS_IF_FAILED(_comInst->get_Resource(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setResource:(NSString*)resource {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(self);
    THROW_NS_IF_FAILED(_comInst->put_Resource(nsStrToHstr(resource).Get()));
}

- (NSString*)userName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setUserName:(NSString*)userName {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(self);
    THROW_NS_IF_FAILED(_comInst->put_UserName(nsStrToHstr(userName).Get()));
}

- (NSString*)password {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(self);
    THROW_NS_IF_FAILED(_comInst->get_Password(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPassword:(NSString*)password {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(self);
    THROW_NS_IF_FAILED(_comInst->put_Password(nsStrToHstr(password).Get()));
}

- (void)retrievePassword {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(self);
    THROW_NS_IF_FAILED(_comInst->RetrievePassword());
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

@end

@implementation WSCPasswordVault

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordVault> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Security.Credentials.PasswordVault").Get(), &out));
    return [_createRtProxy<WSCPasswordVault>(out.Get()) retain];
}

- (void)add:(WSCPasswordCredential*)credential {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IPasswordVault>(self);
    THROW_NS_IF_FAILED(_comInst->Add(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(credential).Get()));
}

- (void)remove:(WSCPasswordCredential*)credential {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IPasswordVault>(self);
    THROW_NS_IF_FAILED(_comInst->Remove(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(credential).Get()));
}

- (WSCPasswordCredential*)retrieve:(NSString*)resource userName:(NSString*)userName {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IPasswordVault>(self);
    THROW_NS_IF_FAILED(_comInst->Retrieve(nsStrToHstr(resource).Get(), nsStrToHstr(userName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (NSArray* /* WSCPasswordCredential* */)findAllByResource:(NSString*)resource {
    ComPtr<IVectorView<ABI::Windows::Security::Credentials::PasswordCredential*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IPasswordVault>(self);
    THROW_NS_IF_FAILED(_comInst->FindAllByResource(nsStrToHstr(resource).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCPasswordCredential_create(unmarshalledReturn.Get());
}

- (NSArray* /* WSCPasswordCredential* */)findAllByUserName:(NSString*)userName {
    ComPtr<IVectorView<ABI::Windows::Security::Credentials::PasswordCredential*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IPasswordVault>(self);
    THROW_NS_IF_FAILED(_comInst->FindAllByUserName(nsStrToHstr(userName).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCPasswordCredential_create(unmarshalledReturn.Get());
}

- (NSArray* /* WSCPasswordCredential* */)retrieveAll {
    ComPtr<IVectorView<ABI::Windows::Security::Credentials::PasswordCredential*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Credentials::IPasswordVault>(self);
    THROW_NS_IF_FAILED(_comInst->RetrieveAll(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCPasswordCredential_create(unmarshalledReturn.Get());
}

@end

@implementation WSCPasswordCredentialPropertyStore {
    RTObservableMapObjFull<HSTRING,
                           HSTRING,
                           IInspectable*,
                           IInspectable*,
                           NSString,
                           RTObject,
                           IMap<HSTRING, IInspectable*>,
                           dummyObjCCreator,
                           dummyObjCCreator,
                           dummyWRLCreator,
                           dummyWRLCreator>
        _map;
}
INTEROP_IMPL_OBSMAP_FULL(self.comObj,
                         RTProxiedObservableNSMutableDictionary_NSString_RTObject,
                         HSTRING,
                         HSTRING,
                         IInspectable*,
                         IInspectable*,
                         NSString,
                         RTObject)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Security.Credentials.PasswordCredentialPropertyStore").Get(),
                                              &out));
    return [_createRtProxy<WSCPasswordCredentialPropertyStore>(out.Get()) retain];
}

@end

id RTProxiedNSArray_WSCPasswordCredential_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Security::Credentials::PasswordCredential*>,
                                         RTArrayObj<ABI::Windows::Security::Credentials::IPasswordCredential*,
                                                    IVectorView<ABI::Windows::Security::Credentials::PasswordCredential*>,
                                                    WSCPasswordCredential,
                                                    ABI::Windows::Security::Credentials::PasswordCredential*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
