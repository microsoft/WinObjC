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

#import "CGPathApplyCurveViewController.h"
#import "CGDrawView.h"

@implementation CGPathApplyCurveViewController

- (void)loadView {
    [super loadView];

    CGDrawView* cgView = [[CGDrawView alloc] initWithFrame:self.view.bounds drawOptions:self.options];

    [cgView setDrawBlock:^(void) {
        CGContextRef currentContext = UIGraphicsGetCurrentContext();

        CGContextSetLineWidth(currentContext, self.options.lineWidth);
        CGContextSetStrokeColorWithColor(currentContext, self.options.lineColor);
        CGContextSetLineDash(currentContext, self.options.linePhase, self.options.lineDashPattern, self.options.lineDashCount);

        CGAffineTransform transformation = self.options.affineTransform;

        CGMutablePathRef thepath = CGPathCreateMutable();

        CGPathMoveToPoint(thepath, &transformation, 100, 450);
        CGPathAddQuadCurveToPoint(thepath, &transformation, 125, 425, 150, 450);
        CGPathMoveToPoint(thepath, &transformation, 200, 450);
        CGPathAddQuadCurveToPoint(thepath, &transformation, 225, 425, 250, 450);
        CGPathMoveToPoint(thepath, &transformation, 100, 550);
        CGPathAddQuadCurveToPoint(thepath, &transformation, 200, 600, 300, 500);
        CGPathMoveToPoint(thepath, &transformation, 285, 505);
        CGPathAddQuadCurveToPoint(thepath, &transformation, 300, 490, 310, 510);

        CGPathMoveToPoint(thepath, &transformation, 100, 100);
        CGPathAddArc(thepath, &transformation, 100, 100, 75, 0, M_PI / 2, true);
        CGPathCloseSubpath(thepath);

        CGPathMoveToPoint(thepath, &transformation, 110, 90);
        CGPathAddArc(thepath, &transformation, 110, 90, 75, M_PI / 2, 0, true);
        CGPathCloseSubpath(thepath);

        CGPathMoveToPoint(thepath, &transformation, 400, 150);
        CGPathAddArc(thepath, &transformation, 300, 150, 100, 0, M_PI / 2, true);
        CGPathAddArc(thepath, &transformation, 300, 150, 100, M_PI / 2, 0, true);
        CGPathMoveToPoint(thepath, &transformation, 200, 150);
        CGPathAddArc(thepath, &transformation, 250, 150, 50, M_PI, 0, false);
        CGPathMoveToPoint(thepath, &transformation, 300, 150);
        CGPathAddArc(thepath, &transformation, 350, 150, 50, M_PI, 0, true);
        CGPathMoveToPoint(thepath, &transformation, 275, 150);
        CGPathAddArc(thepath, &transformation, 250, 150, 25, 0, M_PI / 2, true);
        CGPathAddArc(thepath, &transformation, 250, 150, 25, M_PI / 2, 0, true);
        CGPathMoveToPoint(thepath, &transformation, 375, 150);
        CGPathAddArc(thepath, &transformation, 350, 150, 25, 0, M_PI / 2, true);
        CGPathAddArc(thepath, &transformation, 350, 150, 25, M_PI / 2, 0, true);

        CGContextAddPath(currentContext, thepath);
        CGContextStrokePath(currentContext);

        CGPathApply(thepath, currentContext, CGPathApplyCallback);

        CGPathRelease(thepath);
    }];

    [self.view addSubview:cgView];
}

static void CGPathApplyCallback(void* context, const CGPathElement* element) {
    CGFloat colorComponents[] = { 0, 0, 0, 1 };

    switch (element->type) {
        case kCGPathElementMoveToPoint:
            colorComponents[0] = 1;
            colorComponents[1] = 0;
            colorComponents[2] = 0;
            CGContextSetRGBStrokeColor(context, colorComponents[0], colorComponents[1], colorComponents[2], colorComponents[3]);

            CGContextStrokeRect(context, CGRectMake(element->points[0].x - 2, element->points[0].y - 2, 4, 4));
            break;
        case kCGPathElementAddLineToPoint:
            colorComponents[0] = 0;
            colorComponents[1] = 1;
            colorComponents[2] = 0;
            CGContextSetRGBStrokeColor(context, colorComponents[0], colorComponents[1], colorComponents[2], colorComponents[3]);

            CGContextStrokeRect(context, CGRectMake(element->points[0].x - 2, element->points[0].y - 2, 4, 4));
            break;
        case kCGPathElementAddQuadCurveToPoint:
            colorComponents[0] = 0;
            colorComponents[1] = 1;
            colorComponents[2] = 1;
            CGContextSetRGBStrokeColor(context, colorComponents[0], colorComponents[1], colorComponents[2], colorComponents[3]);

            CGContextStrokeRect(context, CGRectMake(element->points[0].x - 2, element->points[0].y - 2, 4, 4));
            CGContextStrokeRect(context, CGRectMake(element->points[1].x - 2, element->points[1].y - 2, 4, 4));
            break;
        case kCGPathElementAddCurveToPoint:
            colorComponents[0] = 1;
            colorComponents[1] = 0;
            colorComponents[2] = 1;
            CGContextSetRGBStrokeColor(context, colorComponents[0], colorComponents[1], colorComponents[2], colorComponents[3]);

            CGContextStrokeRect(context, CGRectMake(element->points[0].x - 2, element->points[0].y - 2, 4, 4));
            CGContextStrokeRect(context, CGRectMake(element->points[1].x - 2, element->points[1].y - 2, 4, 4));
            CGContextStrokeRect(context, CGRectMake(element->points[2].x - 2, element->points[2].y - 2, 4, 4));
            break;
        case kCGPathElementCloseSubpath:
            break;
    }
}

@end
