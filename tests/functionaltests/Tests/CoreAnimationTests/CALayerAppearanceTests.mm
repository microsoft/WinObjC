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

static const NSTimeInterval c_testTimeoutInSec = 5;

@interface CALayerViewController : UIViewController
@property CALayer* layer;
@property UIView* viewForLayer;
@property NSCondition* condition;
@end

@implementation CALayerViewController
- (instancetype)init {
    if (self = [super init]) {
        self->_layer = [CALayer layer];
        self->_condition = [[NSCondition alloc] init];
    }

    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self->_viewForLayer = self.view;
    self->_viewForLayer.frame = CGRectMake(0, 100, 200, 200);
    self->_viewForLayer.backgroundColor = [UIColor whiteColor];

    [self setupLayer];
    [self->_viewForLayer.layer addSublayer:self->_layer];
}

- (void)setupLayer {
    self->_layer.frame = self->_viewForLayer.bounds;

    self->_layer.contentsGravity = kCAGravityCenter;
    self->_layer.cornerRadius = 100.0;
    self->_layer.borderWidth = 12.0;
    self->_layer.borderColor = [UIColor whiteColor].CGColor;

    self->_layer.backgroundColor = [UIColor orangeColor].CGColor;

    self->_layer.opacity = 0.45f;

    self->_layer.shadowOpacity = 0.75;
    self->_layer.shadowRadius = 3.0;
    self->_layer.shadowOffset = CGSizeMake(0, 3);

    self->_layer.magnificationFilter = kCAFilterLinear;
    self->_layer.geometryFlipped = NO;
}
@end

TEST(CALayerAppearance, OpacityChanged) {
    __block CALayerViewController* caLayerVC;

    dispatch_sync(dispatch_get_main_queue(), ^{
        LOG_INFO("Creating CALayerViewController on the UI thread explicitly");
        caLayerVC = [[CALayerViewController alloc] init];
        [caLayerVC view];

        __block WXUIElement* backingElement = [caLayerVC.layer _xamlElement];
        ASSERT_TRUE(backingElement);

        // We have to artificially ref the element since the block needs to keep it around
        [backingElement retain];

        __block int64_t callbackToken = [backingElement
            registerPropertyChangedCallback:[WXUIElement opacityProperty]
                                   callback:^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                // TODO: It seems like backElement can be destroyed even though it is artificially +1'ed for this
                // callback
                LOG_INFO("Backing XAML element opacity: %f", backingElement.opacity);
                LOG_INFO("CALayer.opacity: %f", caLayerVC.layer.opacity);
                ASSERT_TRUE(backingElement.opacity == caLayerVC.layer.opacity);

                // Unregister the callback
                [backingElement unregisterPropertyChangedCallback:[WXUIElement opacityProperty] token:callbackToken];
                [backingElement release];

                [caLayerVC.condition signal];
            }];
    });

    // TODO: Investigate the improved conditioned wait for a response.
    if (![caLayerVC.condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]]) {
        ASSERT_FALSE_MSG(true, "FAILED: Waiting for property changed event timed out!");
    }

    // Don't leak
    [caLayerVC release];
}

TEST(CALayerAppearance, BackgroundColorChanged) {
    __block CALayerViewController* caLayerVC;

    dispatch_sync(dispatch_get_main_queue(), ^{
        LOG_INFO("Creating CALayerViewController on the UI thread explicitly");
        caLayerVC = [[CALayerViewController alloc] init];
        [caLayerVC view];

        __block WXUIElement* backingElement = [caLayerVC.layer _xamlElement];
        ASSERT_TRUE(backingElement);

        // We have to artificially ref the element since the block needs to keep it around
        [backingElement retain];

        __block int64_t callbackToken = [backingElement
            registerPropertyChangedCallback:[WXCPanel backgroundProperty]
                                   callback:^(WXDependencyObject* sender, WXDependencyProperty* dp) {
                WUXMSolidColorBrush* solidBrush = rt_dynamic_cast([WUXMSolidColorBrush class], [sender getValue:dp]);
                if (solidBrush) {
                    LOG_INFO("Backing XAML element backgroundColor (rgba): %d,%d,%d,%d",
                            [solidBrush.color r],
                            [solidBrush.color g],
                            [solidBrush.color b],
                            [solidBrush.color a]);

                    CGFloat red, green, blue, alpha;
                    [caLayerVC.layer.backgroundColor getRed:&red green:&green blue:&blue alpha:&alpha];
                    LOG_INFO("CALayer.backgroundColor (rgba): %.2f,%.2f,%.2f,%.2f", red, green, blue, alpha);

                    // Validate that the change is reflected on the backing XAML control
                    ASSERT_TRUE(solidBrush.color.r == (int)(red * 255));
                    ASSERT_TRUE(solidBrush.color.g == (int)(green * 255));
                    ASSERT_TRUE(solidBrush.color.b == (int)(blue * 255));
                    ASSERT_TRUE(solidBrush.color.a == (int)(alpha * 255));
                } else {
                    ASSERT_FALSE_MSG(true, "Backing XAML element solid color brush not found");
                }

                // Unregister the callback
                [backingElement unregisterPropertyChangedCallback:[WXCPanel backgroundProperty] token:callbackToken];
                [backingElement release];

                [caLayerVC.condition signal];
            }];
        });

    // TODO: Investigate the improved conditioned wait for a response.
    if (![caLayerVC.condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]]) {
        ASSERT_FALSE_MSG(true, "FAILED: Waiting for property changed event timed out!");
    }

    // Don't leak
    [caLayerVC release];
}
