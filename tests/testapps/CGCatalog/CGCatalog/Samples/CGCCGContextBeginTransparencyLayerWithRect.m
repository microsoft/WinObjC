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

#import "CGCCGContextBeginTransparencyLayerWithRect.h"

@interface TransparencyViewRect : UIView

@end

@implementation TransparencyViewRect

- (void)drawRect:(CGRect)rect {
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGFloat maxWidth = rect.size.width;
    CGFloat maxHeight = rect.size.height;

    // White background
    CGContextSetFillColorWithColor(context, [UIColor whiteColor].CGColor);
    CGContextFillRect(context, rect);

    // Rect Size
    CGFloat rectWidth = maxWidth / 2.0;
    CGFloat rectHeight = rectWidth;

    // Draw background rect
    CGContextSetFillColorWithColor(context, [UIColor yellowColor].CGColor);
    CGRect aRect = CGRectMake(rectWidth / 2 - 25, maxHeight / 2 - rectHeight / 2 - 25, rectWidth + 25, rectHeight + 25);
    CGContextFillRect(context, aRect);

    // Set the blend mode to use between the background rectangle and the ones in the transparency layer
    // Note: The rectangles in the transparency layer should NOT be blended with each other.
    //       Only the background rectangle should be blended with the ones in the layer.
    CGContextSetBlendMode(context, kCGBlendModeHue);

    // Begin Transparency
    CGRect bRect = CGRectInset(aRect, 10, 10);
    CGContextBeginTransparencyLayerWithRect(context, bRect, NULL);

    CGContextSetFillColorWithColor(context, [UIColor redColor].CGColor);
    CGRect cRect = CGRectMake(rectWidth / 2 + 25, maxHeight / 2 - rectHeight / 2 - 50, rectWidth, rectHeight);
    CGContextFillRect(context, cRect);
    CGContextSetFillColorWithColor(context, [UIColor greenColor].CGColor);
    CGRect dRect = CGRectMake(rectWidth / 2 - 25, maxHeight / 2 - rectHeight / 2 + 25, rectWidth, rectHeight);
    CGContextFillRect(context, dRect);
    CGContextSetFillColorWithColor(context, [UIColor blueColor].CGColor);
    CGRect eRect = CGRectMake(rectWidth / 2 - 50, maxHeight / 2 - rectHeight / 2, rectWidth, rectHeight);
    CGContextFillRect(context, eRect);

    // End Transparency
    CGContextEndTransparencyLayer(context);
}

@end

@interface CGCCGContextBeginTransparencyLayerWithRect ()

@property (strong, nonatomic, nullable) TransparencyViewRect* customView;

@end

@implementation CGCCGContextBeginTransparencyLayerWithRect

- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor whiteColor];

    self.customView =
        [[TransparencyViewRect alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height)];
    [self.view addSubview:self.customView];
}

@end
