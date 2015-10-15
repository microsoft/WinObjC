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
#include "UIKit/UIView.h"
#include "UIKit/UIControl.h"
#include "UIKit/UIColor.h"
#include "UIKit/UIFont.h"
#include "Foundation/NSString.h"
#include "CoreGraphics/CGContext.h"
#include "UISegment.h"

static idretain _buttonLeft[2];
static idretain _buttonRight[2];
static idretain _buttonFill[2];

@implementation UISegment : UIView
+ (id)initialize {
    _buttonLeft[0] = [[UIImage imageNamed:@"/img/ButtonBarLeftNoSelect@2x.png"] resizableImageWithCapInsets:UIEdgeInsetsMake(0, 10, 0, 10)];
    _buttonLeft[1] = [[UIImage imageNamed:@"/img/ButtonBarLeftSelect@2x.png"] resizableImageWithCapInsets:UIEdgeInsetsMake(0, 10, 0, 10)];
    _buttonRight[0] =
        [[UIImage imageNamed:@"/img/ButtonBarRightNoSelect@2x.png"] resizableImageWithCapInsets:UIEdgeInsetsMake(0, 10, 0, 10)];
    _buttonRight[1] = [[UIImage imageNamed:@"/img/ButtonBarRightSelect@2x.png"] resizableImageWithCapInsets:UIEdgeInsetsMake(0, 10, 0, 10)];
    _buttonFill[0] = [[UIImage imageNamed:@"/img/ButtonBarFillNoSelect@2x.png"] resizableImageWithCapInsets:UIEdgeInsetsMake(0, 2, 0, 1)];
    _buttonFill[1] = [[UIImage imageNamed:@"/img/ButtonBarFillSelect@2x.png"] resizableImageWithCapInsets:UIEdgeInsetsMake(0, 2, 0, 1)];

    return self;
}

- (id)initWithCoder:(id)coder {
    id result = [super initWithCoder:coder];
    id info = [[coder decodeObjectForKey:@"UISegmentInfo"] retain];
    _position = [coder decodeInt32ForKey:@"UISegmentPosition"];

    CGRect frame;
    frame = [self bounds];

    if ([info isKindOfClass:[NSString class]]) {
        _title = info;
    } else if ([info isKindOfClass:[UIImage class]]) {
        _image = info;
    } else {
        assert(0);
    }
    [self setOpaque:FALSE];
    _textColor[0] = [UIColor darkGrayColor];
    _textColor[1] = [UIColor whiteColor];
    _segmentFont = [UIFont boldSystemFontOfSize:12.0f];

    return self;
}

- (id)initWithTitle:(id)title {
    _title.attach([title copy]);
    _position = 0;

    CGRect frame = { 0 };
    [self initWithFrame:frame];
    [self setOpaque:FALSE];
    _textColor[0] = [UIColor darkGrayColor];
    _textColor[1] = [UIColor whiteColor];
    _segmentFont = [UIFont boldSystemFontOfSize:12.0f];

    return self;
}

- (id)initWithImage:(id)image {
    _image = image;
    _position = 0;

    CGRect frame = { 0.0f, 0.0f, 0.0f, 0.0f };

    [self initWithFrame:frame];
    [self setOpaque:FALSE];
    _textColor[0] = [UIColor darkGrayColor];
    _textColor[1] = [UIColor whiteColor];
    _segmentFont = [UIFont boldSystemFontOfSize:12.0f];

    return self;
}

- (unsigned)position {
    return _position;
}

- (id)setDelegate:(id)delegate {
    _delegate = delegate;

    return self;
}

- (id)setTitle:(id)title {
    _title.attach([title copy]);
    //_image = nil;
    [self setNeedsDisplay];

    return self;
}

- (id)setImage:(id)image {
    _image = image;
    //_title = nil;
    [self setNeedsDisplay];

    return self;
}

- (id)image {
    return _image;
}

- (id)title {
    return _title;
}

- (id)buttonClicked:(id)button {
    [_delegate segmentSelected:self];

    return self;
}

- (id)_setType:(DWORD)type {
    if (_type == 4) {
        return self;
    }

    _type = type;
    [self setNeedsDisplay];

    return self;
}

- (id)_setSelected:(DWORD)selected {
    _selected = selected;
    [self setNeedsDisplay];

    return self;
}

- (id)setEnabled:(DWORD)enabled {
    int newVal;
    if (enabled) {
        newVal = 0;
    } else {
        newVal = 1;
    }

    if (newVal != _disabled) {
        _disabled = newVal;
        [self setNeedsDisplay];
    }

    return self;
}

- (BOOL)isEnabled {
    if (_disabled) {
        return FALSE;
    }

    return TRUE;
}

