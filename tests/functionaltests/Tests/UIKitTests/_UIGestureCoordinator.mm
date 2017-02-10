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

// TestableGestureRcognizer1 respond to TouchBegan to remain in possible
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
@end

@implementation TestableUITouch
@synthesize phase = _phase;
@end

@interface TestableUIGestureCoordinator : _UIGestureCoordinator
@end

@implementation TestableUIGestureCoordinator
- (void)buildTrackingGesturesListWith:(NSMutableArray*)regularRecognizers
                     PossibleGestures:(NSMutableSet*)gesturesInPossibleState
                        DManipGesture:(NSMutableArray*)dManipRecognizers {
    // config g1 to say NO to canPrevent/canbePrevented
    TestableGestureRecognizer1* g1 = [[[TestableGestureRecognizer1 alloc] init] autorelease];
    g1.canPrevent = NO;
    g1.canBePrevented = NO;
    [regularRecognizers addObject:g1];
    if ([g1 state] == UIGestureRecognizerStatePossible) {
        [gesturesInPossibleState addObject:g1];
    }

    // config g2 to say NO to canPrevent/canBePrevented
    TestableGestureRecognizer2* g2 = [[[TestableGestureRecognizer2 alloc] init] autorelease];
    g2.canPrevent = NO;
    g2.canBePrevented = NO;
    [regularRecognizers addObject:g2];
    if ([g2 state] == UIGestureRecognizerStatePossible) {
        [gesturesInPossibleState addObject:g2];
    }
}
@end

TEST(_UIGestureCoordinator, ActiveGestureAllowPossibleGesture) {
    // creating gesture coordinator
    TestableUIGestureCoordinator* cooridnator = [[[TestableUIGestureCoordinator alloc] init] autorelease];

    // create a TouchBgan
    TestableUITouch* touchBegan = [[[TestableUITouch alloc] init] autorelease];
    touchBegan.phase = UITouchPhaseBegan;

    // Gesturecoordinator process TouchBegan, which in terms popluate custom gestures first
    [cooridnator processGesturesForTouch:touchBegan event:nil touchEventName:@selector(touchesBegan:withEvent:)];

    // after processGestures, check result is expected, since both gestures say NO to prevent each other
    // no gesture is prevented, we are looking for one active gesture and one possible gesture
    NSArray* regularGestures = [cooridnator getRegularGestureRecognizers];
    ASSERT_TRUE([regularGestures count] == 2);
    ASSERT_TRUE(((UIGestureRecognizer*)regularGestures[0]).state == UIGestureRecognizerStateBegan);
    ASSERT_TRUE(((UIGestureRecognizer*)regularGestures[1]).state == UIGestureRecognizerStatePossible);

    NSSet* possibleGesture = [cooridnator getGestureRecognizerInPossibleState];
    ASSERT_TRUE([possibleGesture count] == 1);
}

@interface TestableUIGestureCoordinator2 : _UIGestureCoordinator
@end

@implementation TestableUIGestureCoordinator2
- (void)buildTrackingGesturesListWith:(NSMutableArray*)regularRecognizers
                     PossibleGestures:(NSMutableSet*)gesturesInPossibleState
                        DManipGesture:(NSMutableArray*)dManipRecognizers {
    // config g1 to say NO to canPrevent/canbePrevented
    TestableGestureRecognizer1* g1 = [[[TestableGestureRecognizer1 alloc] init] autorelease];
    g1.canPrevent = YES;
    g1.canBePrevented = YES;
    [regularRecognizers addObject:g1];
    if ([g1 state] == UIGestureRecognizerStatePossible) {
        [gesturesInPossibleState addObject:g1];
    }

    // config g1 to say NO to canPrevent/canbePrevented
    TestableGestureRecognizer2* g2 = [[[TestableGestureRecognizer2 alloc] init] autorelease];
    g2.canPrevent = YES;
    g2.canBePrevented = YES;
    [regularRecognizers addObject:g2];
    if ([g2 state] == UIGestureRecognizerStatePossible) {
        [gesturesInPossibleState addObject:g2];
    }
}
@end

