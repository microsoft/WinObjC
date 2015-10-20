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

struct buttonState {
    idretaintype(UIImage) image, backgroundImage;
    idretaintype(UIColor) textColor, titleShadowColor;
    idretaintype(NSString) title;
};

@interface UIRoundedRectButton : UIButton {
}
@end

@implementation UIRoundedRectButton
@end

@implementation UIButton {
    ColorQuad _backgroundColor;
    idretaintype(UIColor) _defaultColor;
    buttonState* _states;
    UIEdgeInsets titleInsets, imageInsets, contentInsets;
    idretaintype(UIFont) _font;
    idretaintype(UILabel) _label;
    idretaintype(UIImageView) _imageView;
    CGSize _shadowOffset;
    bool _showsTouchWhenHighlighted;
    bool _adjustsImageWhenHighlighted;
    bool _isPressed;
    bool _isDisabled;
    bool _didSetBackgroundImage;
    UIButtonType _type;
}
static UIImage* getBackgroundImage(UIButton* self) {
    if (self->_states[self->_curState].backgroundImage != nil) {
        return self->_states[self->_curState].backgroundImage;
    } else if (self->_states[UIControlStateNormal].backgroundImage != nil) {
        return self->_states[UIControlStateNormal].backgroundImage;
    } else {
        return nil;
    }
}

static UIImage* getImage(UIButton* self) {
    if (self->_states[self->_curState].image != nil) {
        return self->_states[self->_curState].image;
    } else if (self->_states[UIControlStateNormal].image != nil) {
        return self->_states[UIControlStateNormal].image;
    } else {
        return nil;
    }
}

static UIFont* getFont(UIButton* self) {
    UIFont* ret = [self->_label font];

    return ret;
}

static NSString* getTitle(UIButton* self) {
    if (self->_type == UIButtonTypeDetailDisclosure || self->_type == UIButtonTypeInfoLight || self->_type == UIButtonTypeInfoDark ||
        self->_type == UIButtonTypeContactAdd) {
        return nil;
    }

    if (self->_states[self->_curState].title != nil) {
        return self->_states[self->_curState].title;
    } else if (self->_states[UIControlStateNormal].title != nil) {
        return self->_states[UIControlStateNormal].title;
    } else {
        return nil;
    }
}

static UIColor* getTitleShadowColor(UIButton* self) {
    if (self->_states[self->_curState].titleShadowColor != nil) {
        return self->_states[self->_curState].titleShadowColor;
    } else if (self->_states[UIControlStateNormal].titleShadowColor != nil) {
        return self->_states[UIControlStateNormal].titleShadowColor;
    } else {
        return [UIColor whiteColor];
    }
}

static UIColor* getTextColor(UIButton* self) {
    if (self->_states[self->_curState].textColor != nil) {
        return self->_states[self->_curState].textColor;
    } else if (self->_states[UIControlStateNormal].textColor != nil) {
        return self->_states[UIControlStateNormal].textColor;
    } else {
        return self->_defaultColor;
    }
}

static void setLabelProperties(UIButton* self) {
    [self->_label setTextColor:getTextColor(self)];
    [self->_label setShadowColor:getTitleShadowColor(self)];
    [self->_label setShadowOffset:self->_shadowOffset];
    [self->_label setText:getTitle(self)];
}
static void setImageProperties(UIButton* self) {
    [self->_imageView setImage:getImage(self)];

    ColorQuad contentColor = self->_backgroundColor;
    if (self->_adjustsImageWhenHighlighted && self->_curState == UIControlStateHighlighted &&
        self->_states[UIControlStateHighlighted].image == nil) {
        contentColor.r = 0.5f;
        contentColor.g = 0.5f;
        contentColor.b = 0.5f;
    }
    [[self->_imageView layer]
        _setContentColor:[UIColor colorWithRed:contentColor.r green:contentColor.g blue:contentColor.b alpha:contentColor.a]];
}

