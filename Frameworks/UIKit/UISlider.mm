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

#import <UIKit/UIView.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIImage.h>
#import <UIKit/UIImageView.h>
#import <UIKit/UIGestureRecognizer.h>
#import <UIKit/UISlider.h>

#import "UIViewInternal.h"
#import "UIGestureRecognizerInternal.h"
#import "CppWinRTHelpers.h"

#include "COMIncludes.h"
#import <winrt/Windows.UI.Xaml.Controls.h>
#import <winrt/Windows.UI.Xaml.Input.h>
#include "COMIncludes_End.h"

using namespace winrt::Windows::UI::Xaml;
namespace WF = winrt::Windows::Foundation;

static const double c_defaultStepFrequency = 0.1;

@implementation UISlider {
    BOOL _continuous;
    TrivialDefaultConstructor<Controls::Slider> _xamlSlider;

    winrt::event_token _manipulationStartingEvent;
    winrt::event_token _manipulationCompletedEvent;
    winrt::event_token _valueChangedEvent;
}

- (void)_initUISlider {
    // Store a strongly-typed backing slider
    _xamlSlider = [self _winrtXamlElement].as<Controls::Slider>();

    _xamlSlider.Maximum(1.0f);
    _xamlSlider.Minimum(0.0f);
    _xamlSlider.Value(0.0f);

    // by default, no tool tip for slider on reference platform
    _xamlSlider.IsThumbToolTipEnabled(false);

    [self _updateStepFrequency];
    [self setContinuous:YES];
    [self _registerForEventsWithXaml];
}

- (void)_updateStepFrequency {
    if (_xamlSlider) {
        // The frame size, minimumValue and maximumValue of UISlider can change dynamically, so we need to update the step frequency when they
        // do.
        if ((_xamlSlider.Maximum() - _xamlSlider.Minimum()) > 0 && self.frame.size.width > 0) {
            _xamlSlider.StepFrequency((_xamlSlider.Maximum() - _xamlSlider.Minimum()) / (self.frame.size.width));
        } else {
            _xamlSlider.StepFrequency(c_defaultStepFrequency);
        }
    }
}

/**
 @Status Interoperable
*/
- (void)setFrame:(CGRect)frame {
    [super setFrame:frame];
    [self _updateStepFrequency];
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        [self _initUISlider];

        if ([coder containsValueForKey:@"UIValue"]) {
            id valueStr = [coder decodeObjectForKey:@"UIValue"];
            _xamlSlider.Value([valueStr floatValue]);
        }

        if ([coder containsValueForKey:@"UIMaxValue"]) {
            _xamlSlider.Maximum([[coder decodeObjectForKey:@"UIMaxValue"] floatValue]);
        }
        if ([coder containsValueForKey:@"UIMinValue"]) {
            _xamlSlider.Minimum([[coder decodeObjectForKey:@"UIMinValue"] floatValue]);
        }
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self _initUISlider];
    }

    return self;
}

/**
 Microsoft Extension
*/
- (instancetype)initWithFrame:(CGRect)frame xamlElement:(RTObject*)xamlElement {
    if (self = [super initWithFrame:frame xamlElement:xamlElement]) {
        [self _initUISlider];
    }

    return self;
}

/**
 Microsoft Extension
*/
+ (RTObject*)createXamlElement {
    return objcwinrt::to_rtobj(Controls::Slider());
}

/**
 @Status Interoperable
*/
- (float)value {
    return _xamlSlider.Value();
}

/**
 @Status Interoperable
*/
- (void)setMinimumValue:(float)value {
    _xamlSlider.Minimum(value);
    [self _updateStepFrequency];
}

- (void)_registerForEventsWithXaml {
    __weak UISlider* weakSelf = self;

    _valueChangedEvent = _xamlSlider.ValueChanged(objcwinrt::callback([weakSelf] (const WF::IInspectable&, const RoutedEventArgs&) {
        __strong UISlider* strongSelf = weakSelf;

        if (strongSelf && strongSelf->_continuous) {
            [strongSelf _sendValueChangedEvents];
        }
    }));

    _xamlSlider.ManipulationMode(Input::ManipulationModes::All);

    // The value of a UISlider on ios cannot be changed by clicking anywhere on the track.
    // The thumb has to be hold and dragged.
    // On the other hand the value of a Xaml Slider can be changed by clicking anywhere on the track.
    // So we need manipulationStartingEvent when the value of Slider changes by clicking anywhere on
    // the track and not by dragging the thumb.
    // TODO: 7877568- Move to handling pointer events when available with projections, instead of manipulation events.
    _manipulationStartingEvent =
        _xamlSlider.ManipulationStarting(objcwinrt::callback([weakSelf] (const WF::IInspectable&, const RoutedEventArgs&) {
            __strong UISlider* strongSelf = weakSelf;

            if (strongSelf && strongSelf->_continuous == NO) {
                [strongSelf _sendValueChangedEvents];
            }
        }));

    // ManipulationCompleted will be fired when dragging has been completed
    // This allows us to fire UIControlEventValueChanged event and UIControlEventTouchUpInside event
    _manipulationCompletedEvent =
        _xamlSlider.ManipulationCompleted(objcwinrt::callback([weakSelf] (const WF::IInspectable&, const RoutedEventArgs&) {
            __strong UISlider* strongSelf = weakSelf;

            if (strongSelf && strongSelf->_continuous == NO) {
                [strongSelf _sendValueChangedEvents];
                [strongSelf sendActionsForControlEvents:UIControlEventTouchUpInside];
            }
        }));
}

- (void)_sendValueChangedEvents {
    [self sendActionsForControlEvents:UIControlEventValueChanged];
}
/**
 @Status Interoperable
*/
- (float)minimumValue {
    return _xamlSlider.Minimum();
}

/**
 @Status Interoperable
*/
- (void)setMaximumValue:(float)value {
    _xamlSlider.Maximum(value);
    [self _updateStepFrequency];
}

/**
 @Status Interoperable
*/
- (float)maximumValue {
    return _xamlSlider.Maximum();
}

/**
 @Status Interoperable
*/
- (void)setValue:(float)value {
    [self setValue:value animated:NO];
}

/**
 @Status Caveat
 @Notes animation is not supported
*/
- (void)setValue:(float)value animated:(BOOL)animated {
    _xamlSlider.Value(value);
}

/**
 @Status Interoperable
*/
- (void)setContinuous:(BOOL)continous {
    _continuous = continous;
}

/**
 @Status Interoperable
*/
- (BOOL)isContinuous {
    return _continuous;
}

/**
 @Status Stub
*/
- (void)setThumbImage:(UIImage*)image forState:(NSUInteger)state {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setMinimumTrackImage:(UIImage*)image forState:(NSUInteger)state {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setMinimumValueImage:(UIImage*)image {
    UNIMPLEMENTED();
}

- (void)dealloc {
    _xamlSlider.ManipulationStarting(_manipulationStartingEvent);
    _xamlSlider.ManipulationCompleted(_manipulationCompletedEvent);
    _xamlSlider.ValueChanged(_valueChangedEvent);
}

/**
 @Status Stub
*/
- (void)setMaximumValueImage:(UIImage*)image {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setMaximumTrackImage:(UIImage*)image forState:(NSUInteger)state {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UIImage*)currentThumbImage {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIImage*)currentMinimumTrackImage {
    UNIMPLEMENTED();
    return StubReturn();
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
