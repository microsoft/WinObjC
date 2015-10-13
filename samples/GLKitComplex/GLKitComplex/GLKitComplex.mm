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

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import "GLRenderer.h"

@interface HelloOpenGLApp : NSObject {
    UIWindow*       _mainWindow;
    GLRenderer*     _renderer;
    UILabel*        _welcomeLabel;    
}
@end

@implementation HelloOpenGLApp

-(void) applicationDidFinishLaunching: (UIApplication *) app {
    CGRect bounds = [[UIScreen mainScreen] bounds];    
    _mainWindow = [[UIWindow alloc] initWithFrame: bounds];

    EAGLContext* ctx = [[EAGLContext alloc] initWithAPI: kEAGLRenderingAPIOpenGLES2];
    [EAGLContext setCurrentContext: ctx];

    _renderer = [[GLRenderer alloc] init];
    [_renderer initGLData];
    
    GLKView* view = [[GLKView alloc] initWithFrame: bounds];
    view.context = ctx;
    view.delegate = _renderer;
    view.drawableDepthFormat = GLKViewDrawableDepthFormat16;

    GLKViewController* ctl = [[GLKViewController alloc] initWithNibName: nil bundle: nil];
    ctl.view = view;
    ctl.delegate = _renderer;
    ctl.preferredFramesPerSecond = 60;

    _mainWindow.rootViewController = ctl;

    bounds.origin.y = bounds.size.height - 180.f;
    bounds.size.height = 180.f;

    _welcomeLabel = [[UILabel alloc] initWithFrame: bounds];
    _welcomeLabel.autoresizingMask = UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleWidth;
    [_welcomeLabel setBackgroundColor: nil];
    [_welcomeLabel setTextColor: [UIColor whiteColor]];
    [_welcomeLabel setFont: [UIFont boldSystemFontOfSize: 24.0f]];
    [_welcomeLabel setTextAlignment: NSTextAlignmentCenter];
    [_mainWindow addSubview: _welcomeLabel];

    [self setLabelText];
    
    //The setup code (in viewDidLoad in your view controller)
    UITapGestureRecognizer *tap = [UITapGestureRecognizer alloc];
    [tap initWithTarget:self action:@selector(handleTap:)];
    [view addGestureRecognizer: tap];
    
    [_mainWindow makeKeyAndVisible];
}

-(void)setLabelText {
    static NSString* modeDescriptions[]={
        @"Vertex Lit, Solid Color, Untextured",
        @"Pixel Lit, Solid Color, Untextured",
        @"Reflection Map with Specularity",
        @"Vertex Lit, Specularity, Textured w/ Decal",
        @"Per-pixel Diffuse & Specular lighting, Textured w/ Decal, Environment and Emissive Map",
        @"Vertex Colors, Untextured",
        @"Solid Color, Untextured",
        @"Vertex Colors, Textured",
        @"Solid Color, Textured w/ Decal"
    };
    
    [_welcomeLabel setText: modeDescriptions[_renderer.mode]];
}

-(void)handleTap: (UITapGestureRecognizer*)tap {
    CGPoint location = [tap locationInView: [tap.view superview]];
    [_renderer nextDisplayMode];
    [self setLabelText];
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
