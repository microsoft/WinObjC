//******************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
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
#import "Starboard.h"
#import "StubReturn.h"

#import <UIKit/NSString+UIKitAdditions.h>
#import <UIKit/UIButton.h>
#import <UIKit/UIImageView.h>
#import <UIKit/UILabel.h>

#import "LoggingNative.h"
#import "CALayerInternal.h"
#import "UIFontInternal.h"
#import "UIViewInternal.h"
#import "UIButtonContent.h"
#import "UIButtonProxies.h"
#import "UIControlInternal.h"
#import "UIEventInternal.h"
#import "UITouchInternal.h"

#import "XamlUtilities.h"
#include "XamlControls.h"
#import "CppWinRTHelpers.h"
#include "../UIKit.Xaml/ObjCXamlControls.h"

#include <map>

using namespace Microsoft::WRL;
using namespace winrt::Windows::UI::Xaml;
namespace WF = winrt::Windows::Foundation;

static const wchar_t* TAG = L"UIButton";

struct ButtonState {
    // Returns whether or not the state contains any currently-set values
    bool IsEmpty() const {
        return !title && !textColor && !image && !backgroundImage;
    }

    StrongId<UIImage> image;
    StrongId<UIImage> backgroundImage;
    StrongId<UIColor> textColor;
    StrongId<NSString> title;

    // We also save the converted data types that we need to set on the XAML Button, so that we do not convert
    // from UIKit datatype to XAML datatype every time layoutSubviews is called.
    ComPtr<IInspectable> inspectableImage;
};

@implementation UIButton {
    TrivialDefaultConstructor<Controls::Button> _xamlButton;

    // UIControlState is a bitmask, _states is a map that maps a UIControlState to a set of values for that state.
    std::map<UIControlState, ButtonState> _states;

    UIEdgeInsets _contentInsets;
    UIEdgeInsets _imageInsets;
    UIEdgeInsets _titleInsets;

    // Child elements
    StrongId<UILabel> _titleLabel;
    StrongId<_UIImageView_Proxy> _proxyImageView;

    // Press handling
    bool _isInTouchSequence;
    long long _isPressedChangedRegistration;

    // Click handling
    winrt::event_token _clickEventRegistration;

    UIButtonType _buttonType;

    ComPtr<IInspectable> _inspectableAdjustsWhenDisabledBrush;
    ComPtr<IInspectable> _inspectableAdjustsWhenHighlightedBrush;
}

static UIEdgeInsets _decodeUIEdgeInsets(NSCoder* coder, NSString* key) {
    id object = [coder decodeObjectForKey:key];
    UIEdgeInsets* rawInsets = (UIEdgeInsets*)((char*)[object bytes] + 1);

    UIEdgeInsets insets = {};
    memcpy(&insets, rawInsets, sizeof(UIEdgeInsets));

    return insets;
}

