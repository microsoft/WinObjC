//******************************************************************************
//
// Copyright Microsoft Corporation. All rights reserved.
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

using namespace UXTestAPI;

static bool _hidesParent(UIModalPresentationStyle style) {
    bool isTablet = UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad;

    if (style == UIModalPresentationPopover) {
        // Popovers (which don't hide their parent) are always presented with WinObjC.
        return false;
    } else if (style == UIModalPresentationFormSheet) {
        return !isTablet;
    }

    return true;
}

class ModeEnabler {
public:
    ModeEnabler(WOCOperationMode mode) {
        dispatch_sync(dispatch_get_main_queue(), ^{
            _oldMode = UIApplication.displayMode.operationMode;
            UIApplication.displayMode.operationMode = mode;
            [UIApplication.displayMode updateDisplaySettings];
        });
    }

    ~ModeEnabler() {
        dispatch_sync(dispatch_get_main_queue(), ^{
            UIApplication.displayMode.operationMode = _oldMode;
            [UIApplication.displayMode updateDisplaySettings];
        });
    }

private:
    WOCOperationMode _oldMode;
};

/*
 * Validates expected appearance events when presented modally and when presenting modally.
 * An instance can be presented from a parent that isn't an instance of ModalEventsTestViewController (though
 * additional validation is enabled when parent and modal are both instances of ModalEventsTestViewController).
 * Validation may fail if attempting to present a non-ModalEventsTestViewController on top of a
 * ModalEventsTestViewController parent.
 */
@interface ModalEventsTestViewController : UIViewController

@property (nonatomic) SEL lastEvent;

@end

