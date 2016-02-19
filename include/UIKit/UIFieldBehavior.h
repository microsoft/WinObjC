//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <UIKit/UIKitExport.h>
#import <Foundation/NSObject.h>
#import <CoreGraphics/CGGeometry.h>
#import <UIKit/UIDynamicBehavior.h>

@protocol UIDynamicItem;
@class NSArray;
@class UIRegion;

UIKIT_EXPORT_CLASS
@interface UIFieldBehavior : UIDynamicBehavior
+ (instancetype)dragField STUB_METHOD;
+ (instancetype)springField STUB_METHOD;
+ (instancetype)velocityFieldWithVector:(CGVector)direction STUB_METHOD;
+ (instancetype)electricField STUB_METHOD;
+ (instancetype)magneticField STUB_METHOD;
+ (instancetype)radialGravityFieldWithPosition:(CGPoint)position STUB_METHOD;
+ (instancetype)linearGravityFieldWithVector:(CGVector)direction STUB_METHOD;
+ (instancetype)vortexField STUB_METHOD;
+ (instancetype)noiseFieldWithSmoothness:(CGFloat)smoothness animationSpeed:(CGFloat)speed STUB_METHOD;
+ (instancetype)turbulenceFieldWithSmoothness:(CGFloat)smoothness animationSpeed:(CGFloat)speed STUB_METHOD;
+ (instancetype)fieldWithEvaluationBlock:(CGVector (^)(UIFieldBehavior*, CGPoint, CGVector, CGFloat, CGFloat, NSTimeInterval))block
    STUB_METHOD;
- (void)addItem:(id<UIDynamicItem>)item STUB_METHOD;
- (void)removeItem:(id<UIDynamicItem>)item STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* items STUB_PROPERTY;
@property (assign, nonatomic) CGPoint position STUB_PROPERTY;
@property (nonatomic, strong) UIRegion* region STUB_PROPERTY;
@property (assign, nonatomic) CGFloat strength STUB_PROPERTY;
@property (assign, nonatomic) CGFloat falloff STUB_PROPERTY;
@property (assign, nonatomic) CGFloat minimumRadius STUB_PROPERTY;
@property (assign, nonatomic) CGVector direction STUB_PROPERTY;
@property (assign, nonatomic) CGFloat smoothness STUB_PROPERTY;
@property (assign, nonatomic) CGFloat animationSpeed STUB_PROPERTY;
@end
