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
