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

#import "Starboard.h"
#import "StubReturn.h"
#import "Foundation/NSString.h"
#import "Foundation/NSMutableData.h"
#import "NSSSLHandler.h"

#define NOMINMAX

#if defined(WIN32) || defined(ANDROID)
#import <pthread.h>

#import <openssl/err.h>
#import <openssl/ssl.h>
#import <cmath>
#import <algorithm>
#import "LoggingNative.h"

static const wchar_t* TAG = L"NSSSLHandler";

static pthread_mutex_t initLock = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t* lockTable;

static void locking_function(int mode, int idx, const char* file, int line) {
    if (mode & CRYPTO_LOCK) {
        pthread_mutex_lock(&(lockTable[idx]));
    } else {
        pthread_mutex_unlock(&(lockTable[idx]));
    }
}
#endif

@implementation NSSSLHandler
#if defined(WIN32) || defined(ANDROID)
+ (void)initialize {
    if (self == [NSSSLHandler class]) {
        kCFStreamSSLLevel = [@"kCFStreamSSLLevel" retain];
        kCFStreamSocketSecurityLevelSSLv3 = [@"kCFStreamSocketSecurityLevelSSLv3" retain];
        kCFStreamSocketSecurityLevelSSLv2 = [@"kCFStreamSocketSecurityLevelSSLv2" retain];
        kCFStreamSocketSecurityLevelTLSv1 = [@"kCFStreamSocketSecurityLevelTLSv1" retain];
        kCFStreamSSLValidatesCertificateChain = [@"kCFStreamSSLValidatesCertificateChain" retain];

        pthread_mutex_lock(&initLock);
        CRYPTO_set_mem_functions((void* (*)(size_t))malloc, (void* (*)(void*, size_t))realloc, free);
        SSL_load_error_strings();
        ERR_load_BIO_strings();
        SSL_library_init();

        int i, numberOfLocks = CRYPTO_num_locks();
        lockTable = (pthread_mutex_t*)OPENSSL_malloc(numberOfLocks * sizeof(pthread_mutex_t));
        for (i = 0; i < numberOfLocks; i++)
            pthread_mutex_init(&(lockTable[i]), NULL);

        CRYPTO_set_locking_callback(locking_function);
        pthread_mutex_unlock(&initLock);
    }
}

- (id)initWithProperties:(id)properties {
    _properties = [properties retain];

    id level = [_properties objectForKey:kCFStreamSSLLevel];

    if (level == NULL)
        _method = (SSL_METHOD*)SSLv23_client_method();
    else if ([level compare:kCFStreamSocketSecurityLevelSSLv3] == 0)
        _method = (SSL_METHOD*)SSLv3_client_method();
    else if ([level compare:kCFStreamSocketSecurityLevelSSLv2] == 0)
        _method = (SSL_METHOD*)SSLv2_client_method();
    else if ([level compare:kCFStreamSocketSecurityLevelTLSv1] == 0)
        _method = (SSL_METHOD*)TLSv1_client_method();
    else
        _method = (SSL_METHOD*)SSLv23_client_method();

    id validatesCertChain = [_properties objectForKey:kCFStreamSSLValidatesCertificateChain];

    if (validatesCertChain != nil) {
    }

    _context = SSL_CTX_new(_method);
    _connection = SSL_new(_context);
    _incoming = BIO_new(BIO_s_mem());
    _outgoing = BIO_new(BIO_s_mem());

    SSL_set_bio(_connection, _incoming, _outgoing);

    SSL_set_connect_state(_connection);

    /* The SSL_read doc.s say that when SSL_read returns Wants More you should use the same arguments
    the next call. It is a little ambiguous whether the same exact pointer should be used, so we don't
    chance it and just maintain a buffer for this purpose. */

    _stableBufferCapacity = 8192;
    _stableBuffer = (uint8_t*)malloc(_stableBufferCapacity);
    _readBuffer = [[NSMutableData alloc] init];

    return self;
}

