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

#import "UIPasteboardViewController.h"
#import "MobileCoreServices/UTType.h"

static const CGFloat c_originX = 5;
static const CGFloat c_originY = 8;
static const CGFloat c_width = 260;
static const CGFloat c_height = 50;

@implementation UIPasteboardViewController {
@private
    UIPasteboard* copyAndPaste;
    UITextField* pasteTextField;
    UITextField* copyTextField;
    UIButton* screenShotButton;
    UIButton* textPasteButton;
    UIButton* URLPasteButton;
    UITableViewCell* cell;
    UIView* myImageOuterView;
    UIImageView* _imageView;
    NSMutableArray* _textFields;
    NSString* clipboardText;
    NSString* clipboardURLText;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    // Initialize the paste board
    copyAndPaste = [UIPasteboard generalPasteboard];
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    [self tableView].allowsSelection = YES;

    return 9;
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    return 70;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    }

    if (indexPath.row == 0) {
        // text field for copy and paste

        CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
        copyTextField = [[UITextField alloc] initWithFrame:frame];

        copyTextField.textColor = [UIColor blackColor];
        copyTextField.font = [UIFont systemFontOfSize:17.0];
        cell.accessoryView = copyTextField;
        cell.textLabel.text = @"Text is copied from here";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        [copyTextField addTarget:self action:@selector(onCopyTextChanged:) forControlEvents:UIControlEventEditingChanged];
        [cell addSubview:copyTextField];
    } else if (indexPath.row == 1) {
        // text is pasted here

        CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
        pasteTextField = [[UITextField alloc] initWithFrame:frame];

        pasteTextField.textColor = [UIColor blackColor];
        pasteTextField.font = [UIFont systemFontOfSize:17.0];
        cell.accessoryView = pasteTextField;
        cell.textLabel.text = @"Copied text Appears here";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        [cell addSubview:pasteTextField];
    } else if (indexPath.row == 2) {
        // control for copy and paste of text

        CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
        textPasteButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        [textPasteButton setFrame:CGRectMake(50, 50, 200, 40)];
        [textPasteButton setTitle:@"Click to paste" forState:UIControlStateNormal];
        cell.accessoryView = textPasteButton;
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.textLabel.text = @"Text copied from notepad will appear after hitting the button";
        [textPasteButton addTarget:self action:@selector(onPasteChanged) forControlEvents:UIControlEventTouchUpInside];
        [cell addSubview:textPasteButton];
    } else if (indexPath.row == 3) {
        // displayer for copy and paste of text

        CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
        UITextField* textField = [[UITextField alloc] initWithFrame:frame];
        UILabel* label = [[UILabel alloc] initWithFrame:frame];
        [label setBackgroundColor:nil];
        if (clipboardText != nil) {
            [label setText:clipboardText];
        } else {
            [label setText:@"No clipboard text present"];
        }

        cell.accessoryView = label;
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.textLabel.text = @"Copy text from notepad and it will appear in the accesoryView";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        [cell addSubview:label];

    } else if (indexPath.row == 4) {
        // control for copy and paste of URL

        CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
        URLPasteButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        [URLPasteButton setFrame:CGRectMake(50, 50, 200, 40)];
        [URLPasteButton setTitle:@"Copy and Paste" forState:UIControlStateNormal];
        cell.accessoryView = URLPasteButton;
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.textLabel.text = @"Click to copy the URL http://www.example.com/ to pasteboard and then paste it below.";
        [URLPasteButton addTarget:self action:@selector(onURLCopyAndPaste) forControlEvents:UIControlEventTouchUpInside];
        [cell addSubview:URLPasteButton];
    } else if (indexPath.row == 5) {
        // displayer for copy and paste of text

        CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
        UILabel* label = [[UILabel alloc] initWithFrame:frame];
        [label setBackgroundColor:nil];
        if (clipboardURLText != nil) {
            [label setText:clipboardURLText];
        } else {
            [label setText:@"No clipboard URL present"];
        }

        cell.accessoryView = label;
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.textLabel.text = @"Copied URL will appear in the accesoryView";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        [cell addSubview:label];

    } else if (indexPath.row == 6) {
        // control for copy of image

        CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
        textPasteButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        [textPasteButton setFrame:CGRectMake(50, 50, 200, 40)];
        [textPasteButton setTitle:@"Put Image to Pasteboard" forState:UIControlStateNormal];
        cell.accessoryView = textPasteButton;
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.textLabel.text = @"An image will be put into Pasteboard after hitting the button. Then click the button 'Show Image'.";
        [textPasteButton addTarget:self action:@selector(onSetImageToPasteboard) forControlEvents:UIControlEventTouchUpInside];
        [cell addSubview:textPasteButton];
    } else if (indexPath.row == 7) {
        // control for copy and paste of a printscreen

        CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
        screenShotButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        [screenShotButton setFrame:CGRectMake(50, 50, 200, 40)];
        [screenShotButton setTitle:@"Show Image" forState:UIControlStateNormal];
        cell.accessoryView = screenShotButton;
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.textLabel.text = @"Take A screen shot CTRL + ALT + PrintScreen then click the button the image should appear";
        [screenShotButton addTarget:self action:@selector(onPasteChangedScreenCapture) forControlEvents:UIControlEventTouchUpInside];
        [cell addSubview:screenShotButton];
    } else if (indexPath.row == 8) {
        // displayer for copy and paste screen shot

        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.textLabel.text = @"Image should appear in accessory view";

        if (_imageView != nil) {
            UIView* view = [[UIView alloc] initWithFrame:CGRectMake(50, 50, 200, 40)];
            [view addSubview:_imageView];

            cell.accessoryView = view;
            [cell addSubview:view];

        } else {
            UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(c_originX, c_originY, c_width, c_height)];
            [label setBackgroundColor:nil];
            [label setText:@"Image on clipboard is null"];

            cell.accessoryView = label;
            [cell addSubview:label];
        }
    }
    return cell;
}

- (void)onCopyTextChanged:(UITextField*)textField {
    copyAndPaste.string = textField.text;
    pasteTextField.text = copyAndPaste.string;

    [[self tableView] setNeedsLayout];
}

- (void)onPasteChanged {
    clipboardText = copyAndPaste.string;

    [[self tableView] reloadData];
}

- (void)onSetImageToPasteboard {
    copyAndPaste.image = [UIImage imageNamed:@"photo9.jpg"];
}

- (void)onURLCopyAndPaste {
    NSURL* urlData = [NSURL URLWithString:@"http://www.example.com/"];
    copyAndPaste.URL = urlData;
    NSURL* urlFromClipboard = copyAndPaste.URL;
    clipboardURLText = urlFromClipboard.absoluteString;

    [[self tableView] reloadData];
}

- (void)onPasteChangedScreenCapture {
    _imageView = [[UIImageView alloc] initWithFrame:CGRectMake(c_originX, c_originY, 320, 320)];
    [_imageView setImage:copyAndPaste.image];

    [[self tableView] reloadData];
}

@end
