//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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
#import "Starboard/SmartTypes.h"
#import "CALayerInternal.h"
#import "NullCompositor.h"

class UIViewTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        static bool initialized;

        if (!initialized) {
            SetCACompositor(new NullCompositor);
            initialized = true;
        }

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

    virtual void TearDown() {
        _view0 = nil;
        _view1 = nil;
        _view2 = nil;
        _view3 = nil;
        _rootView = nil;
        _viewNonSibling = nil;
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

TEST_F(UIViewTest, InsertSubviewAtIndex0) {
    testInsertSubviewAtIndex(0);
}

TEST_F(UIViewTest, InsertSubviewAtIndex1) {
    testInsertSubviewAtIndex(1);
}

TEST_F(UIViewTest, InsertSubviewAtIndex2) {
    testInsertSubviewAtIndex(2);
}

TEST_F(UIViewTest, InsertSubviewAtIndex3) {
    testInsertSubviewAtIndex(3);
}

TEST_F(UIViewTest, InsertSubviewBelowSubview0) {
    testInsertSubviewBelowSubview(_view0, 0);
}

TEST_F(UIViewTest, InsertSubviewBelowSubview1) {
    // Special case: pops on top
    testInsertSubviewBelowSubview(_view1, 3);
}

TEST_F(UIViewTest, InsertSubviewBelowSubview2) {
    testInsertSubviewBelowSubview(_view2, 1);
}

TEST_F(UIViewTest, InsertSubviewBelowSubview3) {
    testInsertSubviewBelowSubview(_view3, 2);
}

TEST_F(UIViewTest, InsertSubviewAboveSubview0) {
    testInsertSubviewAboveSubview(_view0, 1);
}

TEST_F(UIViewTest, InsertSubviewAboveSubview1) {
    // Special case: pops on top
    testInsertSubviewAboveSubview(_view1, 3);
}

TEST_F(UIViewTest, InsertSubviewAboveSubview2) {
    testInsertSubviewAboveSubview(_view2, 2);
}

TEST_F(UIViewTest, InsertSubviewAboveSubview3) {
    testInsertSubviewAboveSubview(_view3, 3);
}

TEST_F(UIViewTest, InsertSubviewBelowSubviewNonSibling) {
    // Non-sibling pops on top
    testInsertSubviewBelowSubview(_viewNonSibling, 3);
}

TEST_F(UIViewTest, InsertSubviewAboveSubviewNonSibling) {
    // Non-sibling pops on top
    testInsertSubviewAboveSubview(_viewNonSibling, 3);
}

TEST_F(UIViewTest, InsertSubviewBelowSubviewNil) {
    // Nil unaffects index
    testInsertSubviewBelowSubview(nil, 1);
}

TEST_F(UIViewTest, InsertSubviewAboveSubviewNil) {
    // Nil unaffects index
    testInsertSubviewAboveSubview(nil, 1);
}