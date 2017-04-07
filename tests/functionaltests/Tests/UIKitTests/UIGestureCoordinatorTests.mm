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
#import <UIkit/UITouch.h>

#import <UIKit/UIGestureRecognizer.h>
#import <UIKit/UITapGestureRecognizer.h>
#import <UIKit/UIGestureRecognizerSubclass.h>
#import <UIKit/UIView.h>

#import <../Frameworks/UIkit/_UIGestureCoordinator.h>

// TestableGestureRcognizer base which can be configed to respond in canPrevent/caBePrevented override
@interface TestableGestureRecognizer : UIGestureRecognizer
@property (nonatomic) BOOL canPrevent;
@property (nonatomic) BOOL canBePrevented;

- (BOOL)canBePreventedByGestureRecognizer:(UIGestureRecognizer*)preventingGestureRecognizer;
- (BOOL)canPreventGestureRecognizer:(UIGestureRecognizer*)preventedGestureRecognizer;

@end

@implementation TestableGestureRecognizer
- (BOOL)canBePreventedByGestureRecognizer:(UIGestureRecognizer*)preventingGestureRecognizer {
    return self.canBePrevented;
}

- (BOOL)canPreventGestureRecognizer:(UIGestureRecognizer*)preventedGestureRecognizer {
    return self.canPrevent;
}
@end

// TestableGestureRcognizer1 respond to TouchBegan to become active
@interface TestableGestureRecognizer1 : TestableGestureRecognizer
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event;
@end

@implementation TestableGestureRecognizer1
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    self.state = UIGestureRecognizerStateBegan;
}
@end

// TestableGestureRcognizer2 respond to TouchBegan to remain in possible
@interface TestableGestureRecognizer2 : TestableGestureRecognizer
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event;
@end

@implementation TestableGestureRecognizer2
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    self.state = UIGestureRecognizerStatePossible;
}
@end

@interface TestableUITouch : UITouch
// overwrite from readonly with read/write
@property (nonatomic) UITouchPhase phase;
@property (nonatomic) UIView* view;
@end

@implementation TestableUITouch
@synthesize phase = _phase;
@synthesize view = _view;
@end

@interface TestableGestureDelegate : NSObject <UIGestureRecognizerDelegate> {
    BOOL delegateInvoked;
}
- (instancetype)initWithReply:(BOOL)reply;
- (BOOL)delegateInvoked;
@end

@implementation TestableGestureDelegate {
    BOOL _reply;
}

- (instancetype)initWithReply:(BOOL)reply {
    if (self = [super init]) {
        _reply = reply;
        delegateInvoked = NO;
    }

    return self;
}

- (BOOL)gestureRecognizer:(UIGestureRecognizer*)gestureRecognizer
    shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer*)otherGestureRecognizer {
    delegateInvoked = YES;
    return _reply;
}

- (BOOL)delegateInvoked {
    return delegateInvoked;
}
@end

// use for UICoordinator Tap Gesture related tests
@interface TestableTapGestureRecognizer : UITapGestureRecognizer
- (void)touchesBegan : (NSSet*)touches withEvent : (UIEvent*)event;
@end

@implementation TestableTapGestureRecognizer
- (void)touchesBegan:(NSSet*)touches withEvent : (UIEvent*)event {
    self.state = UIGestureRecognizerStateBegan;
}

-(BOOL)canBePreventedByGestureRecognizer : (UIGestureRecognizer*)preventingGestureRecognizer {
    return NO;
}

-(BOOL)canPreventGestureRecognizer : (UIGestureRecognizer*)preventedGestureRecognizer {
    return NO;
}
@end

