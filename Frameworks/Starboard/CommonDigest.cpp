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

#include <Windows.h>
#include <bcrypt.h>
#include <CommonCrypto\CommonDigest.h>
#include <CommonCrypto\CommonCryptor.h>
#include <ErrorHandling.h>
#include <assert.h>
#include <StubReturn.h>

struct CC_Digest_State {
    CC_Digest_State(const unsigned int digestLength, const LPCWSTR algorithm) :
        _hAlg(INVALID_HANDLE_VALUE),
        _hHash(INVALID_HANDLE_VALUE),
        _pHashObject(nullptr),
        _algorithm(algorithm),
        _digestLength(digestLength) {
        _init();
    }

    ~CC_Digest_State() {
        if (_hAlg != INVALID_HANDLE_VALUE) {
            BCryptCloseAlgorithmProvider(_hAlg, 0);
            _hAlg = INVALID_HANDLE_VALUE;
        }
        if (_hHash != INVALID_HANDLE_VALUE) {
            BCryptDestroyHash(_hHash);
            _hHash = INVALID_HANDLE_VALUE;
        }
        delete[] _pHashObject;
        _pHashObject = nullptr;
    }

    static int init(CC_Digest_State** ctx, unsigned int digestLength, LPCWSTR algorithm) {
        if (!ctx) {
            return -1;
        }

        *ctx = nullptr;

        CC_Digest_State* state = new CC_Digest_State(digestLength, algorithm);
        if (!_isValidState(state)) {
            return -1;
        }

        *ctx = state;
        return 1;
    }

    // internal implemention of update for all hash contexts
    static int update(CC_Digest_State** ctx, const void* data, CC_LONG len) {
        CC_Digest_State* state = ctx ? *ctx : nullptr;
        if (!_isValidState(state)) {
            *ctx = nullptr;
            return -1;
        }

        return state->_hashData(reinterpret_cast<const BYTE*>(data), len);
    }

    // internal implementaion of final for all hash contexts
    static int final(unsigned char* digest, CC_Digest_State** ctx) {
        CC_Digest_State* state = ctx ? *ctx : nullptr;
        if (!_isValidState(state)) {
            *ctx = nullptr;
            return -1;
        }

        state->_finishHash(digest);
        delete state;

        return 1;
    }

    // internal implementation of the one shot methods for all hash contexts
    static unsigned char* oneShotDigest(int(*init)(CC_Digest_State**),
        int(*update)(CC_Digest_State** ctx, const void* data, CC_LONG len),
        int(*final)(unsigned char* digest, CC_Digest_State** ctx),
        const void* input,
        CC_LONG length,
        unsigned char* digest) {
        CC_Digest_State* ctx;

        if (init(&ctx) < 0) {
            return nullptr;
        }

        int updateResult = update(&ctx, input, length);

        // Final should be called even if update fails.
        if (final(digest, &ctx) < 0) {
            return nullptr;
        }

        if (updateResult < 0) {
            return nullptr;
        }

        return digest;
    }

private:
    NTSTATUS _init() {
        DWORD cbHashObject;
        DWORD cbResult;

        RETURN_IF_NTSTATUS_FAILED_LOG(BCryptOpenAlgorithmProvider(&_hAlg, _algorithm, NULL, 0));
        RETURN_IF_NTSTATUS_FAILED_LOG(
            BCryptGetProperty(_hAlg, BCRYPT_OBJECT_LENGTH, reinterpret_cast<PBYTE>(&cbHashObject), sizeof(DWORD), &cbResult, 0));

        _pHashObject = new BYTE[cbHashObject];
        if (_pHashObject == nullptr) {
            RETURN_IF_NTSTATUS_FAILED_MSG(STATUS_NO_MEMORY, "CC_Digest_State Unable to allocate Hash object");
        }

        RETURN_IF_NTSTATUS_FAILED_LOG(BCryptCreateHash(_hAlg, &_hHash, _pHashObject, cbHashObject, NULL, 0, 0));

        return 0;
    }

    static bool _isValidState(CC_Digest_State* state) {
        if (!state) {
            return false;
        }

        // at this point, state has to be either NULL or valid
        if (state->_hHash == INVALID_HANDLE_VALUE) {
            delete state;
            return false;
        }

        return true;
    }

