//******************************************************************************
//
// UICollectionViewLayout.m
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

#import <UIKit/UIKit.h>
#import "UICollectionViewItemKey.h"
#import "UICollectionViewData.h"
#import "UICollectionViewUpdateItem.h"

@interface UICollectionView ()
- (id)currentUpdate;
- (NSDictionary*)visibleViewsDict;
- (UICollectionViewData*)collectionViewData;
- (CGRect)visibleBoundRects; // visibleBounds is flagged as private API (wtf)
@end

@interface UICollectionReusableView ()
- (void)setIndexPath:(NSIndexPath*)indexPath;
@end

@interface UICollectionViewUpdateItem ()
- (BOOL)isSectionOperation;
@end

@interface UICollectionViewLayoutAttributes () {
    struct {
        unsigned int isCellKind : 1;
        unsigned int isDecorationView : 1;
        unsigned int isHidden : 1;
        unsigned int isPinned : 1;
    } _layoutFlags;
}
@property (nonatomic) UICollectionViewItemType elementCategory;
@property (nonatomic, copy) NSString* elementKind;
@end

@interface UICollectionViewUpdateItem ()
- (NSIndexPath*)indexPath;
@end

@implementation UICollectionViewLayoutAttributes

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Static

/**
   @Status Interoperable
*/
+ (instancetype)layoutAttributesForCellWithIndexPath:(NSIndexPath*)indexPath {
    UICollectionViewLayoutAttributes* attributes = [self new];
    attributes.elementKind = UICollectionElementKindCell;
    attributes.elementCategory = UICollectionViewItemTypeCell;
    attributes.indexPath = indexPath;
    return attributes;
}

/**
   @Status Interoperable
*/
+ (instancetype)layoutAttributesForSupplementaryViewOfKind:(NSString*)elementKind withIndexPath:(NSIndexPath*)indexPath {
    UICollectionViewLayoutAttributes* attributes = [self new];
    attributes.elementCategory = UICollectionViewItemTypeSupplementaryView;
    attributes.elementKind = elementKind;
    attributes.indexPath = indexPath;
    return attributes;
}

