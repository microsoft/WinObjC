//******************************************************************************
//
// Copyright Microsoft Corporation. All rights reserved.
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
#import "UITextFieldViewController2.h"
#import <MobileCoreServices/MobileCoreServices.h>

@implementation UITextFieldViewController2 {
    int _eventId;
    MenuTableViewController* _menuTVC;
}

// setting up the controls to update the UILabel config
- (void)_setup {
    _menuTVC = [[MenuTableViewController alloc] init];
    _menuTVC.view.frame = CGRectMake(0.0f, 108.0f, 200.0f, 0.0f /* setting it to 0 allows vertical scrolling */);
    _menuTVC.tableView.allowsSelection = NO;
    [self.view addSubview:_menuTVC.view];

    self.text = [[UITextField alloc] initWithFrame:CGRectMake(105.0f, 20.0f, 400.0f, 30.0f)];
    [_menuTVC addMenuItemView:self.text andTitle:@"text on textField"];

    self.placeholder = [[UITextField alloc] initWithFrame:CGRectMake(105.0f, 20.0f, 400.0f, 30.0f)];
    [_menuTVC addMenuItemView:self.placeholder andTitle:@"Placeholder on textField"];

    self.fontSize = [[UISlider alloc] initWithFrame:CGRectMake(101.0f, 54.0f, 187.0f, 31.0f)];
    self.fontSize.minimumValue = 4.01f;
    self.fontSize.maximumValue = 80;

    [_menuTVC addMenuItemView:self.fontSize andTitle:@"Font Size"];

    self.fontSizeLabel = [[UILabel alloc] initWithFrame:CGRectMake(297.0f, 57.0f, 53.0f, 25.0f)];
    [_menuTVC addMenuItemView:self.fontSizeLabel andTitle:@"current Font Size"];

    self.autoShrink = [[UISwitch alloc] initWithFrame:CGRectMake(310.0f, 131.0f, 51.0f, 31.0f)];
    [_menuTVC addMenuItemView:self.autoShrink andTitle:@"Adjust font size to fit width"];

    self.minimumFontSize = [[UITextField alloc] initWithFrame:CGRectMake(80.0f, 167.0f, 56.0f, 30.0f)];
    [_menuTVC addMenuItemView:self.minimumFontSize andTitle:@"Minimum font size"];

    self.secureEntry = [[UISwitch alloc] initWithFrame:CGRectMake(310.0f, 131.0f, 51.0f, 31.0f)];
    [_menuTVC addMenuItemView:self.secureEntry andTitle:@"Change Secure Entry Mode"];

    self.textAlignment = [[UITextField alloc] initWithFrame:CGRectMake(74.0f, 92.0f, 45.0f, 30.0f)];
    [_menuTVC addMenuItemView:self.textAlignment andTitle:@"Setting Text Alignment [0-2]"];

    self.borderStyle = [[UITextField alloc] initWithFrame:CGRectMake(74.0f, 92.0f, 45.0f, 30.0f)];
    [_menuTVC addMenuItemView:self.borderStyle andTitle:@"Setting Border Style[0-3]"];

    self.keyboardType = [[UITextField alloc] initWithFrame:CGRectMake(74.0f, 92.0f, 45.0f, 30.0f)];
    [_menuTVC addMenuItemView:self.keyboardType andTitle:@"Set keyboard type[0-11]"];

    self.fr = [[UISlider alloc] initWithFrame:CGRectMake(101.0f, 54.0f, 187.0f, 31.0f)];
    self.fr.minimumValue = 0.0f;
    self.fr.maximumValue = 255.0f;
    [_menuTVC addMenuItemView:self.fr andTitle:@"Text Color red"];

    self.fg = [[UISlider alloc] initWithFrame:CGRectMake(101.0f, 54.0f, 187.0f, 31.0f)];
    self.fg.minimumValue = 0.0f;
    self.fg.maximumValue = 255.0f;
    [_menuTVC addMenuItemView:self.fg andTitle:@"Text Color blue"];

    self.fb = [[UISlider alloc] initWithFrame:CGRectMake(101.0f, 54.0f, 187.0f, 31.0f)];
    self.fb.minimumValue = 0.0f;
    self.fb.maximumValue = 255.0f;
    [_menuTVC addMenuItemView:self.fb andTitle:@"Text Color green"];

    self.br = [[UISlider alloc] initWithFrame:CGRectMake(101.0f, 54.0f, 187.0f, 31.0f)];
    self.br.minimumValue = 0.0f;
    self.br.maximumValue = 255.0f;
    [_menuTVC addMenuItemView:self.br andTitle:@"background red"];

    self.bg = [[UISlider alloc] initWithFrame:CGRectMake(101.0f, 54.0f, 187.0f, 31.0f)];
    self.bg.minimumValue = 0.0f;
    self.bg.maximumValue = 255.0f;
    [_menuTVC addMenuItemView:self.bg andTitle:@"background green"];

    self.bb = [[UISlider alloc] initWithFrame:CGRectMake(101.0f, 54.0f, 187.0f, 31.0f)];
    self.bb.minimumValue = 0.0f;
    self.bb.maximumValue = 255.0f;
    [_menuTVC addMenuItemView:self.bb andTitle:@"background blue"];

    self.x = [[UITextField alloc] initWithFrame:CGRectMake(74.0f, 92.0f, 45.0f, 30.0f)];
    [_menuTVC addMenuItemView:self.x andTitle:@"Bounding Rect origin x"];

    self.y = [[UITextField alloc] initWithFrame:CGRectMake(141.0f, 92.0f, 45.0f, 30.0f)];
    [_menuTVC addMenuItemView:self.y andTitle:@"Bounding Rect origin y"];

    self.w = [[UITextField alloc] initWithFrame:CGRectMake(211.0f, 92.0f, 45.0f, 30.0f)];
    [_menuTVC addMenuItemView:self.w andTitle:@"Bounding Rect width"];

    self.h = [[UITextField alloc] initWithFrame:CGRectMake(293.0f, 92.0f, 45.0f, 30.0f)];
    [_menuTVC addMenuItemView:self.h andTitle:@"Bounding Rect height"];

    self.textField = [[UITextField alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 353.0f, 107.0f)];
    [self.view addSubview:self.textField];
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor whiteColor];
    self.view.frame = CGRectMake(0.0f, 0.0f, 200.0f, 0.0f);

    // creating control default value using textField value
    [self _setup];

    self.view.frame = CGRectMake(0.0f, 0.0f, 800.0f, 600.0f);
    self.view.backgroundColor = [UIColor grayColor];

    self.text.text = self.textField.text;
    self.placeholder.text = self.textField.placeholder;
    self.fontSize.value = self.textField.font.pointSize;
    self.x.text = [NSString stringWithFormat:@"%3.0f", self.textField.frame.origin.x];
    self.y.text = [NSString stringWithFormat:@"%3.0f", self.textField.frame.origin.y];
    self.w.text = [NSString stringWithFormat:@"%3.0f", self.textField.frame.size.width];
    self.h.text = [NSString stringWithFormat:@"%3.0f", self.textField.frame.size.height];
    self.autoShrink.on = self.textField.adjustsFontSizeToFitWidth;
    self.minimumFontSize.text = [NSString stringWithFormat:@"%3.0f", self.textField.minimumFontSize];
    self.secureEntry.on = self.textField.secureTextEntry;
    self.textAlignment.text = [NSString stringWithFormat:@"%d", self.textField.textAlignment];
    self.borderStyle.text = [NSString stringWithFormat:@"%d", self.textField.borderStyle];
    self.keyboardType.text = [NSString stringWithFormat:@"%d", self.textField.keyboardType];

    CGFloat r, g, b, a;
    [self.textField.textColor getRed:&r green:&g blue:&b alpha:&a];
    self.fr.value = r;
    self.fg.value = g;
    self.fb.value = b;

    [self.textField.backgroundColor getRed:&r green:&g blue:&b alpha:&a];
    self.br.value = r;
    self.bg.value = g;
    self.bb.value = b;

    self.text.delegate = self;
    [self.text addTarget:self action:@selector(textFieldEditDidEnd:) forControlEvents:UIControlEventEditingDidEnd];

    self.placeholder.delegate = self;
    [self.placeholder addTarget:self action:@selector(textFieldEditDidEnd:) forControlEvents:UIControlEventEditingDidEnd];

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

    self.minimumFontSize.delegate = self;
    self.minimumFontSize.keyboardType = UIKeyboardTypeDecimalPad;
    [self.minimumFontSize addTarget:self action:@selector(textFieldEditDidEnd:) forControlEvents:UIControlEventEditingDidEnd];

    [self.fontSize addTarget:self action:@selector(fontSizeChanged:) forControlEvents:UIControlEventValueChanged];
    self.fontSize.continuous = YES;

    [self.autoShrink addTarget:self action:@selector(autoShrinkChanged:) forControlEvents:UIControlEventValueChanged];
    [self.secureEntry addTarget:self action:@selector(secureEntryModeChanged:) forControlEvents:UIControlEventValueChanged];

    self.textAlignment.delegate = self;
    self.textAlignment.keyboardType = UIKeyboardTypeNumberPad;
    [self.textAlignment addTarget:self action:@selector(textFieldEditDidEnd:) forControlEvents:UIControlEventEditingDidEnd];

    self.borderStyle.delegate = self;
    self.borderStyle.keyboardType = UIKeyboardTypeNumberPad;
    [self.borderStyle addTarget:self action:@selector(textFieldEditDidEnd:) forControlEvents:UIControlEventEditingDidEnd];

    self.keyboardType.delegate = self;
    self.keyboardType.keyboardType = UIKeyboardTypeNumberPad;
    [self.keyboardType addTarget:self action:@selector(textFieldEditDidEnd:) forControlEvents:UIControlEventEditingDidEnd];

    [self.fr addTarget:self action:@selector(colorChanged:) forControlEvents:UIControlEventValueChanged];
    self.fr.continuous = YES;

    [self.fg addTarget:self action:@selector(colorChanged:) forControlEvents:UIControlEventValueChanged];
    self.fg.continuous = YES;

    [self.fb addTarget:self action:@selector(colorChanged:) forControlEvents:UIControlEventValueChanged];
    self.fb.continuous = YES;

    [self.br addTarget:self action:@selector(colorChanged:) forControlEvents:UIControlEventValueChanged];
    self.br.continuous = YES;

    [self.bg addTarget:self action:@selector(colorChanged:) forControlEvents:UIControlEventValueChanged];
    self.bg.continuous = YES;

    [self.bb addTarget:self action:@selector(colorChanged:) forControlEvents:UIControlEventValueChanged];
    self.bb.continuous = YES;
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
    self.textField.adjustsFontSizeToFitWidth = self.autoShrink.on;
}

