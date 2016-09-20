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

#import <StubReturn.h>
#import "Starboard.h"

#import "LoggingNative.h"
#import "CALayerInternal.h"
#import "UIFontInternal.h"
#import "UIViewInternal.h"
#import "UIButtonContent.h"
#import "UIEventInternal.h"
#import "UITouchInternal.h"

#import "XamlUtilities.h"
#include "XamlControls.h"
#include "../UIKit.Xaml/ObjCXamlControls.h"

#include <map>

static const wchar_t* TAG = L"UIButton";

struct ButtonState {
    StrongId<UIImage> image, backgroundImage;
    StrongId<UIColor> textColor;
    StrongId<NSString> title;
};

@interface UIRoundedRectButton : UIButton {
}
@end

@implementation UIRoundedRectButton
@end

@implementation UIButton {
    StrongId<WXCButton> _xamlButton;
    std::map<UIControlState, ButtonState> _states;
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        [self _UIButton_initInternal:nil];

        if ([coder containsValueForKey:@"UIDisabled"]) {
            BOOL disabled = [coder decodeIntegerForKey:@"UIDisabled"];
            if (disabled) {
                [self setEnabled:NO];
            }
        }

        if ([coder containsValueForKey:@"UIBackgroundColor"]) {
            [self setBackgroundColor:[coder decodeObjectForKey:@"UIBackgroundColor"]];
        }

        id stateContent = [coder decodeObjectForKey:@"UIButtonStatefulContent"];
        if (stateContent != nil) {
            //  Go through each state
            id objEnum = [stateContent objectEnumerator];
            id keyEnum = [stateContent keyEnumerator];

            id curKey;
            UIButtonContent* curObj;

            curKey = [keyEnum nextObject];
            curObj = [objEnum nextObject];

            while (curKey != nil) {
                uint32_t stateNum = [curKey intValue];

                assert(stateNum < 16);

                id image = [curObj image];
                if (image != nil) {
                    _states[stateNum].image = image;
                    [self setImage:image forState:stateNum];
                }

                _states[stateNum].title = [curObj title];
                [self setTitle:[curObj title] forState:stateNum];

                _states[stateNum].textColor = [curObj titleColor];
                [self setTitleColor:[curObj titleColor] forState:stateNum];

                id backgroundImage = [curObj backgroundImage];
                if (backgroundImage != nil) {
                    [self setBackgroundImage:backgroundImage forState:stateNum];
                }

                curKey = [keyEnum nextObject];
                curObj = [objEnum nextObject];
            }
        }
    }

    return self;
}

- (void)_processPointerPressedCallback:(RTObject*)sender eventArgs:(WUXIPointerRoutedEventArgs*)e {
    [self _processPointerEvent:e forTouchPhase:UITouchPhaseBegan];
}

- (void)_processPointerMovedCallback:(RTObject*)sender eventArgs:(WUXIPointerRoutedEventArgs*)e {
    [self _processPointerEvent:e forTouchPhase:UITouchPhaseMoved];
}

- (void)_processPointerReleasedCallback:(RTObject*)sender eventArgs:(WUXIPointerRoutedEventArgs*)e {
    [self _processPointerEvent:e forTouchPhase:UITouchPhaseEnded];
}

- (void)_processPointerCancelledCallback:(RTObject*)sender eventArgs:(WUXIPointerRoutedEventArgs*)e {
    [self _processPointerEvent:e forTouchPhase:UITouchPhaseCancelled];
}

- (void)_processPointerCaptureLostCallback:(RTObject*)sender eventArgs:(WUXIPointerRoutedEventArgs*)e {
    [self _processPointerEvent:e forTouchPhase:UITouchPhaseCancelled];
}