static void createLabel(UIButton* self) {
    CGRect bounds;

    bounds = [self bounds];
    self->_label.attach([[UILabel alloc] initWithFrame:bounds]);
    [self->_label setBackgroundColor:[UIColor clearColor]];
    if (self->_font != nil) {
        [self->_label setFont:(id)self->_font];
    }
    [self addSubview:(id)self->_label];

    self->_imageView.attach([[UIImageView alloc] initWithFrame:bounds]);
    [self addSubview:(id)self->_imageView];
}

- (id)initWithCoder:(NSCoder*)coder {
    _backgroundColor.r = 1.f;
    _backgroundColor.g = 1.f;
    _backgroundColor.b = 1.f;
    _backgroundColor.a = 1.f;

    _states = (buttonState*)EbrCalloc(16, sizeof(buttonState));
    _font = [coder decodeObjectForKey:@"UIFont"];

    if (isOSTarget(@"7.0")) {
        _defaultColor = [UIColor blackColor];
    } else {
        _defaultColor = [UIColor whiteColor];
    }

    if ([coder containsValueForKey:@"UIButtonType"]) {
        UIButtonType type = (UIButtonType)[coder decodeIntForKey:@"UIButtonType"];

        id background = backgroundImageForButtonType(type);
        id selectedBackground = selectedBackgroundImageForButtonType(type);
        id image = imageForButtonType(type);
        id selectedImage = selectedImageForButtonType(type);

        [self setImage:image forState:0];
        [self setImage:selectedImage forState:1];
        [self setBackgroundImage:background forState:0];
        [self setBackgroundImage:selectedBackground forState:1];

        if (type == 1) {
            [self setTitleColor:[UIColor colorWithRed:0.0f green:0.47f blue:0.84f alpha:1.0f] forState:0];
            [self setTitleColor:[UIColor lightTextColor] forState:1];
        }
    }

    if ([coder containsValueForKey:@"UIDisabled"]) {
        BOOL disabled = [coder decodeIntegerForKey:@"UIDisabled"];
        if (disabled) {
            [self setEnabled:FALSE];
        }
    }

    if ([coder containsValueForKey:@"UIBackgroundColor"]) {
        UIButtonType type = (UIButtonType)[self buttonType];
        if (type == UIButtonTypeRoundedRect ||
            type == UIButtonTypeRoundedRectLegacy) { // We're not sure about roundedRect, feel free to delete if needed.
            id color = [coder decodeObjectForKey:@"UIBackgroundColor"];
            [[_imageView layer] _setContentColor:color];
        }
    }

    id stateContent = [coder decodeObjectForKey:@"UIButtonStatefulContent"];
    if (stateContent != nil) {
        //  Go through each state
        id objEnum = [stateContent objectEnumerator];
        id keyEnum = [stateContent keyEnumerator];

        id curObj, curKey;

        curKey = [keyEnum nextObject];
        curObj = [objEnum nextObject];

        while (curKey != nil) {
            uint32_t stateNum = [curKey intValue];

            assert(stateNum < 16);

            id image = [curObj image];
            if (image != nil) {
                _states[stateNum].image = image;
            }
            _states[stateNum].title = [curObj title];
            _states[stateNum].textColor = [curObj titleColor];
            _states[stateNum].titleShadowColor = (UIColor*)[curObj shadowColor];

            id backgroundImage = [curObj backgroundImage];
            if (backgroundImage != nil) {
                _states[stateNum].backgroundImage = backgroundImage;
            }

            curKey = [keyEnum nextObject];
            curObj = [objEnum nextObject];
        }
    }

    if ([coder containsValueForKey:@"UIImageEdgeInsets"]) {
        id obj = [coder decodeObjectForKey:@"UIImageEdgeInsets"];
        UIEdgeInsets inset = { 0 };
        if ([obj isKindOfClass:[NSString class]]) {
            const char* str = (const char*)[obj UTF8String];
            sscanf(str, "{%f, %f, %f, %f}", &inset.top, &inset.left, &inset.bottom, &inset.right);
        } else {
            CGRect* pRect = (CGRect*)((char*)[obj bytes] + 1);
            memcpy(&inset, pRect, sizeof(CGRect));
        }
        imageInsets = inset;
    }
    if ([coder containsValueForKey:@"UITitleEdgeInsets"]) {
        id obj = [coder decodeObjectForKey:@"UITitleEdgeInsets"];
        UIEdgeInsets inset = { 0 };
        if ([obj isKindOfClass:[NSString class]]) {
            const char* str = (const char*)[obj UTF8String];
            sscanf(str, "{%f, %f, %f, %f}", &inset.top, &inset.left, &inset.bottom, &inset.right);
        } else {
            CGRect* pRect = (CGRect*)((char*)[obj bytes] + 1);
            memcpy(&inset, pRect, sizeof(CGRect));
        }
        titleInsets = inset;
    }
    if ([coder containsValueForKey:@"UIContentEdgeInsets"]) {
        id obj = [coder decodeObjectForKey:@"UIContentEdgeInsets"];
        UIEdgeInsets inset = { 0 };
        if ([obj isKindOfClass:[NSString class]]) {
            const char* str = (const char*)[obj UTF8String];
            sscanf(str, "{%f, %f, %f, %f}", &inset.top, &inset.left, &inset.bottom, &inset.right);
        } else {
            CGRect* pRect = (CGRect*)((char*)[obj bytes] + 1);
            memcpy(&inset, pRect, sizeof(CGRect));
        }
        contentInsets = inset;
    }
    if ([coder containsValueForKey:@"UITitleShadowOffset"]) {
        id obj = [coder decodeObjectForKey:@"UITitleShadowOffset"];
        CGSize size = { 0 };
        if ([obj isKindOfClass:[NSString class]]) {
            const char* str = (const char*)[obj UTF8String];
            sscanf(str, "{%f, %f}", &_shadowOffset.width, &_shadowOffset.height);
        } else {
            CGSize* pSize = (CGSize*)((char*)[obj bytes] + 1);
            memcpy(&_shadowOffset, pSize, sizeof(CGSize));
        }
    }
    id result = [super initWithCoder:coder];
    if (![coder containsValueForKey:@"UIContentHorizontalAlignment"]) {
        _contentHorizontalAlignment = UIControlContentHorizontalAlignmentCenter;
    }
    if (![coder containsValueForKey:@"UIContentVerticalAlignment"]) {
        _contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
    }
    _adjustsImageWhenHighlighted = [coder decodeIntegerForKey:@"UIAdjustsImageWhenHighlighted"] != FALSE;
    [self setOpaque:FALSE];
    [self setClipsToBounds:TRUE];
    createLabel(self);

    return result;
}

