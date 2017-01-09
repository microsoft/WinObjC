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

#include <QuartzCore/CABasicAnimation.h>
#include <QuartzCore/CALayer.h>
#include <QuartzCore/CoreAnimationFunctions.h>

#include "CACompositor.h"
#include "CAAnimationInternal.h"
#include "LoggingNative.h"

#include <math.h>

static const wchar_t* TAG = L"CABasicAnimation";

@implementation CABasicAnimation {
    idretain _from;
    idretain _to;
    idretain _by;
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
- (id)fromValue {
    return _from;
}

/**
 @Status Interoperable
*/
- (void)setToValue:(id)value {
    _to.attach([value copy]);
}

/**
 @Status Interoperable
*/
- (id)toValue {
    return _to;
}

/**
 @Status Interoperable
*/
- (void)setByValue:(id)value {
    _by.attach([value copy]);
}

/**
 @Status Interoperable
*/
- (id)byValue {
    return _by;
}

/**
 @Status Interoperable
*/
+ (instancetype)animationWithKeyPath:(NSString*)path {
    CABasicAnimation* ret = [self alloc];
    ret->_timingProperties._duration = 1.0;
    ret->_timingProperties._speed = 1.0;
    ret->_timingProperties._beginTime = CACurrentMediaTime();
    ret->_timingProperties._removedOnCompletion = TRUE;
    [ret setKeyPath:path];

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (void)runActionForKey:(NSString*)key object:(id)object arguments:(NSDictionary*)dict {
    if (_to == nil) {
        _to = [object valueForKey:_keyPath];
    }

    [object addAnimation:self forKey:key];
}

- (std::shared_ptr<ILayerAnimation>)_createAnimation:(CALayer*)layer forKey:(id)forKey {
    _attachedLayer = layer;

    if (_keyPath == nil) {
        _keyPath = forKey;
    }

    if (_from != nil) {
        if (_by == nil && _to == nil) {
            // populate _to with the value of property on layer
            _to = [[layer valueForKeyPath:_keyPath] retain];
        }
    } else if (_to != nil) {
        if (_by == nil) {
            // populate _from with the value of property on layer
            _from = [[layer valueForKeyPath:_keyPath] retain];
        }
    } else if (_by != nil) {
        // populate _from with the value of property on layer
        _from = [[layer valueForKeyPath:_keyPath] retain];
    }

    _runningAnimation = _globalCompositor->CreateBasicAnimation(self, _keyPath, _from, _to, _by, &_timingProperties);

    return _runningAnimation;
}

/**
 @Status Interoperable
 @Public No
*/
- (id)copyWithZone:(NSZone*)zone {
    CABasicAnimation* ret = [super copyWithZone:zone];

    assert(_runningAnimation == NULL);
    ret->_from.attach([_from copy]);
    ret->_to.attach([_to copy]);
    ret->_by.attach([_by copy]);

    return ret;
}

- (void)dealloc {
    _from = nil;
    _to = nil;
    _by = nil;
    [super dealloc];
}

@end
