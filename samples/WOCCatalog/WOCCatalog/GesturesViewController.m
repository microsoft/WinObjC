//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import "GesturesViewController.h"

static float segmentStrokeWidth = 4.0f;
static float splashStrokeWidth = 5.0f;

@interface FadeAwayPathView : UIView
@property (nonatomic, assign) CGPathRef path;
@property (nonatomic, retain) UIColor* color;
@end

@implementation FadeAwayPathView

-(void)drawRect:(CGRect)rect {
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    CGContextClearRect(context, self.bounds);
    CGContextSetLineCap(context, kCGLineCapRound);
    CGContextSetLineWidth(context, segmentStrokeWidth);
    CGContextSetStrokeColorWithColor(context, [self.color CGColor]);
    CGContextBeginPath(context);
    CGContextAddPath(context, self.path);
    CGContextStrokePath(context);
}

-(instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        self.backgroundColor = [UIColor clearColor];
        self.color = [UIColor grayColor];
    }
    
    return self;
}

-(void)showInView:(UIView*)view endSize:(float)size duration:(NSTimeInterval)duration {
    [view addSubview:self];
    
    [UIView animateWithDuration:duration animations:^() {
        self.transform = CGAffineTransformMakeScale(size, size);
        self.alpha = 0.0f;
    } completion:^(BOOL finished) {
        [self removeFromSuperview];
        CGPathRelease(self.path);
        self.path = nil;
    }];
}

@end

@interface SplashView : FadeAwayPathView

@end

@implementation SplashView

-(void)showInView:(UIView*)view atPoint:(CGPoint)point endSize:(float)size color:(UIColor*)color  {
    self.frame = CGRectMake(point.x - self.frame.size.width / 2, point.y - self.frame.size.height / 2, self.frame.size.width, self.frame.size.height);
    
    self.path = CGPathCreateWithEllipseInRect(CGRectInset(self.bounds, splashStrokeWidth, splashStrokeWidth), NULL);
    self.color = color;
    
    [super showInView:view endSize:size duration:0.5f];
}

@end

@interface SegmentView : FadeAwayPathView

@end

@implementation SegmentView {
    CGMutablePathRef _segment;
}

-(void)showInView:(UIView*)view atPoint:(CGPoint)point toPoint:(CGPoint)toPoint color:(UIColor*)color {
    CGRect drawRect = { MIN(point.x, toPoint.x), MIN(point.y, toPoint.y), ABS(toPoint.x - point.x), ABS(toPoint.y - point.y) };
    
    if (CGSizeEqualToSize(drawRect.size, CGSizeZero)) {
        return;
    }
    
    CGRect insetRect = CGRectInset(drawRect, -segmentStrokeWidth/2.0f, -segmentStrokeWidth/2.0f);
    self.frame = insetRect;
   
    CGMutablePathRef segment = CGPathCreateMutable();
    CGPathMoveToPoint(segment, NULL, point.x - insetRect.origin.x, point.y - insetRect.origin.y);
    CGPathAddLineToPoint(segment, NULL, toPoint.x - insetRect.origin.x, toPoint.y - insetRect.origin.y);
    self.path = segment;
    self.color = color;
    
    [super showInView:view endSize:1.0f duration:1.0f];
}

@end

@interface GestureDiagnosticView : UIView

@end

@implementation GestureDiagnosticView

-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    for (UITouch* touch in touches) {
        [[[SplashView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)] showInView:self atPoint:[touch locationInView:self] endSize:8 color:[UIColor blueColor]];
    }
}

-(void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    for (UITouch* touch in touches) {
        [[[SplashView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)] showInView:self atPoint:[touch locationInView:self] endSize:0.25 color:[UIColor blueColor]];
    }
}

-(void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    for (UITouch* touch in touches) {
        CGPoint currentPoint = [touch locationInView:self];
        CGPoint lastPoint = [touch previousLocationInView:self];
        [[[SegmentView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)] showInView:self atPoint:lastPoint   toPoint:currentPoint color:[UIColor blueColor]];
    }
}

-(void)touchesCancelled:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    for (UITouch* touch in touches) {
        [[[SplashView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)] showInView:self atPoint:[touch locationInView:self] endSize:0.25 color:[UIColor blueColor]];
    }
}

@end

@implementation GesturesViewController {
    UILabel* _stateLabel;
    CGPoint _lastPanPoint;
}

