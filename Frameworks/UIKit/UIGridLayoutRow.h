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

#include "UIGridLayoutSection.h"

@interface UIGridLayoutRow : NSObject {
@public
    idretain _items;
    UIGridLayoutSection* _section;
    BOOL _fixedItemSize;
    NSInteger _index;
    BOOL _isValid;
    CGSize _rowSize;
    CGRect _rowFrame;
    BOOL _complete;
    NSInteger _itemCount;
}
- (unsigned)index;
- (unsigned)itemCount;
- (BOOL)fixedItemSize;
- (CGRect)rowFrame;
- (CGSize)rowSize;
- (id)init;
- (id)setFixedItemSize:(BOOL)fixed;
- (id)setRowFrame:(CGRect)frame;
- (id)setComplete:(BOOL)complete;
- (id)setSection:(id)section;
- (id)setIndex:(NSInteger)index;
- (id)setItemCount:(NSInteger)count;
- (id)items;
- (id)addItem:(id)item;
- (id)invalidate;
- (id)layoutRow;
- (id)itemRects;
- (id)layoutRowAndGenerateRectArray:(BOOL)generateRectArray;
@end
