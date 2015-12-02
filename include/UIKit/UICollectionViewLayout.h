//******************************************************************************
//
// UICollectionViewLayout.h
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

#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>

enum _UICollectionViewItemType {
    UICollectionViewItemTypeCell,
    UICollectionViewItemTypeSupplementaryView,
    UICollectionViewItemTypeDecorationView
};
typedef NSInteger UICollectionViewItemType;

// The UICollectionViewLayout class is provided as an abstract class for subclassing to define custom collection layouts.
// Defining a custom layout is an advanced operation intended for applications with complex needs.
@class UICollectionViewLayoutAttributes;
@class UICollectionView;

UIKIT_EXPORT_CLASS
@interface UICollectionViewLayoutAttributes : NSObject <NSCopying>

@property (nonatomic) CGRect frame;
@property (nonatomic) CGPoint center;
@property (nonatomic) CGSize size;
@property (nonatomic) CATransform3D transform3D;
@property (nonatomic) CGFloat alpha;
@property (nonatomic) NSInteger zIndex; // default is 0
@property (nonatomic, getter=isHidden)
    BOOL hidden; // As an optimization, UICollectionView might not create a view for items whose hidden attribute is YES
@property (nonatomic, strong) NSIndexPath* indexPath;

+ (instancetype)layoutAttributesForCellWithIndexPath:(NSIndexPath*)indexPath;

+ (instancetype)layoutAttributesForSupplementaryViewOfKind:(NSString*)elementKind withIndexPath:(NSIndexPath*)indexPath;

+ (instancetype)layoutAttributesForDecorationViewOfKind:(NSString*)kind withIndexPath:(NSIndexPath*)indexPath;

/*
 + (id)layoutAttributesForDecorationViewOfKind:(id)arg1 withIndexPath:(id)arg2;
 - (id)initialLayoutAttributesForInsertedDecorationElementOfKind:(id)arg1 atIndexPath:(id)arg2;
 - (BOOL)_isEquivalentTo:(id)arg1;
 */
@end

@interface UICollectionViewLayoutAttributes (Private)
@property (nonatomic, readonly) NSString* representedElementKind;
@property (nonatomic, readonly) UICollectionViewItemType representedElementCategory;

- (BOOL)isDecorationView;

- (BOOL)isSupplementaryView;

- (BOOL)isCell;
@end

UIKIT_EXPORT_CLASS
@interface UICollectionViewLayout : NSObject <NSCoding>

// Methods in this class are meant to be overridden and will be called by its collection view to gather layout information.
// To get the truth on the current state of the collection view, call methods on UICollectionView rather than these.
@property (nonatomic, unsafe_unretained, readonly) UICollectionView* collectionView;

// Call -invalidateLayout to indicate that the collection view needs to requery the layout information.
// Subclasses must always call super if they override.
- (void)invalidateLayout;

/// @name Registering Decoration Views
- (void)registerClass:(Class)viewClass forDecorationViewOfKind:(NSString*)kind;

- (void)registerNib:(UINib*)nib forDecorationViewOfKind:(NSString*)kind;

@end

@interface UICollectionViewLayout (SubclassingHooks)

+ (Class)layoutAttributesClass; // override this method to provide a custom class to be used when instantiating instances of
                                // UICollectionViewLayoutAttributes

// The collection view calls -prepareLayout once at its first layout as the first message to the layout instance.
// The collection view calls -prepareLayout again after layout is invalidated and before requerying the layout information.
// Subclasses should always call super if they override.
- (void)prepareLayout;

// UICollectionView calls these four methods to determine the layout information.
// Implement -layoutAttributesForElementsInRect: to return layout attributes for supplementary or decoration views, or to perform layout in
// an as-needed-on-screen fashion.
// Additionally, all layout subclasses should implement -layoutAttributesForItemAtIndexPath: to return layout attributes instances on demand
// for specific index paths.
// If the layout supports any supplementary or decoration view types, it should also implement the respective atIndexPath: methods for those
// types.
- (NSArray*)layoutAttributesForElementsInRect:
    (CGRect)rect; // return an array layout attributes instances for all the views in the given rect
- (UICollectionViewLayoutAttributes*)layoutAttributesForItemAtIndexPath:(NSIndexPath*)indexPath;

- (UICollectionViewLayoutAttributes*)layoutAttributesForSupplementaryViewOfKind:(NSString*)kind atIndexPath:(NSIndexPath*)indexPath;

- (UICollectionViewLayoutAttributes*)layoutAttributesForDecorationViewOfKind:(NSString*)kind atIndexPath:(NSIndexPath*)indexPath;

- (BOOL)shouldInvalidateLayoutForBoundsChange:
    (CGRect)newBounds; // return YES to cause the collection view to requery the layout for geometry information
- (CGPoint)targetContentOffsetForProposedContentOffset:(CGPoint)proposedContentOffset
                                 withScrollingVelocity:(CGPoint)velocity; // return a point at which to rest after scrolling - for layouts
                                                                          // that want snap-to-point scrolling behavior

- (CGSize)collectionViewContentSize; // the collection view calls this to update its content size any time it queries new layout information
                                     // - at least one of the width and height fields must match the respective field of the collection
                                     // view's bounds

@end

@interface UICollectionViewLayout (UpdateSupportHooks)

// This method is called when there is an update with deletes/inserts to the collection view.
// It will be called prior to calling the initial/final layout attribute methods below to give the layout an opportunity to do batch
// computations for the insertion and deletion layout attributes.
// The updateItems parameter is an array of UICollectionViewUpdateItem instances for each element that is moving to a new index path.
- (void)prepareForCollectionViewUpdates:(NSArray*)updateItems;

// This method is called inside an animation block after all items have been laid out for a collection view update.
// Subclasses can use this opportunity to layout their 'layout-owned' decoration views in response to the update.
- (void)finalizeCollectionViewUpdates;

// Collection view calls these methods to determine the starting layout for animating in newly inserted views, or the ending layout for
// animating out deleted views
- (UICollectionViewLayoutAttributes*)initialLayoutAttributesForAppearingItemAtIndexPath:(NSIndexPath*)itemIndexPath;

- (UICollectionViewLayoutAttributes*)finalLayoutAttributesForDisappearingItemAtIndexPath:(NSIndexPath*)itemIndexPath;

- (UICollectionViewLayoutAttributes*)initialLayoutAttributesForInsertedSupplementaryElementOfKind:(NSString*)elementKind
                                                                                      atIndexPath:(NSIndexPath*)elementIndexPath;

- (UICollectionViewLayoutAttributes*)finalLayoutAttributesForDeletedSupplementaryElementOfKind:(NSString*)elementKind
                                                                                   atIndexPath:(NSIndexPath*)elementIndexPath;

@end

@interface UICollectionViewLayout (Private)
- (void)setCollectionViewBoundsSize:(CGSize)size;

- (UICollectionReusableView*)decorationViewForCollectionView:(UICollectionView*)collectionView
                                         withReuseIdentifier:(NSString*)reuseIdentifier
                                                   indexPath:(NSIndexPath*)indexPath;
@end
