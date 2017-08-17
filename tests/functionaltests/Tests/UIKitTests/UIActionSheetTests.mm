//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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
#include <TestFramework.h>
#import <UIKit/UIKit.h>
#import "UIViewInternal.h"

#include <COMIncludes.h>
#import <WRLHelpers.h>
#import <ErrorHandling.h>
#import <RawBuffer.h>
#import <wrl/client.h>
#import <wrl/implements.h>
#import <wrl/async.h>
#import <wrl/wrappers/corewrappers.h>
#import <windows.foundation.h>
#import <winrt/Windows.UI.Xaml.Controls.h>
#include <COMIncludes_end.h>

#include "ObjCXamlControls.h"

using namespace winrt::Windows::UI::Xaml;

class UIKitActionSheetTests {
public:
    BEGIN_TEST_CLASS(UIKitActionSheetTests)
    // TODO #2785: Investigate failure in VSTS runs.
    TEST_CLASS_PROPERTY(L"Ignore", L"true")
    END_TEST_CLASS()

    TEST_CLASS_SETUP(UIKitTestsSetup) {
        return FunctionalTestSetupUIApplication();
    }

    TEST_CLASS_CLEANUP(UIKitTestsCleanup) {
        return FunctionalTestCleanupUIApplication();
    }

    TEST_METHOD(CreateXamlElement) {
        FrameworkHelper::RunOnUIThread([]() {
            // TODO: Switch to UIKit.Xaml projections when they're available.
            Microsoft::WRL::ComPtr<IInspectable> xamlElement;
            XamlCreateContentDialog(&xamlElement);
            ASSERT_TRUE(xamlElement);
        });
    }

    TEST_METHOD(GetXamlElement) {
        FrameworkHelper::RunOnUIThread([]() {
            UIActionSheet* actionSheet = [[[UIActionSheet alloc] init] autorelease];
            FrameworkElement backingElement = [actionSheet _winrtXamlElement];
            ASSERT_TRUE(backingElement);

            ASSERT_TRUE(backingElement.as<FrameworkElement>());
        });
    }

    TEST_METHOD(NilParameters) {
        FrameworkHelper::RunOnUIThread([]() {
            UIActionSheet* actionSheet = [[[UIActionSheet alloc] initWithTitle:nil
                                                                      delegate:nil
                                                             cancelButtonTitle:nil
                                                        destructiveButtonTitle:nil
                                                             otherButtonTitles:nil] autorelease];
            FrameworkElement backingElement = [actionSheet _winrtXamlElement];
            ASSERT_TRUE(backingElement);

            // Check that cancel button index, destructive button index, other button index are correct
            NSInteger numButtons = [actionSheet numberOfButtons];
            ASSERT_TRUE(numButtons == 0);

            NSInteger cancelIndex = [actionSheet cancelButtonIndex];
            ASSERT_TRUE(cancelIndex == -1);

            NSInteger destructiveIndex = [actionSheet destructiveButtonIndex];
            ASSERT_TRUE(cancelIndex == -1);

            NSInteger otherIndex = [actionSheet firstOtherButtonIndex];
            ASSERT_TRUE(otherIndex == -1);
        });
    }

    TEST_METHOD(Show) {
        FrameworkHelper::RunOnUIThread([]() {
            StrongId<UIActionSheet> actionSheet;

            actionSheet.attach([[UIActionSheet alloc] initWithTitle:@"Title"
                                                           delegate:nil
                                                  cancelButtonTitle:@"Cancel"
                                             destructiveButtonTitle:@"OK"
                                                  otherButtonTitles:nil]);

            UIView* mainView = UIApplication.sharedApplication.keyWindow.rootViewController.view;
            [actionSheet showInView:mainView];
        });
    }
};
