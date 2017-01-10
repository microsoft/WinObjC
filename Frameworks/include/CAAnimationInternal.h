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
#pragma once

#import <QuartzCore/CAAnimation.h>
#import "CACompositor.h"

struct CAMediaTimingProperties {
    BOOL _removedOnCompletion;
    double _beginTime, _duration, _timeOffset, _delay, _speed;
    BOOL _autoReverses;
    float _repeatCount;
    double _repeatDuration;
    __unsafe_unretained id _timingFunction;
    enum CAMediaFillMode _fillMode;
};

@interface CAAnimation () {
@public
    CAMediaTimingProperties _timingProperties;
    std::shared_ptr<ILayerAnimation> _runningAnimation;
    id _attachedLayer;
    idretaintype(NSString) _keyName;
}

- (void)setDelay:(double)delay;
- (void)_removeAnimationsFromLayer;
- (void)_setFinishedSelector:(SEL)selector;
@end

@interface NSObject (CAAnimationInternal)
- (BOOL)wasRemoved;
- (std::shared_ptr<ILayerAnimation>)_createAnimation:(CALayer*)layer forKey:(id)forKey;
- (void)animationDidStart;
- (id)animationHasStarted;
- (void)animationDidStop:(BOOL)finished;
@end