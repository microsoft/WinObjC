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

#import "AssertARCEnabled.h"
#import <Starboard.h>
#import <StubReturn.h>
#import "XamlUtilities.h"

#import <UWP/WindowsUIXamlControls.h>

static const int c_normalSquareLength = 20;
static const int c_largeSquareLength = 37;

@implementation UIActivityIndicatorView {
    BOOL _hidesWhenStopped;
    BOOL _isAnimating;
    BOOL _startAnimating;

    StrongId<UIColor> _color;
    StrongId<WXCProgressRing> _progressRing;
    StrongId<UIView> _subView;

    UIActivityIndicatorViewStyle _style;
}

/**
 @Status Caveat
 @When UINibUnArchiver have decodeCGrectForKey method. Code needs to be refactored.
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        [self _UIActivityIndicatorView_initInternal:nil];

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
    if (self = [super initWithFrame:CGRectZero]) {
        [self _UIActivityIndicatorView_initInternal:nil];
        [self setActivityIndicatorViewStyle:style];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    return [self _initWithFrame:frame xamlElement:nil];
}

- (instancetype)_initWithFrame:(CGRect)frame xamlElement:(WXFrameworkElement*)xamlElement {
    if (self = [super initWithFrame:frame]) {
        [self _UIActivityIndicatorView_initInternal:xamlElement];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)setFrame:(CGRect)frame {
    [super setFrame:frame];

    _subView.center = { self.center.x - self.frame.origin.x, self.center.y - self.frame.origin.y };
}

- (void)_UIActivityIndicatorView_initInternal:(WXFrameworkElement*)xamlElement {
    if (xamlElement != nil && [xamlElement isKindOfClass:[WXCProgressRing class]]) {
        _progressRing = static_cast<WXCProgressRing*>(xamlElement);
    } else {
        _progressRing = [WXCProgressRing make];
    }

    _subView = [[UIView alloc] initWithFrame:CGRectZero];

    [_subView setXamlElement:_progressRing];
    [self addSubview:_subView];

    _isAnimating = NO;
    [self setHidesWhenStopped:YES];
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
        [self setHidden:YES];
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

    int squareLength = 0;
    if (style == UIActivityIndicatorViewStyleWhite || style == UIActivityIndicatorViewStyleGray) {
        squareLength = c_normalSquareLength;
    } else if (style == UIActivityIndicatorViewStyleWhiteLarge) {
        squareLength = c_largeSquareLength;
    }

    float tempWidth = (self.frame.size.width > squareLength) ? self.frame.size.width : squareLength;
    float tempHeight = (self.frame.size.height > squareLength) ? self.frame.size.height : squareLength;

    self.frame = CGRectMake(self.frame.origin.x, self.frame.origin.y, tempWidth, tempHeight);
    _subView.frame = CGRectMake(0, 0, squareLength, squareLength);
    _subView.center = { self.center.x - self.frame.origin.x, self.center.y - self.frame.origin.y };

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

    _isAnimating = YES;
    [self setHidden:NO];
    [_progressRing setIsActive:YES];
}

/**
 @Status Caveat
 @Notes Same issue as setHidesWhenStopped.
*/
- (void)stopAnimating {
    if (_isAnimating) {
        _isAnimating = NO;
    }

    [_progressRing setIsActive:YES];
    if (_hidesWhenStopped) {
        [self setHidden:NO];
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
    _color = color;

    WUColor* convertedColor = ConvertUIColorToWUColor(color);
    WUXMSolidColorBrush* brush = [WUXMSolidColorBrush makeInstanceWithColor:convertedColor];
    [_progressRing setForeground:brush];
}

/**
 @Status Interoperable
*/
- (UIColor*)color {
    return _color;
}

@end