- (id)drawRect:(CGRect)inRect {
    CGRect bounds;

    bool isDisabled = false;

    if ([[self superview] respondsToSelector:@selector(isEnabled)]) {
        if (![[self superview] isEnabled]) {
            isDisabled = true;
        }
    }
    if (_disabled) {
        isDisabled = true;
    }

    if (isDisabled) {
        [self setAlpha:0.5f];
    } else {
        [self setAlpha:1.0f];
    }

    bounds = [self bounds];

    if (isOSTarget(@"7.0")) {
        if (_tintColor != nil) {
            if (_selected == 1) {
                CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), (CGColorRef)_tintColor);
                CGContextFillRect(UIGraphicsGetCurrentContext(), bounds);
            }
            if ((_type & 2) == 0) {
                CGRect rect = bounds;
                float lineWidth = 1.0f;

                rect.origin.x = rect.size.width - lineWidth;
                rect.size.width = lineWidth;
                CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), (CGColorRef)_tintColor);
                CGContextFillRect(UIGraphicsGetCurrentContext(), rect);
            }
        }
    } else {
        if (!_noDefaultImages) {
            switch (_type) {
                case 0:
                case 3:
                    [_buttonFill[_selected] drawInRect:bounds];
                    break;

                case 1:
                    [_buttonLeft[_selected] drawInRect:bounds];
                    break;

                case 2:
                    [_buttonRight[_selected] drawInRect:bounds];
                    break;

                default:
                    break;
            }
        }
        if (_selected == 1 && _selectedBackground != nil) {
            CGRect superviewRect = { 0 };
            superviewRect = [[self superview] bounds];
            CGRect drawRect;
            drawRect = [[self superview] convertRect:superviewRect toView:self];
            [_selectedBackground drawInRect:drawRect];
        }
        if (_dividerImage != nil) {
            if ((_type & 2) == 0) {
                CGRect rect = bounds;
                CGSize imgSize = { 0, 0 };
                imgSize = [_dividerImage size];

                rect.origin.x = rect.size.width - (imgSize.width / 2.0f) - 1.0f;
                rect.size.width = imgSize.width;
                [_dividerImage drawInRect:rect];
            }
        }
    }

    if (_image != nil) {
        CGSize size;
        CGRect rect;

        rect = [self bounds];
        size = [_image size];

        rect.origin.x = rect.size.width / 2.0f - size.width / 2.0f;
        rect.origin.y = rect.size.height / 2.0f - size.height / 2.0f;
        [_image drawAtPoint:rect.origin];
    }

    if (_title != nil) {
        id color = _textColor[_selected];
        if (isOSTarget(@"7.0") && _selected == 0 && _tintColor != nil) {
            color = _tintColor;
        }
        // if ( _selectedBackground != nil ) color = _textColor[1];
        CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), (CGColorRef)color);

        CGSize size;
        CGRect rect;

        rect = [self bounds];
        size = rect.size;
        size = [_title sizeWithFont:_segmentFont constrainedToSize:CGSizeMake(size.width, size.height) lineBreakMode:UILineBreakModeClip];

        rect.origin.y = rect.size.height / 2.0f - size.height / 2.0f;
        rect.size.height = size.height;
        size = [_title drawInRect:rect withFont:_segmentFont lineBreakMode:UILineBreakModeClip alignment:UITextAlignmentCenter];
    }

    return self;
}

- (float)_contentWidth {
    if (_image != nil) {
        CGSize size = { 0, 0 };

        size = [_image size];
        return size.width;
    }

    if (_title != nil) {
        CGSize size = { 0, 0 };
        size = [_title sizeWithFont:_segmentFont constrainedToSize:CGSizeMake(0.0f, 0.0f) lineBreakMode:UILineBreakModeClip];

        return size.width;
    }

    return 0.0f;
}

- (float)_desiredWidth {
    return _overrideWidth;
}

- (id)_setWidth:(float)width {
    _overrideWidth = width;

    return 0;
}

- (id)touchesBegan:(id)touchSet withEvent:(id)event {
    [[self superview] segmentSelectedDown:self];

    return self;
}

- (id)touchesEnded:(id)touchSet withEvent:(id)event {
    [[self superview] segmentSelectedUp:self];

    return self;
}

- (id)touchesCancelled:(id)touchSet withEvent:(id)event {
    [[self superview] segmentSelectedCancelled:self];

    return self;
}

- (id)_setBackgroundImage:(id)image forState:(DWORD)state {
    if (state == UIControlStateSelected) {
        _selectedBackground = image;
    }
    return self;
}

- (id)_setAttributes:(id)attributes forState:(DWORD)state {
    id font = [attributes objectForKey:@"kCTFontAttributeName"];
    id textColor = [attributes objectForKey:@"UITextAttributeTextColor"];

    if (font != nil) {
        _segmentFont = font;
    }
    if (textColor != nil) {
        if (state == UIControlStateNormal) {
            _textColor[1] = textColor;
        } else if (state == UIControlStateSelected) {
            _textColor[0] = textColor;
        }
    }
    return self;
}

- (id)_setDividerImage:(id)image {
    _dividerImage = image;
    return self;
}

- (id)_setNoDefaultImages:(BOOL)noDefault {
    _noDefaultImages = noDefault;
    return self;
}

- (id)_setTintColor:(id)color {
    _tintColor = color;
    return self;
}

- (void)dealloc {
    _title = nil;
    _image = nil;
    _selectedBackground = nil;
    _highlightedBackground = nil;
    _dividerImage = nil;
    _segmentFont = nil;
    _textColor[0] = nil;
    _textColor[1] = nil;
    [super dealloc];
}

@end
