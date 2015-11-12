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

// WindowsSecurityCryptographyCore.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSCCKeyDerivationParameters, WSCCCryptographicKey, WSCCCryptographicHash, WSCCPersistedKeyProvider,
    WSCCEncryptedAndAuthenticatedData, WSCCCryptographicEngine, WSCCHashAlgorithmProvider, WSCCMacAlgorithmProvider,
    WSCCKeyDerivationAlgorithmProvider, WSCCSymmetricKeyAlgorithmProvider, WSCCAsymmetricKeyAlgorithmProvider, WSCCHashAlgorithmNames,
    WSCCMacAlgorithmNames, WSCCSymmetricAlgorithmNames, WSCCAsymmetricAlgorithmNames, WSCCKeyDerivationAlgorithmNames;
@protocol WSCCIKeyDerivationParameters
, WSCCIKeyDerivationParametersStatics, WSCCICryptographicKey, WSCCIHashComputation, WSCCIHashAlgorithmProvider, WSCCIMacAlgorithmProvider,
    WSCCIMacAlgorithmProvider2, WSCCIKeyDerivationAlgorithmProvider, WSCCISymmetricKeyAlgorithmProvider,
    WSCCIAsymmetricKeyAlgorithmProvider, WSCCIPersistedKeyProviderStatics, WSCCIEncryptedAndAuthenticatedData,
    WSCCICryptographicEngineStatics, WSCCICryptographicEngineStatics2, WSCCIHashAlgorithmProviderStatics, WSCCIMacAlgorithmProviderStatics,
    WSCCIKeyDerivationAlgorithmProviderStatics, WSCCISymmetricKeyAlgorithmProviderStatics, WSCCIAsymmetricKeyAlgorithmProviderStatics,
    WSCCIHashAlgorithmNamesStatics, WSCCIMacAlgorithmNamesStatics, WSCCISymmetricAlgorithmNamesStatics,
    WSCCIAsymmetricAlgorithmNamesStatics, WSCCIKeyDerivationAlgorithmNamesStatics;

// Windows.Security.Cryptography.Core.CryptographicPrivateKeyBlobType
enum _WSCCCryptographicPrivateKeyBlobType {
    WSCCCryptographicPrivateKeyBlobTypePkcs8RawPrivateKeyInfo = 0,
    WSCCCryptographicPrivateKeyBlobTypePkcs1RsaPrivateKey = 1,
    WSCCCryptographicPrivateKeyBlobTypeBCryptPrivateKey = 2,
    WSCCCryptographicPrivateKeyBlobTypeCapi1PrivateKey = 3,
};
typedef unsigned WSCCCryptographicPrivateKeyBlobType;

// Windows.Security.Cryptography.Core.CryptographicPublicKeyBlobType
enum _WSCCCryptographicPublicKeyBlobType {
    WSCCCryptographicPublicKeyBlobTypeX509SubjectPublicKeyInfo = 0,
    WSCCCryptographicPublicKeyBlobTypePkcs1RsaPublicKey = 1,
    WSCCCryptographicPublicKeyBlobTypeBCryptPublicKey = 2,
    WSCCCryptographicPublicKeyBlobTypeCapi1PublicKey = 3,
};
typedef unsigned WSCCCryptographicPublicKeyBlobType;

// Windows.Security.Cryptography.Core.CryptographicPadding
enum _WSCCCryptographicPadding {
    WSCCCryptographicPaddingNone = 0,
    WSCCCryptographicPaddingRsaOaep = 1,
    WSCCCryptographicPaddingRsaPkcs1V15 = 2,
    WSCCCryptographicPaddingRsaPss = 3,
};
typedef unsigned WSCCCryptographicPadding;

#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsSecurityCryptographyCertificates.h"

// Windows.Security.Cryptography.Core.KeyDerivationParameters
#ifndef __WSCCKeyDerivationParameters_DEFINED__
#define __WSCCKeyDerivationParameters_DEFINED__

