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

#include "Starboard.h"

#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSIndexSet.h"
#include "CoreGraphics/CGGeometry.h"
#include "UICollectionViewItemKey.h"
#include "UICollectionViewUpdateItem.h"
#include "UIKit/UICollectionViewLayout.h"

#include "UICollectionViewData.h"

@implementation UICollectionViewLayout {
    idretaintype(NSMutableDictionary) _decorationViewClassDict;
    idretaintype(NSMutableDictionary) _decorationViewNibDict;
    idretaintype(NSMutableDictionary) _decorationViewExternalObjectsTables;
    idretaintype(NSMutableDictionary) _initialAnimationLayoutAttributesDict;
    idretaintype(NSMutableDictionary) _finalAnimationLayoutAttributesDict;
    idretaintype(NSMutableIndexSet) _insertedSectionsSet, _deletedSectionsSet;
}

- (instancetype)init {
    _decorationViewClassDict = [[NSMutableDictionary new] autorelease];
    _decorationViewNibDict = [[NSMutableDictionary new] autorelease];
    _decorationViewExternalObjectsTables = [[NSMutableDictionary new] autorelease];
    _initialAnimationLayoutAttributesDict = [[NSMutableDictionary new] autorelease];
    _finalAnimationLayoutAttributesDict = [[NSMutableDictionary new] autorelease];
    _insertedSectionsSet = [[NSMutableIndexSet new] autorelease];
    _deletedSectionsSet = [[NSMutableIndexSet new] autorelease];
    return self;
}

- (id)initWithCoder:(id)coder {
    [self init];
    return self;
}

- (id)setCollectionView:(id)collectionView {
    _collectionView = collectionView;
    return 0;
}

- (id)collectionView {
    return _collectionView;
}

- (void)registerClass:(id)viewClass forDecorationViewOfKind:(id)decorationViewKind {
    [_decorationViewClassDict setObject:viewClass forKey:decorationViewKind];
}

- (void)prepareLayout {
}

- (void)invalidateLayout {
    [[_collectionView collectionViewData] invalidate];
    [_collectionView setNeedsLayout];
}

+ (id)layoutAttributesClass {
    return [UICollectionViewLayoutAttributes class];
}

- (id)decorationViewClassDict {
    return _decorationViewClassDict;
}

- (id)decorationViewNibDict {
    return _decorationViewNibDict;
}

- (id)decorationViewExternalObjectsTables {
    return _decorationViewExternalObjectsTables;
}

- (id)initialLayoutAttributesForAppearingItemAtIndexPath:(id)itemIndexPath {
    id attrs = [_initialAnimationLayoutAttributesDict
        objectForKey:[UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:itemIndexPath]];

    if ([_insertedSectionsSet containsIndex:[itemIndexPath section]]) {
        attrs = [attrs copy];
        [attrs setAlpha:0];
    }
    return attrs;
}

- (id)finalLayoutAttributesForDisappearingItemAtIndexPath:(id)itemIndexPath {
    id attrs = [_finalAnimationLayoutAttributesDict
        objectForKey:[UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:itemIndexPath]];

    if ([_deletedSectionsSet containsIndex:[itemIndexPath section]]) {
        attrs = [attrs copy];
        [attrs setAlpha:0];
    }
    return attrs;
}

- (void)prepareForCollectionViewUpdates:(id)updateItems {
    id update = [_collectionView currentUpdate];

    for (id view in [[_collectionView visibleViewsDict] objectEnumerator]) {
        id attr = [[view layoutAttributes] copy];
        if (attr) {
            if ([attr isCell]) {
                UICollectionViewData* data = [update objectForKey:@"oldModel"];
                NSInteger index = [data globalIndexForItemAtIndexPath:[attr indexPath]];
                if (index != NSNotFound) {
                    [attr setIndexPath:[attr indexPath]];
                }
            }
            [_initialAnimationLayoutAttributesDict
                setObject:attr
                   forKey:[UICollectionViewItemKey collectionItemKeyForLayoutAttributes:attr]];
        }
    }

    UICollectionViewData* collectionViewData = [_collectionView collectionViewData];

    CGRect bounds = [_collectionView visibleBoundRects];

    for (id attr in [collectionViewData layoutAttributesForElementsInRect:bounds]) {
        if ([attr isCell]) {
            NSInteger index = [collectionViewData globalIndexForItemAtIndexPath:[attr indexPath]];

            index = [[[update objectForKey:@"newToOldIndexMap"] objectAtIndex:index] intValue];
            if (index != NSNotFound) {
                id finalAttrs = [attr copy];
                [finalAttrs setIndexPath:[[update objectForKey:@"oldModel"] indexPathForItemAtGlobalIndex:index]];
                [finalAttrs setAlpha:0];
                [_finalAnimationLayoutAttributesDict
                    setObject:finalAttrs
                       forKey:[UICollectionViewItemKey collectionItemKeyForLayoutAttributes:finalAttrs]];
            }
        }
    }

    for (id updateItem in updateItems) {
        UICollectionUpdateAction action = [updateItem updateAction];

        if ([updateItem isSectionOperation]) {
            if (action == UICollectionUpdateActionReload) {
                [_deletedSectionsSet addIndex:[[updateItem indexPathBeforeUpdate] section]];
                [_insertedSectionsSet addIndex:[[updateItem indexPathAfterUpdate] section]];
            } else {
                id indexSet = action == UICollectionUpdateActionInsert ? _insertedSectionsSet : _deletedSectionsSet;
                [indexSet addIndex:[[updateItem indexPath] section]];
            }
        } else {
            if (action == UICollectionUpdateActionDelete) {
                id key =
                    [UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:[updateItem indexPathBeforeUpdate]];

                id attrs = [[_finalAnimationLayoutAttributesDict objectForKey:key] copy];

                if (attrs) {
                    [attrs setAlpha:0];
                    [_finalAnimationLayoutAttributesDict setObject:attrs forKey:key];
                }
            } else if (action == UICollectionUpdateActionReload || action == UICollectionUpdateActionInsert) {
                id key =
                    [UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:[updateItem indexPathAfterUpdate]];
                id attrs = [[_initialAnimationLayoutAttributesDict objectForKey:key] copy];

                if (attrs) {
                    [attrs setAlpha:0];
                    [_initialAnimationLayoutAttributesDict setObject:attrs forKey:key];
                }
            }
        }
    }
}

