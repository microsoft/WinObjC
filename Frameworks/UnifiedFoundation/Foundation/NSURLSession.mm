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
#import <functional>
#import <Starboard.h>
#import <Windows.h>

#import <map>
#import <mutex>
#import <condition_variable>

#import "NSRunLoopSource.h"
#import "NSURLSession-Internal.h"
#import "NSURLSessionTask-Internal.h"

const int64_t NSURLSessionTransferSizeUnknown = -1LL;

template <typename... Args>
static bool dispatchDelegateOptional(NSOperationQueue* queue, id object, SEL cmd, Args... args) {
    if (object && [object respondsToSelector:cmd]) {
        // does not currently support forwarding implementations
        // just like our objective-c runtime :(
        auto imp = class_getMethodImplementation(object_getClass(object), cmd);
        [queue addOperationWithBlock:^{
            reinterpret_cast<void (*)(id, SEL, Args...)>(imp)(object, cmd, args...);
        }];
        return true;
    }
    return false;
}

// LINKER STUB
@implementation NSURLSessionUploadTask
@end

@interface _NSURLSessionInflightTaskInfo : NSObject {
    NSURLSessionTask* _task;
    NSURLSessionTaskCompletionHandler _taskCompletionHandler;
    NSURLSessionDownloadTaskCompletionHandler _downloadCompletionHandler;
    NSMutableData* _accumulatedData;
    NSURLResponse* _response;
}
- (instancetype)initWithTask:(NSURLSessionTask*)task taskCompletionHandler:(NSURLSessionTaskCompletionHandler)taskCompletionHandler;
- (instancetype)initWithTask:(NSURLSessionTask*)task
   downloadCompletionHandler:(NSURLSessionDownloadTaskCompletionHandler)downloadCompletionHandler;
- (void)dispatchTaskCompletionHandler;
- (void)dispatchDownloadCompletionHandlerForURL:(NSURL*)url;
- (void)accumulateData:(NSData*)data;
@end

@implementation _NSURLSessionInflightTaskInfo
- (instancetype)initWithTask:(NSURLSessionTask*)task taskCompletionHandler:(NSURLSessionTaskCompletionHandler)taskCompletionHandler {
    if (self = [self init]) {
        _task = [task retain];
        _taskCompletionHandler = [taskCompletionHandler copy];
    }
    return self;
}

- (instancetype)initWithTask:(NSURLSessionTask*)task
   downloadCompletionHandler:(NSURLSessionDownloadTaskCompletionHandler)downloadCompletionHandler {
    if (self = [self init]) {
        _task = [task retain];
        _downloadCompletionHandler = [downloadCompletionHandler copy];
    }
    return self;
}

- (void)dealloc {
    [_task release];
    [_taskCompletionHandler release];
    [_downloadCompletionHandler release];
    [_accumulatedData release];
    [_response release];
    [super dealloc];
}

- (void)dispatchTaskCompletionHandler {
    if (_taskCompletionHandler) {
        _taskCompletionHandler(_accumulatedData, _task.response, _task.error);
    }
}
- (void)dispatchDownloadCompletionHandlerForURL:(NSURL*)url {
    if (_downloadCompletionHandler) {
        _downloadCompletionHandler(url, _task.response, _task.error);
    }
}
- (void)accumulateData:(NSData*)data {
    if (!_accumulatedData) {
        _accumulatedData = [data mutableCopy];
    } else {
        [_accumulatedData appendData:data];
    }
}
@end

@interface NSURLSession () <_NSURLSessionTaskDelegate> {
    std::map<id, idretaint<_NSURLSessionInflightTaskInfo>> _inflightTasks;
    NSMutableSet* _allTasks;

    bool _invalidating;
    std::mutex _mutex;
    std::condition_variable _taskRemovalCondition;

    NSThread *_taskDispatchThread;
    NSRunLoopSource *_runLoopCancelSource;

    uint32_t _threadInitializedFuse;
}
@property (readwrite, copy) NSURLSessionConfiguration* configuration;
@property (readwrite, retain) id<NSURLSessionDelegate> delegate;
@property (readwrite, retain) NSOperationQueue* delegateQueue;
- (instancetype)initWithConfiguration:(NSURLSessionConfiguration*)configuration
                             delegate:(id<NSURLSessionDelegate>)delegate
                        delegateQueue:(NSOperationQueue*)operationQueue;
@end

