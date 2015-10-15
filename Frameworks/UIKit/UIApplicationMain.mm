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

#include "Starboard.h"
#include "UIKit/UIFont.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSData.h"
#include "Foundation/NSBundle.h"
#include "Foundation/NSDate.h"
#include "Foundation/NSNib.h"
#include "Foundation/NSNotificationCenter.h"
#include "Foundation/NSRunLoop.h"
#include "Foundation/NSAutoReleasePool.h"

#include "UIKit/UIViewController.h"
#include "UIKit/UIDevice.h"

#import <UIKit/UIApplicationDelegate.h>

#include "UIInterface.h"

@interface NSAutoreleasePoolWarn : NSAutoreleasePool
@end

@implementation NSAutoreleasePoolWarn : NSAutoreleasePool
- (void)addObject:(id)obj {
    EbrDebugLog("Autoreleasing a %s in the toplevel pool that will never be freed\n", object_getClassName(obj));
    [super addObject:obj];
}
@end

void UIBecomeInactive() {
    UIApplication* app = [UIApplication sharedApplication];
    id<UIApplicationDelegate> curDelegate = [app delegate];

    if ([curDelegate respondsToSelector:@selector(applicationWillResignActive:)]) {
        [curDelegate applicationWillResignActive:app];
    }

    // Drain global dispatch queue before ceding control.
    dispatch_sync(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),
                  ^{
                  });
}

int UIOrientationFromString(int curOrientation, NSString* str) {
    char* pOrientation = (char*)[str UTF8String];

    if (strcmp(pOrientation, "UIInterfaceOrientationLandscapeRight") == 0) {
        return UIInterfaceOrientationLandscapeRight;
    } else if (strcmp(pOrientation, "UIInterfaceOrientationLandscapeRight") == 0) {
        return UIInterfaceOrientationLandscapeRight;
    } else if (strcmp(pOrientation, "UIInterfaceOrientationLandscapeDefault") == 0) {
        if (curOrientation == UIInterfaceOrientationLandscapeLeft || curOrientation == UIInterfaceOrientationLandscapeRight) {
            return curOrientation;
        }

        return UIInterfaceOrientationLandscapeRight;
    } else if (strcmp(pOrientation, "UIInterfaceOrientationPortrait") == 0) {
        return UIInterfaceOrientationPortrait;
    } else if (strcmp(pOrientation, "UIInterfaceOrientationPortraitRight") == 0) {
        return UIInterfaceOrientationPortrait;
    } else if (strcmp(pOrientation, "UIInterfaceOrientationLandscapeLeft") == 0) {
        return UIInterfaceOrientationLandscapeLeft;
    } else if (strcmp(pOrientation, "UIDeviceOrientationLandscapeLeft") == 0) {
        return UIInterfaceOrientationLandscapeLeft;
    } else if (strcmp(pOrientation, "UIInterfaceOrientationLandscape") == 0) {
        if (curOrientation == UIInterfaceOrientationLandscapeLeft || curOrientation == UIInterfaceOrientationLandscapeRight) {
            return curOrientation;
        }

        return UIInterfaceOrientationLandscapeRight;
    } else if (strcmp(pOrientation, "") == 0) {
        EbrDebugLog("Warning: orientation is blank\n");
        return UIInterfaceOrientationLandscapeRight;
    } else if (strcmp(pOrientation, "UIInterfaceOrientationPortraitUpsideDown") == 0) {
        return UIInterfaceOrientationPortraitUpsideDown;
    } else {
        EbrDebugLog("Warning: Unsupported orientation %s\n", pOrientation);
        assert(0);
    }

    return UIInterfaceOrientationPortrait;
}

BOOL _doShutdown = FALSE;
int newDeviceOrientation;
volatile bool g_uiMainRunning = false;
static NSAutoreleasePoolWarn* outerPool;

