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

#import "CGCCGContextBeginEndTransparencyLayer.h"

@interface TransparencyView : UIView

@end

@implementation TransparencyView

- (void)drawRect:(CGRect)rect {
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGFloat maxWidth = rect.size.width;
    CGFloat maxHeight = rect.size.height;

    // White background
    CGContextSetFillColorWithColor(context, [UIColor whiteColor].CGColor);
    CGContextFillRect(context, CGRectMake(0, 0, maxWidth, maxHeight));

    // Rect Size
    CGFloat rectWidth = maxWidth / 2.0;
    CGFloat rectHeight = rectWidth;
    // CGFloat rectHeight = maxHeight / 2.0;

    // Draw background rect
    CGContextSetFillColorWithColor(context, [UIColor yellowColor].CGColor);
    CGContextFillRect(context, CGRectMake(rectWidth / 2 - 25, maxHeight / 2 - rectHeight / 2 - 25, rectWidth + 25, rectHeight + 25));

    // Note: Shadow or Alpha would be better test samples for this, but are not fully implemented yet in the bridge.
    // TODO: Use Shadow or Alpha instead of BlendMode when supported by the bridge
    // Enable shadow
    /*CGSize shadowOffset = CGSizeMake(10, 20);
    CGContextSetShadow(context, shadowOffset, 10);*/
    // Set composite alpha of the transparency layer
    // CGContextSetAlpha(context, 0.5);

    CGContextSetBlendMode(context, kCGBlendModeDifference);

    // Begin Transparency
    CGContextBeginTransparencyLayer(context, NULL);

    CGContextSetFillColorWithColor(context, [UIColor redColor].CGColor);
    CGContextFillRect(context, CGRectMake(rectWidth / 2 + 25, maxHeight / 2 - rectHeight / 2 - 50, rectWidth, rectHeight));
    CGContextSetFillColorWithColor(context, [UIColor greenColor].CGColor);
    CGContextFillRect(context, CGRectMake(rectWidth / 2 - 25, maxHeight / 2 - rectHeight / 2 + 25, rectWidth, rectHeight));
    CGContextSetFillColorWithColor(context, [UIColor blueColor].CGColor);
    CGContextFillRect(context, CGRectMake(rectWidth / 2 - 50, maxHeight / 2 - rectHeight / 2, rectWidth, rectHeight));

    // End Transparency
    CGContextEndTransparencyLayer(context);
}

@end

@interface CGCCGContextBeginEndTransparencyLayer ()

@property (strong, nonatomic, nullable) TransparencyView* customView;

@end

@implementation CGCCGContextBeginEndTransparencyLayer

- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor whiteColor];

    self.customView = [[TransparencyView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height)];
    [self.view addSubview:self.customView];
}

@end