@implementation NSURLSession
/* Session Creation */
/**
@Status Interoperable
*/
+ (instancetype)sharedSession {
    // Construct on First Use: C++11 guarantees one total order for static init.
    static NSURLSession* sharedSession = [[NSURLSession alloc] initWithConfiguration:nil delegate:nil delegateQueue:nil];
    return sharedSession;
}

/**
@Status Interoperable
*/
+ (instancetype)sessionWithConfiguration:(NSURLSessionConfiguration*)configuration {
    return [self sessionWithConfiguration:configuration delegate:nil delegateQueue:nil];
}

/**
@Status Interoperable
*/
+ (instancetype)sessionWithConfiguration:(NSURLSessionConfiguration*)configuration
                                delegate:(id<NSURLSessionDelegate>)delegate
                           delegateQueue:(NSOperationQueue*)operationQueue {
    return [[[self alloc] initWithConfiguration:configuration delegate:delegate delegateQueue:operationQueue] autorelease];
}

/**
@Status Interoperable
*/
- (instancetype)initWithConfiguration:(NSURLSessionConfiguration*)configuration
                             delegate:(id<NSURLSessionDelegate>)delegate
                        delegateQueue:(NSOperationQueue*)operationQueue {
    if (self = [super init]) {
        if (!configuration) {
            configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
        }

        // configuration is copied by the copy setter
        self.configuration = configuration;

        self.delegate = delegate;

        if (!operationQueue) {
            // If the caller does not specify a delegate queue,
            // we have to use a serial queue for API compliance.
            operationQueue = [[NSOperationQueue alloc] init];
            [operationQueue setMaxConcurrentOperationCount:1];
        }

        self.delegateQueue = operationQueue;

        _allTasks = [[NSMutableSet alloc] init];
    }
    return self;
}

- (void)dealloc {
    [_configuration release];
    [_delegate release];
    [_delegateQueue release];
    [_allTasks release];
    [_taskDispatchThread release];
    [_runLoopCancelSource release];
    [super dealloc];
}

- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

- (void)_ensureTaskDispatchThreadIsRunning {
    // TODO(DH): this should be an atomic<bool>, but atomics require an intrinsic we can't emit right now.
    if(InterlockedCompareExchange(&_threadInitializedFuse, 0x1, 0x0) == 0x0) {
        _runLoopCancelSource = [[NSRunLoopSource alloc] init];
        _taskDispatchThread = [[NSThread alloc] initWithTarget:self selector:@selector(_taskDispatchThreadBody:) object:nil];
        [_taskDispatchThread start];
    }
}

- (void)_taskDispatchThreadBody:(id)sender {
    NSRunLoop* currentRunLoop = [NSRunLoop currentRunLoop];
    [currentRunLoop addInputSource:_runLoopCancelSource forMode:@"kCFRunLoopDefaultMode"];
    while(!_invalidating) {
        [currentRunLoop runUntilDate:[NSDate distantFuture]];
    }
}

- (NSThread*)_taskDispatchThread {
    return _taskDispatchThread;
}

- (void)_dispatchUnsupportedFailureToCompletionBlock:(NSURLSessionTaskCompletionHandler)completionHandler {
    [self task:nil didCompleteWithError:[NSError errorWithDomain:NSCocoaErrorDomain code:0 userInfo:nil]];
}

- (void)_registerDataTask:(NSURLSessionTask*)task withCompletionHandler:(NSURLSessionTaskCompletionHandler)completionHandler {
    std::lock_guard<std::mutex> lock(_mutex);
    if (completionHandler) {
        _NSURLSessionInflightTaskInfo* inflightTask =
            [[[_NSURLSessionInflightTaskInfo alloc] initWithTask:task taskCompletionHandler:completionHandler] autorelease];
        _inflightTasks[task] = inflightTask;
    }

    [_allTasks addObject:task];
    [self _ensureTaskDispatchThreadIsRunning];
}

- (void)_registerDownloadTask:(NSURLSessionTask*)task withCompletionHandler:(NSURLSessionDownloadTaskCompletionHandler)completionHandler {
    std::lock_guard<std::mutex> lock(_mutex);

    if (completionHandler) {
        _NSURLSessionInflightTaskInfo* inflightTask =
            [[[_NSURLSessionInflightTaskInfo alloc] initWithTask:task downloadCompletionHandler:completionHandler] autorelease];
        _inflightTasks[task] = inflightTask;
    }

    [_allTasks addObject:task];
    [self _ensureTaskDispatchThreadIsRunning];
}

