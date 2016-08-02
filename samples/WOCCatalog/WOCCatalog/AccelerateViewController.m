//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
//
// Copyright (c) 2013 Ryan Nystrom (http://whoisryannystrom.com)
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
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

#import "AccelerateViewController.h"
#import "SingleImageViewController.h"

static const double meanDivisor = 100;

@implementation AccelerateViewController {
    int _accelerateImageNumber;
    int _valueRed;
    int _valueGreen;
    int _valueBlue;
    int _convolveSize;
    NSArray* _indexPathArray;
    UIImage* _img;
    UIImageView* _imv;
    UISlider* _redSlider;
    UISlider* _greenSlider;
    UISlider* _blueSlider;
    UISlider* _convolveSlider;
    UILabel* _rLabel;
    UILabel* _gLabel;
    UILabel* _bLabel;
    UILabel* _boxLabel;
}
- (void)viewDidLoad {
    [super viewDidLoad];

    _accelerateImageNumber = 1;
    _valueRed = 100;
    _valueGreen = 100;
    _valueBlue = 100;
    _convolveSize = 1;

    _redSlider = [[UISlider alloc] initWithFrame:CGRectMake(5.0, 12.0, 180.0, 38.0)];
    _redSlider.backgroundColor = [UIColor clearColor];
    _redSlider.minimumValue = 0.0;
    _redSlider.maximumValue = 200.0;
    _redSlider.continuous = YES;
    _redSlider.value = 100.0;

    _greenSlider = [[UISlider alloc] initWithFrame:CGRectMake(5.0, 12.0, 180.0, 38.0)];
    _greenSlider.backgroundColor = [UIColor clearColor];
    _greenSlider.minimumValue = 0.0;
    _greenSlider.maximumValue = 200.0;
    _greenSlider.continuous = YES;
    _greenSlider.value = 100.0;

    _blueSlider = [[UISlider alloc] initWithFrame:CGRectMake(5.0, 12.0, 180.0, 38.0)];
    _blueSlider.backgroundColor = [UIColor clearColor];
    _blueSlider.minimumValue = 0.0;
    _blueSlider.maximumValue = 200.0;
    _blueSlider.continuous = YES;
    _blueSlider.value = 100.0;

    _convolveSlider = [[UISlider alloc] initWithFrame:CGRectMake(5.0, 12.0, 180.0, 38.0)];
    _convolveSlider.backgroundColor = [UIColor clearColor];
    _convolveSlider.minimumValue = 1.0;
    _convolveSlider.maximumValue = 99.0;
    _convolveSlider.continuous = YES;
    _convolveSlider.value = 1.0;

    [_redSlider addTarget:self action:@selector(redChanged:) forControlEvents:UIControlEventValueChanged];
    [_redSlider setContinuous:NO];
    [_greenSlider addTarget:self action:@selector(greenChanged:) forControlEvents:UIControlEventValueChanged];
    [_greenSlider setContinuous:NO];
    [_blueSlider addTarget:self action:@selector(blueChanged:) forControlEvents:UIControlEventValueChanged];
    [_blueSlider setContinuous:NO];
    [_convolveSlider addTarget:self action:@selector(convolveChanged:) forControlEvents:UIControlEventValueChanged];
    [_convolveSlider setContinuous:NO];

    _rLabel = [[UILabel alloc] init];
    _gLabel = [[UILabel alloc] init];
    _bLabel = [[UILabel alloc] init];
    _boxLabel = [[UILabel alloc] init];

    _img = [UIImage imageNamed:[NSString stringWithFormat:@"photo%d.jpg", _accelerateImageNumber]];
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 8;
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    CGRect screenRect = [[UIScreen mainScreen] bounds];

    if (indexPath.row == 1) {
        return screenRect.size.height - 360;
    }

    return 40;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];

    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    }

    if (indexPath.row == 0) {
        // Title cell

        cell.textLabel.text = @"Accelerate Sample";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    } else if (indexPath.row == 1) {
        // Image display box

        UIImage* transformImg = [self transformImage:_img];
        _imv = [[UIImageView alloc] initWithFrame:CGRectMake(3, 2, cell.bounds.size.width - 6.0f, cell.bounds.size.height - 4.0f)];
        _imv.image = transformImg;

        [_imv setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
        [cell addSubview:_imv];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;

    } else if (indexPath.row == 2) {
        // Red controls

        cell.textLabel.text = [NSString stringWithFormat:@"Red"];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.accessoryView = _redSlider;
    } else if (indexPath.row == 3) {
        // Green controls

        cell.textLabel.text = [NSString stringWithFormat:@"Green"];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.accessoryView = _greenSlider;
    } else if (indexPath.row == 4) {
        // Blue controls

        cell.textLabel.text = [NSString stringWithFormat:@"Blue"];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.accessoryView = _blueSlider;
    } else if (indexPath.row == 5) {
        // Box convolve controls

        cell.textLabel.text = [NSString stringWithFormat:@"Blur"];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.accessoryView = _convolveSlider;
    } else if (indexPath.row == 6) {
        // Labels

        [_rLabel removeFromSuperview];
        [_gLabel removeFromSuperview];
        [_bLabel removeFromSuperview];
        [_boxLabel removeFromSuperview];

        _rLabel.text = [NSString stringWithFormat:@"R: %d%%", _valueRed];
        _gLabel.text = [NSString stringWithFormat:@"G: %d%%", _valueGreen];
        _bLabel.text = [NSString stringWithFormat:@"B: %d%%", _valueBlue];
        _boxLabel.text = [NSString stringWithFormat:@"Kernel Size: %d", _convolveSize];

        _rLabel.frame = CGRectMake(17.0f, 5.0f, 100.0f, cell.bounds.size.height - 5.0f);
        _gLabel.frame = CGRectMake(92.0f, 5.0f, 100.0f, cell.bounds.size.height - 5.0f);
        _bLabel.frame = CGRectMake(167.0f, 5.0f, 100.0f, cell.bounds.size.height - 5.0f);
        _boxLabel.frame = CGRectMake(242.0f, 5.0f, 200.0f, cell.bounds.size.height - 5.0f);

        [_rLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight];
        [_gLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight];
        [_bLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight];
        [_boxLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight];

        [cell addSubview:_rLabel];
        [cell addSubview:_gLabel];
        [cell addSubview:_bLabel];
        [cell addSubview:_boxLabel];

    } else if (indexPath.row == 7) {
        // Select Image

        UIButton* imageChange = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        imageChange.frame = CGRectMake(10.0f, 5.0f, 120.0f, cell.bounds.size.height - 15.0f);
        imageChange.layer.cornerRadius = 5.0f;
        imageChange.backgroundColor = [UIColor lightGrayColor];
        [imageChange setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [imageChange setTitle:@"Select Image" forState:UIControlStateNormal];

        [cell addSubview:imageChange];

        [imageChange addTarget:self action:@selector(imageChangePress) forControlEvents:UIControlEventTouchUpInside];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    }

    return cell;
}

- (void)redChanged:(UISlider*)slider {
    if (_valueRed != slider.value) {
        _valueRed = slider.value;
        _rLabel.text = [NSString stringWithFormat:@"R: %d%%", _valueRed];
        [self changeImageCell];
    }
}

- (void)greenChanged:(UISlider*)slider {
    if (_valueGreen != slider.value) {
        _valueGreen = slider.value;
        _gLabel.text = [NSString stringWithFormat:@"G: %d%%", _valueGreen];
        [self changeImageCell];
    }
}

- (void)blueChanged:(UISlider*)slider {
    if (_valueBlue != slider.value) {
        _valueBlue = slider.value;
        _bLabel.text = [NSString stringWithFormat:@"B: %d%%", _valueBlue];
        [self changeImageCell];
    }
}

- (void)convolveChanged:(UISlider*)slider {
    int oldValue = _convolveSize;
    _convolveSize = (int)slider.value;
    _convolveSize += (_convolveSize % 2) - 1;

    if (oldValue != _convolveSize) {
        _boxLabel.text = [NSString stringWithFormat:@"Kernel Size: %d", _convolveSize];
        [self changeImageCell];
    }
}

- (void)imageChangePress {
    PhotoSelectorController* photoView = [[PhotoSelectorController alloc] init];
    photoView.delegate = self;
    [self.navigationController pushViewController:photoView animated:NO];
}

- (void)imageFromController:(UIImage*)image {
    _img = image;
    _indexPathArray = [NSArray arrayWithObject:[NSIndexPath indexPathForRow:1 inSection:0]];
    [self.tableView reloadRowsAtIndexPaths:_indexPathArray withRowAnimation:UITableViewRowAnimationNone];
}

- (void)changeImageCell {
    UIImage* transformImg = [self transformImage:_img];
    [_imv setImage:transformImg];
}

- (UIImage*)transformImage:(UIImage*)image {
    CGImageRef _localImg = image.CGImage;
    vImage_Buffer inBuffer, midBuffer, outBuffer;
    vImage_Error error;
    void *pixelBuffer, *midPixelBuffer;

    // Create input vImage_Buffer with data from CGImageRef
    CGDataProviderRef inProvider = CGImageGetDataProvider(_localImg);
    CFDataRef inBitmapData = CGDataProviderCopyData(inProvider);

    inBuffer.width = CGImageGetWidth(_localImg);
    inBuffer.height = CGImageGetHeight(_localImg);
    inBuffer.rowBytes = CGImageGetBytesPerRow(_localImg);

    inBuffer.data = (void*)CFDataGetBytePtr(inBitmapData);

    // Create output vImage_Buffer
    midPixelBuffer = malloc(CGImageGetBytesPerRow(_localImg) * CGImageGetHeight(_localImg));
    pixelBuffer = malloc(CGImageGetBytesPerRow(_localImg) * CGImageGetHeight(_localImg));

    if (midPixelBuffer == NULL) {
        NSLog(@"No midpixelbuffer");
    }
    if (pixelBuffer == NULL) {
        NSLog(@"No pixelbuffer");
    }

    midBuffer.data = midPixelBuffer;
    midBuffer.width = CGImageGetWidth(_localImg);
    midBuffer.height = CGImageGetHeight(_localImg);
    midBuffer.rowBytes = CGImageGetBytesPerRow(_localImg);

    outBuffer.data = pixelBuffer;
    outBuffer.width = CGImageGetWidth(_localImg);
    outBuffer.height = CGImageGetHeight(_localImg);
    outBuffer.rowBytes = CGImageGetBytesPerRow(_localImg);

    const CGImageAlphaInfo alphaInfo = CGImageGetAlphaInfo(_localImg);
    const CGBitmapInfo bitmapInfo = CGImageGetBitmapInfo(_localImg);
    const int byteOrder = bitmapInfo & kCGBitmapByteOrderMask;

    unsigned int redIndex, greenIndex, blueIndex, alphaIndex;

    // Use the byteorder and alpha info of the input image to get the byte index of each component
    if (byteOrder == kCGBitmapByteOrder32Big) {
        // RGBX or XRGB
        if (alphaInfo == kCGImageAlphaLast || alphaInfo == kCGImageAlphaNoneSkipLast) {
            alphaIndex = 0;
            redIndex = 3;
            greenIndex = 2;
            blueIndex = 1;
        } else {
            alphaIndex = 3;
            redIndex = 2;
            greenIndex = 1;
            blueIndex = 0;
        }
    } else {
        // XBGR or BGRX
        if (alphaInfo == kCGImageAlphaLast || alphaInfo == kCGImageAlphaNoneSkipLast) {
            alphaIndex = 3;
            redIndex = 0;
            greenIndex = 1;
            blueIndex = 2;
        } else {
            alphaIndex = 0;
            redIndex = 1;
            greenIndex = 2;
            blueIndex = 3;
        }
    }

    // Convert the component index to the matrix diagonal index and set the appropriate values for each component
    int16_t A[16] = { 0 };
    A[(alphaIndex << 2) + alphaIndex] = 100;
    A[(redIndex << 2) + redIndex] = _valueRed;
    A[(greenIndex << 2) + greenIndex] = _valueGreen;
    A[(blueIndex << 2) + blueIndex] = _valueBlue;

    error = vImageMatrixMultiply_ARGB8888(&inBuffer, &midBuffer, A, meanDivisor, NULL, NULL, 0);

    if (error) {
        NSLog(@"error from matrix multiply %ld", error);
    }

    Pixel_8888 background;
    background[0] = 0;
    background[1] = 0;
    background[2] = 0;
    background[3] = 0;

    // Perform convolution
    error = vImageBoxConvolve_ARGB8888(&midBuffer, &outBuffer, NULL, 0, 0, _convolveSize, _convolveSize, background, kvImageEdgeExtend);

    if (error) {
        NSLog(@"error from convolution %ld", error);
    }

    // Create CGImageRef from vImage_Buffer output
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();

    CGContextRef ctx =
        CGBitmapContextCreate(outBuffer.data, outBuffer.width, outBuffer.height, 8, outBuffer.rowBytes, colorSpace, bitmapInfo);

    CGImageRef imageRef = CGBitmapContextCreateImage(ctx);

    UIImage* returnImage = [UIImage imageWithCGImage:imageRef];

    // Clean up
    CGContextRelease(ctx);
    CGColorSpaceRelease(colorSpace);
    free(midPixelBuffer);
    free(pixelBuffer);
    CFRelease(inBitmapData);
    CGImageRelease(imageRef);

    return returnImage;
}
@end

@interface SelectorLayout : UICollectionViewFlowLayout
@end

@implementation SelectorLayout

- (instancetype)init {
    if (self = [super init]) {
        self.itemSize = CGSizeMake(140, 140);
        self.sectionInset = UIEdgeInsetsMake(10, 10, 10, 10);
        self.minimumInteritemSpacing = 5.0f;
        self.minimumLineSpacing = 10.0f;

        [self setScrollDirection:UICollectionViewScrollDirectionVertical];
    }

    return self;
}
@end

@implementation SelectorCell

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        self.imageView =
            [[UIImageView alloc] initWithFrame:CGRectInset(CGRectMake(0, 0, CGRectGetWidth(frame), CGRectGetHeight(frame)), 5, 5)];

        self.imageView.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;
        self.imageView.layer.masksToBounds = YES;
        self.imageView.layer.contentsGravity = kCAGravityResizeAspectFill;
        [self.contentView addSubview:self.imageView];

        self.backgroundColor = [UIColor whiteColor];
    }

    return self;
}

