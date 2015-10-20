/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

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

#include "Starboard.h"
#include "Foundation/NSMutableString.h"
#include "Foundation/NSURLProtocol.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSMutableData.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSRunLoop.h"
#include "Foundation/NSTimer.h"
#include "Foundation/NSStream.h"
#include "NSInputStream_socket.h"
#include "NSOutputStream_socket.h"
#include "Foundation/NSError.h"

#include "Foundation/NSHTTPURLResponse.h"
#include "NSURLProtocol_file.h"
#include "NSURLProtocol_http.h"
#include "NSURLProtocolInternal.h"

#define MIN(x, y) ((x) < (y) ? (x) : (y))

@implementation NSURLProtocol_file
+ (BOOL)canInitWithRequest:(id)request {
    id scheme = [[request URL] scheme];

    if ([scheme isEqualToString:@"file"])
        return YES;

    return NO;
}

- (id)initWithRequest:(id)request cachedResponse:(id)response client:(id)client {
    [super initWithRequest:request cachedResponse:response client:client];

    _modes = [[NSMutableArray arrayWithObject:@"kCFRunLoopDefaultMode"] retain];

    id url = [_request URL];
    EbrDebugLog("Loading %s\n", [[url absoluteString] UTF8String]);

    _path = [[url path] copy];
    // id host = [NSHost hostWithName:hostName];

    return self;
}

- (id)startLoading {
    const char* pFilePath = [_path UTF8String];

    fpIn = EbrFopen(pFilePath, "rb");
    if (!fpIn) {
        EbrDebugLog("Couldn't open %s\n", pFilePath);
    } else {
        EbrDebugLog("Opened %s\n", pFilePath);
    }
    return self;
}

- (id)stopLoading {
    return self;
}

- (id)statusVersion:(id)versionStr {
    return self;
}

- (id)scheduleInRunLoop:(id)runLoop forMode:(id)mode {
    [runLoop performSelector:@selector(_doFileLoad) target:self argument:nil order:0 modes:[NSArray arrayWithObject:mode]];
    return self;
}

- (id)_doFileLoad {
    id url = [_request URL];

    if (fpIn == NULL) {
        EbrDebugLog("doFileLoad: fpIn = NULL! self=%x\n", self);
        id error = [NSError errorWithDomain:@"Couldn't open file" code:100 userInfo:nil];
        [_client URLProtocol:self didFailWithError:error];
        return self;
    }

    EbrFseek(fpIn, 0, SEEK_END);
    int len = EbrFtell(fpIn);
    EbrFseek(fpIn, 0, SEEK_SET);

    char* pData = (char*)EbrMalloc(len);
    len = EbrFread(pData, 1, len, fpIn);
    id dataReceived = [NSData dataWithBytes:pData length:len];
    EbrFree(pData);

    EbrFclose(fpIn);

    [_client URLProtocol:self didReceiveResponse:nil cacheStoragePolicy:NSURLCacheStorageAllowed];
    [_client URLProtocol:self didLoadData:dataReceived];
    [_client URLProtocolDidFinishLoading:self];

    return self;
}

- (id)unscheduleFromRunLoop:(id)runLoop forMode:(id)mode {
    return self;
}

@end
