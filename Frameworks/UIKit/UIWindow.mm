//******************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
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

#import "Starboard.h"
#import <StubReturn.h>
#import "AssertARCEnabled.h"

#import <UIKit/UIApplication.h>
#import <UIKit/UIScreen.h>
#import <UIKit/UITouch.h>
#import <UIKit/UIView.h>
#import <UIKit/UIViewController.h>
#import <UIKit/UIWindow.h>


#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGAffineTransform.h>

#import <Foundation/NSNotificationCenter.h>

#import <QuartzCore/CALayer.h>
#import <QuartzCore/CATransaction.h>

#import "LoggingNative.h"
#import "UIApplicationInternal.h"
#import "CALayerInternal.h"
#import "UIDeviceInternal.h"
#import "CATransactionInternal.h"
#import "StarboardXaml/DisplayProperties.h"

static const wchar_t* TAG = L"UIWindow";

UIWindow* _curKeyWindow = nil;

NSString* const UIWindowDidBecomeVisibleNotification = @"UIWindowDidBecomeVisibleNotification";
NSString* const UIWindowDidBecomeHiddenNotification = @"UIWindowDidBecomeHiddenNotification";
NSString* const UIWindowDidBecomeKeyNotification = @"UIWindowDidBecomeKeyNotification";
NSString* const UIWindowDidResignKeyNotification = @"UIWindowDidResignKeyNotification";

NSString* const UIKeyboardFrameBeginUserInfoKey = @"UIKeyboardFrameBeginUserInfoKey";
NSString* const UIKeyboardFrameEndUserInfoKey = @"UIKeyboardFrameEndUserInfoKey";
NSString* const UIKeyboardAnimationDurationUserInfoKey = @"UIKeyboardAnimationDurationUserInfoKey";
NSString* const UIKeyboardAnimationCurveUserInfoKey = @"UIKeyboardAnimationCurveUserInfoKey";

NSString* const UIKeyboardWillShowNotification = @"UIKeyboardWillShowNotification";
NSString* const UIKeyboardDidShowNotification = @"UIKeyboardDidShowNotification";
NSString* const UIKeyboardWillHideNotification = @"UIKeyboardWillHideNotification";
NSString* const UIKeyboardDidHideNotification = @"UIKeyboardDidHideNotification";
NSString* const UIKeyboardBoundsUserInfoKey = @"UIKeyboardBoundsUserInfoKey";
NSString* const UIKeyboardCenterBeginUserInfoKey = @"UIKeyboardCenterBeginUserInfoKey";
NSString* const UIKeyboardCenterEndUserInfoKey = @"UIKeyboardCenterEndUserInfoKey";
NSString* const UIKeyboardIsLocalUserInfoKey = @"UIKeyboardIsLocalUserInfoKey";

NSString* const UIKeyboardWillChangeFrameNotification = @"UIKeyboardWillChangeFrameNotification";
NSString* const UIKeyboardDidChangeFrameNotification = @"UIKeyboardDidChangeFrameNotification";

const UIWindowLevel UIWindowLevelNormal = 0.0f;
const UIWindowLevel UIWindowLevelAlert = 2000.0f;
const UIWindowLevel UIWindowLevelStatusBar = 1000.0f;

@implementation UIWindow {
@private
    StrongId<UIViewController> _rootViewController;
    UIWindowLevel _windowLevel;
    BOOL _sizeUIWindowToFit;
}

