//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include "Starboard.h"

#include <UIKit/UIKit.h>
#include <vector>
#include "UIBarButtonItem+Internals.h"

@class UIAppearanceSetter;

@implementation UIToolbar {
    id _delegate;
    UIBarStyle _style;
    idretaintype(NSMutableArray) _items;
    idretaintype(UIImage) _backgroundGradient;
    idretaintype(NSMutableArray) _curAddedViews;
    idretaintype(UIColor) _tintColor;

    idretaintype(UIColor) _backgroundTintColor;
    idretaintype(UIColor) _itemTintColor;
}
void initInternal(UIToolbar* self) {
    self->_curAddedViews.attach([NSMutableArray new]);
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    [super initWithCoder:coder];
    initInternal(self);

    NSArray* items = [coder decodeObjectForKey:@"UIItems"];
    _style = (UIBarStyle)[coder decodeInt32ForKey:@"UIBarStyle"];

    switch (_style) {
        case 1:
            _backgroundGradient =
                [[UIImage imageNamed:@"/img/navgradient-blackopaque.png"] stretchableImageWithLeftCapWidth:1 topCapHeight:0];
            break;

        case 2:
        case 3:
            _backgroundGradient =
                [[UIImage imageNamed:@"/img/navgradient-blacktranslucent.png"] stretchableImageWithLeftCapWidth:1 topCapHeight:0];
            break;

        default:
            _backgroundGradient = [[UIImage imageNamed:@"/img/navgradient-default.png"] stretchableImageWithLeftCapWidth:1 topCapHeight:0];
            break;
    }

    UIImageSetLayerContents([self layer], _backgroundGradient);
    UIColor* tintColor = [coder decodeObjectForKey:@"UITintColor"];
    if (tintColor != nil) {
        [self setTintColor:tintColor];
    }

    if (items != nil) {
        [self setItems:items];
    }

    return self;
}

- (instancetype)initWithFrame:(CGRect)frame {
    if (frame.size.height > 44.0f) {
        frame.size.height = 44.0f;
    }
    [super initWithFrame:frame];
    initInternal(self);

    return self;
}

- (void)setDelegate:(id)delegateAddr {
    _delegate = delegateAddr;
}

/**
 @Status Interoperable
*/
- (void)setBarStyle:(UIBarStyle)style {
    _style = style;

    switch (_style) {
        case 1:
            _backgroundGradient =
                [[UIImage imageNamed:@"/img/navgradient-blackopaque.png"] stretchableImageWithLeftCapWidth:1 topCapHeight:0];
            break;

        case 2:
        case 3:
            _backgroundGradient =
                [[UIImage imageNamed:@"/img/navgradient-blacktranslucent.png"] stretchableImageWithLeftCapWidth:1 topCapHeight:0];
            break;

        default:
            _backgroundGradient = [[UIImage imageNamed:@"/img/navgradient-default.png"] stretchableImageWithLeftCapWidth:1 topCapHeight:0];
            break;
    }

    UIImageSetLayerContents([self layer], _backgroundGradient);
}

- (void)setButtonBarTrackingMode:(int)mode {
}

- (id)viewWithTag:(NSUInteger)tag {
    return nil;
}

- (void)showSelectionForButton:(NSUInteger)button {
}

- (void)registerButtonGroup:(int)group withButtons:(int)withButtons withCount:(int)withCount {
}

- (void)showButtonGroup:(int)group withDuration:(double)withDuration {
}

- (void)buttonClicked:(NSUInteger)button {
    [_delegate buttonBarItemTapped:button];
}

/**
 @Status Interoperable
*/
- (void)setItems:(NSArray*)items {
    [self setItems:items animated:FALSE];
}

/**
 @Status Stub
*/
- (void)setTranslucent:(BOOL)translucent {
    UNIMPLEMENTED();
}

static void setBackground(UIToolbar* self, UIColor* color) {
    CGSize size;

    size.width = 2.0f;
    size.height = 10.0f;
    UIGraphicsBeginImageContextWithOptions(size, 1, 2.0f);
    CGContextRef ctx = (CGContextRef)UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(ctx, [color CGColor]);
    CGRect rct = { 0, 0, 0, 0 };
    rct.size = size;
    CGContextFillRect(ctx, rct);

    UIImage* image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();

    self->_backgroundGradient = [image stretchableImageWithLeftCapWidth:1 topCapHeight:0];
    UIImageSetLayerContents([self layer], self->_backgroundGradient);
}

