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

// This header file is not yet fully implemented

#import <Security/SecBase.h>
#import <Security/SecTrust.h>
#import <stdint.h>

struct SSLContext;
typedef const void* SSLConnectionRef;
typedef struct SSLContext* SSLContextRef;

typedef enum SSLAuthenticate : uint32_t SSLAuthenticate;
enum SSLAuthenticate : uint32_t { kNeverAuthenticate = 0, kAlwaysAuthenticate, kTryAuthenticate };

typedef enum SSLClientCertificateState : uint32_t SSLClientCertificateState;
enum SSLClientCertificateState : uint32_t { kSSLClientCertNone = 0, kSSLClientCertRequested, kSSLClientCertSent, kSSLClientCertRejected };

typedef enum SSLProtocol : uint32_t SSLProtocol;
enum SSLProtocol : uint32_t {
    kSSLProtocolUnknown = 0,
    kSSLProtocol3 = 2,
    kTLSProtocol1 = 4,
    kTLSProtocol11 = 7,
    kTLSProtocol12 = 8,
    kDTLSProtocol1 = 9,
    /* DEPRECATED on iOS */
    kSSLProtocol2 = 1,
    kSSLProtocol3Only = 3,
    kTLSProtocol1Only = 5,
    kSSLProtocolAll = 6,
};

typedef enum SSLSessionState : uint32_t SSLSessionState;
enum SSLSessionState : uint32_t { kSSLIdle = 0, kSSLHandshake, kSSLConnected, kSSLClosed, kSSLAborted };

typedef enum SSLSessionOption : uint32_t SSLSessionOption;
enum SSLSessionOption : uint32_t {
    kSSLSessionOptionBreakOnServerAuth = 0,
    kSSLSessionOptionBreakOnCertRequested,
    kSSLSessionOptionBreakOnClientAuth,
    kSSLSessionOptionFalseStart,
    kSSLSessionOptionSendOneByteRecord
};

typedef enum SSLProtocolSide : uint32_t SSLProtocolSide;
enum SSLProtocolSide : uint32_t { kSSLServerSide = 0, kSSLClientSide };

typedef enum SSLConnectionType : uint32_t SSLConnectionType;
enum SSLConnectionType : uint32_t { kSSLStreamType = 0, kSSLDatagramType };

typedef OSStatus (*SSLReadFunc)(SSLConnectionRef connection, void* data, size_t* dataLength);
typedef OSStatus (*SSLWriteFunc)(SSLConnectionRef connection, const void* data, size_t* dataLength);

