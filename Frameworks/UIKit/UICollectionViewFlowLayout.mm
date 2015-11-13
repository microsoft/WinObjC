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
#include <algorithm>

#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSIndexPath.h"
#include "CoreGraphics/CGGeometry.h"
#include "UIKit/UICollectionViewFlowLayout.h"

#include "UIGridLayoutSection.h"
#include "UIGridLayoutRow.h"
#include "UIGridLayoutInfo.h"
#include "UIGridLayoutItem.h"

NSString* const UICollectionElementKindSectionHeader = @"UICollectionElementKindSectionHeader";
NSString* const UICollectionElementKindSectionFooter = @"UICollectionElementKindSectionFooter";

@implementation UICollectionViewFlowLayout {
    struct {
        unsigned int delegateSizeForItem : 1;
        unsigned int delegateReferenceSizeForHeader : 1;
        unsigned int delegateReferenceSizeForFooter : 1;
        unsigned int delegateInsetForSection : 1;
        unsigned int delegateInteritemSpacingForSection : 1;
        unsigned int delegateLineSpacingForSection : 1;
        unsigned int delegateAlignmentOptions : 1;
        unsigned int keepDelegateInfoWhileInvalidating : 1;
        unsigned int keepAllDataWhileInvalidating : 1;
        unsigned int layoutDataIsValid : 1;
        unsigned int delegateInfoIsValid : 1;
    } _gridLayoutFlags;
    CGFloat _interitemSpacing;
    CGFloat _lineSpacing;
    CGSize _itemSize;
    CGSize _headerReferenceSize;
    CGSize _footerReferenceSize;
    UIEdgeInsets _sectionInset;
    idretaintype(UIGridLayoutInfo) _data;
    CGSize _currentLayoutSize;
    idretain _insertedItemsAttributesDict;
    idretain _insertedSectionHeadersAttributesDict;
    idretain _insertedSectionFootersAttributesDict;
    idretain _deletedItemsAttributesDict;
    idretain _deletedSectionHeadersAttributesDict;
    idretain _deletedSectionFootersAttributesDict;
    UICollectionViewScrollDirection _scrollDirection;
    idretaintype(NSMutableDictionary) _rowAlignmentsOptionsDictionary;
    idretain _cachedItemsRects;
    CGRect _visibleBounds;
}
void commonInit(UICollectionViewFlowLayout* self) {
    self->_itemSize = CGSizeMake(50.f, 50.f);
    self->_lineSpacing = 10.f;
    self->_interitemSpacing = 10.f;
    self->_scrollDirection = UICollectionViewScrollDirectionVertical;
}

- (id)init {
    [super init];
    commonInit(self);

    _rowAlignmentsOptionsDictionary.attach([NSMutableDictionary new]);
    [_rowAlignmentsOptionsDictionary setObject:[NSNumber numberWithInt:UIFlowLayoutHorizontalAlignmentJustify]
                                        forKey:@"UIFlowLayoutCommonRowHorizontalAlignmentKey"];
    [_rowAlignmentsOptionsDictionary setObject:[NSNumber numberWithInt:UIFlowLayoutHorizontalAlignmentJustify]
                                        forKey:@"UIFlowLayoutLastRowHorizontalAlignmentKey"];
    [_rowAlignmentsOptionsDictionary setObject:[NSNumber numberWithInt:1] forKey:@"UIFlowLayoutRowVerticalAlignmentKey"];
    return self;
}

- (id)initWithCoder:(id)decoder {
    [super initWithCoder:decoder];
    commonInit(self);

    // Some properties are not set if they're default (like minimumInteritemSpacing == 10)
    if ([decoder containsValueForKey:@"UIItemSize"])
        _itemSize = [decoder decodeCGSizeForKey:@"UIItemSize"];
    if ([decoder containsValueForKey:@"UIInteritemSpacing"])
        _interitemSpacing = [decoder decodeFloatForKey:@"UIInteritemSpacing"];
    if ([decoder containsValueForKey:@"UILineSpacing"])
        _lineSpacing = [decoder decodeFloatForKey:@"UILineSpacing"];
    if ([decoder containsValueForKey:@"UIFooterReferenceSize"])
        _footerReferenceSize = [decoder decodeCGSizeForKey:@"UIFooterReferenceSize"];
    if ([decoder containsValueForKey:@"UIHeaderReferenceSize"])
        _headerReferenceSize = [decoder decodeCGSizeForKey:@"UIHeaderReferenceSize"];
    if ([decoder containsValueForKey:@"UISectionInset"])
        _sectionInset = [decoder decodeUIEdgeInsetsForKey:@"UISectionInset"];
    if ([decoder containsValueForKey:@"UIScrollDirection"])
        _scrollDirection = [decoder decodeIntegerForKey:@"UIScrollDirection"];
    return self;
}