/**
 @Status Stub
*/
- (void)setTintColor:(id)color {
    UNIMPLEMENTED();
    _tintColor = color;

    if (!isOSTarget(@"7.0")) {
        setBackground(self, color);
        _backgroundTintColor = color;
    } else {
        _itemTintColor = color;
        int count = [_items count];
        int i;
        for (i = 0; i < count; i++) {
            id curButton = [_items objectAtIndex:i];

            if (_itemTintColor != nil) {
                [curButton setTintColor:(id)_itemTintColor];
            }
        }
    }
}

/**
 @Status Stub
*/
- (UIColor*)tintColor {
    UNIMPLEMENTED();
    return _tintColor;
}

/**
 @Status Interoperable
*/
- (NSArray*)items {
    return _items;
}

struct BarContainedView {
    CGRect frame;
    UIView* view;
};

struct BarViewContainer {
    std::vector<BarContainedView> subViews;
    float width;
    int flexibilitiesBefore, flexibilitiesAfter;
    DWORD autoResizing;
    bool containsCustom;

    float groupLeft, groupRight;
};

void layoutItems(UIToolbar* self) {
    for (UIView* curView in(NSArray*)self->_curAddedViews) {
        [curView removeFromSuperview];
    }
    [self->_curAddedViews removeAllObjects];

    int count = [self->_items count];
    float totalWidth = 0.0f;
    float numFlexibilities = 0.0f;
    float curPos = 0.0f;
    CGSize maxSize = { 0 };
    bool isFirstItem = false;
    int i;

    std::vector<BarViewContainer*> viewGroups;
    BarViewContainer *curContainer = NULL, *lastContainer = NULL;
    float curWidth = 0.0f;
    int curFlexibilities = 0;
    bool leftAlign = true;
    float groupHeight = 44.0f;

    for (i = 0; i < count; i++) {
        UIBarButtonItem* curButton = [self->_items objectAtIndex:i];

        if (self->_itemTintColor != nil) {
            [curButton setTintColor:(id)self->_itemTintColor];
        }
        [UIAppearanceSetter _applyAppearance:curButton withAppearanceClass:[UIBarButtonItem class] withBaseView:self];

        if ([curButton isFlexibleWidth]) {
            if (curContainer) {
                lastContainer = curContainer;

                curContainer->flexibilitiesBefore = curFlexibilities;
                curContainer->autoResizing |= UIViewAutoresizingFlexibleRightMargin;
                viewGroups.push_back(curContainer);
                curContainer = NULL;
                curWidth = 0.0f;
                curFlexibilities = 0;
            }
            numFlexibilities += 1.0f;
            curFlexibilities++;
            leftAlign = false;

            if (lastContainer) {
                lastContainer->flexibilitiesAfter = curFlexibilities;
            }
        } else {
            CGSize size = [curButton idealSize];
            float margin = curButton.margin;
            float controlWidth = size.width + margin * 2.0f;

            UIView* itemView = [curButton view];
            if (itemView) {
                bool isCustom = false;

                if (!curContainer) {
                    curContainer = new BarViewContainer();
                    curContainer->autoResizing = UIViewAutoresizingFlexibleTopMargin;
                    curContainer->containsCustom = false;
                    curContainer->flexibilitiesBefore = 0;
                    curContainer->flexibilitiesAfter = 0;
                    if (!leftAlign) {
                        curContainer->autoResizing |= UIViewAutoresizingFlexibleLeftMargin;
                    }
                }
                UIView* customView = [curButton customView];
                if (customView != nil) {
                    curContainer->containsCustom = true;
                    DWORD mask = [customView autoresizingMask];
                    if (mask & UIViewAutoresizingFlexibleWidth) {
                        curContainer->autoResizing |= UIViewAutoresizingFlexibleWidth;
                    }
                }

                BarContainedView subview;
                subview.view = itemView;
                subview.frame.origin.x = curWidth + margin;
                subview.frame.origin.y = groupHeight / 2.0f - size.height / 2.0f;
                subview.frame.size.width = size.width;
                subview.frame.size.height = size.height;

                curContainer->subViews.push_back(subview);
            }

            totalWidth += controlWidth;
            curWidth += controlWidth;
            if (curContainer)
                curContainer->width = curWidth;
        }
    }

    //  Close off the last group
    if (curContainer) {
        curContainer->flexibilitiesBefore = curFlexibilities;
        viewGroups.push_back(curContainer);
    }

    if (viewGroups.size() > 0) {
        CGRect bounds;
        bounds = [self bounds];
        bool leftAlign = true;
        float curX = 0.0f;
        float flexibleWidth;

        if (numFlexibilities > 0.0f) {
            flexibleWidth = (bounds.size.width - totalWidth) / numFlexibilities;
        } else {
            flexibleWidth = 0.0f;
        }
        if (flexibleWidth < 0)
            flexibleWidth = 0;

        std::vector<BarViewContainer*>::iterator curGroup;

        for (curGroup = viewGroups.begin(); curGroup != viewGroups.end(); curGroup++) {
            curX += (*curGroup)->flexibilitiesBefore * flexibleWidth;
            (*curGroup)->groupLeft = curX;
            (*curGroup)->groupRight = curX + (*curGroup)->width;
            curX += (*curGroup)->width;
        }

        for (curGroup = viewGroups.begin(); curGroup != viewGroups.end(); curGroup++) {
            CGRect groupFrame;

            groupFrame.origin.x = (*curGroup)->groupLeft;
            groupFrame.origin.y = bounds.size.height / 2.0f - groupHeight / 2.0f;
            groupFrame.size.width = (*curGroup)->width;
            groupFrame.size.height = groupHeight;

            if ((*curGroup)->containsCustom) {
                //  Attempt to center align this group towards the center of the view
                if ((*curGroup)->flexibilitiesBefore > 0 && (*curGroup)->flexibilitiesAfter > 0) {
                    float leftLimit, rightLimit;
                    if (curGroup != viewGroups.begin()) {
                        leftLimit = (*(curGroup - 1))->groupRight;
                    } else {
                        leftLimit = 0.0f;
                    }
                    if ((curGroup + 1) != viewGroups.end()) {
                        rightLimit = (*(curGroup + 1))->groupLeft;
                    } else {
                        rightLimit = bounds.size.width;
                    }

                    float newPos = bounds.size.width / 2.0f - groupFrame.size.width / 2.0f;
                    if (newPos < leftLimit) {
                        newPos = leftLimit;
                    }
                    if (newPos + groupFrame.size.width > rightLimit) {
                        newPos = rightLimit - groupFrame.size.width;
                    }
                    groupFrame.origin.x = newPos;
                }
            }

            UIView* groupView = [[UIView alloc] initWithFrame:groupFrame];
            [groupView setAutoresizingMask:(*curGroup)->autoResizing];

            //  Add subviews
            std::vector<BarContainedView>::iterator curContainedView;
            for (curContainedView = (*curGroup)->subViews.begin(); curContainedView != (*curGroup)->subViews.end(); curContainedView++) {
                [curContainedView->view setFrame:curContainedView->frame];
                [groupView addSubview:curContainedView->view];
            }

            [self->_curAddedViews addObject:groupView];
            [self addSubview:groupView];
            [groupView release];
        }

        for (curGroup = viewGroups.begin(); curGroup != viewGroups.end(); curGroup++) {
            delete *curGroup;
        }
    }
}

