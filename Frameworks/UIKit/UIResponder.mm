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

#import "Starboard.h"
#import "LoggingNative.h"

#import <UIKit/UIView.h>

#import "UIResponderInternal.h"
#import "UIApplicationInternal.h"

static const wchar_t* TAG = L"UIResponder";

id _curFirstResponder;
static int _changingResponder = 0;

@implementation UIResponder

/**
 @Status Interoperable
*/
- (BOOL)resignFirstResponder {
    if (_curFirstResponder == self) {
        _curFirstResponder = nil;
    }

    return TRUE;
}

/**
 @Status Interoperable
*/
- (BOOL)canBecomeFirstResponder {
    return FALSE;
}

/**
 @Status Interoperable
*/
- (BOOL)canResignFirstResponder {
    return TRUE;
}

/**
 @Status Stub
*/
- (void)reloadInputViews {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UIView*)inputView {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Interoperable
*/
- (BOOL)isFirstResponder {
    return _curFirstResponder == self;
}

/**
 @Status Interoperable
*/
- (BOOL)becomeFirstResponder {
    if (_curFirstResponder == self) {
        return TRUE;
    }
    if ([self respondsToSelector:@selector(window)]) {
        if ([static_cast<UIView*>(self) window] == nil) {
            return FALSE;
        }
    }

    _changingResponder++;
    if (_curFirstResponder != nil) {
        if ([_curFirstResponder resignFirstResponder] == FALSE) {
            _changingResponder--;
            return FALSE;
        }
    }
    _curFirstResponder = self;
    _changingResponder--;

    return TRUE;
}

+ (void)_keyPressed:(unsigned short)key {
    if (_curFirstResponder != nil) {
        [_curFirstResponder _keyPressed:key];
    }
}

+ (id)_deleteRange:(id)num {
    if (_curFirstResponder != nil) {
        if ([_curFirstResponder respondsToSelector:@selector(_deleteRange:)]) {
            [_curFirstResponder _deleteRange:num];
        }
    }

    return self;
}

- (void)_keyPressed:(unsigned short)key {
}

/**
 @Status Interoperable
*/
- (UIResponder*)nextResponder {
    return nil;
}

/**
 @Status Stub
*/
- (UIView*)inputAccessoryView {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    if (_curFirstResponder == self) {
        _curFirstResponder = nil;
    }

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    UIResponder* nextResponder = [self nextResponder];

    if (nextResponder != nil) {
        [nextResponder touchesBegan:touches withEvent:event];
        return;
    }

    TraceVerbose(TAG, L"Unhandled touchesBegan!");
}

/**
 @Status Interoperable
*/
- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
    TraceVerbose(TAG, L"Clicked: %hs", object_getClassName(self));
    id nextResponder = [self nextResponder];

    if (nextResponder != nil) {
        [nextResponder touchesMoved:touches withEvent:event];
        return;
    }

    TraceVerbose(TAG, L"Unhandled touchesMoved!");
}

/**
 @Status Interoperable
*/
- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    id nextResponder = [self nextResponder];

    if (nextResponder != nil) {
        [nextResponder touchesEnded:touches withEvent:event];
        return;
    }

    TraceVerbose(TAG, L"Unhandled touchesEnded!");
}

/**
 @Status Interoperable
*/
- (void)touchesCancelled:(NSSet*)touches withEvent:(UIEvent*)event {
    id nextResponder = [self nextResponder];

    if (nextResponder != nil) {
        [nextResponder touchesCancelled:touches withEvent:event];
        return;
    }

    TraceVerbose(TAG, L"Unhandled touchesCancelled!");
}

/**
 @Status Interoperable
*/
- (BOOL)canPerformAction:(SEL)action withSender:(id)sender {
    id curTarget = self;
    while (curTarget != nil) {
        if ([curTarget respondsToSelector:action]) {
            return TRUE;
        }
        curTarget = [curTarget nextResponder];
    }

    return FALSE;
}

/**
 @Status Interoperable
*/
- (void)didMoveToWindow {
    if ([self respondsToSelector:@selector(window)]) {
        if (_curFirstResponder == self && [static_cast<UIView*>(self) window] == nil) {
            [self resignFirstResponder];
            _curFirstResponder = nil;
        }
    }
}

+ (void)_resignCurResponder {
    [_curFirstResponder resignFirstResponder];
    _curFirstResponder = nil;
}

/**
 @Status Stub
*/
- (void)setAccessibilityLabel:(NSString*)label {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setAccessibilityHint:(NSString*)hint {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setAccessibilityTraits:(unsigned)traits {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setIsAccessibilityElement:(BOOL)enabled {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setShouldGroupAccessibilityChildren:(BOOL)group {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)motionBegan:(UIEventSubtype)motion withEvent:(UIEvent*)event {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)motionEnded:(UIEventSubtype)motion withEvent:(UIEvent*)event {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)motionCancelled:(UIEventSubtype)motion withEvent:(UIEvent*)event {
    UNIMPLEMENTED();
}

@end
