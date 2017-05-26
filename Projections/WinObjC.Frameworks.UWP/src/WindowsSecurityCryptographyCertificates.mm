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

// WindowsSecurityCryptographyCertificates.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Security.Cryptography.Certificates.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSecurityCryptographyCertificates.h"
#include "WindowsSecurityCryptographyCertificates_priv.h"

@implementation WSCCCertificate

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateFactory> WSCCICertificateFactory_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.Certificate").Get(), &inst));
    return inst;
}

+ (WSCCCertificate*)makeCertificate:(RTObject<WSSIBuffer>*)certBlob {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = WSCCICertificateFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCertificate(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(certBlob).Get(),
                                                   unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSCCCertificate>(unmarshalledReturn.Get()) retain];
}

- (void)buildChainAsync:(id<NSFastEnumeration> /* WSCCCertificate* */)certificates
                success:(void (^)(WSCCCertificateChain*))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Cryptography::Certificates::CertificateChain*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(self);
    THROW_NS_IF_FAILED(_comInst->BuildChainAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                              ABI::Windows::Security::Cryptography::Certificates::ICertificate*>>::type>*>(
            ConvertToIterable<
                WSCCCertificate,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                                  ABI::Windows::Security::Cryptography::Certificates::ICertificate*>>(
                certificates)
                .Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Cryptography::Certificates::CertificateChain*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Cryptography::Certificates::CertificateChain*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateChain> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSCCCertificateChain>(result.Get()));
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

- (void)buildChainWithParametersAsync:(id<NSFastEnumeration> /* WSCCCertificate* */)certificates
                           parameters:(WSCCChainBuildingParameters*)parameters
                              success:(void (^)(WSCCCertificateChain*))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Cryptography::Certificates::CertificateChain*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(self);
    THROW_NS_IF_FAILED(_comInst->BuildChainWithParametersAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                              ABI::Windows::Security::Cryptography::Certificates::ICertificate*>>::type>*>(
            ConvertToIterable<
                WSCCCertificate,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                                  ABI::Windows::Security::Cryptography::Certificates::ICertificate*>>(
                certificates)
                .Get()),
        _getRtInterface<ABI::Windows::Security::Cryptography::Certificates::IChainBuildingParameters>(parameters).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Cryptography::Certificates::CertificateChain*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Cryptography::Certificates::CertificateChain*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateChain> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSCCCertificateChain>(result.Get()));
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

- (NSArray* /* uint8_t */)serialNumber {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(self);
    THROW_NS_IF_FAILED(_comInst->get_SerialNumber(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (NSArray* /* uint8_t */)getHashValue {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(self);
    THROW_NS_IF_FAILED(_comInst->GetHashValue(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (NSArray* /* uint8_t */)getHashValueWithAlgorithm:(NSString*)hashAlgorithmName {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetHashValueWithAlgorithm(nsStrToHstr(hashAlgorithmName).Get(), &unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)getCertificateBlob {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(self);
    THROW_NS_IF_FAILED(_comInst->GetCertificateBlob(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (NSString*)subject {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)issuer {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Issuer(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)hasPrivateKey {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasPrivateKey(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isStronglyProtected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStronglyProtected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDateTime*)validFrom {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(self);
    THROW_NS_IF_FAILED(_comInst->get_ValidFrom(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFDateTime*)validTo {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(self);
    THROW_NS_IF_FAILED(_comInst->get_ValidTo(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSArray* /* NSString * */)enhancedKeyUsages {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnhancedKeyUsages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (void)setFriendlyName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(self);
    THROW_NS_IF_FAILED(_comInst->put_FriendlyName(nsStrToHstr(value).Get()));
}

- (NSString*)friendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(self);
    THROW_NS_IF_FAILED(_comInst->get_FriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isSecurityDeviceBound {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSecurityDeviceBound(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WSCCCertificateKeyUsages*)keyUsages {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate2>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyUsages(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificateKeyUsages>(unmarshalledReturn.Get());
}

- (NSString*)keyAlgorithmName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate2>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyAlgorithmName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)signatureAlgorithmName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SignatureAlgorithmName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)signatureHashAlgorithmName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SignatureHashAlgorithmName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSCCSubjectAlternativeNameInfo*)subjectAlternativeName {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SubjectAlternativeName(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCSubjectAlternativeNameInfo>(unmarshalledReturn.Get());
}

- (BOOL)isPerUser {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate3>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPerUser(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)storeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate3>(self);
    THROW_NS_IF_FAILED(_comInst->get_StoreName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)keyStorageProviderName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate3>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyStorageProviderName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSCCCertificateRequestProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.CertificateRequestProperties").Get(), &out));
    return [_createRtProxy<WSCCCertificateRequestProperties>(out.Get()) retain];
}

- (NSString*)subject {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSubject:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Subject(nsStrToHstr(value).Get()));
}

- (NSString*)keyAlgorithmName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyAlgorithmName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setKeyAlgorithmName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeyAlgorithmName(nsStrToHstr(value).Get()));
}

- (unsigned int)keySize {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeySize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setKeySize:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeySize(value));
}

- (NSString*)friendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_FriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFriendlyName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_FriendlyName(nsStrToHstr(value).Get()));
}

- (NSString*)hashAlgorithmName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_HashAlgorithmName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setHashAlgorithmName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_HashAlgorithmName(nsStrToHstr(value).Get()));
}

- (WSCCExportOption)exportable {
    ABI::Windows::Security::Cryptography::Certificates::ExportOption unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Exportable(&unmarshalledReturn));
    return (WSCCExportOption)unmarshalledReturn;
}

- (void)setExportable:(WSCCExportOption)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Exportable((ABI::Windows::Security::Cryptography::Certificates::ExportOption)value));
}

- (WSCCEnrollKeyUsages)keyUsages {
    ABI::Windows::Security::Cryptography::Certificates::EnrollKeyUsages unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyUsages(&unmarshalledReturn));
    return (WSCCEnrollKeyUsages)unmarshalledReturn;
}

- (void)setKeyUsages:(WSCCEnrollKeyUsages)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeyUsages((ABI::Windows::Security::Cryptography::Certificates::EnrollKeyUsages)value));
}

- (WSCCKeyProtectionLevel)keyProtectionLevel {
    ABI::Windows::Security::Cryptography::Certificates::KeyProtectionLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyProtectionLevel(&unmarshalledReturn));
    return (WSCCKeyProtectionLevel)unmarshalledReturn;
}

- (void)setKeyProtectionLevel:(WSCCKeyProtectionLevel)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeyProtectionLevel((ABI::Windows::Security::Cryptography::Certificates::KeyProtectionLevel)value));
}

- (NSString*)keyStorageProviderName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyStorageProviderName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setKeyStorageProviderName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeyStorageProviderName(nsStrToHstr(value).Get()));
}

