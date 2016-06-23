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

#import "PopoverViewController.h"

@implementation PopoverViewController

- (id)init {
    self = [super init];
    return self;
}

- (id)initWithImage:(UIImage*)image {
    self = [self init];

    self->imageView = [[UIImageView alloc] initWithImage:image];
    UIButton* backButton = [[UIButton alloc] initWithFrame:CGRectMake(10, 10, 100, 25)];
    [backButton setTitle:@"Done" forState:UIControlStateNormal];
    [backButton addTarget:self action:@selector(dismissViewController) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:backButton];

    return self;
}

- (void)dismissViewController {
    [self dismissViewControllerAnimated:YES completion:^{
        assert(self.numViewEventsFired == 5);
    }];
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self->scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height)];

    [self createLayout];

    scrollView.delegate = self;
    scrollView.clipsToBounds = YES;

    imageView.userInteractionEnabled = YES;

    scrollView.autoresizingMask = (UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight);

    scrollView.contentSize = imageView.image.size;
    scrollView.decelerationRate = 1; // UIScrollViewDecelerationRateFast;

    UITapGestureRecognizer* tapGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleDoubleTap:)];
    [tapGesture setNumberOfTapsRequired:1];
    [imageView addGestureRecognizer:tapGesture];

    [scrollView setContentMode:UIViewContentModeScaleAspectFit];
    [imageView sizeToFit];
    [scrollView setContentSize:CGSizeMake(imageView.frame.size.width, imageView.frame.size.height)];

    [scrollView addSubview:imageView];
    [self.view addSubview:scrollView];

    float minimumScale =
        MIN(self.view.bounds.size.width / imageView.image.size.width, self.view.bounds.size.height / imageView.image.size.height);

    scrollView.maximumZoomScale = 1.;
    scrollView.minimumZoomScale = minimumScale;
    scrollView.zoomScale = minimumScale;

    imageView.center = CGPointMake(scrollView.contentSize.width * 0.5, scrollView.contentSize.height * 0.5);

    self.numViewEventsFired += 1;
}

- (void)createLayout {
    [scrollView setBackgroundColor:[UIColor lightGrayColor]];
}

- (void)scrollViewDidZoom:(UIScrollView*)aScrollView {
    CGFloat offsetX = (scrollView.bounds.size.width > scrollView.contentSize.width) ?
                          (scrollView.bounds.size.width - scrollView.contentSize.width) * 0.5 :
                          0.0;
    CGFloat offsetY = (scrollView.bounds.size.height > scrollView.contentSize.height) ?
                          (scrollView.bounds.size.height - scrollView.contentSize.height) * 0.5 :
                          0.0;
    imageView.center = CGPointMake(scrollView.contentSize.width * 0.5 + offsetX, scrollView.contentSize.height * 0.5 + offsetY);
}

- (void)handleDoubleTap:(UIGestureRecognizer*)gestureRecognizer {
    // zoom in
    float newScale = [scrollView zoomScale] * 2.0;

    if (newScale > scrollView.maximumZoomScale && scrollView.zoomScale != scrollView.minimumZoomScale) {
        newScale = scrollView.minimumZoomScale;
        CGRect zoomRect = [self zoomRectForScale:newScale withCenter:[gestureRecognizer locationInView:gestureRecognizer.view]];

        [scrollView zoomToRect:zoomRect animated:YES];

    } else {
        newScale = scrollView.maximumZoomScale;
        CGRect zoomRect = [self zoomRectForScale:newScale withCenter:[gestureRecognizer locationInView:gestureRecognizer.view]];

        [scrollView zoomToRect:zoomRect animated:YES];
    }
}

- (void)handleRightSwipe:(UIGestureRecognizer*)gestureRecognizer {
}

- (void)handleLeftSwipe:(UIGestureRecognizer*)gestureRecognizer {
}

- (CGRect)zoomRectForScale:(float)scale withCenter:(CGPoint)center {
    CGRect zoomRect;

    zoomRect.size.height = [scrollView frame].size.height / scale;
    zoomRect.size.width = [scrollView frame].size.width / scale;

    // choose an origin so as to get the right center.
    zoomRect.origin.x = center.x - (zoomRect.size.width / 2.0);
    zoomRect.origin.y = center.y - (zoomRect.size.height / 2.0);

    return zoomRect;
}

- (UIView*)viewForZoomingInScrollView:(UIScrollView*)scrollView {
    return imageView;
}

- (void)scrollViewDidEndZooming:(UIScrollView*)scrollView withView:(UIView*)view atScale:(CGFloat)scale {
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    self.numViewEventsFired += 1;
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    self.numViewEventsFired += 1;
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    self.numViewEventsFired += 1;
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    self.numViewEventsFired += 1;
}

@end
