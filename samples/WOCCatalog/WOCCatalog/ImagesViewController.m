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

#import "ImagesViewController.h"

@implementation ImagesViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor blackColor];
    UIImageView *imagesView = [[UIImageView alloc] initWithFrame: CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height)];
        
    imagesView.animationImages = [NSArray arrayWithObjects:
                            [UIImage imageNamed:@"photo1.jpg"],
                            [UIImage imageNamed:@"photo2.jpg"],
                            [UIImage imageNamed:@"photo3.jpg"],
                            [UIImage imageNamed:@"photo4.jpg"],
                            [UIImage imageNamed:@"photo5.jpg"],
                            [UIImage imageNamed:@"photo6.jpg"],
                            [UIImage imageNamed:@"photo7.jpg"],
                            [UIImage imageNamed:@"photo8.jpg"],
                                                            nil];
    imagesView.animationDuration = 10.0;

    [imagesView setContentMode:UIViewContentModeScaleAspectFit];
    [imagesView startAnimating];
    imagesView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [[self view] addSubview: imagesView];
}
@end


