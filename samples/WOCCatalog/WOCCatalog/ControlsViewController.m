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
#import "PopoverViewController.h"

static const int POPOVERCONTROL_ROW = 4;
static const int MODALFORMSHEET_ROW = 5;

@interface ControlsViewController ()

@property (nonatomic) BOOL resizeModal;

@end

@implementation ControlsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:(BOOL)animated];

    // UIModalPresentationFormSheet shouldn't cover parent with tablet.
    assert(!([[self presentedViewController] modalPresentationStyle] == UIModalPresentationFormSheet && [[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad));
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 6;
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

    } else if (indexPath.row == POPOVERCONTROL_ROW) {
        // UIPopoverPresentationController

        cell.textLabel.text = @"UIPopupPresentationController (press to launch)";
        cell.selectionStyle = UITableViewCellSelectionStyleBlue;
    } else if (indexPath.row == MODALFORMSHEET_ROW) {
        // form sheet modal

        UITableViewCell* subtitleCell = [tableView dequeueReusableCellWithIdentifier:@"MenuSubtitleCell"];
        if (!subtitleCell) {
            subtitleCell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"MenuSubtitleCell"];
        }

        subtitleCell.textLabel.text = @"UIModalPresentationFormSheet (press to launch)";
        subtitleCell.detailTextLabel.text = @"Toggle switch to resize (tablet only)";
        subtitleCell.selectionStyle = UITableViewCellSelectionStyleBlue;
        UISwitch* resizeSwitch = [[UISwitch alloc] init];
        resizeSwitch.on = self.resizeModal;
        [resizeSwitch addTarget:self action:@selector(toggleResizeModal) forControlEvents:UIControlEventValueChanged];
        subtitleCell.accessoryView = resizeSwitch;

        return subtitleCell;
    }

    return cell;
}

- (NSIndexPath*)tableView:(UITableView*)tableView willSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    if (indexPath.row == POPOVERCONTROL_ROW || indexPath.row == MODALFORMSHEET_ROW) {
        return indexPath;
    }

    return nil;
}

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    if (indexPath.row == POPOVERCONTROL_ROW) {
        // Note: presenting a UIViewController with the UIModalPresentationStyle of Popover does not yet present the view controller
        // as a popover. UIPopoverController has been depricated in ios9.0.
        // This work will need to be completed as part of UIPopoverPresentationController work.
        PopoverViewController* popover = [[PopoverViewController alloc] initWithImage:[UIImage imageNamed:@"photo1.jpg"]];

        assert(popover.popoverPresentationController == nil);

        popover.modalPresentationStyle = UIModalPresentationPopover;
        // Present the view controller using the popover style.
        [self presentViewController:popover animated:YES completion:nil];

        assert(popover.popoverPresentationController != nil);
        // Get the popover presentation controller and configure it.
        UIPopoverPresentationController* presentationController = [popover popoverPresentationController];
        presentationController.permittedArrowDirections = UIPopoverArrowDirectionLeft | UIPopoverArrowDirectionRight;
        presentationController.sourceView = self.view;
        presentationController.sourceRect = CGRectMake(100, 100, 100, 100);
    } else if (indexPath.row == MODALFORMSHEET_ROW) {
        UIViewController* viewController = [[PopoverViewController alloc] initWithImage:[UIImage imageNamed:@"photo1.jpg"]];
        viewController.modalPresentationStyle = UIModalPresentationFormSheet;

        if (self.resizeModal) {
            viewController.preferredContentSize = CGSizeMake(200, 200);
        }

        [self presentViewController:viewController animated:YES completion:^{
            assert(!([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad && self.view.hidden));
        }];
    }
}

- (void)toggleResizeModal {
    self.resizeModal = !self.resizeModal;
}

@end
