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

#import "MiscellaneousViewController.h"
#import <UIKit/UIButton.h>
#import <UIKit/UILabel.h>

@implementation MiscellaneousViewController {
    int _touchUpInsideCount;
    UILabel* _labelTouchUpInside;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"Miscellaneous Views";
    self.view.backgroundColor = [UIColor whiteColor];

    _touchUpInsideCount = 0;

    UILabel* title = [[UILabel alloc] initWithFrame:CGRectMake(10, 10, 930, 30)];
    title.numberOfLines = 2;
    title.backgroundColor = [UIColor grayColor];
    title.text =
        @"Use this View Controller to test stuffs like Pan Gesture on the UIElement which cannot be done in a UITableViewController";

    _labelTouchUpInside = [[UILabel alloc] initWithFrame:CGRectMake(10, 50, 600, 75)];
    _labelTouchUpInside.numberOfLines = 3;
    _labelTouchUpInside.text = [NSString
        stringWithFormat:
            @"Pan over the button to see if it receives click event\nButton with event: UIControlEventTouchUpInside,\ntouchup count = %d",
            _touchUpInsideCount];

    UIButton* button = [[UIButton alloc] initWithFrame:CGRectMake(10, 125, 200, 50)];
    button.backgroundColor = [UIColor grayColor];
    [button setTitle:@"Button Pan Test" forState:UIControlStateNormal];
    [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [button addTarget:self action:@selector(_buttonTouchUpInside:) forControlEvents:UIControlEventTouchUpInside];

    [self.view addSubview:title];
    [self.view addSubview:_labelTouchUpInside];
    [self.view addSubview:button];
}

- (void)_buttonTouchUpInside:(UIButton*)button {
    _touchUpInsideCount++;
    _labelTouchUpInside.text = [NSString
        stringWithFormat:
            @"Pan over the button to see if it receives click event\nButton with event: UIControlEventTouchUpInside,\ntouchup count = %d",
            _touchUpInsideCount];
}

@end