@implementation ModalEventsTestViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    EXPECT_EQ(_lastEvent, nullptr);
    _lastEvent = _cmd;
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];

    // The controller is about to be presented for the first time or after a previous dismissal.
    EXPECT_TRUE(sel_isEqual(_lastEvent, @selector(viewDidLoad)) || sel_isEqual(_lastEvent, @selector(viewDidDisappear:)));
    _lastEvent = _cmd;

    EXPECT_NE([self presentingViewController], nil);

    if ([self presentedViewController]) {
        // We've presented a modal (that hid us) which is now being dismissed.

        EXPECT_FALSE([self isBeingPresented]);

        ModalEventsTestViewController* presented = (ModalEventsTestViewController*)[self presentedViewController];

        EXPECT_TRUE(_hidesParent(presented.modalPresentationStyle));

        // viewWillDisappear: on the modal should've come first.
        EXPECT_TRUE(sel_isEqual([presented lastEvent], @selector(viewWillDisappear:)));
    } else {
        // We're a modal being presented.

        EXPECT_TRUE([self isBeingPresented]);

        if ([[self presentingViewController] isKindOfClass:[ModalEventsTestViewController class]]) {
            // Verify presenting view controller's events.

            ModalEventsTestViewController* presenting = (ModalEventsTestViewController*)[self presentingViewController];

            if (_hidesParent(self.modalPresentationStyle)) {
                // We're about to hide the presenting view controller. Verify it received a viewWillDisappear: message first.
                EXPECT_TRUE(sel_isEqual([presenting lastEvent], @selector(viewWillDisappear:)));
            } else {
                // We're not hiding our presenting view controller. It should still be visible.
                EXPECT_TRUE(sel_isEqual([presenting lastEvent], @selector(viewDidAppear:)));
            }
        }
    }
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];

    EXPECT_TRUE(sel_isEqual([self lastEvent], @selector(viewWillAppear:)));
    _lastEvent = _cmd;

    EXPECT_EQ([self presentedViewController], nil);
    EXPECT_NE([self presentingViewController], nil);

    if ([[self presentingViewController] isKindOfClass:[ModalEventsTestViewController class]]) {
        // We can only validate the state of the presentingViewController when it is an instance of this class.

        ModalEventsTestViewController* presenting = (ModalEventsTestViewController*)[self presentingViewController];

        if (_hidesParent(self.modalPresentationStyle)) {
            // We should receive viewDidAppear: before parent receives viewDidDisappear:.
            // Ensure last message sent to parent is viewWillDisappear:
            EXPECT_TRUE(sel_isEqual([presenting lastEvent], @selector(viewWillDisappear:)));
        } else {
            // Parent should still be visible.
            EXPECT_TRUE(sel_isEqual([presenting lastEvent], @selector(viewDidAppear:)));
        }
    }
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];

    EXPECT_TRUE(sel_isEqual([self lastEvent], @selector(viewDidAppear:)));
    _lastEvent = _cmd;

    if ([self presentedViewController]) {
        // About to be covered by presented modal

        EXPECT_FALSE([self isBeingDismissed]);

        ModalEventsTestViewController* presented = (ModalEventsTestViewController*)[self presentedViewController];

        EXPECT_TRUE(_hidesParent(presented.modalPresentationStyle));

        // We should receive viewWillDisappear: before presented receives viewWillAppear:
        // Ensure presented is displaying for the first time (or was previously dismissed)
        EXPECT_TRUE(sel_isEqual([presented lastEvent], @selector(viewDidLoad)) ||
                    sel_isEqual([presented lastEvent], @selector(viewDidDisappear:)));
    } else {
        // About to be dismissed

        EXPECT_TRUE([self isBeingDismissed]);

        EXPECT_NE([self presentingViewController], nil);

        if ([[self presentingViewController] isKindOfClass:[ModalEventsTestViewController class]]) {
            ModalEventsTestViewController* presenting = (ModalEventsTestViewController*)[self presentingViewController];

            if (_hidesParent(self.modalPresentationStyle)) {
                // We should receive viewWillDisappear: before presenting receives viewWillAppear:
                EXPECT_TRUE(sel_isEqual([presenting lastEvent], @selector(viewDidDisappear:)));
            } else {
                EXPECT_TRUE(sel_isEqual([presenting lastEvent], @selector(viewDidAppear:)));
            }
        }
    }
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];

    EXPECT_TRUE(sel_isEqual(_lastEvent, @selector(viewWillDisappear:)));
    _lastEvent = _cmd;

    if ([self presentedViewController]) {
        // Modal is covering us.

        EXPECT_FALSE([self isBeingDismissed]);

        EXPECT_NE([self presentingViewController], nil);

        ModalEventsTestViewController* presented = (ModalEventsTestViewController*)[self presentedViewController];

        EXPECT_TRUE(_hidesParent(presented.modalPresentationStyle));

        // presented should receive viewDidAppear: first.
        EXPECT_TRUE(sel_isEqual([presented lastEvent], @selector(viewDidAppear:)));
    } else {
        // We're a dismissed modal.
        EXPECT_EQ([self presentingViewController], nil);

        EXPECT_TRUE([self isBeingDismissed]);
    }
}

@end

class UIViewControllerModalTest : public ::testing::TestWithParam<::testing::tuple<UIModalPresentationStyle, WOCOperationMode, BOOL>> {
protected:
    virtual void SetUp() {
        FunctionalTestSetupUIApplication();
    }

    virtual void TearDown() {
        FunctionalTestCleanupUIApplication();
    }