/**
 @Status Caveat
 @Notes Not all properties are supported.
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        [self _initUIButton];

        if ([coder containsValueForKey:@"UIDisabled"]) {
            BOOL disabled = [coder decodeIntegerForKey:@"UIDisabled"];
            if (disabled) {
                [self setEnabled:NO];
            }
        }

        UIFont* font = [coder decodeObjectForKey:@"UIFont"];
        if (!font) {
            font = [UIFont buttonFont];
        }
        self.font = font;

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

        if ([coder containsValueForKey:@"UIAdjustsImageWhenHighlighted"]) {
            self.adjustsImageWhenHighlighted = [coder decodeBoolForKey:@"UIAdjustsImageWhenHighlighted"];
        }

        if ([coder containsValueForKey:@"UIAdjustsImageWhenDisabled"]) {
            self.adjustsImageWhenDisabled = [coder decodeBoolForKey:@"UIAdjustsImageWhenDisabled"];
        }

        // Insets
        if ([coder containsValueForKey:@"UIImageEdgeInsets"]) {
            _imageInsets = _decodeUIEdgeInsets(coder, @"UIImageEdgeInsets");
        }

        if ([coder containsValueForKey:@"UIContentEdgeInsets"]) {
            _contentInsets = _decodeUIEdgeInsets(coder, @"UIContentEdgeInsets");
        }

        if ([coder containsValueForKey:@"UITitleEdgeInsets"]) {
            _titleInsets = _decodeUIEdgeInsets(coder, @"UITitleEdgeInsets");
        }
    }

    return self;
}

- (void)_initUIButton {
    // Store a strongly-typed backing button
    _xamlButton = [self _winrtXamlElement].as<Controls::Button>();

    // Default to a custom button type
    _buttonType = UIButtonTypeCustom;

    // Default to showing pressed/disabled states
    self.adjustsImageWhenDisabled = YES;
    self.adjustsImageWhenHighlighted = YES;

    // Force-load the template, and get the TextBlock and Image for use in our proxies.
    _xamlButton.ApplyTemplate();
    _xamlButton.UpdateLayout();

    // Create our child UILabel; its frame will be updated in layoutSubviews
    FrameworkElement buttonLabel = XamlControls::GetButtonLabel(_xamlButton);
    _titleLabel = [[UILabel alloc] initWithFrame:CGRectZero xamlElement:objcwinrt::to_rtobj(buttonLabel)];
    _titleLabel.userInteractionEnabled = NO;

    // Create our child UIImageView; its frame will be updated in layoutSubviews
    auto control = _xamlButton.as<Controls::IControlProtected>();
    auto templateImage = control.GetTemplateChild(L"buttonImage").as<Controls::Image>();

    _proxyImageView = [[_UIImageView_Proxy alloc] initWithXamlElement:templateImage];

    _contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
    _contentHorizontalAlignment = UIControlContentHorizontalAlignmentCenter;

    // Register for cooperative pointer events
    __weak UIButton* weakSelf = self;
    XamlControls::HookButtonPointerEvents(_xamlButton,
                                          objcwinrt::callback([weakSelf] (const WF::IInspectable& sender, const Input::PointerRoutedEventArgs& e) {
                                              // We mark the event as handled here. The method _processPointerPressedCallback
                                              // generates a call to touchesBegan:withEvent method,
                                              // and we mark it unhandled there, and then OnPointerPressed
                                              // on the backing XAML Button in c++ is called if the event
                                              // is still not handled. If a derived UIButton overrides
                                              // touchesBegan:withEvent method and does not call touchesBegan:withEvent method
                                              // on the super view, then event remains marked as handled
                                              // and OnPointerPressed is not called on the backing XAML Button.
                                              e.Handled(true);
                                              [weakSelf _processPointerEvent:e forTouchPhase:UITouchPhaseBegan];
                                          }),
                                          objcwinrt::callback([weakSelf] (const WF::IInspectable& sender, const Input::PointerRoutedEventArgs& e) {
                                              e.Handled(true);
                                              [weakSelf _processPointerEvent:e forTouchPhase:UITouchPhaseMoved];
                                          }),
                                          objcwinrt::callback([weakSelf] (const WF::IInspectable& sender, const Input::PointerRoutedEventArgs& e) {
                                              e.Handled(true);
                                              [weakSelf _processPointerEvent:e forTouchPhase:UITouchPhaseEnded];
                                          }),
                                          objcwinrt::callback([weakSelf] (const WF::IInspectable& sender, const Input::PointerRoutedEventArgs& e) {
                                              e.Handled(true);
                                              [weakSelf _processPointerEvent:e forTouchPhase:UITouchPhaseCancelled];
                                          }),
                                          objcwinrt::callback([weakSelf] (const WF::IInspectable& sender, const Input::PointerRoutedEventArgs& e) {
                                              e.Handled(true);
                                              [weakSelf _processPointerEvent:e forTouchPhase:UITouchPhaseCancelled];
                                          }));

    // Initialize press/click management
    _isInTouchSequence = false;

    // Register for IsPressed-changed events to map to UIButton highlighted states
    _isPressedChangedRegistration =
        _xamlButton.RegisterPropertyChangedCallback(Controls::Primitives::ButtonBase::IsPressedProperty(),
                                            objcwinrt::callback([weakSelf] (const DependencyObject& sender, const DependencyProperty& p) {
                                                // Update our highlighted state accordingly
                                                auto button = sender.as<Controls::Primitives::ButtonBase>();
                                                [weakSelf setHighlighted:button.IsPressed()];
                                            }));

    // Register for 'Click' events, to handle keybard and accessibility clicks
    _clickEventRegistration = _xamlButton.Click(objcwinrt::callback([weakSelf] (const WF::IInspectable&, const RoutedEventArgs&) {
        // Simulate a button 'click' for non-pointer-triggered clicks
        [weakSelf sendActionsForControlEvents:UIControlEventTouchDown];
        [weakSelf sendActionsForControlEvents:UIControlEventTouchUpInside];
    }));
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self _initUIButton];
        self.font = [UIFont buttonFont];
    }

    return self;
}

/**
Microsoft Extension
*/
- (instancetype)initWithFrame:(CGRect)frame xamlElement:(RTObject*)xamlElement {
    if (self = [super initWithFrame:frame xamlElement:xamlElement]) {
        [self _initUIButton];
        self.font = [UIFont buttonFont];
    }

    return self;
}

