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

#import <StubReturn.h>
#import "Starboard.h"
#import "LoggingNative.h"
#import "CALayerInternal.h"
#import "UIFontInternal.h"
#import "UIButtonContent.h"

static const wchar_t* TAG = L"UIButton";

struct buttonState {
    StrongId<UIImage> image, backgroundImage;
    StrongId<UIColor> textColor, titleShadowColor;
    StrongId<NSString> title;
};

@interface UIRoundedRectButton : UIButton {
}
@end

@implementation UIRoundedRectButton
@end

@implementation UIButton {
    __CGColorQuad _backgroundColor;
    StrongId<UIColor> _defaultColor;
    buttonState* _states;
    UIEdgeInsets titleInsets, imageInsets, contentInsets;
    StrongId<UIFont> _font;
    StrongId<UILabel> _label;
    StrongId<UIImageView> _imageView;
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

    __CGColorQuad contentColor = self->_backgroundColor;
    if (self->_adjustsImageWhenHighlighted && self->_curState == UIControlStateHighlighted &&
        self->_states[UIControlStateHighlighted].image == nil) {
        contentColor.r = 0.5f;
        contentColor.g = 0.5f;
        contentColor.b = 0.5f;
    }
    [[self->_imageView layer]
        _setContentColor:[[UIColor colorWithRed:contentColor.r green:contentColor.g blue:contentColor.b alpha:contentColor.a] CGColor]];
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

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    _backgroundColor.r = 1.f;
    _backgroundColor.g = 1.f;
    _backgroundColor.b = 1.f;
    _backgroundColor.a = 1.f;

    _states = (buttonState*)IwCalloc(16, sizeof(buttonState));
    _font = [coder decodeObjectForKey:@"UIFont"];

    if (isOSTarget(@"7.0")) {
        _defaultColor = [UIColor blackColor];
    } else {
        _defaultColor = [UIColor blackColor];
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
            UIColor* color = [coder decodeObjectOfClass:[UIColor class] forKey:@"UIBackgroundColor"];
            [[_imageView layer] _setContentColor:[color CGColor]];
        }
    }

    id stateContent = [coder decodeObjectForKey:@"UIButtonStatefulContent"];
    if (stateContent != nil) {
        //  Go through each state
        id objEnum = [stateContent objectEnumerator];
        id keyEnum = [stateContent keyEnumerator];

        id curKey;
        UIButtonContent* curObj;

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
            sscanf_s(str, "{%f, %f, %f, %f}", &inset.top, &inset.left, &inset.bottom, &inset.right);
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
            sscanf_s(str, "{%f, %f, %f, %f}", &inset.top, &inset.left, &inset.bottom, &inset.right);
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
            sscanf_s(str, "{%f, %f, %f, %f}", &inset.top, &inset.left, &inset.bottom, &inset.right);
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
            sscanf_s(str, "{%f, %f}", &_shadowOffset.width, &_shadowOffset.height);
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

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)pos {
    [super initWithFrame:pos];

    _backgroundColor.r = 1.f;
    _backgroundColor.g = 1.f;
    _backgroundColor.b = 1.f;
    _backgroundColor.a = 1.f;

    if (isOSTarget(@"7.0")) {
        _defaultColor = [UIColor blackColor];
    } else {
        _defaultColor = [UIColor blackColor];
    }

    _states = (buttonState*)IwCalloc(16, sizeof(buttonState));
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
        TraceVerbose(TAG, L"UIButton: bad control state %x", state);
        return false;
    }

    return true;
}

/**
 @Public No
*/
- (void)initAccessibility {
    [super initAccessibility];
    self.accessibilityTraits = UIAccessibilityTraitButton;
}

/**
 @Status Interoperable
*/
- (void)setImage:(UIImage*)image forState:(UIControlState)state {
    if (!validateState(state)) {
        return;
    }

    _states[state].image = image;
    [self setNeedsDisplay];
    [self setNeedsLayout];
    setImageProperties(self);
}

/**
 @Status Interoperable
*/
- (void)setBackgroundImage:(UIImage*)image forState:(UIControlState)state {
    if (!validateState(state)) {
        return;
    }

    _states[state].backgroundImage = image;
    [self setNeedsDisplay];
    [self setNeedsLayout];
    setImageProperties(self);
}

/**
 @Status Interoperable
*/
- (UIImage*)backgroundImageForState:(UIControlState)state {
    if (!validateState(state)) {
        return nil;
    }

    return _states[state].backgroundImage;
}

/**
 @Status Interoperable
*/
- (UIImage*)currentImage {
    return getImage(self);
}

