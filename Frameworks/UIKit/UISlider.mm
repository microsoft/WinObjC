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

#import "UIGestureRecognizerInternal.h"

#import "UWP/WindowsUIXamlControls.h"

static const double c_defaultStepFrequency = 0.1;

@implementation UISlider {
    BOOL _continuous;

    // Since xaml Slider does not support minimumValueImage and maximumValueImage, hence we have
    // _rootPanel, which is a panel that holds the xaml slider and minimumValueImage and maximumValueImage.
    StrongId<WXCGrid> _rootPanel;
    StrongId<WXCSlider> _xamlSlider;

    EventRegistrationToken _manipulationStartingEvent;
    EventRegistrationToken _manipulationCompletedEvent;
    EventRegistrationToken _valueChangedEvent;
}

- (void)_UISlider_initInternal:(WXFrameworkElement*)xamlElement {
    if (xamlElement != nil && [xamlElement isKindOfClass:[WXCSlider class]]) {
        _xamlSlider = static_cast<WXCSlider*>(xamlElement);
    } else {
        _xamlSlider = [WXCSlider make];
    }

    // BUG:7911911 - [XAMLCatalog] UISlider not rendering the right track image of XAML slider on ARM
    _xamlSlider.requestedTheme = WXElementThemeLight;
    _xamlSlider.maximum = 1.0f;
    _xamlSlider.minimum = 0.0f;
    _xamlSlider.value = 0.0f;

    _rootPanel = [WXCGrid make];
    [_rootPanel.children addObject:_xamlSlider];
    [self setXamlElement:_rootPanel];
    [self _updateStepFrequency];
    [self setContinuous:YES];
    [self _registerForEventsWithXaml];
}

- (void)_updateStepFrequency {
    // The frame size, minimumValue and maximumValue of UISlider can change dynamically, so we need to update the step frequency when they
    // do.
    if ((_xamlSlider.maximum - _xamlSlider.minimum) > 0 && self.frame.size.width > 0) {
        _xamlSlider.stepFrequency = (_xamlSlider.maximum - _xamlSlider.minimum) / (self.frame.size.width);
    } else {
        _xamlSlider.stepFrequency = c_defaultStepFrequency;
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
        [self _UISlider_initInternal:nil];

        if ([coder containsValueForKey:@"UIValue"]) {
            id valueStr = [coder decodeObjectForKey:@"UIValue"];
            _xamlSlider.value = [valueStr floatValue];
        }

        if ([coder containsValueForKey:@"UIMaxValue"]) {
            _xamlSlider.maximum = [[coder decodeObjectForKey:@"UIMaxValue"] floatValue];
        }
        if ([coder containsValueForKey:@"UIMinValue"]) {
            _xamlSlider.minimum = [[coder decodeObjectForKey:@"UIMinValue"] floatValue];
        }
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
        [self _UISlider_initInternal:xamlElement];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (float)value {
    return _xamlSlider.value;
}

/**
 @Status Interoperable
*/
- (void)setMinimumValue:(float)value {
    _xamlSlider.minimum = value;
    [self _updateStepFrequency];
}

- (void)_registerForEventsWithXaml {
    __weak UISlider* weakSelf = self;
    _valueChangedEvent = [_xamlSlider addValueChangedEvent:^void(RTObject* sender, WXRoutedEventArgs* e) {
        __strong UISlider* strongSelf = weakSelf;
        if (strongSelf && strongSelf->_continuous) {
            [strongSelf _sendValueChangedEvents];
        }
    }];

    _xamlSlider.manipulationMode = WUXIManipulationModesAll;

    // The value of a UISlider on ios cannot be changed by clicking anywhere on the track.
    // The thumb has to be hold and dragged.
    // On the other hand the value of a Xaml Slider can be changed by clicking anywhere on the track.
    // So we need manipulationStartingEvent when the value of Slider changes by clicking anywhere on
    // the track and not by dragging the thumb.
    // TODO: 7877568- Move to handling pointer events when available with projections, instead of manipulation events.
    _manipulationStartingEvent =
        [_xamlSlider addManipulationStartingEvent:^void(RTObject* sender, WUXIManipulationStartingRoutedEventArgs* e) {
            __strong UISlider* strongSelf = weakSelf;
            if (strongSelf && (strongSelf->_continuous == NO)) {
                [strongSelf _sendValueChangedEvents];
            }
        }];

    // ManipulationCompletedEvent will be fired when dragging has been completed
    // This allows us to fire UIControlEventValueChanged event and UIControlEventTouchUpInside event
    _manipulationCompletedEvent =
        [_xamlSlider addManipulationCompletedEvent:^void(RTObject* sender, WUXIManipulationCompletedRoutedEventArgs* e) {
            __strong UISlider* strongSelf = weakSelf;
            if (strongSelf && (strongSelf->_continuous == NO)) {
                [strongSelf _sendValueChangedEvents];
                [strongSelf sendActionsForControlEvents:UIControlEventTouchUpInside];
            }
        }];
}

- (void)_sendValueChangedEvents {
    [self sendActionsForControlEvents:UIControlEventValueChanged];
}
/**
 @Status Interoperable
*/
- (float)minimumValue {
    return _xamlSlider.minimum;
}

/**
 @Status Interoperable
*/
- (void)setMaximumValue:(float)value {
    _xamlSlider.maximum = value;
    [self _updateStepFrequency];
}

/**
 @Status Interoperable
*/
- (float)maximumValue {
    return _xamlSlider.maximum;
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
    _xamlSlider.value = value;
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
    [_xamlSlider removeManipulationStartingEvent:_manipulationStartingEvent];
    [_xamlSlider removeManipulationCompletedEvent:_manipulationCompletedEvent];
    [_xamlSlider removeValueChangedEvent:_valueChangedEvent];
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
