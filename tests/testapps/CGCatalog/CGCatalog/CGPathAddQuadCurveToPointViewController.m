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

#import "CGPathAddQuadCurveToPointViewController.h"
#import "CGDrawView.h"

@implementation CGPathAddQuadCurveToPointViewController

- (void)loadView {
    [super loadView];

    CGDrawView* drawView = [[CGDrawView alloc] initWithFrame:self.view.bounds drawOptions:self.options];
    [drawView setDrawBlock:^(void) {
        CGContextRef currentContext = UIGraphicsGetCurrentContext();

        CGContextSetLineWidth(currentContext, self.options.lineWidth);
        CGContextSetStrokeColorWithColor(currentContext, self.options.lineColor);
        CGContextSetLineDash(currentContext, self.options.linePhase, self.options.lineDashPattern, self.options.lineDashCount);

        CGAffineTransform transformation = self.options.affineTransform;

        CGMutablePathRef thePath = CGPathCreateMutable();

        CGPathMoveToPoint(thePath, &transformation, 100, 50);
        CGPathAddQuadCurveToPoint(thePath, &transformation, 125, 25, 150, 50);

        CGPathMoveToPoint(thePath, &transformation, 200, 50);
        CGPathAddQuadCurveToPoint(thePath, &transformation, 225, 25, 250, 50);

        CGPathMoveToPoint(thePath, &transformation, 100, 150);
        CGPathAddQuadCurveToPoint(thePath, &transformation, 200, 200, 300, 100);

        CGPathMoveToPoint(thePath, &transformation, 285, 105);
        CGPathAddQuadCurveToPoint(thePath, &transformation, 300, 90, 310, 110);

        CGContextAddPath(currentContext, thePath);

        CGContextStrokePath(currentContext);

        CGPathRelease(thePath);

        [super drawComparisonCGImageFromImageName:@"AddQuadCurveToPoint" intoContext:currentContext];
    }];

    [self.view addSubview:drawView];

    [super addComparisonLabel];
}

@end
