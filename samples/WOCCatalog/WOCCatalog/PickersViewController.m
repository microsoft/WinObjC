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

@implementation PickersViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.autoresizesSubviews = TRUE;
    self.view.backgroundColor = [UIColor whiteColor];
    [self tableView].allowsSelection = NO;

    self.title = @"Pickers";
    
    // PICKER VIEW
    
    self.datePickerView = [[UIDatePicker alloc] initWithFrame:CGRectZero];
    self.datePickerView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleTopMargin;
    self.datePickerView.datePickerMode = UIDatePickerModeDate;
    
    // note we are using CGRectZero for the dimensions of our picker view,
    // this is because picker views have a built in optimum size,
    // you just need to set the correct origin in your view.
    //
    // position the picker at the bottom
    CGSize pickerSize = [self.view sizeThatFits:CGSizeZero];
    self.datePickerView.frame = [self calcFrameForPicker:pickerSize];
    
    self.datePickerView.hidden = YES;
    [self.view addSubview: self.datePickerView];
}


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    return 1;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 50.0;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    }
    
    if (indexPath.row == 0) {
        
        NSArray *segmentTextContent = [NSArray arrayWithObjects: @"date", @"time", nil];
        UISegmentedControl *segmentedControl = [[UISegmentedControl alloc] initWithItems:segmentTextContent];
        CGRect frame = CGRectMake( 5.0, 5.0, 200, 40.0);
        segmentedControl.frame = frame;
        segmentedControl.tintColor = [UIColor blackColor];
        segmentedControl.segmentedControlStyle = UISegmentedControlStyleBar;
        
        [segmentedControl addTarget:self
                             action:@selector(action:)
                   forControlEvents:UIControlEventValueChanged];
        
        [cell addSubview: segmentedControl];
        
    } else if (indexPath.row == 1) {
        // UIDatePicker
        
        self.datePickerView = [[UIDatePicker alloc] initWithFrame:CGRectZero];
        self.datePickerView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleTopMargin;
        self.datePickerView.datePickerMode = UIDatePickerModeDate;
        
        // note we are using CGRectZero for the dimensions of our picker view,
        // this is because picker views have a built in optimum size,
        // you just need to set the correct origin in your view.
        //
        // position the picker at the bottom
        CGSize pickerSize = [cell sizeThatFits:CGSizeZero];
        self.datePickerView.frame = [self calcFrameForPicker:pickerSize];
        
        self.datePickerView.hidden = YES;
        //[self.view addSubview:self.datePickerView];
        [cell addSubview: self.datePickerView];
        
    } else if (indexPath.row == 2) {
        
    }
    else if (indexPath.row == 3) {
        
    }
    
    return cell;
}

- (void)action:(id)sender
{
    switch (((UISegmentedControl*) sender).selectedSegmentIndex)
    {
        case 0:
            self.datePickerView.datePickerMode = UIDatePickerModeDate;
            self.datePickerView.hidden = NO;
            break;
            
        case 1:
            self.datePickerView.datePickerMode = UIDatePickerModeTime;
            self.datePickerView.hidden = NO;
            break;
            
        case 2:
            break;
            
            default:
            break;
    }
}

- (CGRect)calcFrameForPicker:(CGSize)size
{
    CGRect screenRect = [[UIScreen mainScreen] applicationFrame];
    CGRect pickerRect = CGRectMake( 0.0,
                                   100.0,
                                   size.width,
                                   size.height-100.0);
    return pickerRect;
}

-(void) viewWillLayoutSubviews
{
    CGSize pickerSize = [self.view sizeThatFits:CGSizeZero];
    self.datePickerView.frame = [self calcFrameForPicker:pickerSize];
}

@end

