/*
 * Copyright (c) 2011, The Iconfactory. All rights reserved.
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

#ifndef _UIBARBUTTONITEM_H_
#define _UIBARBUTTONITEM_H_

#import "UIBarItem.h"
#import <UIKit/UIControl.h>

typedef enum {
    UIBarButtonSystemItemDone,
    UIBarButtonSystemItemCancel,
    UIBarButtonSystemItemEdit,
    UIBarButtonSystemItemSave,
    UIBarButtonSystemItemAdd,
    UIBarButtonSystemItemFlexibleSpace,
    UIBarButtonSystemItemFixedSpace,
    UIBarButtonSystemItemCompose,
    UIBarButtonSystemItemReply,
    UIBarButtonSystemItemAction,
    UIBarButtonSystemItemOrganize,
    UIBarButtonSystemItemBookmarks,
    UIBarButtonSystemItemSearch,
    UIBarButtonSystemItemRefresh,
    UIBarButtonSystemItemStop,
    UIBarButtonSystemItemCamera,
    UIBarButtonSystemItemTrash,
    UIBarButtonSystemItemPlay,
    UIBarButtonSystemItemPause,
    UIBarButtonSystemItemRewind,
    UIBarButtonSystemItemFastForward,
    UIBarButtonSystemItemUndo, // iPhoneOS 3.0
    UIBarButtonSystemItemRedo, // iPhoneOS 3.0
} UIBarButtonSystemItem;

typedef enum {
    UIBarButtonItemStylePlain,
    UIBarButtonItemStyleBordered,
    UIBarButtonItemStyleDone,
} UIBarButtonItemStyle;

enum {
    UIBarMetricsDefault,
    UIBarMetricsLandscapePhone,
};
typedef uint32_t UIBarMetrics;

@class UIView;
@class UIImage;
@class UIColor;

UIKIT_EXPORT_CLASS
@interface UIBarButtonItem : UIBarItem <NSCoding>

- (id)initWithBarButtonSystemItem:(UIBarButtonSystemItem)systemItem target:(id)target action:(SEL)action;
- (id)initWithCustomView:(UIView*)customView;
- (id)initWithTitle:(NSString*)title style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)action;
- (id)initWithImage:(UIImage*)image style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)action;
- (void)setBackButtonBackgroundImage:(UIImage*)backgroundImage forState:(UIControlState)state barMetrics:(UIBarMetrics)barMetrics;
- (void)setBackgroundImage:(UIImage*)backgroundImage forState:(UIControlState)state barMetrics:(UIBarMetrics)barMetrics;
- (UIImage*)backgroundImageForState:(UIControlState)state barMetrics:(UIBarMetrics)barMetrics;
- (void)setBackButtonTitlePositionAdjustment:(UIOffset)adjustment forBarMetrics:(UIBarMetrics)barMetrics;

@property (nonatomic) UIBarButtonItemStyle style;
@property (nonatomic) CGFloat width;
@property (nonatomic, retain) UIView* customView;
@property (nonatomic, assign) id target;
@property (nonatomic) SEL action;
@property (nonatomic, retain) UIColor* tintColor;
@property (nonatomic, copy) NSSet* possibleTitles;

// ----------------------------------------------------------------------------------------------------------
@end

#endif /* _UIBARBUTTONITEM_H_ */
