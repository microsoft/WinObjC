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

#import <Foundation/Foundation.h>
#import <Starboard.h>
#import "NSURLSessionTask-Internal.h"

const float NSURLSessionTaskPriorityHigh = 1.0f;
const float NSURLSessionTaskPriorityDefault = 0.5f;
const float NSURLSessionTaskPriorityLow = 0.0f;

@interface NSURLSessionTask () {
    NSURLProtocol* _protocolConnection;
    NSURLSessionConfiguration* _configuration;
    NSThread* _initialThread;
}
@end

@implementation NSURLSessionTask
@synthesize _taskDelegate = _taskDelegate;

+ (Class)_protocolClassForRequest:(NSURLRequest*)request {
    return [NSURLProtocol _URLProtocolClassForRequest:request];
}

- (id)_initWithTaskDelegate:(id<_NSURLSessionTaskDelegate>)taskDelegate configuration:(NSURLSessionConfiguration*)configuration request:(NSURLRequest*)request {
    if (self = [super init]) {
        _taskDelegate = taskDelegate;
        _configuration = [configuration retain];

        NSMutableURLRequest* newRequest = [request mutableCopy];

        [newRequest setCachePolicy:configuration.requestCachePolicy];
        [newRequest setTimeoutInterval:configuration.timeoutIntervalForRequest];
        [newRequest setHTTPShouldHandleCookies:configuration.HTTPShouldSetCookies];
        [newRequest setHTTPShouldUsePipelining:configuration.HTTPShouldUsePipelining];
        for (NSString* headerField in configuration.HTTPAdditionalHeaders) {
            [newRequest setValue:configuration.HTTPAdditionalHeaders[headerField] forHTTPHeaderField:headerField];
        }

        // TODO: Propagate all NSURLSessionConfiguration values.
        // Right now, NSURLRequest just doesn't support many of them.

        _currentRequest = newRequest;
        _originalRequest = [newRequest copy];

        _priority = NSURLSessionTaskPriorityDefault;
        _state = NSURLSessionTaskStateSuspended;

        _countOfBytesExpectedToReceive = NSURLSessionTransferSizeUnknown;
        _countOfBytesExpectedToSend = NSURLSessionTransferSizeUnknown;
    }
    return self;
}

- (void)dealloc {
    [_taskDescription release];
    [_currentRequest release];
    [_originalRequest release];
    [_response release];
    [_error release];
    [_configuration release];
    [_protocolConnection release];
    [_initialThread release];
    [super dealloc];
}

- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

- (NSCachedURLResponse*)_cachedResponseFromConfiguration {
    return [_configuration.URLCache cachedResponseForRequest:_currentRequest];
}

- (void)_updateWithURLResponse:(NSURLResponse*)response {
    self.response = response;
    self.countOfBytesExpectedToReceive = _response.expectedContentLength;
}

- (void)_signalCompletionInState:(NSURLSessionTaskState)state withError:(NSError*)error {
    self.error = error;
    self.state = state;

    [_taskDelegate task:self didCompleteWithError:self.error];

    [_protocolConnection release];
    _protocolConnection = nil;
}

/*
@Status Interoperable
*/
- (void)resume {
    @synchronized(self) {
        if (_state == NSURLSessionTaskStateRunning) {
            return;
        }

        if (!_initialThread) {
            _initialThread = [[NSThread currentThread] retain];
        }
        [self _startLoading];
        self.state = NSURLSessionTaskStateRunning;
    }
}

- (void)__startLoadingThread {
    if (!_protocolConnection) {
        Class protocolClass = [[self class] _protocolClassForRequest:_currentRequest];
        if (!protocolClass || ![protocolClass canInitWithRequest:_currentRequest]) {
            NSError* error = [NSError errorWithDomain:NSCocoaErrorDomain code:0 userInfo:@{
                NSLocalizedDescriptionKey: [NSString stringWithFormat:@"Unable to find a protocol handler for `%@`.", [_currentRequest.URL scheme]],
            }];
            [self _signalCompletionInState:NSURLSessionTaskStateCompleted withError:error];
            return;
        }

        NSCachedURLResponse* cachedResponse = [self _cachedResponseFromConfiguration];
        _protocolConnection = [[protocolClass alloc] initWithRequest:_currentRequest cachedResponse:cachedResponse client:self];
    }

    [_protocolConnection startLoading];
}

