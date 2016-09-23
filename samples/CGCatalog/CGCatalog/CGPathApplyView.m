//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import "CGPathApplyView.h"

@interface CGPathApplyDrawView : UIView
@property (assign) CGFloat lineWidth;
@property (assign) CGColorRef lineColor;
@end

@implementation CGPathApplyDrawView
- (id)initWithFrame:(CGRect)rect lineWidth:(CGFloat)width color:(CGColorRef)color {
    if (self = [super initWithFrame:rect]) {
        _lineWidth = width;
        _lineColor = color;
    }
    return self;
}

- (void)drawRect:(CGRect)rect {
    CGContextRef currentContext = UIGraphicsGetCurrentContext();

    CGContextSetLineWidth(currentContext, self.lineWidth);

    CGContextSetStrokeColorWithColor(currentContext, self.lineColor);

    CGMutablePathRef thepath = CGPathCreateMutable();
    void CGPathApplyCallback(void* context, const CGPathElement* element);

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
    // This function draws a line from the center of the star (200,125) to each segment's starting point.
    CGPathApply(thepath, currentContext, CGPathApplyCallback);

    // Unnecessary as close subpath will finish this line off but for the sake of consistency, have this here.
    CGPathAddLineToPoint(thepath, NULL, 200, 35);

    CGPathCloseSubpath(thepath);
    CGContextAddPath(currentContext, thepath);
    CGContextStrokePath(currentContext);

    CGPathRelease(thepath);
}

void CGPathApplyCallback(void* context, const CGPathElement* element) {
    CGPoint* points = element->points;
    CGContextMoveToPoint(context, 200, 125);
    CGContextAddLineToPoint(context, points[0].x, points[0].y);
    CGContextStrokePath(context);
}

@end

@implementation CGPathApplyView

- (id)initWithLineWidth:(CGFloat)width LineColor:(CGColorRef)color {
    if (self = [super init]) {
        _lineColor = color;
        _lineWidth = width;
    }
    return self;
}

- (void)loadView {
    [super loadView];

    UIView* cgView = [[CGPathApplyDrawView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height)
                                                      lineWidth:self.lineWidth
                                                          color:self.lineColor];
    [self.view addSubview:cgView];
}

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 0;
}

@end
