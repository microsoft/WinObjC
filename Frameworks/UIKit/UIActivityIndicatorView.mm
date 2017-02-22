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

#import <UIKit/NSObject+UIKitAdditions.h>
#import <UIKit/UIActivityIndicatorView.h>
#import <UIKit/UIColor.h>

#import "XamlUtilities.h"
#import "CppWinRTHelpers.h"

#include "COMIncludes.h"
#import <winrt/Windows.UI.Xaml.Controls.h>
#include "COMIncludes_End.h"

using namespace winrt::Windows::UI::Xaml;

static const int c_normalSquareLength = 20;
static const int c_largeSquareLength = 37;

// Data members can only be default-constructed, so create a wrapper for ProgressRing
// that has a trivial default constructor
struct ProgressRing : Controls::ProgressRing {
    ProgressRing() : Controls::ProgressRing(nullptr) {
    }

    auto operator=(Controls::ProgressRing&& other) {
        return Controls::ProgressRing::operator=(std::move(other));
    }
};

@implementation UIActivityIndicatorView {
    BOOL _hidesWhenStopped;
    BOOL _isAnimating;
    BOOL _startAnimating;

    StrongId<UIColor> _color;
    ProgressRing _progressRing;
    StrongId<UIView> _subView;

    UIActivityIndicatorViewStyle _style;
}

/**
 @Status Caveat
 @When UINibUnArchiver have decodeCGrectForKey method. Code needs to be refactored.
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        [self _initUIActivityIndicatorView:nil];

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
        [self _initUIActivityIndicatorView:nil];
        [self setActivityIndicatorViewStyle:style];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self _initUIActivityIndicatorView:nil];
    }

    return self;
}

/**
 Microsoft Extension
*/
- (instancetype)initWithFrame:(CGRect)frame xamlElement:(RTObject*)xamlElement {
    // TODO: We're passing nil to initWithFrame:xamlElement: because we have to *contain* a _subview for padding/layout.
    // Note: Pass 'xamlElement' instead, once we move to a *single* backing Xaml element for UIActivityIndicatorView.
    if (self = [super initWithFrame:frame xamlElement:nil]) {
        [self _initUIActivityIndicatorView:xamlElement];
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

- (void)_initUIActivityIndicatorView:(RTObject*)xamlElement {
    if (xamlElement != nil) {
        _progressRing = objcwinrt::from_rtobj<Controls::ProgressRing>(xamlElement);
    }

    if (!_progressRing) {
        _progressRing = Controls::ProgressRing();
    }

    // TODO: We should move this over to a single Xaml element which we return from a createXamlElement implementation.
    //       Which would also mean that we'd just reach into [self xamlElement] to get the backing _progressRing,
    //       and we would no longer have a _subview.
    //_subView = [[UIView alloc] initWithFrame:CGRectZero xamlElement:_progressRing];
    [self addSubview:_subView];
    _isAnimating = NO;
    [self setHidesWhenStopped:YES];
    [self setActivityIndicatorViewStyle:UIActivityIndicatorViewStyleWhite];
    [self setUserInteractionEnabled:NO];
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
    _progressRing.IsActive(true);
    //[_progressRing setIsActive:YES];
}

/**
 @Status Caveat
 @Notes Same issue as setHidesWhenStopped.
*/
- (void)stopAnimating {
    if (_isAnimating) {
        _isAnimating = NO;
    }

    _progressRing.IsActive(false);
    //[_progressRing setIsActive:NO];
    if (_hidesWhenStopped) {
        [self setHidden:YES];
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

    winrt::Windows::UI::Color convertedColor = XamlUtilities::ConvertUIColorToWUColor(color);
    Media::SolidColorBrush brush = convertedColor;
    _progressRing.Foreground(brush);
}

/**
 @Status Interoperable
*/
- (UIColor*)color {
    return _color;
}

@end