- (void)dealloc {
    [_properties release];
    [_readBuffer release];
    SSL_free(_connection);
    free(_stableBuffer);
    [super dealloc];
}

- (BOOL)isHandshaking {
    return SSL_in_init(_connection) ? YES : NO;
}

- (int)writePlaintext:(const uint8_t*)buffer maxLength:(int)length {
    int result = SSL_write(_connection, buffer, length);

    if (result < 0) {
        int error = SSL_get_error(_connection, result);

        switch (error) {
            case SSL_ERROR_ZERO_RETURN:
                break;

            case SSL_ERROR_NONE:
                break;

            case SSL_ERROR_WANT_READ:
                break;

            default:;
                char errorCString[256];

                while (error != 0) {
                    ERR_error_string_n(error, errorCString, sizeof(errorCString));

                    TraceError(TAG, L"SSL_write(%d) returned error %d - %hs", length, error, errorCString);

                    error = ERR_get_error();
                }
                break;
        }
    }

    return result;
}

- (NSInteger)writeBytesAvailable {
    return BIO_ctrl_pending(_outgoing);
}

- (BOOL)wantsMoreIncoming {
    return SSL_want_read(_connection);
}

- (NSInteger)readEncrypted:(uint8_t*)buffer maxLength:(int)length {
    int check = BIO_read(_outgoing, buffer, length);

    if (check <= 0) {
        // This shouldn't happen unless we read when not ready
        TraceVerbose(TAG, L"BIO_read(_outgoing,buffer,%d) returned %d ", length, check);
    }

    return check;
}

- (NSInteger)writeEncrypted:(const uint8_t*)buffer maxLength:(int)length {
    size_t check = BIO_write(_incoming, buffer, length);

    if (check <= 0) {
        // This shouldn't happen unless we are out of memory?
        TraceVerbose(TAG, L"BIO_write(_incoming,buffer,%d) returned %d ", length, check);
    }

    return check;
}

- (NSInteger)_readPostSSL:(uint8_t*)buffer maxLength:(int)length {
    int numRead = 0;

    while (numRead < length) {
        int check = SSL_read(_connection, buffer + numRead, length - numRead);

        if (check <= 0) {
            int error = SSL_get_error(_connection, check);

            switch (error) {
                case SSL_ERROR_ZERO_RETURN:
                    return numRead;

                case SSL_ERROR_NONE:
                    return numRead;

                case SSL_ERROR_WANT_READ:
                    return numRead;

                default:;
                    char errorCString[256];

                    while (error != 0) {
                        ERR_error_string_n(error, errorCString, sizeof(errorCString));

                        TraceError(TAG, L"SSL_read(%d) returned error %d - %hs", length, error, errorCString);

                        error = ERR_get_error();
                    }
                    break;
            }
        }

        numRead += check;
        TraceVerbose(TAG, L"Got %d bytes from SSL", check);
        TraceVerbose(TAG, L"Pending=%d", BIO_ctrl_pending(_outgoing));
    }

    return numRead;
}

- (NSInteger)readBytesAvailable {
    /* SSL_pending() is useless here because it doesn't actually process anything, it will return 0 when there are bytes
    available post-processing.
    */
    if ([_readBuffer length] > 0)
        return [_readBuffer length];
    else {
        NSInteger result = [self _readPostSSL:_stableBuffer maxLength:_stableBufferCapacity];

        if (result <= 0)
            return 0;

        [_readBuffer appendBytes:_stableBuffer length:result];
        return result;
    }

    return 0;
}

- (unsigned)readPlaintext:(uint8_t*)buffer maxLength:(unsigned)length {
    unsigned ret = 0;
    if ([_readBuffer length] > 0) {
        unsigned qty = std::min((unsigned)[_readBuffer length], length);

        [_readBuffer getBytes:buffer length:qty];
        [_readBuffer replaceBytesInRange:NSMakeRange(0, qty) withBytes:NULL length:0];
        ret = qty;
    }

    if (ret < length) {
        unsigned more = [self _readPostSSL:buffer + ret maxLength:length - ret];

        if (more < 0) {
            assert(0);
        }

        ret += more;
    }

    return ret;
}

