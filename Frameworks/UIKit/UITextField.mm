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

#import <UIKit/NSString+UIKitAdditions.h>
#import <UIKit/UIColor.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIFont.h>
#import <UIKit/UIImage.h>
#import <UIKit/UIImageView.h>
#import <UIKit/UITableViewCell.h>
#import <UIKit/UITextField.h>
#import <UIKit/UIView.h>
#import <UIKit/UIViewController.h>

#import "XamlControls.h"
#import "XamlUtilities.h"
#import "CppWinRTHelpers.h"

#import "CGContextInternal.h"
#import <CoreGraphics/CGContext.h>

#import "StarboardXaml/DisplayTexture.h"
#import "UIApplicationInternal.h"
#import <UIFontInternal.h>
#import "UIResponderInternal.h"
#import <Foundation/NSNotificationCenter.h>
#import <Foundation/NSTimer.h>

#include "COMIncludes.h"
#import <winrt/Windows.UI.Text.h>
#include "COMIncludes_End.h"

using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Text;

// Empirically discovered global minimum font size
static const CGFloat g_minimumFontSize = 14.0f;

static const wchar_t* TAG = L"UITextField";

NSString* const UITextFieldTextDidBeginEditingNotification = @"UITextFieldTextDidBeginEditingNotification";
NSString* const UITextFieldTextDidChangeNotification = @"UITextFieldTextDidChangeNotification";
NSString* const UITextFieldTextDidEndEditingNotification = @"UITextFieldTextDidEndEditingNotification";

// This is a hidden view control used to steal focus typically when a text field OSK (on screen keyboard) is dismissed.
@interface _UIHiddenButtonView : UIView
@end

@implementation _UIHiddenButtonView
@end

void SetTextControlContentVerticalAlignment(const Controls::Control& control, VerticalAlignment alignment) {
    FrameworkElement elem = XamlUtilities::FindTemplateChild(control, @"ContentElement");

    // set verticalAligment of both content and placeholder of TextBox (or PasswordBox) to be the same value
    if (elem) {
        elem.VerticalAlignment(alignment);
    }

    elem = XamlUtilities::FindTemplateChild(control, @"PlaceholderTextContentPresenter");
    if (elem) {
        elem.VerticalAlignment(alignment);
    }
}

@implementation UITextField {
    StrongId<UIFont> _font;
    StrongId<UIFont> _adjustedFont;
    StrongId<UIImage> _backgroundImage;
    UITextBorderStyle _borderStyle;

    BOOL _secureTextMode;
    BOOL _isFirstResponder;
    CGFloat _minimumFontSize;

    // backing keyboard Behavior
    UITextAutocapitalizationType _autoCapitalizatonType;
    UIKeyboardType _keyboardType;
    UITextAutocorrectionType _autoCorrectionType;
    UITextSpellCheckingType _spellCheckingType;
    BOOL _enablesReturnKeyAutomatically;
    BOOL _adjustsFontSizeToFitWidth;

    // backing xaml textbox and passwordBox
    StrongId<UIView> _subView; // Container UIView for the Xaml textbox or passwordbox
    TrivialDefaultConstructor<Controls::TextBox> _textBox; // Backing xaml textbox
    TrivialDefaultConstructor<Controls::PasswordBox> _passwordBox; // Backing xaml passwordbox
    TrivialDefaultConstructor<Controls::Control> _textContentElement; // ContentElement from the TextBox template to calculate width
    TrivialDefaultConstructor<Controls::Control> _passwordContentElement; // ContentElement from the PasswordBox template to calculate width

    // lock use to access the properties
    StrongId<NSRecursiveLock> _secureModeLock;

    // dummy control to steal the focus
    TrivialDefaultConstructor<Controls::Button> _dummyButton;
    StrongId<_UIHiddenButtonView> _hiddenView;
}

//
// Properties Accessing the Text Attributes
//
/**
 @Status Interoperable
*/
- (void)setText:(NSString*)text {
    [_secureModeLock lock];
    if (_secureTextMode) {
        _passwordBox.Password(objcwinrt::string(text));
    } else {
        _textBox.Text(objcwinrt::string(text));
        // Ensure caret at end of field in case we programmatically
        // gain focus (becomeFirstResponder) after the text is set:
        _textBox.SelectionStart([text length]);
        _textBox.SelectionLength(0);
    }
    [_secureModeLock unlock];

    [self _adjustFontSizeToFitWidthOrApplyCurrentFont];
}

/**
 @Status Interoperable
*/
- (NSString*)text {
    if (_secureTextMode) {
        return objcwinrt::string(_passwordBox.Password());
    } else {
        return objcwinrt::string(_textBox.Text());
    }
}

