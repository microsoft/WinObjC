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
#import <TestFramework.h>
#import "FunctionalTestHelpers.h"
#import "UXTestHelpers.h"

#import "CALayerInternal.h"

@interface CALayerViewController : UIViewController
@property (nonatomic, readonly) CALayer* layer;
@property (nonatomic, readonly) UIView* viewForLayer;
@end

@implementation CALayerViewController
- (void)viewDidLoad {
    [super viewDidLoad];

    _viewForLayer = self.view;
    _viewForLayer.frame = CGRectMake(0.0f, 00.f, 200.0f, 200.0f);
    _viewForLayer.backgroundColor = [UIColor whiteColor];

    _layer = [CALayer layer];
    _layer.frame = self->_viewForLayer.bounds;
    [_viewForLayer.layer addSublayer:_layer];
}
@end

//
// Validate that the CALayer opacity property change invokes a property change in the backing XAML element
//
TEST(CALayerAppearance, OpacityChanged) {
    __block auto uxEvent = std::make_shared<UXTestAPI::UXEvent>();
    __block auto xamlSubscriber = std::make_shared<UXTestAPI::XamlEventSubscription>();

    float expectedOpacity = 0.5f;

    CALayerViewController* caLayerVC = [[CALayerViewController alloc] init];
    UXTestAPI::ViewControllerPresenter testHelper(caLayerVC);

    dispatch_async(dispatch_get_main_queue(), ^{
        WXUIElement* xamlElement = [caLayerVC.layer _xamlElement];

        // Register RAII event subscription handler
        xamlSubscriber->Set(xamlElement, [WXUIElement opacityProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
            // Validation
            EXPECT_EQ_MSG(xamlElement.opacity, caLayerVC.layer.opacity, "Failed to match opacity");
            EXPECT_EQ_MSG(xamlElement.opacity, expectedOpacity, "Failed to match opacity with expected value");

            // Manually unregister the event so we avoid further opacity property changed events
            xamlSubscriber->Reset();

            uxEvent->Signal();
        });

        // Action
        caLayerVC.layer.opacity = expectedOpacity;
    });

    ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event timed out!");
}

//
// Validate that the CALayer background property change invokes a property change in the backing XAML element
//
TEST(CALayerAppearance, BackgroundColorChanged) {
    __block auto uxEvent = std::make_shared<UXTestAPI::UXEvent>();
    __block auto xamlSubscriber = std::make_shared<UXTestAPI::XamlEventSubscription>();

    UIColor* expectedColor = [UIColor redColor];

    CALayerViewController* caLayerVC = [[CALayerViewController alloc] init];
    UXTestAPI::ViewControllerPresenter testHelper(caLayerVC);

    dispatch_async(dispatch_get_main_queue(), ^{
        WXUIElement* xamlElement = [caLayerVC.layer _xamlElement];

        // Register RAII event subscription handler
        xamlSubscriber->Set(xamlElement, [WXCPanel backgroundProperty], ^(WXDependencyObject* sender, WXDependencyProperty* dp) {
            WUXMSolidColorBrush* solidBrush = rt_dynamic_cast([WUXMSolidColorBrush class], [sender getValue:dp]);
            ASSERT_OBJCNE(solidBrush, nil);

            // Validation
            UIColor* colorFromCGColor = [UIColor colorWithCGColor:caLayerVC.layer.backgroundColor];
            EXPECT_TRUE_MSG(UXTestAPI::IsRGBAEqual(solidBrush, colorFromCGColor), @"Failed to match XAML- and CALayer background color");
            EXPECT_OBJCEQ_MSG(colorFromCGColor, expectedColor, @"Failed to match expected color");

            uxEvent->Signal();
        });

        // Action
        caLayerVC.layer.backgroundColor = expectedColor.CGColor;
    });

    ASSERT_TRUE_MSG(uxEvent->Wait(c_testTimeoutInSec), "FAILED: Waiting for property changed event timed out!");
}
