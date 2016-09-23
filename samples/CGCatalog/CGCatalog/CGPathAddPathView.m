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

#import "CGPathAddPathView.h"
#import "CGDrawView.h"

@implementation CGPathAddPathView

- (id)initWithLineWidth:(CGFloat)width LineColor:(CGColorRef)color {
    if (self = [super init]) {
        _lineColor = color;
        _lineWidth = width;
    }
    return self;
}

- (void)loadView {
    [super loadView];

    CGDrawView* drawView = [[CGDrawView alloc] initWithFrame:self.view.bounds lineWidth:self.lineWidth color:self.lineColor];
    [drawView setDrawBlock:^(void) {
        CGContextRef currentContext = UIGraphicsGetCurrentContext();

        CGContextSetLineWidth(currentContext, self.lineWidth);

        CGContextSetStrokeColorWithColor(currentContext, self.lineColor);

        CGMutablePathRef theFirstPath = CGPathCreateMutable();
        CGMutablePathRef theSecondPath = CGPathCreateMutable();

        CGPathMoveToPoint(theFirstPath, NULL, 200, 35);
        CGPathAddLineToPoint(theFirstPath, NULL, 165, 100);
        CGPathAddLineToPoint(theFirstPath, NULL, 100, 100);
        CGPathAddLineToPoint(theFirstPath, NULL, 150, 150);
        CGPathAddLineToPoint(theFirstPath, NULL, 135, 225);
        CGPathAddLineToPoint(theFirstPath, NULL, 200, 170);
        CGPathAddLineToPoint(theFirstPath, NULL, 265, 225);

        CGPathMoveToPoint(theSecondPath, NULL, 265, 225);

        CGPathAddLineToPoint(theSecondPath, NULL, 350, 225);
        CGPathAddLineToPoint(theSecondPath, NULL, 350, 35);
        CGPathAddLineToPoint(theSecondPath, NULL, 200, 35);

        CGPathAddPath(theFirstPath, NULL, theSecondPath);
        CGContextAddPath(currentContext, theFirstPath);

        // Closing the path will close the subpath created from adding the second path to the first.
        CGContextClosePath(currentContext);
        CGContextStrokePath(currentContext);

        CGPathRelease(theFirstPath);
        CGPathRelease(theSecondPath);
    }];

    [self.view addSubview:drawView];
}

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 0;
}

@end
