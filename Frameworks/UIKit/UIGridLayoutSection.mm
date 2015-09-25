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
#include "Foundation/NSMutableArray.h"
#include "CoreGraphics/CGGeometry.h"
#include "UIGridLayoutSection.h"
#include "UIGridLayoutItem.h"
#include "UIGridLayoutRow.h"
#include <algorithm>

@implementation UIGridLayoutSection : NSObject
- (id)init {
    _items.attach([NSMutableArray new]);
    _rows.attach([NSMutableArray new]);
    return self;
}

- (id)setRowAlignmentOptions:(id)options {
    _rowAlignmentOptions.attach([options copy]);
    return self;
}

- (id)rowAlignmentOptions {
    return _rowAlignmentOptions;
}

- (id)setLayoutInfo:(id)info {
    _layoutInfo = info;
    return self;
}

- (id)setVerticalInterstice:(float)vertical {
    _verticalInterstice = vertical;
    return self;
}

- (float)verticalInterstice {
    return _verticalInterstice;
}

- (id)setHorizontalInterstice:(float)horizontal {
    _horizontalInterstice = horizontal;
    return self;
}

- (float)horizontalInterstice {
    return _horizontalInterstice;
}

- (id)setSectionMargins:(UIEdgeInsets)margins {
    _sectionMargins = margins;
    return self;
}

- (UIEdgeInsets)sectionMargins {
    return _sectionMargins;
}

- (CGSize)itemSize {
    return _itemSize;
}

- (id)setItemSize:(CGSize)size {
    memcpy(&_itemSize, &size, sizeof(CGSize));
    return 0;
}

- (CGRect)frame {
    return _frame;
}

- (CGRect)headerFrame {
    return _headerFrame;
}

- (CGRect)footerFrame {
    return _footerFrame;
}

- (id)setFrame:(CGRect)frame {
    _frame = frame;
    return self;
}

- (id)setHeaderDimension:(float)dim {
    _headerDimension = dim;
    return self;
}

- (id)setFooterDimension:(float)dim {
    _footerDimension = dim;
    return self;
}

- (id)addItem {
    id item = [UIGridLayoutItem new];
    [item setSection:self];
    [_items addObject:item];
    return item;
}

- (id)addRow {
    id row = [UIGridLayoutRow new];
    [row setSection:self];
    [_rows addObject:row];
    return row;
}

- (unsigned)itemsCount {
    return _fixedItemSize ? _itemsCount : [_items count];
}

- (id)setItemsCount:(int)itemsCount {
    _itemsCount = itemsCount;
    return 0;
}

- (unsigned)itemsByRowCount {
    return _itemsByRowCount;
}

- (id)setFixedItemSize:(BOOL)fixed {
    _fixedItemSize = fixed;

    return 0;
}

- (int)indexOfIncompleteRow {
    return _indexOfIncompleteRow;
}

- (BOOL)fixedItemSize {
    return _fixedItemSize;
}

- (UIGridLayoutInfo*)layoutInfo {
    return _layoutInfo;
}

- (id)rows {
    return _rows;
}

- (id)items {
    return _items;
}