int UIApplicationMainInit(int argc, char* argv[], NSString* principalClassName, NSString* delegateClassName, int defaultOrientation) {
    // Make sure we reference classes we need:
    void ForceInclusion();
    ForceInclusion();

    [[NSThread currentThread] associateWithCurrentThread];
    NSDictionary* infoDict = [[NSBundle mainBundle] infoDictionary];

    outerPool = [NSAutoreleasePoolWarn new];
    NSAutoreleasePool* pool = [NSAutoreleasePool new];
    NSRunLoop* runLoop = [NSRunLoop currentRunLoop];
    UIApplication* uiApplication;

    if (principalClassName == nil) {
        principalClassName = [infoDict objectForKey:@"NSPrincipalClass"];
    }

    if (principalClassName != nil) {
        char* pClassName = (char*)[principalClassName UTF8String];
        uiApplication = [objc_getClass(pClassName) new];
    } else {
        uiApplication = [UIApplication new];
    }

    id<UIApplicationDelegate> delegateApp;

    if (delegateClassName != nil) {
        char* pClassName = (char*)[delegateClassName UTF8String];
        delegateApp = [objc_getClass(pClassName) new];
    } else {
        delegateApp = [uiApplication delegate];
    }

    [uiApplication setDelegate:delegateApp];
    idretain rootController(nil);

    if (infoDict != nil) {
        NSArray* fonts = [infoDict objectForKey:@"UIAppFonts"];
        if (fonts != nil) {
            for (NSString* curFontName in fonts) {
                NSString* path = [[NSBundle mainBundle] pathForResource:curFontName ofType:nil];
                if (path != nil) {
                    NSData* data = [NSData dataWithContentsOfFile:path];
                    if (data != nil) {
                        UIFont* font = [UIFont fontWithData:data];
                        if (font != nil) {
                            [font _setName:[[path lastPathComponent] stringByDeletingPathExtension]];
                            CTFontManagerRegisterGraphicsFont((CGFontRef)font, NULL);
                        }
                    }
                }
            }
        }

        if (defaultOrientation != UIInterfaceOrientationUnknown) {
            [uiApplication setStatusBarOrientation:defaultOrientation];
            [uiApplication _setInternalOrientation:defaultOrientation];
        }

        NSNumber* statusBarHidden = [infoDict objectForKey:@"UIStatusBarHidden"];
        int hideStatusBar = 0;
        if (statusBarHidden != nil) {
            if ([statusBarHidden intValue] != 0) {
                hideStatusBar = 1;
            }
        }
        [uiApplication setStatusBarHidden:hideStatusBar];

        NSString* mainNibFile;

        if (GetCACompositor()->isTablet()) {
            mainNibFile = [infoDict objectForKey:@"NSMainNibFile~ipad"];
            if (mainNibFile == nil) {
                mainNibFile = [infoDict objectForKey:@"NSMainNibFile"];
            }
        } else {
            mainNibFile = [infoDict objectForKey:@"NSMainNibFile"];
        }

        if (mainNibFile != nil) {
            NSString* nibPath = [[NSBundle mainBundle] pathForResource:mainNibFile ofType:@"nib"];
            if (nibPath != nil) {
                NSArray* obj = [[[NSNib alloc] loadNib:nibPath withOwner:uiApplication] retain];
                int count = [obj count];

                for (int i = 0; i < count; i++) {
                    NSObject* curObj = [obj objectAtIndex:i];

                    if ([curObj isKindOfClass:[UIViewController class]]) {
                        [curObj setResizeToScreen:1];
                        [curObj _doResizeToScreen];
                    }
                }
            }
        } else {
            NSString* storyBoardName = nil;
            if (GetCACompositor()->isTablet()) {
                storyBoardName = [infoDict objectForKey:@"UIMainStoryboardFile~ipad"];
            }

            if (storyBoardName == nil) {
                storyBoardName = [infoDict objectForKey:@"UIMainStoryboardFile"];
            }

            if (storyBoardName != nil) {
                UIStoryboard* storyBoard = [UIStoryboard storyboardWithName:storyBoardName bundle:[NSBundle mainBundle]];
                UIViewController* viewController = [storyBoard instantiateInitialViewController];
                if (viewController != nil) {
                    [viewController setResizeToScreen:1];
                    rootController = viewController;
                }
            }
        }
    }

    id<UIApplicationDelegate> curDelegate = [uiApplication delegate];
    if (curDelegate == nil) {
        [uiApplication setDelegate:uiApplication];
    }

    if ([curDelegate respondsToSelector:@selector(application:didFinishLaunchingWithOptions:)]) {
        NSMutableDictionary* options = [NSMutableDictionary dictionary];

        [curDelegate application:uiApplication didFinishLaunchingWithOptions:nil];
    } else if ([curDelegate respondsToSelector:@selector(applicationDidFinishLaunching:)]) {
        [curDelegate applicationDidFinishLaunching:uiApplication];
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:@"UIApplicationDidFinishLaunchingNotification" object:uiApplication];

    if (rootController != nil) {
        [[uiApplication _popupWindow] setRootViewController:rootController];
        [rootController _doResizeToScreen];
        rootController = nil;
    }

    if ([curDelegate respondsToSelector:@selector(applicationDidBecomeActive:)]) {
        [curDelegate applicationDidBecomeActive:uiApplication];
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:@"UIApplicationDidBecomeActiveNotification" object:uiApplication];

    [[UIDevice currentDevice] performSelectorOnMainThread:@selector(setOrientation:) withObject:0 waitUntilDone:FALSE];
    [[UIDevice currentDevice] performSelectorOnMainThread:@selector(_setInitialOrientation) withObject:0 waitUntilDone:FALSE];
    g_uiMainRunning = true;

    if (newDeviceOrientation != 0) {
        [[UIDevice currentDevice] performSelectorOnMainThread:@selector(submitRotation) withObject:nil waitUntilDone:FALSE];
    }
#ifdef SHOW_OPTIONS_ON_STARTUP
    [[UIApplication sharedApplication] performSelectorOnMainThread:@selector(__showOptions) withObject:0 waitUntilDone:FALSE];
#endif

    //  Make windows visible
    NSArray* windows = [[UIApplication sharedApplication] windows];

    int windowCount = [windows count];
    for (int i = 0; i < windowCount; i++) {
        UIWindow* curWindow = [windows objectAtIndex:i];
        [curWindow setHidden:FALSE];
    }

    //  Cycle through the runloop once before releasing our pool,
    //  so that any layouts or selectors get a chance to retain before
    //  objects get destroyed
    [runLoop runMode:@"kCFRunLoopDefaultMode" beforeDate:[NSDate distantPast]];
    [pool release];

    return 0;
}

int UIApplicationMainLoop() {
    [[NSThread currentThread] associateWithCurrentThread];
    NSRunLoop* runLoop = [NSRunLoop currentRunLoop];

    for (;;) {
        [runLoop run];
        EbrDebugLog("Warning: CFRunLoop stopped\n");
        if (_doShutdown) {
            break;
        }
    }
    UIBecomeInactive();
    if ([[[UIApplication sharedApplication] delegate] respondsToSelector:@selector(applicationWillTerminate:)]) {
        [[[UIApplication sharedApplication] delegate] applicationWillTerminate:[UIApplication sharedApplication]];
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:@"UIApplicationWillTerminateNotification"
                                                        object:[UIApplication sharedApplication]];

    EbrDebugLog("Exiting uncleanly.\n");
    EbrShutdownAV();
    [outerPool release];

    return 0;
}
