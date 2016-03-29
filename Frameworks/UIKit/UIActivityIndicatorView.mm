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
#import "UIKit/UIKit.h"

@implementation UIActivityIndicatorView {
    BOOL hidesWhenStopped, isAnimating;
    idretaintype(UIColor) _color;
    BOOL startAnimating;
    BOOL _addedAnimation;
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
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

/**
 @Status Interoperable
*/
- (void)awakeFromNib {
    if (startAnimating) {
        [self startAnimating];
    }
    [super awakeFromNib];
}

/**
 @Status Caveat
 @Notes style parameter not supported
*/
- (instancetype)initWithActivityIndicatorStyle:(UIActivityIndicatorViewStyle)style {
    CGRect frame;

    frame.origin.x = 100;
    frame.origin.y = 100;
    frame.size.width = 100;
    frame.size.height = 100;

    return [self initWithFrame:frame];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    [super initWithFrame:frame];

    [self setHidesWhenStopped:TRUE];
    [self setUserInteractionEnabled:TRUE];
    _color = [UIColor whiteColor];
    UIImage* image = [UIImage imageNamed:@"/img/activity@2x.png"];
    [[self layer] setContents:(id)[image CGImage]];
    [[self layer] setContentsScale:[image scale]];
    [[self layer] setContentsGravity:kCAGravityCenter];

    return self;
}

/**
 @Status Interoperable
*/
- (void)setHidesWhenStopped:(BOOL)shouldhide {
    hidesWhenStopped = shouldhide;

    if (hidesWhenStopped && !isAnimating) {
        [self setHidden:TRUE];
    }
}

/**
 @Status Interoperable
*/
- (BOOL)hidesWhenStopped {
    return hidesWhenStopped;
}

static void addAnimation(UIActivityIndicatorView* self) {
    if (!self->isAnimating) {
        return;
    }

    if (!self->_addedAnimation) {
        CABasicAnimation* animation = [CABasicAnimation animationWithKeyPath:@"transform.rotation.z"];
        [animation setToValue:[NSNumber numberWithFloat:M_PI * 2]];
        [animation setFromValue:[NSNumber numberWithFloat:0.0f]];
        [animation setDuration:1.0f];
        [animation setBeginTime:CACurrentMediaTime()];
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

/**
 @Status Interoperable
*/
- (void)startAnimating {
    if (isAnimating) {
        return;
    }

    isAnimating = TRUE;
    [self setHidden:FALSE];
    if ([self window] != nil) {
        addAnimation(self);
    }
}

/**
 @Status Interoperable
*/
- (void)stopAnimating {
    if (isAnimating) {
        isAnimating = FALSE;
        removeAnimation(self);
    }

    if (hidesWhenStopped) {
        [self setHidden:TRUE];
    }
}

/**
 @Status Interoperable
*/
- (BOOL)isAnimating {
    return isAnimating;
}

/**
 @Status Interoperable
*/
- (void)willMoveToWindow:(UIWindow*)window {
    if (window != nil) {
        addAnimation(self);
    } else {
        removeAnimation(self);
    }
}

/**
 @Status Interoperable
*/
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    // No-op
}

/**
 @Status Interoperable
*/
- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
    // No-op
}

/**
 @Status Interoperable
*/
- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    // No-op
}

/**
 @Status Stub
*/
- (void)setColor:(UIColor*)color {
    UNIMPLEMENTED();
    _color = color;
}

/**
 @Status Stub
*/
- (UIColor*)color {
    UNIMPLEMENTED();
    return _color;
}

/**
 @Status Interoperable
 @Notes Always returns NO
*/
- (BOOL)isUserInteractionEnabled {
    return NO;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [super dealloc];
}
@end
