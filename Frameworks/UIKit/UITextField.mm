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
#import "UIViewInternal.h"

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
#import <winrt/Windows.UI.Xaml.Input.h>
#include "COMIncludes_End.h"

using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Text;
namespace WF = winrt::Windows::Foundation;

static const wchar_t* TAG = L"UITextField";

NSString* const UITextFieldTextDidBeginEditingNotification = @"UITextFieldTextDidBeginEditingNotification";
NSString* const UITextFieldTextDidChangeNotification = @"UITextFieldTextDidChangeNotification";
NSString* const UITextFieldTextDidEndEditingNotification = @"UITextFieldTextDidEndEditingNotification";

@implementation UITextField {
    StrongId<UIFont> _font;
    StrongId<UIImage> _backgroundImage;

    BOOL _isFirstResponder;
    CGFloat _minimumFontSize;

    // backing keyboard Behavior
    UIKeyboardType _keyboardType;
    BOOL _adjustsFontSizeToFitWidth;

    // Backing xaml control
    TrivialDefaultConstructor<FrameworkElement> _textField;
}

//
// Properties Accessing the Text Attributes
//
/**
 @Status Interoperable
*/
- (void)setText:(NSString*)text {
    XamlControls::SetTextFieldText(_textField, text);
    [self _adjustFontSizeToFitWidthOrApplyCurrentFont];
}

/**
 @Status Interoperable
*/
- (NSString*)text {
    return XamlControls::GetTextFieldText(_textField);
}

/**
 @Status NotInPlan
*/
- (void)setAttributedText:(NSString*)attributedText {
    UNIMPLEMENTED_WITH_MSG("attributedText is not a feature currently supported by Xaml.");
}

