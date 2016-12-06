//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import "CALayerAnimationViewController.h"

@implementation CALayerAnimationViewController {
    UIImage* _photo;

    UIImageView* _imageViewLeftTop;
    UIImageView* _imageViewMidTop;
    UIImageView* _imageViewRightTop;
    UIImageView* _imageViewLeftBottom;
    UIImageView* _imageViewMidBottom;
    UIImageView* _imageViewRightBottom;

    CABasicAnimation* _animation;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor whiteColor];

    _photo = [UIImage imageNamed:@"safe.png"];

    _imageViewLeftTop = [[UIImageView alloc] initWithImage:_photo];
    _imageViewLeftTop.layer.frame =
        CGRectMake(self.view.frame.origin.x, self.view.frame.origin.y, self.view.frame.size.width / 3, self.view.frame.size.height / 2);
    [_imageViewLeftTop setContentMode:UIViewContentModeScaleAspectFit];
    _imageViewLeftTop.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:_imageViewLeftTop];

    _imageViewMidTop = [[UIImageView alloc] initWithImage:_photo];
    _imageViewMidTop.layer.frame = CGRectMake(self.view.frame.origin.x + self.view.frame.size.width / 3,
                                              self.view.frame.origin.y,
                                              self.view.frame.size.width / 3,
                                              self.view.frame.size.height / 2);
    [_imageViewMidTop setContentMode:UIViewContentModeScaleAspectFit];
    _imageViewMidTop.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:_imageViewMidTop];

    _imageViewRightTop = [[UIImageView alloc] initWithImage:_photo];
    _imageViewRightTop.layer.frame = CGRectMake(self.view.frame.origin.x + 2 * self.view.frame.size.width / 3,
                                                self.view.frame.origin.y,
                                                self.view.frame.size.width / 3,
                                                self.view.frame.size.height / 2);
    [_imageViewRightTop setContentMode:UIViewContentModeScaleAspectFit];
    _imageViewRightTop.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:_imageViewRightTop];

    _imageViewLeftBottom = [[UIImageView alloc] initWithImage:_photo];
    _imageViewLeftBottom.layer.frame = CGRectMake(self.view.frame.origin.x,
                                                  self.view.frame.origin.y + self.view.frame.size.height / 2,
                                                  self.view.frame.size.width / 3,
                                                  self.view.frame.size.width / 3);
    [_imageViewLeftBottom setContentMode:UIViewContentModeScaleAspectFit];
    _imageViewLeftBottom.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:_imageViewLeftBottom];

    _imageViewMidBottom = [[UIImageView alloc] initWithImage:_photo];
    _imageViewMidBottom.layer.frame = CGRectMake(self.view.frame.origin.x + self.view.frame.size.width / 3,
                                                 self.view.frame.origin.y + self.view.frame.size.height / 2,
                                                 self.view.frame.size.width / 3,
                                                 self.view.frame.size.width / 3);
    [_imageViewMidBottom setContentMode:UIViewContentModeScaleAspectFit];
    _imageViewMidBottom.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:_imageViewMidBottom];

    _imageViewRightBottom = [[UIImageView alloc] initWithImage:_photo];
    _imageViewRightBottom.layer.frame = CGRectMake(self.view.frame.origin.x + 2 * self.view.frame.size.width / 3,
                                                   self.view.frame.origin.y + self.view.frame.size.height / 2,
                                                   self.view.frame.size.width / 3,
                                                   self.view.frame.size.width / 3);
    [_imageViewRightBottom setContentMode:UIViewContentModeScaleAspectFit];
    _imageViewRightBottom.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:_imageViewRightBottom];

    _animation = [CABasicAnimation animation];
}

- (void)viewDidAppear:(BOOL)animated {
    CGRect fromRect = CGRectMake(0, 0, _photo.size.width / 4, _photo.size.height / 4);
    CGRect byRect = CGRectMake(0,
                               0,
                               _imageViewLeftTop.layer.frame.size.width / 2 - _photo.size.width / 4,
                               _imageViewLeftTop.layer.frame.size.height / 2 - _photo.size.width / 4);
    _animation.keyPath = @"bounds";
    _animation.fromValue = [NSValue valueWithCGRect:fromRect];
    _animation.toValue = nil;
    _animation.byValue = [NSValue valueWithCGRect:byRect];
    _animation.duration = 5;
    _animation.removedOnCompletion = NO;
    _animation.repeatCount = HUGE_VALF;
    [_imageViewLeftTop.layer addAnimation:_animation forKey:@"boundsAnimation"];

    CGRect toRect = CGRectMake(0, 0, _imageViewMidTop.layer.frame.size.width / 2, _imageViewMidTop.layer.frame.size.height / 2);
    _animation.keyPath = @"bounds";
    _animation.fromValue = nil;
    _animation.toValue = [NSValue valueWithCGRect:toRect];
    _animation.byValue = [NSValue valueWithCGRect:byRect];
    _animation.duration = 5;
    _animation.removedOnCompletion = NO;
    _animation.repeatCount = HUGE_VALF;
    [_imageViewMidTop.layer addAnimation:_animation forKey:@"boundsAnimation"];

    [_imageViewRightTop.layer setBounds:fromRect];
    _animation.keyPath = @"bounds";
    _animation.fromValue = nil;
    _animation.toValue = nil;
    _animation.byValue = [NSValue valueWithCGRect:byRect];
    _animation.duration = 5;
    _animation.removedOnCompletion = NO;
    _animation.repeatCount = HUGE_VALF;
    [_imageViewRightTop.layer addAnimation:_animation forKey:@"boundsAnimation"];

    CATransform3D fromTransform = CATransform3DMakeRotation(0, 0, 0, 1);

    CATransform3D byTransform = CATransform3DMakeRotation(90, 0, 0, 1);
    _animation.keyPath = @"transform";
    _animation.fromValue = [NSValue valueWithCATransform3D:fromTransform];
    _animation.byValue = [NSValue valueWithCATransform3D:byTransform];
    _animation.toValue = nil;
    _animation.duration = 5;
    _animation.removedOnCompletion = YES;
    _animation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseIn];
    _animation.repeatCount = HUGE_VALF;
    [_imageViewLeftBottom.layer addAnimation:_animation forKey:@"transformAnimation"];

    CATransform3D toTransform = CATransform3DMakeRotation(90, 0, 0, 1);
    _animation.keyPath = @"transform";
    _animation.fromValue = nil;
    _animation.toValue = [NSValue valueWithCATransform3D:toTransform];
    _animation.byValue = [NSValue valueWithCATransform3D:byTransform];
    _animation.duration = 5;
    _animation.removedOnCompletion = YES;
    _animation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseOut];
    _animation.repeatCount = HUGE_VALF;
    [_imageViewMidBottom.layer addAnimation:_animation forKey:@"transformAnimation"];

    [_imageViewRightBottom.layer setTransform:fromTransform];
    _animation.keyPath = @"transform";
    _animation.fromValue = nil;
    _animation.toValue = nil;
    _animation.byValue = [NSValue valueWithCATransform3D:byTransform];
    _animation.duration = 5;
    _animation.removedOnCompletion = YES;
    _animation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
    _animation.repeatCount = HUGE_VALF;
    [_imageViewRightBottom.layer addAnimation:_animation forKey:@"transformAnimation"];
}

@end
