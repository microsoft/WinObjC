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
#include "Foundation/NSString.h"
#include "Foundation/NSBundle.h"
#include "Foundation/NSMutableDictionary.h"
#include "UIKit/UISegmentedControl.h"
#include "UIKit/UIColor.h"
#include "UISegment.h"
#include <math.h>

@implementation UISegmentedControl : UIControl {
    idretain _segments;
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

- (id)initWithCoder:(id)coder {
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
        [[_segments objectAtIndex:i] setDelegate:self];
        [[_segments objectAtIndex:i] setTag:i];

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

- (id)initWithFrame:(CGRect)pos {
    _segments = [NSMutableArray new];
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

- (id)initWithItems:(id)items {
    _shouldResizeToSuper = TRUE;
    _curSelected = 0xFFFFFFFF;
    _segments = [NSMutableArray new];

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

- (id)insertSegmentWithTitle:(id)title atIndex:(DWORD)index animated:(DWORD)animated {
    id newSegment = [[UISegment alloc] initWithTitle:title];
    [newSegment setDelegate:self];
    [_segments insertObject:newSegment atIndex:index];
    [self addSubview:newSegment];
    [newSegment release];

    positionSegments(self);

    return self;
}

- (id)imageForSegmentAtIndex:(DWORD)index {
    id segment = [_segments objectAtIndex:index];
    return [segment image];
}

- (id)insertSegmentWithImage:(id)image atIndex:(DWORD)index animated:(DWORD)animated {
    id newSegment = [[UISegment alloc] initWithImage:image];
    [newSegment setDelegate:self];
    [_segments insertObject:newSegment atIndex:index];
    [self addSubview:newSegment];
    [newSegment release];

    positionSegments(self);

    return self;
}

- (id)setTitle:(id)title forSegmentAtIndex:(DWORD)index {
    id segment = [_segments objectAtIndex:index];
    [segment setTitle:title];

    return self;
}

- (id)setImage:(id)image forSegmentAtIndex:(DWORD)index {
    id segment = [_segments objectAtIndex:index];
    [segment setImage:image];

    return self;
}

- (void)setEnabled:(BOOL)enable forSegmentAtIndex:(DWORD)index {
    id curSegment = [_segments objectAtIndex:index];
    [curSegment setEnabled:enable];
}

- (id)removeSegmentAtIndex:(DWORD)index animated:(DWORD)animated {
    id segment = [_segments objectAtIndex:index];
    [_segments removeObject:segment];
    [segment removeFromSuperview];
    // if ( _curSelected >= [segments count] ) _curSelected = -1;
    _curSelected = -1;

    positionSegments(self);

    return self;
}

- (id)removeAllSegments {
    int count;

    while ((count = [_segments count]) != 0) {
        [self removeSegmentAtIndex:count - 1 animated:NO];
    }

    return self;
}

- (id)titleForSegmentAtIndex:(DWORD)index {
    if (index == -1) {
        return nil;
    }
    id segment = [_segments objectAtIndex:index];

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

        [self sendEvent:self mask:UIControlEventValueChanged];
    }

    return self;
}

- (id)setSelectedSegmentIndex:(DWORD)pos {
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
            [self sendEvent:self mask:UIControlEventValueChanged];
        }
    }

    return self;
}

- (id)setSegmentedControlStyle:(DWORD)style {
    return self;
}

- (id)setMomentary:(DWORD)isMomentary {
    _isMomentary = isMomentary;
    return self;
}

- (id)segmentSelectedDown:(id)segment {
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

    [self sendEvent:self mask:UIControlEventValueChanged];

    return self;
}

- (id)segmentSelectedUp:(id)segment {
    if (!_isMomentary) {
        return self;
    }

    if (_curSelected != 0xFFFFFFFF) {
        [[_segments objectAtIndex:_curSelected] _setSelected:0];
    }

    _curSelected = -1;

    return self;
}

- (id)segmentSelectedCancelled:(id)segment {
    if (!_isMomentary) {
        return self;
    }

    if (_curSelected != 0xFFFFFFFF) {
        [[_segments objectAtIndex:_curSelected] _setSelected:0];
    }

    _curSelected = -1;

    return self;
}

- (unsigned)selectedSegmentIndex {
    return _curSelected;
}

- (unsigned)numberOfSegments {
    return [_segments count];
}

- (id)setTintColor:(id)uiColor {
    _tintColor = uiColor;

    if (isOSTarget(@"7.0")) {
        [[self layer] setBorderColor:(CGColorRef)_tintColor];
    }
    return self;
}

- (id)tintColor {
    return _tintColor;
}

- (id)setWidth:(float)width forSegmentAtIndex:(int)index {
    id curSegment = [_segments objectAtIndex:index];
    [curSegment _setWidth:width];
    positionSegments(self);

    return 0;
}

- (void)setFrame:(CGRect)frame {
    [super setFrame:frame];
}

- (float)widthForSegmentAtIndex:(int)index {
    id curSegment = [_segments objectAtIndex:index];

    CGRect curFrame = { 0 };
    curFrame = [curSegment frame];
    return curFrame.size.width;
}

- (id)layoutSubviews {
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

    return self;
}

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

- (id)setApportionsSegmentWidthsByContent:(BOOL)byContent {
    _apportionsSegmentWidthsByContent = byContent;
    positionSegments(self);
    return self;
}

- (id)setDividerImage:(id)img forLeftSegmentState:(int)leftState rightSegmentState:(int)rightState barMetrics:(int)barMetrics {
    int count = [_segments count];

    for (int i = 0; i < count; i++) {
        id curSegment = [_segments objectAtIndex:i];

        [curSegment setImage:nil];
        [curSegment _setNoDefaultImages:TRUE];
        if (leftState == 0 && rightState == 0) {
            _dividerImage = img;
            [curSegment _setDividerImage:(id)_dividerImage];
        }
        [curSegment setNeedsDisplay];
        _customImages = TRUE;
    }
    return self;
}

- (id)setBackgroundImage:(id)img forState:(NSUInteger)state barMetrics:(NSUInteger)metrics {
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
            id curSegment = [_segments objectAtIndex:i];

            [curSegment _setBackgroundImage:img forState:state];
            [curSegment setNeedsDisplay];
        }

        if (state < 16) {
            _backgroundImages[state] = img;
        }
    }
    return self;
}

- (id)setTitleTextAttributes:(id)attributes forState:(NSUInteger)state {
    if (state == 0) {
        int count = [_segments count];
        for (int i = 0; i < count; i++) {
            id curSegment = [_segments objectAtIndex:i];

            [curSegment _setAttributes:attributes forState:state];
            [curSegment setNeedsDisplay];
        }

        if (state < 16) {
            _segmentAttributes[state] = attributes;
        }
    }
    return self;
}

- (void)setEnabled:(int)enabled {
    [self setNeedsLayout];
    [super setEnabled:enabled];
}

- (CGSize)sizeThatFits:(CGSize)curSize {
    CGSize ret;

    ret.width = getSegmentsDesiredWidth(self);
    if (ret.width > curSize.width) {
        ret.width = curSize.width;
    }
    ret.height = 32.0f;

    return ret;
}

- (CGSize)intrinsicContentSize {
    CGSize ret;
    ret.width = getSegmentsDesiredWidth(self);
    ret.height = 32.0f;
    return ret;
}

@end
