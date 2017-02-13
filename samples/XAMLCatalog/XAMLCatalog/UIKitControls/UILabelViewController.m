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

#import <UIkit/UISlider.h>
#import "UILabelViewController.h"
#import <MobileCoreServices/MobileCoreServices.h>

@implementation UILabelViewController {
    int _eventId;
}

// setting up the controls to update the UILabel config
- (void)_setup {
    self.text = [[UITextField alloc] initWithFrame:CGRectMake(105.0f, 20.0f, 216.0f, 30.0f)];
    [self.view addSubview:self.text];

    self.fontSize = [[UISlider alloc] initWithFrame:CGRectMake(101.0f, 54.0f, 187.0f, 31.0f)];
    self.fontSize.minimumValue = 4.01f;
    self.fontSize.maximumValue = 80;
    [self.view addSubview:self.fontSize];

    self.x = [[UITextField alloc] initWithFrame:CGRectMake(74.0f, 92.0f, 45.0f, 30.0f)];
    [self.view addSubview:self.x];

    self.y = [[UITextField alloc] initWithFrame:CGRectMake(141.0f, 92.0f, 45.0f, 30.0f)];
    [self.view addSubview:self.y];

    self.w = [[UITextField alloc] initWithFrame:CGRectMake(211.0f, 92.0f, 45.0f, 30.0f)];
    [self.view addSubview:self.w];

    self.h = [[UITextField alloc] initWithFrame:CGRectMake(293.0f, 92.0f, 45.0f, 30.0f)];
    [self.view addSubview:self.h];

    self.numberOfLines = [[UITextField alloc] initWithFrame:CGRectMake(104.0f, 132.0f, 32.0f, 30.0f)];
    [self.view addSubview:self.numberOfLines];

    self.lineBreakMode = [[UITextField alloc] initWithFrame:CGRectMake(207.0f, 132.0f, 32.0f, 30.0f)];
    [self.view addSubview:self.lineBreakMode];

    self.autoShrink = [[UISwitch alloc] initWithFrame:CGRectMake(310.0f, 131.0f, 51.0f, 31.0f)];
    [self.view addSubview:self.autoShrink];

    self.minimumFontSize = [[UITextField alloc] initWithFrame:CGRectMake(80.0f, 167.0f, 56.0f, 30.0f)];
    [self.view addSubview:self.minimumFontSize];

    self.minimumScaleFactor = [[UITextField alloc] initWithFrame:CGRectMake(239.0f, 167.0f, 41.0f, 30.0f)];
    [self.view addSubview:self.minimumScaleFactor];

    self.label = [[UILabel alloc] initWithFrame:CGRectMake(4.0f, 254.0f, 353.0f, 107.0f)];
    self.label.text = @"This is a test string used to test UILabel - and it should wrap and can be as long as three lines";
    self.label.backgroundColor = [UIColor redColor];
    [self.view addSubview:self.label];

    self.fontSizeLabel = [[UILabel alloc] initWithFrame:CGRectMake(297.0f, 57.0f, 53.0f, 25.0f)];
    [self.view addSubview:self.fontSizeLabel];

    self.start = [[UIButton alloc] initWithFrame:CGRectMake(4.0f, 426.0f, 46.0f, 30.0f)];
    [self.start setTitle:@"Start" forState:UIControlStateNormal];
    [self.start setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [self.view addSubview:self.start];

    self.log = [[UITextView alloc] initWithFrame:CGRectMake(6.0f, 488.0f, 355.0f, 128.0f)];
    [self.view addSubview:self.log];

    self.logResult = [[UIButton alloc] initWithFrame:CGRectMake(293.0f, 426.0f, 46.0f, 30.0f)];
    [self.logResult setTitle:@"Copy" forState:UIControlStateNormal];
    [self.logResult setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [self.view addSubview:self.logResult];
}

- (void)viewDidLoad {
    [super viewDidLoad];

    // creating control default value using label value
    [self _setup];

    self.view.frame = CGRectMake(0.0f, 0.0f, 800.0f, 600.0f);
    self.view.backgroundColor = [UIColor grayColor];

    self.text.text = self.label.text;
    self.fontSize.value = self.label.font.pointSize;
    self.x.text = [NSString stringWithFormat:@"%3.0f", self.label.frame.origin.x];
    self.y.text = [NSString stringWithFormat:@"%3.0f", self.label.frame.origin.y];
    self.w.text = [NSString stringWithFormat:@"%3.0f", self.label.frame.size.width];
    self.h.text = [NSString stringWithFormat:@"%3.0f", self.label.frame.size.height];
    self.numberOfLines.text = [NSString stringWithFormat:@"%d", (int)self.label.numberOfLines];
    self.lineBreakMode.text = [NSString stringWithFormat:@"%d", (int)self.label.lineBreakMode];
    self.autoShrink.on = self.label.adjustsFontSizeToFitWidth;
    self.minimumFontSize.text = [NSString stringWithFormat:@"%3.0f", self.label.minimumFontSize];
    self.minimumScaleFactor.text = [NSString stringWithFormat:@"%3.0f", self.label.minimumScaleFactor];

    self.text.delegate = self;
    [self.text addTarget:self action:@selector(textFieldEditDidEnd:) forControlEvents:UIControlEventEditingDidEnd];

    self.x.delegate = self;
    self.x.keyboardType = UIKeyboardTypeNumberPad;
    [self.x addTarget:self action:@selector(textFieldEditDidEnd:) forControlEvents:UIControlEventEditingDidEnd];

    self.y.delegate = self;
    self.y.keyboardType = UIKeyboardTypeNumberPad;
    [self.y addTarget:self action:@selector(textFieldEditDidEnd:) forControlEvents:UIControlEventEditingDidEnd];

    self.w.delegate = self;
    self.w.keyboardType = UIKeyboardTypeNumberPad;
    [self.w addTarget:self action:@selector(textFieldEditDidEnd:) forControlEvents:UIControlEventEditingDidEnd];

    self.h.delegate = self;
    self.h.keyboardType = UIKeyboardTypeNumberPad;
    [self.h addTarget:self action:@selector(textFieldEditDidEnd:) forControlEvents:UIControlEventEditingDidEnd];

    self.numberOfLines.delegate = self;
    self.numberOfLines.keyboardType = UIKeyboardTypeNumberPad;
    [self.numberOfLines addTarget:self action:@selector(textFieldEditDidEnd:) forControlEvents:UIControlEventEditingDidEnd];

    self.lineBreakMode.delegate = self;
    self.lineBreakMode.keyboardType = UIKeyboardTypeNumberPad;
    [self.lineBreakMode addTarget:self action:@selector(textFieldEditDidEnd:) forControlEvents:UIControlEventEditingDidEnd];

    self.minimumFontSize.delegate = self;
    self.minimumFontSize.keyboardType = UIKeyboardTypeDecimalPad;
    [self.minimumFontSize addTarget:self action:@selector(textFieldEditDidEnd:) forControlEvents:UIControlEventEditingDidEnd];

    self.minimumScaleFactor.delegate = self;
    self.minimumScaleFactor.keyboardType = UIKeyboardTypeDecimalPad;
    [self.minimumScaleFactor addTarget:self action:@selector(textFieldEditDidEnd:) forControlEvents:UIControlEventEditingDidEnd];

    [self.fontSize addTarget:self action:@selector(fontSizeChanged:) forControlEvents:UIControlEventValueChanged];
    self.fontSize.continuous = YES;

    [self.autoShrink addTarget:self action:@selector(autoShrinkChanged:) forControlEvents:UIControlEventValueChanged];

    [self.start addTarget:self action:@selector(startTests:) forControlEvents:UIControlEventTouchUpInside];
    [self.logResult addTarget:self action:@selector(copyTestResult:) forControlEvents:UIControlEventTouchUpInside];
}

- (void)copyTestResult:(UIButton*)sender {
    UIPasteboard* pasteBoard = [UIPasteboard generalPasteboard];
    NSString* logResult = self.log.text;
    [pasteBoard setValue:logResult forPasteboardType:(NSString*)kUTTypePlainText];
}

- (void)startTests:(UIButton*)sender {
    // reset the log
    _eventId = 0;

    __weak UILabelViewController* weakSelf = self;
    dispatch_queue_t g = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0);
    dispatch_async(g, ^{
        __strong UILabelViewController* strongSelf = weakSelf;

        if (strongSelf) {
            // enumerate the autoFit
            for (int autoFit = 0; autoFit <= 1; autoFit++) {
                dispatch_sync(dispatch_get_main_queue(), ^{
                    strongSelf.autoShrink.on = (BOOL)autoFit;
                    [strongSelf autoShrinkChanged:strongSelf.autoShrink];
                });

                if (autoFit == 1) {
                    // autFit is on, enumerate miniFontSize/ScaleFactor
                    for (int useMinScaleFactor = 0; useMinScaleFactor <= 1; useMinScaleFactor++) {
                        if (useMinScaleFactor) {
                            for (float minScaleFactor = 0.1; minScaleFactor < 1.0; minScaleFactor += 0.4) {
                                dispatch_sync(dispatch_get_main_queue(), ^{
                                    strongSelf.minimumScaleFactor.text = [NSString stringWithFormat:@"%5.1f", minScaleFactor];
                                    [strongSelf textFieldEditDidEnd:strongSelf.minimumScaleFactor];
                                });

                                [strongSelf enumerateNumberOfLinesLinBreakFontSize];
                            }
                        } else {
                            float minFontSizeStep = strongSelf.label.font.pointSize / 3.0f;
                            for (float minFontSize = 0.1; minFontSize < strongSelf.label.font.pointSize; minFontSize += minFontSizeStep) {
                                dispatch_sync(dispatch_get_main_queue(), ^{
                                    strongSelf.minimumFontSize.text = [NSString stringWithFormat:@"%5.2f", minFontSize];
                                    [strongSelf textFieldEditDidEnd:strongSelf.minimumFontSize];
                                });

                                [strongSelf enumerateNumberOfLinesLinBreakFontSize];
                            }
                        }
                    }
                } else {
                    [strongSelf enumerateNumberOfLinesLinBreakFontSize];
                }
            }
        }
    });
}

- (void)enumerateNumberOfLinesLinBreakFontSize {
    // enumerate different number of lines
    for (int numberOfLines = 0; numberOfLines <= 4; numberOfLines++) {
        dispatch_sync(dispatch_get_main_queue(), ^{
            self.numberOfLines.text = [NSString stringWithFormat:@"%d", numberOfLines];
            [self textFieldEditDidEnd:self.numberOfLines];
        });

        // enumerate different lineBreak
        for (int lineBreakMode = 0; lineBreakMode <= (int)NSLineBreakByTruncatingMiddle; lineBreakMode++) {
            dispatch_sync(dispatch_get_main_queue(), ^{
                self.lineBreakMode.text = [NSString stringWithFormat:@"%d", lineBreakMode];
                [self textFieldEditDidEnd:self.lineBreakMode];
            });

            // enumerate font size
            const float sizeIncreaseStep = 8.00f;

            __block float min;
            __block float max;
            dispatch_sync(dispatch_get_main_queue(), ^{
                min = self.fontSize.minimumValue;
                max = self.fontSize.maximumValue;
            });

            for (float size = min; size <= max; size += sizeIncreaseStep) {
                dispatch_sync(dispatch_get_main_queue(), ^{
                    self.fontSize.value = size;
                    [self fontSizeChanged:self.fontSize];
                    [self updateLog];
                });
            }
        }
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)textFieldShouldReturn:(UITextField*)textField {
    [textField resignFirstResponder];
    return YES;
}

- (void)autoShrinkChanged:(UISwitch*)autoShrinkSwtich {
    self.minimumFontSize.enabled = self.minimumFontSize.enabled = self.autoShrink.on;
    self.label.adjustsFontSizeToFitWidth = self.autoShrink.on;
}

- (void)fontSizeChanged:(UISlider*)slider {
    self.label.font = [self.label.font fontWithSize:slider.value];
    self.fontSizeLabel.text = [NSString stringWithFormat:@"%5.2f", slider.value];
}

- (void)textFieldEditDidEnd:(UITextField*)t {
    if (t == self.text) {
        self.label.text = t.text;
    } else if (t == self.x) {
        CGRect rect = self.label.frame;
        rect.origin.x = [self.x.text floatValue];
        self.label.frame = rect;
    } else if (t == self.y) {
        CGRect rect = self.label.frame;
        rect.origin.y = [self.y.text floatValue];
        self.label.frame = rect;
    } else if (t == self.w) {
        CGRect rect = self.label.frame;
        rect.size.width = [self.w.text floatValue];
        self.label.frame = rect;
    } else if (t == self.h) {
        CGRect rect = self.label.frame;
        rect.size.height = [self.h.text floatValue];
        self.label.frame = rect;
    } else if (t == self.numberOfLines) {
        self.label.numberOfLines = [self.numberOfLines.text intValue];
    } else if (t == self.lineBreakMode) {
        self.label.lineBreakMode = (NSLineBreakMode)[self.lineBreakMode.text intValue];
    } else if (t == self.minimumFontSize) {
        self.label.minimumFontSize = [self.minimumFontSize.text floatValue];
    } else if (t == self.minimumScaleFactor) {
        self.label.minimumScaleFactor = [self.minimumScaleFactor.text floatValue];
    }
}

- (void)updateLog {
    self.textRect = [self.label textRectForBounds:self.label.frame limitedToNumberOfLines:self.label.numberOfLines];
    self.sizeThatFits = [self.label sizeThatFits:self.label.frame.size];
    self.intrinsicContentSize = self.label.intrinsicContentSize;

    self.result = [NSString stringWithFormat:@"id=%04d, frame={%4.2f, %7.2f, %7.2f, %7.2f}, #OfLines=%d, fontSize=%5.2f, lineBreak=%d, "
                                             @"AutoShrink=%d, MinFontSize=%1.2f, MinScale=%1.2f, IntrinicContentSize={%7.2f, %7.2f}, "
                                             @"textRect={%7.2f, %7.2f, %7.2f, %7.2f}, sizeThatFits={%7.2f, %7.2f}",
                                             self->_eventId,
                                             self.label.frame.origin.x,
                                             self.label.frame.origin.y,
                                             self.label.frame.size.width,
                                             self.label.frame.size.height,
                                             (int)self.label.numberOfLines,
                                             self.label.font.pointSize,
                                             (int)self.label.lineBreakMode,
                                             self.autoShrink.on,
                                             self.label.minimumFontSize,
                                             self.label.minimumScaleFactor,
                                             self.intrinsicContentSize.width,
                                             self.intrinsicContentSize.height,
                                             self.textRect.origin.x,
                                             self.textRect.origin.y,
                                             self.textRect.size.width,
                                             self.textRect.size.height,
                                             self.sizeThatFits.width,
                                             self.sizeThatFits.height];

    NSLog(self.result);
    self->_eventId++;
}

@end