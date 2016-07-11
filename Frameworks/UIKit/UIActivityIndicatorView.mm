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
#import <UIKit/UIKit.h>
#import <UWP/WindowsUIXamlControls.h>

#import "AssertARCEnabled.h"
#import "XamlUtilities.h"

@implementation UIActivityIndicatorView {
    BOOL _hidesWhenStopped;
    BOOL _isAnimating;
    BOOL _startAnimating;
    StrongId<UIColor> _color;
    StrongId<WXCProgressRing> _progressRing;
    UIActivityIndicatorViewStyle _style;
}

/**
 @Status Caveat
 @When UINibUnArchiver have decodeCGrectForKey method. Code needs to be refactored.
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        [self _commonInit];

        if ([coder containsValueForKey:@"UIHidesWhenStopped"]) {
            [self setHidesWhenStopped:[coder decodeInt32ForKey:@"UIHidesWhenStopped"]];
        }
        if ([coder containsValueForKey:@"UIAnimating"]) {
            _startAnimating = [coder decodeInt32ForKey:@"UIAnimating"];
        }
        if ([coder containsValueForKey:@"UIActivityIndicatorViewStyle"]) {
            [self setActivityIndicatorViewStyle:(UIActivityIndicatorViewStyle)[coder decodeInt32ForKey:@"UIActivityIndicatorViewStyle"]];
        }
        CGRect frame = CGRectZero;
        if ([coder containsValueForKey:@"UIFrameX"]) {
            frame.origin.x = [coder decodeInt32ForKey:@"UIFrameX"];
        }
        if ([coder containsValueForKey:@"UIFrameY"]) {
            frame.origin.y = [coder decodeInt32ForKey:@"UIFrameY"];
        }
        if ([coder containsValueForKey:@"UIFrameWidth"]) {
            frame.size.width = [coder decodeInt32ForKey:@"UIFrameWidth"];
        }
        if ([coder containsValueForKey:@"UIFrameHeight"]) {
            frame.size.height = [coder decodeInt32ForKey:@"UIFrameHeight"];
        }
        [self setFrame:frame];
    }
    return self;
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)awakeFromNib {
    if (_startAnimating) {
        [self startAnimating];
    }
    [super awakeFromNib];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithActivityIndicatorStyle:(UIActivityIndicatorViewStyle)style {
    if (self = [super initWithFrame:CGRectMake(0, 0, 0, 0)]) {
        [self _commonInit];
        [self setActivityIndicatorViewStyle:style];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self _commonInit];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)setFrame:(CGRect)frame {
    if (_style == UIActivityIndicatorViewStyleWhite || _style == UIActivityIndicatorViewStyleGray) {
        frame.size.width = 32;
        frame.size.height = 32;
    } else if (_style == UIActivityIndicatorViewStyleWhiteLarge) {
        frame.size.width = 40;
        frame.size.height = 40;
    }
    [super setFrame:frame];
}

- (void)_commonInit {
    _progressRing = [WXCProgressRing make];
    [self setNativeElement:_progressRing];
    _isAnimating = FALSE;
    [self setHidesWhenStopped:TRUE];
    [self setActivityIndicatorViewStyle:UIActivityIndicatorViewStyleWhite];
}

/**
 @Status Caveat
 @Notes In iOS , when hideWhenStopped = False and isAnimating = False, it will show a pause UIAcivityIndicatorView. But, XAML don't have an
 API to show a pause Progress Ring.
 @Notes So when isAnimating = False, WinObjC can't show anything, but space is reserved.
*/
- (void)setHidesWhenStopped:(BOOL)shouldhide {
    _hidesWhenStopped = shouldhide;

    if (_hidesWhenStopped && !_isAnimating) {
        [self setHidden:TRUE];
    }
}

/**
 @Status Interoperable
*/
- (BOOL)hidesWhenStopped {
    return _hidesWhenStopped;
}

/**
 @Status Interoperable
*/
- (void)setActivityIndicatorViewStyle:(UIActivityIndicatorViewStyle)style {
    _style = style;
    if (style == UIActivityIndicatorViewStyleWhite || style == UIActivityIndicatorViewStyleGray) {
        self.frame = CGRectMake(0, 0, 32, 32);
    } else if (style == UIActivityIndicatorViewStyleWhiteLarge) {
        self.frame = CGRectMake(0, 0, 40, 40);
    }
    if (style == UIActivityIndicatorViewStyleGray) {
        [self setColor:[UIColor blackColor]];
    } else if (style == UIActivityIndicatorViewStyleWhite || style == UIActivityIndicatorViewStyleWhiteLarge) {
        [self setColor:[UIColor whiteColor]];
    }
}

/**
 @Status Interoperable
*/
- (UIActivityIndicatorViewStyle)activityIndicatorViewStyle {
    return _style;
}

/**
 @Status Interoperable
*/
- (void)startAnimating {
    if (_isAnimating) {
        return;
    }

    _isAnimating = TRUE;
    [self setHidden:FALSE];
    [_progressRing setIsActive:TRUE];
}

/**
 @Status Caveat
 @Notes Same issue as setHidesWhenStopped.
*/
- (void)stopAnimating {
    if (_isAnimating) {
        _isAnimating = FALSE;
    }

    [_progressRing setIsActive:FALSE];
    if (_hidesWhenStopped) {
        [self setHidden:TRUE];
    }
}

/**
 @Status Interoperable
*/
- (BOOL)isAnimating {
    return _isAnimating;
}

/**
 @Status Interoperable
*/
- (void)setColor:(UIColor*)color {
    [_progressRing setForeground:[WUXMSolidColorBrush makeInstanceWithColor:[XamlUtilities convertUIColorToWUColor:color]]];
    _color = color;
}

/**
 @Status Interoperable
*/
- (UIColor*)color {
    return _color;
}

@end