typedef enum SSLCipherSuite : uint32_t SSLCipherSuite;
enum SSLCipherSuite : uint32_t {
    SSL_NULL_WITH_NULL_NULL = 0x0000,
    SSL_RSA_WITH_NULL_MD5 = 0x0001,
    SSL_RSA_WITH_NULL_SHA = 0x0002,
    SSL_RSA_EXPORT_WITH_RC4_40_MD5 = 0x0003,
    SSL_RSA_WITH_RC4_128_MD5 = 0x0004,
    SSL_RSA_WITH_RC4_128_SHA = 0x0005,
    SSL_RSA_EXPORT_WITH_RC2_CBC_40_MD5 = 0x0006,
    SSL_RSA_WITH_IDEA_CBC_SHA = 0x0007,
    SSL_RSA_EXPORT_WITH_DES40_CBC_SHA = 0x0008,
    SSL_RSA_WITH_DES_CBC_SHA = 0x0009,
    SSL_RSA_WITH_3DES_EDE_CBC_SHA = 0x000A,
    SSL_DH_DSS_EXPORT_WITH_DES40_CBC_SHA = 0x000B,
    SSL_DH_DSS_WITH_DES_CBC_SHA = 0x000C,
    SSL_DH_DSS_WITH_3DES_EDE_CBC_SHA = 0x000D,
    SSL_DH_RSA_EXPORT_WITH_DES40_CBC_SHA = 0x000E,
    SSL_DH_RSA_WITH_DES_CBC_SHA = 0x000F,
    SSL_DH_RSA_WITH_3DES_EDE_CBC_SHA = 0x0010,
    SSL_DHE_DSS_EXPORT_WITH_DES40_CBC_SHA = 0x0011,
    SSL_DHE_DSS_WITH_DES_CBC_SHA = 0x0012,
    SSL_DHE_DSS_WITH_3DES_EDE_CBC_SHA = 0x0013,
    SSL_DHE_RSA_EXPORT_WITH_DES40_CBC_SHA = 0x0014,
    SSL_DHE_RSA_WITH_DES_CBC_SHA = 0x0015,
    SSL_DHE_RSA_WITH_3DES_EDE_CBC_SHA = 0x0016,
    SSL_DH_anon_EXPORT_WITH_RC4_40_MD5 = 0x0017,
    SSL_DH_anon_WITH_RC4_128_MD5 = 0x0018,
    SSL_DH_anon_EXPORT_WITH_DES40_CBC_SHA = 0x0019,
    SSL_DH_anon_WITH_DES_CBC_SHA = 0x001A,
    SSL_DH_anon_WITH_3DES_EDE_CBC_SHA = 0x001B,
    SSL_FORTEZZA_DMS_WITH_NULL_SHA = 0x001C,
    SSL_FORTEZZA_DMS_WITH_FORTEZZA_CBC_SHA = 0x001D,
    /* TLS addenda using AES, per RFC 3268 */
    TLS_RSA_WITH_AES_128_CBC_SHA = 0x002F,
    TLS_DH_DSS_WITH_AES_128_CBC_SHA = 0x0030,
    TLS_DH_RSA_WITH_AES_128_CBC_SHA = 0x0031,
    TLS_DHE_DSS_WITH_AES_128_CBC_SHA = 0x0032,
    TLS_DHE_RSA_WITH_AES_128_CBC_SHA = 0x0033,
    TLS_DH_anon_WITH_AES_128_CBC_SHA = 0x0034,
    TLS_RSA_WITH_AES_256_CBC_SHA = 0x0035,
    TLS_DH_DSS_WITH_AES_256_CBC_SHA = 0x0036,
    TLS_DH_RSA_WITH_AES_256_CBC_SHA = 0x0037,
    TLS_DHE_DSS_WITH_AES_256_CBC_SHA = 0x0038,
    TLS_DHE_RSA_WITH_AES_256_CBC_SHA = 0x0039,
    TLS_DH_anon_WITH_AES_256_CBC_SHA = 0x003A,
    /* ECDSA addenda, RFC 4492 */
    TLS_ECDH_ECDSA_WITH_NULL_SHA = 0xC001,
    TLS_ECDH_ECDSA_WITH_RC4_128_SHA = 0xC002,
    TLS_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA = 0xC003,
    TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA = 0xC004,
    TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA = 0xC005,
    TLS_ECDHE_ECDSA_WITH_NULL_SHA = 0xC006,
    TLS_ECDHE_ECDSA_WITH_RC4_128_SHA = 0xC007,
    TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA = 0xC008,
    TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA = 0xC009,
    TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA = 0xC00A,
    TLS_ECDH_RSA_WITH_NULL_SHA = 0xC00B,
    TLS_ECDH_RSA_WITH_RC4_128_SHA = 0xC00C,
    TLS_ECDH_RSA_WITH_3DES_EDE_CBC_SHA = 0xC00D,
    TLS_ECDH_RSA_WITH_AES_128_CBC_SHA = 0xC00E,
    TLS_ECDH_RSA_WITH_AES_256_CBC_SHA = 0xC00F,
    TLS_ECDHE_RSA_WITH_NULL_SHA = 0xC010,
    TLS_ECDHE_RSA_WITH_RC4_128_SHA = 0xC011,
    TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA = 0xC012,
    TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA = 0xC013,
    TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA = 0xC014,
    TLS_ECDH_anon_WITH_NULL_SHA = 0xC015,
    TLS_ECDH_anon_WITH_RC4_128_SHA = 0xC016,
    TLS_ECDH_anon_WITH_3DES_EDE_CBC_SHA = 0xC017,
    TLS_ECDH_anon_WITH_AES_128_CBC_SHA = 0xC018,
    TLS_ECDH_anon_WITH_AES_256_CBC_SHA = 0xC019,
    /* TLS 1.2 addenda,    RFC 5246 */
    /* Initial state. */
    TLS_NULL_WITH_NULL_NULL = 0x0000,
    /* Server provided RSA certificate for key exchange. */
    TLS_RSA_WITH_NULL_MD5 = 0x0001,
    TLS_RSA_WITH_NULL_SHA = 0x0002,
    TLS_RSA_WITH_RC4_128_MD5 = 0x0004,
    TLS_RSA_WITH_RC4_128_SHA = 0x0005,
    TLS_RSA_WITH_3DES_EDE_CBC_SHA = 0x000A,
    TLS_RSA_WITH_NULL_SHA256 = 0x003B,
    TLS_RSA_WITH_AES_128_CBC_SHA256 = 0x003C,
    TLS_RSA_WITH_AES_256_CBC_SHA256 = 0x003D,
    /* Server-authenticated (and optionally client-authenticated ) Diffie-Hellman. */
    TLS_DH_DSS_WITH_3DES_EDE_CBC_SHA = 0x000D,
    TLS_DH_RSA_WITH_3DES_EDE_CBC_SHA = 0x0010,
    TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA = 0x0013,
    TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA = 0x0016,
    TLS_DH_DSS_WITH_AES_128_CBC_SHA256 = 0x003E,
    TLS_DH_RSA_WITH_AES_128_CBC_SHA256 = 0x003F,
    TLS_DHE_DSS_WITH_AES_128_CBC_SHA256 = 0x0040,
    TLS_DHE_RSA_WITH_AES_128_CBC_SHA256 = 0x0067,
    TLS_DH_DSS_WITH_AES_256_CBC_SHA256 = 0x0068,
    TLS_DH_RSA_WITH_AES_256_CBC_SHA256 = 0x0069,
    TLS_DHE_DSS_WITH_AES_256_CBC_SHA256 = 0x006A,
    TLS_DHE_RSA_WITH_AES_256_CBC_SHA256 = 0x006B,
    /* Completely anonymous Diffie-Hellman */
    TLS_DH_anon_WITH_RC4_128_MD5 = 0x0018,
    TLS_DH_anon_WITH_3DES_EDE_CBC_SHA = 0x001B,
    TLS_DH_anon_WITH_AES_128_CBC_SHA256 = 0x006C,
    TLS_DH_anon_WITH_AES_256_CBC_SHA256 = 0x006D,
    /* Addendum from RFC 4279, TLS PSK */
    TLS_PSK_WITH_RC4_128_SHA = 0x008A,
    TLS_PSK_WITH_3DES_EDE_CBC_SHA = 0x008B,
    TLS_PSK_WITH_AES_128_CBC_SHA = 0x008C,
    TLS_PSK_WITH_AES_256_CBC_SHA = 0x008D,
    TLS_DHE_PSK_WITH_RC4_128_SHA = 0x008E,
    TLS_DHE_PSK_WITH_3DES_EDE_CBC_SHA = 0x008F,
    TLS_DHE_PSK_WITH_AES_128_CBC_SHA = 0x0090,
    TLS_DHE_PSK_WITH_AES_256_CBC_SHA = 0x0091,
    TLS_RSA_PSK_WITH_RC4_128_SHA = 0x0092,
    TLS_RSA_PSK_WITH_3DES_EDE_CBC_SHA = 0x0093,
    TLS_RSA_PSK_WITH_AES_128_CBC_SHA = 0x0094,
    TLS_RSA_PSK_WITH_AES_256_CBC_SHA = 0x0095,
    /* RFC 4785 - Pre-Shared Key (PSK ) Ciphersuites with NULL Encryption */
    TLS_PSK_WITH_NULL_SHA = 0x002C,
    TLS_DHE_PSK_WITH_NULL_SHA = 0x002D,
    TLS_RSA_PSK_WITH_NULL_SHA = 0x002E,
    /* Addenda from rfc 5288 AES Galois Counter Mode (GCM ) Cipher Suites for TLS. */
    TLS_RSA_WITH_AES_128_GCM_SHA256 = 0x009C,
    TLS_RSA_WITH_AES_256_GCM_SHA384 = 0x009D,
    TLS_DHE_RSA_WITH_AES_128_GCM_SHA256 = 0x009E,
    TLS_DHE_RSA_WITH_AES_256_GCM_SHA384 = 0x009F,
    TLS_DH_RSA_WITH_AES_128_GCM_SHA256 = 0x00A0,
    TLS_DH_RSA_WITH_AES_256_GCM_SHA384 = 0x00A1,
    TLS_DHE_DSS_WITH_AES_128_GCM_SHA256 = 0x00A2,
    TLS_DHE_DSS_WITH_AES_256_GCM_SHA384 = 0x00A3,
    TLS_DH_DSS_WITH_AES_128_GCM_SHA256 = 0x00A4,
    TLS_DH_DSS_WITH_AES_256_GCM_SHA384 = 0x00A5,
    TLS_DH_anon_WITH_AES_128_GCM_SHA256 = 0x00A6,
    TLS_DH_anon_WITH_AES_256_GCM_SHA384 = 0x00A7,
    /* RFC 5487 - PSK with SHA-256/384 and AES GCM */
    TLS_PSK_WITH_AES_128_GCM_SHA256 = 0x00A8,
    TLS_PSK_WITH_AES_256_GCM_SHA384 = 0x00A9,
    TLS_DHE_PSK_WITH_AES_128_GCM_SHA256 = 0x00AA,
    TLS_DHE_PSK_WITH_AES_256_GCM_SHA384 = 0x00AB,
    TLS_RSA_PSK_WITH_AES_128_GCM_SHA256 = 0x00AC,
    TLS_RSA_PSK_WITH_AES_256_GCM_SHA384 = 0x00AD,
    TLS_PSK_WITH_AES_128_CBC_SHA256 = 0x00AE,
    TLS_PSK_WITH_AES_256_CBC_SHA384 = 0x00AF,
    TLS_PSK_WITH_NULL_SHA256 = 0x00B0,
    TLS_PSK_WITH_NULL_SHA384 = 0x00B1,
    TLS_DHE_PSK_WITH_AES_128_CBC_SHA256 = 0x00B2,
    TLS_DHE_PSK_WITH_AES_256_CBC_SHA384 = 0x00B3,
    TLS_DHE_PSK_WITH_NULL_SHA256 = 0x00B4,
    TLS_DHE_PSK_WITH_NULL_SHA384 = 0x00B5,
    TLS_RSA_PSK_WITH_AES_128_CBC_SHA256 = 0x00B6,
    TLS_RSA_PSK_WITH_AES_256_CBC_SHA384 = 0x00B7,
    TLS_RSA_PSK_WITH_NULL_SHA256 = 0x00B8,
    TLS_RSA_PSK_WITH_NULL_SHA384 = 0x00B9,
    /* Addenda from rfc 5289  Elliptic Curve Cipher Suites with HMAC SHA-256/384. */
    TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256 = 0xC023,
    TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384 = 0xC024,
    TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256 = 0xC025,
    TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA384 = 0xC026,
    TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256 = 0xC027,
    TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384 = 0xC028,
    TLS_ECDH_RSA_WITH_AES_128_CBC_SHA256 = 0xC029,
    TLS_ECDH_RSA_WITH_AES_256_CBC_SHA384 = 0xC02A,
    /* Addenda from rfc 5289  Elliptic Curve Cipher Suites with SHA-256/384 and AES Galois Counter Mode (GCM ) */
    TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256 = 0xC02B,
    TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384 = 0xC02C,
    TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256 = 0xC02D,
    TLS_ECDH_ECDSA_WITH_AES_256_GCM_SHA384 = 0xC02E,
    TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256 = 0xC02F,
    TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384 = 0xC030,
    TLS_ECDH_RSA_WITH_AES_128_GCM_SHA256 = 0xC031,
    TLS_ECDH_RSA_WITH_AES_256_GCM_SHA384 = 0xC032,
    /* RFC 5746 - Secure Renegotiation */
    TLS_EMPTY_RENEGOTIATION_INFO_SCSV = 0x00FF,
    /* Tags for SSL 2 cipher kinds that are not specified or SSL 3. */
    SSL_RSA_WITH_RC2_CBC_MD5 = 0xFF80,
    SSL_RSA_WITH_IDEA_CBC_MD5 = 0xFF81,
    SSL_RSA_WITH_DES_CBC_MD5 = 0xFF82,
    SSL_RSA_WITH_3DES_EDE_CBC_MD5 = 0xFF83,
    SSL_NO_SUCH_CIPHERSUITE = 0xFFFF
};

