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

#include <math.h>
#include "Starboard.h"
#include "QuartzCore/CATransition.h"
#include "CALayerInternal.h"
#include "CACompositor.h"
#include "CAAnimationInternal.h"

@implementation CATransition : CAAnimation
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
- (void)setSubtype:(id)subtype {
    _subtype = subtype;
}

- (void)runActionForKey:(NSString*)key object:(NSObject*)object arguments:(NSDictionary*)dict {
}

- (DisplayAnimation*)_createAnimation:(CALayer*)layer forKey:(NSString*)key {
    _attachedLayer = layer;
    _runningAnimation = _globalCompositor->GetMoveDisplayAnimation(&_runningAnimation2,
                                                                   self,
                                                                   layer->priv->_presentationNode,
                                                                   _type,
                                                                   _subtype,
                                                                   &_timingProperties);

    return _runningAnimation;
}

- (instancetype)copyWithZone:(NSZone*)zone {
    CATransition* ret = [super copyWithZone:zone];

    assert(_runningAnimation == NULL);
    assert(_runningAnimation2 == NULL);

    ret->_type = [_type copy];
    ret->_subtype = [_subtype copy];
    return ret;
}

@end
