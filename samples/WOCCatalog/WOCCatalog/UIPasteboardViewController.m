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
#import <MobileCoreServices/MobileCoreServices.h>

static const CGFloat c_originX = 5;
static const CGFloat c_originY = 8;
static const CGFloat c_width = 260;
static const CGFloat c_height = 50;

@implementation UIPasteboardViewController {
@private
    UIPasteboard* _pasteBoard;
    UILabel* _pasteTextLabel;
    UITextField* _copyTextField;
    UIButton* _screenShotButton;
    UIButton* _textPasteButton;
    UIButton* _URLPasteButton;
    UITableViewCell* _cell;
    UIImageView* _imageView;
    NSString* _pasteBoardText;
    NSURL* _pasteBoardURL;
    NSInteger numberOfPasteboardItems;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    // Initialize the paste board
    _pasteBoard = [UIPasteboard generalPasteboard];
    numberOfPasteboardItems = _pasteBoard.numberOfItems;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    [self tableView].allowsSelection = YES;
    return 14;
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    return 70;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    _cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (nil == _cell) {
        _cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
        _cell.selectionStyle = UITableViewCellSelectionStyleNone;
    }

    CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);

    if (indexPath.row == 0) {
        // text field for copy
        _copyTextField = [[UITextField alloc] initWithFrame:frame];

        _copyTextField.textColor = [UIColor blackColor];
        _copyTextField.font = [UIFont systemFontOfSize:17.0];
        _cell.accessoryView = _copyTextField;
        _cell.textLabel.text = @"Text is copied from here";
        [_copyTextField addTarget:self action:@selector(onCopyTextChanged:) forControlEvents:UIControlEventEditingChanged];
    } else if (indexPath.row == 1) {
        // Label to show pasted text
        _pasteTextLabel = [[UILabel alloc] initWithFrame:frame];
        _pasteTextLabel.textColor = [UIColor blackColor];
        _pasteTextLabel.font = [UIFont systemFontOfSize:17.0];
        _pasteTextLabel.textAlignment = NSTextAlignmentLeft;
        _cell.accessoryView = _pasteTextLabel;
        _cell.textLabel.text = @"Copied text Appears here";
    } else if (indexPath.row == 2) {
        // button to paste text
        _textPasteButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        [_textPasteButton setFrame:CGRectMake(50, 50, 200, 40)];
        [_textPasteButton setTitle:@"Paste text" forState:UIControlStateNormal];
        [_textPasteButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_textPasteButton addTarget:self action:@selector(onPasteChanged) forControlEvents:UIControlEventTouchUpInside];
        _cell.accessoryView = _textPasteButton;
        _cell.textLabel.text = @"Text copied from notepad will appear after hitting the button";
    } else if (indexPath.row == 3) {
        // paste text content if exists
        UITextField* textField = [[UITextField alloc] initWithFrame:frame];
        UILabel* label = [[UILabel alloc] initWithFrame:frame];
        [label setBackgroundColor:nil];
        if (_pasteBoardText != nil) {
            [label setText:_pasteBoardText];
        } else {
            [label setText:@"No text presents in pasteboard"];
        }

        _cell.accessoryView = label;
        _cell.textLabel.text = @"Copy text from notepad and it will appear in the accesoryView";
    } else if (indexPath.row == 4) {
        // copy URL button
        _URLPasteButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        [_URLPasteButton setFrame:CGRectMake(50, 50, 200, 40)];
        [_URLPasteButton setTitle:@"Copy sample URL " forState:UIControlStateNormal];
        [_URLPasteButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_URLPasteButton addTarget:self action:@selector(onCopyURLToPasteboard) forControlEvents:UIControlEventTouchUpInside];
        _cell.accessoryView = _URLPasteButton;
        _cell.textLabel.text = @"Click to copy the URL http://www.example.com/ to pasteboard";
    } else if (indexPath.row == 5) {
        // paste URL button
        _URLPasteButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        [_URLPasteButton setFrame:CGRectMake(50, 50, 200, 40)];
        [_URLPasteButton setTitle:@"Paste URL" forState:UIControlStateNormal];
        [_URLPasteButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_URLPasteButton addTarget:self action:@selector(onPasteURL) forControlEvents:UIControlEventTouchUpInside];
        _cell.accessoryView = _URLPasteButton;
        _cell.textLabel.text = @"Click to paste URL in pasteboard if exists";
    } else if (indexPath.row == 6) {
        // Label to show pasted URL if exists
        UILabel* label = [[UILabel alloc] initWithFrame:frame];
        [label setBackgroundColor:nil];
        if (_pasteBoardURL != nil && _pasteBoardURL.absoluteString != nil) {
            [label setText:_pasteBoardURL.absoluteString];
        } else {
            [label setText:@"No clipboard URL present"];
        }
        _cell.accessoryView = label;
        _cell.textLabel.text = @"Copied URL will appear in the accesoryView";
    } else if (indexPath.row == 7) {
        // copy image button
        _textPasteButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        [_textPasteButton setFrame:CGRectMake(50, 50, 200, 40)];
        [_textPasteButton setTitle:@"Put Image to Pasteboard" forState:UIControlStateNormal];
        [_textPasteButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_textPasteButton addTarget:self action:@selector(onSetImageToPasteboard) forControlEvents:UIControlEventTouchUpInside];
        _cell.accessoryView = _textPasteButton;
        _cell.textLabel.text = @"An image will be put into Pasteboard after hitting the button. Then click the button 'Show Image'.";
    } else if (indexPath.row == 8) {
        // paste image button
        _screenShotButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        [_screenShotButton setFrame:CGRectMake(50, 50, 200, 40)];
        [_screenShotButton setTitle:@"Show Image" forState:UIControlStateNormal];
        [_screenShotButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_screenShotButton addTarget:self action:@selector(onPasteChangedScreenCapture) forControlEvents:UIControlEventTouchUpInside];
        _cell.accessoryView = _screenShotButton;
        _cell.textLabel.text = @"Take A screen shot CTRL + ALT + PrintScreen then click the button the image should appear";
    } else if (indexPath.row == 9) {
        // display area for pasted image from pastebard if exists
        _cell.textLabel.text = @"Image should appear in accessory view";
        if (_imageView != nil) {
            UIView* view = [[UIView alloc] initWithFrame:CGRectMake(50, 50, 200, 40)];
            [view addSubview:_imageView];
            _cell.accessoryView = view;
        } else {
            UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(c_originX, c_originY, c_width, c_height)];
            [label setBackgroundColor:nil];
            [label setText:@"Image does not present in clipboard"];
            _cell.accessoryView = label;
        }
    } else if (indexPath.row == 10) {
        // clear pasteboard button
        _cell.textLabel.text = @"Click to clear pasteboard, afterwards, try above paste text, url or image again";
        UIButton* clearPasteboardButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        [clearPasteboardButton setFrame:CGRectMake(50, 50, 200, 40)];
        [clearPasteboardButton setTitle:@"click to clear Paste board" forState:UIControlStateNormal];
        [clearPasteboardButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [clearPasteboardButton addTarget:self action:@selector(onClearPasteboard) forControlEvents:UIControlEventTouchUpInside];
        _cell.accessoryView = clearPasteboardButton;
    } else if (indexPath.row == 11) {
        // set items button
        _cell.textLabel.text = @"Setting an item which contains text/url/image, afterwards, try paste text/url/image using above button";
        UIButton* setPasteboardItemsButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        [setPasteboardItemsButton setFrame:CGRectMake(50, 50, 200, 40)];
        [setPasteboardItemsButton setTitle:@"click to Set items to Paste board" forState:UIControlStateNormal];
        [setPasteboardItemsButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [setPasteboardItemsButton addTarget:self action:@selector(onSetPasteboardItems) forControlEvents:UIControlEventTouchUpInside];
        _cell.accessoryView = setPasteboardItemsButton;
    } else if (indexPath.row == 12) {
        // check number of items button
        _cell.textLabel.text = @"Click to check how many items in pasteboard";
        UIButton* onGetNumberOfPasteboardItems = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        [onGetNumberOfPasteboardItems setFrame:CGRectMake(50, 50, 200, 40)];
        [onGetNumberOfPasteboardItems setTitle:@"get number of pasteboard item" forState:UIControlStateNormal];
        [onGetNumberOfPasteboardItems setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [onGetNumberOfPasteboardItems addTarget:self
                                         action:@selector(onGetNumberOfPasteboardItems)
                               forControlEvents:UIControlEventTouchUpInside];
        _cell.accessoryView = onGetNumberOfPasteboardItems;
    }
    if (indexPath.row == 13) {
        // label to show how many items that pasteboard has
        UILabel* label = [[UILabel alloc] initWithFrame:frame];
        [label setBackgroundColor:nil];
        [label setText:[NSString stringWithFormat:@"%d", numberOfPasteboardItems]];
        _cell.accessoryView = label;
        _cell.textLabel.text = @"Current number of items in pasteboard";
    }

    return _cell;
}

- (void)onCopyTextChanged:(UITextField*)textField {
    _pasteBoard.string = textField.text;
    _pasteTextLabel.text = _pasteBoard.string;
    [[self tableView] setNeedsLayout];
}

- (void)onPasteChanged {
    _pasteBoardText = _pasteBoard.string;
    [[self tableView] reloadData];
}

- (void)onSetImageToPasteboard {
    _pasteBoard.image = [UIImage imageNamed:@"photo9.jpg"];
}

- (void)onCopyURLToPasteboard {
    NSURL* urlData = [NSURL URLWithString:@"http://www.example.com/"];
    _pasteBoard.URL = urlData;
}

- (void)onPasteURL {
    _pasteBoardURL = _pasteBoard.URL;
    [[self tableView] reloadData];
}

- (void)onPasteChangedScreenCapture {
    _imageView = [[UIImageView alloc] initWithFrame:CGRectMake(c_originX, c_originY, 50, 50)];
    UIImage* image = _pasteBoard.image;
    if (image) {
        [_imageView setImage:_pasteBoard.image];
    } else {
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(c_originX, c_originY, c_width, c_height)];
        [label setBackgroundColor:nil];
        [label setText:@"No Image presents in pasteboard"];
        [_imageView addSubview:label];
    }

    [[self tableView] reloadData];
}

- (void)onSetPasteboardItems {
    NSData* pngData = UIImagePNGRepresentation([UIImage imageNamed:@"segment_check.png"]);
    NSDictionary* item = [NSDictionary dictionaryWithObjectsAndKeys:@"Just another copy text!",
                                                                    (NSString*)kUTTypeText,
                                                                    [NSURL URLWithString:@"http://www.msn.com"],
                                                                    (NSString*)kUTTypeURL,
                                                                    pngData,
                                                                    (NSString*)kUTTypePNG,
                                                                    nil];
    _pasteBoard.items = [NSArray arrayWithObject:item];
}

- (void)onClearPasteboard {
    _pasteBoard.items = nil;
    [[self tableView] reloadData];
}

- (void)onGetNumberOfPasteboardItems {
    numberOfPasteboardItems = _pasteBoard.numberOfItems;
    [[self tableView] reloadData];
}

@end
