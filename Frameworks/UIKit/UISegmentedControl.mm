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

#import "Starboard.h"
#import "UIKit/UIView.h"
#import "UIKit/UIControl.h"
#import "Foundation/NSString.h"
#import "Foundation/NSBundle.h"
#import "Foundation/NSMutableDictionary.h"
#import "UIKit/UISegmentedControl.h"
#import "UIKit/UIColor.h"
#import "UISegment.h"
#import <math.h>
#import "StubReturn.h"
#import "UIViewInternal.h"
#import "UISegmentedControlInternal.h"

@implementation UISegmentedControl {
    StrongId<NSMutableArray> _segments;
    id _tintColor;
    idretain _backgroundImages[16];
    idretain _segmentAttributes[16];
    idretain _dividerImage;
    unsigned _curSelected;
    BOOL _shouldResizeToSuper;
    BOOL _isMomentary;
    BOOL _apportionsSegmentWidthsByContent;
    BOOL _customImages;
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    id result = [super initWithCoder:coder];

    if (isOSTarget(@"7.0")) {
        CGRect frame = [self frame];
        frame.size.height = 29.0f;
        [super setFrame:frame];

        [[self layer] setBorderWidth:1.0f];
        [[self layer] setBorderColor:(CGColorRef)[UIColor blackColor]];
        [self setClipsToBounds:TRUE];
    }

    _segments = [coder decodeObjectForKey:@"UISegments"];
    if ([coder containsValueForKey:@"UISelectedSegmentIndex"]) {
        _curSelected = [coder decodeInt32ForKey:@"UISelectedSegmentIndex"];
    } else {
        _curSelected = 0xFFFFFFFF;
    }
    _isMomentary = [coder decodeInt32ForKey:@"UIMomentary"];
    id tintColor = [coder decodeObjectForKey:@"UISegmentedControlTintColor"];
    if (tintColor != nil) {
        [self setTintColor:tintColor];
    }

    int count = [_segments count];

    for (int i = 0; i < count; i++) {
        UISegment* segment = [_segments objectAtIndex:i];
        [segment setDelegate:self];
        [segment setTag:i];

        DWORD type = 0;

        if (i == 0) {
            type |= 1;
        }
        if (i == count - 1) {
            type |= 2;
        }
        [[_segments objectAtIndex:i] _setType:type];
    }

    positionSegments(self);

    return result;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)pos {
    _segments.attach([NSMutableArray new]);
    _curSelected = 0xFFFFFFFF;
    [super initWithFrame:pos];

    return self;
}

static float widthForItems(id items) {
    float maxItemWidth = 0.0f;

    id font = [UIFont boldSystemFontOfSize:12.0f];

    //  Go through each item
    int count = [items count];
    for (int i = 0; i < count; i++) {
        id curItem = [items objectAtIndex:i];

        if ([curItem isKindOfClass:[NSString class]]) {
            CGSize size = { 0, 0 };

            size = [curItem sizeWithFont:font];
            float width = 10.0f + size.width;
            if (width > maxItemWidth) {
                maxItemWidth = width;
            }
        }
        if ([curItem isKindOfClass:[UIImage class]]) {
            CGSize size = { 0, 0 };

            size = [curItem size];
            float width = 10.0f + size.width;
            if (width > maxItemWidth) {
                maxItemWidth = width;
            }
        }
    }

    if (maxItemWidth > 0.0f) {
        return maxItemWidth * count + 10.0f;
    } else {
        return 0.0f;
    }
}

/**
 @Status Interoperable
*/
- (instancetype)initWithItems:(id)items {
    _shouldResizeToSuper = TRUE;
    _curSelected = 0xFFFFFFFF;
    _segments.attach([NSMutableArray new]);

    CGRect pos;
    pos.origin.x = 0;
    pos.origin.y = 0;
    pos.size.width = widthForItems(items);
    pos.size.height = 32.0f;

    [super initWithFrame:pos];

    //  Go through each item
    int count = [items count];
    for (int i = 0; i < count; i++) {
        id curItem = [items objectAtIndex:i];

        if ([curItem isKindOfClass:[NSString class]]) {
            [self insertSegmentWithTitle:curItem atIndex:i animated:FALSE];
        }
        if ([curItem isKindOfClass:[UIImage class]]) {
            [self insertSegmentWithImage:curItem atIndex:i animated:FALSE];
        }
    }

    positionSegments(self);

    return self;
}

- (id)insertSegment:(DWORD)pos withTitle:(DWORD)title animated:(DWORD)animated {
    assert(0);
    /*
    const char *pTitle = (const char *) pEmu->MapEmuToHost(pEmu->msgSend(title, "cStringUsingEncoding:", "d", 0));
    numSegments ++;
    */

    return self;
}

