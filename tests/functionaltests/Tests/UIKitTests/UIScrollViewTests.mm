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
#import "UWP/WindowsUIXamlControls.h"

#import "FunctionalTestHelpers.h"
#import "UXTestHelpers.h"
#import "UIKitControls/UIScrollViewController.h"

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
            WXFrameworkElement* backingElement = [view xamlElement];
            ASSERT_TRUE(backingElement);

            // TODO: Fix up when UIScrollView moves fully to XAML
            ASSERT_TRUE([backingElement isKindOfClass:[WXFrameworkElement class]]);
        });
    }

    TEST_METHOD(UIScrollView_VerifyDefault) {
        StrongId<UIScrollViewController> scrollViewVC;
        scrollViewVC.attach([[UIScrollViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(scrollViewVC, 2);

        UIScrollView* scrollView = [scrollViewVC scrollView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element
            WXFrameworkElement* xamlScrollView = [scrollView xamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetScrollViewer([xamlScrollView comObj]));
            WXCScrollViewer* scrollViewer = _createRtProxy([WXCScrollViewer class], inspectable.Get());
            ASSERT_OBJCNE(scrollViewer, nil);

            Microsoft::WRL::ComPtr<IInspectable> inspectable2(XamlScrollViewGetSubLayerCanvas([xamlScrollView comObj]));
            WXCCanvas* canvas = _createRtProxy([WXCCanvas class], inspectable2.Get());

            // verify default contentOffset is {0}
            ASSERT_TRUE(scrollView.contentOffset == CGPointZero);
            ASSERT_TRUE(scrollViewer.horizontalOffset == 0);
            ASSERT_TRUE(scrollViewer.verticalOffset == 0);

            // verify default conentInsets is {0}
            EXPECT_TRUE(UIEdgeInsetsEqualToEdgeInsets(scrollView.contentInset, UIEdgeInsetsZero));
            ASSERT_TRUE(canvas.margin.top == 0 && canvas.margin.left == 0 && canvas.margin.right == 0 && canvas.margin.bottom == 0);

            // verfiy scrolling default enabled
            ASSERT_TRUE(scrollView.scrollEnabled);
            ASSERT_TRUE(scrollViewer.verticalScrollBarVisibility == WXCScrollBarVisibilityAuto &&
                        scrollViewer.horizontalScrollBarVisibility == WXCScrollBarVisibilityAuto);

            // verfiy default directional lock disabled
            ASSERT_TRUE(!scrollView.directionalLockEnabled);
            ASSERT_TRUE(!scrollViewer.isVerticalRailEnabled);
            ASSERT_TRUE(!scrollViewer.isHorizontalRailEnabled);

            // verfiy default show horizontal/vertical indicator
            ASSERT_TRUE(scrollView.showsHorizontalScrollIndicator);
            ASSERT_TRUE(scrollView.showsVerticalScrollIndicator);
            ASSERT_TRUE(scrollViewer.verticalScrollBarVisibility == WXCScrollBarVisibilityAuto);
            ASSERT_TRUE(scrollViewer.horizontalScrollBarVisibility == WXCScrollBarVisibilityAuto);

            // verfify default zoomScale and minZoomScale and maxZoomScale is 1
            ASSERT_TRUE(scrollView.zoomScale == 1);
            ASSERT_TRUE(scrollViewer.zoomFactor == 1);

            ASSERT_TRUE(scrollView.maximumZoomScale == 10);
            ASSERT_TRUE(scrollViewer.maxZoomFactor == 10);

            ASSERT_TRUE(scrollView.minimumZoomScale == 1);
            ASSERT_TRUE(scrollViewer.minZoomFactor == 1);
        });
    }

    TEST_METHOD(UIScrollView_VerifyChangeContentOffset) {
        StrongId<UIScrollViewController> scrollViewVC;
        scrollViewVC.attach([[UIScrollViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(scrollViewVC, 2);

        UIScrollView* scrollView = [scrollViewVC scrollView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element
            WXFrameworkElement* xamlScrollView = [scrollView xamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetScrollViewer([xamlScrollView comObj]));
            WXCScrollViewer* scrollViewer = _createRtProxy([WXCScrollViewer class], inspectable.Get());
            ASSERT_OBJCNE(scrollViewer, nil);

            ASSERT_TRUE(scrollView.contentOffset == CGPointZero);
            ASSERT_TRUE(scrollViewer.horizontalOffset == 0);
            ASSERT_TRUE(scrollViewer.verticalOffset == 0);

            // move x only
            scrollView.contentOffset = CGPointMake(100, 0);
            LOG_INFO("expected contentOffset {%f, %f}, acutal on xaml {%f, %f}",
                     scrollView.contentOffset.x,
                     scrollView.contentOffset.y,
                     scrollViewer.horizontalOffset,
                     scrollViewer.verticalOffset);

            EXPECT_TRUE(scrollViewer.horizontalOffset == 100);
            EXPECT_TRUE(scrollViewer.verticalOffset == 0);

            // move y only
            scrollView.contentOffset = CGPointMake(100, 100);
            LOG_INFO("expected contentOffset {%f, %f}, acutal on xaml {%f, %f}",
                     scrollView.contentOffset.x,
                     scrollView.contentOffset.y,
                     scrollViewer.horizontalOffset,
                     scrollViewer.verticalOffset);

            EXPECT_TRUE(scrollViewer.horizontalOffset == 100);
            EXPECT_TRUE(scrollViewer.verticalOffset == 100);

            // move both x and y
            scrollView.contentOffset = CGPointMake(200, 200);
            LOG_INFO("expected contentOffset {%f, %f}, acutal on xaml {%f, %f}",
                     scrollView.contentOffset.x,
                     scrollView.contentOffset.y,
                     scrollViewer.horizontalOffset,
                     scrollViewer.verticalOffset);

            EXPECT_TRUE(scrollViewer.horizontalOffset == 200);
            EXPECT_TRUE(scrollViewer.verticalOffset == 200);
        });
    }

    TEST_METHOD(UIScrollView_VerifyChangeContentInset) {
        StrongId<UIScrollViewController> scrollViewVC;
        scrollViewVC.attach([[UIScrollViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(scrollViewVC, 2);

        UIScrollView* scrollView = [scrollViewVC scrollView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element
            WXFrameworkElement* xamlScrollView = [scrollView xamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetScrollViewer([xamlScrollView comObj]));
            WXCScrollViewer* scrollViewer = _createRtProxy([WXCScrollViewer class], inspectable.Get());
            ASSERT_OBJCNE(scrollViewer, nil);

            Microsoft::WRL::ComPtr<IInspectable> inspectable2(XamlScrollViewGetSubLayerCanvas([xamlScrollView comObj]));
            WXCCanvas* canvas = _createRtProxy([WXCCanvas class], inspectable2.Get());

            // verify default conentInsets is {0}
            EXPECT_TRUE(UIEdgeInsetsEqualToEdgeInsets(scrollView.contentInset, UIEdgeInsetsZero));
            ASSERT_TRUE(canvas.margin.top == 0 && canvas.margin.left == 0 && canvas.margin.right == 0 && canvas.margin.bottom == 0);

            // changing contentInsets
            scrollView.contentInset = UIEdgeInsetsMake(100, 200, 300, 400);
            ASSERT_TRUE(canvas.margin.top == 100 && canvas.margin.left == 200 && canvas.margin.bottom == 300 && canvas.margin.right == 400);
        });
    }

    TEST_METHOD(UIScrollView_VerifyChangingScrollEnabledAndScrollIndicator) {
        StrongId<UIScrollViewController> scrollViewVC;
        scrollViewVC.attach([[UIScrollViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(scrollViewVC, 2);

        UIScrollView* scrollView = [scrollViewVC scrollView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element
            WXFrameworkElement* xamlScrollView = [scrollView xamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetScrollViewer([xamlScrollView comObj]));
            WXCScrollViewer* scrollViewer = _createRtProxy([WXCScrollViewer class], inspectable.Get());
            ASSERT_OBJCNE(scrollViewer, nil);

            ASSERT_TRUE(scrollView.scrollEnabled);
            ASSERT_TRUE(scrollViewer.verticalScrollBarVisibility == WXCScrollBarVisibilityAuto &&
                        scrollViewer.horizontalScrollBarVisibility == WXCScrollBarVisibilityAuto);

            // turn off scrolling
            scrollView.scrollEnabled = NO;
            ASSERT_TRUE(scrollViewer.verticalScrollBarVisibility == WXCScrollBarVisibilityDisabled &&
                        scrollViewer.horizontalScrollBarVisibility == WXCScrollBarVisibilityDisabled);

            // turn back on
            scrollView.scrollEnabled = YES;
            ASSERT_TRUE(scrollViewer.verticalScrollBarVisibility == WXCScrollBarVisibilityAuto &&
                        scrollViewer.horizontalScrollBarVisibility == WXCScrollBarVisibilityAuto);

            // now change the horizontal scrolldinciate
            scrollView.showsHorizontalScrollIndicator = NO;
            ASSERT_TRUE(scrollViewer.verticalScrollBarVisibility == WXCScrollBarVisibilityAuto &&
                        scrollViewer.horizontalScrollBarVisibility == WXCScrollBarVisibilityHidden);

            scrollView.showsVerticalScrollIndicator = NO;
            ASSERT_TRUE(scrollViewer.verticalScrollBarVisibility == WXCScrollBarVisibilityHidden &&
                        scrollViewer.horizontalScrollBarVisibility == WXCScrollBarVisibilityHidden);

            // turn off scrolling, make sure scrollbar are disabled
            scrollView.scrollEnabled = NO;
            ASSERT_TRUE(scrollViewer.verticalScrollBarVisibility == WXCScrollBarVisibilityDisabled &&
                        scrollViewer.horizontalScrollBarVisibility == WXCScrollBarVisibilityDisabled);

            // turn back on, make sure scrollbar are still hidden
            scrollView.scrollEnabled = YES;
            ASSERT_TRUE(scrollViewer.verticalScrollBarVisibility == WXCScrollBarVisibilityHidden &&
                        scrollViewer.horizontalScrollBarVisibility == WXCScrollBarVisibilityHidden);

            scrollView.showsHorizontalScrollIndicator = YES;
            ASSERT_TRUE(scrollViewer.verticalScrollBarVisibility == WXCScrollBarVisibilityHidden &&
                        scrollViewer.horizontalScrollBarVisibility == WXCScrollBarVisibilityAuto);

            scrollView.showsVerticalScrollIndicator = YES;
            ASSERT_TRUE(scrollViewer.verticalScrollBarVisibility == WXCScrollBarVisibilityAuto &&
                        scrollViewer.horizontalScrollBarVisibility == WXCScrollBarVisibilityAuto);
        });
    }

    TEST_METHOD(UIScrollView_VerifyChangingDrectionalLock) {
        StrongId<UIScrollViewController> scrollViewVC;
        scrollViewVC.attach([[UIScrollViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(scrollViewVC, 2);

        UIScrollView* scrollView = [scrollViewVC scrollView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element
            WXFrameworkElement* xamlScrollView = [scrollView xamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetScrollViewer([xamlScrollView comObj]));
            WXCScrollViewer* scrollViewer = _createRtProxy([WXCScrollViewer class], inspectable.Get());
            ASSERT_OBJCNE(scrollViewer, nil);

            // verfiy default directional lock disabled
            ASSERT_TRUE(!scrollView.directionalLockEnabled);
            ASSERT_TRUE(!scrollViewer.isVerticalRailEnabled);
            ASSERT_TRUE(!scrollViewer.isHorizontalRailEnabled);

            // turn off directional lock
            scrollView.directionalLockEnabled = NO;
            ASSERT_TRUE(!scrollView.directionalLockEnabled);
            ASSERT_TRUE(!scrollViewer.isVerticalRailEnabled);
            ASSERT_TRUE(!scrollViewer.isHorizontalRailEnabled);

            // turn back on again
            scrollView.directionalLockEnabled = YES;
            ASSERT_TRUE(scrollView.directionalLockEnabled);
            ASSERT_TRUE(scrollViewer.isVerticalRailEnabled);
            ASSERT_TRUE(scrollViewer.isHorizontalRailEnabled);
        });
    }

    TEST_METHOD(UIScrollView_VerifyChangingZoom) {
        StrongId<UIScrollViewController> scrollViewVC;
        scrollViewVC.attach([[UIScrollViewController alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(scrollViewVC, 2);

        UIScrollView* scrollView = [scrollViewVC scrollView];
        WXFrameworkElement* xamlScrollView = [scrollView xamlElement];
        Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetScrollViewer([xamlScrollView comObj]));
        WXCScrollViewer* scrollViewer = _createRtProxy([WXCScrollViewer class], inspectable.Get());
        ASSERT_OBJCNE(scrollViewer, nil);

        Microsoft::WRL::ComPtr<IInspectable> inspectable2(XamlScrollViewGetSubLayerCanvas([xamlScrollView comObj]));
        WXCCanvas* canvas = _createRtProxy([WXCCanvas class], inspectable2.Get());

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element
            // verfify default zoomScale and minZoomScale and maxZoomScale
            ASSERT_TRUE(scrollView.zoomScale == 1);
            ASSERT_TRUE(scrollViewer.zoomFactor == 1);

            ASSERT_TRUE(scrollView.minimumZoomScale == 1);
            ASSERT_TRUE(scrollViewer.minZoomFactor == 1);

            ASSERT_TRUE(scrollView.maximumZoomScale == 10);
            ASSERT_TRUE(scrollViewer.maxZoomFactor == 10);
        });

        __block auto uxEvent = UXTestAPI::UXEvent::CreateManual();
        __block auto xamlSubscriber = std::make_shared<UXTestAPI::XamlEventSubscription>();

        dispatch_sync(dispatch_get_main_queue(), ^{
            UIColor* expectedColor = [UIColor whiteColor];

            // Register RAII event subscription handler
            xamlSubscriber->Set(scrollViewer,
                                [WXCScrollViewer zoomFactorProperty],
                                ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                                    WFIPropertyValue* actualValue = rt_dynamic_cast([WFIPropertyValue class], [sender getValue:dp]);
                                    float actualZoomFactor = [actualValue getSingle];

                                    // Validation
                                    if (scrollView.zoomScale == actualZoomFactor) {
                                        uxEvent->Set();
                                    }
                                });

            scrollView.zoomScale = 2;
        });

        ASSERT_TRUE_MSG(uxEvent->Wait(1), "FAILED: Waiting for property changed event state timed out!");

        dispatch_sync(dispatch_get_main_queue(), ^{
            LOG_INFO("expected zoomScale {%f}, acutal on xaml {%f}", scrollView.zoomScale, scrollViewer.zoomFactor);
            EXPECT_TRUE(scrollViewer.zoomFactor == 2);
            scrollView.minimumZoomScale = 3;
            LOG_INFO("expected minimumZoomScale {%f}, acutal on xaml {%f}", scrollView.minimumZoomScale, scrollViewer.minZoomFactor);
            EXPECT_TRUE(scrollViewer.minZoomFactor == 3);

            scrollView.maximumZoomScale = 20;
            LOG_INFO("expected maximumZoomScale {%f}, acutal on xaml {%f}", scrollView.maximumZoomScale, scrollViewer.maxZoomFactor);
            EXPECT_TRUE(scrollViewer.maxZoomFactor == 20);
        });
    }
};
