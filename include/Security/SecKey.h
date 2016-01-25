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
#pragma once

#import <CoreFoundation/CFDate.h>
#import <CoreFoundation/CFDictionary.h>
#import <Security/SecBase.h>

// This header file is not yet fully implemented

typedef struct __SecKey* SecKeyRef;

typedef enum SecPadding : uint32_t SecPadding;
enum SecPadding : uint32_t {
    kSecPaddingNone = 0,
    kSecPaddingPKCS1 = 1,
    kSecPaddingPKCS1MD2 = 0x8000,
    kSecPaddingPKCS1MD5 = 0x8001,
    kSecPaddingPKCS1SHA1 = 0x8002,
};

SECURITY_EXPORT const CFTypeRef kSecPrivateKeyAttrs;
SECURITY_EXPORT const CFTypeRef kSecPublicKeyAttrs;

SECURITY_EXPORT CFTypeID SecKeyGetTypeID(void) STUB_METHOD;
SECURITY_EXPORT OSStatus SecKeyGeneratePair(CFDictionaryRef parameters, SecKeyRef* publicKey, SecKeyRef* privateKey) STUB_METHOD;
SECURITY_EXPORT OSStatus SecKeyEncrypt(SecKeyRef key,
                                       SecPadding padding,
                                       const uint8_t* plainText,
                                       size_t plainTextLen,
                                       uint8_t* cipherText,
                                       size_t* cipherTextLen) STUB_METHOD;
SECURITY_EXPORT OSStatus SecKeyDecrypt(SecKeyRef key,
                                       SecPadding padding,
                                       const uint8_t* cipherText,
                                       size_t cipherTextLen,
                                       uint8_t* plainText,
                                       size_t* plainTextLen) STUB_METHOD;
SECURITY_EXPORT OSStatus
SecKeyRawSign(SecKeyRef key, SecPadding padding, const uint8_t* dataToSign, size_t dataToSignLen, uint8_t* sig, size_t* sigLen) STUB_METHOD;
SECURITY_EXPORT OSStatus SecKeyRawVerify(
    SecKeyRef key, SecPadding padding, const uint8_t* signedData, size_t signedDataLen, const uint8_t* sig, size_t sigLen) STUB_METHOD;
SECURITY_EXPORT size_t SecKeyGetBlockSize(SecKeyRef key) STUB_METHOD;