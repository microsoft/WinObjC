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
    UIButton* _readButton;
    UILabel* _textLabel;
    UILabel* _invalidTextLabel;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    CGFloat width = CGRectGetWidth(self.view.bounds);
    // Adds textbox to change text
    _textLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, 2 * width / 3, 50)];
    _textLabel.text = @"";
    [self.view addSubview:_textLabel];
    _invalidTextLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 100, width, 150)];
    _invalidTextLabel.text = @"";
    [self.view addSubview:_invalidTextLabel];

    _readButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    _readButton.frame = CGRectMake(2 * width / 3, 0, width / 3, 50);
    [_readButton addTarget:self action:@selector(readFile) forControlEvents:UIControlEventTouchDown];
    [_readButton setTitle:@"Refresh" forState:UIControlStateNormal];
    [self.view addSubview:_readButton];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)readFile {
    NSURL* containerURL = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:@"group.Folder1"];
    _textLabel.text = [NSString stringWithContentsOfFile:[containerURL.path stringByAppendingPathComponent:@"testfile.txt"]];
    NSURL* invalidURL = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:@"group.Folder3"];
    if ([[UIApplication sharedApplication] canOpenURL:invalidURL]) {
        _invalidTextLabel.text = @"Was able to access unregistered folder!";
    } else {
        _invalidTextLabel.text = @"Was prevented from accessing unregistered folder correctly!";
    }
}

@end
