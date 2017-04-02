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

#import "CGContextInternal.h"
#import <CoreGraphics/CGContext.h>

#import "StarboardXaml/DisplayTexture.h"
#import "UIApplicationInternal.h"
#import <UIFontInternal.h>
#import "UIResponderInternal.h"
#import <Foundation/NSNotificationCenter.h>
#import <Foundation/NSTimer.h>

#import <UWP/WindowsUIXamlControls.h>

// Empirically discovered global minimum font size
static const CGFloat g_minimumFontSize = 14.0f;

static const wchar_t* TAG = L"UITextField";

NSString* const UITextFieldTextDidBeginEditingNotification = @"UITextFieldTextDidBeginEditingNotification";
NSString* const UITextFieldTextDidChangeNotification = @"UITextFieldTextDidChangeNotification";
NSString* const UITextFieldTextDidEndEditingNotification = @"UITextFieldTextDidEndEditingNotification";

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
    StrongId<WXFrameworkElement> _textField; // Backing user control
    StrongId<WXCTextBox> _textBox; // Backing xaml textbox
    StrongId<WXCPasswordBox> _passwordBox; // Backing xaml passwordbox
    StrongId<WXCControl> _textContentElement; // ContentElement from the TextBox template to calculate width
    StrongId<WXCControl> _passwordContentElement; // ContentElement from the PasswordBox template to calculate width

    // lock use to access the properties
    StrongId<NSRecursiveLock> _secureModeLock;
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
        _passwordBox.password = [text copy];
    } else {
        _textBox.text = [text copy];

        // Ensure caret at end of field in case we programmatically
        // gain focus (becomeFirstResponder) after the text is set:
        _textBox.selectionStart = [text length];
        _textBox.selectionLength = 0;
    }
    [_secureModeLock unlock];

    [self _adjustFontSizeToFitWidthOrApplyCurrentFont];
}

/**
 @Status Interoperable
*/
- (NSString*)text {
    if (_secureTextMode) {
        return _passwordBox.password;
    } else {
        return _textBox.text;
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
        _passwordBox.placeholderText = [placeholder copy];
    } else {
        _textBox.placeholderText = [placeholder copy];
    }
    [_secureModeLock unlock];
}

