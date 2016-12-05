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

- (void)touchDown:(id)sender {
    UIButton* button = (UIButton*)sender;

    [button setTitle:@"Touch Down" forState:UIControlStateNormal];
}

- (void)touchUpInside:(id)sender {
    UIButton* button = (UIButton*)sender;

    [button setTitle:@"Touch Up Inside" forState:UIControlStateNormal];
}

- (void)touchUpOutside:(id)sender {
    UIButton* button = (UIButton*)sender;

    [button setTitle:@"Touch Up Outside" forState:UIControlStateNormal];
}

- (void)touchDragInside:(id)sender {
    UIButton* button = (UIButton*)sender;

    [button setTitle:@"Drag Inside" forState:UIControlStateNormal];
}

- (void)touchDragOutside:(id)sender {
    UIButton* button = (UIButton*)sender;

    [button setTitle:@"Drag Outside" forState:UIControlStateNormal];
}

// Since the following will get clobbered by other drag events, just output to the debug window.
- (void)touchDragEnter:(id)sender {
    NSLog(@"Drag Enter");
}

- (void)touchDragExit:(id)sender {
    NSLog(@"Drag Exit");
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
    return 3; //[self.menuItems count];
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
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];

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
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [button setTintColor:[UIColor whiteColor]];
        [cell addSubview:button];
    } else if (indexPath.row == 2) {
        UIButton* button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        button.frame = CGRectMake(5.0f, 5.0f, 200.0f, cell.frame.size.height - 5.0f);
        
        [button setTitle:@"UIControl Events" forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];

        [button addTarget:self action:@selector(touchDown:) forControlEvents:UIControlEventTouchDown];
        [button addTarget:self action:@selector(touchUpInside:) forControlEvents:UIControlEventTouchUpInside];
        [button addTarget:self action:@selector(touchUpOutside:) forControlEvents:UIControlEventTouchUpOutside];
        [button addTarget:self action:@selector(touchDragInside:) forControlEvents:UIControlEventTouchDragInside];
        [button addTarget:self action:@selector(touchDragOutside:) forControlEvents:UIControlEventTouchDragOutside];
        [button addTarget:self action:@selector(touchDragEnter:) forControlEvents:UIControlEventTouchDragEnter];
        [button addTarget:self action:@selector(touchDragExit:) forControlEvents:UIControlEventTouchDragExit];

        [cell addSubview:button];
    }

    return cell;
}

@end
