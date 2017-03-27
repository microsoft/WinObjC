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

#import <UIkit/UISlider.h>
#import "UILabelViewController.h"
#import <MobileCoreServices/MobileCoreServices.h>

#import "UIScrollViewController.h"

@implementation UIScrollViewController {
    MenuTableViewController* _menuTVC;
};

// setting up the controls to update the UILabel config
- (void)_setup {
    // creating scrollview and add it as subview
    self.scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(28.0f, 20.0f, 319.0f, 200.0f)];
    self.scrollView.delegate = self;
    self.scrollView.contentSize = CGSizeMake(600.0f, 600.0f);
    CAGradientLayer* gradient = [CAGradientLayer layer];
    gradient.frame = CGRectMake(0, 0, self.scrollView.contentSize.width, self.scrollView.contentSize.height);
    gradient.colors = @[ (id)[UIColor redColor].CGColor, (id)[UIColor blueColor].CGColor ];
    [self.scrollView.layer insertSublayer:gradient atIndex:0];

    self.scrollView.minimumZoomScale = 1.0f;
    self.scrollView.maximumZoomScale = 10.f;
    self.scrollView.zoomScale = 1.0f;

    float centerX = self.scrollView.bounds.size.width / 2;
    float centerY = self.scrollView.bounds.size.height / 2;

    self.subView = [[UIView alloc] initWithFrame:CGRectMake(centerX - 20, centerY - 20, 40, 40)];
    self.subView.backgroundColor = [UIColor yellowColor];

    [self.scrollView addSubview:self.subView];
    [self.view addSubview:self.scrollView];

    _menuTVC = [[MenuTableViewController alloc] init];
    _menuTVC.view.frame = CGRectMake(0.0f, 250.0f, 200.0f, 0.0f /* setting it to 0 allows vertical scrolling */);
    _menuTVC.tableView.allowsSelection = NO;
    [self.view addSubview:_menuTVC.view];

    self.contentSize = [[UITextField alloc] initWithFrame:CGRectMake(105.0f, 20.0f, 192.0f, 30.0f)];
    [_menuTVC addMenuItemView:self.contentSize andTitle:@"Content Size:"];
    self.contentSize.text = [NSString stringWithFormat:@"%.2f,%.2f", self.scrollView.contentSize.width, self.scrollView.contentSize.height];
    [self.contentSize addTarget:self action:@selector(EditingDidEnd:) forControlEvents:UIControlEventEditingDidEnd];
    self.contentSize.delegate = self;

    self.contentOffset = [[UITextField alloc] initWithFrame:CGRectMake(105.0f, 20.0f, 192.0f, 30.0f)];
    [_menuTVC addMenuItemView:self.contentOffset andTitle:@"Content Offset:"];
    self.contentOffset.text = [NSString stringWithFormat:@"%.2f,%.2f", self.scrollView.contentOffset.x, self.scrollView.contentOffset.y];
    [self.contentOffset addTarget:self action:@selector(EditingDidEnd:) forControlEvents:UIControlEventEditingDidEnd];
    self.contentOffset.delegate = self;

    self.contentInsets = [[UITextField alloc] initWithFrame:CGRectMake(105.0f, 20.0f, 192.0f, 30.0f)];
    [_menuTVC addMenuItemView:self.contentInsets andTitle:@"Content Insets:"];
    self.contentInsets.text = [NSString stringWithFormat:@"%.2f,%.2f,%.2f,%.2f",
                                                         self.scrollView.contentInset.left,
                                                         self.scrollView.contentInset.top,
                                                         self.scrollView.contentInset.right,
                                                         self.scrollView.contentInset.bottom];
    [self.contentInsets addTarget:self action:@selector(EditingDidEnd:) forControlEvents:UIControlEventEditingDidEnd];
    self.contentInsets.delegate = self;

    self.scrollEnabled = [[UISwitch alloc] initWithFrame:CGRectMake(310.0f, 131.0f, 51.0f, 31.0f)];
    [_menuTVC addMenuItemView:self.scrollEnabled andTitle:@"Enable/Disable Scrolling"];
    self.scrollEnabled.on = self.scrollView.scrollEnabled;
    [self.scrollEnabled addTarget:self action:@selector(ValueChanged:) forControlEvents:UIControlEventValueChanged];

    self.directionalLockEnabled = [[UISwitch alloc] initWithFrame:CGRectMake(310.0f, 131.0f, 51.0f, 31.0f)];
    [_menuTVC addMenuItemView:self.directionalLockEnabled andTitle:@"Enable/Disable Direciontal Lock"];
    self.directionalLockEnabled.on = self.scrollView.directionalLockEnabled;
    [self.directionalLockEnabled addTarget:self action:@selector(ValueChanged:) forControlEvents:UIControlEventValueChanged];

    self.showHorizontalIndicator = [[UISwitch alloc] initWithFrame:CGRectMake(310.0f, 131.0f, 51.0f, 31.0f)];
    [_menuTVC addMenuItemView:self.showHorizontalIndicator andTitle:@"Show/Hide Horizontal Scrollbar"];
    self.showHorizontalIndicator.on = self.scrollView.showsHorizontalScrollIndicator;
    [self.showHorizontalIndicator addTarget:self action:@selector(ValueChanged:) forControlEvents:UIControlEventValueChanged];

    self.showVerticalIndicator = [[UISwitch alloc] initWithFrame:CGRectMake(310.0f, 131.0f, 51.0f, 31.0f)];
    [_menuTVC addMenuItemView:self.showVerticalIndicator andTitle:@"Show/Hide Vertical Scrollbar"];
    self.showVerticalIndicator.on = self.scrollView.showsVerticalScrollIndicator;
    [self.showVerticalIndicator addTarget:self action:@selector(ValueChanged:) forControlEvents:UIControlEventValueChanged];

    self.zoomScale = [[UISlider alloc] initWithFrame:CGRectMake(101.0f, 54.0f, 208.0f, 31.0f)];
    [_menuTVC addMenuItemView:self.zoomScale andTitle:@"Zoom Scale:"];
    self.zoomScale.minimumValue = self.scrollView.minimumZoomScale;
    self.zoomScale.maximumValue = self.scrollView.maximumZoomScale;
    self.zoomScale.value = self.scrollView.zoomScale;
    [self.zoomScale addTarget:self action:@selector(ValueChanged:) forControlEvents:UIControlEventValueChanged];

    self.minmumZoomScale = [[UITextField alloc] initWithFrame:CGRectMake(105.0f, 20.0f, 43.0f, 30.0f)];
    [_menuTVC addMenuItemView:self.minmumZoomScale andTitle:@"Minimum zoom scale:"];
    self.minmumZoomScale.text = [NSString stringWithFormat:@"%.2f", self.scrollView.minimumZoomScale];
    [self.minmumZoomScale addTarget:self action:@selector(EditingDidEnd:) forControlEvents:UIControlEventEditingDidEnd];
    self.minmumZoomScale.delegate = self;

    self.maxZoomScale = [[UITextField alloc] initWithFrame:CGRectMake(105.0f, 20.0f, 43.0f, 30.0f)];
    [_menuTVC addMenuItemView:self.maxZoomScale andTitle:@"Maximum zoom scale:"];
    self.maxZoomScale.text = [NSString stringWithFormat:@"%.2f", self.scrollView.maximumZoomScale];
    [self.maxZoomScale addTarget:self action:@selector(EditingDidEnd:) forControlEvents:UIControlEventEditingDidEnd];
    self.maxZoomScale.delegate = self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.

    self.view.backgroundColor = [UIColor whiteColor];
    self.view.frame = CGRectMake(0.0f, 0.0f, 200.0f, 0.0f);

    [self _setup];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)textFieldShouldReturn:(UITextField*)textField {
    [textField resignFirstResponder];
    return YES;
}

