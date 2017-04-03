//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController {
    UIButton* _submitButton;
    UITextField* _inputText;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    CGFloat width = CGRectGetWidth(self.view.bounds);
    // Adds textbox to change text
    _inputText = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 2 * width / 3, 50)];
    _inputText.text = @"Input Text.";
    _inputText.delegate = self;
    [self.view addSubview:_inputText];

    _submitButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    _submitButton.frame = CGRectMake(2 * width / 3, 0, width / 3, 50);
    [_submitButton addTarget:self action:@selector(submit) forControlEvents:UIControlEventTouchDown];
    [_submitButton setTitle:@"Submit" forState:UIControlStateNormal];
    [self.view addSubview:_submitButton];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)submit {
    NSURL* containerURL1 = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:@"group.Folder1"];
    [_inputText.text writeToFile:[containerURL1.path stringByAppendingPathComponent:@"testfile.txt"] atomically:NO];
    NSURL* containerURL2 = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:@"group.Folder2"];
    [_inputText.text writeToFile:[containerURL2.path stringByAppendingPathComponent:@"testfile.txt"] atomically:NO];
}

@end
