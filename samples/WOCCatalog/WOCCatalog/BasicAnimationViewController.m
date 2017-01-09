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

#import "BasicAnimationViewController.h"

@implementation BasicAnimationViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    photo = [UIImage imageNamed:@"photo10.jpg"];
    imageViewLeftTop = [[UIImageView alloc] initWithImage:photo];
    imageViewLeftTop.layer.frame =
        CGRectMake(self.view.frame.origin.x, self.view.frame.origin.y, self.view.frame.size.width / 3, self.view.frame.size.height / 2);
    [imageViewLeftTop setContentMode:UIViewContentModeScaleAspectFit];
    imageViewLeftTop.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [[self view] addSubview:imageViewLeftTop];

    imageViewMidTop = [[UIImageView alloc] initWithImage:photo];
    imageViewMidTop.layer.frame = CGRectMake(self.view.frame.origin.x + self.view.frame.size.width / 3,
                                             self.view.frame.origin.y,
                                             self.view.frame.size.width / 3,
                                             self.view.frame.size.height / 2);
    [imageViewMidTop setContentMode:UIViewContentModeScaleAspectFit];
    imageViewMidTop.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [[self view] addSubview:imageViewMidTop];

    imageViewRightTop = [[UIImageView alloc] initWithImage:photo];
    imageViewRightTop.layer.frame = CGRectMake(self.view.frame.origin.x + 2 * self.view.frame.size.width / 3,
                                               self.view.frame.origin.y,
                                               self.view.frame.size.width / 3,
                                               self.view.frame.size.height / 2);
    [imageViewRightTop setContentMode:UIViewContentModeScaleAspectFit];
    imageViewRightTop.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [[self view] addSubview:imageViewRightTop];

    imageViewLeftBottom = [[UIImageView alloc] initWithImage:photo];
    imageViewLeftBottom.layer.frame = CGRectMake(self.view.frame.origin.x,
                                                 self.view.frame.origin.y + self.view.frame.size.height / 2,
                                                 self.view.frame.size.width / 3,
                                                 self.view.frame.size.width / 3);

    [imageViewLeftBottom setContentMode:UIViewContentModeScaleAspectFit];
    imageViewLeftBottom.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [[self view] addSubview:imageViewLeftBottom];

    imageViewMidBottom = [[UIImageView alloc] initWithImage:photo];
    imageViewMidBottom.layer.frame = CGRectMake(self.view.frame.origin.x + self.view.frame.size.width / 3,
                                                self.view.frame.origin.y + self.view.frame.size.height / 2,
                                                self.view.frame.size.width / 3,
                                                self.view.frame.size.width / 3);

    [imageViewMidBottom setContentMode:UIViewContentModeScaleAspectFit];
    imageViewMidBottom.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [[self view] addSubview:imageViewMidBottom];

    imageViewRightBottom = [[UIImageView alloc] initWithImage:photo];
    imageViewRightBottom.layer.frame = CGRectMake(self.view.frame.origin.x + 2 * self.view.frame.size.width / 3,
                                                  self.view.frame.origin.y + self.view.frame.size.height / 2,
                                                  self.view.frame.size.width / 3,
                                                  self.view.frame.size.width / 3);

    [imageViewRightBottom setContentMode:UIViewContentModeScaleAspectFit];
    imageViewRightBottom.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [[self view] addSubview:imageViewRightBottom];

    animation = [CABasicAnimation animation];
}

- (void)viewDidAppear:(BOOL)animated {
    CGRect fromRect = CGRectMake(0, 0, photo.size.width / 4, photo.size.height / 4);
    CGRect byRect = CGRectMake(0,
                               0,
                               imageViewLeftTop.layer.frame.size.width / 2 - photo.size.width / 4,
                               imageViewLeftTop.layer.frame.size.height / 2 - photo.size.width / 4);
    animation.keyPath = @"bounds";
    animation.fromValue = [NSValue valueWithCGRect:fromRect];
    animation.toValue = nil;
    animation.byValue = [NSValue valueWithCGRect:byRect];
    animation.duration = 5;
    animation.removedOnCompletion = NO;
    animation.repeatCount = HUGE_VALF;
    [imageViewLeftTop.layer addAnimation:animation forKey:@"boundsAnimation"];

    CGRect toRect = CGRectMake(0, 0, imageViewMidTop.layer.frame.size.width / 2, imageViewMidTop.layer.frame.size.height / 2);
    animation.keyPath = @"bounds";
    animation.fromValue = nil;
    animation.toValue = [NSValue valueWithCGRect:toRect];
    animation.byValue = [NSValue valueWithCGRect:byRect];
    animation.duration = 5;
    animation.removedOnCompletion = NO;
    animation.repeatCount = HUGE_VALF;
    [imageViewMidTop.layer addAnimation:animation forKey:@"boundsAnimation"];

    [imageViewRightTop.layer setBounds:fromRect];
    animation.keyPath = @"bounds";
    animation.fromValue = nil;
    animation.toValue = nil;
    animation.byValue = [NSValue valueWithCGRect:byRect];
    animation.duration = 5;
    animation.removedOnCompletion = NO;
    animation.repeatCount = HUGE_VALF;
    [imageViewRightTop.layer addAnimation:animation forKey:@"boundsAnimation"];

    CATransform3D fromTransform = CATransform3DMakeRotation(0, 0, 0, 1);
    CATransform3D byTransform = CATransform3DMakeRotation(90, 0, 0, 1);
    animation.keyPath = @"transform";
    animation.fromValue = [NSValue valueWithCATransform3D:fromTransform];
    animation.byValue = [NSValue valueWithCATransform3D:byTransform];
    animation.toValue = nil;
    animation.duration = 5;
    animation.removedOnCompletion = YES;
    animation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseIn];
    animation.repeatCount = HUGE_VALF;
    [imageViewLeftBottom.layer addAnimation:animation forKey:@"transformAnimation"];

    CATransform3D toTransform = CATransform3DMakeRotation(90, 0, 0, 1);
    animation.keyPath = @"transform";
    animation.fromValue = nil;
    animation.toValue = [NSValue valueWithCATransform3D:toTransform];
    animation.byValue = [NSValue valueWithCATransform3D:byTransform];
    animation.duration = 5;
    animation.removedOnCompletion = YES;
    animation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseOut];
    animation.repeatCount = HUGE_VALF;
    [imageViewMidBottom.layer addAnimation:animation forKey:@"transformAnimation"];

    [imageViewRightBottom.layer setTransform:fromTransform];
    animation.keyPath = @"transform";
    animation.fromValue = nil;
    animation.toValue = nil;
    animation.byValue = [NSValue valueWithCATransform3D:byTransform];
    animation.duration = 5;
    animation.removedOnCompletion = YES;
    animation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
    animation.repeatCount = HUGE_VALF;
    [imageViewRightBottom.layer addAnimation:animation forKey:@"transformAnimation"];
}

- (void)viewDidDisappear:(BOOL)animated {
    [imageViewLeftTop.layer removeAllAnimations];
    [imageViewMidTop.layer removeAllAnimations];
    [imageViewRightTop.layer removeAllAnimations];
    [imageViewLeftBottom.layer removeAllAnimations];
    [imageViewMidBottom.layer removeAllAnimations];
    [imageViewRightBottom.layer removeAllAnimations];
}

@end