WINRT_EXPORT
@interface WSCCKeyDerivationParameters : RTObject
+ (WSCCKeyDerivationParameters*)buildForPbkdf2:(RTObject<WSSIBuffer>*)pbkdf2Salt iterationCount:(unsigned)iterationCount;
+ (WSCCKeyDerivationParameters*)buildForSP800108:(RTObject<WSSIBuffer>*)label context:(RTObject<WSSIBuffer>*)context;
+ (WSCCKeyDerivationParameters*)buildForSP80056a:(RTObject<WSSIBuffer>*)algorithmId
                                      partyUInfo:(RTObject<WSSIBuffer>*)partyUInfo
                                      partyVInfo:(RTObject<WSSIBuffer>*)partyVInfo
                                     suppPubInfo:(RTObject<WSSIBuffer>*)suppPubInfo
                                    suppPrivInfo:(RTObject<WSSIBuffer>*)suppPrivInfo;
@property (copy) RTObject<WSSIBuffer>* kdfGenericBinary;
@property (readonly) unsigned iterationCount;
@end

#endif // __WSCCKeyDerivationParameters_DEFINED__

// Windows.Security.Cryptography.Core.CryptographicKey
#ifndef __WSCCCryptographicKey_DEFINED__
#define __WSCCCryptographicKey_DEFINED__

WINRT_EXPORT
@interface WSCCCryptographicKey : RTObject
@property (readonly) unsigned keySize;
- (RTObject<WSSIBuffer>*)exportDefaultPrivateKeyBlobType;
- (RTObject<WSSIBuffer>*)exportPrivateKeyWithBlobType:(WSCCCryptographicPrivateKeyBlobType)BlobType;
- (RTObject<WSSIBuffer>*)exportDefaultPublicKeyBlobType;
- (RTObject<WSSIBuffer>*)exportPublicKeyWithBlobType:(WSCCCryptographicPublicKeyBlobType)BlobType;
@end

#endif // __WSCCCryptographicKey_DEFINED__

// Windows.Security.Cryptography.Core.CryptographicHash
#ifndef __WSCCCryptographicHash_DEFINED__
#define __WSCCCryptographicHash_DEFINED__

WINRT_EXPORT
@interface WSCCCryptographicHash : RTObject
- (void)append:(RTObject<WSSIBuffer>*)data;
- (RTObject<WSSIBuffer>*)getValueAndReset;
@end

#endif // __WSCCCryptographicHash_DEFINED__

// Windows.Security.Cryptography.Core.PersistedKeyProvider
#ifndef __WSCCPersistedKeyProvider_DEFINED__
#define __WSCCPersistedKeyProvider_DEFINED__

WINRT_EXPORT
@interface WSCCPersistedKeyProvider : RTObject
+ (void)openKeyPairFromCertificateAsync:(WSCCCertificate*)certificate
                      hashAlgorithmName:(NSString*)hashAlgorithmName
                                padding:(WSCCCryptographicPadding)padding
                                success:(void (^)(WSCCCryptographicKey*))success
                                failure:(void (^)(NSError*))failure;
+ (WSCCCryptographicKey*)openPublicKeyFromCertificate:(WSCCCertificate*)certificate
                                    hashAlgorithmName:(NSString*)hashAlgorithmName
                                              padding:(WSCCCryptographicPadding)padding;
@end

#endif // __WSCCPersistedKeyProvider_DEFINED__

// Windows.Security.Cryptography.Core.EncryptedAndAuthenticatedData
#ifndef __WSCCEncryptedAndAuthenticatedData_DEFINED__
#define __WSCCEncryptedAndAuthenticatedData_DEFINED__

WINRT_EXPORT
@interface WSCCEncryptedAndAuthenticatedData : RTObject
@property (readonly) RTObject<WSSIBuffer>* authenticationTag;
@property (readonly) RTObject<WSSIBuffer>* encryptedData;
@end

#endif // __WSCCEncryptedAndAuthenticatedData_DEFINED__

// Windows.Security.Cryptography.Core.CryptographicEngine
#ifndef __WSCCCryptographicEngine_DEFINED__
#define __WSCCCryptographicEngine_DEFINED__

