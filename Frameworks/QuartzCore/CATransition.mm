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

#include <QuartzCore/CAMediaTimingFunction.h>
#include <QuartzCore/CATransition.h>

#include "CALayerInternal.h"
#include "CACompositor.h"
#include "CAAnimationInternal.h"

#include <math.h>

NSString* const kCATransitionFade = @"kCATransitionFade";
NSString* const kCATransitionMoveIn = @"kCATransitionMoveIn";
NSString* const kCATransitionPush = @"kCATransitionPush";
NSString* const kCATransitionReveal = @"kCATransitionReveal";
NSString* const kCATransitionFromRight = @"kCATransitionFromRight";
NSString* const kCATransitionFromLeft = @"kCATransitionFromLeft";
NSString* const kCATransitionFromTop = @"kCATransitionFromTop";
NSString* const kCATransitionFromBottom = @"kCATransitionFromBottom";

@implementation CATransition : CAAnimation
/**
 @Status Interoperable
*/
+ (instancetype)animation {
    CATransition* ret = [self alloc];
    ret->_timingProperties._duration = 1.0f;
    ret->_timingProperties._speed = 1.0f;
    ret->_timingProperties._removedOnCompletion = TRUE;
    [ret setTimingFunction:[CAMediaTimingFunction functionWithName:@"kCAMediaTimingFunctionEaseInEaseOut"]];

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (void)setType:(id)type {
    _type = type;
}

/**
 @Status Interoperable
*/
- (NSString*)type {
    return _type;
}

/**
 @Status Interoperable
*/
- (void)setSubtype:(id)subtype {
    _subtype = subtype;
}

/**
 @Status Interoperable
*/
- (NSString*)subtype {
    return _subtype;
}

/**
 @Status Interoperable
 @Public No
 @Notes CAAction Protocol
*/
- (void)runActionForKey:(NSString*)key object:(NSObject*)object arguments:(NSDictionary*)dict {
}

- (std::shared_ptr<ILayerAnimation>)_createAnimation:(CALayer*)layer forKey:(NSString*)key {
    _attachedLayer = layer;
    _runningAnimation = _globalCompositor->CreateTransitionAnimation(self, _type, _subtype);

    return _runningAnimation;
}

/**
 @Status Interoperable
 @Public No
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    CATransition* ret = [super copyWithZone:zone];

    assert(_runningAnimation == NULL);

    ret->_type = [_type copy];
    ret->_subtype = [_subtype copy];
    return ret;
}

@end
