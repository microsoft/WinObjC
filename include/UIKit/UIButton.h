/*
 * Copyright (c) 2011, The Iconfactory. All rights reserved.
 * Copyright (c) Microsoft Corporation. All rights reserved.
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

#import <UIKit/UIControl.h>
#import <UIKit/UIKitTypes.h>

typedef enum {
    UIButtonTypeCustom = 0,
    UIButtonTypeSystem,
    UIButtonTypeDetailDisclosure,
    UIButtonTypeInfoLight,
    UIButtonTypeInfoDark,
    UIButtonTypeContactAdd,
    UIButtonTypeRoundedRect,
    UIButtonTypeRoundedRectLegacy,
} UIButtonType;

@class UILabel;
@class UIImageView;
@class UIImage;
@class UIFont;
@class UIColor;

UIKIT_EXPORT_CLASS
@interface UIButton : UIControl <NSCoding,
                                 NSObject,
                                 UIAppearance,
                                 UIAppearanceContainer,
                                 UICoordinateSpace,
                                 UIDynamicItem,
                                 UIFocusEnvironment,
                                 UITraitEnvironment>

+ (instancetype)buttonWithType:(UIButtonType)buttonType;
- (CGRect)backgroundRectForBounds:(CGRect)bounds NOTINPLAN_METHOD;
- (CGRect)contentRectForBounds:(CGRect)bounds;
- (CGRect)imageRectForContentRect:(CGRect)contentRect;
- (CGRect)titleRectForContentRect:(CGRect)contentRect;
- (NSAttributedString*)attributedTitleForState:(UIControlState)state NOTINPLAN_METHOD;
- (NSString*)titleForState:(UIControlState)state;
- (UIColor*)titleColorForState:(UIControlState)state;
- (UIColor*)titleShadowColorForState:(UIControlState)state NOTINPLAN_METHOD;
- (UIImage*)backgroundImageForState:(UIControlState)state;
- (UIImage*)imageForState:(UIControlState)state;
- (void)setAttributedTitle:(NSAttributedString*)title forState:(UIControlState)state NOTINPLAN_METHOD;
- (void)setBackgroundImage:(UIImage*)image forState:(UIControlState)state;
- (void)setImage:(UIImage*)image forState:(UIControlState)state;
- (void)setTitle:(NSString*)title forState:(UIControlState)state;
- (void)setTitleColor:(UIColor*)color forState:(UIControlState)state;
- (void)setTitleShadowColor:(UIColor*)color forState:(UIControlState)state NOTINPLAN_METHOD;

@property (nonatomic) BOOL adjustsImageWhenDisabled;
@property (nonatomic) BOOL adjustsImageWhenHighlighted;
@property (nonatomic) BOOL reversesTitleShadowWhenHighlighted NOTINPLAN_PROPERTY;
@property (nonatomic) BOOL showsTouchWhenHighlighted NOTINPLAN_PROPERTY;
@property (nonatomic) CGSize titleShadowOffset NOTINPLAN_PROPERTY;
@property (nonatomic) NSLineBreakMode lineBreakMode;
@property (nonatomic) UIEdgeInsets contentEdgeInsets;
@property (nonatomic) UIEdgeInsets imageEdgeInsets;
@property (nonatomic) UIEdgeInsets titleEdgeInsets;
@property (nonatomic, readonly) UIButtonType buttonType;
@property (nonatomic, readonly, retain) NSString* currentTitle;
@property (nonatomic, readonly, retain) UIColor* currentTitleColor;
@property (nonatomic, readonly, retain) UIColor* currentTitleShadowColor NOTINPLAN_PROPERTY;
@property (nonatomic, readonly, retain) UIImage* currentBackgroundImage;
@property (nonatomic, readonly, retain) UIImage* currentImage;
@property (nonatomic, readonly, retain) UIImageView* imageView;
@property (nonatomic, readonly, retain) UILabel* titleLabel;
@property (nonatomic, retain) UIColor* tintColor NOTINPLAN_PROPERTY;
@property (nonatomic, retain) UIFont* font;
@property (readonly, nonatomic, strong) NSAttributedString* currentAttributedTitle NOTINPLAN_PROPERTY;

@end
