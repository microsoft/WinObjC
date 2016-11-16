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

#import "UIApplicationInternal.h"
#import "StarboardXaml/XamlCompositor.h"
#import "_UIPopupViewController.h"
#import <UWP/WindowsUIXamlControlsPrimitives.h>

static const wchar_t* TAG = L"_UIPopupViewController";

@implementation _UIPopupViewController {
    WUXCPPopup* _popup;
    EventRegistrationToken _layoutUpdated;
}

- (void)loadView {
    _popup = [WUXCPPopup make];
    _popup.child = [WXFrameworkElement createWith:XamlCompositor::GetRootElement().Get()];

    __weak _UIPopupViewController* weakSelf = self;

    // Keep the popup's contents sized to fit the window
    _layoutUpdated = [_popup addLayoutUpdatedEvent:^(RTObject* sender, RTObject* args) {
        _UIPopupViewController* strongSelf = weakSelf;

        if (strongSelf == nil) {
            return;
        }

        WUXCPPopup* popup = strongSelf->_popup;
        WXUIElement* popupChild = popup.child;

        if (popupChild != nil) {
            WXFrameworkElement* child = rt_dynamic_cast<WXFrameworkElement>(popupChild);

            WFRect* appFrame = [[WXWindow current] bounds];

            child.width = appFrame.width;
            child.height = appFrame.height;
        }
    }];
}

- (void)dealloc {
    [_popup removeLayoutUpdatedEvent:_layoutUpdated];
}

- (void)presentViewController:(UIViewController*)viewControllerToPresent animated:(BOOL)flag completion:(void (^)())completion {
    [super presentViewController:viewControllerToPresent animated:flag completion:^{
        _popup.isOpen = YES;

        if (completion != nil) {
            completion();
        }
    }];
}

- (void)dismissViewControllerAnimated:(BOOL)flag completion:(void (^)())completion {
    [super dismissViewControllerAnimated:flag completion:^{
        _popup.isOpen = NO;

        if (completion != nil) {
            completion();
        }
    }];
}

@end
