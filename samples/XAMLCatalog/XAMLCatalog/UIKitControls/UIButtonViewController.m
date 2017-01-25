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

#import "UIButtonViewController.h"
#import <UIKit/UIButton.h>

@interface UIButtonDerived : UIButton
@end

@implementation UIButtonDerived

- (void)touchesBegan:(NSSet*)touchSet withEvent:(UIEvent*)event {
    //[super touchesBegan:touchSet withEvent:event];
}

@end

@implementation UIButtonViewController {
    UILabel* _labelTouchUpInside;

    float _labelHeight;
    float _labelWidth;

    float _defaultHeight;
    float _defaultWidth;

    float _marginLeft;
    float _marginTop;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self.title = @"UIButton";
    [self tableView].allowsSelection = NO;

    _defaultHeight = 50;
    _defaultWidth = 200;
    _marginLeft = 20.0f;
    _marginTop = 5.0f;

    // label sizes
    _labelHeight = 40;
    _labelWidth = 600;
}

+ (UIImage*)scaledTestImage {
    static UIImage* image;
    if (!image) {
        image = [UIImage imageWithCGImage:[UIImage imageNamed:@"button_image.PNG"].CGImage scale:3.0f orientation:UIImageOrientationUp];
    }
    return image;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 15;
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    return _defaultHeight + _labelHeight + 20;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    UITableViewCell* cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];

    if (indexPath.row == 0) {
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop, _labelWidth, _labelHeight)];
        label.text = @"UIButton, no backgroundColor";

        UIButton* button =
            [[UIButton alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop + _labelHeight, _defaultWidth, _defaultHeight)];
        [button setTitle:@"Button" forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];

        [cell addSubview:label];
        [cell addSubview:button];
    } else if (indexPath.row == 1) {
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop, _labelWidth, _labelHeight)];
        label.text = @"UIButton, backgroundcolor = grayColor";

        UIButton* button =
            [[UIButton alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop + _labelHeight, _defaultWidth, _defaultHeight)];
        [button setTitle:@"Button" forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        button.backgroundColor = [UIColor grayColor];

        [cell addSubview:label];
        [cell addSubview:button];
    } else if (indexPath.row == 2) {
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop, _labelWidth, _labelHeight)];
        label.text = @"Button with state : UIControlStateDisabled";

        UIButton* button =
            [[UIButton alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop + _labelHeight, _defaultWidth, _defaultHeight)];
        button.enabled = false;
        button.backgroundColor = [UIColor grayColor];
        [button setTitle:@"Button Disabled" forState:UIControlStateDisabled];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];

        [cell addSubview:button];
        [cell addSubview:label];
    } else if (indexPath.row == 3) {
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop, _labelWidth, _labelHeight)];
        label.text = @"UIButton with overflow text";

        UIButton* button =
            [[UIButton alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop + _labelHeight, _defaultWidth, _defaultHeight)];
        // NOTE : The text gets clipped by the textblock itself, we dont need to do the trimming .
        [button setTitle:@"This text is too long and will overflow and get clipped" forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        button.backgroundColor = [UIColor grayColor];

        [cell addSubview:label];
        [cell addSubview:button];
    } else if (indexPath.row == 4) {
        _labelTouchUpInside = [[UILabel alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop, _labelWidth, _labelHeight)];
        _labelTouchUpInside.text =
            [NSString stringWithFormat:@"Test UIControl events by touching, dragging, etc."];

        UIButton* button = [UIButton buttonWithType : UIButtonTypeRoundedRect];
        button.frame = CGRectMake(_marginLeft, _marginTop + _labelHeight, _defaultWidth, _defaultHeight);

        [button setTitle:@"UIControl Events" forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blueColor] forState:UIControlStateHighlighted];

        [button addTarget:self action:@selector(_touchDown:) forControlEvents:UIControlEventTouchDown];
        [button addTarget:self action:@selector(_touchUpInside:) forControlEvents:UIControlEventTouchUpInside];
        [button addTarget:self action:@selector(_touchUpOutside:) forControlEvents:UIControlEventTouchUpOutside];
        [button addTarget:self action:@selector(_touchDragInside:) forControlEvents:UIControlEventTouchDragInside];
        [button addTarget:self action:@selector(_touchDragOutside:) forControlEvents:UIControlEventTouchDragOutside];
        [button addTarget:self action:@selector(_touchDragEnter:) forControlEvents:UIControlEventTouchDragEnter];
        [button addTarget:self action:@selector(_touchDragExit:) forControlEvents:UIControlEventTouchDragExit];

        button.backgroundColor = [UIColor grayColor];

        [cell addSubview:button];
        [cell addSubview:_labelTouchUpInside];
    } else if (indexPath.row == 5) {
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop, _labelWidth, _labelHeight)];
        label.text = @"UIButton, Pressed Title in Blue color";

        UIButton* button =
            [[UIButton alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop + _labelHeight, _defaultWidth, _defaultHeight)];
        [button setTitle:@"Button Normal" forState:UIControlStateNormal];
        [button setTitle:@"Pressed" forState:UIControlStateHighlighted];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blueColor] forState:UIControlStateHighlighted];

        button.backgroundColor = [UIColor grayColor];

        [cell addSubview:label];
        [cell addSubview:button];
    } else if (indexPath.row == 6) {
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop, _labelWidth, _labelHeight)];
        label.text = @"Derived UIButton, not supporting button press";

        UIButtonDerived* button =
            [[UIButtonDerived alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop + _labelHeight, _defaultWidth, _defaultHeight)];
        [button setTitle:@"Button" forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        button.backgroundColor = [UIColor grayColor];

        [cell addSubview:label];
        [cell addSubview:button];
    } else if (indexPath.row == 7) {
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop, _labelWidth, _labelHeight)];
        label.text = @"UIButton, with backgroundImage, state = Disabled";

        UIButton* button =
            [[UIButton alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop + _labelHeight, _defaultWidth, _defaultHeight)];
        [button setTitle:@"Button Disabled" forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [button setBackgroundImage:[UIImage imageNamed:@"blue_background.jpg"] forState:UIControlStateNormal];
        button.enabled = false;

        [cell addSubview:label];
        [cell addSubview:button];
    } else if (indexPath.row == 8) {
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop, _labelWidth, _labelHeight)];
        label.text = @"UIButton, with backgroundImage";

        UIButton* button =
            [[UIButton alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop + _labelHeight, _defaultWidth, _defaultHeight)];
        [button setTitle:@"Button" forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [button setBackgroundImage:[UIImage imageNamed:@"blue_background.jpg"] forState:UIControlStateNormal];
        [button setBackgroundImage:[UIImage imageNamed:@"yellow_background.jpg"] forState:UIControlStateHighlighted];

        [button setImage:nil forState:UIControlStateNormal];
        [cell addSubview:label];
        [cell addSubview:button];
    } else if (indexPath.row == 9) {
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop, _labelWidth, _labelHeight)];
        label.text = @"UIButton, with image";

        UIButton* button =
            [[UIButton alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop + _labelHeight, _defaultWidth, _defaultHeight)];
        [button setTitle:@"Image Button" forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [button setImage:[UIButtonViewController scaledTestImage] forState:UIControlStateNormal];

        [cell addSubview:label];
        [cell addSubview:button];
    } else if (indexPath.row == 10) {
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop, _labelWidth, _labelHeight)];
        label.text = @"UIButton, with image and background";

        UIButton* button =
            [[UIButton alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop + _labelHeight, _defaultWidth, _defaultHeight)];
        [button setTitle:@"Image Button" forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [button setImage:[UIButtonViewController scaledTestImage] forState:UIControlStateNormal];
        [button setBackgroundImage:[UIImage imageNamed:@"blue_background.jpg"] forState:UIControlStateNormal];
        [button setBackgroundImage:[UIImage imageNamed:@"yellow_background.jpg"] forState:UIControlStateHighlighted];

        [cell addSubview:label];
        [cell addSubview:button];
    } else if (indexPath.row == 11) {
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop, _labelWidth, _labelHeight)];
        label.text = @"UIButton, font changed via titleLabel";

        UIButton* button =
            [[UIButton alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop + _labelHeight, _defaultWidth, _defaultHeight)];
        [button setTitle:@"Courier Button center with Word Wrap" forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];

        button.titleLabel.font = [UIFont fontWithName:@"Courier New" size:[UIFont buttonFontSize]];
        button.titleLabel.lineBreakMode = UILineBreakModeWordWrap;
        button.titleLabel.numberOfLines = 0;
        button.titleLabel.textAlignment = UITextAlignmentCenter;

        [cell addSubview:label];
        [cell addSubview:button];
    } else if (indexPath.row == 12) {
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop, _labelWidth, _labelHeight)];
        label.text = @"UIButton, title set to imageView width and height";

        UIButton* button =
            [[UIButton alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop + _labelHeight, _defaultWidth, _defaultHeight)];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [button setImage:[UIButtonViewController scaledTestImage] forState:UIControlStateNormal];
        [button setBackgroundImage:[UIImage imageNamed:@"blue_background.jpg"] forState:UIControlStateNormal];
        [button setBackgroundImage:[UIImage imageNamed:@"yellow_background.jpg"] forState:UIControlStateHighlighted];

        CGSize imageSize = [button.imageView sizeThatFits:CGSizeZero];

        [button setTitle:[NSString stringWithFormat:@"W (%d) H (%d)", (int)imageSize.width, (int)imageSize.height]
                forState:UIControlStateNormal];

        // Call to an unsupported API, should show up in Output window
        [button.imageView sizeToFit];

        [cell addSubview:label];
        [cell addSubview:button];
    } else if (indexPath.row == 13) {
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop, _labelWidth, _labelHeight)];
        label.text = @"UIButton, Selected=true, Title=Blue";

        UIButton* button =
            [[UIButton alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop + _labelHeight, _defaultWidth, _defaultHeight)];
        button.selected = true;
        [button setTitleColor:[UIColor blueColor] forState:UIControlStateSelected];
        [button setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];

        [button setBackgroundImage:[UIImage imageNamed:@"blue_background.jpg"] forState:UIControlStateSelected];
        [button setBackgroundImage:[UIImage imageNamed:@"yellow_background.jpg"] forState:UIControlStateNormal];

        [button setTitle:@"Selected Button" forState:UIControlStateSelected];
        [button setTitle:@"Selected Button" forState:UIControlStateNormal];

        [cell addSubview:label];
        [cell addSubview:button];
    } else if (indexPath.row == 14) {
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop, _labelWidth, _labelHeight)];
        label.text = @"UIButton, when in Highlighted (pressed) state, text/color/image is the same as normal state";

        UIButton* button =
            [[UIButton alloc] initWithFrame:CGRectMake(_marginLeft, _marginTop + _labelHeight, _defaultWidth, _defaultHeight)];

        // intentionally set nil titleColor for UIControlStateHighlighted
        // make sure color used for UIControlStateNormal is also used
        // in highlighted state
        [button setTitleColor:nil forState:UIControlStateHighlighted];
        [button setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];

        // intentionally set nil on title for UIControlStateHighlighted
        // make sure title used for UIControlStateNormal is also used
        // in highlighted state
        [button setTitle:nil forState:UIControlStateHighlighted];
        [button setTitle:@"Hightlighted Button" forState:UIControlStateNormal];

        // intentionally set nil on Image for UIControlStateHighlighted
        // make sure image used for UIControlStateNormal is also used
        // in highlighted state
        [button setImage:nil forState:UIControlStateHighlighted];
        [button setImage:[UIButtonViewController scaledTestImage] forState:UIControlStateNormal];

        [cell addSubview:label];
        [cell addSubview:button];
    }

    return cell;
}

- (void)_touchDown:(id)sender {
    UIButton* button = (UIButton*)sender;

    [button setTitle:@"Touch Down" forState:UIControlStateNormal];
}

- (void)_touchUpInside:(id)sender {
    UIButton* button = (UIButton*)sender;

    [button setTitle:@"Touch Up Inside" forState:UIControlStateNormal];
}

- (void)_touchUpOutside:(id)sender {
    UIButton* button = (UIButton*)sender;

    [button setTitle:@"Touch Up Outside" forState:UIControlStateNormal];
}

- (void)_touchDragInside:(id)sender {
    UIButton* button = (UIButton*)sender;

    [button setTitle:@"Drag Inside" forState:UIControlStateNormal];
}

- (void)_touchDragOutside:(id)sender {
    UIButton* button = (UIButton*)sender;

    [button setTitle:@"Drag Outside" forState:UIControlStateNormal];
}

// Since the following will get clobbered by other drag events, just output to the debug window.
- (void)_touchDragEnter:(id)sender {
    NSLog(@"Drag Enter");
}

- (void)_touchDragExit:(id)sender {
    NSLog(@"Drag Exit");
}

@end