    int _hashData(const BYTE* data, CC_LONG length) {
        NTSTATUS status = BCryptHashData(_hHash, const_cast<BYTE*>(data), length, 0);
        if (SUCCEEDED_NTSTATUS(status)) {
            return 1;
        }

        LOG_NTSTATUS_MSG(status, "BCryptHashData failed\n");
        return -1;
    }

    void _finishHash(BYTE* digest) {
        LOG_IF_NTSTATUS_FAILED(BCryptFinishHash(_hHash, digest, _digestLength, 0));
    }

    const unsigned int _digestLength;
    const LPCWSTR _algorithm;
    BCRYPT_ALG_HANDLE _hAlg;
    BCRYPT_HASH_HANDLE _hHash;
    PBYTE _pHashObject;
};

/**
@Status Interoperable
*/
extern "C" int CC_MD2_Init(CC_MD2_CTX* ctx) {
    return CC_Digest_State::init(ctx, CC_MD2_DIGEST_LENGTH, BCRYPT_MD2_ALGORITHM);
}

/**
@Status Interoperable
*/
extern "C" int CC_MD2_Update(CC_MD2_CTX* ctx, const void* data, CC_LONG len) {
    return CC_Digest_State::update(ctx, data, len);
}

/**
@Status Interoperable
*/
extern "C" int CC_MD2_Final(unsigned char* digest, CC_MD2_CTX* ctx) {
    return CC_Digest_State::final(digest, ctx);
}

/**
@Status Interoperable
*/
extern "C" unsigned char* CC_MD2(const void* input, CC_LONG length, unsigned char* digest) {
    return CC_Digest_State::oneShotDigest(CC_MD2_Init, CC_MD2_Update, CC_MD2_Final, input, length, digest);
}

/**
@Status Interoperable
*/
extern "C" int CC_MD4_Init(CC_MD4_CTX* ctx) {
    return CC_Digest_State::init(ctx, CC_MD4_DIGEST_LENGTH, BCRYPT_MD4_ALGORITHM);
}

/**
@Status Interoperable
*/
extern "C" int CC_MD4_Update(CC_MD4_CTX* ctx, const void* data, CC_LONG len) {
    return CC_Digest_State::update(ctx, data, len);
}

/**
@Status Interoperable
*/
extern "C" int CC_MD4_Final(unsigned char* digest, CC_MD4_CTX* ctx) {
    return CC_Digest_State::final(digest, ctx);
}

/**
@Status Interoperable
*/
extern "C" unsigned char* CC_MD4(const void* input, CC_LONG length, unsigned char* digest) {
    return CC_Digest_State::oneShotDigest(CC_MD4_Init, CC_MD4_Update, CC_MD4_Final, input, length, digest);
}

/**
@Status Interoperable
*/
extern "C" int CC_MD5_Init(CC_MD5_CTX* ctx) {
    return CC_Digest_State::init(ctx, CC_MD5_DIGEST_LENGTH, BCRYPT_MD5_ALGORITHM);
}

/**
@Status Interoperable
*/
extern "C" int CC_MD5_Update(CC_MD5_CTX* ctx, const void* data, CC_LONG len) {
    return CC_Digest_State::update(ctx, data, len);
}

/**
@Status Interoperable
*/
extern "C" int CC_MD5_Final(unsigned char* digest, CC_MD5_CTX* ctx) {
    return CC_Digest_State::final(digest, ctx);
}

/**
@Status Interoperable
*/
extern "C" unsigned char* CC_MD5(const void* input, CC_LONG length, unsigned char* digest) {
    return CC_Digest_State::oneShotDigest(CC_MD5_Init, CC_MD5_Update, CC_MD5_Final, input, length, digest);
}

/**
@Status Interoperable
*/
extern "C" int CC_SHA1_Init(CC_SHA1_CTX* ctx) {
    return CC_Digest_State::init(ctx, CC_SHA1_DIGEST_LENGTH, BCRYPT_SHA1_ALGORITHM);
}

