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

#import "UIButtonWithControlsViewController.h"
#import <UIKit/UIButton.h>

@implementation UIButtonWithControlsViewController {
    UIButton* _selectedButton;
    MenuTableViewController* _menuTVC;
}

// TODO: Move these methods into TestEnabledUITextField
- (UIColor*)getColor:(NSString*)colorString {
    UIColor* color = nil;

    SEL selector = NSSelectorFromString(colorString);
    if ([UIColor respondsToSelector:selector]) {
        color = [UIColor performSelector:selector];
    }

    return color;
}

- (UIImage*)getImage:(NSString*)imageString {
    UIImage* image = nil;

    // TODO: We should probably do more checking before we try and load this image
    if ([imageString hasSuffix:@".jpg"] || [imageString hasSuffix:@".png"]) {
        image = [UIImage imageNamed:imageString];
    }

    return image;
}

- (UIControlState)getControlState:(NSString*)stateString {
    UIControlState state = UIControlStateNormal;

    if ([stateString rangeOfString:@"N"].location != NSNotFound) {
        state |= UIControlStateNormal;
    }
    if ([stateString rangeOfString:@"H"].location != NSNotFound) {
        state |= UIControlStateHighlighted;
    }
    if ([stateString rangeOfString:@"D"].location != NSNotFound) {
        state |= UIControlStateDisabled;
    }
    if ([stateString rangeOfString:@"S"].location != NSNotFound) {
        state |= UIControlStateSelected;
    }

    return state;
}

- (UIEdgeInsets)getUIEdgeInsetsFromString:(UITextField*)textField {
    UIEdgeInsets ret = UIEdgeInsetsZero;
    NSString* edgeInsetsString = textField.text;

    // Inset strings are formated as {A, B, C, D} where A,B,C and D are CGFloats types.
    // Example: "{80.0f, 80.0f, 80f, 80f}" and "{80, 80, 80, 80}" are a valid edge insets in string format
    if ([edgeInsetsString length] > 0) {
        // Strip off curly braces and use the delimiter to separate components
        NSString* strWithBraces = [edgeInsetsString substringWithRange:NSMakeRange(1, edgeInsetsString.length - 1)];
        NSArray* components = [strWithBraces componentsSeparatedByString:@","];

        if (components.count < 4) {
            textField.backgroundColor = [UIColor redColor]; // invalid number of components
        } else {
            textField.backgroundColor = [UIColor clearColor];
            for (int componentIndex = 0; componentIndex < components.count; componentIndex++) {
                CGFloat value = ((NSString*)[components objectAtIndex:componentIndex]).floatValue;
                if (componentIndex == 0) {
                    ret.top = value;

                } else if (componentIndex == 1) {
                    ret.left = value;
                } else if (componentIndex == 2) {
                    ret.bottom = value;
                } else if (componentIndex == 3) {
                    ret.right = value;
                }
            }
        }
    }

    return ret;
}

- (void)dealloc {
    [_segmentButtonType removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];

    [_textImageEdgeInsets removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];

    [_textTitleStateField removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];
    [_textTitle removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];

    [_textTitleColorStateField removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];
    [_textTitleColor removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];

    [_textImageStateField removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];
    [_textImage removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];

    [_textBackgroundImageStateField removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];
    [_textBackgroundImage removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];
}

- (TestEnabledUITextField*)createTestEnabledUITextField {
    TestEnabledUITextField* testEnabledUITextField = [[TestEnabledUITextField alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 150.0f, 40.0f)];
    testEnabledUITextField.textColor = [UIColor blackColor];
    testEnabledUITextField.backgroundColor = [UIColor lightGrayColor];
    testEnabledUITextField.textAlignment = UITextAlignmentCenter;
    testEnabledUITextField.spellCheckingType = UITextSpellCheckingTypeNo;
    testEnabledUITextField.contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
    testEnabledUITextField.borderStyle = UITextBorderStyleLine;
    testEnabledUITextField.font = [UIFont systemFontOfSize:15.0f];
    testEnabledUITextField.adjustsFontSizeToFitWidth = YES;

    return testEnabledUITextField;
}

- (void)createButtonWithTypeControls {
    NSArray* segmentButtonTypeContent = [NSArray arrayWithObjects:@"Default", @"Custom", @"System", @"RoundedRect", nil];
    _segmentButtonType = [[UISegmentedControl alloc] initWithItems:segmentButtonTypeContent];
    _segmentButtonType.frame = CGRectMake(0.0f, 0.0f, 540.0f, 40.0f);
    [_segmentButtonType addTarget:self action:@selector(onButtonWithTypeChanged:) forControlEvents:UIControlEventValueChanged];
    _segmentButtonType.selectedSegmentIndex = 0;
    [_menuTVC addMenuItemView:_segmentButtonType andTitle:@"Button Type"];
}

