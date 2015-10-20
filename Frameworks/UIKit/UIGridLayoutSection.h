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

#pragma once

#include "UIGridLayoutInfo.h"

@interface UIGridLayoutSection : NSObject {
@public
    idretaintype(NSMutableArray) _items, _rows;
    idretain _rowAlignmentOptions;
    id _layoutInfo;
    float _verticalInterstice, _horizontalInterstice;
    UIEdgeInsets _sectionMargins;
    float _headerDimension, _footerDimension;
    CGRect _headerFrame, _footerFrame, _frame;
    NSInteger _itemsByRowCount;
    NSInteger _itemsCount;
    NSInteger _indexOfIncompleteRow;
    CGSize _itemSize;
    BOOL _fixedItemSize;
    BOOL _isValid;
}
- (float)verticalInterstice;
- (float)horizontalInterstice;
- (unsigned)itemsCount;
- (unsigned)itemsByRowCount;
- (int)indexOfIncompleteRow;
- (BOOL)fixedItemSize;
- (UIGridLayoutInfo*)layoutInfo;
- (UIEdgeInsets)sectionMargins;
- (CGSize)itemSize;
- (CGRect)frame;
- (CGRect)headerFrame;
- (CGRect)footerFrame;
/* annotate with type */ -(id)init;
/* annotate with type */ -(id)setRowAlignmentOptions : (id)options;
/* annotate with type */ -(id)rowAlignmentOptions;
/* annotate with type */ -(id)setLayoutInfo : (id)info;
/* annotate with type */ -(id)setVerticalInterstice : (float)vertical;
/* annotate with type */ -(id)setHorizontalInterstice : (float)horizontal;
/* annotate with type */ -(id)setSectionMargins : (UIEdgeInsets)margins;
/* annotate with type */ -(id)setItemSize : (CGSize)size;
/* annotate with type */ -(id)setFrame : (CGRect)frame;
/* annotate with type */ -(id)setHeaderDimension : (float)dim;
/* annotate with type */ -(id)setFooterDimension : (float)dim;
/* annotate with type */ -(id)addItem;
/* annotate with type */ -(id)addRow;
/* annotate with type */ -(id)setItemsCount : (int)itemsCount;
/* annotate with type */ -(id)setFixedItemSize : (BOOL)fixed;
/* annotate with type */ -(id)rows;
/* annotate with type */ -(id)items;
/* annotate with type */ -(id)computeLayout;
@end
