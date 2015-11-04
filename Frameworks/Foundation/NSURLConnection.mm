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
#include "Foundation/NSURLProtocol.h"
#include "Foundation/NSURLCache.h"
#include "Foundation/NSMutableData.h"
#include "Foundation/NSError.h"
#include "Foundation/NSRunLoop.h"
#include "NSURLConnectionState.h"
#include "Foundation/NSURLConnection.h"

@implementation NSURLConnection : NSObject

/**
 @Status Interoperable
*/
+ (BOOL)canHandleRequest:(id)request {
    return ([NSURLProtocol _URLProtocolClassForRequest:request] != nil) ? YES : NO;
}

/**
 @Status Caveat
 @Notes queue parameter not supported
*/
+ (void)sendAsynchronousRequest:(id)request
                          queue:(id)queue
              completionHandler:(void (^)(NSURLResponse*, NSData*, NSError*))completionHandler {
    EbrDebugLog("sendAsynchronousRequest not fully supported\n");

    id response, error;
    id data = [self sendSynchronousRequest:request returningResponse:&response error:&error];

    completionHandler(response, data, error);
}

/**
 @Status Caveat
 @Notes NSError returned is not detailed
*/
+ (id)sendSynchronousRequest:(id)request returningResponse:(NSURLResponse**)responsep error:(NSError**)errorp {
    id state = [[[NSURLConnectionState alloc] init] autorelease];
    id connection = [[self alloc] initWithRequest:request delegate:state startImmediately:FALSE];

    if (connection == nil) {
        if (errorp != NULL) {
            *errorp = [NSError errorWithDomain:@"NSURLErrorDomain" code:50 userInfo:nil];
        }

        return nil;
    }

    id mode = @"NSURLConnectionRequestMode";

    [connection scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:mode];
    [connection start];

    [state receiveAllDataInMode:mode];
    [connection unscheduleFromRunLoop:[NSRunLoop currentRunLoop] forMode:mode];

    id result = [[((NSURLConnection*)connection)->_mutableData retain] autorelease];

    [connection cancel];

    if (errorp != NULL) {
        *errorp = [state error];
    }

    if (responsep != NULL) {
        *responsep = [[((NSURLConnection*)connection)->_response retain] autorelease];
    }

    [connection release];

    return result;
}

/**
 @Status Interoperable
*/
+ (id)connectionWithRequest:(id)request delegate:(id)delegate {
    return [[[self alloc] initWithRequest:request delegate:delegate] autorelease];
}

