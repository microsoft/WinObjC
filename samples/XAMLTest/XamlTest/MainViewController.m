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

    //  To be re-enabled once we can wrap projected controls as UIKit controls
    /*
    self.text.text = @"UITextField";
    self.text.delegate = self;

    // Programmatic selector
    [self.text addTarget:self action:@selector(textFieldEditingChanged) forControlEvents:UIControlEventEditingChanged];
    */
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];

    // Dispose of any resources that can be recreated.
}

- (IBAction)textFieldEditingBegin:(id)sender {
    NSLog(@"textFieldEditingBegin");
}

- (IBAction)textFieldEditingDidEnd:(id)sender {
    NSLog(@"textFieldEditingDidEnd");
}

- (void)textFieldEditingChanged {
    NSLog(@"textFieldEditingChanged: %@", self.text.text);
}

- (IBAction)buttonClicked:(id)sender {
    NSLog(@"buttonClicked");
}

@end