/**
 Microsoft Extension
*/
+ (RTObject*)createXamlElement {
    return objcwinrt::to_rtobj(XamlControls::CreateButton());
}

/**
 @Public No
*/
- (void)initAccessibility {
    [super initAccessibility];
    self.accessibilityTraits = UIAccessibilityTraitButton;
}

/**
 @Status Interoperable
*/
- (void)layoutSubviews {
    // Grab our current values
    NSString* currentTitle = self.currentTitle;
    ComPtr<IInspectable> currentImage = _currentInspectableImage(self);
    UIImage* currentBackgroundImage = self.currentBackgroundImage;

    // Determine whether or not we should use a disabled or highlighted overlay.
    // Only do so if we have any content to render and we're in a disabled or highlighted state.
    ComPtr<IInspectable> currentBorderBackgroundBrush;
    if (([currentTitle length] > 0) || currentImage || currentBackgroundImage) {
        currentBorderBackgroundBrush = _currentInspectableBorderBackgroundBrush(self);
    }

    // Update our image and border background brush (which we use for applying 'adjustImageWhen' treatment)
    XamlButtonApplyVisuals(objcwinrt::to_insp(_xamlButton), currentImage, currentBorderBackgroundBrush);

    // Update our title label
    self.titleLabel.text = currentTitle;
    self.titleLabel.textColor = self.currentTitleColor;

    // Set frame after updating the visuals
    CGRect contentFrame = [self contentRectForBounds:self.bounds];
    CGRect textFrame = [self titleRectForContentRect:contentFrame];
    CGRect imageFrame = [self imageRectForContentRect:contentFrame];
    self.titleLabel.frame = textFrame;
    self.imageView.frame = imageFrame;

    // Use the layer contents to draw the background image, similar to UIImageView.
    UIImageSetLayerContents([self layer], currentBackgroundImage);

    // UIButton should always stretch its background.  Since we're leveraging our backing CALayer's background for
    // the UIButton background, we stretch it via the CALayer's contentsGravity.
    self.layer.contentsGravity = kCAGravityResize;

    // Probably important to keep around for after the refactor.
    [super layoutSubviews];
}

