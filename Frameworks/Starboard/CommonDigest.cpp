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
#include <wil\Result.h>
#include <assert.h>

struct CC_MD5_State {
    CC_MD5_State() : _hAlg(INVALID_HANDLE_VALUE), _hHash(INVALID_HANDLE_VALUE), _pHashObject(nullptr) {
        _init();
    }

    ~CC_MD5_State() {
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

    bool isValid() const {
        return _hHash != INVALID_HANDLE_VALUE;
    }

    int hashData(const BYTE* data, CC_LONG length) {
        NTSTATUS status = BCryptHashData(_hHash, const_cast<BYTE*>(data), length, 0);
        if (SUCCEEDED_NTSTATUS(status)) {
            return 1;
        }

        LOG_NTSTATUS_MSG(status, "BCryptHashData failed\n");
        return -1;
    }

    void finishHash(BYTE* digest) {
        LOG_IF_NTSTATUS_FAILED(BCryptFinishHash(_hHash, digest, CC_MD5_DIGEST_LENGTH, 0));
    }

private:
    NTSTATUS _init() {
        DWORD cbHashObject;
        DWORD cbResult;

        RETURN_IF_NTSTATUS_FAILED_LOG(BCryptOpenAlgorithmProvider(&_hAlg, BCRYPT_MD5_ALGORITHM, NULL, 0));
        RETURN_IF_NTSTATUS_FAILED_LOG(
            BCryptGetProperty(_hAlg, BCRYPT_OBJECT_LENGTH, reinterpret_cast<PBYTE>(&cbHashObject), sizeof(DWORD), &cbResult, 0));

        _pHashObject = new BYTE[cbHashObject];
        if (_pHashObject == nullptr) {
            RETURN_IF_NTSTATUS_FAILED_MSG(STATUS_NO_MEMORY, "CC_MD5_State Unable to allocate Hash object");
        }

        RETURN_IF_NTSTATUS_FAILED_LOG(BCryptCreateHash(_hAlg, &_hHash, _pHashObject, cbHashObject, NULL, 0, 0));

        return 0;
    }

    BCRYPT_ALG_HANDLE _hAlg;
    BCRYPT_HASH_HANDLE _hHash;
    PBYTE _pHashObject;
};

static inline CC_MD5_State* _getState(CC_MD5_CTX* ctx) {
    return ctx ? *ctx : nullptr;
}

/**
@Status Interoperable
*/
extern "C" int CC_MD5_Init(CC_MD5_CTX* ctx) {
    if (!ctx) {
        return -1;
    }
    *ctx = nullptr;

    CC_MD5_State* state = new CC_MD5_State();
    if (!state) {
        return -1;
    }

    if (!state->isValid()) {
        delete state;
        return -1;
    }

    *ctx = state;
    return 1;
}

/**
@Status Interoperable
*/
extern "C" int CC_MD5_Update(CC_MD5_CTX* ctx, const void* data, unsigned int len) {
    CC_MD5_State* state = _getState(ctx);
    if (!state) {
        return -1;
    }

    // at this point, state has to be either NULL or valid
    assert(state->isValid());

    return state->hashData(reinterpret_cast<const BYTE*>(data), len);
}

/**
@Status Interoperable
*/
extern "C" int CC_MD5_Final(unsigned char* digest, CC_MD5_CTX* ctx) {
    CC_MD5_State* state = _getState(ctx);
    *ctx = nullptr;
    if (!state) {
        return -1;
    }

    // at this point, state has to be either NULL or valid
    assert(state->isValid());

    state->finishHash(digest);
    delete state;

    return 1;
}

/**
@Status Interoperable
*/
extern "C" unsigned char* CC_MD5(const void* input, CC_LONG length, unsigned char* digest) {
    CC_MD5_CTX ctx;

    if ((CC_MD5_Init(&ctx) < 0) || (CC_MD5_Update(&ctx, input, length)) < 0 || (CC_MD5_Final(digest, &ctx)) < 0) {
        return nullptr;
    }

    return digest;
}
