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
#include "UIGridLayoutItem.h"

@implementation UIGridLayoutItem : NSObject
- (id)setSection:(id)section {
    _section = section;
    return 0;
}

- (id)section {
    return _section;
}

- (id)setRowObject:(id)rowObject {
    _rowObject = rowObject;
    return 0;
}

- (id)rowObject {
    return _rowObject;
}

- (id)setItemFrame:(CGRect)frame {
    _itemFrame = frame;
    return 0;
}

- (CGRect)itemFrame {
    return _itemFrame;
}

@end