- (void)secureEntryModeChanged:(UISwitch*)secureEntryModeSwtich {
    self.textField.secureTextEntry = self.secureEntry.on;
}

- (void)fontSizeChanged:(UISlider*)slider {
    self.textField.font = [self.textField.font fontWithSize:slider.value];
    self.fontSizeLabel.text = [NSString stringWithFormat:@"%5.2f", slider.value];
}

- (void)colorChanged:(UISlider*)slider {
    if (slider == self.fr || slider == self.fg || slider == self.fb) {
        self.textField.textColor = [UIColor colorWithRed:self.fr.value green:self.fg.value blue:self.fb.value alpha:1];
    } else {
        self.textField.backgroundColor = [UIColor colorWithRed:self.br.value green:self.bg.value blue:self.bb.value alpha:1];
    }
}

- (void)textFieldEditDidEnd:(UITextField*)sender {
    if (sender == self.text) {
        // update textField text
        self.textField.text = sender.text;
    } else if (sender == self.placeholder) {
        self.textField.placeholder = sender.text;
    } else if (sender == self.x) {
        // update bound rect x
        CGRect rect = self.textField.frame;
        rect.origin.x = [self.x.text floatValue];
        self.textField.frame = rect;
    } else if (sender == self.y) {
        // update bound rect y
        CGRect rect = self.textField.frame;
        rect.origin.y = [self.y.text floatValue];
        self.textField.frame = rect;
    } else if (sender == self.w) {
        // update bound rect width
        CGRect rect = self.textField.frame;
        rect.size.width = [self.w.text floatValue];
        self.textField.frame = rect;
    } else if (sender == self.h) {
        // update bound rect height
        CGRect rect = self.textField.frame;
        rect.size.height = [self.h.text floatValue];
        self.textField.frame = rect;
    } else if (sender == self.minimumFontSize) {
        // update minimum font size
        self.textField.minimumFontSize = [self.minimumFontSize.text floatValue];
    } else if (sender == self.textAlignment) {
        self.textField.textAlignment = (UITextAlignment)([self.textAlignment.text intValue]);
    } else if (sender == self.borderStyle) {
        self.textField.borderStyle = (UITextBorderStyle)([self.borderStyle.text intValue]);
    } else if (sender == self.keyboardType) {
        self.textField.keyboardType = (UIKeyboardType)([self.keyboardType.text intValue]);
    }
}

@end
