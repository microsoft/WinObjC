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
#include "UIKit/UIKit.h"

@implementation UIActivityIndicatorView {
    BOOL hidesWhenStopped, isAnimating;
    idretaintype(UIColor) _color;
    BOOL startAnimating;
    BOOL _addedAnimation;
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    [super initWithCoder:coder];
    _color = [UIColor whiteColor];
    [self setUserInteractionEnabled:TRUE];
    UIImage* image = [UIImage imageNamed:@"/img/activity@2x.png"];
    [[self layer] setContents:(id)[image CGImage]];
    [[self layer] setContentsScale:1.2f * [image scale]];
    [[self layer] setContentsGravity:kCAGravityCenter];

    if ([coder containsValueForKey:@"UIHidesWhenStopped"]) {
        [self setHidesWhenStopped:[coder decodeInt32ForKey:@"UIHidesWhenStopped"]];
    } else {
        [self setHidesWhenStopped:TRUE];
    }
    if ([coder containsValueForKey:@"UIAnimating"]) {
        startAnimating = [coder decodeInt32ForKey:@"UIAnimating"];
    }

    return self;
}

- (void)awakeFromNib {
    if (startAnimating)
        [self startAnimating];
    [super awakeFromNib];
}

- (instancetype)initWithActivityIndicatorStyle:(UIActivityIndicatorViewStyle)style {
    CGRect frame;

    frame.origin.x = 100;
    frame.origin.y = 100;
    frame.size.width = 100;
    frame.size.height = 100;

    return [self initWithFrame:frame];
}

- (instancetype)initWithFrame:(CGRect)frame {
    [super initWithFrame:frame];

    [self setHidesWhenStopped:TRUE];
    [self setUserInteractionEnabled:TRUE];
    _color = [UIColor whiteColor];
    id image = [UIImage imageNamed:@"/img/activity@2x.png"];
    [[self layer] setContents:(id)[image CGImage]];
    [[self layer] setContentsScale:[image scale]];
    [[self layer] setContentsGravity:kCAGravityCenter];

    return self;
}

- (void)setActivityIndicatorViewStyle:(UIActivityIndicatorViewStyle)style {
}

- (void)setHidesWhenStopped:(BOOL)shouldhide {
    hidesWhenStopped = shouldhide;

    if (hidesWhenStopped && !isAnimating)
        [self setHidden:TRUE];
}

- (BOOL)hidesWhenStopped {
    return hidesWhenStopped;
}

static void addAnimation(UIActivityIndicatorView* self) {
    if (!self->isAnimating)
        return;

    if (!self->_addedAnimation) {
        CABasicAnimation* animation = [CABasicAnimation animationWithKeyPath:@"transform.rotation.z"];
        [animation setToValue:[NSNumber numberWithFloat:M_PI * 2]];
        [animation setFromValue:[NSNumber numberWithFloat:0.0f]];
        [animation setDuration:1.0f];
        [animation setRepeatCount:300000.0f];
        [animation setTimingFunction:[CAMediaTimingFunction functionWithName:@"kCAMediaTimingFunctionLinear"]];
        [[self layer] addAnimation:animation forKey:@"RotateAnim"];
        self->_addedAnimation = TRUE;
    }
}

static void removeAnimation(UIActivityIndicatorView* self) {
    if (self->_addedAnimation) {
        [[self layer] removeAllAnimations];
        self->_addedAnimation = FALSE;
    }
}

- (void)startAnimating {
    if (isAnimating)
        return;

    isAnimating = TRUE;
    [self setHidden:FALSE];
    if ([self window] != nil) {
        addAnimation(self);
    }
}

- (void)stopAnimating {
    if (isAnimating) {
        isAnimating = FALSE;
        removeAnimation(self);
    }

    if (hidesWhenStopped)
        [self setHidden:TRUE];
}

- (BOOL)isAnimating {
    return isAnimating;
}

- (void)willMoveToWindow:(UIWindow*)window {
    if (window != nil) {
        addAnimation(self);
    } else {
        removeAnimation(self);
    }
}

- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
}

- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
}

- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
}

- (void)setColor:(UIColor*)color {
    _color = color;
}

- (UIColor*)color {
    return _color;
}

- (BOOL)isUserInteractionEnabled {
    return 0;
}

- (void)dealloc {
    [super dealloc];
}
@end
