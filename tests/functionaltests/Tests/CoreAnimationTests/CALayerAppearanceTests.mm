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
#import <Foundation/Foundation.h>

#include <COMIncludes.h>
#import <WRLHelpers.h>
#import <ErrorHandling.h>
#import <RawBuffer.h>
#import <wrl/client.h>
#import <wrl/implements.h>
#import <wrl/async.h>
#import <wrl/wrappers/corewrappers.h>
#import <windows.foundation.h>
#include <COMIncludes_end.h>

#import "ObjCXamlControls.h"

#import "UWP/WindowsUIXamlControls.h"
#import "CALayerInternal.h"

// TODO: Consolidate this into a common place so that all tests can use it
static const NSTimeInterval c_testTimeoutInSec = 5;

@interface CALayerViewController : UIViewController
@property CALayer* layer;
@property UIView* viewForLayer;
@end

@implementation CALayerViewController
- (instancetype)init {
    if (self = [super init]) {
        self->_layer = [CALayer layer];
    }

    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self->_viewForLayer = self.view;
    self->_viewForLayer.frame = CGRectMake(0, 100, 200, 200);
    self->_viewForLayer.backgroundColor = [UIColor whiteColor];

    self->_layer.frame = self->_viewForLayer.bounds;
    [self->_viewForLayer.layer addSublayer:self->_layer];
}
@end

class CoreAnimationTests {
public:
    BEGIN_TEST_CLASS(CoreAnimationTests)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(CoreAnimationTestsSetup) {
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&UIApplicationDefaultInitialize));
    }

    TEST_METHOD_CLEANUP(CoreAnimationTestsCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    //
    // Validate that the CALayer opacity property change invokes a property change in the backing XAML element
    //
    TEST(CALayerAppearance, OpacityChanged) {
        __block CALayerViewController* caLayerVC;
        __block NSCondition* condition = [[[NSCondition alloc] init] autorelease];
        __block WXUIElement* backingElement = nil;

        dispatch_sync(dispatch_get_main_queue(), ^{
            LOG_INFO("Creating CALayerViewController on the UI thread explicitly");
            caLayerVC = [[CALayerViewController alloc] init];

            // TODO: Remove this line once we hook up to the root view controller which will trigger the view method
            [caLayerVC view];

            // We have to artificially ref the element since the block needs to keep it around
            backingElement = [caLayerVC.layer _xamlElement];
            [backingElement retain];

            // Register callback and wait for the property changed event to trigger
            int64_t callbackToken = [backingElement
                registerPropertyChangedCallback:[WXUIElement opacityProperty]
                                       callback:^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                                           LOG_INFO("Backing XAML element opacity: %f", backingElement.opacity);
                                           LOG_INFO("CALayer.opacity: %f", caLayerVC.layer.opacity);

                                           // Verification
                                           EXPECT_EQ_MSG(backingElement.opacity, caLayerVC.layer.opacity, "Failed to match opacity");
                                           EXPECT_EQ_MSG(backingElement.opacity, 0.5f, "Failed to match opacity with expected value");

                                           // Unregister the callback
                                           [backingElement unregisterPropertyChangedCallback:[WXUIElement opacityProperty]
                                                                                       token:callbackToken];

                                           [condition lock];
                                           [condition signal];
                                           [condition unlock];
                                       }];

            // Action
            caLayerVC.layer.opacity = 0.5f;
        });

        [condition lock];
        ASSERT_TRUE_MSG([condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]],
                        "FAILED: Waiting for property changed event timed out!");
        [condition unlock];

        // Don't leak
        [backingElement release];
        [caLayerVC release];
    }

    //
    // Validate that the CALayer background property change invokes a property change in the backing XAML element
    //
    TEST(CALayerAppearance, BackgroundColorChanged) {
        __block CALayerViewController* caLayerVC;
        __block NSCondition* condition = [[[NSCondition alloc] init] autorelease];
        __block WXUIElement* backingElement = nil;

        dispatch_sync(dispatch_get_main_queue(), ^{
            LOG_INFO("Creating CALayerViewController on the UI thread explicitly");
            caLayerVC = [[CALayerViewController alloc] init];
            [caLayerVC view];

            // We have to artificially ref the element since the block needs to keep it around
            backingElement = [caLayerVC.layer _xamlElement];
            [backingElement retain];

            // Register callback and wait for the property changed event to trigger
            int64_t callbackToken = [backingElement
                registerPropertyChangedCallback:[WXCPanel backgroundProperty]
                                       callback:^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                                           WUXMSolidColorBrush* solidBrush =
                                               rt_dynamic_cast([WUXMSolidColorBrush class], [sender getValue:dp]);
                                           ASSERT_TRUE(solidBrush);

                                           LOG_INFO("Backing XAML element backgroundColor (rgba): %d,%d,%d,%d",
                                                    [solidBrush.color r],
                                                    [solidBrush.color g],
                                                    [solidBrush.color b],
                                                    [solidBrush.color a]);

                                           CGFloat red, green, blue, alpha;
                                           [caLayerVC.layer.backgroundColor getRed:&red green:&green blue:&blue alpha:&alpha];
                                           LOG_INFO("CALayer.backgroundColor (rgba): %.2f,%.2f,%.2f,%.2f", red, green, blue, alpha);

                                           // Validate that the change is reflected on the backing XAML control
                                           EXPECT_EQ_MSG(solidBrush.color.r, (int)(red * 255), @"Failed to match red component");
                                           EXPECT_EQ_MSG(solidBrush.color.g, (int)(green * 255), @"Failed to match green component");
                                           EXPECT_EQ_MSG(solidBrush.color.b, (int)(blue * 255), @"Failed to match blue component");
                                           EXPECT_EQ_MSG(solidBrush.color.a, (int)(alpha * 255), @"Failed to match alpha component");

                                           // Unregister the callback
                                           [backingElement unregisterPropertyChangedCallback:[WXCPanel backgroundProperty]
                                                                                       token:callbackToken];

                                           [condition lock];
                                           [condition signal];
                                           [condition unlock];
                                       }];

            // Action
            caLayerVC.layer.backgroundColor = [UIColor redColor].CGColor;
        });

        [condition lock];
        ASSERT_TRUE_MSG([condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]],
                        "FAILED: Waiting for property changed event timed out!");
        [condition unlock];

        // Don't leak
        [backingElement release];
        [caLayerVC release];
    }
};
