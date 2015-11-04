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

#include "Starboard.h"

#include "Quartzcore/CAPropertyAnimation.h"
#include "QuartzCore/CATransaction.h"
#include "CAAnimationInternal.h"

@interface _BlockAnimationCompletion : NSObject {
@public
    void (^_completionBlock)();
}
@end

@implementation _BlockAnimationCompletion : NSObject
- (void)animationDidStop:(CAAnimation*)anim finished:(BOOL)finished {
    _completionBlock();
}

@end

@implementation CAPropertyAnimation

/**
 @Status Caveat
 @Notes Only position, bounds, and transform properties spuported
*/
- (void)setKeyPath:(NSString*)path {
    _keyPath = [path copy];
}

/**
 @Status Interoperable
*/
- (NSString*)keyPath {
    return _keyPath;
}

/**
 @Status Caveat
 @Notes Only position, bounds, and transform properties spuported
*/
+ (instancetype)animationWithKeyPath:(NSString*)path {
    CAPropertyAnimation* ret = [self alloc];
    ret->_timingProperties._speed = 1.0f;
    ret->_timingProperties._removedOnCompletion = TRUE;

    id completion = [CATransaction completionBlock];
    if (completion != nil) {
        // TODO(DH) What the heck?
        _BlockAnimationCompletion* completionHandler = [_BlockAnimationCompletion alloc];
        completionHandler->_completionBlock = completion;
    }
    [ret setKeyPath:path];

    return [ret autorelease];
}

- (id)copyWithZone:(NSZone*)zone {
    CAPropertyAnimation* ret = [super copyWithZone:zone];

    ret->_keyPath = [_keyPath copy];
    return ret;
}

@end
