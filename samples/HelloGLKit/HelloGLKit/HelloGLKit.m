#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import "GLRenderer.h"

@interface HelloOpenGLApp : NSObject {
    UIWindow* _mainWindow;
    GLRenderer* _renderer;
}
@end

@implementation HelloOpenGLApp

-(void) applicationDidFinishLaunching: (UIApplication *) app {
    CGRect bounds = [[UIScreen mainScreen] bounds];    
    _mainWindow = [[UIWindow alloc] initWithFrame: bounds];

    _renderer = [[GLRenderer alloc] init];

    EAGLContext* ctx = [[EAGLContext alloc] initWithAPI: kEAGLRenderingAPIOpenGLES2];
    GLKView* view = [[GLKView alloc] initWithFrame: bounds];
    view.context = ctx;
    view.delegate = _renderer;

    // GLKViewController* ctl = [[GLKViewController alloc] initWithNibName: nil bundle: nil];
    // ctl.view = view;
    // ctl.delegate = _renderer;
    // ctl.preferredFramesPerSecond = 60;

    // _mainWindow.rootViewController = ctl;
    [_mainWindow addSubview: view];
    [_mainWindow makeKeyAndVisible];
}

@end

#ifdef WINOBJC
// Tell the WinObjC runtime how large to render the application
@implementation UIApplication(UIApplicationInitialStartupMode)
+(void) setStartupDisplayMode: (WOCDisplayMode *) mode {
    mode.autoMagnification = TRUE;
    mode.sizeUIWindowToFit = TRUE;
    mode.fixedWidth = 0;
    mode.fixedHeight = 0;
    mode.magnification = 1.0;
}
@end
#endif
