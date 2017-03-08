//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import "BezierViewController.h"

@interface WOCBezierPathView : UIView
@end

@implementation WOCBezierPathView
+ (Class)layerClass {
    return [CAShapeLayer class];
}

- (CAShapeLayer*)shape {
    return (CAShapeLayer*)self.layer;
}
@end

@implementation BezierViewController
- (void)viewWillLayoutSubviews {
    CGFloat scale = [UIScreen mainScreen].scale;
    CGRect bounds = _bezierPath1.bounds;

    _bezierPath1.shape.path = [UIBezierPath bezierPathWithRoundedRect:CGRectInset(bounds, 10, 10) cornerRadius:10.0f].CGPath;
    _bezierPath1.shape.lineWidth = 10.0f;
    _bezierPath1.shape.fillColor = [UIColor blueColor].CGColor;
    _bezierPath1.shape.strokeColor = [UIColor grayColor].CGColor;
    _bezierPath1.shape.contentsScale = scale;

    CGPoint center = CGPointMake(bounds.size.width / 2, bounds.size.height / 2);
    CGFloat minDimension = center.x < center.y ? center.x : center.y;
    minDimension -= 5.0;
    _bezierPath2.shape.path =
        [UIBezierPath bezierPathWithArcCenter:center radius:minDimension startAngle:0 endAngle:M_PI clockwise:NO].CGPath;
    _bezierPath2.shape.lineWidth = 5.0f;
    _bezierPath2.shape.fillColor = [UIColor blueColor].CGColor;
    _bezierPath2.shape.strokeColor = [UIColor grayColor].CGColor;
    _bezierPath2.shape.contentsScale = scale;

    _bezierPath3.shape.path = [UIBezierPath bezierPathWithOvalInRect:CGRectInset(bounds, 10, 10)].CGPath;
    _bezierPath3.shape.lineWidth = 10.0f;
    _bezierPath3.shape.fillColor = [UIColor blueColor].CGColor;
    _bezierPath3.shape.strokeColor = [UIColor grayColor].CGColor;
    _bezierPath3.shape.contentsScale = scale;

    // Three views that draw the same line with three different line end caps.
    CGRect lineViewBounds = [_endCapViews[0] bounds];
    CGMutablePathRef otherLineCapsPath = CGPathCreateMutable();

    CGPathMoveToPoint(otherLineCapsPath, NULL, 10, 10);
    CGPathAddLineToPoint(otherLineCapsPath, NULL, lineViewBounds.size.width - 20, lineViewBounds.size.height - 20);

    NSString* lineCapNames[] = { kCALineCapButt, kCALineCapRound, kCALineCapSquare };
    int i = 0;
    for (WOCBezierPathView* lineCapView in _endCapViews) {
        CAShapeLayer* shape = lineCapView.shape;
        shape.path = otherLineCapsPath;
        shape.lineWidth = 5.0f;
        shape.fillColor = NULL;
        shape.strokeColor = [UIColor yellowColor].CGColor;
        shape.contentsScale = scale;
        shape.lineCap = lineCapNames[i++];
    }

    // Two views that draw the same concentric circles path with two different fill rules.
    CGRect circleViewBounds = [_fillModeViews[0] bounds];
    CGFloat width = circleViewBounds.size.width;
    CGFloat height = circleViewBounds.size.height;
    CGFloat xstart = circleViewBounds.origin.x;
    CGFloat ystart = circleViewBounds.origin.y;

    CGMutablePathRef otherFillModesPath = CGPathCreateMutable();

    CGPathMoveToPoint(otherFillModesPath, NULL, xstart + .25 * width + .4 * height, ystart + .5 * height);
    CGPathAddArc(otherFillModesPath, NULL, xstart + .25 * width, ystart + .5 * height, .4 * height, 0, M_PI, true);
    CGPathAddArc(otherFillModesPath, NULL, xstart + .25 * width, ystart + .5 * height, .4 * height, M_PI, 0, true);

    CGPathMoveToPoint(otherFillModesPath, NULL, xstart + .25 * width + .3 * height, ystart + .5 * height);
    CGPathAddArc(otherFillModesPath, NULL, xstart + .25 * width, ystart + .5 * height, .3 * height, 0, M_PI, true);
    CGPathAddArc(otherFillModesPath, NULL, xstart + .25 * width, ystart + .5 * height, .3 * height, M_PI, 0, true);

    CGPathMoveToPoint(otherFillModesPath, NULL, xstart + .25 * width + .2 * height, ystart + .5 * height);
    CGPathAddArc(otherFillModesPath, NULL, xstart + .25 * width, ystart + .5 * height, .2 * height, 0, M_PI, true);
    CGPathAddArc(otherFillModesPath, NULL, xstart + .25 * width, ystart + .5 * height, .2 * height, M_PI, 0, true);

    CGPathMoveToPoint(otherFillModesPath, NULL, xstart + .25 * width + .1 * height, ystart + .5 * height);
    CGPathAddArc(otherFillModesPath, NULL, xstart + .25 * width, ystart + .5 * height, .1 * height, 0, M_PI, true);
    CGPathAddArc(otherFillModesPath, NULL, xstart + .25 * width, ystart + .5 * height, .1 * height, M_PI, 0, true);

    CGPathCloseSubpath(otherFillModesPath);

    CGPathMoveToPoint(otherFillModesPath, NULL, xstart + .75 * width + .4 * height, ystart + .5 * height);
    CGPathAddArc(otherFillModesPath, NULL, xstart + .75 * width, ystart + .5 * height, .4 * height, 0, M_PI, false);
    CGPathAddArc(otherFillModesPath, NULL, xstart + .75 * width, ystart + .5 * height, .4 * height, M_PI, 0, false);

    CGPathMoveToPoint(otherFillModesPath, NULL, xstart + .75 * width + .3 * height, ystart + .5 * height);
    CGPathAddArc(otherFillModesPath, NULL, xstart + .75 * width, ystart + .5 * height, .3 * height, 0, M_PI, true);
    CGPathAddArc(otherFillModesPath, NULL, xstart + .75 * width, ystart + .5 * height, .3 * height, M_PI, 0, true);

    CGPathMoveToPoint(otherFillModesPath, NULL, xstart + .75 * width + .2 * height, ystart + .5 * height);
    CGPathAddArc(otherFillModesPath, NULL, xstart + .75 * width, ystart + .5 * height, .2 * height, 0, M_PI, false);
    CGPathAddArc(otherFillModesPath, NULL, xstart + .75 * width, ystart + .5 * height, .2 * height, M_PI, 0, false);

    CGPathMoveToPoint(otherFillModesPath, NULL, xstart + .75 * width + .1 * height, ystart + .5 * height);
    CGPathAddArc(otherFillModesPath, NULL, xstart + .75 * width, ystart + .5 * height, .1 * height, 0, M_PI, true);
    CGPathAddArc(otherFillModesPath, NULL, xstart + .75 * width, ystart + .5 * height, .1 * height, M_PI, 0, true);

    CGPathCloseSubpath(otherFillModesPath);

    NSString* fillRuleNames[] = { kCAFillRuleNonZero, kCAFillRuleEvenOdd };
    i = 0;
    for (WOCBezierPathView* fillModeView in _fillModeViews) {
        CAShapeLayer* shape = fillModeView.shape;
        shape.path = otherFillModesPath;
        shape.lineWidth = 1.0f;
        shape.fillColor = [UIColor whiteColor].CGColor;
        shape.strokeColor = [UIColor redColor].CGColor;
        shape.contentsScale = scale;
        shape.fillRule = fillRuleNames[i++];
    }

    CGPathRelease(otherLineCapsPath);
    CGPathRelease(otherFillModesPath);
}

- (void)viewDidLayoutSubviews {
    [(UIScrollView*)self.view setContentSize:[self.view.subviews[0] bounds].size];
}

@end
