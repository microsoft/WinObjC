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
//******************************************************************************

#import "LocalizationViewController.h"

static const CGFloat c_originX = 5;
static const CGFloat c_originY = 8;
static const CGFloat c_width = 260;
static const CGFloat c_height = 50;

@implementation LocalizationViewController {
@private
    UITableViewCell* _cell;
    UITextField* _copyTextField;
    UILabel* _pasteTextLabel;
}
- (void)viewDidLoad {
    [super viewDidLoad];
    self.tableView.allowsSelection = YES;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 2;
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
        _copyTextField = [[UITextField alloc] initWithFrame:frame];
        _copyTextField.textColor = [UIColor blackColor];
        _copyTextField.font = [UIFont systemFontOfSize:17.0];
        _copyTextField.text = @"Hello World";
        [_copyTextField addTarget:self action:@selector(onCopyTextChanged:) forControlEvents:UIControlEventEditingChanged];

        _cell.accessoryView = _copyTextField;
        _cell.textLabel.text = @"Enter Text";
    } else if (indexPath.row == 1) {
        _pasteTextLabel = [[UILabel alloc] initWithFrame:frame];
        _pasteTextLabel.textColor = [UIColor blackColor];
        _pasteTextLabel.font = [UIFont systemFontOfSize:17.0];
        _pasteTextLabel.textAlignment = NSTextAlignmentLeft;
        _pasteTextLabel.text = NSLocalizedString(_copyTextField.text, nil);
        _cell.accessoryView = _pasteTextLabel;
        _cell.textLabel.text = @"Localized Text";
    }
    return _cell;
}

- (void)viewDidLayoutSubviews {
    [(UIScrollView*)self.view setContentSize:[self.view.subviews[0] bounds].size];
}

- (void)onCopyTextChanged:(UITextField*)textField {
    _pasteTextLabel.text = NSLocalizedString(textField.text, nil);
    [[self tableView] setNeedsLayout];
}

@end
