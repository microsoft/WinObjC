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

#import "CGPathAddRectViewController.h"
#import "CGDrawView.h"

@implementation CGPathAddRectViewController

- (id)initWithLineWidth:(CGFloat)width
              lineColor:(CGColorRef)color
            dashPattern:(CGFloat*)pattern
                  phase:(CGFloat)phase
              dashCount:(size_t)count {
    self = [super initWithLineWidth:width color:color dashPattern:pattern phase:phase dashCount:count];
    return self;
}

- (void)loadView {
    [super loadView];

    CGDrawView* drawView = [[CGDrawView alloc] initWithFrame:self.view.bounds lineWidth:self.lineWidth color:self.lineColor];
    [drawView setDrawBlock:^(void) {
        CGContextRef currentContext = UIGraphicsGetCurrentContext();

        CGContextSetLineWidth(currentContext, self.lineWidth);
        CGContextSetStrokeColorWithColor(currentContext, self.lineColor);
        CGContextSetLineDash(currentContext, self.linePhase, self.lineDashPattern, self.lineDashCount);

        CGMutablePathRef thePath = CGPathCreateMutable();

        CGPathMoveToPoint(thePath, NULL, 50, 50);
        CGPathAddLineToPoint(thePath, NULL, 100, 100);

        CGPathAddRect(thePath, NULL, CGRectMake(100, 100, 200, 100));

        CGContextAddPath(currentContext, thePath);

        CGContextStrokePath(currentContext);

        CGPathRelease(thePath);

        [super drawComparisonCGImageFromImageName:@"PathAddRect" intoContext:currentContext];
    }];

    [self.view addSubview:drawView];

    [super addComparisonLabel];
}

@end
