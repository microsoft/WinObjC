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

#import "CGCCGBitmapContentViewController.h"

@interface CustomBitmapView : UIView {
}

@property (nonatomic, assign) size_t bits;
@property (nonatomic, assign) size_t bitsPerPixel;
@property (nonatomic, assign) CGBitmapInfo info;

@end

@implementation CustomBitmapView {
}

- (void)drawRect:(CGRect)rect {
    CGContextRef context = UIGraphicsGetCurrentContext();

    CGContextSetLineWidth(context, 2.0);

    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();

    CGFloat components[] = { 0.0, 0.0, 1.0, 1.0 };

    CGColorRef color = CGColorCreate(colorspace, components);

    CGContextSetStrokeColorWithColor(context, color);

    CGContextMoveToPoint(context, 0, 0);
    CGContextAddLineToPoint(context, rect.size.width, rect.size.height);

    CGContextStrokePath(context);
    CGColorSpaceRelease(colorspace);

    self.bits = CGBitmapContextGetBitsPerComponent(context);
    self.info = CGBitmapContextGetBitmapInfo(context);
    self.bitsPerPixel = CGBitmapContextGetBitsPerPixel(context);

    CGColorRelease(color);
}

@end

@interface CGCCGBitmapContentViewController ()

@end

@implementation CGCCGBitmapContentViewController {
    CustomBitmapView* _customView;
    UILabel* _bitmapInfoTextView;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];

    _customView = [[CustomBitmapView alloc] initWithFrame:CGRectMake(20, 20, 100, 100)];
    [self.view addSubview:_customView];

    _bitmapInfoTextView = [[UILabel alloc] initWithFrame:CGRectMake(20, 140, 300, 100)];
    [_bitmapInfoTextView setNumberOfLines:0];
    [self.view addSubview:_bitmapInfoTextView];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    NSString* bitmapDetails =
        [NSString stringWithFormat:@"Bits per component: %zu expects 8\nBits per pixel: %zu expects 32\nBitmapInfo is %u expects 8198",
                                   _customView.bits,
                                   _customView.bitsPerPixel,
                                   _customView.info];
    [_bitmapInfoTextView setText:bitmapDetails];
}

@end
