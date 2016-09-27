//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import "CGPathContainsPointViewController.h"

@interface CGPathContainsPointDrawView : UIView
@property (readonly) CGFloat lineWidth;
@property (readonly) CGColorRef lineColor;
@property CGMutablePathRef thePath;
@end

@implementation CGPathContainsPointDrawView

- (id)initWithFrame:(CGRect)rect lineWidth:(CGFloat)width color:(CGColorRef)color {
    if (self = [super initWithFrame:rect]) {
        _lineWidth = width;
        _lineColor = color;
        CGColorRetain(color);
    }
    return self;
}

-(void)dealloc {
    CGColorRelease(_lineColor);
}

- (void)drawRect:(CGRect)rect {
    CGContextRef currentContext = UIGraphicsGetCurrentContext();

    CGContextSetLineWidth(currentContext, self.lineWidth);

    CGContextSetStrokeColorWithColor(currentContext, self.lineColor);

    self.thePath = CGPathCreateMutable();
    CGPathMoveToPoint(self.thePath, NULL, 200, 35);
    CGPathAddLineToPoint(self.thePath, NULL, 165, 100);
    CGPathAddLineToPoint(self.thePath, NULL, 100, 100);
    CGPathAddLineToPoint(self.thePath, NULL, 150, 150);
    CGPathAddLineToPoint(self.thePath, NULL, 135, 225);
    CGPathAddLineToPoint(self.thePath, NULL, 200, 170);
    CGPathAddLineToPoint(self.thePath, NULL, 265, 225);
    CGPathAddLineToPoint(self.thePath, NULL, 250, 150);
    CGPathAddLineToPoint(self.thePath, NULL, 300, 100);
    CGPathAddLineToPoint(self.thePath, NULL, 235, 100);

    // Unnecessary as close subpath will finish this line off but for the sake of consistency, have this here.
    CGPathAddLineToPoint(self.thePath, NULL, 200, 35);
    CGPathCloseSubpath(self.thePath);

    CGContextAddPath(currentContext, self.thePath);
    CGContextStrokePath(currentContext);
}

@end

@implementation CGPathContainsPointViewController {
    CGPathContainsPointDrawView* _theDrawnView;
}

- (void)event:(UITapGestureRecognizer*)event {
    if (CGPathContainsPoint(_theDrawnView.thePath, NULL, [event locationInView:_theDrawnView], YES)) {
        [self.containsPoint setText:@"ContainsPoint: YES"];
    } else {
        [self.containsPoint setText:@"ContainsPoint: NO"];
    }
}

- (id)initWithLineWidth:(CGFloat)width LineColor:(CGColorRef)color {
    if (self = [super init]) {
        self = [super initWithLineWidth : width Color : color];
        return self;
    }
    return self;
}

- (void)loadView {
    [super loadView];

    UITapGestureRecognizer* tapEvent = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(event:)];
    [self.view addGestureRecognizer:tapEvent];

    _theDrawnView =
        [[CGPathContainsPointDrawView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height)
                                                 lineWidth:self.lineWidth
                                                     color:self.lineColor];
    [self.view addSubview:_theDrawnView];

    self.containsPoint = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, 170, 40)];
    [self.containsPoint setBackgroundColor:[UIColor whiteColor]];
    [self.containsPoint setText:@"ContainsPoint: NO"];
    [self.view addSubview:self.containsPoint];

    UILabel* instructions = [[UILabel alloc] initWithFrame:CGRectMake(0, 250, 200, 40)];
    [instructions setBackgroundColor:[UIColor whiteColor]];
    [instructions setText:@"Click inside the star."];
    [self.view addSubview:instructions];
}

@end
