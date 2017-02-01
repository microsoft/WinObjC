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

#import "CGContextShadowViewController.h"

#import <CoreGraphics/CoreGraphics.h>

@interface _ShadowView : UIView
@property (nonatomic, assign) CGSize shadowOffset;
@property (nonatomic, assign) CGFloat shadowBlur;
@property (nonatomic, assign) CGFloat shadowOpacity;
@property (nonatomic, assign) CGFloat contextRotationDegrees;
@end

@implementation _ShadowView

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
    }
    return self;
}

- (void)drawRect:(CGRect)rect {
    [super drawRect:rect];

    CGRect bounds = self.bounds;
    CGFloat thirdWidth = bounds.size.width / 3.f;
    CGFloat rectWidth = thirdWidth * .60f;
    CGFloat rectY = thirdWidth - rectWidth;
    CGRect leftRect{ { (thirdWidth - rectWidth) / 2.f, rectY }, { rectWidth, rectWidth } };
    CGRect midRect{ { 1 * thirdWidth + ((thirdWidth - rectWidth) / 2.f), rectY }, { rectWidth, rectWidth } };
    CGRect rightRect{ { 2 * thirdWidth + ((thirdWidth - rectWidth) / 2.f), rectY }, { rectWidth, rectWidth } };

    CGContextRef context = UIGraphicsGetCurrentContext();

    CGContextSetFillColorWithColor(context, [UIColor yellowColor].CGColor);
    CGContextFillRect(context, { { bounds.size.width / 2.f, 0.f }, { bounds.size.width / 2.f, bounds.size.height } });

    CGContextSetLineWidth(context, 4.f);

    CGContextSaveGState(context); // Save before left rect rotation.

    CGContextTranslateCTM(context, CGRectGetMidX(leftRect), CGRectGetMidY(leftRect));
    CGContextRotateCTM(context, _contextRotationDegrees * M_PI / 180.);
    CGContextTranslateCTM(context, -CGRectGetMidX(leftRect), -CGRectGetMidY(leftRect));

    CGContextSetStrokeColorWithColor(context, [UIColor redColor].CGColor);

    CGContextStrokeRect(context, leftRect);

    CGContextRestoreGState(context);

    CGContextSetShadowWithColor(context,
                                _shadowOffset,
                                _shadowBlur,
                                [UIColor colorWithRed:0.f green:0.f blue:0.f alpha:_shadowOpacity].CGColor);

    CGContextSaveGState(context); // Save before mid rect rotation.

    CGContextTranslateCTM(context, CGRectGetMidX(midRect), CGRectGetMidY(midRect));
    CGContextRotateCTM(context, _contextRotationDegrees * M_PI / 180.);
    CGContextTranslateCTM(context, -CGRectGetMidX(midRect), -CGRectGetMidY(midRect));

    CGContextSetStrokeColorWithColor(context, [UIColor greenColor].CGColor);
    CGContextStrokeEllipseInRect(context, midRect);

    CGContextRestoreGState(context);

    CGContextSaveGState(context); // Save before right rect rotation.

    CGContextTranslateCTM(context, CGRectGetMidX(rightRect), CGRectGetMidY(rightRect));
    CGContextRotateCTM(context, _contextRotationDegrees * M_PI / 180.);
    CGContextTranslateCTM(context, -CGRectGetMidX(rightRect), -CGRectGetMidY(rightRect));

    CGContextSetStrokeColorWithColor(context, [UIColor blueColor].CGColor);
    CGContextStrokeRect(context, rightRect);

    CGContextRestoreGState(context);
}

- (void)setShadowOffset:(CGSize)offset {
    _shadowOffset = offset;
    [self setNeedsDisplay];
}

- (void)setShadowBlur:(CGFloat)blur {
    _shadowBlur = blur;
    [self setNeedsDisplay];
}

- (void)setShadowOpacity:(CGFloat)opacity {
    _shadowOpacity = opacity;
    [self setNeedsDisplay];
}

- (void)setContextRotationDegrees:(CGFloat)degrees {
    _contextRotationDegrees = degrees;
    [self setNeedsDisplay];
}

- (void)layoutSubviews {
    [self setNeedsDisplay];
};

@end

@interface CGContextShadowViewController () {
    UISlider* _shadowDistanceSlider;
    UISlider* _shadowBlurSlider;
    UISlider* _shadowAlphaSlider;
    UISlider* _contextRotationSlider;

    CGFloat _sliderY;
}

@property (strong, nonatomic, nullable) _ShadowView* customView;

@end

@implementation CGContextShadowViewController

- (UISlider*)addLabelledSliderWithTitle:(NSString*)title {
    UILabel* label = [[UILabel alloc] initWithFrame:{ { 0, _sliderY }, CGSizeZero }];
    label.text = title;
    [label sizeToFit];

    UISlider* slider = [[UISlider alloc] initWithFrame:{ { label.bounds.size.width + 10, _sliderY }, { 250.f, 40.f } }];
    _sliderY += 40.f;

    [self.view addSubview:label];
    [self.view addSubview:slider];

    return slider;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor whiteColor];

    _shadowDistanceSlider = [self addLabelledSliderWithTitle:@"Distance"];
    _shadowDistanceSlider.minimumValue = 0.f;
    _shadowDistanceSlider.maximumValue = 100.f;
    [_shadowDistanceSlider addTarget:self action:@selector(_distanceChanged:) forControlEvents:UIControlEventValueChanged];

    _shadowBlurSlider = [self addLabelledSliderWithTitle:@"Blur"];
    _shadowBlurSlider.minimumValue = 0.f;
    _shadowBlurSlider.maximumValue = 100.f;
    [_shadowBlurSlider addTarget:self action:@selector(_blurChanged:) forControlEvents:UIControlEventValueChanged];

    _shadowAlphaSlider = [self addLabelledSliderWithTitle:@"Alpha"];
    _shadowAlphaSlider.minimumValue = 0.f;
    _shadowAlphaSlider.maximumValue = 1.f;
    [_shadowAlphaSlider addTarget:self action:@selector(_alphaChanged:) forControlEvents:UIControlEventValueChanged];

    _contextRotationSlider = [self addLabelledSliderWithTitle:@"Rotation (deg)"];
    _contextRotationSlider.minimumValue = 0.f;
    _contextRotationSlider.maximumValue = 359.f;
    [_contextRotationSlider addTarget:self action:@selector(_rotationChanged:) forControlEvents:UIControlEventValueChanged];

    self.customView =
        [[_ShadowView alloc] initWithFrame:CGRectMake(0, _sliderY, self.view.bounds.size.width, self.view.bounds.size.height - _sliderY)];
    self.customView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;

    // Set defaults!
    _shadowDistanceSlider.value = 2.0f;
    _shadowBlurSlider.value = 2.0f;
    _shadowAlphaSlider.value = 0.5f;
    _contextRotationSlider.value = 0.f;

    [self.view addSubview:self.customView];
}

- (void)_distanceChanged:(id)sender;
{
    CGFloat value = [(UISlider*)sender value];
    self.customView.shadowOffset = { value, value };
}

- (void)_blurChanged:(id)sender;
{
    CGFloat value = [(UISlider*)sender value];
    self.customView.shadowBlur = value;
}

- (void)_alphaChanged:(id)sender;
{
    CGFloat value = [(UISlider*)sender value];
    self.customView.shadowOpacity = value;
}

- (void)_rotationChanged:(id)sender;
{
    CGFloat value = [(UISlider*)sender value];
    self.customView.contextRotationDegrees = value;
}
@end
