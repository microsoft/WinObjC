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
#include "UITableViewContentView.h"
#include "UIKit/UILabel.h"
#include "UIViewInternal.h"
#include "_UIGroupEdgeView.h"
#include "UITableViewInternal.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

@implementation UITableViewCell

static UIImageView* getImageView(UITableViewCell* self) {
    if (self->_imageView == nil) {
        CGRect frame;
        frame.origin.x = 0;
        frame.origin.y = 0;
        frame.size.width = 32;
        frame.size.height = 32;

        self->_imageView.attach([[UIImageView alloc] initWithFrame:frame]);
        [self->_imageView setAutoresizingMask:0];
        [self->_contentView addSubview:self->_imageView];
    }

    return self->_imageView;
}

static UILabel* getTextLabel(UITableViewCell* self) {
    if (self->_textLabel == nil) {
        CGRect ourBounds;
        ourBounds = [self bounds];

        switch (self->_style) {
            case 0: {
                CGRect frame;
                frame.origin.x = 32;
                frame.origin.y = 0;
                frame.size.width = ourBounds.size.width - 32;
                if (frame.size.width < 0)
                    frame.size.width = 0;
                frame.size.height = ourBounds.size.height;
                self->_textLabel.attach([[UILabel alloc] initWithFrame:frame]);
                [self->_textLabel setTextColor:[UIColor blackColor]];
                [self->_textLabel setHighlightedTextColor:[UIColor blackColor]];
                [self->_textLabel setNumberOfLines:0];
                [self->_textLabel setBackgroundColor:nil];
                [self->_textLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];

                [self->_contentView addSubview:self->_textLabel];
                break;
            }

            case 1: {
                CGRect frame;

                frame.origin.x = 32;
                frame.origin.y = 0;
                frame.size.width = ourBounds.size.width - 32;
                if (frame.size.width < 0)
                    frame.size.width = 0;
                frame.size.height = ourBounds.size.height - 12.0f;
                self->_textLabel.attach([[UILabel alloc] initWithFrame:frame]);
                [self->_textLabel setTextColor:[UIColor blackColor]];
                [self->_textLabel setHighlightedTextColor:[UIColor blackColor]];
                [self->_textLabel setBackgroundColor:nil];
                [self->_textLabel setNumberOfLines:0];
                [self->_textLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
                [self->_textLabel setFont:[UIFont fontWithName:@"Helvetica Bold" size:[UIFont labelFontSize]]];

                [self->_contentView addSubview:self->_textLabel];
                break;
            }

            case 2: {
                //  Create the image and text labels
                CGRect frame;

                frame.origin.x = 32;
                frame.origin.y = 0;
                frame.size.width = ourBounds.size.width - 32;
                if (frame.size.width < 0)
                    frame.size.width = 0;
                frame.size.height = ourBounds.size.height - 12.0f;
                self->_textLabel.attach([[UILabel alloc] initWithFrame:frame]);
                [self->_textLabel setTextColor:[UIColor blackColor]];
                [self->_textLabel setHighlightedTextColor:[UIColor blackColor]];
                [self->_textLabel setBackgroundColor:nil];
                [self->_textLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
                [self->_textLabel setNumberOfLines:0];
                [self->_textLabel setFont:[UIFont fontWithName:@"Helvetica Bold" size:[UIFont labelFontSize]]];

                [self->_contentView addSubview:self->_textLabel];
                break;
            }

            case 3: {
                //  Create the image and text labels
                CGRect frame;

                frame.origin.x = 32;
                frame.origin.y = 0;
                frame.size.width = ourBounds.size.width - 32;
                if (frame.size.width < 0)
                    frame.size.width = 0;
                frame.size.height = ourBounds.size.height - 12.0f;
                self->_textLabel.attach([[UILabel alloc] initWithFrame:frame]);
                [self->_textLabel setTextColor:[UIColor blackColor]];
                [self->_textLabel setHighlightedTextColor:[UIColor blackColor]];
                [self->_textLabel setBackgroundColor:nil];
                [self->_textLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
                [self->_textLabel setNumberOfLines:1];
                [self->_textLabel setFont:[UIFont fontWithName:@"Helvetica Bold" size:[UIFont labelFontSize]]];

                [self->_contentView addSubview:self->_textLabel];
                break;
            }

            default:
                assert(0);
                break;
        }

        switch (self->_style) {
            case UITableViewCellStyleSubtitle:
                [self->_textLabel setFont:[UIFont fontWithName:@"Helvetica Bold" size:[UIFont labelFontSize] + 1.0f]];
                break;

            case UITableViewCellStyleValue1:
                [self->_textLabel setFont:[UIFont fontWithName:@"Helvetica Bold" size:[UIFont labelFontSize]]];
                break;

            case UITableViewCellStyleValue2:
                [self->_textLabel setFont:[UIFont fontWithName:@"Helvetica Bold" size:[UIFont smallSystemFontSize]]];
                break;
        }
    }

    return self->_textLabel;
}

static id getSecondaryLabel(UITableViewCell* self) {
    if (self->_secondaryLabel == nil) {
        CGRect ourBounds;
        ourBounds = [self bounds];

        switch (self->_style) {
            case 0: {
                break;
            }

            case 1: {
                CGRect frame;

                frame.origin.x = 32;
                frame.origin.y = 0;
                frame.size.width = ourBounds.size.width - 42;
                if (frame.size.width < 0)
                    frame.size.width = 0;
                frame.size.height = ourBounds.size.height;

                self->_secondaryLabel.attach([[UILabel alloc] initWithFrame:frame]);
                [self->_secondaryLabel setTextColor:[UIColor cornflowerBlueColor]];
                [self->_secondaryLabel setHighlightedTextColor:[UIColor blackColor]];
                [self->_secondaryLabel setBackgroundColor:nil];
                [self->_secondaryLabel setTextAlignment:UITextAlignmentRight];
                [self->_secondaryLabel setFont:[UIFont fontWithName:@"Helvetica" size:[UIFont labelFontSize]]];
                [self->_secondaryLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];

                [self->_contentView addSubview:self->_secondaryLabel];
                break;
            }

            case 2: {
                CGRect frame;

                frame.origin.x = 32;
                frame.origin.y = ourBounds.size.height - 12.0f;
                frame.size.width = ourBounds.size.width - 32;
                if (frame.size.width < 0)
                    frame.size.width = 0;
                frame.size.height = 12.0f;
                self->_secondaryLabel.attach([[UILabel alloc] initWithFrame:frame]);
                [self->_secondaryLabel setTextColor:[UIColor grayColor]];
                [self->_secondaryLabel setHighlightedTextColor:[UIColor blackColor]];
                [self->_secondaryLabel setBackgroundColor:nil];
                [self->_secondaryLabel setFont:[UIFont fontWithName:@"Helvetica" size:[UIFont labelFontSize] / 2.0f]];
                [self->_secondaryLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];

                [self->_contentView addSubview:self->_secondaryLabel];
                break;
            }

            case 3: {
                CGRect frame;

                frame.origin.x = 32;
                frame.origin.y = ourBounds.size.height - 12.0f;
                frame.size.width = ourBounds.size.width - 32;
                if (frame.size.width < 0)
                    frame.size.width = 0;
                frame.size.height = 12.0f;
                self->_secondaryLabel.attach([[UILabel alloc] initWithFrame:frame]);
                [self->_secondaryLabel setTextColor:[UIColor grayColor]];
                [self->_secondaryLabel setHighlightedTextColor:[UIColor blackColor]];
                [self->_secondaryLabel setBackgroundColor:nil];
                [self->_secondaryLabel setFont:[UIFont fontWithName:@"Helvetica" size:[UIFont labelFontSize] / 2.0f]];
                [self->_secondaryLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];

                [self->_contentView addSubview:self->_secondaryLabel];
                break;
            }

            default:
                assert(0);
                break;
        }

        switch (self->_style) {
            case UITableViewCellStyleSubtitle:
                [self->_secondaryLabel setFont:[UIFont fontWithName:@"Helvetica" size:[UIFont systemFontSize]]];
                break;

            case UITableViewCellStyleValue1:
                [self->_secondaryLabel setFont:[UIFont fontWithName:@"Helvetica" size:[UIFont systemFontSize] + 1.0f]];
                break;

            case UITableViewCellStyleValue2:
                [self->_secondaryLabel setFont:[UIFont fontWithName:@"Helvetica" size:[UIFont labelFontSize]]];
                break;
        }
    }

    return self->_secondaryLabel;
}

static void initInternal(UITableViewCell* self) {
    CGRect ourBounds = { 0 };

    self->_indentationWidth = 10.0f;
    self->_selectionStyle = UITableViewCellSelectionStyleBlue;

    ourBounds = [self bounds];

    self->_contentView.attach([[UITableViewContentView alloc] initWithFrame:ourBounds]);
    [self->_contentView setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
    [self addSubview:self->_contentView];
    [self setContentMode:UIViewContentModeRedraw];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)pos reuseIdentifier:(NSString*)identifier {
    return [self initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
}

/**
 @Status Stub
*/
- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString*)identifier {
    UNIMPLEMENTED();
    _style = style;

    CGRect pos = { 0.0f, 0.0f, 320.0f, 44.0f };

    _reuseIdentifier.attach([identifier copy]);
    [super initWithFrame:pos];
    [self setOpaque:FALSE];
    initInternal(self);
    _cellBackgroundColor = [UIColor clearColor];
    _swipeGestureRecognizer.attach([[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(_didSwipe:)]);
    [_swipeGestureRecognizer setDelegate:self];
    [self addGestureRecognizer:_swipeGestureRecognizer];

    return self;
}

- (id)initWithCoder:(NSCoder*)coder {
    id ret = [super initWithCoder:coder];

    if ([coder containsValueForKey:@"UISelectionStyle"]) {
        _selectionStyle = (UITableViewCellSelectionStyle)[coder decodeIntForKey:@"UISelectionStyle"];
    } else {
        _selectionStyle = UITableViewCellSelectionStyleBlue;
    }

    _imageView = [coder decodeObjectForKey:@"UIImageView"];
    _secondaryLabel = [coder decodeObjectForKey:@"UIDetailTextLabel"];
    _textLabel = [coder decodeObjectForKey:@"UITextLabel"];
    _contentView = [coder decodeObjectForKey:@"UIContentView"];
    [_contentView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
    [_contentView setAutoresizesSubviews:TRUE];
    _reuseIdentifier = [coder decodeObjectForKey:@"UIReuseIdentifier"];
    if (_cellBackgroundColor == nil) {
        _cellBackgroundColor = [UIColor clearColor];
    }

    _swipeGestureRecognizer = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(_didSwipe:)];
    [_swipeGestureRecognizer setDelegate:self];
    [self addGestureRecognizer:_swipeGestureRecognizer];
    return ret;
}

- (instancetype)initWithFrame:(CGRect)pos {
    return [self initWithFrame:pos reuseIdentifier:nil];
}

- (void)_doneSlideoutButton {
    [_removeButton removeFromSuperview];
    _removeButton = nil;
}

- (void)_didSwipe:(id)foo {
    // We can only do picking if our superview is actually a table view. This is reused for picker views as well...
    id superview = [self superview];
    if (![superview isKindOfClass:[UITableView class]])
        return;

    // Add a button to remove this tableview cell:
    if (!_removeButton && [superview _canEditCell:self]) {
        CGRect parentRect = [self frame];

        // Create the technology slightly offscreen so it can be scrolled in:
        CGRect rect = { parentRect.size.width, 13, 72, 20 };
        UIImage* buttonBackground = [[UIImage imageNamed:@"/img/redbutton.png"] stretchableImageWithLeftCapWidth:9 topCapHeight:0];

        _removeButton.attach([[UIButton alloc] initWithFrame:rect]);
        [_removeButton setTitle:@"Delete" forState:0];
        [_removeButton setBackgroundImage:buttonBackground forState:0];
        [_removeButton addTarget:self action:@selector(_removeButtonCallback:) forControlEvents:UIControlEventTouchUpInside];

        // Fade the removal button in
        [self addSubview:_removeButton];

        [UIView beginAnimations:@"TableCellRemoveButton" context:nil];
        [UIView setAnimationDuration:0.25f];
        rect.origin.x -= 75;
        [_removeButton setFrame:rect];
        [UIView commitAnimations];
    } else {
        CGRect rect;
        rect = [_removeButton frame];

        [UIView beginAnimations:@"TableCellRemoveButton" context:nil];
        [UIView setAnimationDelegate:self];
        [UIView setAnimationDidStopSelector:@selector(_doneSlideoutButton)];
        [UIView setAnimationDuration:0.25f];
        rect.origin.x += 75;
        [_removeButton setFrame:rect];
        [UIView commitAnimations];
    }
    [self setNeedsLayout];
}

- (void)_removeButtonCallback:(id)button {
    _removeButton = nil;
    [button removeFromSuperview];
    [[self superview] _forwardCellRemoval:self];
}

/**
 @Status Interoperable
*/
- (UIView*)contentView {
    return _contentView;
}

/**
 @Status Interoperable
*/
- (void)setImage:(UIImage*)image {
    [getImageView(self) setImage:image];
}

/**
 @Status Interoperable
*/
- (UIImage*)image {
    return [getImageView(self) image];
}

/**
 @Status Interoperable
*/
- (NSString*)reuseIdentifier {
    if (_reuseIdentifier == nil) {
        return [NSString stringWithCString:object_getClassName(self)];
    }
    return _reuseIdentifier;
}

- (void)_setReuseIdentifier:(NSString*)identifier {
    _reuseIdentifier = [identifier copy];
}

/**
 @Status Interoperable
*/
- (void)setFont:(UIFont*)font {
    [getTextLabel(self) setFont:font];
}

/**
 @Status Interoperable
*/
- (UIFont*)font {
    return [getTextLabel(self) font];
}

/**
 @Status Interoperable
*/
- (void)setText:(NSString*)text {
    [getTextLabel(self) setText:text];
}

/**
 @Status Interoperable
*/
- (NSString*)text {
    return [getTextLabel(self) text];
}

/**
 @Status Interoperable
*/
- (void)setTextColor:(UIColor*)textcolor {
    [getTextLabel(self) setTextColor:textcolor];
}

/**
 @Status Interoperable
*/
- (UIColor*)textColor {
    return [getTextLabel(self) textColor];
}

/**
 @Status Interoperable
*/
- (void)setSelected:(BOOL)isSelected {
    [self setSelected:isSelected animated:NO];
}

- (void)updateBackgroundView:(BOOL)highlight {
    if (_isEditing)
        highlight = FALSE;

    //[_selectedBackgroundView setAlpha:highlight ?1.0f :0.0f];
    BOOL wasHighlighted = _currentlyHighlighted;
    _currentlyHighlighted = highlight;

    if (_currentlyHighlighted && !wasHighlighted) {
        _cellOldBackgroundColor = _cellBackgroundColor;
        switch (_selectionStyle) {
            case UITableViewCellSelectionStyleBlue:
                [self setBackgroundColor:[UIColor windowsTableViewCellSelectionBackgroundColor]];
                break;

            case UITableViewCellSelectionStyleGray:
                [self setBackgroundColor:[UIColor grayColor]];
                break;
        }
        if (_selectionStyle != UITableViewCellSelectionStyleNone)
            [self setHighlighted:highlight forViews:[_contentView subviews]];
        updateBackgroundView(self);
    } else {
        if (!_currentlyHighlighted && wasHighlighted) {
            switch (_selectionStyle) {
                case UITableViewCellSelectionStyleBlue:
                case UITableViewCellSelectionStyleGray:
                    [self setBackgroundColor:_cellOldBackgroundColor];
                    break;
            }
            [self setHighlighted:highlight forViews:[_contentView subviews]];
            updateBackgroundView(self);
        }
    }
    [self setNeedsLayout];
}

- (void)setHighlighted:(BOOL)highlighted forViews:(NSArray*)subviews {
    for (UIView* view in subviews) {
        // Ignore the events if view wants to
        if (![view isUserInteractionEnabled] && [view respondsToSelector:@selector(setHighlighted:)] &&
            ![view isKindOfClass:[UIControl class]]) {
            [view setHighlighted:highlighted];

            [self setHighlighted:highlighted forViews:[view subviews]];
        }
    }
}

/**
 @Status Interoperable
*/
- (void)setHighlighted:(BOOL)highlighted animated:(BOOL)animated {
    _isHighlighted = highlighted;
    [self updateBackgroundView:highlighted];
}

/**
 @Status Interoperable
*/
- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    _isSelected = selected;
    // self.accessibilityTraits = selected ? UIAccessibilityTraitSelected : UIAccessibilityTraitNone;
    [self updateBackgroundView:selected];
}

/**
 @Status Interoperable
*/
- (void)setHighlighted:(BOOL)isHighlighted {
    [self setHighlighted:isHighlighted animated:NO];
}

/**
 @Status Interoperable
*/
- (BOOL)isHighlighted {
    return _isHighlighted;
}

/**
 @Status Interoperable
*/
- (BOOL)isSelected {
    return _isSelected;
}

/**
 @Status Interoperable
*/
- (BOOL)isEditing {
    return _isEditing;
}

- (void)_setEditingMode:(BOOL)editingMode animated:(BOOL)animated {
    BOOL wasEditing = _isEditing;
    _isEditing = editingMode;

    if (wasEditing != editingMode) {
        [self updateBackgroundView:_isSelected || _isHighlighted];
        [self setNeedsLayout];

        if (animated) {
            [UIView beginAnimations:@"EditingMode" context:nil];
            [UIView setAnimationDuration:0.3f];
            [self layoutIfNeeded];
            [UIView commitAnimations];
        }
    }
}

- (UITableViewCellEditingStyle)editingStyle {
    return UITableViewCellEditingStyleNone;
}

/**
 @Status Stub
*/
- (BOOL)showingDeleteConfirmation {
    UNIMPLEMENTED();
    return FALSE;
}

/**
 @Status Interoperable
*/
- (UILabel*)detailTextLabel {
    return getSecondaryLabel(self);
}

- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    if ([priv->superview respondsToSelector:@selector(_cellSelectedDown:)])
        [priv->superview _cellSelectedDown:self];
}

- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
}

- (void)touchesCancelled:(NSSet*)touches withEvent:(UIEvent*)event {
    if ([priv->superview respondsToSelector:@selector(_cellSelectedCancelled:)])
        [priv->superview _cellSelectedCancelled:self];
}

- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    if ([priv->superview respondsToSelector:@selector(_cellSelectedUp:)])
        [priv->superview _cellSelectedUp:self];
}

- (void)__accessoryTapped {
    if ([priv->superview respondsToSelector:@selector(_cellAccessoryTapped:)])
        [priv->superview _cellAccessoryTapped:self];
}

static float getMarginWidth(UITableViewCell* self) {
    CGRect ourFrame;
    ourFrame = [self bounds];
    float tableViewWidth = ourFrame.size.width;

    float marginWidth = 0.0f;
    if (tableViewWidth > 20) {
        if (tableViewWidth < 400 || !GetCACompositor()->isTablet()) {
            marginWidth = 10.0f;
        } else {
            marginWidth = MAX(31.0f, MIN(45.0f, tableViewWidth * 0.06f));
        }
    } else {
        marginWidth = tableViewWidth - 10.0f;
    }

    return marginWidth;
}

static void updateBackgroundView(UITableViewCell* self, bool forceRefresh = false) {
    CGRect ourFrame;
    ourFrame = [self bounds];

    if (self->_groupEdgeStyle != 0) {
        ourFrame.origin.x += getMarginWidth(self);
        ourFrame.size.width -= getMarginWidth(self) * 2.0f;
    }

    if (!self->_isSelected || self->_selectedbackgroundView == nil || self->_selectionStyle == UITableViewCellSelectionStyleNone) {
        if (self->_selectedbackgroundView) {
            if ([self->_selectedbackgroundView superview] == self) {
                [self->_selectedbackgroundView removeFromSuperview];
            }
        }
        if (self->_backgroundView) {
            if ([self->_backgroundView superview] != self || forceRefresh) {
                [self->_backgroundView setFrame:ourFrame];
                [self insertSubview:self->_backgroundView atIndex:0];
                [self sendSubviewToBack:self->_backgroundView];
                [self->_backgroundView setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
            }
        }
    } else {
        if (self->_backgroundView != nil) {
            if ([self->_backgroundView superview] == self) {
                [self->_backgroundView removeFromSuperview];
            }
        }
        if (self->_selectedbackgroundView) {
            if ([self->_selectedbackgroundView superview] != self || forceRefresh) {
                [self->_selectedbackgroundView setFrame:ourFrame];
                [self insertSubview:self->_selectedbackgroundView atIndex:0];
                [self sendSubviewToBack:self->_selectedbackgroundView];
                [self->_selectedbackgroundView setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
            }
        }
    }

    setInternalAccessoryColor(self);
}

/**
 @Status Interoperable
*/
- (void)setBackgroundView:(UIView*)view {
    if (_backgroundView) {
        [_backgroundView removeFromSuperview];
    }

    _backgroundView = view;
    updateBackgroundView(self);
}

/**
 @Status Interoperable
*/
- (UIView*)backgroundView {
    return _backgroundView;
}

/**
 @Status Interoperable
*/
- (void)setSelectedBackgroundView:(UIView*)view {
    if (_selectedbackgroundView) {
        [_selectedbackgroundView removeFromSuperview];
    }

    _selectedbackgroundView = view;
    updateBackgroundView(self);
}

/**
 @Status Interoperable
*/
- (UIView*)selectedBackgroundView {
    return _selectedbackgroundView;
}

/**
 @Status Interoperable
*/
- (void)setTextAlignment:(UITextAlignment)alignment {
    [getTextLabel(self) setTextAlignment:alignment];
}

/**
 @Status Interoperable
*/
- (UITextAlignment)textAlignment {
    return (UITextAlignment)[getTextLabel(self) textAlignment];
}

/**
 @Status Interoperable
*/
- (void)setSelectionStyle:(UITableViewCellSelectionStyle)style {
    _selectionStyle = style;
}

/**
 @Status Interoperable
*/
- (UITableViewCellSelectionStyle)selectionStyle {
    return _selectionStyle;
}

/**
 @Status Interoperable
*/
- (void)setAccessoryType:(UITableViewCellAccessoryType)type {
    _accessoryType = type;
    [self setNeedsLayout];
}

/**
 @Status Stub
*/
- (void)setEditingAccessoryType:(UITableViewCellAccessoryType)type {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (unsigned)accessoryType {
    return _accessoryType;
}

static void setInternalAccessoryColor(UITableViewCell* self) {
    if (self->_internalAccessoryView != nil) {
        ColorQuad contentColor;
        contentColor.r = 0.13f;
        contentColor.g = 0.24f;
        contentColor.b = 0.44f;
        contentColor.a = 1.0f;

        if (self->_isSelected || self->_isHighlighted) {
            switch (self->_selectionStyle) {
                case UITableViewCellSelectionStyleBlue:
                case UITableViewCellSelectionStyleGray:
                    contentColor.r = 1.0f;
                    contentColor.g = 1.0f;
                    contentColor.b = 1.0f;
                    break;
            }
        }

        [[self->_internalAccessoryView layer]
            _setContentColor:[UIColor colorWithRed:contentColor.r green:contentColor.g blue:contentColor.b alpha:contentColor.a]];
    }
}

static id buildInternalAccessory(UITableViewCell* self, int type) {
    if (type == UITableViewCellAccessoryDetailDisclosureButton) {
        if (self->_internalAccessoryButton == nil) {
            if (self->_internalAccessoryButton == nil) {
                self->_internalAccessoryButton = [UIButton buttonWithType:UIButtonTypeDetailDisclosure];
                [self->_internalAccessoryButton addTarget:self
                                                   action:@selector(__accessoryTapped)
                                         forControlEvents:UIControlEventTouchUpInside];
            }

            CGRect bounds;
            bounds = [self->_internalAccessoryButton bounds];
            bounds.size.width = 25.0f;
            bounds.size.height = 25.0f;
            [self->_internalAccessoryButton setBounds:bounds];
        }

        return self->_internalAccessoryButton;
    }

    if (self->_internalAccessoryView == nil || self->_internalAccessoryType != type) {
        id image = nil;

        switch (type) {
            case UITableViewCellAccessoryCheckmark:
                image = [UIImage imageNamed:@"/img/checkmark@2x.png"];
                break;

            case UITableViewCellAccessoryDisclosureIndicator:
            case UITableViewCellAccessoryDetailButton:
                image = [UIImage imageNamed:@"/img/disclosure@2x.png"];
                break;
        }

        if (image != nil) {
            if (self->_internalAccessoryView == nil) {
                self->_internalAccessoryView.attach([UIImageView new]);
                setInternalAccessoryColor(self);
            }

            [self->_internalAccessoryView setImage:image];

            CGRect bounds;
            bounds = [self->_internalAccessoryView bounds];
            bounds.size = [image size];
            [self->_internalAccessoryView setBounds:bounds];
        }

        self->_internalAccessoryType = type;
    }

    return self->_internalAccessoryView;
}

static id getCurrentAccessoryView(UITableViewCell* self) {
    UIView* ret = nil;

    if (self->_accessoryView) {
        ret = self->_accessoryView;
    } else {
        switch (self->_accessoryType) {
            case UITableViewCellAccessoryDisclosureIndicator:
            case UITableViewCellAccessoryDetailDisclosureButton:
            case UITableViewCellAccessoryCheckmark:
            case UITableViewCellAccessoryDetailButton:
                ret = buildInternalAccessory(self, self->_accessoryType);
                break;
        }
    }

    /*
    assert(!_accessoryType || !_removeButton);
    if ( _removeButton ) {
    ret = _removeButton;
    }
    */

    if (ret != self->_curAccessoryView) {
        [self->_curAccessoryView removeFromSuperview];

        self->_curAccessoryView = ret;

        [self->_contentView setNeedsLayout];

        if ([self->_curAccessoryView superview] != self) {
            [self addSubview:self->_curAccessoryView];
            [self->_curAccessoryView setAutoresizingMask:UIViewAutoresizingFlexibleLeftMargin];
            [self->_curAccessoryView bringSubviewToFront:self->_accessoryView];
            [self setNeedsLayout];
        }
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (void)setAccessoryView:(UIView*)view {
    _accessoryView = view;
    getCurrentAccessoryView(self);
}

/**
 @Status Stub
*/
- (void)setEditingAccessoryView:(UIView*)view {
    UNIMPLEMENTED();
    _editingAccessoryView = view;
}

/**
 @Status Interoperable
*/
- (UIView*)accessoryView {
    return _accessoryView;
}

/**
 @Status Stub
*/
- (UIView*)editingAccessoryView {
    UNIMPLEMENTED();
    return _editingAccessoryView;
}

/**
 @Status Interoperable
*/
- (UIImageView*)imageView {
    return getImageView(self);
}

/**
 @Status Stub
*/
- (void)setIndentationWidth:(float)width {
    UNIMPLEMENTED();
    _indentationWidth = width;
}

/**
 @Status Interoperable
*/
- (float)indentationWidth {
    return _indentationWidth;
}

- (void)setIndexPath:(NSIndexPath*)path {
    _indexPath = path;
}

- (void)setSelectedTextColor:(UIColor*)color {
    EbrDebugLog("setSelectedTextColor not supported\n");
}

/**
 @Status Interoperable
*/
- (UILabel*)textLabel {
    return getTextLabel(self);
}

- (void)setTextLabel:(UILabel*)label {
    if (_textLabel != nil) {
        if (_textLabel != label) {
            [_contentView insertSubview:label aboveSubview:_textLabel];
            [_textLabel removeFromSuperview];
        }
    } else {
        [_contentView addSubview:label];
    }
    _textLabel = label;
    [self setNeedsLayout];
}

- (NSIndexPath*)indexPath {
    return _indexPath;
}

- (void)setBackgroundColor:(UIColor*)color {
    _cellBackgroundColor = color;
    _cellBackgroundColorSet = TRUE;
    if (_groupEdgeStyle != 0 && _groupEdgeStyle != 0x800)
        [_groupEdgeView _setStyleColor:(id)_cellBackgroundColor];
    else
        [super setBackgroundColor:color];
}

- (UIColor*)backgroundColor {
    return _cellBackgroundColor;
}

- (void)dealloc {
    _textLabel = nil;
    _secondaryLabel = nil;
    _imageView = nil;
    _backgroundView = nil;
    _selectedbackgroundView = nil;
    _indexPath = nil;
    _deferredIndexPath = nil;
    _accessoryView = nil;
    _curAccessoryView = nil;
    _internalAccessoryView = nil;
    _internalAccessoryButton = nil;
    _reuseIdentifier = nil;
    _contentView = nil;
    _borderView = nil;
    _groupEdgeView = nil;
    _cellBackgroundColor = nil;
    _selectionSegueTemplate = nil;
    _removeButton = nil;
    _swipeGestureRecognizer = nil;
    _editSelectedView = nil;

    [super dealloc];
}

- (void)addBottomBorder:(UITableView*)parentTable {
    if (_borderView == nil) {
        float tableBackground[4] = { 0 };

        [[parentTable backgroundColor] getColors:tableBackground];
        UIColor* backgroundColor = nil;

        if ((tableBackground[3] == 0.0f) ||
            (tableBackground[0] == 1.0f && tableBackground[1] == 1.0f && tableBackground[2] == 1.0f && tableBackground[3] == 1.0f)) {
            backgroundColor = [UIColor grayColor];
        } else {
            backgroundColor = [UIColor whiteColor];
        }

        CGRect ourBounds = { 0 };

        ourBounds = [self bounds];

        CGRect borderRect = ourBounds;
        borderRect.origin.x = 0;
        borderRect.origin.y = ourBounds.size.height - 1.0f;
        borderRect.size.width = ourBounds.size.width;
        borderRect.size.height = 1;
        _borderView.attach([[UIView alloc] initWithFrame:borderRect]);
        [_borderView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleTopMargin];
        [_borderView setBackgroundColor:[backgroundColor CGColor]];
        [self insertSubview:_borderView atIndex:0];
    }
}

static void setupGroupView(UITableViewCell* self) {
    if (self->_groupEdgeStyle != 0 && self->_groupEdgeStyle != 0x800) {
        if (self->_groupEdgeView == nil) {
            CGRect ourBounds = { 0 };
            ourBounds = [self bounds];

            ourBounds.origin.x += getMarginWidth(self);
            ourBounds.size.width -= getMarginWidth(self) * 2.0f;

            self->_groupEdgeView.attach([[_UIGroupEdgeView alloc] initWithFrame:ourBounds]);
            [self->_groupEdgeView setOpaque:FALSE];
            [self->_groupEdgeView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
            [self addSubview:self->_groupEdgeView];
            [self sendSubviewToBack:self->_groupEdgeView];
            if (self->_contentView != nil) {
                [[self->_contentView layer] setCornerRadius:5.0f];
            }
        }

        [self->_groupEdgeView _setStyleColor:(id)self->_cellBackgroundColor];
        [self->_groupEdgeView _setStyle:self->_groupEdgeStyle];
    }
}

- (void)layoutSubviews {
    CGRect ourBounds = { 0 };

    ourBounds = [self bounds];

    if (_groupEdgeStyle != 0) {
        ourBounds.origin.x += getMarginWidth(self);
        ourBounds.size.width -= getMarginWidth(self) * 2.0f;

        if (_groupEdgeStyle != 0x800) {
            if (_groupEdgeView == nil) {
                _groupEdgeView.attach([[_UIGroupEdgeView alloc] initWithFrame:ourBounds]);
                [_groupEdgeView setOpaque:FALSE];
                [_groupEdgeView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
                [self addSubview:_groupEdgeView];
            } else {
                [_groupEdgeView setFrame:ourBounds];
            }
            [self sendSubviewToBack:_groupEdgeView];
            [_groupEdgeView _setStyleColor:(id)_cellBackgroundColor];
            [_groupEdgeView _setStyle:_groupEdgeStyle];
            if (_contentView != nil) {
                [[_contentView layer] setCornerRadius:5.0f];
            }
            [super setBackgroundColor:nil];
        } else {
            [super setBackgroundColor:(id)_cellBackgroundColor];
        }
    } else {
        [super setBackgroundColor:(id)_cellBackgroundColor];
        if (_groupEdgeView != nil) {
            [_groupEdgeView removeFromSuperview];
            _groupEdgeView = nil;
        }
    }

    if (_borderView != nil) {
        CGRect borderRect = ourBounds;
        borderRect.origin.x = 0;
        borderRect.origin.y = ourBounds.size.height - 1.0f;
        borderRect.size.width = ourBounds.size.width;
        borderRect.size.height = 1;
        [_borderView setFrame:borderRect];
    }

    id accessoryView = getCurrentAccessoryView(self);
    if (accessoryView) {
        CGRect accessoryRect = { 0 };

        if ([accessoryView isKindOfClass:[UITextField class]]) {
            CGRect bounds = { 0 };
            bounds = [accessoryView bounds];
            accessoryRect.size = bounds.size;
        } else {
            accessoryRect.size = [accessoryView sizeThatFits:ourBounds.size];
        }

        accessoryRect.origin.x = ourBounds.origin.x + ourBounds.size.width - accessoryRect.size.width - 10.0f;
        accessoryRect.origin.y = ourBounds.origin.y + ourBounds.size.height / 2.0f - accessoryRect.size.height / 2.0f;
        [accessoryView setFrame:accessoryRect];
        ourBounds.size.width -= accessoryRect.size.width + 15.0f;
    }

    if (_isEditing) {
        ourBounds.origin.x += 25.0f;
        ourBounds.size.width -= 25.0f;

        static id selectedImage = nil, unselectedImage = nil;
        if (selectedImage == nil) {
            selectedImage = [[UIImage imageNamed:@"/img/tablecell-edit-selected@2x.png"] retain];
        }
        if (unselectedImage == nil) {
            unselectedImage = [[UIImage imageNamed:@"/img/tablecell-edit-unselected@2x.png"] retain];
        }

        UIImage* useImage = _isSelected ? selectedImage : unselectedImage;
        CGSize imageSize = { 0, 0 };
        imageSize = [useImage size];
        CGRect imgFrame;

        imgFrame.origin.x = ourBounds.origin.x - 15.0f;
        imgFrame.origin.y = ourBounds.origin.y + ourBounds.size.height / 2.0f - imageSize.height / 2.0f;
        imgFrame.size = imageSize;

        if (_editSelectedView == nil) {
            _editSelectedView.attach([[UIImageView alloc] initWithFrame:imgFrame]);
            [_editSelectedView setImage:useImage];
            [self addSubview:_editSelectedView];
        } else {
            [_editSelectedView setImage:useImage];
        }

        if (!_editSelectedViewVisible) {
            [_editSelectedView setAlpha:0.0f];
            [_editSelectedView setAlpha:1.0f];

            CGRect startFrame = imgFrame;
            startFrame.origin.x -= 25.0f;
            CGRect endFrame = imgFrame;

            [_editSelectedView setFrame:startFrame];
            [_editSelectedView setFrame:endFrame];
            _editSelectedViewVisible = TRUE;
        }
    } else {
        if (_editSelectedViewVisible) {
            [_editSelectedView setAlpha:1.0f];
            [_editSelectedView setAlpha:0.0f];

            CGRect endFrame = [_editSelectedView frame];
            endFrame.origin.x -= 25.0f;

            [_editSelectedView setFrame:endFrame];
            _editSelectedViewVisible = FALSE;
        }
    }

    if (_contentView != nil) {
        [_contentView setFrame:ourBounds];
        ourBounds.origin.x = 0.0f;
        ourBounds.origin.y = 0.0f;
    }

    switch (_style) {
        case 1:
        case 0: {
            //  Create the image and text labels
            CGRect frame;
            frame.origin.x = ourBounds.origin.x + 5;
            frame.origin.y = 0;
            frame.size.width = 32;
            frame.size.height = 32;

            UIImage* imageInView = [_imageView image];

            if (imageInView != nil) {
                frame.size = [imageInView size];

                //  Aspect-scale the image to fit
                if (frame.size.height > ourBounds.size.height) {
                    frame.size.width = frame.size.width * (ourBounds.size.height / frame.size.height);
                    frame.size.height = ourBounds.size.height;
                }
            } else {
                frame.size.width = 0.0f;
                frame.size.height = 0.0f;
                frame.origin.x = ourBounds.origin.x;
            }

            //  Center it vertically
            frame.origin.y = ourBounds.size.height / 2.0f - frame.size.height / 2.0f;

            [_imageView setFrame:frame];

            if (_textLabel != nil) {
                frame.origin.x += frame.size.width + 10.0f;
                frame.origin.y = 0;
                frame.size.width = ourBounds.size.width - frame.origin.x;
                if ([_textLabel textAlignment] == UITextAlignmentRight) {
                    frame.size.width -= 10.0f;
                }

                if (frame.size.width < 0)
                    frame.size.width = 0;
                frame.size.height = ourBounds.size.height;
                [_textLabel setFrame:frame];

                if ([_textLabel superview] != _contentView) {
                    [_contentView addSubview:_textLabel];
                }
            }
        } break;

        case 2:
        case 3: {
            CGRect frame;
            frame.origin.x = ourBounds.origin.x + 5;
            frame.origin.y = 0;
            frame.size.width = 32;
            frame.size.height = 32;

            id imageInView = [_imageView image];

            if (imageInView != nil) {
                frame.size = [imageInView size];

                //  Aspect-scale the image to fit
                if (frame.size.height > ourBounds.size.height) {
                    frame.size.width = frame.size.width * (ourBounds.size.height / frame.size.height);
                    frame.size.height = ourBounds.size.height;
                }
            } else {
                frame.size.width = 0.0f;
                frame.size.height = 0.0f;
                frame.origin.x = ourBounds.origin.x;
            }

            //  Center it vertically
            frame.origin.y = ourBounds.size.height / 2.0f - frame.size.height / 2.0f;

            [_imageView setFrame:frame];

            CGSize fitSize;
            fitSize.width = ourBounds.size.width - frame.size.width - frame.origin.x - 10.0f;
            fitSize.height = ourBounds.size.height;

            CGSize label1Size = { 0, 0 }, label2Size = { 0, 0 };
            label1Size = [_textLabel sizeThatFits:fitSize];
            label2Size = [_secondaryLabel sizeThatFits:fitSize];

            float totalHeight = label1Size.height + label2Size.height;

            frame.origin.x += frame.size.width + 10.0f;
            frame.origin.y = ourBounds.size.height / 2.0f - totalHeight / 2.0f;
            frame.size.width = fitSize.width;
            if (frame.size.width < 0)
                frame.size.width = 0;
            frame.size.height = label1Size.height;
            [_textLabel setFrame:frame];

            if (_textLabel != nil && [_textLabel superview] != _contentView) {
                [_contentView addSubview:_textLabel];
            }

            frame.origin.y = ourBounds.size.height / 2.0f - totalHeight / 2.0f + label1Size.height;
            frame.size.height = label2Size.height;
            [_secondaryLabel setFrame:frame];

            if (_secondaryLabel != nil && [_secondaryLabel superview] != _contentView) {
                [_contentView addSubview:_secondaryLabel];
            }
        } break;

        default:
            assert(0);
            break;
    }

    if (_style == 1) {
        //  Adjust secondary label so that it can't overlap the primary
        CGSize measureSize = { 0, 0 };
        CGRect textLabelSize = { 0, 0 };

        textLabelSize = [_textLabel frame];
        measureSize = [_textLabel sizeThatFits:textLabelSize.size];

        textLabelSize.origin.x += measureSize.width + 5.0f;
        textLabelSize.size.width = ourBounds.size.width - textLabelSize.origin.x - 10.0f;
        if (textLabelSize.size.width < 0)
            textLabelSize.size.width = 0;
        [_secondaryLabel setFrame:textLabelSize];
    }

    [super layoutSubviews];
}

- (void)setHidesAccessoryWhenEditing:(BOOL)hide {
}

- (void)setShouldIndentWhileEditing:(BOOL)shouldIndent {
}

/**
 @Status Stub
*/
- (void)setShowsReorderControl:(BOOL)show {
    UNIMPLEMENTED();
    _showsReorderControl = show;
}

/**
 @Status Stub
*/
- (BOOL)showsReorderControl {
    UNIMPLEMENTED();
    return _showsReorderControl;
}

- (void)setSelectionSegueTemplate:(UIStoryboardSegueTemplate*)val {
    _selectionSegueTemplate = val;
}

- (UIStoryboardSegueTemplate*)selectionSegueTemplate {
    return _selectionSegueTemplate;
}

/**
 @Status Stub
*/
- (void)setIndentationLevel:(int)level {
    UNIMPLEMENTED();
    _indentationLevel = level;
}

/**
 @Status Interoperable
*/
- (int)indentationLevel {
    return _indentationLevel;
}

- (void)__didLayout {
    if (_deferredIndexPath != nil) {
        if (_indexPath == nil)
            _indexPath = _deferredIndexPath;
        _deferredIndexPath = nil;
    }
    setupGroupView(self);
}

- (void)_setGroupEdgeStyle:(int)groupEdgeStyle {
    if (groupEdgeStyle != 0) {
        _groupEdgeStyle = groupEdgeStyle;
        if (_groupEdgeStyle != 0x800) {
            if (!_cellBackgroundColorSet) {
                _cellBackgroundColor = [UIColor whiteColor];
                _cellBackgroundColorSet = TRUE;
            }
            updateBackgroundView(self, true);
        }
    }
}

- (void)performSelectionSegue {
    if (_selectionSegueTemplate != nil) {
        [_selectionSegueTemplate perform:self];
    }
}

- (void)setTintColor:(UIColor*)color {
}

static void removeAllAnimationsFromLayers(CALayer* layer) {
    [layer removeAllAnimations];
    for (CALayer* sublayer in [layer sublayers]) {
        removeAllAnimationsFromLayers(sublayer);
    }
}

/**
 @Status Interoperable
*/
- (void)prepareForReuse {
    removeAllAnimationsFromLayers([self layer]);
    _groupEdgeStyle = 0;
    _deferredIndexPath = nil;
    _indexPath = nil;

    if (_borderView != nil) {
        [_borderView removeFromSuperview];
        _borderView = nil;
    }
    if (_accessoryView != nil) {
        [_accessoryView removeFromSuperview];
        _accessoryView = nil;
    }
    if (_curAccessoryView != nil) {
        [_curAccessoryView removeFromSuperview];
        _curAccessoryView = nil;
    }

    // We can't keep the button between reuses. We may want to cache this information sometime but
    // this at least partially fixes the problem.
    if (_removeButton) {
        [_removeButton removeFromSuperview];
        _removeButton = nil;
    }

    if (_editSelectedView) {
        [_editSelectedView removeFromSuperview];
        _editSelectedView = nil;
    }
    _editSelectedViewVisible = FALSE;

    /*
    if ( _backgroundView != nil ) {
    [_backgroundView removeFromSuperview];
    _backgroundView = nil;
    }
    if ( _selectedbackgroundView != nil ) {
    [_selectedbackgroundView removeFromSuperview];
    _selectedbackgroundView = nil;
    }
    */
    [self setNeedsLayout];
}

@end
