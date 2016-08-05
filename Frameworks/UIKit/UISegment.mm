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

#import "Starboard.h"
#import "UIKit/UIView.h"
#import "UIKit/UIControl.h"
#import "UIKit/UIColor.h"
#import "UIKit/UIFont.h"
#import "Foundation/NSString.h"
#import "CoreGraphics/CGContext.h"
#import "UISegment.h"
#import "UIViewInternal.h"
#import "UISegmentedControlInternal.h"

static idretain _defaultTextColor[2];

@implementation UISegment
+ (instancetype)initialize {
    _defaultTextColor[0] = [UIColor blueColor];
    _defaultTextColor[1] = [UIColor whiteColor];

    return self;
}

- (instancetype)initWithCoder:(NSCoder*)coder {
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
    _textColor[0] = nil;
    _textColor[1] = nil;
    _segmentFont = [UIFont boldSystemFontOfSize:15.0f];

    return self;
}

- (instancetype)initWithTitle:(id)title {
    _title.attach([title copy]);
    _position = 0;

    CGRect frame = { 0 };
    [self initWithFrame:frame];
    [self setOpaque:FALSE];
    _textColor[0] = nil;
    _textColor[1] = nil;
    _segmentFont = [UIFont boldSystemFontOfSize:15.0f];

    return self;
}

- (instancetype)initWithImage:(id)image {
    _image = image;
    _position = 0;

    CGRect frame = { 0.0f, 0.0f, 0.0f, 0.0f };

    [self initWithFrame:frame];
    [self setOpaque:FALSE];
    _textColor[0] = nil;
    _textColor[1] = nil;
    _segmentFont = [UIFont boldSystemFontOfSize:15.0f];

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

    if ([[self superview] respondsToSelector:@selector(_isEnabled)]) {
        if (![[self superview] _isEnabled]) {
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

    id bgColor, textColor;

    if (isOSTarget(@"7.0") && _selected == 0 && _tintColor != nil) {
        textColor = _tintColor;
        bgColor = [UIColor whiteColor];
    } else {
        bool tintColorUsed = false;
        int bgSelectState = (_selected + 1) % 2;

        // Get text/background colors. Fall back to tintColor and default colors if necessary
        if (_textColor[_selected] == nil) {
            if (_tintColor != nil) {
                tintColorUsed = (_selected == 0);
                textColor = (tintColorUsed) ? (id)(_tintColor) : (id)(_defaultTextColor[1]);
            } else {
                textColor = _defaultTextColor[_selected];
            }
        } else {
            textColor = _textColor[_selected];
        }

        if (_textColor[bgSelectState] == nil) {
            if (_tintColor != nil && tintColorUsed == false) {
                bgColor = _tintColor;
            } else {
                bgColor = _defaultTextColor[bgSelectState];
            }
        } else {
            bgColor = _textColor[bgSelectState];
        }
    }

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
            CGContextRef ctx = UIGraphicsGetCurrentContext();

            if (_selected) {
                // No border, just fill with background color
                CGContextSetFillColorWithColor(ctx, (CGColorRef)bgColor);
                CGContextFillRect(ctx, bounds);
            } else {
                // Fill with background color and draw border with text color
                const CGRect borderRect = bounds;
                const CGRect fillRect = CGRectInset(bounds, 1.0, 1.0);
                CGContextSetFillColorWithColor(ctx, (CGColorRef)bgColor);
                CGContextFillRect(ctx, fillRect);
                CGContextSetStrokeColorWithColor(ctx, (CGColorRef)textColor);
                CGContextSetLineWidth(ctx, 1.0);
                CGContextStrokeRect(ctx, borderRect);
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
        CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), (CGColorRef)textColor);

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
    [static_cast<UISegmentedControl*>(_delegate) _segmentSelectedDown:self];

    return self;
}

- (id)touchesEnded:(id)touchSet withEvent:(id)event {
    [static_cast<UISegmentedControl*>(_delegate) _segmentSelectedUp:self];

    return self;
}

- (id)touchesCancelled:(id)touchSet withEvent:(id)event {
    [static_cast<UISegmentedControl*>(_delegate) _segmentSelectedCancelled:self];

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
