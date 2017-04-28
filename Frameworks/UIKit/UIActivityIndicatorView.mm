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

#import "UIViewInternal.h"
#import "XamlControls.h"
#import "XamlUtilities.h"
#import "CppWinRTHelpers.h"

#include "COMIncludes.h"
#import <winrt/Windows.UI.Xaml.Controls.h>
#include "COMIncludes_End.h"

using namespace winrt::Windows::UI::Xaml;

static const wchar_t* TAG = L"UIActivityIndicatorView";

// NOTE: These sizes match what iOS uses natively
static const int c_normalSquareLength = 20;
static const int c_largeSquareLength = 37;

@implementation UIActivityIndicatorView {
    BOOL _hidesWhenStopped;
    BOOL _isAnimating;
    BOOL _startAnimating;

    StrongId<UIColor> _color;
    UIActivityIndicatorViewStyle _style;
}

/**
 @Status Caveat
 @When UINibUnArchiver have decodeCGrectForKey method. Code needs to be refactored.
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        [self _initUIActivityIndicatorView];

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
 @Status NotInPlan
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
        [self _initUIActivityIndicatorView];
        [self setActivityIndicatorViewStyle:style];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self _initUIActivityIndicatorView];
    }

    return self;
}

/**
 Microsoft Extension
*/
- (instancetype)initWithFrame:(CGRect)frame xamlElement:(RTObject*)xamlElement {
    if (self = [super initWithFrame:frame xamlElement:xamlElement]) {
        [self _initUIActivityIndicatorView];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)setFrame:(CGRect)frame {
    [super setFrame:frame];
}

- (void)_initUIActivityIndicatorView {
    _isAnimating = NO;
    [self setHidesWhenStopped:YES];
    [self setActivityIndicatorViewStyle:UIActivityIndicatorViewStyleWhite];
    [self setUserInteractionEnabled:NO];
}

/**
 @Status Caveat
 @Notes In iOS, when hideWhenStopped = False and isAnimating = False, it will show a paused UIAcivityIndicatorView. But, XAML doesn't have
 an API to show a paused ProgressRing.
 @Notes So when isAnimating = False, WinObjC can't show anything, but space is reserved.
 @Notes UIActivityIndicatorView.hidden will not be set to YES from within this view. UWP XAML does not support a Visibility of Hidden, only
 Collapsed (which would not reserve space in the layout).
 @Notes Instead of hiding the view, its alpha will be set to 0.0 to emulate this behavior while allowing space to be reserved in the layout.
 */
- (void)setHidesWhenStopped:(BOOL)shouldhide {
    _hidesWhenStopped = shouldhide;

    if (!_isAnimating) {
        self.alpha = _hidesWhenStopped ? 0.0 : 1.0;
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
 @Note Any value other than the officially documented UIActivityIndicatorViewStyle values will be ignored, and the style will default back
 to UIActivityIndicatorViewStyleWhite.
 @Note iOS accepts and defines behavior for undocumented style values for UIActivityIndicatorView. As these are undocumented by Apple, they
 are unsupported by WinObjC.
*/
- (void)setActivityIndicatorViewStyle:(UIActivityIndicatorViewStyle)style {
    _style = style;

    int styleSquareLength;
    UIColor* styleColor;

    switch (style) {
        case UIActivityIndicatorViewStyleWhiteLarge:
            styleSquareLength = c_largeSquareLength;
            styleColor = [UIColor whiteColor];
            break;
        case UIActivityIndicatorViewStyleGray:
            styleSquareLength = c_normalSquareLength;

            // This color matches what iOS uses internally for the gray style.
            // NOTE: UIColor.grayColor differs slightly from this. Its components are W:0.5, A:1.0
            styleColor = [UIColor colorWithWhite:0.0 alpha:0.45];
            break;
        case UIActivityIndicatorViewStyleWhite:
        // Fallthrough intentional - always default to the white style for invalid values
        default:
            styleSquareLength = c_normalSquareLength;
            styleColor = [UIColor whiteColor];

            // Explicityly set the style to white to ignore invalid values
            _style = UIActivityIndicatorViewStyleWhite;
    }

    XamlControls::SetActivityIndicatorViewHeightValue([self _winrtXamlElement], styleSquareLength);
    XamlControls::SetActivityIndicatorViewWidthValue([self _winrtXamlElement], styleSquareLength);

    [self setColor:styleColor];
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
    RunSynchronouslyOnMainThread(^{
        if (!_isAnimating) {
            _isAnimating = YES;
            [self setHidden:NO];
            [self setAlpha:1.0];
            XamlControls::SetActivityIndicatorViewIsActiveValue([self _winrtXamlElement], true);
        }
    });
}

/**
 @Status Caveat
 @Notes Same issue as setHidesWhenStopped.
*/
- (void)stopAnimating {
    RunSynchronouslyOnMainThread(^{
        if (_isAnimating) {
            _isAnimating = NO;

            if (_hidesWhenStopped) {
                // Make our view transparent, rather than hidden, to ensure space is reserved in the layout.
                [self setAlpha:0.0];
            }

            XamlControls::SetActivityIndicatorViewIsActiveValue([self _winrtXamlElement], false);
        }
    });
}

/**
 @Status Interoperable
*/
- (BOOL)isAnimating {
    return XamlControls::GetActivityIndicatorViewIsActiveValue([self _winrtXamlElement]);
}

/**
 @Status Interoperable
*/
- (void)setColor:(UIColor*)color {
    _color = color;

    winrt::Windows::UI::Color convertedColor = XamlUtilities::ConvertUIColorToWUColor(color);
    Media::SolidColorBrush brush = convertedColor;
    XamlControls::SetActivityIndicatorViewForegroundValue([self _winrtXamlElement], brush);
}

/**
 @Status Interoperable
*/
- (UIColor*)color {
    if (!_color) {
        Media::SolidColorBrush brush = XamlControls::GetActivityIndicatorViewForegroundValue([self _winrtXamlElement]);
        winrt::Windows::UI::Color brushColor = brush.Color();
        _color = XamlUtilities::ConvertWUColorToUIColor(brushColor);
    }
    return _color;
}

/**
Microsoft Extension
*/
+ (RTObject*)createXamlElement {
    return objcwinrt::to_rtobj(XamlControls::CreateActivityIndicatorView());
}

@end
