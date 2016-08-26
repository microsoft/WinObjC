//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <Starboard.h>
#import <Foundation/NSInvocation.h>
#import <ctype.h>
#import <objc/encoding.h>
#import "LoggingNative.h"
#import "ErrorHandling.h"

#import "NSMethodSignatureInternal.h"
#import "NSInvocationInternal.h"

#include <vector>
#include <memory>

static const wchar_t* TAG = L"NSInvocation";

@implementation NSInvocation {
    NSMethodSignature* _methodSignature;

    std::unique_ptr<_NSInvocationCallFrame> _callFrame;

    size_t _returnLength;
    BOOL _retainArguments;

    uint8_t _smallReturnValueOptimization[16];
    void* _returnValue;
}

/**
 @Status Interoperable
*/
+ (NSInvocation*)invocationWithMethodSignature:(NSMethodSignature*)methodSignature {
    return [[[self alloc] initWithMethodSignature:methodSignature] autorelease];
}

/**
 @Status Interoperable
 */
- (instancetype)initWithMethodSignature:(NSMethodSignature*)methodSignature {
    if (!methodSignature) {
        [NSException raise:NSInvalidArgumentException format:@"-[NSInvocation initWithMethodSignature:]: method signature must not be nil."];
        [self release];
        return nil;
    }

    if (self = [super init]) {
        _methodSignature = [methodSignature retain];

        _callFrame.reset(new _NSInvocationCallFrame(methodSignature));

        // true _non-promoted_ return length.
        // Used only for copying the argument back to the caller.
        _returnLength = methodSignature.methodReturnLength;

        size_t promotedReturnLength = _callFrame->getReturnLength();
        if (promotedReturnLength > sizeof(_smallReturnValueOptimization)) {
            _returnValue = IwCalloc(promotedReturnLength, 1); // promoted return length
        } else {
            _returnValue = &_smallReturnValueOptimization;
        }
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)setTarget:(id)targetObj {
    [self setArgument:&targetObj atIndex:0];
}

/**
 @Status Interoperable
*/
- (id)target {
    id target = nil;
    [self getArgument:&target atIndex:0];
    return target;
}

/**
 @Status Interoperable
*/
- (void)setSelector:(SEL)targSelector {
    [self setArgument:&targSelector atIndex:1];
}

/**
 @Status Interoperable
*/
- (SEL)selector {
    SEL selector = nil;
    [self getArgument:&selector atIndex:1];
    return selector;
}

/**
 @Status Interoperable
*/
- (NSMethodSignature*)methodSignature {
    return _methodSignature;
}

/**
 @Status Interoperable
*/
- (void)setArgument:(void*)buf atIndex:(int)index {
    if ((index < 0) || (index >= [_methodSignature numberOfArguments])) {
        TraceVerbose(TAG, L"index = %d, MethodSig arguments = %d", index, [_methodSignature numberOfArguments]);
        [NSException raise:NSInvalidArgumentException format:@"The number of arguments exceeds the allowed limit."];
    }

    if (_retainArguments) {
        const char* argumentType = [_methodSignature getArgumentTypeAtIndex:index];
        if (argumentType[0] == '@') {
            // Release old value:
            id oldValue = nil;
            [self getArgument:&oldValue atIndex:index];
            [(*(id*)buf) retain];
            if (oldValue) {
                [oldValue release];
            }
        } else if (argumentType[0] == '*') {
            char* oldValue = nullptr;
            [self getArgument:&oldValue atIndex:index];
            if (oldValue) {
                IwFree(oldValue);
            }
            char* newValue = IwStrDup(*(char**)buf);
            _callFrame->storeArgument(&newValue, index);
            return;
        }
    }
    _callFrame->storeArgument(buf, index);
}

/**
 @Status Interoperable
*/
- (void)getArgument:(void*)buf atIndex:(int)index {
    if ((index < 0) || (index >= [_methodSignature numberOfArguments])) {
        TraceVerbose(TAG, L"index = %d, MethodSig arguments = %d", index, [_methodSignature numberOfArguments]);
        [NSException raise:NSInvalidArgumentException format:@"The number of arguments exceeds the allowed limit."];
    }

    _callFrame->loadArgument(buf, index);
}

/**
 @Status Interoperable
*/
- (void)retainArguments {
    if (!_retainArguments) {
        _retainArguments = YES;

        unsigned int numArgs = [_methodSignature numberOfArguments];

        for (unsigned int i = 0; i < numArgs; i++) {
            const char* type = [_methodSignature getArgumentTypeAtIndex:i];
            if (type[0] == '@') {
                // id or block
                id arg = nil;
                [self getArgument:&arg atIndex:i];
                if (arg) {
                    [arg retain];
                }
            } else if (type[0] == '*') {
                // char*
                char* arg = nullptr;
                [self getArgument:&arg atIndex:i];
                if (arg) {
                    arg = IwStrDup(arg);
                    [self setArgument:&arg atIndex:i];
                }
            }
        }
    }
}

/**
 @Status Interoperable
*/
- (void)getReturnValue:(void*)buf {
    memcpy(buf, _returnValue, _returnLength);
}

/**
 @Status Interoperable
*/
- (void)setReturnValue:(void*)buf {
    memcpy(_returnValue, buf, _returnLength);
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    // Release retained/string-copied arguments
    if (_retainArguments) {
        unsigned int numArgs = [_methodSignature numberOfArguments];

        for (unsigned int i = 0; i < numArgs; i++) {
            const char* type = [_methodSignature getArgumentTypeAtIndex:i];
            if (type[0] == '@') {
                // id or block
                id arg = nil;
                [self getArgument:&arg atIndex:i];
                [arg release];
            } else if (type[0] == '*') {
                char* arg = nullptr;
                [self getArgument:&arg atIndex:i];
                IwFree(arg);
            }
        }
    }

    if (_returnValue != &_smallReturnValueOptimization) {
        IwFree(_returnValue);
    }

    [_methodSignature release];

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (void)invokeWithTarget:(id)target {
    [self setTarget:target];
    [self invoke];
}

/**
 @Status Interoperable
*/
- (void)invoke {
    void* pfn = &objc_msgSend;
    if (_callFrame->getRequiresStructReturn()) {
        pfn = &objc_msgSend_stret;
    }

    _callFrame->execute(pfn, _returnValue);
}

@end
