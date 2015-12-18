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

#include "Foundation/NSMutableArray.h"
#include "Foundation/NSString.h"
#include "CoreGraphics/CGContext.h"
#include "CoreGraphics/CGGradient.h"

#include "UIKit/UIView.h"
#include "UIKit/UIFont.h"
#include "UIKit/UIColor.h"
#include "UIKit/UIDevice.h"
#include "UIKit/UIImage.h"

#include "UIKit/UIButton.h"
#include "UIKit/UILabel.h"
#include "UIKit/UINavigationBar.h"
#include "UIKit/UIBarButtonItem.h"
#include "UIBarButtonItem+Internals.h"

@implementation UINavigationBar {
    idretaintype(NSMutableArray) _items;
    id _delegate;
    CGSize _textShadowOffset;
    idretain _font, _textColor, _textShadowColor;
    idretaintype(UIImage) _navGradient;
    UINavigationItem *_curItem, *_newItem;
    idretaintype(UIBarButtonItem) _leftButton, _rightButton;
    idretaintype(UIBarButtonItem) _backButton;
    idretaintype(UIView) _titleView;
    idretaintype(UILabel) _titleLabel;
    idretaintype(NSDictionary) _titleTextAttributes;
    idretaintype(UIColor) _tintColor;
    idretaintype(UIColor) _barTintColor;
    UIBarStyle _style;
}
static void setBackground(UINavigationBar* self) {
    UIImageSetLayerContents([self layer], self->_navGradient);
}