- (instancetype)initWithFrame:(CGRect)pos {
    [super initWithFrame:pos];

    _backgroundColor.r = 1.f;
    _backgroundColor.g = 1.f;
    _backgroundColor.b = 1.f;
    _backgroundColor.a = 1.f;

    if (isOSTarget(@"7.0")) {
        _defaultColor = [UIColor blackColor];
    } else {
        _defaultColor = [UIColor whiteColor];
    }

    _states = (buttonState*)EbrCalloc(16, sizeof(buttonState));
    _font = [UIFont buttonFont];
    [self setOpaque:FALSE];
    _contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
    _contentHorizontalAlignment = UIControlContentHorizontalAlignmentCenter;
    _adjustsImageWhenHighlighted = true;
    createLabel(self);

    [self setAutoresizesSubviews:TRUE];
    [_imageView setAutoresizingMask:UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin |
                                    UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleBottomMargin];
    [_label setAutoresizingMask:UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin |
                                UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleBottomMargin];

    return self;
}

#ifdef UIBUTTON_DRAW_SELF
- (void)drawRect:(CGRect)inRect {
    CGRect bounds;

    bounds = [self bounds];
    if (getBackgroundImage(self) != nil)
        [getBackgroundImage(self) drawInRect:bounds];
}
#endif

