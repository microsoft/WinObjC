///******************************************************************************
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

#import "CGPathAddLineToPointViewController.h"
#import "CGDrawView.h"

@implementation CGPathAddLineToPointViewController

- (void)loadView {
    [super loadView];

    CGDrawView* drawView = [[CGDrawView alloc] initWithFrame:self.view.bounds drawOptions:self.options];
    [drawView setDrawBlock:^(void) {
        CGContextRef currentContext = UIGraphicsGetCurrentContext();

        CGContextSetLineWidth(currentContext, self.options.lineWidth);
        CGContextSetStrokeColorWithColor(currentContext, self.options.lineColor);
        CGContextSetLineDash(currentContext, self.options.linePhase, self.options.lineDashPattern, self.options.lineDashCount);

        CGAffineTransform transformation = self.options.affineTransform;

        CGMutablePathRef thepath = CGPathCreateMutable();
        CGPathMoveToPoint(thepath, &transformation, 200, 35);
        CGPathAddLineToPoint(thepath, &transformation, 165, 100);
        CGPathAddLineToPoint(thepath, &transformation, 100, 100);
        CGPathAddLineToPoint(thepath, &transformation, 150, 150);
        CGPathAddLineToPoint(thepath, &transformation, 135, 225);
        CGPathAddLineToPoint(thepath, &transformation, 200, 170);
        CGPathAddLineToPoint(thepath, &transformation, 265, 225);
        CGPathAddLineToPoint(thepath, &transformation, 250, 150);
        CGPathAddLineToPoint(thepath, &transformation, 300, 100);
        CGPathAddLineToPoint(thepath, &transformation, 235, 100);

        // Unnecessary as close subpath will finish this line off but for the sake of consistency, have this here.
        CGPathAddLineToPoint(thepath, &transformation, 200, 35);

        CGPathCloseSubpath(thepath);
        CGContextAddPath(currentContext, thepath);
        CGContextStrokePath(currentContext);

        CGPathRelease(thepath);

        [super drawComparisonCGImageFromImageName:@"AddLineToPoint" intoContext:currentContext];
    }];

    [self.view addSubview:drawView];

    [super addComparisonLabel];
}

@end
