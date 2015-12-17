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
#include "UIKit/UIImage.h"
#include "UIKit/UIImageView.h"
#include "UIKit/UIGestureRecognizer.h"
#include "UIKit/UISlider.h"

@implementation UISlider {
    idretaintype(UIImage) _sliderLeft, _sliderRight, _dot, _dotHighlighted;
    idretaintype(UIImageView) _sliderLeftView, _sliderRightView, _sliderThumbView;
    float _value, _max, _min, _trackVal;
}
static void sizeViews(UISlider* self, bool animated) {
    CGRect bounds, thumbSize;
    bounds = [self bounds];
    thumbSize = [self->_sliderThumbView bounds];

    if (animated) {
        [UIView beginAnimations:@"MoveView" context:nil];
        [UIView setAnimationDuration:0.25f];
        [UIView setAnimationDelegate:nil];
    }

    CGRect newFrame;
    newFrame.origin.x = 0;
    newFrame.origin.y = bounds.size.height / 2.0f - 4.0f;
    newFrame.size.width = bounds.size.width;
    newFrame.size.height = 8.0f;
    [self->_sliderLeftView setFrame:newFrame];

    float amt;

    if (self->_max > 0.0f) {
        amt = (self->_value - self->_min) / self->_max;
    } else {
        amt = 0.0f;
    }

    newFrame.size.width = bounds.size.width * amt;
    if (newFrame.size.width > bounds.size.width) {
        newFrame.size.width = bounds.size.width;
    }
    if (newFrame.size.width < 8 || (newFrame.size.width != newFrame.size.width)) {
        newFrame.size.width = 8;
    }

    [self->_sliderRightView setFrame:newFrame];

    newFrame = thumbSize;
    thumbSize.origin.x = bounds.size.width * amt - thumbSize.size.width / 2.0f;
    thumbSize.origin.y = bounds.size.height / 2.0f - thumbSize.size.height / 2.0f;

    [self->_sliderThumbView setFrame:thumbSize];

    if (animated) {
        [UIView commitAnimations];
    }
}

