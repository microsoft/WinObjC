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

#import "XamlControls.h"
#import "XamlUtilities.h"

#import "CGContextInternal.h"
#import <CoreGraphics/CGContext.h>

#import "CACompositor.h"
#import "UIApplicationInternal.h"
#import "UIResponderInternal.h"
#import <Foundation/NSNotificationCenter.h>
#import <Foundation/NSTimer.h>

#import <UIKit/UIColor.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIFont.h>
#import <UIKit/UIImage.h>
#import <UIKit/UIImageView.h>
#import <UIKit/UITableViewCell.h>
#import <UIKit/UITextField.h>
#import <UIKit/UIView.h>
#import <UIKit/UIViewController.h>

#import <UWP/WindowsUIXamlControls.h>

static const wchar_t* TAG = L"UITextField";

NSString* const UITextFieldTextDidBeginEditingNotification = @"UITextFieldTextDidBeginEditingNotification";
NSString* const UITextFieldTextDidChangeNotification = @"UITextFieldTextDidChangeNotification";
NSString* const UITextFieldTextDidEndEditingNotification = @"UITextFieldTextDidEndEditingNotification";

// This is a hidden view control used to steal focus typically when a text field OSK (on screen keyboard) is dismissed.
@interface _UIHiddenButtonView : UIView
@end

@implementation _UIHiddenButtonView
@end

void SetTextControlContentVerticalAlignment(WXCControl* control, WXVerticalAlignment alignment) {
    [control applyTemplate];
    WXFrameworkElement* elem = FindTemplateChild(control, @"ContentElement");

    // set verticalAligment of both content and placeholder of TextBox (or PasswordBox) to be the same value
    if (elem != nullptr) {
        elem.verticalAlignment = alignment;
    }

    elem = FindTemplateChild(control, @"PlaceholderTextContentPresenter");
    if (elem != nullptr) {
        elem.verticalAlignment = alignment;
    }
}

@implementation UITextField {
    StrongId<NSString> _text;
    StrongId<NSString> _placeHolder;
    StrongId<UIFont> _font;
    StrongId<UIColor> _textColor;
    StrongId<UIColor> _backgroundColor;
    StrongId<UIImage> _backgroundImage;

    UITextAlignment _alignment;
    UITextBorderStyle _borderStyle;

    BOOL _secureTextMode;
    BOOL _isFirstResponder;

    // backing keyboard Behavior
    UITextAutocapitalizationType _autoCapitalizatonType;
    UIKeyboardType _keyboardType;
    UITextAutocorrectionType _autoCorrectionType;
    UITextSpellCheckingType _spellCheckingType;
    BOOL _enablesReturnKeyAutomatically;

    // backing xaml textbox and passwordBox
    StrongId<WXCTextBox> _textBox;
    StrongId<WXCPasswordBox> _passwordBox;

    // lock use to access the properties
    StrongId<NSRecursiveLock> _secureModeLock;

    // dummy control to steal the focus
    StrongId<WXCButton> _dummyButton;
    StrongId<_UIHiddenButtonView> _hiddenView;
}

//
// Properties Accessing the Text Attributes
//
/**
 @Status Interoperable
*/
- (void)setText:(NSString*)text {
    if (![_text isEqualToString:text]) {
        if (text != nil) {
            _text = [text copy];
        } else {
            _text = nil;
        }

        [_secureModeLock lock];
        if (_secureTextMode) {
            _passwordBox.password = _text;
        } else {
            _textBox.text = _text;
            // Ensure caret at end of field in case we programmatically
            // gain focus (becomeFirstResponder) after the text is set:
            _textBox.selectionStart = [_text length];
            _textBox.selectionLength = 0;
        }
        [_secureModeLock unlock];
    }
}

/**
 @Status Interoperable
*/
- (NSString*)text {
    return _text;
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
    if (![_placeHolder isEqualToString:placeholder]) {
        if (placeholder != nil) {
            _placeHolder = [placeholder copy];
        } else {
            _placeHolder = nil;
        }

        [_secureModeLock lock];
        if (_secureTextMode) {
            _passwordBox.placeholderText = _placeHolder;
        } else {
            _textBox.placeholderText = _placeHolder;
        }
        [_secureModeLock unlock];
    }
}