- (void)_deregisterTask:(NSURLSessionTask*)task {
    std::lock_guard<std::mutex> lock(_mutex);

    _inflightTasks.erase(task);
    [_allTasks removeObject:task];

    _taskRemovalCondition.notify_all();
}

- (_NSURLSessionInflightTaskInfo*)_inflightDataForTask:(NSURLSessionTask*)task {
    std::lock_guard<std::mutex> lock(_mutex);
    return _inflightTasks[task];
}

- (bool)_isTaskBlockBased:(NSURLSessionTask*)task {
    std::lock_guard<std::mutex> lock(_mutex);
    return _inflightTasks.find(task) != _inflightTasks.end();
}

/* Task Creation */
/**
@Status Interoperable
*/
- (NSURLSessionDataTask*)dataTaskWithURL:(NSURL*)url {
    return [self dataTaskWithRequest:[NSURLRequest requestWithURL:url] completionHandler:nil];
}

/**
@Status Interoperable
*/
- (NSURLSessionDataTask*)dataTaskWithURL:(NSURL*)url completionHandler:(NSURLSessionTaskCompletionHandler)completionHandler {
    return [self dataTaskWithRequest:[NSURLRequest requestWithURL:url] completionHandler:completionHandler];
}

/**
@Status Interoperable
*/
- (NSURLSessionDataTask*)dataTaskWithRequest:(NSURLRequest*)request {
    return [self dataTaskWithRequest:request completionHandler:nil];
}

/**
@Status Interoperable
*/
- (NSURLSessionDataTask*)dataTaskWithRequest:(NSURLRequest*)request completionHandler:(NSURLSessionTaskCompletionHandler)completionHandler {
    if (_invalidating) {
        return nil;
    }

    NSURLSessionDataTask* newTask = [[NSURLSessionDataTask alloc] _initWithTaskDelegate:self configuration:_configuration request:request];
    [self _registerDataTask:newTask withCompletionHandler:completionHandler];
    return newTask;
}

/**
@Status Interoperable
*/
- (NSURLSessionDownloadTask*)downloadTaskWithURL:(NSURL*)url {
    return [self downloadTaskWithRequest:[NSURLRequest requestWithURL:url] completionHandler:nil];
}

/**
@Status Interoperable
*/
- (NSURLSessionDownloadTask*)downloadTaskWithURL:(NSURL*)url
                               completionHandler:(NSURLSessionDownloadTaskCompletionHandler)completionHandler {
    return [self downloadTaskWithRequest:[NSURLRequest requestWithURL:url] completionHandler:completionHandler];
}

/**
@Status Interoperable
*/
- (NSURLSessionDownloadTask*)downloadTaskWithRequest:(NSURLRequest*)request {
    return [self downloadTaskWithRequest:request completionHandler:nil];
}

/**
@Status Interoperable
*/
- (NSURLSessionDownloadTask*)downloadTaskWithRequest:(NSURLRequest*)request
                                   completionHandler:(NSURLSessionDownloadTaskCompletionHandler)completionHandler {
    if (_invalidating) {
        return nil;
    }

    NSURLSessionDownloadTask* newTask =
        [[NSURLSessionDownloadTask alloc] _initWithTaskDelegate:self configuration:_configuration request:request];
    [self _registerDownloadTask:newTask withCompletionHandler:completionHandler];
    return newTask;
}

/**
@Status Interoperable
*/
- (NSURLSessionDownloadTask*)downloadTaskWithResumeData:(NSData*)resumeData {
    return [self downloadTaskWithResumeData:resumeData completionHandler:nil];
}

/**
@Status Interoperable
*/
- (NSURLSessionDownloadTask*)downloadTaskWithResumeData:(NSData*)resumeData
                                      completionHandler:(NSURLSessionDownloadTaskCompletionHandler)completionHandler {
    if (_invalidating) {
        return nil;
    }

    NSURLSessionDownloadTask* newTask =
        [[NSURLSessionDownloadTask alloc] _initWithTaskDelegate:self configuration:_configuration resumeData:resumeData];
    [self _registerDownloadTask:newTask withCompletionHandler:completionHandler];
    return newTask;
}

/**
@Status Interoperable
*/
- (NSURLSessionUploadTask*)uploadTaskWithRequest:(NSURLRequest*)request fromData:(NSData*)data {
    return [self uploadTaskWithRequest:request fromData:data completionHandler:nil];
}

