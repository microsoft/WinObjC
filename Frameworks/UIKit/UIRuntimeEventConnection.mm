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
#import <UIKit/UIRuntimeEventConnection.h>

#import "UIControlInternal.h"
#import "UIProxyObject.h"

#import "LoggingNative.h"

static const wchar_t* TAG = L"UIRuntimeEventConnection";

@implementation UIRuntimeEventConnection
@synthesize mask = _mask;
@synthesize sel = _sel;
@synthesize obj = _obj;
@synthesize target = _target;
@synthesize isValid = _isValid;

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    _target = [coder decodeObjectForKey:@"UISource"];
    _obj = [coder decodeObjectForKey:@"UIDestination"];
    _sel = NSSelectorFromString([coder decodeObjectForKey:@"UILabel"]);
    _mask = [coder decodeInt32ForKey:@"UIEventMask"];

    return self;
}

- (void)_makeConnection {
    TraceVerbose(TAG, L"Source: %hs", object_getClassName(_target));
    TraceVerbose(TAG, L"Dest: %hs", _obj != nil ? object_getClassName(_obj) : "nil (first responder?)");
    TraceVerbose(TAG, L"Event label: %x", _sel);
    TraceVerbose(TAG, L"Event mask: %x", _mask);

    _isValid = YES;

    if (_obj) {
        if ([_obj class] == [UIProxyObject class]) {
            _obj = [_obj _getObject];
        }
    }
    if ([_target respondsToSelector:@selector(_addEventConnection:)]) {
        [_target _addEventConnection:self];
    }
}

/**
 @Status Interoperable
*/
- (instancetype)initWithTarget:(id)target sel:(id)targetsel eventMask:(uint32_t)targetmask {
    _obj = target;
    _sel = NSSelectorFromString(targetsel);
    _mask = targetmask;

    _isValid = YES;

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithTarget:(id)target selector:(SEL)targetSel eventMask:(uint32_t)targetmask {
    _obj = target;
    _sel = targetSel;
    _mask = targetmask;

    _isValid = YES;

    return self;
}

/**
 @Status Interoperable
*/
- (id)obj {
    return _obj;
}

/**
 @Status Interoperable
*/
- (SEL)sel {
    return _sel;
}

/**
 @Status Interoperable
*/
- (uint32_t)mask {
    return _mask;
}

/**
 @Status Interoperable
*/
- (BOOL)isValid {
    return _isValid;
}

/**
 @Status Interoperable
*/
- (void)invalidate {
    _isValid = NO;
}

@end
