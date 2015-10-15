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

#if EBRIUS
extern id kCFStreamSSLLevel;
extern id kCFStreamSocketSecurityLevelSSLv3;
extern id kCFStreamSocketSecurityLevelSSLv2;
extern id kCFStreamSocketSecurityLevelTLSv1;
extern id kCFStreamSSLValidatesCertificateChain;
#endif

struct ssl_st;
struct ssl_ctx_st;
struct bio_st;
struct ssl_method_st;

typedef struct ssl_method_st SSL_METHOD;
typedef struct ssl_st SSL;
typedef struct bio_st BIO;
typedef struct ssl_ctx_st SSL_CTX;

@interface NSSSLHandler : NSObject {
@public
    id _properties;
#if defined(WIN32) || defined(ANDROID)
    SSL_METHOD* _method;
    SSL_CTX* _context;
    SSL* _connection;
    BIO* _incoming;
    BIO* _outgoing;
    int _stableBufferCapacity;
    uint8_t* _stableBuffer;
    id _readBuffer;
    id _outputStream;
#endif
}
- (int)writePlaintext:(const uint8_t*)buffer maxLength:(int)length;
- (unsigned)readPlaintext:(uint8_t*)buffer maxLength:(unsigned)length;
/* annotate with type */ -(id)initWithProperties : (id)properties;
/* annotate with type */ -(id)dealloc;
/* annotate with type */ -(id)isHandshaking;
/* annotate with type */ -(id)writeBytesAvailable;
/* annotate with type */ -(id)wantsMoreIncoming;
/* annotate with type */ -(id)readEncrypted : (uint8_t*)buffer maxLength : (int)length;
/* annotate with type */ -(id)writeEncrypted : (const uint8_t*)buffer maxLength : (int)length;
/* annotate with type */ -(id)_readPostSSL : (uint8_t*)buffer maxLength : (int)length;
/* annotate with type */ -(id)readBytesAvailable;
/* annotate with type */ -(id)transferOneBufferFromSSLToSocket : (id)socket;
/* annotate with type */ -(id)transferOneBufferFromSocketToSSL : (id)socket;
/* annotate with type */ -(id)runHandshakeIfNeeded : (id)socket;
/* annotate with type */ -(id)runWithSocket : (id)socket;
/* annotate with type */ -(id)setOutputStream : (id)stream;
/* annotate with type */ +(id)initialize;
@end