- (id)finalizeCollectionViewUpdates {
    [_initialAnimationLayoutAttributesDict removeAllObjects];
    [_finalAnimationLayoutAttributesDict removeAllObjects];
    [_deletedSectionsSet removeAllIndexes];
    [_insertedSectionsSet removeAllIndexes];
    return self;
}

@end

@implementation UICollectionViewLayoutAttributes {
    UICollectionViewItemType _elementCategory;
    idretain _elementKind;
    idretain _indexPath;
    CGRect _frame;
    CGSize _size;
    CGPoint _center;
    BOOL _hidden;
    NSInteger _zIndex;
    float _alpha;
    CATransform3D _transform3D;
}

- (id)init {
    _alpha = 1.0f;
    _transform3D = CATransform3DMakeTranslation(0, 0, 0);
    return self;
}

- (BOOL)isDecorationView {
    return [self representedElementCategory] == UICollectionViewItemTypeDecorationView;
}

- (BOOL)isSupplementaryView {
    return [self representedElementCategory] == UICollectionViewItemTypeSupplementaryView;
}

- (BOOL)isCell {
    return [self representedElementCategory] == UICollectionViewItemTypeCell;
}

+ (id)layoutAttributesForSupplementaryViewOfKind:(id)elementKind withIndexPath:(id)indexPath {
    UICollectionViewLayoutAttributes* attributes = [self new];
    attributes->_elementCategory = UICollectionViewItemTypeSupplementaryView;
    attributes->_elementKind.attach([elementKind copy]);
    attributes->_indexPath = indexPath;
    return attributes;
}

+ (id)layoutAttributesForCellWithIndexPath:(id)indexPath {
    UICollectionViewLayoutAttributes* attributes = [self new];
    attributes->_elementKind = @"UICollectionElementKindCell";
    attributes->_elementCategory = UICollectionViewItemTypeCell;
    attributes->_indexPath = indexPath;
    return attributes;
}

+ (id)layoutAttributesForDecorationViewOfKind:(id)elementKind withIndexPath:(id)indexPath {
    UICollectionViewLayoutAttributes* attributes = [self new];
    attributes->_elementCategory = UICollectionViewItemTypeDecorationView;
    attributes->_elementKind.attach([elementKind copy]);
    attributes->_indexPath = indexPath;
    return attributes;
}

- (void)setFrame:(CGRect)frame {
    _frame = frame;
    _size = frame.size;
    _center = CGPoint::point(CGRectGetMidX(_frame), CGRectGetMidY(_frame));
}

- (CGRect)frame {
    return _frame;
}

- (CGSize)size {
    return _size;
}

- (CGPoint)center {
    return _center;
}

- (CATransform3D)transform3D {
    return _transform3D;
}

- (float)alpha {
    return _alpha;
}

- (void)setAlpha:(float)alpha {
    _alpha = alpha;
}

- (void)setCenter:(CGPoint)center {
    _center = center;
    _frame = CGRectMake((_center.x - _frame.size.width / 2),
                        (_center.y - _frame.size.height / 2),
                        _frame.size.width,
                        _frame.size.height);
}

- (BOOL)isHidden {
    return _hidden;
}

- (void)setZIndex:(NSInteger)index {
    _zIndex = index;
}

- (int)zIndex {
    return _zIndex;
}

- (id)elementKind {
    return _elementKind;
}

- (id)representedElementKind {
    return _elementKind;
}

- (UICollectionViewItemType)representedElementCategory {
    return _elementCategory;
}

- (id)indexPath {
    return _indexPath;
}

- (void)setIndexPath:(id)indexPath {
    _indexPath = indexPath;
}

- (id)copyWithZone:(NSZone*)zone {
    UICollectionViewLayoutAttributes* layoutAttributes = [[self class] new];
    layoutAttributes->_indexPath = _indexPath;
    layoutAttributes->_elementKind = _elementKind;
    layoutAttributes->_elementCategory = _elementCategory;
    layoutAttributes->_frame = _frame;
    layoutAttributes->_center = _center;
    layoutAttributes->_size = _size;
    layoutAttributes->_transform3D = _transform3D;
    layoutAttributes->_alpha = _alpha;
    layoutAttributes->_zIndex = _zIndex;
    layoutAttributes->_hidden = _hidden;
    return layoutAttributes;
}

@end
