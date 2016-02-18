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

#import <Starboard.h>
#import <Security/SecKey.h>

const CFTypeRef kSecPrivateKeyAttrs = static_cast<CFStringRef>(@"kSecPrivateKeyAttrs");
const CFTypeRef kSecPublicKeyAttrs = static_cast<CFStringRef>(@"kSecPublicKeyAttrs");

/**
 @Status Stub
*/
CFTypeID SecKeyGetTypeID() {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
OSStatus SecKeyGeneratePair(CFDictionaryRef parameters, SecKeyRef* publicKey, SecKeyRef* privateKey) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SecKeyEncrypt(
    SecKeyRef key, SecPadding padding, const uint8_t* plainText, size_t plainTextLen, uint8_t* cipherText, size_t* cipherTextLen) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SecKeyDecrypt(
    SecKeyRef key, SecPadding padding, const uint8_t* cipherText, size_t cipherTextLen, uint8_t* plainText, size_t* plainTextLen) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SecKeyRawSign(SecKeyRef key, SecPadding padding, const uint8_t* dataToSign, size_t dataToSignLen, uint8_t* sig, size_t* sigLen) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SecKeyRawVerify(
    SecKeyRef key, SecPadding padding, const uint8_t* signedData, size_t signedDataLen, const uint8_t* sig, size_t sigLen) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
size_t SecKeyGetBlockSize(SecKeyRef key) {
    UNIMPLEMENTED();
    return 0;
}