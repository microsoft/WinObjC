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

#import "ShadowViewController.h"

int const c_scrollViewContentWidth = 600;
int const c_scrollViewContentHeight = 400;

@implementation ShadowViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor whiteColor];

    scrollView = [[UIScrollView alloc] initWithFrame:self.view.bounds];
    [scrollView setContentSize:CGSizeMake(c_scrollViewContentWidth, c_scrollViewContentHeight)];

    shadowDrawerView = [[ShadowDrawerView alloc] initWithFrame:CGRectMake(0, 0, c_scrollViewContentWidth, c_scrollViewContentHeight)];
    shadowDrawerView.backgroundColor = [UIColor whiteColor];

    [scrollView addSubview:shadowDrawerView];
    [scrollView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
    [self.view addSubview:scrollView];
}

@end

@implementation ShadowDrawerView

- (void)drawRect:(CGRect)rect {
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGFloat dashLen[] = { 10, 10 };
    CGContextSetLineDash(context, 0, dashLen, 2);
    CGContextSetRGBStrokeColor(context, 1, 0, 0, 1);
    CGContextSetShadow(context, CGSizeMake(5, 5), 0);

    CGContextAddEllipseInRect(context, CGRectMake(350, 50, 100, 100));
    CGContextAddRect(context, CGRectMake(200, 50, 100, 100));
    CGContextMoveToPoint(context, 150, 50);
    CGContextAddLineToPoint(context, 50, 150);

    CGContextStrokePath(context);

    CGContextSetLineWidth(context, 10);
    CGContextSetRGBStrokeColor(context, 0, 0, 1, 1);
    CGContextSetLineDash(context, 0, NULL, 0);
    CGContextSetShadowWithColor(context, CGSizeMake(-10, 10), 3, [UIColor greenColor].CGColor);

    CGContextAddEllipseInRect(context, CGRectMake(350, 250, 150, 100));
    CGContextAddRect(context, CGRectMake(200, 250, 100, 100));
    CGContextMoveToPoint(context, 150, 250);
    CGContextAddLineToPoint(context, 50, 350);

    CGContextStrokePath(context);
}

@end