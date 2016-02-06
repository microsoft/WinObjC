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
#import <UIKit/UIMotionEffect.h>

@class NSString;

typedef enum {
    UIInterpolatingMotionEffectTypeTiltAlongHorizontalAxis,
    UIInterpolatingMotionEffectTypeTiltAlongVerticalAxis,
} UIInterpolatingMotionEffectType;

UIKIT_EXPORT_CLASS
@interface UIInterpolatingMotionEffect : UIMotionEffect <NSCoding, NSCopying>
- (instancetype)initWithKeyPath:(NSString*)keyPath type:(UIInterpolatingMotionEffectType)type STUB_METHOD;
@property (readonly, nonatomic) NSString* keyPath STUB_PROPERTY;
@property (readonly, nonatomic) UIInterpolatingMotionEffectType type STUB_PROPERTY;
@property (nonatomic, strong) id minimumRelativeValue STUB_PROPERTY;
@property (nonatomic, strong) id maximumRelativeValue STUB_PROPERTY;
@end
