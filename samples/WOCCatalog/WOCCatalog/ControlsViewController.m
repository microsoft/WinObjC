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

static const int MODALFORMSHEET_ROW = 4;

@interface ControlsViewController ()

@property (nonatomic, strong) UIButton* leftPopoverButton;
@property (nonatomic, strong) UIButton* rightPopoverButton;
@property (nonatomic) BOOL resizeModal;

@end

@implementation ControlsViewController {
    UIActivityIndicatorView* _progressInd;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    UIBarButtonItem* popoverButton = [[UIBarButtonItem alloc] initWithTitle:@"Popover"
                                                                      style:UIBarButtonItemStyleBordered
                                                                     target:self
                                                                     action:@selector(pressedPopoverBarButton:)];
    self.navigationItem.rightBarButtonItem = popoverButton;

    CGRect tableFrame = self.view.bounds;
    tableFrame.size.height -= 100;
    tableFrame.origin.y += 100;
    UITableView* tableView = [[UITableView alloc] initWithFrame:tableFrame];
    [self.view addSubview:tableView];
    tableView.delegate = self;
    tableView.dataSource = self;

    const CGFloat buttonHeight = 50;
    const CGFloat buttonWidth = 175;
    const CGFloat originOffset = 25;

    self.leftPopoverButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    self.leftPopoverButton.titleLabel.font = [UIFont systemFontOfSize:11];
    [self.leftPopoverButton setTitle:@"Popover (left arrow direction)" forState:UIControlStateNormal];
    [self.leftPopoverButton setFrame:CGRectMake(originOffset, originOffset, buttonWidth, buttonHeight)];
    [self.leftPopoverButton addTarget:self action:@selector(pressedPopoverButton:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.leftPopoverButton];

    self.rightPopoverButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    self.rightPopoverButton.titleLabel.font = [UIFont systemFontOfSize:11];
    [self.rightPopoverButton setTitle:@"Popover (up arrow direction)" forState:UIControlStateNormal];
    [self.rightPopoverButton setFrame:CGRectMake(self.view.bounds.size.width - originOffset - buttonWidth, originOffset, buttonWidth, buttonHeight)];
    [self.rightPopoverButton addTarget:self action:@selector(pressedPopoverButton:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.rightPopoverButton];

    UILabel* popoverDisclaimerLabel = [[UILabel alloc] initWithFrame:
        CGRectMake(self.leftPopoverButton.frame.origin.x + self.leftPopoverButton.frame.size.width + originOffset,
                   self.leftPopoverButton.frame.origin.y,
                   self.rightPopoverButton.frame.origin.x - self.leftPopoverButton.frame.origin.x - self.leftPopoverButton.frame.size.width - originOffset * 2,
                   self.leftPopoverButton.frame.size.height)];
    popoverDisclaimerLabel.text = @"Tablet-style popovers require WOCOperationModeTablet to be enabled (see DisplayModeViewController).";
    popoverDisclaimerLabel.textAlignment = NSTextAlignmentCenter;
    [self.view addSubview:popoverDisclaimerLabel];
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:(BOOL)animated];

    // UIModalPresentationFormSheet shouldn't cover parent with tablet.
    assert(!([[self presentedViewController] modalPresentationStyle] == UIModalPresentationFormSheet &&
             [[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad));
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
        [switchCtrl addTarget:self action:@selector(setUIActivityIndicatorView) forControlEvents:UIControlEventValueChanged];
        switchCtrl.on = TRUE;

        cell.accessoryView = switchCtrl;
        cell.textLabel.text = @"UISwitch";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    } else if (indexPath.row == 1) {
        // slider
        CGRect frame = CGRectMake(5.0, 12.0, 120.0, 38.0);
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
        _progressInd = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
        [_progressInd setColor:[UIColor brownColor]];
        [_progressInd startAnimating];
        [_progressInd sizeToFit];

        cell.accessoryView = _progressInd;
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
    if (indexPath.row == MODALFORMSHEET_ROW) {
        return indexPath;
    }

    return nil;
}

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    if (indexPath.row == MODALFORMSHEET_ROW) {
        UIViewController* viewController = [[PopoverViewController alloc] initWithImage:[UIImage imageNamed:@"photo1.jpg"]];
        viewController.modalPresentationStyle = UIModalPresentationFormSheet;

        if (self.resizeModal) {
            viewController.preferredContentSize = CGSizeMake(200, 200);
        }

        [self presentViewController:viewController
                           animated:YES
                         completion:^{
                             assert(!([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad && self.view.hidden));
                         }];
    }
}

- (void)toggleResizeModal {
    self.resizeModal = !self.resizeModal;
}

- (void)setUIActivityIndicatorView {
    if (_progressInd.isAnimating == TRUE) {
        [_progressInd stopAnimating];
    } else {
        [_progressInd startAnimating];
    }
}

- (void)pressedPopoverButton:(UIButton*)sender {
    PopoverViewController* viewController = [[PopoverViewController alloc] initWithImage:[UIImage imageNamed:@"photo1.jpg"]];
    assert(viewController.popoverPresentationController == nil);

    viewController.modalPresentationStyle = UIModalPresentationPopover;
    viewController.preferredContentSize = CGSizeMake(500, 500);

    [self presentViewController:viewController
                       animated:YES
                     completion:^{
                         assert(viewController.numViewEventsFired == 3);
                     }];

    assert(viewController.popoverPresentationController != nil);

    UIPopoverPresentationController* presentationController = [viewController popoverPresentationController];
    presentationController.sourceView = sender;
    presentationController.sourceRect = sender.frame;

    // test different popover arrow directions
    if (sender == self.leftPopoverButton) {
        presentationController.permittedArrowDirections = UIPopoverArrowDirectionLeft;
    } else {
        presentationController.permittedArrowDirections = UIPopoverArrowDirectionUp;
    }
}

- (void)pressedPopoverBarButton:(UIBarButtonItem*)sender {
    PopoverViewController* viewController = [[PopoverViewController alloc] initWithImage:[UIImage imageNamed:@"photo1.jpg"]];
    assert(viewController.popoverPresentationController == nil);

    viewController.modalPresentationStyle = UIModalPresentationPopover;
    viewController.preferredContentSize = CGSizeMake(300, 300);

    [self presentViewController:viewController
                       animated:YES
                     completion:^{
                         assert(viewController.numViewEventsFired == 3);
                     }];

    assert(viewController.popoverPresentationController != nil);

    UIPopoverPresentationController* presentationController = [viewController popoverPresentationController];
    presentationController.barButtonItem = sender;
}

@end