- (void)createInsetControls {
    _textContentEdgeInsets = [self createTestEnabledUITextField];
    [_textContentEdgeInsets addTarget:self action:@selector(onContentEdgeInsetsChanged:) forControlEvents:UIControlEventEditingChanged];
    [_menuTVC addMenuItemView:_textContentEdgeInsets andTitle:@"Content Edge Insets (e.g. {80, 80, 80, 80})"];

    _textTitleEdgeInsets = [self createTestEnabledUITextField];
    [_textTitleEdgeInsets addTarget:self action:@selector(onTitleEdgeInsetsChanged:) forControlEvents:UIControlEventEditingChanged];
    [_menuTVC addMenuItemView:_textTitleEdgeInsets andTitle:@"Title Edge Insets (e.g. {80, 80, 80, 80})"];

    _textImageEdgeInsets = [self createTestEnabledUITextField];
    [_textImageEdgeInsets addTarget:self action:@selector(onImageEdgeInsetsChanged:) forControlEvents:UIControlEventEditingChanged];
    [_menuTVC addMenuItemView:_textImageEdgeInsets andTitle:@"Image Edge Insets (e.g. {80, 80, 80, 80})"];
}

- (void)createTitleControls {
    _textTitleStateField = [self createTestEnabledUITextField];
    [_textTitleStateField addTarget:self action:@selector(onTitleStateFieldChanged:) forControlEvents:UIControlEventEditingChanged];
    [_menuTVC addMenuItemView:_textTitleStateField andTitle:@"Title - state field (e.g. 'N;')"];

    _textTitle = [self createTestEnabledUITextField];
    [_textTitle addTarget:self action:@selector(onTitleChanged:) forControlEvents:UIControlEventEditingChanged];
    [_menuTVC addMenuItemView:_textTitle andTitle:@"Title - e.g. Normal"];
}

- (void)createTitleColorControls {
    _textTitleColorStateField = [self createTestEnabledUITextField];
    [_textTitleColorStateField addTarget:self
                                  action:@selector(onTitleColorStateFieldChanged:)
                        forControlEvents:UIControlEventEditingChanged];
    [_menuTVC addMenuItemView:_textTitleColorStateField andTitle:@"Title Color - state field (e.g. 'N;')"];

    _textTitleColor = [self createTestEnabledUITextField];
    [_textTitleColor addTarget:self action:@selector(onTitleColorChanged:) forControlEvents:UIControlEventEditingChanged];
    [_menuTVC addMenuItemView:_textTitleColor andTitle:@"Title Color - e.g. redColor"];
}

- (void)createImageControls {
    _textImageStateField = [self createTestEnabledUITextField];
    [_textImageStateField addTarget:self action:@selector(onImageStateFieldChanged:) forControlEvents:UIControlEventEditingChanged];
    [_menuTVC addMenuItemView:_textImageStateField andTitle:@"Image - state field (e.g. 'N;')"];

    _textImage = [self createTestEnabledUITextField];
    [_textImage addTarget:self action:@selector(onImageChanged:) forControlEvents:UIControlEventEditingChanged];
    [_menuTVC addMenuItemView:_textImage andTitle:@"Image - (e.g. button_image.png)"];
}

- (void)createBackgroundImageControls {
    _textBackgroundImageStateField = [self createTestEnabledUITextField];
    [_textBackgroundImageStateField addTarget:self
                                       action:@selector(onBackgroundImageStateFieldChanged:)
                             forControlEvents:UIControlEventEditingChanged];
    [_menuTVC addMenuItemView:_textBackgroundImageStateField andTitle:@"Background Image - state field (e.g. 'N;')"];

    _textBackgroundImage = [self createTestEnabledUITextField];
    [_textBackgroundImage addTarget:self action:@selector(onBackgroundImageChanged:) forControlEvents:UIControlEventEditingChanged];
    [_menuTVC addMenuItemView:_textBackgroundImage andTitle:@"Background Image - (e.g. yellow_backgroung.jpg)"];
}

