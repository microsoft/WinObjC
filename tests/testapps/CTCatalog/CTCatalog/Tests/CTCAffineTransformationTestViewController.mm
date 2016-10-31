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
//*****************************************************************************

#import "CTCAffineTransformationTestViewController.h"

static const NSString* text = @"This frame is manipulated by the above sliders.  The leftmost slider changes rotation, which should be "
                              @"about the origin in the bottom-left of this frame with left being clockwise rotation and right being "
                              @"counterclockwise.  The middle sliders change the X and Y scale respectively.  The rightmost sliders "
                              @"change the position of the X, Y origins of the drawn frame respectively.";

@interface CTAffineTransformationTestView : UIView {
}

@property (nonatomic) CGFloat rotationCTM;
@property (nonatomic) CGPoint translationCTM;
@property (nonatomic) CGPoint scaleCTM;

@end

@implementation CTAffineTransformationTestView {
}

- (void)drawRect:(CGRect)rect {
    UIColor* color = [UIColor blackColor];

    CGContextRef context = UIGraphicsGetCurrentContext();

    // Aligns origin for our frame
    CGContextTranslateCTM(context, 0.0f, self.bounds.size.height);

    // Flips y-axis for our frame
    CGContextScaleCTM(context, 1.0f, -1.0f);

    // Apply user given transformations
    CGContextRotateCTM(context, _rotationCTM);
    CGContextScaleCTM(context, _scaleCTM.x, _scaleCTM.y);
    CGContextTranslateCTM(context, _translationCTM.x, _translationCTM.y);

    // Creates path with current rectangle
    CGMutablePathRef path = CGPathCreateMutable();
    CGPathAddRect(path, NULL, self.bounds);

    // Create style setting to match given alignment
    CTParagraphStyleSetting setting;

    setting.spec = kCTParagraphStyleSpecifierAlignment;
    setting.valueSize = sizeof(CTTextAlignment);
    CTTextAlignment alignment = kCTLeftTextAlignment;
    setting.value = &alignment;
    CTParagraphStyleRef paragraphStyle = CTParagraphStyleCreate(&setting, 1);
    CFAutorelease(paragraphStyle);

    UIFont* font = [UIFont systemFontOfSize:20];
    CTFontRef myCFFont = CTFontCreateWithName((__bridge CFStringRef)[font fontName], [font pointSize], NULL);
    CFAutorelease(myCFFont);
    // Make dictionary for attributed string with font, color, and alignment
    NSDictionary* attributesDict = [NSDictionary dictionaryWithObjectsAndKeys:(__bridge id)myCFFont,
                                                                              (id)kCTFontAttributeName,
                                                                              color.CGColor,
                                                                              (id)kCTForegroundColorAttributeName,
                                                                              (__bridge id)paragraphStyle,
                                                                              (id)kCTParagraphStyleAttributeName,
                                                                              nil];

    CFAttributedStringRef attrString =
        CFAttributedStringCreate(kCFAllocatorDefault, (__bridge CFStringRef)text, (__bridge CFDictionaryRef)attributesDict);
    CFAutorelease(attrString);

    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(attrString);
    CFAutorelease(framesetter);

    // Creates frame for framesetter with current attributed string
    CTFrameRef frame = CTFramesetterCreateFrame(framesetter, CFRangeMake(0, 0), path, NULL);
    CFAutorelease(frame);

    // Draws the text in the frame
    CTFrameDraw(frame, context);

    // Creates outline
    CGContextSetLineWidth(context, 2.0);
    CGContextSetStrokeColorWithColor(context, color.CGColor);
    CGContextMoveToPoint(context, 0, 0);
    CGContextAddRect(context, rect);
    CGContextStrokePath(context);

    CGPathRelease(path);
}

@end

