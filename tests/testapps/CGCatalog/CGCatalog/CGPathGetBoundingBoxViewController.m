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

#import "CGPathGetBoundingBoxViewController.h"
#import "CGDrawView.h"

@implementation CGPathGetBoundingBoxViewController

- (id)initWithDrawingOptions:(CGDrawOptions*)options {
    self = [super initWithDrawingOptions:options];
    return self;
}

- (void)loadView {
    [super loadView];

    CGDrawView* drawView = [[CGDrawView alloc] initWithFrame:self.view.bounds drawOptions:self.options];
    [drawView setDrawBlock:^(void) {
        CGContextRef currentContext = UIGraphicsGetCurrentContext();

        CGContextSetLineWidth(currentContext, self.options.lineWidth);
        CGContextSetStrokeColorWithColor(currentContext, self.options.lineColor);
        CGContextSetLineDash(currentContext, self.options.linePhase, self.options.lineDashPattern, self.options.lineDashCount);

        CGMutablePathRef thepath = CGPathCreateMutable();
        CGPathMoveToPoint(thepath, NULL, 200, 35);
        CGPathAddLineToPoint(thepath, NULL, 165, 100);
        CGPathAddLineToPoint(thepath, NULL, 100, 100);
        CGPathAddLineToPoint(thepath, NULL, 150, 150);
        CGPathAddLineToPoint(thepath, NULL, 135, 225);
        CGPathAddLineToPoint(thepath, NULL, 200, 170);
        CGPathAddLineToPoint(thepath, NULL, 265, 225);
        CGPathAddLineToPoint(thepath, NULL, 250, 150);
        CGPathAddLineToPoint(thepath, NULL, 300, 100);
        CGPathAddLineToPoint(thepath, NULL, 235, 100);
        CGPathAddLineToPoint(thepath, NULL, 200, 35);
        CGPathCloseSubpath(thepath);

        CGContextAddPath(currentContext, thepath);
        CGContextStrokePath(currentContext);

        CGRect boundingBox = CGPathGetBoundingBox(thepath);
        CGContextStrokeRect(currentContext, boundingBox);

        CGPathRelease(thepath);

        [super drawComparisonCGImageFromImageName:@"GetBoundingBox" intoContext:currentContext];
    }];

    [self.view addSubview:drawView];

    [super addComparisonLabel];
}

@end
