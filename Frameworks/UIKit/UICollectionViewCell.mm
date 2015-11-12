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
#include "UIKit/UIView.h"
#include "UIKit/UIControl.h"
#include "QuartzCore/CALayer.h"
#include "UIKit/UICollectionReusableView.h"
#include "UIKit/UICollectionViewCell.h"

@implementation UICollectionReusableView : UIView {
@private
    id _collectionView;
    idretain _reuseIdentifier;
    BOOL _needsRefresh;

@public
    idretaintype(UICollectionViewLayoutAttributes) _layoutAttributes;
}

- (id)setCollectionView:(id)view {
    _collectionView = view;
    return 0;
}

- (id)collectionView:(id)view {
    return _collectionView;
}

- (id)setReuseIdentifier:(id)identifier {
    _reuseIdentifier.attach([identifier copy]);
    return 0;
}

- (id)reuseIdentifier {
    return _reuseIdentifier;
}

- (id)layoutAttributes {
    return _layoutAttributes;
}

/**
 @Status Interoperable
*/
- (void)prepareForReuse {
    _layoutAttributes = nil;
}

- (id)applyLayoutAttributes:(UICollectionViewLayoutAttributes*)layoutAttributes {
    if (layoutAttributes != _layoutAttributes) {
        _layoutAttributes = layoutAttributes;

        CGRect bounds;
        CGSize size;

        bounds = [self bounds];
        size = [layoutAttributes size];

        [self setBounds:CGRectMake(bounds.origin.x, bounds.origin.y, size.width, size.height)];

        [self setCenter:[layoutAttributes center]];
        [self setHidden:[layoutAttributes isHidden]];
        [[self layer] setTransform:[layoutAttributes transform3D]];
        [[self layer] setZPosition:[layoutAttributes zIndex]];
        [[self layer] setOpacity:[layoutAttributes alpha]];
    }
    return 0;
}

- (void)_setNeedsRefresh:(BOOL)needsRefresh {
    _needsRefresh = needsRefresh;
}

- (BOOL)_needsRefresh {
    return _needsRefresh;
}

- (id)initWithCoder:(id)aDecoder {
    [super initWithCoder:aDecoder];
    _reuseIdentifier = [aDecoder decodeObjectForKey:@"UIReuseIdentifier"];
    return self;
}

@end

@implementation UICollectionViewCell : UICollectionReusableView {
    struct {
        unsigned int selected : 1;
        unsigned int highlighted : 1;
        unsigned int showingMenu : 1;
        unsigned int clearSelectionWhenMenuDisappears : 1;
        unsigned int waitingForSelectionAnimationHalfwayPoint : 1;
    } _collectionCellFlags;
    idretaintype(UIView) _contentView;
    idretaintype(UIView) _backgroundView;
    idretaintype(UIView) _selectedBackgroundView;
    idretain _selectionSegueTemplate;
}
- (id)initWithFrame:(CGRect)frame {
    [super initWithFrame:frame];

    _backgroundView.attach([[UIView alloc] initWithFrame:[self bounds]]);
    [_backgroundView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
    [self addSubview:(id)_backgroundView];

    _contentView.attach([[UIView alloc] initWithFrame:[self bounds]]);
    [_contentView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
    [self addSubview:(id)_contentView];

    //_menuGesture = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(menuGesture:)];

    return self;
}

- (id)updateBackgroundView:(BOOL)highlight {
    [_selectedBackgroundView setAlpha:highlight ? 1.0f : 0.0f];
    [self setHighlighted:highlight forViews:[_contentView subviews]];
    return 0;
}

- (id)setHighlighted:(BOOL)highlighted forViews:(id)subviews {
    for (id view in subviews) {
        // Ignore the events if view wants to
        if (![view isUserInteractionEnabled] && [view respondsToSelector:@selector(setHighlighted:)] &&
            ![view isKindOfClass:[UIControl class]]) {
            [view setHighlighted:highlighted];

            [self setHighlighted:highlighted forViews:[view subviews]];
        }
    }
    return 0;
}

- (id)setHighlighted:(BOOL)highlighted {
    _collectionCellFlags.highlighted = highlighted;
    [self updateBackgroundView:highlighted];
    return 0;
}

- (BOOL)isHighlighted {
    return _collectionCellFlags.highlighted;
}

- (BOOL)isSelected {
    return _collectionCellFlags.selected;
}

- (id)setSelected:(BOOL)selected {
    _collectionCellFlags.selected = selected;
    // self.accessibilityTraits = selected ? UIAccessibilityTraitSelected : UIAccessibilityTraitNone;
    [self updateBackgroundView:selected];
    return 0;
}

/**
 @Status Interoperable
*/
- (id)contentView {
    return _contentView;
}

- (id)setContentView:(id)view {
    _contentView = view;
    return 0;
}

- (void)prepareForReuse {
    _layoutAttributes = nil;
    [self setSelected:NO];
    [self setHighlighted:NO];
}

- (id)performSelectionSegue {
    if ([_selectionSegueTemplate respondsToSelector:@selector(perform:)]) {
        [_selectionSegueTemplate perform:self];
    }
    return 0;
}

- (id)initWithCoder:(id)aDecoder {
    [super initWithCoder:aDecoder];
    _contentView = [aDecoder decodeObjectForKey:@"UIContentView"];
    [_contentView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
    [_contentView setAutoresizesSubviews:TRUE];
    /*
    if ( [[self subviews] count] > 0) {
    _contentView = [[self subviews] objectAtIndex:0];
    } else {
    _contentView.attach([[UIView alloc] initWithFrame:_m_sttype<CGRect>(self, "bounds")]);
    [_contentView setAutoresizingMask:UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight];
    [self addSubview:_contentView];
    }

    _backgroundView.attach([[UIView alloc] initWithFrame:_m_sttype<CGRect>(self, "bounds")]);
    [_backgroundView setAutoresizingMask:UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight];
    [self insertSubview:(id) _backgroundView belowSubview:_contentView];
    */

    //_menuGesture = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(menuGesture:)];
    return self;
}

@end
