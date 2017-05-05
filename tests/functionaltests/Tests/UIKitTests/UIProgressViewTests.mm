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
#import <UIKit/UIProgressView.h>
#import "UIViewInternal.h"
#import "FunctionalTestHelpers.h"
#import "UXTestHelpers.h"
#include "CppWinRTHelpers.h"

#import "UIKitControls/UIProgressViewController.h"

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

class UIProgressViewTests {
private:
    // These sizes match iOS and what should be used in UIProgressView
    static constexpr double c_expectedDefaultStyleHeight() {
        return 2.0;
    }
    static constexpr double c_expectedBarStyleHeight() {
        return 2.5;
    }

    // Set in the XAMLCatalog UIActivitiIndicatorViewController
    static const int c_expectedInitialFrameWidth = 300;

    // These colors match iOS and what should be used in UIProgressView
    static UIColor* expectedStyleForegroundColor() {
        return [UIColor colorWithRed:0.5 green:0.48 blue:1.0 alpha:1.0];
    }
    static UIColor* expectedDefaultStyleBackgroundColor() {
        return [UIColor colorWithWhite:0.72 alpha:1.0];
    }
    static UIColor* expectedBarStyleBackgroundColor() {
        return [UIColor whiteColor];
    }

    // These are sample images used for testing setting an image as foreground/background
    static NSString* expectedProgressFillImageName() {
        return @"progress-fill-sample.png";
    }
    static NSString* expectedTrackImageName() {
        return @"progress-track-sample.png";
    }

public:
    BEGIN_TEST_CLASS(UIProgressViewTests)
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
            XamlCreateProgressView(&xamlElement);
            ASSERT_TRUE(xamlElement);
        });
    }

    TEST_METHOD(GetXamlElement) {
        FrameworkHelper::RunOnUIThread([]() {
            UIView* view = [[[UIProgressView alloc] init] autorelease];
            FrameworkElement backingElement = [view _winrtXamlElement];
            ASSERT_TRUE(backingElement);
        });
    }

    TEST_METHOD(UIProgressView_GetInternalControl) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);
        });
    }

    TEST_METHOD(UIProgressView_VerifyInitialState) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Ensure ProgressBar properties are as expected
            EXPECT_EQ(0, progressBar.Minimum());
            EXPECT_EQ(1, progressBar.Maximum());
            EXPECT_FALSE(progressBar.IsIndeterminate());

            // Should start in the default style
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);

            // Foreground color should match initial style
            auto solidForegroundBrush = progressBar.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidForegroundBrush, expectedStyleForegroundColor()));

            // Background color should match initial style
            auto solidBackgroundBrush = progressBar.Background().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedDefaultStyleBackgroundColor()));

            // Other properties should start as nil
            EXPECT_EQ(nil, progressView.progressTintColor);
            EXPECT_EQ(nil, progressView.trackTintColor);
            EXPECT_EQ(nil, progressView.progressImage);
            EXPECT_EQ(nil, progressView.trackImage);
            EXPECT_EQ(nil, progressView.observedProgress);

            // Initial progress value should be zero
            EXPECT_EQ(0, progressBar.Value());

            // Height should match initial style
            EXPECT_EQ(c_expectedDefaultStyleHeight(), progressBar.Height());

            // Initial element size is set in the controller
            EXPECT_EQ(c_expectedInitialFrameWidth, xamlElement.Width());
        });
    }

    /*  Verifies visual elements are set according to the UIProgressViewStyleBar style */
    TEST_METHOD(UIProgressView_SetBarStyle) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Should start in the default style
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);

            // Switch to bar style
            [progressView setProgressViewStyle:UIProgressViewStyleBar];
            EXPECT_EQ(UIProgressViewStyleBar, progressView.progressViewStyle);

            // Style colors should match colors for the bar style
            auto solidForegroundBrush = progressBar.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidForegroundBrush, expectedStyleForegroundColor()));
            auto solidBackgroundBrush = progressBar.Background().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedBarStyleBackgroundColor()));

            // Height should match bar style
            EXPECT_EQ(c_expectedBarStyleHeight(), progressBar.Height());

            // Width should not change
            EXPECT_EQ(c_expectedInitialFrameWidth, xamlElement.Width());

            // Other styling properties should not change
            EXPECT_EQ(nil, progressView.progressTintColor);
            EXPECT_EQ(nil, progressView.trackTintColor);
            EXPECT_EQ(nil, progressView.progressImage);
            EXPECT_EQ(nil, progressView.trackImage);
        });
    }

    /*  Verifies visual elements are set appropriately switching between the two styles */
    TEST_METHOD(UIProgressView_SetDefaultStyleAfterBarStyle) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Should start in the default style
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);

            // Switch to bar style
            [progressView setProgressViewStyle:UIProgressViewStyleBar];
            EXPECT_EQ(UIProgressViewStyleBar, progressView.progressViewStyle);

            // Switch back to default style
            [progressView setProgressViewStyle:UIProgressViewStyleDefault];
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);

            // Style colors should match colors for the default style
            auto solidForegroundBrush = progressBar.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidForegroundBrush, expectedStyleForegroundColor()));
            auto solidBackgroundBrush = progressBar.Background().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedDefaultStyleBackgroundColor()));

            // Height should match default style
            EXPECT_EQ(c_expectedDefaultStyleHeight(), progressBar.Height());

            // Width should not change
            EXPECT_EQ(c_expectedInitialFrameWidth, xamlElement.Width());
        });
    }

    /*  Attempts to set a style that is not one of the two officially supported styles:
            UIProgressViewStyleDefault
            UIProgressViewStyleBar

        The style should default to UIProgressViewStyleDefault
    */
    TEST_METHOD(UIProgressView_SetInvalidStyle) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Should start in the default style
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);

            // Attempt to set invalid style
            [progressView setProgressViewStyle:(UIProgressViewStyle)2];

            // Style should be set to the default style
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);

            // Style colors should match colors for the default style
            auto solidForegroundBrush = progressBar.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidForegroundBrush, expectedStyleForegroundColor()));
            auto solidBackgroundBrush = progressBar.Background().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedDefaultStyleBackgroundColor()));

            // Height should match default style
            EXPECT_EQ(c_expectedDefaultStyleHeight(), progressBar.Height());

            // Width should not change
            EXPECT_EQ(c_expectedInitialFrameWidth, xamlElement.Width());
        });
    }

    /* Height should be capped to the default height for the current style */
    TEST_METHOD(UIProgressView_SetHeight) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Height should match default style
            EXPECT_EQ(c_expectedDefaultStyleHeight(), progressBar.Height());

            // Attempt to increase height
            [progressView setFrame:CGRectMake(progressView.frame.origin.x,
                                              progressView.frame.origin.y,
                                              progressView.frame.size.width,
                                              progressView.frame.size.height + 1)];

            // Height should match default style
            EXPECT_EQ(c_expectedDefaultStyleHeight(), progressBar.Height());

            // Attempt to decrease height
            [progressView setFrame:CGRectMake(progressView.frame.origin.x,
                                              progressView.frame.origin.y,
                                              progressView.frame.size.width,
                                              progressView.frame.size.height - 1)];

            // Height should match default style
            EXPECT_EQ(c_expectedDefaultStyleHeight(), progressBar.Height());
        });
    }

    /*  Use a tint color for the progress fill */
    TEST_METHOD(UIProgressView_SetProgressTint) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Set tint color for progress fill
            UIColor* expectedTintColor = [UIColor redColor];
            [progressView setProgressTintColor:expectedTintColor];

            // Progress tint should be set
            auto solidForegroundBrush = progressBar.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidForegroundBrush, expectedTintColor));

            // Other styling properties should not change
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);
            EXPECT_EQ(nil, progressView.trackTintColor);
            EXPECT_EQ(nil, progressView.progressImage);
            EXPECT_EQ(nil, progressView.trackImage);
        });
    }

    /*  Use a tint color for the track */
    TEST_METHOD(UIProgressView_SetTrackTint) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Set tint color for track
            UIColor* expectedTintColor = [UIColor redColor];
            [progressView setTrackTintColor:expectedTintColor];

            // Track tint should be set
            auto solidBackgroundBrush = progressBar.Background().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedTintColor));

            // Other styling properties should not change
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);
            EXPECT_EQ(nil, progressView.progressTintColor);
            EXPECT_EQ(nil, progressView.progressImage);
            EXPECT_EQ(nil, progressView.trackImage);
        });
    }

    /*  Use an image for the progress fill */
    TEST_METHOD(UIProgressView_SetProgressImage) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Set image for progress fill
            UIImage* expectedImage = [UIImage imageNamed:expectedProgressFillImageName()];
            [progressView setProgressImage:expectedImage];

            // Progress image should be set
            auto actualImageBrush = progressBar.Foreground().as<Media::ImageBrush>();
            auto actualImageBitmapSource = actualImageBrush.ImageSource().as<Media::Imaging::BitmapSource>();
            EXPECT_EQ(actualImageBitmapSource.PixelWidth(), (int)expectedImage.size.width);
            EXPECT_EQ(actualImageBitmapSource.PixelHeight(), (int)expectedImage.size.height);

            // Other styling properties should not change
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);
            EXPECT_EQ(nil, progressView.progressTintColor);
            EXPECT_EQ(nil, progressView.trackTintColor);
            EXPECT_EQ(nil, progressView.trackImage);
        });
    }

    /*  Use an image for the track */
    TEST_METHOD(UIProgressView_SetTrackImage) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Set image for track
            UIImage* expectedImage = [UIImage imageNamed:expectedTrackImageName()];
            [progressView setTrackImage:expectedImage];

            // Track image should be set
            auto actualImageBrush = progressBar.Background().as<Media::ImageBrush>();
            auto actualImageBitmapSource = actualImageBrush.ImageSource().as<Media::Imaging::BitmapSource>();
            EXPECT_EQ(actualImageBitmapSource.PixelWidth(), (int)expectedImage.size.width);
            EXPECT_EQ(actualImageBitmapSource.PixelHeight(), (int)expectedImage.size.height);

            // Other styling properties should not change
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);
            EXPECT_EQ(nil, progressView.progressTintColor);
            EXPECT_EQ(nil, progressView.trackTintColor);
            EXPECT_EQ(nil, progressView.progressImage);
        });
    }

    /*  Clearing the tint should reset to the colors for the current style */
    TEST_METHOD(UIProgressView_ClearProgressTint) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Set tint color for progress fill
            UIColor* expectedTintColor = [UIColor redColor];
            [progressView setProgressTintColor:expectedTintColor];

            // Progress tint should be set
            auto progressBrush = progressBar.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(progressBrush, expectedTintColor));

            // Clear the tint
            [progressView setProgressTintColor:nil];

            // Style colors should match colors for the default style
            auto solidForegroundBrush = progressBar.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidForegroundBrush, expectedStyleForegroundColor()));
            auto solidBackgroundBrush = progressBar.Background().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedDefaultStyleBackgroundColor()));

            // Other styling properties should not change
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);
            EXPECT_EQ(nil, progressView.progressTintColor);
            EXPECT_EQ(nil, progressView.trackTintColor);
            EXPECT_EQ(nil, progressView.progressImage);
            EXPECT_EQ(nil, progressView.trackImage);
        });
    }

    /*  Clearing the tint should reset to the colors for the current style */
    TEST_METHOD(UIProgressView_ClearTrackTint) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Set tint color for track
            UIColor* expectedTintColor = [UIColor redColor];
            [progressView setTrackTintColor:expectedTintColor];

            // Track tint should be set
            auto trackBrush = progressBar.Background().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(trackBrush, expectedTintColor));

            // Clear the tint
            [progressView setTrackTintColor:nil];

            // Style colors should match colors for the default style
            auto solidForegroundBrush = progressBar.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidForegroundBrush, expectedStyleForegroundColor()));
            auto solidBackgroundBrush = progressBar.Background().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedDefaultStyleBackgroundColor()));

            // Other styling properties should not change
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);
            EXPECT_EQ(nil, progressView.progressTintColor);
            EXPECT_EQ(nil, progressView.trackTintColor);
            EXPECT_EQ(nil, progressView.progressImage);
            EXPECT_EQ(nil, progressView.trackImage);
        });
    }

    /*  Clearing the image should reset to the colors for the current style */
    TEST_METHOD(UIProgressView_ClearProgressImage) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Set image for progress fill
            UIImage* expectedImage = [UIImage imageNamed:expectedProgressFillImageName()];
            [progressView setProgressImage:expectedImage];

            // Progress image should be set
            auto actualImageBrush = progressBar.Foreground().as<Media::ImageBrush>();
            auto actualImageBitmapSource = actualImageBrush.ImageSource().as<Media::Imaging::BitmapSource>();
            EXPECT_EQ(actualImageBitmapSource.PixelWidth(), (int)expectedImage.size.width);
            EXPECT_EQ(actualImageBitmapSource.PixelHeight(), (int)expectedImage.size.height);

            // Clear the image
            [progressView setProgressImage:nil];

            // Style colors should match colors for the default style
            auto solidForegroundBrush = progressBar.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidForegroundBrush, expectedStyleForegroundColor()));
            auto solidBackgroundBrush = progressBar.Background().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedDefaultStyleBackgroundColor()));

            // Other styling properties should not change
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);
            EXPECT_EQ(nil, progressView.progressTintColor);
            EXPECT_EQ(nil, progressView.trackTintColor);
            EXPECT_EQ(nil, progressView.progressImage);
            EXPECT_EQ(nil, progressView.trackImage);
        });
    }

    /*  Clearing the image should reset to the colors for the current style */
    TEST_METHOD(UIProgressView_ClearTrackImage) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Set image for track
            UIImage* expectedImage = [UIImage imageNamed:expectedTrackImageName()];
            [progressView setTrackImage:expectedImage];

            // Track image should be set
            auto actualImageBrush = progressBar.Background().as<Media::ImageBrush>();
            auto actualImageBitmapSource = actualImageBrush.ImageSource().as<Media::Imaging::BitmapSource>();
            EXPECT_EQ(actualImageBitmapSource.PixelWidth(), (int)expectedImage.size.width);
            EXPECT_EQ(actualImageBitmapSource.PixelHeight(), (int)expectedImage.size.height);

            // Clear the image
            [progressView setTrackImage:nil];

            // Style colors should match colors for the default style
            auto solidForegroundBrush = progressBar.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidForegroundBrush, expectedStyleForegroundColor()));
            auto solidBackgroundBrush = progressBar.Background().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedDefaultStyleBackgroundColor()));

            // Other styling properties should not change
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);
            EXPECT_EQ(nil, progressView.progressTintColor);
            EXPECT_EQ(nil, progressView.trackTintColor);
            EXPECT_EQ(nil, progressView.progressImage);
            EXPECT_EQ(nil, progressView.trackImage);
        });
    }

    /*  Tint should always be cleared after an image is set */
    TEST_METHOD(UIProgressView_SetTrackImageAfterTint) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Set tint color for track
            UIColor* expectedTintColor = [UIColor redColor];
            [progressView setTrackTintColor:expectedTintColor];

            // Track tint should be set
            auto solidBackgroundBrush = progressBar.Background().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedTintColor));

            // Set image for track
            UIImage* expectedImage = [UIImage imageNamed:expectedTrackImageName()];
            [progressView setTrackImage:expectedImage];

            // Track image should be set
            auto actualImageBrush = progressBar.Background().as<Media::ImageBrush>();
            auto actualImageBitmapSource = actualImageBrush.ImageSource().as<Media::Imaging::BitmapSource>();
            EXPECT_EQ(actualImageBitmapSource.PixelWidth(), (int)expectedImage.size.width);
            EXPECT_EQ(actualImageBitmapSource.PixelHeight(), (int)expectedImage.size.height);

            // Other styling properties should not change
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);
            EXPECT_EQ(nil, progressView.progressTintColor);
            EXPECT_EQ(nil, progressView.trackTintColor);
            EXPECT_EQ(nil, progressView.progressImage);
        });
    }

    /*  Tint should always be cleared after an image is set */
    TEST_METHOD(UIProgressView_SetProgressImageAfterTint) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Set tint color for progress fill
            UIColor* expectedTintColor = [UIColor redColor];
            [progressView setProgressTintColor:expectedTintColor];

            // Progress tint should be set
            auto solidForegroundBrush = progressBar.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidForegroundBrush, expectedTintColor));

            // Set image for progress fill
            UIImage* expectedImage = [UIImage imageNamed:expectedProgressFillImageName()];
            [progressView setProgressImage:expectedImage];

            // Progress image should be set
            auto actualImageBrush = progressBar.Foreground().as<Media::ImageBrush>();
            auto actualImageBitmapSource = actualImageBrush.ImageSource().as<Media::Imaging::BitmapSource>();
            EXPECT_EQ(actualImageBitmapSource.PixelWidth(), (int)expectedImage.size.width);
            EXPECT_EQ(actualImageBitmapSource.PixelHeight(), (int)expectedImage.size.height);

            // Other styling properties should not change
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);
            EXPECT_EQ(nil, progressView.progressTintColor);
            EXPECT_EQ(nil, progressView.trackTintColor);
            EXPECT_EQ(nil, progressView.trackImage);
        });
    }

    /*  Image should always be cleared after a tint is set */
    TEST_METHOD(UIProgressView_SetTrackTintAfterImage) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Set image for track
            UIImage* expectedImage = [UIImage imageNamed:expectedTrackImageName()];
            [progressView setTrackImage:expectedImage];

            // Track image should be set
            auto actualImageBrush = progressBar.Background().as<Media::ImageBrush>();
            auto actualImageBitmapSource = actualImageBrush.ImageSource().as<Media::Imaging::BitmapSource>();
            EXPECT_EQ(actualImageBitmapSource.PixelWidth(), (int)expectedImage.size.width);
            EXPECT_EQ(actualImageBitmapSource.PixelHeight(), (int)expectedImage.size.height);

            // Set tint color for track
            UIColor* expectedTintColor = [UIColor redColor];
            [progressView setTrackTintColor:expectedTintColor];

            // Track tint should be set
            auto solidBackgroundBrush = progressBar.Background().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidBackgroundBrush, expectedTintColor));

            // Other styling properties should not change
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);
            EXPECT_EQ(nil, progressView.progressTintColor);
            EXPECT_EQ(nil, progressView.progressImage);
            EXPECT_EQ(nil, progressView.trackImage);
        });
    }

    /*  Image should always be cleared after a tint is set */
    TEST_METHOD(UIProgressView_SetProgressTintAfterImage) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Set image for progress fill
            UIImage* expectedImage = [UIImage imageNamed:expectedProgressFillImageName()];
            [progressView setProgressImage:expectedImage];

            // Progress image should be set
            auto actualImageBrush = progressBar.Foreground().as<Media::ImageBrush>();
            auto actualImageBitmapSource = actualImageBrush.ImageSource().as<Media::Imaging::BitmapSource>();
            EXPECT_EQ(actualImageBitmapSource.PixelWidth(), (int)expectedImage.size.width);
            EXPECT_EQ(actualImageBitmapSource.PixelHeight(), (int)expectedImage.size.height);

            // Set tint color for progress fill
            UIColor* expectedTintColor = [UIColor redColor];
            [progressView setProgressTintColor:expectedTintColor];

            // Progress tint should be set
            auto solidForegroundBrush = progressBar.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(solidForegroundBrush, expectedTintColor));

            // Other styling properties should not change
            EXPECT_EQ(UIProgressViewStyleDefault, progressView.progressViewStyle);
            EXPECT_EQ(nil, progressView.trackTintColor);
            EXPECT_EQ(nil, progressView.trackImage);
            EXPECT_EQ(nil, progressView.progressImage);
        });
    }

    /*  Tint should remain set after a style is applied */
    TEST_METHOD(UIProgressView_SetStyleAfterTint) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Set tint color for progress fill
            UIColor* expectedTintColor = [UIColor redColor];
            [progressView setProgressTintColor:expectedTintColor];

            // Progress tint should be set
            auto progressBrush = progressBar.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(progressBrush, expectedTintColor));

            // Set tint color for track
            [progressView setTrackTintColor:expectedTintColor];

            // Track tint should be set
            auto trackBrush = progressBar.Background().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(trackBrush, expectedTintColor));

            // Switch back to default style
            [progressView setProgressViewStyle:UIProgressViewStyleBar];
            EXPECT_EQ(UIProgressViewStyleBar, progressView.progressViewStyle);

            // Progress tint should still be set
            progressBrush = progressBar.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(progressBrush, expectedTintColor));

            // Track tint should still be set
            trackBrush = progressBar.Background().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(trackBrush, expectedTintColor));

            // Other styling properties should not change
            EXPECT_EQ(nil, progressView.trackImage);
            EXPECT_EQ(nil, progressView.progressImage);
        });
    }

    /*  Image remain set after a style is applied */
    TEST_METHOD(UIProgressView_SetStyleAfterImage) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Set image for progress fill
            UIImage* expectedProgressImage = [UIImage imageNamed:expectedProgressFillImageName()];
            [progressView setProgressImage:expectedProgressImage];

            // Progress image should be set
            auto actualProgressImageBrush = progressBar.Foreground().as<Media::ImageBrush>();
            auto actualProgressImageBitmapSource = actualProgressImageBrush.ImageSource().as<Media::Imaging::BitmapSource>();
            EXPECT_EQ(actualProgressImageBitmapSource.PixelWidth(), (int)expectedProgressImage.size.width);
            EXPECT_EQ(actualProgressImageBitmapSource.PixelHeight(), (int)expectedProgressImage.size.height);

            // Set image for track
            UIImage* expectedTrackImage = [UIImage imageNamed:expectedTrackImageName()];
            [progressView setTrackImage:expectedTrackImage];

            // Track image should be set
            auto actualTrackImageBrush = progressBar.Background().as<Media::ImageBrush>();
            auto actualTrackImageBitmapSource = actualTrackImageBrush.ImageSource().as<Media::Imaging::BitmapSource>();
            EXPECT_EQ(actualTrackImageBitmapSource.PixelWidth(), (int)expectedTrackImage.size.width);
            EXPECT_EQ(actualTrackImageBitmapSource.PixelHeight(), (int)expectedTrackImage.size.height);

            // Set to bar style
            [progressView setProgressViewStyle:UIProgressViewStyleBar];
            EXPECT_EQ(UIProgressViewStyleBar, progressView.progressViewStyle);

            // Progress image should be still set
            actualProgressImageBrush = progressBar.Foreground().as<Media::ImageBrush>();
            actualProgressImageBitmapSource = actualProgressImageBrush.ImageSource().as<Media::Imaging::BitmapSource>();
            EXPECT_EQ(actualProgressImageBitmapSource.PixelWidth(), (int)expectedProgressImage.size.width);
            EXPECT_EQ(actualProgressImageBitmapSource.PixelHeight(), (int)expectedProgressImage.size.height);

            // Track image should be still set
            actualTrackImageBrush = progressBar.Background().as<Media::ImageBrush>();
            actualTrackImageBitmapSource = actualTrackImageBrush.ImageSource().as<Media::Imaging::BitmapSource>();
            EXPECT_EQ(actualTrackImageBitmapSource.PixelWidth(), (int)expectedTrackImage.size.width);
            EXPECT_EQ(actualTrackImageBitmapSource.PixelHeight(), (int)expectedTrackImage.size.height);

            // Other styling properties should not change
            EXPECT_EQ(nil, progressView.progressTintColor);
            EXPECT_EQ(nil, progressView.trackTintColor);
        });
    }

    /*  Manually set the progress value directly */
    TEST_METHOD(UIProgressView_SetProgressValue) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Set the progress value
            float expectedProgressValue = 0.5;
            [progressView setProgress:expectedProgressValue];

            // Progress value should be updated
            EXPECT_EQ(expectedProgressValue, progressView.progress);
        });
    }

    /*  Provide an NSProgress instance to observe.
        The progress value should be set automatically based on the completion fraction of the observed NSProgress instance.
    */
    TEST_METHOD(UIProgressView_SetProgressValueWithObservedProgress) {
        StrongId<UIProgressViewController> progressViewVC;
        progressViewVC.attach([[UIProgressViewController alloc] init]);

        UXTestAPI::ViewControllerPresenter testHelper(progressViewVC, 2);
        UIProgressView* progressView = [progressViewVC progressView];

        dispatch_sync(dispatch_get_main_queue(), ^{
            FrameworkElement xamlElement = [progressView _winrtXamlElement];
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(xamlElement)));
            auto progressBar = objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
            ASSERT_TRUE(progressBar);

            // Progress values
            float totalProgressUnitCount = 4.0;
            float completedProgressUnitCount = 3.0;
            float expectedProgressValue = completedProgressUnitCount / totalProgressUnitCount;

            // Set the observed progress
            NSProgress* progress = [NSProgress progressWithTotalUnitCount:totalProgressUnitCount];
            [progressView setObservedProgress:progress];

            // Progress value should still be zero
            EXPECT_EQ(0, progressView.progress);

            // Update the completed count
            [progress setCompletedUnitCount:completedProgressUnitCount];

            // Progress value should be updated
            EXPECT_EQ(expectedProgressValue, progressView.progress);
        });
    }
};
