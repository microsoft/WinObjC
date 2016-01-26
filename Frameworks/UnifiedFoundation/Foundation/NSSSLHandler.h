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
- (int)writePlaintext:(const uint8_t*)buffer maxLength:(int)length STUB_METHOD;
- (unsigned)readPlaintext:(uint8_t*)buffer maxLength:(unsigned)length STUB_METHOD;
- (id)initWithProperties:(id)properties STUB_METHOD;
- (id)dealloc STUB_METHOD;
- (id)isHandshaking STUB_METHOD;
- (id)writeBytesAvailable STUB_METHOD;
- (id)wantsMoreIncoming STUB_METHOD;
- (id)readEncrypted:(uint8_t*)buffer maxLength:(int)length STUB_METHOD;
- (id)writeEncrypted:(const uint8_t*)buffer maxLength:(int)length STUB_METHOD;
- (id)_readPostSSL:(uint8_t*)buffer maxLength:(int)length STUB_METHOD;
- (id)readBytesAvailable STUB_METHOD;
- (id)transferOneBufferFromSSLToSocket:(id)socket STUB_METHOD;
- (id)transferOneBufferFromSocketToSSL:(id)socket STUB_METHOD;
- (id)runHandshakeIfNeeded:(id)socket STUB_METHOD;
- (id)runWithSocket:(id)socket STUB_METHOD;
- (id)setOutputStream:(id)stream STUB_METHOD;
+ (id)initialize STUB_METHOD;
@end