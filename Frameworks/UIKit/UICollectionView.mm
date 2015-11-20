//******************************************************************************
//
// UICollectionView.m
// PSPDFKit
//
// Copyright (c) 2012-2013 Peter Steinberger. All rights reserved.
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import <Foundation/Foundation.h>

#import <UIKit/UICollectionView.h>
#import <UIKit/UICollectionViewLayout.h>
#import "UICollectionViewData.h"
#import "UICollectionViewLayout+Internals.h"
#import "UICollectionViewItemKey.h"
#import "UICollectionViewUpdateItem.h"

static CGFloat UIAnimationDragCoefficient = 1.f;
static CGFloat UISimulatorAnimationDragCoefficient(void) {
    return UIAnimationDragCoefficient;
}

@interface UICollectionViewLayout (Internal)
@property (nonatomic, unsafe_unretained) UICollectionView* collectionView;
@end

@interface UICollectionViewData (Internal)
- (void)prepareToLoadData;
@end

@interface UICollectionViewCell (Internal)
- (void)performSelectionSegue;
@end

@interface UICollectionViewUpdateItem ()
- (NSIndexPath*)indexPath;

- (BOOL)isSectionOperation;
@end

@interface UICollectionViewLayoutAttributes ()
@property (nonatomic, copy) NSString* elementKind;
@end

CGFloat UISimulatorAnimationDragCoefficient(void);

@interface UICollectionView ()
@property (nonatomic, strong) UICollectionViewData* collectionViewData;
@property (nonatomic, readonly) id currentUpdate;
@property (nonatomic, readonly) NSDictionary* visibleViewsDict;
@property (nonatomic, assign) CGRect visibleBoundRects;
@property (nonatomic, unsafe_unretained) id<UICollectionViewDelegate> collectionViewDelegate;
@property (nonatomic, strong) UICollectionViewLayout* nibLayout;
@property (nonatomic, strong) NSDictionary* nibCellsExternalObjects;
@property (nonatomic, strong) NSDictionary* supplementaryViewsExternalObjects;
@property (nonatomic, strong) NSIndexPath* touchingIndexPath;
@property (nonatomic, strong) NSIndexPath* currentIndexPath;
@end

static char kUIColletionViewExt;

@implementation UICollectionView {
    UICollectionViewLayout* _layout;
    __unsafe_unretained id<UICollectionViewDataSource> _dataSource;
    UIView* _backgroundView;
    NSMutableSet* _indexPathsForSelectedItems;
    NSMutableDictionary* _cellReuseQueues;
    NSMutableDictionary* _supplementaryViewReuseQueues;
    NSMutableDictionary* _decorationViewReuseQueues;
    NSMutableSet* _indexPathsForHighlightedItems;
    int _reloadingSuspendedCount;
    UICollectionReusableView* _firstResponderView;
    UIView* _newContentView;
    int _firstResponderViewType;
    NSString* _firstResponderViewKind;
    NSIndexPath* _firstResponderIndexPath;
    NSMutableDictionary* _allVisibleViewsDict;
    NSIndexPath* _pendingSelectionIndexPath;
    NSMutableSet* _pendingDeselectionIndexPaths;
    UICollectionViewData* _collectionViewData;
    id _update;
    CGRect _visibleBoundRects;
    CGRect _preRotationBounds;
    CGPoint _rotationBoundsOffset;
    int _rotationAnimationCount;
    int _updateCount;
    NSMutableArray* _insertItems;
    NSMutableArray* _deleteItems;
    NSMutableArray* _reloadItems;
    NSMutableArray* _moveItems;
    NSArray* _originalInsertItems;
    NSArray* _originalDeleteItems;
    UITouch* _currentTouch;

    void (^_updateCompletionHandler)(BOOL finished);

    NSMutableDictionary* _cellClassDict;
    NSMutableDictionary* _cellNibDict;
    NSMutableDictionary* _supplementaryViewClassDict;
    NSMutableDictionary* _supplementaryViewNibDict;
    NSMutableDictionary* _cellNibExternalObjectsTables;
    NSMutableDictionary* _supplementaryViewNibExternalObjectsTables;
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
    CGPoint _lastLayoutOffset;
}

@synthesize collectionViewLayout = _layout;
@synthesize currentUpdate = _update;
@synthesize visibleViewsDict = _allVisibleViewsDict;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - NSObject

/**
   @Public No
*/
- (void)_commonSetup {
    _collectionViewFlags.allowsSelection = YES;
    _indexPathsForSelectedItems = [NSMutableSet new];
    _indexPathsForHighlightedItems = [NSMutableSet new];
    _cellReuseQueues = [NSMutableDictionary new];
    _supplementaryViewReuseQueues = [NSMutableDictionary new];
    _decorationViewReuseQueues = [NSMutableDictionary new];
    _allVisibleViewsDict = [NSMutableDictionary new];
    _cellClassDict = [NSMutableDictionary new];
    _cellNibDict = [NSMutableDictionary new];
    _supplementaryViewClassDict = [NSMutableDictionary new];
    _supplementaryViewNibDict = [NSMutableDictionary new];
}

/**
   @Status Interoperable
*/
- (id)initWithFrame:(CGRect)frame {
    return [self initWithFrame:frame collectionViewLayout:nil];
}

/**
   @Status Interoperable
*/
- (id)initWithFrame:(CGRect)frame collectionViewLayout:(UICollectionViewLayout*)layout {
    if ((self = [super initWithFrame:frame])) {
        // Set self as the UIScrollView's delegate
        [super setDelegate:self];

        [self _commonSetup];
        self.collectionViewLayout = layout;
        _collectionViewData = [[UICollectionViewData alloc] initWithCollectionView:self layout:layout];
    }
    return self;
}

/**
   @Status Interoperable
*/
- (id)initWithCoder:(NSCoder*)inCoder {
    if ((self = [super initWithCoder:inCoder])) {
        // Set self as the UIScrollView's delegate
        [super setDelegate:self];

        [self _commonSetup];

        self.nibLayout = [inCoder decodeObjectForKey:@"UICollectionLayout"];

        NSDictionary* cellExternalObjects = [inCoder decodeObjectForKey:@"UICollectionViewCellPrototypeNibExternalObjects"];
        NSDictionary* cellNibs = [inCoder decodeObjectForKey:@"UICollectionViewCellNibDict"];

        for (NSString* identifier in cellNibs.allKeys) {
            _cellNibDict[identifier] = cellNibs[identifier];
        }

        self.nibCellsExternalObjects = cellExternalObjects;

        NSDictionary* supplementaryViewExternalObjects =
            [inCoder decodeObjectForKey:@"UICollectionViewSupplementaryViewPrototypeNibExternalObjects"];
        NSDictionary* supplementaryViewNibs = [inCoder decodeObjectForKey:@"UICollectionViewSupplementaryViewNibDict"];

        for (NSString* identifier in supplementaryViewNibs.allKeys) {
            _supplementaryViewNibDict[identifier] = supplementaryViewNibs[identifier];
        }

        self.supplementaryViewsExternalObjects = supplementaryViewExternalObjects;
    }
    return self;
}

/**
   @Status Interoperable
*/
- (void)awakeFromNib {
    [super awakeFromNib];

    UICollectionViewLayout* nibLayout = self.nibLayout;
    if (nibLayout) {
        self.collectionViewLayout = nibLayout;
        self.nibLayout = nil;
    }
}

