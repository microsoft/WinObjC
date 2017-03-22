//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import "CustomTextControlViewController.h"

#import <UIKit/UIKit.h>

// WinRT Projections imports
#ifdef WINOBJC
#import <UWP/WindowsUICore.h>
#import <UWP/WindowsUITextCore.h>
#import <UWP/WindowsUIViewManagement.h>
#import <UWP/WindowsUIXamlControls.h>
#import <UWP/WindowsUIXamlShapes.h>
#endif // WINOBJC

@interface SpiralTextEdit : UIView

@end

#ifdef WINOBJC
// This class implements a custom edit control that is entirely
// standalone. It does not integrate with XAML focus. Instead,
// it manages focus explicitly by tracking pointer activity.

// This view's only subview is an autoresized UIView that hosts
// a Windows.UI.Xaml.ContentControl, which is used to gain focus,
// tabstop, and recieve pointer events.
@implementation SpiralTextEdit {
    // Internal text storage
    NSString* _textStorage;

    // UIView to host the Xaml Element
    UIView* _hostView;

    // Xaml Control used to gain focus and receive pointer/key events
    WXCContentControl* _xamlControl;
    WUXSRectangle* _xamlControlContent;

    // The _editContext lets us communicate with the input system.
    WUTCCoreTextEditContext* _editContext;

    // The input pane object indicates the visibility of the on screen keyboard.
    // Apps can also ask the keyboard to show or hide.
    WUVInputPane* _inputPane;

    // Flyout used for Copy and Paste contextual menu.
    WXCMenuFlyout* _flyout;

    // Menu items for our flyout
    WXCMenuFlyoutItem* _copy;
    WXCMenuFlyoutItem* _paste;

    // If the _selection starts and ends at the same point,
    // then it represents the location of the caret (insertion point).
    WUTCCoreTextRange* _selection;

    // _internalFocus keeps track of whether our control acts like it has focus.
    bool _internalFocus;

    // If there is a nonempty selection, then _extendingLeft is true if the user
    // is using shift+arrow to adjust the starting point of the selection,
    // or false if the user is adjusting the ending point of the selection.
    bool _extendingLeft;

    // Array of states to keep track of control keys. This array reset on focus lost.
    // Currently there are < 218 key states, but that may change platform to platform.
    bool _keyDown[256];

    // We need to ensure we unregister our event handlers in dealloc
    EventRegistrationToken _customEditControlTappedToken;
    EventRegistrationToken _customEditControlRightTappedToken;
    EventRegistrationToken _customEditControlGotFocusToken;
    EventRegistrationToken _customEditControlPointerPressedToken;
    EventRegistrationToken _customEditControlLostFocusToken;
    EventRegistrationToken _customEditControlKeyDownToken;
    EventRegistrationToken _customEditControlKeyUpToken;

    EventRegistrationToken _copyClickToken;
    EventRegistrationToken _pasteClickToken;

    EventRegistrationToken _editContextTextRequestedToken;
    EventRegistrationToken _editContextSelectionRequestedToken;
    EventRegistrationToken _editContextFocusRemovedToken;
    EventRegistrationToken _editContextTextUpdatingToken;
    EventRegistrationToken _editContextSelectionUpdatingToken;
    EventRegistrationToken _editContextFormatUpdatingToken;
    EventRegistrationToken _editContextLayoutRequestedToken;
    EventRegistrationToken _editContextCompositionStartedToken;
    EventRegistrationToken _editContextCompositionCompletedToken;
}

//// Initialization ////
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self _initializeControl];
    }

    return self;
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        [self _initializeControl];
    }

    return self;
}