static bool validateState(UIControlState state) {
    if (state >= 16) {
        EbrDebugLog("UIButton: bad control state %x\n", state);
        return false;
    }

    return true;
}

- (void)setImage:(UIImage*)image forState:(UIControlState)state {
    if (!validateState(state)) {
        return;
    }

    _states[state].image = image;
    [self setNeedsDisplay];
    [self setNeedsLayout];
    setImageProperties(self);
}

- (void)setBackgroundImage:(UIImage*)image forState:(UIControlState)state {
    if (!validateState(state)) {
        return;
    }

    _states[state].backgroundImage = image;
    [self setNeedsDisplay];
    [self setNeedsLayout];
    setImageProperties(self);
}

- (UIImage*)backgroundImageForState:(UIControlState)state {
    if (!validateState(state)) {
        return nil;
    }

    return _states[state].backgroundImage;
}

- (UIImage*)currentImage {
    return getImage(self);
}

- (void)setTitle:(NSString*)title forState:(UIControlState)state {
    if (!validateState(state)) {
        return;
    }

    _states[state].title.attach([title copy]);
    [self setNeedsLayout];
    [self layoutSubviews];
}

- (NSString*)titleForState:(UIControlState)state {
    if (!validateState(state)) {
        return nil;
    }

    return _states[state].title;
}

- (UIImage*)imageForState:(UIControlState)state {
    if (!validateState(state)) {
        return nil;
    }

    return _states[state].image;
}

- (void)setTitleColor:(UIColor*)color forState:(UIControlState)state {
    if (!validateState(state)) {
        return;
    }

    _states[state].textColor = color;
    [self setNeedsLayout];
}

- (UIColor*)titleColorForState:(UIControlState)state {
    if (!validateState(state)) {
        return nil;
    }

    return _states[state].textColor;
}

- (void)setTintColor:(UIColor*)color {
}

- (void)setTitleShadowColor:(UIColor*)color forState:(UIControlState)state {
    if (!validateState(state)) {
        return;
    }

    _states[state].titleShadowColor = color;
    [self setNeedsLayout];
}

- (UIColor*)titleShadowColorForState:(UIControlState)state {
    if (!validateState(state)) {
        return nil;
    }

    return _states[state].titleShadowColor;
}

- (UIColor*)currentTitleShadowColor {
    return getTitleShadowColor(self);
}

- (void)touchesBegan:(NSSet*)touchSet withEvent:(UIEvent*)event {
    if (_curState & UIControlStateDisabled) {
        return;
    }

    _isPressed = true;
    _curState |= UIControlStateHighlighted;
    [self setNeedsLayout];
    [self setNeedsDisplay];

    [super touchesBegan:touchSet withEvent:event];
}

- (void)touchesEnded:(NSSet*)touchSet withEvent:(UIEvent*)event {
    if (!_isPressed) {
        return;
    }

    _curState &= ~UIControlStateHighlighted;
    [self setNeedsLayout];
    [self setNeedsDisplay];

    [super touchesEnded:touchSet withEvent:event];
}

- (void)touchesCancelled:(NSSet*)touchSet withEvent:(UIEvent*)event {
    if (!_isPressed) {
        return;
    }

    _curState &= ~UIControlStateHighlighted;
    [self setNeedsLayout];
    [self setNeedsDisplay];

    [super touchesCancelled:touchSet withEvent:event];
}

- (void)setAdjustsImageWhenHighlighted:(BOOL)doAdjust {
    _adjustsImageWhenHighlighted = doAdjust != FALSE;
}

- (BOOL)adjustsImageWhenHighlighted {
    return _adjustsImageWhenHighlighted;
}

- (void)setAdjustsImageWhenDisabled:(BOOL)doAdjust {
}

- (void)setFont:(UIFont*)font {
    _font = font;
    [_label setFont:(id)_font];
    [self setNeedsLayout];
}

- (UIFont*)font {
    return _font;
}

- (UIButtonType)buttonType {
    return _type;
}