static void initInternal(UISlider* self) {
    self->_sliderLeft = [[UIImage imageNamed:@"/img/progress-background@2x.png"] stretchableImageWithLeftCapWidth:5 topCapHeight:0];
    self->_sliderRight = [[UIImage imageNamed:@"/img/progress-foreground@2x.png"] stretchableImageWithLeftCapWidth:5 topCapHeight:0];
    self->_dot = [UIImage imageNamed:@"/img/slider-handle@2x.png"];
    self->_dotHighlighted = [UIImage imageNamed:@"/img/slider-handle-highlighted@2x.png"];

    CGRect progressFrame;

    progressFrame.origin.x = 0;
    progressFrame.origin.y = 0;
    progressFrame.size.width = 0;
    progressFrame.size.height = 8;

    self->_sliderLeftView = [[[UIImageView alloc] initWithFrame:progressFrame] autorelease];
    [self->_sliderLeftView setImage:(id)self->_sliderLeft];

    progressFrame.size.width = 8;
    self->_sliderRightView = [[[UIImageView alloc] initWithFrame:progressFrame] autorelease];
    [self->_sliderRightView setImage:(id)self->_sliderRight];

    progressFrame.origin.x = 0;
    progressFrame.origin.y = 0;
    progressFrame.size.width = 50;
    progressFrame.size.height = 100;
    self->_sliderThumbView = [[[UIImageView alloc] initWithFrame:progressFrame] autorelease];
    [self->_sliderThumbView setContentMode:UIViewContentModeCenter];
    [self->_sliderThumbView setImage:(id)self->_dot];
    [self->_sliderThumbView setHighlightedImage:(id)self->_dotHighlighted];
    [self->_sliderThumbView setUserInteractionEnabled:TRUE];

    [self addSubview:(id)self->_sliderLeftView];
    [self addSubview:(id)self->_sliderRightView];
    [self addSubview:(id)self->_sliderThumbView];

    UIPanGestureRecognizer* panGesture = [[[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(_didPan:)] autorelease];
    [panGesture setDelegate:(id<UIGestureRecognizerDelegate>)self];
    [panGesture _setDragSlack:0.0f];
    [self->_sliderThumbView addGestureRecognizer:(id)panGesture];

    sizeViews(self, false);
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    [super initWithCoder:coder];

    id valueStr = [coder decodeObjectForKey:@"UIValue"];

    _value = [valueStr floatValue];
    _max = 1.0f;
    _min = 0.0f;

    if ([coder containsValueForKey:@"UIMaxValue"]) {
        _max = [[coder decodeObjectForKey:@"UIMaxValue"] floatValue];
    }
    if ([coder containsValueForKey:@"UIMinValue"]) {
        _min = [[coder decodeObjectForKey:@"UIMinValue"] floatValue];
    }

    initInternal(self);

    return self;
}

- (instancetype)initWithFrame:(CGRect)frame {
    [super initWithFrame:frame];

    _value = 0.0f;
    _max = 1.0f;
    _min = 0.0f;

    initInternal(self);

    return self;
}

/**
 @Status Interoperable
*/
- (float)value {
    return _value;
}

/**
 @Status Interoperable
*/
- (void)setMinimumValue:(float)value {
    _min = value;
    sizeViews(self, false);
}

/**
 @Status Interoperable
*/
- (float)minimumValue {
    return _min;
}

/**
 @Status Interoperable
*/
- (void)setMaximumValue:(float)value {
    _max = value;
    sizeViews(self, false);
}

/**
 @Status Interoperable
*/
- (float)maximumValue {
    return _max;
}

/**
 @Status Interoperable
*/
- (void)setValue:(float)value {
    [self setValue:value animated:FALSE];
}

- (void)setValue:(float)value animated:(BOOL)animated {
    if (value < _min) {
        value = _min;
    }
    if (value > _max) {
        value = _max;
    }
    _value = value;
    sizeViews(self, animated ? true : false);
}

- (void)setContinuous {
}

/**
 @Status Interoperable
*/
- (void)setThumbImage:(UIImage*)image forState:(NSUInteger)state {
    _dot = image;
    if (state == 0) {
        [_sliderThumbView setImage:image];
        [_sliderThumbView setHighlightedImage:nil];
        sizeViews(self, false);
    } else if (state == 1) {
        [_sliderThumbView setHighlightedImage:image];
    }
}

/**
 @Status Interoperable
*/
- (void)setMinimumTrackImage:(UIImage*)image forState:(NSUInteger)state {
    [_sliderLeftView setImage:image];
    _sliderLeft = [image stretchableImageWithLeftCapWidth:3 topCapHeight:0];
}

- (void)setMinimumValueImage:(UIImage*)image {
    [_sliderLeftView setImage:image];
    _sliderLeft = [image stretchableImageWithLeftCapWidth:3 topCapHeight:0];
}

- (void)setMaximumValueImage:(UIImage*)image {
    [_sliderRightView setImage:image];
    _sliderLeft = [image stretchableImageWithLeftCapWidth:3 topCapHeight:0];
}

/**
 @Status Interoperable
*/
- (void)setMaximumTrackImage:(UIImage*)image forState:(NSUInteger)state {
    [_sliderRightView setImage:image];
    _sliderRight = [image stretchableImageWithLeftCapWidth:3 topCapHeight:0];
}

- (UIImage*)currentThumbImage {
    return _dot;
}

- (UIImage*)currentMinimumTrackImage {
    return _sliderLeft;
}

- (void)layoutSubviews {
    sizeViews(self, false);
}

- (void)_didPan:(UIPanGestureRecognizer*)gesture {
    DWORD state = [gesture state];

    CGPoint amt;
    amt = [gesture translationInView:self];
    [gesture setTranslation:CGPointMake(0, 0) inView:self];

    CGRect bounds;

    if (state == UIGestureRecognizerStateEnded) {
        [_sliderThumbView setHighlighted:FALSE];
    } else if (state == UIGestureRecognizerStateBegan) {
        _trackVal = _value;
        if ([_sliderThumbView highlightedImage] != nil) {
            [_sliderThumbView setHighlighted:TRUE];
        }
    }

    bounds = [self bounds];

    _trackVal += (amt.x / bounds.size.width) * (_max - _min);
    [self setValue:_trackVal];
    [self sendEvent:self mask:UIControlEventValueChanged];
}

- (void)dealloc {
    _sliderLeft = nil;
    _sliderRight = nil;
    _dot = nil;
    _dotHighlighted = nil;
    [_sliderLeftView removeFromSuperview];
    [_sliderRightView removeFromSuperview];
    [_sliderThumbView removeFromSuperview];

    _sliderLeftView = nil;
    _sliderRightView = nil;
    _sliderThumbView = nil;
    [super dealloc];
}

- (void)setHidden:(BOOL)hide {
    [super setHidden:hide];
    [_sliderThumbView setHidden:hide];
}

/**
 @Status Stub
*/
- (void)setMaximumTrackTintColor:(UIColor*)color {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setMinimumTrackTintColor:(UIColor*)color {
    UNIMPLEMENTED();
}

@end
