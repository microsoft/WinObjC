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

#include "CoreGraphics/CGGeometry.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSMutableSet.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSIndexPath.h"
#include "UICollectionViewItemKey.h"
#include "UIKit/UICollectionViewLayout.h"
#include "UIKit/UICollectionView.h"
#include "UICollectionViewData.h"
#include "UICollectionViewUpdateItem.h"
#include "QuartzCore/CATransaction.h"
#include <algorithm>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

@implementation UICollectionView {
    id _dataSource;
    id<UICollectionViewDelegate> _collectionViewDelegate;
    idretaintype(NSMutableDictionary) _supplementaryViewReuseQueues, _cellReuseQueues, _decorationViewReuseQueues;
    idretain _nibLayout, _nibCellsExternalObjects, _supplementaryViewsExternalObjects;
    idretaintype(NSMutableDictionary) _cellNibDict, _supplementaryViewNibDict, _supplementaryViewClassDict,
        _cellClassDict;
    UICollectionViewData* _collectionViewData;
    idretaintype(NSMutableSet) _indexPathsForSelectedItems, _indexPathsForHighlightedItems;
    idretain _layout;
    idretaintype(NSMutableDictionary) _allVisibleViewsDict;
    idretain _backgroundView;
    idretain _touchingIndexPath, _currentIndexPath;
    idretain _updateCompletionHandler;

    idretaintype(NSMutableArray) _insertItems;
    idretaintype(NSMutableArray) _deleteItems;
    idretaintype(NSMutableArray) _reloadItems;
    idretaintype(NSMutableArray) _moveItems;
    idretaintype(NSMutableDictionary) _update;

    idretain _originalInsertItems, _originalDeleteItems;

    int _reloadingSuspendedCount, _updateCount;

    struct {
        unsigned int delegateShouldHighlightItemAtIndexPath : 1;
        unsigned int delegateDidHighlightItemAtIndexPath : 1;
        unsigned int delegateDidUnhighlightItemAtIndexPath : 1;
        unsigned int delegateShouldSelectItemAtIndexPath : 1;
        unsigned int delegateShouldDeselectItemAtIndexPath : 1;
        unsigned int delegateDidSelectItemAtIndexPath : 1;
        unsigned int delegateDidDeselectItemAtIndexPath : 1;
        unsigned int delegateSupportsMenus : 1;
        unsigned int delegateDidEndDisplayingCell : 1;
        unsigned int delegateDidEndDisplayingSupplementaryView : 1;
        unsigned int dataSourceNumberOfSections : 1;
        unsigned int dataSourceViewForSupplementaryElement : 1;
        unsigned int reloadSkippedDuringSuspension : 1;
        unsigned int scheduledUpdateVisibleCells : 1;
        unsigned int scheduledUpdateVisibleCellLayoutAttributes : 1;
        unsigned int allowsSelection : 1;
        unsigned int allowsMultipleSelection : 1;
        unsigned int updating : 1;
        unsigned int fadeCellsForBoundsChange : 1;
        unsigned int updatingLayout : 1;
        unsigned int needsReload : 1;
        unsigned int reloading : 1;
        unsigned int skipLayoutDuringSnapshotting : 1;
        unsigned int layoutInvalidatedSinceLastCellUpdate : 1;
        unsigned int doneFirstLayout : 1;
    } _collectionViewFlags;
}
static void collectionCommonSetup(UICollectionView* self) {
    self->_collectionViewFlags.allowsSelection = YES;
    self->_cellNibDict.attach([NSMutableDictionary new]);
    self->_cellClassDict.attach([NSMutableDictionary new]);
    self->_supplementaryViewNibDict.attach([NSMutableDictionary new]);
    self->_supplementaryViewClassDict.attach([NSMutableDictionary new]);
    self->_indexPathsForSelectedItems.attach([NSMutableSet new]);
    self->_indexPathsForHighlightedItems.attach([NSMutableSet new]);
    self->_allVisibleViewsDict.attach([NSMutableDictionary new]);
    self->_supplementaryViewReuseQueues.attach([NSMutableDictionary new]);
    self->_cellReuseQueues.attach([NSMutableDictionary new]);
    self->_decorationViewReuseQueues.attach([NSMutableDictionary new]);
}

- (id)initWithCoder:(id)inCoder {
    id ret = [super initWithCoder:inCoder];

    [super setDelegate:(id<UIScrollViewDelegate>)self];
    collectionCommonSetup(self);

    _nibLayout = [inCoder decodeObjectForKey:@"UICollectionLayout"];

    id cellExternalObjects = [inCoder decodeObjectForKey:@"UICollectionViewCellPrototypeNibExternalObjects"];
    id cellNibs = [inCoder decodeObjectForKey:@"UICollectionViewCellNibDict"];

    for (id identifier in [cellNibs allKeys]) {
        [_cellNibDict setObject:[cellNibs objectForKey:identifier] forKey:identifier];
    }

    _nibCellsExternalObjects = cellExternalObjects;

    id supplementaryViewExternalObjects =
        [inCoder decodeObjectForKey:@"UICollectionViewSupplementaryViewPrototypeNibExternalObjects"];
    id supplementaryViewNibs = [inCoder decodeObjectForKey:@"UICollectionViewSupplementaryViewNibDict"];

    for (id identifier in [supplementaryViewNibs allKeys]) {
        [_supplementaryViewNibDict setObject:[supplementaryViewNibs objectForKey:identifier] forKey:identifier];
    }

    _supplementaryViewsExternalObjects = supplementaryViewExternalObjects;

    return ret;
}

- (void)awakeFromNib {
    [super awakeFromNib];

    id nibLayout = _nibLayout;
    if (nibLayout) {
        [self setCollectionViewLayout:nibLayout];
        _nibLayout = nil;
    }
}

- (id)initWithFrame:(CGRect)pos collectionViewLayout:(id)layout {
    id ret = [super initWithFrame:pos];
    [super setDelegate:(id<UIScrollViewDelegate>)self];
    [self setBackgroundColor:[UIColor blackColor]];

    collectionCommonSetup(self);
    [self setCollectionViewLayout:layout];
    _collectionViewData = [[UICollectionViewData alloc] initWithCollectionView:self layout:layout];

    return ret;
}

- (id)initWithFrame:(CGRect)pos {
    return [self initWithFrame:pos collectionViewLayout:nil];
}

- (void)setDataSource:(id)dataSource {
    if (dataSource != _dataSource) {
        _dataSource = dataSource;

        //  Getting Item and Section Metrics
        _collectionViewFlags.dataSourceNumberOfSections =
            [_dataSource respondsToSelector:@selector(numberOfSectionsInCollectionView:)];

        //  Getting Views for Items
        _collectionViewFlags.dataSourceViewForSupplementaryElement =
            [_dataSource respondsToSelector:@selector(collectionView:viewForSupplementaryElementOfKind:atIndexPath:)];
    }
}

- (id)dataSource {
    return _dataSource;
}

- (void)setDelegate:(id)delegate {
    _collectionViewDelegate = delegate;
    _collectionViewFlags.delegateShouldSelectItemAtIndexPath =
        [delegate respondsToSelector:@selector(collectionView:shouldSelectItemAtIndexPath:)];
    _collectionViewFlags.delegateDidSelectItemAtIndexPath =
        [delegate respondsToSelector:@selector(collectionView:didSelectItemAtIndexPath:)];
    _collectionViewFlags.delegateShouldDeselectItemAtIndexPath =
        [delegate respondsToSelector:@selector(collectionView:shouldDeselectItemAtIndexPath:)];
    _collectionViewFlags.delegateDidDeselectItemAtIndexPath =
        [delegate respondsToSelector:@selector(collectionView:didDeselectItemAtIndexPath:)];

    //  Managing Cell Highlighting
    _collectionViewFlags.delegateShouldHighlightItemAtIndexPath =
        [delegate respondsToSelector:@selector(collectionView:shouldHighlightItemAtIndexPath:)];
    _collectionViewFlags.delegateDidHighlightItemAtIndexPath =
        [delegate respondsToSelector:@selector(collectionView:didHighlightItemAtIndexPath:)];
    _collectionViewFlags.delegateDidUnhighlightItemAtIndexPath =
        [delegate respondsToSelector:@selector(collectionView:didUnhighlightItemAtIndexPath:)];

    //  Tracking the Removal of Views
    _collectionViewFlags.delegateDidEndDisplayingCell =
        [delegate respondsToSelector:@selector(collectionView:didEndDisplayingCell:forItemAtIndexPath:)];
    _collectionViewFlags.delegateDidEndDisplayingSupplementaryView = [delegate
        respondsToSelector:@selector(collectionView:didEndDisplayingSupplementaryView:forElementOfKind:atIndexPath:)];

    //  Managing Actions for Cells
    _collectionViewFlags.delegateSupportsMenus =
        [delegate respondsToSelector:@selector(collectionView:shouldShowMenuForItemAtIndexPath:)];
}

- (id)delegate {
    return _collectionViewDelegate;
}