WINRT_EXPORT
@interface WSCCCryptographicEngine : RTObject
+ (RTObject<WSSIBuffer>*)encrypt:(WSCCCryptographicKey*)key data:(RTObject<WSSIBuffer>*)data iv:(RTObject<WSSIBuffer>*)iv;
+ (RTObject<WSSIBuffer>*)decrypt:(WSCCCryptographicKey*)key data:(RTObject<WSSIBuffer>*)data iv:(RTObject<WSSIBuffer>*)iv;
+ (WSCCEncryptedAndAuthenticatedData*)encryptAndAuthenticate:(WSCCCryptographicKey*)key
                                                        data:(RTObject<WSSIBuffer>*)data
                                                       nonce:(RTObject<WSSIBuffer>*)nonce
                                           authenticatedData:(RTObject<WSSIBuffer>*)authenticatedData;
+ (RTObject<WSSIBuffer>*)decryptAndAuthenticate:(WSCCCryptographicKey*)key
                                           data:(RTObject<WSSIBuffer>*)data
                                          nonce:(RTObject<WSSIBuffer>*)nonce
                              authenticationTag:(RTObject<WSSIBuffer>*)authenticationTag
                              authenticatedData:(RTObject<WSSIBuffer>*)authenticatedData;
+ (RTObject<WSSIBuffer>*)sign:(WSCCCryptographicKey*)key data:(RTObject<WSSIBuffer>*)data;
+ (BOOL)verifySignature:(WSCCCryptographicKey*)key data:(RTObject<WSSIBuffer>*)data signature:(RTObject<WSSIBuffer>*)signature;
+ (RTObject<WSSIBuffer>*)deriveKeyMaterial:(WSCCCryptographicKey*)key
                                parameters:(WSCCKeyDerivationParameters*)parameters
                            desiredKeySize:(unsigned)desiredKeySize;
+ (RTObject<WSSIBuffer>*)signHashedData:(WSCCCryptographicKey*)key data:(RTObject<WSSIBuffer>*)data;
+ (BOOL)verifySignatureWithHashInput:(WSCCCryptographicKey*)key data:(RTObject<WSSIBuffer>*)data signature:(RTObject<WSSIBuffer>*)signature;
+ (void)decryptAsync:(WSCCCryptographicKey*)key
                data:(RTObject<WSSIBuffer>*)data
                  iv:(RTObject<WSSIBuffer>*)iv
             success:(void (^)(RTObject<WSSIBuffer>*))success
             failure:(void (^)(NSError*))failure;
+ (void)signAsync:(WSCCCryptographicKey*)key
             data:(RTObject<WSSIBuffer>*)data
          success:(void (^)(RTObject<WSSIBuffer>*))success
          failure:(void (^)(NSError*))failure;
+ (void)signHashedDataAsync:(WSCCCryptographicKey*)key
                       data:(RTObject<WSSIBuffer>*)data
                    success:(void (^)(RTObject<WSSIBuffer>*))success
                    failure:(void (^)(NSError*))failure;
@end

#endif // __WSCCCryptographicEngine_DEFINED__

// Windows.Security.Cryptography.Core.HashAlgorithmProvider
#ifndef __WSCCHashAlgorithmProvider_DEFINED__
#define __WSCCHashAlgorithmProvider_DEFINED__

WINRT_EXPORT
@interface WSCCHashAlgorithmProvider : RTObject
+ (WSCCHashAlgorithmProvider*)openAlgorithm:(NSString*)algorithm;
@property (readonly) NSString* algorithmName;
@property (readonly) unsigned hashLength;
- (RTObject<WSSIBuffer>*)hashData:(RTObject<WSSIBuffer>*)data;
- (WSCCCryptographicHash*)createHash;
@end

#endif // __WSCCHashAlgorithmProvider_DEFINED__

// Windows.Security.Cryptography.Core.MacAlgorithmProvider
#ifndef __WSCCMacAlgorithmProvider_DEFINED__
#define __WSCCMacAlgorithmProvider_DEFINED__

