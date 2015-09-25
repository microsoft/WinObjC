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

#include "Starboard.h"

id _curFirstResponder;
static int _changingResponder = 0;

@implementation UIResponder : NSObject
- (BOOL)resignFirstResponder {
    if (_curFirstResponder == self) {
        _curFirstResponder = nil;
        if (_changingResponder == 0)
            [[UIApplication sharedApplication] _evaluateKeyboard];
    }

    return TRUE;
}

- (BOOL)canBecomeFirstResponder {
    return FALSE;
}

- (BOOL)canResignFirstResponder {
    return TRUE;
}

- (void)reloadInputViews {
}

- (UIView*)inputView {
    return nil;
}

- (BOOL)isFirstResponder {
    return _curFirstResponder == self;
}

- (BOOL)becomeFirstResponder {
    if (_curFirstResponder == self)
        return TRUE;
    if ([self respondsToSelector:@selector(window)]) {
        if ([self window] == nil)
            return FALSE;
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

+ (void)keyPressed:(unsigned)key {
    if (_curFirstResponder != nil) {
        [_curFirstResponder keyPressed:key];
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

- (void)keyPressed:(unsigned)key {
}

- (UIResponder*)nextResponder {
    return nil;
}

- (UIView*)inputAccessoryView {
    return nil;
}

- (void)dealloc {
    if (_curFirstResponder == self) {
        _curFirstResponder = nil;
    }

    [super dealloc];
}

- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    UIResponder* nextResponder = [self nextResponder];

    if (nextResponder != nil) {
        [nextResponder touchesBegan:touches withEvent:event];
        return;
    }

    EbrDebugLog("Unhandled touchesBegan!\n");
}

- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
    EbrDebugLog("Clicked: %s\n", object_getClassName(self));
    id nextResponder = [self nextResponder];

    if (nextResponder != nil) {
        [nextResponder touchesMoved:touches withEvent:event];
        return;
    }

    EbrDebugLog("Unhandled touchesMoved!\n");
}

- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    id nextResponder = [self nextResponder];

    if (nextResponder != nil) {
        [nextResponder touchesEnded:touches withEvent:event];
        return;
    }

    EbrDebugLog("Unhandled touchesEnded!\n");
}

- (void)touchesCancelled:(NSSet*)touches withEvent:(UIEvent*)event {
    id nextResponder = [self nextResponder];

    if (nextResponder != nil) {
        [nextResponder touchesCancelled:touches withEvent:event];
        return;
    }

    EbrDebugLog("Unhandled touchesCancelled!\n");
}

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

- (void)didMoveToWindow {
    if (_curFirstResponder == self && [self window] == nil) {
        [self resignFirstResponder];
        _curFirstResponder = nil;
    }
}

+ (void)_resignCurResponder {
    [_curFirstResponder resignFirstResponder];
    _curFirstResponder = nil;
}

- (void)setAccessibilityLabel:(NSString*)label {
}

- (void)setAccessibilityHint:(NSString*)hint {
}

- (void)setAccessibilityTraits:(unsigned)traits {
}

- (void)setIsAccessibilityElement:(BOOL)enabled {
}

- (void)setShouldGroupAccessibilityChildren:(BOOL)group {
}

@end