- (void)_initializeControl {
    // Use a reference to weak self in our event handler blocks, to avoid retain-loops
    __weak id weakSelf = self;

    // Our CALayer implementation is not a Xaml::Control, and so cannot recieve focus.
    // To enable focus, the following lines create a Control, then initializes a subview
    // such that the Control serves as the UIView's backing 'CALayer'.
    // By hosting it in this manner, we can add it to the visual tree, and treat it like
    // any other Xaml FrameworkElement, including gaining focus, getting key events, and so on.
    _xamlControl = [WXCContentControl make];

    // This view only stands to be the host of our Xaml element; we won't draw to it.
    // Instead, we'll drawRect: to 'self'; the containing SpiralTextEdit UIView.
    _hostView = [[UIView alloc] initWithFrame:self.bounds xamlElement:_xamlControl];
    _hostView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;

    [self addSubview:_hostView];

    _xamlControl.horizontalContentAlignment = WXHorizontalAlignmentStretch;
    _xamlControl.verticalContentAlignment = WXVerticalAlignmentStretch;

    // Xaml ContentControls do not respond to pointer events unless their content
    // is set. Set it to a Rectangle.
    _xamlControlContent = [WUXSRectangle make];

    // The background of the control content must be non-null in order for it to
    // respond to pointer events.
    _xamlControlContent.fill = [WUXMSolidColorBrush makeInstanceWithColor:[WUColors transparent]];

    _xamlControl.content = _xamlControlContent;

    // A control must be Tab-Stoppable and Enabled in order to become focused
    _xamlControl.isTabStop = YES;

    _textStorage = @"";

    _selection = [WUTCCoreTextRange new];
    _selection.endCaretPosition = _selection.startCaretPosition = 0;

    [self _resetKeyStates];

    // Initizlize our flyout for contextual functions like copy and paste.
    _flyout = [WXCMenuFlyout make];

    // Additional flyout items such as formatting can be added here.
    _copy = [WXCMenuFlyoutItem make];
    _copy.text = @"Copy";
    _copyClickToken = [_copy addClickEvent:^(RTObject* sender, WXRoutedEventArgs* e) {
        [weakSelf _copyClick:sender args:e];
    }];

    _paste = [WXCMenuFlyoutItem make];
    _paste.text = @"Paste";
    _pasteClickToken = [_paste addClickEvent:^(RTObject* sender, WXRoutedEventArgs* e) {
        [weakSelf _pasteClick:sender args:e];
    }];

    [_flyout.items addObject:_copy];
    [_flyout.items addObject:_paste];

    // Create a CoreTextEditContext for our custom edit control.
    WUTCCoreTextServicesManager* manager = [WUTCCoreTextServicesManager getForCurrentView];
    _editContext = [manager createEditContext];

    // Get the Input Pane so we can programmatically hide and show it.
    _inputPane = [WUVInputPane getForCurrentView];

    // For demonstration purposes, this sample sets the Input Pane display policy to Manual
    // so that it can manually show the software keyboard when the control gains focus and
    // dismiss it when the control loses focus. If you leave the policy as Automatic, then
    // the system will hide and show the Input Pane for you. Note that on Desktop, you will
    // need to implement the UIA text pattern to get expected automatic behavior.
    _editContext.inputPaneDisplayPolicy = WUTCCoreTextInputPaneDisplayPolicyManual;

    // Set the input scope to Text because this text box is for any text.
    // This also informs software keyboards to show their regular
    // text entry layout.  There are many other input scopes and each will
    // inform a keyboard layout and text behavior.
    _editContext.inputScope = WUTCCoreTextInputScopeText;

    // Register all the events associated with this Control
    // Note that you should always unregister your events when control is deallocated

    // Using Tapped and RightTapped ensures proper behavior on non-desktop devices.
    _customEditControlTappedToken = [_xamlControl addTappedEvent:^(RTObject* sender, WUXITappedRoutedEventArgs* e) {
        [weakSelf _xamlControlTapped:sender args:e];
    }];

    _customEditControlRightTappedToken = [_xamlControl addRightTappedEvent:^(RTObject* sender, WUXIRightTappedRoutedEventArgs* e) {
        [weakSelf _xamlControlRightTapped:sender args:e];
    }];

    // This event comes from Xaml when either the control is tabbed to, or
    // directional focused.
    _customEditControlGotFocusToken = [_xamlControl addGotFocusEvent:^(RTObject* sender, WXRoutedEventArgs* e) {
        [weakSelf _xamlControlGotFocus:sender args:e];
    }];

    // LostFocus can originate from variety of events, from tab to system alerts.
    _customEditControlLostFocusToken = [_xamlControl addLostFocusEvent:^(RTObject* sender, WXRoutedEventArgs* e) {
        [weakSelf _xamlControlLostFocus:sender args:e];
    }];

    // Subscribe to pointer events on the content control.
    // Note: UIView subscribes to, and handles all pointer events for its backing xamlElement (in this case, '_xamlControl'),
    // in order to integrate with the UIResponder chain.
    // So if we want to also receive _xamlControl's pointer events, we have a few options:
    // 1. Subscribe to pointer events on _xamlControl's internal WUXSRectangle content (rather than directly on _xamlControl).
    // 2. Use addHandler with 'true' to subscribe to _xamlControl's 'pointer pressed' events that UIView already processes/handles.
    // 3.  Respond to touchesBegan:, etc. on either '_hostView' or 'self'.
    // This example uses option #1.
    _customEditControlPointerPressedToken = [_xamlControlContent addPointerPressedEvent:^(RTObject* sender, WUXIPointerRoutedEventArgs* e) {
        [weakSelf _xamlControlPointerPressed:sender args:e];
    }];

    // All keys, including control keys, accelerator keys generate a keydown/up event,
    // when the Control is Xaml-focused.
    _customEditControlKeyDownToken = [_xamlControl addKeyDownEvent:^(RTObject* sender, WUXIKeyRoutedEventArgs* e) {
        [weakSelf _xamlControlKeyDown:sender args:e];
    }];

    _customEditControlKeyUpToken = [_xamlControl addKeyUpEvent:^(RTObject* sender, WUXIKeyRoutedEventArgs* e) {
        [weakSelf _xamlControlKeyUp:sender args:e];
    }];

    // The system raises this event to request a specific range of text.
    _editContextTextRequestedToken =
        [_editContext addTextRequestedEvent:^(WUTCCoreTextEditContext* sender, WUTCCoreTextTextRequestedEventArgs* e) {
            [weakSelf _editContextTextRequested:sender args:e];
        }];

    // The system raises this event to request the current selection.
    _editContextSelectionRequestedToken =
        [_editContext addSelectionRequestedEvent:^(WUTCCoreTextEditContext* sender, WUTCCoreTextSelectionRequestedEventArgs* e) {
            [weakSelf _editContextSelectionRequested:sender args:e];
        }];

    // The system raises this event when it wants the edit control to remove focus.
    _editContextFocusRemovedToken = [_editContext addFocusRemovedEvent:^(WUTCCoreTextEditContext* sender, RTObject* e) {
        [weakSelf _editContextFocusRemoved:sender args:e];
    }];

    // The system raises this event to update text in the edit control.
    _editContextTextUpdatingToken =
        [_editContext addTextUpdatingEvent:^(WUTCCoreTextEditContext* sender, WUTCCoreTextTextUpdatingEventArgs* e) {
            [weakSelf _editContextTextUpdating:sender args:e];
        }];

    // The system raises this event to change the selection in the edit control.
    _editContextSelectionUpdatingToken =
        [_editContext addSelectionUpdatingEvent:^(WUTCCoreTextEditContext* sender, WUTCCoreTextSelectionUpdatingEventArgs* e) {
            [weakSelf _editContextSelectionUpdating:sender args:e];
        }];

    // The system raises this event when it wants the edit control
    // to apply formatting on a range of text.
    _editContextFormatUpdatingToken =
        [_editContext addFormatUpdatingEvent:^(WUTCCoreTextEditContext* sender, WUTCCoreTextFormatUpdatingEventArgs* e) {
            [weakSelf _editContextFormatUpdating:sender args:e];
        }];

    // The system raises this event to request layout information.
    // This is used to help choose a position for the IME candidate window,
    // and scroll the focused window into view.
    _editContextLayoutRequestedToken =
        [_editContext addLayoutRequestedEvent:^(WUTCCoreTextEditContext* sender, WUTCCoreTextLayoutRequestedEventArgs* e) {
            [weakSelf _editContextLayoutRequested:sender args:e];
        }];

    // The system raises this event to notify the edit control
    // that the string composition has started.
    _editContextCompositionStartedToken =
        [_editContext addCompositionStartedEvent:^(WUTCCoreTextEditContext* sender, WUTCCoreTextCompositionStartedEventArgs* e) {
            [weakSelf _editContextCompositionStarted:sender args:e];
        }];

    // The system raises this event to notify the edit control
    // that the string composition is finished.
    _editContextCompositionCompletedToken =
        [_editContext addCompositionCompletedEvent:^(WUTCCoreTextEditContext* sender, WUTCCoreTextCompositionCompletedEventArgs* e) {
            [weakSelf _editContextCompositionCompleted:sender args:e];
        }];

    [self setNeedsDisplay];
}

