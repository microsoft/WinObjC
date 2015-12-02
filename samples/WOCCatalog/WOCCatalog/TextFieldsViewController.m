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

#import "TextFieldsViewController.h"

static const CGFloat c_originX = 5;
static const CGFloat c_originY = 8;
static const CGFloat c_width = 260;
static const CGFloat c_height = 40;

@implementation TextFieldsViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    [self tableView].allowsSelection = NO;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 4;
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    return 50;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    }

    if (indexPath.row == 0) {
        // plain text field
        CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
        UITextField* textField = [[UITextField alloc] initWithFrame:frame];

        textField.borderStyle = UITextBorderStyleBezel;
        textField.textColor = [UIColor blackColor];
        textField.font = [UIFont systemFontOfSize:17.0];
        textField.placeholder = @"placeholder text";
        textField.backgroundColor = [UIColor whiteColor];
        textField.autocorrectionType = UITextAutocorrectionTypeNo;
        textField.keyboardType = UIKeyboardTypeDefault;
        textField.returnKeyType = UIReturnKeyDone;
        textField.clearButtonMode = UITextFieldViewModeWhileEditing;

        [cell addSubview:textField];

    } else if (indexPath.row == 1) {
        // rounded text field
        CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
        UITextField* textField = [[UITextField alloc] initWithFrame:frame];

        textField.borderStyle = UITextBorderStyleRoundedRect;
        textField.textColor = [UIColor blackColor];
        textField.font = [UIFont systemFontOfSize:17.0];
        textField.placeholder = @"placeholder text";
        textField.backgroundColor = [UIColor whiteColor];
        textField.autocorrectionType = UITextAutocorrectionTypeNo;
        textField.keyboardType = UIKeyboardTypeDefault;
        textField.returnKeyType = UIReturnKeyDone;
        textField.clearButtonMode = UITextFieldViewModeWhileEditing;

        [cell addSubview:textField];

    } else if (indexPath.row == 2) {
        // secure text field

        CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
        UITextField* textField = [[UITextField alloc] initWithFrame:frame];

        textField.borderStyle = UITextBorderStyleBezel;
        textField.textColor = [UIColor blackColor];
        textField.font = [UIFont systemFontOfSize:17.0];
        textField.placeholder = @"password text";
        textField.backgroundColor = [UIColor whiteColor];
        textField.autocorrectionType = UITextAutocorrectionTypeNo;
        textField.keyboardType = UIKeyboardTypeDefault;
        textField.returnKeyType = UIReturnKeyDone;
        textField.clearButtonMode = UITextFieldViewModeWhileEditing;
        textField.secureTextEntry = TRUE;

        [cell addSubview:textField];

    } else if (indexPath.row == 3) {
        // text field with background image

        CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
        UITextField* textField = [[UITextField alloc] initWithFrame:frame];

        textField.background = [UIImage imageNamed:@"photo5.jpg"];
        textField.textColor = [UIColor blackColor];
        textField.font = [UIFont systemFontOfSize:17.0];
        textField.placeholder = @"placeholder text";
        textField.autocorrectionType = UITextAutocorrectionTypeNo;
        textField.keyboardType = UIKeyboardTypeDefault;
        textField.returnKeyType = UIReturnKeyDone;
        textField.clearButtonMode = UITextFieldViewModeWhileEditing;

        [cell addSubview:textField];
    }

    return cell;
}

@end
