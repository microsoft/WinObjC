//******************************************************************************
//
// UICollectionView.h
// PSPDFKit
//
// Copyright (c) 2012-2013 Peter Steinberger. All rights reserved.
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

#pragma once

#import <UIKit/UIKit.h>
#import <UIKit/UIKitExport.h>

@class UICollectionViewLayout;
@class UICollectionViewLayoutAttributes;
@class UICollectionViewController;

enum _UICollectionViewScrollPosition {
    UICollectionViewScrollPositionNone = 0,

    // The vertical positions are mutually exclusive to each other, but are bitwise or-able with the horizontal scroll positions.
    // Combining positions from the same grouping (horizontal or vertical) will result in an NSInvalidArgumentException.
    UICollectionViewScrollPositionTop = 1 << 0,
    UICollectionViewScrollPositionCenteredVertically = 1 << 1,
    UICollectionViewScrollPositionBottom = 1 << 2,

    // Likewise, the horizontal positions are mutually exclusive to each other.
    UICollectionViewScrollPositionLeft = 1 << 3,
    UICollectionViewScrollPositionCenteredHorizontally = 1 << 4,
    UICollectionViewScrollPositionRight = 1 << 5
};
typedef NSUInteger UICollectionViewScrollPosition;

enum _UICollectionElementCategory {
    UICollectionElementCategoryCell,
    UICollectionElementCategorySupplementaryView,
    UICollectionElementCategoryDecorationView
};
typedef NSUInteger UICollectionElementCategory;

// Define the `UICollectionViewDisableForwardToUICollectionViewSentinel` to disable the automatic forwarding to UICollectionView on iOS 6+.
// (Copy below line into your AppDelegate.m)
//@interface UICollectionViewDisableForwardToUICollectionViewSentinel : NSObject @end @implementation
//UICollectionViewDisableForwardToUICollectionViewSentinel @end

// API-compatible replacement for UICollectionView.
// Works on iOS 4.3 upwards (including iOS 6).
UIKIT_EXPORT_CLASS
@interface UICollectionView : UIScrollView <UIScrollViewDelegate>

- (id)initWithFrame:(CGRect)frame collectionViewLayout:(UICollectionViewLayout*)layout; // the designated initializer

@property (nonatomic, strong) UICollectionViewLayout* collectionViewLayout;
@property (nonatomic, assign) IBOutlet id<UICollectionViewDelegate> delegate;
@property (nonatomic, assign) IBOutlet id<UICollectionViewDataSource> dataSource;
@property (nonatomic, strong) UIView* backgroundView; // will be automatically resized to track the size of the collection view and placed
                                                      // behind all cells and supplementary views.

// For each reuse identifier that the collection view will use, register either a class or a nib from which to instantiate a cell.
// If a nib is registered, it must contain exactly 1 top level object which is a UICollectionViewCell.
// If a class is registered, it will be instantiated via alloc/initWithFrame:
- (void)registerClass:(Class)cellClass forCellWithReuseIdentifier:(NSString*)identifier;

- (void)registerClass:(Class)viewClass forSupplementaryViewOfKind:(NSString*)elementKind withReuseIdentifier:(NSString*)identifier;

- (void)registerNib:(UINib*)nib forCellWithReuseIdentifier:(NSString*)identifier;

// TODO: implement!
- (void)registerNib:(UINib*)nib forSupplementaryViewOfKind:(NSString*)kind withReuseIdentifier:(NSString*)identifier;

- (id)dequeueReusableCellWithReuseIdentifier:(NSString*)identifier forIndexPath:(NSIndexPath*)indexPath;

- (id)dequeueReusableSupplementaryViewOfKind:(NSString*)elementKind
                         withReuseIdentifier:(NSString*)identifier
                                forIndexPath:(NSIndexPath*)indexPath;

// These properties control whether items can be selected, and if so, whether multiple items can be simultaneously selected.
@property (nonatomic) BOOL allowsSelection; // default is YES
@property (nonatomic) BOOL allowsMultipleSelection; // default is NO

- (NSArray*)indexPathsForSelectedItems; // returns nil or an array of selected index paths
- (void)selectItemAtIndexPath:(NSIndexPath*)indexPath animated:(BOOL)animated scrollPosition:(UICollectionViewScrollPosition)scrollPosition;

- (void)deselectItemAtIndexPath:(NSIndexPath*)indexPath animated:(BOOL)animated;

- (void)reloadData; // discard the dataSource and delegate data and requery as necessary

- (void)setCollectionViewLayout:(UICollectionViewLayout*)layout animated:(BOOL)animated; // transition from one layout to another

// Information about the current state of the collection view.

- (NSInteger)numberOfSections;

- (NSInteger)numberOfItemsInSection:(NSInteger)section;

- (UICollectionViewLayoutAttributes*)layoutAttributesForItemAtIndexPath:(NSIndexPath*)indexPath;

- (UICollectionViewLayoutAttributes*)layoutAttributesForSupplementaryElementOfKind:(NSString*)kind atIndexPath:(NSIndexPath*)indexPath;

- (NSIndexPath*)indexPathForItemAtPoint:(CGPoint)point;

- (NSIndexPath*)indexPathForCell:(UICollectionViewCell*)cell;

- (UICollectionViewCell*)cellForItemAtIndexPath:(NSIndexPath*)indexPath;

- (NSArray*)visibleCells;

- (NSArray*)indexPathsForVisibleItems;

// Interacting with the collection view.

- (void)scrollToItemAtIndexPath:(NSIndexPath*)indexPath
               atScrollPosition:(UICollectionViewScrollPosition)scrollPosition
                       animated:(BOOL)animated;

// These methods allow dynamic modification of the current set of items in the collection view
- (void)insertSections:(NSIndexSet*)sections;
- (void)deleteSections:(NSIndexSet*)sections;
- (void)reloadSections:(NSIndexSet*)sections;
- (void)moveSection:(NSInteger)section toSection:(NSInteger)newSection;
- (void)insertItemsAtIndexPaths:(NSArray*)indexPaths;
- (void)deleteItemsAtIndexPaths:(NSArray*)indexPaths;
- (void)reloadItemsAtIndexPaths:(NSArray*)indexPaths;
- (void)moveItemAtIndexPath:(NSIndexPath*)indexPath toIndexPath:(NSIndexPath*)newIndexPath;
- (void)performBatchUpdates:(void (^)(void))updates
                 completion:(void (^)(BOOL finished))
                                completion; // allows multiple insert/delete/reload/move calls to be animated simultaneously. Nestable.

@end