- (id)computeLayout {
    if (!_isValid) {
        assert([_rows count] == 0);

        // iterate over all items, turning them into rows.
        CGSize sectionSize = CGSizeMake(0, 0);
        NSInteger rowIndex = 0;
        NSUInteger itemIndex = 0;
        NSInteger itemsByRowCount = 0;
        CGFloat dimensionLeft = 0;
        id row = nil;

        // get dimension and compensate for section margin
        CGFloat headerFooterDimension = [_layoutInfo dimension];
        CGFloat dimension = headerFooterDimension;

        if ([_layoutInfo horizontal]) {
            dimension -= _sectionMargins.top + _sectionMargins.bottom;

            _headerFrame = CGRectMake(sectionSize.width, 0, _headerDimension, headerFooterDimension);
            sectionSize.width += _headerDimension + _sectionMargins.left;
        } else {
            dimension -= _sectionMargins.left + _sectionMargins.right;
            _headerFrame = CGRectMake(0, sectionSize.height, headerFooterDimension, _headerDimension);
            sectionSize.height += _headerDimension + _sectionMargins.top;
        }

        CGFloat spacing = [_layoutInfo horizontal] ? _verticalInterstice : _horizontalInterstice;

        do {
            bool finishCycle = itemIndex >= [self itemsCount];
            // TODO: fast path could even remove row creation and just calculate on the fly
            id item = nil;
            if (!finishCycle)
                item = _fixedItemSize ? nil : [_items objectAtIndex:itemIndex];

            CGSize itemSize;

            if (_fixedItemSize) {
                itemSize = _itemSize;
            } else {
                CGRect rect;
                rect = [item itemFrame];
                itemSize = rect.size;
            }
            CGFloat itemDimension = [_layoutInfo horizontal] ? itemSize.height : itemSize.width;

            // first item of each row does not add spacing
            if (itemsByRowCount > 0)
                itemDimension += spacing;
            if (dimensionLeft < itemDimension || finishCycle) {
                // finish current row
                if (row) {
                    // compensate last row
                    _itemsByRowCount = std::max(itemsByRowCount, _itemsByRowCount);
                    [row setItemCount:itemsByRowCount];

                    // if current row is done but there are still items left, increase the incomplete row counter
                    if (!finishCycle)
                        _indexOfIncompleteRow = rowIndex;

                    [row layoutRow];

                    if ([_layoutInfo horizontal]) {
                        CGSize rowSize;
                        rowSize = [row rowSize];
                        [row setRowFrame:CGRectMake(
                                             sectionSize.width, _sectionMargins.top, rowSize.width, rowSize.height)];
                        sectionSize.height = std::max(rowSize.height, sectionSize.height);
                        sectionSize.width += rowSize.width + (finishCycle ? 0 : _horizontalInterstice);
                    } else {
                        CGSize rowSize;
                        rowSize = [row rowSize];
                        [row setRowFrame:CGRectMake(
                                             _sectionMargins.left, sectionSize.height, rowSize.width, rowSize.height)];
                        sectionSize.height += rowSize.height + (finishCycle ? 0 : _verticalInterstice);
                        sectionSize.width = std::max(rowSize.width, sectionSize.width);
                    }
                }
                // add new rows until the section is fully laid out
                if (!finishCycle) {
                    // create new row
                    [row setComplete:YES]; // finish up current row
                    row = [self addRow];
                    [row setFixedItemSize:_fixedItemSize];
                    [row setIndex:rowIndex];
                    _indexOfIncompleteRow = rowIndex;
                    rowIndex++;
                    // convert an item from previous row to current, remove spacing for first item
                    if (itemsByRowCount > 0)
                        itemDimension -= spacing;
                    dimensionLeft = dimension - itemDimension;
                    itemsByRowCount = 0;
                }
            } else {
                dimensionLeft -= itemDimension;
            }

            // add item on slow path
            if (item)
                [row addItem:item];

            itemIndex++;
            itemsByRowCount++;
        } while (itemIndex <= [self itemsCount]); // cycle once more to finish last row

        if ([_layoutInfo horizontal]) {
            sectionSize.width += _sectionMargins.right;
            _footerFrame = CGRectMake(sectionSize.width, 0, _footerDimension, headerFooterDimension);
            sectionSize.width += _footerDimension;
        } else {
            sectionSize.height += _sectionMargins.bottom;
            _footerFrame = CGRectMake(0, sectionSize.height, headerFooterDimension, _footerDimension);
            sectionSize.height += _footerDimension;
        }

        _frame = CGRectMake(0, 0, sectionSize.width, sectionSize.height);
        _isValid = YES;
    }
    return 0;
}

@end
