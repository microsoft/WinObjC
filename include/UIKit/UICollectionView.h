//******************************************************************************
//
// UICollectionView.h
// PSPDFKit
//
// Copyright (c) 2012-2013 Peter Steinberger. All rights reserved.
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
#pragma once

#import <UIKit/UIKitExport.h>
#import <UIKit/UICollectionViewLayout.h>
#import <UIKit/UICollectionViewUpdateItem.h>
#import <UIKit/UICollectionViewLayoutAttributes.h>
#import <UIKit/UIScrollView.h>

@class UICollectionViewLayout, UICollectionViewLayoutAttributes, UICollectionViewController, UICollectionViewCell,
    UICollectionViewTransitionLayout;
@protocol UICollectionViewDelegate
, UICollectionViewDataSource;

typedef void (^UICollectionViewLayoutInteractiveTransitionCompletion)(BOOL completed, BOOL finish);

typedef NSUInteger UICollectionViewScrollPosition;
enum {
    UICollectionViewScrollPositionNone = 0,
    UICollectionViewScrollPositionTop = 1 << 0,
    UICollectionViewScrollPositionCenteredVertically = 1 << 1,
    UICollectionViewScrollPositionBottom = 1 << 2,
    UICollectionViewScrollPositionLeft = 1 << 3,
    UICollectionViewScrollPositionCenteredHorizontally = 1 << 4,
    UICollectionViewScrollPositionRight = 1 << 5,
};

UIKIT_EXPORT_CLASS
@interface UICollectionView : UIScrollView <NSCoding,
                                            NSObject,
                                            UIAppearance,
                                            UIAppearanceContainer,
                                            UICoordinateSpace,
                                            UIDynamicItem,
                                            UIFocusEnvironment,
                                            UITraitEnvironment>

- (BOOL)beginInteractiveMovementForItemAtIndexPath:(NSIndexPath*)indexPath STUB_METHOD;
- (NSArray*)indexPathsForSelectedItems;
- (NSArray*)indexPathsForVisibleItems;
- (NSArray*)indexPathsForVisibleSupplementaryElementsOfKind:(NSString*)elementKind STUB_METHOD;
- (NSArray*)visibleCells;
- (NSArray*)visibleSupplementaryViewsOfKind:(NSString*)elementKind STUB_METHOD;
- (NSIndexPath*)indexPathForCell:(UICollectionViewCell*)cell;
- (NSIndexPath*)indexPathForItemAtPoint:(CGPoint)point;
- (NSInteger)numberOfItemsInSection:(NSInteger)section;
- (NSInteger)numberOfSections;
- (UICollectionReusableView*)dequeueReusableSupplementaryViewOfKind:(NSString*)elementKind
                                                withReuseIdentifier:(NSString*)identifier
                                                       forIndexPath:(NSIndexPath*)indexPath;
- (UICollectionReusableView*)supplementaryViewForElementKind:(NSString*)elementKind atIndexPath:(NSIndexPath*)indexPath STUB_METHOD;
- (UICollectionViewCell*)cellForItemAtIndexPath:(NSIndexPath*)indexPath;
- (UICollectionViewCell*)dequeueReusableCellWithReuseIdentifier:(NSString*)identifier forIndexPath:(NSIndexPath*)indexPath;
- (UICollectionViewLayoutAttributes*)layoutAttributesForItemAtIndexPath:(NSIndexPath*)indexPath;
- (UICollectionViewLayoutAttributes*)layoutAttributesForSupplementaryElementOfKind:(NSString*)kind atIndexPath:(NSIndexPath*)indexPath;
- (UICollectionViewTransitionLayout*)
startInteractiveTransitionToCollectionViewLayout:(UICollectionViewLayout*)layout
                                      completion:(UICollectionViewLayoutInteractiveTransitionCompletion)completion STUB_METHOD;
- (instancetype)initWithFrame:(CGRect)frame collectionViewLayout:(UICollectionViewLayout*)layout;
- (void)cancelInteractiveMovement STUB_METHOD;
- (void)cancelInteractiveTransition STUB_METHOD;
- (void)deleteItemsAtIndexPaths:(NSArray*)indexPaths;
- (void)deleteSections:(NSIndexSet*)sections;
- (void)deselectItemAtIndexPath:(NSIndexPath*)indexPath animated:(BOOL)animated;
- (void)endInteractiveMovement STUB_METHOD;
- (void)finishInteractiveTransition STUB_METHOD;
- (void)insertItemsAtIndexPaths:(NSArray*)indexPaths;
- (void)insertSections:(NSIndexSet*)sections;
- (void)moveItemAtIndexPath:(NSIndexPath*)indexPath toIndexPath:(NSIndexPath*)newIndexPath;
- (void)moveSection:(NSInteger)section toSection:(NSInteger)newSection;
- (void)performBatchUpdates:(void (^)(void))updates completion:(void (^)(BOOL finished))completion;
- (void)registerClass:(Class)cellClass forCellWithReuseIdentifier:(NSString*)identifier;
- (void)registerClass:(Class)viewClass forSupplementaryViewOfKind:(NSString*)elementKind withReuseIdentifier:(NSString*)identifier;
- (void)registerNib:(UINib*)nib forCellWithReuseIdentifier:(NSString*)identifier;
- (void)registerNib:(UINib*)nib forSupplementaryViewOfKind:(NSString*)kind withReuseIdentifier:(NSString*)identifier;
- (void)reloadData;
- (void)reloadItemsAtIndexPaths:(NSArray*)indexPaths;
- (void)reloadSections:(NSIndexSet*)sections;
- (void)scrollToItemAtIndexPath:(NSIndexPath*)indexPath
               atScrollPosition:(UICollectionViewScrollPosition)scrollPosition
                       animated:(BOOL)animated;
- (void)selectItemAtIndexPath:(NSIndexPath*)indexPath animated:(BOOL)animated scrollPosition:(UICollectionViewScrollPosition)scrollPosition;
- (void)setCollectionViewLayout:(UICollectionViewLayout*)layout animated:(BOOL)animated completion:(void (^)(BOOL))completion STUB_METHOD;
- (void)setCollectionViewLayout:(UICollectionViewLayout*)layout animated:(BOOL)animated; // transition from one layout to another
- (void)updateInteractiveMovementTargetPosition:(CGPoint)targetPosition STUB_METHOD;

@property (nonatomic) BOOL allowsMultipleSelection;
@property (nonatomic) BOOL allowsSelection;
@property (nonatomic) BOOL remembersLastFocusedIndexPath STUB_PROPERTY;
@property (nonatomic, assign) IBOutlet id<UICollectionViewDataSource> dataSource;
@property (nonatomic, assign) IBOutlet id<UICollectionViewDelegate> delegate;
@property (nonatomic, strong) UICollectionViewLayout* collectionViewLayout;
@property (nonatomic, strong) UIView* backgroundView;

@end