- (void)_UIButton_initInternal:(WXFrameworkElement*)xamlElement {
    if (xamlElement != nil && [xamlElement isKindOfClass:[WXCButton class]]) {
        _xamlButton.attach(static_cast<WXCButton*>(xamlElement));
    } else {
        _xamlButton.attach(XamlControls::CreateButton());
    }

    // Set the XAML element's name so it's easily found in the VS live tree viewer
    [_xamlButton setName:[NSString stringWithUTF8String:object_getClassName(self)]];

    __weak UIButton* weakSelf = self;
    XamlControls::HookButtonPointerEvents(_xamlButton,
                                          ^(RTObject* sender, WUXIPointerRoutedEventArgs* e) {
                                              // We mark the event as handled here. The method _processPointerPressedCallback
                                              // generates a call to touchesBegan:withEvent method,
                                              // and we mark it unhandled there, and then OnPointerPressed
                                              // on the backing XAML Button in c++ is called if the event
                                              // is still not handled. If a derived UIButton overrides
                                              // touchesBegan:withEvent method and does not call touchesBegan:withEvent method
                                              // on the super view, then event remains marked as handled
                                              // and OnPointerPressed is not called on the backing XAML Button.
                                              e.handled = YES;
                                              [weakSelf _processPointerPressedCallback:sender eventArgs:e];
                                          },
                                          ^(RTObject* sender, WUXIPointerRoutedEventArgs* e) {
                                              e.handled = YES;
                                              [weakSelf _processPointerMovedCallback:sender eventArgs:e];
                                          },
                                          ^(RTObject* sender, WUXIPointerRoutedEventArgs* e) {
                                              e.handled = YES;
                                              [weakSelf _processPointerReleasedCallback:sender eventArgs:e];
                                          },
                                          ^(RTObject* sender, WUXIPointerRoutedEventArgs* e) {
                                              e.handled = YES;
                                              [weakSelf _processPointerCancelledCallback:sender eventArgs:e];
                                          },
                                          ^(RTObject* sender, WUXIPointerRoutedEventArgs* e) {
                                              e.handled = YES;
                                              [weakSelf _processPointerCaptureLostCallback:sender eventArgs:e];
                                          });

    XamlControls::HookLayoutEvent(_xamlButton,
                                  ^(RTObject*, WUXIPointerRoutedEventArgs*) {
                                      // Since we are using XAML Button behind the scene, the intrinsicContentSize calculation is done
                                      // by XAML.
                                      // The size of XAML elements(for eg Image) is calculated at runtime and then the
                                      // intrinsicContentSize is invalidated.
                                      [weakSelf setNeedsLayout];
                                  });

    [self layer].contentsElement = _xamlButton;
}