- (void)awakeFromNib {
}

/**
 @Status Interoperable
*/
- (void)setScrollDirection:(UICollectionViewScrollDirection)direction {
    _scrollDirection = direction;
}

/**
 @Status Interoperable
*/
- (void)setItemSize:(CGSize)size {
    _itemSize = size;
}

/**
 @Status Interoperable
*/
- (CGSize)itemSize {
    return _itemSize;
}

- (id)setHeaderReferenceSize:(CGSize)size {
    return self;
}

- (id)setFooterReferenceSize:(CGSize)size {
    return self;
}

/**
 @Status Interoperable
*/
- (void)setMinimumInteritemSpacing:(float)spacing {
    _interitemSpacing = spacing;
}

/**
 @Status Interoperable
*/
- (float)minimumInteritemSpacing {
    return _interitemSpacing;
}

/**
 @Status Interoperable
*/
- (void)setMinimumLineSpacing:(float)spacing {
    _lineSpacing = spacing;
}

/**
 @Status Interoperable
*/
- (float)minimumLineSpacing {
    return _lineSpacing;
}

/**
 @Status Interoperable
*/
- (void)setSectionInset:(UIEdgeInsets)sectionInset {
    if (!UIEdgeInsetsEqualToEdgeInsets(sectionInset, _sectionInset)) {
        _sectionInset = sectionInset;
        [self invalidateLayout];
    }
}

- (void)prepareLayout {
    _cachedItemsRects = [NSMutableDictionary dictionary];

    _data.attach([UIGridLayoutInfo new]); // clear old layout data
    [_data setHorizontal:_scrollDirection == UICollectionViewScrollDirectionHorizontal];

    _visibleBounds = [[self collectionView] bounds];
    CGSize collectionViewSize = _visibleBounds.size;
    [_data setDimension:[_data horizontal] ? collectionViewSize.height : collectionViewSize.width];
    [_data setRowAlignmentOptions:(id)_rowAlignmentsOptionsDictionary];
    [self fetchItemsInfo];
}

- (id)fetchItemsInfo {
    [self getSizingInfos];
    [self updateItemsLayout];
    return self;
}

- (void)invalidateLayout {
    [super invalidateLayout];
    _cachedItemsRects = nil;
    _data = nil;
}

/**
 @Status Interoperable
*/
- (CGSize)collectionViewContentSize {
    if (!_data)
        [self prepareLayout];

    return [_data contentSize];
}

- (id)updateItemsLayout {
    CGSize contentSize = CGSizeMake(0, 0);

    for (UIGridLayoutSection* section in [_data sections]) {
        [section computeLayout];

        // update section offset to make frame absolute (section only calculates relative)
        CGRect origSectionFrame, sectionFrame;

        sectionFrame = [section frame];
        origSectionFrame = sectionFrame;

        UIEdgeInsets sectionMargins;

        sectionMargins = [section sectionMargins];
        if ([_data horizontal]) {
            sectionFrame.origin.x += contentSize.width;
            contentSize.width += origSectionFrame.size.width + origSectionFrame.origin.x;
            contentSize.height =
                std::max(contentSize.height,
                         origSectionFrame.size.height + origSectionFrame.origin.y + sectionMargins.top + sectionMargins.bottom);
        } else {
            sectionFrame.origin.y += contentSize.height;
            contentSize.height += origSectionFrame.size.height + origSectionFrame.origin.y;
            contentSize.width =
                std::max(contentSize.width,
                         origSectionFrame.size.width + origSectionFrame.origin.x + sectionMargins.left + sectionMargins.right);
        }
        [section setFrame:sectionFrame];
    }
    [_data setContentSize:contentSize];
    return self;
}

