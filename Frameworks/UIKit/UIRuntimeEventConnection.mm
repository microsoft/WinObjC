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
#include "UIKit/UIRuntimeEventConnection.h"
#include "LoggingNative.h"

static const wchar_t* TAG = L"UIRuntimeEventConnection";

@implementation UIRuntimeEventConnection

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    targetControl = [coder decodeObjectForKey:@"UISource"];
    obj = [coder decodeObjectForKey:@"UIDestination"];
    selector = (SEL)NSSelectorFromString([coder decodeObjectForKey:@"UILabel"]);
    mask = [coder decodeInt32ForKey:@"UIEventMask"];

    return self;
}

- (void)_makeConnection {
    TraceVerbose(TAG, L"Source: %hs", object_getClassName(targetControl));
    TraceVerbose(TAG, L"Dest: %hs", obj != nil ? object_getClassName(obj) : "nil (first responder?)");
    TraceVerbose(TAG, L"Event label: %x", selector);
    TraceVerbose(TAG, L"Event mask: %x", mask);

    valid = TRUE;

    if (obj != nil) {
        if (strcmp(object_getClassName(obj), "UIProxyObject") == 0) {
            obj = [obj _getObject];
        }
    }

    [targetControl addEventConnection:self];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithTarget:(id)target sel:(id)targetsel eventMask:(uint32_t)targetmask {
    obj = target;
    selector = (SEL)NSSelectorFromString(targetsel);
    mask = targetmask;

    valid = TRUE;

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithTarget:(id)target selector:(SEL)targetSel eventMask:(uint32_t)targetmask {
    obj = target;
    selector = targetSel;
    mask = targetmask;

    valid = TRUE;

    return self;
}

/**
 @Status Interoperable
*/
- (id)obj {
    return obj;
}

/**
 @Status Interoperable
*/
- (SEL)sel {
    return selector;
}

/**
 @Status Interoperable
*/
- (uint32_t)mask {
    return mask;
}

/**
 @Status Interoperable
*/
- (BOOL)isValid {
    return valid;
}

/**
 @Status Interoperable
*/
- (void)invalidate {
    valid = FALSE;
}

@end
