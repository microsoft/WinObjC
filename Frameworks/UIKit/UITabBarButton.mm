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
#include "UITabBarButton.h"
#include "UIKit/UIColor.h"
#include "CGContextInternal.h"

@implementation UITabBarButton : UIView
- (instancetype)initWithFrame:(CGRect)frame item:(UITabBarItem*)item delegate:(id<UITabBarDelegate>)delegate {
    [super initWithFrame:frame];
    _item = item;
    _delegate = delegate;

    // We shouldn't occlude anything we aren't specifically drawing to:
    [self setBackgroundColor:[UIColor clearColor]];

    return self;
}

- (void)drawRect:(CGRect)pos {
    CGRect rect;
    rect = [self bounds];

    id tabBar = [self superview];
    id selectedItem = [tabBar selectedItem];
    if (selectedItem == _item) {
        id selectionIndicatorImage = [tabBar selectionIndicatorImage];
        if (selectionIndicatorImage != nil) {
            [selectionIndicatorImage drawInRect:rect];
        } else {
            CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), (CGColorRef)[UIColor grayColor]);
            CGContextFillRect(UIGraphicsGetCurrentContext(), rect);
        }
    }

    id image = [_item image];
    if (image != nil) {
        CGSize size;
        size = [image size];

        float scale = [image scale];
        CGContextRef context = CGBitmapContextCreate32(unsigned(size.width * scale), unsigned(size.height * scale));

        CGContextTranslateCTM(context, 0, size.height * scale);
        CGContextScaleCTM(context, 1.0, -1.0);

        CGRect drawRect;
        drawRect.origin.x = 0;
        drawRect.origin.y = 0;
        drawRect.size.width = size.width * scale;
        drawRect.size.height = size.height * scale;

        if (_item == selectedItem) {
            id highlight = [UIImage imageNamed:@"/img/tabbar-button-highlight.png"];

            CGContextClipToMask(context, drawRect, (CGImageRef)[image CGImage]);
            CGContextDrawImage(context, drawRect, (CGImageRef)[highlight CGImage]);
        } else {
            if ([_item enabled]) {
                id deselected = [UIImage imageNamed:@"/img/tabbar-button-deselected.png"];

                CGContextClipToMask(context, drawRect, (CGImageRef)[image CGImage]);
                CGContextDrawImage(context, drawRect, (CGImageRef)[deselected CGImage]);
            } else {
                id deselected = [UIImage imageNamed:@"/img/tabbar-button-disabled.png"];

                CGContextClipToMask(context, drawRect, (CGImageRef)[image CGImage]);
                CGContextDrawImage(context, drawRect, (CGImageRef)[deselected CGImage]);
            }
        }

        CGPoint pos;

        pos.x = rect.size.width / 2 - size.width / 2;
        pos.y = 5.0f;

        drawRect.origin = pos;
        drawRect.size.width = size.width;
        drawRect.size.height = size.height;

        CGRect clipRect;
        clipRect.origin.x = 3.0f;
        clipRect.origin.y = 5.0f;
        clipRect.size.width = rect.size.width - clipRect.origin.x - 3.0f;
        clipRect.size.height = rect.size.height - clipRect.origin.y - 13.0f;
        CGContextSaveGState(UIGraphicsGetCurrentContext());
        CGContextClipToRect(UIGraphicsGetCurrentContext(), clipRect);
        CGContextDrawImage(UIGraphicsGetCurrentContext(), drawRect, CGBitmapContextGetImage(context));
        CGContextRestoreGState(UIGraphicsGetCurrentContext());

        CGContextRelease(context);
    }

    id title = [_item title];
    if (title != nil) {
        CGSize size;
        id font = [UIFont defaultFont];
        size = [title sizeWithFont:font constrainedToSize:CGSizeMake(0.0f, 0.0f) lineBreakMode:UILineBreakModeClip];

        CGRect textRect;
        textRect.origin.y = rect.size.height - size.height;
        textRect.origin.x = rect.origin.x;
        textRect.size.width = rect.size.width;
        textRect.size.height = size.height;
        EbrCenterTextInRectVertically(&textRect, &size, font);

        CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), (CGColorRef)[UIColor whiteColor]);
        size = [title drawInRect:textRect withFont:font lineBreakMode:UILineBreakModeClip alignment:UITextAlignmentCenter];
    }
}

- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    UIView* parent = [self superview];
    if ([_item enabled] && [parent selectedItem] != _item) {
        [parent setSelectedItem:_item];

        if ([_delegate respondsToSelector:@selector(_tabBar:didSelectItem:)]) {
            [_delegate _tabBar:parent didSelectItem:_item];
        }
        if ([_delegate respondsToSelector:@selector(tabBar:didSelectItem:)]) {
            [_delegate tabBar:parent didSelectItem:_item];
        }
    }
}

@end
