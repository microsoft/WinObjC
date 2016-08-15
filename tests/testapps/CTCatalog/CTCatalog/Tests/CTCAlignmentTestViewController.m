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

#import "CTCAlignmentTestViewController.h"

@interface CTAlignmentTestView : UIView {
}

@property (nonatomic, copy) NSString* text;
@property (nonatomic) CTTextAlignment alignment;
@property (nonatomic, copy) UIFont* font;

@end

@implementation CTAlignmentTestView {
}

- (void)drawRect:(CGRect)rect {
    UIColor* color = [UIColor blueColor];

    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextTranslateCTM(context, 0.0f, self.bounds.size.height);
    CGContextScaleCTM(context, 1.0f, -1.0f);

    CGMutablePathRef path = CGPathCreateMutable();
    CGPathAddRect(path, NULL, self.bounds);

    CTParagraphStyleSetting setting;
    setting.spec = kCTParagraphStyleSpecifierAlignment;
    setting.valueSize = sizeof(CTTextAlignment);
    setting.value = &_alignment;
    CTParagraphStyleRef paragraphStyle = CTParagraphStyleCreate(&setting, 1);

    CTFontRef myCFFont = CTFontCreateWithName((__bridge CFStringRef)[_font fontName], [_font pointSize], NULL);
    NSDictionary* attributesDict = [NSDictionary dictionaryWithObjectsAndKeys:(__bridge id)myCFFont,
                                                                              (id)kCTFontAttributeName,
                                                                              color.CGColor,
                                                                              (id)kCTForegroundColorAttributeName,
                                                                              (__bridge id)paragraphStyle,
                                                                              (id)kCTParagraphStyleAttributeName,
                                                                              nil];

    CFAttributedStringRef attrString =
        CFAttributedStringCreate(kCFAllocatorDefault, (__bridge CFStringRef)_text, (__bridge CFDictionaryRef)attributesDict);

    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(attrString);
    CFRelease(attrString);

    CTFrameRef frame = CTFramesetterCreateFrame(framesetter, CFRangeMake(0, 0), path, NULL);
    CTFrameDraw(frame, context);

    CGContextSetLineWidth(context, 2.0);

    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();

    CGContextSetStrokeColorWithColor(context, color.CGColor);

    CGContextMoveToPoint(context, 0, 0);
    CGContextAddRect(context, rect);

    CGContextStrokePath(context);
    CGColorSpaceRelease(colorspace);
}
@end

@interface CTCAlignmentTestViewController ()

@end

@implementation CTCAlignmentTestViewController {
    CTAlignmentTestView* _leftView;
    CTAlignmentTestView* _centerView;
    CTAlignmentTestView* _rightView;
    UITextField* _textField;
    UISlider* _fontSizeSlider;
    UIPickerView* _fontPicker;
    UIFont* _font;
    NSArray* _fonts;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    _fontSizeSlider = [[UISlider alloc] initWithFrame:CGRectMake(440, 240, 100, 100)];
    _fontSizeSlider.minimumValue = 8.0;
    _fontSizeSlider.maximumValue = 140.0;
    _fontSizeSlider.value = 20.0;
    _fontSizeSlider.continuous = YES;
    [_fontSizeSlider addTarget:self action:@selector(sizeChanged) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:_fontSizeSlider];

    _textField = [[UITextField alloc] initWithFrame:CGRectMake(440, 360, 300, 30)];
    _textField.text = @"the quick brown fox jumps over the lazy dog. THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    _textField.delegate = self;
    [self.view addSubview:_textField];

    NSMutableArray* fonts = [NSMutableArray new];
    for (NSString* familyName in [UIFont familyNames]) {
        for (NSString* fontName in [UIFont fontNamesForFamilyName:familyName]) {
            [fonts addObject:fontName];
        }
    }
    _fonts = [fonts sortedArrayUsingSelector:@selector(localizedCaseInsensitiveCompare:)];
    _font = [UIFont systemFontOfSize:_fontSizeSlider.value];
    [self drawTests];
    _fontPicker = [[UIPickerView alloc] initWithFrame:CGRectMake(500, 20, 200, 200)];
    _fontPicker.delegate = self;
    _fontPicker.dataSource = self;
    [self.view addSubview:_fontPicker];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
}

- (void)drawTests {
    _leftView = [[CTAlignmentTestView alloc] initWithFrame:CGRectMake(20, 20, 400, 400)];
    _leftView.backgroundColor = [UIColor whiteColor];
    _leftView.alignment = kCTLeftTextAlignment;
    _leftView.font = _font;
    _leftView.text =
        [[_textField.text stringByReplacingOccurrencesOfString:@"\\n" withString:@"\n"] stringByReplacingOccurrencesOfString:@"\\t"
                                                                                                                  withString:@"\t"];
    [self.view addSubview:_leftView];

    _centerView = [[CTAlignmentTestView alloc] initWithFrame:CGRectMake(20, 220, 400, 200)];
    _centerView.backgroundColor = [UIColor whiteColor];
    _centerView.alignment = kCTCenterTextAlignment;
    _centerView.font = _font;
    _centerView.text =
        [[_textField.text stringByReplacingOccurrencesOfString:@"\\n" withString:@"\n"] stringByReplacingOccurrencesOfString:@"\\t"
                                                                                                                  withString:@"\t"];
    [self.view addSubview:_centerView];

    _rightView = [[CTAlignmentTestView alloc] initWithFrame:CGRectMake(20, 420, 400, 200)];
    _rightView.backgroundColor = [UIColor whiteColor];
    _rightView.alignment = kCTRightTextAlignment;
    _rightView.font = _font;
    _rightView.text =
        [[_textField.text stringByReplacingOccurrencesOfString:@"\\n" withString:@"\n"] stringByReplacingOccurrencesOfString:@"\\t"
                                                                                                                  withString:@"\t"];
    [self.view addSubview:_rightView];
}

- (void)refreshViews {
    [_leftView removeFromSuperview];
    [_centerView removeFromSuperview];
    [_rightView removeFromSuperview];
    [self drawTests];
}

// Font Picker Methods

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView*)pickerView {
    // Only the one row of fonts
    return 1;
}

- (NSInteger)pickerView:(UIPickerView*)pickerView numberOfRowsInComponent:(NSInteger)component {
    return _fonts.count;
}

- (NSString*)pickerView:(UIPickerView*)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    return _fonts[row];
}
- (void)pickerView:(UIPickerView*)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    _font = [UIFont fontWithName:_fonts[row] size:_fontSizeSlider.value];
    [self refreshViews];
}

// Font Size Slider Methods

- (void)sizeChanged {
    _font = [UIFont fontWithName:_font.fontName size:_fontSizeSlider.value];
    [self refreshViews];
}

// Text Field Methods

- (void)textFieldDidEndEditing:(UITextField*)textField {
    [self drawTests];
}

@end
