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
#import "PhotogridViewController.h"
#import "SingleImageViewController.h"

@interface PhotoLayout : UICollectionViewFlowLayout
@end

@implementation PhotoLayout

- (id)init {
    self = [super init];

    self.itemSize = CGSizeMake(140, 140);
    self.sectionInset = UIEdgeInsetsMake(10, 10, 10, 10);
    self.minimumInteritemSpacing = 5.0f;
    self.minimumLineSpacing = 10.0f;

    [self setScrollDirection:UICollectionViewScrollDirectionVertical];

    return self;
}

@end

@implementation PhotoCell

- (id)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];

    self.imageView = [[UIImageView alloc] initWithFrame:CGRectInset(CGRectMake(0, 0, CGRectGetWidth(frame), CGRectGetHeight(frame)), 5, 5)];

    self.imageView.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;
    self.imageView.layer.masksToBounds = YES;
    self.imageView.layer.contentsGravity = kCAGravityResizeAspectFill;
    [self.contentView addSubview:self.imageView];

    self.backgroundColor = [UIColor whiteColor];

    return self;
}

- (void)setImage:(UIImage*)image {
    self.imageView.image = image;
}

@end

@implementation PhotogridViewController

- (id)init {
    self = [super init];
    self.collectionView = [[UICollectionView alloc] initWithFrame:CGRectZero collectionViewLayout:[[PhotoLayout alloc] init]];
    [self.collectionView setDataSource:self];
    [self.collectionView setDelegate:self];
    [self.collectionView registerClass:[PhotoCell class] forCellWithReuseIdentifier:@"photoCell"];

    [self setTitle:@"Canada"];

    images = [NSArray arrayWithObjects:[[UIImage imageNamed:@"photo1.jpg"] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal],
                                       [UIImage imageNamed:@"photo2.jpg"],
                                       [UIImage imageNamed:@"photo3.jpg"],
                                       [UIImage imageNamed:@"photo4.jpg"],
                                       [UIImage imageNamed:@"photo5.jpg"],
                                       [UIImage imageNamed:@"photo6.jpg"],
                                       [UIImage imageNamed:@"photo7.gif"],
                                       [UIImage imageNamed:@"photo8.tif"],
                                       nil];

    return self;
}

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView*)collectionView {
    return 1;
}

- (NSInteger)collectionView:(UICollectionView*)collectionView numberOfItemsInSection:(NSInteger)section {
    return [images count];
}

- (UICollectionViewCell*)collectionView:(UICollectionView*)collectionView cellForItemAtIndexPath:(NSIndexPath*)indexPath {
    PhotoCell* pc = [collectionView dequeueReusableCellWithReuseIdentifier:@"photoCell" forIndexPath:indexPath];
    [pc setImage:[images objectAtIndex:indexPath.item]];

    return pc;
}

- (void)collectionView:(UICollectionView*)collectionView didSelectItemAtIndexPath:(NSIndexPath*)indexPath {
    SingleImageViewController* imvc = [[SingleImageViewController alloc] initWithImage:[images objectAtIndex:indexPath.item]];

    [self.navigationController pushViewController:imvc animated:YES];
    [[imvc view] setNeedsLayout];
}

@end