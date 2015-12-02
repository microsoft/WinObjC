//******************************************************************************
//
// UICollectionViewFlowLayout.h
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

UIKIT_EXPORT extern NSString* const UICollectionElementKindSectionHeader;
UIKIT_EXPORT extern NSString* const UICollectionElementKindSectionFooter;

enum _UICollectionViewScrollDirection { UICollectionViewScrollDirectionVertical, UICollectionViewScrollDirectionHorizontal };
typedef NSInteger UICollectionViewScrollDirection;

@protocol UICollectionViewDelegateFlowLayout <UICollectionViewDelegate>
@optional

/**
   @Status Interoperable
*/
- (CGSize)collectionView:(UICollectionView*)collectionView
                  layout:(UICollectionViewLayout*)collectionViewLayout
  sizeForItemAtIndexPath:(NSIndexPath*)indexPath;

/**
   @Status Interoperable
*/
- (UIEdgeInsets)collectionView:(UICollectionView*)collectionView
                        layout:(UICollectionViewLayout*)collectionViewLayout
        insetForSectionAtIndex:(NSInteger)section;

/**
   @Status Interoperable
*/
- (CGFloat)collectionView:(UICollectionView*)collectionView
                                 layout:(UICollectionViewLayout*)collectionViewLayout
    minimumLineSpacingForSectionAtIndex:(NSInteger)section;

/**
   @Status Interoperable
*/
- (CGFloat)collectionView:(UICollectionView*)collectionView
                                      layout:(UICollectionViewLayout*)collectionViewLayout
    minimumInteritemSpacingForSectionAtIndex:(NSInteger)section;

/**
   @Status Interoperable
*/
- (CGSize)collectionView:(UICollectionView*)collectionView
                             layout:(UICollectionViewLayout*)collectionViewLayout
    referenceSizeForHeaderInSection:(NSInteger)section;

/**
   @Status Interoperable
*/
- (CGSize)collectionView:(UICollectionView*)collectionView
                             layout:(UICollectionViewLayout*)collectionViewLayout
    referenceSizeForFooterInSection:(NSInteger)section;

@end

@class UIGridLayoutInfo;

UIKIT_EXPORT_CLASS
@interface UICollectionViewFlowLayout : UICollectionViewLayout

@property (nonatomic) CGFloat minimumLineSpacing;
@property (nonatomic) CGFloat minimumInteritemSpacing;
@property (nonatomic) CGSize itemSize; // for the cases the delegate method is not implemented
@property (nonatomic) UICollectionViewScrollDirection scrollDirection; // default is UICollectionViewScrollDirectionVertical
@property (nonatomic) CGSize headerReferenceSize;
@property (nonatomic) CGSize footerReferenceSize;

@property (nonatomic) BOOL sectionHeadersPinToVisibleBounds;
@property (nonatomic) BOOL sectionFootersPinToVisibleBounds;

@property (nonatomic) UIEdgeInsets sectionInset;

/*
 Row alignment options exits in the official UICollectionView, but hasn't been made public API.

 Here's a snippet to test this on UICollectionView:

 NSMutableDictionary *rowAlign = [[flowLayout valueForKey:@"_rowAlignmentsOptionsDictionary"] mutableCopy];
 rowAlign[@"UIFlowLayoutCommonRowHorizontalAlignmentKey"] = @(1);
 rowAlign[@"UIFlowLayoutLastRowHorizontalAlignmentKey"] = @(3);
 [flowLayout setValue:rowAlign forKey:@"_rowAlignmentsOptionsDictionary"];
 */
@property (nonatomic, strong) NSDictionary* rowAlignmentOptions;

@end

// @steipete addition, private API in UICollectionViewFlowLayout
UIKIT_EXPORT extern NSString* const UIFlowLayoutCommonRowHorizontalAlignmentKey;
UIKIT_EXPORT extern NSString* const UIFlowLayoutLastRowHorizontalAlignmentKey;
UIKIT_EXPORT extern NSString* const UIFlowLayoutRowVerticalAlignmentKey;

