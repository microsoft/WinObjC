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

// Five UIWindow are created. The first four are for testing/demostrating windowLevel property of UIWindow.
// The level control UIWindow has buttons for changing the windowLevel of blue, red, yellow window.
// The last UIWindow is the main UIWindow which is for testing/demostrating all other things.
- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions {
    self.levelControlVC = [[WindowLevelControlViewController alloc] init];
    self.levelControlWindow = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.levelControlWindow.rootViewController = self.levelControlVC;
    self.levelControlWindow.windowLevel = UIWindowLevelNormal;
    [self.levelControlWindow makeKeyAndVisible];

    self.redVC = [[BlankWindowViewController alloc] init];
    self.redVC.view.backgroundColor = [UIColor redColor];
    CGRect redColorWindowRect = CGRectMake(50, 140, 280, 480);
    self.redColorWindow = [[UIWindow alloc] initWithFrame:redColorWindowRect];
    self.redColorWindow.rootViewController = self.redVC;
    self.redColorWindow.windowLevel = UIWindowLevelNormal + 1.0f;
    self.redColorWindow.sizeUIWindowToFit = FALSE;
    [self.redColorWindow makeKeyAndVisible];

    self.blueVC = [[BlankWindowViewController alloc] init];
    self.blueVC.view.backgroundColor = [UIColor blueColor];
    CGRect blueColorWindowRect = CGRectMake(50, 160, 280, 50);
    self.blueColorWindow = [[UIWindow alloc] initWithFrame:blueColorWindowRect];
    self.blueColorWindow.rootViewController = self.blueVC;
    self.blueColorWindow.windowLevel = UIWindowLevelNormal + 2.0f;
    self.blueColorWindow.sizeUIWindowToFit = FALSE;
    [self.blueColorWindow makeKeyAndVisible];

    self.yellowVC = [[BlankWindowViewController alloc] init];
    self.yellowVC.view.backgroundColor = [UIColor yellowColor];
    CGRect yellowColorWindowRect = CGRectMake(80, 160, 220, 420);
    self.yellowColorWindow = [[UIWindow alloc] initWithFrame:yellowColorWindowRect];
    self.yellowColorWindow.rootViewController = self.yellowVC;
    self.yellowColorWindow.windowLevel = UIWindowLevelNormal + 3.0f;
    self.yellowColorWindow.sizeUIWindowToFit = FALSE;
    [self.yellowColorWindow makeKeyAndVisible];

    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    MainViewController* mtvc = [[MainViewController alloc] init];
    self.viewController = (UIViewController*)[[UINavigationController alloc] initWithRootViewController:mtvc];
    self.window.windowLevel = UIWindowLevelNormal + 4.0f;
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
