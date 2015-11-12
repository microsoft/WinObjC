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
- (id)init;
- (id)setRowAlignmentOptions:(id)options;
- (id)rowAlignmentOptions;
- (id)setLayoutInfo:(id)info;
- (id)setVerticalInterstice:(float)vertical;
- (id)setHorizontalInterstice:(float)horizontal;
- (id)setSectionMargins:(UIEdgeInsets)margins;
- (id)setItemSize:(CGSize)size;
- (id)setFrame:(CGRect)frame;
- (id)setHeaderDimension:(float)dim;
- (id)setFooterDimension:(float)dim;
- (id)addItem;
- (id)addRow;
- (id)setItemsCount:(int)itemsCount;
- (id)setFixedItemSize:(BOOL)fixed;
- (id)rows;
- (id)items;
- (id)computeLayout;
@end