/**
   @Status Interoperable
*/
+ (instancetype)layoutAttributesForDecorationViewOfKind:(NSString*)elementKind withIndexPath:(NSIndexPath*)indexPath {
    UICollectionViewLayoutAttributes* attributes = [self new];
    attributes.elementCategory = UICollectionViewItemTypeDecorationView;
    attributes.elementKind = elementKind;
    attributes.indexPath = indexPath;
    return attributes;
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - NSObject

/**
   @Status Interoperable
*/
- (id)init {
    if ((self = [super init])) {
        _alpha = 1.f;
        _transform3D = CATransform3DIdentity;
    }
    return self;
}

/**
   @Status Interoperable
*/
- (NSUInteger)hash {
    return ([_elementKind hash] * 31) + [_indexPath hash];
}

/**
   @Status Interoperable
*/
- (BOOL)isEqual:(id)other {
    if ([other isKindOfClass:self.class]) {
        UICollectionViewLayoutAttributes* otherLayoutAttributes = (UICollectionViewLayoutAttributes*)other;
        if (_elementCategory == otherLayoutAttributes.elementCategory && [_elementKind isEqual:otherLayoutAttributes.elementKind] &&
            [_indexPath isEqual:otherLayoutAttributes.indexPath]) {
            return YES;
        }
    }
    return NO;
}

/**
   @Status Interoperable
*/
- (NSString*)description {
    return [NSString stringWithFormat:@"<%@: %p frame:%@ indexPath:%@ elementKind:%@>",
                                      NSStringFromClass(self.class),
                                      self,
                                      NSStringFromCGRect(self.frame),
                                      self.indexPath,
                                      self.elementKind];
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Public

/**
   @Status Interoperable
*/
- (UICollectionViewItemType)representedElementCategory {
    return _elementCategory;
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Private

/**
   @Public No
*/
- (NSString*)representedElementKind {
    return self.elementKind;
}

/**
   @Public No
*/
- (BOOL)isDecorationView {
    return self.representedElementCategory == UICollectionViewItemTypeDecorationView;
}

/**
   @Public No
*/
- (BOOL)isSupplementaryView {
    return self.representedElementCategory == UICollectionViewItemTypeSupplementaryView;
}

/**
   @Public No
*/
- (BOOL)isPinnedSupplementaryView {
    return (self.representedElementCategory == UICollectionViewItemTypeSupplementaryView) &&
           (_layoutFlags.isPinned);
}

/**
   @Public No
*/
- (BOOL)isCell {
    return self.representedElementCategory == UICollectionViewItemTypeCell;
}

/**
   @Public No
*/
- (void)updateFrame {
    _frame = (CGRect){ { _center.x - _size.width / 2, _center.y - _size.height / 2 }, _size };
}

/**
   @Public No
*/
- (void)setPinned:(BOOL)pinned {
    _layoutFlags.isPinned = pinned ? 1 : 0;
}

/**
   @Public No
*/
- (void)setSize:(CGSize)size {
    _size = size;
    [self updateFrame];
}

/**
   @Public No
*/
- (void)setCenter:(CGPoint)center {
    _center = center;
    [self updateFrame];
}

/**
   @Public No
*/
- (void)setFrame:(CGRect)frame {
    _frame = frame;
    _size = _frame.size;
    _center = (CGPoint){ CGRectGetMidX(_frame), CGRectGetMidY(_frame) };
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - NSCopying

/**
   @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    UICollectionViewLayoutAttributes* layoutAttributes = [self.class new];
    layoutAttributes.indexPath = self.indexPath;
    layoutAttributes.elementKind = self.elementKind;
    layoutAttributes.elementCategory = self.elementCategory;
    layoutAttributes.frame = self.frame;
    layoutAttributes.center = self.center;
    layoutAttributes.size = self.size;
    layoutAttributes.transform3D = self.transform3D;
    layoutAttributes.alpha = self.alpha;
    layoutAttributes.zIndex = self.zIndex;
    layoutAttributes.hidden = self.isHidden;
    return layoutAttributes;
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - UICollection/UICollection interoperability

#if 0

- (NSMethodSignature*)methodSignatureForSelector:(SEL)selector {
    NSMethodSignature* signature = [super methodSignatureForSelector:selector];
    if (!signature) {
        NSString* selString = NSStringFromSelector(selector);
        if ([selString hasPrefix:@"_"]) {
            SEL cleanedSelector = NSSelectorFromString([selString substringFromIndex:1]);
            signature = [super methodSignatureForSelector:cleanedSelector];
        }
    }
    return signature;
}

- (void)forwardInvocation:(NSInvocation*)invocation {
    NSString* selString = NSStringFromSelector([invocation selector]);
    if ([selString hasPrefix:@"_"]) {
        SEL cleanedSelector = NSSelectorFromString([selString substringFromIndex:1]);
        if ([self respondsToSelector:cleanedSelector]) {
            invocation.selector = cleanedSelector;
            [invocation invokeWithTarget:self];
        }
    } else {
        [super forwardInvocation:invocation];
    }
}

#endif

@end

@interface UICollectionViewLayout () {
    __unsafe_unretained UICollectionView* _collectionView;
    CGSize _collectionViewBoundsSize;
    NSMutableDictionary* _initialAnimationLayoutAttributesDict;
    NSMutableDictionary* _finalAnimationLayoutAttributesDict;
    NSMutableIndexSet* _deletedSectionsSet;
    NSMutableIndexSet* _insertedSectionsSet;
    NSMutableDictionary* _decorationViewClassDict;
    NSMutableDictionary* _decorationViewNibDict;
    NSMutableDictionary* _decorationViewExternalObjectsTables;
}
@property (nonatomic, unsafe_unretained) UICollectionView* collectionView;
@property (nonatomic, copy, readonly) NSDictionary* decorationViewClassDict;
@property (nonatomic, copy, readonly) NSDictionary* decorationViewNibDict;
@property (nonatomic, copy, readonly) NSDictionary* decorationViewExternalObjectsTables;
@end

@implementation UICollectionViewLayout
///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - NSObject

/**
   @Status Interoperable
*/
- (id)init {
    if ((self = [super init])) {
        _decorationViewClassDict = [NSMutableDictionary new];
        _decorationViewNibDict = [NSMutableDictionary new];
        _decorationViewExternalObjectsTables = [NSMutableDictionary new];
        _initialAnimationLayoutAttributesDict = [NSMutableDictionary new];
        _finalAnimationLayoutAttributesDict = [NSMutableDictionary new];
        _insertedSectionsSet = [NSMutableIndexSet new];
        _deletedSectionsSet = [NSMutableIndexSet new];
    }
    return self;
}

/**
   @Status Interoperable
*/
- (void)awakeFromNib {
    [super awakeFromNib];
}

/**
   @Status Interoperable
*/
- (void)setCollectionView:(UICollectionView*)collectionView {
    if (collectionView != _collectionView) {
        _collectionView = collectionView;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Invalidating the Layout

/**
   @Status Interoperable
*/
- (void)invalidateLayout {
    [[_collectionView collectionViewData] invalidate];
    [_collectionView setNeedsLayout];
}

/**
   @Status Stub
*/
- (BOOL)shouldInvalidateLayoutForBoundsChange:(CGRect)newBounds {
    // not sure about his..
    if ((self.collectionView.bounds.size.width != newBounds.size.width) ||
        (self.collectionView.bounds.size.height != newBounds.size.height)) {
        return YES;
    }
    return NO;
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Providing Layout Attributes

/**
   @Status Interoperable
*/
+ (Class)layoutAttributesClass {
    return UICollectionViewLayoutAttributes.class;
}

/**
   @Status Interoperable
*/
- (void)prepareLayout {
}

/**
   @Status Interoperable
*/
- (NSArray*)layoutAttributesForElementsInRect:(CGRect)rect {
    return nil;
}

/**
   @Status Interoperable
*/
- (UICollectionViewLayoutAttributes*)layoutAttributesForItemAtIndexPath:(NSIndexPath*)indexPath {
    return nil;
}

/**
   @Status Interoperable
*/
- (UICollectionViewLayoutAttributes*)layoutAttributesForSupplementaryViewOfKind:(NSString*)kind atIndexPath:(NSIndexPath*)indexPath {
    return nil;
}

/**
   @Status Interoperable
*/
- (UICollectionViewLayoutAttributes*)layoutAttributesForDecorationViewOfKind:(NSString*)kind atIndexPath:(NSIndexPath*)indexPath {
    return nil;
}

// return a point at which to rest after scrolling - for layouts that want snap-to-point scrolling behavior
/**
   @Status Interoperable
*/
- (CGPoint)targetContentOffsetForProposedContentOffset:(CGPoint)proposedContentOffset withScrollingVelocity:(CGPoint)velocity {
    return proposedContentOffset;
}

/**
   @Status Interoperable
*/
- (CGSize)collectionViewContentSize {
    return CGSizeZero;
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Responding to Collection View Updates

/**
   @Status Interoperable
*/
- (void)prepareForCollectionViewUpdates:(NSArray*)updateItems {
    NSDictionary* update = [_collectionView currentUpdate];

    for (UICollectionReusableView* view in [[_collectionView visibleViewsDict] objectEnumerator]) {
        UICollectionViewLayoutAttributes* attr = [view.layoutAttributes copy];
        if (attr) {
            if (attr.isCell) {
                NSUInteger index = [update[@"oldModel"] globalIndexForItemAtIndexPath:[attr indexPath]];
                if (index != NSNotFound) {
                    [attr setIndexPath:[attr indexPath]];
                }
            }
            _initialAnimationLayoutAttributesDict[[UICollectionViewItemKey collectionItemKeyForLayoutAttributes:attr]] = attr;
        }
    }

    UICollectionViewData* collectionViewData = [_collectionView collectionViewData];

    CGRect bounds = [_collectionView visibleBoundRects];

    for (UICollectionViewLayoutAttributes* attr in [collectionViewData layoutAttributesForElementsInRect:bounds]) {
        if (attr.isCell) {
            NSInteger index = (NSInteger)[collectionViewData globalIndexForItemAtIndexPath:attr.indexPath];

            index = [update[@"newToOldIndexMap"][(NSUInteger)index] integerValue];
            if (index != NSNotFound) {
                UICollectionViewLayoutAttributes* finalAttrs = [attr copy];
                [finalAttrs setIndexPath:[update[@"oldModel"] indexPathForItemAtGlobalIndex:index]];
                [finalAttrs setAlpha:0];
                _finalAnimationLayoutAttributesDict[[UICollectionViewItemKey collectionItemKeyForLayoutAttributes:finalAttrs]] = finalAttrs;
            }
        }
    }

    for (UICollectionViewUpdateItem* updateItem in updateItems) {
        UICollectionUpdateAction action = updateItem.updateAction;

        if ([updateItem isSectionOperation]) {
            if (action == UICollectionUpdateActionReload) {
                [_deletedSectionsSet addIndex:(NSUInteger)[[updateItem indexPathBeforeUpdate] section]];
                [_insertedSectionsSet addIndex:(NSUInteger)[updateItem indexPathAfterUpdate].section];
            } else {
                NSMutableIndexSet* indexSet = action == UICollectionUpdateActionInsert ? _insertedSectionsSet : _deletedSectionsSet;
                [indexSet addIndex:(NSUInteger)[updateItem indexPath].section];
            }
        } else {
            if (action == UICollectionUpdateActionDelete) {
                UICollectionViewItemKey* key =
                    [UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:[updateItem indexPathBeforeUpdate]];

                UICollectionViewLayoutAttributes* attrs = [_finalAnimationLayoutAttributesDict[key] copy];

                if (attrs) {
                    [attrs setAlpha:0];
                    _finalAnimationLayoutAttributesDict[key] = attrs;
                }
            } else if (action == UICollectionUpdateActionReload || action == UICollectionUpdateActionInsert) {
                UICollectionViewItemKey* key =
                    [UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:[updateItem indexPathAfterUpdate]];
                UICollectionViewLayoutAttributes* attrs = [_initialAnimationLayoutAttributesDict[key] copy];

                if (attrs) {
                    [attrs setAlpha:0];
                    _initialAnimationLayoutAttributesDict[key] = attrs;
                }
            }
        }
    }
}

/**
   @Status Interoperable
*/
- (UICollectionViewLayoutAttributes*)initialLayoutAttributesForAppearingItemAtIndexPath:(NSIndexPath*)itemIndexPath {
    UICollectionViewLayoutAttributes* attrs =
        _initialAnimationLayoutAttributesDict[[UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:itemIndexPath]];

    if ([_insertedSectionsSet containsIndex:(NSUInteger)[itemIndexPath section]]) {
        attrs = [attrs copy];
        [attrs setAlpha:0];
    }
    return attrs;
}

/**
   @Status Interoperable
*/
- (UICollectionViewLayoutAttributes*)finalLayoutAttributesForDisappearingItemAtIndexPath:(NSIndexPath*)itemIndexPath {
    UICollectionViewLayoutAttributes* attrs =
        _finalAnimationLayoutAttributesDict[[UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:itemIndexPath]];

    if ([_deletedSectionsSet containsIndex:(NSUInteger)[itemIndexPath section]]) {
        attrs = [attrs copy];
        [attrs setAlpha:0];
    }
    return attrs;
}

/**
   @Status Interoperable
*/
- (UICollectionViewLayoutAttributes*)initialLayoutAttributesForInsertedSupplementaryElementOfKind:(NSString*)elementKind
                                                                                      atIndexPath:(NSIndexPath*)elementIndexPath {
    UICollectionViewLayoutAttributes* attrs =
        _initialAnimationLayoutAttributesDict[[UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:elementIndexPath]];

    if ([_insertedSectionsSet containsIndex:(NSUInteger)[elementIndexPath section]]) {
        attrs = [attrs copy];
        [attrs setAlpha:0];
    }
    return attrs;
}

/**
   @Status Interoperable
*/
- (UICollectionViewLayoutAttributes*)finalLayoutAttributesForDeletedSupplementaryElementOfKind:(NSString*)elementKind
                                                                                   atIndexPath:(NSIndexPath*)elementIndexPath {
    return nil;
}

/**
   @Status Interoperable
*/
- (void)finalizeCollectionViewUpdates {
    [_initialAnimationLayoutAttributesDict removeAllObjects];
    [_finalAnimationLayoutAttributesDict removeAllObjects];
    [_deletedSectionsSet removeAllIndexes];
    [_insertedSectionsSet removeAllIndexes];
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Registering Decoration Views

/**
   @Status Interoperable
*/
- (void)registerClass:(Class)viewClass forDecorationViewOfKind:(NSString*)kind {
    _decorationViewClassDict[kind] = viewClass;
}

/**
   @Status Interoperable
*/
- (void)registerNib:(UINib*)nib forDecorationViewOfKind:(NSString*)kind {
    _decorationViewNibDict[kind] = nib;
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Private

/**
   @Public No
*/
- (void)setCollectionViewBoundsSize:(CGSize)size {
    _collectionViewBoundsSize = size;
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - NSCoding

/**
   @Status Interoperable
*/
- (id)initWithCoder:(NSCoder*)coder {
    if ((self = [self init])) {
    }
    return self;
}

/**
   @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
}

@end
