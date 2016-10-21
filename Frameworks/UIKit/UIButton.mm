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
#import "UIButtonProxies.h"
#import "UIEventInternal.h"
#import "UITouchInternal.h"

#import "XamlUtilities.h"
#include "XamlControls.h"
#include "../UIKit.Xaml/ObjCXamlControls.h"

#include <map>

static const wchar_t* TAG = L"UIButton";

struct ButtonState {
    StrongId<UIImage> image;
    StrongId<UIImage> backgroundImage;
    StrongId<UIColor> textColor;
    StrongId<NSString> title;

    // We also save the converted data types that we need to set on the XAML Button, so that we do not convert
    // from UIKit datatype to XAML datatype every time layoutSubviews is called.
    Microsoft::WRL::ComPtr<IInspectable> inspectableImage;
    Microsoft::WRL::ComPtr<IInspectable> inspectableBackgroundImage;
    Microsoft::WRL::ComPtr<IInspectable> inspectableTitleColor;
    Microsoft::WRL::ComPtr<IInspectable> inspectableTitle;
    RECT backgroundImageInsets;
};

@interface UIRoundedRectButton : UIButton {
}
@end

@implementation UIRoundedRectButton
@end

@implementation UIButton {
    StrongId<WXCButton> _xamlButton;

    // UIControlState is a bitmask, _states is a map that maps a UIControlState to a set of values for that state.
    std::map<UIControlState, ButtonState> _states;

    UIEdgeInsets _contentInsets;
    UIEdgeInsets _imageInsets;
    UIEdgeInsets _titleInsets;

    // Proxies
    StrongId<_UILabel_Proxy> _proxyLabel;
    StrongId<_UIImageView_Proxy> _proxyImageView;

    bool _isPressed;
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
        _xamlButton = static_cast<WXCButton*>(xamlElement);
    } else {
        _xamlButton = XamlControls::CreateButton();
    }

    // Force-load the template, and get the TextBlock and Image for use in our proxies.
    [_xamlButton applyTemplate];

    WXCImage* templateImage = rt_dynamic_cast([WXCImage class], [_xamlButton getTemplateChild:@"buttonImage"]);
    WXCTextBlock* templateText = rt_dynamic_cast([WXCTextBlock class], [_xamlButton getTemplateChild:@"buttonText"]);

    if (templateText) {
        _proxyLabel = [[_UILabel_Proxy alloc] initWithXamlElement:templateText font:[UIFont buttonFont]];
    }

    if (templateImage) {
        _proxyImageView = [[_UIImageView_Proxy alloc] initWithXamlElement:templateImage];
    }

    _contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
    _contentHorizontalAlignment = UIControlContentHorizontalAlignmentCenter;

    // Set the XAML element's name so it's easily found in the VS live tree viewer
    [_xamlButton setName:[NSString stringWithUTF8String:object_getClassName(self)]];

    __block UIButton* weakSelf = self;
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
    _states[state].image = image;
    WUXMImageBrush* imageBrush = ConvertUIImageToWUXMImageBrush(image);
    if (imageBrush) {
        _states[state].inspectableImage = [imageBrush comObj];
    }

    [self setNeedsLayout];
    [self layoutIfNeeded];
}

/**
 @Status Interoperable
*/
- (void)layoutSubviews {
    XamlButtonApplyVisuals([_xamlButton comObj],
                           _currentInspectableTitle(self),
                           _currentInspectableImage(self),
                           _currentInspectableBackgroundImage(self),
                           _currentBackgroundImageInsets(self),
                           _currentInspectableTitleColor(self));

    // Set frame after updating the visuals
    CGRect contentFrame = [self contentRectForBounds:self.bounds];
    CGRect textFrame = [self titleRectForContentRect:contentFrame];
    CGRect imageFrame = [self imageRectForContentRect:contentFrame];
    self.titleLabel.frame = textFrame;
    self.imageView.frame = imageFrame;

    // Probably important to keep around for after the refactor.
    [super layoutSubviews];
}