/**
@Status Interoperable
*/
extern "C" int CC_SHA1_Update(CC_SHA1_CTX* ctx, const void* data, CC_LONG len) {
    return CC_Digest_State::update(ctx, data, len);
}

/**
@Status Interoperable
*/
extern "C" int CC_SHA1_Final(unsigned char* digest, CC_SHA1_CTX* ctx) {
    return CC_Digest_State::final(digest, ctx);
}

/**
@Status Interoperable
*/
extern "C" unsigned char* CC_SHA1(const void* input, CC_LONG length, unsigned char* digest) {
    return CC_Digest_State::oneShotDigest(CC_SHA1_Init, CC_SHA1_Update, CC_SHA1_Final, input, length, digest);
}

/**
@Status Stub
*/
extern "C" int CC_SHA224_Init(CC_SHA224_CTX* ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
*/
extern "C" int CC_SHA224_Update(CC_SHA224_CTX* ctx, const void* data, CC_LONG len) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
*/
extern "C" int CC_SHA224_Final(unsigned char* digest, CC_SHA224_CTX* ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
*/
extern "C" unsigned char* CC_SHA224(const void* input, CC_LONG length, unsigned char* digest) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Interoperable
*/
extern "C" int CC_SHA256_Init(CC_SHA256_CTX* ctx) {
    return CC_Digest_State::init(ctx, CC_SHA256_DIGEST_LENGTH, BCRYPT_SHA256_ALGORITHM);
}

/**
@Status Interoperable
*/
extern "C" int CC_SHA256_Update(CC_SHA256_CTX* ctx, const void* data, CC_LONG len) {
    return CC_Digest_State::update(ctx, data, len);
}

/**
@Status Interoperable
*/
extern "C" int CC_SHA256_Final(unsigned char* digest, CC_SHA256_CTX* ctx) {
    return CC_Digest_State::final(digest, ctx);
}

/**
@Status Interoperable
*/
extern "C" unsigned char* CC_SHA256(const void* input, CC_LONG length, unsigned char* digest) {
    return CC_Digest_State::oneShotDigest(CC_SHA256_Init, CC_SHA256_Update, CC_SHA256_Final, input, length, digest);
}

/**
@Status Interoperable
*/
extern "C" int CC_SHA384_Init(CC_SHA384_CTX* ctx) {
    return CC_Digest_State::init(ctx, CC_SHA384_DIGEST_LENGTH, BCRYPT_SHA384_ALGORITHM);
}

/**
@Status Interoperable
*/
extern "C" int CC_SHA384_Update(CC_SHA384_CTX* ctx, const void* data, CC_LONG len) {
    return CC_Digest_State::update(ctx, data, len);
}

/**
@Status Interoperable
*/
extern "C" int CC_SHA384_Final(unsigned char* digest, CC_SHA384_CTX* ctx) {
    return CC_Digest_State::final(digest, ctx);
}

/**
@Status Interoperable
*/
extern "C" unsigned char* CC_SHA384(const void* input, CC_LONG length, unsigned char* digest) {
    return CC_Digest_State::oneShotDigest(CC_SHA384_Init, CC_SHA384_Update, CC_SHA384_Final, input, length, digest);
}

/**
@Status Interoperable
*/
extern "C" int CC_SHA512_Init(CC_SHA512_CTX* ctx) {
    return CC_Digest_State::init(ctx, CC_SHA512_DIGEST_LENGTH, BCRYPT_SHA512_ALGORITHM);
}

/**
@Status Interoperable
*/
extern "C" int CC_SHA512_Update(CC_SHA512_CTX* ctx, const void* data, CC_LONG len) {
    return CC_Digest_State::update(ctx, data, len);
}

/**
@Status Interoperable
*/
extern "C" int CC_SHA512_Final(unsigned char* digest, CC_SHA512_CTX* ctx) {
    return CC_Digest_State::final(digest, ctx);
}

/**
@Status Interoperable
*/
extern "C" unsigned char* CC_SHA512(const void* input, CC_LONG length, unsigned char* digest) {
    return CC_Digest_State::oneShotDigest(CC_SHA512_Init, CC_SHA512_Update, CC_SHA512_Final, input, length, digest);
}
