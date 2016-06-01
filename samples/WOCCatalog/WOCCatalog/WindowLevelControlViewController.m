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
//******************************************************************************

#import "WindowLevelControlViewController.h"
#import "AppDelegate.h"

@implementation WindowLevelControlViewController

AppDelegate* _appDelegate;
UIWindow* _mainWindow;
UIWindow* _levelControlWindow;
UIWindow* _redWindow;
UIWindow* _blueWindow;
UIWindow* _yellowWindow;
bool _internalInitialized;

- (id)init {
    self = [super init];
    _internalInitialized = false;
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor whiteColor];

    UIButton* backToMainBtn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    backToMainBtn.frame = CGRectMake(30.0f, 50.0f, 100.0f, 20.0f);
    backToMainBtn.layer.cornerRadius = 5.0f;
    [backToMainBtn setTitle:@"< BackToMain" forState:UIControlStateNormal];
    [backToMainBtn addTarget:self action:@selector(_backBtnClicked) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:backToMainBtn];

    UIButton* redOnTopBtn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    redOnTopBtn.frame = CGRectMake(30.0f, 80.0f, 100.0f, 20.0f);
    redOnTopBtn.layer.cornerRadius = 5.0f;
    [redOnTopBtn setTitle:@"RedOnTop" forState:UIControlStateNormal];
    [redOnTopBtn addTarget:self action:@selector(_redBtnClicked) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:redOnTopBtn];

    UIButton* yellowOnTopBtn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    yellowOnTopBtn.frame = CGRectMake(130.0f, 80.0f, 100.0f, 20.0f);
    yellowOnTopBtn.layer.cornerRadius = 5.0f;
    [yellowOnTopBtn setTitle:@"YellowOnTop" forState:UIControlStateNormal];
    [yellowOnTopBtn addTarget:self action:@selector(_yellowBtnClicked) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:yellowOnTopBtn];

    UIButton* blueOnTopBtn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    blueOnTopBtn.frame = CGRectMake(230.0f, 80.0f, 100.0f, 20.0f);
    blueOnTopBtn.layer.cornerRadius = 5.0f;
    [blueOnTopBtn setTitle:@"BlueOnTop" forState:UIControlStateNormal];
    [blueOnTopBtn addTarget:self action:@selector(_blueBtnClicked) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:blueOnTopBtn];
}

- (void)_initInternal {
    _appDelegate = (AppDelegate*)[[UIApplication sharedApplication] delegate];
    _mainWindow = [_appDelegate window];
    _levelControlWindow = [_appDelegate levelControlWindow];
    _redWindow = [_appDelegate redColorWindow];
    _blueWindow = [_appDelegate blueColorWindow];
    _yellowWindow = [_appDelegate yellowColorWindow];
    _internalInitialized = true;
}

- (void)_redBtnClicked {
    if (!_internalInitialized) {
        [self _initInternal];
    }
    _redWindow.windowLevel =
        (_yellowWindow.windowLevel > _blueWindow.windowLevel) ? _yellowWindow.windowLevel + 1.0f : _blueWindow.windowLevel + 1.0f;
}

- (void)_yellowBtnClicked {
    if (!_internalInitialized) {
        [self _initInternal];
    }
    _yellowWindow.windowLevel =
        (_redWindow.windowLevel > _blueWindow.windowLevel) ? _redWindow.windowLevel + 1.0f : _blueWindow.windowLevel + 1.0f;
}

- (void)_blueBtnClicked {
    if (!_internalInitialized) {
        [self _initInternal];
    }
    _blueWindow.windowLevel =
        (_yellowWindow.windowLevel > _redWindow.windowLevel) ? _yellowWindow.windowLevel + 1.0f : _redWindow.windowLevel + 1.0f;
}

- (void)_backBtnClicked {
    if (!_internalInitialized) {
        [self _initInternal];
    }
    _levelControlWindow.windowLevel = UIWindowLevelNormal;
    _redWindow.windowLevel = UIWindowLevelNormal + 1.0f;
    _blueWindow.windowLevel = UIWindowLevelNormal + 2.0f;
    _yellowWindow.windowLevel = UIWindowLevelNormal + 3.0f;
    _mainWindow.windowLevel = UIWindowLevelNormal + 4.0f;
}

@end
