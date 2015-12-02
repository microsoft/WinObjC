//******************************************************************************
//
// UICollectionViewItemKey.m
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
#import "UICollectionViewItemKey.h"

NSString* const UICollectionElementKindCell = @"UICollectionElementKindCell";
NSString* const UICollectionElementKindDecorationView = @"UICollectionElementKindDecorationView";

@implementation UICollectionViewItemKey

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Static

+ (id)collectionItemKeyForCellWithIndexPath:(NSIndexPath*)indexPath {
    UICollectionViewItemKey* key = [self.class new];
    key.indexPath = indexPath;
    key.type = UICollectionViewItemTypeCell;
    key.identifier = UICollectionElementKindCell;
    return key;
}

+ (id)collectionItemKeyForLayoutAttributes:(UICollectionViewLayoutAttributes*)layoutAttributes {
    UICollectionViewItemKey* key = [self.class new];
    key.indexPath = layoutAttributes.indexPath;
    UICollectionViewItemType const itemType = layoutAttributes.representedElementCategory;
    key.type = itemType;
    key.identifier = layoutAttributes.representedElementKind;
    return key;
}

NSString* UICollectionViewItemTypeToString(UICollectionViewItemType type) {
    switch (type) {
        case UICollectionViewItemTypeCell:
            return @"Cell";
        case UICollectionViewItemTypeDecorationView:
            return @"Decoration";
        case UICollectionViewItemTypeSupplementaryView:
            return @"Supplementary";
        default:
            return @"<INVALID>";
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - NSObject

- (NSString*)description {
    return [NSString stringWithFormat:@"<%@: %p Type = %@ Identifier=%@ IndexPath = %@>",
                                      NSStringFromClass(self.class),
                                      self,
                                      UICollectionViewItemTypeToString(self.type),
                                      _identifier,
                                      self.indexPath];
}

- (NSUInteger)hash {
    return (([_indexPath hash] + _type) * 31) + [_identifier hash];
}

- (BOOL)isEqual:(id)other {
    if ([other isKindOfClass:self.class]) {
        UICollectionViewItemKey* otherKeyItem = (UICollectionViewItemKey*)other;
        // identifier might be nil?
        if (_type == otherKeyItem.type && [_indexPath isEqual:otherKeyItem.indexPath] &&
            ([_identifier isEqualToString:otherKeyItem.identifier] || _identifier == otherKeyItem.identifier)) {
            return YES;
        }
    }
    return NO;
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - NSCopying

- (id)copyWithZone:(NSZone*)zone {
    UICollectionViewItemKey* itemKey = [self.class new];
    itemKey.indexPath = self.indexPath;
    itemKey.type = self.type;
    itemKey.identifier = self.identifier;
    return itemKey;
}

@end