// static helper to create a TouchEvent for TouchBegan Phase. and the touch is associated with a view
// which contains two gestures, one transit to Began when receiving touchBegan
// The other transit to possible when receiveing touchBegan
static TestableUITouch* createTestableUITuch(BOOL activeGestureCanPrevent,
                                             BOOL possibleGestureCanBePrevented,
                                             BOOL addPossibleGestureFirst = NO,
                                             TestableGestureDelegate* activeGestureDelegate = nil,
                                             TestableGestureDelegate* possibleGestureDelegate = nil) {
    TestableUITouch* touch = [[[TestableUITouch alloc] init] autorelease];
    touch.phase = UITouchPhaseBegan;

    UIView* view = [[[UIView alloc] init] autorelease];
    touch.view = view;

    // config activeGesture to say NO to canPrevent/canbePrevented
    TestableGestureRecognizer1* activeGesture = [[[TestableGestureRecognizer1 alloc] init] autorelease];
    activeGesture.canPrevent = activeGestureCanPrevent;
    activeGesture.canBePrevented = YES;
    activeGesture.delegate = activeGestureDelegate;

    // config g2 to say NO to canPrevent/canBePrevented
    TestableGestureRecognizer2* possibleGesture = [[[TestableGestureRecognizer2 alloc] init] autorelease];
    possibleGesture.canPrevent = YES;
    possibleGesture.canBePrevented = possibleGestureCanBePrevented;
    possibleGesture.delegate = possibleGestureDelegate;

    if (addPossibleGestureFirst) {
        [view addGestureRecognizer:possibleGesture];
        [view addGestureRecognizer:activeGesture];
    } else {
        [view addGestureRecognizer:activeGesture];
        [view addGestureRecognizer:possibleGesture];
    }

    return touch;
}

class UIGestureCoordinatorTests {
public:
    BEGIN_TEST_CLASS(UIGestureCoordinatorTests)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(UIKitTestsSetup) {
        return FunctionalTestSetupUIApplication();
    }

    TEST_CLASS_CLEANUP(UIKitTestsCleanup) {
        return FunctionalTestCleanupUIApplication();
    }

    TEST_METHOD(UIGestureCoordinator_ActiveGestureAllowPossibleGesture) {
        // conifg activeGesture can NOT prevent other, and possible gesture can NOT be prevented, adding activeGesture first
        TestableUITouch* touch = createTestableUITuch(NO, NO, YES);
        _UIGestureCoordinator* cooridnator = [[[_UIGestureCoordinator alloc] init] autorelease];
        [cooridnator processGesturesForTouch : touch event : nil touchEventName : @selector(touchesBegan : withEvent : )];

        // after processGestures, check result is expected, since both gestures say NO to prevent each other
        // no gesture is prevented, we are looking for one active gesture and one possible gesture
        NSArray* regularGestures = [cooridnator getRegularGestureRecognizers];
        ASSERT_TRUE([regularGestures count] == 2);
        ASSERT_TRUE(((UIGestureRecognizer*)regularGestures[0]).state == UIGestureRecognizerStatePossible);
        ASSERT_TRUE(((UIGestureRecognizer*)regularGestures[1]).state == UIGestureRecognizerStateBegan);

        NSSet* possibleGesture = [cooridnator getGestureRecognizerInPossibleState];
        ASSERT_TRUE([possibleGesture count] == 1);
    }

    TEST_METHOD(UIGestureCoordinator_ActiveGesturePreventPossibleGestureHasNotReceivedTouch) {
        // conifg activeGesture can prevent other, and possible gesture can be prevented, adding possibleGesture first
        TestableUITouch* touch = createTestableUITuch(YES, YES);
        _UIGestureCoordinator* cooridnator = [[[_UIGestureCoordinator alloc] init] autorelease];
        [cooridnator processGesturesForTouch : touch event : nil touchEventName : @selector(touchesBegan : withEvent : )];

        // after processGestures, check result is expected,
        // in this case, since both gestures says YES to prevent each other
        // and both didn't provide delegates to VOTE, which means they both say NO by default
        // so we are looking for the active gesture will prevent the possible gesture
        NSArray* regularGestures = [cooridnator getRegularGestureRecognizers];

        // one gesture in active state
        ASSERT_TRUE([regularGestures count] == 1);
        ASSERT_TRUE(((UIGestureRecognizer*)regularGestures[0]).state == UIGestureRecognizerStateBegan);

        // no gesture in possible state
        NSSet* possibleGesture = [cooridnator getGestureRecognizerInPossibleState];
        ASSERT_TRUE([possibleGesture count] == 0);
    }

