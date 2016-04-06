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

// This header file is not yet implemented
#include <stdint.h>
#include <StubIncludes.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
    kCCBlockSizeAES128        = 16,
    kCCBlockSizeDES           = 8,
    kCCBlockSize3DES          = 8,
    kCCBlockSizeCAST          = 8,
    kCCBlockSizeRC2           = 8,
    kCCBlockSizeBlowfish      = 8,
};

enum {
    kCCKeySizeAES128          = 16,
    kCCKeySizeAES192          = 24,
    kCCKeySizeAES256          = 32,
    kCCKeySizeDES             = 8,
    kCCKeySize3DES            = 24,
    kCCKeySizeMinCAST         = 5,
    kCCKeySizeMaxCAST         = 16,
    kCCKeySizeMinRC4          = 1,
    kCCKeySizeMaxRC4          = 512,
    kCCKeySizeMinRC2          = 1,
    kCCKeySizeMaxRC2          = 128,
    kCCKeySizeMinBlowfish     = 8,
    kCCKeySizeMaxBlowfish     = 56,
};

enum {
    kCCContextSizeAES128	= 404,
    kCCContextSizeDES		= 240,
    kCCContextSize3DES		= 496,
    kCCContextSizeCAST		= 240,
    kCCContextSizeRC4		= 1072
};

#define CC_SHA256_DIGEST_LENGTH 32

void CCHmac(uint32_t alg, uint8_t* key, uint32_t keylength, uint8_t* msg, int msglength, void* out) STUB_METHOD;

enum {
    kCCAlgorithmAES128 = 0,
    kCCAlgorithmDES,
    kCCAlgorithm3DES,
    kCCAlgorithmCAST,
    kCCAlgorithmRC4,
    kCCAlgorithmRC2,
    kCCAlgorithmBlowfish
};

enum {
    kCCHmacAlgSHA1,
    kCCHmacAlgMD5,
    kCCHmacAlgSHA256,
    kCCHmacAlgSHA384,
    kCCHmacAlgSHA512,
    kCCHmacAlgSHA224,
};

typedef int32_t CCCryptorStatus;

enum {
    kCCSuccess = 0,
};

typedef struct _CCCryptor* CCCryptorRef;

enum {
    kCCEncrypt = 0,
    kCCDecrypt,
};

int32_t CCCrypt(uint32_t op, /* kCCEncrypt, etc. */
                uint32_t alg, /* kCCAlgorithmAES128, etc. */
                uint32_t options, /* kCCOptionPKCS7Padding, etc. */
                const void* key,
                size_t keyLength,
                const void* iv, /* optional initialization vector */
                const void* dataIn, /* optional per op and alg */
                size_t dataInLength,
                void* dataOut, /* data RETURNED here */
                size_t dataOutAvailable,
                size_t* dataOutMoved) STUB_METHOD;

#ifdef __cplusplus
}
#endif
