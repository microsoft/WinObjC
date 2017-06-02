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

#import <NSRunLoopSource.h>

#import <algorithm>
#import <atomic>
#import <vector>

static const wchar_t* TAG = L"NSURLConnection";

// Private helper function that returns a NSURLProtocol object capable of handling a NSURLRequest
// Returns nil if one cannot be created
static NSURLProtocol* __protocolForRequest(NSURLRequest* request, id<NSURLProtocolClient> client) {
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
        _operationQueue = queue;
        _completionHandler = handler;
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
@interface NSURLConnection () <_NSURLProtocolClientInternal> {
@private
    StrongId<NSObject<NSURLConnectionDelegate>> _delegate;

    std::vector<std::pair<StrongId<NSRunLoop>, StrongId<NSRunLoopMode>>> _scheduledRunLoops;

    StrongId<NSOperationQueue> _delegateQueue; // Lazily initialized

    StrongId<NSURLResponse> _response;
    StrongId<NSURLProtocol> _protocol;

    StrongId<NSRunLoopSource> _runLoopCancelSource;
    StrongId<NSThread> _protocolThread;
    bool _started;
    bool _done;
}
@end

@implementation NSURLConnection

// Helper function that executes a block on the delegate queue or scheduled run loops - used for delegate callbacks
static void __dispatchDelegateCallback(NSURLConnection* connection, void (^callbackBlock)()) {
    if (connection->_delegateQueue) {
        [connection->_delegateQueue addOperationWithBlock:callbackBlock];

    } else if (connection->_scheduledRunLoops.size() > 0) {
        for (auto pair : connection->_scheduledRunLoops) {
            [pair.first performSelector:@selector(invoke) target:callbackBlock argument:nil order:0 modes:@[ pair.second.get() ]];
        }
    }
}

// Body of the thread on which the NSURLProtocol loads
- (void)_protocolThreadBody {
    NSRunLoop* currentRunLoop = [NSRunLoop currentRunLoop];
    [currentRunLoop _addInputSource:_runLoopCancelSource forMode:NSDefaultRunLoopMode];
    while (!_done) {
        [currentRunLoop runUntilDate:[NSDate distantFuture]];
    }
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
                        *response = [innerResponse retain];
                    }

                    if (error) {
                        *error = [innerError retain];
                    }

                    data = [innerData retain];

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
        _runLoopCancelSource.attach([NSRunLoopSource new]);

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

        if ((!_delegateQueue) && (_scheduledRunLoops.empty())) {
            // Run on the current run loop in the default mode
            [self scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
        }

        _started = true;

        NSURLProtocol* protocol = __protocolForRequest(_currentRequest, self);
        if (!protocol) {
            TraceError(TAG, L"[NSURLConnection start] could not create a NSURLProtocol for its NSURLRequest.");
            return;
        }
        _protocol = protocol;

        _protocolThread.attach([[NSThread alloc] initWithTarget:self selector:@selector(_protocolThreadBody) object:nil]);
        [_protocolThread start];

        [_protocol performSelector:@selector(startLoading) onThread:_protocolThread withObject:nil waitUntilDone:NO];
    }
}

/**
 @Status Interoperable
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

        _scheduledRunLoops.emplace_back(aRunLoop, mode);
    }
}

/**
 @Status Interoperable
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
 @Status Interoperable
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

        [_runLoopCancelSource _trigger];
    }
}

/**
 @Status Interoperable
*/
- (void)URLProtocol:(NSURLProtocol*)urlProtocol didFailWithError:(NSError*)error {
    auto delegateCount = std::make_shared<std::atomic<uint>>(std::max(_scheduledRunLoops.size(), 1u));

    __dispatchDelegateCallback(self, ^void() {
        TraceError(TAG, L"URL protocol did fail");
        // if ( [_delegate respondsToSelector:@selector(connection:willSendRequest:redirectResponse:)] ) [_delegate
        // connection:self willSendRequest:_request redirectResponse:nil];
        if ([_delegate respondsToSelector:@selector(connection:didFailWithError:)]) {
            [_delegate connection:self didFailWithError:error];
        }

        if (--(*delegateCount) == 0) {
            _protocol = nil;
            _delegate = nil;
            _done = true;
            [_runLoopCancelSource _trigger];
        }
    });
}