static float getSegmentsDesiredWidth(UISegmentedControl* self) {
    int count = [self->_segments count];
    CGRect ourBounds;

    ourBounds = [self bounds];

    float x = 0.0f;
    float segWidth = ourBounds.size.width / (float)count;
    float totalWidth;

    if (self->_apportionsSegmentWidthsByContent) {
        totalWidth = 0.0f;

        for (int i = 0; i < count; i++) {
            id curSegment = [self->_segments objectAtIndex:i];

            totalWidth += [curSegment _contentWidth] + 10.0f;
        }
    } else {
        totalWidth = 0.0f;

        for (int i = 0; i < count; i++) {
            id curSegment = [self->_segments objectAtIndex:i];

            float fixedWidth = [curSegment _desiredWidth];

            if (fixedWidth != 0.0f) {
                totalWidth += fixedWidth;
            } else {
                totalWidth += segWidth;
            }
        }
    }

    return totalWidth;
}

static void positionSegments(UISegmentedControl* self) {
    int count = [self->_segments count];
    CGRect ourBounds;

    ourBounds = [self bounds];

    float x = 0.0f;
    float segWidth = ourBounds.size.width / (float)count;
    float segWidthScaler = getSegmentsDesiredWidth(self);
    if (segWidthScaler == 0.0f) {
        segWidthScaler = 1.0f;
    }

    for (int i = 0; i < count; i++) {
        id curSegment = [self->_segments objectAtIndex:i];

        CGRect curFrame = { 0 };
        curFrame = [curSegment frame];

        float width = segWidth;
        if (self->_apportionsSegmentWidthsByContent) {
            width = [curSegment _contentWidth] + 10.0f;
        } else {
            float fixedWidth = [curSegment _desiredWidth];

            if (fixedWidth != 0.0f) {
                width = fixedWidth;
            }
        }
        width = width * ourBounds.size.width / segWidthScaler;

        curFrame = ourBounds;
        curFrame.origin.x = floorf(x);
        curFrame.size.width = ceilf(width);

        [curSegment setFrame:curFrame];
        x += width;

        DWORD type = 0;

        if (i == 0) {
            type |= 1;
        }
        if (i == count - 1) {
            type |= 2;
        }

        [curSegment _setType:type];
        if (i == self->_curSelected) {
            [curSegment _setSelected:1];
        } else {
            [curSegment _setSelected:0];
        }
        if (self->_dividerImage != nil) {
            [curSegment _setDividerImage:self->_dividerImage];
        }
        if (self->_customImages) {
            [curSegment _setNoDefaultImages:TRUE];
        }
        if (self->_tintColor) {
            [curSegment _setTintColor:self->_tintColor];
        }
        for (int i = 0; i < 16; i++) {
            if (self->_backgroundImages[i] != nil) {
                [curSegment _setBackgroundImage:self->_backgroundImages[i] forState:i];
            }

            if (self->_segmentAttributes[i] != nil) {
                [curSegment _setAttributes:self->_segmentAttributes[i] forState:i];
            }
        }
    }
}

/**
 @Status Caveat
 @Notes animated parameter not supported
*/
- (void)insertSegmentWithTitle:(NSString*)title atIndex:(NSUInteger)index animated:(BOOL)animated {
    UISegment* newSegment = [[UISegment alloc] initWithTitle:title];
    [newSegment setDelegate:self];
    [_segments insertObject:newSegment atIndex:index];
    [self addSubview:newSegment];
    [newSegment release];

    positionSegments(self);
}

/**
 @Status Interoperable
*/
- (UIImage*)imageForSegmentAtIndex:(NSUInteger)index {
    UISegment* segment = [_segments objectAtIndex:index];
    return [segment image];
}

/**
 @Status Caveat
 @Notes animated parameter not supported
*/
- (void)insertSegmentWithImage:(UIImage*)image atIndex:(NSUInteger)index animated:(BOOL)animated {
    UISegment* newSegment = [[UISegment alloc] initWithImage:image];
    [newSegment setDelegate:self];
    [_segments insertObject:newSegment atIndex:index];
    [self addSubview:newSegment];
    [newSegment release];

    positionSegments(self);
}

/**
 @Status Interoperable
*/
- (void)setTitle:(NSString*)title forSegmentAtIndex:(NSUInteger)index {
    UISegment* segment = [_segments objectAtIndex:index];
    [segment setTitle:title];
}

