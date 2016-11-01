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

#import "CGPathAddArcViewController.h"
#import "CGDrawView.h"

@implementation CGPathAddArcViewController

- (id)initWithDrawingOptions:(CGDrawOptions*)options {
    self = [super initWithDrawingOptions:options];
    return self;
}

- (void)loadView {
    [super loadView];
    [self.view setBackgroundColor:[UIColor clearColor]];

    CGDrawView* drawView = [[CGDrawView alloc] initWithFrame:self.view.bounds drawOptions:self.options];
    [drawView setDrawBlock:^(void) {
        CGContextRef currentContext = UIGraphicsGetCurrentContext();

        CGContextSetLineWidth(currentContext, self.options.lineWidth);
        CGContextSetStrokeColorWithColor(currentContext, self.options.lineColor);
        CGContextSetLineDash(currentContext, self.options.linePhase, self.options.lineDashPattern, self.options.lineDashCount);

        CGMutablePathRef thepath = CGPathCreateMutable();
        CGPathMoveToPoint(thepath, NULL, 100, 100);
        CGPathAddArc(thepath, NULL, 100, 100, 75, 0, M_PI / 2, true);
        CGPathCloseSubpath(thepath);

        CGPathMoveToPoint(thepath, NULL, 110, 90);
        CGPathAddArc(thepath, NULL, 110, 90, 75, M_PI / 2, 0, true);
        CGPathCloseSubpath(thepath);

        CGPathMoveToPoint(thepath, NULL, 400, 150);
        CGPathAddArc(thepath, NULL, 300, 150, 100, 0, M_PI / 2, true);
        CGPathAddArc(thepath, NULL, 300, 150, 100, M_PI / 2, 0, true);
        CGPathMoveToPoint(thepath, NULL, 200, 150);
        CGPathAddArc(thepath, NULL, 250, 150, 50, M_PI, 0, false);
        CGPathMoveToPoint(thepath, NULL, 300, 150);
        CGPathAddArc(thepath, NULL, 350, 150, 50, M_PI, 0, true);
        CGPathMoveToPoint(thepath, NULL, 275, 150);
        CGPathAddArc(thepath, NULL, 250, 150, 25, 0, M_PI / 2, true);
        CGPathAddArc(thepath, NULL, 250, 150, 25, M_PI / 2, 0, true);
        CGPathMoveToPoint(thepath, NULL, 375, 150);
        CGPathAddArc(thepath, NULL, 350, 150, 25, 0, M_PI / 2, true);
        CGPathAddArc(thepath, NULL, 350, 150, 25, M_PI / 2, 0, true);

        CGContextAddPath(currentContext, thepath);

        CGContextStrokePath(currentContext);

        CGPathRelease(thepath);

        [super drawComparisonCGImageFromImageName:@"AddArc" intoContext:currentContext];
    }];

    [self.view addSubview:drawView];

    [super addComparisonLabel];
}

@end
