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

#import "AssertARCEnabled.h"
#import "Starboard.h"
#import "StubReturn.h"
#import "XamlUtilities.h"
#import <UIKit/UIKit.h>
#import <UWP/WindowsUIXamlControls.h>

static const wchar_t* TAG = L"UIToolbar";

@implementation UIToolbar {
    StrongId<WXCCommandBar> _xamlCommandBar;
    UIBarStyle _style;
    StrongId<UIColor> _tintColor;
    StrongId<UIColor> _barTintColor;
    BOOL _translucent;
    StrongId<NSMutableArray> _items;
    EventRegistrationToken _commandBarLoadedEvent;
}

- (void)_UIToolbar_initInternal {
    _xamlCommandBar = [WXCCommandBar make];
    [self setNativeElement:_xamlCommandBar];
    [self setTranslucent:YES];
    [self setBarStyle:UIBarStyleDefault];
    __weak UIToolbar* weakSelf = self;

    _commandBarLoadedEvent = [_xamlCommandBar addLoadedEvent:^void(RTObject* sender, WXRoutedEventArgs* e) {
        __strong UIToolbar* strongSelf = weakSelf;
        WXFrameworkElement* moreButton = [XamlUtilities findTemplateChild:strongSelf->_xamlCommandBar name:@"MoreButton"];
        moreButton.visibility = WUCAppViewBackButtonVisibilityCollapsed;
    }];
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        [self _UIToolbar_initInternal];

        if ([coder containsValueForKey:@"UIBarStyle"]) {
            [self setBarStyle:(UIBarStyle)[coder decodeInt32ForKey:@"UIBarStyle"]];
        }
        if ([coder containsValueForKey:@"UITintColor"]) {
            [self setTintColor:[coder decodeObjectForKey:@"UITintColor"]];
        }
        if ([coder containsValueForKey:@"UIItems"]) {
            [self setItems:[coder decodeObjectForKey:@"UIItems"]];
        }
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self _UIToolbar_initInternal];
    }
    return self;
}

/**
 @Status Stub
*/
- (void)setDelegate:(id)delegateAddr {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)setItems:(NSArray*)items {
    [self setItems:items animated:NO];
}

/**
 @Status Interoperable
*/
- (NSArray*)items {
    return _items;
}

/**
 @Status Caveat
 @Notes animated parameter not supported
 @Notes UIBarButtonItem not currently supported. When this changes, UIBarButtonItem will replace WXCAppBarButton usage.
*/
- (void)setItems:(NSArray*)items animated:(BOOL)animated {
    [_xamlCommandBar.primaryCommands removeAllObjects];
    [_items removeAllObjects];
    NSMutableArray* mutableItems = [items mutableCopy];

    for (id button in items) {
        if ([button isKindOfClass:[WXCAppBarButton class]]) {
            [_xamlCommandBar.primaryCommands addObject:button];
        } else if ([button isKindOfClass:[UIBarButtonItem class]]) {
            // TODO: Task 5243737
        } else {
            [mutableItems removeObject:button];
            TraceError(TAG, L"Failed to recognize item type in UIToolBar");
        }
    }
    _items = mutableItems;
}

/**
 @Status Interoperable
*/
- (void)setBarStyle:(UIBarStyle)style {
    if (style >= UIBarStyleDefault && style <= UIBarStyleBlackTranslucent) {
        _style = style;

        switch (style) {
            case UIBarStyleBlack:
                [self setBarTintColor:[UIColor blackColor]];
                break;
            case UIBarStyleBlackTranslucent:
                [self setBarTintColor:[UIColor blackColor]];
                [self setTranslucent:YES];
                break;
            default:
                [self setBarTintColor:[UIColor whiteColor]];
                break;
        }
    } else {
        TraceError(TAG, L"Failed to recognize UIBarStyle: %d", style);
    }
}

/**
 @Status Interoperable
*/
- (UIBarStyle)barStyle {
    return _style;
}

/**
 @Status Caveat
 @Notes UIBarButtonItem not currently supported. When this changes, UIBarButtonItem will replace WXCAppBarButton usage.
*/
- (void)setTintColor:(id)color {
    _tintColor = color;

    for (id button in _items) {
        if ([button isKindOfClass:[WXCAppBarButton class]]) {
            [button setForeground:[WUXMSolidColorBrush makeInstanceWithColor:[XamlUtilities convertUIColorToWUColor:color]]];
        } else if ([button isKindOfClass:[UIBarButtonItem class]]) {
            // TODO: Task 5243737
        }
    }
}

/**
 @Status Interoperable
*/
- (UIColor*)tintColor {
    return _tintColor;
}

/**
 @Status Interoperable
*/
- (void)setBarTintColor:(UIColor*)color {
    _barTintColor = color;

    [_xamlCommandBar setBackground:[WUXMSolidColorBrush makeInstanceWithColor:[XamlUtilities convertUIColorToWUColor:color]]];
}

/**
 @Status Interoperable
*/
- (UIColor*)barTintColor {
    return _barTintColor;
}

/**
 @Status Caveat
 @Notes Not be fully implemented. Setting opacity on the command bar will also change the opacity of the child views.
*/
- (void)setTranslucent:(BOOL)translucent {
    _translucent = translucent;

    if (translucent) {
        _xamlCommandBar.opacity = 0.5;
    } else {
        _xamlCommandBar.opacity = 1;
    }
}

/**
 @Status Caveat
 @Notes isTranslucent should return YES if any part of the background image has an alpha of less than 1. 
*/
- (BOOL)isTranslucent {
    return _translucent;
}

/**
 @Status Stub
*/
- (UIImage*)backgroundImageForToolbarPosition:(UIBarPosition)topOrBottom barMetrics:(UIBarMetrics)barMetrics {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setBackgroundImage:(UIImage*)image forToolbarPosition:(UIToolbarPosition)position barMetrics:(UIBarMetrics)metrics {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UIImage*)shadowImageForToolbarPosition:(UIBarPosition)topOrBottom {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setShadowImage:(UIImage*)shadowImage forToolbarPosition:(UIBarPosition)topOrBottom {
    UNIMPLEMENTED();
}

- (void)dealloc {
    [_xamlCommandBar removeLoadedEvent:_commandBarLoadedEvent];
}

@end