    void TestModalPresentDismiss(UIModalPresentationStyle style, BOOL animated) {
        auto initialPresentEvent = UXEvent::CreateManual();
        auto finalPresentEvent = UXEvent::CreateManual();
        auto initialDismissEvent = UXEvent::CreateManual();
        auto finalDismissEvent = UXEvent::CreateManual();

        dispatch_async(dispatch_get_main_queue(), ^{

            UIWindow* currentWindow = GetCurrentWindow();

            // Avoid capture of |presenting| in block to ensure presentViewController mechanism keeps it alive.
            __block StrongId<ModalEventsTestViewController> presenting;

            presenting.attach([[ModalEventsTestViewController alloc] init]);

            // Assume rootViewController is top-most.
            [currentWindow.rootViewController
                presentViewController:presenting
                             animated:NO
                           completion:^{
                               initialPresentEvent->Set();

                               EXPECT_TRUE(sel_isEqual([presenting lastEvent], @selector(viewDidAppear:)));

                               EXPECT_FALSE([presenting isBeingPresented]);

                               StrongId<ModalEventsTestViewController> presented;
                               presented.attach([[ModalEventsTestViewController alloc] init]);
                               [presented setModalPresentationStyle:style];

                               [presenting
                                   presentViewController:presented
                                                animated:animated
                                              completion:^{
                                                  finalPresentEvent->Set();

                                                  EXPECT_FALSE([presented isBeingPresented]);
                                                  EXPECT_FALSE([presenting isBeingDismissed]);

                                                  if (_hidesParent(style)) {
                                                      EXPECT_TRUE(sel_isEqual([presenting lastEvent], @selector(viewDidDisappear:)));
                                                  }

                                                  EXPECT_TRUE(sel_isEqual([presented lastEvent], @selector(viewDidAppear:)));

                                                  [presenting dismissViewControllerAnimated:animated
                                                                                 completion:^{
                                                                                     initialDismissEvent->Set();

                                                                                     EXPECT_FALSE([presenting isBeingDismissed]);

                                                                                     EXPECT_TRUE(sel_isEqual([presented lastEvent],
                                                                                                             @selector(viewDidDisappear:)));
                                                                                     EXPECT_TRUE(sel_isEqual([presenting lastEvent],
                                                                                                             @selector(viewDidAppear:)));

                                                                                     [presenting
                                                                                         dismissViewControllerAnimated:animated
                                                                                                            completion:^{
                                                                                                                finalDismissEvent->Set();
                                                                                                            }];
                                                                                 }];
                                              }];

                               if (style == UIModalPresentationPopover) {
                                   [presented popoverPresentationController].sourceView = [presenting view];
                                   [presented popoverPresentationController].sourceRect =
                                       CGRectMake([presenting view].bounds.size.width / 2, [presenting view].bounds.size.height / 2, 1, 1);
                               }
                           }];
        });

        ASSERT_TRUE_MSG(initialPresentEvent->Wait(5), "FAILED: Waiting for initial present completion timed out!");
        ASSERT_TRUE_MSG(finalPresentEvent->Wait(5), "FAILED: Waiting for final present completion timed out!");
        ASSERT_TRUE_MSG(initialDismissEvent->Wait(5), "FAILED: Waiting for initial dismiss completion timed out!");
        ASSERT_TRUE_MSG(finalDismissEvent->Wait(5), "FAILED: Waiting for final dismiss completion timed out!");
    }
};

TEST_P(UIViewControllerModalTest, PresentDismiss) {
    UIModalPresentationStyle style = ::testing::get<0>(GetParam());
    WOCOperationMode mode = ::testing::get<1>(GetParam());
    BOOL animated = ::testing::get<2>(GetParam());

    ModeEnabler enabler(mode);
    TestModalPresentDismiss(style, animated);
}

static constexpr UIModalPresentationStyle c_presentationStyles[] = { UIModalPresentationFullScreen,
                                                                     UIModalPresentationFormSheet,
                                                                     UIModalPresentationPopover };

static constexpr WOCOperationMode c_operationModes[] = { WOCOperationModePhone, WOCOperationModeTablet };

// TODO: Add animated=YES option upon resolution of issue #2576.
static constexpr BOOL c_animationModes[] = { NO };

INSTANTIATE_TEST_CASE_P(PresentDismiss,
                        UIViewControllerModalTest,
                        ::testing::Combine(::testing::ValuesIn(c_presentationStyles),
                                           ::testing::ValuesIn(c_operationModes),
                                           ::testing::ValuesIn(c_animationModes)));
