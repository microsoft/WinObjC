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

#import "UIViewViewController.h"
#import <UIKit/UIView.h>

@interface UIViewHitTest : UIView
@property (nonatomic) BOOL shouldRespondToTouch;
@property (nonatomic) UILabel* statusLabel;
@end

@implementation UIViewHitTest {
    BOOL _shouldRespondToTouch;
};

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        // Default to true
        _shouldRespondToTouch = true;
    }

    return self;
}

- (void)touchesBegan:(NSSet*)touchSet withEvent:(UIEvent*)event {
    _statusLabel.text = @"Touches Began";

    if (!_shouldRespondToTouch) {
        assert(false); // TODO: Fail test instead of asserting when we have a mechanism to do so.
        _statusLabel.text = @"FAILED: Unexpected touch received!";
    }
}

-(void)touchesMoved:(NSSet*)touchSet withEvent:(UIEvent*)event {
    _statusLabel.text = @"Touches Moved";

    if (!_shouldRespondToTouch) {
        assert(false); // TODO: Fail test instead of asserting when we have a mechanism to do so.
        _statusLabel.text = @"FAILED: Unexpected touch received!";
    }
}

-(void)touchesEnded:(NSSet*)touchSet withEvent:(UIEvent*)event {
    _statusLabel.text = @"Touches Ended";

    if (!_shouldRespondToTouch) {
        assert(false); // TODO: Fail test instead of asserting when we have a mechanism to do so.
        _statusLabel.text = @"FAILED: Unexpected touch received!";
    }
}

- (BOOL)shouldRespondToTouch {
    return _shouldRespondToTouch;
}

- (void)setShouldRespondToTouch:(BOOL)shouldRespond {
    _shouldRespondToTouch = shouldRespond;
}

@end

@implementation UIViewViewController {
    CGRect _labelFrame;
    CGRect _containerViewFrame;
    CGRect _testViewFrame;
    CGRect _statusLabelViewFrame;
    float _cellHeight;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"UIView";
    [self tableView].allowsSelection = NO;

    static const float margin = 5.0;

    CGRect screenBounds = [[UIScreen mainScreen] bounds];
    _labelFrame = CGRectMake(margin, margin, screenBounds.size.width, 50);
    _containerViewFrame = CGRectMake(margin, margin + _labelFrame.size.height, 300, 100);
    _testViewFrame = CGRectMake(margin, margin, _containerViewFrame.size.width - (margin * 2.0), _containerViewFrame.size.height - (margin * 2.0));
    _statusLabelViewFrame = CGRectMake(margin * 2.0, margin, _testViewFrame.size.width - (margin * 2.0), 40);
    _cellHeight = _labelFrame.size.height + _containerViewFrame.size.height + (margin * 2.0);
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 6;
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    return _cellHeight;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    // Grab a cell
    UITableViewCell* cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];

    // Add the instruction label
    UILabel* label = [[UILabel alloc] initWithFrame:_labelFrame];
    // Using adjustsFontSizeToFitWidth so the instruction labels show up on phone
    // The need for adjustsFontSizeToFitWidth is tracked by #1690.
    // The fact that adjustsFontSizeToFitWidth functions incorrectly on desktop tracked by #1689.
    label.adjustsFontSizeToFitWidth = YES;
    [cell.contentView addSubview:label];

    // Add a container view to deliniate bounds of test view
    UIView* containerView = [[UIView alloc] initWithFrame:_containerViewFrame];
    containerView.backgroundColor = [UIColor grayColor];
    [cell.contentView addSubview : containerView];

    // Add the test view
    UIViewHitTest* testView = [[UIViewHitTest alloc] initWithFrame:_testViewFrame];
    testView.backgroundColor = [UIColor yellowColor];
    [containerView addSubview:testView];

    // Add the status label
    UILabel* statusLabel = [[UILabel alloc] initWithFrame:_statusLabelViewFrame];
    statusLabel.text = @"No Touch Input Detected";
    statusLabel.userInteractionEnabled = NO;
    [containerView addSubview:statusLabel];

    // Give the testView a label to report status
    testView.statusLabel = statusLabel;

    if (indexPath.row == 0) {
        // Setup test
        label.text = @"Alpha=0.0; yellow background SHOULD NOT be visible and view SHOULD NOT respond to touch.";
        testView.alpha = 0.0;
        testView.shouldRespondToTouch = NO;
    } else if (indexPath.row == 1) {
        // Setup test
        label.text = @"Yellow background SHOULD be visible and view SHOULD respond to touch.";
    } else if (indexPath.row == 2) {
        // Setup test
        label.text = @"Clear background SHOULD NOT be visible, but view SHOULD respond to touch.";
        testView.backgroundColor = [UIColor clearColor];
    } else if (indexPath.row == 3) {
        // Setup test
        label.text = @"UserInteractionEnabled=NO; yellow background SHOULD be visible but view SHOULD NOT respond to touch.";
        testView.userInteractionEnabled = NO;
        testView.shouldRespondToTouch = NO;
    }  else if (indexPath.row == 4) {
        // Setup test
        label.text = @"Hidden=YES; yellow background SHOULD NOT be visible and view SHOULD NOT respond to touch.";
        testView.hidden = YES;
    } else if (indexPath.row == 5) {
        // Setup test
        label.text = @"nil background SHOULD NOT be visible, but view SHOULD respond to touch.";
        testView.backgroundColor = nil;
    }

    return cell;
}

@end
