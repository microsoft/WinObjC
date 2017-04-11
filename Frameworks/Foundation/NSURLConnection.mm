/* Copyright (c) 2006-2007 Christopher J. W. Lloyd
   Copyright (c) Microsoft. All rights reserved.

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

#import "Starboard.h"
#import "Foundation/NSURLProtocol.h"
#import "Foundation/NSURLCache.h"
#import "Foundation/NSMutableData.h"
#import "Foundation/NSError.h"
#import "Foundation/NSRunLoop.h"
#import "Foundation/NSURLConnection.h"
#import "LoggingNative.h"
#import "NSURLProtocolInternal.h"

#import <algorithm>
#import <vector>

static const wchar_t* TAG = L"NSURLConnection";

// Private helper function that returns a NSURLProtocol object capable of handling a NSURLRequest
// Returns nil if one cannot be created
static NSURLProtocol* _protocolForRequest(NSURLRequest* request, id<NSURLProtocolClient> client) {
    Class cls = [NSURLProtocol _URLProtocolClassForRequest:request];
    if (!cls || ![cls canInitWithRequest:request]) {
        return nil;
    }

    return
        [[[cls alloc] initWithRequest:request cachedResponse:[[NSURLCache sharedURLCache] cachedResponseForRequest:request] client:client]
            autorelease];
}

// Private class that acts as a helper for sendAsynchronousRequest: (and by extension, sendSynchronousRequest:)
// Forwards response, data, and error to a completion handler, which is executed on a specified queue.
@interface _NSURLConnection_DataDelegate : NSObject <NSURLConnectionDataDelegate>
+ (instancetype)delegateWithQueue:(NSOperationQueue*)queue handler:(void (^)(NSURLResponse*, NSData*, NSError*))handler;
- (instancetype)initWithQueue:(NSOperationQueue*)queue handler:(void (^)(NSURLResponse*, NSData*, NSError*))handler;
@end

@implementation _NSURLConnection_DataDelegate {
@private
    StrongId<NSOperationQueue> _operationQueue;
    StrongId<void (^)(NSURLResponse*, NSData*, NSError*)> _completionHandler;

    StrongId<NSURLResponse> _response;
    StrongId<NSMutableData> _data;
}

+ (instancetype)delegateWithQueue:(NSOperationQueue*)queue handler:(void (^)(NSURLResponse*, NSData*, NSError*))handler {
    return [[[_NSURLConnection_DataDelegate alloc] initWithQueue:queue handler:handler] autorelease];
}

- (instancetype)initWithQueue:(NSOperationQueue*)queue handler:(void (^)(NSURLResponse*, NSData*, NSError*))handler {
    if (self = [super init]) {
        self->_operationQueue = queue;
        self->_completionHandler = handler;
    }
    return self;
}

- (void)connection:(NSURLConnection*)connection didFailWithError:(NSError*)error {
    [_operationQueue addOperationWithBlock:^void() {
        _completionHandler(_response.get(), nil, error);
    }];
}

- (void)connection:(NSURLConnection*)connection didReceiveResponse:(NSURLResponse*)response {
    // We get some of these for each redirect. Only capture the final one.
    _response = response;
    if (!_data || [_data length] > 0) {
        _data.attach([NSMutableData new]);
    }
}

- (void)connection:(NSURLConnection*)connection didReceiveData:(NSData*)data {
    [_data appendData:data];
}

- (void)connectionDidFinishLoading:(NSURLConnection*)connection {
    [_operationQueue addOperationWithBlock:^void() {
        _completionHandler(_response.get(), _data.get(), nil);
    }];
}

@end

// Actual NSURLConnection implementation
@implementation NSURLConnection {
@private
    StrongId<NSObject<NSURLConnectionDelegate>> _delegate;

    std::vector<std::pair<StrongId<NSRunLoop>, StrongId<NSRunLoopMode>>> _scheduledRunLoops;
    // TODO #2469: Cannot currently schedule on more than one runloop

    StrongId<NSOperationQueue> _delegateQueue; // Lazily initialized

    StrongId<NSURLResponse> _response;
    NSURLCacheStoragePolicy _storagePolicy;
    StrongId<NSURLProtocol> _protocol;

    bool _started;
}

/**
 @Status Interoperable
*/
+ (BOOL)canHandleRequest:(NSURLRequest*)request {
    return [[NSURLProtocol _URLProtocolClassForRequest:request] canInitWithRequest:request];
}