    TEST_METHOD(UIGestureCoordinator_ActiveGesturePreventPossibleGestureHasReceivedTouch) {
        TestableUITouch* touch = createTestableUITuch(YES, YES, NO);
        _UIGestureCoordinator* cooridnator = [[[_UIGestureCoordinator alloc] init] autorelease];
        [cooridnator processGesturesForTouch : touch event : nil touchEventName : @selector(touchesBegan : withEvent : )];

        // after processGestures, check result is expected,
        // in this case, since both gestures says YES to prevent each other
        // and both didn't provide delegates to consult with, which is quivalent of both delegates voting NO
        // so we are expecting active gesture will prevent the possible gesture
        NSArray* regularGestures = [cooridnator getRegularGestureRecognizers];

        // one gesture in active state
        ASSERT_TRUE([regularGestures count] == 1);
        ASSERT_TRUE(((UIGestureRecognizer*)regularGestures[0]).state == UIGestureRecognizerStateBegan);

        // no gesture in possible state
        NSSet* possibleGesture = [cooridnator getGestureRecognizerInPossibleState];
        ASSERT_TRUE([possibleGesture count] == 0);
    }

    TEST_METHOD(UIGestureCoordinator_DelegateAllowConcurrentGestures) {
        TestableGestureDelegate* delegateForPossibleGesture = [[[TestableGestureDelegate alloc] initWithReply:YES] autorelease];
        TestableUITouch* touch = createTestableUITuch(YES, YES, YES, nil, delegateForPossibleGesture);
        _UIGestureCoordinator* cooridnator = [[[_UIGestureCoordinator alloc] init] autorelease];
        [cooridnator processGesturesForTouch : touch event : nil touchEventName : @selector(touchesBegan : withEvent : )];

        // after processGestures, check result is expected,
        // in this case,  both gestures says YES to prevent each other
        // But one of them provides delegate saying concurrent firing is allowed
        // so we are looking for the active gesture will not prevent the possible gesture
        NSArray* regularGestures = [cooridnator getRegularGestureRecognizers];

        // one gesture in possible state, one is active state
        ASSERT_TRUE([regularGestures count] == 2);
        ASSERT_TRUE(((UIGestureRecognizer*)regularGestures[0]).state == UIGestureRecognizerStatePossible);
        ASSERT_TRUE(((UIGestureRecognizer*)regularGestures[1]).state == UIGestureRecognizerStateBegan);

        // make sure the delegate is invoked for voting
        TestableGestureDelegate* d1 = (TestableGestureDelegate*)(((UIGestureRecognizer*)regularGestures[0]).delegate);
        ASSERT_TRUE(d1 != nil);
        ASSERT_TRUE([d1 delegateInvoked]);

        // one gesture in possible state
        NSSet* possibleGesture = [cooridnator getGestureRecognizerInPossibleState];
        ASSERT_TRUE([possibleGesture count] == 1);

        // reset tracking gesture list
        [cooridnator resetTrackingGestureList];
        regularGestures = [cooridnator getRegularGestureRecognizers];

        // make sure earlier active and possible gestures are gone
        ASSERT_TRUE([regularGestures count] == 0);

        possibleGesture = [cooridnator getGestureRecognizerInPossibleState];
        ASSERT_TRUE([possibleGesture count] == 0);
    }