- (void)viewDidLoad {
    [super viewDidLoad];

    // Set up the stage for the UIButton that will be manipulated
    self.title = @"UIButton with controls";
    self.view.backgroundColor = [UIColor whiteColor];
    self.view.frame = CGRectMake(0.0f, 0.0f, 200.0f, 0.0f);

    // Configure the button
    [self setupButtons];

    // TableViewController hosting the controls that manipulate UIButton
    _menuTVC = [[MenuTableViewController alloc] init];
    _menuTVC.view.frame = CGRectMake(0.0f, 200.0f, 200.0f, 0.0f /* setting it to 0 allows vertical scrolling */);
    _menuTVC.tableView.allowsSelection = NO;
    [self.view addSubview:_menuTVC.view];

    [self createButtonWithTypeControls];

    _switchHighlighted = [[UISwitch alloc] init];
    [_switchHighlighted addTarget:self action:@selector(onHighlighted) forControlEvents:UIControlEventValueChanged];
    [_menuTVC addMenuItemView:_switchHighlighted andTitle:@"Highlighted"];

    _switchEnabled = [[UISwitch alloc] init];
    _switchEnabled.on = YES;
    [_switchEnabled addTarget:self action:@selector(onEnabled) forControlEvents:UIControlEventValueChanged];
    [_menuTVC addMenuItemView:_switchEnabled andTitle:@"Enabled"];

    _switchSelected = [[UISwitch alloc] init];
    [_switchSelected addTarget:self action:@selector(onSelected) forControlEvents:UIControlEventValueChanged];
    [_menuTVC addMenuItemView:_switchSelected andTitle:@"Selected"];

    _switchAdjustsImageWhenHighlighted = [[UISwitch alloc] init];
    _switchAdjustsImageWhenHighlighted.on = YES;
    [_switchAdjustsImageWhenHighlighted addTarget:self
                                           action:@selector(onAdjustsImageWhenHighlighted)
                                 forControlEvents:UIControlEventValueChanged];
    [_menuTVC addMenuItemView:_switchAdjustsImageWhenHighlighted andTitle:@"AdjustsImageWhenHighlighted"];

    _switchAdjustsImageWhenDisabled = [[UISwitch alloc] init];
    _switchAdjustsImageWhenDisabled.on = YES;
    [_switchAdjustsImageWhenDisabled addTarget:self
                                        action:@selector(onAdjustsImageWhenDisabled)
                              forControlEvents:UIControlEventValueChanged];
    [_menuTVC addMenuItemView:_switchAdjustsImageWhenDisabled andTitle:@"AdjustsImageWhenDisabled"];

    [self createInsetControls];
    [self createTitleControls];
    [self createTitleColorControls];
    [self createImageControls];
    [self createBackgroundImageControls];
}

// Initial configuration parameters for the UIButton
- (void)setupButtons {
    _defaultButton = [[UIButton alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 200.0f, 200.0f)];
    [_defaultButton setFont:[UIFont fontWithName:@"ArialMT" size:16.0f]];

    _customButton = [UIButton buttonWithType:UIButtonTypeCustom];
    _customButton.frame = CGRectMake(200.0f, 0.0f, 200.0f, 200.0f);

    _systemButton = [UIButton buttonWithType:UIButtonTypeSystem];
    _systemButton.frame = CGRectMake(400.0f, 0.0f, 200.0f, 200.0f);

    _roundedRectButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    _roundedRectButton.frame = CGRectMake(600.0f, 0.0f, 200.0f, 200.0f);

    [self.view addSubview:_defaultButton];
    [self.view addSubview:_customButton];
    [self.view addSubview:_systemButton];
    [self.view addSubview:_roundedRectButton];

    _selectedButton = _defaultButton;
}

- (UIButton*)selectButton:(UIButtonType)buttonType {
    switch (buttonType) {
        case UIButtonTypeCustom:
            _segmentButtonType.selectedSegmentIndex = 1;
            _selectedButton = _customButton;
            break;
        case UIButtonTypeSystem:
            _segmentButtonType.selectedSegmentIndex = 2;
            _selectedButton = _systemButton;
            break;
#ifdef WINOBJC
        case UIButtonTypeRoundedRect:
            _segmentButtonType.selectedSegmentIndex = 3;
            _selectedButton = _roundedRectButton;
            break;
#endif
        case UIButtonTypeDetailDisclosure:
        case UIButtonTypeInfoLight:
        case UIButtonTypeInfoDark:
        case UIButtonTypeContactAdd:
        default:
            _segmentButtonType.selectedSegmentIndex = 0;
            _selectedButton = _defaultButton;
            break;
    }

    return _selectedButton;
}

// Toggle if the button is highlighted (alternate to a pressed button)
- (void)onHighlighted {
    _selectedButton.highlighted = _switchHighlighted.on;
}

// Toggle if the button is enabled or disabled
- (void)onEnabled {
    _selectedButton.enabled = _switchEnabled.on;
}

// Toggle if the button is selected
- (void)onSelected {
    _selectedButton.selected = _switchSelected.on;
}

// Toggles the button's adjustsImageWhenHighlighted property
- (void)onAdjustsImageWhenHighlighted {
    _selectedButton.adjustsImageWhenHighlighted = _switchAdjustsImageWhenHighlighted.on;
}

// Toggles the button's adjustsImageWhenDisabled property
- (void)onAdjustsImageWhenDisabled {
    _selectedButton.adjustsImageWhenDisabled = _switchAdjustsImageWhenDisabled.on;
}