/**
 @Status Interoperable
*/
- (void)setImage:(UIImage*)image forSegmentAtIndex:(NSUInteger)index {
    UISegment* segment = [_segments objectAtIndex:index];
    [segment setImage:image];
}

/**
 @Status Interoperable
*/
- (void)setEnabled:(BOOL)enable forSegmentAtIndex:(NSUInteger)index {
    UISegment* curSegment = [_segments objectAtIndex:index];
    [curSegment setEnabled:enable];
}

- (id)removeSegmentAtIndex:(DWORD)index animated:(DWORD)animated {
    UISegment* segment = [_segments objectAtIndex:index];
    [_segments removeObject:segment];
    [segment removeFromSuperview];
    // if ( _curSelected >= [segments count] ) _curSelected = -1;
    _curSelected = -1;

    positionSegments(self);

    return self;
}

/**
 @Status Interoperable
*/
- (void)removeAllSegments {
    int count;

    while ((count = [_segments count]) != 0) {
        [self removeSegmentAtIndex:count - 1 animated:NO];
    }
}

/**
 @Status Interoperable
*/
- (NSString*)titleForSegmentAtIndex:(NSUInteger)index {
    if (index == -1) {
        return nil;
    }
    UISegment* segment = [_segments objectAtIndex:index];

    return [segment title];
}

