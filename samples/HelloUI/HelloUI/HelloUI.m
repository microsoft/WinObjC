#import <UIKit/UIKit.h>

@interface HelloUIApp : NSObject {
    UIWindow* _mainWindow;
    UILabel* _welcomeLabel;
    UIButton* _draggableButton;
    UIButton* _longPressableButton;
    UIButton* _tapGestureButton;
}
@end

@implementation HelloUIApp

- (void)applicationDidFinishLaunching:(UIApplication*)app {
    CGRect bounds = [[UIScreen mainScreen] bounds];

    _mainWindow = [[UIWindow alloc] initWithFrame:bounds];

    _welcomeLabel = [[UILabel alloc] initWithFrame:bounds];
    [_welcomeLabel setBackgroundColor:nil];
    [_welcomeLabel setTextColor:[UIColor blueColor]];
    [_welcomeLabel setText:@"Hello Islandwood!"];
    [_welcomeLabel setFont:[UIFont boldSystemFontOfSize:48.0f]];
    [_welcomeLabel setTextAlignment:UITextAlignmentCenter];

    [_mainWindow addSubview:_welcomeLabel];

    CABasicAnimation* textZoomAnim = [CABasicAnimation animationWithKeyPath:@"transform.scale"];
    textZoomAnim.fromValue = [NSNumber numberWithFloat:1.0f];
    textZoomAnim.toValue = [NSNumber numberWithFloat:0.5f];
    textZoomAnim.duration = 0.5;
    textZoomAnim.repeatCount = INT_MAX;
    textZoomAnim.autoreverses = YES;
    textZoomAnim.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];

    [[_welcomeLabel layer] addAnimation:textZoomAnim forKey:@"TextZoom"];

    _draggableButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [_draggableButton setTitle:@"Move me!" forState:UIControlStateNormal];
    [_draggableButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [_draggableButton setTintColor:[UIColor whiteColor]];
    _draggableButton.frame = CGRectMake(bounds.size.width / 2.0f - 50.0f, 50.0f, 100.0f, 40.0f);
    [_draggableButton addTarget:self action:@selector(buttonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [_mainWindow addSubview:_draggableButton];

    UIPanGestureRecognizer* moveButton = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(buttonPanned:)];

    [_draggableButton addGestureRecognizer:moveButton];

    _longPressableButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [_longPressableButton setTitle:@"LongPress me!" forState:UIControlStateNormal];
    [_longPressableButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [_longPressableButton setTintColor:[UIColor purpleColor]];
    _longPressableButton.frame = CGRectMake(bounds.size.width / 2.0f - 50.0f, 100.0f, 140.0f, 40.0f);
    [_mainWindow addSubview:_longPressableButton];

    UILongPressGestureRecognizer* longPressGesture =
        [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(buttonLongPressed:)];
    [_longPressableButton addGestureRecognizer:longPressGesture];

    _tapGestureButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [_tapGestureButton setTitle:@"Touch Gesture!" forState:UIControlStateNormal];
    [_tapGestureButton setTintColor:[UIColor purpleColor]];
    [_tapGestureButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    _tapGestureButton.frame = CGRectMake(bounds.size.width / 2.0f - 50.0f, 150.0f, 100.0f, 40.0f);
    [_mainWindow addSubview:_tapGestureButton];
    UITapGestureRecognizer* tapGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTap:)];
    [_tapGestureButton addGestureRecognizer:tapGesture];

    [_mainWindow makeKeyAndVisible];
}

- (void)buttonPressed:(UIButton*)button {
    [_welcomeLabel setText:@"Got a touch!"];
}

- (void)buttonPanned:(UIPanGestureRecognizer*)gesture {
    CGPoint newPosition = _draggableButton.layer.position;
    CGPoint movement = [gesture translationInView:_draggableButton];
    [gesture setTranslation:CGPointMake(0, 0) inView:_draggableButton];
    newPosition.x += movement.x;
    newPosition.y += movement.y;
    _draggableButton.layer.position = newPosition;
}

- (void)buttonLongPressed:(UILongPressGestureRecognizer*)gesture {
    if (gesture.state == UIGestureRecognizerStatePossible) {
        [_welcomeLabel setText:@"Long Press possible!"];
    } else if (gesture.state == UIGestureRecognizerStateBegan) {
        [_welcomeLabel setText:@"Long Press Began!"];
    } else if (gesture.state == UIGestureRecognizerStateEnded || gesture.state == UIGestureRecognizerStateRecognized) {
        [_welcomeLabel setText:@"Long Press Ended!"];
    } else if (gesture.state == UIGestureRecognizerStateChanged) {
        [_welcomeLabel setText:@"Long Press Changed!"];
    } else if (gesture.state == UIGestureRecognizerStateFailed) {
        [_welcomeLabel setText:@"Long Press Failed!"];
    } else if (gesture.state == UIGestureRecognizerStateCancelled) {
        [_welcomeLabel setText:@"Long Press Cancelled!"];
    }
}

- (void)handleTap:(UITapGestureRecognizer*)sender {
    if (sender.state == UIGestureRecognizerStatePossible) {
        [_welcomeLabel setText:@"Tap possible!"];
    } else if (sender.state == UIGestureRecognizerStateEnded || sender.state == UIGestureRecognizerStateRecognized) {
        [_welcomeLabel setText:@"Tap Ended!"];
    } else if (sender.state == UIGestureRecognizerStateFailed) {
        [_welcomeLabel setText:@"Tap Failed!"];
    } else if (sender.state == UIGestureRecognizerStateCancelled) {
        [_welcomeLabel setText:@"Tap Cancelled!"];
    }
}
@end

#ifdef WINOBJC
// Tell the WinObjC runtime how large to render the application
@implementation UIApplication (UIApplicationInitialStartupMode)
+ (void)setStartupDisplayMode:(WOCDisplayMode*)mode {
    mode.autoMagnification = TRUE;
    mode.sizeUIWindowToFit = TRUE;
    mode.fixedWidth = 0;
    mode.fixedHeight = 0;
    mode.magnification = 1.0;
}
@end
#endif