/**
 @Status Interoperable
*/
- (id)initWithRequest:(id)request delegate:(id)delegate startImmediately:(BOOL)startLoading {
    _request = [request copy];
    id cls = [NSURLProtocol _URLProtocolClassForRequest:request];
    if (cls == nil) {
        return nil;
    }

    if ((_protocol = [[cls alloc] initWithRequest:_request
                                   cachedResponse:[[NSURLCache sharedURLCache] cachedResponseForRequest:_request]
                                           client:self]) == nil) {
        [self dealloc];
        return nil;
    }

    _delegate = [delegate retain];

    if (startLoading) {
        [self start];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (id)initWithRequest:(id)request delegate:(id)delegate {
    return [self initWithRequest:request delegate:delegate startImmediately:YES];
}

- (void)dealloc {
    [_request release];
    [_protocol release];
    [_delegate release];
    [_response release];
    [_mutableData release];
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (void)start {
    if (!_didRetain) {
        [self retain];
        _didRetain = TRUE;
    }

    [_protocol startLoading];
}

/**
 @Status Interoperable
*/
- (void)scheduleInRunLoop:(id)runLoop forMode:(id)mode {
    [_protocol scheduleInRunLoop:runLoop forMode:mode];
}

/**
 @Status Interoperable
*/
- (void)unscheduleFromRunLoop:(id)runLoop forMode:(id)mode {
    [_protocol unscheduleFromRunLoop:runLoop forMode:mode];
}

- (void)URLProtocol:(id)urlProtocol didFailWithError:(id)error {
    EbrDebugLog("URL protocol did fail\n");
    // if ( [_delegate respondsToSelector:@selector(connection:willSendRequest:redirectResponse:)] ) [_delegate
    // connection:self willSendRequest:_request redirectResponse:nil];
    if ([_delegate respondsToSelector:@selector(connection:didFailWithError:)]) {
        [_delegate connection:self didFailWithError:error];
    }

    if (_didRetain && !_didRelease) {
        _didRelease = TRUE;
        [self autorelease];
    }
    [_delegate autorelease];
    _delegate = nil;
}

- (id)URLProtocol:(id)urlProtocol willSendRequest:(id)request redirectResponse:(id)response {
    id ret = request;

    if ([_delegate respondsToSelector:@selector(connection:willSendRequest:redirectResponse:)]) {
        ret = [_delegate connection:self willSendRequest:request redirectResponse:response];
    }

    return ret;
}

- (void)URLProtocol:(id)urlProtocol didReceiveResponse:(id)response cacheStoragePolicy:(NSURLCacheStoragePolicy)policy {
    EbrDebugLog("URL protocol did receive response\n");

    if (_mutableData == nil) {
        _mutableData = [[NSMutableData alloc] init];
    }

    /*
    if ( [response respondsToSelector:@selector(statusCode)] && [response statusCode] != 200 ) {
    [_delegate setError:[NSError errorWithDomain:@"Bad response code" code:[response statusCode] userInfo:nil]];
    }
    */

    _response = [response retain];
    _storagePolicy = policy;

    if ([_delegate respondsToSelector:@selector(connection:willCacheResponse:)]) {
        [_delegate connection:self willCacheResponse:response];
    }
    if ([_delegate respondsToSelector:@selector(connection:didReceiveResponse:)]) {
        [_delegate connection:self didReceiveResponse:response];
    }
}

- (void)URLProtocol:(id)urlProtocol didLoadData:(id)data {
    EbrDebugLog("URL protocol did load data\n");
    if (_mutableData == nil) {
        _mutableData = [[NSMutableData alloc] init];
    }

    if (![_request _shouldDiscardData]) {
        [_mutableData appendData:data];
    }

    if ([_delegate respondsToSelector:@selector(connection:didReceiveData:)]) {
        [_delegate connection:self didReceiveData:data];
    }
}

- (void)URLProtocolDidFinishLoading:(id)urlProtocol {
    EbrDebugLog("URL protocol did finish loading\n");
    /*
    if(_storagePolicy==NSURLCacheStorageNotAllowed) {
    //[[NSURLCache sharedURLCache] removeCachedResponseForRequest:_request];
    } else {
    //NSCachedURLResponse *cachedResponse=[[NSCachedURLResponse alloc] initWithResponse:_response data:_mutableData
    userInfo:nil storagePolicy:_storagePolicy];

    //if([_delegate respondsToSelector:@selector(connection:willCacheResponse:)])
    //cachedResponse=[_delegate connection:self willCacheResponse:cachedResponse];

    //if(cachedResponse!=nil){
    //[[NSURLCache sharedURLCache] storeCachedResponse:cachedResponse forRequest:_request];
    //}
    }
    */

    if ([_delegate respondsToSelector:@selector(connectionDidFinishLoading:)]) {
        [_delegate performSelector:@selector(connectionDidFinishLoading:) withObject:self];
    }

    if (_didRetain && !_didRelease) {
        _didRelease = TRUE;
        [self autorelease];
    }
    [_delegate autorelease];
    _delegate = nil;
}

/**
 @Status Interoperable
*/
- (void)cancel {
    [_protocol stopLoading];

    if (_didRetain && !_didRelease) {
        _didRelease = TRUE;
        [self autorelease];
    }
}

- (void)URLProtocol:(id)urlProtocol didReceiveAuthenticationChallenge:(id)challenge {
    if ([_delegate respondsToSelector:@selector(connection:willSendRequestForAuthenticationChallenge:)]) {
        [_delegate connection:self willSendRequestForAuthenticationChallenge:challenge];
    } else {
        [_delegate connection:self didReceiveAuthenticationChallenge:challenge];
    }
}

#if 0

-(void)URLProtocol:(NSURLProtocol *)urlProtocol wasRedirectedToRequest:(NSURLRequest *)request redirectResponse:(NSURLResponse *)redirect {
[_delegate connection:self willSendRequest:request redirectResponse:redirect];
}

-(void)URLProtocol:(NSURLProtocol *)urlProtocol didCancelAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge {
// [_delegate connection:self didCancelAuthenticationChallenge];
}

-(void)URLProtocol:(NSURLProtocol *)urlProtocol cachedResponseIsValid:(NSCachedURLResponse *)cachedResponse {
}

#endif

#if 0
-(id) initWithRequest:(id)url delegate:(id)delegate startImmediately:(DWORD)immediately {
_delegate = delegate;

if ( immediately ) [self start];
return self;
}

-(id) unscheduleFromRunLoop:(id)runLoop forMode:(id)mode {
if ( _timer != nil ) {
[_timer invalidate];
_timer = nil;
}

return self;
}

-(id) scheduleInRunLoop:(id)runLoop forMode:(id)mode {
if ( _timer != nil ) return self;

_timer = [[NSTimer alloc] initWithFireDate:[NSDate date] interval:0.0 target:self selector:@selector(_notifyFailure) userInfo:0 repeats:FALSE];

[runLoop addTimer:_timer forMode:mode];
[runLoop _wakeUp];

return self;
}

+(id) sendSynchronousRequest:(id)request returningResponse:(id *)response error:(id *)error {
if ( response ) *response = nil;
if ( error ) *error = [NSError errorWithDomain:@"socket" code:100 userInfo:nil];
return nil;
}

+(id) connectionWithRequest:(id)request delegate:(id)delegate {
return [[self alloc] initWithRequest:request delegate:delegate];
}

+(id) canHandleRequest:(id)request {
return FALSE;
}

-(id) /* use typed version */ _notifyFailure {
if ( [_delegate respondsToSelector:@selector(connection:didFailWithError:)] ) {
[_delegate connection:self didFailWithError:nil];
}
return nil;
}

-(id) /* use typed version */ start {
[self scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:@"kCFRunLoopDefaultMode"];
return nil;
}

-(id) /* use typed version */ cancel {
return nil;
}

-(id) /* use typed version */ dealloc {
_delegate = nil;
return [super dealloc];
}
#endif

- (id)retain {
    return [super retain];
}

- (void)release {
    [super release];
}

- (id)autorelease {
    return [super autorelease];
}

- (id)_protocol {
    return _protocol;
}

@end