/**
 @Status Stub
*/
- (CGFloat)titleVerticalPositionAdjustmentForBarMetrics:(UIBarMetrics)barMetrics {
    UNIMPLEMENTED();
    return NULL;
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    NSArray* items = [coder decodeObjectForKey:@"UIItems"];

    if (items == nil) {
        (_items).attach([NSMutableArray new]);
    } else {
        (_items).attach([items mutableCopy]);
    }

    if ([_items count] > 0) {
        _newItem = [_items objectAtIndex:0];
    }

    _font = [UIFont boldSystemFontOfSize:18];
    _textColor = [UIColor blackColor];
    _textShadowColor = [UIColor blackColor];
    _textShadowOffset.width = 1;
    _textShadowOffset.height = 1;
    (_backButton)
        .attach([[UIBarButtonItem alloc] initWithTitle:@"Back" style:UIBarButtonItemStylePlain target:self action:@selector(backClicked)]);

    _style = (UIBarStyle)[coder decodeInt32ForKey:@"UIBarStyle"];

    switch (_style) {
        case 1:
            _navGradient = [[UIImage imageNamed:@"/img/navgradient-blackopaque.png"] stretchableImageWithLeftCapWidth:1 topCapHeight:0];
            break;

        case 2:
        case 3:
            _navGradient =
                [[UIImage imageNamed:@"/img/navgradient-blacktranslucent.png"] stretchableImageWithLeftCapWidth:1 topCapHeight:0];
            break;

        default:
            _navGradient = [[UIImage imageNamed:@"/img/navgradient-default.png"] stretchableImageWithLeftCapWidth:1 topCapHeight:0];
            break;
    }

    [super initWithCoder:coder];

    CGRect frame;
    frame = [self bounds];

    (_titleLabel).attach([[UILabel alloc] initWithFrame:frame]);
    [_titleLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
    [_titleLabel setBackgroundColor:nil];
    [_titleLabel setTextAlignment:UITextAlignmentCenter];
    [self addSubview:_titleLabel];
    setBackground(self);

    [self setAutoresizesSubviews:TRUE];
    return self;
}

- (instancetype)initWithFrame:(CGRect)pos {
    (_items).attach([NSMutableArray new]);

    [super initWithFrame:pos];

    [[self layer] setBackgroundColor:(CGColorRef)[UIColor whiteColor]];
    _font = [UIFont boldSystemFontOfSize:18];
    (_backButton)
        .attach([[UIBarButtonItem alloc] initWithTitle:@"Back" style:UIBarButtonItemStylePlain target:self action:@selector(backClicked)]);
    pos.origin.x = 0;
    pos.origin.y = 0;
    (_titleLabel).attach([[UILabel alloc] initWithFrame:pos]);
    [_titleLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
    [_titleLabel setBackgroundColor:nil];
    [_titleLabel setTextAlignment:UITextAlignmentCenter];
    [self addSubview:_titleLabel];

    if (isOSTarget(@"7.0")) {
        _textColor = [UIColor blackColor];
        [self setBarTintColor:[UIColor colorWithWhite:.92f alpha:1.f]];

        CGRect borderRect = pos;
        borderRect.origin.x = 0;
        borderRect.origin.y = pos.size.height - 1.0f;
        borderRect.size.width = pos.size.width;
        borderRect.size.height = 1;
        id borderView = [[UIView alloc] initWithFrame:borderRect];
        [borderView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleTopMargin];
        [borderView setBackgroundColor:[UIColor blackColor]];
        [self insertSubview:borderView atIndex:0];
    } else {
        _textColor = [UIColor blackColor];
        _textShadowColor = [UIColor blackColor];
        _textShadowOffset.width = 1;
        _textShadowOffset.height = 1;

        _navGradient = [[UIImage imageNamed:@"/img/navgradient-default.png"] stretchableImageWithLeftCapWidth:1 topCapHeight:0];
        setBackground(self);
    }

    [self setAutoresizesSubviews:TRUE];

    return self;
}

/**
 @Status Interoperable
*/
- (void)setDelegate:(id<UINavigationBarDelegate>)delegate {
    _delegate = delegate;
}

/**
 @Status Interoperable
*/
- (id<UINavigationBarDelegate>)delegate {
    return _delegate;
}

/**
 @Status Interoperable
*/
- (UINavigationItem*)topItem {
    return [_items lastObject];
}

/**
 @Status Interoperable
*/
- (UINavigationItem*)backItem {
    unsigned count = [_items count];

    if (count > 1) {
        return [_items objectAtIndex:count - 1];
    } else {
        return nil;
    }
}

- (void)pushNavigationItem:(UINavigationItem*)item {
    [_items addObject:item];
    [self setNeedsDisplay];
    [self setNeedsLayout];
    _newItem = item;
}

/**
 @Status Caveat
 @Notes animation parameter not supported
*/
- (void)setItems:(NSArray*)items animated:(BOOL)animated {
    (_items).attach([items mutableCopy]);
    [self setNeedsDisplay];
    [self setNeedsLayout];
    _newItem = [_items lastObject];
}

/**
 @Status Interoperable
*/
- (void)setItems:(NSArray*)items {
    [self setItems:items animated:FALSE];
}

/**
 @Status Interoperable
*/
- (NSArray*)items {
    return _items;
}

/**
 @Status Caveat
 @Notes animation parameter not supported
*/
- (void)pushNavigationItem:(UINavigationItem*)item animated:(BOOL)animated {
    [self pushNavigationItem:item];
}

/**
 @Status Caveat
 @Notes animation parameter not supported
*/
- (void)popNavigationItemAnimated:(BOOL)animated {
    id item = [_items lastObject];
    if (item == nil) {
        EbrDebugLog("No navigation item to pop!\n");
        return;
    }

    [_items removeLastObject];

    [self setNeedsDisplay];
    [self setNeedsLayout];
    _newItem = [_items lastObject];
}

/**
 @Status Interoperable
*/
- (void)setBarStyle:(UIBarStyle)style {
    _style = style;
}

/**
 @Status Interoperable
*/
- (UIBarStyle)barStyle {
    return _style;
}

/**
 @Status Stub
*/
- (void)setTintColor:(UIColor*)color {
    UNIMPLEMENTED();
    _tintColor = color;
    if (((int)[[[UIDevice currentDevice] systemVersion] versionStringCompare:@"7.0"]) >= 0) {
        // If we're in >= ios7, this means that we set the children to this colour
    } else {
        // Otherwise, it means setting the background colour
        [self setBarTintColor:color];
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
 @Status Stub
*/
- (void)setTranslucent:(BOOL)translucent {
    UNIMPLEMENTED();
}

- (void)navigationItemChanged:(UINavigationItem*)item {
    if (_curItem == item && _newItem == nil) {
        _newItem = _curItem;
    }
    [self setNeedsLayout];
}

- (void)backClicked {
    id lastItem = [[[_items lastObject] retain] autorelease];

    [self endEditing:TRUE];

    if ([_delegate navigationBar:self shouldPopItem:lastItem]) {
        [_items removeLastObject];
        if ([_delegate respondsToSelector:@selector(_navigationBar:didPopItem:)]) {
            [_delegate _navigationBar:self didPopItem:lastItem];
        }
        if ([_delegate respondsToSelector:@selector(navigationBar:didPopItem:)]) {
            [_delegate navigationBar:self didPopItem:lastItem];
        }
        _newItem = [_items lastObject];
        [self setNeedsLayout];
    }
}

static void setTitleLabelAttributes(UINavigationBar* self) {
    id textColor = nil, textShadowColor = nil, font = nil;
    CGSize textShadowOffset = { 0, 0 };

    textColor = [self->_titleTextAttributes objectForKey:@"UITextAttributeTextColor"];
    if (textColor == nil) {
        textColor = self->_textColor;
    }

    textShadowColor = [self->_titleTextAttributes objectForKey:@"UITextAttributeTextShadowColor"];
    if (textShadowColor == nil) {
        textShadowColor = self->_textShadowColor;
    }

    font = [self->_titleTextAttributes objectForKey:@"kCTFontAttributeName"];

    id shadowOffset = [self->_titleTextAttributes objectForKey:@"UITextAttributeTextShadowOffset"];
    if (shadowOffset != nil) {
        textShadowOffset = [shadowOffset CGSizeValue];
    } else {
        textShadowOffset = self->_textShadowOffset;
    }

    if (font != nil) {
        [self->_titleLabel setFont:font];
    }
    [self->_titleLabel setTextColor:textColor];
    [self->_titleLabel setShadowColor:textShadowColor];
    [self->_titleLabel setShadowOffset:textShadowOffset];
}

- (void)layoutSubviews {
    if (_newItem != nil) {
        bool backButtonHandler = false;
        if (_curItem != nil) {
            [_curItem setDelegate:nil];
        }

        if (_leftButton != nil) {
            [[_leftButton view] setBackButtonDelegate:nil action:NULL withParam:nil];
            [[_leftButton view] removeFromSuperview];
        }
        if (_rightButton != nil) {
            [[_rightButton view] removeFromSuperview];
        }
        if (_titleView != nil) {
            [_titleView removeFromSuperview];
        }

        _curItem = _newItem;
        [_curItem setDelegate:self];
        _newItem = nil;

        _leftButton = [_curItem leftBarButtonItem];

        _rightButton = [_curItem _rightBarButtonOrControl];
        _titleView = [_curItem titleView];

        if (_leftButton == nil && [_items count] > 1) {
            if (![_curItem hidesBackButton]) {
                UIBarButtonItem* back = [_curItem backBarButtonItem];

                if (back != nil) {
                    _leftButton = _backButton;
                    NSString* text = [back title];
                    UIImage* image = nil;

                    image = [back backButtonBackgroundImage];
                    if (image == nil) {
                        image = [back image];
                    }

                    [_backButton setTitle:text];
                    [_backButton setImage:image];
                } else {
                    _leftButton = _backButton;
                    [_backButton setTitle:@"Back"];
                    [_backButton setImage:nil];
                    backButtonHandler = true;
                }
            }
        }

        if (backButtonHandler && [_leftButton respondsToSelector:@selector(_sendAction:)]) {
            [[_leftButton view] setBackButtonDelegate:_leftButton action:@selector(_sendAction:) withParam:nil];
            [[_leftButton view] setBackButtonReturnsSuccess:FALSE];
            [[_leftButton view] setBackButtonPriority:-100];
        }

        CGRect bounds;

        bounds = [self bounds];
        float leftMargin = 0;
        float rightMargin = 0;

        if (_leftButton != nil) {
            UIView* leftButtonView = [_leftButton view];
            CGRect frame = CGRectMake(5.0f, 5.0f, 65.0f, 35.0f);

            frame.size = [_leftButton idealSize];
            leftMargin = frame.size.width + 10.0f;

            frame.origin.y = bounds.size.height / 2.0f - frame.size.height / 2.0f;
            [leftButtonView setFrame:frame];
            [leftButtonView setAutoresizingMask:UIViewAutoresizingFlexibleRightMargin];
            [self addSubview:leftButtonView];
        } else {
            leftMargin = 5.0f;
        }

        if (_rightButton != nil) {
            UIView* rightButtonView = [_rightButton view];

            CGRect frame = CGRectMake(5.0f, 5.0f, 65.0f, 35.0f);

            frame.size = [_rightButton idealSize];
            frame.origin.x = bounds.size.width - frame.size.width - 5.0f;
            frame.origin.y = bounds.size.height / 2.0f - frame.size.height / 2.0f;
            rightMargin = frame.size.width + 10.0f;

            [rightButtonView setFrame:frame];
            [rightButtonView setAutoresizingMask:UIViewAutoresizingFlexibleLeftMargin];
            [self addSubview:rightButtonView];
        } else {
            rightMargin = 5.0f;
        }

        if (_titleView != nil) {
            CGRect frame;

            CGSize maxSize;

            maxSize.width = bounds.size.width - (leftMargin + rightMargin);
            maxSize.height = 35.0f;

            CGSize outSize = maxSize;
            outSize = [_titleView sizeThatFits:maxSize];

            //  Don't allow the titleview to overlap the left button
            if (bounds.size.width / 2.0f - outSize.width / 2.0f < leftMargin) {
                outSize.width = (bounds.size.width / 2.0f - leftMargin) * 2.0f;
            }

            frame.size.width = outSize.width;
            frame.size.height = outSize.height;
            if (frame.size.height > 35.0f) {
                frame.size.height = 35.0f;
            }
            frame.origin.x = bounds.size.width / 2.0f - outSize.width / 2.0f;
            frame.origin.y = 5.0f;

            [_titleView setFrame:frame];
            [self addSubview:_titleView];
            [self sendSubviewToBack:_titleView];
            [_titleLabel setHidden:TRUE];
        } else {
            float margin = leftMargin > rightMargin ? leftMargin : rightMargin;

            CGRect frame;

            frame.origin.x = margin;
            frame.origin.y = 0;
            frame.size.width = bounds.size.width - margin * 2;
            frame.size.height = bounds.size.height;
            [_titleLabel setFrame:frame];

            [_titleLabel setHidden:FALSE];
        }

        [self bringSubviewToFront:_titleLabel];
        id topItem = [_items lastObject];
        id topItemTitle = nil;

        if (topItem != nil) {
            topItemTitle = [topItem title];
            [_titleLabel setText:topItemTitle];
        }
        setTitleLabelAttributes(self);
    }
}

/**
 @Status Caveat
 @Notes forBarMetrics not supported
*/
- (void)setBackgroundImage:(UIImage*)image forBarMetrics:(UIBarMetrics)metrics {
    _navGradient = image;
    setBackground(self);
}

/**
 @Status Stub
*/
- (void)setTitleTextAttributes:(NSDictionary*)attributes {
    UNIMPLEMENTED();
    (_titleTextAttributes).attach([attributes copy]);
}

/**
 @Status Stub
*/
- (NSDictionary*)titleTextAttributes {
    UNIMPLEMENTED();
    return _titleTextAttributes;
}

- (UIBarButtonItem*)_leftButton {
    return _leftButton;
}

- (void)dealloc {
    if (_curItem != nil) {
        [_curItem setDelegate:nil];
    }

    _items = nil;
    _font = nil;
    _textColor = nil;
    _textShadowColor = nil;
    _navGradient = nil;
    _curItem = nil;
    _newItem = nil;
    _leftButton = nil;
    _rightButton = nil;
    _backButton = nil;
    _titleView = nil;
    _titleLabel = nil;
    _titleTextAttributes = nil;
    _tintColor = nil;
    _barTintColor = nil;

    [super dealloc];
}

- (CGSize)sizeThatFits:(CGSize)curSize {
    CGSize ret = { 320.0f, 44.0f };
    return ret;
}

/**
 @Status Stub
*/
- (void)setTitleVerticalPositionAdjustment:(float)adjustment forBarMetrics:(UIBarMetrics)forBarMetrics {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setShadowImage:(UIImage*)image {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (UIColor*)barTintColor {
    return _barTintColor;
}

/**
 @Status Caveat
 @Notes Navigation bar translucency and system "blur" effect for content behind the navigation bar is not supported.
*/
- (void)setBarTintColor:(UIColor*)color {
    // Alpha is ignored for bar tint.
    _barTintColor = [color colorWithAlphaComponent:1.0];
    CGSize size;

    size.width = 2.0f;
    size.height = 10.0f;
    UIGraphicsBeginImageContextWithOptions(size, 1, 2.0f);
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(ctx, (CGColorRef)(UIColor*)_barTintColor);
    CGRect rct = { 0, 0, 0, 0 };
    rct.size = size;
    CGContextFillRect(ctx, rct);

    id image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();

    _navGradient = [image stretchableImageWithLeftCapWidth:1 topCapHeight:0];
    setBackground(self);
}

/**
 @Status Stub
*/
- (void)setBackIndicatorImage:(UIImage*)image {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setBackIndicatorTransitionMaskImage:(UIImage*)image {
    UNIMPLEMENTED();
}

//
@end