/**
@Status Stub
*/
- (NSURLSessionUploadTask*)uploadTaskWithRequest:(NSURLRequest*)request
                                        fromData:(NSData*)data
                               completionHandler:(NSURLSessionTaskCompletionHandler)completionHandler {
    if (_invalidating) {
        return nil;
    }

    // stream data?
    UNIMPLEMENTED();
    [self _dispatchUnsupportedFailureToCompletionBlock:completionHandler];
    return nil;
}

/**
@Status Interoperable
*/
- (NSURLSessionUploadTask*)uploadTaskWithRequest:(NSURLRequest*)request fromFile:(NSURL*)fileURL {
    return [self uploadTaskWithRequest:request fromFile:fileURL completionHandler:nil];
}

/**
@Status Stub
*/
- (NSURLSessionUploadTask*)uploadTaskWithRequest:(NSURLRequest*)request
                                        fromFile:(NSURL*)fileURL
                               completionHandler:(NSURLSessionTaskCompletionHandler)completionHandler {
    if (_invalidating) {
        return nil;
    }

    UNIMPLEMENTED();
    [self _dispatchUnsupportedFailureToCompletionBlock:completionHandler];
    return nil;
}

/**
@Status Stub
*/
- (NSURLSessionUploadTask*)uploadTaskWithStreamedRequest:(NSURLRequest*)request {
    if (_invalidating) {
        return nil;
    }

    UNIMPLEMENTED();
    [self _dispatchUnsupportedFailureToCompletionBlock:nil];
    return nil;
}

/**
@Status Interoperable
*/
- (void)finishTasksAndInvalidate {
    [self _beginInvalidation];
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),
                   ^{
                       [self _waitForTasks];
                       [self _completeInvalidation];
                   });
}

- (void)_waitForTasks {
    std::unique_lock<std::mutex> lock(_mutex);
    _taskRemovalCondition.wait(lock, [&]() { return [_allTasks count] == 0; });
    lock.unlock();
}

/**
@Status Interoperable
*/
- (void)invalidateAndCancel {
    // We may be sending a signal to our final referenceholder
    // that could cause them to destroy us.
    [self retain];

    [self _beginInvalidation];

    std::unique_lock<std::mutex> lock(_mutex);
    NSSet* tasksToCancel = [_allTasks copy];
    lock.unlock();

    [self _completeInvalidation];

    for (NSURLSessionTask* task in tasksToCancel) {
        [task cancel];
    }

    [self release];
}

- (void)_beginInvalidation {
    std::lock_guard<std::mutex> lock(_mutex);
    _invalidating = true;
}

- (void)_completeInvalidation {
    std::lock_guard<std::mutex> lock(_mutex);

    dispatchDelegateOptional(_delegateQueue, _delegate, @selector(URLSession:didBecomeInvalidWithError:), self, nil);

    self.delegate = nil;
    self.delegateQueue = nil;

    [_runLoopCancelSource _trigger];
}

/**
@Status Caveat
@Notes Does not flush cache, cookies, or credentials yet. Does not switch to new socket.
*/
- (void)flushWithCompletionHandler:(void (^)(void))completionHandler {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),
                   ^{
                       std::lock_guard<std::mutex> lock(_mutex);

                       // These three do not have corresponding APIs yet.
                       //[_configuration.URLCache _flush];
                       //[_configuration.HTTPCookieStorage _flush];
                       //[_configuration.URLCredentialStorage _flush];

                       [_delegateQueue addOperationWithBlock:completionHandler];
                   });
}

/**
@Status Caveat
@Notes Does not erase cookies or credentials yet. Does not switch to new socket.
*/
- (void)resetWithCompletionHandler:(void (^)(void))completionHandler {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),
                   ^{
                       std::lock_guard<std::mutex> lock(_mutex);

                       [_configuration.URLCache removeAllCachedResponses];
                       // These two do not have corresponding APIs yet.
                       //[_configuration.HTTPCookieStorage _removeAllCookies];
                       //[_configuration.URLCredentialStorage _removeAllCredentials];

                       [_delegateQueue addOperationWithBlock:completionHandler];
                   });
}