    TEST_METHOD(UIGestureCoordinator_DelegatesForbidConcurrentGestures) {
        TestableGestureDelegate* delegateForPossibleGesture = [[[TestableGestureDelegate alloc] initWithReply:NO] autorelease];
        TestableGestureDelegate* delegateForActiveGesture = [[[TestableGestureDelegate alloc] initWithReply:NO] autorelease];
        TestableUITouch* touch = createTestableUITuch(YES, YES, YES, delegateForActiveGesture, delegateForPossibleGesture);
        _UIGestureCoordinator* cooridnator = [[[_UIGestureCoordinator alloc] init] autorelease];
        [cooridnator processGesturesForTouch : touch event : nil touchEventName : @selector(touchesBegan : withEvent : )];

        // after processGestures, check result is expected,
        // in this case,  both gestures says YES to prevent each other
        // And both provides delegate saying concurrent firing is *not* allowed
        // so we are looking for the active gesture will not prevent the possible gesture
        NSArray* regularGestures = [cooridnator getRegularGestureRecognizers];

        // make sure only one gesture in active state
        ASSERT_TRUE([regularGestures count] == 1);
        ASSERT_TRUE(((UIGestureRecognizer*)regularGestures[0]).state == UIGestureRecognizerStateBegan);

        // make sure its delegate is invoked for voting
        TestableGestureDelegate* d0 = (TestableGestureDelegate*)(((UIGestureRecognizer*)regularGestures[0]).delegate);
        ASSERT_TRUE(d0 != nil);
        ASSERT_TRUE([d0 delegateInvoked]);

        // no gesture in possible state
        NSSet* possibleGesture = [cooridnator getGestureRecognizerInPossibleState];
        ASSERT_TRUE([possibleGesture count] == 0);

        // reset tracking gesture list
        [cooridnator resetTrackingGestureList];
        regularGestures = [cooridnator getRegularGestureRecognizers];

        // make sure earlier active gesture is gone
        ASSERT_TRUE([regularGestures count] == 0);
    }

    TEST_METHOD(UIGestureCoordinator_TapGestureMiscFunctions) {
        TestableUITouch* touch = [[[TestableUITouch alloc] init] autorelease];
        touch.phase = UITouchPhaseMoved;

        UIView* view = [[[UIView alloc] init] autorelease];
        touch.view = view;

        // config multiple Tap getures with different tap count
        TestableTapGestureRecognizer* tapGesture = [[[TestableTapGestureRecognizer alloc] init] autorelease];
        tapGesture.numberOfTapsRequired = 1;
        [view addGestureRecognizer : tapGesture];

        tapGesture = [[[TestableTapGestureRecognizer alloc] init] autorelease];
        tapGesture.numberOfTapsRequired = 10;
        [view addGestureRecognizer : tapGesture];

        tapGesture = [[[TestableTapGestureRecognizer alloc] init] autorelease];
        tapGesture.numberOfTapsRequired = 1000;
        [view addGestureRecognizer : tapGesture];

        _UIGestureCoordinator* cooridnator = [[[_UIGestureCoordinator alloc] init] autorelease];
        [cooridnator processGesturesForTouch : touch event : nil touchEventName : @selector(touchesBegan : withEvent : )];

        // after processGestures, check result is expected,
        // we should three Tap gestures, two of require multiple taps and max required tap count is 1000
        ASSERT_TRUE([cooridnator containsTapGestureRequiredMultipleTap]);
        ASSERT_TRUE([cooridnator maxNubmerOfTapsRequiredInAllTapGestures] == 1000);

        NSArray* regularGestures = [cooridnator getRegularGestureRecognizers];
        ASSERT_TRUE([regularGestures count] == 3);

        // fail all other tap gestures except the first one
        [cooridnator failOtherTapGesturesExcept : regularGestures[0]];

        // make sure we still have one tap gesture left
        ASSERT_TRUE(((UIGestureRecognizer*)regularGestures[0]).state == UIGestureRecognizerStateBegan);
        ASSERT_TRUE(((UIGestureRecognizer*)regularGestures[1]).state == UIGestureRecognizerStateFailed);
        ASSERT_TRUE(((UIGestureRecognizer*)regularGestures[2]).state == UIGestureRecognizerStateFailed);
    }
};

