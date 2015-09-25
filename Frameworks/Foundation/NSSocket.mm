/* Copyright (c) 2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifdef WIN32
#include <io.h>
#include <fcntl.h>
#include <WinSock2.h>
#include <ws2tcpip.h>

typedef int socklen_t;
#elif defined(WINPHONE) || defined(__OBJC__)
#include <WinSock2.h>
#include <ws2tcpip.h>

typedef int socklen_t;
#undef WIN32
#define WINPHONE
#else
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/tcp.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <netdb.h>
#define closesocket close
#define ioctlsocket ioctl
#endif

#include <pthread.h>

#include "Starboard.h"
#include "NSSocket.h"
#include "Foundation/NSError.h"
#include "Foundation/NSString.h"
#include "NSSSLHandler.h"

@implementation NSSocket : NSObject
static inline void byteZero(void* vsrc, size_t size) {
    uint8_t* src = (uint8_t*)vsrc;
    size_t i;

    for (i = 0; i < size; i++)
        src[i] = 0;
}

- (id)initWithDescriptor:(int)descriptor {
    _descriptor = descriptor;
    return self;
}

+ (id)socketWithDescriptor:(int)descriptor {
    return [[[self alloc] initWithDescriptor:descriptor] autorelease];
}

- (id)initTCPStream {
    _descriptor = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (_descriptor == -1) {
        [self dealloc];
        assert(0);
        return nil;
    }
    return self;
}

/*
id initWithFileDescriptor__unused( int fd) {
+socketWithDescriptor:(int)descriptor {
return [[[self alloc] initWithDescriptor:descriptor] autorelease];
}

-initUDPStream {
NSError *error=[self errorForReturnValue:_descriptor=socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP)];
if(error!=nil){
[self dealloc];
return nil;
}
return self;
}

-(void)closeAndDealloc {
[self close];
[self dealloc];
}
*/
- (id)errorForReturnValue:(int)returnValue {
    if (returnValue < 0) {
        return [NSError errorWithDomain:0 code:errno userInfo:nil];
    }
    return nil;
}

- (id)setOperationWouldBlock:(BOOL)blocks {
    u_long onoff = blocks ? NO : YES;

    return [self errorForReturnValue:ioctlsocket(_descriptor, FIONBIO, &onoff)];
}

- (BOOL)operationWouldBlock {
#if defined(WIN32) || defined(WINPHONE)
    return WSAGetLastError() == WSAEWOULDBLOCK;
#else
    return (errno == EINPROGRESS);
#endif
}

struct PipeInfo {
    int s;
    int port;
};

static void* connectFunc(void* p) {
    struct PipeInfo* pipe = (struct PipeInfo*)p;
    int socket = pipe->s;
    struct sockaddr_in pin;

    memset(&pin, 0, sizeof(pin));
    pin.sin_family = AF_INET;
    pin.sin_addr.s_addr = inet_addr("127.0.0.1");
    pin.sin_port = pipe->port;

    if (connect(socket, (sockaddr*)&pin, sizeof(pin)) == -1) {
#if defined(WIN32)
        int err = WSAGetLastError();
        LPSTR errString = 0;
        int size = FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, 0, err, 0, (LPSTR)&errString, 0, 0);
#endif
        assert(0);
    }

    int opt_value = 1;

#if !defined(WIN32) && !defined(WINPHONE)
    setsockopt(socket, IPPROTO_TCP, TCP_NODELAY, &opt_value, sizeof(opt_value));
#endif

    delete pipe;

    return NULL;
}

- (id)initConnectedToSocket:(id*)otherX {
    int sockets[2];

#ifdef ANDROID
    socketpair(AF_LOCAL, SOCK_STREAM, 0, sockets);
#else
    sockets[0] = socket(AF_INET, SOCK_STREAM, 0);
    sockets[1] = socket(AF_INET, SOCK_STREAM, 0);
    EbrDebugLog("sockets[0] = %d sockets[1] = %d\n", sockets[0], sockets[1]);

    struct sockaddr_in sin, pin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    sin.sin_port = htons(0);

    if (bind(sockets[0], (sockaddr*)&sin, sizeof(sin)) == -1) {
        assert(0);
    }

    if (listen(sockets[0], 1) == -1) {
        assert(0);
    }

    socklen_t len = sizeof(sin);
    getsockname(sockets[0], (sockaddr*)&sin, &len);

    //  Spawn a quick thread to connect
    pthread_t tid;
    struct PipeInfo* p = new PipeInfo();

    p->s = sockets[1];
    p->port = sin.sin_port;
    pthread_create(&tid, NULL, connectFunc, (void*)p);

    socklen_t pinLen = sizeof(pin);
    int connected = accept(sockets[0], (sockaddr*)&pin, &pinLen);
    closesocket(sockets[0]);

    sockets[0] = connected;

    int opt_value = 1;

#if !defined(WIN32) && !defined(WINPHONE)
    setsockopt(sockets[0], IPPROTO_TCP, TCP_NODELAY, &opt_value, sizeof(opt_value));
    setsockopt(sockets[1], IPPROTO_TCP, TCP_NODELAY, &opt_value, sizeof(opt_value));
#endif

//_pipe(pipes, 4096, _O_BINARY);
#endif

    *otherX = [[[[self class] alloc] initWithDescriptor:sockets[0]] autorelease];

    return [self initWithDescriptor:sockets[1]];
}

