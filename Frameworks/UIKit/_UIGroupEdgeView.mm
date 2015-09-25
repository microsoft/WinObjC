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
#include "_UIGroupEdgeView.h"
#include "CoreGraphics/CGContext.h"
#include "UIKit/UIColor.h"

struct GroupBackgroundTexture {
    idretain _image;
    CGColorRef _backgroundColor; // should be retained/released
    DWORD _style;
};

#define MAX_GROUPBACKGROUND_TEXTURES 32
static GroupBackgroundTexture _backgroundTextures[MAX_GROUPBACKGROUND_TEXTURES];
static int _numGroupBackgroundTextures;

static UIImage* findGroupBackgroundTexture(DWORD style, UIColor* color) {
    for (int i = 0; i < _numGroupBackgroundTextures; i++) {
        if (_backgroundTextures[i]._style == style && (_backgroundTextures[i]._backgroundColor == color ||
                                                       [_backgroundTextures[i]._backgroundColor isEqual:color])) {
            return _backgroundTextures[i]._image;
        }
    }

    if (_numGroupBackgroundTextures < MAX_GROUPBACKGROUND_TEXTURES) {
        GroupBackgroundTexture* newBackgroundTexture = &_backgroundTextures[_numGroupBackgroundTextures++];
        newBackgroundTexture->_style = style;
        newBackgroundTexture->_backgroundColor = (CGColorRef)color;

        CGSize size = CGSizeMake(16.0f, 16.0f);

        UIGraphicsBeginImageContextWithOptions(size, 0, 0.0f);
        CGContextRef ctx = UIGraphicsGetCurrentContext();
        CGRect rect;
        rect.origin.x = 0;
        rect.origin.y = 0;
        rect.size = size;

        rect.origin.x += 0.5f;
        rect.origin.y += 0.5f;
        rect.size.width -= 0.5f;
        rect.size.height -= 0.5f;
        CGContextSetStrokeColorWithColor(ctx, (CGColorRef)[UIColor grayColor]);
        CGContextSetFillColorWithColor(ctx, newBackgroundTexture->_backgroundColor);
        CGContextBeginPath(ctx);

        if (newBackgroundTexture->_style & 0x04) { //  Rounded bottom
            CGContextMoveToPoint(ctx, rect.origin.x + 5.0f, rect.size.height);
            CGContextAddArc(ctx, rect.origin.x + 5.0f, rect.size.height - 5.0f, 5.0f, kPi / 2.0f, kPi, 0);
        } else {
            CGContextMoveToPoint(ctx, rect.origin.x, rect.size.height);
        }

        if (newBackgroundTexture->_style & 0x02) { //  Rounded top
            CGContextAddLineToPoint(ctx, rect.origin.x, rect.origin.y + 5.0f);
            CGContextAddArc(ctx, rect.origin.x + 5.0f, rect.origin.y + 5.0f, 5.0f, kPi, kPi + kPi / 2.0f, 0);
        } else {
            CGContextAddLineToPoint(ctx, rect.origin.x, rect.origin.y - 5.0f);
        }

        if (newBackgroundTexture->_style & 0x02) { //  Rounded top
            CGContextAddLineToPoint(ctx, rect.size.width - 5.0f, rect.origin.y);
            CGContextAddArc(ctx, rect.size.width - 5.0f, rect.origin.y + 5.0f, 5.0f, kPi + kPi / 2.0f, kPi * 2.0f, 0);
        } else {
            CGContextAddLineToPoint(ctx, rect.size.width, rect.origin.y - 5.0f);
        }

        if (newBackgroundTexture->_style & 0x04) {
            CGContextAddLineToPoint(ctx, rect.size.width, rect.size.height - 5.0f);
            CGContextAddArc(ctx, rect.size.width - 5.0f, rect.size.height - 5.0f, 5.0f, 0, kPi / 2.0f, 0);
        } else {
            CGContextAddLineToPoint(ctx, rect.size.width, rect.size.height);
        }

        CGContextClosePath(ctx);

        CGContextSetLineWidth(ctx, 1.0f);
        CGContextFillPath(ctx);
        CGContextStrokePath(ctx);

        UIImage* uiImage = UIGraphicsGetImageFromCurrentImageContext();
        UIGraphicsEndImageContext();
        uiImage = [uiImage stretchableImageWithLeftCapWidth:8 topCapHeight:8];
        newBackgroundTexture->_image = uiImage;

        return uiImage;
    } else {
        return nil;
    }
}

@implementation _UIGroupEdgeView : UIView
- (void)_setStyle:(int)style {
    if (_style != style) {
        _style = style;
        [self setNeedsLayout];
    }
}

- (void)_setStyleColor:(UIColor*)background {
    if (![_backgroundColor isEqual:background]) {
        _backgroundColor = background;
        [self setNeedsLayout];
    }
}

- (void)layoutSubviews {
    if (_style != 0) {
        [self __setContentsImage:findGroupBackgroundTexture(_style, _backgroundColor)];
    } else {
        [[self layer] setContents:nil];
    }
}

@end