/**
@Status Interoperable
*/
- (void)getTasksWithCompletionHandler:(void (^)(NSArray* dataTasks, NSArray* uploadTasks, NSArray* downloadTasks))completionHandler {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),
                   ^{
                       std::lock_guard<std::mutex> lock(_mutex);

                       NSMutableArray* dataTasks = [NSMutableArray array];
                       NSMutableArray* uploadTasks = [NSMutableArray array];
                       NSMutableArray* downloadTasks = [NSMutableArray array];

                       for (NSURLSessionTask* task in _allTasks) {
                           if ([task isKindOfClass:[NSURLSessionDataTask class]]) {
                               [dataTasks addObject:task];
                           } else if ([task isKindOfClass:[NSURLSessionDownloadTask class]]) {
                               [downloadTasks addObject:task];
                           } else if ([task isKindOfClass:[NSURLSessionUploadTask class]]) {
                               [uploadTasks addObject:task];
                           }
                       }

                       [_delegateQueue addOperationWithBlock:^{
                           completionHandler(dataTasks, uploadTasks, downloadTasks);
                       }];
                   });
}

// These delegate methods will be used by all tasks and internally to the session.
// They will proxy to the delegate method IF NECESSARY.
// We're using the full method name so that we can avoid repeating ourselves during the
// optional invocation. We don't personally care about messages from other sessions.
// and as such, the session parameter is unused.
- (void)URLSession:(NSURLSession*)session
    didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge
      completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler {
    if (dispatchDelegateOptional(_delegateQueue, _delegate, _cmd, self, challenge, completionHandler)) {
        // We do not want to invoke the default behaviour.
        return;
    }

    completionHandler(NSURLSessionAuthChallengePerformDefaultHandling, nil);
}

- (void)task:(NSURLSessionTask*)task didCompleteWithError:(NSError*)error {
    _NSURLSessionInflightTaskInfo* inflightTaskData = [self _inflightDataForTask:task];
    if (inflightTaskData) {
        [inflightTaskData dispatchTaskCompletionHandler];
    } else {
        dispatchDelegateOptional(_delegateQueue, _delegate, @selector(URLSession:task:didCompleteWithError:), self, task, error);
        // we DO want to invoke the default behaviour, which is simply to clear out the task
    }

    [self _deregisterTask:task];
}

- (void)task:(NSURLSessionTask*)task
    didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge
      completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler {
    if (![self _isTaskBlockBased:task]) {
        if (dispatchDelegateOptional(_delegateQueue,
                                     _delegate,
                                     @selector(URLSession:task:didReceiveChallenge:completionHandler:),
                                     self,
                                     task,
                                     challenge,
                                     completionHandler)) {
            // We do not want to invoke the default behaviour.
            return;
        }
    }

    // Apple's docs state that this fallback only occurs if the user DOES NOT provide a delegate.
    if (!_delegate) {
        [self URLSession:self didReceiveChallenge:challenge completionHandler:completionHandler];
        return;
    }

    // This will only happen if there was a delegate and it did not respond to this method.
    completionHandler(NSURLSessionAuthChallengePerformDefaultHandling, nil);
}

- (void)task:(NSURLSessionTask*)task
             didSendBodyData:(int64_t)bytesSent
              totalBytesSent:(int64_t)totalBytesSent
    totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend {
    if ([self _isTaskBlockBased:task]) {
        return;
    }
    dispatchDelegateOptional(_delegateQueue,
                             _delegate,
                             @selector(URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:),
                             self,
                             task,
                             bytesSent,
                             totalBytesSent,
                             totalBytesExpectedToSend);
}

- (void)task:(NSURLSessionTask*)task needNewBodyStream:(void (^)(NSInputStream* bodyStream))completionHandler {
    if (![self _isTaskBlockBased:task]) {
        if (dispatchDelegateOptional(
                _delegateQueue, _delegate, @selector(URLSession:task:needNewBodyStream:), self, task, completionHandler)) {
            // We do not want to invoke the default behaviour.
            return;
        }
    }
    completionHandler(nil);
}

- (void)task:(NSURLSessionTask*)task
    willPerformHTTPRedirection:(NSHTTPURLResponse*)response
                    newRequest:(NSURLRequest*)request
             completionHandler:(void (^)(NSURLRequest*))completionHandler {
    if (![self _isTaskBlockBased:task]) {
        if (dispatchDelegateOptional(_delegateQueue,
                                     _delegate,
                                     @selector(URLSession:task:willPerformHTTPRedirection:newRequest:completionHandler:),
                                     self,
                                     task,
                                     response,
                                     request,
                                     completionHandler)) {
            // We do not want to invoke the default behaviour.
            return;
        }
    }

    completionHandler(request);
}

