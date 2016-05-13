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
#import "StubReturn.h"
#import "UIKit/UITabBar.h"
#import "UITabBarButton.h"
#import "UIKit/UIColor.h"
#import "CoreGraphics/CGContext.h"
#import "Foundation/NSMutableArray.h"
#import "Foundation/NSString.h"
#import "UIKit/UIColor.h"
#import "UIKit/UITabBar.h"

#import "LoggingNative.h"
#import "UIAppearanceSetter.h"
#import "UITabBarButton.h"
#import "UIViewInternal.h"
#import "CACompositor.h"

static const wchar_t* TAG = L"UITabBar";

@implementation UITabBar {
    idretain _items;
    bool _layoutDirty;
    StrongId<NSMutableArray> _buttons;
    idretain _backgroundImage, _selectionIndicatorImage;
    id _delegate;
    id _selectedItem;
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    [super initWithCoder:coder];
    _items = [coder decodeObjectForKey:@"UIItems"];
    _layoutDirty = true;
    _delegate = [coder decodeObjectForKey:@"UIDelegate"];
    _selectionIndicatorImage =
        [[UIImage imageNamed:@"/img/tabbar-button-selected.png"] resizableImageWithCapInsets:UIEdgeInsetsMake(0, 5, 5, 5)];
    _backgroundImage = [[UIImage imageNamed:@"/img/tabbar-background.png"] resizableImageWithCapInsets:UIEdgeInsetsMake(2, 3, 10, 3)];

    [self setBackgroundColor:[UIColor blackColor]];
    [self setContentMode:UIViewContentModeRedraw];

    if (GetCACompositor()->isTablet()) {
        id background =
            [[UIImage imageNamed:@"/img/navgradient-blackopaque.png"] resizableImageWithCapInsets:UIEdgeInsetsMake(2, 3, 10, 3)];
        [self __setContentsImage:background];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    [super initWithFrame:frame];
    _items.attach([NSMutableArray new]);

    [self setBackgroundColor:[UIColor blackColor]];
    [self setContentMode:UIViewContentModeRedraw];
    _selectionIndicatorImage =
        [[UIImage imageNamed:@"/img/tabbar-button-selected.png"] resizableImageWithCapInsets:UIEdgeInsetsMake(0, 5, 5, 5)];
    _backgroundImage = [[UIImage imageNamed:@"/img/tabbar-background.png"] resizableImageWithCapInsets:UIEdgeInsetsMake(2, 3, 10, 3)];

    if (GetCACompositor()->isTablet()) {
        id background =
            [[UIImage imageNamed:@"/img/navgradient-blackopaque.png"] resizableImageWithCapInsets:UIEdgeInsetsMake(2, 3, 10, 3)];
        [self __setContentsImage:background];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    _buttons = nil;
    _backgroundImage = nil;
    _selectionIndicatorImage = nil;
    _items = nil;

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (NSArray*)items {
    return _items;
}

/**
 @Status Interoperable
*/
- (void)setItems:(NSArray*)items {
    _layoutDirty = true;
    _items.attach([items copy]);
    [self setNeedsLayout];
}

/**
 @Status Stub
*/
- (void)setItems:(NSArray*)items animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)beginCustomizingItems:(NSArray*)items {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (BOOL)endCustomizingAnimated:(BOOL)animated {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (BOOL)isCustomizing {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)setSelectedItem:(id)item {
    _selectedItem = item;
    for (UITabBarButton* button in(id) _buttons) {
        [button setNeedsDisplay];
    }
}

/**
 @Status Interoperable
*/
- (void)setDelegate:(id<UITabBarDelegate>)delegate {
    _delegate = delegate;
}

/**
 @Status Interoperable
*/
- (UITabBarItem*)selectedItem {
    return _selectedItem;
}

/**
 @Status Interoperable
*/
- (void)layoutSubviews {
    if (!_layoutDirty) {
        return;
    }

    if (_buttons) {
        for (UITabBarButton* button in(id) _buttons) {
            [button removeFromSuperview];
        }
        [_buttons removeAllObjects];
    } else {
        _buttons.attach([NSMutableArray new]);
    }

    int itemCount = [_items count];
    if (itemCount > 0) {
        CGRect bounds;
        bounds = [self bounds];
        float itemWidth = bounds.size.width / itemCount;

        float curX = 0.f;
        float spacing = 0.f;

        if (GetCACompositor()->isTablet()) {
            itemWidth = 75.0f;
            spacing = 50.0f;

            curX = bounds.size.width / 2.0f - (itemCount * itemWidth + spacing * (itemCount - 1)) / 2.0f;
        }
        for (UITabBarItem* item in(id) _items) {
            [UIAppearanceSetter _applyAppearance:item withAppearanceClass:[UITabBarItem class] withBaseView:self];

            CGRect frame = bounds;
            frame.origin.x = curX;
            frame.size.width = itemWidth;

            UITabBarButton* button = [[UITabBarButton alloc] initWithFrame:frame item:item delegate:_delegate];
            [_buttons addObject:button];
            [self addSubview:button];
            [button release];

            curX += itemWidth;
            curX += spacing;
        }
    }

    _layoutDirty = false;
    [super layoutSubviews];
}

/**
 @Status Interoperable
*/
- (void)drawRect:(CGRect)pos {
    if (_backgroundImage != nil) {
        CGRect bounds;
        bounds = [self bounds];
        [_backgroundImage drawInRect:bounds];
    }
}

/**
 @Status Interoperable
*/
- (void)setBackgroundImage:(UIImage*)image {
    _backgroundImage = image;
    [self setNeedsDisplay];
}

/**
 @Status Interoperable
*/
- (UIImage*)backgroundImage {
    return _backgroundImage;
}

/**
 @Status Stub
*/
- (UIImage*)selectionIndicatorImage {
    UNIMPLEMENTED();
    return _selectionIndicatorImage;
}

/**
 @Status Stub
*/
- (void)setSelectionIndicatorImage:(UIImage*)image {
    UNIMPLEMENTED();
    _selectionIndicatorImage = image;
}

/**
 @Status Stub
*/
- (void)setSelectedImageTintColor:(UIColor*)color {
    UNIMPLEMENTED_WITH_MSG("UITabBar setSelectedImageTintColor not supported\n");
}

/**
 @Status Stub
*/
- (void)setTintColor:(UIColor*)color {
    UNIMPLEMENTED();
    TraceVerbose(TAG, L"UITabBar setTintColor not supported");
}

- (void)_setLayoutDirty {
    _layoutDirty = true;
    [self setNeedsLayout];
}

@end
