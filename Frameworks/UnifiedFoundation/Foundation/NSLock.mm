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

#import <Starboard.h>
#import "NSLock+Internal.h"
#import <mutex>
#import <chrono>

@implementation NSLock {
    std::timed_mutex _mtx;
    std::unique_lock<std::timed_mutex> _lock;
    idretaintype(NSString) _name;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self == [super init]) {
        _lock = std::unique_lock<std::timed_mutex>(_mtx, std::defer_lock);
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)lock {
    _lock.lock();
}

/**
 @Status Interoperable
*/
- (BOOL)tryLock {
    return _lock.try_lock();
}

/**
 @Status Interoperable
*/
- (void)unlock {
    _lock.unlock();
}

/**
 @Status Interoperable
*/
- (void)setName:(NSString*)name {
    [name retain];
    [_name release];
    _name = name;
}

/**
 @Status Interoperable
*/
- (NSString*)name {
    return _name;
}

/**
 @Status Interoperable
*/
- (BOOL)lockBeforeDate:(NSDate*)value {
    NSDate* now = [NSDate date];
    long timeInMs = [value timeIntervalSinceDate:now] * 1000;
    return _lock.try_lock_for(std::chrono::milliseconds(timeInMs));
}

- (BOOL)isLocked {
    return _lock.owns_lock();
}
@end