/**
 @Status Interoperable
*/
- (NSString*)placeholder {
    if (_secureTextMode) {
        return _passwordBox.placeholderText;
    } else {
        return _textBox.placeholderText;
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
    _passwordBox.fontFamily = _textBox.fontFamily = [WUXMFontFamily makeInstanceWithName:[font _compatibleFamilyName]];

    // The following enums map from DWrite directly to Xaml
    _passwordBox.fontStretch = _textBox.fontStretch = (WUTFontStretch)[font _fontStretch];
    _passwordBox.fontStyle = _textBox.fontStyle = (WUTFontStyle)[font _fontStyle];
    _passwordBox.fontSize = _textBox.fontSize = font.pointSize;

    WUTFontWeight* weight = nil;

    switch ([font _fontWeight]) {
        case DWRITE_FONT_WEIGHT_THIN:
            weight = [WUTFontWeights thin];
            break;
        // case DWRITE_FONT_WEIGHT_EXTRA_LIGHT:
        case DWRITE_FONT_WEIGHT_ULTRA_LIGHT:
            weight = [WUTFontWeights extraLight];
            break;
        case DWRITE_FONT_WEIGHT_LIGHT:
            weight = [WUTFontWeights light];
            break;
        case DWRITE_FONT_WEIGHT_SEMI_LIGHT:
            weight = [WUTFontWeights semiLight];
        // case DWRITE_FONT_WEIGHT_NORMAL:
        case DWRITE_FONT_WEIGHT_REGULAR:
            weight = [WUTFontWeights normal];
            break;
        case DWRITE_FONT_WEIGHT_MEDIUM:
            weight = [WUTFontWeights medium];
            break;
        // case DWRITE_FONT_WEIGHT_DEMI_BOLD:
        case DWRITE_FONT_WEIGHT_SEMI_BOLD:
            weight = [WUTFontWeights semiBold];
            break;
        case DWRITE_FONT_WEIGHT_BOLD:
            weight = [WUTFontWeights bold];
            break;
        // case DWRITE_FONT_WEIGHT_EXTRA_BOLD:
        case DWRITE_FONT_WEIGHT_ULTRA_BOLD:
            weight = [WUTFontWeights extraBold];
            break;
        // case DWRITE_FONT_WEIGHT_BLACK:
        case DWRITE_FONT_WEIGHT_HEAVY:
            weight = [WUTFontWeights black];
            break;
        // case DWRITE_FONT_WEIGHT_EXTRA_BLACK
        case DWRITE_FONT_WEIGHT_ULTRA_BLACK:
            weight = [WUTFontWeights extraBlack];
            break;
        default:
            TraceWarning(TAG, L"Unknown font weight, using normal");
            weight = [WUTFontWeights normal];
            break;
    }

    _passwordBox.fontWeight = _textBox.fontWeight = weight;
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
    WUColor* convertedColor = XamlUtilities::ConvertUIColorToWUColor(color);
    WUXMSolidColorBrush* brush = [WUXMSolidColorBrush makeInstanceWithColor:convertedColor];

    [_secureModeLock lock];
    if (_secureTextMode) {
        _passwordBox.foreground = brush;
    } else {
        _textBox.foreground = brush;
    }
    [_secureModeLock unlock];
}

/**
 @Status Interoperable
*/
- (UIColor*)textColor {
    WUXMSolidColorBrush* colorBrush = nil;
    if (_secureTextMode) {
        colorBrush = rt_dynamic_cast<WUXMSolidColorBrush>(_passwordBox.foreground);
    } else {
        colorBrush = rt_dynamic_cast<WUXMSolidColorBrush>(_textBox.foreground);
    }

    if (colorBrush != nil) {
        return XamlUtilities::ConvertWUColorToUIColor(colorBrush.color);
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

    WUColor* convertedColor = XamlUtilities::ConvertUIColorToWUColor(color);
    WUXMSolidColorBrush* brush = [WUXMSolidColorBrush makeInstanceWithColor:convertedColor];

    [_secureModeLock lock];
    if (_secureTextMode) {
        _passwordBox.background = brush;
    } else {
        _textBox.background = brush;
    }
    [_secureModeLock unlock];
}

/**
 @Status Interoperable
*/
- (UIColor*)backgroundColor {
    WUXMSolidColorBrush* colorBrush = nil;
    if (_secureTextMode && _passwordBox.background != nullptr) {
        colorBrush = rt_dynamic_cast<WUXMSolidColorBrush>(_passwordBox.background);
    } else if (!_secureTextMode && _textBox.background != nullptr) {
        colorBrush = rt_dynamic_cast<WUXMSolidColorBrush>(_textBox.background);
    }

    if (colorBrush != nil) {
        return XamlUtilities::ConvertWUColorToUIColor(colorBrush.color);
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
        _textBox.textAlignment = XamlUtilities::ConvertUITextAlignmentToWXTextAlignment(alignment);
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
        return XamlUtilities::ConvertWXTextAlignmentToUITextAlignment(_textBox.textAlignment);
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
        if (_secureTextMode) {
            if (_passwordContentElement == nil) {
                // Not an error, we just might not be loaded yet.
                [self _applyFont:_adjustedFont];
                return;
            }
            passwordString = [@"" stringByPaddingToLength:self.text.length withString:_passwordBox.passwordChar startingAtIndex:0];
            elementWidth =
                _passwordContentElement.actualWidth - _passwordContentElement.padding.left - _passwordContentElement.padding.right;
        } else {
            if (_textContentElement == nil) {
                // Not an error, we just might not be loaded yet.
                [self _applyFont:_adjustedFont];
                return;
            }
            elementWidth = _textContentElement.actualWidth - _textContentElement.padding.left - _textContentElement.padding.right;
        }

        // Try smaller and smaller fonts until it fits within the size, or mins out
        while (_adjustedFont.pointSize > self.minimumFontSize) {
            // Grab the width directly from the ContentElement, to allow the cancel button to be considered.
            if (_secureTextMode) {
                CGSize size = [passwordString sizeWithFont:_adjustedFont];
                if ((_passwordContentElement == nil) || (size.width <= elementWidth)) {
                    break;
                }
            } else {
                CGSize size = [self.text sizeWithFont:_adjustedFont];
                if ((_textContentElement == nil) || (size.width <= elementWidth)) {
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
        return _passwordBox.focusState != WXFocusStateUnfocused;
    } else {
        return _textBox.focusState != WXFocusStateUnfocused;
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
        WUXMIBitmapSource* bitmapImageSource = XamlUtilities::CreateRtProxy([WUXMIBitmapSource class], inspectableNode.Get());
        WUXMImageBrush* imageBrush = [WUXMImageBrush make];
        imageBrush.imageSource = bitmapImageSource;

        [_secureModeLock lock];
        if (_secureTextMode) {
            _passwordBox.background = imageBrush;
        } else {
            _textBox.background = imageBrush;
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
        _passwordBox.inputScope = XamlUtilities::ConvertKeyboardTypeToInputScope(_keyboardType, YES);
    } else {
        _textBox.inputScope = XamlUtilities::ConvertKeyboardTypeToInputScope(_keyboardType, NO);
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
        XamlControls::SetTextFieldSecureTextEntryValue(_textField, secure);
        _secureTextMode = secure;

        if (secure) {
            [self _switchToPasswordBox];
        } else {
            [self _switchToTextBox];
        }
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
        BOOL secureTextEntry = [coder decodeInt32ForKey:@"UISecureTextEntry"];
        [self _initUITextField:secureTextEntry];

        // Font needs to be decoded first since setText will use the fontSize when adjusting
        // the text to fit if required.
        _font = [coder decodeObjectForKey:@"UIFont"];
        if (_font == nil) {
            _font = [UIFont fontWithName:@"Segoe UI" size:[UIFont labelFontSize]];
        }

        self.text = [coder decodeObjectForKey:@"UIText"];
        self.placeholder = [coder decodeObjectForKey:@"UIPlaceholder"];

        self.textAlignment = (UITextAlignment)[coder decodeInt32ForKey:@"UITextAlignment"];
        self.borderStyle = (UITextBorderStyle)[coder decodeInt32ForKey:@"UIBorderStyle"];
        self.textColor = [coder decodeObjectForKey:@"UITextColor"];
        if (self.textColor == nil) {
            self.textColor = [UIColor blackColor];
        }

        // TODO: Investigate if this is correct
        self.backgroundColor = [UIColor lightGrayColor];

        _keyboardType = (UIKeyboardType)[coder decodeInt32ForKey:@"UIKeyboardType"];
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
        [self _initUITextField:NO];

        // TODO: Remove duplicate code from here and the initWithFrame:xamlElement: implementation.
        self.textAlignment = UITextAlignmentLeft;
        self.borderStyle = UITextBorderStyleNone;
        self.textColor = [UIColor blackColor];
        self.backgroundColor = [UIColor lightGrayColor];

        _font = [UIFont fontWithName:@"Segoe UI" size:[UIFont labelFontSize]];
        _backgroundImage = nil;
        _spellCheckingType = UITextSpellCheckingTypeDefault;
        _isFirstResponder = NO;
    }

    return self;
}

- (id)initWithFrame:(CGRect)frame xamlElement:(WXFrameworkElement*)xamlElement {
    if (self = [super initWithFrame:frame xamlElement:xamlElement]) {
        // move to top so that setting properties below can happen on xamlElement
        [self _initUITextField:NO];

        self.textAlignment = UITextAlignmentLeft;
        self.borderStyle = UITextBorderStyleNone;
        self.textColor = [UIColor blackColor];
        self.backgroundColor = [UIColor lightGrayColor];

        _font = [UIFont fontWithName:@"Segoe UI" size:[UIFont labelFontSize]];
        _backgroundImage = nil;
        _spellCheckingType = UITextSpellCheckingTypeDefault;
        _isFirstResponder = NO;
    }

    return self;
}

/**
Microsoft Extension
*/
+ (WXFrameworkElement*)createXamlElement {
    // No autorelease needed because CreateTextField is autoreleased
    return XamlControls::CreateTextField();
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
        _passwordBox.isEnabled = enabled;
    } else {
        _textBox.isEnabled = enabled;
    }
}

/**
 @Status Interoperable
*/
- (BOOL)isEnabled {
    if (self.secureTextEntry) {
        return _passwordBox.isEnabled;
    } else {
        return _textBox.isEnabled;
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
        _isFirstResponder = [_passwordBox focus:WXFocusStateProgrammatic];
    } else {
        _isFirstResponder = [_textBox focus:WXFocusStateProgrammatic];
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

    WXVerticalAlignment verticalAlignment =
        XamlUtilities::ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(self.contentVerticalAlignment);

    [_secureModeLock lock];
    if (self.secureTextEntry) {
        [self setTextControlContentVerticalAlignment:_passwordBox verticalAlignment:verticalAlignment];
    } else {
        [self setTextControlContentVerticalAlignment:_textBox verticalAlignment:verticalAlignment];
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
    if (self.secureTextEntry) {
        _passwordBox.isEnabled = NO;
        _passwordBox.isEnabled = YES;
    } else {
        _textBox.isEnabled = NO;
        _textBox.isEnabled = YES;
    }
}

- (void)setTextControlContentVerticalAlignment:(WXCControl*)control verticalAlignment:(WXVerticalAlignment)alignment {
    // Set vertical aligment of both content and placeholder for TextBox and PasswordBox to the same value
    WXFrameworkElement* elem = XamlUtilities::FindTemplateChild(control, @"ContentElement");
    if (elem != nullptr) {
        elem.verticalAlignment = alignment;
    }

    elem = XamlUtilities::FindTemplateChild(control, @"PlaceholderTextContentPresenter");
    if (elem != nullptr) {
        elem.verticalAlignment = alignment;
    }
}

// Handler when control GotFocus
- (void)_setupControlGotFocusHandler:(WXCControl*)control {
    __weak WXCControl* weakControl = control;
    __weak UITextField* weakSelf = self;

    [control addGotFocusEvent:^void(RTObject* sender, WXRoutedEventArgs* e) {
        __strong UITextField* strongSelf = weakSelf;
        if (strongSelf) {
            // when GotFocus, check delegate (if exits) to see if it allows start editing
            if ([strongSelf.delegate respondsToSelector:@selector(textFieldShouldBeginEditing:)] &&
                ![strongSelf.delegate textFieldShouldBeginEditing:strongSelf]) {
                // delegate says NO, but we already got the focus at this point, need to kill the focus on this control
                // TODO: when GettingFocus event is available in xaml SDK, we should use that. for now, let us 
                // stick with enable/disable textbox/passwordbox to kill focus. tabbing support is much better than before
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
            [weakControl updateLayout];
            [strongSelf _adjustFontSizeToFitWidthOrApplyCurrentFont];
        }
    }];
}

// Handler when control LostFocus
- (void)_setupControlLostFocusHandler:(WXCControl*)control {
    __weak WXCControl* weakControl = control;
    __weak UITextField* weakSelf = self;

    [control addLostFocusEvent:^void(RTObject* sender, WXRoutedEventArgs* e) {
        __strong UITextField* strongSelf = weakSelf;
        if (strongSelf) {
            // when LostFocus, check delegate (if exits) to see if it allows end Editing
            if ([strongSelf.delegate respondsToSelector:@selector(textFieldShouldEndEditing:)] &&
                ![strongSelf.delegate textFieldShouldEndEditing:strongSelf]) {
                // delegate does not allow editing to be ended, but we already lost the focus
                // we need re-setting the focus back. it will trigger GotFocusEvent again on this control
                // and then it will update the firstResponder status as YES
                [weakControl focus:WXFocusStateProgrammatic];
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

            // TODO: What cancel button?
            // Update the collapsed/visible state of the cancel button and adjust text size.
            [weakControl updateLayout];
            [strongSelf _adjustFontSizeToFitWidthOrApplyCurrentFont];
        }
    }];
}

// Handler when KeyDown
- (void)_setupControlKeyDownHandler:(WXCControl*)control {
    __weak UITextField* weakSelf = self;

    // hooking up keydown event to process ENTER key
    [control addKeyDownEvent:^void(RTObject* sender, WUXIKeyRoutedEventArgs* e) {
        __strong UITextField* strongSelf = weakSelf;
        if (strongSelf && e.key == WSVirtualKeyEnter) {
            BOOL dismissKeyboard = TRUE;

            // check with delegate if should resign firstResponder and dismiss the keyboard
            if ([strongSelf.delegate respondsToSelector:@selector(textFieldShouldReturn:)]) {
                dismissKeyboard = [strongSelf.delegate textFieldShouldReturn:strongSelf];
            }

            if (dismissKeyboard) {
                [strongSelf resignFirstResponder];
            }

            e.handled = YES;
        } else {
            e.handled = NO;
        }
    }];
}

// Helper to initialize textbox
- (void)_switchToTextBox {
    _textBox = XamlControls::GetTextFieldTextBox(_textField);
    if (!_textBox) {
        FAIL_FAST();
    }

    // if passwordbox exists, need to transfer the properties that we set on passwordbox to textbox
    if (_passwordBox != nil) {
        if (_backgroundImage == nil || self.borderStyle == UITextBorderStyleRoundedRect) {
            WUColor* convertedColor = XamlUtilities::ConvertUIColorToWUColor(self.backgroundColor);
            WUXMSolidColorBrush* brush = [WUXMSolidColorBrush makeInstanceWithColor:convertedColor];
            _textBox.background = brush;
        }

        WUColor* convertedTextColor = XamlUtilities::ConvertUIColorToWUColor(self.textColor);
        WUXMSolidColorBrush* textBrush = [WUXMSolidColorBrush makeInstanceWithColor:convertedTextColor];
        _textBox.foreground = textBrush;

        _textBox.textAlignment = XamlUtilities::ConvertUITextAlignmentToWXTextAlignment(self.textAlignment);
        _textBox.inputScope = XamlUtilities::ConvertKeyboardTypeToInputScope(_keyboardType, NO);
        _textBox.text = self.text;
        _textBox.placeholderText = self.placeholder;
        _textBox.isSpellCheckEnabled = (self.spellCheckingType == UITextSpellCheckingTypeYes);
    }

    // setting up addtional textbox properties in loaded listener that requires looking into control template
    __weak UITextField* weakSelf = self;
    [_textBox addLoadedEvent:^void(RTObject* sender, WXRoutedEventArgs* e) {
        __strong UITextField* strongSelf = weakSelf;
        if (strongSelf) {
            dispatch_async(dispatch_get_main_queue(), ^{
                XamlUtilities::SetControlBorderStyle(strongSelf->_textBox, strongSelf.borderStyle);

                WXVerticalAlignment verticalAlignment =
                    XamlUtilities::ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(strongSelf.contentVerticalAlignment);
                [strongSelf setTextControlContentVerticalAlignment:strongSelf->_textBox verticalAlignment:verticalAlignment];

                // retrieve the ContentElement from the template
                WXFrameworkElement* frameworkElement = XamlUtilities::FindTemplateChild(strongSelf->_textBox, @"ContentElement");
                strongSelf->_textContentElement = (frameworkElement != nullptr) ? rt_dynamic_cast<WXCControl>(frameworkElement) : nullptr;

                if (strongSelf->_textContentElement == nullptr) {
                    TraceWarning(TAG, L"Could not find ContentElement in control template: adjustsFontSizeToFitWidth will not function");
                }

                [strongSelf _adjustFontSizeToFitWidthOrApplyCurrentFont];
            });
        }
    }];

    // set up text change event handler
    [_textBox addTextChangedEvent:^void(RTObject* sender, WXRoutedEventArgs* e) {
        __strong UITextField* strongSelf = weakSelf;
        if (strongSelf) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [strongSelf sendActionsForControlEvents:UIControlEventEditingChanged];
                [[NSNotificationCenter defaultCenter] postNotificationName:UITextFieldTextDidChangeNotification object:strongSelf];
            });
        }
    }];

    // set up focus and keydown handlers
    [self _setupControlGotFocusHandler:_textBox];
    [self _setupControlLostFocusHandler:_textBox];
    [self _setupControlKeyDownHandler:_textBox];
}

// Helper to Initialize passwordBox
- (void)_switchToPasswordBox {
    _passwordBox = XamlControls::GetTextFieldPasswordBox(_textField);
    if (!_passwordBox) {
        FAIL_FAST();
    }

    // set up focus and keydown handlers
    [self _setupControlGotFocusHandler:_passwordBox];
    [self _setupControlLostFocusHandler:_passwordBox];
    [self _setupControlKeyDownHandler:_passwordBox];

    // if textbox exists, need to transfer the properties from textbox to passwordbox
    if (_textBox != nil) {
        if (_backgroundImage == nil || self.borderStyle == UITextBorderStyleRoundedRect) {
            WUColor* convertedColor = XamlUtilities::ConvertUIColorToWUColor(self.backgroundColor);
            WUXMSolidColorBrush* brush = [WUXMSolidColorBrush makeInstanceWithColor:convertedColor];
            _passwordBox.background = brush;
        }

        WUColor* convertedTextColor = XamlUtilities::ConvertUIColorToWUColor(self.textColor);
        WUXMSolidColorBrush* textBrush = [WUXMSolidColorBrush makeInstanceWithColor:convertedTextColor];
        _passwordBox.foreground = textBrush;
        // passwordBox does not support textAlignment

        dispatch_async(dispatch_get_main_queue(), ^{
            // border manipulate the control tempate and must be done after loaded
            XamlUtilities::SetControlBorderStyle(_passwordBox, self.borderStyle);

            WXVerticalAlignment verticalAlignment =
                XamlUtilities::ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(self.contentVerticalAlignment);
            [self setTextControlContentVerticalAlignment:_passwordBox verticalAlignment:verticalAlignment];
        });

        _passwordBox.inputScope = XamlUtilities::ConvertKeyboardTypeToInputScope(_keyboardType, YES);
        _passwordBox.password = self.text;
        _passwordBox.placeholderText = self.placeholder;
    }

    // set up password change handler
    __weak UITextField* weakSelf = self;

    [_passwordBox addLoadedEvent:^void(RTObject* sender, WXRoutedEventArgs* e) {
        __strong UITextField* strongSelf = weakSelf;
        if (strongSelf) {
            dispatch_async(dispatch_get_main_queue(), ^{
                XamlUtilities::SetControlBorderStyle(strongSelf->_passwordBox, strongSelf.borderStyle);

                WXVerticalAlignment verticalAlignment =
                    XamlUtilities::ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(strongSelf.contentVerticalAlignment);
                [strongSelf setTextControlContentVerticalAlignment:strongSelf->_passwordBox verticalAlignment:verticalAlignment];

                // retrieve the ContentElement from the template
                WXFrameworkElement* frameworkElement = XamlUtilities::FindTemplateChild(strongSelf->_passwordBox, @"ContentElement");
                strongSelf->_textContentElement = (frameworkElement != nullptr) ? rt_dynamic_cast<WXCControl>(frameworkElement) : nullptr;

                if (strongSelf->_textContentElement == nullptr) {
                    TraceWarning(TAG, L"Could not find ContentElement in control template: adjustsFontSizeToFitWidth will not function");
                }

                [strongSelf _adjustFontSizeToFitWidthOrApplyCurrentFont];
            });
        }
    }];

    [_passwordBox addPasswordChangedEvent:^void(RTObject* sender, WXRoutedEventArgs* e) {
        __strong UITextField* strongSelf = weakSelf;
        if (strongSelf) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [strongSelf sendActionsForControlEvents:UIControlEventEditingChanged];
            });
        }
    }];
}

// Main entrance to initialize TextField
- (void)_initUITextField:(BOOL)secureTextMode {
    _secureModeLock = [NSRecursiveLock new];

    _textField = rt_dynamic_cast<WXFrameworkElement>([self xamlElement]);
    if (!_textField) {
        // Definitely didn't receive any supported backing XAML elements
        FAIL_FAST();
    }

    // Initially both controls can be lazy loaded, we instantiate the appropriate control
    // at runtime based on the secureTextEntry value
    XamlControls::SetTextFieldSecureTextEntryValue(_textField, secureTextMode);

    _secureTextMode = secureTextMode;
    if (_secureTextMode) {
        [self _switchToPasswordBox];
    } else {
        [self _switchToTextBox];
    }
}

@end
