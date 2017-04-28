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

#import "UIActivityIndicatorViewController.h"

@implementation UIActivityIndicatorViewController {
    NSArray* _indicatorStylesText;
};

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"Xaml ActivityIndicator";

    [self _setup];
    [self updateColorSlidersFromIndicatorColor];
}

// Setup controls for testing the UIActivityIndicatorView
- (void)_setup {
    // Define style picker text
    _indicatorStylesText = [[NSArray alloc] initWithObjects:@"White Large Style", @"White Style", @"Gray Style", nil];

    // Get screen dimensions for placement
    int screenHeight = [[UIScreen mainScreen] bounds].size.height;
    int screenWidth = [[UIScreen mainScreen] bounds].size.width;

    // Setup indicator
    _indicator = [[UIActivityIndicatorView alloc] initWithFrame:CGRectMake((screenWidth / 2) - 25, 20, 50, 50)];
    //_indicator.activityIndicatorViewStyle = UIActivityIndicatorViewStyleGray;
    _indicator.backgroundColor = [UIColor lightGrayColor];
    [self.view addSubview:_indicator];

    // Setup animate button
    _animateIndicatorButton = [UIButton buttonWithType:UIButtonTypeSystem];
    _animateIndicatorButton.frame = CGRectMake((screenWidth / 2) - 150, 75, 300, 25);
    [_animateIndicatorButton setTitle:@"Start Animating" forState:UIControlStateNormal];
    [_animateIndicatorButton addTarget:self action:@selector(animateButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_animateIndicatorButton];

    // Setup switch label
    _hideIndicatorLabel = [[UILabel alloc] initWithFrame:CGRectMake((screenWidth / 2) - 150, 100, 600, 25)];
    _hideIndicatorLabel.text = @"Hide When Stopped:";
    [self.view addSubview:_hideIndicatorLabel];

    // Setup hide indicator switch
    _hideStoppedIndicatorSwitch = [[UISwitch alloc] initWithFrame:CGRectMake(_hideIndicatorLabel.frame.origin.x + 175, 105, 50, 25)];
    [_hideStoppedIndicatorSwitch addTarget:self action:@selector(hideIndicatorSwitchToggled:) forControlEvents:UIControlEventValueChanged];
    _hideStoppedIndicatorSwitch.on = YES;
    [self.view addSubview:_hideStoppedIndicatorSwitch];

    // Setup slider name labels
    _redLabel = [[UILabel alloc] initWithFrame:CGRectMake((screenWidth / 2) - 125, 125, 20, 20)];
    _greenLabel = [[UILabel alloc] initWithFrame:CGRectMake((screenWidth / 2) - 125, 175, 20, 20)];
    _blueLabel = [[UILabel alloc] initWithFrame:CGRectMake((screenWidth / 2) - 125, 225, 20, 20)];
    _alphaLabel = [[UILabel alloc] initWithFrame:CGRectMake((screenWidth / 2) - 125, 275, 20, 20)];

    _redLabel.text = @"R:";
    _greenLabel.text = @"G:";
    _blueLabel.text = @"B:";
    _alphaLabel.text = @"A:";

    [self.view addSubview:_redLabel];
    [self.view addSubview:_greenLabel];
    [self.view addSubview:_blueLabel];
    [self.view addSubview:_alphaLabel];

    // Setup slider value labels
    _redValueLabel = [[UILabel alloc] initWithFrame:CGRectMake((screenWidth / 2) + 120, 125, 50, 20)];
    _greenValueLabel = [[UILabel alloc] initWithFrame:CGRectMake((screenWidth / 2) + 120, 175, 50, 20)];
    _blueValueLabel = [[UILabel alloc] initWithFrame:CGRectMake((screenWidth / 2) + 120, 225, 50, 20)];
    _alphaValueLabel = [[UILabel alloc] initWithFrame:CGRectMake((screenWidth / 2) + 120, 275, 50, 20)];

    [self.view addSubview:_redValueLabel];
    [self.view addSubview:_greenValueLabel];
    [self.view addSubview:_blueValueLabel];
    [self.view addSubview:_alphaValueLabel];

    // Setup sliders
    _redSlider = [[UISlider alloc] initWithFrame:CGRectMake((screenWidth / 2) - 100, 125, 200, 50)];
    _greenSlider = [[UISlider alloc] initWithFrame:CGRectMake((screenWidth / 2) - 100, 175, 200, 50)];
    _blueSlider = [[UISlider alloc] initWithFrame:CGRectMake((screenWidth / 2) - 100, 225, 200, 50)];
    _alphaSlider = [[UISlider alloc] initWithFrame:CGRectMake((screenWidth / 2) - 100, 275, 200, 50)];

    _redSlider.minimumValue = 0.0;
    _redSlider.maximumValue = 1.0;
    _redSlider.minimumTrackTintColor = UIColor.redColor;
    _redSlider.maximumTrackTintColor = UIColor.whiteColor;

    _greenSlider.minimumValue = 0.0;
    _greenSlider.maximumValue = 1.0;
    _greenSlider.minimumTrackTintColor = UIColor.greenColor;
    _greenSlider.maximumTrackTintColor = UIColor.whiteColor;

    _blueSlider.minimumValue = 0.0;
    _blueSlider.maximumValue = 1.0;
    _blueSlider.minimumTrackTintColor = UIColor.blueColor;
    _blueSlider.maximumTrackTintColor = UIColor.whiteColor;

    _alphaSlider.minimumValue = 0.0;
    _alphaSlider.maximumValue = 1.0;
    _alphaSlider.minimumTrackTintColor = UIColor.lightGrayColor;
    _alphaSlider.maximumTrackTintColor = UIColor.whiteColor;

    [self.view addSubview:_redSlider];
    [self.view addSubview:_greenSlider];
    [self.view addSubview:_blueSlider];
    [self.view addSubview:_alphaSlider];

    [_redSlider addTarget:self action:@selector(colorComponentChanged) forControlEvents:UIControlEventValueChanged];
    [_greenSlider addTarget:self action:@selector(colorComponentChanged) forControlEvents:UIControlEventValueChanged];
    [_blueSlider addTarget:self action:@selector(colorComponentChanged) forControlEvents:UIControlEventValueChanged];
    [_alphaSlider addTarget:self action:@selector(colorComponentChanged) forControlEvents:UIControlEventValueChanged];

    // Setup style picker
    _indicatorStylePicker = [[UIPickerView alloc] initWithFrame:CGRectMake((screenWidth / 2) - 75, 325, 150, 100)];
    _indicatorStylePicker.delegate = self;
    [_indicatorStylePicker selectRow:_indicator.activityIndicatorViewStyle inComponent:0 animated:NO];
    [self.view addSubview:_indicatorStylePicker];
}

// Toggles the animation of the activity indicator
- (void)animateButtonPressed:(UIButton*)sender {
    if (_indicator.isAnimating) {
        [_indicator stopAnimating];
        [sender setTitle:@"Start Animating" forState:UIControlStateNormal];
    } else {
        [_indicator startAnimating];
        [sender setTitle:@"Stop Animating" forState:UIControlStateNormal];
    }
}

// Sets the hidesWhenStopped property of the activity indicator
- (void)hideIndicatorSwitchToggled:(UISwitch*)sender {
    _indicator.hidesWhenStopped = sender.isOn;
}

// Updates the activity indicator color and slider value labels with the current slider values
- (void)colorComponentChanged {
    _indicator.color = [UIColor colorWithRed:_redSlider.value green:_greenSlider.value blue:_blueSlider.value alpha:_alphaSlider.value];

    _redValueLabel.text = [NSString stringWithFormat:@"%.2f", _redSlider.value];
    _greenValueLabel.text = [NSString stringWithFormat:@"%.2f", _greenSlider.value];
    _blueValueLabel.text = [NSString stringWithFormat:@"%.2f", _blueSlider.value];
    _alphaValueLabel.text = [NSString stringWithFormat:@"%.2f", _alphaSlider.value];
}

/* Updates the color sliders with the current color components of the activity indicator
NOTE: This is needed to ensure the sliders are correctly updated when changing styles on the indicator.
*/
- (void)updateColorSlidersFromIndicatorColor {
    // Get the internal color components for our current indicator color
    CGColorRef indicatorColor = _indicator.color.CGColor;
    CGColorSpaceRef colorSpace = CGColorGetColorSpace(indicatorColor);
    CGColorSpaceModel colorSpaceModel = CGColorSpaceGetModel(colorSpace);
    const CGFloat* components = CGColorGetComponents(indicatorColor);

    float red, green, blue, alpha;

    // Translate color components based on color space
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

    _redSlider.value = red;
    _greenSlider.value = green;
    _blueSlider.value = blue;
    _alphaSlider.value = alpha;
    _redValueLabel.text = [NSString stringWithFormat:@"%.2f", red];
    _greenValueLabel.text = [NSString stringWithFormat:@"%.2f", green];
    _blueValueLabel.text = [NSString stringWithFormat:@"%.2f", blue];
    _alphaValueLabel.text = [NSString stringWithFormat:@"%.2f", alpha];
}

- (void)pickerView:(UIPickerView*)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    _indicator.activityIndicatorViewStyle = (UIActivityIndicatorViewStyle)row;
    [self updateColorSlidersFromIndicatorColor];
}

- (NSString*)pickerView:(UIPickerView*)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    return _indicatorStylesText[row];
}

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView*)pickerView {
    return 1;
}

- (NSInteger)pickerView:(UIPickerView*)pickerView numberOfRowsInComponent:(NSInteger)component {
    return [_indicatorStylesText count];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end