- (id)selectSegment:(DWORD)pos {
    if (pos != _curSelected) {
        if (_curSelected != 0xFFFFFFFF) {
            [[_segments objectAtIndex:_curSelected] _setSelected:0];
        }

        _curSelected = pos;

        if (_curSelected != 0xFFFFFFFF) {
            [[_segments objectAtIndex:_curSelected] _setSelected:1];
        }

        [self sendActionsForControlEvents:UIControlEventValueChanged];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)setSelectedSegmentIndex:(NSInteger)pos {
    if (pos != _curSelected) {
        if (_curSelected != 0xFFFFFFFF) {
            [[_segments objectAtIndex:_curSelected] _setSelected:0];
        }

        _curSelected = pos;

        if (_curSelected != 0xFFFFFFFF) {
            [[_segments objectAtIndex:_curSelected] _setSelected:1];
        }

        bool fireEvent = false;
        if (!isOSTarget(@"5.0")) {
            fireEvent = true;
        }
        if (fireEvent) {
            [self sendActionsForControlEvents:UIControlEventValueChanged];
        }
    }
}

/**
 @Status Stub
*/
- (void)setSegmentedControlStyle:(UISegmentedControlStyle)style {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)setMomentary:(BOOL)isMomentary {
    _isMomentary = isMomentary;
}

- (id)_segmentSelectedDown:(id)segment {
    if (_curState & UIControlStateDisabled || ![segment isEnabled]) {
        return self;
    }

    DWORD _lastSelected = _curSelected;

    if (_curSelected != 0xFFFFFFFF) {
        [[_segments objectAtIndex:_curSelected] _setSelected:0];
    }

    _curSelected = [_segments indexOfObject:segment];

    if (_curSelected != 0xFFFFFFFF) {
        [[_segments objectAtIndex:_curSelected] _setSelected:1];
    }

    [self sendActionsForControlEvents:UIControlEventValueChanged];

    return self;
}

- (id)_segmentSelectedUp:(id)segment {
    if (!_isMomentary) {
        return self;
    }

    if (_curSelected != 0xFFFFFFFF) {
        [[_segments objectAtIndex:_curSelected] _setSelected:0];
    }

    _curSelected = -1;

    return self;
}

- (id)_segmentSelectedCancelled:(id)segment {
    if (!_isMomentary) {
        return self;
    }

    if (_curSelected != 0xFFFFFFFF) {
        [[_segments objectAtIndex:_curSelected] _setSelected:0];
    }

    _curSelected = -1;

    return self;
}

/**
 @Status Interoperable
*/
- (NSInteger)selectedSegmentIndex {
    return _curSelected;
}

/**
 @Status Interoperable
*/
- (unsigned)numberOfSegments {
    return [_segments count];
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (void)setTintColor:(UIColor*)uiColor {
    _tintColor = uiColor;

    if (isOSTarget(@"7.0")) {
        [[self layer] setBorderColor:(CGColorRef)_tintColor];
    }
}

/**
 @Status Interoperable
*/
- (id)tintColor {
    return _tintColor;
}

/**
 @Status Interoperable
*/
- (void)setWidth:(CGFloat)width forSegmentAtIndex:(NSUInteger)index {
    UISegment* curSegment = [_segments objectAtIndex:index];
    [curSegment _setWidth:width];
    positionSegments(self);
}

/**
 @Status Interoperable
*/
- (void)setFrame:(CGRect)frame {
    [super setFrame:frame];
}

/**
 @Status Interoperable
*/
- (CGFloat)widthForSegmentAtIndex:(NSUInteger)index {
    UISegment* curSegment = [_segments objectAtIndex:index];

    CGRect curFrame = { 0 };
    curFrame = [curSegment frame];
    return curFrame.size.width;
}

/**
 @Status Interoperable
*/
- (void)layoutSubviews {
    if (_shouldResizeToSuper) {
        CGRect superRect = { 0 };
        id superView = [self superview];
        superRect = [self bounds];

        if (superView != nil && superRect.size.height == 0.0f) {
            superRect.origin.x = 0;
            superRect.origin.y = 0;
            superRect.size.height = 32.0f;

            [self setBounds:superRect];
        }

        positionSegments(self);
    } else {
        positionSegments(self);
    }
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    _segments = nil;
    _tintColor = nil;
    _dividerImage = nil;

    for (int i = 0; i < 16; i++) {
        _backgroundImages[i] = nil;
        _segmentAttributes[i] = nil;
    }
    [super dealloc];
}

/**
 @Status Stub
*/
- (void)setApportionsSegmentWidthsByContent:(BOOL)byContent {
    UNIMPLEMENTED();
    _apportionsSegmentWidthsByContent = byContent;
    positionSegments(self);
}

/**
 @Status Stub
*/
- (void)setDividerImage:(UIImage*)img
    forLeftSegmentState:(UIControlState)leftState
      rightSegmentState:(UIControlState)rightState
             barMetrics:(UIBarMetrics)barMetrics {
    UNIMPLEMENTED();
    int count = [_segments count];

    for (int i = 0; i < count; i++) {
        UISegment* curSegment = [_segments objectAtIndex:i];

        [curSegment setImage:nil];
        [curSegment _setNoDefaultImages:TRUE];
        if (leftState == 0 && rightState == 0) {
            _dividerImage = img;
            [curSegment _setDividerImage:(id)_dividerImage];
        }
        [curSegment setNeedsDisplay];
        _customImages = TRUE;
    }
}

/**
 @Status Caveat
 @Notes metrics parameter not supported
*/
- (void)setBackgroundImage:(UIImage*)img forState:(UIControlState)state barMetrics:(UIBarMetrics)metrics {
    if ([img leftCapWidth] == 0) {
        CGSize imgSize;
        imgSize = [img size];

        UIEdgeInsets insets = { 0 };
        insets.left = (imgSize.width - 1.0f) / 2.0f;
        insets.right = (imgSize.width - 1.0f) / 2.0f;

        img = [img resizableImageWithCapInsets:insets];
    }
    if (state == 0) {
        [self __setContentsImage:img];
    } else {
        int count = [_segments count];
        for (int i = 0; i < count; i++) {
            UISegment* curSegment = [_segments objectAtIndex:i];

            [curSegment _setBackgroundImage:img forState:state];
            [curSegment setNeedsDisplay];
        }

        if (state < 16) {
            _backgroundImages[state] = img;
        }
    }
}

/**
 @Status Interoperable
*/
- (void)setTitleTextAttributes:(NSDictionary*)attributes forState:(UIControlState)state {
    if (state == 0) {
        int count = [_segments count];
        for (int i = 0; i < count; i++) {
            UISegment* curSegment = [_segments objectAtIndex:i];

            [curSegment _setAttributes:attributes forState:state];
            [curSegment setNeedsDisplay];
        }

        if (state < 16) {
            _segmentAttributes[state] = attributes;
        }
    }
}

/**
 @Status Interoperable
*/
- (void)setEnabled:(int)enabled {
    [self setNeedsLayout];
    [super setEnabled:enabled];
}

/**
 @Status Interoperable
*/
- (CGSize)sizeThatFits:(CGSize)curSize {
    CGSize ret;

    ret.width = getSegmentsDesiredWidth(self);
    if (ret.width > curSize.width) {
        ret.width = curSize.width;
    }
    ret.height = 32.0f;

    return ret;
}

/**
 @Status Interoperable
*/
- (CGSize)intrinsicContentSize {
    CGSize ret;
    ret.width = getSegmentsDesiredWidth(self);
    ret.height = 32.0f;
    return ret;
}

/**
 @Status Stub
*/
- (BOOL)isEnabledForSegmentAtIndex:(NSUInteger)segment {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setContentOffset:(CGSize)offset forSegmentAtIndex:(NSUInteger)segment {
    UNIMPLEMENTED();
}

@end