- (void)setTitleEdgeInsets:(UIEdgeInsets)insets {
    memcpy(&titleInsets, &insets, sizeof(UIEdgeInsets));
    [self setNeedsLayout];
}

- (void)setImageEdgeInsets:(UIEdgeInsets)insets {
    memcpy(&imageInsets, &insets, sizeof(UIEdgeInsets));
    [self setNeedsLayout];
}

- (void)setContentEdgeInsets:(UIEdgeInsets)insets {
    memcpy(&contentInsets, &insets, sizeof(UIEdgeInsets));
    [self setNeedsLayout];
}

- (UIEdgeInsets)imageEdgeInsets {
    return imageInsets;
}

- (UIEdgeInsets)titleEdgeInsets {
    return titleInsets;
}

- (UIEdgeInsets)contentEdgeInsets {
    return contentInsets;
}

- (void)setShowsTouchWhenHighlighted:(BOOL)showsTouch {
    _showsTouchWhenHighlighted = showsTouch != FALSE;
}

- (BOOL)showsTouchWhenHighlighted {
    return _showsTouchWhenHighlighted;
}

static UIImage* imageForButtonType(UIButtonType type) {
    UIImage* image = nil;

    switch (type) {
        case UIButtonTypeDetailDisclosure: //  Detail
            image = [UIImage imageNamed:@"/img/disclosure-btn.png"];
            break;

        case UIButtonTypeInfoLight: //  info
        case UIButtonTypeInfoDark:
            image = [UIImage imageNamed:@"/img/info.png"];
            break;

        case UIButtonTypeContactAdd: //  add
            image = [UIImage imageNamed:@"/img/add.png"];
            break;
    }

    return image;
}

static UIImage* selectedImageForButtonType(UIButtonType type) {
    return nil;
}

static UIImage* backgroundImageForButtonType(UIButtonType type) {
    UIImage* background = nil;

    switch (type) {
        case UIButtonTypeRoundedRect:
        case UIButtonTypeRoundedRectLegacy:
            background = [[UIImage imageNamed:@"/img/rounded-button@2x.png"] stretchableImageWithLeftCapWidth:11 topCapHeight:11];
            break;
    }

    return background;
}

static UIImage* selectedBackgroundImageForButtonType(UIButtonType type) {
    return nil;
}

+ (UIButton*)buttonWithType:(UIButtonType)type {
    UIButton* ret;

    if (type == UIButtonTypeRoundedRect || type == UIButtonTypeRoundedRectLegacy) {
        //  UIRoundedRectButton
        ret = [UIRoundedRectButton alloc];
    } else {
        ret = [self alloc];
    }

    ret->_type = type;

    CGRect pos;

    pos.origin.x = 0;
    pos.origin.y = 0;
    pos.size.width = 30;
    pos.size.height = 30;

    id background = backgroundImageForButtonType(type);
    id selectedBackground = selectedBackgroundImageForButtonType(type);
    id image = imageForButtonType(type);
    id selectedImage = selectedImageForButtonType(type);

    if (background || image) {
        if (background) {
            pos.size = [background size];
        } else {
            pos.size = [image size];
        }
    }

    [ret initWithFrame:pos];

    [ret setImage:image forState:0];
    [ret setImage:selectedImage forState:1];
    [ret setBackgroundImage:background forState:0];
    [ret setBackgroundImage:selectedBackground forState:1];

    if (type == UIButtonTypeRoundedRect || type == UIButtonTypeRoundedRectLegacy) {
        [ret setTitleColor:[UIColor colorWithRed:0.0f green:0.47f blue:0.84f alpha:1.0f] forState:0];
        [ret setTitleColor:[UIColor lightTextColor] forState:1];
    }

    return [ret autorelease];
}

- (void)setTitleShadowOffset:(CGSize)offset {
    memcpy(&_shadowOffset, &offset, sizeof(CGSize));
}

- (void)setReversesTitleShadowWhenHighlighted:(BOOL)reverses {
}

