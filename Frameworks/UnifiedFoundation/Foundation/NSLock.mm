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

#include <process.h>

#include "Starboard.h"
#include "Foundation/NSLock.h"
#include "Foundation/NSRecursiveLock.h"

@implementation NSLock {
    uint32_t _lock;
    idretaintype(NSString) _name;
}
- (instancetype)init {
    EbrLockInit(&_lock);

    return self;
}

- (void)lock {
    EbrLockEnter(_lock);
}

/**
 @Status Interoperable
*/
- (BOOL)tryLock {
    BOOL ret = EbrLockTryEnter(_lock);

    return ret;
}

- (void)unlock {
    EbrLockLeave(_lock);
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
@end

@implementation NSRecursiveLock {
    uint32_t _lock;
    idretaintype(NSString) _name;
}

- (instancetype)init {
    EbrLockInit(&_lock);

    return self;
}

- (void)lock {
    EbrLockEnter(_lock);
}

/**
 @Status Interoperable
*/
- (BOOL)tryLock {
    BOOL ret = EbrLockTryEnter(_lock);

    return ret;
}

- (void)unlock {
    EbrLockLeave(_lock);
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
@end