WINRT_EXPORT
@interface WSCCMacAlgorithmProvider : RTObject
+ (WSCCMacAlgorithmProvider*)openAlgorithm:(NSString*)algorithm;
@property (readonly) NSString* algorithmName;
@property (readonly) unsigned macLength;
- (WSCCCryptographicKey*)createKey:(RTObject<WSSIBuffer>*)keyMaterial;
- (WSCCCryptographicHash*)createHash:(RTObject<WSSIBuffer>*)keyMaterial;
@end

#endif // __WSCCMacAlgorithmProvider_DEFINED__

// Windows.Security.Cryptography.Core.KeyDerivationAlgorithmProvider
#ifndef __WSCCKeyDerivationAlgorithmProvider_DEFINED__
#define __WSCCKeyDerivationAlgorithmProvider_DEFINED__

WINRT_EXPORT
@interface WSCCKeyDerivationAlgorithmProvider : RTObject
+ (WSCCKeyDerivationAlgorithmProvider*)openAlgorithm:(NSString*)algorithm;
@property (readonly) NSString* algorithmName;
- (WSCCCryptographicKey*)createKey:(RTObject<WSSIBuffer>*)keyMaterial;
@end

#endif // __WSCCKeyDerivationAlgorithmProvider_DEFINED__

// Windows.Security.Cryptography.Core.SymmetricKeyAlgorithmProvider
#ifndef __WSCCSymmetricKeyAlgorithmProvider_DEFINED__
#define __WSCCSymmetricKeyAlgorithmProvider_DEFINED__

WINRT_EXPORT
@interface WSCCSymmetricKeyAlgorithmProvider : RTObject
+ (WSCCSymmetricKeyAlgorithmProvider*)openAlgorithm:(NSString*)algorithm;
@property (readonly) NSString* algorithmName;
@property (readonly) unsigned blockLength;
- (WSCCCryptographicKey*)createSymmetricKey:(RTObject<WSSIBuffer>*)keyMaterial;
@end

#endif // __WSCCSymmetricKeyAlgorithmProvider_DEFINED__

// Windows.Security.Cryptography.Core.AsymmetricKeyAlgorithmProvider
#ifndef __WSCCAsymmetricKeyAlgorithmProvider_DEFINED__
#define __WSCCAsymmetricKeyAlgorithmProvider_DEFINED__

WINRT_EXPORT
@interface WSCCAsymmetricKeyAlgorithmProvider : RTObject
+ (WSCCAsymmetricKeyAlgorithmProvider*)openAlgorithm:(NSString*)algorithm;
@property (readonly) NSString* algorithmName;
- (WSCCCryptographicKey*)createKeyPair:(unsigned)keySize;
- (WSCCCryptographicKey*)importDefaultPrivateKeyBlob:(RTObject<WSSIBuffer>*)keyBlob;
- (WSCCCryptographicKey*)importKeyPairWithBlobType:(RTObject<WSSIBuffer>*)keyBlob BlobType:(WSCCCryptographicPrivateKeyBlobType)BlobType;
- (WSCCCryptographicKey*)importDefaultPublicKeyBlob:(RTObject<WSSIBuffer>*)keyBlob;
- (WSCCCryptographicKey*)importPublicKeyWithBlobType:(RTObject<WSSIBuffer>*)keyBlob BlobType:(WSCCCryptographicPublicKeyBlobType)BlobType;
@end

#endif // __WSCCAsymmetricKeyAlgorithmProvider_DEFINED__

// Windows.Security.Cryptography.Core.HashAlgorithmNames
#ifndef __WSCCHashAlgorithmNames_DEFINED__
#define __WSCCHashAlgorithmNames_DEFINED__

WINRT_EXPORT
@interface WSCCHashAlgorithmNames : RTObject
+ (NSString*)md5;
+ (NSString*)sha1;
+ (NSString*)sha256;
+ (NSString*)sha384;
+ (NSString*)sha512;
@end

#endif // __WSCCHashAlgorithmNames_DEFINED__

// Windows.Security.Cryptography.Core.MacAlgorithmNames
#ifndef __WSCCMacAlgorithmNames_DEFINED__
#define __WSCCMacAlgorithmNames_DEFINED__