- (void)sizeToFit {
    CGRect frame;

    frame = [self frame];
    frame.size = [_states[UIControlStateNormal].image size];

    if (getTitle(self)) {
        CGSize size;

        size = [getTitle(self) sizeWithFont:(id)getFont(self) constrainedToSize:CGSizeMake(0.0f, 0.0f) lineBreakMode:UILineBreakModeClip];
        size.width += 20.0f;

        if (size.width > frame.size.width) {
            frame.size.width = size.width;
        }
        if (size.height > frame.size.height) {
            frame.size.height = size.height;
        }
    }

    if (getBackgroundImage(self)) {
        id background = getBackgroundImage(self);
        CGSize size;

        size = [background size];

        if (size.width > frame.size.width) {
            frame.size.width = size.width;
        }
        if (size.height > frame.size.height) {
            frame.size.height = size.height;
        }
    }

    frame.size.width += (contentInsets.right + contentInsets.left);
    frame.size.height += (contentInsets.top + contentInsets.bottom);
    [self setFrame:frame];
}

- (NSString*)currentTitle {
    return getTitle(self);
}

- (UIColor*)currentTitleColor {
    return getTextColor(self);
}

- (UILabel*)titleLabel {
    return _label;
}

- (UIImageView*)imageView {
    return _imageView;
}

static CGSize getTitleSize(UIButton* self, CGRect bounds) {
    CGSize textSize = { 0 };

    id title = getTitle(self);
    if ([title length] > 0) {
        textSize = [title sizeWithFont:(id)getFont(self) constrainedToSize:CGSizeMake(10000.0f, 10000.0f)];
    }
    /*
    textSize = [_label sizeThatFits:bounds.size];
    */

    return textSize;
}

static CGSize getImageSize(UIButton* self) {
    CGSize ret = { 0, 0 };
    id img = getImage(self);

    if (img != nil) {
        ret = [img size];
    }
    return ret;
}

static CGRect calcComponentRect(UIButton* self, CGSize size, CGRect contentRect) {
    CGRect rect;

    rect.origin = contentRect.origin;
    rect.size = size;

    if (CGRectGetMaxX(rect) > CGRectGetMaxX(contentRect)) {
        rect.size.width -= CGRectGetMaxX(rect) - CGRectGetMaxX(contentRect);
    }
    if (CGRectGetMaxY(rect) > CGRectGetMaxY(contentRect)) {
        rect.size.height -= CGRectGetMaxY(rect) - CGRectGetMaxY(contentRect);
    }

    switch (self->_contentHorizontalAlignment) {
        case UIControlContentHorizontalAlignmentCenter:
            rect.origin.x += floorf((contentRect.size.width / 2.f) - (rect.size.width / 2.f));
            break;

        case UIControlContentHorizontalAlignmentRight:
            rect.origin.x += contentRect.size.width - rect.size.width;
            break;

        case UIControlContentHorizontalAlignmentFill:
            rect.size.width = contentRect.size.width;
            break;

        case UIControlContentHorizontalAlignmentLeft:
            break;
    }

    switch (self->_contentVerticalAlignment) {
        case UIControlContentVerticalAlignmentCenter:
            rect.origin.y += floorf((contentRect.size.height / 2.f) - (rect.size.height / 2.f));
            break;

        case UIControlContentVerticalAlignmentBottom:
            rect.origin.y += contentRect.size.height - rect.size.height;
            break;

        case UIControlContentVerticalAlignmentFill:
            rect.size.height = contentRect.size.height;
            break;

        case UIControlContentVerticalAlignmentTop:
            break;
    }

    return rect;
}

static CGRect calcTitleRect(UIButton* self, CGRect bounds) {
    UIEdgeInsets inset = self->titleInsets;

    CGSize titleSize = getTitleSize(self, bounds);
    CGSize imageSize = getImageSize(self);

    CGSize totalSize = titleSize;
    totalSize.width += imageSize.width;

    CGRect ret = calcComponentRect(self, totalSize, UIEdgeInsetsInsetRect(bounds, inset));
    ret.origin.x += imageSize.width;

    return ret;
}