enum _UIFlowLayoutHorizontalAlignment {
    UIFlowLayoutHorizontalAlignmentLeft,
    UIFlowLayoutHorizontalAlignmentCentered,
    UIFlowLayoutHorizontalAlignmentRight,
    UIFlowLayoutHorizontalAlignmentJustify // 3; default except for the last row
};
typedef NSInteger UIFlowLayoutHorizontalAlignment;

// TODO: settings for UIFlowLayoutRowVerticalAlignmentKey

/*
@interface UICollectionViewFlowLayout (Private)

- (CGSize)synchronizeLayout;

// For items being inserted or deleted, the collection view calls some different methods, which you should override to provide the
appropriate layout information.
- (UICollectionViewLayoutAttributes *)initialLayoutAttributesForFooterInInsertedSection:(NSInteger)section;
- (UICollectionViewLayoutAttributes *)initialLayoutAttributesForHeaderInInsertedSection:(NSInteger)section;
- (UICollectionViewLayoutAttributes *)initialLayoutAttributesForInsertedItemAtIndexPath:(NSIndexPath *)indexPath;
- (UICollectionViewLayoutAttributes *)finalLayoutAttributesForFooterInDeletedSection:(NSInteger)section;
- (UICollectionViewLayoutAttributes *)finalLayoutAttributesForHeaderInDeletedSection:(NSInteger)section;
- (UICollectionViewLayoutAttributes *)finalLayoutAttributesForDeletedItemAtIndexPath:(NSIndexPath *)indexPath;

- (void)_updateItemsLayout;
- (void)_getSizingInfos;
- (void)_updateDelegateFlags;

- (UICollectionViewLayoutAttributes *)layoutAttributesForFooterInSection:(NSInteger)section;
- (UICollectionViewLayoutAttributes *)layoutAttributesForHeaderInSection:(NSInteger)section;
- (UICollectionViewLayoutAttributes *)layoutAttributesForItemAtIndexPath:(NSIndexPath *)indexPath usingData:(id)data;
- (UICollectionViewLayoutAttributes *)layoutAttributesForFooterInSection:(NSInteger)section usingData:(id)data;
- (UICollectionViewLayoutAttributes *)layoutAttributesForHeaderInSection:(NSInteger)section usingData:(id)data;

- (id)indexesForSectionFootersInRect:(CGRect)rect;
- (id)indexesForSectionHeadersInRect:(CGRect)rect;
- (id)indexPathsForItemsInRect:(CGRect)rect usingData:(id)arg2;
- (id)indexesForSectionFootersInRect:(CGRect)rect usingData:(id)arg2;
- (id)indexesForSectionHeadersInRect:(CGRect)arg1 usingData:(id)arg2;
- (CGRect)_frameForItemAtSection:(int)arg1 andRow:(int)arg2 usingData:(id)arg3;
- (CGRect)_frameForFooterInSection:(int)arg1 usingData:(id)arg2;
- (CGRect)_frameForHeaderInSection:(int)arg1 usingData:(id)arg2;
- (void)_invalidateLayout;
- (NSIndexPath *)indexPathForItemAtPoint:(CGPoint)arg1;
- (UICollectionViewLayoutAttributes *)_layoutAttributesForItemsInRect:(CGRect)arg1;
- (CGSize)collectionViewContentSize;
- (void)finalizeCollectionViewUpdates;
- (void)_invalidateButKeepDelegateInfo;
- (void)_invalidateButKeepAllInfo;
- (BOOL)shouldInvalidateLayoutForBoundsChange:(CGRect)arg1;
- (id)layoutAttributesForElementsInRect:(CGRect)arg1;
- (void)invalidateLayout;
- (id)layoutAttributesForItemAtIndexPath:(id)arg1;

@end
*/
