//
//  UITabBar.h
//  UIKit
//
//  Created by Peter Steinberger on 23.03.11.
//
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

#import "UIView.h"
#import "UIInterface.h"

@class UITabBar, UITabBarItem, UIImage;
@protocol UITabBarDelegate;

typedef enum : NSInteger {
    UITabBarItemPositioningAutomatic,
    UITabBarItemPositioningFill,
    UITabBarItemPositioningCentered,
} UITabBarItemPositioning;

UIKIT_EXPORT_CLASS
@interface UITabBar : UIView <NSCoding,
                              NSObject,
                              UIAppearance,
                              UIAppearanceContainer,
                              UICoordinateSpace,
                              UIDynamicItem,
                              UIFocusEnvironment,
                              UITraitEnvironment>
@property (assign, nonatomic) id<UITabBarDelegate> delegate;
@property (copy, nonatomic) NSArray* items;
@property (assign, nonatomic) UITabBarItem* selectedItem;
- (void)setItems:(NSArray*)items animated:(BOOL)animated STUB_METHOD;
- (void)beginCustomizingItems:(NSArray*)items STUB_METHOD;
- (BOOL)endCustomizingAnimated:(BOOL)animated STUB_METHOD;
- (BOOL)isCustomizing STUB_METHOD;
@property (nonatomic) UIBarStyle barStyle STUB_PROPERTY;
@property (nonatomic, strong) UIColor* barTintColor STUB_PROPERTY;
@property (nonatomic) UITabBarItemPositioning itemPositioning STUB_PROPERTY;
@property (nonatomic) CGFloat itemSpacing STUB_PROPERTY;
@property (nonatomic) CGFloat itemWidth STUB_PROPERTY;
@property (nonatomic, strong) UIColor* tintColor STUB_PROPERTY;
@property (nonatomic, strong) UIColor* selectedImageTintColor STUB_PROPERTY;
@property (getter=isTranslucent, nonatomic) BOOL translucent STUB_PROPERTY;
@property (nonatomic, strong) UIImage* backgroundImage;
@property (nonatomic, strong) UIImage* shadowImage STUB_PROPERTY;
@property (nonatomic, strong) UIImage* selectionIndicatorImage;
@end