/**
 @Status NotInPlan
*/
- (NSAttributedString*)attributedText {
    UNIMPLEMENTED_WITH_MSG("attributedText is not a feature currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)setPlaceholder:(NSString*)placeholder {
    XamlControls::SetTextFieldPlaceholder(_textField, placeholder);
}

/**
 @Status Interoperable
*/
- (NSString*)placeholder {
    return XamlControls::GetTextFieldPlaceholder(_textField);
}

/**
 @Status NotInPlan
*/
- (void)setAttributedPlaceholder:(NSString*)atributedStr {
    UNIMPLEMENTED_WITH_MSG("attributedPlaceholder is not a feature currently supported by Xaml.");
}

/**
 @Status NotInPlan
*/
- (NSAttributedString*)attributedPlaceholder {
    UNIMPLEMENTED_WITH_MSG("attributedPlaceholder is not a feature currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)setDefaultTextAttributes:(NSDictionary*)defaultAttributes {
    UNIMPLEMENTED_WITH_MSG("defaultTextAttributes is not a feature currently supported by Xaml.");
}

/**
 @Status NotInPlan
*/
- (NSDictionary*)defaultTextAttributes {
    UNIMPLEMENTED_WITH_MSG("defaultTextAttributes is not a feature currently supported by Xaml.");
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
    XamlControls::SetTextFieldTextColor(_textField, color);
}

/**
 @Status Interoperable
*/
- (UIColor*)textColor {
    return XamlControls::GetTextFieldTextColor(_textField);
}

/**
 @Status Interoperable
*/
- (void)setBackgroundColor:(UIColor*)color {
    // In class WXCTextBox and WXCPasswordBox, there is just one ivar 'background' for both background color and background image.
    // When setting background color, clear out _backgroundImage assigning it to nil.
    _backgroundImage = nil;
    XamlControls::SetTextFieldBackgroundColor(_textField, color);
}

/**
 @Status Interoperable
*/
- (UIColor*)backgroundColor {
    return XamlControls::GetTextFieldBackgroundColor(_textField);
}

/**
 @Status Interoperable
*/
- (void)setTextAlignment:(UITextAlignment)alignment {
    XamlControls::SetTextFieldTextAlignment(_textField, alignment);
}

/**
 @Status Interoperable
*/
- (UITextAlignment)textAlignment {
    return XamlControls::GetTextFieldTextAlignment(_textField);
}

/**
 @Status NotInPlan
*/
- (void)setTypingAttributes:(NSDictionary*)typingAttributes {
    UNIMPLEMENTED_WITH_MSG("typingAttributes mode does not support UITextAlignment");
}

/**
 @Status NotInPlan
*/
- (NSDictionary*)typingAttributes {
    UNIMPLEMENTED_WITH_MSG("typingAttributes mode does not support UITextAlignment");
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
    StrongId<UIFont> targetFont = _font;

    if (self.adjustsFontSizeToFitWidth) {
        CGRect adjustedBounds;
        adjustedBounds = [self bounds];

        // This is padding between inner text control and outter control
        // need to use adjustedBound (inner bound for text control) to fit the text.
        const CGFloat padding = 16.0;
        if (adjustedBounds.size.width > padding) {
            adjustedBounds = CGRectMake(adjustedBounds.origin.x,
                                        adjustedBounds.origin.y,
                                        adjustedBounds.size.width - padding,
                                        adjustedBounds.size.height);
        }

        float adjustedFontSize = XamlUtilities::FindMaxFontSizeToFit(adjustedBounds,
                                                                     XamlControls::GetTextFieldText(_textField),
                                                                     _font,
                                                                     1,
                                                                     _minimumFontSize,
                                                                     std::max(_minimumFontSize, [_font pointSize]));
        if (adjustedFontSize != [_font pointSize]) {
            targetFont = [_font fontWithSize:adjustedFontSize];
        }
    }

    XamlControls::TextFieldApplyFont(_textField,
                                     [targetFont _compatibleFamilyName],
                                     [targetFont _fontStretch],
                                     [targetFont _fontStyle],
                                     targetFont.pointSize,
                                     [targetFont _fontWeight]);
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
    return XamlControls::GetTextFieldEditingState(_textField);
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
 @Status NotInPlan
*/
- (void)setAllowsEditingTextAttributes:(BOOL)value {
    UNIMPLEMENTED_WITH_MSG("EditingTextAttributes does not support in xaml");
}

/**
 @Status NotInPlan
*/
- (BOOL)allowsEditingTextAttributes {
    UNIMPLEMENTED_WITH_MSG("EditingTextAttributes does not support in xaml");
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
    UITextBorderStyle currentBorderStyle = XamlControls::GetTextFieldBorderStyle(_textField);
    if (currentBorderStyle != style) {
        UITextBorderStyle oldStyle = currentBorderStyle;
        XamlControls::SetTextFieldBorderStyle(_textField, style);
        currentBorderStyle = style;

        // If currentBorderStyle is set to the UITextBorderStyleRoundedRect,
        // the custom background image associated with the text field is ignored.
        if (currentBorderStyle == UITextBorderStyleRoundedRect && _backgroundImage != nil) {
            XamlControls::SetTextFieldBackgroundColor(_textField, self.backgroundColor);
        }

        // If currentBorderStyle is not set to the UITextBorderStyleRoundedRect,
        // the custom background image associated with the text field is shown.
        if (oldStyle == UITextBorderStyleRoundedRect) {
            self.background = _backgroundImage;
        }
    }
}

/**
 @Status Interoperable
*/
- (UITextBorderStyle)borderStyle {
    return XamlControls::GetTextFieldBorderStyle(_textField);
}

/**
 @Status Caveat
 @Notes Does not support UIImage object that was initialized using a CIImage object
*/
- (void)setBackground:(UIImage*)image {
    _backgroundImage = image;

    // On reference platform, background image is only shown when borderStyle is not UITextBorderStyleRoundedRect
    if (self.borderStyle != UITextBorderStyleRoundedRect) {
        XamlControls::SetTextFieldBackgroundImage(_textField, _backgroundImage);
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
 @Status NotInPlan
*/
- (void)setClearButtonMode:(UITextFieldViewMode)mode {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (UITextFieldViewMode)clearButtonMode {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)setLeftView:(UIView*)view {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (UIView*)leftView {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)setLeftViewMode:(UITextFieldViewMode)mode {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (UITextFieldViewMode)leftViewMode {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)setRightView:(UIView*)view {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (UIView*)rightView {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)setRightViewMode:(UITextFieldViewMode)mode {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (UITextFieldViewMode)rightViewMode {
    UNIMPLEMENTED();
    return StubReturn();
}

//
// Drawing and positioning Overrides
//
/**
 @Status NotInPlan
*/
- (CGRect)textRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)drawTextInRect:(CGRect)rect {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (CGRect)placeholderRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)drawPlaceholderInRect:(CGRect)rect {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (CGRect)borderRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (CGRect)editingRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (CGRect)clearButtonRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (CGRect)leftViewRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (CGRect)rightViewRectForBounds:(CGRect)bounds {
    UNIMPLEMENTED();
    return StubReturn();
}

//
// Replacing the System Input Views
//
/**
 @Status NotInPlan
*/
- (void)setInputView:(UIView*)view {
    UNIMPLEMENTED_WITH_MSG("inputAccessoryView is not supported by xaml.");
}

/**
 @Status NotInPlan
*/
- (UIView*)inputView {
    UNIMPLEMENTED_WITH_MSG("inputAccessoryView is not supported by xaml.");
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)setInputAccessoryView:(UIView*)view {
    UNIMPLEMENTED_WITH_MSG("inputAccessoryView is not supported by xaml.");
}

/**
 @Status NotInPlan
*/
- (UIView*)inputAccessoryView {
    UNIMPLEMENTED_WITH_MSG("inputAccessoryView is not supported by xaml.");
    return StubReturn();
}

//
// UITextInputTraits protocol defined properties,  Managing the Keyboard Behavior
//
/**
 @Status NotInPlan
*/
- (void)setAutocapitalizationType:(UITextAutocapitalizationType)type {
    UNIMPLEMENTED_WITH_MSG(
        "autocapitalizationType isn't directly supported, autoCapitalizatoin is supported by setting keyboardType in xaml.");
}

/**
 @Status NotInPlan
*/
- (UITextAutocapitalizationType)autocapitalizationType {
    UNIMPLEMENTED_WITH_MSG(
        "autocapitalizationType isn't directly supported, autoCapitalizatoin is supported by setting keyboardType in xaml.");
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)setAutocorrectionType:(UITextAutocorrectionType)type {
    UNIMPLEMENTED_WITH_MSG("autocorrectionType is not a feature currently supported by Xaml.");
}

/**
 @Status NotInPlan
*/
- (UITextAutocorrectionType)autocorrectionType {
    UNIMPLEMENTED_WITH_MSG("autocorrectionType is not a feature currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)setSpellCheckingType:(UITextSpellCheckingType)type {
    UNIMPLEMENTED_WITH_MSG("spellCheckingType is not a feature currently supported by Xaml.");
}

/**
 @Status NotInPlan
*/
- (UITextSpellCheckingType)spellCheckingType {
    UNIMPLEMENTED_WITH_MSG("spellCheckingType is not a feature currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)setEnablesReturnKeyAutomatically:(BOOL)enabled {
    UNIMPLEMENTED_WITH_MSG("enablesReturnKeyAutomatically is not a feature currently supported by Xaml.");
}

/**
 @Status NotInPlan
*/
- (BOOL)enablesReturnKeyAutomatically {
    UNIMPLEMENTED_WITH_MSG("enablesReturnKeyAutomatically is not a feature currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)setKeyboardAppearance:(UIKeyboardAppearance)appearance {
    UNIMPLEMENTED_WITH_MSG("keyboardAppearance is not a feature currently supported by Xaml.");
}

/**
 @Status NotInPlan
*/
- (UIKeyboardAppearance)keyboardAppearance {
    UNIMPLEMENTED_WITH_MSG("keyboardAppearance is not a feature currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)setKeyboardType:(UIKeyboardType)type {
    _keyboardType = type;
    XamlControls::SetTextFieldInputScope(_textField, _keyboardType);
}

/**
 @Status Interoperable
*/
- (UIKeyboardType)keyboardType {
    return _keyboardType;
}

/**
 @Status NotInPlan
*/
- (void)setReturnKeyType:(UIReturnKeyType)type {
    UNIMPLEMENTED_WITH_MSG("returnKeyType is not a feature currently supported by Xaml.");
}

/**
 @Status NotInPlan
*/
- (UIReturnKeyType)returnKeyType {
    UNIMPLEMENTED_WITH_MSG("returnKeyType is not a feature currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)setSecureTextEntry:(BOOL)secure {
    XamlControls::SetTextFieldSecureTextEntryValue(_textField, secure);
}

/**
 @Status Interoperable
*/
- (BOOL)isSecureTextEntry {
    return XamlControls::GetTextFieldSecureTextEntryValue(_textField);
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

        self.textAlignment = UITextAlignmentLeft;
        self.borderStyle = UITextBorderStyleNone;
        self.textColor = [UIColor blackColor];
        self.backgroundColor = [UIColor lightGrayColor];

        _font = [UIFont fontWithName:@"Segoe UI" size:[UIFont labelFontSize]];
        _backgroundImage = nil;
        _isFirstResponder = NO;
    }

    return self;
}

- (id)initWithFrame:(CGRect)frame xamlElement:(RTObject*)xamlElement {
    if (self = [super initWithFrame:frame xamlElement:xamlElement]) {
        // move to top so that setting properties below can happen on xamlElement
        [self _initUITextField:NO];

        self.textAlignment = UITextAlignmentLeft;
        self.borderStyle = UITextBorderStyleNone;
        self.textColor = [UIColor blackColor];
        self.backgroundColor = [UIColor lightGrayColor];

        _font = [UIFont fontWithName:@"Segoe UI" size:[UIFont labelFontSize]];
        _backgroundImage = nil;
        _isFirstResponder = NO;
    }

    return self;
}

/**
Microsoft Extension
*/
+ (RTObject*)createXamlElement {
    // No autorelease needed because CreateTextField is autoreleased
    return objcwinrt::to_rtobj(XamlControls::CreateTextField());
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
    XamlControls::SetTextFieldEnabled(_textField, enabled);
}

/**
 @Status Interoperable
*/
- (BOOL)isEnabled {
    return XamlControls::GetTextFieldEnabled(_textField);
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
    _isFirstResponder = XamlControls::TextFieldBecomeFirstResponder(_textField);
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
    XamlControls::TextFieldKillFocus(_textField);
    return YES;
}

/**
 @Status NotInPlan
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

- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    [self becomeFirstResponder];
}

/**
 @Status Interoperable
*/
- (void)setContentVerticalAlignment:(UIControlContentVerticalAlignment)alignment {
    [super setContentVerticalAlignment:alignment];

    XamlControls::SetTextFieldVerticalTextAlignment(_textField, alignment);
}

//
// UIKeyInput Protocol related methods
//
/**
 @Status NotInPlan
*/
- (void)deleteBackward {
    UNIMPLEMENTED_WITH_MSG("UIKeyInput protocol deleteBackward is not a feature currently supported by Xaml.");
}

/**
 @Status NotInPlan
*/
- (void)insertText:(NSString*)text {
    UNIMPLEMENTED_WITH_MSG("UIKeyInput protocol insertText is not a feature currently supported by Xaml.");
}

/**
 @Status NotInPlan
*/
- (BOOL)hasText {
    UNIMPLEMENTED_WITH_MSG("UIKeyInput protocol hasText is not a feature currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (UITextRange*)textRangeFromPosition:(UITextPosition*)fromPosition toPosition:(UITextPosition*)toPosition {
    UNIMPLEMENTED_WITH_MSG("UIKeyInput protocol textRangeFromPosition is not a feature currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (UITextPosition*)positionFromPosition:(UITextPosition*)position offset:(NSInteger)offset {
    UNIMPLEMENTED_WITH_MSG("UIKeyInput protocol positionFromPosition is not a feature currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (CGRect)firstRectForRange:(UITextRange*)range {
    UNIMPLEMENTED_WITH_MSG("UIKeyInput protocol firstRectForRange is not a feature currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (CGRect)caretRectForPosition:(UITextPosition*)position {
    UNIMPLEMENTED_WITH_MSG("UIKeyInput protocol caretRectForPosition is not a feature currently supported by Xaml.");
    return StubReturn();
}

// Handler when control GotFocus
- (void)_processGotFocusEvent {
    // when GotFocus, check delegate (if exists) to see if it allows start editing
    if ([self.delegate respondsToSelector:@selector(textFieldShouldBeginEditing:)] && ![self.delegate textFieldShouldBeginEditing:self]) {
        // delegate says NO, but we already got the focus at this point, need to kill the focus on this control
        XamlControls::TextFieldKillFocus(self->_textField);
        return;
    }

    // no one says NO, update first responder to YES
    self->_isFirstResponder = YES;

    // more delegate update
    if ([self.delegate respondsToSelector:@selector(textFieldDidBeginEditing:)]) {
        [self.delegate textFieldDidBeginEditing:self];
    }

    // more notification
    dispatch_async(dispatch_get_main_queue(), ^{
        [self sendActionsForControlEvents:UIControlEventEditingDidBegin];
        [[NSNotificationCenter defaultCenter] postNotificationName:UITextFieldTextDidBeginEditingNotification object:self];
    });
}

// Handler when control LostFocus
- (void)_processLostFocusEvent {
    // when LostFocus, check delegate (if exists) to see if it allows end Editing
    if ([self.delegate respondsToSelector:@selector(textFieldShouldEndEditing:)] && ![self.delegate textFieldShouldEndEditing:self]) {
        // delegate does not allow editing to be ended, but we already lost the focus
        // we need re-setting the focus back. it will trigger GotFocusEvent again on this control
        // and then it will update the firstResponder status as YES
        if (!XamlControls::TextFieldBecomeFirstResponder(_textField)) {
            TraceWarning(TAG, L"Failed to setFocus on TextField");
        }
        return;
    }

    // no delegate say no, update firstResponder status to be NO
    self->_isFirstResponder = NO;

    // more delegate update
    if ([self.delegate respondsToSelector:@selector(textFieldDidEndEditing:)]) {
        [self.delegate textFieldDidEndEditing:self];
    }

    // more notification
    dispatch_async(dispatch_get_main_queue(), ^{
        [self sendActionsForControlEvents:UIControlEventEditingDidEnd];
        [[NSNotificationCenter defaultCenter] postNotificationName:UITextFieldTextDidEndEditingNotification object:self];
    });
}

// Main entrance to initialize TextField
- (void)_initUITextField:(BOOL)secureTextEntry {
    _textField = [self _winrtXamlElement].as<FrameworkElement>();

    if (!_textField) {
        // Definitely didn't receive any supported backing XAML elements
        FAIL_FAST();
    }

    // Initially both controls can be lazy loaded, we instantiate the appropriate control
    // at runtime based on the secureTextEntry value
    XamlControls::SetTextFieldSecureTextEntryValue(_textField, secureTextEntry);
    __weak UITextField* weakSelf = self;

    XamlControls::TextFieldRegisterEventHandlers(_textField,
                                                 // Text Changed event
                                                 [weakSelf](const WF::IInspectable& sender, const RoutedEventArgs&) {
                                                     __strong UITextField* strongSelf = weakSelf;
                                                     if (strongSelf) {
                                                         dispatch_async(dispatch_get_main_queue(), ^{
                                                             [strongSelf sendActionsForControlEvents:UIControlEventEditingChanged];
                                                             [[NSNotificationCenter defaultCenter]
                                                                 postNotificationName:UITextFieldTextDidChangeNotification
                                                                               object:strongSelf];
                                                             [strongSelf _adjustFontSizeToFitWidthOrApplyCurrentFont];
                                                         });
                                                     }
                                                 },

                                                 // Got focus event
                                                 [weakSelf](const WF::IInspectable& sender, const RoutedEventArgs&) {
                                                     __strong UITextField* strongSelf = weakSelf;
                                                     if (strongSelf) {
                                                         dispatch_async(dispatch_get_main_queue(), ^{
                                                             [strongSelf _processGotFocusEvent];
                                                         });
                                                     }
                                                 },

                                                 // Lost focus event
                                                 [weakSelf](const WF::IInspectable& sender, const RoutedEventArgs&) {
                                                     __strong UITextField* strongSelf = weakSelf;
                                                     if (strongSelf) {
                                                         dispatch_async(dispatch_get_main_queue(), ^{
                                                             [strongSelf _processLostFocusEvent];
                                                         });
                                                     }
                                                 },

                                                 // Enter Key down event handler
                                                 [weakSelf](const WF::IInspectable& sender, const RoutedEventArgs&) {
                                                     __strong UITextField* strongSelf = weakSelf;
                                                     if (strongSelf) {
                                                         dispatch_async(dispatch_get_main_queue(), ^{
                                                             BOOL dismissKeyboard = TRUE;

                                                             // check with delegate if should resign firstResponder and dismiss the keyboard
                                                             if ([strongSelf.delegate
                                                                     respondsToSelector:@selector(textFieldShouldReturn:)]) {
                                                                 dismissKeyboard = [strongSelf.delegate textFieldShouldReturn:strongSelf];
                                                             }

                                                             if (dismissKeyboard) {
                                                                 [strongSelf resignFirstResponder];
                                                             }
                                                         });
                                                     }
                                                 });
}

/**
@Status Interoperable
*/
- (void)dealloc {
    XamlControls::TextFieldUnregisterEventHandlers(_textField);
}

@end