/**
 @Status Stub
*/
- (void)setAttributedText:(NSString*)attributedText {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (NSAttributedString*)attributedText {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)setPlaceholder:(NSString*)placeholder {
    [_secureModeLock lock];
    if (_secureTextMode) {
        _passwordBox.PlaceholderText(objcwinrt::string(placeholder));
    } else {
        _textBox.PlaceholderText(objcwinrt::string(placeholder));
    }
    [_secureModeLock unlock];
}

/**
 @Status Interoperable
*/
- (NSString*)placeholder {
    if (_secureTextMode) {
        return objcwinrt::string(_passwordBox.PlaceholderText());
    } else {
        return objcwinrt::string(_textBox.PlaceholderText());
    }
}

/**
 @Status Stub
*/
- (void)setAttributedPlaceholder:(NSString*)atributedStr {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (NSAttributedString*)attributedPlaceholder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setDefaultTextAttributes:(NSDictionary*)defaultAttributes {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (NSDictionary*)defaultTextAttributes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)setFont:(UIFont*)font {
    if (font == nil) {
        _font = [UIFont fontWithName:@"Segoe UI" size:[UIFont labelFontSize]];
    } else {
        _font = font;
    }

    [self _adjustFontSizeToFitWidthOrApplyCurrentFont];
}

- (void)_applyFont:(UIFont*)font {
    Media::FontFamily fontFamily(objcwinrt::string([font _compatibleFamilyName]));
    _textBox.FontFamily(fontFamily);
    _passwordBox.FontFamily(fontFamily);

    // The following enums map from DWrite directly to Xaml
    _textBox.FontStretch((FontStretch)[font _fontStretch]);
    _passwordBox.FontStretch((FontStretch)[font _fontStretch]);

    _textBox.FontStyle((FontStyle)[font _fontStyle]);
    _passwordBox.FontStyle((FontStyle)[font _fontStyle]);

    _textBox.FontSize(font.pointSize);
    _passwordBox.FontSize(font.pointSize);

    winrt::Windows::UI::Text::FontWeight weight;

    switch ([font _fontWeight]) {
        case DWRITE_FONT_WEIGHT_THIN:
            weight = FontWeights::Thin();
            break;
        // case DWRITE_FONT_WEIGHT_EXTRA_LIGHT:
        case DWRITE_FONT_WEIGHT_ULTRA_LIGHT:
            weight = FontWeights::ExtraLight();
            break;
        case DWRITE_FONT_WEIGHT_LIGHT:
            weight = FontWeights::Light();
            break;
        case DWRITE_FONT_WEIGHT_SEMI_LIGHT:
            weight = FontWeights::SemiLight();
        // case DWRITE_FONT_WEIGHT_NORMAL:
        case DWRITE_FONT_WEIGHT_REGULAR:
            weight = FontWeights::Normal();
            break;
        case DWRITE_FONT_WEIGHT_MEDIUM:
            weight = FontWeights::Medium();
            break;
        // case DWRITE_FONT_WEIGHT_DEMI_BOLD:
        case DWRITE_FONT_WEIGHT_SEMI_BOLD:
            weight = FontWeights::SemiBold();
            break;
        case DWRITE_FONT_WEIGHT_BOLD:
            weight = FontWeights::Bold();
            break;
        // case DWRITE_FONT_WEIGHT_EXTRA_BOLD:
        case DWRITE_FONT_WEIGHT_ULTRA_BOLD:
            weight = FontWeights::ExtraBold();
            break;
        // case DWRITE_FONT_WEIGHT_BLACK:
        case DWRITE_FONT_WEIGHT_HEAVY:
            weight = FontWeights::Black();
            break;
        // case DWRITE_FONT_WEIGHT_EXTRA_BLACK
        case DWRITE_FONT_WEIGHT_ULTRA_BLACK:
            weight = FontWeights::ExtraBlack();
            break;
        default:
            TraceWarning(TAG, L"Unknown font weight, using normal");
            weight = FontWeights::Normal();
            break;
    }

    _textBox.FontWeight(weight);
    _passwordBox.FontWeight(weight);
}

/**
 @Status Interoperable
*/
- (UIFont*)font {
    return _font;
}

/**
 @Status Interoperable
*/
- (void)setTextColor:(UIColor*)color {
/*
    WUColor* convertedColor = XamlUtilities::ConvertUIColorToWUColor(color);
    WUXMSolidColorBrush* brush = [WUXMSolidColorBrush makeInstanceWithColor:convertedColor];

    [_secureModeLock lock];
    if (_secureTextMode) {
        _passwordBox.foreground = brush;
    } else {
        _textBox.foreground = brush;
    }
    [_secureModeLock unlock];
*/
}

/**
 @Status Interoperable
*/
- (UIColor*)textColor {
    Media::SolidColorBrush colorBrush = nullptr;
    if (_secureTextMode) {
        colorBrush = _passwordBox.Foreground().try_as<Media::SolidColorBrush>();
    } else {
        colorBrush = _textBox.Foreground().try_as<Media::SolidColorBrush>();
    }

    if (colorBrush) {
        //return XamlUtilities::ConvertWUColorToUIColor(colorBrush.color);
    }

    return nil;
}

/**
 @Status Interoperable
*/
- (void)setBackgroundColor:(UIColor*)color {
    // In class WXCTextBox and WXCPasswordBox, there is just one ivar 'background' for both background color and background image.
    // When setting background color, clear out _backgroundImage assigning it to nil.
    _backgroundImage = nil;
    /*
    WUColor* convertedColor = XamlUtilities::ConvertUIColorToWUColor(color);
    WUXMSolidColorBrush* brush = [WUXMSolidColorBrush makeInstanceWithColor:convertedColor];

    [_secureModeLock lock];
    if (_secureTextMode) {
        _passwordBox.background = brush;
    } else {
        _textBox.background = brush;
    }
    [_secureModeLock unlock];
    */
}

/**
 @Status Interoperable
*/
- (UIColor*)backgroundColor {
    Media::SolidColorBrush colorBrush = nullptr;
    if (_secureTextMode && _passwordBox.Background()) {
        colorBrush = _passwordBox.Background().try_as<Media::SolidColorBrush>();
    } else if (!_secureTextMode && _textBox.Background()) {
        colorBrush = _textBox.Background().try_as<Media::SolidColorBrush>();
    }

    if (colorBrush) {
        //return XamlUtilities::ConvertWUColorToUIColor(colorBrush.color);
    }

    return nil;
}

/**
 @Status Interoperable
*/
- (void)setTextAlignment:(UITextAlignment)alignment {
    [_secureModeLock lock];
    if (!_secureTextMode) {
        // passwordBox does not support text alignment
        _textBox.TextAlignment(XamlUtilities::ConvertUITextAlignmentToWXTextAlignment(alignment));
    } else {
        UNIMPLEMENTED_WITH_MSG("SecureTextEntry mode does not support UITextAlignment");
    }
    [_secureModeLock unlock];
}

/**
 @Status Interoperable
*/
- (UITextAlignment)textAlignment {
    if (_secureTextMode) {
        return UITextAlignmentLeft;
    } else {
        return XamlUtilities::ConvertWXTextAlignmentToUITextAlignment(_textBox.TextAlignment());
    }
}

/**
 @Status Stub
*/
- (void)setTypingAttributes:(NSDictionary*)typingAttributes {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (NSDictionary*)typingAttributes {
    UNIMPLEMENTED();
    return StubReturn();
}

//
// Properties: Sizing the Text Field’s Text
//
/**
 @Status Interoperable
*/
- (void)setAdjustsFontSizeToFitWidth:(BOOL)adjust {
    _adjustsFontSizeToFitWidth = adjust;
    [self _adjustFontSizeToFitWidthOrApplyCurrentFont];
}

/**
 @Status Interoperable
*/
- (BOOL)adjustsFontSizeToFitWidth {
    return _adjustsFontSizeToFitWidth;
}

- (void)_adjustFontSizeToFitWidthOrApplyCurrentFont {
    _adjustedFont = self.font;

    if (_adjustedFont == nil) {
        _adjustedFont = [UIFont fontWithName:@"Segoe UI" size:[UIFont labelFontSize]];
    }

    // If the min size is greater than our font size, the font wins out.
    // If the font's pointsize is smaller than the global min font size, the font wins out.
    if (self.adjustsFontSizeToFitWidth && (self.minimumFontSize < _adjustedFont.pointSize) &&
        (_adjustedFont.pointSize > g_minimumFontSize) && self.text && self.text.length) {
        NSString* passwordString = nil;
        CGFloat elementWidth = 0.0f;

        // Measure using the password masking character, not the verbatim text
        if (self->_secureTextMode) {
            if (!_passwordContentElement) {
                // Not an error, we just might not be loaded yet.
                [self _applyFont:_adjustedFont];
                return;
            }
            passwordString = [@"" stringByPaddingToLength:self.text.length withString:objcwinrt::string(_passwordBox.PasswordChar()) startingAtIndex:0];
            elementWidth =
                _passwordContentElement.ActualWidth() - _passwordContentElement.Padding().Left - _passwordContentElement.Padding().Right;
        } else {
            if (!_textContentElement) {
                // Not an error, we just might not be loaded yet.
                [self _applyFont:_adjustedFont];
                return;
            }
            elementWidth = _textContentElement.ActualWidth() - _textContentElement.Padding().Left - _textContentElement.Padding().Right;
        }

        // Try smaller and smaller fonts until it fits within the size, or mins out
        while (_adjustedFont.pointSize > self.minimumFontSize) {
            // Grab the width directly from the ContentElement, to allow the cancel button to be considered.
            if (self->_secureTextMode) {
                CGSize size = [passwordString sizeWithFont:_adjustedFont];
                if (!_passwordContentElement || (size.width <= elementWidth)) {
                    break;
                }
            } else {
                CGSize size = [self.text sizeWithFont:_adjustedFont];
                if (!_textContentElement || (size.width <= elementWidth)) {
                    break;
                }
            }

            CGFloat newFontSize = _adjustedFont.pointSize - 1;
            if (newFontSize < g_minimumFontSize) {
                _adjustedFont = [_adjustedFont fontWithSize:g_minimumFontSize];
                break;
            } else if (newFontSize < self.minimumFontSize) {
                _adjustedFont = [_adjustedFont fontWithSize:self.minimumFontSize];
                break;
            }

            _adjustedFont = [_adjustedFont fontWithSize:newFontSize];
        }
        [self _applyFont:_adjustedFont];
    } else {
        [self _applyFont:self.font];
    }
}

/**
 @Status Interoperable
*/
- (void)setMinimumFontSize:(CGFloat)fontSize {
    _minimumFontSize = fontSize;
    [self _adjustFontSizeToFitWidthOrApplyCurrentFont];
}

/**
 @Status Interoperable
*/
- (CGFloat)minimumFontSize {
    return _minimumFontSize;
}

//
// Managing the Editing Behavior
//
/**
 @Status Interoperable
*/
- (BOOL)isEditing {
    if (_secureTextMode) {
        return _passwordBox.FocusState() != FocusState::Unfocused;
    } else {
        return _textBox.FocusState() != FocusState::Unfocused;
    }
}

/**
 @Status Stub
*/
- (void)setClearsOnBeginEditing:(BOOL)value {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (BOOL)clearOnBeginEditing {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setclearsOnInsertion:(BOOL)value {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (BOOL)clearsOnInsertion {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setAllowsEditingTextAttributes:(BOOL)value {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (BOOL)allowsEditingTextAttributes {
    UNIMPLEMENTED();
    return StubReturn();
}

//
// Setting the View' Background Appearance
//
/**
 @Status Caveat
 @Notes Does not support UITextBorderStyleBezel
*/
- (void)setBorderStyle:(UITextBorderStyle)style {
    if (_borderStyle != style) {
        UITextBorderStyle oldStyle = _borderStyle;
        _borderStyle = style;

        [_secureModeLock lock];
        if (_secureTextMode) {
            XamlUtilities::SetControlBorderStyle(_passwordBox, _borderStyle);
        } else {
            XamlUtilities::SetControlBorderStyle(_textBox, _borderStyle);
        }
        /*
        WUColor* convertedColor = XamlUtilities::ConvertUIColorToWUColor(self.backgroundColor);
        WUXMSolidColorBrush* brush = [WUXMSolidColorBrush makeInstanceWithColor:convertedColor];

        // If _borderStyle is set to the UITextBorderStyleRoundedRect,
        // the custom background image associated with the text field is ignored.
        // _borderStyle == UITextBorderStyleRoundedRect means to
        // change _borderStyle from another style to UITextBorderStyleRoundedRect.
        if (_borderStyle == UITextBorderStyleRoundedRect && _backgroundImage != nil) {
            if (_secureTextMode) {
                _passwordBox.background = brush;
            } else {
                _textBox.background = brush;
            }
        }
        [_secureModeLock unlock];
        */
        // If _borderStyle is not set to the UITextBorderStyleRoundedRect,
        // the custom background image associated with the text field is shown.
        // oldStyle == UITextBorderStyleRoundedRect means to
        // change _borderStyle from UITextBorderStyleRoundedRect to another style.
        if (oldStyle == UITextBorderStyleRoundedRect) {
            self.background = _backgroundImage;
        }
    }
}

/**
 @Status Interoperable
*/
- (UITextBorderStyle)borderStyle {
    return _borderStyle;
}

/**
 @Status Caveat
 @Notes Does not support UIImage object that was initialized using a CIImage object
*/
- (void)setBackground:(UIImage*)image {
    _backgroundImage = image;

    // Gap: Need to add using CIImage to set ImageBrush when CGImage is NULL after CIImage is implemented.
    CGImageRef cgImg = [image CGImage];
    if (cgImg == NULL) {
        TraceWarning(TAG, L"cgImg is NULL, need to use CIImage to initialize ImageBrush.");
        return;
    }

    if (_borderStyle != UITextBorderStyleRoundedRect) {
        Microsoft::WRL::ComPtr<IInspectable> inspectableNode(DisplayTexture::GetBitmapForCGImage(cgImg));
        auto bitmapImageSource = objcwinrt::from_insp<Media::Imaging::BitmapSource>(inspectableNode);
        Media::ImageBrush imageBrush;
        imageBrush.ImageSource(bitmapImageSource);

        [_secureModeLock lock];
        if (_secureTextMode) {
            _passwordBox.Background(imageBrush);
        } else {
            _textBox.Background(imageBrush);
        }
        [_secureModeLock unlock];
    }
}

/**
 @Status Interoperable
*/
- (UIImage*)background {
    return _backgroundImage;
}

/**
 @Status Stub
*/
- (void)setDisabledBackground:(UIImage*)image {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UIImage*)disabledBackground {
    UNIMPLEMENTED();
    return StubReturn();
}

//
// Managing Overlay Views
//
/**
 @Status Stub
*/
- (void)setClearButtonMode:(UITextFieldViewMode)mode {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UITextFieldViewMode)clearButtonMode {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setLeftView:(UIView*)view {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UIView*)leftView {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setLeftViewMode:(UITextFieldViewMode)mode {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UITextFieldViewMode)leftViewMode {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setRightView:(UIView*)view {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UIView*)rightView {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setRightViewMode:(UITextFieldViewMode)mode {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UITextFieldViewMode)rightViewMode {
    UNIMPLEMENTED();
    return StubReturn();
}

//
// Drawing and positioning Overrides
//
/**
 @Status Stub
*/
- (CGRect)textRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)drawTextInRect:(CGRect)rect {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (CGRect)placeholderRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)drawPlaceholderInRect:(CGRect)rect {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (CGRect)borderRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGRect)editingRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGRect)clearButtonRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGRect)leftViewRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGRect)rightViewRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED();
    return StubReturn();
}

//
// Replacing the System Input Views
//
/**
 @Status Stub
*/
- (void)setInputView:(UIView*)view {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UIView*)inputView {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setInputAccessoryView:(UIView*)view {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UIView*)inputAccessoryView {
    UNIMPLEMENTED();
    return StubReturn();
}

//
// UITextInputTraits protocol defined properties,  Managing the Keyboard Behavior
//
/**
 @Status Stub
*/
- (void)setAutocapitalizationType:(UITextAutocapitalizationType)type {
    _autoCapitalizatonType = type;
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UITextAutocapitalizationType)autocapitalizationType {
    UNIMPLEMENTED();
    return _autoCapitalizatonType;
}

/**
 @Status Interoperable
*/
- (void)setAutocorrectionType:(UITextAutocorrectionType)type {
    _autoCorrectionType = type;
}

/**
 @Status Interoperable
*/
- (UITextAutocorrectionType)autocorrectionType {
    return _autoCorrectionType;
}

/**
 @Status Interoperable
*/
- (void)setSpellCheckingType:(UITextSpellCheckingType)type {
    _spellCheckingType = type;
}

/**
 @Status Interoperable
*/
- (UITextSpellCheckingType)spellCheckingType {
    return _spellCheckingType;
}

/**
 @Status Interoperable
*/
- (void)setEnablesReturnKeyAutomatically:(BOOL)enabled {
    _enablesReturnKeyAutomatically = enabled;
}

/**
 @Status Interoperable
*/
- (BOOL)enablesReturnKeyAutomatically {
    return _enablesReturnKeyAutomatically;
}

/**
 @Status Stub
*/
- (void)setKeyboardAppearance:(UIKeyboardAppearance)appearance {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UIKeyboardAppearance)keyboardAppearance {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)setKeyboardType:(UIKeyboardType)type {
    _keyboardType = type;

    [_secureModeLock lock];
    if (_secureTextMode) {
        _passwordBox.InputScope(XamlUtilities::ConvertKeyboardTypeToInputScope(_keyboardType, YES));
    } else {
        _textBox.InputScope(XamlUtilities::ConvertKeyboardTypeToInputScope(_keyboardType, NO));
    }
    [_secureModeLock unlock];
}

/**
 @Status Interoperable
*/
- (UIKeyboardType)keyboardType {
    return _keyboardType;
}

/**
 @Status Stub
*/
- (void)setReturnKeyType:(UIReturnKeyType)type {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UIReturnKeyType)returnKeyType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)setSecureTextEntry:(BOOL)secure {
    [_secureModeLock lock];
    if (_secureTextMode != secure) {
        if (secure) {
            [self _initPasswordBox:nil];
        } else {
            [self _initTextBox:nil];
        }
        _secureTextMode = secure;
    }
    [_secureModeLock unlock];
}

/**
 @Status Interoperable
*/
- (BOOL)isSecureTextEntry {
    return _secureTextMode;
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        // move to top so that setting properties below can happen on xamlElement
        [self _initUITextField:nil];

        _font = [coder decodeObjectForKey:@"UIFont"];
        self.textAlignment = (UITextAlignment)[coder decodeInt32ForKey:@"UITextAlignment"];
        self.borderStyle = (UITextBorderStyle)[coder decodeInt32ForKey:@"UIBorderStyle"];
        _keyboardType = (UIKeyboardType)[coder decodeInt32ForKey:@"UIKeyboardType"];
        _secureTextMode = [coder decodeInt32ForKey:@"UISecureTextEntry"];
        self.text = [coder decodeObjectForKey:@"UIText"];
        self.placeholder = [coder decodeObjectForKey:@"UIPlaceholder"];
        UIColor* textColor = [coder decodeObjectForKey:@"UITextColor"];
        if (textColor == nil) {
            textColor = [UIColor blackColor];
        }
        self.textColor = textColor;

        if (_font == nil) {
            _font = [UIFont fontWithName:@"Segoe UI" size:[UIFont labelFontSize]];
        }

        self.backgroundColor = [UIColor lightGrayColor];
        _backgroundImage = nil;
        _isFirstResponder = NO;

        [self _adjustFontSizeToFitWidthOrApplyCurrentFont];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        // move to top so that setting properties below can happen on xamlElement
        [self _initUITextField:nil];

        // TODO: Remove duplicate code from here and the initWithFrame:xamlElement: implementation.
        _font = [UIFont fontWithName:@"Segoe UI" size:[UIFont labelFontSize]];
        self.textAlignment = UITextAlignmentLeft;
        self.borderStyle = UITextBorderStyleNone;
        _secureTextMode = NO;
        self.textColor = [UIColor blackColor];
        self.backgroundColor = [UIColor lightGrayColor];
        _backgroundImage = nil;
        _spellCheckingType = UITextSpellCheckingTypeDefault;
        _isFirstResponder = NO;
    }

    return self;
}

- (id)initWithFrame:(CGRect)frame xamlElement:(const FrameworkElement&)xamlElement {
    // TODO: We're passing nullptr to initWithFrame:xamlElement: because we have to *contain* either a TextBox or a PasswordBox.
    // Note: Pass 'xamlElement' instead, once we move to a *single* backing Xaml element for UITextField.
    if (self = [super initWithFrame:frame xamlElement:nullptr]) {
        // move to top so that setting properties below can happen on xamlElement
        [self _initUITextField:xamlElement];

        _font = [UIFont fontWithName:@"Segoe UI" size:[UIFont labelFontSize]];
        self.textAlignment = UITextAlignmentLeft;
        self.borderStyle = UITextBorderStyleNone;
        _secureTextMode = NO;
        self.textColor = [UIColor blackColor];
        self.backgroundColor = [UIColor lightGrayColor];
        _backgroundImage = nil;
        _spellCheckingType = UITextSpellCheckingTypeDefault;
        _isFirstResponder = NO;
    }

    return self;
}

/**
 @Status Stub
*/
- (void)layoutSubviews {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)setEnabled:(BOOL)enabled {
    if (self.secureTextEntry) {
        self->_passwordBox.IsEnabled(enabled);
    } else {
        self->_textBox.IsEnabled(enabled);
    }
}

/**
 @Status Interoperable
*/
- (BOOL)isEnabled {
    if (self.secureTextEntry) {
        return self->_passwordBox.IsEnabled() ? YES : NO;
    } else {
        return self->_textBox.IsEnabled() ? YES : NO;
    }
}

//
// UIControl defined properties override
//
/**
 @Status Interoperable
*/
- (BOOL)becomeFirstResponder {
    if (_isFirstResponder) {
        return YES;
    }

    // Try to become first responder by setting focus
    if (self.secureTextEntry) {
        _isFirstResponder = self->_passwordBox.Focus(FocusState::Programmatic);
    } else {
        _isFirstResponder = self->_textBox.Focus(FocusState::Programmatic);
    }

    return _isFirstResponder;
}

/**
 @Status Interoperable
*/
- (BOOL)isFirstResponder {
    return _isFirstResponder;
}

/**
 @Status Interoperable
*/
- (BOOL)resignFirstResponder {
    if (![self isFirstResponder]) {
        return YES;
    }

    // Lost focus will take care of firstResponder status
    [self _killFocus];
    return YES;
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
- (UIColor*)tintColor {
    UNIMPLEMENTED();
    return StubReturn();
}

- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    [self becomeFirstResponder];
}

/**
 @Status Interoperable
*/
- (void)setContentVerticalAlignment:(UIControlContentVerticalAlignment)alignment {
    [super setContentVerticalAlignment:alignment];

    VerticalAlignment verticalAlignment =
        XamlUtilities::ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(self.contentVerticalAlignment);

    [_secureModeLock lock];
    if (self.secureTextEntry) {
        SetTextControlContentVerticalAlignment(self->_passwordBox, verticalAlignment);
    } else {
        SetTextControlContentVerticalAlignment(self->_textBox, verticalAlignment);
    }
    [_secureModeLock unlock];
}

//
// UIKeyInput Protocol related methods
//
/**
 @Status Stub
*/
- (void)deleteBackward {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)insertText:(NSString*)text {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (BOOL)hasText {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UITextRange*)textRangeFromPosition:(UITextPosition*)fromPosition toPosition:(UITextPosition*)toPosition {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UITextPosition*)positionFromPosition:(UITextPosition*)position offset:(NSInteger)offset {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGRect)firstRectForRange:(UITextRange*)range {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGRect)caretRectForPosition:(UITextPosition*)position {
    UNIMPLEMENTED();
    return StubReturn();
}

// Kill the focus on this UITextField
- (void)_killFocus {
    _dummyButton.Focus(FocusState::Programmatic);
}

// Handler when control GotFocus
- (void)_setupControlGotFocusHandler:(const Controls::Control&)control {
    __weak UITextField* weakSelf = self;
    control.GotFocus([&control, weakSelf] (auto&& sender, auto&& e) {
        __strong UITextField* strongSelf = weakSelf;
        // when GotFocus, check delegate (if exists) to see if it allows start editing
        if ([strongSelf.delegate respondsToSelector:@selector(textFieldShouldBeginEditing:)] &&
            ![strongSelf.delegate textFieldShouldBeginEditing:strongSelf]) {
            // delegate says NO, but we already got the focus at this point, need to kill the focus on this control
            [strongSelf _killFocus];
            return;
        }

        // no one says NO, update first responder to YES
        strongSelf->_isFirstResponder = YES;

        // more delegate update
        if ([strongSelf.delegate respondsToSelector:@selector(textFieldDidBeginEditing:)]) {
            [strongSelf.delegate textFieldDidBeginEditing:strongSelf];
        }

        // more notification
        dispatch_async(dispatch_get_main_queue(), ^{
            [strongSelf sendActionsForControlEvents:UIControlEventEditingDidBegin];
            [[NSNotificationCenter defaultCenter] postNotificationName:UITextFieldTextDidBeginEditingNotification object:strongSelf];
        });

        // Update the collapsed/visible state of the cancel button and adjust text size.
        control.UpdateLayout();
        [strongSelf _adjustFontSizeToFitWidthOrApplyCurrentFont];
    });
}

// Handler when control LostFocus
- (void)_setupControlLostFocusHandler:(const Controls::Control&)control {
    auto weakControl = winrt::make_weak(control);
    __weak UITextField* weakSelf = self;

    control.LostFocus([weakSelf, weakControl] (auto&& sender, auto &&e) {
        __strong UITextField* strongSelf = weakSelf;
        auto strongControl = weakControl.get();

        if (strongSelf && strongControl) {
            // when LostFocus, check delegate (if exits) to see if it allows end Editing
            if ([strongSelf.delegate respondsToSelector:@selector(textFieldShouldEndEditing:)] &&
                ![strongSelf.delegate textFieldShouldEndEditing:strongSelf]) {
                // delegate does not allow edting to be ended, but we already lost the focus
                // we need re-setting the focus back. it will trigger GotFocusEvent again on this control
                // and then it will update the firstResponder status as YES
                strongControl.Focus(FocusState::Programmatic);
                return;
            }

            // no delegate say no, update firstResponder status to be NO
            strongSelf->_isFirstResponder = NO;

            // more delegate update
            if ([strongSelf.delegate respondsToSelector:@selector(textFieldDidEndEditing:)]) {
                [strongSelf.delegate textFieldDidEndEditing:strongSelf];
            }

            // more notification
            dispatch_async(dispatch_get_main_queue(), ^{
                [strongSelf sendActionsForControlEvents:UIControlEventEditingDidEnd];
                [[NSNotificationCenter defaultCenter] postNotificationName:UITextFieldTextDidEndEditingNotification object:strongSelf];
            });

            // Update the collapsed/visible state of the cancel button and adjust text size.
            strongControl.UpdateLayout();
            [strongSelf _adjustFontSizeToFitWidthOrApplyCurrentFont];
        }
    });
}

// Handler when KeyDown
- (void)_setupControlKeyDownHandler:(const Controls::Control&)control {
    __weak UITextField* weakSelf = self;

    // hooking up keydown event to process ENTER key
    control.KeyDown([weakSelf] (auto&& sender, auto&& e) {
        __strong UITextField* strongSelf = weakSelf;
        if (strongSelf && e.Key() == winrt::Windows::System::VirtualKey::Enter) {
            BOOL dismissKeyboard = TRUE;

            // check with delegate if should resign firstResponder and dismiss the keyboard
            if ([strongSelf.delegate respondsToSelector:@selector(textFieldShouldReturn:)]) {
                dismissKeyboard = [strongSelf.delegate textFieldShouldReturn:strongSelf];
            }

            if (dismissKeyboard) {
                [strongSelf resignFirstResponder];
            }

            e.Handled(true);
        } else {
            e.Handled(false);
        }
    });
}

// Helper to initialize textbox
- (void)_initTextBox:(const FrameworkElement&)xamlElement {
    if (xamlElement) {
        _textBox = xamlElement.try_as<Controls::TextBox>();
    }

    if (!_textBox) {
        _textBox = Controls::TextBox();
    }

    // Remove the old subview (if it exists)
    [_subView removeFromSuperview];

    // Create a new view for the xaml element and add it as a subview of ourselves
    _subView = [[UIView alloc] initWithFrame:self.bounds xamlElement:_textBox];
    [_subView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
    [self addSubview:_subView];

    // if passwordbox exits, need to transfer the properties that we set on passwordbox to textbox
    if (_passwordBox != nil) {
        if (_backgroundImage == nil || self.borderStyle == UITextBorderStyleRoundedRect) {
        /*
            WUColor* convertedColor = XamlUtilities::ConvertUIColorToWUColor(self.backgroundColor);
            WUXMSolidColorBrush* brush = [WUXMSolidColorBrush makeInstanceWithColor:convertedColor];
            _textBox.background = brush;
        */
        }

        /*
        WUColor* convertedTextColor = XamlUtilities::ConvertUIColorToWUColor(self.textColor);
        WUXMSolidColorBrush* textBrush = [WUXMSolidColorBrush makeInstanceWithColor:convertedTextColor];
        _textBox.foreground = textBrush;
        */

        _textBox.TextAlignment(XamlUtilities::ConvertUITextAlignmentToWXTextAlignment(self.textAlignment));
        _textBox.InputScope(XamlUtilities::ConvertKeyboardTypeToInputScope(_keyboardType, NO));
        _textBox.Text(objcwinrt::string(self.text));
        _textBox.PlaceholderText(objcwinrt::string(self.placeholder));
        _textBox.IsSpellCheckEnabled(self.spellCheckingType == UITextSpellCheckingTypeYes);

        // clean up passwordbox after transfering the properties
        self->_passwordBox = nullptr;
    }

    // setting up addtional textbox properties in loaded listener that requires looking into control template
    __weak UITextField* weakSelf = self;
    self->_textBox.Loaded([weakSelf] (auto&& sender, auto&& e) {
        __strong UITextField* strongSelf = weakSelf;
        XamlUtilities::SetControlBorderStyle(strongSelf->_textBox, strongSelf.borderStyle);
        VerticalAlignment verticalAlignment =
            XamlUtilities::ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(strongSelf.contentVerticalAlignment);
        SetTextControlContentVerticalAlignment(strongSelf->_textBox, verticalAlignment);

        // retrieve the ContentElement from the template
        FrameworkElement frameworkElement = XamlUtilities::FindTemplateChild(strongSelf->_textBox, @"ContentElement");
        strongSelf->_textContentElement = frameworkElement ? frameworkElement.as<Controls::Control>() : nullptr;

        if (!strongSelf->_textContentElement) {
            TraceWarning(TAG, L"Could not find ContentElement in control template: adjustsFontSizeToFitWidth will not function");
        }

        [strongSelf _adjustFontSizeToFitWidthOrApplyCurrentFont];
    });

    // set up text change event handler
    self->_textBox.TextChanged([weakSelf] (auto&& sender, auto&& e) {
        __strong UITextField* strongSelf = weakSelf;
        if (strongSelf) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [strongSelf sendActionsForControlEvents:UIControlEventEditingChanged];
                [[NSNotificationCenter defaultCenter] postNotificationName:UITextFieldTextDidChangeNotification object:strongSelf];
            });
        }
    });

    // set up focus and keydown handlers
    [self _setupControlGotFocusHandler:_textBox];
    [self _setupControlLostFocusHandler:_textBox];
    [self _setupControlKeyDownHandler:_textBox];
}

// Helper to Initialize passwordBox
- (void)_initPasswordBox:(const FrameworkElement&)xamlElement {
    _passwordBox = Controls::PasswordBox();

    // set up focus and keydown handlers
    [self _setupControlGotFocusHandler:_passwordBox];
    [self _setupControlLostFocusHandler:_passwordBox];
    [self _setupControlKeyDownHandler:_passwordBox];

    // Remove the old subview (if it exists)
    [_subView removeFromSuperview];

    // Create a new view for the xaml element and add it as a subview of ourselves
    _subView = [[UIView alloc] initWithFrame:self.bounds xamlElement:_passwordBox];
    [_subView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
    [self addSubview:_subView];

    // if textbox exists, need to transfer the properties from textbox to passwordbox
    if (_textBox) {
        if (_backgroundImage == nil || self.borderStyle == UITextBorderStyleRoundedRect) {
            /*
            WUColor* convertedColor = XamlUtilities::ConvertUIColorToWUColor(self.backgroundColor);
            WUXMSolidColorBrush* brush = [WUXMSolidColorBrush makeInstanceWithColor:convertedColor];
            _passwordBox.background = brush;
            */
        }

        /*
        WUColor* convertedTextColor = XamlUtilities::ConvertUIColorToWUColor(self.textColor);
        WUXMSolidColorBrush* textBrush = [WUXMSolidColorBrush makeInstanceWithColor:convertedTextColor];
        _passwordBox.foreground = textBrush;
        // passwordBox does not support textAlignment
        */

        // border manipulate the control tempate and must be done after loaded
        XamlUtilities::SetControlBorderStyle(_passwordBox, self.borderStyle);
        VerticalAlignment verticalAlignment =
            XamlUtilities::ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(self.contentVerticalAlignment);
        SetTextControlContentVerticalAlignment(_passwordBox, verticalAlignment);
        _passwordBox.InputScope(XamlUtilities::ConvertKeyboardTypeToInputScope(_keyboardType, YES));

        _passwordBox.Password(objcwinrt::string(self.text));
        _passwordBox.PlaceholderText(objcwinrt::string(self.placeholder));

        // clean up textbox after transfering the properties
        _textBox = nullptr;
    }

    // set up password change handler
    __weak UITextField* weakSelf = self;

    self->_passwordBox.Loaded([weakSelf] (auto&& sender, auto&& e) {
        __strong UITextField* strongSelf = weakSelf;
        XamlUtilities::SetControlBorderStyle(strongSelf->_passwordBox, strongSelf.borderStyle);
        VerticalAlignment verticalAlignment =
            XamlUtilities::ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(strongSelf.contentVerticalAlignment);
        SetTextControlContentVerticalAlignment(strongSelf->_passwordBox, verticalAlignment);

        // retrieve the ContentElement from the template
        FrameworkElement frameworkElement = XamlUtilities::FindTemplateChild(strongSelf->_passwordBox, @"ContentElement");
        strongSelf->_textContentElement = frameworkElement ? frameworkElement.as<Controls::Control>() : nullptr;

        if (!strongSelf->_textContentElement) {
            TraceWarning(TAG, L"Could not find ContentElement in control template: adjustsFontSizeToFitWidth will not function");
        }

        [strongSelf _adjustFontSizeToFitWidthOrApplyCurrentFont];
    });

    self->_passwordBox.PasswordChanged([weakSelf] (auto&& sender, auto&& e) {
        __strong UITextField* strongSelf = weakSelf;
        if (strongSelf) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [strongSelf sendActionsForControlEvents:UIControlEventEditingChanged];
            });
        }
    });
}

// Main entrance to initialize TextField
- (void)_initUITextField:(const FrameworkElement&)xamlElement {
    self->_secureModeLock = [NSRecursiveLock new];

    // creating dummy button and hidden view so that it can be used to steal/kill the focus for this UITextField
    self->_dummyButton = Controls::Button();
    self->_dummyButton.Visibility(Visibility::Visible);
    self->_dummyButton.IsEnabled(true);
    self->_dummyButton.IsTabStop(true);

    _hiddenView = [[_UIHiddenButtonView alloc] initWithFrame:CGRectZero xamlElement:_dummyButton];
    [self addSubview:_hiddenView];

    if (self->_secureTextMode) {
        [self _initPasswordBox:nullptr];
    } else {
        [self _initTextBox:xamlElement];
    }
}

@end
