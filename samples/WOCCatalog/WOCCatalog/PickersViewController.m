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

#import "PickersViewController.h"

static const int TAG_SUBVIEW_SEGEMENTCONTROL = 1;

@implementation PickersViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.autoresizesSubviews = TRUE;
    self.view.backgroundColor = [UIColor whiteColor];
    self.tableView.separatorColor = [UIColor clearColor];
    self.tableView.allowsSelection = NO;
    self.tableView.scrollEnabled = NO;

    self.title = @"Pickers";

    // PICKER VIEW
    self.datePickerView = [[UIDatePicker alloc] init];
    self.datePickerView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleTopMargin;
    self.datePickerView.datePickerMode = UIDatePickerModeDate;
    self.datePickerView.hidden = YES;
    [self.view addSubview:self.datePickerView];
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 1;
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    return 50.0;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    } else {
        // before reuse, check if cell contains any tagged subview, if so, remove them first
        UIView* subView = (UIView*)[cell viewWithTag:TAG_SUBVIEW_SEGEMENTCONTROL];
        [subView removeFromSuperview];
    }

    if (indexPath.row == 0) {
        NSArray* segmentTextContent = [NSArray arrayWithObjects:@"date", @"time", nil];
        UISegmentedControl* segmentedControl = [[UISegmentedControl alloc] initWithItems:segmentTextContent];
        CGRect frame = CGRectMake(5.0, 5.0, 200, 40.0);
        segmentedControl.frame = frame;
        segmentedControl.tintColor = [UIColor blackColor];
        segmentedControl.segmentedControlStyle = UISegmentedControlStyleBar;

        [segmentedControl addTarget:self action:@selector(action:) forControlEvents:UIControlEventValueChanged];

        segmentedControl.tag = TAG_SUBVIEW_SEGEMENTCONTROL;
        [cell addSubview:segmentedControl];
    }

    return cell;
}

- (void)action:(id)sender {
    switch (((UISegmentedControl*)sender).selectedSegmentIndex) {
        case 0:
            self.datePickerView.datePickerMode = UIDatePickerModeDate;
            self.datePickerView.hidden = NO;
            break;

        case 1:
            self.datePickerView.datePickerMode = UIDatePickerModeTime;
            self.datePickerView.hidden = NO;
            break;

        default:
            break;
    }
}

- (CGRect)calcFrameForPicker {
    CGRect tableRect = self.view.bounds;
    CGRect pickerRect = CGRectMake(0.0, 50.0, tableRect.size.width, tableRect.size.height - 50.0);

    return pickerRect;
}

- (void)viewWillLayoutSubviews {
    self.datePickerView.frame = [self calcFrameForPicker];
}

@end
