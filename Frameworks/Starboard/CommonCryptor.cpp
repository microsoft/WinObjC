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
#include <CommonCrypto\CommonCryptor.h>
#include <COMIncludes.h>
#include <wrl\wrappers\corewrappers.h>
#include <wrl\client.h>
#include <windows.security.cryptography.h>
#include <windows.storage.streams.h>
#include <COMIncludes_End.h>
#include <ErrorHandling.h>
#include <StubReturn.h>
#include <RawBuffer.h>
#include <memory>
#include <vector>

using namespace Microsoft::WRL;
using namespace ABI::Windows::Storage::Streams;
using namespace ABI::Windows::Security::Cryptography;
using namespace ABI::Windows::Security::Cryptography::Core;
using namespace Windows::Foundation;

static CCCryptorStatus _cryptorStatusFromHRESULT(HRESULT result) {
    switch (result) {
        case E_INVALIDARG:
            return kCCParamError;
        case E_OUTOFMEMORY:
            return kCCMemoryFailure;
        case E_NOTIMPL:
            return kCCUnimplemented;
        case SEC_E_BUFFER_TOO_SMALL:
            return kCCBufferTooSmall;
        case SEC_E_CANNOT_PACK:
            return kCCAlignmentError;
        case CRYPT_E_BAD_ENCODE:
            return kCCDecodeError;
        case S_OK:
            return kCCSuccess;
        default:
            // In case of some other HRESULT, hand that back to the caller without translating.
            LOG_HR_MSG(result, "Unable to translate HRESULT to CCCryptorStatus.");
            break;
    }

    return result;
}

struct CC_Cryptor_State {
    CC_Cryptor_State(CCOperation op, CCAlgorithm alg, CCOptions options, const void* key, size_t keyLength, const void* iv)
        : _op(op),
          _alg(alg),
          _options(options),
          _key(key),
          _keyLength(keyLength),
          _blockSize(0),
          _iv(iv),
          _ivBuffer(nullptr),
          _inputBuffer() {
        if (_alg == kCCAlgorithmAES) {
            _blockSize = 16;
        } else if (_alg == kCCAlgorithmRC4) {
            _blockSize = 1;
        } else {
            _blockSize = 8;
        }
    }

    ~CC_Cryptor_State() {
    }

    static std::unique_ptr<CC_Cryptor_State> init(
        CCOperation op, CCAlgorithm alg, CCOptions options, const void* key, size_t keyLength, const void* iv, CCCryptorStatus* statusOut) {

        std::unique_ptr<CC_Cryptor_State> pState = std::make_unique<CC_Cryptor_State>(op, alg, options, key, keyLength, iv);

        HRESULT initResult = pState->_init();
        if (FAILED(initResult)) {
            *statusOut = _cryptorStatusFromHRESULT(initResult);
            return nullptr;
        }

        *statusOut = kCCSuccess;
        return pState;
    }

    CCCryptorStatus update(const void* dataIn, size_t dataInLength, void* dataOut, size_t dataOutAvailable, size_t* dataOutMoved) {
        return _cryptorStatusFromHRESULT(_update(dataIn, dataInLength, dataOut, dataOutAvailable, dataOutMoved));
    }

    CCCryptorStatus final(void* dataOut, size_t dataOutAvailable, size_t* dataOutMoved) {
        return _cryptorStatusFromHRESULT(_final(dataOut, dataOutAvailable, dataOutMoved));
    }

    CCCryptorStatus reset(const void* iv) {
        _iv = iv;
        _ivBuffer = nullptr;
        _inputBuffer.clear();
        _cryptographicKey = nullptr;

        HRESULT initResult = _init();
        if (FAILED(initResult)) {
            return _cryptorStatusFromHRESULT(initResult);
        }

        return kCCSuccess;
    }

    static CCCryptorStatus oneShot(CCOperation op,
                                   CCAlgorithm alg,
                                   CCOptions options,
                                   const void* key,
                                   size_t keyLength,
                                   const void* iv,
                                   const void* dataIn,
                                   size_t dataInLength,
                                   void* dataOut,
                                   size_t dataOutAvailable,
                                   size_t* dataOutMoved) {
        CCCryptorStatus status;
        *dataOutMoved = 0;

        std::unique_ptr<CC_Cryptor_State> pState = CC_Cryptor_State::init(op, alg, options, key, keyLength, iv, &status);
        if (status != kCCSuccess) {
            return status;
        }

        size_t dataMoved1 = 0;
        status = pState->update(dataIn, dataInLength, dataOut, dataOutAvailable, &dataMoved1);
        *dataOutMoved = dataMoved1;
        if (status != kCCSuccess) {
            return status;
        }

        size_t dataMoved2 = 0;
        status = pState->final((uint8_t*)dataOut + dataMoved1, dataOutAvailable - dataMoved1, &dataMoved2);
        *dataOutMoved = dataMoved1 + dataMoved2;
        return status;
    }

