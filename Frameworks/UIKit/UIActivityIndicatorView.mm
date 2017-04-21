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
    TrivialDefaultConstructor<Controls::ProgressRing> _progressRing;
    StrongId<UIView> _subView;

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
 @Note Frame will not be resized smaller than the contained ProgressRing, as this would obscure it.
*/
- (void)setFrame:(CGRect)frame {
    if (frame.size.width < [self _getXamlProgressRing].Width() || frame.size.height < [self _getXamlProgressRing].Height()) {
        int updatedFrameHeight =
            frame.size.height < [self _getXamlProgressRing].Height() ? [self _getXamlProgressRing].Height() : frame.size.height;
        int updatedFrameWidth =
            frame.size.width < [self _getXamlProgressRing].Width() ? [self _getXamlProgressRing].Width() : frame.size.width;
        frame = CGRectMake(frame.origin.x, frame.origin.y, updatedFrameWidth, updatedFrameHeight);
    }

    [super setFrame:frame];
}

- (void)_initUIActivityIndicatorView {
    [self _getXamlProgressRing];

    _isAnimating = NO;
    [self setHidden:NO]; // Ensure space is reserved in the layout. See notes for setHidesWhenStopped.
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
 @Note iOS accepts and defines behavior for undocumented style values for UIActivityIndicatorView. As there are undocumented by Apple, they
 are unsupported by WinObjC.
 @Note If the frame is smaller than the current size of the ProgressRing, it will be expanded to accomodate it. This may affect layouts. The
 frame will never be shrunken in size.
 @Note In iOS, the frame for UIActivityIndicatorView can be defined smaller than the indicator itself, and still render the indicator. In
 XAML, this would prevent the ProgressRing from being displayed.
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
        case UIActivityIndicatorViewStyleWhite: // Fallthrough intentional - always default to the white style for invalid values
        default:
            styleSquareLength = c_normalSquareLength;
            styleColor = [UIColor whiteColor];
            _style = UIActivityIndicatorViewStyleWhite; // Explicityly set the style to white to ignore invalid values
    }

    // Expand the frame size if it is not large enough to show the ProgressRing
    int updatedFrameHeight = self.frame.size.height < styleSquareLength ? styleSquareLength : self.frame.size.height;
    int updatedFrameWidth = self.frame.size.width < styleSquareLength ? styleSquareLength : self.frame.size.width;
    self.frame = CGRectMake(self.frame.origin.x, self.frame.origin.y, updatedFrameWidth, updatedFrameHeight);

    [self _getXamlProgressRing].Height(styleSquareLength);
    [self _getXamlProgressRing].Width(styleSquareLength);

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
            XamlControls::SetProgressRingIsActiveValue([self _winrtXamlElement], true);
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

            XamlControls::SetProgressRingIsActiveValue([self _winrtXamlElement], false);
        }
    });
}

/**
 @Status Interoperable
*/
- (BOOL)isAnimating {
    return XamlControls::GetProgressRingIsActiveValue([self _winrtXamlElement]);
}

/**
 @Status Interoperable
*/
- (void)setColor:(UIColor*)color {
    _color = color;

    winrt::Windows::UI::Color convertedColor = XamlUtilities::ConvertUIColorToWUColor(color);
    Media::SolidColorBrush brush = convertedColor;
    [self _getXamlProgressRing].Foreground(brush);
}

/**
 @Status Interoperable
*/
- (UIColor*)color {
    return _color;
}

/**
Microsoft Extension
*/
+ (RTObject*)createXamlElement {
    return objcwinrt::to_rtobj(XamlControls::CreateProgressRing());
}

// Exposes the underlying ProgressRing within UIActivityIndicator's Xaml representation
- (Controls::ProgressRing)_getXamlProgressRing {
    if (!_progressRing) {
        auto progressRingControl = [self _winrtXamlElement].try_as<Controls::Grid>();
        Controls::ProgressRing progressRing = nullptr;
        if (progressRingControl) {
            progressRing = XamlControls::XamlGetInternalProgressRing(progressRingControl);
        } else {
            progressRing = [self _winrtXamlElement].as<Controls::ProgressRing>();
        }

        if (!progressRing) {
            FAIL_FAST();
        }

        _progressRing = progressRing;
    }

    return _progressRing;
}

@end