/**
 @Status Interoperable
*/
- (NSString*)placeholder {
    return _placeHolder;
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
 @Status Caveat
 @Notes Fonts can be set, but will be ignored for rendering, instead default font will be used.
*/
- (void)setFont:(UIFont*)font {
    _font = font;
    // TODO 7374333: need map UIFont with fontFamily/FontSize/FontWeight/FontStyle on target
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
    _textColor = color;

    WUColor* convertedColor = ConvertUIColorToWUColor(_textColor);
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
    return _textColor;
}

/**
 @Status Interoperable
*/
- (void)setBackgroundColor:(UIColor*)color {
    _backgroundColor = color;

    // In class WXCTextBox and WXCPasswordBox, there is just one ivar 'background' for both background color and background image.
    // When setting background color, clear out _backgroundImage assigning it to nil.
    _backgroundImage = nil;

    WUColor* convertedColor = ConvertUIColorToWUColor(_backgroundColor);
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
    return _backgroundColor;
}

/**
 @Status Interoperable
*/
- (void)setTextAlignment:(UITextAlignment)alignment {
    _alignment = alignment;

    [_secureModeLock lock];
    if (!_secureTextMode) {
        // passwordBox does not support text alignment
        _textBox.textAlignment = ConvertUITextAlignmentToWXTextAlignment(_alignment);
    }
    [_secureModeLock unlock];
}

/**
 @Status Interoperable
*/
- (UITextAlignment)textAlignment {
    return _alignment;
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
 @Status Stub
*/
- (void)setAdjustsFontSizeToFitWidth:(BOOL)adjust {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)adjustsFontSizeToFitWidth:(BOOL)adjust {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setMinimumFontSize:(CGFloat)fontSize {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (CGFloat)minimumFontSize {
    UNIMPLEMENTED();
    return StubReturn();
}

//
// Managing the Editing Behavior
//
/**
 @Status Stub
*/
- (BOOL)isEditing {
    UNIMPLEMENTED();
    return StubReturn();
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
            SetControlBorderStyle(_passwordBox, _borderStyle);
        } else {
            SetControlBorderStyle(_textBox, _borderStyle);
        }

        WUColor* convertedColor = ConvertUIColorToWUColor(_backgroundColor);
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
        Microsoft::WRL::ComPtr<IInspectable> inspectableNode(GetCACompositor()->GetBitmapForCGImage(cgImg));
        WUXMIBitmapSource* bitmapImageSource = CreateRtProxy([WUXMIBitmapSource class], inspectableNode.Get());
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
        _passwordBox.inputScope = ConvertKeyboardTypeToInputScope(_keyboardType, YES);
    } else {
        _textBox.inputScope = ConvertKeyboardTypeToInputScope(_keyboardType, NO);
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
        _secureTextMode = secure;
        if (_secureTextMode) {
            [self _initPasswordBox:nil];
            [self setXamlElement:_passwordBox];
        } else {
            [self _initTextBox:nil];
            [self setXamlElement:_textBox];
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
        _font = [coder decodeObjectForKey:@"UIFont"];
        _alignment = (UITextAlignment)[coder decodeInt32ForKey:@"UITextAlignment"];
        _borderStyle = (UITextBorderStyle)[coder decodeInt32ForKey:@"UIBorderStyle"];
        _keyboardType = (UIKeyboardType)[coder decodeInt32ForKey:@"UIKeyboardType"];
        _secureTextMode = [coder decodeInt32ForKey:@"UISecureTextEntry"];
        _text = [coder decodeObjectForKey:@"UIText"];
        _placeHolder = [coder decodeObjectForKey:@"UIPlaceholder"];
        _textColor = [coder decodeObjectForKey:@"UITextColor"];

        if (_textColor == nil) {
            _textColor = [UIColor blackColor];
        }

        _backgroundColor = [UIColor lightGrayColor];
        _backgroundImage = nil;
        _isFirstResponder = NO;

        [self _initTextField:nil];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    return [self _initWithFrame:frame xamlElement:nil];
}

- (id)_initWithFrame:(CGRect)frame xamlElement:(WXFrameworkElement*)xamlElement {
    if (self = [super initWithFrame:frame]) {
        _font = [UIFont fontWithName:@"Segoe UI" size:[UIFont labelFontSize]];
        _alignment = UITextAlignmentLeft;
        _borderStyle = UITextBorderStyleNone;
        _secureTextMode = NO;
        _text = nil;
        _textColor = [UIColor blackColor];
        _backgroundColor = [UIColor lightGrayColor];
        _backgroundImage = nil;
        _spellCheckingType = UITextSpellCheckingTypeDefault;
        _isFirstResponder = NO;

        [self _initTextField:xamlElement];
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
        self->_passwordBox.isEnabled = enabled;
    } else {
        self->_textBox.isEnabled = enabled;
    }
}

/**
 @Status Interoperable
*/
- (BOOL)isEnabled {
    if (self.secureTextEntry) {
        return self->_passwordBox.isEnabled;
    } else {
        return self->_textBox.isEnabled;
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
        _isFirstResponder = [self->_passwordBox focus:WXFocusStateProgrammatic];
    } else {
        _isFirstResponder = [self->_textBox focus:WXFocusStateProgrammatic];
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

    WXVerticalAlignment verticalAlignment = ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(self.contentVerticalAlignment);

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
    [_dummyButton focus:WXFocusStateProgrammatic];
}

// Handler when control GotFocus
- (void)_setupControlGotFocusHandler:(WXCControl*)control {
    __weak UITextField* weakSelf = self;

    [control addGotFocusEvent:^void(RTObject* sender, WXRoutedEventArgs* e) {
        __strong UITextField* strongSelf = weakSelf;
        if (strongSelf) {
            // when GotFocus, check delegate (if exits) to see if it allows start editing
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
            dispatch_async(dispatch_get_main_queue(),
                           ^{
                               [strongSelf sendActionsForControlEvents:UIControlEventEditingDidBegin];
                               [[NSNotificationCenter defaultCenter] postNotificationName:UITextFieldTextDidBeginEditingNotification
                                                                                   object:strongSelf];
                           });
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
                // delegate does not allow edting to be ended, but we already lost the focus
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
            dispatch_async(dispatch_get_main_queue(),
                           ^{
                               [strongSelf sendActionsForControlEvents:UIControlEventEditingDidEnd];
                               [[NSNotificationCenter defaultCenter] postNotificationName:UITextFieldTextDidEndEditingNotification
                                                                                   object:strongSelf];
                           });
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
- (void)_initTextBox:(WXFrameworkElement*)xamlElement {
    if (xamlElement != nil && [xamlElement isKindOfClass:[WXCTextBox class]]) {
        self->_textBox = static_cast<WXCTextBox*>(xamlElement);
    } else {
        self->_textBox = [WXCTextBox make];
    }

    self->_passwordBox = nil;
    __weak UITextField* weakSelf = self;

    // setting up textbox properties, e.g., foreground, textalignment, border, and input scope, text content etc...
    [self->_textBox addLoadedEvent:^void(RTObject* sender, WXRoutedEventArgs* e) {
        __strong UITextField* strongSelf = weakSelf;
        if (strongSelf) {
            if (strongSelf->_backgroundImage == nil || _borderStyle == UITextBorderStyleRoundedRect) {
                WUColor* convertedColor = ConvertUIColorToWUColor(strongSelf.backgroundColor);
                WUXMSolidColorBrush* brush = [WUXMSolidColorBrush makeInstanceWithColor:convertedColor];
                strongSelf->_textBox.background = brush;
            }

            WUColor* convertedTextColor = ConvertUIColorToWUColor(strongSelf.textColor);
            WUXMSolidColorBrush* textBrush = [WUXMSolidColorBrush makeInstanceWithColor:convertedTextColor];
            strongSelf->_textBox.foreground = textBrush;

            strongSelf->_textBox.textAlignment = ConvertUITextAlignmentToWXTextAlignment(strongSelf.textAlignment);

            SetControlBorderStyle(strongSelf->_textBox, strongSelf.borderStyle);

            WXVerticalAlignment verticalAlignment =
                ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(strongSelf.contentVerticalAlignment);
            SetTextControlContentVerticalAlignment(strongSelf->_textBox, verticalAlignment);
            strongSelf->_textBox.inputScope = ConvertKeyboardTypeToInputScope(strongSelf->_keyboardType, NO);
            strongSelf->_textBox.text = strongSelf.text;
            strongSelf->_textBox.placeholderText = strongSelf.placeholder;
            strongSelf->_textBox.isSpellCheckEnabled = (strongSelf.spellCheckingType == UITextSpellCheckingTypeYes);
        }
    }];

    // set up text change event handler
    [self->_textBox addTextChangedEvent:^void(RTObject* sender, WXRoutedEventArgs* e) {
        __strong UITextField* strongSelf = weakSelf;
        if (strongSelf) {
            strongSelf.text = strongSelf->_textBox.text;
            dispatch_async(dispatch_get_main_queue(),
                           ^{
                               [strongSelf sendActionsForControlEvents:UIControlEventEditingChanged];
                               [[NSNotificationCenter defaultCenter] postNotificationName:UITextFieldTextDidChangeNotification
                                                                                   object:strongSelf];
                           });
        }
    }];

    // set up focus and keydown handlers
    [self _setupControlGotFocusHandler:_textBox];
    [self _setupControlLostFocusHandler:_textBox];
    [self _setupControlKeyDownHandler:_textBox];
}

// Helper to Initialize passwordBox
- (void)_initPasswordBox:(WXFrameworkElement*)xamlElement {
    self->_passwordBox = [WXCPasswordBox make];

    self->_textBox = nil;
    __weak UITextField* weakSelf = self;

    // setting up loadedEvent to update properties
    [self->_passwordBox addLoadedEvent:^void(RTObject* sender, WXRoutedEventArgs* e) {
        __strong UITextField* strongSelf = weakSelf;
        if (strongSelf) {
            if (strongSelf->_backgroundImage == nil || _borderStyle == UITextBorderStyleRoundedRect) {
                WUColor* convertedColor = ConvertUIColorToWUColor(strongSelf.backgroundColor);
                WUXMSolidColorBrush* brush = [WUXMSolidColorBrush makeInstanceWithColor:convertedColor];
                strongSelf->_passwordBox.background = brush;
            }

            WUColor* convertedTextColor = ConvertUIColorToWUColor(strongSelf.textColor);
            WUXMSolidColorBrush* textBrush = [WUXMSolidColorBrush makeInstanceWithColor:convertedTextColor];
            strongSelf->_passwordBox.foreground = textBrush;
            // passwordBox does not support textAlignment

            // border manipulate the control tempate and must be done after loaded
            SetControlBorderStyle(strongSelf->_passwordBox, strongSelf.borderStyle);
            WXVerticalAlignment verticalAlignment =
                ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(strongSelf.contentVerticalAlignment);
            SetTextControlContentVerticalAlignment(strongSelf->_passwordBox, verticalAlignment);
            strongSelf->_passwordBox.inputScope = ConvertKeyboardTypeToInputScope(strongSelf->_keyboardType, YES);
            strongSelf->_passwordBox.password = strongSelf.text;
            strongSelf->_passwordBox.placeholderText = strongSelf.placeholder;
        }
    }];

    // set up password change handler
    [self->_passwordBox addPasswordChangedEvent:^void(RTObject* sender, WXRoutedEventArgs* e) {
        __strong UITextField* strongSelf = weakSelf;
        if (strongSelf) {
            strongSelf.text = strongSelf->_passwordBox.password;
            dispatch_async(dispatch_get_main_queue(),
                           ^{
                               [strongSelf sendActionsForControlEvents:UIControlEventEditingChanged];
                           });
        }
    }];

    // set up focus and keydown handlers
    [self _setupControlGotFocusHandler:_passwordBox];
    [self _setupControlLostFocusHandler:_passwordBox];
    [self _setupControlKeyDownHandler:_passwordBox];
}

// Main entrance to initialize TextField
- (void)_initTextField:(WXFrameworkElement*)xamlElement {
    self->_secureModeLock = [NSRecursiveLock new];

    // creating dummy button and hidden view so that it can be used to steal/kill the focus for this UITextField
    self->_dummyButton = [WXCButton make];
    self->_dummyButton.visibility = WXVisibilityVisible;
    self->_dummyButton.isEnabled = YES;
    self->_dummyButton.isTabStop = YES;

    self->_hiddenView = [[_UIHiddenButtonView alloc] initWithFrame:CGRectZero];
    [self->_hiddenView setXamlElement:self->_dummyButton];
    [self addSubview:self->_hiddenView];

    if (self->_secureTextMode) {
        [self _initPasswordBox:nil];
        [self setXamlElement:self->_passwordBox];
    } else {
        [self _initTextBox:xamlElement];
        [self setXamlElement:self->_textBox];
    }
}

@end
