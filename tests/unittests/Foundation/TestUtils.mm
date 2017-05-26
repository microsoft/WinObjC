//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#import <TestFramework.h>
#import <Starboard/SmartTypes.h>
#import <windows.h>
#import "TestUtils.h"
#import <memory>
#import <atomic>

void assertOrderedSetContent(NSOrderedSet* set, NSObject* first, ...) {
    va_list args;
    va_start(args, first);

    id curVal = first;

    size_t i = 0;
    while (curVal != nil) {
        ASSERT_OBJCEQ(curVal, [set objectAtIndex:i++]);
        curVal = va_arg(args, id);
    }

    va_end(args);

    ASSERT_EQ(i, [set count]);
}

NSString* getPathToFile(NSString* fileName) {
    return [[[NSFileManager defaultManager] currentDirectoryPath] stringByAppendingPathComponent:fileName];
}

void createFileWithContentAndVerify(NSString* fileName, NSString* content) {
    NSString* fullPath = getPathToFile(fileName);
    NSError* error = nil;
    ASSERT_TRUE([content writeToFile:fullPath atomically:NO encoding:NSUTF8StringEncoding error:&error]);
    ASSERT_EQ(nil, error);
    ASSERT_TRUE([[NSFileManager defaultManager] fileExistsAtPath:fullPath]);
}

void deleteFile(NSString* name) {
    NSString* fullPath = getPathToFile(name);
    if ([[NSFileManager defaultManager] fileExistsAtPath:fullPath]) {
        [[NSFileManager defaultManager] removeItemAtPath:fullPath error:nil];
    }
};

@interface THRunLoopSpinner () {
@public
    std::shared_ptr<std::atomic<bool>> _shouldStop;
    NSRunLoop* _loop;
    pthread_t _thread;
    _NSBooleanCondition* _threadStartedCondition;
}
@end

@implementation THRunLoopSpinner
static void* _helperThreadBody(void* context) {
    __unsafe_unretained THRunLoopSpinner* unsafeHelper = static_cast<id>(context);
    @autoreleasepool {
        __strong THRunLoopSpinner* helper = [unsafeHelper retain];
        auto pShouldStop =
            helper->_shouldStop; // Capture the shared_ptr; the thread needs to read from it _after the helper is deallocated!_
        std::atomic<bool>& shouldStop = *pShouldStop;

        NSRunLoop* loop = helper->_loop = [NSRunLoop currentRunLoop];
        [helper->_threadStartedCondition broadcast];
        [helper release];

        while (!shouldStop) {
            @autoreleasepool {
                [loop runMode:NSDefaultRunLoopMode beforeDate:[NSDate dateWithTimeIntervalSinceNow:0.1]];
            }
        }
    }
    return nullptr;
}

- (instancetype)init {
    if (self = [super init]) {
        _shouldStop.reset(new std::atomic<bool>(false));
        _threadStartedCondition = [[_NSBooleanCondition alloc] init];

        auto rc = pthread_create(&_thread, nullptr, &_helperThreadBody, static_cast<void*>(self));
        ASSERT_EQ_MSG(0, rc, "Failed to create a thread");

        [_threadStartedCondition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:10]];

        ASSERT_TRUE_MSG(_threadStartedCondition.isOpen, "Helper thread never started!");
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
    _NSBooleanCondition* condition = [[_NSBooleanCondition new] autorelease];
    void (^wrappedBlock)() = ^{
        block();
        [condition broadcast];
    };

    [_loop performSelector:@selector(invoke) target:wrappedBlock argument:nil order:0 modes:@[ NSDefaultRunLoopMode ]];

    [condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:20]];

    ASSERT_TRUE(condition.isOpen);
}
@end