- (void)EditingDidEnd:(id)sender {
    if (sender == self.contentSize) {
        NSString* s = [NSString stringWithFormat:@"{%@}", self.contentSize.text];
        self.scrollView.contentSize = CGSizeFromString(s);
    } else if (sender == self.contentOffset) {
        NSString* s = [NSString stringWithFormat:@"{%@}", self.contentOffset.text];
        self.scrollView.contentOffset = CGPointFromString(s);
    } else if (sender == self.contentInsets) {
        NSString* s = [NSString stringWithFormat:@"{%@}", self.contentInsets.text];
        self.scrollView.contentInset = UIEdgeInsetsFromString(s);
    } else if (sender == self.maxZoomScale) {
        self.scrollView.maximumZoomScale = [self.maxZoomScale.text floatValue];
    } else if (sender == self.minmumZoomScale) {
        self.scrollView.minimumZoomScale = [self.minmumZoomScale.text floatValue];
    }
}

- (void)ValueChanged:(id)sender {
    if (sender == self.scrollEnabled) {
        self.scrollView.scrollEnabled = self.scrollEnabled.on;
    } else if (sender == self.directionalLockEnabled) {
        self.scrollView.directionalLockEnabled = self.directionalLockEnabled.on;
    } else if (sender == self.showVerticalIndicator) {
        self.scrollView.showsVerticalScrollIndicator = self.showVerticalIndicator.on;
    } else if (sender == self.showHorizontalIndicator) {
        self.scrollView.showsHorizontalScrollIndicator = self.showHorizontalIndicator.on;
    } else if (sender == self.zoomScale) {
        self.scrollView.zoomScale = self.zoomScale.value;
    }

    [self.view endEditing:YES];
}