- (id)setCollectionViewLayout:(id)layout animated:(BOOL)animated {
    if (layout == _layout)
        return 0;

    // not sure it was it original code, but here this prevents crash
    // in case we switch layout before previous one was initially loaded
    CGRect bounds = { 0 };
    bounds = [self bounds];

    if (CGRectIsEmpty(bounds) || !_collectionViewFlags.doneFirstLayout) {
        [_layout setCollectionView:nil];
        _collectionViewData = [[UICollectionViewData alloc] initWithCollectionView:self layout:layout];
        [layout setCollectionView:self];
        _layout = layout;

        // originally the use method
        // _setNeedsVisibleCellsUpdate:withLayoutAttributes:
        // here with CellsUpdate set to YES and LayoutAttributes parameter set to NO
        // inside this method probably some flags are set and finally
        // setNeedsDisplay is called

        _collectionViewFlags.scheduledUpdateVisibleCells = YES;
        _collectionViewFlags.scheduledUpdateVisibleCellLayoutAttributes = NO;

        [self setNeedsDisplay];
    } else {
        [layout setCollectionView:self];

        _collectionViewData = [[UICollectionViewData alloc] initWithCollectionView:self layout:layout];
        [_collectionViewData prepareToLoadData];

        id previouslySelectedIndexPaths = [self indexPathsForSelectedItems];
        id selectedCellKeys = [NSMutableSet setWithCapacity:[previouslySelectedIndexPaths count]];

        for (id indexPath in previouslySelectedIndexPaths) {
            [selectedCellKeys addObject:[UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:indexPath]];
        }

        id previouslyVisibleItemsKeys = [_allVisibleViewsDict allKeys];
        id previouslyVisibleItemsKeysSet = [NSSet setWithArray:previouslyVisibleItemsKeys];
        id previouslyVisibleItemsKeysSetMutable = [NSMutableSet setWithArray:previouslyVisibleItemsKeys];

        if ([selectedCellKeys intersectsSet:selectedCellKeys]) {
            [previouslyVisibleItemsKeysSetMutable intersectSet:previouslyVisibleItemsKeysSetMutable];
        }

        [self bringSubviewToFront:[_allVisibleViewsDict objectForKey:[previouslyVisibleItemsKeysSetMutable anyObject]]];

        CGPoint targetOffset;
        targetOffset = [self contentOffset];
        CGPoint centerPoint =
            CGPoint::point(bounds.origin.x + bounds.size.width / 2.f, bounds.origin.y + bounds.size.height / 2.f);
        id centerItemIndexPath = [self indexPathForItemAtPoint:centerPoint];

        if (!centerItemIndexPath) {
            id visibleItems = [self indexPathsForVisibleItems];
            if ([visibleItems count] > 0) {
                centerItemIndexPath = [visibleItems objectAtIndex:([visibleItems count] / 2)];
            }
        }

        if (centerItemIndexPath) {
            id layoutAttributes = [layout layoutAttributesForItemAtIndexPath:centerItemIndexPath];
            if (layoutAttributes) {
// We don't have a makeRect in this implementation..
#if 0
UICollectionViewScrollPosition scrollPosition = UICollectionViewScrollPositionCenteredVertically|UICollectionViewScrollPositionCenteredHorizontally;
CGRect targetRect, layoutAttributesFrame;

layoutAttributesFrame = [layoutAttributes frame];
targetRect = [self makeRect:layoutAttributesFrame toScrollPosition:scrollPosition];
targetOffset = CGPoint::point(std::max(0.f, (float) targetRect.origin.x), std::max(0.f, (float) targetRect.origin.y));
#endif
            }
        }

        CGRect newlyBounds = CGRectMake(targetOffset.x, targetOffset.y, bounds.size.width, bounds.size.height);
        id newlyVisibleLayoutAttrs = [_collectionViewData layoutAttributesForElementsInRect:newlyBounds];

        id layoutInterchangeData = [NSMutableDictionary
            dictionaryWithCapacity:[newlyVisibleLayoutAttrs count] + [previouslyVisibleItemsKeysSet count]];

        id newlyVisibleItemsKeys = [NSMutableSet set];
        for (id attr in newlyVisibleLayoutAttrs) {
            UICollectionViewItemKey* newKey = [UICollectionViewItemKey collectionItemKeyForLayoutAttributes:attr];
            [newlyVisibleItemsKeys addObject:newKey];

            id prevAttr = nil;
            id newAttr = nil;

            if ([newKey type] == UICollectionViewItemTypeDecorationView) {
                prevAttr =
                    [[self collectionViewLayout] layoutAttributesForDecorationViewOfKind:[attr representedElementKind]
                                                                             atIndexPath:[newKey indexPath]];
                newAttr = [layout layoutAttributesForDecorationViewOfKind:[attr representedElementKind]
                                                              atIndexPath:[newKey indexPath]];
            } else if ([newKey type] == UICollectionViewItemTypeCell) {
                prevAttr = [[self collectionViewLayout] layoutAttributesForItemAtIndexPath:[newKey indexPath]];
                newAttr = [layout layoutAttributesForItemAtIndexPath:[newKey indexPath]];
            } else {
                prevAttr = [[self collectionViewLayout]
                    layoutAttributesForSupplementaryViewOfKind:[attr representedElementKind]
                                                   atIndexPath:[newKey indexPath]];
                newAttr = [layout layoutAttributesForSupplementaryViewOfKind:[attr representedElementKind]
                                                                 atIndexPath:[newKey indexPath]];
            }

            if (prevAttr != nil && newAttr != nil) {
                [layoutInterchangeData setObject:[NSDictionary dictionaryWithObjectsAndKeys:prevAttr,
                                                                                            @"previousLayoutInfos",
                                                                                            "newAttr",
                                                                                            @"newLayoutInfos",
                                                                                            NULL]
                                          forKey:newKey];
            }
        }

        for (UICollectionViewItemKey* key in previouslyVisibleItemsKeysSet) {
            id prevAttr = nil;
            id newAttr = nil;

            if ([key type] == UICollectionViewItemTypeDecorationView) {
                id decorView = [_allVisibleViewsDict objectForKey:key];
                prevAttr =
                    [[self collectionViewLayout] layoutAttributesForDecorationViewOfKind:[decorView reuseIdentifier]
                                                                             atIndexPath:[key indexPath]];
                newAttr = [layout layoutAttributesForDecorationViewOfKind:[decorView reuseIdentifier]
                                                              atIndexPath:[key indexPath]];
            } else if ([key type] == UICollectionViewItemTypeCell) {
                prevAttr = [[self collectionViewLayout] layoutAttributesForItemAtIndexPath:[key indexPath]];
                newAttr = [layout layoutAttributesForItemAtIndexPath:[key indexPath]];
            } else if ([key type] == UICollectionViewItemTypeSupplementaryView) {
                id suuplView = [_allVisibleViewsDict objectForKey:key];
                prevAttr = [[self collectionViewLayout]
                    layoutAttributesForSupplementaryViewOfKind:[[suuplView layoutAttributes] representedElementKind]
                                                   atIndexPath:[key indexPath]];
                newAttr = [layout
                    layoutAttributesForSupplementaryViewOfKind:[[suuplView layoutAttributes] representedElementKind]
                                                   atIndexPath:[key indexPath]];
            }

            id layoutInterchangeDataValue = [NSMutableDictionary dictionary];
            if (prevAttr)
                [layoutInterchangeDataValue setObject:prevAttr forKey:@"previousLayoutInfos"];
            if (newAttr)
                [layoutInterchangeDataValue setObject:newAttr forKey:@"newLayoutInfos"];
            [layoutInterchangeData setObject:layoutInterchangeDataValue forKey:key];
        }

        for (UICollectionViewItemKey* key in [layoutInterchangeData keyEnumerator]) {
            if ([key type] == UICollectionViewItemTypeCell) {
                id cell = [_allVisibleViewsDict objectForKey:key];

                if (!cell) {
                    cell = [self createPreparedCellForItemAtIndexPath:[key indexPath]
                                                 withLayoutAttributes:[[layoutInterchangeData objectForKey:key]
                                                                          objectForKey:@"previousLayoutInfos"]];
                    [_allVisibleViewsDict setObject:cell forKey:key];
                    [self addControlledSubview:cell];
                } else
                    [cell applyLayoutAttributes:[[layoutInterchangeData objectForKey:key]
                                                    objectForKey:@"previousLayoutInfos"]];
            } else if ([key type] == UICollectionViewItemTypeSupplementaryView) {
                id view = [_allVisibleViewsDict objectForKey:key];
                if (!view) {
                    id attrs = [[layoutInterchangeData objectForKey:key] objectForKey:@"previousLayoutInfos"];
                    view = [self createPreparedSupplementaryViewForElementOfKind:[attrs representedElementKind]
                                                                     atIndexPath:[attrs indexPath]
                                                            withLayoutAttributes:attrs];
                    [_allVisibleViewsDict setObject:view forKey:key];
                    [self addControlledSubview:view];
                }
            } else if ([key type] == UICollectionViewItemTypeDecorationView) {
                id view = [_allVisibleViewsDict objectForKey:key];
                if (!view) {
                    id attrs = [[layoutInterchangeData objectForKey:key] objectForKey:@"previousLayoutInfos"];
                    view = [self dequeueReusableOrCreateDecorationViewOfKind:[attrs representedElementKind]
                                                                forIndexPath:[attrs indexPath]];
                    [_allVisibleViewsDict setObject:view forKey:key];
                    [self addControlledSubview:view];
                }
            }
        }

        CGRect contentRect;

        contentRect = [_collectionViewData collectionViewContentRect];

#if 0
void (^applyNewLayoutBlock)(void) = ^{
NSEnumerator *keys = [layoutInterchangeData keyEnumerator];
for (PSTCollectionViewItemKey *key in keys) {
// TODO: This is most likely not 100% the same time as in UICollectionView. Needs to be investigated.
PSTCollectionViewCell *cell = (PSTCollectionViewCell *)_allVisibleViewsDict[key];
[cell willTransitionFromLayout:_layout toLayout:layout];
[cell applyLayoutAttributes:layoutInterchangeData[key][@"newLayoutInfos"]];
[cell didTransitionFromLayout:_layout toLayout:layout];
}
};

void (^freeUnusedViews)(void) = ^{
NSMutableSet *toRemove = [NSMutableSet set];
for (PSTCollectionViewItemKey *key in [_allVisibleViewsDict keyEnumerator]) {
if (![newlyVisibleItemsKeys containsObject:key]) {
if (key.type == PSTCollectionViewItemTypeCell) {
[self reuseCell:_allVisibleViewsDict[key]];
[toRemove addObject:key];
}
else if (key.type == PSTCollectionViewItemTypeSupplementaryView) {
[self reuseSupplementaryView:_allVisibleViewsDict[key]];
[toRemove addObject:key];
}
else if (key.type == PSTCollectionViewItemTypeDecorationView) {
[self reuseDecorationView:_allVisibleViewsDict[key]];
[toRemove addObject:key];
}
}
}

for (id key in toRemove)
[_allVisibleViewsDict removeObjectForKey:key];
};

if (animated) {
[UIView animateWithDuration:.3 animations:^{
_collectionViewFlags.updatingLayout = YES;
self.contentOffset = targetOffset;
self.contentSize = contentRect.size;
applyNewLayoutBlock();
} completion:^(BOOL finished) {
freeUnusedViews();
_collectionViewFlags.updatingLayout = NO;

// layout subviews for updating content offset or size while updating layout
if (!CGPointEqualToPoint(self.contentOffset, targetOffset)
|| !CGSizeEqualToSize(self.contentSize, contentRect.size)) {
[self layoutSubviews];
}
}];  }
else {
self.contentOffset = targetOffset;
self.contentSize = contentRect.size;
applyNewLayoutBlock();
freeUnusedViews();
}
#endif
        assert(0);

        [_layout setCollectionView:nil];
        _layout = layout;
    }

    return 0;
}

- (void)setCollectionViewLayout:(id)layout {
    [self setCollectionViewLayout:layout animated:NO];
}

- (void)registerNib:(id)nib forCellWithReuseIdentifier:(id)identifier {
    [_cellNibDict setObject:nib forKey:identifier];
}