- (void)_startLoading {
    [self performSelector:@selector(__startLoadingThread) onThread:_initialThread withObject:nil waitUntilDone:NO];
}

/*
@Status Interoperable
*/
- (void)cancel {
    @synchronized(self) {
        if (_state != NSURLSessionTaskStateRunning) {
            return;
        }

        [self _stopLoading];
    }
    [self _signalCompletionInState:NSURLSessionTaskStateCanceling withError:nil];
}

- (void)_stopLoading {
    [_protocolConnection stopLoading];
    _protocolConnection = nil;
}

/*
@Status Stub
*/
- (void)suspend {
    @synchronized(self) {
        if (_state == NSURLSessionTaskStateSuspended) {
            return;
        }
        UNIMPLEMENTED();
    }
}

- (void)URLProtocol:(NSURLProtocol*)connection didReceiveResponse:(NSURLResponse*)response cacheStoragePolicy:(NSURLCacheStoragePolicy)policy {
    // TODO: Some of our URL machinery will leak data before a redirect
    // we don't want to count that data.

    self.countOfBytesReceived = 0;
    [self _updateWithURLResponse:response];
}

- (void)URLProtocol:(NSURLProtocol*)connection didFailWithError:(NSError*)error {
    [self _signalCompletionInState:NSURLSessionTaskStateCompleted withError:error];
}

- (void)URLProtocol:(NSURLProtocol*)connection didReceiveAuthenticationChallenge:(NSURLAuthenticationChallenge*)challenge {
    auto continuation = ^(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential) {
        switch (disposition) {
            case NSURLSessionAuthChallengeUseCredential:
                [challenge.sender useCredential:credential forAuthenticationChallenge:challenge];
                break;
            case NSURLSessionAuthChallengePerformDefaultHandling:
                [challenge.sender continueWithoutCredentialForAuthenticationChallenge:challenge];
                break;
            case NSURLSessionAuthChallengeCancelAuthenticationChallenge:
                [challenge.sender cancelAuthenticationChallenge:challenge];
                break;
            case NSURLSessionAuthChallengeRejectProtectionSpace:
                [challenge.sender rejectProtectionSpaceAndContinueWithChallenge:challenge];
                break;
        }
    };
    [_taskDelegate task:self didReceiveChallenge:challenge completionHandler:continuation];
}

- (void)URLProtocol:(NSURLProtocol*)connection didCancelAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge {
    [self cancel];
}

- (void)URLProtocol:(NSURLProtocol*)connection cachedResponseIsValid:(NSCachedURLResponse*)cachedResponse {
}

- (void)URLProtocol:(NSURLProtocol*)connection wasRedirectedToRequest:(NSURLRequest*)request redirectResponse:(NSURLResponse*)response {
    auto continuation = ^(NSURLRequest* sessionNewRequest) {
        @synchronized (self) {
            [self _stopLoading];
            self.currentRequest = sessionNewRequest;
            [self _startLoading];
        }
    };

    [_taskDelegate
                              task:self
        willPerformHTTPRedirection:(NSHTTPURLResponse*)response
                        newRequest:request
                 completionHandler:continuation];
};

- (void)URLProtocol:(NSURLProtocol*)connection didLoadData:(NSData*)data {
    self.countOfBytesReceived = self.countOfBytesReceived + [data length];
}

- (void)URLProtocolDidFinishLoading:(NSURLProtocol*)connection {
    [self _signalCompletionInState:NSURLSessionTaskStateCompleted withError:nil];
}

@end