- (void)setImage:(UIImage*)image {
    self.imageView.image = image;
}
@end

@implementation PhotoSelectorController {
    NSArray* images;
}

@synthesize delegate = _delegate;

- (instancetype)init {
    if (self = [super init]) {
        self.collectionView = [[UICollectionView alloc] initWithFrame:CGRectZero collectionViewLayout:[[SelectorLayout alloc] init]];
        [self.collectionView setDataSource:self];
        [self.collectionView setDelegate:self];
        [self.collectionView registerClass:[SelectorCell class] forCellWithReuseIdentifier:@"photoCell"];

        images = [NSArray arrayWithObjects:[[UIImage imageNamed:@"photo1.jpg"] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal],
                                           [UIImage imageNamed:@"photo2.jpg"],
                                           [UIImage imageNamed:@"photo3.jpg"],
                                           [UIImage imageNamed:@"photo4.jpg"],
                                           [UIImage imageNamed:@"photo5.jpg"],
                                           [UIImage imageNamed:@"photo6.jpg"],
                                           [UIImage imageNamed:@"photo7.gif"],
                                           [UIImage imageNamed:@"photo8.tif"],
                                           nil];
    }

    return self;
}

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView*)collectionView {
    return 1;
}

- (NSInteger)collectionView:(UICollectionView*)collectionView numberOfItemsInSection:(NSInteger)section {
    return [images count];
}

- (UICollectionViewCell*)collectionView:(UICollectionView*)collectionView cellForItemAtIndexPath:(NSIndexPath*)indexPath {
    SelectorCell* pc = [collectionView dequeueReusableCellWithReuseIdentifier:@"photoCell" forIndexPath:indexPath];
    [pc setImage:[images objectAtIndex:indexPath.item]];

    return pc;
}

- (void)collectionView:(UICollectionView*)collectionView didSelectItemAtIndexPath:(NSIndexPath*)indexPath {
    if ([_delegate respondsToSelector:@selector(imageFromController:)]) {
        [_delegate imageFromController:[images objectAtIndex:indexPath.item]];
    }

    [self.navigationController popViewControllerAnimated:NO];
}
@end