//// Text Drawing - Uses CoreGraphics, but can be achieved however you wish ////

- (void)drawRect:(CGRect)rect {
    CGContextRef ctx = UIGraphicsGetCurrentContext();

    CGContextSaveGState(ctx);

    CGColorRef borderColor;
    CGColorRef fillColor = [UIColor whiteColor].CGColor;
    float borderThickness;

    // Draw a focus indication of some sort.
    if (_internalFocus) {
        borderColor = [UIColor blueColor].CGColor;
        borderThickness = 2.0f;
    } else {
        borderColor = [UIColor grayColor].CGColor;
        borderThickness = 1.0f;
    }

    // Add border using fill, until we support layer borders
    CGContextSetFillColorWithColor(ctx, borderColor);
    CGContextFillRect(ctx, self.bounds);
    CGContextSetFillColorWithColor(ctx, fillColor);
    CGContextFillRect(ctx, CGRectInset(self.bounds, borderThickness, borderThickness));

    // The raw materials we have are a string (_text) and information about
    // where the caret/selection is (_selection). We can render the control
    // any way we like.
    float angle = 0;
    float scale = 1.0f;

    UIFont* font = [UIFont fontWithName:@"WinObjC" size:14];
    UIColor* color = [UIColor blackColor];
    UIColor* selectedColor = [UIColor blueColor];
    NSMutableDictionary* attrs =
        [NSMutableDictionary dictionaryWithObjectsAndKeys:font, UITextAttributeFont, color, UITextAttributeTextColor, nil];
    CGPoint center = CGPointMake(self.bounds.size.width / 2, self.bounds.size.height / 2);
    CGFloat radius = center.x - 10.0f;

    for (int i = 0; i <= _textStorage.length; i++) {
        // Loop through each char in the string and place it around the center point.
        CGFloat xCoord = center.x + (radius * scale * sin(angle));
        CGFloat yCoord = center.y - (radius * scale * cos(angle));

        // Handle selection highlighting
        if (i < _textStorage.length) {
            if (_selection.startCaretPosition != _selection.endCaretPosition) {
                if (i >= _selection.startCaretPosition && i < _selection.endCaretPosition) {
                    [attrs setObject:selectedColor forKey:UITextAttributeTextColor];
                } else {
                    [attrs setObject:color forKey:UITextAttributeTextColor];
                }
            } else {
                [attrs setObject:color forKey:UITextAttributeTextColor];
            }

            NSString* letter = [_textStorage substringWithRange:NSMakeRange(i, 1)];
            CGSize letterSize = [letter sizeWithAttributes:attrs];
            [letter drawAtPoint:CGPointMake(xCoord - (letterSize.width / 2.0f), yCoord - (letterSize.height / 2.0f)) withAttributes:attrs];
        }

        if (_selection.startCaretPosition == _selection.endCaretPosition) {
            if (_selection.startCaretPosition == i && _internalFocus) {
                CGContextSetFillColorWithColor(ctx, selectedColor.CGColor);
                CGContextFillRect(ctx, CGRectMake(xCoord - 1.5, yCoord - 8, 3, 16));
            }
        }

        angle += 10.0f / 360.0f * M_PI * 2;
        scale *= 0.995f;
    }

    CGContextRestoreGState(ctx);
}