WINRT_EXPORT
@interface WSCCMacAlgorithmNames : RTObject
+ (NSString*)aesCmac;
+ (NSString*)hmacMd5;
+ (NSString*)hmacSha1;
+ (NSString*)hmacSha256;
+ (NSString*)hmacSha384;
+ (NSString*)hmacSha512;
@end

#endif // __WSCCMacAlgorithmNames_DEFINED__

// Windows.Security.Cryptography.Core.SymmetricAlgorithmNames
#ifndef __WSCCSymmetricAlgorithmNames_DEFINED__
#define __WSCCSymmetricAlgorithmNames_DEFINED__

WINRT_EXPORT
@interface WSCCSymmetricAlgorithmNames : RTObject
+ (NSString*)aesCbc;
+ (NSString*)aesCbcPkcs7;
+ (NSString*)aesCcm;
+ (NSString*)aesEcb;
+ (NSString*)aesEcbPkcs7;
+ (NSString*)aesGcm;
+ (NSString*)desCbc;
+ (NSString*)desCbcPkcs7;
+ (NSString*)desEcb;
+ (NSString*)desEcbPkcs7;
+ (NSString*)rc2Cbc;
+ (NSString*)rc2CbcPkcs7;
+ (NSString*)rc2Ecb;
+ (NSString*)rc2EcbPkcs7;
+ (NSString*)rc4;
+ (NSString*)tripleDesCbc;
+ (NSString*)tripleDesCbcPkcs7;
+ (NSString*)tripleDesEcb;
+ (NSString*)tripleDesEcbPkcs7;
@end

#endif // __WSCCSymmetricAlgorithmNames_DEFINED__

// Windows.Security.Cryptography.Core.AsymmetricAlgorithmNames
#ifndef __WSCCAsymmetricAlgorithmNames_DEFINED__
#define __WSCCAsymmetricAlgorithmNames_DEFINED__

WINRT_EXPORT
@interface WSCCAsymmetricAlgorithmNames : RTObject
+ (NSString*)dsaSha1;
+ (NSString*)rsaSignPssSha512;
+ (NSString*)dsaSha256;
+ (NSString*)ecdsaP256Sha256;
+ (NSString*)ecdsaP384Sha384;
+ (NSString*)ecdsaP521Sha512;
+ (NSString*)rsaOaepSha1;
+ (NSString*)rsaOaepSha256;
+ (NSString*)rsaOaepSha384;
+ (NSString*)rsaOaepSha512;
+ (NSString*)rsaPkcs1;
+ (NSString*)rsaSignPkcs1Sha1;
+ (NSString*)rsaSignPkcs1Sha256;
+ (NSString*)rsaSignPkcs1Sha384;
+ (NSString*)rsaSignPkcs1Sha512;
+ (NSString*)rsaSignPssSha1;
+ (NSString*)rsaSignPssSha256;
+ (NSString*)rsaSignPssSha384;
@end

#endif // __WSCCAsymmetricAlgorithmNames_DEFINED__

// Windows.Security.Cryptography.Core.KeyDerivationAlgorithmNames
#ifndef __WSCCKeyDerivationAlgorithmNames_DEFINED__
#define __WSCCKeyDerivationAlgorithmNames_DEFINED__

WINRT_EXPORT
@interface WSCCKeyDerivationAlgorithmNames : RTObject
+ (NSString*)pbkdf2Md5;
+ (NSString*)pbkdf2Sha1;
+ (NSString*)pbkdf2Sha256;
+ (NSString*)pbkdf2Sha384;
+ (NSString*)pbkdf2Sha512;
+ (NSString*)sp800108CtrHmacMd5;
+ (NSString*)sp800108CtrHmacSha1;
+ (NSString*)sp800108CtrHmacSha256;
+ (NSString*)sp800108CtrHmacSha384;
+ (NSString*)sp800108CtrHmacSha512;
+ (NSString*)sp80056aConcatMd5;
+ (NSString*)sp80056aConcatSha1;
+ (NSString*)sp80056aConcatSha256;
+ (NSString*)sp80056aConcatSha384;
+ (NSString*)sp80056aConcatSha512;
@end

#endif // __WSCCKeyDerivationAlgorithmNames_DEFINED__