/**
 @Status Caveat
 @Notes NSError returned is not detailed
*/
+ (NSData*)sendSynchronousRequest:(NSURLRequest*)request
                returningResponse:(NSURLResponse* _Nullable*)response
                            error:(NSError* _Nullable*)error {
    if (!request) {
        return nil;
    }

    __block NSData* data = nil;
    __block bool finished = false;
    __block NSCondition* condition = [[NSCondition new] autorelease];
    NSOperationQueue* queue = [[NSOperationQueue new] autorelease];

    [self sendAsynchronousRequest:request
                            queue:queue
                completionHandler:^void(NSURLResponse* innerResponse, NSData* innerData, NSError* innerError) {
                    if (response) {
                        *response = innerResponse ? [innerResponse retain] : nil;
                    }

                    if (error) {
                        *error = innerError ? [innerError retain] : nil;
                    }

                    data = innerData ? [innerData retain] : nil;

                    [condition lock];
                    finished = true;
                    [condition signal];
                    [condition unlock];
                }];

    [condition lock];
    while (!finished) {
        [condition wait];
    }
    [condition unlock];

    // autorelease outside the block for safety in release timing
    if (response) {
        [*response autorelease];
    }

    if (error) {
        [*error autorelease];
    }

    return [data autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)connectionWithRequest:(NSURLRequest*)request delegate:(id)delegate {
    return [[[self alloc] initWithRequest:request delegate:delegate] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithRequest:(NSURLRequest*)request delegate:(id)delegate {
    return [self initWithRequest:request delegate:delegate startImmediately:YES];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithRequest:(NSURLRequest*)request delegate:(id)delegate startImmediately:(BOOL)startImmediately {
    if (self = [super init]) {
        _originalRequest = [request copy];
        _currentRequest = [_originalRequest copy];
        _delegate = delegate;

        if (startImmediately) {
            [self start];
        }
    }
    return self;
}

/**
 @Status Interoperable
*/
+ (void)sendAsynchronousRequest:(NSURLRequest*)request
                          queue:(NSOperationQueue*)queue
              completionHandler:(void (^)(NSURLResponse*, NSData*, NSError*))handler {
    if (request) {
        NSURLConnection* connection = [[[self alloc] initWithRequest:request
                                                            delegate:[_NSURLConnection_DataDelegate delegateWithQueue:queue handler:handler]
                                                    startImmediately:NO] autorelease];
        [connection setDelegateQueue:queue];
        [connection start];
    }
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_originalRequest release];
    [_currentRequest release];
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (void)start {
    @synchronized(self) {
        if (_started) {
            TraceError(TAG, L"[NSURLConnection start] called on a connection that was already started.");
            return;
        }

        _started = true;

        NSURLProtocol* protocol = _protocolForRequest(_currentRequest, self);
        if (!protocol) {
            TraceError(TAG, L"[NSURLConnection start] could not create a NSURLProtocol for its NSURLRequest.");
            return;
        }
        _protocol = protocol;

        if (_delegateQueue) {
            [_delegateQueue addOperationWithBlock:^void() {
                [_protocol startLoading];
            }];

        } else if (_scheduledRunLoops.size() == 1) {
            // TODO #2469: Cannot currently schedule on more than one runloop
            for (auto pair : _scheduledRunLoops) {
                [pair.first performSelector:@selector(startLoading) target:_protocol argument:nil order:0 modes:@[ pair.second.get() ]];
            }

        } else {
            // Run on the current run loop in the default mode
            [[NSRunLoop currentRunLoop] performSelector:@selector(startLoading)
                                                 target:_protocol
                                               argument:nil
                                                  order:0
                                                  modes:@[ NSDefaultRunLoopMode ]];
        }
    }
}

/**
 @Status Caveat
 @Notes  TODO #2469: Cannot currently schedule on more than one runloop
                 Callbacks do not currently occur on scheduled runloop
*/
- (void)scheduleInRunLoop:(NSRunLoop*)aRunLoop forMode:(NSRunLoopMode)mode {
    @synchronized(self) {
        if (_started) {
            TraceError(TAG, L"[NSURLConnection scheduleInRunLoop:] called on a connection that already started.");
            return;
        }

        if (_delegateQueue) {
            [NSException raise:NSInternalInconsistencyException
                        format:@"A connection cannot be scheduled with both an operation queue and a run loop."];
        }

        if (_scheduledRunLoops.size() >= 1) {
            TraceError(TAG, L"NSURLConnection: Scheduling on more than one run loop is currently not supported.");
            return;
        }

        _scheduledRunLoops.emplace_back(aRunLoop, mode);
    }
}

/**
 @Status Caveat
 @Notes  TODO #2469: Callbacks do not currently occur on delegate queue
*/
- (void)setDelegateQueue:(NSOperationQueue*)queue {
    @synchronized(self) {
        if (_started) {
            TraceError(TAG, L"[NSURLConnection setDelegateQueue:] called on a connection that already started.");
            return;
        }

        if (_scheduledRunLoops.size() > 0) {
            [NSException raise:NSInternalInconsistencyException
                        format:@"A connection cannot be scheduled with both an operation queue and a run loop."];
        }

        if (_delegateQueue) {
            TraceError(TAG, L"[NSURLConnection setDelegateQueue:] called on a connection that already had a delegate queue; ignoring.");
            return;
        }

        _delegateQueue = queue;
    }
}

/**
 @Status Caveat
 @Notes  TODO #2469: Cannot currently schedule on more than one runloop
*/
- (void)unscheduleFromRunLoop:(NSRunLoop*)aRunLoop forMode:(NSRunLoopMode)mode {
    @synchronized(self) {
        auto it = std::find_if(_scheduledRunLoops.begin(),
                               _scheduledRunLoops.end(),
                               [aRunLoop](const std::pair<StrongId<NSRunLoop>, StrongId<NSRunLoopMode>>& pair) {
                                   return aRunLoop == pair.first;
                               });
        if (it != _scheduledRunLoops.end()) {
            _scheduledRunLoops.erase(it);
            return;
        }
    }

    TraceError(TAG, L"unscheduleFromRunLoop: specified run loop and mode were not found");
}

/**
 @Status Interoperable
*/
- (void)cancel {
    @synchronized(self) {
        [_protocol stopLoading];
        _protocol = nil;
    }
}

/**
 @Status Interoperable
*/
- (void)URLProtocol:(id)urlProtocol didFailWithError:(id)error {
    TraceError(TAG, L"URL protocol did fail");
    // if ( [_delegate respondsToSelector:@selector(connection:willSendRequest:redirectResponse:)] ) [_delegate
    // connection:self willSendRequest:_request redirectResponse:nil];
    if ([_delegate respondsToSelector:@selector(connection:didFailWithError:)]) {
        [_delegate connection:self didFailWithError:error];
    }

    _protocol = nil;
    _delegate = nil;
}

/**
 @Status Interoperable
*/
- (void)URLProtocol:(id)urlProtocol didReceiveResponse:(NSURLResponse*)response cacheStoragePolicy:(NSURLCacheStoragePolicy)policy {
    /*
    if ( [response respondsToSelector:@selector(statusCode)] && [response statusCode] != 200 ) {
    [_delegate setError:[NSError errorWithDomain:@"Bad response code" code:[response statusCode] userInfo:nil]];
    }
    */

    _response = response;
    _storagePolicy = policy;

    if ([_delegate respondsToSelector:@selector(connection:willCacheResponse:)]) {
        // TODO #2469: This is currently incorrect, these are not the same thing
        [_delegate connection:self willCacheResponse:static_cast<NSCachedURLResponse*>(response)];
    }
    if ([_delegate respondsToSelector:@selector(connection:didReceiveResponse:)]) {
        [_delegate connection:self didReceiveResponse:response];
    }
}

/**
 @Status Interoperable
*/
- (void)URLProtocol:(id)urlProtocol didLoadData:(id)data {
    if ([_delegate respondsToSelector:@selector(connection:didReceiveData:)]) {
        [_delegate connection:self didReceiveData:data];
    }
}

/**
 @Status Interoperable
*/
- (void)URLProtocolDidFinishLoading:(id)urlProtocol {
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

    _protocol = nil;
    _delegate = nil;
}

/**
 @Status Interoperable
*/
- (void)URLProtocol:(id)urlProtocol didReceiveAuthenticationChallenge:(id)challenge {
    if ([_delegate respondsToSelector:@selector(connection:willSendRequestForAuthenticationChallenge:)]) {
        [_delegate connection:self willSendRequestForAuthenticationChallenge:challenge];
    } else {
        [_delegate connection:self didReceiveAuthenticationChallenge:challenge];
    }
}

/**
 @Status Interoperable
*/
- (void)URLProtocol:(NSURLProtocol*)urlProtocol wasRedirectedToRequest:(NSURLRequest*)request redirectResponse:(NSURLResponse*)response {
    [_protocol stopLoading];
    NSURLRequest* newRequest = request;
    if ([_delegate respondsToSelector:@selector(connection:willSendRequest:redirectResponse:)]) {
        newRequest = [_delegate connection:self willSendRequest:request redirectResponse:response];
    }
    _protocol = nil;

    if (!newRequest) {
        [self cancel];
        return;
    }

    NSURLProtocol* protocol = _protocolForRequest(request, self);
    if (!protocol) {
        TraceError(TAG, L"NSURLConnection was redirected to a new request, but could not create a NSURLProtocol for the new request.");
        return;
    }
    _protocol = protocol;
    _currentRequest = newRequest;
    [_protocol startLoading];
}

/**
 @Status Stub
 @Notes
*/
- (void)URLProtocol:(NSURLProtocol*)protocol cachedResponseIsValid:(NSCachedURLResponse*)cachedResponse {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)URLProtocol:(NSURLProtocol*)protocol didCancelAuthenticationChallenge:(NSURLAuthenticationChallenge*)challenge {
    UNIMPLEMENTED();
}

@end
