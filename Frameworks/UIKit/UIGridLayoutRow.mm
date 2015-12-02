//******************************************************************************
//
// UIGridLayoutRow.m
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
#import "UIGridLayoutRow.h"
#import "UIGridLayoutSection.h"
#import "UIGridLayoutItem.h"
#import "UIGridLayoutInfo.h"

@interface UIGridLayoutRow () {
    NSMutableArray *_items;
    BOOL _isValid;
    int _verticalAlignement;
    int _horizontalAlignement;
}
@property (nonatomic, strong) NSArray *items;
@end

@implementation UIGridLayoutRow

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - NSObject

- (id)init {
    if ((self = [super init])) {
        _items = [NSMutableArray new];
    }
    return self;
}

- (NSString *)description {
    return [NSString stringWithFormat:@"<%@: %p frame:%@ index:%ld items:%@>", NSStringFromClass(self.class), self, NSStringFromCGRect(self.rowFrame), (long)self.index, self.items];
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Public

- (void)invalidate {
    _isValid = NO;
    _rowSize = CGSizeZero;
    _rowFrame = CGRectZero;
}

- (NSArray *)itemRects {
    return [self layoutRowAndGenerateRectArray:YES];
}

- (void)layoutRow {
    [self layoutRowAndGenerateRectArray:NO];
}

- (NSArray *)layoutRowAndGenerateRectArray:(BOOL)generateRectArray {
    NSMutableArray *rects = generateRectArray ? [NSMutableArray array] : nil;
    if (!_isValid || generateRectArray) {
        // properties for aligning
        BOOL isHorizontal = self.section.layoutInfo.horizontal;
        BOOL isLastRow = self.section.indexOfImcompleteRow == self.index;
        UIFlowLayoutHorizontalAlignment horizontalAlignment = [self.section.rowAlignmentOptions[isLastRow ? UIFlowLayoutLastRowHorizontalAlignmentKey : UIFlowLayoutCommonRowHorizontalAlignmentKey] integerValue];

        // calculate space that's left over if we would align it from left to right.
        CGFloat leftOverSpace = self.section.layoutInfo.dimension;
        if (isHorizontal) {
            leftOverSpace -= self.section.sectionMargins.top + self.section.sectionMargins.bottom;
        }else {
            leftOverSpace -= self.section.sectionMargins.left + self.section.sectionMargins.right;
        }

        // calculate the space that we have left after counting all items.
        // UICollectionView is smart and lays out items like they would have been placed on a full row
        // So we need to calculate the "usedItemCount" with using the last item as a reference size.
        // This allows us to correctly justify-place the items in the grid.
        NSInteger usedItemCount = 0;
        NSInteger itemIndex = 0;
        CGFloat spacing = isHorizontal ? self.section.verticalInterstice : self.section.horizontalInterstice;
        // the last row should justify as if it is filled with more (invisible) items so that the whole
        // UICollectionView feels more like a grid than a random line of blocks
        while (itemIndex < self.itemCount || isLastRow) {
            CGFloat nextItemSize;
            // first we need to find the size (width/height) of the next item to fit
            if (!self.fixedItemSize) {
                UIGridLayoutItem *item = self.items[(NSUInteger)MIN(itemIndex, self.itemCount - 1)];
                nextItemSize = isHorizontal ? item.itemFrame.size.height : item.itemFrame.size.width;
            }else {
                nextItemSize = isHorizontal ? self.section.itemSize.height : self.section.itemSize.width;
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
        CGPoint itemOffset = CGPointZero;
        if (horizontalAlignment == UIFlowLayoutHorizontalAlignmentRight) {
            itemOffset.x += leftOverSpace;
        }else if (horizontalAlignment == UIFlowLayoutHorizontalAlignmentCentered ||
                (horizontalAlignment == UIFlowLayoutHorizontalAlignmentJustify && usedItemCount == 1)) {
            // Special case one item row to split leftover space in half
            itemOffset.x += leftOverSpace / 2;
        }

        // calculate the justified spacing among all items in a row if we are using
        // the default UIFlowLayoutHorizontalAlignmentJustify layout
        CGFloat interSpacing = usedItemCount <= 1 ? 0 : leftOverSpace / (CGFloat)(usedItemCount - 1);

        // calculate row frame as union of all items
        CGRect frame = CGRectZero;
        CGRect itemFrame = (CGRect){.size=self.section.itemSize};
        for (itemIndex = 0; itemIndex < self.itemCount; itemIndex++) {
            UIGridLayoutItem *item = nil;
            if (!self.fixedItemSize) {
                item = self.items[(NSUInteger)itemIndex];
                itemFrame = [item itemFrame];
            }
            // depending on horizontal/vertical for an item size (height/width),
            // we add the minimum separator then an equally distributed spacing
            // (since our default mode is justify) calculated from the total leftover
            // space divided by the number of intervals
            if (isHorizontal) {
                itemFrame.origin.y = itemOffset.y;
                itemOffset.y += itemFrame.size.height + self.section.verticalInterstice;
                if (horizontalAlignment == UIFlowLayoutHorizontalAlignmentJustify) {
                    itemOffset.y += interSpacing;
                }
            }else {
                itemFrame.origin.x = itemOffset.x;
                itemOffset.x += itemFrame.size.width + self.section.horizontalInterstice;
                if (horizontalAlignment == UIFlowLayoutHorizontalAlignmentJustify) {
                    itemOffset.x += interSpacing;
                }
            }
            item.itemFrame = itemFrame; // might call nil; don't care
            [rects addObject:[NSValue valueWithCGRect:itemFrame]];
            frame = CGRectUnion(frame, itemFrame);
        }
        _rowSize = frame.size;
        //        _rowFrame = frame; // set externally
        _isValid = YES;
    }
    return rects;
}

- (void)addItem:(UIGridLayoutItem *)item {
    [_items addObject:item];
    item.rowObject = self;
    [self invalidate];
}

- (UIGridLayoutRow *)snapshot {
    UIGridLayoutRow *snapshotRow = [self.class new];
    snapshotRow.section = self.section;
    snapshotRow.items = self.items;
    snapshotRow.rowSize = self.rowSize;
    snapshotRow.rowFrame = self.rowFrame;
    snapshotRow.index = self.index;
    snapshotRow.complete = self.complete;
    snapshotRow.fixedItemSize = self.fixedItemSize;
    snapshotRow.itemCount = self.itemCount;
    return snapshotRow;
}

- (UIGridLayoutRow *)copyFromSection:(UIGridLayoutSection *)section {
    return nil; // ???
}

- (NSInteger)itemCount {
    if (self.fixedItemSize) {
        return _itemCount;
    }else {
        return (NSInteger)self.items.count;
    }
}

@end
