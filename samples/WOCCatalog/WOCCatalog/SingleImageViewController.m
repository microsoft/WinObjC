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

#import "SingleImageViewController.h"

@implementation SingleImageViewController

- (id)init {
    self = [super init];
    return self;
}

- (id)initWithImage:(UIImage*)image {
    self = [self init];

    self->imageView = [[UIImageView alloc] initWithImage:image];

    return self;
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
}

- (void)createLayout {
    [scrollView setBackgroundColor:[UIColor whiteColor]];
}

- (void)scrollViewDidZoom:(UIScrollView*)aScrollView {
    // don't have to do anything special to centralize the imageView after zoom when zoomFactor is less than 1
    // xaml scrollview does that automatically now
}

- (void)handleDoubleTap:(UIGestureRecognizer*)gestureRecognizer {
    // zoom in
    float newScale = [scrollView zoomScale] * 2.0;

    if (newScale > scrollView.maximumZoomScale && scrollView.zoomScale != scrollView.minimumZoomScale) {
        newScale = scrollView.minimumZoomScale;
    } else {
        newScale = scrollView.maximumZoomScale;
    }

    CGPoint pointInView = [gestureRecognizer locationInView:gestureRecognizer.view];
    CGRect zoomRect = [self zoomRectForScale:newScale withCenter:pointInView];
    [scrollView zoomToRect:zoomRect animated:YES];
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

    NSLog(@"Center=[%f, %f], Scrollview fame=[%f, %f], RoomRect=[[%f,%f], [%f,%f]]",
          center.x,
          center.y,
          [scrollView frame].size.width,
          [scrollView frame].size.height,
          zoomRect.origin.x,
          zoomRect.origin.y,
          zoomRect.size.width,
          zoomRect.size.height);
    return zoomRect;
}

- (UIView*)viewForZoomingInScrollView:(UIScrollView*)scrollView {
    return imageView;
}

- (void)scrollViewDidEndZooming:(UIScrollView*)scrollView withView:(UIView*)view atScale:(CGFloat)scale {
}

@end