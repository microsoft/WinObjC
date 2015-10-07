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

#ifndef _UIMOTIONEFFECT_H_
#define _UIMOTIONEFFECT_H_

#import <Foundation/NSObject.h>

@class NSArray;

typedef enum {
    UIInterpolatingMotionEffectTypeTiltAlongHorizontalAxis,
    UIInterpolatingMotionEffectTypeTiltAlongVerticalAxis
} UIInterpolatingMotionEffectType;

@interface UIMotionEffect : NSObject<NSCopying, NSCoding>

@end

@interface UIInterpolatingMotionEffect : UIMotionEffect

@property (retain, nonatomic) id maximumRelativeValue;
@property (retain, nonatomic) id minimumRelativeValue;

- (instancetype)initWithKeyPath:(NSString *)keyPath type:(UIInterpolatingMotionEffectType)type;

@end

@interface UIMotionEffectGroup : UIMotionEffect
@property (copy, nonatomic) NSArray *motionEffects;
@end

#endif /* _UIMOTIONEFFECT_H_ */