- (NSString*)smartcardReaderName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SmartcardReaderName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSmartcardReaderName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->put_SmartcardReaderName(nsStrToHstr(value).Get()));
}

- (WSCCCertificate*)signingCertificate {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SigningCertificate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (void)setSigningCertificate:(WSCCCertificate*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_SigningCertificate(_getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(value).Get()));
}

- (WSCCCertificate*)attestationCredentialCertificate {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AttestationCredentialCertificate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (void)setAttestationCredentialCertificate:(WSCCCertificate*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AttestationCredentialCertificate(
        _getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(value).Get()));
}

- (NSString*)curveName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurveName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCurveName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CurveName(nsStrToHstr(value).Get()));
}

- (NSArray* /* uint8_t */)curveParameters {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurveParameters(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (void)setCurveParameters:(NSArray* /* uint8_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CurveParameters(__value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (NSString*)containerNamePrefix {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContainerNamePrefix(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setContainerNamePrefix:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContainerNamePrefix(nsStrToHstr(value).Get()));
}

- (NSString*)containerName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContainerName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setContainerName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContainerName(nsStrToHstr(value).Get()));
}

- (BOOL)useExistingKey {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3>(self);
    THROW_NS_IF_FAILED(_comInst->get_UseExistingKey(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setUseExistingKey:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3>(self);
    THROW_NS_IF_FAILED(_comInst->put_UseExistingKey((boolean)value));
}

@end

@implementation WSCCUserCertificateEnrollmentManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)createRequestAsync:(WSCCCertificateRequestProperties*)request
                   success:(void (^)(NSString*))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager>(self);
    THROW_NS_IF_FAILED(_comInst->CreateRequestAsync(
        _getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(request).Get(),
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

- (RTObject<WFIAsyncAction>*)installCertificateAsync:(NSString*)certificate installOption:(WSCCInstallOptions)installOption {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager>(self);
    THROW_NS_IF_FAILED(_comInst->InstallCertificateAsync(nsStrToHstr(certificate).Get(),
                                                         (ABI::Windows::Security::Cryptography::Certificates::InstallOptions)installOption,
                                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)importPfxDataAsync:(NSString*)pfxData
                                       password:(NSString*)password
                                     exportable:(WSCCExportOption)exportable
                             keyProtectionLevel:(WSCCKeyProtectionLevel)keyProtectionLevel
                                  installOption:(WSCCInstallOptions)installOption
                                   friendlyName:(NSString*)friendlyName {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->ImportPfxDataAsync(nsStrToHstr(pfxData).Get(),
                                     nsStrToHstr(password).Get(),
                                     (ABI::Windows::Security::Cryptography::Certificates::ExportOption)exportable,
                                     (ABI::Windows::Security::Cryptography::Certificates::KeyProtectionLevel)keyProtectionLevel,
                                     (ABI::Windows::Security::Cryptography::Certificates::InstallOptions)installOption,
                                     nsStrToHstr(friendlyName).Get(),
                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)importPfxDataToKspAsync:(NSString*)pfxData
                                            password:(NSString*)password
                                          exportable:(WSCCExportOption)exportable
                                  keyProtectionLevel:(WSCCKeyProtectionLevel)keyProtectionLevel
                                       installOption:(WSCCInstallOptions)installOption
                                        friendlyName:(NSString*)friendlyName
                                  keyStorageProvider:(NSString*)keyStorageProvider {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->ImportPfxDataToKspAsync(nsStrToHstr(pfxData).Get(),
                                          nsStrToHstr(password).Get(),
                                          (ABI::Windows::Security::Cryptography::Certificates::ExportOption)exportable,
                                          (ABI::Windows::Security::Cryptography::Certificates::KeyProtectionLevel)keyProtectionLevel,
                                          (ABI::Windows::Security::Cryptography::Certificates::InstallOptions)installOption,
                                          nsStrToHstr(friendlyName).Get(),
                                          nsStrToHstr(keyStorageProvider).Get(),
                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)importPfxDataToKspWithParametersAsync:(NSString*)pfxData
                                                          password:(NSString*)password
                                               pfxImportParameters:(WSCCPfxImportParameters*)pfxImportParameters {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2>(self);
    THROW_NS_IF_FAILED(_comInst->ImportPfxDataToKspWithParametersAsync(
        nsStrToHstr(pfxData).Get(),
        nsStrToHstr(password).Get(),
        _getRtInterface<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters>(pfxImportParameters).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSCCPfxImportParameters

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.PfxImportParameters").Get(), &out));
    return [_createRtProxy<WSCCPfxImportParameters>(out.Get()) retain];
}

- (WSCCExportOption)exportable {
    ABI::Windows::Security::Cryptography::Certificates::ExportOption unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_Exportable(&unmarshalledReturn));
    return (WSCCExportOption)unmarshalledReturn;
}

- (void)setExportable:(WSCCExportOption)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_Exportable((ABI::Windows::Security::Cryptography::Certificates::ExportOption)value));
}

- (WSCCKeyProtectionLevel)keyProtectionLevel {
    ABI::Windows::Security::Cryptography::Certificates::KeyProtectionLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyProtectionLevel(&unmarshalledReturn));
    return (WSCCKeyProtectionLevel)unmarshalledReturn;
}

- (void)setKeyProtectionLevel:(WSCCKeyProtectionLevel)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeyProtectionLevel((ABI::Windows::Security::Cryptography::Certificates::KeyProtectionLevel)value));
}

- (WSCCInstallOptions)installOptions {
    ABI::Windows::Security::Cryptography::Certificates::InstallOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstallOptions(&unmarshalledReturn));
    return (WSCCInstallOptions)unmarshalledReturn;
}

- (void)setInstallOptions:(WSCCInstallOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_InstallOptions((ABI::Windows::Security::Cryptography::Certificates::InstallOptions)value));
}

- (NSString*)friendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_FriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFriendlyName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_FriendlyName(nsStrToHstr(value).Get()));
}

- (NSString*)keyStorageProviderName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyStorageProviderName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setKeyStorageProviderName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeyStorageProviderName(nsStrToHstr(value).Get()));
}

- (NSString*)containerNamePrefix {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContainerNamePrefix(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setContainerNamePrefix:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContainerNamePrefix(nsStrToHstr(value).Get()));
}

- (NSString*)readerName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReaderName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setReaderName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReaderName(nsStrToHstr(value).Get()));
}

@end

@implementation WSCCCertificateEnrollmentManager

ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2>
WSCCICertificateEnrollmentManagerStatics2_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.CertificateEnrollmentManager").Get(), &inst));
    return inst;
}

+ (WSCCUserCertificateEnrollmentManager*)userCertificateEnrollmentManager {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager> unmarshalledReturn;
    auto _comInst = WSCCICertificateEnrollmentManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_UserCertificateEnrollmentManager(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCUserCertificateEnrollmentManager>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)importPfxDataToKspAsync:(NSString*)pfxData
                                            password:(NSString*)password
                                          exportable:(WSCCExportOption)exportable
                                  keyProtectionLevel:(WSCCKeyProtectionLevel)keyProtectionLevel
                                       installOption:(WSCCInstallOptions)installOption
                                        friendlyName:(NSString*)friendlyName
                                  keyStorageProvider:(NSString*)keyStorageProvider {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSCCICertificateEnrollmentManagerStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->ImportPfxDataToKspAsync(nsStrToHstr(pfxData).Get(),
                                          nsStrToHstr(password).Get(),
                                          (ABI::Windows::Security::Cryptography::Certificates::ExportOption)exportable,
                                          (ABI::Windows::Security::Cryptography::Certificates::KeyProtectionLevel)keyProtectionLevel,
                                          (ABI::Windows::Security::Cryptography::Certificates::InstallOptions)installOption,
                                          nsStrToHstr(friendlyName).Get(),
                                          nsStrToHstr(keyStorageProvider).Get(),
                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>
WSCCICertificateEnrollmentManagerStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.CertificateEnrollmentManager").Get(), &inst));
    return inst;
}

+ (void)createRequestAsync:(WSCCCertificateRequestProperties*)request
                   success:(void (^)(NSString*))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WSCCICertificateEnrollmentManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateRequestAsync(
        _getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>(request).Get(),
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

+ (RTObject<WFIAsyncAction>*)installCertificateAsync:(NSString*)certificate installOption:(WSCCInstallOptions)installOption {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSCCICertificateEnrollmentManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->InstallCertificateAsync(nsStrToHstr(certificate).Get(),
                                                         (ABI::Windows::Security::Cryptography::Certificates::InstallOptions)installOption,
                                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)importPfxDataAsync:(NSString*)pfxData
                                       password:(NSString*)password
                                     exportable:(WSCCExportOption)exportable
                             keyProtectionLevel:(WSCCKeyProtectionLevel)keyProtectionLevel
                                  installOption:(WSCCInstallOptions)installOption
                                   friendlyName:(NSString*)friendlyName {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSCCICertificateEnrollmentManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->ImportPfxDataAsync(nsStrToHstr(pfxData).Get(),
                                     nsStrToHstr(password).Get(),
                                     (ABI::Windows::Security::Cryptography::Certificates::ExportOption)exportable,
                                     (ABI::Windows::Security::Cryptography::Certificates::KeyProtectionLevel)keyProtectionLevel,
                                     (ABI::Windows::Security::Cryptography::Certificates::InstallOptions)installOption,
                                     nsStrToHstr(friendlyName).Get(),
                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3>
WSCCICertificateEnrollmentManagerStatics3_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.CertificateEnrollmentManager").Get(), &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)importPfxDataToKspWithParametersAsync:(NSString*)pfxData
                                                          password:(NSString*)password
                                               pfxImportParameters:(WSCCPfxImportParameters*)pfxImportParameters {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSCCICertificateEnrollmentManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->ImportPfxDataToKspWithParametersAsync(
        nsStrToHstr(pfxData).Get(),
        nsStrToHstr(password).Get(),
        _getRtInterface<ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters>(pfxImportParameters).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSCCKeyAttestationHelper

ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2> WSCCIKeyAttestationHelperStatics2_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.KeyAttestationHelper").Get(), &inst));
    return inst;
}

+ (void)decryptTpmAttestationCredentialWithContainerNameAsync:(NSString*)credential
                                                containerName:(NSString*)containerName
                                                      success:(void (^)(NSString*))success
                                                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WSCCIKeyAttestationHelperStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->DecryptTpmAttestationCredentialWithContainerNameAsync(nsStrToHstr(credential).Get(),
                                                                                       nsStrToHstr(containerName).Get(),
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

ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics> WSCCIKeyAttestationHelperStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.KeyAttestationHelper").Get(), &inst));
    return inst;
}

+ (void)decryptTpmAttestationCredentialAsync:(NSString*)credential
                                     success:(void (^)(NSString*))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WSCCIKeyAttestationHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->DecryptTpmAttestationCredentialAsync(nsStrToHstr(credential).Get(), &unmarshalledReturn));

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

+ (NSString*)getTpmAttestationCredentialId:(NSString*)credential {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyAttestationHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetTpmAttestationCredentialId(nsStrToHstr(credential).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSCCCertificateQuery

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Security.Cryptography.Certificates.CertificateQuery").Get(),
                                              &out));
    return [_createRtProxy<WSCCCertificateQuery>(out.Get()) retain];
}

- (NSMutableArray* /* NSString * */)enhancedKeyUsages {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnhancedKeyUsages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)issuerName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery>(self);
    THROW_NS_IF_FAILED(_comInst->get_IssuerName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setIssuerName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery>(self);
    THROW_NS_IF_FAILED(_comInst->put_IssuerName(nsStrToHstr(value).Get()));
}

- (NSString*)friendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery>(self);
    THROW_NS_IF_FAILED(_comInst->get_FriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFriendlyName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery>(self);
    THROW_NS_IF_FAILED(_comInst->put_FriendlyName(nsStrToHstr(value).Get()));
}

- (NSArray* /* uint8_t */)thumbprint {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbprint(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (void)setThumbprint:(NSArray* /* uint8_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery>(self);
    THROW_NS_IF_FAILED(_comInst->put_Thumbprint(__value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (BOOL)hardwareOnly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery>(self);
    THROW_NS_IF_FAILED(_comInst->get_HardwareOnly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHardwareOnly:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery>(self);
    THROW_NS_IF_FAILED(_comInst->put_HardwareOnly((boolean)value));
}

- (BOOL)includeDuplicates {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncludeDuplicates(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIncludeDuplicates:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IncludeDuplicates((boolean)value));
}

- (BOOL)includeExpiredCertificates {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncludeExpiredCertificates(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIncludeExpiredCertificates:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IncludeExpiredCertificates((boolean)value));
}

- (NSString*)storeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery2>(self);
    THROW_NS_IF_FAILED(_comInst->get_StoreName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setStoreName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery2>(self);
    THROW_NS_IF_FAILED(_comInst->put_StoreName(nsStrToHstr(value).Get()));
}

@end

@implementation WSCCCertificateStore

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateStore> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)add:(WSCCCertificate*)certificate {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateStore>(self);
    THROW_NS_IF_FAILED(_comInst->Add(_getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(certificate).Get()));
}

- (void)Delete:(WSCCCertificate*)certificate {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateStore>(self);
    THROW_NS_IF_FAILED(
        _comInst->Delete(_getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(certificate).Get()));
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateStore2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSCCUserCertificateStore

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::IUserCertificateStore> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)requestAddAsync:(WSCCCertificate*)certificate success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IUserCertificateStore>(self);
    THROW_NS_IF_FAILED(
        _comInst->RequestAddAsync(_getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(certificate).Get(),
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

- (void)requestDeleteAsync:(WSCCCertificate*)certificate success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IUserCertificateStore>(self);
    THROW_NS_IF_FAILED(
        _comInst->RequestDeleteAsync(_getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(certificate).Get(),
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

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IUserCertificateStore>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSCCCertificateStores

ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateStoresStatics> WSCCICertificateStoresStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateStoresStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.CertificateStores").Get(), &inst));
    return inst;
}

+ (void)findAllAsyncWithSuccess:(void (^)(NSArray* /* WSCCCertificate* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>*>>
        unmarshalledReturn;
    auto _comInst = WSCCICertificateStoresStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Security::Cryptography::Certificates::Certificate*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WSCCCertificate_create(result.Get()));
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

+ (void)findAllWithQueryAsync:(WSCCCertificateQuery*)query
                      success:(void (^)(NSArray* /* WSCCCertificate* */))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>*>>
        unmarshalledReturn;
    auto _comInst = WSCCICertificateStoresStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FindAllWithQueryAsync(_getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery>(query).Get(),
                                        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Security::Cryptography::Certificates::Certificate*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WSCCCertificate_create(result.Get()));
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

+ (WSCCCertificateStore*)trustedRootCertificationAuthorities {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateStore> unmarshalledReturn;
    auto _comInst = WSCCICertificateStoresStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TrustedRootCertificationAuthorities(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificateStore>(unmarshalledReturn.Get());
}

+ (WSCCCertificateStore*)intermediateCertificationAuthorities {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateStore> unmarshalledReturn;
    auto _comInst = WSCCICertificateStoresStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IntermediateCertificationAuthorities(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificateStore>(unmarshalledReturn.Get());
}

+ (WSCCCertificateStore*)getStoreByName:(NSString*)storeName {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateStore> unmarshalledReturn;
    auto _comInst = WSCCICertificateStoresStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetStoreByName(nsStrToHstr(storeName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificateStore>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2> WSCCICertificateStoresStatics2_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.CertificateStores").Get(), &inst));
    return inst;
}

+ (WSCCUserCertificateStore*)getUserStoreByName:(NSString*)storeName {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::IUserCertificateStore> unmarshalledReturn;
    auto _comInst = WSCCICertificateStoresStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetUserStoreByName(nsStrToHstr(storeName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCUserCertificateStore>(unmarshalledReturn.Get());
}

@end

@implementation WSCCStandardCertificateStoreNames

ComPtr<ABI::Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>
WSCCIStandardCertificateStoreNamesStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.StandardCertificateStoreNames").Get(), &inst));
    return inst;
}

+ (NSString*)personal {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIStandardCertificateStoreNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Personal(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)trustedRootCertificationAuthorities {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIStandardCertificateStoreNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TrustedRootCertificationAuthorities(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)intermediateCertificationAuthorities {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIStandardCertificateStoreNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IntermediateCertificationAuthorities(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSCCKeyAlgorithmNames

ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics> WSCCIKeyAlgorithmNamesStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.KeyAlgorithmNames").Get(), &inst));
    return inst;
}

+ (NSString*)rsa {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Rsa(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)dsa {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Dsa(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)ecdh256 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ecdh256(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)ecdh384 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ecdh384(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)ecdh521 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ecdh521(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)ecdsa256 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ecdsa256(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)ecdsa384 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ecdsa384(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)ecdsa521 {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyAlgorithmNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ecdsa521(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2> WSCCIKeyAlgorithmNamesStatics2_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.KeyAlgorithmNames").Get(), &inst));
    return inst;
}

+ (NSString*)ecdsa {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyAlgorithmNamesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ecdsa(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)ecdh {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyAlgorithmNamesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ecdh(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSCCKeyStorageProviderNames

ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2> WSCCIKeyStorageProviderNamesStatics2_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.KeyStorageProviderNames").Get(), &inst));
    return inst;
}

+ (NSString*)passportKeyStorageProvider {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyStorageProviderNamesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_PassportKeyStorageProvider(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics> WSCCIKeyStorageProviderNamesStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.KeyStorageProviderNames").Get(), &inst));
    return inst;
}

+ (NSString*)softwareKeyStorageProvider {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyStorageProviderNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SoftwareKeyStorageProvider(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)smartcardKeyStorageProvider {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyStorageProviderNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SmartcardKeyStorageProvider(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)platformKeyStorageProvider {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCCIKeyStorageProviderNamesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PlatformKeyStorageProvider(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSCCChainBuildingParameters

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::IChainBuildingParameters> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.ChainBuildingParameters").Get(), &out));
    return [_createRtProxy<WSCCChainBuildingParameters>(out.Get()) retain];
}

- (NSMutableArray* /* NSString * */)enhancedKeyUsages {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IChainBuildingParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnhancedKeyUsages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (WFDateTime*)validationTimestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IChainBuildingParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_ValidationTimestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setValidationTimestamp:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IChainBuildingParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_ValidationTimestamp(*[value internalStruct]));
}

- (BOOL)revocationCheckEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IChainBuildingParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_RevocationCheckEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setRevocationCheckEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IChainBuildingParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_RevocationCheckEnabled((boolean)value));
}

- (BOOL)networkRetrievalEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IChainBuildingParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkRetrievalEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setNetworkRetrievalEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IChainBuildingParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_NetworkRetrievalEnabled((boolean)value));
}

- (BOOL)authorityInformationAccessEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IChainBuildingParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_AuthorityInformationAccessEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAuthorityInformationAccessEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IChainBuildingParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_AuthorityInformationAccessEnabled((boolean)value));
}

- (BOOL)currentTimeValidationEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IChainBuildingParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentTimeValidationEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCurrentTimeValidationEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IChainBuildingParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_CurrentTimeValidationEnabled((boolean)value));
}

- (NSMutableArray* /* WSCCCertificate* */)exclusiveTrustRoots {
    ComPtr<IVector<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IChainBuildingParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExclusiveTrustRoots(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WSCCCertificate_create(unmarshalledReturn.Get());
}

@end

@implementation WSCCChainValidationParameters

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::IChainValidationParameters> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.ChainValidationParameters").Get(), &out));
    return [_createRtProxy<WSCCChainValidationParameters>(out.Get()) retain];
}

- (WSCCCertificateChainPolicy)certificateChainPolicy {
    ABI::Windows::Security::Cryptography::Certificates::CertificateChainPolicy unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IChainValidationParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_CertificateChainPolicy(&unmarshalledReturn));
    return (WSCCCertificateChainPolicy)unmarshalledReturn;
}

- (void)setCertificateChainPolicy:(WSCCCertificateChainPolicy)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IChainValidationParameters>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_CertificateChainPolicy((ABI::Windows::Security::Cryptography::Certificates::CertificateChainPolicy)value));
}

- (WNHostName*)serverDnsName {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IChainValidationParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerDnsName(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (void)setServerDnsName:(WNHostName*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::IChainValidationParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_ServerDnsName(_getRtInterface<ABI::Windows::Networking::IHostName>(value).Get()));
}

@end

@implementation WSCCCertificateChain

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateChain> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSCCChainValidationResult)validate {
    ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateChain>(self);
    THROW_NS_IF_FAILED(_comInst->Validate(&unmarshalledReturn));
    return (WSCCChainValidationResult)unmarshalledReturn;
}

- (WSCCChainValidationResult)validateWithParameters:(WSCCChainValidationParameters*)parameter {
    ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateChain>(self);
    THROW_NS_IF_FAILED(_comInst->ValidateWithParameters(
        _getRtInterface<ABI::Windows::Security::Cryptography::Certificates::IChainValidationParameters>(parameter).Get(),
        &unmarshalledReturn));
    return (WSCCChainValidationResult)unmarshalledReturn;
}

- (NSArray* /* WSCCCertificate* */)getCertificates:(BOOL)includeRoot {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateChain>(self);
    THROW_NS_IF_FAILED(_comInst->GetCertificates((boolean)includeRoot, unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCCertificate_create(unmarshalledReturn.Get());
}

@end

@implementation WSCCCertificateKeyUsages

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.CertificateKeyUsages").Get(), &out));
    return [_createRtProxy<WSCCCertificateKeyUsages>(out.Get()) retain];
}

- (BOOL)encipherOnly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncipherOnly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEncipherOnly:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>(self);
    THROW_NS_IF_FAILED(_comInst->put_EncipherOnly((boolean)value));
}

- (BOOL)crlSign {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>(self);
    THROW_NS_IF_FAILED(_comInst->get_CrlSign(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCrlSign:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>(self);
    THROW_NS_IF_FAILED(_comInst->put_CrlSign((boolean)value));
}

- (BOOL)keyCertificateSign {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyCertificateSign(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setKeyCertificateSign:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeyCertificateSign((boolean)value));
}

- (BOOL)keyAgreement {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyAgreement(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setKeyAgreement:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeyAgreement((boolean)value));
}

- (BOOL)dataEncipherment {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataEncipherment(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setDataEncipherment:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>(self);
    THROW_NS_IF_FAILED(_comInst->put_DataEncipherment((boolean)value));
}

- (BOOL)keyEncipherment {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyEncipherment(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setKeyEncipherment:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeyEncipherment((boolean)value));
}

- (BOOL)nonRepudiation {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>(self);
    THROW_NS_IF_FAILED(_comInst->get_NonRepudiation(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setNonRepudiation:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>(self);
    THROW_NS_IF_FAILED(_comInst->put_NonRepudiation((boolean)value));
}

- (BOOL)digitalSignature {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>(self);
    THROW_NS_IF_FAILED(_comInst->get_DigitalSignature(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setDigitalSignature:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>(self);
    THROW_NS_IF_FAILED(_comInst->put_DigitalSignature((boolean)value));
}

@end

@implementation WSCCSubjectAlternativeNameInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.SubjectAlternativeNameInfo").Get(), &out));
    return [_createRtProxy<WSCCSubjectAlternativeNameInfo>(out.Get()) retain];
}

- (NSArray* /* NSString * */)emailName {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailName(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSArray* /* NSString * */)iPAddress {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_IPAddress(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSArray* /* NSString * */)url {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Url(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSArray* /* NSString * */)dnsName {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DnsName(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSArray* /* NSString * */)distinguishedName {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DistinguishedName(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSArray* /* NSString * */)principalName {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrincipalName(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WSCCCmsTimestampInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsTimestampInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSCCCertificate*)signingCertificate {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICmsTimestampInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SigningCertificate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (NSArray* /* WSCCCertificate* */)certificates {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICmsTimestampInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Certificates(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCCertificate_create(unmarshalledReturn.Get());
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICmsTimestampInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

@end

@implementation WSCCCmsSignerInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsSignerInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Security.Cryptography.Certificates.CmsSignerInfo").Get(),
                                              &out));
    return [_createRtProxy<WSCCCmsSignerInfo>(out.Get()) retain];
}

- (WSCCCertificate*)certificate {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICmsSignerInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Certificate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (void)setCertificate:(WSCCCertificate*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICmsSignerInfo>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Certificate(_getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(value).Get()));
}

- (NSString*)hashAlgorithmName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICmsSignerInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_HashAlgorithmName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setHashAlgorithmName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICmsSignerInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_HashAlgorithmName(nsStrToHstr(value).Get()));
}

- (WSCCCmsTimestampInfo*)timestampInfo {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsTimestampInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICmsSignerInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimestampInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCmsTimestampInfo>(unmarshalledReturn.Get());
}

@end

@implementation WSCCCmsAttachedSignature

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsAttachedSignature> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory> WSCCICmsAttachedSignatureFactory_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.CmsAttachedSignature").Get(), &inst));
    return inst;
}

+ (WSCCCmsAttachedSignature*)makeCmsAttachedSignature:(RTObject<WSSIBuffer>*)inputBlob {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsAttachedSignature> unmarshalledReturn;
    auto _comInst = WSCCICmsAttachedSignatureFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCmsAttachedSignature(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(inputBlob).Get(),
                                                            unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSCCCmsAttachedSignature>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics> WSCCICmsAttachedSignatureStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.CmsAttachedSignature").Get(), &inst));
    return inst;
}

+ (void)generateSignatureAsync:(RTObject<WSSIBuffer>*)data
                       signers:(id<NSFastEnumeration> /* WSCCCmsSignerInfo* */)signers
                  certificates:(id<NSFastEnumeration> /* WSCCCertificate* */)certificates
                       success:(void (^)(RTObject<WSSIBuffer>*))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = WSCCICmsAttachedSignatureStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GenerateSignatureAsync(
        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::Security::Cryptography::Certificates::CmsSignerInfo*,
            ABI::Windows::Security::Cryptography::Certificates::ICmsSignerInfo*>>::type>*>(
            ConvertToIterable<
                WSCCCmsSignerInfo,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Security::Cryptography::Certificates::CmsSignerInfo*,
                                                                  ABI::Windows::Security::Cryptography::Certificates::ICmsSignerInfo*>>(
                signers)
                .Get()),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                              ABI::Windows::Security::Cryptography::Certificates::ICertificate*>>::type>*>(
            ConvertToIterable<
                WSCCCertificate,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                                  ABI::Windows::Security::Cryptography::Certificates::ICertificate*>>(
                certificates)
                .Get()),
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

- (NSArray* /* WSCCCertificate* */)certificates {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICmsAttachedSignature>(self);
    THROW_NS_IF_FAILED(_comInst->get_Certificates(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCCertificate_create(unmarshalledReturn.Get());
}

- (NSArray* /* uint8_t */)content {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICmsAttachedSignature>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (NSArray* /* WSCCCmsSignerInfo* */)signers {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::CmsSignerInfo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICmsAttachedSignature>(self);
    THROW_NS_IF_FAILED(_comInst->get_Signers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCCmsSignerInfo_create(unmarshalledReturn.Get());
}

- (WSCCSignatureValidationResult)verifySignature {
    ABI::Windows::Security::Cryptography::Certificates::SignatureValidationResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICmsAttachedSignature>(self);
    THROW_NS_IF_FAILED(_comInst->VerifySignature(&unmarshalledReturn));
    return (WSCCSignatureValidationResult)unmarshalledReturn;
}

@end

@implementation WSCCCmsDetachedSignature

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsDetachedSignature> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory> WSCCICmsDetachedSignatureFactory_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.CmsDetachedSignature").Get(), &inst));
    return inst;
}

+ (WSCCCmsDetachedSignature*)makeCmsDetachedSignature:(RTObject<WSSIBuffer>*)inputBlob {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsDetachedSignature> unmarshalledReturn;
    auto _comInst = WSCCICmsDetachedSignatureFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCmsDetachedSignature(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(inputBlob).Get(),
                                                            unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSCCCmsDetachedSignature>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics> WSCCICmsDetachedSignatureStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.Certificates.CmsDetachedSignature").Get(), &inst));
    return inst;
}

+ (void)generateSignatureAsync:(RTObject<WSSIInputStream>*)data
                       signers:(id<NSFastEnumeration> /* WSCCCmsSignerInfo* */)signers
                  certificates:(id<NSFastEnumeration> /* WSCCCertificate* */)certificates
                       success:(void (^)(RTObject<WSSIBuffer>*))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = WSCCICmsDetachedSignatureStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GenerateSignatureAsync(
        _getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(data).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::Security::Cryptography::Certificates::CmsSignerInfo*,
            ABI::Windows::Security::Cryptography::Certificates::ICmsSignerInfo*>>::type>*>(
            ConvertToIterable<
                WSCCCmsSignerInfo,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Security::Cryptography::Certificates::CmsSignerInfo*,
                                                                  ABI::Windows::Security::Cryptography::Certificates::ICmsSignerInfo*>>(
                signers)
                .Get()),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                              ABI::Windows::Security::Cryptography::Certificates::ICertificate*>>::type>*>(
            ConvertToIterable<
                WSCCCertificate,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                                  ABI::Windows::Security::Cryptography::Certificates::ICertificate*>>(
                certificates)
                .Get()),
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

- (NSArray* /* WSCCCertificate* */)certificates {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICmsDetachedSignature>(self);
    THROW_NS_IF_FAILED(_comInst->get_Certificates(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCCertificate_create(unmarshalledReturn.Get());
}

- (NSArray* /* WSCCCmsSignerInfo* */)signers {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::CmsSignerInfo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICmsDetachedSignature>(self);
    THROW_NS_IF_FAILED(_comInst->get_Signers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCCmsSignerInfo_create(unmarshalledReturn.Get());
}

- (void)verifySignatureAsync:(RTObject<WSSIInputStream>*)data
                     success:(void (^)(WSCCSignatureValidationResult))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Cryptography::Certificates::SignatureValidationResult>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::Certificates::ICmsDetachedSignature>(self);
    THROW_NS_IF_FAILED(
        _comInst->VerifySignatureAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(data).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Security::Cryptography::Certificates::SignatureValidationResult>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Cryptography::Certificates::SignatureValidationResult>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Security::Cryptography::Certificates::SignatureValidationResult result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WSCCSignatureValidationResult)result);
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

id RTProxiedIterableNSArray_WSCCCertificate_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Security::Cryptography::Certificates::Certificate*>,
                                                 RTIterableObj<ABI::Windows::Security::Cryptography::Certificates::ICertificate*,
                                                               IIterable<ABI::Windows::Security::Cryptography::Certificates::Certificate*>,
                                                               WSCCCertificate,
                                                               ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WSCCCmsSignerInfo_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<ABI::Windows::Security::Cryptography::Certificates::CmsSignerInfo*>,
                                RTIterableObj<ABI::Windows::Security::Cryptography::Certificates::ICmsSignerInfo*,
                                              IIterable<ABI::Windows::Security::Cryptography::Certificates::CmsSignerInfo*>,
                                              WSCCCmsSignerInfo,
                                              ABI::Windows::Security::Cryptography::Certificates::CmsSignerInfo*,
                                              dummyObjCCreator,
                                              dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

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

id RTProxiedNSArray_WSCCCmsSignerInfo_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Security::Cryptography::Certificates::CmsSignerInfo*>,
                                         RTArrayObj<ABI::Windows::Security::Cryptography::Certificates::ICmsSignerInfo*,
                                                    IVectorView<ABI::Windows::Security::Cryptography::Certificates::CmsSignerInfo*>,
                                                    WSCCCmsSignerInfo,
                                                    ABI::Windows::Security::Cryptography::Certificates::CmsSignerInfo*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WSCCCertificate_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Security::Cryptography::Certificates::Certificate*>,
                                                RTMutableArrayObj<ABI::Windows::Security::Cryptography::Certificates::ICertificate*,
                                                                  IVector<ABI::Windows::Security::Cryptography::Certificates::Certificate*>,
                                                                  WSCCCertificate,
                                                                  ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
