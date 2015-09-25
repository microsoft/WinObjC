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
#include "Foundation/NSValue.h"
#include "CoreGraphics/CGGeometry.h"
#include "UIKit/UICollectionViewFlowLayout.h"

#include "UIGridLayoutRow.h"
#include "UIGridLayoutItem.h"
#include "UIGridLayoutSection.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

@implementation UIGridLayoutRow : NSObject
- (id)init {
    _items.attach([NSMutableArray new]);
    return self;
}

- (id)setFixedItemSize:(BOOL)fixed {
    _fixedItemSize = fixed;
    return self;
}

- (id)setRowFrame:(CGRect)frame {
    memcpy(&_rowFrame, &frame, sizeof(CGRect));
    return self;
}

- (CGRect)rowFrame {
    return _rowFrame;
}

- (id)setComplete:(BOOL)complete {
    _complete = complete;
    return self;
}

- (id)setSection:(id)section {
    _section = section;
    return self;
}

- (id)setIndex:(NSInteger)index {
    _index = index;
    return self;
}

- (unsigned)index {
    return _index;
}

- (id)setItemCount:(NSInteger)count {
    _itemCount = count;
    return self;
}

- (unsigned)itemCount {
    if (_fixedItemSize) {
        return _itemCount;
    } else {
        return [(NSMutableArray*)_items count];
    }
}

- (BOOL)fixedItemSize {
    return _fixedItemSize;
}

- (id)items {
    return _items;
}

- (id)addItem:(id)item {
    [(NSMutableArray*)_items addObject:item];
    [item setRowObject:self];
    [self invalidate];
    return self;
}

- (id)invalidate {
    _isValid = NO;
    _rowSize = CGSizeMake(0, 0);
    _rowFrame = CGRectMake(0, 0, 0, 0);
    return self;
}

- (id)layoutRow {
    [self layoutRowAndGenerateRectArray:NO];
    return self;
}

- (CGSize)rowSize {
    return _rowSize;
}

- (id)itemRects {
    return [self layoutRowAndGenerateRectArray:YES];
}

- (id)layoutRowAndGenerateRectArray:(BOOL)generateRectArray {
    id rects = generateRectArray ? [NSMutableArray array] : nil;

    if (!_isValid || generateRectArray) {
        // properties for aligning
        BOOL isHorizontal = [[_section layoutInfo] horizontal];
        BOOL isLastRow = [_section indexOfIncompleteRow] == _index;
        UIFlowLayoutHorizontalAlignment horizontalAlignment = [[[_section rowAlignmentOptions]
            objectForKey:isLastRow ? @"UIFlowLayoutLastRowHorizontalAlignmentKey"
                                   : @"UIFlowLayoutCommonRowHorizontalAlignmentKey"] integerValue];

        // calculate space that's left over if we would align it from left to right.
        CGFloat leftOverSpace = [[_section layoutInfo] dimension];

        UIEdgeInsets sectionMargins;
        sectionMargins = [_section sectionMargins];
        if (isHorizontal) {
            leftOverSpace -= sectionMargins.top + sectionMargins.bottom;
        } else {
            leftOverSpace -= sectionMargins.left + sectionMargins.right;
        }

        // calculate the space that we have left after counting all items.
        // UICollectionView is smart and lays out items like they would have been placed on a full row
        // So we need to calculate the "usedItemCount" with using the last item as a reference size.
        // This allows us to correctly justify-place the items in the grid.
        NSUInteger usedItemCount = 0;
        NSUInteger itemIndex = 0;
        CGFloat spacing = isHorizontal ? [_section verticalInterstice] : [_section horizontalInterstice];
        // the last row should justify as if it is filled with more (invisible) items so that the whole
        // UICollectionView feels more like a grid than a random line of blocks
        while (itemIndex < [self itemCount] || isLastRow) {
            CGFloat nextItemSize;
            // first we need to find the size (width/height) of the next item to fit
            if (!_fixedItemSize) {
                id item = [(NSMutableArray*)_items objectAtIndex:MIN(itemIndex, [self itemCount] - 1)];

                CGRect itemFrame;
                itemFrame = [item itemFrame];
                nextItemSize = isHorizontal ? itemFrame.size.height : itemFrame.size.width;
            } else {
                CGSize itemSize;
                itemSize = [_section itemSize];
                nextItemSize = isHorizontal ? itemSize.height : itemSize.width;
            }

            // the first item does not add a separator spacing,
            // every one afterwards in the same row will need this spacing constant
            if (itemIndex > 0) {
                nextItemSize += spacing;
            }

            // check to see if we can at least fit an item (+separator if necessary)
            if (leftOverSpace < nextItemSize) {
                break;
            }

            // we need to maintain the leftover space after the maximum amount of items have
            // occupied, so we know how to adjust equal spacing among all the items in a row
            leftOverSpace -= nextItemSize;

            itemIndex++;
            usedItemCount = itemIndex;
        }

        // push everything to the right if right-aligning and divide in half for centered
        // currently there is no public API supporting this behavior
        CGPoint itemOffset = CGPoint::point(0, 0);
        if (horizontalAlignment == UIFlowLayoutHorizontalAlignmentRight) {
            itemOffset.x += leftOverSpace;
        } else if (horizontalAlignment == UIFlowLayoutHorizontalAlignmentCentered ||
                   (horizontalAlignment == UIFlowLayoutHorizontalAlignmentJustify && usedItemCount == 1)) {
            // Special case one item row to split leftover space in half
            itemOffset.x += leftOverSpace / 2;
        }

        // calculate the justified spacing among all items in a row if we are using
        // the default PSTFlowLayoutHorizontalAlignmentJustify layout
        CGFloat interSpacing = usedItemCount <= 1 ? 0 : leftOverSpace / (CGFloat)(usedItemCount - 1);

        // calculate row frame as union of all items
        CGRect frame = CGRectMake(0, 0, 0, 0);

        CGSize itemSize;
        itemSize = [_section itemSize];
        CGRect itemFrame = CGRectMake(0, 0, itemSize.width, itemSize.height);
        for (itemIndex = 0; itemIndex < [self itemCount]; itemIndex++) {
            id item = nil;
            if (!_fixedItemSize) {
                item = [(NSMutableArray*)_items objectAtIndex:itemIndex];
                itemFrame = [item itemFrame];
            }
            // depending on horizontal/vertical for an item size (height/width),
            // we add the minimum separator then an equally distributed spacing
            // (since our default mode is justify) calculated from the total leftover
            // space divided by the number of intervals
            if (isHorizontal) {
                itemFrame.origin.y = itemOffset.y;
                itemOffset.y += itemFrame.size.height + [_section verticalInterstice];
                if (horizontalAlignment == UIFlowLayoutHorizontalAlignmentJustify) {
                    itemOffset.y += interSpacing;
                }
            } else {
                itemFrame.origin.x = itemOffset.x;
                itemOffset.x += itemFrame.size.width + [_section horizontalInterstice];
                if (horizontalAlignment == UIFlowLayoutHorizontalAlignmentJustify) {
                    itemOffset.x += interSpacing;
                }
            }
            [item setItemFrame:itemFrame]; // might call nil; don't care
            [rects addObject:[NSValue valueWithCGRect:itemFrame]];
            frame = CGRectUnion(frame, itemFrame);
        }
        _rowSize = frame.size;
        //        _rowFrame = frame; // set externally
        _isValid = YES;
    }
    return rects;
}

@end