- (id)getSizingInfos {
    assert([[_data sections] count] == 0);

    id<UICollectionViewDelegateFlowLayout> flowDataSource = [_collectionView delegate];

    BOOL implementsSizeDelegate = [flowDataSource respondsToSelector:@selector(collectionView:layout:sizeForItemAtIndexPath:)];
    BOOL implementsHeaderReferenceDelegate =
        [flowDataSource respondsToSelector:@selector(collectionView:layout:referenceSizeForHeaderInSection:)];
    BOOL implementsFooterReferenceDelegate =
        [flowDataSource respondsToSelector:@selector(collectionView:layout:referenceSizeForFooterInSection:)];

    NSUInteger numberOfSections = [_collectionView numberOfSections];
    for (NSUInteger section = 0; section < numberOfSections; section++) {
        id layoutSection = [_data addSection];
        [layoutSection setVerticalInterstice:[_data horizontal] ? _interitemSpacing : _lineSpacing];
        [layoutSection setHorizontalInterstice:![_data horizontal] ? _interitemSpacing : _lineSpacing];

        if ([flowDataSource respondsToSelector:@selector(collectionView:layout:insetForSectionAtIndex:)]) {
            UIEdgeInsets insets;
            insets = [flowDataSource collectionView:_collectionView layout:self insetForSectionAtIndex:section];
            [layoutSection setSectionMargins:insets];
        } else {
            [layoutSection setSectionMargins:_sectionInset];
        }

        if ([flowDataSource respondsToSelector:@selector(collectionView:layout:minimumLineSpacingForSectionAtIndex:)]) {
            CGFloat minimumLineSpacing =
                [flowDataSource collectionView:_collectionView layout:self minimumLineSpacingForSectionAtIndex:section];
            if ([_data horizontal]) {
                [layoutSection setHorizontalInterstice:minimumLineSpacing];
            } else {
                [layoutSection setVerticalInterstice:minimumLineSpacing];
            }
        }

        if ([flowDataSource respondsToSelector:@selector(collectionView:layout:minimumInteritemSpacingForSectionAtIndex:)]) {
            CGFloat minimumInterimSpacing =
                [flowDataSource collectionView:_collectionView layout:self minimumInteritemSpacingForSectionAtIndex:section];
            if ([_data horizontal]) {
                [layoutSection setVerticalInterstice:minimumInterimSpacing];
            } else {
                [layoutSection setHorizontalInterstice:minimumInterimSpacing];
            }
        }

        CGSize headerReferenceSize;
        if (implementsHeaderReferenceDelegate) {
            headerReferenceSize = [flowDataSource collectionView:_collectionView layout:self referenceSizeForHeaderInSection:section];
        } else {
            headerReferenceSize = _headerReferenceSize;
        }
        [layoutSection setHeaderDimension:[_data horizontal] ? headerReferenceSize.width : headerReferenceSize.height];

        CGSize footerReferenceSize;
        if (implementsFooterReferenceDelegate) {
            footerReferenceSize = [flowDataSource collectionView:_collectionView layout:self referenceSizeForFooterInSection:section];
        } else {
            footerReferenceSize = _footerReferenceSize;
        }
        [layoutSection setFooterDimension:[_data horizontal] ? footerReferenceSize.width : footerReferenceSize.height];

        NSUInteger numberOfItems = [_collectionView numberOfItemsInSection:section];

        // if delegate implements size delegate, query it for all items
        if (implementsSizeDelegate) {
            for (NSUInteger item = 0; item < numberOfItems; item++) {
                id indexPath = [NSIndexPath indexPathForItem:item inSection:section];
                CGSize itemSize;

                if (implementsSizeDelegate) {
                    itemSize = [flowDataSource collectionView:_collectionView layout:self sizeForItemAtIndexPath:indexPath];
                } else {
                    itemSize = _itemSize;
                }

                id layoutItem = [layoutSection addItem];
                CGRect rect = CGRectMake(0, 0, itemSize.width, itemSize.height);
                [layoutItem setItemFrame:rect];
            }
            // if not, go the fast path
        } else {
            [layoutSection setFixedItemSize:YES];
            [layoutSection setItemSize:_itemSize];
            [layoutSection setItemsCount:numberOfItems];
        }
    }
    return self;
}

