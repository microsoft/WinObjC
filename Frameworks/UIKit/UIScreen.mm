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

#import <UIKit/UIApplication.h>
#import <UIKit/UIDevice.h>
#import <UIKit/UIScreen.h>
#import <UIKit/UIScreenMode.h>
#import <UIKit/UIView.h>

#import <Foundation/NSArray.h>

#import <QuartzCore/CADisplayLink.h>

#import "StubReturn.h"
#import "StarboardXaml/DisplayProperties.h"
#import <CoreGraphics/CGBase.h>

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
    return DisplayProperties::ScreenScale();
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
    return CGRectMake(0.0, 0.0, DisplayProperties::ScreenWidth(), DisplayProperties::ScreenHeight());
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
    // TODO: #2439 Should this account for the UWP status bar occlusion rect?
    return CGRectMake(0.0, 0.0, DisplayProperties::ScreenWidth(), DisplayProperties::ScreenHeight());
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