    size_t outputLength(size_t inputLength, bool final) {
        // For stream ciphers, the output size is always equal to the input size. For block ciphers, the output size will always be less
        // than or equal to the input size plus the size of one block

        if (_alg == kCCAlgorithmRC4) {
            return inputLength;
        }

        // Round down the input length to the nearest block
        size_t output = inputLength - (inputLength % _blockSize);

        // If final is false, the return value indicates the output space needed for update.
        if (!final) {
            return output;
        }

        // If final is true and padding is enabled, add a block
        if (_options & kCCOptionPKCS7Padding) {
            output += _blockSize;
        }

        return output;
    }

private:
    HRESULT _validateParams() {
        // Validate operation parameter
        if (_op != kCCEncrypt && _op != kCCDecrypt) {
            RETURN_HR_MSG(E_INVALIDARG, "Expected operation kCCEncrypt or kCCDecrypt");
        }

        // Validate algorithm/key parameter
        switch (_alg) {
        case kCCAlgorithmAES:
            if (!_key || (_keyLength != kCCKeySizeAES128 && _keyLength != kCCKeySizeAES192 && _keyLength != kCCKeySizeAES256)) {
                RETURN_HR_MSG(E_INVALIDARG, "Invalid key for specified algorithm kCCAlgorithmAES");
            }
            break;
        case kCCAlgorithmDES:
            if (!_key || _keyLength != kCCKeySizeDES) {
                RETURN_HR_MSG(E_INVALIDARG, "Invalid key for specified algorithm kCCAlgorithmDES");
            }
            break;
        case kCCAlgorithm3DES:
            if (!_key || _keyLength != kCCKeySize3DES) {
                RETURN_HR_MSG(E_INVALIDARG, "Invalid key for specified algorithm kCCAlgorithm3DES");
            }
            break;
        case kCCAlgorithmCAST:
            UNIMPLEMENTED_WITH_MSG("kCCAlgorithmCAST is not supported");
            return E_NOTIMPL;
        case kCCAlgorithmRC4:
            if ((!_key) || (_keyLength < kCCKeySizeMinRC4) || (_keyLength > kCCKeySizeMaxRC4)) {
                RETURN_HR_MSG(E_INVALIDARG, "Invalid key for specified algorithm kCCAlgorithmRC4");
            }
            break;
        case kCCAlgorithmRC2:
            if ((!_key) || (_keyLength < kCCKeySizeMinRC2) || (_keyLength > kCCKeySizeMaxRC2)) {
                RETURN_HR_MSG(E_INVALIDARG, "Invalid key for specified algorithm kCCAlgorithmRC2");
            }
            break;
        case kCCAlgorithmBlowfish:
            UNIMPLEMENTED_WITH_MSG("kCCAlgorithmBlowfish is not supported");
            return E_NOTIMPL;
        default:
            RETURN_HR_MSG(E_INVALIDARG, "Unknown algorithm");
            break;
        }

        return S_OK;
    }

