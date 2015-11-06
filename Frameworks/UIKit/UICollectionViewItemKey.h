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

#include "UIKit/UICollectionViewLayout.h"

@interface UICollectionViewItemKey : NSObject {
@public
    idretain _identifier;
    idretain _indexPath;
    UICollectionViewItemType _type;
}
- (unsigned)hash;
- (UICollectionViewItemType)type;
- (BOOL)isEqual:(UICollectionViewItemKey*)other;
- (id)indexPath;
- (id)setIndexPath:(id)path;
- (id)identifier;
- (id)copyWithZone:(id)zone;
+ (id)collectionItemKeyForLayoutAttributes:(UICollectionViewLayoutAttributes*)layoutAttributes;
+ (id)collectionItemKeyForCellWithIndexPath:(id)indexPath;
@end
