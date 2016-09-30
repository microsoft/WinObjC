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
#import "CGDrawView.h"

@implementation CGPathContainsPointViewController {
    CGDrawView* _theDrawnView;
}

- (void)event:(UITapGestureRecognizer*)event {
    if (CGPathContainsPoint(self.containingPath, NULL, [event locationInView:_theDrawnView], YES)) {
        [self.containsPoint setText:@"ContainsPoint: YES"];
    } else {
        [self.containsPoint setText:@"ContainsPoint: NO"];
    }
}

- (id)initWithDrawingOptions:(CGDrawOptions*)options {
    self = [super initWithDrawingOptions:options];
    return self;
}

- (void)loadView {
    [super loadView];

    UITapGestureRecognizer* tapEvent = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(event:)];
    [self.view addGestureRecognizer:tapEvent];

    _theDrawnView = [[CGDrawView alloc] initWithFrame:self.view.bounds drawOptions:self.options];

    // Create a weak reference to self to avoid bad retain in block.
    __weak CGPathContainsPointViewController* weakSelf = self;
    [_theDrawnView setDrawBlock:^(void) {
        CGContextRef currentContext = UIGraphicsGetCurrentContext();

        CGContextSetLineWidth(currentContext, weakSelf.options.lineWidth);
        CGContextSetStrokeColorWithColor(currentContext, weakSelf.options.lineColor);
        CGContextSetLineDash(currentContext, weakSelf.options.linePhase, weakSelf.options.lineDashPattern, weakSelf.options.lineDashCount);

        weakSelf.containingPath = CGPathCreateMutable();
        CGPathMoveToPoint(weakSelf.containingPath, NULL, 200, 35);
        CGPathAddLineToPoint(weakSelf.containingPath, NULL, 165, 100);
        CGPathAddLineToPoint(weakSelf.containingPath, NULL, 100, 100);
        CGPathAddLineToPoint(weakSelf.containingPath, NULL, 150, 150);
        CGPathAddLineToPoint(weakSelf.containingPath, NULL, 135, 225);
        CGPathAddLineToPoint(weakSelf.containingPath, NULL, 200, 170);
        CGPathAddLineToPoint(weakSelf.containingPath, NULL, 265, 225);
        CGPathAddLineToPoint(weakSelf.containingPath, NULL, 250, 150);
        CGPathAddLineToPoint(weakSelf.containingPath, NULL, 300, 100);
        CGPathAddLineToPoint(weakSelf.containingPath, NULL, 235, 100);

        // Unnecessary as close subpath will finish this line off but for the sake of consistency, have this here.
        CGPathAddLineToPoint(weakSelf.containingPath, NULL, 200, 35);
        CGPathCloseSubpath(weakSelf.containingPath);

        CGContextAddPath(currentContext, weakSelf.containingPath);
        CGContextStrokePath(currentContext);
    }];
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
