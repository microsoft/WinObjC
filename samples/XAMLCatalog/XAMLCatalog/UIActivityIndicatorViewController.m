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

#import <UIKit/UIKit.h>
#import "UIActivityIndicatorViewController.h"

@implementation UIActivityIndicatorViewController

- (id)init {
    self = [super init];

    return self;
}

- (instancetype)initWithCoder:(NSCoder *)aDecoder
{
    self = [super initWithCoder:aDecoder];

    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    // UIActivityIndicatorView - style gray
    UIActivityIndicatorView* aivStyleGray = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
    [aivStyleGray startAnimating];
    [self addMenuItemView:aivStyleGray andTitle:@"viewStyleGray"];

    // UIActivityIndicatorView - style white
    UIActivityIndicatorView* aivStylewhite = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhite];
    [aivStylewhite startAnimating];
    aivStylewhite.backgroundColor = [UIColor lightGrayColor];
    [self addMenuItemView:aivStylewhite andTitle:@"viewStyleWhite"];

    // UIActivityIndicatorView - style white large
    UIActivityIndicatorView* aivStyleWhiteLarge = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
    aivStyleWhiteLarge.backgroundColor = [UIColor lightGrayColor];
    [aivStyleWhiteLarge startAnimating];
    [self addMenuItemView:aivStyleWhiteLarge andTitle:@"viewStyleWhiteLarge"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
