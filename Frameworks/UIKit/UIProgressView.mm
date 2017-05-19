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
#import <UIKit/UIProgressView.h>
#include <UIKit/UIColor.h>
#include <UIKit/UIImage.h>

#import "UIViewInternal.h"
#import "XamlControls.h"
#import "XamlUtilities.h"
#import "CppWinRTHelpers.h"

using namespace winrt::Windows::UI::Xaml;

static const wchar_t* TAG = L"UIProgressView";

static void* ProgressViewObservedProgressContext = &ProgressViewObservedProgressContext;

// NOTE: These sizes match what iOS uses natively
static const double c_defaultStyleHeight = 2.0;
static const double c_barStyleHeight = 2.5;

@implementation UIProgressView {
    float _value;
    UIProgressViewStyle _progressViewStyle;

    StrongId<NSProgress> _observedProgress;
    StrongId<UIColor> _trackTint;
    StrongId<UIColor> _progressTint;
    StrongId<UIImage> _trackImage;
    StrongId<UIImage> _progressImage;
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        if ([coder containsValueForKey:@"UIProgressViewStyle"]) {
            [self setProgressViewStyle:(UIProgressViewStyle)[coder decodeInt32ForKey:@"UIProgressViewStyle"]];
        } else {
            [self setProgressViewStyle:UIProgressViewStyleDefault];
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
        [self setFrame:frame];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self setProgressViewStyle:UIProgressViewStyleDefault];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)setFrame:(CGRect)frame {
    CGRect updatedFrame = [self _limitFrameHeight:frame];
    [super setFrame:updatedFrame];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithProgressViewStyle:(UIProgressViewStyle)style {
    if (self = [super init]) {
        [self setProgressViewStyle:style];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)setProgressViewStyle:(UIProgressViewStyle)style {

    // Ensure the default style is always set for anything other than the bar style, to ignore invalid styles
    if (style == UIProgressViewStyleBar) {
        _progressViewStyle = UIProgressViewStyleBar;
    } else {
        _progressViewStyle = UIProgressViewStyleDefault;
    }

    // Set track and progress fill appropriately
    [self _updateProgressStyle];
    [self _updateTrackStyle];

    // Ensure the frame gets updated for this style
    [self setFrame:[self frame]];
}

/**
 Constricts the frame height to match the size iOS uses natively.
 NOTE: On iOS, the UIProgressView height is always limited in this way.
*/
- (CGRect)_limitFrameHeight:(CGRect)frame {
    double styleHeight;

    // It is safe to only check for the default style here because the style is guaranteed to be valid by setProgresViewStyle
    if (_progressViewStyle == UIProgressViewStyleDefault) {
        styleHeight = c_defaultStyleHeight;
    } else {
        styleHeight = c_barStyleHeight;
    }

    return CGRectMake(frame.origin.x, frame.origin.y, frame.size.width, styleHeight);
}

/**
 @Status Interoperable
*/
- (UIProgressViewStyle)progressViewStyle {
    return _progressViewStyle;
}

/**
 @Status Interoperable
*/
- (void)setObservedProgress:(NSProgress*)progress {
    if (progress) {
        _observedProgress = progress;

        [_observedProgress addObserver:self
                            forKeyPath:@"fractionCompleted"
                               options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionInitial
                               context:ProgressViewObservedProgressContext];
    } else {
        [_observedProgress removeObserver:self forKeyPath:@"fractionCompleted" context:ProgressViewObservedProgressContext];

        _observedProgress = nil;
    }
}

/**
 @Status Interoperable
*/
- (NSProgress*)observedProgress {
    return _observedProgress;
}

/**
 @Status Interoperable
*/
- (void)observeValueForKeyPath:(NSString*)keyPath ofObject:(id)object change:(NSDictionary*)change context:(void*)context {

    // Ensure this notification was meant for us, otherwise send it to super
    if (context == (void*)ProgressViewObservedProgressContext) {

        // Ensure the value changed
        if ([[change objectForKey:NSKeyValueChangeKindKey] integerValue] == NSKeyValueChangeSetting) {
            NSValue* newValue = [change objectForKey:NSKeyValueChangeNewKey];

            // Ensure we got a value, and it is of the expected type
            if (newValue && strncmp([newValue objCType], @encode(double), 1) == 0) {
                double fractionCompleted = 0.0;
                [newValue getValue:&fractionCompleted];
                [self setProgress:fractionCompleted];
            }
        }
    } else {
        [super observeValueForKeyPath:keyPath ofObject:object change:change context:context];
    }
}

/**
 @Status Interoperable
*/
- (void)setProgress:(float)progress {
    _value = progress;
    XamlControls::SetProgressViewValue([self _winrtXamlElement], _value);
}

/**
 @Status Caveat
 @Notes animation parameter not supported
*/
- (void)setProgress:(float)progress animated:(BOOL)animated {
    [self setProgress:progress];
}

/**
 @Status Interoperable
*/
- (void)setProgressTintColor:(UIColor*)color {
    _progressTintColor = color;
    _progressImage = nil;

    [self _updateProgressStyle];
}

/**
 @Status Interoperable
*/
- (void)setTrackTintColor:(UIColor*)color {
    _trackTintColor = color;
    _trackImage = nil;

    [self _updateTrackStyle];
}

/**
 @Status Interoperable
*/
- (void)setTrackImage:(UIImage*)image {
    _trackImage = image;
    _trackTintColor = nil;

    [self _updateTrackStyle];
}

/**
 @Status Interoperable
*/
- (void)setProgressImage:(UIImage*)image {
    _progressImage = image;
    _progressTintColor = nil;

    [self _updateProgressStyle];
}

/**
 @Status Interoperable
*/
- (UIImage*)trackImage {
    return _trackImage;
}

/**
 @Status Interoperable
*/
- (UIImage*)progressImage {
    return _progressImage;
}

/**
 @Status Interoperable
*/
- (float)progress {
    return XamlControls::GetProgressViewValue([self _winrtXamlElement]);
}

/**
 Updates the progress fill based on if we have set a tint, image, or neither.
*/
- (void)_updateProgressStyle {
    if (_progressImage) {
        [self _setProgressViewForegroundImage:_progressImage];
    } else {
        UIColor* progressColor;

        // Use the tint color if set, otherwise use the default
        if (_progressTintColor) {
            progressColor = _progressTintColor;
        } else {

            // This matches what iOS uses natively
            progressColor = [UIColor colorWithRed:0.5 green:0.48 blue:1.0 alpha:1.0];
        }

        [self _setProgressViewForegroundColor:progressColor];
    }
}

/**
 Updates the track based on if we have set a tint, image, or neither.
*/
- (void)_updateTrackStyle {
    if (_trackImage) {
        [self _setProgressViewBackgroundImage:_trackImage];
    } else {
        UIColor* trackColor;

        // Use the tint color if set, otherwise use the default for the current style
        if (_trackTintColor) {
            trackColor = _trackTintColor;

            // It is safe to only check for the default style here because the style is guaranteed to be valid by setProgresViewStyle
        } else if (_progressViewStyle == UIProgressViewStyleDefault) {

            // These colors match what iOS uses natively
            trackColor = [UIColor colorWithWhite:0.72 alpha:1.0];
        } else {
            trackColor = [UIColor whiteColor];
        }

        [self _setProgressViewBackgroundColor:trackColor];
    }
}

/**
 Sets the backing XAML control's foreground to the given color
*/
- (void)_setProgressViewForegroundColor:(UIColor*)color {
    winrt::Windows::UI::Color convertedColor = XamlUtilities::ConvertUIColorToWUColor(color);
    Media::SolidColorBrush brush = convertedColor;
    XamlControls::SetProgressViewForegroundValue([self _winrtXamlElement], brush);
}

/**
 Sets the backing XAML control's foreground to the given image
*/
- (void)_setProgressViewForegroundImage:(UIImage*)image {
    Media::ImageBrush brush = XamlUtilities::ConvertUIImageToWUXMImageBrush(image);
    XamlControls::SetProgressViewForegroundValue([self _winrtXamlElement], brush);
}

/**
 Sets the backing XAML control's background to the given color
*/
- (void)_setProgressViewBackgroundColor:(UIColor*)color {
    winrt::Windows::UI::Color convertedColor = XamlUtilities::ConvertUIColorToWUColor(color);
    Media::SolidColorBrush brush = convertedColor;
    XamlControls::SetProgressViewBackgroundValue([self _winrtXamlElement], brush);
}

/**
 Sets the backing XAML control's background to the given image
*/
- (void)_setProgressViewBackgroundImage:(UIImage*)image {
    Media::ImageBrush brush = XamlUtilities::ConvertUIImageToWUXMImageBrush(image);
    XamlControls::SetProgressViewBackgroundValue([self _winrtXamlElement], brush);
}

/**
 Microsoft Extension
*/
+ (RTObject*)createXamlElement {
    return objcwinrt::to_rtobj(XamlControls::CreateProgressView());
}

- (void)dealloc {
    [_observedProgress removeObserver:self forKeyPath:@"fractionCompleted" context:ProgressViewObservedProgressContext];
}

@end