- (instancetype)_initWithFrame:(CGRect)frame xamlElement:(WXFrameworkElement*)xamlElement {
    if (self = [super initWithFrame:frame]) {
        [self _UIButton_initInternal:xamlElement];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)pos {
    if (self = [super initWithFrame:pos]) {
        [self _UIButton_initInternal:nil];
    }

    return self;
}

/**
 @Public No
*/
- (void)initAccessibility {
    [super initAccessibility];
    self.accessibilityTraits = UIAccessibilityTraitButton;
}

/**
 @Status Caveat
 @Notes UIControlStateSelected, UIControlStateApplication and UIControlStateReserved states not supported
*/
- (void)setImage:(UIImage*)image forState:(UIControlState)state {
    if (!validateState(state)) {
        return;
    }

    WUXMImageBrush* imageBrush = ConvertUIImageToWUXMImageBrush(image);
    if (!imageBrush) {
        XamlSetButtonImage([_xamlButton comObj], nullptr, state, 0, 0);
    } else {
        XamlSetButtonImage([_xamlButton comObj], [imageBrush comObj], state, image.size.width, image.size.height);
    }
}

/**
 @Status Interoperable
*/
- (void)setEnabled:(BOOL)enabled {
    _xamlButton.get().isEnabled = enabled;
}

/**
 @Status Interoperable
*/
- (BOOL)isEnabled {
    return _xamlButton.get().isEnabled;
}

/**
 @Status Caveat
 @Notes UIControlStateSelected, UIControlStateApplication and UIControlStateReserved states not supported
*/
- (void)setBackgroundImage:(UIImage*)image forState:(UIControlState)state {
    if (!validateState(state)) {
        return;
    }

    _states[state].backgroundImage = image;

    WUXMImageBrush* imageBrush = ConvertUIImageToWUXMImageBrush(image);
    if (!imageBrush) {
        XamlSetBackgroundImage([_xamlButton comObj], nullptr, state, 0, 0);
    } else {
        XamlSetBackgroundImage([_xamlButton comObj], [imageBrush comObj], state, image.size.width, image.size.height);
    }
}

/**
 @Status Caveat
 @Notes The xaml element may be modified directly and we could still return stale values.
*/
- (UIImage*)backgroundImageForState:(UIControlState)state {
    if (!validateState(state)) {
        return nil;
    }

    return _states[state].backgroundImage;
}

/**
 @Status Caveat
 @Notes The xaml element may be modified directly and we could still return stale values.
*/
- (UIImage*)currentImage {
    if (self->_states[self->_curState].backgroundImage != nil) {
        return self->_states[self->_curState].backgroundImage;
    }

    return self->_states[UIControlStateNormal].backgroundImage;
}

/**
 @Status Interoperable
*/
- (void)setTitle:(NSString*)title forState:(UIControlState)state {
    if (!validateState(state)) {
        return;
    }

    _states[state].title.attach([title copy]);

    XamlSetTitleForState([_xamlButton comObj], [[WFPropertyValue createString:title] comObj], state);
}

/**
 @Status Caveat
 @Notes The xaml element may be modified directly and we could still return stale values.
*/
- (NSString*)titleForState:(UIControlState)state {
    if (!validateState(state)) {
        return nil;
    }

    return _states[state].title;
}

/**
 @Status Caveat
 @Notes The xaml element may be modified directly and we could still return stale values.
*/
- (UIImage*)imageForState:(UIControlState)state {
    if (!validateState(state)) {
        return nil;
    }

    return _states[state].image;
}

/**
 @Status Interoperable
*/
- (void)setTitleColor:(UIColor*)color forState:(UIControlState)state {
    if (!validateState(state)) {
        return;
    }

    _states[state].textColor = color;

    WUColor* convertedColor = ConvertUIColorToWUColor(color);
    WUXMSolidColorBrush* brush = [WUXMSolidColorBrush makeInstanceWithColor:convertedColor];

    XamlSetTitleColorForState([_xamlButton comObj], [brush comObj], state);
}

/**
 @Status Caveat
 @Notes The xaml element may be modified directly and we could still return stale values.
*/
- (UIColor*)titleColorForState:(UIControlState)state {
    if (!validateState(state)) {
        return nil;
    }

    return _states[state].textColor;
}

/**
 @Status Stub
*/
- (void)setTintColor:(UIColor*)color {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setTitleShadowColor:(UIColor*)color forState:(UIControlState)state {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UIColor*)titleShadowColorForState:(UIControlState)state {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIColor*)currentTitleShadowColor {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)touchesMoved:(NSSet*)touchSet withEvent:(UIEvent*)event {
    WUXIPointerRoutedEventArgs* routedEvent = [event _touchEvent]->_routedEventArgs;
    [routedEvent setHandled:NO];

    [super touchesMoved:touchSet withEvent:event];
}

/**
 @Status Interoperable
*/
- (void)touchesBegan:(NSSet*)touchSet withEvent:(UIEvent*)event {
    // If the derived UIButton overrides this method and does not call super implementation, then the
    // event remains handled, which results in the button not getting pressed.
    // Else we mark the event to be not handled so that the XAML implementation of Button can handle the event.
    WUXIPointerRoutedEventArgs* routedEvent = [event _touchEvent]->_routedEventArgs;
    [routedEvent setHandled:NO];

    if (!_xamlButton.get().isEnabled) {
        return;
    }

    _curState |= UIControlStateHighlighted;
    [super touchesBegan:touchSet withEvent:event];
}

/**
 @Status Interoperable
*/
- (void)touchesEnded:(NSSet*)touchSet withEvent:(UIEvent*)event {
    WUXIPointerRoutedEventArgs* routedEvent = [event _touchEvent]->_routedEventArgs;
    [routedEvent setHandled:NO];

    if (!_xamlButton.get().isPressed) {
        return;
    }

    _curState &= ~UIControlStateHighlighted;
    [super touchesEnded:touchSet withEvent:event];
}

/**
 @Status Interoperable
*/
- (void)touchesCancelled:(NSSet*)touchSet withEvent:(UIEvent*)event {
    WUXIPointerRoutedEventArgs* routedEvent = [event _touchEvent]->_routedEventArgs;
    [routedEvent setHandled:NO];

    if (!_xamlButton.get().isPressed) {
        return;
    }

    _curState &= ~UIControlStateHighlighted;
    [super touchesCancelled:touchSet withEvent:event];

    // Release the pointer capture so Xaml knows we're no longer in a pressed state
    [_xamlButton releasePointerCapture:routedEvent.pointer];
}

/**
 @Status Stub
*/
- (void)setAdjustsImageWhenHighlighted:(BOOL)doAdjust {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (BOOL)adjustsImageWhenHighlighted {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setAdjustsImageWhenDisabled:(BOOL)doAdjust {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setFont:(UIFont*)font {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UIFont*)font {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIButtonType)buttonType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setTitleEdgeInsets:(UIEdgeInsets)insets {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setImageEdgeInsets:(UIEdgeInsets)insets {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setContentEdgeInsets:(UIEdgeInsets)insets {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UIEdgeInsets)imageEdgeInsets {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIEdgeInsets)titleEdgeInsets {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIEdgeInsets)contentEdgeInsets {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setShowsTouchWhenHighlighted:(BOOL)showsTouch {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (BOOL)showsTouchWhenHighlighted {
    UNIMPLEMENTED();
    return StubReturn();
}

static bool validateState(UIControlState state) {
    if (state == UIControlStateNormal || state == UIControlStateHighlighted || state == UIControlStateDisabled ||
        state == UIControlStateSelected) {
        return true;
    }

    TraceVerbose(TAG, L"UIButton: bad control state %x", state);
    return false;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [super dealloc];

    XamlRemovePointerEvents([_xamlButton comObj]);
    XamlRemoveLayoutEvent([_xamlButton comObj]);

    for (auto& state : _states) {
        state.second.backgroundImage = nil;
        state.second.image = nil;
        state.second.textColor = nil;
        state.second.title = nil;
    }

    _xamlButton = nil;
}

/**
 @Status Caveat
 @Notes type not supported fully
*/
+ (UIButton*)buttonWithType:(UIButtonType)type {
    UIButton* ret = [[UIButton alloc] initWithFrame:CGRectZero];
    if (type == UIButtonTypeRoundedRect || type == UIButtonTypeSystem) {
        [ret setTitleColor:[UIColor colorWithRed:0.0f green:0.47843137f blue:1.0f alpha:1.0f] forState:UIControlStateNormal];
    }

    return [ret autorelease];
}

/**
 @Status Stub
*/
- (void)setReversesTitleShadowWhenHighlighted:(BOOL)reverses {
    UNIMPLEMENTED();
}

/**
 @Status Caveat
 @Notes The xaml element may be modified directly and we could still return stale values.
*/
- (NSString*)currentTitle {
    if (self->_states[self->_curState].title != nil) {
        return self->_states[self->_curState].title;
    }

    return self->_states[UIControlStateNormal].title;
}

/**
 @Status Caveat
 @Notes The xaml element may be modified directly and we could still return stale values.
*/
- (UIColor*)currentTitleColor {
    if (self->_states[self->_curState].textColor != nil) {
        return self->_states[self->_curState].textColor;
    } else if (self->_states[UIControlStateNormal].textColor != nil) {
        return self->_states[UIControlStateNormal].textColor;
    } else {
        return [UIColor whiteColor];
    }
}

/**
 @Status Stub
*/
- (UILabel*)titleLabel {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIImageView*)imageView {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Returns the receiving view
*/
- (UIView*)viewForBaselineLayout {
    return self;
}

/**
 @Status Stub
*/
- (CGSize)intrinsicContentSize {
    SIZE sizeFromXaml = XamlGetIntrinsicContentSizeFromXaml([_xamlButton comObj]);
    CGSize ret = { (float)sizeFromXaml.cx, (float)sizeFromXaml.cy };

    return ret;
}

/**
 @Status Stub
*/
- (CGRect)backgroundRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGRect)contentRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED();
    return bounds;
}

/**
 @Status Stub
*/
- (CGRect)imageRectForContentRect:(CGRect)contentRect {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGRect)titleRectForContentRect:(CGRect)contentRect {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (NSAttributedString*)attributedTitleForState:(UIControlState)state {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setAttributedTitle:(NSAttributedString*)title forState:(UIControlState)state {
    UNIMPLEMENTED();
}

@end