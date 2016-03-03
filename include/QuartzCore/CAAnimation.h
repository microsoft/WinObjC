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

#import <QuartzCore/CoreAnimationExport.h>
#import <QuartzCore/CAAction.h>
#import <QuartzCore/CAMediaTiming.h>
#import <CoreGraphics/CGPath.h>

@class CAAnimation;
@class NSString;
@class CAMediaTimingFunction;
@class NSArray;

enum CAMediaFillMode {
    fillModeRemoved,
    fillModeForwards,
    fillModeBackwards,
    fillModeBoth,
};

#ifdef __cplusplus
class DisplayAnimation;
#else
typedef void* DisplayAnimation;
#endif

CA_EXPORT_CLASS
@interface CAAnimation : NSObject <CAAction, CAMediaTiming, NSCoding, NSCopying>

- (BOOL)shouldArchiveValueForKey:(NSString*)key STUB_METHOD;
+ (id)defaultValueForKey:(NSString*)key STUB_METHOD;
+ (instancetype)animation;

@property (getter=isRemovedOnCompletion) BOOL removedOnCompletion;
@property (retain) CAMediaTimingFunction* timingFunction;
@property (retain) id delegate;
@property BOOL usesSceneTimeBase STUB_PROPERTY;
@property CGFloat fadeInDuration STUB_PROPERTY;
@property CGFloat fadeOutDuration STUB_PROPERTY;
@property (copy, nonatomic) NSArray* animationEvents STUB_PROPERTY;

// CAMediaTiming
@property BOOL autoreverses;
@property CFTimeInterval beginTime;
@property CFTimeInterval duration;
@property (copy) NSString* fillMode;
@property float repeatCount;
@property CFTimeInterval repeatDuration;
@property float speed;
@property CFTimeInterval timeOffset;

// Added by MS
@property CGPathRef path;

@end

@protocol CAAnimationDelegate
- (void)animationDidStart:(CAAnimation*)theAnimation;
- (void)animationDidStop:(BOOL)finished;
@end