- (NSInteger)transferOneBufferFromSSLToSocket:(id)socket {
    NSInteger available = [self readEncrypted:_stableBuffer maxLength:_stableBufferCapacity];

    if (available <= 0)
        return available;
    else {
        NSInteger check = [socket write:_stableBuffer maxLength:available];

        if (check != available)
            TraceError(TAG, L"failure socket write:%d=%d", available, check);

        return check;
    }
    return self;
}

- (NSInteger)transferOneBufferFromSocketToSSL:(id)socket {
    if ([socket hasBytesAvailable]) {
        NSInteger result = [socket read:_stableBuffer maxLength:_stableBufferCapacity];
        TraceVerbose(TAG, L"Got %d bytes for SSL", result);

        if (result <= 0)
            return result;

        NSInteger check;

        if ((check = [self writeEncrypted:_stableBuffer maxLength:result]) != result) {
            TraceError(TAG, L"[sslHandler writeEncrypted:socketBuffer maxLength:%d] failed %d", result, check);
        }

        return result;
    } else {
        return 0;
    }
}

- (void)runHandshakeIfNeeded:(id)socket {
    while ([self isHandshaking]) {
        int check = SSL_do_handshake(_connection);

        if (check == 1) {
            [_outputStream _triggerWrite];
            break;
        }

        if (check == 0) {
            break;
        }

        if ([self writeBytesAvailable]) {
            if ((check = [self transferOneBufferFromSSLToSocket:socket]) <= 0)
                break;
        }

        if ([self wantsMoreIncoming]) {
            if ((check = [self transferOneBufferFromSocketToSSL:socket]) <= 0) {
                break;
            }
        }
    }
}

- (void)runWithSocket:(id)socket {
    while ([self writeBytesAvailable] || [self wantsMoreIncoming]) {
        NSInteger check;

        if ([self writeBytesAvailable]) {
            if ((check = [self transferOneBufferFromSSLToSocket:socket]) <= 0)
                break;
        }

        if ([self wantsMoreIncoming]) {
            if ((check = [self transferOneBufferFromSocketToSSL:socket]) <= 0)
                break;
        }
    }
}

- (void)setOutputStream:(id)stream {
    _outputStream = stream;
}

#else

/*
 @Status Stub
 @Notes
*/
- (int)writePlaintext:(const uint8_t*)buffer maxLength:(int)length {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (unsigned)readPlaintext:(uint8_t*)buffer maxLength:(unsigned)length {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (id)initWithProperties:(id)properties {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (void)dealloc {
    UNIMPLEMENTED();
    [super dealloc];
}

/*
 @Status Stub
 @Notes
*/
- (BOOL)isHandshaking {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (NSInteger)writeBytesAvailable {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (BOOL)wantsMoreIncoming {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (NSInteger)readEncrypted:(uint8_t*)buffer maxLength:(int)length {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (NSInteger)writeEncrypted:(const uint8_t*)buffer maxLength:(int)length {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (NSInteger)_readPostSSL:(uint8_t*)buffer maxLength:(int)length {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (NSInteger)readBytesAvailable {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (NSInteger)transferOneBufferFromSSLToSocket:(id)socket {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (NSInteger)transferOneBufferFromSocketToSSL:(id)socket {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (void)runHandshakeIfNeeded:(id)socket {
    UNIMPLEMENTED();
}

/*
 @Status Stub
 @Notes
*/
- (void)runWithSocket:(id)socket {
    UNIMPLEMENTED();
}

/*
 @Status Stub
 @Notes
*/
- (void)setOutputStream:(id)stream {
    UNIMPLEMENTED();
}

/*
 @Status Stub
 @Notes
*/
+ (void)initialize {
    UNIMPLEMENTED();
}

#endif

@end