static CGRect calculateContentRect(UIButton* self, CGSize size, CGRect contentRect) {
    CGRect rect = { { 0, 0 }, size };

    switch (self.contentHorizontalAlignment) {
        case UIControlContentHorizontalAlignmentCenter:
            rect.origin.x = contentRect.origin.x + floorf((contentRect.size.width - rect.size.width) / 2.f);
            break;

        case UIControlContentHorizontalAlignmentRight:
            rect.origin.x = contentRect.size.width - rect.size.width;
            break;

        case UIControlContentHorizontalAlignmentFill:
            rect.size.width = contentRect.size.width;
            rect.origin.x = contentRect.origin.x;
            break;

        case UIControlContentHorizontalAlignmentLeft:
            rect.origin.x = contentRect.origin.x;
            break;
    }

    switch (self.contentVerticalAlignment) {
        case UIControlContentVerticalAlignmentCenter:
            rect.origin.y = contentRect.origin.y + floorf((contentRect.size.height - rect.size.height) / 2.f);
            break;

        case UIControlContentVerticalAlignmentBottom:
            rect.origin.y = contentRect.size.height - rect.size.height;
            break;

        case UIControlContentVerticalAlignmentFill:
            rect.size.height = contentRect.size.height;
            rect.origin.y = contentRect.origin.y;
            break;

        case UIControlContentVerticalAlignmentTop:
            rect.origin.y = contentRect.origin.y;
            break;
    }

    return rect;
}

/**
 @Status Interoperable
*/
- (CGRect)contentRectForBounds:(CGRect)bounds {
    return UIEdgeInsetsInsetRect(bounds, self.contentEdgeInsets);
}

/**
 @Status Interoperable
*/
- (CGRect)imageRectForContentRect:(CGRect)contentRect {
    CGSize titleSize = [self.currentTitle sizeWithFont:self.font];
    CGSize imageSize = { 0 };
    CGRect insetsRect = UIEdgeInsetsInsetRect(contentRect, self.imageEdgeInsets);

    if (!self.currentImage) {
        return CGRectZero;
    }

    imageSize = self.currentImage.size;

    CGSize totalSize = imageSize;
    totalSize.width += titleSize.width;

    // Get the frame based on the control alignment.
    CGRect ret = calculateContentRect(self, totalSize, insetsRect);

    ret.size.width -= titleSize.width;

    // Always try to fit the entire image on screen.
    ret.origin.x = std::max(ret.origin.x, insetsRect.origin.x);
    ret.origin.y = std::max(ret.origin.y, insetsRect.origin.y);

    // Intersect with the content rect
    ret = CGRectIntersection(ret, insetsRect);

    return ret;
}

/**
 @Status Interoperable
*/
- (CGRect)titleRectForContentRect:(CGRect)contentRect {
    CGSize titleSize = [self.currentTitle sizeWithFont:self.font];
    CGSize totalSize = titleSize;
    CGSize imageSize = [self.currentImage size];
    CGRect insetsRect = UIEdgeInsetsInsetRect(contentRect, self.titleEdgeInsets);

    if ([self currentTitle].length == 0) {
        return CGRectZero;
    }

    totalSize.width += imageSize.width;

    // Get the frame based on the control alignment.
    CGRect ret = calculateContentRect(self, totalSize, insetsRect);

    if (!CGSizeEqualToSize(imageSize, CGSizeZero)) {
        // Always try to fit the entire image on screen.
        ret.origin.x = std::max(ret.origin.x, insetsRect.origin.x);
        ret.origin.y = std::max(ret.origin.y, insetsRect.origin.y);

        // Remove the image portion
        ret.origin.x += imageSize.width;
        ret.size.width -= imageSize.width;
    }

    // Intersect with the content rect
    ret = CGRectIntersection(ret, insetsRect);

    return ret;
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
    _states[state].backgroundImage = image;
    _states[state].backgroundImageInsets = { 0, 0, 0, 0 };
    WUXMImageBrush* backgroundImageBrush = ConvertUIImageToWUXMImageBrush(image);
    if (backgroundImageBrush) {
        _states[state].inspectableBackgroundImage = [backgroundImageBrush comObj];
        _states[state].backgroundImageInsets = { image.capInsets.left * image.scale,
                                                 image.capInsets.top * image.scale,
                                                 image.capInsets.right * image.scale,
                                                 image.capInsets.bottom * image.scale };
    }

    [self setNeedsLayout];
    [self layoutIfNeeded];
}

/**
 @Status Caveat
 @Notes The xaml element may be modified directly and we could still return stale values.
*/
- (UIImage*)backgroundImageForState:(UIControlState)state {
    return _states[state].backgroundImage;
}