- (void)scrollViewDidScroll:(UIScrollView*)scrollView {
    NSLog(@"scrollViewDidScroll");
    self.contentOffset.text = [NSString stringWithFormat:@"%.2f,%.2f", self.scrollView.contentOffset.x, self.scrollView.contentOffset.y];
}

- (void)scrollViewWillBeginDragging:(UIScrollView*)scrollView {
    NSLog(@"scrollViewWillBeginDragging");
}

- (void)scrollViewWillEndDragging:(UIScrollView*)scrollView
                     withVelocity:(CGPoint)velocity
              targetContentOffset:(inout CGPoint*)targetContentOffset {
    NSLog(@"scrollViewWillEndDragging");
}

- (void)scrollViewDidEndDragging:(UIScrollView*)scrollView willDecelerate:(BOOL)decelerate {
    NSLog(@"scrollViewDidEndDragging");
}

- (BOOL)scrollViewShouldScrollToTop:(UIScrollView*)scrollView {
    NSLog(@"scrollViewShouldScrollToTop");
    return YES;
}

- (void)scrollViewDidScrollToTop:(UIScrollView*)scrollView {
    NSLog(@"scrollViewDidScrollToTop");
}

- (void)scrollViewWillBeginDecelerating:(UIScrollView*)scrollView {
    NSLog(@"scrollViewWillBeginDecelerating");
}

- (void)scrollViewDidEndDecelerating:(UIScrollView*)scrollView {
    NSLog(@"scrollViewDidEndDecelerating");
}

- (UIView*)viewForZoomingInScrollView:(UIScrollView*)scrollView {
    NSLog(@"viewForZoomingInScrollView");
    return self.subView;
}

- (void)scrollViewWillBeginZooming:(UIScrollView*)scrollView withView:(UIView*)view {
    NSLog(@"scrollViewWillBeginZooming");
}

- (void)scrollViewDidEndZooming:(UIScrollView*)scrollView withView:(UIView*)view atScale:(CGFloat)scale {
    NSLog(@"scrollViewDidEndZooming");
}

- (void)scrollViewDidZoom:(UIScrollView*)scrollView {
    NSLog(@"scrollViewDidZoom");
    self.zoomScale.value = self.scrollView.zoomScale;
    self.contentSize.text = [NSString stringWithFormat:@"%.2f,%.2f", self.scrollView.contentSize.width, self.scrollView.contentSize.height];
}

- (void)scrollViewDidEndScrollingAnimation:(UIScrollView*)scrollView {
    NSLog(@"scrollViewDidEndScrollingAnimation");
}

@end
