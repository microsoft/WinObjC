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

#import <Foundation/NSAutoreleasePool.h>
#import <objc/objc-arc.h>

@interface NSAutoreleasePool () {
    void* _opaqueAutoreleasePool;
}
@end
@implementation NSAutoreleasePool
/*
 * _ARCCompatibleAutoreleasePool signals to the runtime that, if necessary,
 * this autorelease pool class may be entirely avoided. This allows for fast-path
 * object management.
 *
 * The original methods remain as mere shims for the runtime's management functions.
 */
- (void)_ARCCompatibleAutoreleasePool {
}

/**
 @Status Interoperable
 */
+ (void)addObject:(id)object {
    objc_autorelease(object);
}

/**
 @Status Interoperable
 */
- (void)addObject:(id)object {
    objc_autorelease(object);
}

/**
 @Status Interoperable
 */
- (id)init {
    if (self = [super init]) {
        _opaqueAutoreleasePool = objc_autoreleasePoolPush();
    }
    return self;
}

/**
 @Status Interoperable
 */
- (void)dealloc {
    objc_autoreleasePoolPop(_opaqueAutoreleasePool);
    [super dealloc];
}

/**
 @Status Interoperable
 @Notes On non-GC platforms like WinObjC, -drain is identical to -release.
 */
- (void)drain {
    [self release];
}
@end
