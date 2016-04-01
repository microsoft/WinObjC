//******************************************************************************
//
// UICollectionViewUpdateItem.m
// PSPDFKit
//
// Copyright (c) 2012-2013 Peter Steinberger. All rights reserved.
// Contributed by Sergey Gavrilyuk.
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#import <StubReturn.h>
#import "AssertARCEnabled.h"

#include "UICollectionViewLayoutAttributes+Internal.h"
#include "UICollectionViewItemKey.h"

@interface UICollectionViewLayoutAttributes () {
    struct {
        unsigned int isCellKind : 1;
        unsigned int isDecorationView : 1;
        unsigned int isHidden : 1;
        unsigned int isPinned : 1;
    } _layoutFlags;
}
@property (nonatomic) UICollectionViewItemType elementCategory;
@property (nonatomic, copy) NSString* elementKind;
@end

@implementation UICollectionViewLayoutAttributes

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Static

/**
 @Status Interoperable
*/
+ (instancetype)layoutAttributesForCellWithIndexPath:(NSIndexPath*)indexPath {
    UICollectionViewLayoutAttributes* attributes = [self new];
    attributes.elementKind = UICollectionElementKindCell;
    attributes.elementCategory = UICollectionViewItemTypeCell;
    attributes.indexPath = indexPath;
    return attributes;
}

/**
 @Status Interoperable
*/
+ (instancetype)layoutAttributesForSupplementaryViewOfKind:(NSString*)elementKind withIndexPath:(NSIndexPath*)indexPath {
    UICollectionViewLayoutAttributes* attributes = [self new];
    attributes.elementCategory = UICollectionViewItemTypeSupplementaryView;
    attributes.elementKind = elementKind;
    attributes.indexPath = indexPath;
    return attributes;
}

/**
 @Status Interoperable
*/
+ (instancetype)layoutAttributesForDecorationViewOfKind:(NSString*)elementKind withIndexPath:(NSIndexPath*)indexPath {
    UICollectionViewLayoutAttributes* attributes = [self new];
    attributes.elementCategory = UICollectionViewItemTypeDecorationView;
    attributes.elementKind = elementKind;
    attributes.indexPath = indexPath;
    return attributes;
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - NSObject

/**
 @Status Interoperable
*/
- (instancetype)init {
    if ((self = [super init])) {
        _alpha = 1.f;
        _transform3D = CATransform3DIdentity;
    }
    return self;
}

/**
 @Status Interoperable
*/
- (NSUInteger)hash {
    return ([_elementKind hash] * 31) + [_indexPath hash];
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(id)other {
    if ([other isKindOfClass:self.class]) {
        UICollectionViewLayoutAttributes* otherLayoutAttributes = (UICollectionViewLayoutAttributes*)other;
        if (_elementCategory == otherLayoutAttributes.elementCategory && [_elementKind isEqual:otherLayoutAttributes.elementKind] &&
            [_indexPath isEqual:otherLayoutAttributes.indexPath]) {
            return YES;
        }
    }
    return NO;
}

/**
 @Status Interoperable
*/
- (NSString*)description {
    return [NSString stringWithFormat:@"<%@: %p frame:%@ indexPath:%@ elementKind:%@>",
                                      NSStringFromClass(self.class),
                                      self,
                                      NSStringFromCGRect(self.frame),
                                      self.indexPath,
                                      self.elementKind];
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Public

/**
 @Status Interoperable
*/
- (UICollectionViewItemType)representedElementCategory {
    return _elementCategory;
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Private

/**
 @Public No
*/
- (NSString*)representedElementKind {
    return self.elementKind;
}

/**
 @Public No
*/
- (BOOL)isDecorationView {
    return self.representedElementCategory == UICollectionViewItemTypeDecorationView;
}

/**
 @Public No
*/
- (BOOL)isSupplementaryView {
    return self.representedElementCategory == UICollectionViewItemTypeSupplementaryView;
}

/**
 @Public No
*/
- (BOOL)isPinnedSupplementaryView {
    return (self.representedElementCategory == UICollectionViewItemTypeSupplementaryView) && (_layoutFlags.isPinned);
}

/**
 @Public No
*/
- (BOOL)isCell {
    return self.representedElementCategory == UICollectionViewItemTypeCell;
}

/**
 @Public No
*/
- (void)updateFrame {
    _frame = (CGRect){ { _center.x - _size.width / 2, _center.y - _size.height / 2 }, _size };
}

/**
 @Public No
*/
- (void)setPinned:(BOOL)pinned {
    _layoutFlags.isPinned = pinned ? 1 : 0;
}

/**
 @Public No
*/
- (void)setSize:(CGSize)size {
    _size = size;
    [self updateFrame];
}

/**
 @Public No
*/
- (void)setCenter:(CGPoint)center {
    _center = center;
    [self updateFrame];
}

/**
 @Public No
*/
- (void)setFrame:(CGRect)frame {
    _frame = frame;
    _size = _frame.size;
    _center = (CGPoint){ CGRectGetMidX(_frame), CGRectGetMidY(_frame) };
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - NSCopying

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    UICollectionViewLayoutAttributes* layoutAttributes = [self.class new];
    layoutAttributes.indexPath = self.indexPath;
    layoutAttributes.elementKind = self.elementKind;
    layoutAttributes.elementCategory = self.elementCategory;
    layoutAttributes.frame = self.frame;
    layoutAttributes.center = self.center;
    layoutAttributes.size = self.size;
    layoutAttributes.transform3D = self.transform3D;
    layoutAttributes.alpha = self.alpha;
    layoutAttributes.zIndex = self.zIndex;
    layoutAttributes.hidden = self.isHidden;
    return layoutAttributes;
}

/**
 @Status Stub
 @Notes
*/
- (void)setBounds:(CGRect)bounds {
    UNIMPLEMENTED();
}

@end
