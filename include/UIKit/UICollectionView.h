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

#ifndef _UICOLLECTIONVIEW_H_
#define _UICOLLECTIONVIEW_H_

#import "UIKitExport.h"
#import <stdint.h> // uint32_t

enum {
    UICollectionViewScrollPositionNone = 0,
    UICollectionViewScrollPositionTop = 1 << 0,
    UICollectionViewScrollPositionCenteredVertically = 1 << 1,
    UICollectionViewScrollPositionBottom = 1 << 2,
    UICollectionViewScrollPositionLeft = 1 << 3,
    UICollectionViewScrollPositionCenteredHorizontally = 1 << 4,
    UICollectionViewScrollPositionRight = 1 << 5
};
typedef uint32_t UICollectionViewScrollPosition;

@class UICollectionView;
@class UICollectionViewCell;
@class UICollectionViewLayout;
@class UICollectionViewData;

@interface UICollectionViewDataSource : NSObject
- (uint32_t) collectionView: (UICollectionView *)view numberOfItemsInSection: (NSInteger) section;
- (uint32_t) numberOfSectionsInCollectionView: (UICollectionView*) view;
@end

@protocol UICollectionViewDelegate <UIScrollViewDelegate>
- (BOOL)collectionView:(UICollectionView *)collectionView shouldSelectItemAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)collectionView:(UICollectionView *)collectionView shouldDeselectItemAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)collectionView:(UICollectionView *)collectionView shouldHighlightItemAtIndexPath:(NSIndexPath *)indexPath;
@end

UIKIT_EXPORT_CLASS
@interface UICollectionView : UIScrollView 

- (UICollectionViewCell *)cellForItemAtIndexPath:(NSIndexPath *)indexPath;

- (id)dequeueReusableCellWithReuseIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath*)indexPath;
- (id)dequeueReusableSupplementaryViewOfKind:(NSString*)elementKind withReuseIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath*)indexPath;
- (NSArray *)indexPathsForSelectedItems;
- (id)initWithFrame:(CGRect)frame collectionViewLayout:(UICollectionViewLayout *)layout;

- (void)reloadData;
- (void)reloadSections:(NSIndexSet *)sections;

- (void)performBatchUpdates:(void (^)(void))updates completion:(void (^)(BOOL finished))completion;

- (void)registerClass:(Class)viewClass forSupplementaryViewOfKind:(NSString *)elementKind withReuseIdentifier:(NSString *)identifier;
- (void)registerClass:(Class)viewClass forCellWithReuseIdentifier:(NSString*)identifier;
- (void)registerNib:(UINib *)nib forCellWithReuseIdentifier:(NSString *)identifier;
- (void)registerNib:(UINib *)nib forSupplementaryViewOfKind:(NSString *)kind withReuseIdentifier:(NSString *)identifier;

- (void)deselectItemAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;

- (void)scrollToItemAtIndexPath:(NSIndexPath *)indexPath atScrollPosition:(UICollectionViewScrollPosition)scrollPosition animated:(BOOL)animated;

- (void)insertItemsAtIndexPaths:(NSArray *)indexPaths;
- (void)deleteItemsAtIndexPaths:(NSArray *)indexPaths;

- (NSInteger)numberOfSections;
- (NSInteger)numberOfItemsInSection:(NSInteger)section;

- (CGRect)visibleBoundRects;

@property (nonatomic, retain) UICollectionViewLayout *collectionViewLayout;
@property (nonatomic, assign) UICollectionViewDataSource *dataSource;
@property (nonatomic) BOOL allowsSelection;
@property (nonatomic) BOOL allowsMultipleSelection;

@end

@protocol UICollectionViewDataSource <NSObject>
@end

@interface NSIndexPath (UICollectionViewAdditions)

+ (NSIndexPath *)indexPathForItem:(NSInteger)item inSection:(NSInteger)section;

@property (nonatomic, readonly) NSInteger item;

@end

#endif /* _UICOLLECTIONVIEW_H_ */
