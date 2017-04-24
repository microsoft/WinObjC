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
#import <UIKit/UIActivityIndicatorView.h>
#import "UIViewInternal.h"
#import "FunctionalTestHelpers.h"
#import "UXTestHelpers.h"
#include "CppWinRTHelpers.h"

#import "UIKitControls/UIActivityIndicatorViewController.h"

#include <COMIncludes.h>
#import <WRLHelpers.h>
#import <ErrorHandling.h>
#import <RawBuffer.h>
#import <wrl/client.h>
#import <wrl/implements.h>
#import <wrl/async.h>
#import <wrl/wrappers/corewrappers.h>
#import <windows.foundation.h>
#import <winrt/Windows.UI.Xaml.h>
#import <winrt/Windows.UI.Xaml.Controls.h>
#include <COMIncludes_end.h>

#include "ObjCXamlControls.h"

using namespace UXTestAPI;
using namespace winrt::Windows::UI::Xaml;

class UIKitActivityIndicatorTests {
private:
    static const int expectedNormalSize = 20;
    static const int expectedLargeSize = 37;

public:
    BEGIN_TEST_CLASS(UIKitActivityIndicatorTests)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(UIKitTestsSetup) {
        return FunctionalTestSetupUIApplication();
    }

    TEST_CLASS_CLEANUP(UIKitTestsCleanup) {
        return FunctionalTestCleanupUIApplication();
    }

    TEST_METHOD(CreateXamlElement) {
        FrameworkHelper::RunOnUIThread([]() {
            Microsoft::WRL::ComPtr<IInspectable> xamlElement;
            XamlCreateProgressRing(&xamlElement);
            ASSERT_TRUE(xamlElement);
        });
    }

    TEST_METHOD(GetXamlElement) {
        FrameworkHelper::RunOnUIThread([]() {
            UIView* view = [[[UIActivityIndicatorView alloc] init] autorelease];
            FrameworkElement backingElement = [view _winrtXamlElement];
            ASSERT_TRUE(backingElement);
        });
    }

    TEST_METHOD(UIActivityIndicatorView_GetInternalControl) {
        StrongId<UIActivityIndicatorViewController> activityIndicatorVC;
        activityIndicatorVC.attach([[UIActivityIndicatorViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(activityIndicatorVC);
        UIActivityIndicatorView* indicator = [activityIndicatorVC indicator];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [indicator _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressRing(objcwinrt::to_insp(xamlElement)));
            auto progressRing = objcwinrt::from_insp<Controls::ProgressRing>(inspectable);
            ASSERT_TRUE(progressRing);
        });
    }

    TEST_METHOD(UIActivityIndicatorView_VerifyInitialState) {
        StrongId<UIActivityIndicatorViewController> activityIndicatorVC;
        activityIndicatorVC.attach([[UIActivityIndicatorViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(activityIndicatorVC, 5);
        UIActivityIndicatorView* indicator = [activityIndicatorVC indicator];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [indicator _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressRing(objcwinrt::to_insp(xamlElement)));
            auto progressRing = objcwinrt::from_insp<Controls::ProgressRing>(inspectable);
            ASSERT_TRUE(progressRing);

            // Should not be animating initially
            ASSERT_FALSE(indicator.isAnimating);
            ASSERT_FALSE(progressRing.IsActive());
            // Should be visible initially
            EXPECT_EQ(winrt::Windows::UI::Xaml::Visibility::Visible, progressRing.Visibility());
            ASSERT_FALSE(indicator.hidden);
            EXPECT_EQ(0.0, xamlElement.Opacity());
            EXPECT_EQ(0.0, indicator.alpha);
            ASSERT_TRUE(indicator.hidesWhenStopped);

            // Should start in the white style
            EXPECT_EQ(UIActivityIndicatorViewStyleWhite, indicator.activityIndicatorViewStyle);

            // Color should match initial style
            auto solidForegroundBrush = progressRing.Foreground().as<Media::SolidColorBrush>();
            UIColor* expectedForegroundColor = [UIColor whiteColor];
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidForegroundBrush, expectedForegroundColor));

            // Size should match initial style
            EXPECT_EQ(expectedNormalSize, progressRing.Height());
            EXPECT_EQ(expectedNormalSize, progressRing.Width());

            // Initial element size is set in the controller
            EXPECT_EQ(50, xamlElement.Height());
            EXPECT_EQ(50, xamlElement.Width());

            // The ProgressRing should always be centered in the element
            ASSERT_TRUE(isCenteredInParent(progressRing, xamlElement));
        });
    }