static CGRect calculateContentRect(UIButton* self, CGSize size, CGRect contentRect) {
    CGRect rect = CGRectMake(0, 0, size.width, size.height);

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
    /////////////////////////////////////////////////////////////////////
    // Note: #1365 All size calculations here must check for nil,
    // as we cannot assume getting a size from nil will return CGSizeZero
    /////////////////////////////////////////////////////////////////////
    UIImage* currentImage = self.currentImage;
    if (!currentImage) {
        // No image, so we return zero for the entire content rect
        return CGRectZero;
    }

    // Grab the size of the current title
    // TODO: Should we be asking our label for this?
    NSString* currentTitle = self.currentTitle;
    CGSize titleSize = CGSizeZero;
    if (currentTitle) {
        // We need to round the font size to the nearest pixel value to avoid rounding errors when used in conjunction with the
        // frame values that are rounded by UIView.
        titleSize = doPixelRound([currentTitle sizeWithFont:self.font]);
    }

    // Now calculate the total size based on the image and title sizes
    CGSize totalSize = currentImage.size;
    totalSize.width += titleSize.width;

    // Get the frame based on the control alignment.
    CGRect insetsRect = UIEdgeInsetsInsetRect(contentRect, self.imageEdgeInsets);
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
    /////////////////////////////////////////////////////////////////////
    // Note: #1365 All size calculations here must check for nil,
    // as we cannot assume getting a size from nil will return CGSizeZero
    /////////////////////////////////////////////////////////////////////

    // Grab the size of the current title
    // TODO: Should we be asking our label for this?
    NSString* currentTitle = self.currentTitle;
    CGSize titleSize = CGSizeZero;
    if (currentTitle && currentTitle.length > 0) {
        // We need to round the font size to the nearest pixel value to avoid rounding errors when used in conjunction with the
        // frame values that are rounded by UIView.
        titleSize = doPixelRound([currentTitle sizeWithFont:self.font]);
    } else {
        // No title, so we return zero for the entire content rect
        return CGRectZero;
    }

    // Grab the size of the current image
    UIImage* currentImage = self.currentImage;
    CGSize imageSize = CGSizeZero;
    if (currentImage) {
        imageSize = [currentImage size];
    }

    CGRect insetsRect = UIEdgeInsetsInsetRect(contentRect, self.titleEdgeInsets);

    CGSize totalSize = titleSize;
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
    _xamlButton.IsEnabled(enabled);
    [super setEnabled:enabled];
}

/**
 @Status Interoperable
*/
- (BOOL)isEnabled {
    return static_cast<BOOL>(_xamlButton.IsEnabled());
}

/**
 @Status Interoperable
*/
- (void)setImage:(UIImage*)image forState:(UIControlState)state {
    _states[state].image = image;

    // NOTE: check if image is nil before creating inspectableImage
    // ConvertUIImageToWUXMImageBrush:nil creates a valid imageBrush with null comObj
    // which isn't what we want
    if (image) {
        Media::ImageBrush imageBrush = XamlUtilities::ConvertUIImageToWUXMImageBrush(image);
        if (imageBrush) {
            _states[state].inspectableImage = objcwinrt::to_insp(imageBrush);
        }
    } else {
        // this enforces the fallback of using Image of normalState
        // when a image for other states does not exis
        _states[state].inspectableImage = nullptr;
    }

    // Update the Xaml elements immediately, so the image proxy reflects reality
    XamlButtonApplyVisuals(objcwinrt::to_insp(_xamlButton), _currentInspectableImage(self), _currentInspectableBorderBackgroundBrush(self));

    [self invalidateIntrinsicContentSize];
    [self setNeedsLayout];
}

/**
@Status Interoperable
@Notes The xaml element may be modified directly and we could return stale values.
*/
- (UIImage*)imageForState:(UIControlState)state {
    // Don't do index-based lookup to avoid inserting empty entries into the map
    const auto& statePair = _states.find(state);
    return statePair != _states.end() ? statePair->second.image : nullptr;
}

/**
 @Status Interoperable
 @Notes The xaml element may be modified directly and we could return stale values.
*/
- (UIImage*)currentImage {
    // Don't do index-based lookup to avoid inserting empty entries into the map
    const auto& statePair = _states.find(self->_curState);
    if (statePair != _states.end() && statePair->second.image != nil) {
        return statePair->second.image;
    }

    return self->_states[UIControlStateNormal].image;
}

/**
@Status Interoperable
@Notes The xaml element may be modified directly and we could return stale values.
*/
- (void)setBackgroundImage:(UIImage*)image forState:(UIControlState)state {
    _states[state].backgroundImage = image;

    [self invalidateIntrinsicContentSize];
    [self setNeedsLayout];
}

/**
@Status Interoperable
@Notes The xaml element may be modified directly and we could return stale values.
*/
- (UIImage*)backgroundImageForState:(UIControlState)state {
    // Don't do index-based lookup to avoid inserting empty entries into the map
    const auto& statePair = _states.find(state);
    return statePair != _states.end() ? statePair->second.backgroundImage : nullptr;
}