- (id)layoutAttributesForItemAtIndexPath:(id)indexPath {
    return [self _buildLayoutAttributesForItemAtIndexPath:indexPath];
}

- (id)_buildLayoutAttributesForItemAtIndexPath:(NSIndexPath*)indexPath {
    if (!_data)
        [self prepareLayout];

    UIGridLayoutSection* section = [[_data sections] objectAtIndex:[indexPath section]];
    id row = nil;
    CGRect itemFrame = CGRectMake(0, 0, 0, 0);

    if ([section fixedItemSize] && [section itemsByRowCount] > 0 &&
        [indexPath item] / [section itemsByRowCount] < (NSInteger)[[section rows] count]) {
        row = [[section rows] objectAtIndex:[indexPath item] / [section itemsByRowCount]];
        NSUInteger itemIndex = [indexPath item] % [section itemsByRowCount];
        id itemRects = [row itemRects];
        itemFrame = [[itemRects objectAtIndex:itemIndex] CGRectValue];
    } else if ([indexPath item] < (NSInteger)[[section items] count]) {
        UIGridLayoutItem* item = [[section items] objectAtIndex:[indexPath item]];
        row = [item rowObject];
        itemFrame = [item itemFrame];
    }

    id layoutAttributes = [[[self class] layoutAttributesClass] layoutAttributesForCellWithIndexPath:indexPath];

    // calculate item rect
    CGRect normalizedRowFrame = [row rowFrame];
    normalizedRowFrame.origin.x += [section frame].origin.x;
    normalizedRowFrame.origin.y += [section frame].origin.y;
    [layoutAttributes setFrame:CGRectMake(normalizedRowFrame.origin.x + itemFrame.origin.x,
                                          normalizedRowFrame.origin.y + itemFrame.origin.y,
                                          itemFrame.size.width,
                                          itemFrame.size.height)];

    return layoutAttributes;
}

- (id)layoutAttributesForElementsInRect:(CGRect)rect {
    return [self _buildLayoutAttributesForElementsInRect:rect];
}

