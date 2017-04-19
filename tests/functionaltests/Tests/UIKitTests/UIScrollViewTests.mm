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
#import <UIKit/UIScrollView.h>

#include "ObjCXamlControls.h"
#import "UIViewInternal.h"

#import "FunctionalTestHelpers.h"
#import "UXTestHelpers.h"
#import "CppWinRTHelpers.h"
#import "UIKitControls/UIScrollViewController.h"
#import "CoreGraphics/CGGeometry.h"

#include "COMIncludes.h"
#import <winrt/Windows.UI.Xaml.Controls.h>
#import <winrt/Windows.UI.Xaml.h>
#import <winrt/Windows.Foundation.h>
#include "COMIncludes_End.h"

using namespace winrt::Windows::UI::Xaml;
namespace WF = winrt::Windows::Foundation;

class UIScrollViewTests {
public:
    BEGIN_TEST_CLASS(UIScrollViewTests)
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
            XamlCreateScrollView(&xamlElement);
            ASSERT_TRUE(xamlElement);
        });
    }

    TEST_METHOD(GetXamlElement) {
        FrameworkHelper::RunOnUIThread([]() {
            UIView* view = [[[UIScrollView alloc] init] autorelease];
            FrameworkElement backingElement = [view _winrtXamlElement];
            ASSERT_TRUE(backingElement);
        });
    }

    TEST_METHOD(UIScrollView_VerifyDefault) {
        StrongId<UIScrollViewController> scrollViewVC;
        scrollViewVC.attach([[UIScrollViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(scrollViewVC, 2);

        UIScrollView* scrollView = [scrollViewVC scrollView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element
            FrameworkElement xamlScrollView = [scrollView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetScrollViewer(objcwinrt::to_insp(xamlScrollView)));
            auto scrollViewer = objcwinrt::from_insp<Controls::ScrollViewer>(inspectable);
            ASSERT_TRUE(scrollViewer);

            Microsoft::WRL::ComPtr<IInspectable> inspectable2(XamlScrollViewGetSubLayerCanvas(objcwinrt::to_insp(xamlScrollView)));
            auto canvas = objcwinrt::from_insp<Controls::Canvas>(inspectable2);

            // verify default contentOffset is {0}
            ASSERT_TRUE(scrollView.contentOffset == CGPointZero);
            ASSERT_TRUE(scrollViewer.HorizontalOffset() == 0);
            ASSERT_TRUE(scrollViewer.VerticalOffset() == 0);

            // verify default contentInsets is {0}
            EXPECT_TRUE(UIEdgeInsetsEqualToEdgeInsets(scrollView.contentInset, UIEdgeInsetsZero));
            ASSERT_TRUE(canvas.Margin().Top == 0 && canvas.Margin().Left == 0 && canvas.Margin().Right == 0 && canvas.Margin().Bottom == 0);

            // verify scrolling default enabled
            ASSERT_TRUE(scrollView.scrollEnabled);
            ASSERT_TRUE(scrollViewer.VerticalScrollBarVisibility() == Controls::ScrollBarVisibility::Auto &&
                        scrollViewer.HorizontalScrollBarVisibility() == Controls::ScrollBarVisibility::Auto);

            // verify default directional lock disabled
            ASSERT_TRUE(!scrollView.directionalLockEnabled);
            ASSERT_TRUE(!scrollViewer.IsVerticalRailEnabled());
            ASSERT_TRUE(!scrollViewer.IsHorizontalRailEnabled());

            // verify default show horizontal/vertical indicator
            ASSERT_TRUE(scrollView.showsHorizontalScrollIndicator);
            ASSERT_TRUE(scrollView.showsVerticalScrollIndicator);
            ASSERT_TRUE(scrollViewer.VerticalScrollBarVisibility() == Controls::ScrollBarVisibility::Auto);
            ASSERT_TRUE(scrollViewer.HorizontalScrollBarVisibility() == Controls::ScrollBarVisibility::Auto);

            // verify default zoomScale and minZoomScale and maxZoomScale is 1
            ASSERT_TRUE(scrollView.zoomScale == 1);
            ASSERT_TRUE(scrollViewer.ZoomFactor() == 1);

            ASSERT_TRUE(scrollView.maximumZoomScale == 10);
            ASSERT_TRUE(scrollViewer.MaxZoomFactor() == 10);

            ASSERT_TRUE(scrollView.minimumZoomScale == 1);
            ASSERT_TRUE(scrollViewer.MinZoomFactor() == 1);
        });
    }

    TEST_METHOD(UIScrollView_VerifyChangeContentOffset) {
        StrongId<UIScrollViewController> scrollViewVC;
        scrollViewVC.attach([[UIScrollViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(scrollViewVC, 2);

        UIScrollView* scrollView = [scrollViewVC scrollView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element
            FrameworkElement xamlScrollView = [scrollView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetScrollViewer(objcwinrt::to_insp(xamlScrollView)));
            auto scrollViewer = objcwinrt::from_insp<Controls::ScrollViewer>(inspectable);
            ASSERT_TRUE(scrollViewer);

            ASSERT_TRUE(scrollView.contentOffset == CGPointZero);
            ASSERT_TRUE(scrollViewer.HorizontalOffset() == 0);
            ASSERT_TRUE(scrollViewer.VerticalOffset() == 0);

            // move x only
            scrollView.contentOffset = CGPointMake(100, 0);
            LOG_INFO("expected contentOffset {%f, %f}, actual on xaml {%f, %f}",
                     scrollView.contentOffset.x,
                     scrollView.contentOffset.y,
                     scrollViewer.HorizontalOffset(),
                     scrollViewer.VerticalOffset());

            EXPECT_TRUE(scrollViewer.HorizontalOffset() == 100);
            EXPECT_TRUE(scrollViewer.VerticalOffset() == 0);

            // move y only
            scrollView.contentOffset = CGPointMake(100, 100);
            LOG_INFO("expected contentOffset {%f, %f}, actual on xaml {%f, %f}",
                     scrollView.contentOffset.x,
                     scrollView.contentOffset.y,
                     scrollViewer.HorizontalOffset(),
                     scrollViewer.VerticalOffset());

            EXPECT_TRUE(scrollViewer.HorizontalOffset() == 100);
            EXPECT_TRUE(scrollViewer.VerticalOffset() == 100);

            // move both x and y
            scrollView.contentOffset = CGPointMake(200, 200);
            LOG_INFO("expected contentOffset {%f, %f}, actual on xaml {%f, %f}",
                     scrollView.contentOffset.x,
                     scrollView.contentOffset.y,
                     scrollViewer.HorizontalOffset(),
                     scrollViewer.VerticalOffset());

            EXPECT_TRUE(scrollViewer.HorizontalOffset() == 200);
            EXPECT_TRUE(scrollViewer.VerticalOffset() == 200);
        });
    }

    TEST_METHOD(UIScrollView_VerifyChangeContentInset) {
        StrongId<UIScrollViewController> scrollViewVC;
        scrollViewVC.attach([[UIScrollViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(scrollViewVC, 2);

        UIScrollView* scrollView = [scrollViewVC scrollView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element
            FrameworkElement xamlScrollView = [scrollView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetScrollViewer(objcwinrt::to_insp(xamlScrollView)));
            auto scrollViewer = objcwinrt::from_insp<Controls::ScrollViewer>(inspectable);
            ASSERT_TRUE(scrollViewer);

            Microsoft::WRL::ComPtr<IInspectable> inspectable2(XamlScrollViewGetSubLayerCanvas(objcwinrt::to_insp(xamlScrollView)));
            auto canvas = objcwinrt::from_insp<Controls::Canvas>(inspectable2);

            // verify default contentInsets is {0}
            EXPECT_TRUE(UIEdgeInsetsEqualToEdgeInsets(scrollView.contentInset, UIEdgeInsetsZero));
            ASSERT_TRUE(canvas.Margin().Top == 0 && canvas.Margin().Left == 0 && canvas.Margin().Right == 0 && canvas.Margin().Bottom == 0);

            // changing contentInsets
            scrollView.contentInset = UIEdgeInsetsMake(100, 200, 300, 400);
            ASSERT_TRUE(canvas.Margin().Top == 100 && canvas.Margin().Left == 200 && canvas.Margin().Bottom == 300 &&
                        canvas.Margin().Right == 400);
        });
    }

    TEST_METHOD(UIScrollView_VerifyChangingScrollEnabledAndScrollIndicator) {
        StrongId<UIScrollViewController> scrollViewVC;
        scrollViewVC.attach([[UIScrollViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(scrollViewVC, 2);

        UIScrollView* scrollView = [scrollViewVC scrollView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element
            FrameworkElement xamlScrollView = [scrollView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetScrollViewer(objcwinrt::to_insp(xamlScrollView)));
            auto scrollViewer = objcwinrt::from_insp<Controls::ScrollViewer>(inspectable);
            ASSERT_TRUE(scrollViewer);

            ASSERT_TRUE(scrollView.scrollEnabled);
            ASSERT_TRUE(scrollViewer.VerticalScrollBarVisibility() == Controls::ScrollBarVisibility::Auto &&
                        scrollViewer.HorizontalScrollBarVisibility() == Controls::ScrollBarVisibility::Auto);

            // turn off scrolling, make sure scrollbar are hidden
            scrollView.scrollEnabled = NO;
            ASSERT_TRUE(scrollViewer.VerticalScrollBarVisibility() == Controls::ScrollBarVisibility::Hidden &&
                        scrollViewer.HorizontalScrollBarVisibility() == Controls::ScrollBarVisibility::Hidden);

            // turn back on
            scrollView.scrollEnabled = YES;
            ASSERT_TRUE(scrollViewer.VerticalScrollBarVisibility() == Controls::ScrollBarVisibility::Auto &&
                        scrollViewer.HorizontalScrollBarVisibility() == Controls::ScrollBarVisibility::Auto);

            // now change the horizontal scrollIndicator
            scrollView.showsHorizontalScrollIndicator = NO;
            ASSERT_TRUE(scrollViewer.VerticalScrollBarVisibility() == Controls::ScrollBarVisibility::Auto &&
                        scrollViewer.HorizontalScrollBarVisibility() == Controls::ScrollBarVisibility::Hidden);

            scrollView.showsVerticalScrollIndicator = NO;
            ASSERT_TRUE(scrollViewer.VerticalScrollBarVisibility() == Controls::ScrollBarVisibility::Hidden &&
                        scrollViewer.HorizontalScrollBarVisibility() == Controls::ScrollBarVisibility::Hidden);

            // turn off scrolling, make sure scrollbar are hidden
            scrollView.scrollEnabled = NO;
            ASSERT_TRUE(scrollViewer.VerticalScrollBarVisibility() == Controls::ScrollBarVisibility::Hidden &&
                        scrollViewer.HorizontalScrollBarVisibility() == Controls::ScrollBarVisibility::Hidden);

            // turn back on, make sure scrollbar are still hidden
            scrollView.scrollEnabled = YES;
            ASSERT_TRUE(scrollViewer.VerticalScrollBarVisibility() == Controls::ScrollBarVisibility::Hidden &&
                        scrollViewer.HorizontalScrollBarVisibility() == Controls::ScrollBarVisibility::Hidden);

            scrollView.showsHorizontalScrollIndicator = YES;
            ASSERT_TRUE(scrollViewer.VerticalScrollBarVisibility() == Controls::ScrollBarVisibility::Hidden &&
                        scrollViewer.HorizontalScrollBarVisibility() == Controls::ScrollBarVisibility::Auto);

            scrollView.showsVerticalScrollIndicator = YES;
            ASSERT_TRUE(scrollViewer.VerticalScrollBarVisibility() == Controls::ScrollBarVisibility::Auto &&
                        scrollViewer.HorizontalScrollBarVisibility() == Controls::ScrollBarVisibility::Auto);
        });
    }

    TEST_METHOD(UIScrollView_VerifyChangingDirectionalLock) {
        StrongId<UIScrollViewController> scrollViewVC;
        scrollViewVC.attach([[UIScrollViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(scrollViewVC, 2);

        UIScrollView* scrollView = [scrollViewVC scrollView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element
            FrameworkElement xamlScrollView = [scrollView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetScrollViewer(objcwinrt::to_insp(xamlScrollView)));
            auto scrollViewer = objcwinrt::from_insp<Controls::ScrollViewer>(inspectable);
            ASSERT_TRUE(scrollViewer);

            // verify default directional lock disabled
            ASSERT_TRUE(!scrollView.directionalLockEnabled);
            ASSERT_TRUE(!scrollViewer.IsVerticalRailEnabled());
            ASSERT_TRUE(!scrollViewer.IsHorizontalRailEnabled());

            // turn off directional lock
            scrollView.directionalLockEnabled = NO;
            ASSERT_TRUE(!scrollView.directionalLockEnabled);
            ASSERT_TRUE(!scrollViewer.IsVerticalRailEnabled());
            ASSERT_TRUE(!scrollViewer.IsHorizontalRailEnabled());

            // turn back on again
            scrollView.directionalLockEnabled = YES;
            ASSERT_TRUE(scrollView.directionalLockEnabled);
            ASSERT_TRUE(scrollViewer.IsVerticalRailEnabled());
            ASSERT_TRUE(scrollViewer.IsHorizontalRailEnabled());
        });
    }

    TEST_METHOD(UIScrollView_VerifyChangingZoom) {
        StrongId<UIScrollViewController> scrollViewVC;
        scrollViewVC.attach([[UIScrollViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(scrollViewVC, 2);

        UIScrollView* scrollView = [scrollViewVC scrollView];
        FrameworkElement xamlScrollView = [scrollView _winrtXamlElement];
        Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetScrollViewer(objcwinrt::to_insp(xamlScrollView)));
        auto scrollViewer = objcwinrt::from_insp<Controls::ScrollViewer>(inspectable);
        ASSERT_TRUE(scrollViewer);

        Microsoft::WRL::ComPtr<IInspectable> inspectable2(XamlScrollViewGetSubLayerCanvas(objcwinrt::to_insp(xamlScrollView)));
        auto canvas = objcwinrt::from_insp<Controls::Canvas>(inspectable2);

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element
            // verify default zoomScale and minZoomScale and maxZoomScale
            ASSERT_TRUE(scrollView.zoomScale == 1);
            ASSERT_TRUE(scrollViewer.ZoomFactor() == 1);

            ASSERT_TRUE(scrollView.minimumZoomScale == 1);
            ASSERT_TRUE(scrollViewer.MinZoomFactor() == 1);

            ASSERT_TRUE(scrollView.maximumZoomScale == 10);
            ASSERT_TRUE(scrollViewer.MaxZoomFactor() == 10);
        });

        __block auto uxEvent = UXTestAPI::UXEvent::CreateManual();
        __block auto xamlSubscriber = std::make_shared<UXTestAPI::XamlEventSubscription>();

        dispatch_sync(dispatch_get_main_queue(), ^{
            UIColor* expectedColor = [UIColor whiteColor];

            // Register RAII event subscription handler
            xamlSubscriber->Set(scrollViewer,
                                Controls::ScrollViewer::ZoomFactorProperty(),
                                ^(const DependencyObject& sender, const DependencyProperty& dp) {
                                    auto actualValue = sender.GetValue(dp).as<WF::IPropertyValue>();
                                    float actualZoomFactor = actualValue.GetSingle();

                                    // Validation
                                    if (scrollView.zoomScale == actualZoomFactor) {
                                        uxEvent->Set();
                                    }
                                });

            scrollView.zoomScale = 2;
        });

        ASSERT_TRUE_MSG(uxEvent->Wait(1), "FAILED: Waiting for property changed event state timed out!");

        dispatch_sync(dispatch_get_main_queue(), ^{
            LOG_INFO("expected zoomScale {%f}, actual on xaml {%f}", scrollView.zoomScale, scrollViewer.ZoomFactor());
            EXPECT_TRUE(scrollViewer.ZoomFactor() == 2);
            scrollView.minimumZoomScale = 3;
            LOG_INFO("expected minimumZoomScale {%f}, actual on xaml {%f}", scrollView.minimumZoomScale, scrollViewer.MinZoomFactor());
            EXPECT_TRUE(scrollViewer.MinZoomFactor() == 3);

            scrollView.maximumZoomScale = 20;
            LOG_INFO("expected maximumZoomScale {%f}, actual on xaml {%f}", scrollView.maximumZoomScale, scrollViewer.MaxZoomFactor());
            EXPECT_TRUE(scrollViewer.MaxZoomFactor() == 20);
        });
    }

    // Test to verify that Issue #2471 is fixed (UIScrollView programmatic scroll methods do not work if .scrollEnabled = NO)
    TEST_METHOD(UIScrollView_VerifyContentOffsetScrollingWhenUserScrollIsDisabled) {
        StrongId<UIScrollViewController> scrollViewVC;
        scrollViewVC.attach([[UIScrollViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(scrollViewVC, 2);

        UIScrollView* scrollView = [scrollViewVC scrollView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element
            FrameworkElement xamlScrollView = [scrollView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetScrollViewer(objcwinrt::to_insp(xamlScrollView)));
            auto scrollViewer = objcwinrt::from_insp<Controls::ScrollViewer>(inspectable);
            ASSERT_TRUE(scrollViewer);

            // scrollEnabled = No
            scrollView.scrollEnabled = NO;
            scrollView.showsHorizontalScrollIndicator = YES;
            scrollView.showsVerticalScrollIndicator = YES;
            // Verify at zero offset
            ASSERT_TRUE(scrollView.contentOffset == CGPointZero);
            ASSERT_TRUE(scrollViewer.HorizontalOffset() == 0);
            ASSERT_TRUE(scrollViewer.VerticalOffset() == 0);

            // move x only previously this would fail to change the offset
            scrollView.contentOffset = CGPointMake(100, 0);
            LOG_INFO("expected contentOffset {%f, %f}, actual on xaml {%f, %f}",
                     scrollView.contentOffset.x,
                     scrollView.contentOffset.y,
                     scrollViewer.HorizontalOffset(),
                     scrollViewer.VerticalOffset());

            EXPECT_TRUE(scrollViewer.HorizontalOffset() == 100);
            EXPECT_TRUE(scrollViewer.VerticalOffset() == 0);

            // scrollEnabled = No and Scrollbars not visible
            scrollView.scrollEnabled = NO;
            scrollView.showsHorizontalScrollIndicator = NO;
            scrollView.showsVerticalScrollIndicator = NO;

            // move x 10 more pixels previously this would fail to change the offset
            scrollView.contentOffset = CGPointMake(110, 0);
            LOG_INFO("expected contentOffset {%f, %f}, actual on xaml {%f, %f}",
                     scrollView.contentOffset.x,
                     scrollView.contentOffset.y,
                     scrollViewer.HorizontalOffset(),
                     scrollViewer.VerticalOffset());

            EXPECT_TRUE(scrollViewer.HorizontalOffset() == 110);
            EXPECT_TRUE(scrollViewer.VerticalOffset() == 0);

            // scrollEnabled = Yes and Scrollbars not visible
            scrollView.scrollEnabled = YES;
            scrollView.showsHorizontalScrollIndicator = NO;
            scrollView.showsVerticalScrollIndicator = NO;

            // move x 10 more pixels this worked before and should continue to update offset
            scrollView.contentOffset = CGPointMake(120, 0);
            LOG_INFO("expected contentOffset {%f, %f}, actual on xaml {%f, %f}",
                     scrollView.contentOffset.x,
                     scrollView.contentOffset.y,
                     scrollViewer.HorizontalOffset(),
                     scrollViewer.VerticalOffset());

            EXPECT_TRUE(scrollViewer.HorizontalOffset() == 120);
            EXPECT_TRUE(scrollViewer.VerticalOffset() == 0);
        });
    }

    // Test to verify that Issue #2471 is fixed (UIScrollView programmatic scroll methods do not work if .scrollEnabled = NO)
    TEST_METHOD(UIScrollView_VerifyscrollRectToVisibleWhenUserScrollIsDisabled) {
        StrongId<UIScrollViewController> scrollViewVC;
        scrollViewVC.attach([[UIScrollViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(scrollViewVC, 2);

        UIScrollView* scrollView = [scrollViewVC scrollView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element
            FrameworkElement xamlScrollView = [scrollView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetScrollViewer(objcwinrt::to_insp(xamlScrollView)));
            auto scrollViewer = objcwinrt::from_insp<Controls::ScrollViewer>(inspectable);
            ASSERT_TRUE(scrollViewer);

            // scrollEnabled = No
            scrollView.scrollEnabled = NO;
            scrollView.showsHorizontalScrollIndicator = YES;
            scrollView.showsVerticalScrollIndicator = YES;
            // Verify at zero offset
            ASSERT_TRUE(scrollView.contentOffset == CGPointZero);
            ASSERT_TRUE(scrollViewer.HorizontalOffset() == 0);
            ASSERT_TRUE(scrollViewer.VerticalOffset() == 0);

            CGRect targetRect1 = CGRectMake(0, 230, 1, 1);
            [scrollView scrollRectToVisible:targetRect1 animated:NO];
            LOG_INFO("expected contentOffset {%f, %f}, actual on xaml {%f, %f}",
                     scrollView.contentOffset.x,
                     scrollView.contentOffset.y,
                     scrollViewer.HorizontalOffset(),
                     scrollViewer.VerticalOffset());

            EXPECT_TRUE(scrollViewer.HorizontalOffset() == 0);
            EXPECT_TRUE(scrollViewer.VerticalOffset() == 31);

            // scrollEnabled = No and Scrollbars not visible
            scrollView.scrollEnabled = NO;
            scrollView.showsHorizontalScrollIndicator = NO;
            scrollView.showsVerticalScrollIndicator = NO;

            // move x 10 more pixels previously this would fail to change the offset
            targetRect1.origin.y = 240;
            [scrollView scrollRectToVisible:targetRect1 animated:NO];
            LOG_INFO("expected contentOffset {%f, %f}, actual on xaml {%f, %f}",
                     scrollView.contentOffset.x,
                     scrollView.contentOffset.y,
                     scrollViewer.HorizontalOffset(),
                     scrollViewer.VerticalOffset());

            EXPECT_TRUE(scrollViewer.HorizontalOffset() == 0);
            EXPECT_TRUE(scrollViewer.VerticalOffset() == 41);

            // scrollEnabled = Yes and Scrollbars not visible
            scrollView.scrollEnabled = YES;
            scrollView.showsHorizontalScrollIndicator = NO;
            scrollView.showsVerticalScrollIndicator = NO;

            // move x 10 more pixels this worked before and should continue to update offset
            targetRect1.origin.y = 250;
            [scrollView scrollRectToVisible:targetRect1 animated:NO];
            LOG_INFO("expected contentOffset {%f, %f}, actual on xaml {%f, %f}",
                     scrollView.contentOffset.x,
                     scrollView.contentOffset.y,
                     scrollViewer.HorizontalOffset(),
                     scrollViewer.VerticalOffset());

            EXPECT_TRUE(scrollViewer.HorizontalOffset() == 0);
            EXPECT_TRUE(scrollViewer.VerticalOffset() == 51);
        });
    }
};