/**
 @Status Caveat
 @Notes The xaml element may be modified directly and we could still return stale values.
*/
- (UIImage*)currentImage {
    if (self->_states[self->_curState].image != nil) {
        return self->_states[self->_curState].image;
    }

    return self->_states[UIControlStateNormal].image;
}

/**
 @Status Caveat
 @Notes The xaml element may be modified directly and we could still return stale values.
*/
- (UIImage*)currentBackgroundImage {
    if (self->_states[self->_curState].backgroundImage != nil) {
        return self->_states[self->_curState].backgroundImage;
    }

    return self->_states[UIControlStateNormal].backgroundImage;
}

/**
 @Status Interoperable
*/
- (void)setTitle:(NSString*)title forState:(UIControlState)state {
    _states[state].title.attach([title copy]);
    RTObject* rtString = [WFPropertyValue createString:title];
    if (rtString) {
        _states[state].inspectableTitle = [rtString comObj];
    }

    [self setNeedsLayout];
    [self layoutIfNeeded];
}

/**
 @Status Caveat
 @Notes The xaml element may be modified directly and we could still return stale values.
*/
- (NSString*)titleForState:(UIControlState)state {
    return _states[state].title;
}

/**
 @Status Caveat
 @Notes The xaml element may be modified directly and we could still return stale values.
*/
- (UIImage*)imageForState:(UIControlState)state {
    return _states[state].image;
}

/**
 @Status Interoperable
*/
- (void)setTitleColor:(UIColor*)color forState:(UIControlState)state {
    _states[state].textColor = color;
    WUColor* convertedColor = ConvertUIColorToWUColor(color);
    WUXMSolidColorBrush* titleColorBrush = [WUXMSolidColorBrush makeInstanceWithColor:convertedColor];
    if (titleColorBrush) {
        _states[state].inspectableTitleColor = [titleColorBrush comObj];
    }

    [self setNeedsLayout];
    [self layoutIfNeeded];
}

/**
 @Status Caveat
 @Notes The xaml element may be modified directly and we could still return stale values.
*/
- (UIColor*)titleColorForState:(UIControlState)state {
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

    if (![self isEnabled]) {
        return;
    }

    _isPressed = true;
    UIControlState newState = _curState | UIControlStateHighlighted;

    // Relayout when new state is different than old state
    if (_curState != newState) {
        _curState = newState;
        [self setNeedsLayout];
        [self layoutIfNeeded];
    }

    [super touchesBegan:touchSet withEvent:event];
}

/**
 @Status Interoperable
*/
- (void)touchesEnded:(NSSet*)touchSet withEvent:(UIEvent*)event {
    WUXIPointerRoutedEventArgs* routedEvent = [event _touchEvent]->_routedEventArgs;
    [routedEvent setHandled:NO];

    if (!_isPressed) {
        return;
    }

    _isPressed = false;
    UIControlState newState = _curState & ~UIControlStateHighlighted;

    // Relayout when new state is different than old state
    if (_curState != newState) {
        _curState = newState;
        [self setNeedsLayout];
        [self layoutIfNeeded];
    }

    [super touchesEnded:touchSet withEvent:event];
}