//// Internal ////

// Clamps the text range in place to fit within the text storage.
- (void)_clampRange:(WUTCCoreTextRange*)range {
    range.endCaretPosition = MIN(range.endCaretPosition, (int)_textStorage.length);
    range.endCaretPosition = MAX(range.endCaretPosition, 0);
    range.startCaretPosition = MIN(range.startCaretPosition, (int)_textStorage.length);
    range.startCaretPosition = MAX(range.startCaretPosition, 0);
}

- (void)_resetKeyStates {
    // Reset key states to unpressed.
    memset(_keyDown, 0, sizeof(bool) * 256);
}

- (void)_copyFromClipboard {
    [self _updateTextWithRange:_selection text:[[UIPasteboard generalPasteboard] string]];
}

- (void)_copyToClipboard {
    [[UIPasteboard generalPasteboard] setString:[self _stringForRange:_selection]];
}

- (void)_updateTextWithRange:(WUTCCoreTextRange*)range text:(NSString*)text {
    if (_textStorage.length) {
        [self _clampRange:range];
        _textStorage = [_textStorage
            stringByReplacingCharactersInRange:NSMakeRange(range.startCaretPosition, range.endCaretPosition - range.startCaretPosition)
                                    withString:text];
    } else {
        _textStorage = text;
    }

    _selection.startCaretPosition = range.startCaretPosition + text.length;
    _selection.endCaretPosition = _selection.startCaretPosition;
    [self _setSelectionAndNotify:_selection];

    [self setNeedsDisplay];
}