    HRESULT _init() {
        RETURN_IF_FAILED(_validateParams());

        ComPtr<ISymmetricKeyAlgorithmProviderStatics> symmetricKeyAlgorithmProviderStatics;
        ComPtr<ISymmetricAlgorithmNamesStatics> symmetricAlgorithmNamesStatics;
        ComPtr<ICryptographicBufferStatics> cryptographicBufferStatics;
        RETURN_IF_FAILED_LOG(
            GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Security_Cryptography_Core_SymmetricKeyAlgorithmProvider)
                                     .Get(),
                                 &symmetricKeyAlgorithmProviderStatics));
        RETURN_IF_FAILED_LOG(
            GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Security_Cryptography_Core_SymmetricAlgorithmNames).Get(),
                                 &symmetricAlgorithmNamesStatics));
        RETURN_IF_FAILED_LOG(
            GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Security_Cryptography_CryptographicBuffer).Get(),
                                 &cryptographicBufferStatics));

        Microsoft::WRL::Wrappers::HString name;
        unsigned char allZeroIV[16] = {};

        // Retrieve algorithm name
        switch (_options) {
            case kCCOptionPKCS7Padding:
                if (!_iv) {
                    _iv = allZeroIV;
                }

                switch (_alg) {
                    case kCCAlgorithmAES:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_AesCbcPkcs7(name.GetAddressOf()));
                        break;
                    case kCCAlgorithmDES:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_DesCbcPkcs7(name.GetAddressOf()));
                        break;
                    case kCCAlgorithm3DES:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_TripleDesCbcPkcs7(name.GetAddressOf()));
                        break;
                    case kCCAlgorithmRC4:
                        RETURN_HR_MSG(E_INVALIDARG, "Padding is not a valid option on stream ciphers.");
                    case kCCAlgorithmRC2:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_Rc2CbcPkcs7(name.GetAddressOf()));
                        break;
                    default:
                        return E_INVALIDARG;
                        break;
                }
                break;
            case kCCOptionECBMode:
                _iv = nullptr;
                switch (_alg) {
                    case kCCAlgorithmAES:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_AesEcb(name.GetAddressOf()));
                        break;
                    case kCCAlgorithmDES:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_DesEcb(name.GetAddressOf()));
                        break;
                    case kCCAlgorithm3DES:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_TripleDesEcb(name.GetAddressOf()));
                        break;
                    case kCCAlgorithmRC4:
                        RETURN_HR_MSG(E_INVALIDARG, "ECB mode is not a valid option on stream ciphers.");
                    case kCCAlgorithmRC2:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_Rc2Ecb(name.GetAddressOf()));
                        break;
                    default:
                        return E_INVALIDARG;
                        break;
                }
                break;
            case (kCCOptionPKCS7Padding | kCCOptionECBMode):
                _iv = nullptr;
                switch (_alg) {
                    case kCCAlgorithmAES:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_AesEcbPkcs7(name.GetAddressOf()));
                        break;
                    case kCCAlgorithmDES:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_DesEcbPkcs7(name.GetAddressOf()));
                        break;
                    case kCCAlgorithm3DES:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_TripleDesEcbPkcs7(name.GetAddressOf()));
                        break;
                    case kCCAlgorithmRC4:
                        RETURN_HR_MSG(E_INVALIDARG, "Padding/ECB mode is not a valid option on stream ciphers.");
                    case kCCAlgorithmRC2:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_Rc2EcbPkcs7(name.GetAddressOf()));
                        break;
                    default:
                        return E_INVALIDARG;
                        break;
                }
                break;
            default:
                if (!(_iv || (_alg == kCCAlgorithmRC4))) {
                    _iv = allZeroIV;
                }

                switch (_alg) {
                    case kCCAlgorithmAES:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_AesCbc(name.GetAddressOf()));
                        break;
                    case kCCAlgorithmDES:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_DesCbc(name.GetAddressOf()));
                        break;
                    case kCCAlgorithm3DES:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_TripleDesCbc(name.GetAddressOf()));
                        break;
                    case kCCAlgorithmRC4:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_Rc4(name.GetAddressOf()));
                        break;
                    case kCCAlgorithmRC2:
                        RETURN_IF_FAILED_LOG(symmetricAlgorithmNamesStatics->get_Rc2Cbc(name.GetAddressOf()));
                        break;
                    default:
                        return E_INVALIDARG;
                        break;
                }
                break;
        }

        // Initialize key buffer
        ComPtr<ISymmetricKeyAlgorithmProvider> symmetricKeyAlgorithmProvider;
        RETURN_IF_FAILED_LOG(symmetricKeyAlgorithmProviderStatics->OpenAlgorithm(name.Get(), &symmetricKeyAlgorithmProvider));
        ComPtr<IBuffer> keyBuffer;
        RETURN_IF_FAILED_LOG(BufferFromRawData(&keyBuffer, (unsigned char*)_key, _keyLength));
        RETURN_IF_FAILED_LOG(symmetricKeyAlgorithmProvider->CreateSymmetricKey(keyBuffer.Get(), &_cryptographicKey));

        // Initialize iv buffer
        if (_iv) {
            RETURN_IF_FAILED_LOG(cryptographicBufferStatics->CreateFromByteArray(_blockSize, (unsigned char*)_iv, &_ivBuffer));
        } else {
             _ivBuffer = nullptr;
        }

        return S_OK;
    }

    HRESULT _performOp(void* dataOut, size_t dataOutAvailable, size_t dataOutSize, size_t dataInSize, size_t* dataOutMoved, bool final) {
        ComPtr<ICryptographicBufferStatics> cryptographicBufferStatics;
        RETURN_IF_FAILED_LOG(
            GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Security_Cryptography_CryptographicBuffer).Get(),
                &cryptographicBufferStatics));

        // Create an IBuffer for input data, remove data from internal storage
        ComPtr<IBuffer> dataInBuffer;
        RETURN_IF_FAILED_LOG(BufferFromRawData(&dataInBuffer, _inputBuffer.data(), dataInSize));

        ComPtr<ICryptographicEngineStatics> cryptographicEngineStatics;

        RETURN_IF_FAILED_LOG(
            GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Security_Cryptography_Core_CryptographicEngine).Get(),
                &cryptographicEngineStatics));

        ComPtr<IBuffer> dataOutBuffer;

        // Peform the Encrypt/Decrypt operation
        if (_op == kCCEncrypt) {
            RETURN_IF_FAILED_LOG(
                cryptographicEngineStatics->Encrypt(_cryptographicKey.Get(), dataInBuffer.Get(), _ivBuffer.Get(), &dataOutBuffer));
        } else {
            RETURN_IF_FAILED_LOG(
                cryptographicEngineStatics->Decrypt(_cryptographicKey.Get(), dataInBuffer.Get(), _ivBuffer.Get(), &dataOutBuffer));
        }

        // Copy the output to the out pointer
        ComPtr<IBufferByteAccess> bufferAccess;
        RETURN_IF_FAILED_LOG(dataOutBuffer.As(&bufferAccess));
        BYTE* pRawOutput;
        RETURN_IF_FAILED_LOG(bufferAccess->Buffer(&pRawOutput));
        memcpy_s(dataOut, dataOutAvailable, pRawOutput, dataOutSize);

        *dataOutMoved = dataOutSize;

        // If this is the final operation, we are done
        if (final) {
            return S_OK;
        }

        // Last encrypted block becomes the new initialization vector
        if (_alg != kCCAlgorithmRC4 && !(_options & kCCOptionECBMode)) {
            if (_op == kCCEncrypt) {
                RETURN_IF_FAILED_LOG(
                    cryptographicBufferStatics->CreateFromByteArray(_blockSize, pRawOutput + dataOutSize - _blockSize, &_ivBuffer));
            } else {
                RETURN_IF_FAILED_LOG(cryptographicBufferStatics->CreateFromByteArray(_blockSize,
                    _inputBuffer.data() + dataOutSize - _blockSize,
                    &_ivBuffer));
            }
        }

        _inputBuffer.erase(_inputBuffer.begin(), _inputBuffer.begin() + dataOutSize);

        return S_OK;
    }

    HRESULT _update(const void* dataIn, size_t dataInLength, void* dataOut, size_t dataOutAvailable, size_t* dataOutMoved) {
        *dataOutMoved = 0;
        size_t inputSize = _inputBuffer.size() + dataInLength;

        // Determine the size of data to encrypt or decrypt. This will be a multiple of the block size.
        size_t dataInOutLength = inputSize - (inputSize % _blockSize);
        if (dataInOutLength > dataOutAvailable) {
            return SEC_E_BUFFER_TOO_SMALL;
        }

        _inputBuffer.insert(_inputBuffer.end(), (uint8_t*)dataIn, (uint8_t*)dataIn + dataInLength);

        // If there isn't an entire block worth of data to encrypt, simply return.
        if (dataInOutLength == 0) {
            return S_OK;
        }

        // Perform the operation
        return _performOp(dataOut, dataOutAvailable, dataInOutLength, dataInOutLength, dataOutMoved, false);
    }

    HRESULT _final(void* dataOut, size_t dataOutAvailable, size_t* dataOutMoved) {
        *dataOutMoved = 0;

        if (_inputBuffer.size() == 0) {
            return S_OK;
        }

        // There can be no leftover data unless kCCOptionPKCS7Padding is specified
        if (!(_options & kCCOptionPKCS7Padding)) {
            return SEC_E_CANNOT_PACK;
        }

        // round up input to the nearest block
        size_t dataOutSize = _inputBuffer.size() + (_blockSize - _inputBuffer.size() % _blockSize);

        if (dataOutAvailable < dataOutSize) {
            return SEC_E_BUFFER_TOO_SMALL;
        }

        return _performOp(dataOut, dataOutAvailable, _blockSize, _inputBuffer.size(), dataOutMoved, true);
    }

    CCOperation _op;
    CCAlgorithm _alg;
    CCOptions _options;
    const void* _key;
    size_t _keyLength;
    size_t _blockSize;
    const void* _iv;
    ComPtr<ICryptographicKey> _cryptographicKey;
    ComPtr<IBuffer> _ivBuffer;
    std::vector<uint8_t> _inputBuffer;
};