@implementation CTCAffineTransformationTestViewController {
    CTAffineTransformationTestView* _textView;
    UISlider* _rotationSlider;
    UISlider* _scaleXSlider;
    UISlider* _scaleYSlider;
    UISlider* _translateXSlider;
    UISlider* _translateYSlider;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    CGFloat width = CGRectGetWidth(self.view.bounds);

    _rotationSlider = [[UISlider alloc] initWithFrame:CGRectMake(0, 10, width / 4, 50)];
    _rotationSlider.minimumValue = -2.0f * M_PI;
    _rotationSlider.maximumValue = 2.0f * M_PI;
    _rotationSlider.value = 0.0f;
    _rotationSlider.continuous = YES;
    [_rotationSlider addTarget:self action:@selector(drawTests) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:_rotationSlider];

    _scaleXSlider = [[UISlider alloc] initWithFrame:CGRectMake(width / 3, 10, width / 4, 50)];
    _scaleXSlider.minimumValue = -2.0f;
    _scaleXSlider.maximumValue = 2.0f;
    _scaleXSlider.value = 1.0f;
    _scaleXSlider.continuous = YES;
    [_scaleXSlider addTarget:self action:@selector(drawTests) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:_scaleXSlider];

    _scaleYSlider = [[UISlider alloc] initWithFrame:CGRectMake(width / 3, 70, width / 4, 50)];
    _scaleYSlider.minimumValue = -2.0f;
    _scaleYSlider.maximumValue = 2.0f;
    _scaleYSlider.value = 1.0f;
    _scaleYSlider.continuous = YES;
    [_scaleYSlider addTarget:self action:@selector(drawTests) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:_scaleYSlider];

    _translateXSlider = [[UISlider alloc] initWithFrame:CGRectMake(2.0f * width / 3, 10, width / 4, 50)];
    _translateXSlider.minimumValue = -200;
    _translateXSlider.maximumValue = 200;
    _translateXSlider.value = 0.0f;
    _translateXSlider.continuous = YES;
    [_translateXSlider addTarget:self action:@selector(drawTests) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:_translateXSlider];

    _translateYSlider = [[UISlider alloc] initWithFrame:CGRectMake(2.0f * width / 3, 70, width / 4, 50)];
    _translateYSlider.minimumValue = -200;
    _translateYSlider.maximumValue = 200;
    _translateYSlider.value = 0.0f;
    _translateYSlider.continuous = YES;
    [_translateYSlider addTarget:self action:@selector(drawTests) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:_translateYSlider];

    // Create frame of text
    _textView = [[CTAffineTransformationTestView alloc] initWithFrame:CGRectMake(width / 4, 150, width / 2, 200)];
    _textView.backgroundColor = [UIColor whiteColor];
    _textView.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    // Sets view to call updateTableViews when done drawing
    _textView.rotationCTM = 0.0f;
    _textView.scaleCTM = { 1.0f, 1.0f };
    _textView.translationCTM = { 0.0f, 0.0f };
    [self.view addSubview:_textView];

    // Draws the frameview
    [self drawTests];
}

- (void)viewDidLayoutSubviews {
    CGFloat width = CGRectGetWidth(self.view.bounds);
    _textView.frame = CGRectMake(width / 4, 150, width / 2, 200);
    [_textView setNeedsDisplay];

    _rotationSlider.frame = CGRectMake(0, 10, width / 4, 50);
    [_rotationSlider setNeedsDisplay];

    _scaleXSlider.frame = CGRectMake(width / 3, 10, width / 4, 50);
    [_scaleXSlider setNeedsDisplay];

    _scaleYSlider.frame = CGRectMake(width / 3, 70, width / 4, 50);
    [_scaleYSlider setNeedsDisplay];

    _translateXSlider.frame = CGRectMake(2.0f * width / 3, 10, width / 4, 50);
    [_translateXSlider setNeedsDisplay];

    _translateYSlider.frame = CGRectMake(2.0f * width / 3, 70, width / 4, 50);
    [_translateYSlider setNeedsDisplay];
}

- (void)drawTests {
    // Update the text in the frame
    // Allows input of \n and \t to insert newlines and tabs respectively
    _textView.rotationCTM = _rotationSlider.value;
    _textView.scaleCTM = { _scaleXSlider.value, _scaleYSlider.value };
    _textView.translationCTM = { _translateXSlider.value, _translateYSlider.value };
    [_textView setNeedsDisplay];
}
@end