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

#import "ApplicationViewController.h"
#import "UIKit/UIDevice.h"

static const CGFloat c_originX = 5;
static const CGFloat c_originY = 8;
static const CGFloat c_width = 160;
static const CGFloat c_height = 40;

@implementation ApplicationViewController {
    UIDevice* device;
    NSString* name;
    NSString* systemVersion;
    NSString* identifierForVendor;
    UITextField* currentSystemVersion;
    UIButton* _disableInputButton;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self tableView].allowsSelection = NO;
}

- (id)init {
    self = [super init];
    device = [UIDevice currentDevice];
    name = [device name];
    systemVersion = [device systemVersion];
    identifierForVendor = [[device identifierForVendor] UUIDString];
    return self;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 6;
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    return 50;
}

- (void)onTextFieldChange:(UITextField*)textField {
    [UIApplication sharedApplication].applicationIconBadgeNumber = textField.text.intValue;
}

- (void)onSystemVersionTextChanged:(UITextField*)textField {
// setting systemVersion not supported on other platforms
#ifdef WINOBJC
    device.systemVersion = textField.text;
#endif
    currentSystemVersion.text = [device systemVersion];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    }

    if (indexPath.row == 0) {
        UIUserNotificationSettings* settings = [UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeBadge categories:nil];
        [[UIApplication sharedApplication] registerUserNotificationSettings:settings];

        // applicationIconBadgeNumber
        CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
        UITextField* textField = [[UITextField alloc] initWithFrame:frame];

        textField.borderStyle = UITextBorderStyleBezel;
        textField.textColor = [UIColor blackColor];
        textField.font = [UIFont systemFontOfSize:17.0];
        textField.placeholder = @"enter badge number";
        textField.backgroundColor = [UIColor whiteColor];
        textField.autocorrectionType = UITextAutocorrectionTypeNo;
        textField.keyboardType = UIKeyboardTypeDefault;
        textField.returnKeyType = UIReturnKeyDone;
        textField.clearButtonMode = UITextFieldViewModeWhileEditing;

        [textField addTarget:self action:@selector(onTextFieldChange:) forControlEvents:UIControlEventEditingChanged];

        cell.accessoryView = textField;
        cell.textLabel.text = @"Set badge number";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;

    } else if (indexPath.row == 1) {
        // device name
        UITextField* textField = [[UITextField alloc] initWithFrame:CGRectMake(c_originX, c_originY, c_width, c_height)];
        textField.text = name;
        textField.borderStyle = UITextBorderStyleBezel;
        textField.font = [UIFont systemFontOfSize:10.0];
        cell.accessoryView = textField;
        cell.textLabel.text = @"UIDevice Name";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;

    } else if (indexPath.row == 2) {
        // to set the systemVersion
        UITextField* textField = [[UITextField alloc] initWithFrame:CGRectMake(c_originX, c_originY, c_width, c_height)];

        textField.borderStyle = UITextBorderStyleBezel;
        textField.textColor = [UIColor blackColor];
        textField.font = [UIFont systemFontOfSize:10.0];
        textField.backgroundColor = [UIColor whiteColor];

        textField.placeholder = @"enter systemVersion";
        textField.autocorrectionType = UITextAutocorrectionTypeNo;
        textField.keyboardType = UIKeyboardTypeDefault;
        textField.returnKeyType = UIReturnKeyDone;
        textField.clearButtonMode = UITextFieldViewModeWhileEditing;
        [textField addTarget:self action:@selector(onSystemVersionTextChanged:) forControlEvents:UIControlEventEditingChanged];

        cell.accessoryView = textField;
        cell.textLabel.text = @"system version";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    } else if (indexPath.row == 3) {
        // Current Set System Version
        currentSystemVersion = [[UITextField alloc] initWithFrame:CGRectMake(c_originX, c_originY, 50, c_height)];
        currentSystemVersion.text = systemVersion;
        currentSystemVersion.borderStyle = UITextBorderStyleBezel;

        cell.accessoryView = currentSystemVersion;
        cell.textLabel.text = @"current set system version";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    } else if (indexPath.row == 4) {
        // Identifier For Vendor
        UITextField* textField = [[UITextField alloc] initWithFrame:CGRectMake(c_originX, c_originY, 300, c_height)];
        textField.text = identifierForVendor;
        textField.borderStyle = UITextBorderStyleBezel;
        textField.font = [UIFont systemFontOfSize:8.0];
        cell.accessoryView = textField;
        cell.textLabel.text = @"identifierForVendor";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    } else if (indexPath.row == 5) {
        // Add test for disabling input
        UIButton* _disableInputButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        NSString* buttonText = @"Ignore UIApplication interaction events for 5 seconds.";
        _disableInputButton.frame = CGRectMake(5.0f, 5.0f, 450, cell.frame.size.height - 5.0f);
        _disableInputButton.layer.cornerRadius = 5.0f;
        [_disableInputButton setTitle:buttonText forState:UIControlStateNormal];
        _disableInputButton.titleLabel.textAlignment = UITextAlignmentCenter;
        [_disableInputButton addTarget:self action:@selector(_disableInputButtonClicked) forControlEvents:UIControlEventTouchUpInside];
        [cell addSubview:_disableInputButton];
    }

    return cell;
}

- (void)_reEnableInput {
    // Reenable input
    [[UIApplication sharedApplication] endIgnoringInteractionEvents];
}

- (void)_disableInputButtonClicked {
    // Disable input for 5 seconds
    [[UIApplication sharedApplication] beginIgnoringInteractionEvents];
    [self performSelector:@selector(_reEnableInput) withObject:self afterDelay:5.0];
}

@end