/**
 @Status Interoperable
*/
- (void)touchesCancelled:(NSSet*)touchSet withEvent:(UIEvent*)event {
    WUXIPointerRoutedEventArgs* routedEvent = [event _touchEvent]->_routedEventArgs;
    [routedEvent setHandled:NO];

    if (!_isPressed) {
        return;
    }

    _isPressed = false;
    UIControlState newState = _curState & ~UIControlStateHighlighted;

    // Relayout when new state is different than old state
    if (_curState != newState) {
        _curState = newState;
        [self setNeedsLayout];
        [self layoutIfNeeded];
    }

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
 @Status Interoperable
*/
- (void)setFont:(UIFont*)font {
    self.titleLabel.font = font;
}

/**
 @Status Interoperable
*/
- (UIFont*)font {
    return self.titleLabel.font;
}

/**
 @Status Stub
*/
- (UIButtonType)buttonType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)setTitleEdgeInsets:(UIEdgeInsets)insets {
    _titleInsets = insets;
    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (void)setImageEdgeInsets:(UIEdgeInsets)insets {
    _imageInsets = insets;
    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (void)setContentEdgeInsets:(UIEdgeInsets)insets {
    _contentInsets = insets;
    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (UIEdgeInsets)imageEdgeInsets {
    return _imageInsets;
}

/**
 @Status Interoperable
*/
- (UIEdgeInsets)titleEdgeInsets {
    return _titleInsets;
}

/**
 @Status Interoperable
*/
- (UIEdgeInsets)contentEdgeInsets {
    return _contentInsets;
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

/**
 @Status Interoperable
*/
- (void)dealloc {
    XamlRemovePointerEvents([_xamlButton comObj]);
    XamlRemoveLayoutEvent([_xamlButton comObj]);

    for (auto& state : _states) {
        state.second.backgroundImage = nil;
        state.second.image = nil;
        state.second.textColor = nil;
        state.second.title = nil;
    }

    _xamlButton = nil;
    [super dealloc];
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
 @Status Interoperable
*/
- (NSString*)currentTitle {
    if (self->_states[self->_curState].title != nil) {
        return self->_states[self->_curState].title;
    }

    return self->_states[UIControlStateNormal].title;
}

static Microsoft::WRL::ComPtr<IInspectable> _currentInspectableTitle(UIButton* self) {
    if (self->_states[self->_curState].inspectableTitle) {
        return self->_states[self->_curState].inspectableTitle;
    }

    return self->_states[UIControlStateNormal].inspectableTitle;
}

static RECT _currentBackgroundImageInsets(UIButton* self) {
    if (self->_states[self->_curState].backgroundImage) {
        return self->_states[self->_curState].backgroundImageInsets;
    }

    return self->_states[UIControlStateNormal].backgroundImageInsets;
}

static Microsoft::WRL::ComPtr<IInspectable> _currentInspectableTitleColor(UIButton* self) {
    if (self->_states[self->_curState].inspectableTitleColor) {
        return self->_states[self->_curState].inspectableTitleColor;
    }

    return self->_states[UIControlStateNormal].inspectableTitleColor;
}

static Microsoft::WRL::ComPtr<IInspectable> _currentInspectableImage(UIButton* self) {
    if (self->_states[self->_curState].inspectableImage) {
        return self->_states[self->_curState].inspectableImage;
    }

    return self->_states[UIControlStateNormal].inspectableImage;
}

static Microsoft::WRL::ComPtr<IInspectable> _currentInspectableBackgroundImage(UIButton* self) {
    if (self->_states[self->_curState].inspectableBackgroundImage) {
        return self->_states[self->_curState].inspectableBackgroundImage;
    }

    return self->_states[UIControlStateNormal].inspectableBackgroundImage;
}

/**
 @Status Interoperable
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
 @Status Caveat
 @Notes Returns a mock UILabel that proxies some common properties and selectors to the underlying TextBlock
*/
- (UILabel*)titleLabel {
    return (UILabel*)[[_proxyLabel retain] autorelease];
}

/**
 @Status Caveat
 @Notes Returns a mock UIImageView that proxies some common properties and selectors to the underlying Image
*/
- (UIImageView*)imageView {
    return (UIImageView*)[[_proxyImageView retain] autorelease];
}

/**
 @Status Caveat
 @Notes Returns the receiving view
*/
- (UIView*)viewForBaselineLayout {
    return self;
}

/**
 @Status Interoperable
*/
- (CGSize)intrinsicContentSize {
    CGSize ret = CGSizeZero;

    UIImage* img = self.currentImage;
    UIEdgeInsets contentInsets = self.contentEdgeInsets;
    CGSize textSize = [[self currentTitle] sizeWithFont:self.font];

    // Size should at least fit the image in a normal state.
    if (img != nil) {
        ret = [img size];
    }

    if ([self currentTitle].length) {
        ret.width = std::max(textSize.width, ret.width);
        ret.height = std::max(textSize.height, ret.height);
    }

    // If we have a background, its image size dictates the smallest size.
    if (self.currentBackgroundImage) {
        UIImage* background = self.currentBackgroundImage;
        CGSize size = [background size];

        ret.width = std::max(size.width, ret.width);
        ret.height = std::max(size.height, ret.height);
    } else if (UIEdgeInsetsEqualToEdgeInsets(contentInsets, UIEdgeInsetsZero)) {
        // Min values found emperically; set if no contentInsets are set.
        ret.width = std::max(ret.width, 30.0f);
        ret.height = std::max(ret.height, 12 + textSize.height);
    }

    ret.width += (contentInsets.right + contentInsets.left);
    ret.height += (contentInsets.top + contentInsets.bottom);

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