SECURITY_EXPORT OSStatus SSLSetConnection(SSLContextRef context, SSLConnectionRef connection) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetConnection(SSLContextRef context, SSLConnectionRef _Nullable* connection) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLSetSessionOption(SSLContextRef context, SSLSessionOption option, Boolean value) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetSessionOption(SSLContextRef context, SSLSessionOption option, Boolean* value) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLSetIOFuncs(SSLContextRef context, SSLReadFunc readFunc, SSLWriteFunc writeFunc) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLSetClientSideAuthenticate(SSLContextRef context, SSLAuthenticate auth) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLHandshake(SSLContextRef context) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetSessionState(SSLContextRef context, SSLSessionState* state) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetNegotiatedProtocolVersion(SSLContextRef context, SSLProtocol* protocol) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLSetPeerID(SSLContextRef context, const void* peerID, size_t peerIDLen) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetPeerID(SSLContextRef context, const void* _Nullable* peerID, size_t* peerIDLen) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetBufferedReadSize(SSLContextRef context, size_t* bufSize) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLRead(SSLContextRef context, void* data, size_t dataLength, size_t* processed) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLWrite(SSLContextRef context, const void* data, size_t dataLength, size_t* processed) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLClose(SSLContextRef context) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetNumberSupportedCiphers(SSLContextRef context, size_t* numCiphers) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetSupportedCiphers(SSLContextRef context, SSLCipherSuite* ciphers, size_t* numCiphers) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLSetEnabledCiphers(SSLContextRef context, const SSLCipherSuite* ciphers, size_t numCiphers) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetNumberEnabledCiphers(SSLContextRef context, size_t* numCiphers) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetEnabledCiphers(SSLContextRef context, SSLCipherSuite* ciphers, size_t* numCiphers) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetNegotiatedCipher(SSLContextRef context, SSLCipherSuite* cipherSuite) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLAddDistinguishedName(SSLContextRef context, const void* derDN, size_t derDNLen) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLCopyDistinguishedNames(SSLContextRef context, CFArrayRef _Nullable* names) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLSetCertificate(SSLContextRef context, CFArrayRef certRefs) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetClientCertificateState(SSLContextRef context, SSLClientCertificateState* clientState) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLSetEncryptionCertificate(SSLContextRef context, CFArrayRef certRefs) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLCopyPeerTrust(SSLContextRef context, SecTrustRef* trust) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLSetPeerDomainName(SSLContextRef context, const char* peerName, size_t peerNameLen) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetPeerDomainNameLength(SSLContextRef context, size_t* peerNameLen) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetPeerDomainName(SSLContextRef context, char* peerName, size_t* peerNameLen) STUB_METHOD;
SECURITY_EXPORT CFTypeID SSLContextGetTypeID() STUB_METHOD;
SECURITY_EXPORT SSLContextRef SSLCreateContext(CFAllocatorRef alloc,
                                               SSLProtocolSide protocolSide,
                                               SSLConnectionType connectionType) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetDatagramWriteSize(SSLContextRef dtlsContext, size_t* bufSize) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetMaxDatagramRecordSize(SSLContextRef dtlsContext, size_t* maxSize) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetProtocolVersionMax(SSLContextRef context, SSLProtocol* maxVersion) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLGetProtocolVersionMin(SSLContextRef context, SSLProtocol* minVersion) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLSetDatagramHelloCookie(SSLContextRef dtlsContext, const void* cookie, size_t cookieLen) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLSetMaxDatagramRecordSize(SSLContextRef dtlsContext, size_t maxSize) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLSetProtocolVersionMax(SSLContextRef context, SSLProtocol maxVersion) STUB_METHOD;
SECURITY_EXPORT OSStatus SSLSetProtocolVersionMin(SSLContextRef context, SSLProtocol minVersion) STUB_METHOD;