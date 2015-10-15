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
#include "UIAppearanceSetter.h"

@implementation UINavigationItem : NSObject {
    idretaintype(NSString) _title;
    idretaintype(UIView) _titleView;
    idretaintype(NSString) _prompt;
    idretaintype(UIBarButtonItem) _rightBarButtonItem, _leftBarButtonItem, _backBarButtonItem;
    idretaintype(NSArray) _rightBarButtonItems, _leftBarButtonItems;
    idretaintype(UIBarButtonItem) _rightSegmentedControlItem;
    BOOL _hidesBackButton;
    id _delegate;
}

- (UINavigationItem*)initWithTitle:(NSString*)title {
    _title.attach([title copy]);

    _leftBarButtonItems = [NSMutableArray array];
    _rightBarButtonItems = [NSMutableArray array];

    return self;
}

- (NSObject*)initWithCoder:(NSCoder*)coder {
    id name = [coder decodeObjectForKey:@"UITitle"];
    id titleView = [coder decodeObjectForKey:@"UITitleView"];

    _leftBarButtonItem = [coder decodeObjectForKey:@"UILeftBarButtonItem"];
    _rightBarButtonItem = [coder decodeObjectForKey:@"UIRightBarButtonItem"];

    _leftBarButtonItems = [NSMutableArray array];
    if (_leftBarButtonItem != nil) {
        [_leftBarButtonItems addObject:(id)_leftBarButtonItem];
    }
    _rightBarButtonItems = [NSMutableArray array];
    if (_rightBarButtonItem != nil) {
        [_rightBarButtonItems addObject:(id)_rightBarButtonItem];
    }

    [self initWithTitle:name];

    if (titleView != nil) {
        [self setTitleView:titleView];
    }

    return self;
}

- (void)setTitle:(NSString*)title {
    _title.attach([title copy]);
    [_delegate navigationItemChanged:self];
}

- (void)setTitleView:(UIView*)view {
    _titleView = view;
    [_delegate navigationItemChanged:self];
}

- (UIView*)titleView {
    return _titleView;
}

- (void)setPrompt:(NSString*)prompt {
    _prompt = prompt;
}

- (void)setRightBarButtonItem:(UIBarButtonItem*)rightBarItem {
    [self setRightBarButtonItem:rightBarItem animated:FALSE];
}

- (void)setRightBarButtonItem:(UIBarButtonItem*)rightBarItem animated:(BOOL)animated {
    _rightBarButtonItem = rightBarItem;
    if ([_rightBarButtonItems count] > 0) {
        if (rightBarItem != nil) {
            [_rightBarButtonItems replaceObjectAtIndex:0 withObject:rightBarItem];
        } else {
            [_rightBarButtonItems removeObjectAtIndex:0];
        }
    } else {
        if (rightBarItem != nil) {
            [_rightBarButtonItems addObject:rightBarItem];
        }
    }

    [_delegate navigationItemChanged:self];
}

- (void)setRightBarButtonItems:(NSArray*)rightBarItems animated:(BOOL)animated {
    _rightBarButtonItems = rightBarItems;
    if ([rightBarItems count] > 0) {
        _rightBarButtonItem = [rightBarItems objectAtIndex:0];
    } else {
        _rightBarButtonItem = nil;
    }

    [_delegate navigationItemChanged:self];
}

- (void)setRightBarButtonItems:(NSArray*)rightBarItems {
    [self setRightBarButtonItems:rightBarItems animated:FALSE];
}

- (UIBarButtonItem*)rightBarButtonItem {
    return _rightBarButtonItem;
}

- (NSArray*)rightBarButtonItems {
    return _rightBarButtonItems;
}

- (UIBarButtonItem*)_rightBarButtonOrControl {
    if ([_rightBarButtonItems count] > 1) {
        if (_rightSegmentedControlItem == nil) {
            float totalWidth = 0.0f;
            float topHeight = 0.0f;
            id reverseItems = [NSMutableArray array];
            for (UIBarButtonItem* curItem in [_rightBarButtonItems reverseObjectEnumerator]) {
                CGSize buttonSize = { 0.0f, 0.0f };
                [curItem _idealSize:&buttonSize];
                totalWidth += buttonSize.width;
                if (buttonSize.height > topHeight) {
                    topHeight = buttonSize.height;
                }
                [reverseItems addObject:curItem];
            }

            CGRect frame = CGRectMake(0.0f, 0.0f, totalWidth, topHeight);
            id toolbarControl = [[UIToolbar alloc] initWithFrame:frame];
            [toolbarControl setItems:(id)reverseItems];
            _rightSegmentedControlItem.attach([[UIBarButtonItem alloc] initWithCustomView:toolbarControl]);
            [toolbarControl release];
        }

        return _rightSegmentedControlItem;
    } else {
        return [self rightBarButtonItem];
    }
    return nil;
}

- (void)setLeftBarButtonItems:(NSArray*)leftBarItems {
    [self setLeftBarButtonItems:leftBarItems animated:FALSE];
}

- (void)setLeftBarButtonItem:(UIBarButtonItem*)leftBarItem {
    _leftBarButtonItem = leftBarItem;
    if ([_leftBarButtonItems count] > 0) {
        if (leftBarItem != nil) {
            [_leftBarButtonItems replaceObjectAtIndex:0 withObject:leftBarItem];
        } else {
            [_leftBarButtonItems removeObjectAtIndex:0];
        }
    } else {
        if (leftBarItem != nil) {
            [_leftBarButtonItems addObject:leftBarItem];
        }
    }
    [_delegate navigationItemChanged:self];
}

- (void)setLeftBarButtonItem:(NSArray*)leftBarItems animated:(BOOL)animated {
    _leftBarButtonItems = leftBarItems;
    if ([leftBarItems count] > 0) {
        _leftBarButtonItem = [leftBarItems objectAtIndex:0];
    } else {
        _leftBarButtonItem = nil;
    }

    [_delegate navigationItemChanged:self];
}

- (void)setBackBarButtonItem:(UIBarButtonItem*)backBarItem {
    _backBarButtonItem = backBarItem;
    [_delegate navigationItemChanged:self];
}

- (UIBarButtonItem*)backBarButtonItem {
    return _backBarButtonItem;
}

- (UIBarButtonItem*)leftBarButtonItem {
    return _leftBarButtonItem;
}

- (NSArray*)leftBarButtonItems {
    return _leftBarButtonItems;
}

- (NSString*)title {
    return _title;
}

- (NSString*)prompt {
    return _prompt;
}

- (void)setHidesBackButton:(BOOL)hide {
    [self setHidesBackButton:hide animated:FALSE];
}

- (void)setHidesBackButton:(BOOL)hide animated:(BOOL)animate {
    _hidesBackButton = hide;
    [_delegate navigationItemChanged:self];
}

- (BOOL)hidesBackButton {
    return _hidesBackButton;
}

- (void)setDelegate:(id)delegate {
    _delegate = delegate;
}

- (void)dealloc {
    _title = nil;
    _titleView = nil;
    _prompt = nil;
    _rightBarButtonItem = nil;
    _leftBarButtonItem = nil;
    _backBarButtonItem = nil;
    _rightBarButtonItems = nil;
    _rightSegmentedControlItem = nil;
    _leftBarButtonItems = nil;

    [super dealloc];
}

@end