- (NSString*)_stringForRange:(WUTCCoreTextRange*)range {
    if (_textStorage.length) {
        [self _clampRange:range];
        return [_textStorage substringWithRange:NSMakeRange(range.startCaretPosition, range.endCaretPosition - range.startCaretPosition)];
    }
    return @"";
}

- (void)_removeInternalFocus {
    if (_internalFocus) {
        // Notify the system that this edit context is no longer in focus
        [_editContext notifyFocusLeave];

        // Update the internal notion of focus
        _internalFocus = false;

        // Ask the software keyboard to dismiss.
        [_inputPane tryHide];

        // Update our UI.
        [self setNeedsDisplay];
    }
}

- (void)_setInternalFocus {
    if (!_internalFocus) {
        // Update internal notion of focus.
        _internalFocus = true;

        // Update the UI.
        [self setNeedsDisplay];

        // Notify the CoreTextEditContext that the edit context has focus,
        // so it should start processing text input.
        [_editContext notifyFocusEnter];
    }

    // Ask the software keyboard to show.  The system will ultimately decide if it will show.
    // For example, it will not show if there is a keyboard attached.
    [_inputPane tryShow];
}

// Change the selection without notifying CoreTextEditContext of the new selection.
- (void)_setSelection:(WUTCCoreTextRange*)selection {
    // Modify the internal selection.
    _selection = selection;

    // Range-check selection
    [self _clampRange:_selection];

    // Update the UI to show the new selection.
    [self setNeedsDisplay];
}

// Change the selection and notify CoreTextEditContext of the new selection.
- (void)_setSelectionAndNotify:(WUTCCoreTextRange*)selection {
    [self _setSelection:selection];
    [_editContext notifySelectionChanged:_selection];
}

//// Event Handlers ////
- (void)_pasteClick:(RTObject*)sender args:(WXRoutedEventArgs*)e {
    [self _copyFromClipboard];
    [_flyout hide];
}

- (void)_copyClick:(RTObject*)sender args:(WXRoutedEventArgs*)e {
    [self _copyToClipboard];
    [_flyout hide];
}

- (void)_xamlControlTapped:(RTObject*)sender args:(WUXITappedRoutedEventArgs*)e {
    if (_xamlControl.focusState == WXFocusStateUnfocused) {
        [_xamlControl focus:WXFocusStatePointer];
    }
}

- (void)_xamlControlRightTapped:(RTObject*)sender args:(WUXIRightTappedRoutedEventArgs*)e {
    [_flyout showAt:_xamlControl point:[e getPosition:_xamlControl]];
}

- (void)_xamlControlKeyUp:(RTObject*)sender args:(WUXIKeyRoutedEventArgs*)e {
    _keyDown[(int)e.key] = false;
}

