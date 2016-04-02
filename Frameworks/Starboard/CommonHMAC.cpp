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
#include <CommonCrypto\CommonHMAC.h>
#include <CommonCrypto\CommonDigest.h>
#include <COMIncludes.h>
#include <wrl\wrappers\corewrappers.h>
#include <wrl\client.h>
#include <windows.security.cryptography.h>
#include <windows.storage.streams.h>
#include <COMIncludes_End.h>
#include <ErrorHandling.h>
#include <StubReturn.h>
#include <RawBuffer.h>

using namespace Microsoft::WRL;
using namespace ABI::Windows::Storage::Streams;
using namespace ABI::Windows::Security::Cryptography::Core;
using namespace Windows::Foundation;

struct CC_Hmac_State {
    CC_Hmac_State(CCHmacAlgorithm algorithm, const void* key, size_t keyLength) :
        _algorithm(algorithm),
        _key(key),
        _keyLength(keyLength),
        _isValid(true) {
        if (FAILED(_init())) {
            invalidate();
        }
    }

    ~CC_Hmac_State() {
    }

    static void init(CC_Hmac_State** ctx, CCHmacAlgorithm algorithm, const void* key, size_t keyLength) {
        if (!ctx) {
            LOG_HR(E_INVALIDARG);
            return;
        }

        *ctx = nullptr;

        CC_Hmac_State* state = new CC_Hmac_State(algorithm, key, keyLength);
        if (!_validState(&state)) {
            LOG_HR(E_UNEXPECTED);
            return;
        }

        *ctx = state;
        return;
    }

    static void update(CC_Hmac_State** ctx, const void* data, size_t len) {
        if (!_validState(ctx)) {
            LOG_HR(E_INVALIDARG);
            return;
        }

        if (FAILED((*ctx)->_update(data, len))) {
            delete *ctx;
            *ctx = nullptr;
        }
    }

    static void final(void* digest, CC_Hmac_State** ctx) {
       if (!_validState(ctx)) {
           LOG_HR(E_INVALIDARG);
           return;
       }

        if (FAILED((*ctx)->_finishHash(digest))) {
            LOG_HR(E_UNEXPECTED);
        }
        delete *ctx;
        *ctx = nullptr;
    }

    static void oneShot(CCHmacAlgorithm algorithm, const void* key, size_t keyLength, const void* data, size_t dataLength, void* macOut) {
        CC_Hmac_State* ctx;

        init(&ctx, algorithm, key, keyLength);

        update(&ctx, data, dataLength);

        final(macOut, &ctx);
    }

private:
    static bool _validState(CC_Hmac_State** ctx) {
        if (!ctx) {
            return false;
        }

        CC_Hmac_State* state = *ctx;
        if (!state) {
            return false;
        }

        if (!state->_isValid) {
            delete state;
            *ctx = nullptr;
            return false;
        }

        return true;
    }

    void invalidate() {
        _isValid = false;
    }

