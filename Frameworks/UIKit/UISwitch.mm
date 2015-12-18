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
#include "CoreGraphics/CGContext.h"
#include "UIKit/UIImage.h"
#include "UIKit/UIImageView.h"
#include "UIKit/UIGestureRecognizer.h"
#include "UIKit/UISwitch.h"
#include <math.h>

const float minX = 0.0f, maxX = 50.0f;

@implementation UISwitch {
    bool _on;
    id _onView, _offView;
    id _selector;
    CGPoint _touchStart;
    float dragPos;
    bool _cancelDrag;
}

/**
 @Status Interoperable
*/
- (void)setOn:(BOOL)on {
    _on = on ? true : false;
    adjustImages(self, _on ? maxX : minX, false);
}

/**
 @Status Interoperable
*/
- (void)setOn:(BOOL)on animated:(BOOL)animated {
    _on = on ? true : false;
    adjustImages(self, _on ? maxX : minX, animated ? true : false);
}

/**
 @Status Stub
*/
- (void)setOnTintColor:(UIColor*)color {
    UNIMPLEMENTED();
}

- (void)setOffTintColor:(UIColor*)color {
}

/**
 @Status Interoperable
*/
- (BOOL)isOn {
    return _on ? TRUE : FALSE;
}

static void adjustImages(UISwitch* self, float pos, bool animated) {
    if (pos < minX) {
        pos = minX;
    }
    if (pos > maxX) {
        pos = maxX;
    }

    if (animated) {
        [UIView beginAnimations:@"MoveButton" context:nil];
        [UIView setAnimationDuration:0.25f];
    }

    CGRect frame = { 0 };
    frame = [self->_offView frame];
    frame.size.width = pos;
    [self->_offView setFrame:frame];

    frame = [self->_selector frame];
    frame.origin.x = pos + 5.0f;
    [self->_selector setFrame:frame];

    if (animated) {
        [UIView commitAnimations];
    }
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)pos {
    pos.size.width = 48;
    pos.size.height = 20;
    [super initWithFrame:pos];

    [self setOpaque:FALSE];
    _onView = [[[UIImageView alloc] initWithImage:[UIImage imageNamed:@"/img/switch-off@2x.png"]] autorelease];
    id off = [[[UIImageView alloc] initWithImage:[UIImage imageNamed:@"/img/switch-on@2x.png"]] autorelease];
    _selector = [[[UIImageView alloc] initWithImage:[UIImage imageNamed:@"/img/switch-selector@2x.png"]] autorelease];
    [_selector setUserInteractionEnabled:TRUE];

    pos = [off bounds];
    _offView = [[[UIView alloc] initWithFrame:pos] autorelease];
    [_offView setClipsToBounds:TRUE];
    [_offView addSubview:off];

    id panGesture = [[[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(_didPan:)] autorelease];
    [panGesture setDelegate:self];
    [panGesture _setDragSlack:0.0f];
    [self addGestureRecognizer:(id)panGesture];
    id tapGesture = [[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(_didTap:)] autorelease];
    [tapGesture setDelegate:self];
    [self addGestureRecognizer:(id)tapGesture];

    [self addSubview:_onView];
    [self addSubview:_offView];
    [self addSubview:_selector];

    adjustImages(self, _on ? maxX : minX, false);

    return self;
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    _on = [coder decodeBoolForKey:@"UISwitchOn"] ? true : false;
    [super initWithCoder:coder];

    [self setOpaque:FALSE];
    _onView = [[[UIImageView alloc] initWithImage:[UIImage imageNamed:@"/img/switch-off@2x.png"]] autorelease];
    id off = [[[UIImageView alloc] initWithImage:[UIImage imageNamed:@"/img/switch-on@2x.png"]] autorelease];
    _selector = [[[UIImageView alloc] initWithImage:[UIImage imageNamed:@"/img/switch-selector@2x.png"]] autorelease];
    [_selector setUserInteractionEnabled:TRUE];

    CGRect pos;
    pos = [off bounds];
    _offView = [[[UIView alloc] initWithFrame:pos] autorelease];
    [_offView setClipsToBounds:TRUE];
    [_offView addSubview:off];

    id panGesture = [[[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(_didPan:)] autorelease];
    [panGesture setDelegate:self];
    [panGesture _setDragSlack:0.0f];
    [self addGestureRecognizer:(id)panGesture];
    id tapGesture = [[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(_didTap:)] autorelease];
    [tapGesture setDelegate:self];
    [self addGestureRecognizer:(id)tapGesture];

    [self addSubview:_onView];
    [self addSubview:_offView];
    [self addSubview:_selector];

    adjustImages(self, _on ? maxX : minX, false);

    return self;
}

- (void)_didPan:(id)gesture {
    DWORD state = [gesture state];

    if (state != UIGestureRecognizerStateBegan && _cancelDrag) {
        return;
    }

    CGPoint amt;
    amt = [gesture translationInView:self];
    [gesture setTranslation:CGPointMake(0, 0) inView:self];

    if (state == UIGestureRecognizerStateEnded) {
        bool finalValue;
        dragPos += amt.x;
        if (dragPos > (minX + maxX) / 2.0f) {
            finalValue = true;
        } else {
            finalValue = false;
        }

        if (finalValue != _on) {
            _on = finalValue;
            [self sendEvent:self mask:UIControlEventValueChanged];
        }

        if (_on) {
            adjustImages(self, maxX, true);
        } else {
            adjustImages(self, minX, true);
        }
    } else if (state == UIGestureRecognizerStateBegan) {
        _cancelDrag = false;
        if (_on) {
            dragPos = maxX;
        } else {
            dragPos = minX;
        }
    }

    if (state == UIGestureRecognizerStateBegan || state == UIGestureRecognizerStateChanged) {
        dragPos += amt.x;
        adjustImages(self, dragPos, false);
    }
}

- (void)_didTap:(UIGestureRecognizer*)gesture {
    bool finalValue;

    _cancelDrag = true;
    if (_on) {
        finalValue = false;
    } else {
        finalValue = true;
    }

    if (finalValue != _on) {
        _on = finalValue;
        [self sendEvent:self mask:UIControlEventValueChanged];
    }

    if (_on) {
        adjustImages(self, maxX, true);
    } else {
        adjustImages(self, minX, true);
    }
}

@end