- (void)_xamlControlKeyDown:(RTObject*)sender args:(WUXIKeyRoutedEventArgs*)e {
    _keyDown[(int)e.key] = true;

    switch (e.key) {
        // Back is equivalent to Backspace
        case WSVirtualKeyBack:
            if (_selection.endCaretPosition == _selection.startCaretPosition) {
                WUTCCoreTextRange* backspace = [WUTCCoreTextRange new];
                backspace.startCaretPosition = _selection.startCaretPosition - 1;
                backspace.endCaretPosition = _selection.endCaretPosition;
                [self _updateTextWithRange:backspace text:@""];
            } else {
                [self _updateTextWithRange:_selection text:@""];
            }
            break;
        // Effectively the same as delete when _selection is a range.
        case WSVirtualKeyDelete:
            if (_selection.endCaretPosition == _selection.startCaretPosition) {
                WUTCCoreTextRange* backspace = [WUTCCoreTextRange new];
                backspace.startCaretPosition = _selection.startCaretPosition;
                backspace.endCaretPosition = _selection.endCaretPosition + 1;
                [self _updateTextWithRange:backspace text:@""];
            } else {
                [self _updateTextWithRange:_selection text:@""];
            }
            break;

        // We have to pay attention to the direction; the text range invariant is Start <= End
        case WSVirtualKeyLeft: {
            WUTCCoreTextRange* backSel = [WUTCCoreTextRange new];

            if (_selection.endCaretPosition == _selection.startCaretPosition) {
                _extendingLeft = true;
            }

            if (!_extendingLeft) {
                backSel.startCaretPosition = _selection.startCaretPosition;
                backSel.endCaretPosition = _selection.endCaretPosition - 1;
            } else {
                backSel.startCaretPosition = _selection.startCaretPosition - 1;
                backSel.endCaretPosition = _selection.endCaretPosition;
            }

            if (!_keyDown[WSVirtualKeyShift]) {
                backSel.endCaretPosition = backSel.startCaretPosition;
            }

            [self _setSelectionAndNotify:backSel];

            break;
        }
        case WSVirtualKeyRight: {
            WUTCCoreTextRange* forwardSel = [WUTCCoreTextRange new];

            if (_selection.endCaretPosition == _selection.startCaretPosition) {
                _extendingLeft = false;
            }

            if (_extendingLeft) {
                forwardSel.startCaretPosition = _selection.startCaretPosition + 1;
                forwardSel.endCaretPosition = _selection.endCaretPosition;
            } else {
                forwardSel.startCaretPosition = _selection.startCaretPosition;
                forwardSel.endCaretPosition = _selection.endCaretPosition + 1;
            }

            if (!_keyDown[WSVirtualKeyShift]) {
                forwardSel.startCaretPosition = forwardSel.endCaretPosition;
            }

            [self _setSelectionAndNotify:forwardSel];

            break;
        }
        // Home and end are also bound by "handedness"
        case WSVirtualKeyHome:
            if (_keyDown[WSVirtualKeyShift]) {
                _extendingLeft = true;
                _selection.endCaretPosition = _selection.startCaretPosition;
                _selection.startCaretPosition = 0;
            } else {
                _extendingLeft = false;
                _selection.endCaretPosition = _selection.startCaretPosition = 0;
            }

            [self _setSelectionAndNotify:_selection];

            break;
        case WSVirtualKeyEnd:
            if (_keyDown[WSVirtualKeyShift]) {
                if (_extendingLeft) {
                    _selection.startCaretPosition = _selection.endCaretPosition;
                }
                _extendingLeft = false;
                _selection.endCaretPosition = _textStorage.length;
            } else {
                _extendingLeft = false;
                _selection.endCaretPosition = _selection.startCaretPosition = _textStorage.length;
            }

            [self _setSelectionAndNotify:_selection];

            break;

        // Copy and paste
        case WSVirtualKeyV:
            if (_keyDown[(int)WSVirtualKeyControl]) {
                [self _copyFromClipboard];
            }

            break;
        case WSVirtualKeyC:
            if (_keyDown[(int)WSVirtualKeyControl]) {
                [self _copyToClipboard];
            }

            break;
        default:
            break;
    }
}

- (void)_xamlControlLostFocus:(RTObject*)sender args:(WXRoutedEventArgs*)e {
    [self _removeInternalFocus];
    [self _resetKeyStates];
}

- (void)_xamlControlPointerPressed:(RTObject*)sender args:(WUXIPointerRoutedEventArgs*)e {
    // Ensure no one else gets a chance to steal focus by setting handled.
    e.handled = YES;

    // We're only interested in left button presses for selection changes
    if (![e getCurrentPoint:_xamlControl].properties.isLeftButtonPressed) {
        return;
    }

    if (_internalFocus) {
        // This calculates an index from a point on the text spiral
        WUIPointerPoint* point = [e getCurrentPoint:_xamlControl];
        double x = point.position.x - _xamlControl.width / 2.0f;
        double y = point.position.y - _xamlControl.height / 2.0f;
        double rotationShrinkage = 0.83489316731872652497885712108957; // 0.995 ^ 36, the total shrinkage going 360` around the spiral
        double angle = 1.0 - (atan2(x, y) + M_PI) / (M_PI * 2);
        double lerp = (1.0 - angle) + (angle * rotationShrinkage);
        double distance = sqrt(x * x + y * y);

        // Clicked the center, discard.
        if (distance == 0) {
            return;
        }

        int spoke = (int)floor(fmod(angle, 1.0) * 36);
        double winds = log10f(distance / (self.bounds.size.width / 2.0f - 10.0f) / lerp) / log10f(rotationShrinkage); // log(value, base)
        spoke += (int)floor(winds) * 36;

        WUTCCoreTextRange* newRange = [WUTCCoreTextRange new];

        if (_keyDown[WSVirtualKeyShift]) {
            if (_extendingLeft) {
                if (spoke >= _selection.endCaretPosition) {
                    newRange.startCaretPosition = _selection.endCaretPosition;
                    newRange.endCaretPosition = spoke;
                    _extendingLeft = false;
                } else {
                    newRange.startCaretPosition = spoke;
                    newRange.endCaretPosition = _selection.endCaretPosition;
                }
            } else {
                if (spoke < _selection.startCaretPosition) {
                    newRange.endCaretPosition = _selection.startCaretPosition;
                    newRange.startCaretPosition = spoke;
                    _extendingLeft = true;
                } else {
                    newRange.endCaretPosition = spoke;
                    newRange.startCaretPosition = _selection.startCaretPosition;
                }
            }
        } else {
            newRange.startCaretPosition = newRange.endCaretPosition = spoke;
        }

        [self _setSelectionAndNotify:newRange];
    }
}