- (id)_buildLayoutAttributesForElementsInRect:(CGRect)rect {
    // Apple calls _layoutAttributesForItemsInRect
    if (!_data)
        [self prepareLayout];

    id layoutAttributesArray = [NSMutableArray array];
    for (UIGridLayoutSection* section in [_data sections]) {
        CGRect frame;

        frame = [section frame];
        if (CGRectIntersectsRect(frame, rect)) {
            // if we have fixed size, calculate item frames only once.
            // this also uses the default PSTFlowLayoutCommonRowHorizontalAlignmentKey alignment
            // for the last row. (we want this effect!)
            id rectCache = _cachedItemsRects;
            NSUInteger sectionIndex = [[_data sections] indexOfObjectIdenticalTo:section];

            CGRect normalizedHeaderFrame;
            normalizedHeaderFrame = [section headerFrame];

            normalizedHeaderFrame.origin.x += frame.origin.x;
            normalizedHeaderFrame.origin.y += frame.origin.y;
            if (!CGRectIsEmpty(normalizedHeaderFrame) && CGRectIntersectsRect(normalizedHeaderFrame, rect)) {
                id layoutAttributes = [[[self class] layoutAttributesClass]
                    layoutAttributesForSupplementaryViewOfKind:@"UICollectionElementKindSectionHeader"
                                                 withIndexPath:[NSIndexPath indexPathForItem:0 inSection:sectionIndex]];
                [layoutAttributes setFrame:normalizedHeaderFrame];
                [layoutAttributesArray addObject:layoutAttributes];
            }

            id itemRects = [rectCache objectForKey:[NSNumber numberWithInt:sectionIndex]];
            if (!itemRects && [section fixedItemSize] && [[section rows] count]) {
                itemRects = [[[section rows] objectAtIndex:0] itemRects];
                if (itemRects)
                    [rectCache setObject:itemRects forKey:[NSNumber numberWithInt:sectionIndex]];
            }

            for (UIGridLayoutRow* row in [section rows]) {
                CGRect normalizedRowFrame;

                normalizedRowFrame = [row rowFrame];
                normalizedRowFrame.origin.x += frame.origin.x;
                normalizedRowFrame.origin.y += frame.origin.y;
                if (CGRectIntersectsRect(normalizedRowFrame, rect)) {
                    // TODO be more fine-grained for items

                    for (unsigned itemIndex = 0; itemIndex < [row itemCount]; itemIndex++) {
                        id layoutAttributes;
                        NSUInteger sectionItemIndex;
                        CGRect itemFrame;
                        if ([row fixedItemSize]) {
                            itemFrame = [[itemRects objectAtIndex:itemIndex] CGRectValue];
                            sectionItemIndex = [row index] * [section itemsByRowCount] + itemIndex;
                        } else {
                            UIGridLayoutItem* item = [[row items] objectAtIndex:itemIndex];
                            sectionItemIndex = [[section items] indexOfObjectIdenticalTo:item];

                            itemFrame = [item itemFrame];
                        }

                        CGRect itemRect = CGRectMake(normalizedRowFrame.origin.x + itemFrame.origin.x,
                                                     normalizedRowFrame.origin.y + itemFrame.origin.y,
                                                     itemFrame.size.width,
                                                     itemFrame.size.height);
                        if (CGRectIntersectsRect(itemRect, rect)) {
                            layoutAttributes = [[[self class] layoutAttributesClass]
                                layoutAttributesForCellWithIndexPath:[NSIndexPath indexPathForItem:sectionItemIndex
                                                                                         inSection:sectionIndex]];
                            [layoutAttributes setFrame:CGRectMake(normalizedRowFrame.origin.x + itemFrame.origin.x,
                                                                  normalizedRowFrame.origin.y + itemFrame.origin.y,
                                                                  itemFrame.size.width,
                                                                  itemFrame.size.height)];
                            [layoutAttributesArray addObject:layoutAttributes];
                        }
                    }
                }
            }

            CGRect normalizedFooterFrame;

            normalizedFooterFrame = [section footerFrame];
            normalizedFooterFrame.origin.x += frame.origin.x;
            normalizedFooterFrame.origin.y += frame.origin.y;
            if (!CGRectIsEmpty(normalizedFooterFrame) && CGRectIntersectsRect(normalizedFooterFrame, rect)) {
                id layoutAttributes = [[[self class] layoutAttributesClass]
                    layoutAttributesForSupplementaryViewOfKind:@"UICollectionElementKindSectionFooter"
                                                 withIndexPath:[NSIndexPath indexPathForItem:0 inSection:sectionIndex]];
                [layoutAttributes setFrame:normalizedFooterFrame];
                [layoutAttributesArray addObject:layoutAttributes];
            }
        }
    }
    return layoutAttributesArray;
}

- (id)layoutAttributesForSupplementaryViewOfKind:(id)kind atIndexPath:(NSIndexPath*)indexPath {
    if (!_data)
        [self prepareLayout];

    NSUInteger sectionIndex = [indexPath section];
    id layoutAttributes = nil;

    if (sectionIndex < [[_data sections] count]) {
        id section = [[_data sections] objectAtIndex:sectionIndex];

        CGRect normalizedFrame = CGRectZero;
        if ([kind isEqualToString:@"UICollectionElementKindSectionHeader"]) {
            normalizedFrame = [section headerFrame];
        } else if ([kind isEqualToString:@"UICollectionElementKindSectionFooter"]) {
            normalizedFrame = [section footerFrame];
        }

        if (!CGRectIsEmpty(normalizedFrame)) {
            normalizedFrame.origin.x += [section frame].origin.x;
            normalizedFrame.origin.y += [section frame].origin.y;

            layoutAttributes = [[[self class] layoutAttributesClass]
                layoutAttributesForSupplementaryViewOfKind:kind
                                             withIndexPath:[NSIndexPath indexPathForItem:0 inSection:sectionIndex]];
            [layoutAttributes setFrame:normalizedFrame];
        }
    }
    return layoutAttributes;
}

@end