- (void)registerNib:(id)nib forSupplementaryViewOfKind:(id)kind withReuseIdentifier:(id)identifier {
    id kindAndIdentifier = [NSString stringWithFormat:@"%@/%@", kind, identifier];
    [_supplementaryViewNibDict setObject:nib forKey:kindAndIdentifier];
}

- (void)layoutSubviews {
    [super layoutSubviews];

    // Adding alpha animation to make the relayouting smooth
    if (_collectionViewFlags.fadeCellsForBoundsChange) {
#if 0
CATransition *transition = [CATransition animation];
transition.duration = 0.25f * PSTSimulatorAnimationDragCoefficient();
transition.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
transition.type = kCATransitionFade;
[self.layer addAnimation:transition forKey:@"rotationAnimation"];
#endif
        assert(0);
    }

    CGRect bounds;
    bounds = [self bounds];

    [_collectionViewData validateLayoutInRect:bounds];

    // update cells
    if (_collectionViewFlags.fadeCellsForBoundsChange) {
        assert(0);
#if 0
[CATransaction begin];
[CATransaction setDisableActions:YES];
#endif
    }

    if (!_collectionViewFlags.updatingLayout)
        [self updateVisibleCellsNow:YES];

    if (_collectionViewFlags.fadeCellsForBoundsChange) {
#if 0
[CATransaction commit];
#endif
        assert(0);
    }

    // do we need to update contentSize?
    CGSize contentSize;
    CGRect contentRect;

    contentRect = [_collectionViewData collectionViewContentRect];
    contentSize = contentRect.size;

    CGSize curSize;

    curSize = [self contentSize];

    if (!CGSizeEqualToSize(curSize, contentSize)) {
        [self setContentSize:contentSize];

        // if contentSize is different, we need to re-evaluate layout, bounds (contentOffset) might changed
        bounds = [self bounds];
        [_collectionViewData validateLayoutInRect:bounds];
        [self updateVisibleCellsNow:YES];
    }

    if (_backgroundView) {
        CGPoint contentOffset;

        contentOffset = [self contentOffset];
        bounds = [self bounds];

        CGRect rect = CGRectMake(contentOffset.x, contentOffset.y, bounds.size.width, bounds.size.height);
        [_backgroundView setFrame:rect];
    }

    _collectionViewFlags.fadeCellsForBoundsChange = NO;
    _collectionViewFlags.doneFirstLayout = YES;
}

- (id)invalidateLayout {
    [_layout invalidateLayout];
    [_collectionViewData invalidate]; // invalidate layout cache
    return self;
}

- (id)collectionViewLayout {
    return _layout;
}

- (id)collectionViewData {
    return _collectionViewData;
}

- (void)reloadData {
    if (_reloadingSuspendedCount != 0)
        return;
    [self invalidateLayout];

    for (id curView in(id) _allVisibleViewsDict) {
        id obj = [_allVisibleViewsDict objectForKey:curView];

        if ([obj isKindOfClass:[UIView class]]) {
            [obj removeFromSuperview];
        }
    }
    [_allVisibleViewsDict removeAllObjects];

    for (id indexPath in(id) _indexPathsForSelectedItems) {
        id selectedCell = [self cellForItemAtIndexPath:indexPath];
        [selectedCell setSelected:NO];
        [selectedCell setHighlighted:NO];
    }
    [_indexPathsForSelectedItems removeAllObjects];
    [_indexPathsForHighlightedItems removeAllObjects];

    [self setNeedsLayout];
}

- (id)indexPathsForSelectedItems {
    return [_indexPathsForSelectedItems allObjects];
}

- (NSInteger)numberOfSections {
    return [_collectionViewData numberOfSections];
}

- (NSInteger)numberOfItemsInSection:(int)section {
    return [_collectionViewData numberOfItemsInSection:section];
}

- (id)updateVisibleCellsNow:(BOOL)now {
    CGRect bounds;
    bounds = [self bounds];

    id layoutAttributesArray = [_collectionViewData layoutAttributesForElementsInRect:bounds];

    if (layoutAttributesArray == nil || [layoutAttributesArray count] == 0) {
        // If our layout source isn't providing any layout information, we should just
        // stop, otherwise we'll blow away all the currently existing cells.
        return 0;
    }

    // create ItemKey/Attributes dictionary
    id itemKeysToAddDict = [NSMutableDictionary dictionary];

    // Add new cells.
    for (id layoutAttributes in layoutAttributesArray) {
        UICollectionViewItemKey* itemKey =
            [UICollectionViewItemKey collectionItemKeyForLayoutAttributes:layoutAttributes];
        [itemKeysToAddDict setObject:layoutAttributes forKey:itemKey];

        // check if cell is in visible dict; add it if not.
        id view = [_allVisibleViewsDict objectForKey:itemKey];
        if (!view || [view _needsRefresh]) {
            if (view) {
                id reusableView = view;
                [[itemKey retain] autorelease];

                //  View needs refreshing
                [reusableView removeFromSuperview];
                [_allVisibleViewsDict removeObjectForKey:itemKey];
                if ([itemKey type] == UICollectionViewItemTypeCell) {
                    if (_collectionViewFlags.delegateDidEndDisplayingCell) {
                        [_collectionViewDelegate collectionView:self
                                           didEndDisplayingCell:reusableView
                                             forItemAtIndexPath:[itemKey indexPath]];
                    }
                    [self reuseCell:reusableView];
                } else if ([itemKey type] == UICollectionViewItemTypeSupplementaryView) {
                    if (_collectionViewFlags.delegateDidEndDisplayingSupplementaryView) {
                        [_collectionViewDelegate collectionView:self
                              didEndDisplayingSupplementaryView:reusableView
                                               forElementOfKind:[itemKey identifier]
                                                    atIndexPath:[itemKey indexPath]];
                    }
                    [self reuseSupplementaryView:reusableView];
                } else if ([itemKey type] == UICollectionViewItemTypeDecorationView) {
                    [self reuseDecorationView:reusableView];
                }
                view = nil;
            }
            if ([itemKey type] == UICollectionViewItemTypeCell) {
                view = [self createPreparedCellForItemAtIndexPath:[itemKey indexPath]
                                             withLayoutAttributes:layoutAttributes];

            } else if ([itemKey type] == UICollectionViewItemTypeSupplementaryView) {
                view = [self createPreparedSupplementaryViewForElementOfKind:[layoutAttributes representedElementKind]
                                                                 atIndexPath:[layoutAttributes indexPath]
                                                        withLayoutAttributes:layoutAttributes];
            } else if ([itemKey type] == UICollectionViewItemTypeDecorationView) {
                view = [self dequeueReusableOrCreateDecorationViewOfKind:[layoutAttributes representedElementKind]
                                                            forIndexPath:[layoutAttributes indexPath]];
            }

            // Supplementary views are optional
            if (view) {
                [view _setNeedsRefresh:FALSE];
                [_allVisibleViewsDict setObject:view forKey:itemKey];
                [self addControlledSubview:view];

                // Always apply attributes. Fixes #203.
                [view applyLayoutAttributes:layoutAttributes];
            }
        } else {
            // just update cell
            [view applyLayoutAttributes:layoutAttributes];
        }
    }

    // Detect what items should be removed and queued back.
    id allVisibleItemKeys = [NSMutableSet setWithArray:[_allVisibleViewsDict allKeys]];
    [allVisibleItemKeys minusSet:[NSSet setWithArray:[itemKeysToAddDict allKeys]]];

    // Finally remove views that have not been processed and prepare them for re-use.
    for (UICollectionViewItemKey* itemKey in allVisibleItemKeys) {
        id reusableView = [_allVisibleViewsDict objectForKey:itemKey];
        if (reusableView) {
            [reusableView removeFromSuperview];
            [_allVisibleViewsDict removeObjectForKey:itemKey];
            if ([itemKey type] == UICollectionViewItemTypeCell) {
                if (_collectionViewFlags.delegateDidEndDisplayingCell) {
                    [_collectionViewDelegate collectionView:self
                                       didEndDisplayingCell:reusableView
                                         forItemAtIndexPath:[itemKey indexPath]];
                }
                [self reuseCell:reusableView];
            } else if ([itemKey type] == UICollectionViewItemTypeSupplementaryView) {
                if (_collectionViewFlags.delegateDidEndDisplayingSupplementaryView) {
                    [_collectionViewDelegate collectionView:self
                          didEndDisplayingSupplementaryView:reusableView
                                           forElementOfKind:[itemKey identifier]
                                                atIndexPath:[itemKey indexPath]];
                }
                [self reuseSupplementaryView:reusableView];
            } else if ([itemKey type] == UICollectionViewItemTypeDecorationView) {
                [self reuseDecorationView:reusableView];
            }
        }
    }

    return 0;
}

- (id)createPreparedCellForItemAtIndexPath:(NSIndexPath*)indexPath withLayoutAttributes:(id)layoutAttributes {
    id cell = [_dataSource collectionView:self cellForItemAtIndexPath:indexPath];

    // Apply attributes
    [cell applyLayoutAttributes:layoutAttributes];

    // reset selected/highlight state
    [cell setHighlighted:[_indexPathsForHighlightedItems containsObject:indexPath]];
    [cell setSelected:[_indexPathsForSelectedItems containsObject:indexPath]];

    // voiceover support
    [cell setIsAccessibilityElement:YES];

    return cell;
}

- (id)createPreparedSupplementaryViewForElementOfKind:(id)kind
                                          atIndexPath:(NSIndexPath*)indexPath
                                 withLayoutAttributes:(id)layoutAttributes {
    if (_collectionViewFlags.dataSourceViewForSupplementaryElement) {
        id view = [_dataSource collectionView:self viewForSupplementaryElementOfKind:kind atIndexPath:indexPath];
        [view applyLayoutAttributes:layoutAttributes];
        return view;
    }
    return nil;
}

