//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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
#import <CoreImage/CIImage.h>
#import <CoreImage/CIContext.h>
#import <CoreGraphics/CGImage.h>
#import <Accelerate/Accelerate.h>

@implementation ImagesViewController

+ (UIImage*)scaleImage:(CGImageRef)imageRef scaledRect:(CGRect)rect quality:(CGInterpolationQuality)quality {
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();

    CGContextSetInterpolationQuality(context, quality);
    CGAffineTransform flipVertical = CGAffineTransformMake(1, 0, 0, -1, 0, rect.size.height);
    CGContextConcatCTM(context, flipVertical);
    CGContextDrawImage(context, rect, imageRef);
    CGImageRef scaledImageRef = CGBitmapContextCreateImage(context);
    UIImage* scaledImage = [UIImage imageWithCGImage:scaledImageRef];
    CGImageRelease(scaledImageRef);

    UIGraphicsEndImageContext();

    return scaledImage;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor blackColor];
    CGRect rect = CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height);
    UIImageView* imagesView = [[UIImageView alloc] initWithFrame:rect];
    UIImage* photo = [UIImage imageNamed:@"photo9.jpg"];
    UIImage* scaledPhotoHighInterpolation = [ImagesViewController scaleImage:photo.CGImage scaledRect:rect quality:kCGInterpolationHigh];
    UIImage* scaledPhotoNoInterpolation = [ImagesViewController scaleImage:photo.CGImage scaledRect:rect quality:kCGInterpolationNone];

    CIContext* context = [CIContext contextWithOptions:nil];
    photo = [UIImage imageNamed:@"photo2.png"];
    CIImage* ciImage = [CIImage imageWithCGImage:photo.CGImage];
    CGImageRef cgImage = [context createCGImage:ciImage fromRect:CGRectMake(300, 600, 200, 200)];

    imagesView.animationImages = [NSArray arrayWithObjects:scaledPhotoHighInterpolation,
                                                           scaledPhotoNoInterpolation,
                                                           [UIImage imageNamed:@"photo1.jpg"],
                                                           [UIImage imageNamed:@"photo2.png"],
                                                           [UIImage imageWithCGImage:cgImage],
                                                           [UIImage imageNamed:@"photo3.jpg"],
                                                           [UIImage imageNamed:@"photo4.jpg"],
                                                           [UIImage imageNamed:@"photo5.jpg"],
                                                           [UIImage imageNamed:@"photo6.jpg"],
                                                           [UIImage imageNamed:@"photo7.gif"],
                                                           [UIImage imageNamed:@"photo8.tif"],
                                                           nil];

    imagesView.animationDuration = 10.0;

    [imagesView setContentMode:UIViewContentModeScaleAspectFit];
    [imagesView startAnimating];
    imagesView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [[self view] addSubview:imagesView];
}

@end
