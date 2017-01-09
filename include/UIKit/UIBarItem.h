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
#import <UIKit/UIAppearance.h>
#import <UIKit/UIControl.h>
#import "UIGeometry.h"
#import <UIKit/UIAccessibility.h>

@class UIImage;

@interface UIBarItem : NSObject <NSCoding, UIAppearance, UIAccessibility>

@property (nonatomic, getter=isEnabled) BOOL enabled;
@property (nonatomic, retain) UIImage* image;
@property (nonatomic, assign) UIEdgeInsets imageInsets STUB_PROPERTY;
@property (nonatomic, copy) NSString* title;
@property (nonatomic) NSInteger tag STUB_PROPERTY;

// UIAccessibility properties.
@property BOOL isAccessibilityElement;
@property (copy) NSString* accessibilityLabel STUB_PROPERTY;
@property (copy) NSString* accessibilityHint;
@property (copy) NSString* accessibilityValue STUB_PROPERTY;
@property UIAccessibilityTraits accessibilityTraits STUB_PROPERTY;
@property UIAccessibilityNavigationStyle accessibilityNavigationStyle STUB_PROPERTY;
@property (nonatomic) CGRect accessibilityFrame STUB_PROPERTY;
@property (copy) UIBezierPath* accessibilityPath STUB_PROPERTY;
@property CGPoint accessibilityActivationPoint STUB_PROPERTY;
@property (retain) NSString* accessibilityLanguage STUB_PROPERTY;
@property BOOL accessibilityElementsHidden STUB_PROPERTY;
@property BOOL shouldGroupAccessibilityChildren STUB_PROPERTY;
@property BOOL accessibilityViewIsModal STUB_PROPERTY;

// Not really part of the UIAccessibility protocol (standalone UIAccessibilityIdentifier protocol)
@property (copy) NSString* accessibilityIdentifier STUB_PROPERTY;

- (void)setTitleTextAttributes:(NSDictionary*)attributes forState:(UIControlState)state STUB_METHOD;

@end
