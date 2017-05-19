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

#import "UIProgressViewController.h"

@implementation UIProgressViewController {
    NSNumberFormatter* decimalFormat;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"Xaml ProgressView";

    self.view.backgroundColor = [UIColor whiteColor];

    [self _setup];
    [self updateFillTextFields];
    [self updateTrackTextFields];
}

- (void)_setup {
    // Formatter used by input fields
    decimalFormat = [[NSNumberFormatter alloc] init];
    decimalFormat.positiveFormat = @"0.##";

    // Get screen width for placement
    int screenWidth = [[UIScreen mainScreen] bounds].size.width;

    // Setup ProgressView
    _progressView = [[UIProgressView alloc] initWithFrame:CGRectMake((screenWidth / 2) - 150, 70, 300, 10)];
    [self.view addSubview:_progressView];

    // Setup observed progress button
    _startButton = [UIButton buttonWithType:UIButtonTypeSystem];
    _startButton.frame = CGRectMake((screenWidth / 2) - 150, 110, 300, 20);
    [_startButton setTitle:@"Set With Observed Progress" forState:UIControlStateNormal];
    [_startButton addTarget:self action:@selector(startButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_startButton];

    // Setup progress value input field
    _progressValue = [[UITextField alloc] initWithFrame:CGRectMake((screenWidth / 2) - 25, 140, 50, 30)];
    [_progressValue setBorderStyle:UITextBorderStyleLine];
    [_progressValue setText:@"0.0"];
    [self.view addSubview:_progressValue];

    // Setup button for setting progress
    _setProgressButton = [UIButton buttonWithType:UIButtonTypeSystem];
    _setProgressButton.frame = CGRectMake((screenWidth / 2) - 50, 170, 100, 20);
    [_setProgressButton setTitle:@"Set Progress" forState:UIControlStateNormal];
    [_setProgressButton addTarget:self action:@selector(setProgressButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_setProgressButton];

    // Setup fill image/tint toggle button
    _fillSelectButton = [UIButton buttonWithType:UIButtonTypeSystem];
    _fillSelectButton.frame = CGRectMake((screenWidth / 2) - 50, 200, 100, 20);
    [_fillSelectButton setTitle:@"Image Fill" forState:UIControlStateNormal];
    [_fillSelectButton addTarget:self action:@selector(fillSelectButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_fillSelectButton];

    // Setup track image/tint toggle button
    _trackSelectButton = [UIButton buttonWithType:UIButtonTypeSystem];
    _trackSelectButton.frame = CGRectMake((screenWidth / 2) - 50, 230, 100, 20);
    [_trackSelectButton setTitle:@"Image Track" forState:UIControlStateNormal];
    [_trackSelectButton addTarget:self action:@selector(trackSelectButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_trackSelectButton];

    // Setup style toggle button
    _styleSelectButton = [UIButton buttonWithType:UIButtonTypeSystem];
    _styleSelectButton.frame = CGRectMake((screenWidth / 2) - 50, 260, 100, 20);
    [_styleSelectButton setTitle:@"Bar Style" forState:UIControlStateNormal];
    [_styleSelectButton addTarget:self action:@selector(styleSelectButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_styleSelectButton];

    // Setup fill tint input fields
    _redFillComponent = [[UITextField alloc] initWithFrame:CGRectMake((screenWidth / 2) - 55, 300, 50, 30)];
    _greenFillComponent = [[UITextField alloc] initWithFrame:CGRectMake((screenWidth / 2) - 55, 335, 50, 30)];
    _blueFillComponent = [[UITextField alloc] initWithFrame:CGRectMake((screenWidth / 2) - 55, 370, 50, 30)];
    _alphaFillComponent = [[UITextField alloc] initWithFrame:CGRectMake((screenWidth / 2) - 55, 405, 50, 30)];
    _redFillComponent.backgroundColor = [UIColor colorWithRed:1 green:0 blue:0 alpha:.25];
    _greenFillComponent.backgroundColor = [UIColor colorWithRed:0 green:1 blue:0 alpha:.25];
    _blueFillComponent.backgroundColor = [UIColor colorWithRed:0 green:0 blue:1 alpha:.25];
    _alphaFillComponent.backgroundColor = [UIColor colorWithWhite:.5 alpha:.25];
    [_redFillComponent setBorderStyle:UITextBorderStyleLine];
    [_greenFillComponent setBorderStyle:UITextBorderStyleLine];
    [_blueFillComponent setBorderStyle:UITextBorderStyleLine];
    [_alphaFillComponent setBorderStyle:UITextBorderStyleLine];
    [self.view addSubview:_redFillComponent];
    [self.view addSubview:_greenFillComponent];
    [self.view addSubview:_blueFillComponent];
    [self.view addSubview:_alphaFillComponent];

    // Setup fill tint button
    _setFillTintButton = [UIButton buttonWithType:UIButtonTypeSystem];
    _setFillTintButton.frame = CGRectMake((screenWidth / 2) - 55, 435, 50, 20);
    [_setFillTintButton setTitle:@"Set Fill" forState:UIControlStateNormal];
    [_setFillTintButton addTarget:self action:@selector(setFillTintButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_setFillTintButton];

    // Setup track tint input fields
    _redTrackComponent = [[UITextField alloc] initWithFrame:CGRectMake((screenWidth / 2) + 5, 300, 50, 30)];
    _greenTrackComponent = [[UITextField alloc] initWithFrame:CGRectMake((screenWidth / 2) + 5, 335, 50, 30)];
    _blueTrackComponent = [[UITextField alloc] initWithFrame:CGRectMake((screenWidth / 2) + 5, 370, 50, 30)];
    _alphaTrackComponent = [[UITextField alloc] initWithFrame:CGRectMake((screenWidth / 2) + 5, 405, 50, 30)];
    _redTrackComponent.backgroundColor = [UIColor colorWithRed:1 green:0 blue:0 alpha:.25];
    _greenTrackComponent.backgroundColor = [UIColor colorWithRed:0 green:1 blue:0 alpha:.25];
    _blueTrackComponent.backgroundColor = [UIColor colorWithRed:0 green:0 blue:1 alpha:.25];
    _alphaTrackComponent.backgroundColor = [UIColor colorWithWhite:.5 alpha:.25];
    [_redTrackComponent setBorderStyle:UITextBorderStyleLine];
    [_greenTrackComponent setBorderStyle:UITextBorderStyleLine];
    [_blueTrackComponent setBorderStyle:UITextBorderStyleLine];
    [_alphaTrackComponent setBorderStyle:UITextBorderStyleLine];
    [self.view addSubview:_redTrackComponent];
    [self.view addSubview:_greenTrackComponent];
    [self.view addSubview:_blueTrackComponent];
    [self.view addSubview:_alphaTrackComponent];

    // Setup track tint button
    _setTrackTintButton = [UIButton buttonWithType:UIButtonTypeSystem];
    _setTrackTintButton.frame = CGRectMake((screenWidth / 2), 435, 75, 20);
    [_setTrackTintButton setTitle:@"Set Track" forState:UIControlStateNormal];
    [_setTrackTintButton addTarget:self action:@selector(setTrackTintButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_setTrackTintButton];
}

// Updates progress with observed progress
- (void)startButtonPressed:(UIButton*)sender {
    if (_progressView.observedProgress) {
        [_progressView setObservedProgress:nil];
        [sender setTitle:@"Set With Observed Progress" forState:UIControlStateNormal];
    } else {
        _progress = [NSProgress progressWithTotalUnitCount:4];
        [_progressView setObservedProgress:_progress];
        [_progress setCompletedUnitCount:3];
        [sender setTitle:@"Remove Observed Progress" forState:UIControlStateNormal];
    }
}

// Toggles the progress fill between tint and image
- (void)fillSelectButtonPressed:(UIButton*)sender {
    if (!_progressView.progressImage) {
        [_progressView setProgressImage:[UIImage imageNamed:@"progress-fill-sample.png"]];
        [sender setTitle:@"Tint Fill" forState:UIControlStateNormal];
    } else {
        [_progressView setProgressImage:nil];
        [sender setTitle:@"Image Fill" forState:UIControlStateNormal];
    }

    [self updateFillTextFields];
}

// Toggles the track between tint and image
- (void)trackSelectButtonPressed:(UIButton*)sender {
    if (!_progressView.trackImage) {
        [_progressView setTrackImage:[UIImage imageNamed:@"progress-track-sample.png"]];
        [sender setTitle:@"Tint Track" forState:UIControlStateNormal];
    } else {
        [_progressView setTrackImage:nil];
        [sender setTitle:@"Image Track" forState:UIControlStateNormal];
    }

    [self updateTrackTextFields];
}

// Toggles between the two UIProgressViewStyles
- (void)styleSelectButtonPressed:(UIButton*)sender {
    if (_progressView.progressViewStyle == UIProgressViewStyleDefault) {
        [_progressView setProgressViewStyle:UIProgressViewStyleBar];
        [sender setTitle:@"Default Style" forState:UIControlStateNormal];
    } else {
        [_progressView setProgressViewStyle:UIProgressViewStyleDefault];
        [sender setTitle:@"Bar Style" forState:UIControlStateNormal];
    }

    [self updateFillTextFields];
    [self updateFillTextFields];
}

// Sets the progress value from the input field
- (void)setProgressButtonPressed:(UIButton*)sender {
    [_progressView setProgress:[_progressValue.text floatValue]];
}

// Sets the fill tint from the input fields
- (void)setFillTintButtonPressed:(UIButton*)sender {
    [_progressView setProgressTintColor:[UIColor colorWithRed:[_redFillComponent.text floatValue]
                                                        green:[_greenFillComponent.text floatValue]
                                                         blue:[_blueFillComponent.text floatValue]
                                                        alpha:[_alphaFillComponent.text floatValue]]];

    [_fillSelectButton setTitle:@"Image Fill" forState:UIControlStateNormal];
}

// Sets the track tint from the input fields
- (void)setTrackTintButtonPressed:(UIButton*)sender {
    [_progressView setTrackTintColor:[UIColor colorWithRed:[_redTrackComponent.text floatValue]
                                                     green:[_greenTrackComponent.text floatValue]
                                                      blue:[_blueTrackComponent.text floatValue]
                                                     alpha:[_alphaTrackComponent.text floatValue]]];

    [_trackSelectButton setTitle:@"Image Track" forState:UIControlStateNormal];
}

// Updates the fill tint text fields from the current ProgressView fill tint
- (void)updateFillTextFields {
    NSArray* components = [self getRGBAColorComponents:_progressView.progressTintColor];
    [_redFillComponent setText:[decimalFormat stringFromNumber:components[0]]];
    [_greenFillComponent setText:[decimalFormat stringFromNumber:components[1]]];
    [_blueFillComponent setText:[decimalFormat stringFromNumber:components[2]]];
    [_alphaFillComponent setText:[decimalFormat stringFromNumber:components[3]]];
}

// Updates the track tint text fields from the current ProgressView track tint
- (void)updateTrackTextFields {
    NSArray* components = [self getRGBAColorComponents:_progressView.trackTintColor];
    [_redTrackComponent setText:[decimalFormat stringFromNumber:components[0]]];
    [_greenTrackComponent setText:[decimalFormat stringFromNumber:components[1]]];
    [_blueTrackComponent setText:[decimalFormat stringFromNumber:components[2]]];
    [_alphaTrackComponent setText:[decimalFormat stringFromNumber:components[3]]];
}

// Extracts the RGBA components from the provided UIColor
- (NSArray*)getRGBAColorComponents:(UIColor*)color {
    CGColorRef colorRef = color.CGColor;
    CGColorSpaceRef colorSpace = CGColorGetColorSpace(colorRef);
    CGColorSpaceModel colorSpaceModel = CGColorSpaceGetModel(colorSpace);
    const CGFloat* components = CGColorGetComponents(colorRef);
    float red, green, blue, alpha;

    switch (colorSpaceModel) {
        case kCGColorSpaceModelMonochrome:
            red = components[0];
            green = components[0];
            blue = components[0];
            alpha = components[1];
            break;
        case kCGColorSpaceModelRGB:
            red = components[0];
            green = components[1];
            blue = components[2];
            alpha = components[3];
            break;

        default:
            red = 0.0;
            green = 0.0;
            blue = 0.0;
            alpha = 0.0;
            break;
    }

    return [NSArray arrayWithObjects:[NSNumber numberWithFloat:red],
                                     [NSNumber numberWithFloat:green],
                                     [NSNumber numberWithFloat:blue],
                                     [NSNumber numberWithFloat:alpha],
                                     nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