/**
 @Status Interoperable
*/
- (void)setTitle:(NSString*)title forState:(UIControlState)state {
    if (!validateState(state)) {
        return;
    }

    _states[state].title.attach([title copy]);
    [self setNeedsLayout];
    [self layoutSubviews];

    self.accessibilityLabel = title;
}

/**
 @Status Interoperable
*/
- (NSString*)titleForState:(UIControlState)state {
    if (!validateState(state)) {
        return nil;
    }

    return _states[state].title;
}

/**
 @Status Interoperable
*/
- (UIImage*)imageForState:(UIControlState)state {
    if (!validateState(state)) {
        return nil;
    }

    return _states[state].image;
}

/**
 @Status Interoperable
*/
- (void)setTitleColor:(UIColor*)color forState:(UIControlState)state {
    if (!validateState(state)) {
        return;
    }

    _states[state].textColor = color;
    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (UIColor*)titleColorForState:(UIControlState)state {
    if (!validateState(state)) {
        return nil;
    }

    return _states[state].textColor;
}

/**
 @Status Stub
*/
- (void)setTintColor:(UIColor*)color {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)setTitleShadowColor:(UIColor*)color forState:(UIControlState)state {
    if (!validateState(state)) {
        return;
    }

    _states[state].titleShadowColor = color;
    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (UIColor*)titleShadowColorForState:(UIControlState)state {
    if (!validateState(state)) {
        return nil;
    }

    return _states[state].titleShadowColor;
}

/**
 @Status Interoperable
*/
- (UIColor*)currentTitleShadowColor {
    return getTitleShadowColor(self);
}

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
- (void)touchesEnded:(NSSet*)touchSet withEvent:(UIEvent*)event {
    if (!_isPressed) {
        return;
    }

    _curState &= ~UIControlStateHighlighted;
    [self setNeedsLayout];
    [self setNeedsDisplay];

    [super touchesEnded:touchSet withEvent:event];
}

/**
 @Status Interoperable
*/
- (void)touchesCancelled:(NSSet*)touchSet withEvent:(UIEvent*)event {
    if (!_isPressed) {
        return;
    }

    _curState &= ~UIControlStateHighlighted;
    [self setNeedsLayout];
    [self setNeedsDisplay];

    [super touchesCancelled:touchSet withEvent:event];
}

/**
 @Status Stub
*/
- (void)setAdjustsImageWhenHighlighted:(BOOL)doAdjust {
    UNIMPLEMENTED();
    _adjustsImageWhenHighlighted = doAdjust != FALSE;
}

/**
 @Status Stub
*/
- (BOOL)adjustsImageWhenHighlighted {
    UNIMPLEMENTED();
    return _adjustsImageWhenHighlighted;
}

/**
 @Status Stub
*/
- (void)setAdjustsImageWhenDisabled:(BOOL)doAdjust {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)setFont:(UIFont*)font {
    _font = font;
    [_label setFont:(id)_font];
    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (UIFont*)font {
    return _font;
}

/**
 @Status Interoperable
*/
- (UIButtonType)buttonType {
    return _type;
}

/**
 @Status Interoperable
*/
- (void)setTitleEdgeInsets:(UIEdgeInsets)insets {
    memcpy(&titleInsets, &insets, sizeof(UIEdgeInsets));
    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (void)setImageEdgeInsets:(UIEdgeInsets)insets {
    memcpy(&imageInsets, &insets, sizeof(UIEdgeInsets));
    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (void)setContentEdgeInsets:(UIEdgeInsets)insets {
    memcpy(&contentInsets, &insets, sizeof(UIEdgeInsets));
    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (UIEdgeInsets)imageEdgeInsets {
    return imageInsets;
}

/**
 @Status Interoperable
*/
- (UIEdgeInsets)titleEdgeInsets {
    return titleInsets;
}

/**
 @Status Interoperable
*/
- (UIEdgeInsets)contentEdgeInsets {
    return contentInsets;
}

/**
 @Status Stub
*/
- (void)setShowsTouchWhenHighlighted:(BOOL)showsTouch {
    UNIMPLEMENTED();
    _showsTouchWhenHighlighted = showsTouch != FALSE;
}

/**
 @Status Stub
*/
- (BOOL)showsTouchWhenHighlighted {
    UNIMPLEMENTED();
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

        case UIButtonTypeCustom:
        case UIButtonTypeSystem:
        case UIButtonTypeRoundedRect:
        case UIButtonTypeRoundedRectLegacy:
            UNIMPLEMENTED_WITH_MSG("Button type: %u is not handled", type);
            break;

        default:
            TraceWarning(TAG, L"Unknown button type");
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

        case UIButtonTypeCustom:
        case UIButtonTypeSystem:
        case UIButtonTypeDetailDisclosure:
        case UIButtonTypeInfoLight:
        case UIButtonTypeInfoDark:
        case UIButtonTypeContactAdd:
            UNIMPLEMENTED_WITH_MSG("Button type: %u is not handled", type);
            break;

        default:
            TraceWarning(TAG, L"Unknown button type");
    }

    return background;
}

static UIImage* selectedBackgroundImageForButtonType(UIButtonType type) {
    UIImage* background = nil;

    switch (type) {
        case UIButtonTypeRoundedRect:
        case UIButtonTypeRoundedRectLegacy:
            background = [[UIImage imageNamed:@"/img/rounded-button-pressed@2x.png"] stretchableImageWithLeftCapWidth:11 topCapHeight:11];
            break;

        case UIButtonTypeCustom:
        case UIButtonTypeSystem:
        case UIButtonTypeDetailDisclosure:
        case UIButtonTypeInfoLight:
        case UIButtonTypeInfoDark:
        case UIButtonTypeContactAdd:
            UNIMPLEMENTED_WITH_MSG("Button type: %u is not handled", type);
            break;

        default:
            TraceWarning(TAG, L"Unknown button type");
    }

    return background;
}

/**
 @Status Interoperable
*/
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
        [ret setTitleColor:[UIColor colorWithRed:0.0f green:0.0f blue:0.0f alpha:1.0f] forState:0];
    }

    return [ret autorelease];
}

- (void)setTitleShadowOffset:(CGSize)offset {
    memcpy(&_shadowOffset, &offset, sizeof(CGSize));
}

/**
 @Status Stub
*/
- (void)setReversesTitleShadowWhenHighlighted:(BOOL)reverses {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
- (NSString*)currentTitle {
    return getTitle(self);
}

/**
 @Status Interoperable
*/
- (UIColor*)currentTitleColor {
    return getTextColor(self);
}

/**
 @Status Interoperable
*/
- (UILabel*)titleLabel {
    return _label;
}

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
- (void)layoutSubviews {
    id image = getBackgroundImage(self);

    if (image != nil) {
        UIImageSetLayerContents([self layer], image);

        __CGColorQuad contentColor = _backgroundColor;
        if (_adjustsImageWhenHighlighted && _curState == UIControlStateHighlighted && _states[UIControlStateHighlighted].image == nil) {
            contentColor.r = 0.5f;
            contentColor.g = 0.5f;
            contentColor.b = 0.5f;
        }
        //  TODO: I think this should always be the case?  Should UIButton always stretch its background?
        self.layer.contentsGravity = kCAGravityResize;
        [[self layer]
            _setContentColor:[[UIColor colorWithRed:contentColor.r green:contentColor.g blue:contentColor.b alpha:contentColor.a] CGColor]];
        _didSetBackgroundImage = true;
    } else if (_didSetBackgroundImage) {
        [[self layer] setContents:nil];
    }

    setLabelProperties(self);
    setImageProperties(self);

    CGRect bounds = { 0 };

    bounds = [self bounds];
    bounds = UIEdgeInsetsInsetRect(bounds, contentInsets);

    CGRect contentFrame = [self contentRectForBounds:bounds];
    CGRect textFrame = [self titleRectForContentRect:contentFrame];
    CGRect imageFrame = [self imageRectForContentRect:contentFrame];

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

/**
 @Status Interoperable
*/
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
    IwFree(_states);
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (UIView*)viewForBaselineLayout {
    return _label;
}

/**
 @Status Interoperable
*/
- (CGSize)intrinsicContentSize {
    CGSize ret = { 0 };
    UIImage* img = _states[UIControlStateNormal].image;

    if (img != nil) {
        ret = [img size];
    }

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

/**
 @Status Caveat
 @Notes Overriding this method has no effect
*/
- (CGRect)backgroundRectForBounds:(CGRect)bounds {
    return bounds;
}

/**
 @Status Interoperable
*/
- (CGRect)contentRectForBounds:(CGRect)bounds {
    return bounds;
}

/**
 @Status Interoperable
*/
- (CGRect)imageRectForContentRect:(CGRect)contentRect {
    return calcImageRect(self, contentRect);
}

/**
 @Status Interoperable
*/
- (CGRect)titleRectForContentRect:(CGRect)contentRect {
    return calcTitleRect(self, contentRect);
}

/**
 @Status Stub
*/
- (NSAttributedString*)attributedTitleForState:(UIControlState)state {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setAttributedTitle:(NSAttributedString*)title forState:(UIControlState)state {
    UNIMPLEMENTED();
}

@end
