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

#import "MainViewController.h"

@interface MainViewController ()
@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // This demonstrates that the UIViewController is hooked up all the way to XAML backing control
    self.text.text = @"All hooked up!";
    self.slider.value = 0.33;

    // Spinners should be spinning
    [self.spinner setActivityIndicatorViewStyle:UIActivityIndicatorViewStyleGray];
    [self.spinner startAnimating];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];

    // Dispose of any resources that can be recreated.
}

- (IBAction)textFieldEditingChanged:(id)sender {
    NSLog(@"textFieldEditingChanged: %@", self.text.text);

    // Change the label text
    self.label.text = self.text.text;
}

- (IBAction)buttonClicked:(id)sender {
    NSLog(@"buttonClicked");

    // Change the label text
    self.text.text = @"You clicked a button";
}

- (IBAction)sliderValueChanged:(id)sender {
    NSLog(@"sliderValueChangedChanged: %@", self.text.text);

    // Change the label text
    self.text.text = [NSString stringWithFormat:@"Slider value: %f", self.slider.value];
}


@end
