//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#import <Foundation/NSThread.h>
#import <Starboard/SmartTypes.h>
#import <UIKit/UIView.h>
#import "UWP/WindowsUIXamlControls.h"

class UIKitViewTests {
public:
    BEGIN_TEST_CLASS(UIKitViewTests)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(UIKitTestsSetup) {
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&UIApplicationDefaultInitialize));
    }

    TEST_METHOD_CLEANUP(UIKitTestsCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST(UIView, Create) {
        EXPECT_FALSE([NSThread isMainThread]);

        // Try to create and destroy a UIView on a non-UI thread
        [[[UIView alloc] initWithFrame:CGRectMake(0, 0, 10, 10)] release];
    }

    TEST(UIView, GetXamlElement) {
        FrameworkHelper::RunOnUIThread([]() {
            UIView* view = [[[UIView alloc] init] autorelease];
            WXFrameworkElement* backingElement = [view xamlElement];
            ASSERT_TRUE(backingElement);
            ASSERT_TRUE([backingElement isKindOfClass:[WXFrameworkElement class]]);
            ASSERT_TRUE([backingElement.name isEqualToString:@"UIView"]);
        });
    }

    class UIViewTestHelper {
    public:
        UIViewTestHelper() {
            _rootView = [[UIView alloc] init];
            _view0 = [[UIView alloc] init];
            _view1 = [[UIView alloc] init];
            _view2 = [[UIView alloc] init];
            _view3 = [[UIView alloc] init];
            _viewNonSibling = [[UIView alloc] init];

            [_rootView addSubview:_view0];
            [_rootView addSubview:_view1];
            [_rootView addSubview:_view2];
            [_rootView addSubview:_view3];
        }

        int indexOf(UIView* view) {
            NSUInteger index = [[_rootView subviews] indexOfObject:view];

            return (int)index;
        }

        void testInsertSubviewAtIndex(int index) {
            [_rootView insertSubview:_view1 atIndex:index];
            ASSERT_EQ(index, indexOf(_view1));
        }

        void testInsertSubviewBelowSubview(UIView* belowSubview, int expectedIndex) {
            [_rootView insertSubview:_view1 belowSubview:belowSubview];
            ASSERT_EQ(expectedIndex, indexOf(_view1));
        }

        void testInsertSubviewAboveSubview(UIView* aboveSubview, int expectedIndex) {
            [_rootView insertSubview:_view1 aboveSubview:aboveSubview];
            ASSERT_EQ(expectedIndex, indexOf(_view1));
        }

        StrongId<UIView> _rootView;
        StrongId<UIView> _view0;
        StrongId<UIView> _view1;
        StrongId<UIView> _view2;
        StrongId<UIView> _view3;
        StrongId<UIView> _viewNonSibling;
    };

    TEST(UIView, InsertSubviewAtIndex0) {
        FrameworkHelper::RunOnUIThread([]() {
            UIViewTestHelper testHelper;
            testHelper.testInsertSubviewAtIndex(0);
        });
    }

    TEST(UIView, InsertSubviewAtIndex1) {
        FrameworkHelper::RunOnUIThread([]() {
            UIViewTestHelper testHelper;
            testHelper.testInsertSubviewAtIndex(1);
        });
    }

    TEST(UIView, InsertSubviewAtIndex2) {
        FrameworkHelper::RunOnUIThread([]() {
            UIViewTestHelper testHelper;
            testHelper.testInsertSubviewAtIndex(2);
        });
    }

    TEST(UIView, InsertSubviewAtIndex3) {
        FrameworkHelper::RunOnUIThread([]() {
            UIViewTestHelper testHelper;
            testHelper.testInsertSubviewAtIndex(3);
        });
    }

    TEST(UIView, InsertSubviewBelowSubview0) {
        FrameworkHelper::RunOnUIThread([]() {
            UIViewTestHelper testHelper;
            testHelper.testInsertSubviewBelowSubview(testHelper._view0, 0);
        });
    }

    TEST(UIView, InsertSubviewBelowSubview1) {
        FrameworkHelper::RunOnUIThread([]() {
            UIViewTestHelper testHelper;

            // Special case: pops on top
            testHelper.testInsertSubviewBelowSubview(testHelper._view1, 3);
        });
    }

    TEST(UIView, InsertSubviewBelowSubview2) {
        FrameworkHelper::RunOnUIThread([]() {
            UIViewTestHelper testHelper;
            testHelper.testInsertSubviewBelowSubview(testHelper._view2, 1);
        });
    }

    TEST(UIView, InsertSubviewBelowSubview3) {
        FrameworkHelper::RunOnUIThread([]() {
            UIViewTestHelper testHelper;
            testHelper.testInsertSubviewBelowSubview(testHelper._view3, 2);
        });
    }

    TEST(UIView, InsertSubviewAboveSubview0) {
        FrameworkHelper::RunOnUIThread([]() {
            UIViewTestHelper testHelper;
            testHelper.testInsertSubviewAboveSubview(testHelper._view0, 1);
        });
    }

    TEST(UIView, InsertSubviewAboveSubview1) {
        FrameworkHelper::RunOnUIThread([]() {
            UIViewTestHelper testHelper;

            // Special case: pops on top
            testHelper.testInsertSubviewAboveSubview(testHelper._view1, 3);
        });
    }

    TEST(UIView, InsertSubviewAboveSubview2) {
        FrameworkHelper::RunOnUIThread([]() {
            UIViewTestHelper testHelper;
            testHelper.testInsertSubviewAboveSubview(testHelper._view2, 2);
        });
    }

    TEST(UIView, InsertSubviewAboveSubview3) {
        FrameworkHelper::RunOnUIThread([]() {
            UIViewTestHelper testHelper;
            testHelper.testInsertSubviewAboveSubview(testHelper._view3, 3);
        });
    }

    TEST(UIView, InsertSubviewBelowSubviewNonSibling) {
        FrameworkHelper::RunOnUIThread([]() {
            UIViewTestHelper testHelper;

            // Non-sibling pops on top
            testHelper.testInsertSubviewBelowSubview(testHelper._viewNonSibling, 3);
        });
    }

    TEST(UIView, InsertSubviewAboveSubviewNonSibling) {
        FrameworkHelper::RunOnUIThread([]() {
            UIViewTestHelper testHelper;

            // Non-sibling pops on top
            testHelper.testInsertSubviewAboveSubview(testHelper._viewNonSibling, 3);
        });
    }

    TEST(UIView, InsertSubviewBelowSubviewNil) {
        FrameworkHelper::RunOnUIThread([]() {
            UIViewTestHelper testHelper;

            // Nil unaffects index
            testHelper.testInsertSubviewBelowSubview(nil, 1);
        });
    }

    TEST(UIView, InsertSubviewAboveSubviewNil) {
        FrameworkHelper::RunOnUIThread([]() {
            UIViewTestHelper testHelper;

            // Nil unaffects index
            testHelper.testInsertSubviewAboveSubview(nil, 1);
        });
    }
};