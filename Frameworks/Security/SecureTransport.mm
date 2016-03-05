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
#import <Security/SecureTransport.h>

/**
 @Status Stub
*/
OSStatus SSLSetConnection(SSLContextRef context, SSLConnectionRef connection) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetConnection(SSLContextRef context, SSLConnectionRef _Nullable* connection) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLSetSessionOption(SSLContextRef context, SSLSessionOption option, Boolean value) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetSessionOption(SSLContextRef context, SSLSessionOption option, Boolean* value) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLSetIOFuncs(SSLContextRef context, SSLReadFunc readFunc, SSLWriteFunc writeFunc) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLSetClientSideAuthenticate(SSLContextRef context, SSLAuthenticate auth) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLHandshake(SSLContextRef context) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetSessionState(SSLContextRef context, SSLSessionState* state) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetNegotiatedProtocolVersion(SSLContextRef context, SSLProtocol* protocol) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLSetPeerID(SSLContextRef context, const void* peerID, size_t peerIDLen) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetPeerID(SSLContextRef context, const void* _Nullable* peerID, size_t* peerIDLen) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetBufferedReadSize(SSLContextRef context, size_t* bufSize) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLRead(SSLContextRef context, void* data, size_t dataLength, size_t* processed) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLWrite(SSLContextRef context, const void* data, size_t dataLength, size_t* processed) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLClose(SSLContextRef context) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetNumberSupportedCiphers(SSLContextRef context, size_t* numCiphers) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetSupportedCiphers(SSLContextRef context, SSLCipherSuite* ciphers, size_t* numCiphers) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLSetEnabledCiphers(SSLContextRef context, const SSLCipherSuite* ciphers, size_t numCiphers) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetNumberEnabledCiphers(SSLContextRef context, size_t* numCiphers) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetEnabledCiphers(SSLContextRef context, SSLCipherSuite* ciphers, size_t* numCiphers) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetNegotiatedCipher(SSLContextRef context, SSLCipherSuite* cipherSuite) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLAddDistinguishedName(SSLContextRef context, const void* derDN, size_t derDNLen) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLCopyDistinguishedNames(SSLContextRef context, CFArrayRef _Nullable* names) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLSetCertificate(SSLContextRef context, CFArrayRef certRefs) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetClientCertificateState(SSLContextRef context, SSLClientCertificateState* clientState) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLSetEncryptionCertificate(SSLContextRef context, CFArrayRef certRefs) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLCopyPeerTrust(SSLContextRef context, SecTrustRef _Nullable* trust) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLSetPeerDomainName(SSLContextRef context, const char* peerName, size_t peerNameLen) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetPeerDomainNameLength(SSLContextRef context, size_t* peerNameLen) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetPeerDomainName(SSLContextRef context, char* peerName, size_t* peerNameLen) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
CFTypeID SSLContextGetTypeID() {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
SSLContextRef SSLCreateContext(CFAllocatorRef alloc, SSLProtocolSide protocolSide, SSLConnectionType connectionType) {
    UNIMPLEMENTED();
    return nullptr;
}

/**
 @Status Stub
*/
OSStatus SSLGetDatagramWriteSize(SSLContextRef dtlsContext, size_t* bufSize) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetMaxDatagramRecordSize(SSLContextRef dtlsContext, size_t* maxSize) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetProtocolVersionMax(SSLContextRef context, SSLProtocol* maxVersion) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLGetProtocolVersionMin(SSLContextRef context, SSLProtocol* minVersion) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLSetDatagramHelloCookie(SSLContextRef dtlsContext, const void* cookie, size_t cookieLen) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLSetMaxDatagramRecordSize(SSLContextRef dtlsContext, size_t maxSize) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLSetProtocolVersionMax(SSLContextRef context, SSLProtocol maxVersion) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}

/**
 @Status Stub
*/
OSStatus SSLSetProtocolVersionMin(SSLContextRef context, SSLProtocol minVersion) {
    UNIMPLEMENTED();
    return errSecUnimplemented;
}
