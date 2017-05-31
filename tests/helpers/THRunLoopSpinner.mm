//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <Helpers/TestHelpers.h>
#import <pthread.h>

#import <memory>
#import <atomic>

@interface THRunLoopSpinner () {
@public
    std::shared_ptr<std::atomic<bool>> _shouldStop;
    pthread_t _thread;
    THBooleanCondition* _threadStartedCondition;
}
@end

@implementation THRunLoopSpinner
static void* _helperThreadBody(void* context) {
    __unsafe_unretained THRunLoopSpinner* unsafeHelper = static_cast<id>(context);
    @autoreleasepool {
        __strong THRunLoopSpinner* helper = [unsafeHelper retain];
        // Capture the shared_ptr; the thread needs to read from it _after the helper is deallocated!_
        auto pShouldStop = helper->_shouldStop;
        std::atomic<bool>& shouldStop = *pShouldStop;

        NSRunLoop* loop = helper->_runLoop = [NSRunLoop currentRunLoop];
        [helper->_threadStartedCondition broadcast];
        [helper release];

        NSTimer* spinTimer = [NSTimer timerWithTimeInterval:0.1 target:[NSObject class] selector:@selector(class) userInfo:nil repeats:YES];
        [loop addTimer:spinTimer forMode:NSDefaultRunLoopMode];

        while (!shouldStop) {
            @autoreleasepool {
                // Spin the runloop for 0.1 seconds. It will usually bail out due to lack of input.
                // When something gets scheduled on it, this will trigger its execution.
                [loop runMode:NSDefaultRunLoopMode beforeDate:[NSDate dateWithTimeIntervalSinceNow:0.1]];
            }
        }
    }
    return nullptr;
}

- (instancetype)init {
    if (self = [super init]) {
        _shouldStop.reset(new std::atomic<bool>(false));
        _threadStartedCondition = [[THBooleanCondition alloc] init];

        auto rc = pthread_create(&_thread, nullptr, &_helperThreadBody, static_cast<void*>(self));
        if (rc != 0) {
            [self release];
            return nil;
        }

        [_threadStartedCondition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:60]];

        if (!_threadStartedCondition.isOpen) {
            [self release];
            return nil;
        }
    }
    return self;
}

- (void)dealloc {
    [self stop];
    [_threadStartedCondition release];
    [super dealloc];
}

- (void)stop {
    _shouldStop->store(true);
    pthread_join(_thread, nullptr);
}

- (void)scheduleAndAwaitBlock:(void (^)())block {
    THBooleanCondition* condition = [[THBooleanCondition new] autorelease];
    void (^wrappedBlock)() = ^{
        block();
        [condition broadcast];
    };

    [_runLoop performSelector:@selector(invoke) target:wrappedBlock argument:nil order:0 modes:@[ NSDefaultRunLoopMode ]];

    [condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:60]];

    if (!condition.isOpen) {
        [NSException raise:NSGenericException format:@"*** %s: failed to await block", __PRETTY_FUNCTION__];
    }
}
@end