-(void)_doTap:(UITapGestureRecognizer*)sender {
    if (sender.state == UIGestureRecognizerStateBegan) {
        [[[SplashView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)] showInView:self.view atPoint:[sender locationInView:self.view] endSize:8 color:[UIColor redColor]];
    }
}

-(void)_doPan:(UIPanGestureRecognizer*)sender {
    switch (sender.state) {
        case UIGestureRecognizerStateBegan:
            _lastPanPoint = [sender locationInView:self.view];
            [[[SplashView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)] showInView:self.view atPoint:_lastPanPoint endSize:8 color:[UIColor redColor]];
            break;
        case UIGestureRecognizerStateChanged: {
            CGPoint currentPoint = [sender locationInView:self.view];
            [[[SegmentView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)] showInView:self.view atPoint:_lastPanPoint toPoint:currentPoint color:[UIColor redColor]];
            _lastPanPoint = currentPoint;
            break;
        }
        case UIGestureRecognizerStateEnded:
            [[[SplashView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)] showInView:self.view atPoint:[sender locationInView:self.view] endSize:0.25 color:[UIColor redColor]];
        default:
            break;
    }
}

-(void)_doLongPress:(UILongPressGestureRecognizer*)sender {
    if (sender.state == UIGestureRecognizerStateBegan) {
        [[[SplashView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)] showInView:self.view atPoint:[sender locationInView:self.view] endSize:8 color:[UIColor redColor]];
    }
}

-(void)loadView {
    self.view = [[GestureDiagnosticView alloc] initWithFrame:[UIScreen mainScreen].applicationFrame];
    self.view.backgroundColor = [UIColor whiteColor];
}

-(void)viewDidLoad {
    UIView* sizingView = [[UIView alloc] init];
    
    UILabel* instructionLabel = [[UILabel alloc] init];
    _stateLabel = [[UILabel alloc] init];
    
    instructionLabel.text = @"Tap, Pan or Long-Press";
    instructionLabel.font = [UIFont systemFontOfSize:[UIFont labelFontSize] * 1.25f];
    instructionLabel.textColor = [UIColor blackColor];
    [instructionLabel sizeToFit];
    
    _stateLabel.text = @"Tap and Long-Press require 2 fingers, Pan requires 2-4. Gestures do not cancel touches. Blue shows raw multitouch sequence. Red shows gesture responses.";
    _stateLabel.font = [UIFont systemFontOfSize:[UIFont labelFontSize] * 0.75f];
    _stateLabel.textColor = [UIColor darkGrayColor];
    [_stateLabel sizeToFit];
    
    // Autosize to center in the frame.
    sizingView.frame = CGRectMake(self.view.bounds.size.width / 2 - 150,
                                self.view.bounds.size.height / 2 - 20,
                                  300, 200);
    
    CGRect instructionFrame = instructionLabel.frame;
    instructionFrame.origin.y = 0;
    instructionFrame.origin.x = 0;
    instructionFrame.size.width = sizingView.frame.size.width;
    instructionLabel.frame = instructionFrame;
    instructionLabel.textAlignment = NSTextAlignmentCenter;
    
    CGRect stateFrame = _stateLabel.frame;
    stateFrame.origin.y = instructionFrame.size.height;
    stateFrame.origin.x = sizingView.frame.size.width / 2 - 120;
    stateFrame.size.width = 240;
    stateFrame.size.height = 100;
    _stateLabel.frame = stateFrame;
    _stateLabel.numberOfLines = 0;
    _stateLabel.textAlignment = NSTextAlignmentCenter;
    
    sizingView.autoresizingMask =
        UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleBottomMargin |
        UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin;
    
    [self.view addSubview:sizingView];
    [sizingView addSubview:instructionLabel];
    [sizingView addSubview:_stateLabel];
    
    UILongPressGestureRecognizer* longPress = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(_doLongPress:)];
    UITapGestureRecognizer* tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(_doTap:)];
    UIPanGestureRecognizer* pan = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(_doPan:)];
    
    longPress.numberOfTouchesRequired = 2;
    tap.numberOfTouchesRequired = 2;
    
    pan.minimumNumberOfTouches = 2;
    pan.maximumNumberOfTouches = 4;
    
    longPress.cancelsTouchesInView = pan.cancelsTouchesInView = tap.cancelsTouchesInView = NO;
    
    [self.view addGestureRecognizer:longPress];
    [self.view addGestureRecognizer:tap];
    [self.view addGestureRecognizer:pan];
}

@end
