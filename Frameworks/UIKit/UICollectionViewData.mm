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
#include "Foundation/NSIndexPath.h"
#include "CoreGraphics/CGGeometry.h"
#include "UICollectionViewData.h"

@implementation UICollectionViewData : NSObject
- (id)initWithCollectionView:(id)collectionView layout:(id)layout {
    _collectionView = collectionView;
    _layout = layout;
    return self;
}

- (BOOL)_filterAttribs:(id)evaluatedObject bindings:(id)bindings {
    return ([evaluatedObject isKindOfClass:[UICollectionViewLayoutAttributes class]] &&
            ([evaluatedObject isCell] || [evaluatedObject isSupplementaryView] || [evaluatedObject isDecorationView]));
}

- (id)validateLayoutInRect:(CGRect)rect {
    [self validateItemCounts];
    [self prepareToLoadData];

    // TODO: check if we need to fetch data from layout
    if (!CGRectEqualToRect(_validLayoutRect, rect)) {
        _validLayoutRect = rect;
// we only want cell layoutAttributes & supplementaryView layoutAttributes
#if 0
id pred = [NSPredicate predicateWithObject:self selector:@selector(_filterAttribs:bindings:) withBindings:nil];
_cachedLayoutAttributes = [[_layout layoutAttributesForElementsInRect:rect] filteredArrayUsingPredicate:pred];
#else
        _cachedLayoutAttributes = [_layout layoutAttributesForElementsInRect:rect];
#endif
    }
    return self;
}

- (void)validateItemCounts {
    if (!_collectionViewDataFlags.itemCountsAreValid) {
        [self updateItemCounts];
    }
}

- (BOOL)layoutIsPrepared {
    return _collectionViewDataFlags.layoutIsPrepared;
}

- (unsigned)numberOfSections {
    [self validateItemCounts];
    return _numSections;
}

- (unsigned)numberOfItems {
    [self validateItemCounts];
    return _numItems;
}

- (unsigned)numberOfItemsInSection:(int)section {
    [self validateItemCounts];
    if (section >= _numSections || section < 0) {
        // In case of inconsistency returns the 'less harmful' amount of items. Throwing an exception here potentially
        // causes exceptions when data is consistent. Deleting sections is one of the parts sensitive to this.
        // All checks via assertions are done on CollectionView animation methods, specially 'endAnimations'.
        return 0;
        //@throw [NSException exceptionWithName:NSInvalidArgumentException reason:[NSString stringWithFormat:@"Section
        //%d out of range: 0...%d", section, _numSections] userInfo:nil];
    }

    NSInteger numberOfItemsInSection = 0;
    if (_sectionItemCounts) {
        numberOfItemsInSection = _sectionItemCounts[section];
    }
    return numberOfItemsInSection;
}

- (unsigned)numberOfItemsBeforeSection:(int)section {
    [self validateItemCounts];

    assert(section < _numSections); //, @"request for number of items in section %ld when there are only %ld sections in
    // the collection view", (long)section, (long)_numSections);

    NSInteger returnCount = 0;
    for (int i = 0; i < section; i++) {
        returnCount += _sectionItemCounts[i];
    }

    return returnCount;
}

- (id)setLayoutIsPrepared:(BOOL)layoutIsPrepared {
    _collectionViewDataFlags.layoutIsPrepared = layoutIsPrepared;
    return 0;
}

- (id)setContentSize:(CGSize)size {
    _contentSize = size;
    return 0;
}

- (id)prepareToLoadData {
    if (![self layoutIsPrepared]) {
        [_layout prepareLayout];
        _contentSize = [_layout collectionViewContentSize];
        [self setLayoutIsPrepared:YES];
    }
    return self;
}

- (id)layoutAttributesForElementsInRect:(CGRect)rect {
    [self validateLayoutInRect:rect];
    return _cachedLayoutAttributes;
}

- (id)updateItemCounts {
    // query how many sections there will be
    _numSections = 1;
    if ([[_collectionView dataSource] respondsToSelector:@selector(numberOfSectionsInCollectionView:)]) {
        _numSections = [[_collectionView dataSource] numberOfSectionsInCollectionView:_collectionView];
    }
    if (_numSections <= 0) { // early bail-out
        _numItems = 0;
        if (_sectionItemCounts) {
            free(_sectionItemCounts);
        }
        _sectionItemCounts = 0;
        _collectionViewDataFlags.itemCountsAreValid = YES;
        return 0;
    }

    // allocate space
    if (!_sectionItemCounts) {
        _sectionItemCounts = (NSInteger*)malloc(_numSections * sizeof(NSInteger));
    } else {
        _sectionItemCounts = (NSInteger*)realloc(_sectionItemCounts, _numSections * sizeof(NSInteger));
    }

    // query cells per section
    _numItems = 0;
    for (NSInteger i = 0; i < _numSections; i++) {
        NSInteger cellCount = [[_collectionView dataSource] collectionView:_collectionView numberOfItemsInSection:i];
        _sectionItemCounts[i] = cellCount;
        _numItems += cellCount;
    }

    _collectionViewDataFlags.itemCountsAreValid = YES;
    return self;
}

- (id)invalidate {
    _collectionViewDataFlags.itemCountsAreValid = NO;
    _collectionViewDataFlags.layoutIsPrepared = NO;
    _validLayoutRect = CGRectNull; // don't set CGRectZero in case of _contentSize=CGSizeZero
    return self;
}

- (CGRect)collectionViewContentRect {
    CGRect ret = {
        {
            0, 0,
        },
        _contentSize,
    };
    return ret;
}

- (unsigned)globalIndexForItemAtIndexPath:(id)indexPath {
    return [self numberOfItemsBeforeSection:[indexPath section]] + [indexPath item];
}

- (id)indexPathForItemAtGlobalIndex:(NSInteger)index {
    [self validateItemCounts];

    assert(index < _numItems); //, @"request for index path for global index %ld when there are only %ld items in the
    // collection view", (long)index, (long)_numItems);

    NSInteger section = 0;
    NSInteger countItems = 0;
    for (section = 0; section < _numSections; section++) {
        NSInteger countIncludingThisSection = countItems + _sectionItemCounts[section];
        if (countIncludingThisSection > index) {
            break;
        }
        countItems = countIncludingThisSection;
    }

    NSInteger item = index - countItems;

    return [NSIndexPath indexPathForItem:item inSection:section];
}

@end