- (void)_xamlControlGotFocus:(RTObject*)sender args:(WXRoutedEventArgs*)e {
    [self _setInternalFocus];
}

- (void)_editContextFocusRemoved:(WUTCCoreTextEditContext*)sender args:(RTObject*)e {
    [self _removeInternalFocus];
}

// Return the specified range of text. Note that the system may ask for more text
// than exists in the text buffer.
- (void)_editContextTextRequested:(WUTCCoreTextEditContext*)sender args:(WUTCCoreTextTextRequestedEventArgs*)e {
    WUTCCoreTextTextRequest* request = e.request;
    request.text = [self _stringForRange:request.range];
}

// Return the current selection.
- (void)_editContextSelectionRequested:(WUTCCoreTextEditContext*)sender args:(WUTCCoreTextSelectionRequestedEventArgs*)e {
    WUTCCoreTextSelectionRequest* request = e.request;
    request.selection = _selection;
}

- (void)_editContextTextUpdating:(WUTCCoreTextEditContext*)sender args:(WUTCCoreTextTextUpdatingEventArgs*)e {
    WUTCCoreTextRange* range = e.range;
    WUTCCoreTextRange* newSelection = e.newSelection;

    // Modify the internal text store.
    [self _updateTextWithRange:range text:e.text];

    // You can set the proper font or direction for the updated text based on the language by checking
    // e.inputLanguage.  We will not do that in this sample.

    // Modify the current selection.
    newSelection.endCaretPosition = newSelection.startCaretPosition;

    // Update the selection of the edit context. There is no need to notify the system
    // because the system itself changed the selection.
    [self _setSelection:newSelection];
}

- (void)_editContextSelectionUpdating:(WUTCCoreTextEditContext*)sender args:(WUTCCoreTextSelectionUpdatingEventArgs*)e {
    // Set the new selection to the value specified by the system.
    WUTCCoreTextRange* range = e.selection;

    // Update the selection of the edit context. There is no need to notify the system
    // because the system itself changed the selection.
    [self _setSelection:range];
}

// The bounds returned drive the IME position and scrolling as to not block the
// field with the on-screen keyboard.
- (void)_editContextLayoutRequested:(WUTCCoreTextEditContext*)sender args:(WUTCCoreTextLayoutRequestedEventArgs*)e {
    WUTCCoreTextLayoutRequest* request = e.request;
    WFRect* rect = [WFRect new];
    rect.x = 0;
    rect.y = 0;
    rect.width = _xamlControl.width;
    rect.height = _xamlControl.height;
    request.layoutBounds.controlBounds = rect;
    request.layoutBounds.textBounds = rect;
}

// The following code specifies how you would apply any formatting to the specified range of text
// For this sample, we do not make any changes to the format.
// Formatting includes foreground, underlines and background colors, for IME and auto correction.
- (void)_editContextFormatUpdating:(WUTCCoreTextEditContext*)sender args:(WUTCCoreTextFormatUpdatingEventArgs*)e {
    // Apply text color if specified.
    // A null value indicates that the default should be used.
    if (e.textColor != nil) {
        // Set text color
    } else {
        // Reset text to default color
    }

    // Apply background color if specified.
    // A null value indicates that the default should be used.
    if (e.backgroundColor != nil) {
        // Set background color
    } else {
        // Reset background to default color
    }

    // Apply underline if specified.
    // A null value indicates that the default should be used.
    if (e.underlineType != nil) {
        // Add underline adornment
    } else {
        // Remove underline adornments
    }
}

