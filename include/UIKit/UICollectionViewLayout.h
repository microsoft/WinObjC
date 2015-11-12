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

#ifndef _UICOLLECTIONVIEWCLAYOUT_H_
#define _UICOLLECTIONVIEWCLAYOUT_H_

#import "UIKitExport.h"
#import <Foundation/Foundation.h>
#import <QuartzCore/CATransform3D.h>

enum _UICollectionViewItemType {
    UICollectionViewItemTypeCell,
    UICollectionViewItemTypeSupplementaryView,
    UICollectionViewItemTypeDecorationView
};

typedef unsigned UICollectionViewItemType;

@class UICollectionViewLayoutAttributes;
@class UICollectionView;

UIKIT_EXPORT_CLASS
@interface UICollectionViewLayout : NSObject <NSCoding> {
    id _collectionView;
}

@property (nonatomic, readonly) UICollectionView* collectionView;

- (void)prepareLayout;
- (NSArray*)layoutAttributesForElementsInRect:(CGRect)rect;
- (BOOL)shouldInvalidateLayoutForBoundsChange:(CGRect)newBounds;
- (UICollectionViewLayoutAttributes*)layoutAttributesForItemAtIndexPath:(NSIndexPath*)indexPath;
- (void)registerClass:(Class)viewClass forDecorationViewOfKind:(NSString*)decorationViewKind;
- (void)prepareForCollectionViewUpdates:(NSArray*)updateItems;
- (UICollectionViewLayoutAttributes*)initialLayoutAttributesForAppearingDecorationElementOfKind:(NSString*)elementKind
                                                                                    atIndexPath:(NSIndexPath*)elementIndexPath;
- (UICollectionViewLayoutAttributes*)initialLayoutAttributesForAppearingItemAtIndexPath:(NSIndexPath*)itemIndexPath;
- (UICollectionViewLayoutAttributes*)initialLayoutAttributesForAppearingSupplementaryElementOfKind:(NSString*)elementKind
                                                                                       atIndexPath:(NSIndexPath*)elementIndexPath;

- (UICollectionViewLayoutAttributes*)layoutAttributesForDecorationViewOfKind:(NSString*)decorationViewKind
                                                                 atIndexPath:(NSIndexPath*)indexPath;
- (NSArray*)layoutAttributesForElementsInRect:(CGRect)rect;
- (UICollectionViewLayoutAttributes*)layoutAttributesForItemAtIndexPath:(NSIndexPath*)indexPath;
- (UICollectionViewLayoutAttributes*)layoutAttributesForSupplementaryViewOfKind:(NSString*)kind atIndexPath:(NSIndexPath*)indexPath;

- (UICollectionViewLayoutAttributes*)finalLayoutAttributesForDisappearingItemAtIndexPath:(NSIndexPath*)itemIndexPath;

- (void)invalidateLayout;

@end

UIKIT_EXPORT_CLASS
@interface UICollectionViewLayoutAttributes : NSObject <NSCopying>

- (UICollectionViewItemType)representedElementCategory;

@property (nonatomic) CGRect frame;
@property (nonatomic) CGPoint center;
@property (nonatomic) CATransform3D transform3D;
@property (nonatomic) NSInteger zIndex;
@property (nonatomic, retain) NSIndexPath* indexPath;
@property (nonatomic, readonly) NSString* representedElementKind;
@property (nonatomic) CGFloat alpha;

+ (instancetype)layoutAttributesForSupplementaryViewOfKind:(NSString*)supplementaryViewKind withIndexPath:(NSIndexPath*)indexPath;
+ (instancetype)layoutAttributesForDecorationViewOfKind:(NSString*)decorationViewKind withIndexPath:(NSIndexPath*)indexPath;
+ (instancetype)layoutAttributesForCellWithIndexPath:(NSIndexPath*)indexPath;
@end

#endif /* _UICOLLECTIONVIEWCLAYOUT_H_ */
