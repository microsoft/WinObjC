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

#import "ButtonsViewController.h"

@implementation ButtonsViewController

- (id)init {
    self = [super init];

    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self.title = @"Buttons";

    [self tableView].allowsSelection = NO;
    self.menuItems = [NSArray array];
    self.menuItems =
        [NSArray arrayWithObjects:self.grayButton, self.imageButton, self.roundedButtonType, self.detailDisclosureButtonType, nil];
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 2; //[self.menuItems count];
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
        UIButton* button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        button.frame = CGRectMake(5.0f, 5.0f, 200.0f, cell.frame.size.height - 5.0f);
        button.layer.cornerRadius = 5.0f;
        [button setTitle:@"Simple Button" forState:UIControlStateNormal];
        [cell addSubview:button];
    } else if (indexPath.row == 1) {
        UIImage* buttonBackground = [UIImage imageNamed:@"whiteButton.png"];
        UIImage* buttonBackgroundPressed = [UIImage imageNamed:@"blueButton.png"];
        UIButton* button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        button.frame = CGRectMake(5.0f, 5.0f, 200.0f, cell.frame.size.height - 5.0f);

        UIImage* newImage = [buttonBackground stretchableImageWithLeftCapWidth:12.0 topCapHeight:0.0];
        [button setBackgroundImage:newImage forState:UIControlStateNormal];

        UIImage* newPressedImage = [buttonBackgroundPressed stretchableImageWithLeftCapWidth:12.0 topCapHeight:0.0];
        [button setBackgroundImage:newPressedImage forState:UIControlStateHighlighted];

        [button setTitle:@"Image Button" forState:UIControlStateNormal];
        [button setTintColor:[UIColor whiteColor]];
        [cell addSubview:button];
    }

    return cell;
}

@end
