/*
 * Copyright (c) 2011, The Iconfactory. All rights reserved.
 * Copyright (c) 2016 Microsoft Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of The Iconfactory nor the names of its contributors may
 *    be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE ICONFACTORY BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#pragma once

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>

typedef NS_ENUM(NSInteger, UIForceTouchCapability) {
    UIForceTouchCapabilityUnknown = 0,
    UIForceTouchCapabilityUnavailable = 1,
    UIForceTouchCapabilityAvailable = 2,
};

typedef NS_ENUM(NSInteger, UITouchType) {
    UITouchTypeDirect,
    UITouchTypeIndirect,
    UITouchTypeStylus,
};

typedef NS_OPTIONS(NSInteger, UITouchProperties) {
    UITouchPropertyForce = (1UL << 0),
    UITouchPropertyAzimuth = (1UL << 1),
    UITouchPropertyAltitude = (1UL << 2),
    UITouchPropertyLocation = (1UL << 3),
};

typedef NS_ENUM(NSInteger, UITouchPhase) {
    UITouchPhaseBegan,
    UITouchPhaseMoved,
    UITouchPhaseStationary,
    UITouchPhaseEnded,
    UITouchPhaseCancelled,
};

@class UIView, UIWindow, SKNode;

@interface UITouch : NSObject
- (CGFloat)azimuthAngleInView:(UIView*)view STUB_METHOD;
- (CGPoint)locationInNode:(SKNode*)node STUB_METHOD;
- (CGPoint)locationInView:(UIView*)inView;
- (CGPoint)preciseLocationInView:(UIView*)view STUB_METHOD;
- (CGPoint)preciseLocationInView:(UIView*)view STUB_METHOD;
- (CGPoint)precisePreviousLocationInView:(UIView*)view STUB_METHOD;
- (CGPoint)precisePreviousLocationInView:(UIView*)view STUB_METHOD;
- (CGPoint)previousLocationInNode:(SKNode*)node STUB_METHOD;
- (CGPoint)previousLocationInView:(UIView*)inView;
- (CGVector)azimuthUnitVectorInView:(UIView*)view STUB_METHOD;

@property (nonatomic, readonly) NSTimeInterval timestamp;
@property (nonatomic, readonly) NSUInteger tapCount;
@property (nonatomic, readonly) UITouchPhase phase;
@property (nonatomic, readonly, copy) NSArray* gestureRecognizers;
@property (nonatomic, readonly, retain) UIView* view;
@property (nonatomic, readonly, retain) UIWindow* window;
@property (readonly, nonatomic) CGFloat altitudeAngle STUB_PROPERTY;
@property (readonly, nonatomic) CGFloat force STUB_PROPERTY;
@property (readonly, nonatomic) CGFloat majorRadius STUB_PROPERTY;
@property (readonly, nonatomic) CGFloat majorRadiusTolerance STUB_PROPERTY;
@property (readonly, nonatomic) CGFloat maximumPossibleForce STUB_PROPERTY;
@property (readonly, nonatomic) NSNumber* estimationUpdateIndex STUB_PROPERTY;
@property (readonly, nonatomic) UITouchProperties estimatedProperties STUB_PROPERTY;
@property (readonly, nonatomic) UITouchProperties estimatedPropertiesExpectingUpdates STUB_PROPERTY;
@property (readonly, nonatomic) UITouchType type STUB_PROPERTY;

@end
