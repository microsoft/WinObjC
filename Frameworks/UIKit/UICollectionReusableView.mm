//******************************************************************************
//
// UICollectionViewCell.m
// PSPDFKit
//
// Copyright (c) 2012-2013 Peter Steinberger. All rights reserved.
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

@interface UICollectionReusableView () {
    UICollectionViewLayoutAttributes* _layoutAttributes;
    NSString* _reuseIdentifier;
    __unsafe_unretained UICollectionView* _collectionView;
    struct {
        unsigned int inUpdateAnimation : 1;
    } _reusableViewFlags;
    char filler[50]; // [HACK] Our class needs to be larger than Apple's class for the superclass change to work.
}
@property (nonatomic, copy) NSString* reuseIdentifier;
@property (nonatomic, unsafe_unretained) UICollectionView* collectionView;
@property (nonatomic, strong) UICollectionViewLayoutAttributes* layoutAttributes;
@end

@implementation UICollectionReusableView

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - NSObject

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    if ((self = [super initWithFrame:frame])) {
    }
    return self;
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)aDecoder {
    if ((self = [super initWithCoder:aDecoder])) {
        self.reuseIdentifier = [aDecoder decodeObjectForKey:@"UIReuseIdentifier"];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)awakeFromNib {
    self.reuseIdentifier = [self valueForKeyPath:@"reuseIdentifier"];
}

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Public

/**
 @Status Interoperable
*/
- (void)prepareForReuse {
    self.layoutAttributes = nil;
}

/**
 @Status Interoperable
*/
- (void)applyLayoutAttributes:(UICollectionViewLayoutAttributes*)layoutAttributes {
    if (layoutAttributes != _layoutAttributes) {
        _layoutAttributes = layoutAttributes;

        self.bounds = (CGRect){.origin = self.bounds.origin, .size = layoutAttributes.size };
        self.center = layoutAttributes.center;
        self.hidden = layoutAttributes.hidden;
        self.layer.transform = layoutAttributes.transform3D;
        self.layer.zPosition = layoutAttributes.zIndex;
        self.layer.opacity = layoutAttributes.alpha;
    }
}

/**
 @Status Interoperable
*/
- (void)willTransitionFromLayout:(UICollectionViewLayout*)oldLayout toLayout:(UICollectionViewLayout*)newLayout {
    _reusableViewFlags.inUpdateAnimation = YES;
}

/**
 @Status Interoperable
*/
- (void)didTransitionFromLayout:(UICollectionViewLayout*)oldLayout toLayout:(UICollectionViewLayout*)newLayout {
    _reusableViewFlags.inUpdateAnimation = NO;
}

- (BOOL)isInUpdateAnimation {
    return _reusableViewFlags.inUpdateAnimation;
}

- (void)setInUpdateAnimation:(BOOL)inUpdateAnimation {
    _reusableViewFlags.inUpdateAnimation = (unsigned int)inUpdateAnimation;
}

/**
 @Status Stub
 @Notes
*/
- (UICollectionViewLayoutAttributes*)preferredLayoutAttributesFittingAttributes:(UICollectionViewLayoutAttributes*)layoutAttributes {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