/**
@Status Caveat
@Notes kCCAlgorithmCAST and kCCAlgorithmBlowfish are unsupported.
*/
CCCryptorStatus CCCryptorCreate(
    CCOperation op, CCAlgorithm alg, CCOptions options, const void* key, size_t keyLength, const void* iv, CCCryptorRef* cryptorRef) {
    *cryptorRef = nullptr;

    CCCryptorStatus status;
    std::unique_ptr<CC_Cryptor_State> pState = CC_Cryptor_State::init(op, alg, options, key, keyLength, iv, &status);
    if (status == kCCSuccess) {
        *cryptorRef = pState.release();
    }

    return status;
}

/**
@Status Caveat
@Notes Ignores caller-supplied memory and overwrites cryptorRef with dynamically allocated memory.
*/
CCCryptorStatus CCCryptorCreateFromData(CCOperation op,
                                        CCAlgorithm alg,
                                        CCOptions options,
                                        const void* key,
                                        size_t keyLength,
                                        const void* iv,
                                        const void* data,
                                        size_t dataLength,
                                        CCCryptorRef* cryptorRef,
                                        size_t* dataUsed) {
    if (!dataUsed || !cryptorRef) {
        return kCCParamError;
    }

    *dataUsed = 0;
    *cryptorRef = nullptr;

    CCCryptorStatus status;
    std::unique_ptr<CC_Cryptor_State> pState = CC_Cryptor_State::init(op, alg, options, key, keyLength, iv, &status);
    if (status == kCCSuccess) {
        *cryptorRef = pState.release();
    }

    return status;
}

