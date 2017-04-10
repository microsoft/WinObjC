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
#import "CppWinRTHelpers.h"

#include "COMIncludes.h"
#import <winrt/Windows.UI.Xaml.Controls.Primitives.h>
#include "COMIncludes_End.h"

using namespace winrt::Windows::UI::Xaml;
using winrt::Windows::UI::Xaml::Controls::Primitives::Popup;
namespace WF = winrt::Windows::Foundation;

static const wchar_t* TAG = L"_UIPopupViewController";

@implementation _UIPopupViewController {
    TrivialDefaultConstructor<Popup> _popup;
    winrt::event_token _layoutUpdated;
}

- (void)loadView {
    _popup = Popup();
    _popup.Child(objcwinrt::from_insp<FrameworkElement>(XamlCompositor::GetRootElement()));

    __weak _UIPopupViewController* weakSelf = self;

    // Keep the popup's contents sized to fit the window
    _layoutUpdated = _popup.LayoutUpdated(objcwinrt::callback([weakSelf] (const WF::IInspectable& sender, const WF::IInspectable& e) {
        _UIPopupViewController* strongSelf = weakSelf;

        if (strongSelf == nil) {
            return;
        }

        Popup popup = strongSelf->_popup;
        UIElement popupChild = popup.Child();

        if (popupChild) {
            FrameworkElement child = popupChild.as<FrameworkElement>();

            winrt::Windows::Foundation::Rect appFrame = Window::Current().Bounds();

            child.Width(appFrame.Width);
            child.Height(appFrame.Height);
        }
    }));
}

- (void)dealloc {
    _popup.LayoutUpdated(_layoutUpdated);
}

- (void)presentViewController:(UIViewController*)viewControllerToPresent animated:(BOOL)flag completion:(void (^)())completion {
    [super presentViewController:viewControllerToPresent animated:flag completion:^{
        _popup.IsOpen(true);

        if (completion != nil) {
            completion();
        }
    }];
}

- (void)dismissViewControllerAnimated:(BOOL)flag completion:(void (^)())completion {
    [super dismissViewControllerAnimated:flag completion:^{
        _popup.IsOpen(false);

        if (completion != nil) {
            completion();
        }
    }];
}

@end
