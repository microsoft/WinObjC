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

#import <QuartzCore/CALayer.h>
#import <QuartzCore/CAMediaTiming.h>

@class NSString;
@class NSArray;
@class NSDictionary;

CA_EXPORT_CLASS
@interface CAEmitterCell : NSObject <CAMediaTiming, NSCoding, NSObject>

+ (instancetype)emitterCell;
@property (strong) id contents;
@property CGRect contentsRect;
@property (copy) NSArray* emitterCells;
@property (getter=isEnabled) BOOL enabled;
@property CGColorRef color;
@property float redRange;
@property float greenRange;
@property float blueRange;
@property float alphaRange;
@property float redSpeed;
@property float greenSpeed;
@property float blueSpeed;
@property float alphaSpeed;
@property (copy) NSString* magnificationFilter;
@property (copy) NSString* minificationFilter;
@property float minificationFilterBias;
@property CGFloat scale;
@property CGFloat scaleRange;
@property (copy) NSString* name;
@property (copy) NSDictionary* style;
@property CGFloat spin;
@property CGFloat spinRange;
@property CGFloat emissionLatitude;
@property CGFloat emissionLongitude;
@property CGFloat emissionRange;
@property float lifetime;
@property float lifetimeRange;
@property float birthRate;
@property CGFloat scaleSpeed;
@property CGFloat velocity;
@property CGFloat velocityRange;
@property CGFloat xAcceleration;
@property CGFloat yAcceleration;
@property CGFloat zAcceleration;
+ (id)defaultValueForKey:(NSString*)key;
- (BOOL)shouldArchiveValueForKey:(NSString*)key;

@end
