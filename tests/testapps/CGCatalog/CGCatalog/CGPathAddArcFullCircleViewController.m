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

#import "CGPathAddArcFullCircleViewController.h"
#import "CGDrawView.h"

@implementation CGPathAddArcFullCircleViewController

- (void)loadView {
    [super loadView];
    [self.view setBackgroundColor:[UIColor clearColor]];

    CGDrawView* drawView = [[CGDrawView alloc] initWithFrame:self.view.bounds drawOptions:self.options];
    [drawView setDrawBlock:^(void) {
        CGContextRef currentContext = UIGraphicsGetCurrentContext();

        CGContextSetLineWidth(currentContext, self.options.lineWidth);
        CGContextSetStrokeColorWithColor(currentContext, self.options.lineColor);
        CGContextSetLineDash(currentContext, self.options.linePhase, self.options.lineDashPattern, self.options.lineDashCount);

        CGAffineTransform transformation = self.options.affineTransform;

        CGMutablePathRef thepath = CGPathCreateMutable();
        CGPathMoveToPoint(thepath, &transformation, 75, 50);
        CGPathAddArc(thepath, &transformation, 50, 50, 25, 0, 2 * M_PI, true);
        CGPathMoveToPoint(thepath, &transformation, 175, 50);
        CGPathAddArc(thepath, &transformation, 150, 50, 25, 2 * M_PI, 0, true);
        CGPathMoveToPoint(thepath, &transformation, 75, 150);
        CGPathAddArc(thepath, &transformation, 50, 150, 25, 0, 2 * M_PI, false);
        CGPathMoveToPoint(thepath, &transformation, 175, 150);
        CGPathAddArc(thepath, &transformation, 150, 150, 25, 2 * M_PI, 0, false);

        CGContextAddPath(currentContext, thepath);

        CGContextStrokePath(currentContext);

        CGPathRelease(thepath);

        [super drawComparisonCGImageFromImageName:@"FullCircles" intoContext:currentContext];
    }];

    [self.view addSubview:drawView];

    [super addComparisonLabel];
}

@end