// This indicates that an IME has started composition.  If there is no handler for this event,
// then composition will not start.
- (void)_editContextCompositionStarted:(WUTCCoreTextEditContext*)sender args:(WUTCCoreTextCompositionStartedEventArgs*)e {
}

- (void)_editContextCompositionCompleted:(WUTCCoreTextEditContext*)sender args:(WUTCCoreTextCompositionCompletedEventArgs*)e {
}

- (void)dealloc {
    [_xamlControl removeTappedEvent:_customEditControlTappedToken];
    [_xamlControl removeRightTappedEvent:_customEditControlRightTappedToken];
    [_xamlControl removeGotFocusEvent:_customEditControlGotFocusToken];
    [_xamlControlContent removePointerPressedEvent:_customEditControlPointerPressedToken];
    [_xamlControl removeLostFocusEvent:_customEditControlLostFocusToken];
    [_xamlControl removeKeyDownEvent:_customEditControlKeyDownToken];
    [_xamlControl removeKeyUpEvent:_customEditControlKeyUpToken];

    [_copy removeClickEvent:_copyClickToken];
    [_paste removeClickEvent:_pasteClickToken];

    [_editContext removeTextRequestedEvent:_editContextTextRequestedToken];
    [_editContext removeSelectionRequestedEvent:_editContextSelectionRequestedToken];
    [_editContext removeFocusRemovedEvent:_editContextFocusRemovedToken];
    [_editContext removeTextUpdatingEvent:_editContextTextUpdatingToken];
    [_editContext removeSelectionUpdatingEvent:_editContextSelectionUpdatingToken];
    [_editContext removeFormatUpdatingEvent:_editContextFormatUpdatingToken];
    [_editContext removeLayoutRequestedEvent:_editContextLayoutRequestedToken];
    [_editContext removeCompositionStartedEvent:_editContextCompositionStartedToken];
    [_editContext removeCompositionCompletedEvent:_editContextCompositionCompletedToken];
}

@end
#else // WINOBJC
@implementation SpiralTextEdit

- (void)_commonInit {
    UILabel* infoLabel = [[UILabel alloc] initWithFrame:self.bounds];

    infoLabel.text = @"Build this sample using the Islandwood SDK";
    infoLabel.numberOfLines = 0;
    infoLabel.textAlignment = NSTextAlignmentCenter;

    [self addSubview:infoLabel];

    self.backgroundColor = [UIColor grayColor];
}

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self _commonInit];
    }

    return self;
}

- (instancetype)initWithCoder:(NSCoder*)aDecoder {
    if (self = [super initWithCoder:aDecoder]) {
        [self _commonInit];
    }

    return self;
}

@end
#endif // WINOBJC

@implementation CustomTextControlViewController {
    BOOL _fromCoder;
}

- (instancetype)initWithCoder:(NSCoder*)aDecoder {
    if (self = [super initWithCoder:aDecoder]) {
        _fromCoder = YES;
    }

    return self;
}

- (void)viewDidLoad {
    self.view.backgroundColor = [UIColor whiteColor];

    if (!_fromCoder) {
        CGRect centeredEditRect = CGRectMake(self.view.bounds.size.width / 2 - 200 / 2, 200, 200, 200);
        CGRect centeredInfoRect = CGRectMake(self.view.bounds.size.width / 2 - 300 / 2, 100, 300, 100);

        SpiralTextEdit* textEdit = [[SpiralTextEdit alloc] initWithFrame:centeredEditRect];
        UILabel* infoLabel = [[UILabel alloc] initWithFrame:centeredInfoRect];
        UIButton* focusButton = [UIButton buttonWithType:UIButtonTypeSystem];

        textEdit.autoresizingMask = infoLabel.autoresizingMask = focusButton.autoresizingMask =
            UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleBottomMargin;

        infoLabel.text = @"Click the control to gain focus. Use the keyboard to type and caret navigate. Hold shift to update the "
                         @"selection. Right click or Ctrl+C or V to copy and paste.";
        infoLabel.numberOfLines = 0;
        infoLabel.textAlignment = NSTextAlignmentCenter;

        focusButton.frame = CGRectMake(self.view.bounds.size.width / 2 - 100 / 2, 450, 100, 50);
        [focusButton setTitle:@"Tab To Focus" forState:UIControlStateNormal];

        [self.view addSubview:focusButton];
        [self.view addSubview:textEdit];
        [self.view addSubview:infoLabel];
    }
}

@end