    TEST_METHOD(UIActivityIndicatorView_StartAnimating) {
        StrongId<UIActivityIndicatorViewController> activityIndicatorVC;
        activityIndicatorVC.attach([[UIActivityIndicatorViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(activityIndicatorVC, 2);
        UIActivityIndicatorView* indicator = [activityIndicatorVC indicator];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [indicator _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressRing(objcwinrt::to_insp(xamlElement)));
            auto progressRing = objcwinrt::from_insp<Controls::ProgressRing>(inspectable);
            ASSERT_TRUE(progressRing);

            [indicator startAnimating];
            ASSERT_TRUE(indicator.isAnimating);

            ASSERT_TRUE(progressRing.IsActive());
            EXPECT_EQ(winrt::Windows::UI::Xaml::Visibility::Visible, progressRing.Visibility());
            ASSERT_FALSE(indicator.hidden);
            EXPECT_EQ(1.0, xamlElement.Opacity());
            EXPECT_EQ(1.0, indicator.alpha);
        });
    }

    TEST_METHOD(UIActivityIndicatorView_StopAnimating) {
        StrongId<UIActivityIndicatorViewController> activityIndicatorVC;
        activityIndicatorVC.attach([[UIActivityIndicatorViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(activityIndicatorVC, 2);
        UIActivityIndicatorView* indicator = [activityIndicatorVC indicator];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [indicator _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressRing(objcwinrt::to_insp(xamlElement)));
            auto progressRing = objcwinrt::from_insp<Controls::ProgressRing>(inspectable);

            [indicator startAnimating];
            ASSERT_TRUE(indicator.isAnimating);
            ASSERT_TRUE(progressRing.IsActive());
            EXPECT_EQ(winrt::Windows::UI::Xaml::Visibility::Visible, xamlElement.Visibility());

            [indicator stopAnimating];
            ASSERT_FALSE(indicator.isAnimating);
            ASSERT_FALSE(progressRing.IsActive());
            // Element should be still "Visible" after stopping animation, to ensure space is preserved in the layout.
            EXPECT_EQ(winrt::Windows::UI::Xaml::Visibility::Visible, xamlElement.Visibility());
            ASSERT_FALSE(indicator.hidden);
            EXPECT_EQ(0.0, xamlElement.Opacity());
            EXPECT_EQ(0.0, indicator.alpha);
        });
    }

    TEST_METHOD(UIActivityIndicatorView_HidesWhenStopped_BeforeStartAnimation) {
        StrongId<UIActivityIndicatorViewController> activityIndicatorVC;
        activityIndicatorVC.attach([[UIActivityIndicatorViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(activityIndicatorVC, 2);
        UIActivityIndicatorView* indicator = [activityIndicatorVC indicator];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [indicator _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressRing(objcwinrt::to_insp(xamlElement)));
            auto progressRing = objcwinrt::from_insp<Controls::ProgressRing>(inspectable);

            [indicator setHidesWhenStopped:false];
            ASSERT_FALSE(indicator.hidesWhenStopped);
            EXPECT_EQ(1.0, xamlElement.Opacity());
            EXPECT_EQ(1.0, indicator.alpha);
            // Visibility should not be altered
            EXPECT_EQ(xamlElement.Visibility(), winrt::Windows::UI::Xaml::Visibility::Visible);
            ASSERT_FALSE(indicator.hidden);

            [indicator startAnimating];
            ASSERT_TRUE(indicator.isAnimating);
            ASSERT_TRUE(progressRing.IsActive());
            // Opacity and visibility should not be altered
            EXPECT_EQ(1.0, xamlElement.Opacity());
            EXPECT_EQ(1.0, indicator.alpha);
            EXPECT_EQ(winrt::Windows::UI::Xaml::Visibility::Visible, xamlElement.Visibility());
            ASSERT_FALSE(indicator.hidden);

            [indicator stopAnimating];
            ASSERT_FALSE(indicator.isAnimating);
            ASSERT_FALSE(progressRing.IsActive());

            // Opacity and visibility should not be altered
            EXPECT_EQ(1.0, xamlElement.Opacity());
            EXPECT_EQ(1.0, indicator.alpha);
            EXPECT_EQ(winrt::Windows::UI::Xaml::Visibility::Visible, xamlElement.Visibility());
            ASSERT_FALSE(indicator.hidden);
        });
    }

    TEST_METHOD(UIActivityIndicatorView_HidesWhenStopped_AfterStartAnimation) {
        StrongId<UIActivityIndicatorViewController> activityIndicatorVC;
        activityIndicatorVC.attach([[UIActivityIndicatorViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(activityIndicatorVC, 2);
        UIActivityIndicatorView* indicator = [activityIndicatorVC indicator];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [indicator _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressRing(objcwinrt::to_insp(xamlElement)));
            auto progressRing = objcwinrt::from_insp<Controls::ProgressRing>(inspectable);

            [indicator startAnimating];
            ASSERT_TRUE(indicator.isAnimating);
            ASSERT_TRUE(progressRing.IsActive());
            EXPECT_EQ(1.0, xamlElement.Opacity());
            EXPECT_EQ(1.0, indicator.alpha);
            // Visibility should not be altered
            EXPECT_EQ(winrt::Windows::UI::Xaml::Visibility::Visible, xamlElement.Visibility());
            ASSERT_FALSE(indicator.hidden);

            [indicator setHidesWhenStopped:false];
            ASSERT_FALSE(indicator.hidesWhenStopped);
            EXPECT_EQ(1.0, xamlElement.Opacity());
            EXPECT_EQ(1.0, indicator.alpha);
            // Visibility should not be altered
            EXPECT_EQ(winrt::Windows::UI::Xaml::Visibility::Visible, xamlElement.Visibility());
            ASSERT_FALSE(indicator.hidden);

            [indicator stopAnimating];
            ASSERT_FALSE(indicator.isAnimating);
            ASSERT_FALSE(progressRing.IsActive());

            // Opacity and visibility should not be altered
            EXPECT_EQ(1.0, xamlElement.Opacity());
            EXPECT_EQ(1.0, indicator.alpha);
            EXPECT_EQ(winrt::Windows::UI::Xaml::Visibility::Visible, xamlElement.Visibility());
            ASSERT_FALSE(indicator.hidden);
        });
    }

    TEST_METHOD(UIActivityIndicatorView_HidesWhenStopped_AfterStopAnimation) {
        StrongId<UIActivityIndicatorViewController> activityIndicatorVC;
        activityIndicatorVC.attach([[UIActivityIndicatorViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(activityIndicatorVC, 2);
        UIActivityIndicatorView* indicator = [activityIndicatorVC indicator];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [indicator _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressRing(objcwinrt::to_insp(xamlElement)));
            auto progressRing = objcwinrt::from_insp<Controls::ProgressRing>(inspectable);

            [indicator startAnimating];
            ASSERT_TRUE(indicator.isAnimating);
            ASSERT_TRUE(progressRing.IsActive());
            EXPECT_EQ(1.0, xamlElement.Opacity());
            EXPECT_EQ(1.0, indicator.alpha);
            // Visibility should not be altered
            EXPECT_EQ(winrt::Windows::UI::Xaml::Visibility::Visible, xamlElement.Visibility());
            ASSERT_FALSE(indicator.hidden);

            [indicator stopAnimating];
            ASSERT_FALSE(indicator.isAnimating);
            ASSERT_FALSE(progressRing.IsActive());
            EXPECT_EQ(0.0, xamlElement.Opacity());
            EXPECT_EQ(0.0, indicator.alpha);
            // Visibility should not be altered
            EXPECT_EQ(winrt::Windows::UI::Xaml::Visibility::Visible, xamlElement.Visibility());
            ASSERT_FALSE(indicator.hidden);

            [indicator setHidesWhenStopped:false];
            ASSERT_FALSE(indicator.hidesWhenStopped);
            EXPECT_EQ(1.0, xamlElement.Opacity());
            EXPECT_EQ(1.0, indicator.alpha);
            // Visibility should not be altered
            EXPECT_EQ(winrt::Windows::UI::Xaml::Visibility::Visible, xamlElement.Visibility());
            ASSERT_FALSE(indicator.hidden);
        });
    }

    TEST_METHOD(UIActivityIndicatorView_SetGrayStyle) {
        StrongId<UIActivityIndicatorViewController> activityIndicatorVC;
        activityIndicatorVC.attach([[UIActivityIndicatorViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(activityIndicatorVC);
        UIActivityIndicatorView* indicator = [activityIndicatorVC indicator];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [indicator _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressRing(objcwinrt::to_insp(xamlElement)));
            auto progressRing = objcwinrt::from_insp<Controls::ProgressRing>(inspectable);

            // Change to gray style
            indicator.activityIndicatorViewStyle = UIActivityIndicatorViewStyleGray;
            EXPECT_EQ(UIActivityIndicatorViewStyleGray, indicator.activityIndicatorViewStyle);

            auto solidForegroundBrush = progressRing.Foreground().as<Media::SolidColorBrush>();
            UIColor* expectedForegroundColor = [UIColor colorWithWhite:0.0 alpha:0.45];
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidForegroundBrush, expectedForegroundColor));

            EXPECT_EQ(expectedNormalSize, progressRing.Height());
            EXPECT_EQ(expectedNormalSize, progressRing.Width());

            // Frame size should not change
            EXPECT_EQ(50, xamlElement.Height());
            EXPECT_EQ(50, xamlElement.Width());

            ASSERT_TRUE(isCenteredInParent(progressRing, xamlElement));
        });
    }

    TEST_METHOD(UIActivityIndicatorView_SetWhiteLargeStyle) {
        StrongId<UIActivityIndicatorViewController> activityIndicatorVC;
        activityIndicatorVC.attach([[UIActivityIndicatorViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(activityIndicatorVC);
        UIActivityIndicatorView* indicator = [activityIndicatorVC indicator];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [indicator _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressRing(objcwinrt::to_insp(xamlElement)));
            auto progressRing = objcwinrt::from_insp<Controls::ProgressRing>(inspectable);

            // Change to white large style
            indicator.activityIndicatorViewStyle = UIActivityIndicatorViewStyleWhiteLarge;
            EXPECT_EQ(UIActivityIndicatorViewStyleWhiteLarge, indicator.activityIndicatorViewStyle);

            auto solidForegroundBrush = progressRing.Foreground().as<Media::SolidColorBrush>();
            UIColor* expectedForegroundColor = [UIColor whiteColor];
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidForegroundBrush, expectedForegroundColor));

            EXPECT_EQ(expectedLargeSize, progressRing.Height());
            EXPECT_EQ(expectedLargeSize, progressRing.Width());

            // Frame size should not change
            EXPECT_EQ(50, xamlElement.Height());
            EXPECT_EQ(50, xamlElement.Width());

            ASSERT_TRUE(isCenteredInParent(progressRing, xamlElement));
        });
    }

    TEST_METHOD(UIActivityIndicatorView_ResizeLargeToNormal) {
        StrongId<UIActivityIndicatorViewController> activityIndicatorVC;
        activityIndicatorVC.attach([[UIActivityIndicatorViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(activityIndicatorVC);
        UIActivityIndicatorView* indicator = [activityIndicatorVC indicator];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [indicator _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressRing(objcwinrt::to_insp(xamlElement)));
            auto progressRing = objcwinrt::from_insp<Controls::ProgressRing>(inspectable);

            // Change to white large style
            indicator.activityIndicatorViewStyle = UIActivityIndicatorViewStyleWhiteLarge;
            EXPECT_EQ(UIActivityIndicatorViewStyleWhiteLarge, indicator.activityIndicatorViewStyle);

            EXPECT_EQ(expectedLargeSize, progressRing.Height());
            EXPECT_EQ(expectedLargeSize, progressRing.Width());
            // Frame size should not change
            EXPECT_EQ(50, xamlElement.Height());
            EXPECT_EQ(50, xamlElement.Width());

            // Change to back white style
            indicator.activityIndicatorViewStyle = UIActivityIndicatorViewStyleWhite;
            EXPECT_EQ(UIActivityIndicatorViewStyleWhite, indicator.activityIndicatorViewStyle);

            EXPECT_EQ(expectedNormalSize, progressRing.Height());
            EXPECT_EQ(expectedNormalSize, progressRing.Width());
            // Frame size should not change
            EXPECT_EQ(50, xamlElement.Height());
            EXPECT_EQ(50, xamlElement.Width());

            ASSERT_TRUE(isCenteredInParent(progressRing, xamlElement));
        });
    }

    TEST_METHOD(UIActivityIndicatorView_SetInvalidStyle) {
        StrongId<UIActivityIndicatorViewController> activityIndicatorVC;
        activityIndicatorVC.attach([[UIActivityIndicatorViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(activityIndicatorVC);
        UIActivityIndicatorView* indicator = [activityIndicatorVC indicator];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [indicator _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressRing(objcwinrt::to_insp(xamlElement)));
            auto progressRing = objcwinrt::from_insp<Controls::ProgressRing>(inspectable);

            // Change to an invalid style value
            indicator.activityIndicatorViewStyle = (UIActivityIndicatorViewStyle)3;
            EXPECT_EQ(UIActivityIndicatorViewStyleWhite, indicator.activityIndicatorViewStyle);

            auto solidForegroundBrush = progressRing.Foreground().as<Media::SolidColorBrush>();
            UIColor* expectedForegroundColor = [UIColor whiteColor];
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidForegroundBrush, expectedForegroundColor));

            EXPECT_EQ(expectedNormalSize, progressRing.Height());
            EXPECT_EQ(expectedNormalSize, progressRing.Width());
            // Frame size should not change
            EXPECT_EQ(50, xamlElement.Height());
            EXPECT_EQ(50, xamlElement.Width());

            ASSERT_TRUE(isCenteredInParent(progressRing, xamlElement));
        });
    }

    TEST_METHOD(UIActivityIndicatorView_ChangeFrameSize_Smaller) {
        StrongId<UIActivityIndicatorViewController> activityIndicatorVC;
        activityIndicatorVC.attach([[UIActivityIndicatorViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(activityIndicatorVC);
        UIActivityIndicatorView* indicator = [activityIndicatorVC indicator];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [indicator _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressRing(objcwinrt::to_insp(xamlElement)));
            auto progressRing = objcwinrt::from_insp<Controls::ProgressRing>(inspectable);

            // Attempt to shrink frame to be smaller than the ProgressRing
            [indicator setFrame:CGRectMake(indicator.frame.origin.x, indicator.frame.origin.y, 10, 10)];
            // Frame should not become smaller than the ProgressRing
            EXPECT_EQ(progressRing.Height(), xamlElement.Height());
            EXPECT_EQ(progressRing.Width(), xamlElement.Width());

            // ProgressRing size should not change
            EXPECT_EQ(expectedNormalSize, progressRing.Height());
            EXPECT_EQ(expectedNormalSize, progressRing.Width());

            ASSERT_TRUE(isCenteredInParent(progressRing, xamlElement));
        });
    }

    TEST_METHOD(UIActivityIndicatorView_ChangeFrameSize_Larger) {
        StrongId<UIActivityIndicatorViewController> activityIndicatorVC;
        activityIndicatorVC.attach([[UIActivityIndicatorViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(activityIndicatorVC);
        UIActivityIndicatorView* indicator = [activityIndicatorVC indicator];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [indicator _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressRing(objcwinrt::to_insp(xamlElement)));
            auto progressRing = objcwinrt::from_insp<Controls::ProgressRing>(inspectable);

            // Grow frame
            [indicator setFrame:CGRectMake(indicator.frame.origin.x, indicator.frame.origin.y, 100, 100)];
            EXPECT_EQ(100, xamlElement.Height());
            EXPECT_EQ(100, xamlElement.Width());

            // ProgressRing size should not change
            EXPECT_EQ(expectedNormalSize, progressRing.Height());
            EXPECT_EQ(expectedNormalSize, progressRing.Width());

            ASSERT_TRUE(isCenteredInParent(progressRing, xamlElement));
        });
    }

    TEST_METHOD(UIActivityIndicatorView_ExpandFrameToFitIndicator) {
        StrongId<UIActivityIndicatorViewController> activityIndicatorVC;
        activityIndicatorVC.attach([[UIActivityIndicatorViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(activityIndicatorVC);
        UIActivityIndicatorView* indicator = [activityIndicatorVC indicator];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [indicator _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressRing(objcwinrt::to_insp(xamlElement)));
            auto progressRing = objcwinrt::from_insp<Controls::ProgressRing>(inspectable);

            // Shrink frame to be smaller than the ProgressRing
            [indicator setFrame:CGRectMake(indicator.frame.origin.x, indicator.frame.origin.y, 10, 10)];

            // Change to gray style
            indicator.activityIndicatorViewStyle = UIActivityIndicatorViewStyleGray;
            EXPECT_EQ(UIActivityIndicatorViewStyleGray, indicator.activityIndicatorViewStyle);

            EXPECT_EQ(expectedNormalSize, progressRing.Height());
            EXPECT_EQ(expectedNormalSize, progressRing.Width());

            // Frame should be expanded to fit ProgressRing
            EXPECT_EQ(expectedNormalSize, xamlElement.Height());
            EXPECT_EQ(expectedNormalSize, xamlElement.Width());

            ASSERT_TRUE(isCenteredInParent(progressRing, xamlElement));
        });
    }

    TEST_METHOD(UIActivityIndicatorView_SetColor) {
        StrongId<UIActivityIndicatorViewController> activityIndicatorVC;
        activityIndicatorVC.attach([[UIActivityIndicatorViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(activityIndicatorVC);
        UIActivityIndicatorView* indicator = [activityIndicatorVC indicator];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [indicator _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressRing(objcwinrt::to_insp(xamlElement)));
            auto progressRing = objcwinrt::from_insp<Controls::ProgressRing>(inspectable);

            EXPECT_EQ(UIActivityIndicatorViewStyleWhite, indicator.activityIndicatorViewStyle);

            UIColor* expectedForegroundColor = [UIColor blueColor];
            indicator.color = expectedForegroundColor;
            EXPECT_EQ(expectedForegroundColor, indicator.color);

            // Indicator style should not change
            EXPECT_EQ(UIActivityIndicatorViewStyleWhite, indicator.activityIndicatorViewStyle);

            auto solidForegroundBrush = progressRing.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidForegroundBrush, expectedForegroundColor));
        });
    }

    BOOL isCenteredInParent(FrameworkElement element, FrameworkElement parent) {
        auto relativeOrigin = element.TransformToVisual(parent).TransformPoint({ 0, 0 });
        Point elementCenter = { relativeOrigin.X + element.ActualWidth() / 2, relativeOrigin.Y + element.ActualHeight() / 2 };
        Point parentCenter = { parent.ActualWidth() / 2, parent.ActualHeight() / 2 };
        return elementCenter.X == parentCenter.X && elementCenter.Y == parentCenter.Y;
    }
};
