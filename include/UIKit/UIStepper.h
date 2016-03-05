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
#import <UIKit/UIAppearance.h>
#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UICoordinateSpace.h>
#import <UIKit/UIDynamicItem.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UIControl.h>

@class UIColor;
@class UIImage;

UIKIT_EXPORT_CLASS
@interface UIStepper : UIControl <NSCoding,
                                  NSObject,
                                  UIAppearance,
                                  UIAppearanceContainer,
                                  UICoordinateSpace,
                                  UIDynamicItem,
                                  UIFocusEnvironment,
                                  UITraitEnvironment>
@property (getter=isContinuous, nonatomic) BOOL continuous STUB_PROPERTY;
@property (nonatomic) BOOL autorepeat STUB_PROPERTY;
@property (nonatomic) BOOL wraps STUB_PROPERTY;
@property (nonatomic) double minimumValue STUB_PROPERTY;
@property (nonatomic) double maximumValue STUB_PROPERTY;
@property (nonatomic) double stepValue STUB_PROPERTY;
@property (nonatomic) double value STUB_PROPERTY;
@property (nonatomic, strong) UIColor* tintColor STUB_PROPERTY;
- (UIImage*)backgroundImageForState:(UIControlState)state STUB_METHOD;
- (void)setBackgroundImage:(UIImage*)image forState:(UIControlState)state STUB_METHOD;
- (UIImage*)decrementImageForState:(UIControlState)state STUB_METHOD;
- (void)setDecrementImage:(UIImage*)image forState:(UIControlState)state STUB_METHOD;
- (UIImage*)dividerImageForLeftSegmentState:(UIControlState)leftState rightSegmentState:(UIControlState)rightState STUB_METHOD;
- (void)setDividerImage:(UIImage*)image
    forLeftSegmentState:(UIControlState)leftState
      rightSegmentState:(UIControlState)rightState STUB_METHOD;
- (UIImage*)incrementImageForState:(UIControlState)state STUB_METHOD;
- (void)setIncrementImage:(UIImage*)image forState:(UIControlState)state STUB_METHOD;
@end
