#import <UIKit/UIKit.h>

@interface HelloUIApp : NSObject
{
    UIWindow *_mainWindow;
    UILabel  *_welcomeLabel;
    UIButton *_draggableButton;
}
@end

@implementation HelloUIApp

-(void) applicationDidFinishLaunching: (UIApplication *) app
{
    CGRect bounds = [[UIScreen mainScreen] bounds];
    
    _mainWindow = [[UIWindow alloc] initWithFrame: bounds];
    
    _welcomeLabel = [[UILabel alloc] initWithFrame: bounds];
    [_welcomeLabel setBackgroundColor: nil];
    [_welcomeLabel setTextColor: [UIColor blueColor]];
    [_welcomeLabel setText: @"Hello Islandwood!"];
    [_welcomeLabel setFont: [UIFont boldSystemFontOfSize: 48.0f]];
    [_welcomeLabel setTextAlignment: UITextAlignmentCenter];
    
    [_mainWindow addSubview: _welcomeLabel];
    
    CABasicAnimation *textZoomAnim = [CABasicAnimation animationWithKeyPath: @"transform.scale"];
    textZoomAnim.fromValue = [NSNumber numberWithFloat: 1.0f];
    textZoomAnim.toValue = [NSNumber numberWithFloat: 0.5f];
    textZoomAnim.duration = 0.5;
    textZoomAnim.repeatCount = INT_MAX;
    textZoomAnim.autoreverses = YES;
    textZoomAnim.timingFunction = [CAMediaTimingFunction functionWithName: kCAMediaTimingFunctionEaseInEaseOut];
    
    [[_welcomeLabel layer] addAnimation: textZoomAnim forKey: @"TextZoom"];
    
    _draggableButton = [UIButton buttonWithType: UIButtonTypeRoundedRect];
    [_draggableButton setTitle: @"Move me!" forState: UIControlStateNormal];
    [_draggableButton setTintColor:[UIColor whiteColor]];
    _draggableButton.frame = CGRectMake(bounds.size.width / 2.0f - 50.0f, 50.0f, 100.0f, 40.0f);
    [_draggableButton addTarget: self action: @selector(buttonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [_mainWindow addSubview: _draggableButton];
    
    UIPanGestureRecognizer *moveButton = [[UIPanGestureRecognizer alloc] initWithTarget: self action: @selector(buttonPanned:)];
    [_draggableButton addGestureRecognizer: moveButton];
    
    [_mainWindow makeKeyAndVisible];
}

-(void) buttonPressed: (UIButton*)button
{
    [_welcomeLabel setText: @"Got a touch!"];
}

-(void) buttonPanned: (UIPanGestureRecognizer *) gesture
{
    CGPoint newPosition = _draggableButton.layer.position;
    CGPoint movement = [gesture translationInView: _draggableButton];
    [gesture setTranslation: CGPointMake(0, 0) inView: _draggableButton];
    newPosition.x += movement.x;
    newPosition.y += movement.y;
    _draggableButton.layer.position = newPosition;
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
