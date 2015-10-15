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
/* annotate with type */ -(id)init;
/* annotate with type */ -(id)setFixedItemSize : (BOOL)fixed;
/* annotate with type */ -(id)setRowFrame : (CGRect)frame;
/* annotate with type */ -(id)setComplete : (BOOL)complete;
/* annotate with type */ -(id)setSection : (id)section;
/* annotate with type */ -(id)setIndex : (NSInteger)index;
/* annotate with type */ -(id)setItemCount : (NSInteger)count;
/* annotate with type */ -(id)items;
/* annotate with type */ -(id)addItem : (id)item;
/* annotate with type */ -(id)invalidate;
/* annotate with type */ -(id)layoutRow;
/* annotate with type */ -(id)itemRects;
/* annotate with type */ -(id)layoutRowAndGenerateRectArray : (BOOL)generateRectArray;
@end