/**
 @Status Interoperable
*/
- (void)URLProtocol:(NSURLProtocol*)urlProtocol
    didReceiveResponse:(NSURLResponse*)response
    cacheStoragePolicy:(NSURLCacheStoragePolicy)policy {
    auto delegateCount = std::make_shared<std::atomic<uint>>(std::max(_scheduledRunLoops.size(), 1u));

    __block StrongId<NSCachedURLResponse> cachedResponse;
    if (policy != NSURLCacheStorageNotAllowed) {
        cachedResponse.attach([[NSCachedURLResponse alloc] initWithResponse:response data:nil]);
    }

    __dispatchDelegateCallback(self, ^void() {
        /*
        if ( [response respondsToSelector:@selector(statusCode)] && [response statusCode] != 200 ) {
        [_delegate setError:[NSError errorWithDomain:@"Bad response code" code:[response statusCode] userInfo:nil]];
        }
        */

        _response = response;

        if (cachedResponse && [_delegate respondsToSelector:@selector(connection:willCacheResponse:)]) {
            cachedResponse = [_delegate connection:self willCacheResponse:cachedResponse];
        }

        if (cachedResponse && (--(*delegateCount) == 0)) {
            [[NSURLCache sharedURLCache] storeCachedResponse:cachedResponse forRequest:_currentRequest];
        }

        if ([_delegate respondsToSelector:@selector(connection:didReceiveResponse:)]) {
            [_delegate connection:self didReceiveResponse:response];
        }
    });
}

/**
 @Status Interoperable
*/
- (void)URLProtocol:(NSURLProtocol*)urlProtocol didLoadData:(NSData*)data {
    __dispatchDelegateCallback(self, ^void() {
        if ([_delegate respondsToSelector:@selector(connection:didReceiveData:)]) {
            [_delegate connection:self didReceiveData:data];
        }
    });
}

/**
 @Status Interoperable
*/
- (void)URLProtocolDidFinishLoading:(NSURLProtocol*)urlProtocol {
    auto delegateCount = std::make_shared<std::atomic<uint>>(std::max(_scheduledRunLoops.size(), 1u));

    __dispatchDelegateCallback(self, ^void() {
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
            [_delegate connectionDidFinishLoading:self];
        }

        if (--(*delegateCount) == 0) {
            _protocol = nil;
            _delegate = nil;
            _done = true;
            [_runLoopCancelSource _trigger];
        }
    });
}

/**
 @Status Interoperable
*/
- (void)URLProtocol:(NSURLProtocol*)urlProtocol didReceiveAuthenticationChallenge:(NSURLAuthenticationChallenge*)challenge {
    __dispatchDelegateCallback(self, ^void() {
        if ([_delegate respondsToSelector:@selector(connection:willSendRequestForAuthenticationChallenge:)]) {
            [_delegate connection:self willSendRequestForAuthenticationChallenge:challenge];
        } else {
            [_delegate connection:self didReceiveAuthenticationChallenge:challenge];
        }
    });
}

/**
 @Status Interoperable
*/
- (void)URLProtocol:(NSURLProtocol*)urlProtocol wasRedirectedToRequest:(NSURLRequest*)request redirectResponse:(NSURLResponse*)response {
    __block StrongId<NSURLRequest> newRequest = request;

    auto delegateCount = std::make_shared<std::atomic<uint>>(std::max(_scheduledRunLoops.size(), 1u));
    auto stoppedLoading = std::make_shared<std::atomic<uint>>(0);

    __dispatchDelegateCallback(self, ^void() {
        // Call stop loading on the delegate thread to preserve callback ordering, only call it once though
        if (stoppedLoading->fetch_add(1) == 0) {
            [_protocol stopLoading];
        }

        if ([_delegate respondsToSelector:@selector(connection:willSendRequest:redirectResponse:)]) {
            newRequest = [_delegate connection:self willSendRequest:newRequest redirectResponse:response];
        }

        if (--(*delegateCount) == 0) {
            _protocol = nil;

            if (!newRequest) {
                [self cancel];
                return;
            }

            NSURLProtocol* protocol = __protocolForRequest(request, self);
            if (!protocol) {
                TraceError(TAG,
                           L"NSURLConnection was redirected to a new request, but could not create a NSURLProtocol for the new request.");
                return;
            }

            _protocol = protocol;
            _currentRequest = newRequest;
            [_protocol performSelector:@selector(startLoading) onThread:_protocolThread withObject:nil waitUntilDone:NO];
        }
    });
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

- (void)URLProtocol:(NSURLProtocol*)protocol
                 didWriteData:(NSInteger)bytesWritten
            totalBytesWritten:(NSInteger)totalBytesWritten
    totalBytesExpectedToWrite:(NSInteger)totalBytesExpectedToWrite {
    __dispatchDelegateCallback(self, ^void() {
        if ([_delegate respondsToSelector:@selector(connection:didSendBodyData:totalBytesWritten:totalBytesExpectedToWrite:)]) {
            [_delegate connection:self
                          didSendBodyData:bytesWritten
                        totalBytesWritten:totalBytesWritten
                totalBytesExpectedToWrite:totalBytesExpectedToWrite];
        } else if ([_delegate respondsToSelector:@selector(connection:didWriteData:totalBytesWritten:expectedTotalBytes:)]) {
            [_delegate connection:self
                             didWriteData:bytesWritten
                        totalBytesWritten:totalBytesWritten
                totalBytesExpectedToWrite:totalBytesExpectedToWrite];
        }
    });
}

@end
