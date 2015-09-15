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

#include "UIKit/UITabBar.h"
#include "UITabBarButton.h"

#include "UIKit/UIColor.h"
#include "CoreGraphics/CGContext.h"
#include "Foundation/NSString.h"
#include "Foundation/NSMutableArray.h"

#if 0
#include "UIAppearanceSetter.h"
#endif

@implementation UITabBar {
    idretain _items;
    bool     _layoutDirty;
    idretaintype(NSArray) _buttons;
    idretain _backgroundImage, _selectionIndicatorImage;
    id _delegate;
    id _selectedItem;
}

    -(instancetype) initWithCoder:(NSCoder*)coder {
        [super initWithCoder:coder];
        _items = [coder decodeObjectForKey:@"UIItems"];
        _layoutDirty = true;
        _delegate = [coder decodeObjectForKey:@"UIDelegate"];
        _selectionIndicatorImage = [[UIImage imageNamed:@"/img/tabbar-button-selected.png"] resizableImageWithCapInsets: UIEdgeInsetsMake(0, 5, 5, 5)];
        _backgroundImage = [[UIImage imageNamed:@"/img/tabbar-background.png"] resizableImageWithCapInsets: UIEdgeInsetsMake(2, 3, 10, 3)];

        [self setBackgroundColor:[UIColor blackColor]];
        [self setContentMode:UIViewContentModeRedraw];

        if ( GetCACompositor()->isTablet() ) {
            id background = [[UIImage imageNamed:@"/img/navgradient-blackopaque.png"] resizableImageWithCapInsets: UIEdgeInsetsMake(2, 3, 10, 3)];
            [self __setContentsImage:background];
        }

        return self;
    }

    -(instancetype) initWithFrame:(CGRect)frame {
        [super initWithFrame:frame];
        _items.attach([NSMutableArray new]);

        [self setBackgroundColor:[UIColor blackColor]];
        [self setContentMode:UIViewContentModeRedraw];
        _selectionIndicatorImage = [[UIImage imageNamed:@"/img/tabbar-button-selected.png"] resizableImageWithCapInsets: UIEdgeInsetsMake(0, 5, 5, 5)];
        _backgroundImage = [[UIImage imageNamed:@"/img/tabbar-background.png"] resizableImageWithCapInsets: UIEdgeInsetsMake(2, 3, 10, 3)];

        if ( GetCACompositor()->isTablet() ) {
            id background = [[UIImage imageNamed:@"/img/navgradient-blackopaque.png"] resizableImageWithCapInsets: UIEdgeInsetsMake(2, 3, 10, 3)];
            [self __setContentsImage:background];
        }

        return self;
    }

    -(void) dealloc {
        _buttons = nil;
        _backgroundImage = nil;
        _selectionIndicatorImage = nil;
        _items = nil;

        [super dealloc];
    }

    -(NSArray*) items {
        return _items;
    }

    -(void) setItems:(NSArray*)items {
        _layoutDirty = true;
        _items.attach([items copy]);
        [self setNeedsLayout];
    }

    -(void) setSelectedItem:(id)item {
        _selectedItem = item;
        for (UITabBarButton* button in (id) _buttons) {
            [button setNeedsDisplay];
        }
    }

    -(void) setDelegate:(id<UITabBarDelegate>)delegate {
        _delegate = delegate;
    }

    -(UITabBarItem*) selectedItem {
        return _selectedItem;
    }

    -(void) layoutSubviews {
        if ( !_layoutDirty ) return;

        if ( _buttons ) {
            for (UITabBarButton* button in (id) _buttons) {
                [button removeFromSuperview];
            }
            [_buttons removeAllObjects];
        } else {
            _buttons.attach([NSMutableArray new]);
        }

        int itemCount = [_items count];
        if ( itemCount > 0 ) {
            CGRect bounds;
            bounds = [self bounds];
            float itemWidth = bounds.size.width / itemCount;

            float curX = 0.f;
            float spacing = 0.f;

            if ( GetCACompositor()->isTablet() ) {
                itemWidth = 75.0f;
                spacing = 50.0f;

                curX = bounds.size.width / 2.0f - (itemCount * itemWidth + spacing * (itemCount - 1)) / 2.0f;
            }
            for (UITabBarItem* item in (id) _items) {
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

    -(void) drawRect:(CGRect)pos {
        if ( _backgroundImage != nil ) {
            CGRect bounds;
            bounds = [self bounds];
            [_backgroundImage drawInRect:bounds];
        }
    }

    -(void) setBackgroundImage:(UIImage*)image {
        _backgroundImage = image;
        [self setNeedsDisplay];
    }

    -(UIImage*) backgroundImage {
        return _backgroundImage;
    }

    -(UIImage*) selectionIndicatorImage {
        return _selectionIndicatorImage;
    }

    -(void) setSelectionIndicatorImage:(UIImage*)image {
        _selectionIndicatorImage = image;
    }

    -(void) setSelectedImageTintColor:(UIColor*)color {
        EbrDebugLog("UITabBar setSelectedImageTintColor not supported\n");
    }

    -(void) setTintColor:(UIColor*)color {
        EbrDebugLog("UITabBar setTintColor not supported\n");
    }

    -(void) _setLayoutDirty {
        _layoutDirty = true;
        [self setNeedsLayout];
    }

        //  
@end

