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

#import "CGPathAddCurveToPointView.h"
#import "CGDrawView.h"

@implementation CGPathAddCurveToPointView

- (id)initWithLineWidth:(CGFloat)width LineColor:(CGColorRef)color {
    if (self = [super init]) {
        _lineColor = color;
        _lineWidth = width;
    }
    return self;
}

- (void)loadView {
    [super loadView];
    [self.view setBackgroundColor:[UIColor clearColor]];

    CGDrawView* drawView = [[CGDrawView alloc] initWithFrame:self.view.bounds lineWidth:self.lineWidth color:self.lineColor];
    [drawView setDrawBlock:^(void) {
        CGContextRef currentContext = UIGraphicsGetCurrentContext();

        CGContextSetLineWidth(currentContext, self.lineWidth);

        CGContextSetStrokeColorWithColor(currentContext, self.lineColor);

        CGMutablePathRef thepath = CGPathCreateMutable();
        CGPathMoveToPoint(thepath, NULL, 30, 100);
        CGPathAddCurveToPoint(thepath, NULL, 47.0f, 67.0f, 50.0f, 55.0f, 45.0f, 50.0f);
        CGPathAddCurveToPoint(thepath, NULL, 42.0f, 47.0f, 37.0f, 46.0f, 30.0f, 55.0f);

        CGPathAddCurveToPoint(thepath, NULL, 23.0f, 46.0f, 18.0f, 47.0f, 15.0f, 50.0f);
        CGPathAddCurveToPoint(thepath, NULL, 10.0f, 55.0f, 13.0f, 67.0f, 30.0f, 100.0f);

        CGPathCloseSubpath(thepath);
        CGContextAddPath(currentContext, thepath);

        CGContextStrokePath(currentContext);

        CGPathRelease(thepath);
    }];

    [self.view addSubview:drawView];
}

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 0;
}

@end