    HRESULT _init() {
        ComPtr<IMacAlgorithmProviderStatics> macAlgorithmProviderStatics;
        ComPtr<IMacAlgorithmNamesStatics> macAlgorithmNamesStatics;

        RETURN_IF_FAILED_LOG(
            GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Security_Cryptography_Core_MacAlgorithmProvider).Get(),
                 &macAlgorithmProviderStatics));

        RETURN_IF_FAILED_LOG(
            GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Security_Cryptography_Core_MacAlgorithmNames).Get(),
                &macAlgorithmNamesStatics));

        HSTRING name;

        switch (_algorithm) {
            case kCCHmacAlgSHA1:
                RETURN_IF_FAILED_LOG(macAlgorithmNamesStatics->get_HmacSha1(&name));
                _digestLength = CC_SHA1_DIGEST_LENGTH;
                break;
            case kCCHmacAlgMD5:
                RETURN_IF_FAILED_LOG(macAlgorithmNamesStatics->get_HmacMd5(&name));
                _digestLength = CC_MD5_DIGEST_LENGTH;
                break;
            case kCCHmacAlgSHA256:
                RETURN_IF_FAILED_LOG(macAlgorithmNamesStatics->get_HmacSha256(&name));
                _digestLength = CC_SHA256_DIGEST_LENGTH;
                break;
            case kCCHmacAlgSHA384:
                RETURN_IF_FAILED_LOG(macAlgorithmNamesStatics->get_HmacSha384(&name));
                _digestLength = CC_SHA384_DIGEST_LENGTH;
                break;
            case kCCHmacAlgSHA512:
                RETURN_IF_FAILED_LOG(macAlgorithmNamesStatics->get_HmacSha512(&name));
                _digestLength = CC_SHA512_DIGEST_LENGTH;
                break;
            case kCCHmacAlgSHA224:
            default:
                UNIMPLEMENTED_WITH_MSG("Requested HMAC algorithm is not supported");
                return E_NOTIMPL;
        }

        RETURN_IF_FAILED_LOG(macAlgorithmProviderStatics->OpenAlgorithm(name, &_macAlgorithmProvider));

        ComPtr<IBuffer> keyBuffer;
        RETURN_IF_FAILED_LOG(BufferFromRawData(&keyBuffer, (unsigned char*)_key, _keyLength));
        ComPtr<IMacAlgorithmProvider2> macAlgorithmProvider2;
        RETURN_IF_FAILED_LOG(_macAlgorithmProvider.As(&macAlgorithmProvider2));
        RETURN_IF_FAILED_LOG(macAlgorithmProvider2->CreateHash(keyBuffer.Get(), &_hash));
        return S_OK;
    }

    HRESULT _update(const void* data, size_t length) {
        ComPtr<IBuffer> dataBuffer;
        RETURN_IF_FAILED_LOG(BufferFromRawData(&dataBuffer, (unsigned char*)data, length));
        RETURN_IF_FAILED_LOG(_hash->Append(dataBuffer.Get()));
        return S_OK;
    }

    HRESULT _finishHash(void* digest) {
        memset(digest, 0, _digestLength);
        RETURN_IF_FAILED_LOG(_hash->GetValueAndReset(&_outBuffer));
        ComPtr<IBufferByteAccess> bufferAccess;
        RETURN_IF_FAILED_LOG(_outBuffer.As(&bufferAccess));
        BYTE* pRawHash;
        RETURN_IF_FAILED_LOG(bufferAccess->Buffer(&pRawHash));
        memcpy_s(digest, _digestLength, pRawHash, _digestLength);
        return S_OK;
    }

    const CCHmacAlgorithm _algorithm;
    const void* _key;
    const size_t _keyLength;
    ComPtr<IMacAlgorithmProvider> _macAlgorithmProvider;
    ComPtr<IHashComputation> _hash;
    ComPtr<IBuffer> _outBuffer;
    size_t _digestLength;
    bool _isValid;
};


/**
@Status Interoperable
*/
void CCHmacInit(CCHmacContext* ctx, CCHmacAlgorithm algorithm, const void* key, size_t keyLength) {
    CC_Hmac_State::init(ctx, algorithm, key, keyLength);
}

/**
@Status Interoperable
*/
void CCHmacUpdate(CCHmacContext* ctx, const void* data, size_t dataLength) {
    CC_Hmac_State::update(ctx, data, dataLength);
}

/**
@Status Interoperable
*/
void CCHmacFinal(CCHmacContext* ctx, void* macOut) {
    CC_Hmac_State::final(macOut, ctx);
}

/**
@Status Interoperable
*/
void CCHmac(CCHmacAlgorithm algorithm, const void* key, size_t keyLength, const void* data, size_t dataLength, void* macOut) {
    CC_Hmac_State::oneShot(algorithm, key, keyLength, data, dataLength, macOut);
}

