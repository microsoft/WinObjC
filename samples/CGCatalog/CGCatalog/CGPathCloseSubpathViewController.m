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

- (id)initWithLineWidth:(CGFloat)width LineColor:(CGColorRef)color {
    self = [super initWithLineWidth : width Color : color];
    return self;
}

- (void)loadView {
    [super loadView];

    CGDrawView* drawView = [[CGDrawView alloc] initWithFrame:self.view.bounds lineWidth:self.lineWidth color:self.lineColor];
    [drawView setDrawBlock:^(void) {
        CGContextRef currentContext = UIGraphicsGetCurrentContext();

        CGContextSetLineWidth(currentContext, self.lineWidth);

        CGContextSetStrokeColorWithColor(currentContext, self.lineColor);

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
    }];

    [self.view addSubview:drawView];
}

@end
