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

#import "AppDelegate.h"
#import "MainViewController.h"
#ifdef WINOBJC
#import "UWP/WindowsUIViewManagement.h"
#import "UWP/WindowsFoundationMetadata.h"
#endif

#ifdef WINOBJC
// Tell the WinObjC runtime how large to render the application
@implementation UIApplication (UIApplicationInitialStartupMode)
+ (void)setStartupDisplayMode:(WOCDisplayMode*)mode {
    mode.autoMagnification = TRUE;
    mode.sizeUIWindowToFit = TRUE;
    mode.clampScaleToClosestExpected = FALSE;
    mode.fixedWidth = 0;
    mode.fixedHeight = 0;
    mode.magnification = 1.0;
}
@end
#endif

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions {
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    MainViewController* mtvc = [[MainViewController alloc] init];
    self.viewController = (UIViewController*)[[UINavigationController alloc] initWithRootViewController:mtvc];
    self.window.rootViewController = self.viewController;
    [self.window makeKeyAndVisible];

#ifdef WINOBJC
    WFMPlatform platform = [self detectPlatform];
    if (platform == WFMPlatformWindowsPhone) {
        // On windows phone the navigation bar hides a part of screen at the bottom, so we try to enter full screen mode on a windows phone.
        [[WUVApplicationView getForCurrentView] tryEnterFullScreenMode];
    }
#endif
    return YES;
}

#ifdef WINOBJC
- (WFMPlatform)detectPlatform {
    // Using ApiInformation class we ask if Windows.Phone.PhoneContract is present to detect if the device is a windows phone, with the
    // current introduced version number 1.
    BOOL isWindowsPhone = [WFMApiInformation isApiContractPresentByMajor:@"Windows.Phone.PhoneContract" majorVersion:1];
    if (isWindowsPhone) {
        return WFMPlatformWindowsPhone;
    } else {
        return WFMPlatformWindows;
    }
}
#endif

- (void)applicationWillResignActive:(UIApplication*)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions
    // (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background
    // state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to
    // pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication*)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to
    // restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication*)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering
    // the background.
}

- (void)applicationDidBecomeActive:(UIApplication*)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the
    // background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication*)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
