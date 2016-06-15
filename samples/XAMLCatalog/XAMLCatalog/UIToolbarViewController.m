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

#import "UIToolbarViewController.h"
#ifdef WINOBJC
#import <UWP/WindowsUIXamlControls.h>
#endif

@implementation UIToolbarViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.view setBackgroundColor:[UIColor lightGrayColor]];
    self.title = @"Xaml UIToolbar";

    NSArray* buttonArray = nil;
    int midToolbarY = 150;

#ifdef WINOBJC
    int topToolbarY = 0;
    int bottomToolbarY = self.view.frame.size.height - 90;

    WXCAppBarButton* _saveButton = [WXCAppBarButton make];
    _saveButton.icon = [WXCSymbolIcon makeInstanceWithSymbol:WXCSymbolSave];
    WXCAppBarButton* _editButton = [WXCAppBarButton make];
    _editButton.icon = [WXCSymbolIcon makeInstanceWithSymbol:WXCSymbolEdit];
    buttonArray = [NSArray arrayWithObjects:_saveButton, _editButton, nil];
#else
    int topToolbarY = 64;
    int bottomToolbarY = self.view.frame.size.height - 44;
#endif

    UIToolbar* topToolbar = [[UIToolbar alloc] initWithFrame:CGRectMake(0, topToolbarY, self.view.frame.size.width, 44)];
    [topToolbar setBarStyle:UIBarStyleBlack];
    [topToolbar setItems:buttonArray animated:YES];
    [topToolbar setTranslucent:NO];
    [topToolbar setTintColor:[UIColor yellowColor]];
    [self.view addSubview:topToolbar];

    UIToolbar* midToolbar = [[UIToolbar alloc] initWithFrame:CGRectMake(0, midToolbarY, self.view.frame.size.width, 44)];
    [midToolbar setBarStyle:UIBarStyleDefault];
    [self.view addSubview:midToolbar];

    UIToolbar* bottomToolbar = [[UIToolbar alloc] initWithFrame:CGRectMake(0, bottomToolbarY, self.view.frame.size.width, 44)];
    [bottomToolbar setBarStyle:UIBarStyleBlackTranslucent];
    [self.view addSubview:bottomToolbar];
}

@end