static CGRect calcImageRect(UIButton* self, CGRect bounds) {
    UIEdgeInsets inset = self->imageInsets;

    CGSize titleSize = getTitleSize(self, bounds);
    CGSize imageSize = getImageSize(self);

    CGSize totalSize = imageSize;
    totalSize.width += titleSize.width;

    CGRect ret = calcComponentRect(self, totalSize, UIEdgeInsetsInsetRect(bounds, inset));

    if (ret.size.width > imageSize.width) {
        ret.size.width = imageSize.width;
    }
    if (ret.size.height > imageSize.height) {
        ret.size.height = imageSize.height;
    }

    return ret;
}

- (void)layoutSubviews {
    id image = getBackgroundImage(self);

    if (image != nil) {
        UIImageSetLayerContents([self layer], image);

        ColorQuad contentColor = _backgroundColor;
        if (_adjustsImageWhenHighlighted && _curState == UIControlStateHighlighted && _states[UIControlStateHighlighted].image == nil) {
            contentColor.r = 0.5f;
            contentColor.g = 0.5f;
            contentColor.b = 0.5f;
        }
        [[self layer] _setContentColor:[UIColor colorWithRed:contentColor.r green:contentColor.g blue:contentColor.b alpha:contentColor.a]];
        _didSetBackgroundImage = true;
    } else if (_didSetBackgroundImage) {
        [[self layer] setContents:nil];
    }

    setLabelProperties(self);
    setImageProperties(self);

    CGRect bounds = { 0 };

    bounds = [self bounds];
    bounds = UIEdgeInsetsInsetRect(bounds, contentInsets);

    CGRect textFrame = calcTitleRect(self, bounds);
    CGRect imageFrame = calcImageRect(self, bounds);

    [_label setFrame:textFrame];
    [_imageView setFrame:imageFrame];

    if ((_curState & UIControlStateDisabled)) {
        if (!_isDisabled) {
            _isDisabled = true;
            if (_states[UIControlStateDisabled].backgroundImage == nil && _states[UIControlStateDisabled].image == nil) {
                [_label setAlpha:0.5f];
            }
            if (_states[UIControlStateDisabled].textColor == nil) {
                [_imageView setAlpha:0.5f];
            }
        }
    } else {
        if (_isDisabled) {
            [_label setAlpha:1.0f];
            [_imageView setAlpha:1.0f];
            _isDisabled = false;
        }
    }

    [super layoutSubviews];
}

- (void)dealloc {
    for (int i = 0; i < 16; i++) {
        _states[i].backgroundImage = nil;
        _states[i].image = nil;
        _states[i].textColor = nil;
        _states[i].titleShadowColor = nil;
        _states[i].title = nil;
    }

    _font = nil;
    _defaultColor = nil;
    [_label removeFromSuperview];
    _label = nil;
    [_imageView removeFromSuperview];
    _imageView = nil;
    EbrFree(_states);
    [super dealloc];
}

- (UIView*)viewForBaselineLayout {
    return _label;
}

- (CGSize)intrinsicContentSize {
    CGSize ret;

    ret = [_states[UIControlStateNormal].image size];

    if (getTitle(self)) {
        CGSize size;

        size = [getTitle(self) sizeWithFont:(id)getFont(self)];
        size.width += 20.0f;

        if (size.width > ret.width) {
            ret.width = size.width;
        }
        if (size.height > ret.height) {
            ret.height = size.height;
        }
    }

    if (getBackgroundImage(self)) {
        id background = getBackgroundImage(self);
        CGSize size;

        size = [background size];

        if (size.width > ret.width) {
            ret.width = size.width;
        }
        if (size.height > ret.height) {
            ret.height = size.height;
        }
    }

    ret.width += (contentInsets.right + contentInsets.left);
    ret.height += (contentInsets.top + contentInsets.bottom);

    if (ret.height < 30.0f) {
        ret.height = 30.0f;
    }

    return ret;
}

//

@end