/**
   @Status Interoperable
*/
- (NSString*)description {
    return [NSString stringWithFormat:@"%@ collection view layout: %@", [super description], self.collectionViewLayout];
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - UIView

/**
   @Status Interoperable
*/
- (void)layoutSubviews {
    [super layoutSubviews];

    // Adding alpha animation to make the relayouting smooth
    if (_collectionViewFlags.fadeCellsForBoundsChange) {
// TODO: need kCATransitionFade
#if 0
        CATransition *transition = [CATransition animation];
        transition.duration = 0.25f * UISimulatorAnimationDragCoefficient();
        transition.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
        transition.type = kCATransitionFade;
        [self.layer addAnimation:transition forKey:@"rotationAnimation"];
#endif
        NSLog(@"fadeCellsForBoundsChange not supported");
    }

    [_collectionViewData validateLayoutInRect:self.bounds];

    // update cells
    if (_collectionViewFlags.fadeCellsForBoundsChange) {
        [CATransaction begin];
        [CATransaction setDisableActions:YES];
    }

    if (!_collectionViewFlags.updatingLayout)
        [self updateVisibleCellsNow:YES];

    if (_collectionViewFlags.fadeCellsForBoundsChange) {
        [CATransaction commit];
    }

    // do we need to update contentSize?
    CGSize contentSize = [_collectionViewData collectionViewContentRect].size;
    if (!CGSizeEqualToSize(self.contentSize, contentSize)) {
        self.contentSize = contentSize;

        // if contentSize is different, we need to re-evaluate layout, bounds (contentOffset) might changed
        [_collectionViewData validateLayoutInRect:self.bounds];
        [self updateVisibleCellsNow:YES];
    }

    if (_backgroundView) {
        _backgroundView.frame = (CGRect){.origin = self.contentOffset, .size = self.bounds.size };
    }

    _collectionViewFlags.fadeCellsForBoundsChange = NO;
    _collectionViewFlags.doneFirstLayout = YES;
}

/**
   @Status Interoperable
*/
- (void)setFrame:(CGRect)frame {
    if (!CGRectEqualToRect(frame, self.frame)) {
        CGRect bounds = (CGRect){.origin = self.contentOffset, .size = frame.size };
        BOOL shouldInvalidate = [self.collectionViewLayout shouldInvalidateLayoutForBoundsChange:bounds];
        [super setFrame:frame];
        if (shouldInvalidate) {
            [self invalidateLayout];
            _collectionViewFlags.fadeCellsForBoundsChange = YES;
        }
    }
}

/**
   @Status Interoperable
*/
- (void)setBounds:(CGRect)bounds {
    if (!CGRectEqualToRect(bounds, self.bounds)) {
        BOOL shouldInvalidate = [self.collectionViewLayout shouldInvalidateLayoutForBoundsChange:bounds];
        [super setBounds:bounds];
        if (shouldInvalidate) {
            [self invalidateLayout];
            _collectionViewFlags.fadeCellsForBoundsChange = YES;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - UIScrollViewDelegate

/**
   @Public No
 */
- (void)scrollViewDidScroll:(UIScrollView*)scrollView {
    id<UICollectionViewDelegate> delegate = self.collectionViewDelegate;
    if ((id)delegate != self && [delegate respondsToSelector:@selector(scrollViewDidScroll:)]) {
        [delegate scrollViewDidScroll:scrollView];
    }
}

/**
   @Public No
*/
- (void)scrollViewDidZoom:(UIScrollView*)scrollView {
    id<UICollectionViewDelegate> delegate = self.collectionViewDelegate;
    if ((id)delegate != self && [delegate respondsToSelector:@selector(scrollViewDidZoom:)]) {
        [delegate scrollViewDidZoom:scrollView];
    }
}

/**
   @Public No
*/
- (void)scrollViewWillBeginDragging:(UIScrollView*)scrollView {
    id<UICollectionViewDelegate> delegate = self.collectionViewDelegate;
    if ((id)delegate != self && [delegate respondsToSelector:@selector(scrollViewWillBeginDragging:)]) {
        [delegate scrollViewWillBeginDragging:scrollView];
    }
}

/**
   @Public No
*/
- (void)scrollViewWillEndDragging:(UIScrollView*)scrollView
                     withVelocity:(CGPoint)velocity
              targetContentOffset:(inout CGPoint*)targetContentOffset {
    // Let collectionViewLayout decide where to stop.
    *targetContentOffset =
        [[self collectionViewLayout] targetContentOffsetForProposedContentOffset:*targetContentOffset withScrollingVelocity:velocity];

    id<UICollectionViewDelegate> delegate = self.collectionViewDelegate;
    if ((id)delegate != self && [delegate respondsToSelector:@selector(scrollViewWillEndDragging:withVelocity:targetContentOffset:)]) {
        // if collectionViewDelegate implements this method, it may modify targetContentOffset as well
        [delegate scrollViewWillEndDragging:scrollView withVelocity:velocity targetContentOffset:targetContentOffset];
    }
}

/**
   @Public No
*/
- (void)scrollViewDidEndDragging:(UIScrollView*)scrollView willDecelerate:(BOOL)decelerate {
    id<UICollectionViewDelegate> delegate = self.collectionViewDelegate;
    if ((id)delegate != self && [delegate respondsToSelector:@selector(scrollViewDidEndDragging:willDecelerate:)]) {
        [delegate scrollViewDidEndDragging:scrollView willDecelerate:decelerate];
    }

    // if we are in the middle of a cell touch event, perform the "touchEnded" simulation
    if (self.touchingIndexPath) {
        [self cellTouchCancelled];
    }
}

/**
   @Public No
*/
- (void)scrollViewWillBeginDecelerating:(UIScrollView*)scrollView {
    id<UICollectionViewDelegate> delegate = self.collectionViewDelegate;
    if ((id)delegate != self && [delegate respondsToSelector:@selector(scrollViewWillBeginDecelerating:)]) {
        [delegate scrollViewWillBeginDecelerating:scrollView];
    }
}

/**
   @Public No
*/
- (void)scrollViewDidEndDecelerating:(UIScrollView*)scrollView {
    id<UICollectionViewDelegate> delegate = self.collectionViewDelegate;
    if ((id)delegate != self && [delegate respondsToSelector:@selector(scrollViewDidEndDecelerating:)]) {
        [delegate scrollViewDidEndDecelerating:scrollView];
    }
}

/**
   @Public No
*/
- (void)scrollViewDidEndScrollingAnimation:(UIScrollView*)scrollView {
    id<UICollectionViewDelegate> delegate = self.collectionViewDelegate;
    if ((id)delegate != self && [delegate respondsToSelector:@selector(scrollViewDidEndScrollingAnimation:)]) {
        [delegate scrollViewDidEndScrollingAnimation:scrollView];
    }
}

/**
   @Public No
*/
- (UIView*)viewForZoomingInScrollView:(UIScrollView*)scrollView {
    id<UICollectionViewDelegate> delegate = self.collectionViewDelegate;
    if ((id)delegate != self && [delegate respondsToSelector:@selector(viewForZoomingInScrollView:)]) {
        return [delegate viewForZoomingInScrollView:scrollView];
    }
    return nil;
}

/**
   @Public No
*/
- (void)scrollViewWillBeginZooming:(UIScrollView*)scrollView withView:(UIView*)view {
    id<UICollectionViewDelegate> delegate = self.collectionViewDelegate;
    if ((id)delegate != self && [delegate respondsToSelector:@selector(scrollViewWillBeginZooming:withView:)]) {
        [delegate scrollViewWillBeginZooming:scrollView withView:view];
    }
}

/**
   @Public No
*/
- (void)scrollViewDidEndZooming:(UIScrollView*)scrollView withView:(UIView*)view atScale:(CGFloat)scale {
    id<UICollectionViewDelegate> delegate = self.collectionViewDelegate;
    if ((id)delegate != self && [delegate respondsToSelector:@selector(scrollViewDidEndZooming:withView:atScale:)]) {
        [delegate scrollViewDidEndZooming:scrollView withView:view atScale:scale];
    }
}

/**
   @Public No
*/
- (BOOL)scrollViewShouldScrollToTop:(UIScrollView*)scrollView {
    id<UICollectionViewDelegate> delegate = self.collectionViewDelegate;
    if ((id)delegate != self && [delegate respondsToSelector:@selector(scrollViewShouldScrollToTop:)]) {
        return [delegate scrollViewShouldScrollToTop:scrollView];
    }
    return YES;
}

/**
   @Public No
*/
- (void)scrollViewDidScrollToTop:(UIScrollView*)scrollView {
    id<UICollectionViewDelegate> delegate = self.collectionViewDelegate;
    if ((id)delegate != self && [delegate respondsToSelector:@selector(scrollViewDidScrollToTop:)]) {
        [delegate scrollViewDidScrollToTop:scrollView];
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Public

/**
   @Status Interoperable
*/
- (void)registerClass:(Class)cellClass forCellWithReuseIdentifier:(NSString*)identifier {
    NSParameterAssert(cellClass);
    NSParameterAssert(identifier);
    _cellClassDict[identifier] = cellClass;
}

/**
   @Status Interoperable
*/
- (void)registerClass:(Class)viewClass forSupplementaryViewOfKind:(NSString*)elementKind withReuseIdentifier:(NSString*)identifier {
    NSParameterAssert(viewClass);
    NSParameterAssert(elementKind);
    NSParameterAssert(identifier);
    NSString* kindAndIdentifier = [NSString stringWithFormat:@"%@/%@", elementKind, identifier];
    _supplementaryViewClassDict[kindAndIdentifier] = viewClass;
}

/**
   @Status Stub
*/
- (void)registerNib:(UINib*)nib forCellWithReuseIdentifier:(NSString*)identifier {
    NSArray* topLevelObjects = [nib instantiateWithOwner:nil options:nil];
#pragma unused(topLevelObjects)
    NSAssert(topLevelObjects.count == 1 && [topLevelObjects[0] isKindOfClass:UICollectionViewCell.class],
             @"must contain exactly 1 top level object which is a UICollectionViewCell");

    _cellNibDict[identifier] = nib;
}

/**
   @Status Stub
*/
- (void)registerNib:(UINib*)nib forSupplementaryViewOfKind:(NSString*)kind withReuseIdentifier:(NSString*)identifier {
    NSArray* topLevelObjects = [nib instantiateWithOwner:nil options:nil];
#pragma unused(topLevelObjects)
    NSAssert(topLevelObjects.count == 1 && [topLevelObjects[0] isKindOfClass:UICollectionReusableView.class],
             @"must contain exactly 1 top level object which is a UICollectionReusableView");

    NSString* kindAndIdentifier = [NSString stringWithFormat:@"%@/%@", kind, identifier];
    _supplementaryViewNibDict[kindAndIdentifier] = nib;
}

/**
   @Status Interoperable
*/
- (id)dequeueReusableCellWithReuseIdentifier:(NSString*)identifier forIndexPath:(NSIndexPath*)indexPath {
    // de-queue cell (if available)
    NSMutableArray* reusableCells = _cellReuseQueues[identifier];
    UICollectionViewCell* cell = [reusableCells lastObject];
    UICollectionViewLayoutAttributes* attributes = [self.collectionViewLayout layoutAttributesForItemAtIndexPath:indexPath];

    if (cell) {
        [reusableCells removeObjectAtIndex:reusableCells.count - 1];
    } else {
        if (_cellNibDict[identifier]) {
            // Cell was registered via registerNib:forCellWithReuseIdentifier:
            UINib* cellNib = _cellNibDict[identifier];
            NSDictionary* externalObjects = self.nibCellsExternalObjects[identifier];
            if (externalObjects) {
                // TODO: need UiNibExternalObjects() support maybe?
                // cell = [cellNib instantiateWithOwner:self options:@{UINibExternalObjects : externalObjects}][0];
                cell = [cellNib instantiateWithOwner:self options:externalObjects][0];
            } else {
                cell = [cellNib instantiateWithOwner:self options:nil][0];
            }
        } else {
            Class cellClass = _cellClassDict[identifier];
            // compatibility layer
            Class collectionViewCellClass = NSClassFromString(@"UICollectionViewCell");
            if (collectionViewCellClass && [cellClass isEqual:collectionViewCellClass]) {
                cellClass = UICollectionViewCell.class;
            }
            if (cellClass == nil) {
                @throw [NSException exceptionWithName:NSInvalidArgumentException
                                               reason:[NSString stringWithFormat:@"Class not registered for identifier %@", identifier]
                                             userInfo:nil];
            }
            if (attributes) {
                cell = [[cellClass alloc] initWithFrame:attributes.frame];
            } else {
                cell = [cellClass new];
            }
        }
        cell.collectionView = self;
        cell.reuseIdentifier = identifier;
    }

    [cell applyLayoutAttributes:attributes];

    return cell;
}

/**
   @Status Interoperable
*/
- (id)dequeueReusableSupplementaryViewOfKind:(NSString*)elementKind
                         withReuseIdentifier:(NSString*)identifier
                                forIndexPath:(NSIndexPath*)indexPath {
    NSString* kindAndIdentifier = [NSString stringWithFormat:@"%@/%@", elementKind, identifier];
    NSMutableArray* reusableViews = _supplementaryViewReuseQueues[kindAndIdentifier];
    UICollectionReusableView* view = [reusableViews lastObject];
    if (view) {
        [reusableViews removeObjectAtIndex:reusableViews.count - 1];
    } else {
        if (_supplementaryViewNibDict[kindAndIdentifier]) {
            // supplementary view was registered via registerNib:forCellWithReuseIdentifier:
            UINib* supplementaryViewNib = _supplementaryViewNibDict[kindAndIdentifier];
            NSDictionary* externalObjects = self.supplementaryViewsExternalObjects[kindAndIdentifier];
            if (externalObjects) {
                // view = [supplementaryViewNib instantiateWithOwner:self options:@{UINibExternalObjects : externalObjects}][0];
                view = [supplementaryViewNib instantiateWithOwner:self options:externalObjects][0];
            } else {
                view = [supplementaryViewNib instantiateWithOwner:self options:nil][0];
            }
        } else {
            Class viewClass = _supplementaryViewClassDict[kindAndIdentifier];
            Class reusableViewClass = NSClassFromString(@"UICollectionReusableView");
            if (reusableViewClass && [viewClass isEqual:reusableViewClass]) {
                viewClass = UICollectionReusableView.class;
            }
            if (viewClass == nil) {
                @throw [NSException
                    exceptionWithName:NSInvalidArgumentException
                               reason:[NSString stringWithFormat:@"Class not registered for kind/identifier %@", kindAndIdentifier]
                             userInfo:nil];
            }
            if (self.collectionViewLayout) {
                UICollectionViewLayoutAttributes* attributes =
                    [self.collectionViewLayout layoutAttributesForSupplementaryViewOfKind:elementKind atIndexPath:indexPath];
                if (attributes) {
                    view = [[viewClass alloc] initWithFrame:attributes.frame];
                }
            } else {
                view = [viewClass new];
            }
        }
        view.collectionView = self;
        view.reuseIdentifier = identifier;
    }

    return view;
}

/**
   @Status Caveat -- this appears to be an extension.
*/
- (id)dequeueReusableOrCreateDecorationViewOfKind:(NSString*)elementKind forIndexPath:(NSIndexPath*)indexPath {
    NSMutableArray* reusableViews = _decorationViewReuseQueues[elementKind];
    UICollectionReusableView* view = [reusableViews lastObject];
    UICollectionViewLayout* collectionViewLayout = self.collectionViewLayout;
    UICollectionViewLayoutAttributes* attributes =
        [collectionViewLayout layoutAttributesForDecorationViewOfKind:elementKind atIndexPath:indexPath];

    if (view) {
        [reusableViews removeObjectAtIndex:reusableViews.count - 1];
    } else {
        NSDictionary* decorationViewNibDict = collectionViewLayout.decorationViewNibDict;
        NSDictionary* decorationViewExternalObjects = collectionViewLayout.decorationViewExternalObjectsTables;
        if (decorationViewNibDict[elementKind]) {
            // supplementary view was registered via registerNib:forCellWithReuseIdentifier:
            UINib* supplementaryViewNib = decorationViewNibDict[elementKind];
            NSDictionary* externalObjects = decorationViewExternalObjects[elementKind];
            if (externalObjects) {
                // view = [supplementaryViewNib instantiateWithOwner:self options:@{UINibExternalObjects : externalObjects}][0];
                view = [supplementaryViewNib instantiateWithOwner:self options:externalObjects][0];
            } else {
                view = [supplementaryViewNib instantiateWithOwner:self options:nil][0];
            }
        } else {
            NSDictionary* decorationViewClassDict = collectionViewLayout.decorationViewClassDict;
            Class viewClass = decorationViewClassDict[elementKind];
            Class reusableViewClass = NSClassFromString(@"UICollectionReusableView");
            if (reusableViewClass && [viewClass isEqual:reusableViewClass]) {
                viewClass = UICollectionReusableView.class;
            }
            if (viewClass == nil) {
                @throw [NSException exceptionWithName:NSInvalidArgumentException
                                               reason:[NSString stringWithFormat:@"Class not registered for identifier %@", elementKind]
                                             userInfo:nil];
            }
            if (attributes) {
                view = [[viewClass alloc] initWithFrame:attributes.frame];
            } else {
                view = [viewClass new];
            }
        }
        view.collectionView = self;
        view.reuseIdentifier = elementKind;
    }

    [view applyLayoutAttributes:attributes];

    return view;
}

/**
   @Public No
*/
- (NSArray*)allCells {
    auto res = [[NSMutableArray alloc] init];
    auto visibleViews = [_allVisibleViewsDict allValues];
    for (id obj in visibleViews) {
        if ([obj isKindOfClass:UICollectionViewCell.class]) {
            [res addObject:obj];
        }
    }
    return res;
    /* WAS:
    return [[_allVisibleViewsDict allValues] filteredArrayUsingPredicate:
        [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary *bindings) {
            return [evaluatedObject isKindOfClass:UICollectionViewCell.class];
    }]];
    */
}

/**
   @Status Interoperable
*/
- (NSArray*)visibleCells {
    auto res = [[NSMutableArray alloc] init];
    auto visibleViews = [_allVisibleViewsDict allValues];
    for (id obj in visibleViews) {
        if ([obj isKindOfClass:UICollectionViewCell.class] &&
            CGRectIntersectsRect(self.bounds, static_cast<UICollectionViewCell*>(obj).frame)) {
            [res addObject:obj];
        }
    }
    return res;
    /* WAS:
    return [[_allVisibleViewsDict allValues] filteredArrayUsingPredicate:
        [NSPredicate predicateWithBlock:
             ^BOOL(id evaluatedObject, NSDictionary *bindings) {
                return [evaluatedObject isKindOfClass:UICollectionViewCell.class] &&
                       CGRectIntersectsRect(self.bounds, [evaluatedObject frame]);
    }]];
    */
}

/**
   @Status Interoperable
*/
- (void)reloadData {
    if (_reloadingSuspendedCount != 0)
        return;
    [self invalidateLayout];
    [_allVisibleViewsDict enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL* stop) {
        if ([obj isKindOfClass:UIView.class]) {
            [obj removeFromSuperview];
        }
    }];
    [_allVisibleViewsDict removeAllObjects];

    for (NSIndexPath* indexPath in _indexPathsForSelectedItems) {
        UICollectionViewCell* selectedCell = [self cellForItemAtIndexPath:indexPath];
        selectedCell.selected = NO;
        selectedCell.highlighted = NO;
    }
    [_indexPathsForSelectedItems removeAllObjects];
    [_indexPathsForHighlightedItems removeAllObjects];

    [self setNeedsLayout];
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Query Grid

/**
   @Status Interoperable
*/
- (NSInteger)numberOfSections {
    return [_collectionViewData numberOfSections];
}

/**
   @Status Interoperable
*/
- (NSInteger)numberOfItemsInSection:(NSInteger)section {
    return [_collectionViewData numberOfItemsInSection:section];
}

/**
   @Status Interoperable
*/
- (UICollectionViewLayoutAttributes*)layoutAttributesForItemAtIndexPath:(NSIndexPath*)indexPath {
    return [[self collectionViewLayout] layoutAttributesForItemAtIndexPath:indexPath];
}

/**
   @Status Interoperable
*/
- (UICollectionViewLayoutAttributes*)layoutAttributesForSupplementaryElementOfKind:(NSString*)kind atIndexPath:(NSIndexPath*)indexPath {
    return [[self collectionViewLayout] layoutAttributesForSupplementaryViewOfKind:kind atIndexPath:indexPath];
}

/**
   @Status Interoperable
*/

- (NSIndexPath*)indexPathForItemAtPoint:(CGPoint)point {
    UICollectionViewLayoutAttributes* attributes =
        [[self.collectionViewLayout layoutAttributesForElementsInRect:CGRectMake(point.x, point.y, 1, 1)] lastObject];
    return attributes.indexPath;
}

/**
   @Status Interoperable
*/

- (NSIndexPath*)indexPathForCell:(UICollectionViewCell*)cell {
    __block NSIndexPath* indexPath = nil;
    [_allVisibleViewsDict enumerateKeysAndObjectsWithOptions:kNilOptions
                                                  usingBlock:^(id key, id obj, BOOL* stop) {
                                                      UICollectionViewItemKey* itemKey = (UICollectionViewItemKey*)key;
                                                      if (itemKey.type == UICollectionViewItemTypeCell) {
                                                          UICollectionViewCell* currentCell = (UICollectionViewCell*)obj;
                                                          if (currentCell == cell) {
                                                              indexPath = itemKey.indexPath;
                                                              *stop = YES;
                                                          }
                                                      }
                                                  }];
    return indexPath;
}

/**
   @Status Interoperable
*/

- (UICollectionViewCell*)cellForItemAtIndexPath:(NSIndexPath*)indexPath {
    // NSInteger index = [_collectionViewData globalIndexForItemAtIndexPath:indexPath];
    // TODO Apple uses some kind of globalIndex for this.
    __block UICollectionViewCell* cell = nil;
    [_allVisibleViewsDict enumerateKeysAndObjectsWithOptions:0
                                                  usingBlock:^(id key, id obj, BOOL* stop) {
                                                      UICollectionViewItemKey* itemKey = (UICollectionViewItemKey*)key;
                                                      if (itemKey.type == UICollectionViewItemTypeCell) {
                                                          if ([itemKey.indexPath isEqual:indexPath]) {
                                                              cell = obj;
                                                              *stop = YES;
                                                          }
                                                      }
                                                  }];
    return cell;
}

/**
   @Status Interoperable
*/

- (NSArray*)indexPathsForVisibleItems {
    NSArray* visibleCells = self.visibleCells;
    NSMutableArray* indexPaths = [NSMutableArray arrayWithCapacity:visibleCells.count];

    [visibleCells enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL* stop) {
        UICollectionViewCell* cell = (UICollectionViewCell*)obj;
        [indexPaths addObject:cell.layoutAttributes.indexPath];
    }];

    return indexPaths;
}

/**
   @Status Interoperable
*/

// returns nil or an array of selected index paths
- (NSArray*)indexPathsForSelectedItems {
    return [_indexPathsForSelectedItems allObjects];
}


/**
   @Status Interoperable
*/

// Interacting with the collection view.
- (void)scrollToItemAtIndexPath:(NSIndexPath*)indexPath
               atScrollPosition:(UICollectionViewScrollPosition)scrollPosition
                       animated:(BOOL)animated {
    // Ensure grid is laid out; else we can't scroll.
    [self layoutSubviews];

    UICollectionViewLayoutAttributes* layoutAttributes = [self.collectionViewLayout layoutAttributesForItemAtIndexPath:indexPath];
    if (layoutAttributes) {
        CGRect targetRect = [self makeRect:layoutAttributes.frame toScrollPosition:scrollPosition];
        [self scrollRectToVisible:targetRect animated:animated];
    }
}

/**
   @Status Interoperable
*/

- (CGRect)makeRect:(CGRect)targetRect toScrollPosition:(UICollectionViewScrollPosition)scrollPosition {
    // split parameters
    NSUInteger verticalPosition = scrollPosition & 0x07; // 0000 0111
    NSUInteger horizontalPosition = scrollPosition & 0x38; // 0011 1000

    if (verticalPosition != UICollectionViewScrollPositionNone && verticalPosition != UICollectionViewScrollPositionTop &&
        verticalPosition != UICollectionViewScrollPositionCenteredVertically && verticalPosition != UICollectionViewScrollPositionBottom) {
        @throw [NSException
            exceptionWithName:NSInvalidArgumentException
                       reason:@"UICollectionViewScrollPosition: attempt to use a scroll position with multiple vertical positioning styles"
                     userInfo:nil];
    }

    if (horizontalPosition != UICollectionViewScrollPositionNone && horizontalPosition != UICollectionViewScrollPositionLeft &&
        horizontalPosition != UICollectionViewScrollPositionCenteredHorizontally &&
        horizontalPosition != UICollectionViewScrollPositionRight) {
        @throw [NSException
            exceptionWithName:NSInvalidArgumentException
                       reason:
                           @"UICollectionViewScrollPosition: attempt to use a scroll position with multiple horizontal positioning styles"
                     userInfo:nil];
    }

    CGRect frame = self.layer.bounds;
    CGFloat calculateX;
    CGFloat calculateY;

    switch (verticalPosition) {
        case UICollectionViewScrollPositionCenteredVertically:
            calculateY = fmax(targetRect.origin.y - ((frame.size.height / 2) - (targetRect.size.height / 2)), -self.contentInset.top);
            targetRect = CGRectMake(targetRect.origin.x, calculateY, targetRect.size.width, frame.size.height);
            break;
        case UICollectionViewScrollPositionTop:
            targetRect = CGRectMake(targetRect.origin.x, targetRect.origin.y, targetRect.size.width, frame.size.height);
            break;

        case UICollectionViewScrollPositionBottom:
            calculateY = fmax(targetRect.origin.y - (frame.size.height - targetRect.size.height), -self.contentInset.top);
            targetRect = CGRectMake(targetRect.origin.x, calculateY, targetRect.size.width, frame.size.height);
            break;
    }

    switch (horizontalPosition) {
        case UICollectionViewScrollPositionCenteredHorizontally:
            calculateX = targetRect.origin.x - ((frame.size.width / 2) - (targetRect.size.width / 2));
            targetRect = CGRectMake(calculateX, targetRect.origin.y, frame.size.width, targetRect.size.height);
            break;

        case UICollectionViewScrollPositionLeft:
            targetRect = CGRectMake(targetRect.origin.x, targetRect.origin.y, frame.size.width, targetRect.size.height);
            break;

        case UICollectionViewScrollPositionRight:
            calculateX = targetRect.origin.x - (frame.size.width - targetRect.size.width);
            targetRect = CGRectMake(calculateX, targetRect.origin.y, frame.size.width, targetRect.size.height);
            break;
    }

    return targetRect;
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Touch Handling

- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    [super touchesBegan:touches withEvent:event];

    // reset touching state vars
    self.touchingIndexPath = nil;
    self.currentIndexPath = nil;

    CGPoint touchPoint = [[touches anyObject] locationInView:self];
    NSIndexPath* indexPath = [self indexPathForItemAtPoint:touchPoint];
    if (indexPath && self.allowsSelection) {
        if (![self highlightItemAtIndexPath:indexPath animated:YES scrollPosition:UICollectionViewScrollPositionNone notifyDelegate:YES])
            return;

        self.touchingIndexPath = indexPath;
        self.currentIndexPath = indexPath;

        if (!self.allowsMultipleSelection) {
            // temporally unhighlight background on touchesBegan (keeps selected by _indexPathsForSelectedItems)
            // single-select only mode only though
            NSIndexPath* tempDeselectIndexPath = _indexPathsForSelectedItems.anyObject;
            if (tempDeselectIndexPath && ![tempDeselectIndexPath isEqual:self.touchingIndexPath]) {
                // iOS6 UICollectionView deselects cell without notification
                UICollectionViewCell* selectedCell = [self cellForItemAtIndexPath:tempDeselectIndexPath];
                selectedCell.selected = NO;
            }
        }
    }
}

- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
    [super touchesMoved:touches withEvent:event];

    // allows moving between highlight and unhighlight state only if setHighlighted is not overwritten
    if (self.touchingIndexPath) {
        CGPoint touchPoint = [[touches anyObject] locationInView:self];
        NSIndexPath* indexPath = [self indexPathForItemAtPoint:touchPoint];

        // moving out of bounds
        if ([self.currentIndexPath isEqual:self.touchingIndexPath] && ![indexPath isEqual:self.touchingIndexPath] &&
            [self unhighlightItemAtIndexPath:self.touchingIndexPath animated:YES notifyDelegate:YES shouldCheckHighlight:YES]) {
            self.currentIndexPath = indexPath;
            // moving back into the original touching cell
        } else if (![self.currentIndexPath isEqual:self.touchingIndexPath] && [indexPath isEqual:self.touchingIndexPath]) {
            [self highlightItemAtIndexPath:self.touchingIndexPath
                                  animated:YES
                            scrollPosition:UICollectionViewScrollPositionNone
                            notifyDelegate:YES];
            self.currentIndexPath = self.touchingIndexPath;
        }
    }
}

/**
   @Public No
*/
- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    [super touchesEnded:touches withEvent:event];

    if (self.touchingIndexPath) {
        // first unhighlight the touch operation
        [self unhighlightItemAtIndexPath:self.touchingIndexPath animated:YES notifyDelegate:YES];

        CGPoint touchPoint = [[touches anyObject] locationInView:self];
        NSIndexPath* indexPath = [self indexPathForItemAtPoint:touchPoint];
        if ([indexPath isEqual:self.touchingIndexPath]) {
            [self userSelectedItemAtIndexPath:indexPath];
        } else if (!self.allowsMultipleSelection) {
            NSIndexPath* tempDeselectIndexPath = _indexPathsForSelectedItems.anyObject;
            if (tempDeselectIndexPath && ![tempDeselectIndexPath isEqual:self.touchingIndexPath]) {
                [self cellTouchCancelled];
            }
        }

        // for pedantic reasons only - always set to nil on touchesBegan
        self.touchingIndexPath = nil;
        self.currentIndexPath = nil;
    }
}

- (void)touchesCancelled:(NSSet*)touches withEvent:(UIEvent*)event {
    [super touchesCancelled:touches withEvent:event];

    // do not mark touchingIndexPath as nil because whoever cancelled this touch will need to signal a touch up event later
    if (self.touchingIndexPath) {
        // first unhighlight the touch operation
        [self unhighlightItemAtIndexPath:self.touchingIndexPath animated:YES notifyDelegate:YES];
    }
}

- (void)cellTouchCancelled {
    // turn on ALL the *should be selected* cells (iOS6 UICollectionView does no state keeping or other fancy optimizations)
    // there should be no notifications as this is a silent "turn everything back on"
    for (NSIndexPath* tempDeselectedIndexPath in [_indexPathsForSelectedItems copy]) {
        UICollectionViewCell* selectedCell = [self cellForItemAtIndexPath:tempDeselectedIndexPath];
        selectedCell.selected = YES;
    }
}

- (void)userSelectedItemAtIndexPath:(NSIndexPath*)indexPath {
    if (self.allowsMultipleSelection && [_indexPathsForSelectedItems containsObject:indexPath]) {
        [self deselectItemAtIndexPath:indexPath animated:YES notifyDelegate:YES];
    } else if (self.allowsSelection) {
        [self selectItemAtIndexPath:indexPath animated:YES scrollPosition:UICollectionViewScrollPositionNone notifyDelegate:YES];
    }
}

/**
   @Status Interoperable
*/

// select item, notify delegate (internal)
- (void)selectItemAtIndexPath:(NSIndexPath*)indexPath
                     animated:(BOOL)animated
               scrollPosition:(UICollectionViewScrollPosition)scrollPosition
               notifyDelegate:(BOOL)notifyDelegate {
    if (self.allowsMultipleSelection && [_indexPathsForSelectedItems containsObject:indexPath]) {
        BOOL shouldDeselect = YES;
        if (notifyDelegate && _collectionViewFlags.delegateShouldDeselectItemAtIndexPath) {
            shouldDeselect = [self.delegate collectionView:self shouldDeselectItemAtIndexPath:indexPath];
        }

        if (shouldDeselect) {
            [self deselectItemAtIndexPath:indexPath animated:animated notifyDelegate:notifyDelegate];
        }
    } else {
        // either single selection, or wasn't already selected in multiple selection mode
        BOOL shouldSelect = YES;
        if (notifyDelegate && _collectionViewFlags.delegateShouldSelectItemAtIndexPath) {
            shouldSelect = [self.delegate collectionView:self shouldSelectItemAtIndexPath:indexPath];
        }

        if (!self.allowsMultipleSelection) {
            // now unselect the previously selected cell for single selection
            NSIndexPath* tempDeselectIndexPath = _indexPathsForSelectedItems.anyObject;
            if (tempDeselectIndexPath && ![tempDeselectIndexPath isEqual:indexPath]) {
                [self deselectItemAtIndexPath:tempDeselectIndexPath animated:YES notifyDelegate:YES];
            }
        }

        if (shouldSelect) {
            UICollectionViewCell* selectedCell = [self cellForItemAtIndexPath:indexPath];
            selectedCell.selected = YES;

            [_indexPathsForSelectedItems addObject:indexPath];

            [selectedCell performSelectionSegue];

            if (scrollPosition != UICollectionViewScrollPositionNone) {
                [self scrollToItemAtIndexPath:indexPath atScrollPosition:scrollPosition animated:animated];
            }

            if (notifyDelegate && _collectionViewFlags.delegateDidSelectItemAtIndexPath) {
                [self.delegate collectionView:self didSelectItemAtIndexPath:indexPath];
            }
        }
    }
}

/**
   @Status Interoperable
*/

- (void)selectItemAtIndexPath:(NSIndexPath*)indexPath
                     animated:(BOOL)animated
               scrollPosition:(UICollectionViewScrollPosition)scrollPosition {
    [self selectItemAtIndexPath:indexPath animated:animated scrollPosition:scrollPosition notifyDelegate:NO];
}

/**
   @Status Interoperable
*/

- (void)deselectItemAtIndexPath:(NSIndexPath*)indexPath animated:(BOOL)animated {
    [self deselectItemAtIndexPath:indexPath animated:animated notifyDelegate:NO];
}

/**
   @Status Interoperable
*/

- (void)deselectItemAtIndexPath:(NSIndexPath*)indexPath animated:(BOOL)animated notifyDelegate:(BOOL)notifyDelegate {
    BOOL shouldDeselect = YES;
    // deselect only relevant during multi mode
    if (self.allowsMultipleSelection && notifyDelegate && _collectionViewFlags.delegateShouldDeselectItemAtIndexPath) {
        shouldDeselect = [self.delegate collectionView:self shouldDeselectItemAtIndexPath:indexPath];
    }

    if (shouldDeselect && [_indexPathsForSelectedItems containsObject:indexPath]) {
        UICollectionViewCell* selectedCell = [self cellForItemAtIndexPath:indexPath];
        if (selectedCell) {
            if (selectedCell.selected) {
                selectedCell.selected = NO;
            }
        }
        [_indexPathsForSelectedItems removeObject:indexPath];

        if (notifyDelegate && _collectionViewFlags.delegateDidDeselectItemAtIndexPath) {
            [self.delegate collectionView:self didDeselectItemAtIndexPath:indexPath];
        }
    }
}

/**
   @Status Interoperable
*/

- (BOOL)highlightItemAtIndexPath:(NSIndexPath*)indexPath
                        animated:(BOOL)animated
                  scrollPosition:(UICollectionViewScrollPosition)scrollPosition
                  notifyDelegate:(BOOL)notifyDelegate {
    BOOL shouldHighlight = YES;
    if (notifyDelegate && _collectionViewFlags.delegateShouldHighlightItemAtIndexPath) {
        shouldHighlight = [self.delegate collectionView:self shouldHighlightItemAtIndexPath:indexPath];
    }

    if (shouldHighlight) {
        UICollectionViewCell* highlightedCell = [self cellForItemAtIndexPath:indexPath];
        highlightedCell.highlighted = YES;
        [_indexPathsForHighlightedItems addObject:indexPath];

        if (scrollPosition != UICollectionViewScrollPositionNone) {
            [self scrollToItemAtIndexPath:indexPath atScrollPosition:scrollPosition animated:animated];
        }

        if (notifyDelegate && _collectionViewFlags.delegateDidHighlightItemAtIndexPath) {
            [self.delegate collectionView:self didHighlightItemAtIndexPath:indexPath];
        }
    }
    return shouldHighlight;
}

/**
   @Status Interoperable
*/

- (BOOL)unhighlightItemAtIndexPath:(NSIndexPath*)indexPath animated:(BOOL)animated notifyDelegate:(BOOL)notifyDelegate {
    return [self unhighlightItemAtIndexPath:indexPath animated:animated notifyDelegate:notifyDelegate shouldCheckHighlight:NO];
}

/**
   @Status Interoperable
*/

- (BOOL)unhighlightItemAtIndexPath:(NSIndexPath*)indexPath
                          animated:(BOOL)animated
                    notifyDelegate:(BOOL)notifyDelegate
              shouldCheckHighlight:(BOOL)check {
    if ([_indexPathsForHighlightedItems containsObject:indexPath]) {
        UICollectionViewCell* highlightedCell = [self cellForItemAtIndexPath:indexPath];
        // iOS6 does not notify any delegate if the cell was never highlighted (setHighlighted overwritten) during touchMoved
        if (check && !highlightedCell.highlighted) {
            return NO;
        }

        // if multiple selection or not unhighlighting a selected item we don't perform any op
        if (highlightedCell.highlighted && [_indexPathsForSelectedItems containsObject:indexPath]) {
            highlightedCell.highlighted = YES;
        } else {
            highlightedCell.highlighted = NO;
        }

        [_indexPathsForHighlightedItems removeObject:indexPath];

        if (notifyDelegate && _collectionViewFlags.delegateDidUnhighlightItemAtIndexPath) {
            [self.delegate collectionView:self didUnhighlightItemAtIndexPath:indexPath];
        }

        return YES;
    }
    return NO;
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Update Grid

/**
   @Status Interoperable
*/
- (void)insertSections:(NSIndexSet*)sections {
    [self updateSections:sections updateAction:UICollectionUpdateActionInsert];
}

/**
   @Status Interoperable
*/
- (void)deleteSections:(NSIndexSet*)sections {
    // First delete all items
    NSMutableArray* paths = [NSMutableArray new];
    [sections enumerateIndexesUsingBlock:^(NSUInteger idx, BOOL* stop) {
        for (int i = 0; i < [self numberOfItemsInSection:(NSInteger)idx]; ++i) {
            [paths addObject:[NSIndexPath indexPathForItem:i inSection:(NSInteger)idx]];
        }
    }];
    [self deleteItemsAtIndexPaths:paths];
    // Then delete the section.
    [self updateSections:sections updateAction:UICollectionUpdateActionDelete];
}

/**
   @Status Interoperable
*/
- (void)reloadSections:(NSIndexSet*)sections {
    [self updateSections:sections updateAction:UICollectionUpdateActionReload];
}

/**
   @Status Interoperable
*/
- (void)moveSection:(NSInteger)section toSection:(NSInteger)newSection {
    NSMutableArray* moveUpdateItems = [self arrayForUpdateAction:UICollectionUpdateActionMove];
    [moveUpdateItems addObject:[[UICollectionViewUpdateItem alloc]
                                   initWithInitialIndexPath:[NSIndexPath indexPathForItem:NSNotFound inSection:section]
                                             finalIndexPath:[NSIndexPath indexPathForItem:NSNotFound inSection:newSection]
                                               updateAction:UICollectionUpdateActionMove]];
    if (!_collectionViewFlags.updating) {
        [self setupCellAnimations];
        [self endItemAnimations];
    }
}

/**
   @Status Interoperable
*/
- (void)insertItemsAtIndexPaths:(NSArray*)indexPaths {
    [self updateRowsAtIndexPaths:indexPaths updateAction:UICollectionUpdateActionInsert];
}

/**
   @Status Interoperable
*/
- (void)deleteItemsAtIndexPaths:(NSArray*)indexPaths {
    [self updateRowsAtIndexPaths:indexPaths updateAction:UICollectionUpdateActionDelete];
}

/**
   @Status Interoperable
*/
- (void)reloadItemsAtIndexPaths:(NSArray*)indexPaths {
    [self updateRowsAtIndexPaths:indexPaths updateAction:UICollectionUpdateActionReload];
}

/**
   @Status Interoperable
*/
- (void)moveItemAtIndexPath:(NSIndexPath*)indexPath toIndexPath:(NSIndexPath*)newIndexPath {
    NSMutableArray* moveUpdateItems = [self arrayForUpdateAction:UICollectionUpdateActionMove];
    [moveUpdateItems addObject:[[UICollectionViewUpdateItem alloc] initWithInitialIndexPath:indexPath
                                                                             finalIndexPath:newIndexPath
                                                                               updateAction:UICollectionUpdateActionMove]];
    if (!_collectionViewFlags.updating) {
        [self setupCellAnimations];
        [self endItemAnimations];
    }
}

/**
   @Status Interoperable
*/
- (void)performBatchUpdates:(void (^)(void))updates completion:(void (^)(BOOL finished))completion {
    [self setupCellAnimations];

    if (updates)
        updates();
    if (completion)
        _updateCompletionHandler = completion;

    [self endItemAnimations];
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Properties

/**
   @Status Interoperable
*/
- (void)setBackgroundView:(UIView*)backgroundView {
    if (backgroundView != _backgroundView) {
        [_backgroundView removeFromSuperview];
        _backgroundView = backgroundView;
        backgroundView.frame = (CGRect){.origin = self.contentOffset, .size = self.bounds.size };
        backgroundView.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;
        [self addSubview:backgroundView];
        [self sendSubviewToBack:backgroundView];
    }
}

/**
   @Status Interoperable
*/
- (void)setCollectionViewLayout:(UICollectionViewLayout*)layout animated:(BOOL)animated {
    if (layout == _layout)
        return;

    // not sure it was it original code, but here this prevents crash
    // in case we switch layout before previous one was initially loaded
    if (CGRectIsEmpty(self.bounds) || !_collectionViewFlags.doneFirstLayout) {
        _layout.collectionView = nil;
        _collectionViewData = [[UICollectionViewData alloc] initWithCollectionView:self layout:layout];
        layout.collectionView = self;
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
        layout.collectionView = self;

        _layout.collectionView = nil;
        _layout = layout;

        _collectionViewData = [[UICollectionViewData alloc] initWithCollectionView:self layout:layout];
        [_collectionViewData prepareToLoadData];

        NSArray* previouslySelectedIndexPaths = [self indexPathsForSelectedItems];
        NSMutableSet* selectedCellKeys = [NSMutableSet setWithCapacity:previouslySelectedIndexPaths.count];

        for (NSIndexPath* indexPath in previouslySelectedIndexPaths) {
            [selectedCellKeys addObject:[UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:indexPath]];
        }

        NSArray* previouslyVisibleItemsKeys = [_allVisibleViewsDict allKeys];
        NSSet* previouslyVisibleItemsKeysSet = [NSSet setWithArray:previouslyVisibleItemsKeys];
        NSMutableSet* previouslyVisibleItemsKeysSetMutable = [NSMutableSet setWithArray:previouslyVisibleItemsKeys];

        if ([selectedCellKeys intersectsSet:selectedCellKeys]) {
            [previouslyVisibleItemsKeysSetMutable intersectSet:previouslyVisibleItemsKeysSetMutable];
        }

        [self bringSubviewToFront:_allVisibleViewsDict[[previouslyVisibleItemsKeysSetMutable anyObject]]];

        CGPoint targetOffset = self.contentOffset;
        CGPoint centerPoint =
            CGPointMake(self.bounds.origin.x + self.bounds.size.width / 2.f, self.bounds.origin.y + self.bounds.size.height / 2.f);
        NSIndexPath* centerItemIndexPath = [self indexPathForItemAtPoint:centerPoint];

        if (!centerItemIndexPath) {
            NSArray* visibleItems = [self indexPathsForVisibleItems];
            if (visibleItems.count > 0) {
                centerItemIndexPath = visibleItems[visibleItems.count / 2];
            }
        }

        if (centerItemIndexPath) {
            UICollectionViewLayoutAttributes* layoutAttributes = [layout layoutAttributesForItemAtIndexPath:centerItemIndexPath];
            if (layoutAttributes) {
                UICollectionViewScrollPosition scrollPosition =
                    UICollectionViewScrollPositionCenteredVertically | UICollectionViewScrollPositionCenteredHorizontally;
                CGRect targetRect = [self makeRect:layoutAttributes.frame toScrollPosition:scrollPosition];
                targetOffset = CGPointMake(fmax(0.f, targetRect.origin.x), fmax(0.f, targetRect.origin.y));
            }
        }

        CGRect newlyBounds = CGRectMake(targetOffset.x, targetOffset.y, self.bounds.size.width, self.bounds.size.height);
        NSArray* newlyVisibleLayoutAttrs = [_collectionViewData layoutAttributesForElementsInRect:newlyBounds];

        NSMutableDictionary* layoutInterchangeData =
            [NSMutableDictionary dictionaryWithCapacity:newlyVisibleLayoutAttrs.count + previouslyVisibleItemsKeysSet.count];

        NSMutableSet* newlyVisibleItemsKeys = [NSMutableSet set];
        for (UICollectionViewLayoutAttributes* attr in newlyVisibleLayoutAttrs) {
            UICollectionViewItemKey* newKey = [UICollectionViewItemKey collectionItemKeyForLayoutAttributes:attr];
            [newlyVisibleItemsKeys addObject:newKey];

            UICollectionViewLayoutAttributes* prevAttr = nil;
            UICollectionViewLayoutAttributes* newAttr = nil;

            if (newKey.type == UICollectionViewItemTypeDecorationView) {
                prevAttr = [self.collectionViewLayout layoutAttributesForDecorationViewOfKind:attr.representedElementKind
                                                                                  atIndexPath:newKey.indexPath];
                newAttr = [layout layoutAttributesForDecorationViewOfKind:attr.representedElementKind atIndexPath:newKey.indexPath];
            } else if (newKey.type == UICollectionViewItemTypeCell) {
                prevAttr = [self.collectionViewLayout layoutAttributesForItemAtIndexPath:newKey.indexPath];
                newAttr = [layout layoutAttributesForItemAtIndexPath:newKey.indexPath];
            } else {
                prevAttr = [self.collectionViewLayout layoutAttributesForSupplementaryViewOfKind:attr.representedElementKind
                                                                                     atIndexPath:newKey.indexPath];
                newAttr = [layout layoutAttributesForSupplementaryViewOfKind:attr.representedElementKind atIndexPath:newKey.indexPath];
            }

            if (prevAttr != nil && newAttr != nil) {
                layoutInterchangeData[newKey] = @{ @"previousLayoutInfos" : prevAttr, @"newLayoutInfos" : newAttr };
            }
        }

        for (UICollectionViewItemKey* key in previouslyVisibleItemsKeysSet) {
            UICollectionViewLayoutAttributes* prevAttr = nil;
            UICollectionViewLayoutAttributes* newAttr = nil;

            if (key.type == UICollectionViewItemTypeDecorationView) {
                UICollectionReusableView* decorView = _allVisibleViewsDict[key];
                prevAttr =
                    [self.collectionViewLayout layoutAttributesForDecorationViewOfKind:decorView.reuseIdentifier atIndexPath:key.indexPath];
                newAttr = [layout layoutAttributesForDecorationViewOfKind:decorView.reuseIdentifier atIndexPath:key.indexPath];
            } else if (key.type == UICollectionViewItemTypeCell) {
                prevAttr = [self.collectionViewLayout layoutAttributesForItemAtIndexPath:key.indexPath];
                newAttr = [layout layoutAttributesForItemAtIndexPath:key.indexPath];
            } else if (key.type == UICollectionViewItemTypeSupplementaryView) {
                UICollectionReusableView* suuplView = _allVisibleViewsDict[key];
                prevAttr =
                    [self.collectionViewLayout layoutAttributesForSupplementaryViewOfKind:suuplView.layoutAttributes.representedElementKind
                                                                              atIndexPath:key.indexPath];
                newAttr = [layout layoutAttributesForSupplementaryViewOfKind:suuplView.layoutAttributes.representedElementKind
                                                                 atIndexPath:key.indexPath];
            }

            NSMutableDictionary* layoutInterchangeDataValue = [NSMutableDictionary dictionary];
            if (prevAttr)
                layoutInterchangeDataValue[@"previousLayoutInfos"] = prevAttr;
            if (newAttr)
                layoutInterchangeDataValue[@"newLayoutInfos"] = newAttr;
            layoutInterchangeData[key] = layoutInterchangeDataValue;
        }

        for (UICollectionViewItemKey* key in [layoutInterchangeData keyEnumerator]) {
            if (key.type == UICollectionViewItemTypeCell) {
                UICollectionViewCell* cell = _allVisibleViewsDict[key];

                if (!cell) {
                    cell = [self createPreparedCellForItemAtIndexPath:key.indexPath
                                                 withLayoutAttributes:layoutInterchangeData[key][@"previousLayoutInfos"]];
                    _allVisibleViewsDict[key] = cell;
                    [self addControlledSubview:cell];
                } else
                    [cell applyLayoutAttributes:layoutInterchangeData[key][@"previousLayoutInfos"]];
            } else if (key.type == UICollectionViewItemTypeSupplementaryView) {
                UICollectionReusableView* view = _allVisibleViewsDict[key];
                if (!view) {
                    UICollectionViewLayoutAttributes* attrs = layoutInterchangeData[key][@"previousLayoutInfos"];
                    view = [self createPreparedSupplementaryViewForElementOfKind:attrs.representedElementKind
                                                                     atIndexPath:attrs.indexPath
                                                            withLayoutAttributes:attrs];
                    _allVisibleViewsDict[key] = view;
                    [self addControlledSubview:view];
                }
            } else if (key.type == UICollectionViewItemTypeDecorationView) {
                UICollectionReusableView* view = _allVisibleViewsDict[key];
                if (!view) {
                    UICollectionViewLayoutAttributes* attrs = layoutInterchangeData[key][@"previousLayoutInfos"];
                    view = [self dequeueReusableOrCreateDecorationViewOfKind:attrs.representedElementKind forIndexPath:attrs.indexPath];
                    _allVisibleViewsDict[key] = view;
                    [self addControlledSubview:view];
                }
            }
        };

        CGRect contentRect = [_collectionViewData collectionViewContentRect];

        void (^applyNewLayoutBlock)(void) = ^{
            NSEnumerator* keys = [layoutInterchangeData keyEnumerator];
            for (UICollectionViewItemKey* key in keys) {
                // TODO: This is most likely not 100% the same time as in UICollectionView. Needs to be investigated.
                UICollectionViewCell* cell = (UICollectionViewCell*)_allVisibleViewsDict[key];
                [cell willTransitionFromLayout:_layout toLayout:layout];
                [cell applyLayoutAttributes:layoutInterchangeData[key][@"newLayoutInfos"]];
                [cell didTransitionFromLayout:_layout toLayout:layout];
            }
        };

        void (^freeUnusedViews)(void) = ^{
            NSMutableSet* toRemove = [NSMutableSet set];
            for (UICollectionViewItemKey* key in [_allVisibleViewsDict keyEnumerator]) {
                if (![newlyVisibleItemsKeys containsObject:key]) {
                    if (key.type == UICollectionViewItemTypeCell) {
                        [self reuseCell:_allVisibleViewsDict[key]];
                        [toRemove addObject:key];
                    } else if (key.type == UICollectionViewItemTypeSupplementaryView) {
                        [self reuseSupplementaryView:_allVisibleViewsDict[key]];
                        [toRemove addObject:key];
                    } else if (key.type == UICollectionViewItemTypeDecorationView) {
                        [self reuseDecorationView:_allVisibleViewsDict[key]];
                        [toRemove addObject:key];
                    }
                }
            }

            for (id key in toRemove)
                [_allVisibleViewsDict removeObjectForKey:key];
        };

        if (animated) {
            [UIView animateWithDuration:.3
                animations:^{
                    _collectionViewFlags.updatingLayout = YES;
                    self.contentOffset = targetOffset;
                    self.contentSize = contentRect.size;
                    applyNewLayoutBlock();
                }
                completion:^(BOOL finished) {
                    freeUnusedViews();
                    _collectionViewFlags.updatingLayout = NO;

                    // layout subviews for updating content offset or size while updating layout
                    if (!CGPointEqualToPoint(self.contentOffset, targetOffset) || !CGSizeEqualToSize(self.contentSize, contentRect.size)) {
                        [self layoutSubviews];
                    }
                }];
        } else {
            self.contentOffset = targetOffset;
            self.contentSize = contentRect.size;
            applyNewLayoutBlock();
            freeUnusedViews();
        }
    }
}

- (void)setCollectionViewLayout:(UICollectionViewLayout*)layout {
    [self setCollectionViewLayout:layout animated:NO];
}

- (id<UICollectionViewDelegate>)delegate {
    return self.collectionViewDelegate;
}

- (void)setDelegate:(id<UICollectionViewDelegate>)delegate {
    self.collectionViewDelegate = delegate;

    //  Managing the Selected Cells
    _collectionViewFlags.delegateShouldSelectItemAtIndexPath =
        (unsigned int)[self.delegate respondsToSelector:@selector(collectionView:shouldSelectItemAtIndexPath:)];
    _collectionViewFlags.delegateDidSelectItemAtIndexPath =
        (unsigned int)[self.delegate respondsToSelector:@selector(collectionView:didSelectItemAtIndexPath:)];
    _collectionViewFlags.delegateShouldDeselectItemAtIndexPath =
        (unsigned int)[self.delegate respondsToSelector:@selector(collectionView:shouldDeselectItemAtIndexPath:)];
    _collectionViewFlags.delegateDidDeselectItemAtIndexPath =
        (unsigned int)[self.delegate respondsToSelector:@selector(collectionView:didDeselectItemAtIndexPath:)];

    //  Managing Cell Highlighting
    _collectionViewFlags.delegateShouldHighlightItemAtIndexPath =
        (unsigned int)[self.delegate respondsToSelector:@selector(collectionView:shouldHighlightItemAtIndexPath:)];
    _collectionViewFlags.delegateDidHighlightItemAtIndexPath =
        (unsigned int)[self.delegate respondsToSelector:@selector(collectionView:didHighlightItemAtIndexPath:)];
    _collectionViewFlags.delegateDidUnhighlightItemAtIndexPath =
        (unsigned int)[self.delegate respondsToSelector:@selector(collectionView:didUnhighlightItemAtIndexPath:)];

    //  Tracking the Removal of Views
    _collectionViewFlags.delegateDidEndDisplayingCell =
        (unsigned int)[self.delegate respondsToSelector:@selector(collectionView:didEndDisplayingCell:forItemAtIndexPath:)];
    _collectionViewFlags.delegateDidEndDisplayingSupplementaryView = (unsigned int)[self.delegate
        respondsToSelector:@selector(collectionView:didEndDisplayingSupplementaryView:forElementOfKind:atIndexPath:)];

    //  Managing Actions for Cells
    _collectionViewFlags.delegateSupportsMenus =
        (unsigned int)[self.delegate respondsToSelector:@selector(collectionView:shouldShowMenuForItemAtIndexPath:)];

    // These aren't present in the flags which is a little strange. Not adding them because that will mess with byte alignment which will
    // affect cross compatibility.
    // The flag names are guesses and are there for documentation purposes.
    // _collectionViewFlags.delegateCanPerformActionForItemAtIndexPath = [self.delegate
    // respondsToSelector:@selector(collectionView:canPerformAction:forItemAtIndexPath:withSender:)];
    // _collectionViewFlags.delegatePerformActionForItemAtIndexPath    = [self.delegate
    // respondsToSelector:@selector(collectionView:performAction:forItemAtIndexPath:withSender:)];
}

// Might be overkill since two are required and two are handled by UICollectionViewData leaving only one flag we actually need to check for
- (void)setDataSource:(id<UICollectionViewDataSource>)dataSource {
    if (dataSource != _dataSource) {
        _dataSource = dataSource;

        //  Getting Item and Section Metrics
        _collectionViewFlags.dataSourceNumberOfSections =
            (unsigned int)[_dataSource respondsToSelector:@selector(numberOfSectionsInCollectionView:)];

        //  Getting Views for Items
        _collectionViewFlags.dataSourceViewForSupplementaryElement =
            (unsigned int)[_dataSource respondsToSelector:@selector(collectionView:viewForSupplementaryElementOfKind:atIndexPath:)];
    }
}

- (BOOL)allowsSelection {
    return _collectionViewFlags.allowsSelection;
}

- (void)setAllowsSelection:(BOOL)allowsSelection {
    _collectionViewFlags.allowsSelection = (unsigned int)allowsSelection;
}

- (BOOL)allowsMultipleSelection {
    return _collectionViewFlags.allowsMultipleSelection;
}

- (void)setAllowsMultipleSelection:(BOOL)allowsMultipleSelection {
    _collectionViewFlags.allowsMultipleSelection = (unsigned int)allowsMultipleSelection;

    // Deselect all objects if allows multiple selection is false
    if (!allowsMultipleSelection && _indexPathsForSelectedItems.count) {
        // Note: Apple's implementation leaves a mostly random item selected. Presumably they
        //       have a good reason for this, but I guess it's just skipping the last or first index.
        for (NSIndexPath* selectedIndexPath in [_indexPathsForSelectedItems copy]) {
            if (_indexPathsForSelectedItems.count == 1)
                continue;
            [self deselectItemAtIndexPath:selectedIndexPath animated:YES notifyDelegate:YES];
        }
    }
}

- (CGRect)visibleBoundRects {
    // in original UICollectionView implementation they
    // check for _visibleBounds and can union self.bounds
    // with this value. Don't know the meaning of _visibleBounds however.
    return self.bounds;
}
///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Private

- (void)invalidateLayout {
    [self.collectionViewLayout invalidateLayout];
    [self.collectionViewData invalidate]; // invalidate layout cache
}

// update currently visible cells, fetches new cells if needed
// TODO: use now parameter.
- (void)updateVisibleCellsNow:(BOOL)now {
    NSArray* layoutAttributesArray = [_collectionViewData layoutAttributesForElementsInRect:self.bounds];

    if (layoutAttributesArray == nil || layoutAttributesArray.count == 0) {
        // If our layout source isn't providing any layout information, we should just
        // stop, otherwise we'll blow away all the currently existing cells.
        return;
    }

    // create ItemKey/Attributes dictionary
    NSMutableDictionary* itemKeysToAddDict = [NSMutableDictionary dictionary];

    // Add new cells.
    for (UICollectionViewLayoutAttributes* layoutAttributes in layoutAttributesArray) {
        UICollectionViewItemKey* itemKey = [UICollectionViewItemKey collectionItemKeyForLayoutAttributes:layoutAttributes];
        itemKeysToAddDict[itemKey] = layoutAttributes;

        // check if cell is in visible dict; add it if not.
        UICollectionReusableView* view = _allVisibleViewsDict[itemKey];
        if (!view) {
            if (itemKey.type == UICollectionViewItemTypeCell) {
                view = [self createPreparedCellForItemAtIndexPath:itemKey.indexPath withLayoutAttributes:layoutAttributes];

            } else if (itemKey.type == UICollectionViewItemTypeSupplementaryView) {
                view = [self createPreparedSupplementaryViewForElementOfKind:layoutAttributes.representedElementKind
                                                                 atIndexPath:layoutAttributes.indexPath
                                                        withLayoutAttributes:layoutAttributes];
            } else if (itemKey.type == UICollectionViewItemTypeDecorationView) {
                view = [self dequeueReusableOrCreateDecorationViewOfKind:layoutAttributes.representedElementKind
                                                            forIndexPath:layoutAttributes.indexPath];
            }

            // Supplementary views are optional
            if (view) {
                _allVisibleViewsDict[itemKey] = view;
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
    NSMutableSet* allVisibleItemKeys = [NSMutableSet setWithArray:[_allVisibleViewsDict allKeys]];
    [allVisibleItemKeys minusSet:[NSSet setWithArray:[itemKeysToAddDict allKeys]]];

    // Finally remove views that have not been processed and prepare them for re-use.
    for (UICollectionViewItemKey* itemKey in allVisibleItemKeys) {
        UICollectionReusableView* reusableView = _allVisibleViewsDict[itemKey];
        if (reusableView) {
            [reusableView removeFromSuperview];
            [_allVisibleViewsDict removeObjectForKey:itemKey];
            if (itemKey.type == UICollectionViewItemTypeCell) {
                if (_collectionViewFlags.delegateDidEndDisplayingCell) {
                    [self.delegate collectionView:self
                             didEndDisplayingCell:(UICollectionViewCell*)reusableView
                               forItemAtIndexPath:itemKey.indexPath];
                }
                [self reuseCell:(UICollectionViewCell*)reusableView];
            } else if (itemKey.type == UICollectionViewItemTypeSupplementaryView) {
                if (_collectionViewFlags.delegateDidEndDisplayingSupplementaryView) {
                    [self.delegate collectionView:self
                        didEndDisplayingSupplementaryView:reusableView
                                         forElementOfKind:itemKey.identifier
                                              atIndexPath:itemKey.indexPath];
                }
                [self reuseSupplementaryView:reusableView];
            } else if (itemKey.type == UICollectionViewItemTypeDecorationView) {
                [self reuseDecorationView:reusableView];
            }
        }
    }
}

// fetches a cell from the dataSource and sets the layoutAttributes
- (UICollectionViewCell*)createPreparedCellForItemAtIndexPath:(NSIndexPath*)indexPath
                                         withLayoutAttributes:(UICollectionViewLayoutAttributes*)layoutAttributes {
    UICollectionViewCell* cell = [self.dataSource collectionView:self cellForItemAtIndexPath:indexPath];

    // Apply attributes
    [cell applyLayoutAttributes:layoutAttributes];

    // reset selected/highlight state
    [cell setHighlighted:[_indexPathsForHighlightedItems containsObject:indexPath]];
    [cell setSelected:[_indexPathsForSelectedItems containsObject:indexPath]];

    // voiceover support
    cell.isAccessibilityElement = YES;

    return cell;
}

- (UICollectionReusableView*)createPreparedSupplementaryViewForElementOfKind:(NSString*)kind
                                                                 atIndexPath:(NSIndexPath*)indexPath
                                                        withLayoutAttributes:(UICollectionViewLayoutAttributes*)layoutAttributes {
    if (_collectionViewFlags.dataSourceViewForSupplementaryElement) {
        UICollectionReusableView* view = [self.dataSource collectionView:self viewForSupplementaryElementOfKind:kind atIndexPath:indexPath];
        [view applyLayoutAttributes:layoutAttributes];
        return view;
    }
    return nil;
}

// @steipete optimization
- (void)queueReusableView:(UICollectionReusableView*)reusableView inQueue:(NSMutableDictionary*)queue withIdentifier:(NSString*)identifier {
    NSParameterAssert(identifier.length > 0);

    [reusableView removeFromSuperview];
    [reusableView prepareForReuse];

    // enqueue cell
    NSMutableArray* reuseableViews = queue[identifier];
    if (!reuseableViews) {
        reuseableViews = [NSMutableArray array];
        queue[identifier] = reuseableViews;
    }
    [reuseableViews addObject:reusableView];
}

// enqueue cell for reuse
- (void)reuseCell:(UICollectionViewCell*)cell {
    [self queueReusableView:cell inQueue:_cellReuseQueues withIdentifier:cell.reuseIdentifier];
}

// enqueue supplementary view for reuse
- (void)reuseSupplementaryView:(UICollectionReusableView*)supplementaryView {
    NSString* kindAndIdentifier =
        [NSString stringWithFormat:@"%@/%@", supplementaryView.layoutAttributes.elementKind, supplementaryView.reuseIdentifier];
    [self queueReusableView:supplementaryView inQueue:_supplementaryViewReuseQueues withIdentifier:kindAndIdentifier];
}

// enqueue decoration view for reuse
- (void)reuseDecorationView:(UICollectionReusableView*)decorationView {
    [self queueReusableView:decorationView inQueue:_decorationViewReuseQueues withIdentifier:decorationView.reuseIdentifier];
}

- (void)addControlledSubview:(UICollectionReusableView*)subview {
    // avoids placing views above the scroll indicator
    // If the collection view is not displaying scrollIndicators then self.subviews.count can be 0.
    // We take the max to ensure we insert at a non negative index because a negative index will silently fail to insert the view
    NSInteger insertionIndex = MAX((NSInteger)(self.subviews.count - (self.dragging ? 1 : 0)), 0);
    [self insertSubview:subview atIndex:insertionIndex];
    UIView* scrollIndicatorView = nil;
    if (self.dragging) {
        scrollIndicatorView = [self.subviews lastObject];
    }

    NSMutableArray* floatingViews = [[NSMutableArray alloc] init];
    for (UIView* uiView in self.subviews) {
        if ([uiView isKindOfClass:UICollectionReusableView.class]) {
            UICollectionReusableView* reusableView = (UICollectionReusableView*)uiView;
            if (([[reusableView layoutAttributes] zIndex] > 0) ||
                ([[reusableView layoutAttributes] isPinnedSupplementaryView])) {
                [floatingViews addObject:uiView];
            }
        }
    }

    [floatingViews sortUsingComparator:^NSComparisonResult(UICollectionReusableView* obj1, UICollectionReusableView* obj2) {
        BOOL isSupplementary1 = [[obj1 layoutAttributes] isPinnedSupplementaryView];
        BOOL isSupplementary2 = [[obj2 layoutAttributes] isPinnedSupplementaryView];
        if (isSupplementary1 != isSupplementary2) {
            if (isSupplementary1) {
                return (NSComparisonResult)NSOrderedDescending;
            } else {
                return (NSComparisonResult)NSOrderedAscending;
            }
        }

        CGFloat z1 = [[obj1 layoutAttributes] zIndex];
        CGFloat z2 = [[obj2 layoutAttributes] zIndex];
        if (z1 > z2) {
            return (NSComparisonResult)NSOrderedDescending;
        } else if (z1 < z2) {
            return (NSComparisonResult)NSOrderedAscending;
        } else {
            return (NSComparisonResult)NSOrderedSame;
        }
    }];

    for (UICollectionReusableView* uiView in floatingViews) {
        [self bringSubviewToFront:uiView];
    }

    if (floatingViews.count && scrollIndicatorView) {
        [self bringSubviewToFront:scrollIndicatorView];
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Updating grid internal functionality

- (void)suspendReloads {
    _reloadingSuspendedCount++;
}

- (void)resumeReloads {
    if (0 < _reloadingSuspendedCount)
        _reloadingSuspendedCount--;
}

- (NSMutableArray*)arrayForUpdateAction:(UICollectionUpdateAction)updateAction {
    NSMutableArray* updateActions = nil;

    switch (updateAction) {
        case UICollectionUpdateActionInsert:
            if (!_insertItems)
                _insertItems = [NSMutableArray new];
            updateActions = _insertItems;
            break;
        case UICollectionUpdateActionDelete:
            if (!_deleteItems)
                _deleteItems = [NSMutableArray new];
            updateActions = _deleteItems;
            break;
        case UICollectionUpdateActionMove:
            if (!_moveItems)
                _moveItems = [NSMutableArray new];
            updateActions = _moveItems;
            break;
        case UICollectionUpdateActionReload:
            if (!_reloadItems)
                _reloadItems = [NSMutableArray new];
            updateActions = _reloadItems;
            break;
        default:
            break;
    }
    return updateActions;
}

- (void)prepareLayoutForUpdates {
    NSMutableArray* array = [[NSMutableArray alloc] init];
    [array addObjectsFromArray:[_originalDeleteItems sortedArrayUsingSelector:@selector(inverseCompareIndexPaths:)]];
    [array addObjectsFromArray:[_originalInsertItems sortedArrayUsingSelector:@selector(compareIndexPaths:)]];
    [array addObjectsFromArray:[_reloadItems sortedArrayUsingSelector:@selector(compareIndexPaths:)]];
    [array addObjectsFromArray:[_moveItems sortedArrayUsingSelector:@selector(compareIndexPaths:)]];
    [_layout prepareForCollectionViewUpdates:array];
}

- (void)updateWithItems:(NSArray*)items {
    [self prepareLayoutForUpdates];

    NSMutableArray* animations = [[NSMutableArray alloc] init];
    NSMutableDictionary* newAllVisibleView = [[NSMutableDictionary alloc] init];

    NSMutableDictionary* viewsToRemove = [NSMutableDictionary dictionaryWithObjectsAndKeys:[NSMutableArray array],
                                                                                           @(UICollectionViewItemTypeCell),
                                                                                           [NSMutableArray array],
                                                                                           @(UICollectionViewItemTypeDecorationView),
                                                                                           [NSMutableArray array],
                                                                                           @(UICollectionViewItemTypeSupplementaryView),
                                                                                           nil];

    for (UICollectionViewUpdateItem* updateItem in items) {
        if (updateItem.isSectionOperation && updateItem.updateAction != UICollectionUpdateActionDelete)
            continue;
        if (updateItem.isSectionOperation && updateItem.updateAction == UICollectionUpdateActionDelete) {
            NSInteger numberOfBeforeSection = [_update[@"oldModel"] numberOfItemsInSection:updateItem.indexPathBeforeUpdate.section];
            for (NSInteger i = 0; i < numberOfBeforeSection; i++) {
                NSIndexPath* indexPath = [NSIndexPath indexPathForItem:i inSection:updateItem.indexPathBeforeUpdate.section];

                UICollectionViewLayoutAttributes* finalAttrs = [_layout finalLayoutAttributesForDisappearingItemAtIndexPath:indexPath];
                UICollectionViewItemKey* key = [UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:indexPath];
                UICollectionReusableView* view = _allVisibleViewsDict[key];
                if (view) {
                    UICollectionViewLayoutAttributes* startAttrs = view.layoutAttributes;

                    if (!finalAttrs) {
                        finalAttrs = [startAttrs copy];
                        finalAttrs.alpha = 0;
                    }
                    [animations addObject:@{ @"view" : view, @"previousLayoutInfos" : startAttrs, @"newLayoutInfos" : finalAttrs }];

                    [_allVisibleViewsDict removeObjectForKey:key];

                    [(NSMutableArray*)viewsToRemove[@(key.type)] addObject:view];
                }
            }
            continue;
        }

        if (updateItem.updateAction == UICollectionUpdateActionDelete) {
            NSIndexPath* indexPath = updateItem.indexPathBeforeUpdate;

            UICollectionViewLayoutAttributes* finalAttrs = [_layout finalLayoutAttributesForDisappearingItemAtIndexPath:indexPath];
            UICollectionViewItemKey* key = [UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:indexPath];
            UICollectionReusableView* view = _allVisibleViewsDict[key];
            if (view) {
                UICollectionViewLayoutAttributes* startAttrs = view.layoutAttributes;

                if (!finalAttrs) {
                    finalAttrs = [startAttrs copy];
                    finalAttrs.alpha = 0;
                }
                [animations addObject:@{ @"view" : view, @"previousLayoutInfos" : startAttrs, @"newLayoutInfos" : finalAttrs }];

                [_allVisibleViewsDict removeObjectForKey:key];

                [(NSMutableArray*)viewsToRemove[@(key.type)] addObject:view];
            }
        } else if (updateItem.updateAction == UICollectionUpdateActionInsert) {
            NSIndexPath* indexPath = updateItem.indexPathAfterUpdate;
            UICollectionViewItemKey* key = [UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:indexPath];
            UICollectionViewLayoutAttributes* startAttrs = [_layout initialLayoutAttributesForAppearingItemAtIndexPath:indexPath];
            UICollectionViewLayoutAttributes* finalAttrs = [_layout layoutAttributesForItemAtIndexPath:indexPath];

            CGRect startRect = startAttrs.frame;
            CGRect finalRect = finalAttrs.frame;

            if (CGRectIntersectsRect(self.visibleBoundRects, startRect) || CGRectIntersectsRect(self.visibleBoundRects, finalRect)) {
                if (!startAttrs) {
                    startAttrs = [finalAttrs copy];
                    startAttrs.alpha = 0;
                }

                UICollectionReusableView* view = [self createPreparedCellForItemAtIndexPath:indexPath withLayoutAttributes:startAttrs];
                [self addControlledSubview:view];

                newAllVisibleView[key] = view;
                [animations addObject:@{ @"view" : view, @"previousLayoutInfos" : startAttrs, @"newLayoutInfos" : finalAttrs }];
            }
        } else if (updateItem.updateAction == UICollectionUpdateActionMove) {
            NSIndexPath* indexPathBefore = updateItem.indexPathBeforeUpdate;
            NSIndexPath* indexPathAfter = updateItem.indexPathAfterUpdate;

            UICollectionViewItemKey* keyBefore = [UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:indexPathBefore];
            UICollectionViewItemKey* keyAfter = [UICollectionViewItemKey collectionItemKeyForCellWithIndexPath:indexPathAfter];
            UICollectionReusableView* view = _allVisibleViewsDict[keyBefore];

            UICollectionViewLayoutAttributes* startAttrs = nil;
            UICollectionViewLayoutAttributes* finalAttrs = [_layout layoutAttributesForItemAtIndexPath:indexPathAfter];

            if (view) {
                startAttrs = view.layoutAttributes;
                [_allVisibleViewsDict removeObjectForKey:keyBefore];
                newAllVisibleView[keyAfter] = view;
            } else {
                startAttrs = [finalAttrs copy];
                startAttrs.alpha = 0;
                view = [self createPreparedCellForItemAtIndexPath:indexPathAfter withLayoutAttributes:startAttrs];
                [self addControlledSubview:view];
                newAllVisibleView[keyAfter] = view;
            }

            [animations addObject:@{ @"view" : view, @"previousLayoutInfos" : startAttrs, @"newLayoutInfos" : finalAttrs }];
        }
    }

    for (UICollectionViewItemKey* key in [_allVisibleViewsDict keyEnumerator]) {
        UICollectionReusableView* view = _allVisibleViewsDict[key];

        if (key.type == UICollectionViewItemTypeCell) {
            NSUInteger oldGlobalIndex = [_update[@"oldModel"] globalIndexForItemAtIndexPath:key.indexPath];
            NSArray* oldToNewIndexMap = _update[@"oldToNewIndexMap"];
            NSUInteger newGlobalIndex = NSNotFound;
            if (NSNotFound != oldGlobalIndex && oldGlobalIndex < oldToNewIndexMap.count) {
                newGlobalIndex = [oldToNewIndexMap[oldGlobalIndex] unsignedIntegerValue];
            }
            NSIndexPath* newIndexPath =
                newGlobalIndex == NSNotFound ? nil : [_update[@"newModel"] indexPathForItemAtGlobalIndex:(int)newGlobalIndex];
            NSIndexPath* oldIndexPath =
                oldGlobalIndex == NSNotFound ? nil : [_update[@"oldModel"] indexPathForItemAtGlobalIndex:(int)oldGlobalIndex];

            if (newIndexPath) {
                UICollectionViewLayoutAttributes* startAttrs = nil;
                UICollectionViewLayoutAttributes* finalAttrs = nil;

                startAttrs = [_layout initialLayoutAttributesForAppearingItemAtIndexPath:oldIndexPath];
                finalAttrs = [_layout layoutAttributesForItemAtIndexPath:newIndexPath];

                NSMutableDictionary* dic = [NSMutableDictionary dictionaryWithDictionary:@{ @"view" : view }];
                if (startAttrs)
                    dic[@"previousLayoutInfos"] = startAttrs;
                if (finalAttrs)
                    dic[@"newLayoutInfos"] = finalAttrs;

                [animations addObject:dic];
                UICollectionViewItemKey* newKey = [key copy];
                [newKey setIndexPath:newIndexPath];
                newAllVisibleView[newKey] = view;
            }
        } else if (key.type == UICollectionViewItemTypeSupplementaryView) {
            UICollectionViewLayoutAttributes* startAttrs = nil;
            UICollectionViewLayoutAttributes* finalAttrs = nil;

            startAttrs = view.layoutAttributes;
            finalAttrs =
                [_layout layoutAttributesForSupplementaryViewOfKind:view.layoutAttributes.representedElementKind atIndexPath:key.indexPath];

            NSMutableDictionary* dic = [NSMutableDictionary dictionaryWithDictionary:@{ @"view" : view }];
            if (startAttrs)
                dic[@"previousLayoutInfos"] = startAttrs;
            if (finalAttrs)
                dic[@"newLayoutInfos"] = finalAttrs;

            [animations addObject:dic];
            UICollectionViewItemKey* newKey = [key copy];
            newAllVisibleView[newKey] = view;
        }
    }
    NSArray* allNewlyVisibleItems = [_layout layoutAttributesForElementsInRect:self.visibleBoundRects];
    for (UICollectionViewLayoutAttributes* attrs in allNewlyVisibleItems) {
        UICollectionViewItemKey* key = [UICollectionViewItemKey collectionItemKeyForLayoutAttributes:attrs];

        if (key.type == UICollectionViewItemTypeCell && ![[newAllVisibleView allKeys] containsObject:key]) {
            UICollectionViewLayoutAttributes* startAttrs = [_layout initialLayoutAttributesForAppearingItemAtIndexPath:attrs.indexPath];

            UICollectionReusableView* view = [self createPreparedCellForItemAtIndexPath:attrs.indexPath withLayoutAttributes:startAttrs];
            [self addControlledSubview:view];
            newAllVisibleView[key] = view;

            [animations addObject:@{ @"view" : view, @"previousLayoutInfos" : startAttrs ? startAttrs : attrs, @"newLayoutInfos" : attrs }];
        }
    }

    // In here I think it doesn't need the animation but the transaction, it would cause some issue of display.
    // I resolve the bug when user insert the new sections, the cell will display with a blink animation at the first operation.
    // But I don't know why the next operation wouldn't reproduction in the pre version.
    _allVisibleViewsDict = newAllVisibleView;

    for (NSDictionary* animation in animations) {
        UICollectionReusableView* view = animation[@"view"];
        UICollectionViewLayoutAttributes* attr = animation[@"previousLayoutInfos"];
        [view applyLayoutAttributes:attr];
    };

    _collectionViewFlags.updatingLayout = YES;

    [CATransaction begin];
    [CATransaction setAnimationDuration:0];
    [CATransaction setCompletionBlock:^{
        // Iterate through all the views that we are going to remove.
        [viewsToRemove enumerateKeysAndObjectsUsingBlock:^(NSNumber* keyObj, NSArray* views, BOOL* stop) {
            UICollectionViewItemType type = (UICollectionViewItemType)[keyObj unsignedIntegerValue];
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
            _updateCompletionHandler(YES);
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
}

- (void)setupCellAnimations {
    [self updateVisibleCellsNow:YES];
    [self suspendReloads];
    _collectionViewFlags.updating = YES;
}

- (void)endItemAnimations {
    _updateCount++;
    UICollectionViewData* oldCollectionViewData = _collectionViewData;
    _collectionViewData = [[UICollectionViewData alloc] initWithCollectionView:self layout:_layout];

    [_layout invalidateLayout];
    [_collectionViewData prepareToLoadData];

    NSMutableArray* someMutableArr1 = [[NSMutableArray alloc] init];

    NSArray* removeUpdateItems =
        [[self arrayForUpdateAction:UICollectionUpdateActionDelete] sortedArrayUsingSelector:@selector(inverseCompareIndexPaths:)];

    NSArray* insertUpdateItems =
        [[self arrayForUpdateAction:UICollectionUpdateActionInsert] sortedArrayUsingSelector:@selector(compareIndexPaths:)];

    NSMutableArray* sortedMutableReloadItems = [[_reloadItems sortedArrayUsingSelector:@selector(compareIndexPaths:)] mutableCopy];
    NSMutableArray* sortedMutableMoveItems = [[_moveItems sortedArrayUsingSelector:@selector(compareIndexPaths:)] mutableCopy];

    _originalDeleteItems = [removeUpdateItems copy];
    _originalInsertItems = [insertUpdateItems copy];

    NSMutableArray* someMutableArr2 = [[NSMutableArray alloc] init];
    NSMutableArray* someMutableArr3 = [[NSMutableArray alloc] init];
    NSMutableDictionary* operations = [[NSMutableDictionary alloc] init];

    for (UICollectionViewUpdateItem* updateItem in sortedMutableReloadItems) {
        NSAssert(updateItem.indexPathBeforeUpdate.section < [oldCollectionViewData numberOfSections],
                 @"attempt to reload item (%@) that doesn't exist (there are only %ld sections before update)",
                 updateItem.indexPathBeforeUpdate,
                 (long)[oldCollectionViewData numberOfSections]);

        if (updateItem.indexPathBeforeUpdate.item != NSNotFound) {
            NSAssert(updateItem.indexPathBeforeUpdate.item <
                         [oldCollectionViewData numberOfItemsInSection:updateItem.indexPathBeforeUpdate.section],
                     @"attempt to reload item (%@) that doesn't exist (there are only %ld items in section %ld before update)",
                     updateItem.indexPathBeforeUpdate,
                     (long)[oldCollectionViewData numberOfItemsInSection:updateItem.indexPathBeforeUpdate.section],
                     (long)updateItem.indexPathBeforeUpdate.section);
        }

        [someMutableArr2 addObject:[[UICollectionViewUpdateItem alloc] initWithAction:UICollectionUpdateActionDelete
                                                                         forIndexPath:updateItem.indexPathBeforeUpdate]];
        [someMutableArr3 addObject:[[UICollectionViewUpdateItem alloc] initWithAction:UICollectionUpdateActionInsert
                                                                         forIndexPath:updateItem.indexPathAfterUpdate]];
    }

    NSMutableArray* sortedDeletedMutableItems = [[_deleteItems sortedArrayUsingSelector:@selector(inverseCompareIndexPaths:)] mutableCopy];
    NSMutableArray* sortedInsertMutableItems = [[_insertItems sortedArrayUsingSelector:@selector(compareIndexPaths:)] mutableCopy];

    for (UICollectionViewUpdateItem* deleteItem in sortedDeletedMutableItems) {
        if ([deleteItem isSectionOperation]) {
            NSAssert(deleteItem.indexPathBeforeUpdate.section < [oldCollectionViewData numberOfSections],
                     @"attempt to delete section (%ld) that doesn't exist (there are only %ld sections before update)",
                     (long)deleteItem.indexPathBeforeUpdate.section,
                     (long)[oldCollectionViewData numberOfSections]);

            for (UICollectionViewUpdateItem* moveItem in sortedMutableMoveItems) {
                if (moveItem.indexPathBeforeUpdate.section == deleteItem.indexPathBeforeUpdate.section) {
                    if (moveItem.isSectionOperation)
                        NSAssert(NO,
                                 @"attempt to delete and move from the same section %ld",
                                 (long)deleteItem.indexPathBeforeUpdate.section);
                    else
                        NSAssert(NO, @"attempt to delete and move from the same section (%@)", moveItem.indexPathBeforeUpdate);
                }
            }
        } else {
            NSAssert(deleteItem.indexPathBeforeUpdate.section < [oldCollectionViewData numberOfSections],
                     @"attempt to delete item (%@) that doesn't exist (there are only %ld sections before update)",
                     deleteItem.indexPathBeforeUpdate,
                     (long)[oldCollectionViewData numberOfSections]);
            NSAssert(deleteItem.indexPathBeforeUpdate.item <
                         [oldCollectionViewData numberOfItemsInSection:deleteItem.indexPathBeforeUpdate.section],
                     @"attempt to delete item (%@) that doesn't exist (there are only %ld items in section%ld before update)",
                     deleteItem.indexPathBeforeUpdate,
                     (long)[oldCollectionViewData numberOfItemsInSection:deleteItem.indexPathBeforeUpdate.section],
                     (long)deleteItem.indexPathBeforeUpdate.section);

            for (UICollectionViewUpdateItem* moveItem in sortedMutableMoveItems) {
                NSAssert(![deleteItem.indexPathBeforeUpdate isEqual:moveItem.indexPathBeforeUpdate],
                         @"attempt to delete and move the same item (%@)",
                         deleteItem.indexPathBeforeUpdate);
            }

            if (!operations[@(deleteItem.indexPathBeforeUpdate.section)])
                operations[@(deleteItem.indexPathBeforeUpdate.section)] = [NSMutableDictionary dictionary];

            operations[@(deleteItem.indexPathBeforeUpdate.section)][@"deleted"] =
                @([operations[@(deleteItem.indexPathBeforeUpdate.section)][@"deleted"] intValue] + 1);
        }
    }

    for (NSUInteger i = 0; i < sortedInsertMutableItems.count; i++) {
        UICollectionViewUpdateItem* insertItem = sortedInsertMutableItems[i];
        NSIndexPath* indexPath = insertItem.indexPathAfterUpdate;

        BOOL sectionOperation = [insertItem isSectionOperation];
        if (sectionOperation) {
            NSAssert([indexPath section] < [_collectionViewData numberOfSections],
                     @"attempt to insert %ld but there are only %ld sections after update",
                     (long)[indexPath section],
                     (long)[_collectionViewData numberOfSections]);

            for (UICollectionViewUpdateItem* moveItem in sortedMutableMoveItems) {
                if ([moveItem.indexPathAfterUpdate isEqual:indexPath]) {
                    if (moveItem.isSectionOperation)
                        NSAssert(NO, @"attempt to perform an insert and a move to the same section (%ld)", (long)indexPath.section);
                }
            }

            NSUInteger j = i + 1;
            while (j < sortedInsertMutableItems.count) {
                UICollectionViewUpdateItem* nextInsertItem = sortedInsertMutableItems[j];

                if (nextInsertItem.indexPathAfterUpdate.section == indexPath.section) {
                    NSAssert(nextInsertItem.indexPathAfterUpdate.item < [_collectionViewData numberOfItemsInSection:indexPath.section],
                             @"attempt to insert item %ld into section %ld, but there are only %ld items in section %ld after the update",
                             (long)nextInsertItem.indexPathAfterUpdate.item,
                             (long)indexPath.section,
                             (long)[_collectionViewData numberOfItemsInSection:indexPath.section],
                             (long)indexPath.section);
                    [sortedInsertMutableItems removeObjectAtIndex:j];
                } else
                    break;
            }
        } else {
            NSAssert(indexPath.item < [_collectionViewData numberOfItemsInSection:indexPath.section],
                     @"attempt to insert item to (%@) but there are only %ld items in section %ld after update",
                     indexPath,
                     (long)[_collectionViewData numberOfItemsInSection:indexPath.section],
                     (long)indexPath.section);

            if (!operations[@(indexPath.section)])
                operations[@(indexPath.section)] = [NSMutableDictionary dictionary];

            operations[@(indexPath.section)][@"inserted"] = @([operations[@(indexPath.section)][@"inserted"] intValue] + 1);
        }
    }

    for (UICollectionViewUpdateItem* sortedItem in sortedMutableMoveItems) {
        if (sortedItem.isSectionOperation) {
            NSAssert(sortedItem.indexPathBeforeUpdate.section < [oldCollectionViewData numberOfSections],
                     @"attempt to move section (%ld) that doesn't exist (%ld sections before update)",
                     (long)sortedItem.indexPathBeforeUpdate.section,
                     (long)[oldCollectionViewData numberOfSections]);
            NSAssert(sortedItem.indexPathAfterUpdate.section < [_collectionViewData numberOfSections],
                     @"attempt to move section to %ld but there are only %ld sections after update",
                     (long)sortedItem.indexPathAfterUpdate.section,
                     (long)[_collectionViewData numberOfSections]);
        } else {
            NSAssert(sortedItem.indexPathBeforeUpdate.section < [oldCollectionViewData numberOfSections],
                     @"attempt to move item (%@) that doesn't exist (%ld sections before update)",
                     sortedItem,
                     (long)[oldCollectionViewData numberOfSections]);
            NSAssert(sortedItem.indexPathBeforeUpdate.item <
                         [oldCollectionViewData numberOfItemsInSection:sortedItem.indexPathBeforeUpdate.section],
                     @"attempt to move item (%@) that doesn't exist (%ld items in section %ld before update)",
                     sortedItem,
                     (long)[oldCollectionViewData numberOfItemsInSection:sortedItem.indexPathBeforeUpdate.section],
                     (long)sortedItem.indexPathBeforeUpdate.section);

            NSAssert(sortedItem.indexPathAfterUpdate.section < [_collectionViewData numberOfSections],
                     @"attempt to move item to (%@) but there are only %ld sections after update",
                     sortedItem.indexPathAfterUpdate,
                     (long)[_collectionViewData numberOfSections]);
            NSAssert(sortedItem.indexPathAfterUpdate.item <
                         [_collectionViewData numberOfItemsInSection:sortedItem.indexPathAfterUpdate.section],
                     @"attempt to move item to (%@) but there are only %ld items in section %ld after update",
                     sortedItem,
                     (long)[_collectionViewData numberOfItemsInSection:sortedItem.indexPathAfterUpdate.section],
                     (long)sortedItem.indexPathAfterUpdate.section);
        }

        if (!operations[@(sortedItem.indexPathBeforeUpdate.section)])
            operations[@(sortedItem.indexPathBeforeUpdate.section)] = [NSMutableDictionary dictionary];
        if (!operations[@(sortedItem.indexPathAfterUpdate.section)])
            operations[@(sortedItem.indexPathAfterUpdate.section)] = [NSMutableDictionary dictionary];

        operations[@(sortedItem.indexPathBeforeUpdate.section)][@"movedOut"] =
            @([operations[@(sortedItem.indexPathBeforeUpdate.section)][@"movedOut"] intValue] + 1);

        operations[@(sortedItem.indexPathAfterUpdate.section)][@"movedIn"] =
            @([operations[@(sortedItem.indexPathAfterUpdate.section)][@"movedIn"] intValue] + 1);
    }

#if !defined NS_BLOCK_ASSERTIONS
    for (NSNumber* sectionKey in [operations keyEnumerator]) {
        NSInteger section = [sectionKey integerValue];

        NSInteger insertedCount = [operations[sectionKey][@"inserted"] integerValue];
        NSInteger deletedCount = [operations[sectionKey][@"deleted"] integerValue];
        NSInteger movedInCount = [operations[sectionKey][@"movedIn"] integerValue];
        NSInteger movedOutCount = [operations[sectionKey][@"movedOut"] integerValue];

        NSAssert(
            [oldCollectionViewData numberOfItemsInSection:section] + insertedCount - deletedCount + movedInCount - movedOutCount ==
                [_collectionViewData numberOfItemsInSection:section],
            @"invalid update in section %ld: number of items after update (%ld) should be equal to the number of items before update (%ld) "
             "plus count of inserted items (%ld), minus count of deleted items (%ld), plus count of items moved in (%ld), minus count of "
             "items moved out (%ld)",
            (long)section,
            (long)[_collectionViewData numberOfItemsInSection:section],
            (long)[oldCollectionViewData numberOfItemsInSection:section],
            (long)insertedCount,
            (long)deletedCount,
            (long)movedInCount,
            (long)movedOutCount);
    }
#endif

    [someMutableArr2 addObjectsFromArray:sortedDeletedMutableItems];
    [someMutableArr3 addObjectsFromArray:sortedInsertMutableItems];
    [someMutableArr1 addObjectsFromArray:[someMutableArr2 sortedArrayUsingSelector:@selector(inverseCompareIndexPaths:)]];
    [someMutableArr1 addObjectsFromArray:sortedMutableMoveItems];
    [someMutableArr1 addObjectsFromArray:[someMutableArr3 sortedArrayUsingSelector:@selector(compareIndexPaths:)]];

    NSMutableArray* layoutUpdateItems = [[NSMutableArray alloc] init];

    [layoutUpdateItems addObjectsFromArray:sortedDeletedMutableItems];
    [layoutUpdateItems addObjectsFromArray:sortedMutableMoveItems];
    [layoutUpdateItems addObjectsFromArray:sortedInsertMutableItems];

    NSMutableArray* newModel = [NSMutableArray array];
    for (NSInteger i = 0; i < [oldCollectionViewData numberOfSections]; i++) {
        NSMutableArray* sectionArr = [NSMutableArray array];
        for (NSInteger j = 0; j < [oldCollectionViewData numberOfItemsInSection:i]; j++)
            [sectionArr addObject:@([oldCollectionViewData globalIndexForItemAtIndexPath:[NSIndexPath indexPathForItem:j inSection:i]])];
        [newModel addObject:sectionArr];
    }

    for (UICollectionViewUpdateItem* updateItem in layoutUpdateItems) {
        switch (updateItem.updateAction) {
            case UICollectionUpdateActionDelete: {
                if (updateItem.isSectionOperation) {
                    // section updates are ignored anyway in animation code. If not commented, mixing rows and section deletion causes crash
                    // in else below
                    // [newModel removeObjectAtIndex:updateItem.indexPathBeforeUpdate.section];
                } else {
                    [(NSMutableArray*)newModel[(NSUInteger)updateItem.indexPathBeforeUpdate.section]
                        removeObjectAtIndex:(NSUInteger)updateItem.indexPathBeforeUpdate.item];
                }
            } break;
            case UICollectionUpdateActionInsert: {
                if (updateItem.isSectionOperation) {
                    [newModel insertObject:[[NSMutableArray alloc] init] atIndex:(NSUInteger)updateItem.indexPathAfterUpdate.section];
                } else {
                    [(NSMutableArray*)newModel[(NSUInteger)updateItem.indexPathAfterUpdate.section]
                        insertObject:@(NSNotFound)
                             atIndex:(NSUInteger)updateItem.indexPathAfterUpdate.item];
                }
            } break;

            case UICollectionUpdateActionMove: {
                if (updateItem.isSectionOperation) {
                    id section = newModel[(NSUInteger)updateItem.indexPathBeforeUpdate.section];
                    [newModel insertObject:section atIndex:(NSUInteger)updateItem.indexPathAfterUpdate.section];
                } else {
                    id object = @([oldCollectionViewData globalIndexForItemAtIndexPath:updateItem.indexPathBeforeUpdate]);
                    [newModel[(NSUInteger)updateItem.indexPathBeforeUpdate.section] removeObject:object];
                    [newModel[(NSUInteger)updateItem.indexPathAfterUpdate.section]
                        insertObject:object
                             atIndex:(NSUInteger)updateItem.indexPathAfterUpdate.item];
                }
            } break;
            default:
                break;
        }
    }

    NSMutableArray* oldToNewMap = [NSMutableArray arrayWithCapacity:(NSUInteger)[oldCollectionViewData numberOfItems]];
    NSMutableArray* newToOldMap = [NSMutableArray arrayWithCapacity:(NSUInteger)[_collectionViewData numberOfItems]];

    for (NSInteger i = 0; i < [oldCollectionViewData numberOfItems]; i++)
        [oldToNewMap addObject:@(NSNotFound)];

    for (NSInteger i = 0; i < [_collectionViewData numberOfItems]; i++)
        [newToOldMap addObject:@(NSNotFound)];

    for (NSUInteger i = 0; i < newModel.count; i++) {
        NSMutableArray* section = newModel[i];
        for (NSUInteger j = 0; j < section.count; j++) {
            NSUInteger newGlobalIndex =
                [_collectionViewData globalIndexForItemAtIndexPath:[NSIndexPath indexPathForItem:(NSInteger)j inSection:(NSInteger)i]];
            if ([section[j] integerValue] != NSNotFound)
                oldToNewMap[[section[j] unsignedIntegerValue]] = @(newGlobalIndex);
            if (newGlobalIndex != NSNotFound)
                newToOldMap[newGlobalIndex] = section[j];
        }
    }

    _update = @{
        @"oldModel" : oldCollectionViewData,
        @"newModel" : _collectionViewData,
        @"oldToNewIndexMap" : oldToNewMap,
        @"newToOldIndexMap" : newToOldMap
    };

    [self updateWithItems:someMutableArr1];

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
}

- (void)updateRowsAtIndexPaths:(NSArray*)indexPaths updateAction:(UICollectionUpdateAction)updateAction {
    BOOL updating = _collectionViewFlags.updating;
    if (!updating)
        [self setupCellAnimations];

    NSMutableArray* array = [self arrayForUpdateAction:updateAction]; // returns appropriate empty array if not exists

    for (NSIndexPath* indexPath in indexPaths) {
        UICollectionViewUpdateItem* updateItem = [[UICollectionViewUpdateItem alloc] initWithAction:updateAction forIndexPath:indexPath];
        [array addObject:updateItem];
    }

    if (!updating)
        [self endItemAnimations];
}

- (void)updateSections:(NSIndexSet*)sections updateAction:(UICollectionUpdateAction)updateAction {
    BOOL updating = _collectionViewFlags.updating;
    if (!updating)
        [self setupCellAnimations];

    NSMutableArray* updateActions = [self arrayForUpdateAction:updateAction];

    [sections enumerateIndexesUsingBlock:^(NSUInteger section, BOOL* stop) {
        UICollectionViewUpdateItem* updateItem =
            [[UICollectionViewUpdateItem alloc] initWithAction:updateAction
                                                  forIndexPath:[NSIndexPath indexPathForItem:NSNotFound inSection:(NSInteger)section]];
        [updateActions addObject:updateItem];
    }];

    if (!updating)
        [self endItemAnimations];
}

@end
