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

// WindowsSecurityCryptographyCore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Security.Cryptography.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSecurityCryptographyCore.h"
#include "WindowsSecurityCryptographyCore_priv.h"

@implementation WSCCKeyDerivationParameters

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParameters> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParametersStatics2> WSCCIKeyDerivationParametersStatics2_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParametersStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.KeyDerivationParameters").Get(), &inst));
    return inst;
}

+ (WSCCKeyDerivationParameters*)buildForCapi1Kdf:(WSCCCapi1KdfTargetAlgorithm)capi1KdfTargetAlgorithm {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParameters> unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationParametersStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->BuildForCapi1Kdf((ABI::Windows::Security::Cryptography::Core::Capi1KdfTargetAlgorithm)capi1KdfTargetAlgorithm,
                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCKeyDerivationParameters>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParametersStatics> WSCCIKeyDerivationParametersStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParametersStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.KeyDerivationParameters").Get(), &inst));
    return inst;
}

+ (WSCCKeyDerivationParameters*)buildForPbkdf2:(RTObject<WSSIBuffer>*)pbkdf2Salt iterationCount:(unsigned int)iterationCount {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParameters> unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationParametersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->BuildForPbkdf2(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(pbkdf2Salt).Get(),
                                                iterationCount,
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCKeyDerivationParameters>(unmarshalledReturn.Get());
}

+ (WSCCKeyDerivationParameters*)buildForSP800108:(RTObject<WSSIBuffer>*)label context:(RTObject<WSSIBuffer>*)context {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParameters> unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationParametersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->BuildForSP800108(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(label).Get(),
                                                  _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(context).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCKeyDerivationParameters>(unmarshalledReturn.Get());
}

+ (WSCCKeyDerivationParameters*)buildForSP80056a:(RTObject<WSSIBuffer>*)algorithmId
                                      partyUInfo:(RTObject<WSSIBuffer>*)partyUInfo
                                      partyVInfo:(RTObject<WSSIBuffer>*)partyVInfo
                                     suppPubInfo:(RTObject<WSSIBuffer>*)suppPubInfo
                                    suppPrivInfo:(RTObject<WSSIBuffer>*)suppPrivInfo {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParameters> unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationParametersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->BuildForSP80056a(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(algorithmId).Get(),
                                                  _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(partyUInfo).Get(),
                                                  _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(partyVInfo).Get(),
                                                  _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(suppPubInfo).Get(),
                                                  _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(suppPrivInfo).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCKeyDerivationParameters>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)kdfGenericBinary {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_KdfGenericBinary(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setKdfGenericBinary:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_KdfGenericBinary(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (unsigned int)iterationCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_IterationCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WSCCCapi1KdfTargetAlgorithm)capi1KdfTargetAlgorithm {
    ABI::Windows::Security::Cryptography::Core::Capi1KdfTargetAlgorithm unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParameters2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Capi1KdfTargetAlgorithm(&unmarshalledReturn));
    return (WSCCCapi1KdfTargetAlgorithm)unmarshalledReturn;
}

- (void)setCapi1KdfTargetAlgorithm:(WSCCCapi1KdfTargetAlgorithm)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParameters2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Capi1KdfTargetAlgorithm((ABI::Windows::Security::Cryptography::Core::Capi1KdfTargetAlgorithm)value));
}

@end

@implementation WSCCCryptographicKey

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicKey> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)keySize {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeySize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)exportDefaultPrivateKeyBlobType {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(self);
    THROW_NS_IF_FAILED(_comInst->ExportDefaultPrivateKeyBlobType(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)exportPrivateKeyWithBlobType:(WSCCCryptographicPrivateKeyBlobType)BlobType {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(self);
    THROW_NS_IF_FAILED(
        _comInst->ExportPrivateKeyWithBlobType((ABI::Windows::Security::Cryptography::Core::CryptographicPrivateKeyBlobType)BlobType,
                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)exportDefaultPublicKeyBlobType {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(self);
    THROW_NS_IF_FAILED(_comInst->ExportDefaultPublicKeyBlobType(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)exportPublicKeyWithBlobType:(WSCCCryptographicPublicKeyBlobType)BlobType {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(self);
    THROW_NS_IF_FAILED(
        _comInst->ExportPublicKeyWithBlobType((ABI::Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType)BlobType,
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WSCCCryptographicHash

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IHashComputation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)append:(RTObject<WSSIBuffer>*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IHashComputation>(self);
    THROW_NS_IF_FAILED(_comInst->Append(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get()));
}

- (RTObject<WSSIBuffer>*)getValueAndReset {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IHashComputation>(self);
    THROW_NS_IF_FAILED(_comInst->GetValueAndReset(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WSCCPersistedKeyProvider

ComPtr<ABI::Windows::Security::Cryptography::Core::IPersistedKeyProviderStatics> WSCCIPersistedKeyProviderStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IPersistedKeyProviderStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.PersistedKeyProvider").Get(), &inst));
    return inst;
}

+ (void)openKeyPairFromCertificateAsync:(WSCCCertificate*)certificate
                      hashAlgorithmName:(NSString*)hashAlgorithmName
                                padding:(WSCCCryptographicPadding)padding
                                success:(void (^)(WSCCCryptographicKey*))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Cryptography::Core::CryptographicKey*>> unmarshalledReturn;
    auto _comInst = WSCCIPersistedKeyProviderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->OpenKeyPairFromCertificateAsync(
        _getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(certificate).Get(),
        nsStrToHstr(hashAlgorithmName).Get(),
        (ABI::Windows::Security::Cryptography::Core::CryptographicPadding)padding,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Cryptography::Core::CryptographicKey*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Cryptography::Core::CryptographicKey*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicKey> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSCCCryptographicKey>(result.Get()));
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

+ (WSCCCryptographicKey*)openPublicKeyFromCertificate:(WSCCCertificate*)certificate
                                    hashAlgorithmName:(NSString*)hashAlgorithmName
                                              padding:(WSCCCryptographicPadding)padding {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicKey> unmarshalledReturn;
    auto _comInst = WSCCIPersistedKeyProviderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->OpenPublicKeyFromCertificate(
        _getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(certificate).Get(),
        nsStrToHstr(hashAlgorithmName).Get(),
        (ABI::Windows::Security::Cryptography::Core::CryptographicPadding)padding,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCryptographicKey>(unmarshalledReturn.Get());
}

@end

@implementation WSCCEncryptedAndAuthenticatedData

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IEncryptedAndAuthenticatedData> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIBuffer>*)encryptedData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IEncryptedAndAuthenticatedData>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncryptedData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)authenticationTag {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IEncryptedAndAuthenticatedData>(self);
    THROW_NS_IF_FAILED(_comInst->get_AuthenticationTag(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WSCCCryptographicEngine

ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicEngineStatics2> WSCCICryptographicEngineStatics2_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicEngineStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.CryptographicEngine").Get(), &inst));
    return inst;
}

+ (RTObject<WSSIBuffer>*)signHashedData:(WSCCCryptographicKey*)key data:(RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = WSCCICryptographicEngineStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->SignHashedData(_getRtInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(key).Get(),
                                                _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

+ (BOOL)verifySignatureWithHashInput:(WSCCCryptographicKey*)key
                                data:(RTObject<WSSIBuffer>*)data
                           signature:(RTObject<WSSIBuffer>*)signature {
    boolean unmarshalledReturn;
    auto _comInst = WSCCICryptographicEngineStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->VerifySignatureWithHashInput(_getRtInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(key).Get(),
                                               _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                               _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(signature).Get(),
                                               &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)decryptAsync:(WSCCCryptographicKey*)key
                data:(RTObject<WSSIBuffer>*)data
                  iv:(RTObject<WSSIBuffer>*)iv
             success:(void (^)(RTObject<WSSIBuffer>*))success
             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = WSCCICryptographicEngineStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->DecryptAsync(_getRtInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(key).Get(),
                                              _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                              _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(iv).Get(),
                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

+ (void)signAsync:(WSCCCryptographicKey*)key
             data:(RTObject<WSSIBuffer>*)data
          success:(void (^)(RTObject<WSSIBuffer>*))success
          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = WSCCICryptographicEngineStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->SignAsync(_getRtInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(key).Get(),
                                           _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                           &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

+ (void)signHashedDataAsync:(WSCCCryptographicKey*)key
                       data:(RTObject<WSSIBuffer>*)data
                    success:(void (^)(RTObject<WSSIBuffer>*))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = WSCCICryptographicEngineStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->SignHashedDataAsync(_getRtInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(key).Get(),
                                      _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicEngineStatics> WSCCICryptographicEngineStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicEngineStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.CryptographicEngine").Get(), &inst));
    return inst;
}

+ (RTObject<WSSIBuffer>*)encrypt:(WSCCCryptographicKey*)key data:(RTObject<WSSIBuffer>*)data iv:(RTObject<WSSIBuffer>*)iv {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = WSCCICryptographicEngineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Encrypt(_getRtInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(key).Get(),
                                         _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                         _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(iv).Get(),
                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

+ (RTObject<WSSIBuffer>*)decrypt:(WSCCCryptographicKey*)key data:(RTObject<WSSIBuffer>*)data iv:(RTObject<WSSIBuffer>*)iv {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = WSCCICryptographicEngineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Decrypt(_getRtInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(key).Get(),
                                         _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                         _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(iv).Get(),
                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

+ (WSCCEncryptedAndAuthenticatedData*)encryptAndAuthenticate:(WSCCCryptographicKey*)key
                                                        data:(RTObject<WSSIBuffer>*)data
                                                       nonce:(RTObject<WSSIBuffer>*)nonce
                                           authenticatedData:(RTObject<WSSIBuffer>*)authenticatedData {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IEncryptedAndAuthenticatedData> unmarshalledReturn;
    auto _comInst = WSCCICryptographicEngineStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->EncryptAndAuthenticate(_getRtInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(key).Get(),
                                         _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                         _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(nonce).Get(),
                                         _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(authenticatedData).Get(),
                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCEncryptedAndAuthenticatedData>(unmarshalledReturn.Get());
}

+ (RTObject<WSSIBuffer>*)decryptAndAuthenticate:(WSCCCryptographicKey*)key
                                           data:(RTObject<WSSIBuffer>*)data
                                          nonce:(RTObject<WSSIBuffer>*)nonce
                              authenticationTag:(RTObject<WSSIBuffer>*)authenticationTag
                              authenticatedData:(RTObject<WSSIBuffer>*)authenticatedData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = WSCCICryptographicEngineStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->DecryptAndAuthenticate(_getRtInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(key).Get(),
                                         _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                         _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(nonce).Get(),
                                         _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(authenticationTag).Get(),
                                         _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(authenticatedData).Get(),
                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

+ (RTObject<WSSIBuffer>*)sign:(WSCCCryptographicKey*)key data:(RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = WSCCICryptographicEngineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Sign(_getRtInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(key).Get(),
                                      _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                      unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

+ (BOOL)verifySignature:(WSCCCryptographicKey*)key data:(RTObject<WSSIBuffer>*)data signature:(RTObject<WSSIBuffer>*)signature {
    boolean unmarshalledReturn;
    auto _comInst = WSCCICryptographicEngineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->VerifySignature(_getRtInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(key).Get(),
                                                 _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                                 _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(signature).Get(),
                                                 &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (RTObject<WSSIBuffer>*)deriveKeyMaterial:(WSCCCryptographicKey*)key
                                parameters:(WSCCKeyDerivationParameters*)parameters
                            desiredKeySize:(unsigned int)desiredKeySize {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = WSCCICryptographicEngineStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->DeriveKeyMaterial(_getRtInterface<ABI::Windows::Security::Cryptography::Core::ICryptographicKey>(key).Get(),
                                    _getRtInterface<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParameters>(parameters).Get(),
                                    desiredKeySize,
                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WSCCHashAlgorithmProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IHashAlgorithmProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Security::Cryptography::Core::IHashAlgorithmProviderStatics> WSCCIHashAlgorithmProviderStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IHashAlgorithmProviderStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.HashAlgorithmProvider").Get(), &inst));
    return inst;
}

+ (WSCCHashAlgorithmProvider*)openAlgorithm:(NSString*)algorithm {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IHashAlgorithmProvider> unmarshalledReturn;
    auto _comInst = WSCCIHashAlgorithmProviderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->OpenAlgorithm(nsStrToHstr(algorithm).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCHashAlgorithmProvider>(unmarshalledReturn.Get());
}

- (NSString*)algorithmName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IHashAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlgorithmName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned int)hashLength {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IHashAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HashLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)hashData:(RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IHashAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(
        _comInst->HashData(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WSCCCryptographicHash*)createHash {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IHashComputation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IHashAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(_comInst->CreateHash(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCryptographicHash>(unmarshalledReturn.Get());
}

@end

@implementation WSCCMacAlgorithmProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IMacAlgorithmProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Security::Cryptography::Core::IMacAlgorithmProviderStatics> WSCCIMacAlgorithmProviderStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IMacAlgorithmProviderStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.MacAlgorithmProvider").Get(), &inst));
    return inst;
}

+ (WSCCMacAlgorithmProvider*)openAlgorithm:(NSString*)algorithm {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IMacAlgorithmProvider> unmarshalledReturn;
    auto _comInst = WSCCIMacAlgorithmProviderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->OpenAlgorithm(nsStrToHstr(algorithm).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCMacAlgorithmProvider>(unmarshalledReturn.Get());
}

- (NSString*)algorithmName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IMacAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlgorithmName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned int)macLength {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IMacAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_MacLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WSCCCryptographicKey*)createKey:(RTObject<WSSIBuffer>*)keyMaterial {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicKey> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IMacAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(_comInst->CreateKey(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(keyMaterial).Get(),
                                           unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCryptographicKey>(unmarshalledReturn.Get());
}

- (WSCCCryptographicHash*)createHash:(RTObject<WSSIBuffer>*)keyMaterial {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IHashComputation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IMacAlgorithmProvider2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateHash(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(keyMaterial).Get(),
                                            unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCryptographicHash>(unmarshalledReturn.Get());
}

@end

@implementation WSCCKeyDerivationAlgorithmProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationAlgorithmProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationAlgorithmProviderStatics>
WSCCIKeyDerivationAlgorithmProviderStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationAlgorithmProviderStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.KeyDerivationAlgorithmProvider").Get(), &inst));
    return inst;
}

+ (WSCCKeyDerivationAlgorithmProvider*)openAlgorithm:(NSString*)algorithm {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationAlgorithmProvider> unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmProviderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->OpenAlgorithm(nsStrToHstr(algorithm).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCKeyDerivationAlgorithmProvider>(unmarshalledReturn.Get());
}

- (NSString*)algorithmName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IKeyDerivationAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlgorithmName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSCCCryptographicKey*)createKey:(RTObject<WSSIBuffer>*)keyMaterial {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicKey> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IKeyDerivationAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(_comInst->CreateKey(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(keyMaterial).Get(),
                                           unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCryptographicKey>(unmarshalledReturn.Get());
}

@end

@implementation WSCCSymmetricKeyAlgorithmProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ISymmetricKeyAlgorithmProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Security::Cryptography::Core::ISymmetricKeyAlgorithmProviderStatics> WSCCISymmetricKeyAlgorithmProviderStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ISymmetricKeyAlgorithmProviderStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.SymmetricKeyAlgorithmProvider").Get(), &inst));
    return inst;
}

+ (WSCCSymmetricKeyAlgorithmProvider*)openAlgorithm:(NSString*)algorithm {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ISymmetricKeyAlgorithmProvider> unmarshalledReturn;
    auto _comInst = WSCCISymmetricKeyAlgorithmProviderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->OpenAlgorithm(nsStrToHstr(algorithm).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCSymmetricKeyAlgorithmProvider>(unmarshalledReturn.Get());
}

- (NSString*)algorithmName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::ISymmetricKeyAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlgorithmName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned int)blockLength {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::ISymmetricKeyAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_BlockLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WSCCCryptographicKey*)createSymmetricKey:(RTObject<WSSIBuffer>*)keyMaterial {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicKey> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::ISymmetricKeyAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(_comInst->CreateSymmetricKey(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(keyMaterial).Get(),
                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCryptographicKey>(unmarshalledReturn.Get());
}

@end

@implementation WSCCAsymmetricKeyAlgorithmProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProviderStatics>
WSCCIAsymmetricKeyAlgorithmProviderStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProviderStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.AsymmetricKeyAlgorithmProvider").Get(), &inst));
    return inst;
}

+ (WSCCAsymmetricKeyAlgorithmProvider*)openAlgorithm:(NSString*)algorithm {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider> unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricKeyAlgorithmProviderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->OpenAlgorithm(nsStrToHstr(algorithm).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCAsymmetricKeyAlgorithmProvider>(unmarshalledReturn.Get());
}

- (NSString*)algorithmName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlgorithmName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSCCCryptographicKey*)createKeyPair:(unsigned int)keySize {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicKey> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(_comInst->CreateKeyPair(keySize, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCryptographicKey>(unmarshalledReturn.Get());
}

- (WSCCCryptographicKey*)importDefaultPrivateKeyBlob:(RTObject<WSSIBuffer>*)keyBlob {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicKey> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ImportDefaultPrivateKeyBlob(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(keyBlob).Get(),
                                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCryptographicKey>(unmarshalledReturn.Get());
}

- (WSCCCryptographicKey*)importKeyPairWithBlobType:(RTObject<WSSIBuffer>*)keyBlob BlobType:(WSCCCryptographicPrivateKeyBlobType)BlobType {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicKey> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(
        _comInst->ImportKeyPairWithBlobType(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(keyBlob).Get(),
                                            (ABI::Windows::Security::Cryptography::Core::CryptographicPrivateKeyBlobType)BlobType,
                                            unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCryptographicKey>(unmarshalledReturn.Get());
}

- (WSCCCryptographicKey*)importDefaultPublicKeyBlob:(RTObject<WSSIBuffer>*)keyBlob {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicKey> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ImportDefaultPublicKeyBlob(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(keyBlob).Get(),
                                                            unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCryptographicKey>(unmarshalledReturn.Get());
}

- (WSCCCryptographicKey*)importPublicKeyWithBlobType:(RTObject<WSSIBuffer>*)keyBlob BlobType:(WSCCCryptographicPublicKeyBlobType)BlobType {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicKey> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider>(self);
    THROW_NS_IF_FAILED(
        _comInst->ImportPublicKeyWithBlobType(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(keyBlob).Get(),
                                              (ABI::Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType)BlobType,
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCryptographicKey>(unmarshalledReturn.Get());
}

- (WSCCCryptographicKey*)createKeyPairWithCurveName:(NSString*)curveName {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicKey> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateKeyPairWithCurveName(nsStrToHstr(curveName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCryptographicKey>(unmarshalledReturn.Get());
}

- (WSCCCryptographicKey*)createKeyPairWithCurveParameters:(NSArray* /* uint8_t */)parameters {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicKey> unmarshalledReturn;
    UINT32 __parameters_ArrayLen = 0;
    bool __parameters_IsTemp = false;
    uint8_t* __parameters_Array = NULL;
    if (!ConvertToCArray<uint8_t>(parameters, &__parameters_ArrayLen, &__parameters_Array, &__parameters_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider2>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateKeyPairWithCurveParameters(__parameters_ArrayLen, __parameters_Array, unmarshalledReturn.GetAddressOf()));
    if (__parameters_IsTemp)
        CoTaskMemFree(__parameters_Array);
    return _createRtProxy<WSCCCryptographicKey>(unmarshalledReturn.Get());
}

@end

@implementation WSCCHashAlgorithmNames

ComPtr<ABI::Windows::Security::Cryptography::Core::IHashAlgorithmNamesStatics> WSCCIHashAlgorithmNamesStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IHashAlgorithmNamesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.HashAlgorithmNames").Get(), &inst));
    return inst;
}

+ (NSString*)md5 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIHashAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Md5(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sha1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIHashAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sha1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sha256 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIHashAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sha256(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sha384 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIHashAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sha384(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sha512 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIHashAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sha512(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSCCMacAlgorithmNames

ComPtr<ABI::Windows::Security::Cryptography::Core::IMacAlgorithmNamesStatics> WSCCIMacAlgorithmNamesStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IMacAlgorithmNamesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.MacAlgorithmNames").Get(), &inst));
    return inst;
}

+ (NSString*)hmacMd5 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIMacAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HmacMd5(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hmacSha1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIMacAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HmacSha1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hmacSha256 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIMacAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HmacSha256(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hmacSha384 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIMacAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HmacSha384(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hmacSha512 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIMacAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HmacSha512(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aesCmac {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIMacAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AesCmac(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSCCSymmetricAlgorithmNames

ComPtr<ABI::Windows::Security::Cryptography::Core::ISymmetricAlgorithmNamesStatics> WSCCISymmetricAlgorithmNamesStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::ISymmetricAlgorithmNamesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.SymmetricAlgorithmNames").Get(), &inst));
    return inst;
}

+ (NSString*)desCbc {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DesCbc(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)desEcb {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DesEcb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tripleDesCbc {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TripleDesCbc(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tripleDesEcb {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TripleDesEcb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rc2Cbc {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Rc2Cbc(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rc2Ecb {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Rc2Ecb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aesCbc {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AesCbc(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aesEcb {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AesEcb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aesGcm {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AesGcm(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aesCcm {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AesCcm(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aesCbcPkcs7 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AesCbcPkcs7(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aesEcbPkcs7 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AesEcbPkcs7(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)desCbcPkcs7 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DesCbcPkcs7(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)desEcbPkcs7 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DesEcbPkcs7(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tripleDesCbcPkcs7 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TripleDesCbcPkcs7(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tripleDesEcbPkcs7 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TripleDesEcbPkcs7(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rc2CbcPkcs7 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Rc2CbcPkcs7(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rc2EcbPkcs7 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Rc2EcbPkcs7(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rc4 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCISymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Rc4(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSCCAsymmetricAlgorithmNames

ComPtr<ABI::Windows::Security::Cryptography::Core::IAsymmetricAlgorithmNamesStatics> WSCCIAsymmetricAlgorithmNamesStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IAsymmetricAlgorithmNamesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.AsymmetricAlgorithmNames").Get(), &inst));
    return inst;
}

+ (NSString*)rsaPkcs1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RsaPkcs1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rsaOaepSha1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RsaOaepSha1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rsaOaepSha256 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RsaOaepSha256(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rsaOaepSha384 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RsaOaepSha384(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rsaOaepSha512 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RsaOaepSha512(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)ecdsaP256Sha256 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EcdsaP256Sha256(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)ecdsaP384Sha384 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EcdsaP384Sha384(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)ecdsaP521Sha512 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EcdsaP521Sha512(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)dsaSha1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DsaSha1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)dsaSha256 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DsaSha256(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rsaSignPkcs1Sha1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RsaSignPkcs1Sha1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rsaSignPkcs1Sha256 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RsaSignPkcs1Sha256(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rsaSignPkcs1Sha384 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RsaSignPkcs1Sha384(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rsaSignPkcs1Sha512 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RsaSignPkcs1Sha512(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rsaSignPssSha1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RsaSignPssSha1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rsaSignPssSha256 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RsaSignPssSha256(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rsaSignPssSha384 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RsaSignPssSha384(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rsaSignPssSha512 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RsaSignPssSha512(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::Security::Cryptography::Core::IAsymmetricAlgorithmNamesStatics2> WSCCIAsymmetricAlgorithmNamesStatics2_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IAsymmetricAlgorithmNamesStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.AsymmetricAlgorithmNames").Get(), &inst));
    return inst;
}

+ (NSString*)ecdsaSha256 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_EcdsaSha256(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)ecdsaSha384 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_EcdsaSha384(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)ecdsaSha512 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIAsymmetricAlgorithmNamesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_EcdsaSha512(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSCCEccCurveNames

ComPtr<ABI::Windows::Security::Cryptography::Core::IEccCurveNamesStatics> WSCCIEccCurveNamesStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IEccCurveNamesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Security.Cryptography.Core.EccCurveNames").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)brainpoolP160r1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BrainpoolP160r1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)brainpoolP160t1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BrainpoolP160t1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)brainpoolP192r1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BrainpoolP192r1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)brainpoolP192t1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BrainpoolP192t1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)brainpoolP224r1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BrainpoolP224r1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)brainpoolP224t1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BrainpoolP224t1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)brainpoolP256r1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BrainpoolP256r1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)brainpoolP256t1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BrainpoolP256t1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)brainpoolP320r1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BrainpoolP320r1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)brainpoolP320t1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BrainpoolP320t1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)brainpoolP384r1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BrainpoolP384r1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)brainpoolP384t1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BrainpoolP384t1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)brainpoolP512r1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BrainpoolP512r1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)brainpoolP512t1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BrainpoolP512t1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)curve25519 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Curve25519(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)ec192wapi {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ec192wapi(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)nistP192 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NistP192(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)nistP224 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NistP224(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)nistP256 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NistP256(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)nistP384 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NistP384(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)nistP521 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NistP521(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)numsP256t1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NumsP256t1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)numsP384t1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NumsP384t1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)numsP512t1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NumsP512t1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)secP160k1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SecP160k1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)secP160r1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SecP160r1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)secP160r2 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SecP160r2(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)secP192k1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SecP192k1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)secP192r1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SecP192r1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)secP224k1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SecP224k1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)secP224r1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SecP224r1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)secP256k1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SecP256k1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)secP256r1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SecP256r1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)secP384r1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SecP384r1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)secP521r1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SecP521r1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)wtls7 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Wtls7(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)wtls9 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Wtls9(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)wtls12 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Wtls12(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)x962P192v1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_X962P192v1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)x962P192v2 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_X962P192v2(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)x962P192v3 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_X962P192v3(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)x962P239v1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_X962P239v1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)x962P239v2 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_X962P239v2(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)x962P239v3 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_X962P239v3(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)x962P256v1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_X962P256v1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSArray* /* NSString * */)allEccCurveNames {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = WSCCIEccCurveNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllEccCurveNames(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WSCCKeyDerivationAlgorithmNames

ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationAlgorithmNamesStatics2> WSCCIKeyDerivationAlgorithmNamesStatics2_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationAlgorithmNamesStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.KeyDerivationAlgorithmNames").Get(), &inst));
    return inst;
}

+ (NSString*)capiKdfMd5 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_CapiKdfMd5(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)capiKdfSha1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_CapiKdfSha1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)capiKdfSha256 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_CapiKdfSha256(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)capiKdfSha384 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_CapiKdfSha384(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)capiKdfSha512 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_CapiKdfSha512(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationAlgorithmNamesStatics> WSCCIKeyDerivationAlgorithmNamesStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationAlgorithmNamesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Core.KeyDerivationAlgorithmNames").Get(), &inst));
    return inst;
}

+ (NSString*)pbkdf2Md5 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Pbkdf2Md5(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)pbkdf2Sha1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Pbkdf2Sha1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)pbkdf2Sha256 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Pbkdf2Sha256(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)pbkdf2Sha384 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Pbkdf2Sha384(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)pbkdf2Sha512 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Pbkdf2Sha512(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sp800108CtrHmacMd5 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sp800108CtrHmacMd5(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sp800108CtrHmacSha1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sp800108CtrHmacSha1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sp800108CtrHmacSha256 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sp800108CtrHmacSha256(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sp800108CtrHmacSha384 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sp800108CtrHmacSha384(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sp800108CtrHmacSha512 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sp800108CtrHmacSha512(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sp80056aConcatMd5 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sp80056aConcatMd5(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sp80056aConcatSha1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sp80056aConcatSha1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sp80056aConcatSha256 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sp80056aConcatSha256(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sp80056aConcatSha384 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sp80056aConcatSha384(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sp80056aConcatSha512 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyDerivationAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sp80056aConcatSha512(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

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
