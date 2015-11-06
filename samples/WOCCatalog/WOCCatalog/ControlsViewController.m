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

#import "ControlsViewController.h"
#import "SingleImageViewController.h"

#define UIPOPOVERCONTROL_ROW 4

@implementation ControlsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 5;
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
        // switch
        CGRect frame = CGRectMake(5.0, 12.0, 94.0, 27.0);
        UISwitch* switchCtrl = [[UISwitch alloc] initWithFrame:frame];

        // in case the parent view draws with a custom color or gradient, use a transparent color
        switchCtrl.backgroundColor = [UIColor clearColor];

        cell.accessoryView = switchCtrl;
        cell.textLabel.text = @"UISwitch";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    } else if (indexPath.row == 1) {
        // slider
        CGRect frame = CGRectMake(5.0, 12.0, 120.0, 8.0);
        UISlider* sliderCtl = [[UISlider alloc] initWithFrame:frame];

        // in case the parent view draws with a custom color or gradient, use a transparent color
        sliderCtl.backgroundColor = [UIColor clearColor];

        sliderCtl.minimumValue = 0.0;
        sliderCtl.maximumValue = 100.0;
        sliderCtl.continuous = YES;
        sliderCtl.value = 50.0;

        // Add an accessibility label that describes the slider.
        [sliderCtl setAccessibilityLabel:@"StandardSlider"];

        cell.accessoryView = sliderCtl;
        cell.textLabel.text = @"UISlider";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    } else if (indexPath.row == 2) {
        // activity indicator
        CGRect frame = CGRectMake(5.0, 12.0, 40.0, 40.0);

        UIActivityIndicatorView* progressInd =
            [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
        // self.progressIndSavedColor = progressInd.color;
        progressInd.frame = frame;
        [progressInd startAnimating];
        progressInd.activityIndicatorViewStyle = UIActivityIndicatorViewStyleGray;
        [progressInd sizeToFit];

        cell.accessoryView = progressInd;
        cell.textLabel.text = @"UIActivityIndicator";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    } else if (indexPath.row == 3) {
        // progress view

        CGRect frame = CGRectMake(5.0, 20.0, 160, 24);
        UIProgressView* progressBar = [[UIProgressView alloc] initWithFrame:frame];
        progressBar.progressViewStyle = UIProgressViewStyleDefault;
        progressBar.progress = 0.5;

        cell.accessoryView = progressBar;
        cell.textLabel.text = @"UIProgressView";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;

    } else if (indexPath.row == UIPOPOVERCONTROL_ROW) {
        // UIPopoverPresentationController

        cell.textLabel.text = @"UIPopupPresentationController (press me)";
        cell.selectionStyle = UITableViewCellSelectionStyleBlue;
    }

    return cell;
}

- (NSIndexPath*)tableView:(UITableView*)tableView willSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    if (indexPath.row == UIPOPOVERCONTROL_ROW) {
        return indexPath;
    }

    return nil;
}

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    if (indexPath.row == UIPOPOVERCONTROL_ROW) {
        // Note: presenting a UIViewController with the UIModalPresentationStyle of Popover does not yet present the view controller
        // as a popover. This work will need to be completed as part of UIPopoverController and UIPresentation controller work.
        SingleImageViewController* imvc = [[SingleImageViewController alloc] initWithImage:[UIImage imageNamed:@"photo1.jpg"]];

        assert(imvc.popoverPresentationController == nil);

        imvc.modalPresentationStyle = UIModalPresentationPopover;
        [self presentViewController:imvc animated:YES completion:nil];
        assert(imvc.popoverPresentationController != nil);
    }
}

@end
