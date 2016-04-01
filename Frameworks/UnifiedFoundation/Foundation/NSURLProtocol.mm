/* Copyright (c) 2006-2007 Christopher J. W. Lloyd
   Copyright (c) 2016 Microsoft Corporation. All rights reserved.

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
#include "StubReturn.h"
#include "Foundation/NSString.h"
#include "Foundation/NSURLProtocol.h"
#include "NSURLProtocol_file.h"
#include "Foundation/NSMutableArray.h"
#include "NSURLProtocolInternal.h"
#include "NSRaise.h"
#include "LoggingNative.h"

static const wchar_t* TAG = L"NSURLProtocol";

@implementation NSURLProtocol

+ (NSMutableArray*)_registeredClasses {
    static StrongId<NSMutableArray> _registeredClasses([NSMutableArray array]);
    return _registeredClasses;
}

/**
 @Status Interoperable
*/
+ (BOOL)registerClass:(id)cls {
    @synchronized (self) {
        if ([[self _registeredClasses] containsObject:cls]) {
            return NO;
        }
        [[self _registeredClasses] addObject:cls];
        return YES;
    }
}

+ (id)_URLProtocolClassForRequest:(id)request {
    @synchronized (self) {
        NSArray* classes = [self _registeredClasses];
        NSInteger count = [classes count];

        while (--count >= 0) {
            id check = [classes objectAtIndex:count];

            if ([check canInitWithRequest:request])
                return check;
        }

        id url = [request URL];
        id absStr = [url absoluteString];
        const char* urlStr = [absStr UTF8String];
        TraceWarning(TAG, L"Couldn't find protocol handler for %hs", urlStr ? urlStr : "(null)");

        return nil;
    }
}

/**
 @Status Interoperable
*/
- (instancetype)initWithRequest:(NSURLRequest*)request cachedResponse:(NSCachedURLResponse*)cachedResponse client:(id<NSURLProtocolClient>)client {
    if (self = [super init]) {
        _request.attach([request mutableCopy]);
        _cachedResponse = cachedResponse;
        _client = client;
    }
    return self;
}

/**
 @Status Interoperable
*/
- (id<NSURLProtocolClient>)client {
    return [[_client retain] autorelease];
}

/**
 @Status Interoperable
*/
- (NSURLRequest*)request {
    return [[_request retain] autorelease];
}

/**
 @Status Interoperable
*/
- (NSCachedURLResponse*)cachedResponse {
    return [[_cachedResponse retain] autorelease];
}

- (id)scheduleInRunLoop:(id)runLoop forMode:(id)mode {
    return self;
}

- (id)unscheduleFromRunLoop:(id)runLoop forMode:(id)mode {
    return self;
}

/**
 @Status Interoperable
*/
- (void)startLoading {
    NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)stopLoading {
    NSInvalidAbstractInvocation();
}

/**
 @Status Stub
 @Notes
*/
+ (void)unregisterClass:(Class)protocolClass {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)canInitWithRequest:(NSURLRequest*)request {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (id)propertyForKey:(NSString*)key inRequest:(NSURLRequest*)request {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (void)setProperty:(id)value forKey:(NSString*)key inRequest:(NSMutableURLRequest*)request {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (void)removePropertyForKey:(NSString*)key inRequest:(NSMutableURLRequest*)request {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (NSURLRequest*)canonicalRequestForRequest:(NSURLRequest*)request {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)requestIsCacheEquivalent:(NSURLRequest*)aRequest toRequest:(NSURLRequest*)bRequest {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