- (int)write:(void*)buffer maxLength:(DWORD)length {
    return send(_descriptor, (const char*)buffer, length, 0);
}

- (int)read:(void*)buffer maxLength:(DWORD)length {
    return recv(_descriptor, (char*)buffer, length, 0);
}

- (int)descriptor {
    return _descriptor;
}

- (void)setDescriptor:(int)descriptor {
    _descriptor = descriptor;
}

- (int)hash {
    return _descriptor;
}

- (BOOL)isEqual:(NSSocket*)other {
    if (![(id)other isKindOfClass:[NSSocket class]])
        return NO;

    return (_descriptor == other->_descriptor) ? YES : NO;
}

- (id)connectToHost:(id)host port:(int)portNumber immediate:(BOOL*)immediate {
    BOOL block = YES;
    const char* pHost = [host UTF8String];

    id error = nil;

    *immediate = NO;

    if (!block) {
        if ((error = [self setOperationWouldBlock:NO]) != nil)
            return error;
    }

    struct sockaddr_in tryAddr;
    memset(&tryAddr, 0, sizeof(struct sockaddr_in));

    if (pHost == NULL) {
        EbrDebugLog("NULL connection to %s\n", pHost);
    } else {
        struct addrinfo* remoteHost;

        // struct hostent *remoteHost;
        EbrDebugLog("Gethostbyname %s\n", pHost);
        int success = getaddrinfo(pHost, NULL, NULL, &remoteHost);
        EbrDebugLog("%d\n", success);

        if (success == 0 && remoteHost != NULL) {
            struct sockaddr_in* pAddr = (sockaddr_in*)remoteHost->ai_addr;
            memcpy(&tryAddr.sin_addr.s_addr, &pAddr->sin_addr, 4);
            tryAddr.sin_family = AF_INET;
            tryAddr.sin_port = htons(portNumber);
            freeaddrinfo(remoteHost);
        } else {
            tryAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
            tryAddr.sin_family = AF_INET;
            tryAddr.sin_port = htons(12345);
        }
    }

    if (tryAddr.sin_port != 12345 &&
        connect(_descriptor, (struct sockaddr*)&tryAddr, (socklen_t)sizeof(tryAddr)) == 0) {
        if (!block) {
            if ((error = [self setOperationWouldBlock:YES]) != nil)
                return error;
        }
        *immediate = YES;
        _isConnected = TRUE;
        return nil;
    } else if ([self operationWouldBlock]) {
        if (!block) {
            if ((error = [self setOperationWouldBlock:YES]) != nil)
                return error;
        }
        return nil;
    } else {
        error = [self errorForReturnValue:-1];
    }

    if (error == nil)
        error = [NSError errorWithDomain:0 code:EHOSTUNREACH userInfo:nil];
    return error;
}

- (id)close {
    // return [self errorForReturnValue:close(_descriptor)];
    if (_descriptor != -1) {
        closesocket(_descriptor);
        _descriptor = -1;
    }
    return nil;
}

- (BOOL)hasBytesAvailable {
    DWORD bytesAvail = 0;
    int ret = ioctlsocket(_descriptor, FIONREAD, &bytesAvail);
    if (ret == 0) {
        if (bytesAvail > 0) {
            return TRUE;
        } else {
            return FALSE;
        }
    }
    return FALSE;
}

- (BOOL)setSSLProperties:(id)properties {
#ifndef QNX
    if (_sslHandler == nil) {
        _sslHandler = [[NSSSLHandler alloc] initWithProperties:properties];
    }
#endif
    return YES;
}

- (id)sslHandler {
    return _sslHandler;
}

- (BOOL)isConnected {
    return _isConnected;
}

@end