-(void)_initUIWindow {
    // Configure the root Window to be a transparent 'root' layer
    CALayer* ourLayer = [self layer];
    [ourLayer setOpaque:FALSE];
    [ourLayer _setRootLayer:TRUE];
    [CATransaction _addSublayerToTop:ourLayer];
    [ourLayer _layerProxy]->SetTopMost();

    // Configure the Window level and size
    [self setWindowLevel:UIWindowLevelNormal];
    [self setSizeUIWindowToFit:[[UIApplication displayMode] sizeUIWindowToFit]];

    // Add ourself to the sharedApplication's windows collection
    [static_cast<NSMutableArray*>([[UIApplication sharedApplication] windows]) addObject:self];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)pos {
    //  We are ourself, a view
    if (self = [super initWithFrame:pos]) {
        [self _initUIWindow];

        // Become the key window if there isn't one already
        // Note: It's unclear whether or not this matches reference platform behavior.
        if (![[UIApplication sharedApplication] keyWindow]) {
            [self makeKeyWindow];
        }
    }

    return self;
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        // Set our frame before initializing, since initializing does a resize to fit the application window
        [super setFrame:[[UIScreen mainScreen] bounds]];
        [self _initUIWindow];
    }

    return self;
}

- (UIWindow*)_getWindowInternal {
    return self;
}

- (void)_moveToTopOfSameLevel {
    id windows = [[UIApplication sharedApplication] windows];
    int windowCount = [windows count];
    int idxOfCurrentWindow = [windows indexOfObject:self];

    // Nothing needed if the current window is the last one in windows arrary
    if (idxOfCurrentWindow == windowCount - 1) {
        return;
    }

    // Nothing needed if the window level of next window is larger than current one
    UIWindow* nextWindow = (UIWindow*)[windows objectAtIndex:idxOfCurrentWindow + 1];
    if (nextWindow.windowLevel > _windowLevel) {
        return;
    }

    // Get the index of the window whose window level is larger than current window's and calculate the new position
    int nextLevelIndex = [windows indexOfObjectPassingTest:^BOOL(id obj, NSUInteger idx, BOOL* stop) {
        if ([(UIWindow*)obj windowLevel] > _windowLevel) {
            *stop = YES;
            return YES;
        }
        return NO;
    }];

    int idxOfNewPosition = 0;
    if (nextLevelIndex == NSNotFound) {
        idxOfNewPosition = windowCount - 1;
    } else {
        idxOfNewPosition = nextLevelIndex - 1;
    }

    // Move current window to the last one of windows with same window level
    [static_cast<NSMutableArray*>(windows) removeObjectAtIndex:idxOfCurrentWindow];
    [static_cast<NSMutableArray*>(windows) insertObject:self atIndex:idxOfNewPosition];

    // Reset the ZIndex property of the windows impacted
    for (int i = idxOfCurrentWindow; i <= idxOfNewPosition; i++) {
        UIWindow* window = (UIWindow*)[windows objectAtIndex:i];
        [window.layer _setZIndex:i + 1];
    }
}

/**
 @Status Interoperable
*/
- (void)makeKeyAndVisible {
    [self setHidden:FALSE];
    [self makeKeyWindow];
    [self _moveToTopOfSameLevel];
}

/**
 @Status Interoperable
*/
- (void)makeKeyWindow {
    [self becomeKeyWindow];
}

/**
 @Status Interoperable
*/
- (void)becomeKeyWindow {
    _curKeyWindow = self;
    [[NSNotificationCenter defaultCenter] postNotificationName:@"UIWindowDidBecomeKeyNotification" object:self];
}

/**
 @Status Interoperable
*/
- (void)resignKeyWindow {
    _curKeyWindow = nil;
}

