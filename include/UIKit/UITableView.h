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

#import <UIKit/UIScrollView.h>
#import <UIKit/UITableViewCell.h>
#import <UIKit/NSIndexPath+UITableView.h>
#import <UIKit/UITableViewDelegate.h>
#import <UIKit/UITableViewDataSource.h>

UIKIT_EXPORT NSString* const UITableViewIndexSearch;
UIKIT_EXPORT const CGFloat UITableViewAutomaticDimension;

UIKIT_EXPORT NSString* const UITableViewSelectionDidChangeNotification;

typedef enum {
    UITableViewStylePlain,
    UITableViewStyleGrouped,
} UITableViewStyle;

typedef enum {
    UITableViewScrollPositionNone,
    UITableViewScrollPositionTop,
    UITableViewScrollPositionMiddle,
    UITableViewScrollPositionBottom,
} UITableViewScrollPosition;

typedef enum {
    UITableViewRowAnimationFade,
    UITableViewRowAnimationRight,
    UITableViewRowAnimationLeft,
    UITableViewRowAnimationTop,
    UITableViewRowAnimationBottom,
    UITableViewRowAnimationNone,
    UITableViewRowAnimationMiddle,
    UITableViewRowAnimationAutomatic = 100,
} UITableViewRowAnimation;

@class UINib, UITableViewHeaderFooterView, UIVisualEffect;

UIKIT_EXPORT_CLASS
@interface UITableView : UIScrollView <NSCoding,
                                       NSObject,
                                       UIAppearance,
                                       UIAppearanceContainer,
                                       UICoordinateSpace,
                                       UIDynamicItem,
                                       UIFocusEnvironment,
                                       UITraitEnvironment>

- (CGRect)rectForFooterInSection:(NSInteger)section;
- (CGRect)rectForHeaderInSection:(NSInteger)section;
- (CGRect)rectForRowAtIndexPath:(NSIndexPath*)indexPath;
- (CGRect)rectForSection:(NSInteger)section;
- (NSArray*)indexPathsForRowsInRect:(CGRect)rect;
- (NSIndexPath*)indexPathForCell:(UITableViewCell*)cell;
- (NSIndexPath*)indexPathForRowAtPoint:(CGPoint)point;
- (NSInteger)numberOfRowsInSection:(NSInteger)section;
- (UITableViewCell*)cellForRowAtIndexPath:(NSIndexPath*)indexPath;
- (UITableViewCell*)dequeueReusableCellWithIdentifier:(NSString*)identifier;
- (UITableViewCell*)dequeueReusableCellWithIdentifier:(NSString*)identifier forIndexPath:(NSIndexPath*)indexPath;
- (UITableViewHeaderFooterView*)footerViewForSection:(NSInteger)section STUB_METHOD;
- (UITableViewHeaderFooterView*)headerViewForSection:(NSInteger)section STUB_METHOD;
- (UITableViewHeaderFooterView*)dequeueReusableHeaderFooterViewWithIdentifier:(NSString*)identifier;
- (instancetype)initWithFrame:(CGRect)frame style:(UITableViewStyle)style;
- (void)beginUpdates;
- (void)deleteRowsAtIndexPaths:(NSArray*)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
- (void)deleteSections:(NSIndexSet*)sections withRowAnimation:(UITableViewRowAnimation)animation;
- (void)deselectRowAtIndexPath:(NSIndexPath*)indexPath animated:(BOOL)animated;
- (void)endUpdates;

- (void)insertRowsAtIndexPaths:(NSArray*)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
- (void)insertSections:(NSIndexSet*)sections withRowAnimation:(UITableViewRowAnimation)animation;
- (void)moveRowAtIndexPath:(NSIndexPath*)indexPath toIndexPath:(NSIndexPath*)newIndexPath;
- (void)moveSection:(NSInteger)section toSection:(NSInteger)newSection STUB_METHOD;
- (void)registerClass:(Class)aClass forHeaderFooterViewReuseIdentifier:(NSString*)identifier;
- (void)registerClass:(Class)cellClass forCellReuseIdentifier:(NSString*)identifier;
- (void)registerNib:(UINib*)nib forCellReuseIdentifier:(NSString*)identifier;
- (void)registerNib:(UINib*)nib forHeaderFooterViewReuseIdentifier:(NSString*)identifier STUB_METHOD;
- (void)reloadData;
- (void)reloadRowsAtIndexPaths:(NSArray*)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
- (void)reloadSectionIndexTitles STUB_METHOD;
- (void)reloadSections:(NSIndexSet*)sections withRowAnimation:(UITableViewRowAnimation)animation;
- (void)scrollToNearestSelectedRowAtScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated;
- (void)scrollToRowAtIndexPath:(NSIndexPath*)indexPath atScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated;
- (void)selectRowAtIndexPath:(NSIndexPath*)indexPath animated:(BOOL)animated scrollPosition:(UITableViewScrollPosition)scrollPosition;
- (void)setEditing:(BOOL)editing animated:(BOOL)animate;

@property (copy, nonatomic) UIVisualEffect* separatorEffect STUB_PROPERTY;
@property (nonatomic) BOOL allowsMultipleSelection;
@property (nonatomic) BOOL allowsMultipleSelectionDuringEditing STUB_PROPERTY;
@property (nonatomic) BOOL allowsSelection;
@property (nonatomic) BOOL allowsSelectionDuringEditing STUB_PROPERTY;
@property (nonatomic) BOOL cellLayoutMarginsFollowReadableWidth STUB_PROPERTY;
@property (nonatomic) BOOL remembersLastFocusedIndexPath STUB_PROPERTY;
@property (nonatomic) CGFloat estimatedRowHeight STUB_PROPERTY;
@property (nonatomic) CGFloat estimatedSectionFooterHeight STUB_PROPERTY;
@property (nonatomic) CGFloat estimatedSectionHeaderHeight STUB_PROPERTY;
@property (nonatomic) CGFloat rowHeight;
@property (nonatomic) CGFloat sectionFooterHeight;
@property (nonatomic) CGFloat sectionHeaderHeight;
@property (nonatomic) NSInteger sectionIndexMinimumDisplayRowCount;
@property (nonatomic) UIEdgeInsets separatorInset;
@property (nonatomic) UITableViewCellSeparatorStyle separatorStyle;
@property (nonatomic, assign) id<UITableViewDataSource> dataSource;
@property (nonatomic, assign) id<UITableViewDelegate> delegate;
@property (nonatomic, getter=isEditing) BOOL editing;
@property (nonatomic, readonly) UITableViewStyle style;
@property (nonatomic, readwrite, retain) UIView* backgroundView;
@property (nonatomic, retain) UIColor* separatorColor;
@property (nonatomic, retain) UIView* tableFooterView;
@property (nonatomic, retain) UIView* tableHeaderView;
@property (nonatomic, strong) UIColor* sectionIndexBackgroundColor STUB_PROPERTY;
@property (nonatomic, strong) UIColor* sectionIndexColor STUB_PROPERTY;
@property (nonatomic, strong) UIColor* sectionIndexTrackingBackgroundColor STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* indexPathsForSelectedRows;
@property (readonly, nonatomic) NSArray* indexPathsForVisibleRows;
@property (readonly, nonatomic) NSArray* visibleCells;
@property (readonly, nonatomic) NSIndexPath* indexPathForSelectedRow;
@property (readonly, nonatomic) NSInteger numberOfSections;
@end