/**
@Status Interoperable
@Notes The xaml element may be modified directly and we could return stale values.
*/
- (UIImage*)currentBackgroundImage {
    // Don't do index-based lookup to avoid inserting empty entries into the map
    const auto& statePair = _states.find(self->_curState);
    if (statePair != _states.end() && statePair->second.backgroundImage != nil) {
        return statePair->second.backgroundImage;
    }

    return self->_states[UIControlStateNormal].backgroundImage;
}

/**
 @Status Interoperable
*/
- (void)setTitle:(NSString*)title forState:(UIControlState)state {
    _states[state].title = [title copy];

    // Update our title label immediately
    self.titleLabel.text = self.currentTitle;
    [self invalidateIntrinsicContentSize];
    [self setNeedsLayout];
}

/**
 @Status Interoperable
 @Notes The xaml element may be modified directly and we could return stale values.
*/
- (NSString*)titleForState:(UIControlState)state {
    // Don't do index-based lookup to avoid inserting empty entries into the map
    const auto& statePair = _states.find(state);
    return statePair != _states.end() ? statePair->second.title : nullptr;
}

/**
 @Status Interoperable
*/
- (NSString*)currentTitle {
    // Don't do index-based lookup to avoid inserting empty entries into the map
    const auto& statePair = _states.find(self->_curState);
    if (statePair != _states.end() && statePair->second.title != nil) {
        return statePair->second.title;
    }

    return self->_states[UIControlStateNormal].title;
}

/**
 @Status Interoperable
*/
- (void)setTitleColor:(UIColor*)color forState:(UIControlState)state {
    _states[state].textColor = color;

    // Update our title label color
    self.titleLabel.textColor = self.currentTitleColor;
    [self invalidateIntrinsicContentSize];
    [self setNeedsLayout];
}

/**
 @Status Interoperable
 @Notes The xaml element may be modified directly and we could return stale values.
*/
- (UIColor*)titleColorForState:(UIControlState)state {
    // Don't do index-based lookup to avoid inserting empty entries into the map
    const auto& statePair = _states.find(state);
    return statePair != _states.end() ? statePair->second.textColor : nullptr;
}

/**
 @Status Interoperable
*/
- (UIColor*)currentTitleColor {
    // Don't do index-based lookup to avoid inserting empty entries into the map
    const auto& statePair = _states.find(self->_curState);
    if (statePair != _states.end() && statePair->second.textColor != nil) {
        return statePair->second.textColor;
    } else if (self->_states[UIControlStateNormal].textColor != nil) {
        return self->_states[UIControlStateNormal].textColor;
    } else {
        return [UIColor whiteColor];
    }
}

/**
 @Status NotInPlan
 @Notes TintColor is not a feature currently supported by Xaml.
*/
- (void)setTintColor:(UIColor*)color {
    UNIMPLEMENTED_WITH_MSG("TintColor is not a feature currently supported by Xaml.");
}