/**
 @Status Caveat
 @Notes animated parameter not supported
*/
- (void)setItems:(NSArray*)items animated:(BOOL)animated {
    _items = items;
    layoutItems(self);
}

- (void)setFrame:(CGRect)frame {
    [self _setShouldLayout];
    [super setFrame:frame];
}

- (CGSize)sizeThatFits:(CGSize)curSize {
    CGSize ret;

    ret.width = 0;
    ret.height = 0;

    int count = [_items count];
    float totalWidth = 0.0f;
    CGSize maxSize = { 0 };
    int i;

    for (i = 0; i < count; i++) {
        UIBarButtonItem* curButton = [_items objectAtIndex:i];

        if (![curButton isFlexibleWidth]) {
            CGSize idealSize = [curButton idealSize];
            totalWidth += idealSize.width + curButton.margin * 2.0f;
        }
    }

    CGRect parentWidth;

    parentWidth = [[self superview] bounds];

    // ret->width = curPos;
    //  Durr ..
    ret.width = 320.0f;
    ret.height = 44;

    return ret;
}

- (void)dealloc {
    _items = nil;
    _backgroundGradient = nil;
    _curAddedViews = nil;
    _tintColor = nil;

    [super dealloc];
}

/**
 @Status Caveat
 @Notes position and metrics parameters not supported
*/
- (void)setBackgroundImage:(UIImage*)image forToolbarPosition:(unsigned int)position barMetrics:(UIBarMetrics)metrics {
    _backgroundGradient = image;
    UIImageSetLayerContents([self layer], _backgroundGradient);
}

/**
 @Status Stub
*/
- (void)setBarTintColor:(UIColor*)color {
    UNIMPLEMENTED();
    if (isOSTarget(@"7.0")) {
        setBackground(self, color);
        _backgroundTintColor = color;
    }
}
@end
