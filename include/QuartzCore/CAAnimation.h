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

#ifndef _CAANIMATION_H_
#define _CAANIMATION_H_

#import <Foundation/NSObject.h>
#import <QuartzCore/CABase.h>
#import <QuartzCore/CAMediaTiming.h>
#import <QuartzCore/CAAction.h>
#import <QuartzCore/CALayer.h>

@class CAMediaTimingFunction;

CA_EXPORT NSString * const kCATransitionFade;
CA_EXPORT NSString * const kCATransitionMoveIn;
CA_EXPORT NSString * const kCATransitionPush;
CA_EXPORT NSString * const kCATransitionReveal;

CA_EXPORT NSString * const kCATransitionFromLeft;
CA_EXPORT NSString * const kCATransitionFromRight;
CA_EXPORT NSString * const kCATransitionFromTop;
CA_EXPORT NSString * const kCATransitionFromBottom;

CA_EXPORT NSString * const kCAAnimationRotateAuto;
CA_EXPORT NSString * const kCAAnimationRotateAutoReverse;

enum CAMediaFillMode
{
    fillModeRemoved,
    fillModeForwards,
    fillModeBackwards,
    fillModeBoth
};

struct CAMediaTimingProperties
{
    BOOL _removedOnCompletion;
    double _beginTime, _duration, _timeOffset, _delay, _speed;
    BOOL _autoReverses;
    float _repeatCount;
    double _repeatDuration;
    __unsafe_unretained id _timingFunction;
    enum CAMediaFillMode _fillMode;
};
#ifdef __cplusplus
class DisplayAnimation;
#else
typedef void *DisplayAnimation;
#endif

CA_EXPORT_CLASS
@interface CAAnimation : NSObject <NSCopying, CAMediaTiming, CAAction> {
@public
    struct CAMediaTimingProperties _timingProperties;
    idretain                _delegate;
    idretaintype(NSString)  _keyName;
    id                      _attachedLayer;
    DisplayAnimation        *_runningAnimation, *_runningAnimation2;
    SEL                     _finishedSelector;
    id                      _name;
    idretain                _undefinedKeys;
    BOOL                    _wasRemoved, _wasAborted;
}

+animation;

@property (retain) id delegate;
@property (getter=isRemovedOnCompletion) BOOL removedOnCompletion;
@property (retain) CAMediaTimingFunction *timingFunction;
@property CGPathRef path;

@end

@interface NSObject (CAAnimationDelegate)
-(void)animationDidStart:(CAAnimation *)animation;
-(void)animationDidStop:(CAAnimation *)animation finished:(BOOL)finished;
@end

#import <QuartzCore/CAPropertyAnimation.h>
#import <QuartzCore/CABasicAnimation.h>
#import <QuartzCore/CATransition.h>
#import <QuartzCore/CAAnimationGroup.h>

#endif /* _CAANIMATION_H_ */