/**
 @Status Interoperable
*/
- (BOOL)isKeyWindow {
    if (_curKeyWindow == self) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 @Status Interoperable
*/
- (UIResponder*)nextResponder {
    return [UIApplication sharedApplication];
}

/**
 @Status Interoperable
*/
- (UIViewController*)rootViewController {
    return _rootViewController;
}

/**
 @Status Interoperable
*/
- (void)setRootViewController:(UIViewController*)controller {
    _rootViewController = controller;

    id controllerView = [controller view];

    if (controllerView != nil) {
        [self addSubview:controllerView];
        CGRect screenFrame;
        if ([static_cast<UIViewController*>(_rootViewController) wantsFullScreenLayout]) {
            screenFrame = [[UIScreen mainScreen] bounds];
        } else {
            screenFrame = [[UIScreen mainScreen] applicationFrame];
        }

        [[static_cast<UIViewController*>(_rootViewController) view] setFrame:screenFrame];
    }

    if (controller && [controller respondsToSelector:@selector(preferredInterfaceOrientationForPresentation)]) {
        UIDeviceOrientation ourOrientation = static_cast<UIDeviceOrientation>([controller preferredInterfaceOrientationForPresentation]);
        [[UIDevice currentDevice] _setOrientation:ourOrientation animated:FALSE];
    }
}

/**
 Microsoft Extension
*/
- (BOOL)sizeUIWindowToFit {
    return _sizeUIWindowToFit;
}

/**
 Microsoft Extension
*/
- (void)setSizeUIWindowToFit:(BOOL)shouldSize {
    _sizeUIWindowToFit = shouldSize;
}

// TODO: #2440 Remove this seemingly-unnecessary private method (why not call the public setRootViewController?)
- (void)_setRootViewController:(UIViewController*)controller {
    _rootViewController = controller;
    if (controller) {
        id view = [controller view];

        if ([[view superview] isKindOfClass:[UIWindow class]]) {
            TraceVerbose(TAG, L"Setting root controller to %hs", object_getClassName(controller));
            CGRect screenFrame;
            screenFrame = [[UIScreen mainScreen] applicationFrame];
            [view setFrame:screenFrame];
        }
    } else {
        TraceVerbose(TAG, L"Setting root controller to nil");
    }
}

- (NSInteger)_compareWindowLevel:(id)other {
    float level1 = [self windowLevel];
    float level2 = [other windowLevel];

    if (level1 > level2) {
        return 1;
    } else if (level1 < level2) {
        return -1;
    } else {
        return 0;
    }
}

/**
 @Status Interoperable
*/
- (void)setWindowLevel:(float)level {
    _windowLevel = level;
    [static_cast<NSMutableArray*>([[UIApplication sharedApplication] windows]) sortUsingSelector:@selector(_compareWindowLevel:)];
    int zIndex = 0;
    for (UIWindow* window in [[UIApplication sharedApplication] windows]) {
        [window.layer _setZIndex:++zIndex];
    }
}

/**
 @Status Interoperable
*/
- (UIWindowLevel)windowLevel {
    return _windowLevel;
}

/**
 @Status NotInPlan
 @Notes Multi-screen apps can be built using WinRT APIs.
*/
- (void)setScreen:(UIScreen*)screen {
    UNIMPLEMENTED_WITH_MSG("Multi-screen apps can be built using WinRT APIs.");
}

/**
 @Status NotInPlan
 @Notes Multi-screen apps can be built using WinRT APIs.
*/
- (UIScreen*)screen {
    UNIMPLEMENTED_WITH_MSG("Multi-screen apps can be built using WinRT APIs.");
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [CATransaction _removeLayer:[self layer]];
    [static_cast<NSMutableArray*>([[UIApplication sharedApplication] windows]) removeObject:self];
}

/**
 @Status Stub
*/
- (CGPoint)convertPoint:(CGPoint)point toWindow:(UIWindow*)window {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGPoint)convertPoint:(CGPoint)point fromWindow:(UIWindow*)window {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
-(CGRect)convertRect:(CGRect)rect toWindow:(UIWindow*)window {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGRect)convertRect:(CGRect)rect fromWindow:(UIWindow*)window {
    UNIMPLEMENTED();
    return StubReturn();
}

// TODO: #2440 Remove this unnecessary method in favor of properly implementing UIView point/rect conversion
- (CGPoint)_convertPoint:(CGPoint)point fromView:(UIView*)fromView toView:(UIView*)toView {
    return [CALayer convertPoint:point fromLayer:[fromView layer] toLayer:[toView layer]];
}

/**
 @Status NotInPlan
 @Notes Application-level events are not delivered in this manner on Windows.
*/
- (void)sendEvent:(UIEvent*)event {
    UNIMPLEMENTED_WITH_MSG("Application-level events are not delivered in this manner on Windows.");
}

@end