- (id)dequeueReusableSupplementaryViewOfKind:(id)elementKind
                         withReuseIdentifier:(id)identifier
                                forIndexPath:(NSIndexPath*)indexPath {
    id kindAndIdentifier = [NSString stringWithFormat:@"%@/%@", elementKind, identifier];
    id reusableViews = [_supplementaryViewReuseQueues objectForKey:kindAndIdentifier];
    id view = [[[reusableViews lastObject] retain] autorelease];
    if (view) {
        [reusableViews removeObjectAtIndex:[reusableViews count] - 1];
    } else {
        if ([_supplementaryViewNibDict objectForKey:kindAndIdentifier]) {
            // supplementary view was registered via registerNib:forCellWithReuseIdentifier:
            id supplementaryViewNib = [_supplementaryViewNibDict objectForKey:kindAndIdentifier];
            id externalObjects = [_supplementaryViewsExternalObjects objectForKey:kindAndIdentifier];
            if (externalObjects) {
                id objects = [supplementaryViewNib instantiateWithOwner:self options:nil proxies:externalObjects];
                view = [objects objectAtIndex:0];
            } else {
                id objects = [supplementaryViewNib instantiateWithOwner:self options:nil];
                view = [objects objectAtIndex:0];
            }
        } else {
            id viewClass = [_supplementaryViewClassDict objectForKey:kindAndIdentifier];
            if (viewClass == nil) {
                assert(0);
                return nil;
                //@throw [NSException exceptionWithName:NSInvalidArgumentException reason:[NSString
                //stringWithFormat:@"Class not registered for kind/identifier %@", kindAndIdentifier] userInfo:nil];
            }
            if (_layout) {
                id attributes = [_layout layoutAttributesForSupplementaryViewOfKind:elementKind atIndexPath:indexPath];
                if (attributes) {
                    CGRect frame;
                    frame = [attributes frame];
                    view = [[viewClass alloc] initWithFrame:frame];
                }
            } else {
                view = [viewClass new];
            }
        }
        [view setCollectionView:self];
        [view setReuseIdentifier:identifier];
    }

    return view;
}

- (void)registerClass:(Class)cls forCellWithReuseIdentifier:(NSString*)id {
    [_cellClassDict setObject:cls forKey:id];
}

- (id)dequeueReusableCellWithReuseIdentifier:(id)identifier forIndexPath:(NSIndexPath*)indexPath {
    // de-queue cell (if available)
    id reusableCells = [_cellReuseQueues objectForKey:identifier];
    id cell = [[[reusableCells lastObject] retain] autorelease];
    id attributes = [_layout layoutAttributesForItemAtIndexPath:indexPath];

    if (cell) {
        [reusableCells removeObjectAtIndex:[reusableCells count] - 1];
    } else {
        if ([_cellNibDict objectForKey:identifier]) {
            // Cell was registered via registerNib:forCellWithReuseIdentifier:
            id cellNib = [_cellNibDict objectForKey:identifier];
            id externalObjects = [_nibCellsExternalObjects objectForKey:identifier];

            if (externalObjects) {
                id objects = [cellNib instantiateWithOwner:self options:nil proxies:externalObjects];
                cell = [objects objectAtIndex:0];
            } else {
                id objects = [cellNib instantiateWithOwner:self options:nil];
                cell = [objects objectAtIndex:0];
            }
        } else {
            id cellClass = [_cellClassDict objectForKey:identifier];
            if (cellClass == nil) {
                assert(0);
                //@throw [NSException exceptionWithName:NSInvalidArgumentException reason:[NSString
                //stringWithFormat:@"Class not registered for identifier %@", identifier] userInfo:nil];
            }
            if (attributes) {
                cell = [[cellClass alloc] initWithFrame:[attributes frame]];
            } else {
                cell = [cellClass new];
            }
        }
        [cell setCollectionView:self];
        [cell setReuseIdentifier:identifier];
    }

    [cell applyLayoutAttributes:attributes];

    return cell;
}

- (id)dequeueReusableOrCreateDecorationViewOfKind:(id)elementKind forIndexPath:(NSIndexPath*)indexPath {
    id reusableViews = [_decorationViewReuseQueues objectForKey:elementKind];
    id view = [[[reusableViews lastObject] retain] autorelease];
    id collectionViewLayout = _layout;
    id attributes = [collectionViewLayout layoutAttributesForDecorationViewOfKind:elementKind atIndexPath:indexPath];

    if (view) {
        [reusableViews removeObjectAtIndex:[reusableViews count] - 1];
    } else {
        id decorationViewNibDict = [collectionViewLayout decorationViewNibDict];
        id decorationViewExternalObjects = [collectionViewLayout decorationViewExternalObjectsTables];
        if ([decorationViewNibDict objectForKey:elementKind]) {
            // supplementary view was registered via registerNib:forCellWithReuseIdentifier:
            id supplementaryViewNib = [decorationViewNibDict objectForKey:elementKind];
            id externalObjects = [decorationViewExternalObjects objectForKey:elementKind];
            if (externalObjects) {
                id objects = [supplementaryViewNib instantiateWithOwner:self options:nil proxies:externalObjects];
                view = [objects objectAtIndex:0];
            } else {
                id objects = [supplementaryViewNib instantiateWithOwner:self options:nil];
                view = [objects objectAtIndex:0];
            }

        } else {
            id decorationViewClassDict = [collectionViewLayout decorationViewClassDict];
            id viewClass = [decorationViewClassDict objectForKey:elementKind];
            if (viewClass == nil) {
                assert(0);
                //@throw [NSException exceptionWithName:NSInvalidArgumentException reason:[NSString
                //stringWithFormat:@"Class not registered for identifier %@", elementKind] userInfo:nil];
            }
            if (attributes) {
                view = [[viewClass alloc] initWithFrame:[attributes frame]];
            } else {
                view = [viewClass new];
            }
        }
        [view setCollectionView:self];
        [view setReuseIdentifier:elementKind];
    }

    [view applyLayoutAttributes:attributes];

    return view;
}

