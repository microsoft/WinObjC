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

#import "Starboard.h"

#import <UIKit/UIView.h>
#import <UIKit/UIDevice.h>
#import <UIKit/UIApplication.h>
#import <Foundation/NSArray.h>
#import <UIKit/UIScreen.h>

#import "StubReturn.h"
#import "CACompositor.h"

extern float statusBarHeight;

static UIScreen* mainScreen;
static UIScreenMode* _curMode;
static NSArray* _availableModes;
static UIScreenMode* _preferredMode;

NSString* const UIScreenDidConnectNotification = @"UIScreenDidConnectNotification";
NSString* const UIScreenDidDisconnectNotification = @"UIScreenDidDisconnectNotification";
NSString* const UIScreenModeDidChangeNotification = @"UIScreenModeDidChangeNotification";
NSString* const UIScreenBrightnessDidChangeNotification = @"UIScreenBrightnessDidChangeNotification";

@implementation UIScreen : NSObject

/**
 @Status Interoperable
*/
+ (void)initialize {
    if (self == [UIScreen self]) {
        mainScreen = [self alloc];
        _curMode = [[UIScreenMode alloc] init];
        _preferredMode = [[UIScreenMode alloc] init];

        UIScreenMode* arrayArgs[1];
        arrayArgs[0] = [[UIScreenMode alloc] init];
        _availableModes = [[NSArray alloc] initWithObjects:arrayArgs count:1];
    }
}

/**
 @Status Interoperable
*/
+ (UIScreen*)mainScreen {
    return mainScreen;
}

/**
 @Status Stub
*/
- (UIScreenMode*)currentMode {
    UNIMPLEMENTED();
    return _curMode;
}

/**
 @Status Stub
*/
- (NSArray*)availableModes {
    UNIMPLEMENTED()
    return _availableModes;
}

/**
 @Status Stub
*/
- (UIScreenMode*)preferredMode {
    UNIMPLEMENTED();
    return _preferredMode;
}

/**
 @Status Stub
*/
+ (NSArray*)screens {
    UNIMPLEMENTED();
    return [NSArray arrayWithObject:mainScreen];
}

/**
 @Status Caveat
 @Notes Returns the system scale and will dynamcially change unlike iOS.
*/
- (CGFloat)scale {
    return GetCACompositor()->screenScale();
}

/**
 @Status Caveat
 @Notes Returns the host screen scale which will never change. This value may not map 1:1 with iOS.
*/
- (CGFloat)nativeScale {
    return UIApplication.displayMode.hostScreenScale;
}

/**
 @Status Caveat
 @Notes Always returns 1.0.
*/
- (CGFloat)brightness {
    return 1.0;
}

/**
 @Status Interoperable
*/
- (CGRect)bounds {
    CGRect ret;
    ret.origin.x = 0.0f;
    ret.origin.y = 0.0f;
    ret.size.width = GetCACompositor()->screenWidth();
    ret.size.height = GetCACompositor()->screenHeight();

    return ret;
}

/**
 @Status Caveat
 @Notes returns the host window size width and height.
*/
- (CGRect)nativeBounds {
    CGRect ret;
    ret.origin.x = 0.0f;
    ret.origin.y = 0.0f;
    ret.size = UIApplication.displayMode.hostWindowSize;

    return ret;
}

/**
 @Status Interoperable
*/
- (CGRect)applicationFrame {
    BOOL isHidden = [[UIApplication sharedApplication] isStatusBarHidden];
    UIInterfaceOrientation statusBarOrientation = (UIInterfaceOrientation)[[UIApplication sharedApplication] statusBarOrientation];
    CGRect ret;
    ret.origin.x = 0.0f;
    ret.origin.y = 0.0f;
    ret.size.width = GetCACompositor()->screenWidth();
    ret.size.height = GetCACompositor()->screenHeight();

    if (!isHidden) {
        switch (statusBarOrientation) {
            case UIInterfaceOrientationLandscapeLeft:
                ret.origin.x += statusBarHeight;
                ret.size.width -= statusBarHeight;
                break;

            case UIInterfaceOrientationLandscapeRight:
                ret.size.width -= statusBarHeight;
                break;

            case UIInterfaceOrientationPortrait:
                ret.origin.y += statusBarHeight;
                ret.size.height -= statusBarHeight;
                break;

            case UIInterfaceOrientationPortraitUpsideDown:
                ret.size.height -= statusBarHeight;
                break;

            case 0:
                ret.origin.y += statusBarHeight;
                ret.size.height -= statusBarHeight;
                break;

            default:
                assert(0);
                break;
        }
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (CADisplayLink*)displayLinkWithTarget:(NSObject*)target selector:(SEL)selector {
    id ret = [CADisplayLink displayLinkWithTarget:target selector:selector];

    return ret;
}

/**
 @Status Stub
*/
- (UIView*)snapshotViewAfterScreenUpdates:(BOOL)afterUpdates {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
