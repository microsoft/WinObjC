//******************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
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

#import <UIKit/UIScreen.h>
#import "_UIPopupViewController.h"
#import <UWP/WindowsUIXamlControlsPrimitives.h>

static const wchar_t* TAG = L"_UIPopupViewController";

@implementation _UIPopupViewController {
    WUXCPPopup* _popup;
    EventRegistrationToken _layoutUpdated;
}

- (void)loadView {
    UIView* view = [[UIView alloc] init];
    _popup = [WUXCPPopup make];
    [view setXamlElement:_popup];

    _UIPopupViewController __weak* weakSelf = self;

    _layoutUpdated = [_popup addLayoutUpdatedEvent:^(RTObject* sender, RTObject* args) {
        _UIPopupViewController* strongSelf = weakSelf;

        if (strongSelf == nil) {
            return;
        }

        WUXCPPopup* popup = strongSelf->_popup;
        id child = popup.child;

        if (child != nil) {
        WXFrameworkElement* child2 = rt_dynamic_cast<WXFrameworkElement>(child);
        /*
        if (![child isKindOfClass:[WXFrameworkElement class]]) {
            // Don't know how to lay this thing out
            return;
        }
        */

        double childWidth = [static_cast<WXFrameworkElement*>(child2) width];
        double childHeight = [static_cast<WXFrameworkElement*>(child2) height];

        CGRect appFrame = [[UIScreen mainScreen] bounds];
        popup.horizontalOffset = max(0, (appFrame.size.width - childWidth) / 2.0);
        popup.verticalOffset = max(0, (appFrame.size.height - childHeight) / 2.0); }
    }];

    self.view = view;
}

- (void)dealloc {
    [_popup removeLayoutUpdatedEvent:_layoutUpdated];
}

- (void)presentViewController:(UIViewController*)viewControllerToPresent animated:(BOOL)flag completion:(void (^)())completion {
    _popup.child = viewControllerToPresent.view.xamlElement;
    _popup.isOpen = YES;
    [super presentViewController:viewControllerToPresent animated:flag completion:completion];
}

- (void)dismissViewControllerAnimated:(BOOL)flag completion:(void (^)())completion {
    _popup.isOpen = NO;
    [super dismissViewControllerAnimated:flag completion:completion];
}

@end
