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
#include "UIAnimationNotification.h"

typedef void (^completionBlockFunc)(BOOL);

static void sendHasStarted(id delegate, SEL selector, NSString* animName, void* context) {
    if (delegate != nil) {
        SEL selName = selector;
        bool contextArg = true;

        if (selName == NULL) {
            if ([delegate respondsToSelector:@selector(aanimationWillStart:context:)]) {
                selName = @selector(animationWillStart:context:);
            } else {
                selName = @selector(animationWillStart:);
                contextArg = false;
            }
        }

        if (![delegate respondsToSelector:selName]) {
            selName = NULL;
        }
        if (selName) {
            if (contextArg) {
                [delegate performSelector:selName withObject:animName withObject:(id)context];
            } else {
                [delegate performSelector:selName withObject:animName];
            }
        }
    }
}

void sendDidStop(id delegate, SEL selector, NSString* animName, BOOL finished, void* context) {
    if (delegate != nil) {
        SEL selName = selector;
        bool contextArg = true;

        if (selName == NULL) {
            if ([delegate respondsToSelector:@selector(animationDidStop:finished:context:)]) {
                selName = @selector(animationDidStop:finished:context:);
            } else {
                selName = @selector(animationDidStop:finished:);
                contextArg = false;
            }
        }

        if (![delegate respondsToSelector:selName]) {
            selName = NULL;
        }

        if (selName) {
            id didFinish = [NSNumber numberWithBool:finished];
            if (contextArg) {
                [delegate performSelector:selName withObject:animName withObject:didFinish withObject:context];
            } else {
                [delegate performSelector:selName withObject:animName withObject:didFinish];
            }
        }
    }
}

@implementation UIAnimationNotification : NSObject
- (void)_animationHasStarted:(id)animation {
    if (_numAnimations == 0) {
        return;
    }
    _numStarted++;

    assert(_numStarted <= _numAnimations);

    if (_numStarted == _numAnimations) {
        sendHasStarted(_animDelegate, _animationWillStartSelector, _animName, _context);
    }
}

- (void)animationDidStop:(id)animation finished:(BOOL)finished {
    if (_numAnimations == 0) {
        return;
    }
    _numStopped++;

    assert(_numStopped <= _numAnimations);

    if (_numStopped == _numAnimations) {
        sendDidStop(_animDelegate, _animationDidStopSelector, _animName, finished, _context);
    }
    if (_completionBlock != nil && _numStopped == _numAnimations) {
        ((completionBlockFunc)_completionBlock)(TRUE);
        [_completionBlock release];
    }
    if (_animDelegate != nil && _numStopped == _numAnimations) {
        [_animDelegate release];
        [_animName release];
    }
}

@end