- (void)dataTask:(NSURLSessionDataTask*)task
    didReceiveResponse:(NSURLResponse*)response
     completionHandler:(void (^)(NSURLSessionResponseDisposition disposition))completionHandler {
    if (![self _isTaskBlockBased:task]) {
        // Only fall through to the delegate if it's not an inflight block task.
        if (dispatchDelegateOptional(_delegateQueue,
                                     _delegate,
                                     @selector(URLSession:dataTask:didReceiveResponse:completionHandler:),
                                     self,
                                     task,
                                     response,
                                     completionHandler)) {
            // We do not want to invoke the default behaviour.
            return;
        }
    }

    completionHandler(NSURLSessionResponseAllow);
}

- (void)dataTask:(NSURLSessionDataTask*)task didBecomeDownloadTask:(NSURLSessionDownloadTask*)downloadTask {
    if (![self _isTaskBlockBased:task]) {
        dispatchDelegateOptional(_delegateQueue,
                                 _delegate,
                                 @selector(URLSession:dataTask:didBecomeDownloadTask:),
                                 self,
                                 task,
                                 downloadTask);
    } else {
        // this should not happen ...
        [NSException raise:NSInvalidArgumentException format:@"invalid state transition"];
    }

    [self _deregisterTask:task];
}

- (void)dataTask:(NSURLSessionDataTask*)task didReceiveData:(NSData*)data {
    _NSURLSessionInflightTaskInfo* inflightTaskData = [self _inflightDataForTask:task];
    if (inflightTaskData) {
        [inflightTaskData accumulateData:data];
    } else {
        if (dispatchDelegateOptional(_delegateQueue, _delegate, @selector(URLSession:dataTask:didReceiveData:), self, task, data)) {
            // We do not want to invoke the default behaviour.
            return;
        }
    }
}

- (void)dataTask:(NSURLSessionDataTask*)task
    willCacheResponse:(NSCachedURLResponse*)proposedResponse
    completionHandler:(void (^)(NSCachedURLResponse*))completionHandler {
    if (![self _isTaskBlockBased:task]) {
        if (dispatchDelegateOptional(_delegateQueue,
                                     _delegate,
                                     @selector(URLSession:dataTask:willCacheResponse:completionHandler:),
                                     self,
                                     task,
                                     proposedResponse,
                                     completionHandler)) {
            // We do not want to invoke the default behaviour.
            return;
        }
    }

    completionHandler(proposedResponse);
}

- (void)downloadTask:(NSURLSessionDownloadTask*)task didResumeAtOffset:(int64_t)offset expectedTotalBytes:(int64_t)expectedTotalBytes {
    if ([self _isTaskBlockBased:task]) {
        return;
    }

    dispatchDelegateOptional(_delegateQueue,
                             _delegate,
                             @selector(URLSession:downloadTask:didResumeAtOffset:expectedTotalBytes:),
                             self,
                             task,
                             offset,
                             expectedTotalBytes);
}

- (void)downloadTask:(NSURLSessionDownloadTask*)task
                 didWriteData:(int64_t)bytesWritten
            totalBytesWritten:(int64_t)totalBytesWritten
    totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite {
    if ([self _isTaskBlockBased:task]) {
        return;
    }

    dispatchDelegateOptional(_delegateQueue,
                             _delegate,
                             @selector(URLSession:downloadTask:didWriteData:totalBytesWritten:totalBytesExpectedToWrite:),
                             self,
                             task,
                             bytesWritten,
                             totalBytesWritten,
                             totalBytesExpectedToWrite);
}

- (void)downloadTask:(NSURLSessionDownloadTask*)task didFinishDownloadingToURL:(NSURL*)url {
    _NSURLSessionInflightTaskInfo* inflightTaskData = [self _inflightDataForTask:task];
    if (inflightTaskData) {
        [inflightTaskData dispatchDownloadCompletionHandlerForURL:url];
    } else {
        // NOT OPTIONAL (protocol specifies @required)
        auto properDelegate(reinterpret_cast<id<NSURLSessionDownloadDelegate>>(_delegate));
        [_delegateQueue addOperationWithBlock:^{
            [properDelegate URLSession:self downloadTask:task didFinishDownloadingToURL:url];
        }];
    }
}
@end
