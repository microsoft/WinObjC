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

#ifndef _UISEARCHBAR_H_
#define _UISEARCHBAR_H_

#import "UIView.h"
#import "UITextField.h"
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

@protocol UISearchBarDelegate;

UIKIT_EXPORT_CLASS
@interface UISearchBar : UIView

@property (nonatomic, copy) NSString* text;
@property (nonatomic, assign) id<UISearchBarDelegate> delegate;
@property (nonatomic) BOOL showsCancelButton;
@property (nonatomic, copy) NSString* placeholder;
@property (nonatomic, retain) UIColor* tintColor;
@property (nonatomic, retain) UIColor* barTintColor;
@property (nonatomic) UITextAutocorrectionType autocorrectionType;
@property (nonatomic, copy) NSArray* scopeButtonTitles;
@property (nonatomic) BOOL showsScopeBar;
@property (nonatomic, getter=isSearchResultsButtonSelected) BOOL searchResultsButtonSelected;
@property (nonatomic, retain) UIImage* backgroundImage;
@property (nonatomic) BOOL showsBookmarkButton;
@property (nonatomic) NSInteger selectedScopeButtonIndex;
@property (nonatomic) UIBarStyle barStyle;
@property (nonatomic) UITextAutocapitalizationType autocapitalizationType;
@property (nonatomic) UIKeyboardType keyboardType;
@property (nonatomic) UIOffset searchTextPositionAdjustment;
@property (nonatomic) UISearchBarStyle searchBarStyle;
@property (nonatomic) NSString* prompt;

- (void)setShowsCancelButton:(BOOL)showsCancelButton animated:(BOOL)animated;
- (void)setImage:(UIImage*)iconImage forSearchBarIcon:(UISearchBarIcon)icon state:(UIControlState)state;
- (void)setSearchFieldBackgroundImage:(UIImage*)iconImage forState:(UIControlState)state;

@end

@protocol UISearchBarDelegate <NSObject>

@optional

- (BOOL)searchBarShouldBeginEditing:(UISearchBar*)searchBar;
- (void)searchBarTextDidBeginEditing:(UISearchBar*)searchBar;
- (BOOL)searchBarShouldEndEditing:(UISearchBar*)searchBar;
- (void)searchBarTextDidEndEditing:(UISearchBar*)searchBar;
- (void)searchBar:(UISearchBar*)searchBar textDidChange:(NSString*)searchText;
- (BOOL)searchBar:(UISearchBar*)searchBar shouldChangeTextInRange:(NSRange)range replacementText:(NSString*)text;

- (void)searchBarSearchButtonClicked:(UISearchBar*)searchBar;
- (void)searchBarBookmarkButtonClicked:(UISearchBar*)searchBar;
- (void)searchBarCancelButtonClicked:(UISearchBar*)searchBar;
- (void)searchBarResultsListButtonClicked:(UISearchBar*)searchBar;

- (void)searchBar:(UISearchBar*)searchBar selectedScopeButtonIndexDidChange:(NSInteger)selectedScope;

@end

#endif /* _UISEARCHBAR_H_ */
