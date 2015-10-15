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
#include "UICollectionViewItemKey.h"
#include "UIKit/UICollectionViewLayout.h"

@implementation UICollectionViewItemKey : NSObject
+ (id)collectionItemKeyForLayoutAttributes:(UICollectionViewLayoutAttributes*)layoutAttributes {
    UICollectionViewItemKey* key = [self new];
    key->_indexPath = [layoutAttributes indexPath];
    UICollectionViewItemType const itemType = [layoutAttributes representedElementCategory];
    key->_type = itemType;
    key->_identifier = [layoutAttributes representedElementKind];
    return key;
}

+ (id)collectionItemKeyForCellWithIndexPath:(id)indexPath {
    UICollectionViewItemKey* key = [self new];
    key->_indexPath = indexPath;
    key->_type = UICollectionViewItemTypeCell;
    key->_identifier = @"UICollectionElementKindCell";
    return key;
}

- (unsigned)hash {
    return (([_indexPath hash] + _type) * 31) + [_identifier hash];
}

- (UICollectionViewItemType)type {
    return _type;
}

- (id)indexPath {
    return _indexPath;
}

- (id)setIndexPath:(id)path {
    _indexPath = path;
    return self;
}

- (id)identifier {
    return _identifier;
}

- (BOOL)isEqual:(UICollectionViewItemKey*)other {
    if ([other isKindOfClass:[UICollectionViewItemKey class]]) {
        // identifier might be nil?
        if (_type == other->_type && [_indexPath isEqual:[other indexPath]] &&
            ([(NSString*)_identifier isEqualToString:(id)other->_identifier] || (id)_identifier == other->_identifier)) {
            return YES;
        }
    }
    return NO;
}

- (id)copyWithZone:(id)zone {
    UICollectionViewItemKey* itemKey = [UICollectionViewItemKey new];
    itemKey->_indexPath = _indexPath;
    itemKey->_type = _type;
    itemKey->_identifier = _identifier;
    return itemKey;
}

@end
