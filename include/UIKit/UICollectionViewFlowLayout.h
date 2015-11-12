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

#ifndef _UICOLLECTIONVIEWFLOWLAYOUT_H_
#define _UICOLLECTIONVIEWFLOWLAYOUT_H_

#import <Foundation/Foundation.h>
#import "UIKitExport.h"
#import <UIKit/UICollectionView.h>
#import <UIKit/UICollectionViewLayout.h>

enum {
    UICollectionViewScrollDirectionVertical,
    UICollectionViewScrollDirectionHorizontal,
};
typedef uint32_t UICollectionViewScrollDirection;

typedef enum _UIFlowLayoutHorizontalAlignment {
    UIFlowLayoutHorizontalAlignmentLeft,
    UIFlowLayoutHorizontalAlignmentCentered,
    UIFlowLayoutHorizontalAlignmentRight,
    UIFlowLayoutHorizontalAlignmentJustify // 3; default except for the last row
};

typedef uint32_t UIFlowLayoutHorizontalAlignment;

UIKIT_EXPORT NSString* const UICollectionElementKindSectionHeader;
UIKIT_EXPORT NSString* const UICollectionElementKindSectionFooter;

@protocol UICollectionViewDelegateFlowLayout <UICollectionViewDelegate>

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

UIKIT_EXPORT_CLASS
@interface UICollectionViewFlowLayout : UICollectionViewLayout

@property (nonatomic) UICollectionViewScrollDirection scrollDirection;
@property (nonatomic) CGSize itemSize;
@property (nonatomic) CGSize headerReferenceSize;
@property (nonatomic) CGFloat minimumInteritemSpacing;
@property (nonatomic) CGFloat minimumLineSpacing;
@property (nonatomic) UIEdgeInsets sectionInset;

- (CGSize)collectionViewContentSize;

@end

#endif /* _UICOLLECTIONVIEWFLOWLAYOUT_H_ */