TEST(_UIGestureCoordinator, ActiveGesturePreventPossibleGestureHasNotReceivedTouch) {
    TestableUIGestureCoordinator2* cooridnator = [[[TestableUIGestureCoordinator2 alloc] init] autorelease];
    TestableUITouch* touchBegan = [[[TestableUITouch alloc] init] autorelease];
    touchBegan.phase = UITouchPhaseBegan;
    [cooridnator processGesturesForTouch:touchBegan event:nil touchEventName:@selector(touchesBegan:withEvent:)];

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

@interface TestableUIGestureCoordinator3 : _UIGestureCoordinator
@end

@implementation TestableUIGestureCoordinator3
- (void)buildTrackingGesturesListWith:(NSMutableArray*)regularRecognizers
                     PossibleGestures:(NSMutableSet*)gesturesInPossibleState
                        DManipGesture:(NSMutableArray*)dManipRecognizers {
    // config g2 to say YES to canPrevent/canbePrevented
    TestableGestureRecognizer2* g2 = [[[TestableGestureRecognizer2 alloc] init] autorelease];
    g2.canPrevent = YES;
    g2.canBePrevented = YES;
    [regularRecognizers addObject:g2];
    if ([g2 state] == UIGestureRecognizerStatePossible) {
        [gesturesInPossibleState addObject:g2];
    }

    // config g1 to say YES to canPrevent/canbePrevented
    TestableGestureRecognizer1* g1 = [[[TestableGestureRecognizer1 alloc] init] autorelease];
    g1.canPrevent = YES;
    g1.canBePrevented = YES;
    [regularRecognizers addObject:g1];
    if ([g1 state] == UIGestureRecognizerStatePossible) {
        [gesturesInPossibleState addObject:g1];
    }
}
@end

TEST(_UIGestureCoordinator, ActiveGesturePreventPossibleGestureHasReceivedTouch) {
    TestableUIGestureCoordinator3* cooridnator = [[[TestableUIGestureCoordinator3 alloc] init] autorelease];
    TestableUITouch* touchBegan = [[[TestableUITouch alloc] init] autorelease];
    touchBegan.phase = UITouchPhaseBegan;
    [cooridnator processGesturesForTouch:touchBegan event:nil touchEventName:@selector(touchesBegan:withEvent:)];

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

@interface TestableUIGestureCoordinator4 : _UIGestureCoordinator
@end

@implementation TestableUIGestureCoordinator4
- (void)buildTrackingGesturesListWith:(NSMutableArray*)regularRecognizers
                     PossibleGestures:(NSMutableSet*)gesturesInPossibleState
                        DManipGesture:(NSMutableArray*)dManipRecognizers {
    // config g2 to say YES to canPrevnt/canbePrevented
    TestableGestureRecognizer2* g2 = [[[TestableGestureRecognizer2 alloc] init] autorelease];
    g2.canPrevent = YES;
    g2.canBePrevented = YES;
    [regularRecognizers addObject:g2];
    if ([g2 state] == UIGestureRecognizerStatePossible) {
        [gesturesInPossibleState addObject:g2];
    }

    // config g2' delegate to say YES when being asked if concurrent firing is allowed
    TestableGestureDelegate* delegate2 = [[[TestableGestureDelegate alloc] initWithReply:YES] autorelease];
    g2.delegate = delegate2;

    // config g1 to say YES to canPrevnt/canbePrevented
    TestableGestureRecognizer1* g1 = [[[TestableGestureRecognizer1 alloc] init] autorelease];
    g1.canPrevent = YES;
    g1.canBePrevented = YES;
    [regularRecognizers addObject:g1];
    if ([g1 state] == UIGestureRecognizerStatePossible) {
        [gesturesInPossibleState addObject:g1];
    }
}
@end

TEST(_UIGestureCoordinator, DelegateAllowConcurrentGestures) {
    TestableUIGestureCoordinator4* cooridnator = [[[TestableUIGestureCoordinator4 alloc] init] autorelease];
    TestableUITouch* touchBegan = [[[TestableUITouch alloc] init] autorelease];
    touchBegan.phase = UITouchPhaseBegan;
    [cooridnator processGesturesForTouch:touchBegan event:nil touchEventName:@selector(touchesBegan:withEvent:)];

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

@interface TestableUIGestureCoordinator5 : _UIGestureCoordinator
@end

@implementation TestableUIGestureCoordinator5
- (void)buildTrackingGesturesListWith:(NSMutableArray*)regularRecognizers
                     PossibleGestures:(NSMutableSet*)gesturesInPossibleState
                        DManipGesture:(NSMutableArray*)dManipRecognizers {
    // config g2 to say YES to canPrevnt/canbePrevented
    TestableGestureRecognizer2* g2 = [[[TestableGestureRecognizer2 alloc] init] autorelease];
    g2.canPrevent = YES;
    g2.canBePrevented = YES;
    [regularRecognizers addObject:g2];
    if ([g2 state] == UIGestureRecognizerStatePossible) {
        [gesturesInPossibleState addObject:g2];
    }

    // config g2' delegate to say NO when being asked if concurrent firing is not allowed
    TestableGestureDelegate* delegate2 = [[[TestableGestureDelegate alloc] initWithReply:NO] autorelease];
    g2.delegate = delegate2;

    // config g1 to say YES to canPrevnt/canbePrevented
    TestableGestureRecognizer1* g1 = [[[TestableGestureRecognizer1 alloc] init] autorelease];
    g1.canPrevent = YES;
    g1.canBePrevented = YES;
    [regularRecognizers addObject:g1];
    if ([g1 state] == UIGestureRecognizerStatePossible) {
        [gesturesInPossibleState addObject:g1];
    }
    // config g1' delegate to say NO when being asked if concurrent firing is not allowed
    TestableGestureDelegate* delegate1 = [[[TestableGestureDelegate alloc] initWithReply:NO] autorelease];
    g1.delegate = delegate1;
}
@end

TEST(_UIGestureCoordinator, DelegatesForbidConcurrentGestures) {
    TestableUIGestureCoordinator5* cooridnator = [[[TestableUIGestureCoordinator5 alloc] init] autorelease];
    TestableUITouch* touchBegan = [[[TestableUITouch alloc] init] autorelease];
    touchBegan.phase = UITouchPhaseBegan;
    [cooridnator processGesturesForTouch:touchBegan event:nil touchEventName:@selector(touchesBegan:withEvent:)];

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

// use for UICoordinator Tap Gesture related tests
@interface TestableTapGestureRecognizer : UITapGestureRecognizer
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event;
@end

@implementation TestableTapGestureRecognizer
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    self.state = UIGestureRecognizerStateBegan;
}
@end

@interface TestableUIGestureCoordinator6 : _UIGestureCoordinator
@end

@implementation TestableUIGestureCoordinator6
// override to popluate gestures
- (void)buildTrackingGesturesListWith:(NSMutableArray*)regularRecognizers
                     PossibleGestures:(NSMutableSet*)gesturesInPossibleState
                        DManipGesture:(NSMutableArray*)dManipRecognizers {
    // config multiple Tap getures with different tap count
    TestableTapGestureRecognizer* tapGesture = [[[TestableTapGestureRecognizer alloc] init] autorelease];
    tapGesture.numberOfTapsRequired = 1;
    [regularRecognizers addObject:tapGesture];

    tapGesture = [[[TestableTapGestureRecognizer alloc] init] autorelease];
    tapGesture.numberOfTapsRequired = 10;
    [regularRecognizers addObject:tapGesture];

    tapGesture = [[[TestableTapGestureRecognizer alloc] init] autorelease];
    tapGesture.numberOfTapsRequired = 1000;
    [regularRecognizers addObject:tapGesture];
}
@end

TEST(_UIGestureCoordinator, TapGestureMiscFunctions) {
    TestableUIGestureCoordinator6* cooridnator = [[[TestableUIGestureCoordinator6 alloc] init] autorelease];
    TestableUITouch* touchBegan = [[[TestableUITouch alloc] init] autorelease];
    touchBegan.phase = UITouchPhaseBegan;
    [cooridnator processGesturesForTouch:touchBegan event:nil touchEventName:@selector(touchesBegan:withEvent:)];

    // after processGestures, check result is expected,
    // we should three Tap gestures, two of require multiple taps and max required tap count is 1000
    ASSERT_TRUE([cooridnator containsTapGestureRequiredMultipleTap]);
    ASSERT_TRUE([cooridnator maxNubmerOfTapsRequiredInAllTapGestures] == 1000);

    NSArray* regularGestures = [cooridnator getRegularGestureRecognizers];
    ASSERT_TRUE([regularGestures count] == 3);

    // fail all other tap gestures except the first one
    [cooridnator failOtherTapGesturesExcept:regularGestures[0]];

    // make sure we still have one tap gesture left
    ASSERT_TRUE(((UIGestureRecognizer*)regularGestures[0]).state == UIGestureRecognizerStateBegan);
    ASSERT_TRUE(((UIGestureRecognizer*)regularGestures[1]).state == UIGestureRecognizerStateFailed);
    ASSERT_TRUE(((UIGestureRecognizer*)regularGestures[2]).state == UIGestureRecognizerStateFailed);
}