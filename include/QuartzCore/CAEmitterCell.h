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
#import <QuartzCore/CALayer.h>
#import <QuartzCore/CAMediaTiming.h>

@class NSString;
@class NSArray;
@class NSDictionary;

CA_EXPORT_CLASS
@interface CAEmitterCell : NSObject <CAMediaTiming, NSCoding>

+ (instancetype)emitterCell;
@property (strong) id contents;
@property CGRect contentsRect;
@property (copy) NSArray* emitterCells;
@property (getter=isEnabled) BOOL enabled;
@property CGColorRef color STUB_PROPERTY;
@property float redRange;
@property float greenRange;
@property float blueRange;
@property float alphaRange;
@property float redSpeed STUB_PROPERTY;
@property float greenSpeed STUB_PROPERTY;
@property float blueSpeed STUB_PROPERTY;
@property float alphaSpeed STUB_PROPERTY;
@property (copy) NSString* magnificationFilter STUB_PROPERTY;
@property (copy) NSString* minificationFilter STUB_PROPERTY;
@property float minificationFilterBias STUB_PROPERTY;
@property CGFloat scale;
@property CGFloat scaleRange;
@property (copy) NSString* name;
@property (copy) NSDictionary* style STUB_PROPERTY;
@property CGFloat spin;
@property CGFloat spinRange STUB_PROPERTY;
@property CGFloat emissionLatitude;
@property CGFloat emissionLongitude;
@property CGFloat emissionRange;
@property float lifetime;
@property float lifetimeRange;
@property float birthRate;
@property CGFloat scaleSpeed;
@property CGFloat velocity;
@property CGFloat velocityRange;
@property CGFloat xAcceleration STUB_PROPERTY;
@property CGFloat yAcceleration;
@property CGFloat zAcceleration STUB_PROPERTY;
+ (id)defaultValueForKey:(NSString*)key STUB_METHOD;
- (BOOL)shouldArchiveValueForKey:(NSString*)key STUB_METHOD;

// CAMediaTiming
@property BOOL autoreverses;
@property CFTimeInterval beginTime;
@property CFTimeInterval duration;
@property (copy) NSString* fillMode STUB_PROPERTY;
@property float repeatCount;
@property CFTimeInterval repeatDuration;
@property float speed;
@property CFTimeInterval timeOffset;

@end
