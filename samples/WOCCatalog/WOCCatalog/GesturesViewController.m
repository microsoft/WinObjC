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
#import <CoreGraphics/CGBitmapContext.h>

static float segmentStrokeWidth = 1.0f;
static float splashStrokeWidth = 5.0f;

@interface SplashView : UIView
@property (nonatomic, retain) UIColor* color;
@end

@implementation SplashView

-(void)drawRect:(CGRect)rect {
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    CGContextClearRect(context, self.bounds);
    CGContextSetLineWidth(context, splashStrokeWidth);
    CGContextSetStrokeColorWithColor(context, [self.color CGColor]);
    CGContextSetAlpha(context, 0.25f);
    CGContextBeginPath(context);
    CGContextAddEllipseInRect(context, CGRectInset(self.bounds, splashStrokeWidth, splashStrokeWidth));
    CGContextStrokePath(context);
}

-(instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        self.backgroundColor = [UIColor clearColor];
        self.color = [UIColor grayColor];
    }
    
    return self;
}

-(void)showInView:(UIView*)view atPoint:(CGPoint)point endSize:(float)size color:(UIColor*)color  {
    self.frame = CGRectMake(point.x - self.frame.size.width / 2, point.y - self.frame.size.height / 2, self.frame.size.width, self.frame.size.height);
    
    self.color = color;
    
    [view addSubview:self];
    
    [UIView animateWithDuration:0.5f animations:^() {
        self.transform = CGAffineTransformMakeScale(size, size);
        self.alpha = 0.0f;
    } completion:^(BOOL finished) {
        [self removeFromSuperview];
    }];
}

@end

@interface _TouchColorPair : NSObject
@property (nonatomic, retain) UIBezierPath* path;
@property (nonatomic, retain) UIColor* color;
@end

@implementation _TouchColorPair

@end

@interface GestureDiagnosticView : UIView

@end

@implementation GestureDiagnosticView {
    NSMutableDictionary<NSValue*, _TouchColorPair*>* _touchMap;
    NSMutableSet<NSValue*>* _trackedTouches;
    NSUInteger _numTouches;
    NSUInteger _numPoints;
    UIImage* _cachedImage;
}

-(instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        self.backgroundColor = [UIColor clearColor];
        _touchMap = [NSMutableDictionary new];
        _trackedTouches = [NSMutableSet new];
    }

    return self;
}

-(void)addLine:(CGPoint)point toPoint:(CGPoint)toPoint color:(UIColor*)color hash:(NSUInteger)hash {
    NSValue* hashKey = [NSNumber numberWithUnsignedInteger:hash];
    _TouchColorPair* pair = [_touchMap objectForKey:hashKey];
    if (!pair) {
        pair = [_TouchColorPair new];
        pair.path = [UIBezierPath new];
        pair.path.lineWidth = segmentStrokeWidth;
        pair.color = color;
        _touchMap[hashKey] = pair;
    }

    _numPoints++;
    
    [pair.path moveToPoint:point];
    [pair.path addLineToPoint:toPoint];
    [self setNeedsDisplay];
}

-(void)flushPoints {
    UIGraphicsBeginImageContext(self.bounds.size);
    
    [_cachedImage drawAtPoint:CGPointZero];
    for (_TouchColorPair* pair in _touchMap.allValues) {
        CGContextSetStrokeColorWithColor(UIGraphicsGetCurrentContext(), pair.color.CGColor);
        [pair.path stroke];
    }
    [_touchMap removeAllObjects];
    
    _cachedImage = UIGraphicsGetImageFromCurrentImageContext();
    _numPoints = 0;
    
    UIGraphicsEndImageContext();
}

-(void)setFrame:(CGRect)frame {
    [super setFrame:frame];
    _cachedImage = nil;
}

-(void)drawRect:(CGRect)rect {
    if (_numPoints == 128) {
        [self flushPoints];
    }
    
    [_cachedImage drawAtPoint:CGPointZero];
    for (_TouchColorPair* pair in _touchMap.allValues) {
        CGContextSetStrokeColorWithColor(UIGraphicsGetCurrentContext(), pair.color.CGColor);
        [pair.path stroke];
    }
}

-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    for (UITouch* touch in touches) {
        if (!_trackedTouches.count) {
            _cachedImage = nil;
            [self setNeedsDisplay];
        }
    
        [_trackedTouches addObject:[NSNumber numberWithUnsignedInteger:touch.hash]];
        
        [[[SplashView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)] showInView:self atPoint:[touch locationInView:self] endSize:8 color:[UIColor blueColor]];
    }
}

-(void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    for (UITouch* touch in touches) {
        [_trackedTouches removeObject:[NSNumber numberWithUnsignedInteger:touch.hash]];
        [[[SplashView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)] showInView:self atPoint:[touch locationInView:self] endSize:0.25 color:[UIColor blueColor]];
    }
    if (!_trackedTouches.count) {
        [self flushPoints];
    }
}

-(void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    for (UITouch* touch in touches) {
        if (![_trackedTouches containsObject:[NSNumber numberWithUnsignedInteger:touch.hash]]) {
            continue;
        }
        CGPoint currentPoint = [touch locationInView:self];
        CGPoint lastPoint = [touch previousLocationInView:self];
        
        [self addLine:lastPoint toPoint:currentPoint color:[UIColor blueColor] hash:[touch hash]];
        
        [self setNeedsDisplay];
    }
}

-(void)touchesCancelled:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    for (UITouch* touch in touches) {
        [_trackedTouches removeObject:[NSNumber numberWithUnsignedInteger:touch.hash]];
        [[[SplashView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)] showInView:self atPoint:[touch locationInView:self] endSize:0.25 color:[UIColor blueColor]];
    }
    
    if (!_trackedTouches.count) {
        [self flushPoints];
    }
}

@end

@implementation GesturesViewController {
    UILabel* _stateLabel;
    CGPoint _lastPanPoint;
}

-(void)_doTap:(UITapGestureRecognizer*)sender {
    if (sender.state == UIGestureRecognizerStateRecognized) {
        [[[SplashView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)] showInView:self.view atPoint:[sender locationInView:self.view] endSize:8 color:[UIColor redColor]];
    }
}

-(void)_doPan:(UIPanGestureRecognizer*)sender {
    CGPoint panPoint = [sender locationInView:self.view];
    switch (sender.state) {
        case UIGestureRecognizerStateBegan:
            [[[SplashView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)] showInView:self.view atPoint:panPoint endSize:8 color:[UIColor redColor]];
            _lastPanPoint = panPoint;
            break;
        case UIGestureRecognizerStateChanged: {
            [(GestureDiagnosticView*)self.view addLine:_lastPanPoint toPoint:panPoint color:[UIColor redColor] hash:sender.hash];
            _lastPanPoint = panPoint;
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
    self.view.multipleTouchEnabled = YES;
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
