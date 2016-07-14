//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#include <StarboardExport.h>
#include <stdint.h>
#include <stdbool.h>
#include <StubIncludes.h>

#define CC_MD2_DIGEST_LENGTH 16
#define CC_MD4_DIGEST_LENGTH 16
#define CC_MD5_DIGEST_LENGTH 16
#define CC_SHA1_DIGEST_LENGTH 20
#define CC_SHA224_DIGEST_LENGTH 28
#define CC_SHA256_DIGEST_LENGTH 32
#define CC_SHA384_DIGEST_LENGTH 48
#define CC_SHA512_DIGEST_LENGTH 64

enum {
    kCCBlockSizeAES128 = 16,
    kCCBlockSizeDES = 8,
    kCCBlockSize3DES = 8,
    kCCBlockSizeCAST = 8,
    kCCBlockSizeRC2 = 8,
    kCCBlockSizeBlowfish = 8,
};

enum {
    kCCKeySizeAES128 = 16,
    kCCKeySizeAES192 = 24,
    kCCKeySizeAES256 = 32,
    kCCKeySizeDES = 8,
    kCCKeySize3DES = 24,
    kCCKeySizeMinCAST = 5,
    kCCKeySizeMaxCAST = 16,
    kCCKeySizeMinRC4 = 1,
    kCCKeySizeMaxRC4 = 512,
    kCCKeySizeMinRC2 = 2, // Note: Differs from reference platform (normally 1)
    kCCKeySizeMaxRC2 = 128,
    kCCKeySizeMinBlowfish = 8,
    kCCKeySizeMaxBlowfish = 56
};

enum {
    kCCAlgorithmAES128 = 0,
    kCCAlgorithmAES = 0,
    kCCAlgorithmDES,
    kCCAlgorithm3DES,
    kCCAlgorithmCAST,
    kCCAlgorithmRC4,
    kCCAlgorithmRC2,
    kCCAlgorithmBlowfish
};

typedef int32_t CCAlgorithm;

enum { kCCSuccess = 0, kCCParamError, kCCBufferTooSmall, kCCMemoryFailure, kCCAlignmentError, kCCDecodeError, kCCUnimplemented };

typedef int32_t CCCryptorStatus;

enum {
    kCCEncrypt = 0,
    kCCDecrypt,
};

typedef int32_t CCOperation;

enum { kCCOptionPKCS7Padding = 1, kCCOptionECBMode = 2 };

typedef int32_t CCOptions;

struct CC_Cryptor_State;
typedef struct CC_Cryptor_State* CCCryptorRef;

SB_EXTERNC_BEGIN

SB_IMPEXP CCCryptorStatus CCCryptorCreate(
    CCOperation op, CCAlgorithm alg, CCOptions options, const void* key, size_t keyLength, const void* iv, CCCryptorRef* cryptorRef);

SB_IMPEXP CCCryptorStatus CCCryptorCreateFromData(CCOperation op,
                                                  CCAlgorithm alg,
                                                  CCOptions options,
                                                  const void* key,
                                                  size_t keyLength,
                                                  const void* iv,
                                                  const void* data,
                                                  size_t dataLength,
                                                  CCCryptorRef* cryptorRef,
                                                  size_t* dataUsed);

SB_IMPEXP CCCryptorStatus CCCryptorRelease(CCCryptorRef cryptorRef);

SB_IMPEXP CCCryptorStatus CCCryptorUpdate(
    CCCryptorRef cryptorRef, const void* dataIn, size_t dataInLength, void* dataOut, size_t dataOutAvailable, size_t* dataOutMoved);

SB_IMPEXP CCCryptorStatus CCCryptorFinal(CCCryptorRef cryptorRef, void* dataOut, size_t dataOutAvailable, size_t* dataOutMoved);

SB_IMPEXP size_t CCCryptorGetOutputLength(CCCryptorRef cryptorRef, size_t inputLength, bool final);

SB_IMPEXP CCCryptorStatus CCCryptorReset(CCCryptorRef cryptorRef, const void* iv);

SB_IMPEXP CCCryptorStatus CCCrypt(CCOperation op,
                                  CCAlgorithm alg,
                                  CCOptions options,
                                  const void* key,
                                  size_t keyLength,
                                  const void* iv,
                                  const void* dataIn,
                                  size_t dataInLength,
                                  void* dataOut,
                                  size_t dataOutAvailable,
                                  size_t* dataOutMoved);

SB_EXTERNC_END