/**
@Status Interoperable
*/
CCCryptorStatus CCCryptorRelease(CCCryptorRef cryptorRef) {
    delete cryptorRef;
    return kCCSuccess;
}

/**
@Status Interoperable
*/
CCCryptorStatus CCCryptorUpdate(
    CCCryptorRef cryptorRef, const void* dataIn, size_t dataInLength, void* dataOut, size_t dataOutAvailable, size_t* dataOutMoved) {
    if (!cryptorRef) {
        return kCCParamError;
    }

    return cryptorRef->update(dataIn, dataInLength, dataOut, dataOutAvailable, dataOutMoved);
}

/**
@Status Interoperable
*/
CCCryptorStatus CCCryptorFinal(CCCryptorRef cryptorRef, void* dataOut, size_t dataOutAvailable, size_t* dataOutMoved) {
    if (!dataOutMoved || !cryptorRef) {
        return kCCParamError;
    }

    return cryptorRef->final(dataOut, dataOutAvailable, dataOutMoved);
}

/**
@Status Interoperable
*/
size_t CCCryptorGetOutputLength(CCCryptorRef cryptorRef, size_t inputLength, bool final) {
    if (!cryptorRef) {
        LOG_HR(E_INVALIDARG);
        return 0;
    }

    return cryptorRef->outputLength(inputLength, final);
}

/**
@Status Interoperable
*/
CCCryptorStatus CCCryptorReset(CCCryptorRef cryptorRef, const void* iv) {
    if (!cryptorRef) {
        return kCCParamError;
    }

    return cryptorRef->reset(iv);
}

/**
@Status Interoperable
*/
CCCryptorStatus CCCrypt(CCOperation op,
                        CCAlgorithm alg,
                        CCOptions options,
                        const void* key,
                        size_t keyLength,
                        const void* iv,
                        const void* dataIn,
                        size_t dataInLength,
                        void* dataOut,
                        size_t dataOutAvailable,
                        size_t* dataOutMoved) {
    return CC_Cryptor_State::oneShot(op, alg, options, key, keyLength, iv, dataIn, dataInLength, dataOut, dataOutAvailable, dataOutMoved);
}