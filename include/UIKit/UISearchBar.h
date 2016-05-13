//
//  UISearchBar.h
//  UIKit
//
//  Created by Peter Steinberger on 23.03.11.
//
/*
* Copyright (c) 2011, The Iconfactory. All rights reserved.
*
* Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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
#import "UITextField.h"
#import "UISearchBarDelegate.h"
#import <UIKit/UIInterface.h>

typedef enum {
    UISearchBarIconSearch,
    UISearchBarIconClear,
    UISearchBarIconBookmark,
    UISearchBarIconResultsList,
} UISearchBarIcon;

typedef enum {
    UISearchBarStyleDefault,
    UISearchBarStyleMinimal,
} UISearchBarStyle;

UIKIT_EXPORT_CLASS
@interface UISearchBar : UIView <NSCoding,
                                 UIAppearance,
                                 UIAppearanceContainer,
                                 UIBarPositioning,
                                 UICoordinateSpace,
                                 UIDynamicItem,
                                 UIFocusEnvironment,
                                 UITextInputTraits,
                                 UITraitEnvironment>
@property (copy, nonatomic) NSString* placeholder;
@property (copy, nonatomic) NSString* prompt;
@property (copy, nonatomic) NSString* text;
@property (nonatomic) UIBarStyle barStyle STUB_PROPERTY;
@property (nonatomic, strong) UIColor* barTintColor STUB_PROPERTY;
@property (nonatomic) UISearchBarStyle searchBarStyle STUB_PROPERTY;
@property (nonatomic, strong) UIColor* tintColor STUB_PROPERTY;
@property (getter=isTranslucent, assign, nonatomic) BOOL translucent;
@property (nonatomic) BOOL showsBookmarkButton STUB_PROPERTY;
@property (nonatomic) BOOL showsCancelButton;
- (void)setShowsCancelButton:(BOOL)showsCancelButton animated:(BOOL)animated STUB_METHOD;
@property (nonatomic) BOOL showsSearchResultsButton STUB_PROPERTY;
@property (getter=isSearchResultsButtonSelected, nonatomic) BOOL searchResultsButtonSelected STUB_PROPERTY;
@property (copy, nonatomic) NSArray* scopeButtonTitles STUB_PROPERTY;
@property (nonatomic) NSInteger selectedScopeButtonIndex STUB_PROPERTY;
@property (nonatomic) BOOL showsScopeBar STUB_PROPERTY;
@property (nonatomic, weak) id<UISearchBarDelegate> delegate;
@property (nonatomic, strong) UIImage* backgroundImage STUB_PROPERTY;
- (UIImage*)backgroundImageForBarPosition:(UIBarPosition)barPosition barMetrics:(UIBarMetrics)barMetrics STUB_METHOD;
- (void)setBackgroundImage:(UIImage*)backgroundImage
            forBarPosition:(UIBarPosition)barPosition
                barMetrics:(UIBarMetrics)barMetrics STUB_METHOD;
- (UIImage*)imageForSearchBarIcon:(UISearchBarIcon)icon state:(UIControlState)state STUB_METHOD;
- (void)setImage:(UIImage*)iconImage forSearchBarIcon:(UISearchBarIcon)icon state:(UIControlState)state STUB_METHOD;
- (UIOffset)positionAdjustmentForSearchBarIcon:(UISearchBarIcon)icon STUB_METHOD;
- (void)setPositionAdjustment:(UIOffset)adjustment forSearchBarIcon:(UISearchBarIcon)icon STUB_METHOD;
@property (readwrite, nonatomic, strong) UIView* inputAccessoryView STUB_PROPERTY;
@property (nonatomic, strong) UIImage* scopeBarBackgroundImage STUB_PROPERTY;
- (UIImage*)scopeBarButtonBackgroundImageForState:(UIControlState)state STUB_METHOD;
- (void)setScopeBarButtonBackgroundImage:(UIImage*)backgroundImage forState:(UIControlState)state STUB_METHOD;
- (UIImage*)scopeBarButtonDividerImageForLeftSegmentState:(UIControlState)leftState
                                        rightSegmentState:(UIControlState)rightState STUB_METHOD;
- (void)setScopeBarButtonDividerImage:(UIImage*)dividerImage
                  forLeftSegmentState:(UIControlState)leftState
                    rightSegmentState:(UIControlState)rightState STUB_METHOD;
- (NSDictionary*)scopeBarButtonTitleTextAttributesForState:(UIControlState)state STUB_METHOD;
- (void)setScopeBarButtonTitleTextAttributes:(NSDictionary*)attributes forState:(UIControlState)state STUB_METHOD;
- (UIImage*)searchFieldBackgroundImageForState:(UIControlState)state;
- (void)setSearchFieldBackgroundImage:(UIImage*)backgroundImage forState:(UIControlState)state;
@property (nonatomic) UIOffset searchFieldBackgroundPositionAdjustment STUB_PROPERTY;
@property (nonatomic) UIOffset searchTextPositionAdjustment STUB_PROPERTY;

@property (nonatomic) UITextAutocapitalizationType autocapitalizationType STUB_PROPERTY;
@property (nonatomic) UITextAutocorrectionType autocorrectionType STUB_PROPERTY;
@property (nonatomic) BOOL enablesReturnKeyAutomatically STUB_PROPERTY;
@property (nonatomic) UIKeyboardAppearance keyboardAppearance STUB_PROPERTY;
@property (nonatomic) UIKeyboardType keyboardType STUB_PROPERTY;
@property (nonatomic, getter=isSecureTextEntry) BOOL secureTextEntry STUB_PROPERTY;
@property (nonatomic) UITextSpellCheckingType spellCheckingType STUB_PROPERTY;
@property (nonatomic) UIReturnKeyType returnKeyType STUB_PROPERTY;
@end