/**
 @Status NotInPlan
 @Notes TintColor is not a feature currently supported by Xaml.
*/
- (UIColor*)tintColor {
    UNIMPLEMENTED_WITH_MSG("TintColor is not a feature currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes Text shadows are not currently supported by Xaml.
*/
- (void)setTitleShadowColor:(UIColor*)color forState:(UIControlState)state {
    UNIMPLEMENTED_WITH_MSG("Text shadows are not currently supported by Xaml.");
}

/**
 @Status NotInPlan
 @Notes Text shadows are not currently supported by Xaml.
*/
- (UIColor*)titleShadowColorForState:(UIControlState)state {
    UNIMPLEMENTED_WITH_MSG("Text shadows are not currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes Text shadows are not currently supported by Xaml.
*/
- (UIColor*)currentTitleShadowColor {
    UNIMPLEMENTED_WITH_MSG("Text shadows are not currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes Text shadows are not currently supported by Xaml.
*/
- (void)setReversesTitleShadowWhenHighlighted:(BOOL)reverses {
    UNIMPLEMENTED_WITH_MSG("Text shadows are not currently supported by Xaml.");
}

/**
 @Status NotInPlan
 @Notes Text shadows are not currently supported by Xaml.
*/
- (void)setTitleShadowOffset:(CGSize)offset {
    UNIMPLEMENTED_WITH_MSG("Text shadows are not currently supported by Xaml.");
}

/**
 @Status NotInPlan
 @Notes Text shadows are not currently supported by Xaml.
*/
- (CGSize)titleShadowOffset {
    UNIMPLEMENTED_WITH_MSG("Text shadows are not currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)touchesMoved:(NSSet*)touchSet withEvent:(UIEvent*)event {
    // If the derived UIButton overrides this method and does not call this super implementation, then the
    // event remains *handled*, which results in the Button.Xaml not calling into its super for further processing.
    // Else, we mark the event as *not handled*, so Button.Xaml calls into its super for further event processing.
    Input::PointerRoutedEventArgs routedEvent = [event _touchEvent]->_routedEventArgs;
    routedEvent.Handled(false);

    [super touchesMoved:touchSet withEvent:event];
}

/**
 @Status Interoperable
*/
- (void)touchesBegan:(NSSet*)touchSet withEvent:(UIEvent*)event {
    // If the derived UIButton overrides this method and does not call this super implementation, then the
    // event remains *handled*, which results in the Button.Xaml not calling into its super for further processing.
    // Else, we mark the event as *not handled*, so Button.Xaml calls into its super for further event processing.
    Input::PointerRoutedEventArgs routedEvent = [event _touchEvent]->_routedEventArgs;
    routedEvent.Handled(false);

    if (![self isEnabled]) {
        return;
    }

    // Track that we're currently in a touch sequence
    _isInTouchSequence = true;

    [super touchesBegan:touchSet withEvent:event];
}

/**
 @Status Interoperable
*/
- (void)touchesEnded:(NSSet*)touchSet withEvent:(UIEvent*)event {
    // If the derived UIButton overrides this method and does not call this super implementation, then the
    // event remains *handled*, which results in the Button.Xaml not calling into its super for further processing.
    // Else, we mark the event as *not handled*, so Button.Xaml calls into its super for further event processing.
    Input::PointerRoutedEventArgs routedEvent = [event _touchEvent]->_routedEventArgs;
    routedEvent.Handled(false);

    if (!_isInTouchSequence) {
        return;
    }

    // Track that we're no longer in a touch sequence
    _isInTouchSequence = false;

    [super touchesEnded:touchSet withEvent:event];

    // Release the pointer capture so Xaml knows we're no longer in a pressed state, which
    // also prevents the button from firing a 'click' event since we already fire one via UIControl's
    // touch handling.
    _xamlButton.ReleasePointerCapture(routedEvent.Pointer());
}

/**
 @Status Interoperable
*/
- (void)touchesCancelled:(NSSet*)touchSet withEvent:(UIEvent*)event {
    if (!_isInTouchSequence) {
        return;
    }

    // Track that we're no longer in a touch sequence
    _isInTouchSequence = false;

    [super touchesCancelled:touchSet withEvent:event];

    // Release the pointer capture so Xaml knows we're no longer in a pressed state
    Input::PointerRoutedEventArgs routedEvent = [event _touchEvent]->_routedEventArgs;
    _xamlButton.ReleasePointerCapture(routedEvent.Pointer());
}

static bool _isStateCustomizationSet(UIButton* self, UIControlState state) {
    // Returns whether or not we have any customization set for the specified state.
    // For example; checking for 'UIControlStateDisabled' would return true for a 'UIControlStateDisabled' state as well as
    // for a 'UIControlStateHighlighted | UIControlStateDisabled' state.
    for (const auto& statePair : self->_states) {
        if ((statePair.first & state) && !statePair.second.IsEmpty()) {
            return true;
        }
    }

    return false;
}

static ComPtr<IInspectable> _currentInspectableBorderBackgroundBrush(UIButton* self) {
    // Only use the brush if we're in the current state, and no customization has yet been set
    // for any permutation of that state.
    if (!self.isEnabled && !_isStateCustomizationSet(self, UIControlStateDisabled)) {
        return self->_inspectableAdjustsWhenDisabledBrush;
    } else if (self.isHighlighted && !_isStateCustomizationSet(self, UIControlStateHighlighted)) {
        return self->_inspectableAdjustsWhenHighlightedBrush;
    }

    return nullptr;
}

/**
 @Status Caveat
 @Notes We use this value to determine whether or not we add a lightening overlay to the button background, background image, and image,
        whereas on the reference platform the tint is only applied directly to the images.  You can opt out by disabling this setting,
        or by setting any UIControlStateDisabled properties.
*/
- (void)setAdjustsImageWhenDisabled:(BOOL)shouldAdjust {
    if (shouldAdjust && !_inspectableAdjustsWhenDisabledBrush) {
        // Semi-transparent white overlay
        Media::SolidColorBrush colorBrush = winrt::Windows::UI::ColorHelper::FromArgb(150, 255, 255, 255);
        _inspectableAdjustsWhenDisabledBrush = objcwinrt::to_insp(colorBrush);
        [self setNeedsLayout];
    } else if (!shouldAdjust && _inspectableAdjustsWhenDisabledBrush) {
        _inspectableAdjustsWhenDisabledBrush = nullptr;
        [self setNeedsLayout];
    }
}

/**
 @Status Interoperable
*/
- (BOOL)adjustsImageWhenDisabled {
    return _inspectableAdjustsWhenDisabledBrush != nullptr;
}

/**
 @Status Caveat
 @Notes We use this value to determine whether or not we add a darkening overlay to the button background, background image, and image,
        whereas on the reference platform the tint is only applied directly to the images.  You can opt out by disabling this setting,
        or by setting any UIControlStateHighlighted properties.
*/
- (void)setAdjustsImageWhenHighlighted:(BOOL)shouldAdjust {
    if (shouldAdjust && !_inspectableAdjustsWhenHighlightedBrush) {
        // Mostly transparent black overlay
        Media::SolidColorBrush colorBrush = winrt::Windows::UI::ColorHelper::FromArgb(65, 0, 0, 0);
        _inspectableAdjustsWhenHighlightedBrush = objcwinrt::to_insp(colorBrush);
        [self setNeedsLayout];
    } else if (!shouldAdjust && _inspectableAdjustsWhenHighlightedBrush) {
        _inspectableAdjustsWhenHighlightedBrush = nullptr;
        [self setNeedsLayout];
    }
}

/**
 @Status Interoperable
*/
- (BOOL)adjustsImageWhenHighlighted {
    return _inspectableAdjustsWhenHighlightedBrush != nullptr;
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
    return _buttonType;
}

/**
 @Status Interoperable
*/
- (void)setTitleEdgeInsets:(UIEdgeInsets)insets {
    _titleInsets = insets;
    [self invalidateIntrinsicContentSize];
    [self setNeedsLayout];
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
- (void)setImageEdgeInsets:(UIEdgeInsets)insets {
    _imageInsets = insets;
    [self invalidateIntrinsicContentSize];
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
- (void)setContentEdgeInsets:(UIEdgeInsets)insets {
    _contentInsets = insets;
    [self invalidateIntrinsicContentSize];
    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (UIEdgeInsets)contentEdgeInsets {
    return _contentInsets;
}

/**
 @Status NotInPlan
 @Notes Xaml doesn't have built in support for showing 'glowing' touch feedback.
*/
- (void)setShowsTouchWhenHighlighted:(BOOL)showsTouch {
    UNIMPLEMENTED_WITH_MSG("Xaml doesn't have built in support for showing 'glowing' touch feedback.");
}

/**
 @Status NotInPlan
 @Notes Xaml doesn't have built in support for showing 'glowing' touch feedback.
*/
- (BOOL)showsTouchWhenHighlighted {
    UNIMPLEMENTED_WITH_MSG("Xaml doesn't have built in support for showing 'glowing' touch feedback.");
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    XamlRemovePointerEvents(objcwinrt::to_insp(_xamlButton));
    _xamlButton.UnregisterPropertyChangedCallback(Controls::Primitives::ButtonBase::IsPressedProperty(), _isPressedChangedRegistration);
    _xamlButton.Click(_clickEventRegistration);
}

/**
 @Status Caveat
 @Notes Only UIButtonTypeSystem and UIButtonTypeRoundedRect receive special treatment; all other types are treated as UIButtonTypeCustom.
*/
+ (UIButton*)buttonWithType:(UIButtonType)type {
    UIButton* ret = [[UIButton alloc] initWithFrame:CGRectZero];
    if (type == UIButtonTypeRoundedRect || type == UIButtonTypeSystem) {
        ret->_buttonType = type;
        // Default title color
        [ret setTitleColor:[UIColor colorWithRed:0.0f green:0.47843137f blue:1.0f alpha:1.0f] forState:UIControlStateNormal];

        // Default disabled title color
        [ret setTitleColor:[UIColor lightTextColor] forState:UIControlStateDisabled];
    }

    return ret;
}

static ComPtr<IInspectable> _currentInspectableImage(UIButton* self) {
    if (self->_states[self->_curState].inspectableImage) {
        return self->_states[self->_curState].inspectableImage;
    }

    return self->_states[UIControlStateNormal].inspectableImage;
}

/**
 @Status Interoperable
*/
- (UILabel*)titleLabel {
    return _titleLabel;
}

/**
 @Status Caveat
 @Notes Returns a mock UIImageView that proxies some common properties and selectors to the underlying Image
*/
- (UIImageView*)imageView {
    return (UIImageView*)_proxyImageView;
}

/**
 @Status Interoperable
*/
- (CGSize)intrinsicContentSize {
    CGSize ret = CGSizeZero;

    ////////////////////////////////////////////////////////////////////
    // Note: #1365 All size calculations here must check for nil,
    // as we cannot assume getting a size from nil will return CGSizeZero
    ////////////////////////////////////////////////////////////////////

    // Size should at least fit the image in a normal state.
    UIImage* currentImage = self.currentImage;
    if (currentImage) {
        ret = [currentImage size];
    }

    // TODO: Should we be asking our label for its intrinsicContentSize?
    CGSize textSize = CGSizeZero;
    NSString* currentTitle = self.currentTitle;
    if (currentTitle && (currentTitle.length > 0)) {
        // We need to round the font size to the nearest pixel value to avoid rounding errors when used in conjunction with the
        // frame values that are rounded by UIView.
        textSize = doPixelRound([currentTitle sizeWithFont:self.font]);
        ret.width = std::max(textSize.width, ret.width);
        ret.height = std::max(textSize.height, ret.height);
    }

    // If we have a background, its image size dictates the smallest size.
    UIEdgeInsets contentInsets = self.contentEdgeInsets;
    UIImage* currentBackgroundImage = self.currentBackgroundImage;
    if (currentBackgroundImage) {
        CGSize imageSize = [currentBackgroundImage size];
        ret.width = std::max(imageSize.width, ret.width);
        ret.height = std::max(imageSize.height, ret.height);
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
 @Status NotInPlan
 @Notes Custom rendering over derived UIButtons is not currently supported.
*/
- (CGRect)backgroundRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED_WITH_MSG("Custom rendering over derived UIButtons is not currently supported.");
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes Attributed text is not easily supported by Xaml.
*/
- (NSAttributedString*)attributedTitleForState:(UIControlState)state {
    UNIMPLEMENTED_WITH_MSG("Attributed text is not easily supported by Xaml.");
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes Attributed text is not easily supported by Xaml.
*/
- (void)setAttributedTitle:(NSAttributedString*)title forState:(UIControlState)state {
    UNIMPLEMENTED_WITH_MSG("Attributed text is not easily supported by Xaml.");
}

/**
 @Status NotInPlan
 @Notes Attributed text is not easily supported by Xaml.
*/
- (NSAttributedString*)currentAttributedTitle {
    UNIMPLEMENTED_WITH_MSG("Attributed text is not easily supported by Xaml.");
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)setLineBreakMode:(UILineBreakMode)mode {
    self.titleLabel.lineBreakMode = mode;
}

/**
 @Status Interoperable
*/
- (UILineBreakMode)lineBreakMode {
    return self.titleLabel.lineBreakMode;
}

@end