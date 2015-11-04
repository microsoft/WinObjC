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
#include <math.h>

#include "QuartzCore/CALayer.h"
#include "QuartzCore/CABasicAnimation.h"
#include "CACompositor.h"
#include "CAAnimationInternal.h"

@implementation CABasicAnimation {
    idretain _from, _to;
}

/**
 @Status Interoperable
*/
- (void)setFromValue:(id)value {
    _from.attach([value copy]);
}

/**
 @Status Interoperable
*/
- (void)setToValue:(id)value {
    _to.attach([value copy]);
}

/**
 @Status Stub
*/
- (void)setByValue:(id)value {
    UNIMPLEMENTED();
    EbrDebugLog("CABasicAnimation::setByValue not supported\n");
}

/**
 @Status Interoperable
*/
- (id)toValue {
    return _to;
}

+ (instancetype)animationWithKeyPath:(NSString*)path {
    CABasicAnimation* ret = [self alloc];
    ret->_timingProperties._duration = 1.0;
    ret->_timingProperties._speed = 1.0;
    ret->_timingProperties._removedOnCompletion = TRUE;
    [ret setKeyPath:path];

    return [ret autorelease];
}

- (id)runActionForKey:(NSString*)key object:(id)object arguments:(NSDictionary*)dict {
    if (_to == nil) {
        _to = [object valueForKey:_keyPath];
    }

    [object addAnimation:self forKey:key];

    return self;
}

- (DisplayAnimation*)_createAnimation:(CALayer*)layer forKey:(id)forKey {
    _attachedLayer = layer;

    if (_keyPath == nil) {
        _keyPath = forKey;
    }

    _runningAnimation = _globalCompositor->GetBasicDisplayAnimation(self, _keyPath, _from, _to, &_timingProperties);

    return _runningAnimation;
}

- (id)copyWithZone:(NSZone*)zone {
    CABasicAnimation* ret = [super copyWithZone:zone];

    assert(_runningAnimation == NULL);
    ret->_from.attach([_from copy]);
    ret->_to.attach([_to copy]);

    return ret;
}

- (void)dealloc {
    _from = nil;
    _to = nil;
    [super dealloc];
}

@end