//
// ButtonWithType
//
- (void)onButtonWithTypeChanged:(UISegmentedControl*)segmentedControl {
    if (segmentedControl.selectedSegmentIndex == 0) {
        _selectedButton = _defaultButton;
    } else if (segmentedControl.selectedSegmentIndex == 1) {
        _selectedButton = _customButton;
    } else if (segmentedControl.selectedSegmentIndex == 2) {
        _selectedButton = _systemButton;
    } else if (segmentedControl.selectedSegmentIndex == 3) {
        _selectedButton = _roundedRectButton;
    }
}

//
// Content Edge Insets
//
- (void)onContentEdgeInsetsChanged:(UITextField*)textField {
    if ([textField.text hasPrefix:@"{"] && [textField.text hasSuffix:@"}"]) {
        _selectedButton.contentEdgeInsets = [self getUIEdgeInsetsFromString:textField];

        NSLog(@"%@", NSStringFromCGRect(_selectedButton.imageView.frame));
    }
}

//
// Title Edge Insets
//
- (void)onTitleEdgeInsetsChanged:(UITextField*)textField {
    if ([textField.text hasPrefix:@"{"] && [textField.text hasSuffix:@"}"]) {
        _selectedButton.titleEdgeInsets = [self getUIEdgeInsetsFromString:textField];

        NSLog(@"%@", NSStringFromCGRect(_selectedButton.titleLabel.frame));
    }
}

//
// Image Edge Insets
//
- (void)onImageEdgeInsetsChanged:(UITextField*)textField {
    if ([textField.text hasPrefix:@"{"] && [textField.text hasSuffix:@"}"]) {
        _selectedButton.imageEdgeInsets = [self getUIEdgeInsetsFromString:textField];

        NSLog(@"%@", NSStringFromCGRect(_selectedButton.imageView.frame));
    }
}

//
// Title
//
- (void)onTitleStateFieldChanged:(UITextField*)textField {
    // Need a way to signal that the bit field should only be interpreted when a sentinel character is present
    if ([textField.text hasSuffix:@";"]) {
        UIControlState newControlState = [self getControlState:textField.text];
        if (newControlState != _titleControlState) {
            _titleControlState = newControlState;

            // Draw attention to the old text
            _textTitle.backgroundColor = [UIColor redColor];
        }
    }
}

- (void)onTitleChanged:(UITextField*)textField {
    NSString* changedText = textField.text;
    [_selectedButton setTitle:changedText forState:_titleControlState];

    // Text has been updated - revert to previous background color
    _textTitle.backgroundColor = [UIColor lightGrayColor];
}

//
// TitleColor
//
- (void)onTitleColorStateFieldChanged:(UITextField*)textField {
    UIControlState newControlState = [self getControlState:textField.text];
    if (newControlState != _titleColorControlState) {
        _titleColorControlState = newControlState;

        // Draw attention to the old text
        _textTitleColor.backgroundColor = [UIColor redColor];
    }
}

- (void)onTitleColorChanged:(UITextField*)textField {
    _titleColor = [self getColor:textField.text];
    [_selectedButton setTitleColor:_titleColor forState:_titleColorControlState];

    // Text has been updated - revert to previous background color
    _textTitleColor.backgroundColor = [UIColor lightGrayColor];
}

//
// Image
//
- (void)onImageStateFieldChanged:(UITextField*)textField {
    UIControlState newControlState = [self getControlState:textField.text];
    if (newControlState != _imageControlState) {
        _imageControlState = newControlState;

        // Draw attention to the old text
        _textImage.backgroundColor = [UIColor redColor];
    }
}

- (void)onImageChanged:(UITextField*)textField {
    _image = [self getImage:textField.text];
    [_selectedButton setImage:_image forState:_imageControlState];

    // Text has been updated - revert to previous background color
    _textImage.backgroundColor = [UIColor lightGrayColor];
}

//
// Background Image
//
- (void)onBackgroundImageStateFieldChanged:(UITextField*)textField {
    UIControlState newControlState = [self getControlState:textField.text];
    if (newControlState != _backgroundImageControlState) {
        _backgroundImageControlState = newControlState;

        // Draw attention to the old text
        _textBackgroundImage.backgroundColor = [UIColor redColor];
    }
}

- (void)onBackgroundImageChanged:(UITextField*)textField {
    _backgroundImage = [self getImage:textField.text];
    [_selectedButton setBackgroundImage:_backgroundImage forState:_backgroundImageControlState];

    // Text has been updated - revert to previous background color
    _textBackgroundImage.backgroundColor = [UIColor lightGrayColor];
}

//
// Dismiss keyboard
//

// Delegate to dismiss the keyboard
- (BOOL)textFieldShouldReturn:(UITextField*)textField {
    [textField resignFirstResponder];

    return YES;
}

@end
