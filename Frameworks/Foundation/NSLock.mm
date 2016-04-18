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
#import <mutex>
#import <chrono>
#import "NSLock+Internal.h"

@implementation NSLock {
    std::timed_mutex _mtx;
    idretaintype(NSString) _name;
    // internal counter used for test purpose.
    volatile long _count;
}

/**
 @Status Interoperable
*/
- (void)lock {
    _mtx.lock();
    _InterlockedIncrement(&_count);
}

/**
 @Status Interoperable
*/
- (BOOL)tryLock {
    BOOL status = _mtx.try_lock();
    if (status) {
        _InterlockedIncrement(&_count);
    }

    return status;
}

/**
 @Status Interoperable
*/
- (void)unlock {
    _InterlockedDecrement(&_count);
    _mtx.unlock();
}

/**
 @Status Interoperable
*/
- (void)setName:(NSString*)name {
    _name.attach([name copy]);
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
    BOOL status = _mtx.try_lock_for(std::chrono::milliseconds(timeInMs));
    if (status) {
        _InterlockedIncrement(&_count);
    }

    return status;
}

- (long)_lockCount {
    return _count;
}
@end