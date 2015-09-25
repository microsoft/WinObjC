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
#include "UIKit/UITabBarController.h"
#include "UIKit/UIViewController.h"
#include "UIKit/UIApplication.h"
#include "Foundation/NSString.h"
#include "Foundation/NSMutableArray.h"
#include "UIKit/UINavigationController.h"

#include "UITabPane.h"

extern float statusBarHeight;

@implementation UITabPane : UIView

- (instancetype)initWithFrame:(CGRect)frame {
    UITabPane* ret = [super initWithFrame:frame];
    _containerView = [[UIView alloc] initWithFrame:frame];
    [self addSubview:_containerView];
    [_containerView setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
    [_containerView release];

    return ret;
}

- (void)layoutSubviews {
    assert(_parent != nil);

    if (_parent->_selectedIndex == -1) {
        [_parent setSelectedIndex:0];
    }
    bool isNotifying = false;

    if (_newController != nil) {
        if (_newController != _curController) {
            _oldController = _curController;
            _curController = _newController;
            _newController = nil;

            isNotifying = true;

            if (_oldController != nil) {
                id oldControllerView;

                //  Remove the current controller we're displaying
                [_oldController notifyViewWillDisappear:FALSE];

                oldControllerView = [_oldController view];
                //[oldControllerView setHidden:TRUE];
                [oldControllerView removeFromSuperview];
            }

            isNotifying = true;
        } else {
            _newController = nil;
        }
    }

    CGRect bounds;
    bounds = [self bounds];

    if (![[UIApplication sharedApplication] isStatusBarHidden] && ![_curController wantsFullScreenLayout]) {
        bounds.origin.y = statusBarHeight;
        bounds.size.height -= statusBarHeight;
    } else {
        bounds.origin.y = 0;
    }

    _curControllerView = [_curController view];

    CGRect contentBounds = bounds;

    if (!_parent->_hideTabBar) {
        contentBounds.size.height -= 50.0f;
    }

    if (isNotifying || _parent->_layoutForRotation) {
        _parent->_layoutForRotation = false;
        [_containerView setFrame:contentBounds];
        contentBounds.origin.x = 0;
        contentBounds.origin.y = 0;
        [_curControllerView setFrame:contentBounds];
    }

    if (_parent->_tabBarChanged) {
        _parent->_tabBarChanged = false;
        if (!_parent->_hideTabBar) {
            [_tabBar setHidden:FALSE];
            if (_tabBar != nil) {
                CGRect size;

                size.origin.x = 0;
                size.origin.y = bounds.origin.y + bounds.size.height - 50.0f;
                size.size.width = bounds.size.width;
                size.size.height = 50.0f;

                [_tabBar setFrame:size];
            }
        } else {
            [_tabBar setHidden:TRUE];
        }
    }

    if (isNotifying) {
        if ([_curControllerView superview] != self) {
            [_containerView addSubview:_curControllerView];
        }
        [_curController notifyViewWillAppear:FALSE];

        [_curControllerView setHidden:FALSE];
        [_curControllerView setClipsToBounds:1];
        // if ( _tabBar != nil ) [self bringSubviewToFront:(id) _tabBar];

        if (_oldController != nil) {
            [_oldController notifyViewDidDisappear:FALSE];
        }
        [_curController notifyViewDidAppear:FALSE];
    }

    [super layoutSubviews];
}

@end
