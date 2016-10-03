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

#import "CGPathCloseSubpathViewController.h"
#import "CGDrawView.h"

@implementation CGPathCloseSubpathViewController

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

        CGMutablePathRef thePath = CGPathCreateMutable();
        CGPathMoveToPoint(thePath, NULL, 50, 50);
        CGPathAddLineToPoint(thePath, NULL, 50, 100);
        CGPathAddLineToPoint(thePath, NULL, 100, 100);
        CGPathCloseSubpath(thePath);

        CGPathMoveToPoint(thePath, NULL, 200, 50);
        CGPathAddLineToPoint(thePath, NULL, 200, 100);
        CGPathAddLineToPoint(thePath, NULL, 150, 100);
        CGPathCloseSubpath(thePath);

        CGPathMoveToPoint(thePath, NULL, 100, 200);
        CGPathAddLineToPoint(thePath, NULL, 125, 150);
        CGPathAddLineToPoint(thePath, NULL, 150, 200);
        CGPathCloseSubpath(thePath);

        CGPathCloseSubpath(thePath);
        CGContextAddPath(currentContext, thePath);
        CGContextStrokePath(currentContext);

        CGPathRelease(thePath);

        [super drawComparisonCGImageFromImageName:@"CloseSubPath" intoContext:currentContext];
    }];

    [self.view addSubview:drawView];

    [super addComparisonLabel];
}

@end
