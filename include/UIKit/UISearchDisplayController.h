//
//  UISearchDisplayController.h
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

#import "UIKitExport.h"
#import "UITableView.h"

@class UISearchBar, UITableView, UIViewController, UIPopoverController;
@protocol UITableViewDataSource
, UITableViewDelegate, UISearchDisplayDelegate;

UIKIT_EXPORT_CLASS
@interface UISearchDisplayController : NSObject {
    UIViewController* _viewController;
    UISearchBar* _searchBar;
    UITableView* _tableView;
    __unsafe_unretained id<UISearchDisplayDelegate> _delegate;
    __unsafe_unretained id<UITableViewDataSource> _tableViewDataSource;
    __unsafe_unretained id<UITableViewDelegate> _tableViewDelegate;
}

- (id)initWithSearchBar:(UISearchBar*)searchBar contentsController:(UIViewController*)viewController;

@property (nonatomic, assign) id<UISearchDisplayDelegate> delegate;

@property (nonatomic, getter=isActive) BOOL active;
- (void)setActive:(BOOL)visible animated:(BOOL)animated;

@property (nonatomic, readonly) UISearchBar* searchBar;
@property (nonatomic, readonly) UIViewController* searchContentsController;

@property (nonatomic, readonly) UITableView* searchResultsTableView;
@property (nonatomic, assign) id<UITableViewDataSource> searchResultsDataSource;
@property (nonatomic, assign) id<UITableViewDelegate> searchResultsDelegate;

@end