- (id)addControlledSubview:(id)subview {
    // avoids placing views above the scroll indicator
    // If the collection view is not displaying scrollIndicators then self.subviews.count can be 0.
    // We take the max to ensure we insert at a non negative index because a negative index will silently fail to insert
    // the view
    NSInteger insertionIndex = MAX((NSInteger)([[self subviews] count] - ([self isDragging] ? 1 : 0)), 0);
    [self insertSubview:subview atIndex:insertionIndex];
    id scrollIndicatorView = nil;
    if ([self isDragging]) {
        scrollIndicatorView = [[self subviews] lastObject];
    }

#if 0
id floatingViews = [[NSMutableArray alloc] init];
for (id uiView in [self subviews]) {
for (UIView *uiView in self.subviews) {
if ([uiView isKindOfClass:PSTCollectionReusableView.class] && [[(PSTCollectionReusableView *)uiView layoutAttributes] zIndex] > 0) {
[floatingViews addObject:uiView];
}
}

[floatingViews sortUsingComparator:^NSComparisonResult(PSTCollectionReusableView *obj1, PSTCollectionReusableView *obj2) {
CGFloat z1 = [[obj1 layoutAttributes] zIndex];
CGFloat z2 = [[obj2 layoutAttributes] zIndex];
if (z1 > z2) {
return (NSComparisonResult)NSOrderedDescending;
}else if (z1 < z2) {
return (NSComparisonResult)NSOrderedAscending;
}else {
return (NSComparisonResult)NSOrderedSame;
}
}];

for (PSTCollectionReusableView *uiView in floatingViews) {
[self bringSubviewToFront:uiView];
}

if (floatingViews.count && scrollIndicatorView) {
[self bringSubviewToFront:scrollIndicatorView];
}
#endif
    return 0;
}

- (id)reuseCell:(id)cell {
    [self queueReusableView:cell inQueue:(id)_cellReuseQueues withIdentifier:[cell reuseIdentifier]];

    return 0;
}

- (id)reuseSupplementaryView:(id)supplementaryView {
    id kindAndIdentifier = [NSString stringWithFormat:@"%@/%@",
                                                      [[supplementaryView layoutAttributes] elementKind],
                                                      [supplementaryView reuseIdentifier]];
    [self queueReusableView:supplementaryView
                    inQueue:(id)_supplementaryViewReuseQueues
             withIdentifier:kindAndIdentifier];
    return 0;
}

- (id)reuseDecorationView:(id)decorationView {
    [self queueReusableView:decorationView
                    inQueue:(id)_decorationViewReuseQueues
             withIdentifier:[decorationView reuseIdentifier]];

    return 0;
}

- (id)queueReusableView:(id)reusableView inQueue:(id)queue withIdentifier:(id)identifier {
    assert([identifier length] > 0);

    [reusableView removeFromSuperview];
    [reusableView prepareForReuse];

    // enqueue cell
    id reuseableViews = [queue objectForKey:identifier];
    if (!reuseableViews) {
        reuseableViews = [NSMutableArray array];
        [queue setObject:reuseableViews forKey:identifier];
    }
    [reuseableViews addObject:reusableView];

    return 0;
}

- (void)touchesBegan:(id)touches withEvent:(id)event {
    // reset touching state vars
    _touchingIndexPath = nil;
    _currentIndexPath = nil;

    CGPoint touchPoint = [[touches anyObject] locationInView:self];
    NSIndexPath* indexPath = [self indexPathForItemAtPoint:touchPoint];
    if (indexPath && [self allowsSelection]) {
        if (![self highlightItemAtIndexPath:indexPath
                                   animated:YES
                             scrollPosition:UICollectionViewScrollPositionNone
                             notifyDelegate:YES])
            return;

        _touchingIndexPath = indexPath;
        _currentIndexPath = indexPath;

        if (![self allowsMultipleSelection]) {
            // temporally unhighlight background on touchesBegan (keeps selected by _indexPathsForSelectedItems)
            // single-select only mode only though
            id tempDeselectIndexPath = [_indexPathsForSelectedItems anyObject];
            if (tempDeselectIndexPath && ![tempDeselectIndexPath isEqual:(id)_touchingIndexPath]) {
                // iOS6 UICollectionView deselects cell without notification
                id selectedCell = [self cellForItemAtIndexPath:tempDeselectIndexPath];
                [selectedCell setSelected:NO];
            }
        }
    }
}

- (void)touchesMoved:(id)touches withEvent:(id)event {
    if (_touchingIndexPath) {
        CGPoint touchPoint = [[touches anyObject] locationInView:self];
        NSIndexPath* indexPath = [self indexPathForItemAtPoint:touchPoint];

        // moving out of bounds
        if ([_currentIndexPath isEqual:(id)_touchingIndexPath] && ![indexPath isEqual:(id)_touchingIndexPath] &&
            [self unhighlightItemAtIndexPath:(id)_touchingIndexPath
                                    animated:YES
                              notifyDelegate:YES
                        shouldCheckHighlight:YES]) {
            _currentIndexPath = indexPath;
            // moving back into the original touching cell
        } else if (![_currentIndexPath isEqual:(id)_touchingIndexPath] && [indexPath isEqual:(id)_touchingIndexPath]) {
            [self highlightItemAtIndexPath:(id)_touchingIndexPath
                                  animated:YES
                            scrollPosition:UICollectionViewScrollPositionNone
                            notifyDelegate:YES];
            _currentIndexPath = _touchingIndexPath;
        }
    }
}

- (void)touchesEnded:(id)touches withEvent:(id)event {
    if (_touchingIndexPath) {
        // first unhighlight the touch operation
        [self unhighlightItemAtIndexPath:(id)_touchingIndexPath animated:YES notifyDelegate:YES];

        CGPoint touchPoint = [[touches anyObject] locationInView:self];
        NSIndexPath* indexPath = [self indexPathForItemAtPoint:touchPoint];
        if ([indexPath isEqual:(id)_touchingIndexPath]) {
            [self userSelectedItemAtIndexPath:indexPath];
        } else if (![self allowsMultipleSelection]) {
            id tempDeselectIndexPath = [_indexPathsForSelectedItems anyObject];
            if (tempDeselectIndexPath && ![tempDeselectIndexPath isEqual:(id)_touchingIndexPath]) {
                [self cellTouchCancelled];
            }
        }

        // for pedantic reasons only - always set to nil on touchesBegan
        _touchingIndexPath = nil;
        _currentIndexPath = nil;
    }
}

- (id)cellTouchCancelled {
    // turn on ALL the *should be selected* cells (iOS6 UICollectionView does no state keeping or other fancy
    // optimizations)
    // there should be no notifications as this is a silent "turn everything back on"
    id selectedCopy = [_indexPathsForSelectedItems copy];
    for (id tempDeselectedIndexPath in selectedCopy) {
        id selectedCell = [self cellForItemAtIndexPath:tempDeselectedIndexPath];
        [selectedCell setSelected:YES];
    }
    [selectedCopy release];

    return self;
}

- (id)userSelectedItemAtIndexPath:(NSIndexPath*)indexPath {
    if ([self allowsMultipleSelection] && [_indexPathsForSelectedItems containsObject:indexPath]) {
        [self deselectItemAtIndexPath:indexPath animated:YES notifyDelegate:YES];
    } else if ([self allowsSelection]) {
        [self selectItemAtIndexPath:indexPath
                           animated:YES
                     scrollPosition:UICollectionViewScrollPositionNone
                     notifyDelegate:YES];
    }

    return self;
}

- (id)selectItemAtIndexPath:(NSIndexPath*)indexPath
                   animated:(BOOL)animated
             scrollPosition:(UICollectionViewScrollPosition)scrollPosition
             notifyDelegate:(BOOL)notifyDelegate {
    if ([self allowsMultipleSelection] && [_indexPathsForSelectedItems containsObject:indexPath]) {
        BOOL shouldDeselect = YES;
        if (notifyDelegate && _collectionViewFlags.delegateShouldDeselectItemAtIndexPath) {
            shouldDeselect = [_collectionViewDelegate collectionView:self shouldDeselectItemAtIndexPath:indexPath];
        }

        if (shouldDeselect) {
            [self deselectItemAtIndexPath:indexPath animated:animated notifyDelegate:notifyDelegate];
        }
    } else {
        // either single selection, or wasn't already selected in multiple selection mode
        BOOL shouldSelect = YES;
        if (notifyDelegate && _collectionViewFlags.delegateShouldSelectItemAtIndexPath) {
            shouldSelect = [_collectionViewDelegate collectionView:self shouldSelectItemAtIndexPath:indexPath];
        }

        if (![self allowsMultipleSelection]) {
            // now unselect the previously selected cell for single selection
            id tempDeselectIndexPath = [_indexPathsForSelectedItems anyObject];
            if (tempDeselectIndexPath && ![tempDeselectIndexPath isEqual:indexPath]) {
                [self deselectItemAtIndexPath:tempDeselectIndexPath animated:YES notifyDelegate:YES];
            }
        }

        if (shouldSelect) {
            id selectedCell = [self cellForItemAtIndexPath:indexPath];
            [selectedCell setSelected:YES];

            [_indexPathsForSelectedItems addObject:indexPath];

            [selectedCell performSelectionSegue];

            if (scrollPosition != UICollectionViewScrollPositionNone) {
                [self scrollToItemAtIndexPath:indexPath atScrollPosition:scrollPosition animated:animated];
            }

            if (notifyDelegate && _collectionViewFlags.delegateDidSelectItemAtIndexPath) {
                int section = [indexPath section], item = [indexPath item];
                [_collectionViewDelegate collectionView:self didSelectItemAtIndexPath:indexPath];
            }
        }
    }

    return self;
}

- (void)touchesCancelled:(id)touches withEvent:(id)event {
    // do not mark touchingIndexPath as nil because whoever cancelled this touch will need to signal a touch up event
    // later
    if (_touchingIndexPath) {
        // first unhighlight the touch operation
        [self unhighlightItemAtIndexPath:(id)_touchingIndexPath animated:YES notifyDelegate:YES];
    }
}

- (id)indexPathForItemAtPoint:(CGPoint)point {
    id attributes = [[_layout layoutAttributesForElementsInRect:CGRectMake(point.x, point.y, 1, 1)] lastObject];
    return [attributes indexPath];
}

- (BOOL)highlightItemAtIndexPath:(NSIndexPath*)indexPath
                        animated:(BOOL)animated
                  scrollPosition:(UICollectionViewScrollPosition)scrollPosition
                  notifyDelegate:(BOOL)notifyDelegate {
    BOOL shouldHighlight = YES;
    if (notifyDelegate && _collectionViewFlags.delegateShouldHighlightItemAtIndexPath) {
        shouldHighlight = [_collectionViewDelegate collectionView:self shouldHighlightItemAtIndexPath:indexPath];
    }

    if (shouldHighlight) {
        id highlightedCell = [self cellForItemAtIndexPath:indexPath];
        [highlightedCell setHighlighted:YES];
        [_indexPathsForHighlightedItems addObject:indexPath];

        if (scrollPosition != UICollectionViewScrollPositionNone) {
            [self scrollToItemAtIndexPath:indexPath atScrollPosition:scrollPosition animated:animated];
        }

        if (notifyDelegate && _collectionViewFlags.delegateDidHighlightItemAtIndexPath) {
            [_collectionViewDelegate collectionView:self didHighlightItemAtIndexPath:indexPath];
        }
    }
    return shouldHighlight;
}

- (BOOL)unhighlightItemAtIndexPath:(NSIndexPath*)indexPath animated:(BOOL)animated notifyDelegate:(BOOL)notifyDelegate {
    return [self unhighlightItemAtIndexPath:indexPath
                                   animated:animated
                             notifyDelegate:notifyDelegate
                       shouldCheckHighlight:NO];
}

- (BOOL)unhighlightItemAtIndexPath:(NSIndexPath*)indexPath
                          animated:(BOOL)animated
                    notifyDelegate:(BOOL)notifyDelegate
              shouldCheckHighlight:(BOOL)check {
    if ([_indexPathsForHighlightedItems containsObject:indexPath]) {
        id highlightedCell = [self cellForItemAtIndexPath:indexPath];
        // iOS6 does not notify any delegate if the cell was never highlighted (setHighlighted overwritten) during
        // touchMoved
        if (check && ![highlightedCell isHighlighted]) {
            return NO;
        }

        // if multiple selection or not unhighlighting a selected item we don't perform any op
        if ([highlightedCell isHighlighted] && [_indexPathsForSelectedItems containsObject:indexPath]) {
            [highlightedCell setHighlighted:YES];
        } else {
            [highlightedCell setHighlighted:NO];
        }

        [_indexPathsForHighlightedItems removeObject:indexPath];

        if (notifyDelegate && _collectionViewFlags.delegateDidUnhighlightItemAtIndexPath) {
            [_collectionViewDelegate collectionView:self didUnhighlightItemAtIndexPath:indexPath];
        }

        return YES;
    }
    return NO;
}

- (id)deselectItemAtIndexPath:(id)indexPath animated:(BOOL)animated notifyDelegate:(BOOL)notifyDelegate {
    BOOL shouldDeselect = YES;
    // deselect only relevant during multi mode
    if ([self allowsMultipleSelection] && notifyDelegate &&
        _collectionViewFlags.delegateShouldDeselectItemAtIndexPath) {
        shouldDeselect = [_collectionViewDelegate collectionView:self shouldDeselectItemAtIndexPath:indexPath];
    }

    if (shouldDeselect && [_indexPathsForSelectedItems containsObject:indexPath]) {
        id selectedCell = [self cellForItemAtIndexPath:indexPath];
        if (selectedCell) {
            if ([selectedCell isSelected]) {
                [selectedCell setSelected:NO];
            }
        }
        [_indexPathsForSelectedItems removeObject:indexPath];

        if (notifyDelegate && _collectionViewFlags.delegateDidDeselectItemAtIndexPath) {
            [_collectionViewDelegate collectionView:self didDeselectItemAtIndexPath:indexPath];
        }
    }
    return self;
}

- (BOOL)allowsSelection {
    return _collectionViewFlags.allowsSelection;
}

- (BOOL)allowsMultipleSelection {
    return _collectionViewFlags.allowsMultipleSelection;
}

- (id)cellForItemAtIndexPath:(id)indexPath {
    id ret = nil;

    for (UICollectionViewItemKey* itemKey in(id) _allVisibleViewsDict) {
        if ([itemKey type] == UICollectionViewItemTypeCell) {
            if ([[itemKey indexPath] isEqual:indexPath]) {
                ret = [_allVisibleViewsDict objectForKey:itemKey];
                break;
            }
        }
    }

    return ret;
}

- (void)deselectItemAtIndexPath:(id)indexPath animated:(BOOL)animated {
    [self deselectItemAtIndexPath:indexPath animated:animated notifyDelegate:NO];
}

- (void)performBatchUpdates:(void (^)())updates completion:(void (^)(BOOL))completion {
    [self setupCellAnimations];

    if (updates)
        EbrCallBlock(updates, "d", updates);
    if (completion)
        _updateCompletionHandler.attach([completion copy]);

    [self endItemAnimations];
}

- (id)setupCellAnimations {
    [self updateVisibleCellsNow:YES];
    [self suspendReloads];
    _collectionViewFlags.updating = YES;
    return 0;
}

- (id)suspendReloads {
    _reloadingSuspendedCount++;
    return 0;
}

- (id)resumeReloads {
    if (0 < _reloadingSuspendedCount)
        _reloadingSuspendedCount--;
    return self;
}

- (void)reloadSections:(id)sections {
    [self updateSections:sections updateAction:UICollectionUpdateActionReload];
}

- (id)updateSections:(id)sections updateAction:(UICollectionUpdateAction)updateAction {
    BOOL updating = _collectionViewFlags.updating;
    if (!updating)
        [self setupCellAnimations];

    id updateActions = [self arrayForUpdateAction:updateAction];

    NSUInteger idx = [sections firstIndex];
    while (idx != NSNotFound) {
        NSUInteger section = idx;
        id updateItem = [[UICollectionViewUpdateItem alloc]
            initWithAction:updateAction
              forIndexPath:[NSIndexPath indexPathForItem:NSNotFound inSection:section]];
        [updateActions addObject:updateItem];
        idx = [sections indexGreaterThanIndex:idx];
    }

    if (!updating)
        [self endItemAnimations];
    return self;
}

- (id)arrayForUpdateAction:(UICollectionUpdateAction)updateAction {
    id updateActions = nil;

    switch (updateAction) {
        case UICollectionUpdateActionInsert:
            if (!_insertItems)
                _insertItems.attach([NSMutableArray new]);
            updateActions = _insertItems;
            break;
        case UICollectionUpdateActionDelete:
            if (!_deleteItems)
                _deleteItems.attach([NSMutableArray new]);
            updateActions = _deleteItems;
            break;
        case UICollectionUpdateActionMove:
            if (!_moveItems)
                _moveItems.attach([NSMutableArray new]);
            updateActions = _moveItems;
            break;
        case UICollectionUpdateActionReload:
            if (!_reloadItems)
                _reloadItems.attach([NSMutableArray new]);
            updateActions = _reloadItems;
            break;
        default:
            break;
    }
    return updateActions;
}

- (id)currentUpdate {
    return _update;
}

- (id)visibleViewsDict {
    return _allVisibleViewsDict;
}

- (CGRect)visibleBoundRects {
    return [self bounds];
}

- (id)prepareLayoutForUpdates {
    id array = [NSMutableArray array];
    [array addObjectsFromArray:[_originalDeleteItems sortedArrayUsingSelector:@selector(inverseCompareIndexPaths:)]];
    [array addObjectsFromArray:[_originalInsertItems sortedArrayUsingSelector:@selector(compareIndexPaths:)]];
    [array addObjectsFromArray:[_reloadItems sortedArrayUsingSelector:@selector(compareIndexPaths:)]];
    [array addObjectsFromArray:[_moveItems sortedArrayUsingSelector:@selector(compareIndexPaths:)]];
    [_layout prepareForCollectionViewUpdates:array];
    return self;
}

- (id)updateWithItems:(id)items {
    [self prepareLayoutForUpdates];

    id animations = [NSMutableArray array];
    id newAllVisibleView = [NSMutableDictionary dictionary];

    id viewsToRemove = [NSMutableDictionary dictionary];
    [viewsToRemove setObject:[NSMutableArray array] forKey:[NSNumber numberWithInt:UICollectionViewItemTypeCell]];
    [viewsToRemove setObject:[NSMutableArray array]
                      forKey:[NSNumber numberWithInt:UICollectionViewItemTypeDecorationView]];
    [viewsToRemove setObject:[NSMutableArray array]
                      forKey:[NSNumber numberWithInt:UICollectionViewItemTypeSupplementaryView]];

    for (UICollectionViewUpdateItem* updateItem in items) {
        if ([updateItem isSectionOperation] && [updateItem updateAction] != UICollectionUpdateActionDelete)
            continue;
        if ([updateItem isSectionOperation] && [updateItem updateAction] == UICollectionUpdateActionDelete) {
            NSInteger numberOfBeforeSection = [[_update objectForKey:@"oldModel"]
                numberOfItemsInSection:[[updateItem indexPathBeforeUpdate] section]];
            for (NSInteger i = 0; i < numberOfBeforeSection; i++) {
                id indexPath = [NSIndexPath indexPathForItem:i inSection:[[updateItem indexPathBeforeUpdate] section]];

                id finalAttrs = [_layout finalLayoutAttributesForDisappearingItemAtIndexPath:indexPath];
                UICollectionViewItemKey* key =
                    [UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:indexPath];
                id view = [_allVisibleViewsDict objectForKey:key];
                if (view) {
                    id startAttrs = [view layoutAttributes];

                    if (!finalAttrs) {
                        finalAttrs = [startAttrs copy];
                        [finalAttrs setAlpha:0];
                    }
                    id dict = [NSMutableDictionary dictionary];
                    [dict setObject:view forKey:@"view"];
                    [dict setObject:startAttrs forKey:@"previousLayoutInfos"];
                    [dict setObject:finalAttrs forKey:@"newLayoutInfos"];
                    [animations addObject:dict];

                    [_allVisibleViewsDict removeObjectForKey:key];

                    [[viewsToRemove objectForKey:[NSNumber numberWithInt:[key type]]] addObject:view];
                }
            }
            continue;
        }

        if ([updateItem updateAction] == UICollectionUpdateActionDelete) {
            id indexPath = [updateItem indexPathBeforeUpdate];

            id finalAttrs = [_layout finalLayoutAttributesForDisappearingItemAtIndexPath:indexPath];
            UICollectionViewItemKey* key = [UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:indexPath];
            id view = [_allVisibleViewsDict objectForKey:key];
            if (view) {
                id startAttrs = [view layoutAttributes];

                if (!finalAttrs) {
                    finalAttrs = [startAttrs copy];
                    [finalAttrs setAlpha:0];
                }
                id dict = [NSMutableDictionary dictionary];
                [dict setObject:view forKey:@"view"];
                [dict setObject:startAttrs forKey:@"previousLayoutInfos"];
                [dict setObject:finalAttrs forKey:@"newLayoutInfos"];
                [animations addObject:dict];

                [_allVisibleViewsDict removeObjectForKey:key];

                [[viewsToRemove objectForKey:[NSNumber numberWithInt:[key type]]] addObject:view];
            }
        } else if ([updateItem updateAction] == UICollectionUpdateActionInsert) {
            id indexPath = [updateItem indexPathAfterUpdate];
            id key = [UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:indexPath];
            id startAttrs = [_layout initialLayoutAttributesForAppearingItemAtIndexPath:indexPath];
            id finalAttrs = [_layout layoutAttributesForItemAtIndexPath:indexPath];

            CGRect startRect = [startAttrs frame];
            CGRect finalRect = [finalAttrs frame];

            if (CGRectIntersectsRect([self visibleBoundRects], startRect) ||
                CGRectIntersectsRect([self visibleBoundRects], finalRect)) {
                if (!startAttrs) {
                    startAttrs = [finalAttrs copy];
                    [startAttrs setAlpha:0];
                }

                id view = [self createPreparedCellForItemAtIndexPath:indexPath withLayoutAttributes:startAttrs];
                [self addControlledSubview:view];

                [newAllVisibleView setObject:view forKey:key];
                id dict = [NSMutableDictionary dictionary];
                [dict setObject:view forKey:@"view"];
                [dict setObject:startAttrs forKey:@"previousLayoutInfos"];
                [dict setObject:finalAttrs forKey:@"newLayoutInfos"];
                [animations addObject:dict];
            }
        } else if ([updateItem updateAction] == UICollectionUpdateActionMove) {
            id indexPathBefore = [updateItem indexPathBeforeUpdate];
            id indexPathAfter = [updateItem indexPathAfterUpdate];

            id keyBefore = [UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:indexPathBefore];
            id keyAfter = [UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:indexPathAfter];
            id view = [_allVisibleViewsDict objectForKey:keyBefore];

            id startAttrs = nil;
            id finalAttrs = [_layout layoutAttributesForItemAtIndexPath:indexPathAfter];

            if (view) {
                startAttrs = [view layoutAttributes];
                [_allVisibleViewsDict removeObjectForKey:keyBefore];
                [newAllVisibleView setObject:view forKey:keyAfter];
            } else {
                startAttrs = [finalAttrs copy];
                [startAttrs setAlpha:0];
                view = [self createPreparedCellForItemAtIndexPath:indexPathAfter withLayoutAttributes:startAttrs];
                [self addControlledSubview:view];
                [newAllVisibleView setObject:view forKey:keyAfter];
            }

            id dict = [NSMutableDictionary dictionary];
            [dict setObject:view forKey:@"view"];
            [dict setObject:startAttrs forKey:@"previousLayoutInfos"];
            [dict setObject:finalAttrs forKey:@"newLayoutInfos"];
            [animations addObject:dict];
        }
    }

    for (UICollectionViewItemKey* key in [_allVisibleViewsDict keyEnumerator]) {
        UICollectionViewItemKey* view = [_allVisibleViewsDict objectForKey:key];

        if ([key type] == UICollectionViewItemTypeCell) {
            NSUInteger oldGlobalIndex =
                [[_update objectForKey:@"oldModel"] globalIndexForItemAtIndexPath:[key indexPath]];
            id oldToNewIndexMap = [_update objectForKey:@"oldToNewIndexMap"];
            NSUInteger newGlobalIndex = NSNotFound;
            if (NSNotFound != oldGlobalIndex && oldGlobalIndex < [oldToNewIndexMap count]) {
                newGlobalIndex = [[oldToNewIndexMap objectAtIndex:oldGlobalIndex] intValue];
            }
            id newIndexPath = newGlobalIndex == NSNotFound ? nil : [[_update objectForKey:@"newModel"]
                                                                       indexPathForItemAtGlobalIndex:newGlobalIndex];
            id oldIndexPath = oldGlobalIndex == NSNotFound ? nil : [[_update objectForKey:@"oldModel"]
                                                                       indexPathForItemAtGlobalIndex:oldGlobalIndex];

            if (newIndexPath) {
                id startAttrs = nil;
                id finalAttrs = nil;

                startAttrs = [_layout initialLayoutAttributesForAppearingItemAtIndexPath:oldIndexPath];
                finalAttrs = [_layout layoutAttributesForItemAtIndexPath:newIndexPath];

                id dic = [NSMutableDictionary dictionary];

                [dic setObject:view forKey:@"view"];
                if (startAttrs)
                    [dic setObject:startAttrs forKey:@"previousLayoutInfos"];
                if (finalAttrs)
                    [dic setObject:finalAttrs forKey:@"newLayoutInfos"];

                [animations addObject:dic];
                id newKey = [key copy];
                [newKey setIndexPath:newIndexPath];
                [newAllVisibleView setObject:view forKey:newKey];
            }
        } else if ([key type] == UICollectionViewItemTypeSupplementaryView) {
            id startAttrs = nil;
            id finalAttrs = nil;

            startAttrs = [view layoutAttributes];
            finalAttrs =
                [_layout layoutAttributesForSupplementaryViewOfKind:[[view layoutAttributes] representedElementKind]
                                                        atIndexPath:[key indexPath]];

            id dic = [NSMutableDictionary dictionary];

            [dic setObject:view forKey:@"view"];
            if (startAttrs)
                [dic setObject:startAttrs forKey:@"previousLayoutInfos"];
            if (finalAttrs)
                [dic setObject:finalAttrs forKey:@"newLayoutInfos"];

            [animations addObject:dic];
            id newKey = [key copy];
            [newAllVisibleView setObject:view forKey:newKey];
            [view _setNeedsRefresh:1];
        } else if ([key type] == UICollectionViewItemTypeDecorationView) {
            id startAttrs = nil;
            id finalAttrs = nil;

            startAttrs = [view layoutAttributes];
            finalAttrs =
                [_layout layoutAttributesForDecorationViewOfKind:[[view layoutAttributes] representedElementKind]
                                                     atIndexPath:[key indexPath]];

            id dic = [NSMutableDictionary dictionary];

            [dic setObject:view forKey:@"view"];
            if (startAttrs)
                [dic setObject:startAttrs forKey:@"previousLayoutInfos"];
            if (finalAttrs)
                [dic setObject:finalAttrs forKey:@"newLayoutInfos"];

            [animations addObject:dic];
            id newKey = [key copy];
            [newAllVisibleView setObject:view forKey:newKey];
            [view _setNeedsRefresh:1];
        } else {
            assert(0);
        }
    }

    id allNewlyVisibleItems = [_layout layoutAttributesForElementsInRect:[self visibleBoundRects]];
    for (id attrs in allNewlyVisibleItems) {
        UICollectionViewItemKey* key = [UICollectionViewItemKey collectionItemKeyForLayoutAttributes:attrs];

        if ([key type] == UICollectionViewItemTypeCell && ![[newAllVisibleView allKeys] containsObject:key]) {
            id startAttrs = [_layout initialLayoutAttributesForAppearingItemAtIndexPath:[attrs indexPath]];

            id view = [self createPreparedCellForItemAtIndexPath:[attrs indexPath]
                                            withLayoutAttributes:startAttrs ? startAttrs : attrs];
            [self addControlledSubview:view];
            [newAllVisibleView setObject:view forKey:key];

            id dict = [NSMutableDictionary dictionary];
            [dict setObject:view forKey:@"view"];
            [dict setObject:startAttrs ? startAttrs : attrs forKey:@"previousLayoutInfos"];
            [dict setObject:attrs forKey:@"newLayoutInfos"];
            [animations addObject:dict];
        }
    }

    _allVisibleViewsDict = newAllVisibleView;

    for (id animation in animations) {
        id view = [animation objectForKey:@"view"];
        id attr = [animation objectForKey:@"previousLayoutInfos"];
        [view applyLayoutAttributes:attr];
    }

    [CATransaction begin];
    [CATransaction setAnimationDuration:0];
    [CATransaction setCompletionBlock:^{
        // Iterate through all the views that we are going to remove.
        [viewsToRemove enumerateKeysAndObjectsUsingBlock:^(NSNumber* keyObj, NSArray* views, BOOL* stop) {
            UICollectionViewItemType type = [keyObj unsignedIntegerValue];
            for (UICollectionReusableView* view in views) {
                if (type == UICollectionViewItemTypeCell) {
                    [self reuseCell:(UICollectionViewCell*)view];
                } else if (type == UICollectionViewItemTypeSupplementaryView) {
                    [self reuseSupplementaryView:view];
                } else if (type == UICollectionViewItemTypeDecorationView) {
                    [self reuseDecorationView:view];
                }
            }
        }];

        _collectionViewFlags.updatingLayout = NO;

        // In here I think when the block is called, the flag is YES. So the _updateCopletionHandler's paramer is YES.
        if (_updateCompletionHandler) {
            EbrCallBlock(_updateCompletionHandler, "dd", (id)_updateCompletionHandler, finished);
            _updateCompletionHandler = nil;
        }
    }];

    for (NSDictionary* animation in animations) {
        UICollectionReusableView* view = animation[@"view"];
        UICollectionViewLayoutAttributes* attrs = animation[@"newLayoutInfos"];
        [view applyLayoutAttributes:attrs];
    }
    [CATransaction commit];

    [_layout finalizeCollectionViewUpdates];

    return self;
}

- (id)_doUpdateCompletion:(BOOL)finished:(id)viewsToRemove {
    for (id keyObj in viewsToRemove) {
        id views = [viewsToRemove objectForKey:keyObj];
        UICollectionViewItemType type = [keyObj unsignedIntegerValue];
        for (id view in views) {
            if (type == UICollectionViewItemTypeCell) {
                [self reuseCell:view];
            } else if (type == UICollectionViewItemTypeSupplementaryView) {
                [self reuseSupplementaryView:view];
            } else if (type == UICollectionViewItemTypeDecorationView) {
                [self reuseDecorationView:view];
            }
        }
    }

    _collectionViewFlags.updatingLayout = NO;
    if (_updateCompletionHandler) {
        EbrCallBlock(_updateCompletionHandler, "dd", (id)_updateCompletionHandler, finished);
        _updateCompletionHandler = nil;
    }
    return self;
}

- (id)_doUpdateAnimations:(id)animations {
    _collectionViewFlags.updatingLayout = YES;

    for (id animation in animations) {
        id view = [animation objectForKey:@"view"];
        id attrs = [animation objectForKey:@"newLayoutInfos"];
        [view applyLayoutAttributes:attrs];
    }
    return self;
}

- (id)endItemAnimations {
    _updateCount++;
    id oldCollectionViewData = [_collectionViewData retain];
    _collectionViewData = [[UICollectionViewData alloc] initWithCollectionView:self layout:(id)_layout];

    [_layout invalidateLayout];
    [_collectionViewData prepareToLoadData];

    id someMutableArr1 = [[NSMutableArray alloc] init];

    id removeUpdateItems = [[self arrayForUpdateAction:UICollectionUpdateActionDelete]
        sortedArrayUsingSelector:@selector(inverseCompareIndexPaths:)];

    id insertUpdateItems = [[self arrayForUpdateAction:UICollectionUpdateActionInsert]
        sortedArrayUsingSelector:@selector(compareIndexPaths:)];

    id sortedMutableReloadItems = [[_reloadItems sortedArrayUsingSelector:@selector(compareIndexPaths:)] mutableCopy];
    id sortedMutableMoveItems = [[_moveItems sortedArrayUsingSelector:@selector(compareIndexPaths:)] mutableCopy];

    _originalDeleteItems = [removeUpdateItems copy];
    _originalInsertItems = [insertUpdateItems copy];

    id someMutableArr2 = [NSMutableArray new];
    id someMutableArr3 = [NSMutableArray new];
    id operations = [NSMutableDictionary new];

    for (id updateItem in sortedMutableReloadItems) {
        assert([[updateItem indexPathBeforeUpdate] section] < [oldCollectionViewData numberOfSections]);

        if ([[updateItem indexPathBeforeUpdate] item] != NSNotFound) {
            assert([[updateItem indexPathBeforeUpdate] item] <
                   [oldCollectionViewData numberOfItemsInSection:[[updateItem indexPathBeforeUpdate] section]]);
        }

        [someMutableArr2
            addObject:[[UICollectionViewUpdateItem alloc] initWithAction:UICollectionUpdateActionDelete
                                                            forIndexPath:[updateItem indexPathBeforeUpdate]]];
        [someMutableArr3
            addObject:[[UICollectionViewUpdateItem alloc] initWithAction:UICollectionUpdateActionInsert
                                                            forIndexPath:[updateItem indexPathAfterUpdate]]];
    }

    id sortedDeletedMutableItems =
        [[_deleteItems sortedArrayUsingSelector:@selector(inverseCompareIndexPaths:)] mutableCopy];
    id sortedInsertMutableItems = [[_insertItems sortedArrayUsingSelector:@selector(compareIndexPaths:)] mutableCopy];

    for (id deleteItem in sortedDeletedMutableItems) {
        if ([deleteItem isSectionOperation]) {
            assert([[deleteItem indexPathBeforeUpdate] section] < [oldCollectionViewData numberOfSections]);

            for (id moveItem in sortedMutableMoveItems) {
                if ([[moveItem indexPathBeforeUpdate] section] == [[deleteItem indexPathBeforeUpdate] section]) {
                    if ([moveItem isSectionOperation])
                        assert(0);
                    else
                        assert(0);
                }
            }
        } else {
            assert([[deleteItem indexPathBeforeUpdate] section] < [oldCollectionViewData numberOfSections]);
            assert([[deleteItem indexPathBeforeUpdate] item] <
                   [oldCollectionViewData numberOfItemsInSection:[[deleteItem indexPathBeforeUpdate] section]]);

            id dict = nil;
            if (!(dict = [operations
                      objectForKey:[NSNumber numberWithInt:[[deleteItem indexPathBeforeUpdate] section]]])) {
                dict = [NSMutableDictionary dictionary];
                [operations setObject:dict
                               forKey:[NSNumber numberWithInt:[[deleteItem indexPathBeforeUpdate] section]]];
            }

            [dict setObject:[NSNumber numberWithInt:[[dict objectForKey:@"deleted"] intValue] + 1] forKey:@"deleted"];
        }
    }

    for (NSUInteger i = 0; i < [sortedInsertMutableItems count]; i++) {
        id insertItem = [sortedInsertMutableItems objectAtIndex:i];
        id indexPath = [insertItem indexPathAfterUpdate];

        BOOL sectionOperation = [insertItem isSectionOperation];
        if (sectionOperation) {
            assert([indexPath section] < [_collectionViewData numberOfSections]);

            for (id moveItem in sortedMutableMoveItems) {
                if ([[moveItem indexPathAfterUpdate] isEqual:indexPath]) {
                    if ([moveItem isSectionOperation])
                        assert(0); // NO, @"attempt to perform an insert and a move to the same section (%ld)",
                                   // (long)indexPath.section);
                }
            }

            NSUInteger j = i + 1;
            while (j < [sortedInsertMutableItems count]) {
                id nextInsertItem = [sortedInsertMutableItems objectAtIndex:j];

                if ([[nextInsertItem indexPathAfterUpdate] section] == [indexPath section]) {
                    assert([[nextInsertItem indexPathAfterUpdate] item] <
                           [_collectionViewData numberOfItemsInSection:[indexPath section]]);
                    /*
                    @"attempt to insert item %ld into section %ld, but there are only %ld items in section %ld after the
                    update",
                    (long)nextInsertItem.indexPathAfterUpdate.item,
                    (long)indexPath.section,
                    (long)[_collectionViewData numberOfItemsInSection:indexPath.section],
                    (long)indexPath.section);
                    */
                    [sortedInsertMutableItems removeObjectAtIndex:j];
                } else
                    break;
            }
        } else {
            assert([indexPath item] < [_collectionViewData numberOfItemsInSection:[indexPath section]]);
            /*
            @"attempt to insert item to (%@) but there are only %ld items in section %ld after update",
            indexPath,
            (long)[_collectionViewData numberOfItemsInSection:indexPath.section],
            (long)indexPath.section);
            */

            id dict;
            if (!(dict = [operations objectForKey:[NSNumber numberWithInt:[indexPath section]]])) {
                dict = [NSMutableDictionary dictionary];
                [operations setObject:dict forKey:[NSNumber numberWithInt:[indexPath section]]];
            }

            [dict setObject:[NSNumber numberWithInt:[[dict objectForKey:@"inserted"] intValue] + 1] forKey:@"inserted"];
        }
    }

    for (id sortedItem in sortedMutableMoveItems) {
        if ([sortedItem isSectionOperation]) {
            assert([[sortedItem indexPathBeforeUpdate] section] < [oldCollectionViewData numberOfSections]);
            /*
            @"attempt to move section (%ld) that doesn't exist (%ld sections before update)",
            (long)sortedItem.indexPathBeforeUpdate.section,
            (long)[oldCollectionViewData numberOfSections]);
            */
            assert([[sortedItem indexPathAfterUpdate] section] < [_collectionViewData numberOfSections]);
            /*
            @"attempt to move section to %ld but there are only %ld sections after update",
            (long)sortedItem.indexPathAfterUpdate.section,
            (long)[_collectionViewData numberOfSections]);
            */
        } else {
            assert([[sortedItem indexPathBeforeUpdate] section] < [oldCollectionViewData numberOfSections]);
            /*
            @"attempt to move item (%@) that doesn't exist (%ld sections before update)",
            sortedItem, (long)[oldCollectionViewData numberOfSections]);
            */
            assert([[sortedItem indexPathBeforeUpdate] item] <
                   [oldCollectionViewData numberOfItemsInSection:[[sortedItem indexPathBeforeUpdate] section]]);
            /*
            @"attempt to move item (%@) that doesn't exist (%ld items in section %ld before update)",
            sortedItem,
            (long)[oldCollectionViewData numberOfItemsInSection:sortedItem.indexPathBeforeUpdate.section],
            (long)sortedItem.indexPathBeforeUpdate.section);
            */
            assert([[sortedItem indexPathAfterUpdate] section] < [_collectionViewData numberOfSections]);
            /*
            @"attempt to move item to (%@) but there are only %ld sections after update",
            sortedItem.indexPathAfterUpdate,
            (long)[_collectionViewData numberOfSections]);
            */
            assert([[sortedItem indexPathAfterUpdate] item] <
                   [_collectionViewData numberOfItemsInSection:[[sortedItem indexPathAfterUpdate] section]]);
            /*
            @"attempt to move item to (%@) but there are only %ld items in section %ld after update",
            sortedItem,
            (long)[_collectionViewData numberOfItemsInSection:sortedItem.indexPathAfterUpdate.section],
            (long)sortedItem.indexPathAfterUpdate.section);
            */
        }

        id dict1 = nil, dict2 = nil;
        if (!(dict1 =
                  [operations objectForKey:[NSNumber numberWithInt:[[sortedItem indexPathBeforeUpdate] section]]])) {
            dict1 = [NSMutableDictionary dictionary];
            [operations setObject:dict1 forKey:[NSNumber numberWithInt:[[sortedItem indexPathBeforeUpdate] section]]];
        }
        if (!(dict2 = [operations objectForKey:[NSNumber numberWithInt:[[sortedItem indexPathAfterUpdate] section]]])) {
            dict2 = [NSMutableDictionary dictionary];
            [operations setObject:dict2 forKey:[NSNumber numberWithInt:[[sortedItem indexPathAfterUpdate] section]]];
        }

        [dict1 setObject:[NSNumber numberWithInt:[[dict1 objectForKey:@"movedOut"] intValue] + 1] forKey:@"movedOut"];
        [dict2 setObject:[NSNumber numberWithInt:[[dict2 objectForKey:@"movedIn"] intValue] + 1] forKey:@"movedIn"];
    }

    /*
    #if !defined  NS_BLOCK_ASSERTIONS
    for (NSNumber *sectionKey in [operations keyEnumerator]) {
    NSInteger section = [sectionKey intValue];

    NSInteger insertedCount = [operations[sectionKey][@"inserted"] intValue];
    NSInteger deletedCount = [operations[sectionKey][@"deleted"] intValue];
    NSInteger movedInCount = [operations[sectionKey][@"movedIn"] intValue];
    NSInteger movedOutCount = [operations[sectionKey][@"movedOut"] intValue];

    NSAssert([oldCollectionViewData numberOfItemsInSection:section] + insertedCount - deletedCount + movedInCount -
    movedOutCount ==
    [_collectionViewData numberOfItemsInSection:section],
    @"invalid update in section %ld: number of items after update (%ld) should be equal to the number of items before
    update (%ld) "\
    "plus count of inserted items (%ld), minus count of deleted items (%ld), plus count of items moved in (%ld), minus
    count of items moved out (%ld)",
    (long)section,
    (long)[_collectionViewData numberOfItemsInSection:section],
    (long)[oldCollectionViewData numberOfItemsInSection:section],
    (long)insertedCount, (long)deletedCount, (long)movedInCount, (long)movedOutCount);
    }
    #endif
    */

    [someMutableArr2 addObjectsFromArray:sortedDeletedMutableItems];
    [someMutableArr3 addObjectsFromArray:sortedInsertMutableItems];
    [someMutableArr1
        addObjectsFromArray:[someMutableArr2 sortedArrayUsingSelector:@selector(inverseCompareIndexPaths:)]];
    [someMutableArr1 addObjectsFromArray:sortedMutableMoveItems];
    [someMutableArr1 addObjectsFromArray:[someMutableArr3 sortedArrayUsingSelector:@selector(compareIndexPaths:)]];

    id layoutUpdateItems = [NSMutableArray array];

    [layoutUpdateItems addObjectsFromArray:sortedDeletedMutableItems];
    [layoutUpdateItems addObjectsFromArray:sortedMutableMoveItems];
    [layoutUpdateItems addObjectsFromArray:sortedInsertMutableItems];

    id newModel = [NSMutableArray array];
    for (unsigned i = 0; i < [oldCollectionViewData numberOfSections]; i++) {
        id sectionArr = [NSMutableArray array];
        for (unsigned j = 0; j < [oldCollectionViewData numberOfItemsInSection:i]; j++)
            [sectionArr
                addObject:[NSNumber numberWithInt:[oldCollectionViewData
                                                      globalIndexForItemAtIndexPath:[NSIndexPath indexPathForItem:j
                                                                                                        inSection:i]]]];
        [newModel addObject:sectionArr];
    }

    for (id updateItem in layoutUpdateItems) {
        switch ([updateItem updateAction]) {
            case UICollectionUpdateActionDelete: {
                if ([updateItem isSectionOperation]) {
                    // section updates are ignored anyway in animation code. If not commented, mixing rows and section
                    // deletion causes crash in else below
                    // [newModel removeObjectAtIndex:updateItem.indexPathBeforeUpdate.section];
                } else {
                    [[newModel objectAtIndex:[[updateItem indexPathBeforeUpdate] section]]
                        removeObjectAtIndex:[[updateItem indexPathBeforeUpdate] item]];
                }
            } break;
            case UICollectionUpdateActionInsert: {
                if ([updateItem isSectionOperation]) {
                    [newModel insertObject:[NSMutableArray array] atIndex:[[updateItem indexPathAfterUpdate] section]];
                } else {
                    [[newModel objectAtIndex:[[updateItem indexPathAfterUpdate] section]]
                        insertObject:[NSNumber numberWithInt:NSNotFound]
                             atIndex:[[updateItem indexPathAfterUpdate] item]];
                }
            } break;

            case UICollectionUpdateActionMove: {
                if ([updateItem isSectionOperation]) {
                    id section = [newModel objectAtIndex:[[updateItem indexPathBeforeUpdate] section]];
                    [newModel insertObject:section atIndex:[[updateItem indexPathAfterUpdate] section]];
                } else {
                    id object =
                        [NSNumber numberWithInt:[oldCollectionViewData
                                                    globalIndexForItemAtIndexPath:[updateItem indexPathBeforeUpdate]]];
                    [[newModel objectAtIndex:[[updateItem indexPathBeforeUpdate] section]] removeObject:object];
                    [[newModel objectAtIndex:[[updateItem indexPathAfterUpdate] section]]
                        insertObject:object
                             atIndex:[[updateItem indexPathAfterUpdate] item]];
                }
            } break;
            default:
                break;
        }
    }

    id oldToNewMap = [NSMutableArray arrayWithCapacity:[oldCollectionViewData numberOfItems]];
    id newToOldMap = [NSMutableArray arrayWithCapacity:[_collectionViewData numberOfItems]];

    for (unsigned i = 0; i < [oldCollectionViewData numberOfItems]; i++)
        [oldToNewMap addObject:[NSNumber numberWithInt:NSNotFound]];

    for (unsigned i = 0; i < [_collectionViewData numberOfItems]; i++)
        [newToOldMap addObject:[NSNumber numberWithInt:NSNotFound]];

    for (NSUInteger i = 0; i < [newModel count]; i++) {
        id section = [newModel objectAtIndex:i];
        for (NSUInteger j = 0; j < [section count]; j++) {
            NSInteger newGlobalIndex =
                [_collectionViewData globalIndexForItemAtIndexPath:[NSIndexPath indexPathForItem:j inSection:i]];
            if ([[section objectAtIndex:j] integerValue] != NSNotFound)
                [oldToNewMap setObject:[NSNumber numberWithInt:newGlobalIndex]
                    atIndexedSubscript:[[section objectAtIndex:j] intValue]];
            if (newGlobalIndex != NSNotFound)
                [newToOldMap setObject:[section objectAtIndex:j] atIndexedSubscript:newGlobalIndex];
        }
    }

    _update.attach([[NSMutableDictionary alloc] initWithCapacity:3]);
    [_update setObject:(id)oldCollectionViewData forKey:@"oldModel"];
    [_update setObject:(id)_collectionViewData forKey:@"newModel"];
    [_update setObject:oldToNewMap forKey:@"oldToNewIndexMap"];
    [_update setObject:newToOldMap forKey:@"newToOldIndexMap"];

    [self updateWithItems:someMutableArr1];

    [oldCollectionViewData release];
    _originalInsertItems = nil;
    _originalDeleteItems = nil;
    _insertItems = nil;
    _deleteItems = nil;
    _moveItems = nil;
    _reloadItems = nil;
    _update = nil;
    _updateCount--;
    _collectionViewFlags.updating = NO;
    [self resumeReloads];
    return self;
}

@end
